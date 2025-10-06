#define _GNU_SOURCE
#include <dlfcn.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/ioctl.h>
#include <poll.h>
#include <pthread.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/prctl.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <time.h>
#include <unistd.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

#ifndef EPOLLRDHUP
#define EPOLLRDHUP 0
#endif
#ifndef EPOLLONESHOT
#define EPOLLONESHOT 0
#endif
#ifndef EPOLLET
#define EPOLLET 0
#endif
#ifndef EPOLLEXCLUSIVE
#define EPOLLEXCLUSIVE 0
#endif

/* ------------------------------------------------------------------------- */
/* Forward declarations for the real libc entry points.                     */
/* ------------------------------------------------------------------------- */
typedef int (*real_open_t)(const char *, int, ...);
typedef int (*real_openat_t)(int, const char *, int, ...);
typedef int (*real_close_t)(int);
typedef int (*real_ioctl_t)(int, unsigned long, ...);
typedef ssize_t (*real_read_t)(int, void *, size_t);
typedef ssize_t (*real_write_t)(int, const void *, size_t);
typedef int (*real_select_t)(int, fd_set *, fd_set *, fd_set *, struct timeval *);
typedef int (*real_pselect_t)(int, fd_set *, fd_set *, fd_set *, const struct timespec *, const sigset_t *);
typedef int (*real_poll_t)(struct pollfd *, nfds_t, int);
typedef int (*real_ppoll_t)(struct pollfd *, nfds_t, const struct timespec *, const sigset_t *);
typedef int (*real_epoll_create_t)(int);
typedef int (*real_epoll_create1_t)(int);
typedef int (*real_epoll_ctl_t)(int, int, int, struct epoll_event *);
typedef int (*real_epoll_wait_t)(int, struct epoll_event *, int, int);
typedef int (*real_epoll_pwait_t)(int, struct epoll_event *, int, int, const sigset_t *);
typedef void *(*real_mmap_t)(void *, size_t, int, int, int, off_t);
typedef int (*real_munmap_t)(void *, size_t);
typedef int (*real_dup_t)(int);
typedef int (*real_dup2_t)(int, int);
typedef int (*real_dup3_t)(int, int, int);

typedef int (*real_pipe_t)(int [2]);
typedef int (*real_pipe2_t)(int [2], int);

typedef off_t (*real_lseek_t)(int, off_t, int);
typedef off64_t (*real_lseek64_t)(int, off64_t, int);

typedef int (*real_fcntl_t)(int, int, ...);

static real_open_t       real_open_fn = NULL;
static real_openat_t     real_openat_fn = NULL;
static real_close_t      real_close_fn = NULL;
static real_ioctl_t      real_ioctl_fn = NULL;
static real_read_t       real_read_fn = NULL;
static real_write_t      real_write_fn = NULL;
static real_select_t     real_select_fn = NULL;
static real_pselect_t    real_pselect_fn = NULL;
static real_poll_t       real_poll_fn = NULL;
static real_ppoll_t      real_ppoll_fn = NULL;
static real_epoll_create_t   real_epoll_create_fn = NULL;
static real_epoll_create1_t  real_epoll_create1_fn = NULL;
static real_epoll_ctl_t      real_epoll_ctl_fn = NULL;
static real_epoll_wait_t     real_epoll_wait_fn = NULL;
static real_epoll_pwait_t    real_epoll_pwait_fn = NULL;
static real_mmap_t       real_mmap_fn = NULL;
static real_munmap_t     real_munmap_fn = NULL;
static real_dup_t        real_dup_fn = NULL;
static real_dup2_t       real_dup2_fn = NULL;
static real_dup3_t       real_dup3_fn = NULL;
static real_pipe_t       real_pipe_fn = NULL;
static real_pipe2_t      real_pipe2_fn = NULL;
static real_lseek_t      real_lseek_fn = NULL;
static real_lseek64_t    real_lseek64_fn = NULL;
static real_fcntl_t      real_fcntl_fn = NULL;

/* ------------------------------------------------------------------------- */
/* Runtime configuration                                                      */
/* ------------------------------------------------------------------------- */
static int log_fd = -1;
static pthread_mutex_t log_mu = PTHREAD_MUTEX_INITIALIZER;
static __thread int g_internal = 0;

static size_t g_dump_limit = 256;       /* bytes dumped for read/write/ioctl */
static int g_dump_ascii = 1;            /* include ASCII column in hex dumps */

/* Certain driver specific ioctls are declared with _IOC_NONE even though they
 * still expect a user supplied argument.  When we run under the tracer those
 * calls would previously loose their argument which in turn makes the driver
 * fail with EFAULT.  Keep a small whitelist of such requests so we can forward
 * the pointer to the real ioctl implementation. */
static bool ioctl_requires_hidden_arg(unsigned long request, size_t *forced_size) {
    switch (request) {
        case 0x50e1: /* AKPCM_IOC_RESUME expects a pointer to resume flags. */
            if (forced_size) {
                *forced_size = sizeof(unsigned long);
            }
            return true;
        default:
            break;
    }
    return false;
}

static const char *k_targets[] = {
    "/dev/ion",
    "/dev/uio0",
    "/dev/isp_char",
    "/dev/video0",
    "/dev/akgpio",
    "/dev/akpcm_cdev0",
    "/dev/akpcm_cdev1",
    "/dev/mem",
    NULL
};

/* ------------------------------------------------------------------------- */
/* Logging helpers                                                            */
/* ------------------------------------------------------------------------- */
static void ensure_real_write(void) {
    if (!real_write_fn) {
        real_write_fn = (real_write_t)dlsym(RTLD_NEXT, "write");
    }
}

static void log_raw(const char *buf, size_t len) {
    if (log_fd < 0 || !buf || !len) {
        return;
    }
    ensure_real_write();
    if (!real_write_fn) {
        return;
    }
    g_internal++;
    real_write_fn(log_fd, buf, len);
    g_internal--;
}

static void log_printf(const char *fmt, ...) {
    if (log_fd < 0) {
        return;
    }
    char buffer[1024];
    va_list ap;
    va_start(ap, fmt);
    int len = vsnprintf(buffer, sizeof(buffer), fmt, ap);
    va_end(ap);
    if (len <= 0) {
        return;
    }
    if ((size_t)len >= sizeof(buffer)) {
        len = (int)(sizeof(buffer) - 1);
    }
    log_raw(buffer, (size_t)len);
}

static pid_t get_tid_internal(void) {
#ifdef SYS_gettid
    return (pid_t)syscall(SYS_gettid);
#else
    return getpid();
#endif
}

static void now_timestamp(char *out, size_t n) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    snprintf(out, n, "%lld.%06ld",
             (long long)ts.tv_sec,
             ts.tv_nsec / 1000);
}

static void thread_name(char *out, size_t n) {
#if defined(PR_GET_NAME)
    if (prctl(PR_GET_NAME, (unsigned long)out, 0, 0, 0) == 0) {
        out[n - 1] = '\0';
        return;
    }
#endif
    if (n > 0) {
        out[0] = '\0';
    }
}

/* ------------------------------------------------------------------------- */
/* FD bookkeeping                                                             */
/* ------------------------------------------------------------------------- */
typedef struct {
    int used;
    int is_target;
    char path[PATH_MAX];
    dev_t rdev;
    pid_t owner_tid;
    char uio_name[128];
} fdinfo_t;

#define FD_LIMIT 4096
static fdinfo_t fdmap[FD_LIMIT];

static bool is_target_path(const char *path) {
    if (!path) {
        return false;
    }
    for (int i = 0; k_targets[i]; ++i) {
        if (strcmp(path, k_targets[i]) == 0) {
            return true;
        }
    }
    return false;
}

static void resolve_fd_path(int fd, char *out, size_t n) {
    if (!out || n == 0) {
        return;
    }
    char link[64];
    snprintf(link, sizeof(link), "/proc/self/fd/%d", fd);
    g_internal++;
    ssize_t m = readlink(link, out, n - 1);
    g_internal--;
    if (m >= 0) {
        out[m] = '\0';
    } else {
        snprintf(out, n, "?");
    }
}

static void populate_fdinfo(int fd, const char *path_hint) {
    if (fd < 0 || fd >= FD_LIMIT) {
        return;
    }
    fdinfo_t *fi = &fdmap[fd];
    memset(fi, 0, sizeof(*fi));
    fi->used = 1;
    fi->owner_tid = get_tid_internal();

    if (path_hint && path_hint[0]) {
        strncpy(fi->path, path_hint, sizeof(fi->path) - 1);
    } else {
        resolve_fd_path(fd, fi->path, sizeof(fi->path));
    }
    fi->is_target = is_target_path(fi->path);

    struct stat st;
    g_internal++;
    if (fstat(fd, &st) == 0 && S_ISCHR(st.st_mode)) {
        fi->rdev = st.st_rdev;
    }
    g_internal--;

    if (strncmp(fi->path, "/dev/uio", 8) == 0) {
        int idx = atoi(fi->path + 8);
        char sysname[PATH_MAX];
        snprintf(sysname, sizeof(sysname), "/sys/class/uio/uio%d/name", idx);
        g_internal++;
        int name_fd = real_open_fn ? real_open_fn(sysname, O_RDONLY) : open(sysname, O_RDONLY);
        if (name_fd >= 0) {
            ssize_t r = real_read_fn ? real_read_fn(name_fd, fi->uio_name, sizeof(fi->uio_name) - 1)
                                     : read(name_fd, fi->uio_name, sizeof(fi->uio_name) - 1);
            if (r > 0) {
                while (r > 0 && (fi->uio_name[r - 1] == '\n' || fi->uio_name[r - 1] == '\r')) {
                    r--;
                }
                fi->uio_name[r] = '\0';
            } else {
                fi->uio_name[0] = '\0';
            }
            if (real_close_fn) {
                real_close_fn(name_fd);
            } else {
                close(name_fd);
            }
        }
        g_internal--;
    }
}

static fdinfo_t *fdinfo_get(int fd) {
    if (fd < 0 || fd >= FD_LIMIT) {
        return NULL;
    }
    fdinfo_t *fi = &fdmap[fd];
    if (!fi->used) {
        populate_fdinfo(fd, NULL);
    }
    return fi;
}

static void fdinfo_clear(int fd) {
    if (fd < 0 || fd >= FD_LIMIT) {
        return;
    }
    memset(&fdmap[fd], 0, sizeof(fdmap[fd]));
}

static void log_call_header(const char *call, int fd, const fdinfo_t *fi) {
    char ts[64];
    char tname[32];
    now_timestamp(ts, sizeof(ts));
    thread_name(tname, sizeof(tname));
    if (fi && fi->used) {
        unsigned maj = (unsigned)((fi->rdev >> 8) & 0xff);
        unsigned min = (unsigned)(fi->rdev & 0xff);
        log_printf("[%d/%d %s thr=%s owner=%d] %s(fd=%d path=%s rdev=%u:%u) ",
                   getpid(), (int)get_tid_internal(), ts,
                   tname[0] ? tname : "?",
                   fi->owner_tid,
                   call,
                   fd,
                   fi->path[0] ? fi->path : "?",
                   maj,
                   min);
    } else {
        log_printf("[%d/%d %s thr=%s] %s(fd=%d) ",
                   getpid(), (int)get_tid_internal(), ts,
                   tname[0] ? tname : "?",
                   call,
                   fd);
    }
}

/* ------------------------------------------------------------------------- */
/* Hex dump helpers                                                           */
/* ------------------------------------------------------------------------- */
static void hexdump_buffer(const void *data, size_t length) {
    if (!data || length == 0) {
        log_printf("(no data)\n");
        return;
    }
    size_t max_bytes = length;
    if (max_bytes > g_dump_limit) {
        max_bytes = g_dump_limit;
    }
    const unsigned char *buf = (const unsigned char *)data;
    char line[128];
    for (size_t i = 0; i < max_bytes; i += 16) {
        size_t chunk = (max_bytes - i) < 16 ? (max_bytes - i) : 16;
        int len = snprintf(line, sizeof(line), "  %04zx:", i);
        for (size_t j = 0; j < chunk; ++j) {
            len += snprintf(line + len, sizeof(line) - (size_t)len, " %02x", buf[i + j]);
        }
        if (g_dump_ascii) {
            len += snprintf(line + len, sizeof(line) - (size_t)len, "  ");
            for (size_t j = 0; j < chunk; ++j) {
                unsigned char c = buf[i + j];
                line[len++] = (c >= 32 && c <= 126) ? (char)c : '.';
                if ((size_t)len >= sizeof(line) - 4) {
                    break;
                }
            }
        }
        line[len++] = '\n';
        log_raw(line, (size_t)len);
    }
    if (length > g_dump_limit) {
        log_printf("  ... (%zu bytes total)\n", length);
    }
}

/* ------------------------------------------------------------------------- */
/* Constructor / destructor                                                   */
/* ------------------------------------------------------------------------- */
__attribute__((constructor))
static void tracer_init(void) {
    real_open_fn = (real_open_t)dlsym(RTLD_NEXT, "open");
    real_openat_fn = (real_openat_t)dlsym(RTLD_NEXT, "openat");
    real_close_fn = (real_close_t)dlsym(RTLD_NEXT, "close");
    real_ioctl_fn = (real_ioctl_t)dlsym(RTLD_NEXT, "ioctl");
    real_read_fn = (real_read_t)dlsym(RTLD_NEXT, "read");
    real_write_fn = (real_write_t)dlsym(RTLD_NEXT, "write");
    real_select_fn = (real_select_t)dlsym(RTLD_NEXT, "select");
    real_pselect_fn = (real_pselect_t)dlsym(RTLD_NEXT, "pselect");
    real_poll_fn = (real_poll_t)dlsym(RTLD_NEXT, "poll");
    real_ppoll_fn = (real_ppoll_t)dlsym(RTLD_NEXT, "ppoll");
    real_epoll_create_fn = (real_epoll_create_t)dlsym(RTLD_NEXT, "epoll_create");
    real_epoll_create1_fn = (real_epoll_create1_t)dlsym(RTLD_NEXT, "epoll_create1");
    real_epoll_ctl_fn = (real_epoll_ctl_t)dlsym(RTLD_NEXT, "epoll_ctl");
    real_epoll_wait_fn = (real_epoll_wait_t)dlsym(RTLD_NEXT, "epoll_wait");
    real_epoll_pwait_fn = (real_epoll_pwait_t)dlsym(RTLD_NEXT, "epoll_pwait");
    real_mmap_fn = (real_mmap_t)dlsym(RTLD_NEXT, "mmap");
    real_munmap_fn = (real_munmap_t)dlsym(RTLD_NEXT, "munmap");
    real_dup_fn = (real_dup_t)dlsym(RTLD_NEXT, "dup");
    real_dup2_fn = (real_dup2_t)dlsym(RTLD_NEXT, "dup2");
    real_dup3_fn = (real_dup3_t)dlsym(RTLD_NEXT, "dup3");
    real_pipe_fn = (real_pipe_t)dlsym(RTLD_NEXT, "pipe");
    real_pipe2_fn = (real_pipe2_t)dlsym(RTLD_NEXT, "pipe2");
    real_lseek_fn = (real_lseek_t)dlsym(RTLD_NEXT, "lseek");
    real_lseek64_fn = (real_lseek64_t)dlsym(RTLD_NEXT, "lseek64");
    real_fcntl_fn = (real_fcntl_t)dlsym(RTLD_NEXT, "fcntl");

    const char *log_path = getenv("IPC_TRACE_LOG");
    if (!log_path || !log_path[0]) {
        log_path = "/tmp/ipc_trace.log";
    }

    const char *dump = getenv("IPC_TRACE_DUMP");
    if (dump && dump[0]) {
        g_dump_limit = (size_t)strtoul(dump, NULL, 0);
    }

    const char *ascii = getenv("IPC_TRACE_ASCII");
    if (ascii && ascii[0] == '0') {
        g_dump_ascii = 0;
    }

    g_internal++;
    if (real_open_fn) {
        log_fd = real_open_fn(log_path, O_CREAT | O_WRONLY | O_APPEND, 0644);
    } else {
        log_fd = open(log_path, O_CREAT | O_WRONLY | O_APPEND, 0644);
    }
    g_internal--;

    if (log_fd >= 0) {
        char ts[64];
        char tname[32];
        now_timestamp(ts, sizeof(ts));
        thread_name(tname, sizeof(tname));
        log_printf("[%d/%d %s thr=%s] === ipc-trace preload start ===\n",
                   getpid(), (int)get_tid_internal(), ts,
                   tname[0] ? tname : "?");
    }
}

__attribute__((destructor))
static void tracer_shutdown(void) {
    if (log_fd >= 0) {
        char ts[64];
        char tname[32];
        now_timestamp(ts, sizeof(ts));
        thread_name(tname, sizeof(tname));
        log_printf("[%d/%d %s thr=%s] === ipc-trace preload stop ===\n",
                   getpid(), (int)get_tid_internal(), ts,
                   tname[0] ? tname : "?");
        g_internal++;
        if (real_close_fn) {
            real_close_fn(log_fd);
        } else {
            close(log_fd);
        }
        g_internal--;
    }
    log_fd = -1;
}

/* ------------------------------------------------------------------------- */
/* Common logging glue                                                        */
/* ------------------------------------------------------------------------- */
static bool should_trace_fd(int fd) {
    fdinfo_t *fi = fdinfo_get(fd);
    return fi && fi->is_target;
}

static void maybe_log_uio_name(const fdinfo_t *fi) {
    if (fi && fi->uio_name[0]) {
        log_printf("  uio_name=%s\n", fi->uio_name);
    }
}

/* ------------------------------------------------------------------------- */
/* open / openat                                                              */
/* ------------------------------------------------------------------------- */
int open(const char *path, int flags, ...) {
    mode_t mode = 0;
    if (flags & O_CREAT) {
        va_list ap;
        va_start(ap, flags);
        mode = (mode_t)va_arg(ap, int);
        va_end(ap);
    }
    if (!real_open_fn) {
        real_open_fn = (real_open_t)dlsym(RTLD_NEXT, "open");
    }
    if (g_internal) {
        return (flags & O_CREAT) ? real_open_fn(path, flags, mode) : real_open_fn(path, flags);
    }
    g_internal++;
    int fd = (flags & O_CREAT) ? real_open_fn(path, flags, mode) : real_open_fn(path, flags);
    g_internal--;
    if (fd >= 0 && is_target_path(path)) {
        populate_fdinfo(fd, path);
        fdinfo_t *fi = fdinfo_get(fd);
        pthread_mutex_lock(&log_mu);
        log_call_header("open", fd, fi);
        log_printf("= %d\n", fd);
        maybe_log_uio_name(fi);
        pthread_mutex_unlock(&log_mu);
    }
    return fd;
}

int open64(const char *path, int flags, ...) {
    mode_t mode = 0;
    if (flags & O_CREAT) {
        va_list ap;
        va_start(ap, flags);
        mode = (mode_t)va_arg(ap, int);
        va_end(ap);
    }
    return open(path, flags, mode);
}

int openat(int dirfd, const char *path, int flags, ...) {
    mode_t mode = 0;
    if (flags & O_CREAT) {
        va_list ap;
        va_start(ap, flags);
        mode = (mode_t)va_arg(ap, int);
        va_end(ap);
    }
    if (!real_openat_fn) {
        real_openat_fn = (real_openat_t)dlsym(RTLD_NEXT, "openat");
    }
    if (g_internal) {
        return (flags & O_CREAT) ? real_openat_fn(dirfd, path, flags, mode)
                                 : real_openat_fn(dirfd, path, flags);
    }
    g_internal++;
    int fd = (flags & O_CREAT) ? real_openat_fn(dirfd, path, flags, mode)
                               : real_openat_fn(dirfd, path, flags);
    g_internal--;
    if (fd >= 0) {
        populate_fdinfo(fd, NULL);
        fdinfo_t *fi = fdinfo_get(fd);
        if (fi && fi->is_target) {
            pthread_mutex_lock(&log_mu);
            log_call_header("openat", fd, fi);
            log_printf("= %d\n", fd);
            maybe_log_uio_name(fi);
            pthread_mutex_unlock(&log_mu);
        }
    }
    return fd;
}

/* ------------------------------------------------------------------------- */
/* close                                                                      */
/* ------------------------------------------------------------------------- */
int close(int fd) {
    if (!real_close_fn) {
        real_close_fn = (real_close_t)dlsym(RTLD_NEXT, "close");
    }
    if (g_internal) {
        return real_close_fn(fd);
    }
    fdinfo_t *fi = fdinfo_get(fd);
    bool trace = fi && fi->is_target;
    g_internal++;
    int rc = real_close_fn(fd);
    g_internal--;
    if (trace) {
        pthread_mutex_lock(&log_mu);
        log_call_header("close", fd, fi);
        log_printf("= %d errno=%d\n", rc, errno);
        pthread_mutex_unlock(&log_mu);
    }
    fdinfo_clear(fd);
    return rc;
}

/* ------------------------------------------------------------------------- */
/* dup / dup2 / dup3 / pipe                                                   */
/* ------------------------------------------------------------------------- */
int dup(int oldfd) {
    if (!real_dup_fn) {
        real_dup_fn = (real_dup_t)dlsym(RTLD_NEXT, "dup");
    }
    if (g_internal) {
        return real_dup_fn(oldfd);
    }
    g_internal++;
    int newfd = real_dup_fn(oldfd);
    g_internal--;
    if (newfd >= 0) {
        fdinfo_t *fi = fdinfo_get(oldfd);
        if (fi && fi->is_target) {
            populate_fdinfo(newfd, fi->path);
            fdmap[newfd].is_target = fi->is_target;
            fdmap[newfd].owner_tid = get_tid_internal();
            fdmap[newfd].rdev = fi->rdev;
            strncpy(fdmap[newfd].uio_name, fi->uio_name, sizeof(fi->uio_name) - 1);
            pthread_mutex_lock(&log_mu);
            log_call_header("dup", oldfd, fi);
            log_printf("-> %d\n", newfd);
            pthread_mutex_unlock(&log_mu);
        }
    }
    return newfd;
}

int dup2(int oldfd, int newfd) {
    if (!real_dup2_fn) {
        real_dup2_fn = (real_dup2_t)dlsym(RTLD_NEXT, "dup2");
    }
    if (g_internal) {
        return real_dup2_fn(oldfd, newfd);
    }
    g_internal++;
    int rc = real_dup2_fn(oldfd, newfd);
    g_internal--;
    if (rc >= 0) {
        fdinfo_t *fi = fdinfo_get(oldfd);
        if (fi && fi->is_target) {
            populate_fdinfo(newfd, fi->path);
            fdmap[newfd].is_target = fi->is_target;
            fdmap[newfd].owner_tid = get_tid_internal();
            fdmap[newfd].rdev = fi->rdev;
            strncpy(fdmap[newfd].uio_name, fi->uio_name, sizeof(fi->uio_name) - 1);
            pthread_mutex_lock(&log_mu);
            log_call_header("dup2", oldfd, fi);
            log_printf("-> %d\n", newfd);
            pthread_mutex_unlock(&log_mu);
        }
    }
    return rc;
}

int dup3(int oldfd, int newfd, int flags) {
    if (!real_dup3_fn) {
        real_dup3_fn = (real_dup3_t)dlsym(RTLD_NEXT, "dup3");
    }
    if (g_internal) {
        return real_dup3_fn(oldfd, newfd, flags);
    }
    g_internal++;
    int rc = real_dup3_fn(oldfd, newfd, flags);
    g_internal--;
    if (rc >= 0) {
        fdinfo_t *fi = fdinfo_get(oldfd);
        if (fi && fi->is_target) {
            populate_fdinfo(newfd, fi->path);
            fdmap[newfd].is_target = fi->is_target;
            fdmap[newfd].owner_tid = get_tid_internal();
            fdmap[newfd].rdev = fi->rdev;
            strncpy(fdmap[newfd].uio_name, fi->uio_name, sizeof(fi->uio_name) - 1);
            pthread_mutex_lock(&log_mu);
            log_call_header("dup3", oldfd, fi);
            log_printf("-> %d flags=0x%x\n", newfd, flags);
            pthread_mutex_unlock(&log_mu);
        }
    }
    return rc;
}

int pipe(int pipefd[2]) {
    if (!real_pipe_fn) {
        real_pipe_fn = (real_pipe_t)dlsym(RTLD_NEXT, "pipe");
    }
    if (g_internal) {
        return real_pipe_fn(pipefd);
    }
    g_internal++;
    int rc = real_pipe_fn(pipefd);
    g_internal--;
    if (rc == 0) {
        fdinfo_clear(pipefd[0]);
        fdinfo_clear(pipefd[1]);
    }
    return rc;
}

int pipe2(int pipefd[2], int flags) {
    if (!real_pipe2_fn) {
        real_pipe2_fn = (real_pipe2_t)dlsym(RTLD_NEXT, "pipe2");
    }
    if (g_internal) {
        return real_pipe2_fn(pipefd, flags);
    }
    g_internal++;
    int rc = real_pipe2_fn(pipefd, flags);
    g_internal--;
    if (rc == 0) {
        fdinfo_clear(pipefd[0]);
        fdinfo_clear(pipefd[1]);
    }
    return rc;
}

/* ------------------------------------------------------------------------- */
/* lseek                                                                      */
/* ------------------------------------------------------------------------- */
off_t lseek(int fd, off_t offset, int whence) {
    if (!real_lseek_fn) {
        real_lseek_fn = (real_lseek_t)dlsym(RTLD_NEXT, "lseek");
    }
    if (g_internal) {
        return real_lseek_fn(fd, offset, whence);
    }
    g_internal++;
    off_t rc = real_lseek_fn(fd, offset, whence);
    g_internal--;
    if (should_trace_fd(fd)) {
        fdinfo_t *fi = fdinfo_get(fd);
        pthread_mutex_lock(&log_mu);
        log_call_header("lseek", fd, fi);
        log_printf("off=%lld whence=%d -> %lld errno=%d\n",
                   (long long)offset,
                   whence,
                   (long long)rc,
                   errno);
        pthread_mutex_unlock(&log_mu);
    }
    return rc;
}

off64_t lseek64(int fd, off64_t offset, int whence) {
    if (!real_lseek64_fn) {
        real_lseek64_fn = (real_lseek64_t)dlsym(RTLD_NEXT, "lseek64");
    }
    if (g_internal) {
        return real_lseek64_fn(fd, offset, whence);
    }
    g_internal++;
    off64_t rc = real_lseek64_fn(fd, offset, whence);
    g_internal--;
    if (should_trace_fd(fd)) {
        fdinfo_t *fi = fdinfo_get(fd);
        pthread_mutex_lock(&log_mu);
        log_call_header("lseek64", fd, fi);
        log_printf("off=%lld whence=%d -> %lld errno=%d\n",
                   (long long)offset,
                   whence,
                   (long long)rc,
                   errno);
        pthread_mutex_unlock(&log_mu);
    }
    return rc;
}

/* ------------------------------------------------------------------------- */
/* fcntl                                                                      */
/* ------------------------------------------------------------------------- */
int fcntl(int fd, int cmd, ...) {
    if (!real_fcntl_fn) {
        real_fcntl_fn = (real_fcntl_t)dlsym(RTLD_NEXT, "fcntl");
    }

    int has_arg = 0;
    switch (cmd) {
#ifdef F_DUPFD
        case F_DUPFD:
#endif
#ifdef F_DUPFD_CLOEXEC
        case F_DUPFD_CLOEXEC:
#endif
#ifdef F_SETFD
        case F_SETFD:
#endif
#ifdef F_SETFL
        case F_SETFL:
#endif
#ifdef F_SETOWN
        case F_SETOWN:
#endif
#ifdef F_SETSIG
        case F_SETSIG:
#endif
#ifdef F_SETLEASE
        case F_SETLEASE:
#endif
#ifdef F_NOTIFY
        case F_NOTIFY:
#endif
#ifdef F_SETPIPE_SZ
        case F_SETPIPE_SZ:
#endif
#ifdef F_ADD_SEALS
        case F_ADD_SEALS:
#endif
#ifdef F_SETLK
        case F_SETLK:
#endif
#ifdef F_SETLKW
        case F_SETLKW:
#endif
#if defined(F_SETLK64) && (!defined(F_SETLK) || F_SETLK64 != F_SETLK)
        case F_SETLK64:
#endif
#if defined(F_SETLKW64) && (!defined(F_SETLKW) || F_SETLKW64 != F_SETLKW)
        case F_SETLKW64:
#endif
#ifdef F_OFD_SETLK
        case F_OFD_SETLK:
#endif
#ifdef F_OFD_SETLKW
        case F_OFD_SETLKW:
#endif
            has_arg = 1;
            break;
        default:
            break;
    }

    va_list ap;
    unsigned long arg = 0;
    if (has_arg) {
        va_start(ap, cmd);
        arg = va_arg(ap, unsigned long);
        va_end(ap);
    }

    if (g_internal) {
        return has_arg ? real_fcntl_fn(fd, cmd, arg) : real_fcntl_fn(fd, cmd);
    }

    g_internal++;
    int rc = has_arg ? real_fcntl_fn(fd, cmd, arg) : real_fcntl_fn(fd, cmd);
    g_internal--;

    if (should_trace_fd(fd)) {
        fdinfo_t *fi = fdinfo_get(fd);
        pthread_mutex_lock(&log_mu);
        log_call_header("fcntl", fd, fi);
        if (has_arg) {
            log_printf("cmd=0x%x arg=0x%lx -> %d errno=%d\n", cmd, arg, rc, errno);
        } else {
            log_printf("cmd=0x%x -> %d errno=%d\n", cmd, rc, errno);
        }
        pthread_mutex_unlock(&log_mu);
    }
    return rc;
}

/* ------------------------------------------------------------------------- */
/* read / write                                                               */
/* ------------------------------------------------------------------------- */
ssize_t read(int fd, void *buf, size_t count) {
    if (!real_read_fn) {
        real_read_fn = (real_read_t)dlsym(RTLD_NEXT, "read");
    }
    if (g_internal) {
        return real_read_fn(fd, buf, count);
    }
    g_internal++;
    ssize_t rc = real_read_fn(fd, buf, count);
    g_internal--;
    if (rc >= 0 && should_trace_fd(fd)) {
        fdinfo_t *fi = fdinfo_get(fd);
        pthread_mutex_lock(&log_mu);
        log_call_header("read", fd, fi);
        log_printf("count=%zu -> %zd errno=%d\n", count, rc, errno);
        if (rc > 0) {
            hexdump_buffer(buf, (size_t)rc);
        }
        pthread_mutex_unlock(&log_mu);
    }
    return rc;
}

ssize_t write(int fd, const void *buf, size_t count) {
    if (!real_write_fn) {
        real_write_fn = (real_write_t)dlsym(RTLD_NEXT, "write");
    }
    if (g_internal) {
        return real_write_fn(fd, buf, count);
    }
    g_internal++;
    ssize_t rc = real_write_fn(fd, buf, count);
    g_internal--;
    if (rc >= 0 && should_trace_fd(fd)) {
        fdinfo_t *fi = fdinfo_get(fd);
        pthread_mutex_lock(&log_mu);
        log_call_header("write", fd, fi);
        log_printf("count=%zu -> %zd errno=%d\n", count, rc, errno);
        if (rc > 0) {
            hexdump_buffer(buf, (size_t)rc);
        }
        pthread_mutex_unlock(&log_mu);
    }
    return rc;
}

/* ------------------------------------------------------------------------- */
/* mmap / munmap                                                              */
/* ------------------------------------------------------------------------- */
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
    if (!real_mmap_fn) {
        real_mmap_fn = (real_mmap_t)dlsym(RTLD_NEXT, "mmap");
    }
    if (g_internal) {
        return real_mmap_fn(addr, length, prot, flags, fd, offset);
    }
    g_internal++;
    void *result = real_mmap_fn(addr, length, prot, flags, fd, offset);
    g_internal--;
    if (fd >= 0 && should_trace_fd(fd)) {
        fdinfo_t *fi = fdinfo_get(fd);
        pthread_mutex_lock(&log_mu);
        log_call_header("mmap", fd, fi);
        log_printf("addr=%p len=0x%zx prot=0x%x flags=0x%x off=0x%llx -> %p errno=%d\n",
                   addr,
                   length,
                   prot,
                   flags,
                   (long long)offset,
                   result,
                   errno);
        pthread_mutex_unlock(&log_mu);
    }
    return result;
}

int munmap(void *addr, size_t length) {
    if (!real_munmap_fn) {
        real_munmap_fn = (real_munmap_t)dlsym(RTLD_NEXT, "munmap");
    }
    if (g_internal) {
        return real_munmap_fn(addr, length);
    }
    g_internal++;
    int rc = real_munmap_fn(addr, length);
    g_internal--;
    pthread_mutex_lock(&log_mu);
    char ts[64];
    char tname[32];
    now_timestamp(ts, sizeof(ts));
    thread_name(tname, sizeof(tname));
    log_printf("[%d/%d %s thr=%s] munmap(addr=%p len=0x%zx) = %d errno=%d\n",
               getpid(), (int)get_tid_internal(), ts,
               tname[0] ? tname : "?",
               addr,
               length,
               rc,
               errno);
    pthread_mutex_unlock(&log_mu);
    return rc;
}

/* ------------------------------------------------------------------------- */
/* select / poll family                                                       */
/* ------------------------------------------------------------------------- */
static void log_poll_events(short events, const char *prefix) {
    if (!events) {
        log_printf("%s0", prefix);
        return;
    }
    int first = 1;
#define PRINT_EVENT(ev, name)                 \
    do {                                      \
        if (events & (ev)) {                  \
            log_printf("%s%s",               \
                       (first ? prefix : "|"), (name)); \
            first = 0;                        \
        }                                     \
    } while (0)
    PRINT_EVENT(POLLIN, "IN");
    PRINT_EVENT(POLLOUT, "OUT");
    PRINT_EVENT(POLLERR, "ERR");
    PRINT_EVENT(POLLHUP, "HUP");
    PRINT_EVENT(POLLPRI, "PRI");
    PRINT_EVENT(POLLRDNORM, "RDNORM");
    PRINT_EVENT(POLLRDBAND, "RDBAND");
    PRINT_EVENT(POLLWRNORM, "WRNORM");
    PRINT_EVENT(POLLWRBAND, "WRBAND");
    PRINT_EVENT(POLLNVAL, "NVAL");
#undef PRINT_EVENT
}

static void log_epoll_events(uint32_t events, const char *prefix) {
    if (!events) {
        log_printf("%s0", prefix);
        return;
    }
    int first = 1;
#define PRINT_EP_EVENT(ev, name)              \
    do {                                      \
        if (events & (ev)) {                  \
            log_printf("%s%s",               \
                       (first ? prefix : "|"), (name)); \
            first = 0;                        \
        }                                     \
    } while (0)
    PRINT_EP_EVENT(EPOLLIN, "IN");
    PRINT_EP_EVENT(EPOLLOUT, "OUT");
    PRINT_EP_EVENT(EPOLLPRI, "PRI");
    PRINT_EP_EVENT(EPOLLERR, "ERR");
    PRINT_EP_EVENT(EPOLLHUP, "HUP");
    PRINT_EP_EVENT(EPOLLRDHUP, "RDHUP");
    PRINT_EP_EVENT(EPOLLET, "ET");
    PRINT_EP_EVENT(EPOLLONESHOT, "ONESHOT");
    PRINT_EP_EVENT(EPOLLEXCLUSIVE, "EXCLUSIVE");
#undef PRINT_EP_EVENT
}

int poll(struct pollfd *fds, nfds_t nfds, int timeout) {
    if (!real_poll_fn) {
        real_poll_fn = (real_poll_t)dlsym(RTLD_NEXT, "poll");
    }
    if (g_internal) {
        return real_poll_fn(fds, nfds, timeout);
    }
    g_internal++;
    int rc = real_poll_fn(fds, nfds, timeout);
    g_internal--;
    pthread_mutex_lock(&log_mu);
    char ts[64];
    char tname[32];
    now_timestamp(ts, sizeof(ts));
    thread_name(tname, sizeof(tname));
    log_printf("[%d/%d %s thr=%s] poll(nfds=%zu timeout=%d) -> %d errno=%d\n",
               getpid(), (int)get_tid_internal(), ts,
               tname[0] ? tname : "?",
               (size_t)nfds,
               timeout,
               rc,
               errno);
    for (nfds_t i = 0; i < nfds; ++i) {
        int fd = fds[i].fd;
        fdinfo_t *fi = fdinfo_get(fd);
        if (fi && fi->is_target) {
            log_printf("  fd=%d path=%s events=", fd, fi->path);
            log_poll_events(fds[i].events, "");
            log_printf(" revents=");
            log_poll_events(fds[i].revents, "");
            log_printf("\n");
        }
    }
    pthread_mutex_unlock(&log_mu);
    return rc;
}

int ppoll(struct pollfd *fds, nfds_t nfds, const struct timespec *ts, const sigset_t *set) {
    if (!real_ppoll_fn) {
        real_ppoll_fn = (real_ppoll_t)dlsym(RTLD_NEXT, "ppoll");
    }
    if (g_internal) {
        return real_ppoll_fn(fds, nfds, ts, set);
    }
    g_internal++;
    int rc = real_ppoll_fn(fds, nfds, ts, set);
    g_internal--;
    return rc;
}

int select(int nfds, fd_set *rfds, fd_set *wfds, fd_set *efds, struct timeval *timeout) {
    if (!real_select_fn) {
        real_select_fn = (real_select_t)dlsym(RTLD_NEXT, "select");
    }
    if (g_internal) {
        return real_select_fn(nfds, rfds, wfds, efds, timeout);
    }
    g_internal++;
    int rc = real_select_fn(nfds, rfds, wfds, efds, timeout);
    g_internal--;
    pthread_mutex_lock(&log_mu);
    char ts[64];
    char tname[32];
    now_timestamp(ts, sizeof(ts));
    thread_name(tname, sizeof(tname));
    log_printf("[%d/%d %s thr=%s] select(nfds=%d) -> %d errno=%d\n",
               getpid(), (int)get_tid_internal(), ts,
               tname[0] ? tname : "?",
               nfds,
               rc,
               errno);
    for (int fd = 0; fd < nfds; ++fd) {
        fdinfo_t *fi = fdinfo_get(fd);
        if (!fi || !fi->is_target) {
            continue;
        }
        if ((rfds && FD_ISSET(fd, rfds)) ||
            (wfds && FD_ISSET(fd, wfds)) ||
            (efds && FD_ISSET(fd, efds))) {
            log_printf("  fd=%d path=%s", fd, fi->path);
            if (rfds && FD_ISSET(fd, rfds)) {
                log_printf(" R");
            }
            if (wfds && FD_ISSET(fd, wfds)) {
                log_printf(" W");
            }
            if (efds && FD_ISSET(fd, efds)) {
                log_printf(" E");
            }
            log_printf("\n");
        }
    }
    pthread_mutex_unlock(&log_mu);
    return rc;
}

int pselect(int nfds, fd_set *rfds, fd_set *wfds, fd_set *efds,
            const struct timespec *timeout, const sigset_t *sigmask) {
    if (!real_pselect_fn) {
        real_pselect_fn = (real_pselect_t)dlsym(RTLD_NEXT, "pselect");
    }
    if (g_internal) {
        return real_pselect_fn(nfds, rfds, wfds, efds, timeout, sigmask);
    }
    g_internal++;
    int rc = real_pselect_fn(nfds, rfds, wfds, efds, timeout, sigmask);
    g_internal--;
    return rc;
}

int epoll_create(int size) {
    if (!real_epoll_create_fn) {
        real_epoll_create_fn = (real_epoll_create_t)dlsym(RTLD_NEXT, "epoll_create");
    }
    if (g_internal) {
        return real_epoll_create_fn(size);
    }
    g_internal++;
    int fd = real_epoll_create_fn(size);
    g_internal--;
    if (fd >= 0) {
        fdinfo_clear(fd);
    }
    return fd;
}

int epoll_create1(int flags) {
    if (!real_epoll_create1_fn) {
        real_epoll_create1_fn = (real_epoll_create1_t)dlsym(RTLD_NEXT, "epoll_create1");
    }
    if (g_internal) {
        return real_epoll_create1_fn(flags);
    }
    g_internal++;
    int fd = real_epoll_create1_fn(flags);
    g_internal--;
    if (fd >= 0) {
        fdinfo_clear(fd);
    }
    return fd;
}

int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event) {
    if (!real_epoll_ctl_fn) {
        real_epoll_ctl_fn = (real_epoll_ctl_t)dlsym(RTLD_NEXT, "epoll_ctl");
    }
    if (g_internal) {
        return real_epoll_ctl_fn(epfd, op, fd, event);
    }
    uint32_t events = event ? event->events : 0;
    g_internal++;
    int rc = real_epoll_ctl_fn(epfd, op, fd, event);
    g_internal--;
    if (should_trace_fd(fd)) {
        fdinfo_t *fi = fdinfo_get(fd);
        pthread_mutex_lock(&log_mu);
        log_call_header("epoll_ctl", fd, fi);
        log_printf("op=%d -> %d errno=%d events=", op, rc, errno);
        log_epoll_events(events, "");
        log_printf("\n");
        pthread_mutex_unlock(&log_mu);
    }
    return rc;
}

int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout) {
    if (!real_epoll_wait_fn) {
        real_epoll_wait_fn = (real_epoll_wait_t)dlsym(RTLD_NEXT, "epoll_wait");
    }
    if (g_internal) {
        return real_epoll_wait_fn(epfd, events, maxevents, timeout);
    }
    g_internal++;
    int rc = real_epoll_wait_fn(epfd, events, maxevents, timeout);
    g_internal--;
    pthread_mutex_lock(&log_mu);
    char ts[64];
    char tname[32];
    now_timestamp(ts, sizeof(ts));
    thread_name(tname, sizeof(tname));
    log_printf("[%d/%d %s thr=%s] epoll_wait(max=%d timeout=%d) -> %d errno=%d\n",
               getpid(), (int)get_tid_internal(), ts,
               tname[0] ? tname : "?",
               maxevents,
               timeout,
               rc,
               errno);
    if (rc > 0) {
        for (int i = 0; i < rc; ++i) {
            int fd = events[i].data.fd;
            fdinfo_t *fi = fdinfo_get(fd);
            if (fi && fi->is_target) {
                log_printf("  fd=%d path=%s events=", fd, fi->path);
                log_epoll_events(events[i].events, "");
                log_printf("\n");
            }
        }
    }
    pthread_mutex_unlock(&log_mu);
    return rc;
}

int epoll_pwait(int epfd, struct epoll_event *events, int maxevents, int timeout, const sigset_t *set) {
    if (!real_epoll_pwait_fn) {
        real_epoll_pwait_fn = (real_epoll_pwait_t)dlsym(RTLD_NEXT, "epoll_pwait");
    }
    if (g_internal) {
        return real_epoll_pwait_fn(epfd, events, maxevents, timeout, set);
    }
    g_internal++;
    int rc = real_epoll_pwait_fn(epfd, events, maxevents, timeout, set);
    g_internal--;
    return rc;
}

/* ------------------------------------------------------------------------- */
/* ioctl                                                                      */
/* ------------------------------------------------------------------------- */
int ioctl(int fd, unsigned long request, ...) {
    if (!real_ioctl_fn) {
        real_ioctl_fn = (real_ioctl_t)dlsym(RTLD_NEXT, "ioctl");
    }
    va_list ap;
    va_start(ap, request);
    unsigned long arg = 0;
    int has_arg = 0;
    size_t forced_size = 0;
    int force_arg = ioctl_requires_hidden_arg(request, &forced_size);
    if ((_IOC_DIR(request) != _IOC_NONE) || (_IOC_SIZE(request) != 0) || force_arg) {
        arg = va_arg(ap, unsigned long);
        has_arg = 1;
    }
    va_end(ap);

    if (g_internal) {
        return has_arg ? real_ioctl_fn(fd, request, arg) : real_ioctl_fn(fd, request);
    }

    void *arg_ptr = has_arg ? (void *)arg : NULL;
    size_t arg_size = has_arg ? (size_t)_IOC_SIZE(request) : 0;
    if (has_arg && arg_size == 0 && forced_size) {
        arg_size = forced_size;
    }
    int dir = _IOC_DIR(request);

    unsigned char *pre_image = NULL;
    if (has_arg && arg_ptr && (dir & _IOC_WRITE) && arg_size && arg_size <= 65536) {
        pre_image = (unsigned char *)malloc(arg_size);
        if (pre_image) {
            memcpy(pre_image, arg_ptr, arg_size);
        }
    }

    int rc;
    g_internal++;
    if (has_arg) {
        rc = real_ioctl_fn(fd, request, arg);
    } else {
        rc = real_ioctl_fn(fd, request);
    }
    int saved_errno = errno;
    g_internal--;

    if (should_trace_fd(fd)) {
        fdinfo_t *fi = fdinfo_get(fd);
        pthread_mutex_lock(&log_mu);
        log_call_header("ioctl", fd, fi);
        log_printf("req=0x%lx dir=0x%x size=%zu -> %d errno=%d\n",
                   request,
                   dir,
                   arg_size,
                   rc,
                   saved_errno);
        if (has_arg) {
            log_printf("  arg=%p\n", arg_ptr);
            if (arg_size && arg_ptr) {
                if (pre_image && (dir & _IOC_WRITE)) {
                    log_printf("  -- before --\n");
                    hexdump_buffer(pre_image, arg_size);
                }
                if (dir & _IOC_READ) {
                    log_printf("  -- after --\n");
                    hexdump_buffer(arg_ptr, arg_size);
                }
            }
        }
        maybe_log_uio_name(fi);
        pthread_mutex_unlock(&log_mu);
    }

    if (pre_image) {
        free(pre_image);
    }
    errno = saved_errno;
    return rc;
}

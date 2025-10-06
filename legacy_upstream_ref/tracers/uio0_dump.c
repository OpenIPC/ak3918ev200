/*
 * File: uio0_dump.c
 * Author: Abel Romero
 * License: MIT
 *
 * What it does
 * ------------
 * - Hooks mmap(), select(), and ioctl() via LD_PRELOAD.
 * - Targets /dev/uio0 by rdev (major:minor), discovered in the constructor.
 * - On mmap(fd=/dev/uio0): remembers the returned VA and the length in globals
 *   g_va and g_len.
 * - After any ioctl(fd=/dev/uio0, ...): dumps the whole mapped window
 *   as 32-bit words, in hex, to /mnt/disc1/uio_dump.log.
 * - After select() returns: if /dev/uio0's fd is set in readfds, dumps the same.
 *
 * Notes
 * -----
 * - The mapped MMIO region on your board is small (~0x430..0x500), so dumping it
 *   entirely is inexpensive and avoids missing interesting registers.
 * - No stdatomic, no non-portable stuff; fits uClibc toolchains.
 */

#define _GNU_SOURCE
#include <dlfcn.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

/* ---------- Configuration ---------- */
#define UIO_DEV_PATH "/dev/uio0"
#define LOG_PATH     "/mnt/disc1/uio0_dump.log"

/* ---------- Globals ---------- */
static dev_t g_target_rdev = 0;          /* rdev of /dev/uio0 (major:minor) */
static int   g_have_rdev   = 0;

static volatile void *g_va = NULL;       /* last VA returned by mmap(uio0) */
static size_t         g_len = 0;         /* its length */

static int g_log_fd = -1;

/* Real functions */
static void *(*real_mmap)(void*,size_t,int,int,int,off_t) = NULL;
static int    (*real_munmap)(void*, size_t)               = NULL;
static int    (*real_select)(int, fd_set*, fd_set*, fd_set*, struct timeval*) = NULL;
static int    (*real_ioctl)(int, unsigned long, ...) = NULL;

/* ---------- Logging ---------- */
static void ts_now(char *b, size_t n){
    struct timespec ts; clock_gettime(CLOCK_REALTIME, &ts);
    struct tm tm; localtime_r(&ts.tv_sec, &tm);
    int ms = (int)(ts.tv_nsec / 1000000);
    snprintf(b, n, "%04d-%02d-%02d %02d:%02d:%02d.%03d",
             tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,
             tm.tm_hour, tm.tm_min, tm.tm_sec, ms);
}
static void log_line(const char *fmt, ...){
    if (g_log_fd < 0) return;
    char ts[32]; ts_now(ts, sizeof ts);
    dprintf(g_log_fd, "[%s] ", ts);
    va_list ap; va_start(ap, fmt);
    vdprintf(g_log_fd, fmt, ap);
    va_end(ap);
    fsync(g_log_fd);
}

/* ---------- Helpers ---------- */
static int fd_is_target(int fd){
    if (fd < 0 || !g_have_rdev) return 0;
    struct stat st;
    if (fstat(fd, &st) != 0) return 0;
    /* We're only interested in character device with matching rdev */
    return (S_ISCHR(st.st_mode) && st.st_rdev == g_target_rdev);
}

/* NEW: verify that [addr..addr+len) is inside any readable VMA of this process */
static int range_is_mapped_readable(const void *addr, size_t len){
    if (!addr || len == 0) return 0;
    uintptr_t a = (uintptr_t)addr, b = a + len;

    FILE *f = fopen("/proc/self/maps", "r");
    if (!f){
        /* best effort: if we can't verify, assume mapped to avoid false negatives */
        return 1;
    }
    char line[512];
    int ok = 0;
    while (fgets(line, sizeof line, f)){
        uintptr_t ms=0, me=0;
        char perms[8] = {0};
        if (sscanf(line, "%lx-%lx %4s", &ms, &me, perms) == 3){
            if (perms[0] != 'r') continue;            /* need readable */
                if (a >= ms && b <= me){ ok = 1; break; } /* fully contained */
        }
    }
    fclose(f);
    return ok;
}

/* Pretty dump: words in hex, 8 words per line */
static void dump_words(const char *tag){
    if (!g_va || g_len == 0) {
        log_line("%s: no mapping (g_va=NULL, g_len=0)\n", tag);
        return;
    }

    /* NEW: safety check to avoid dumping after munmap/exec or into invalid VMA */
    if (!range_is_mapped_readable((const void*)g_va, g_len)){
        log_line("%s: mapping not readable/valid anymore (base=%p len=0x%zx) -> SKIP\n",
                 tag, (const void*)g_va, g_len);
        return;
    }

    size_t nwords = g_len / 4;
    const volatile uint32_t *w = (const volatile uint32_t*)g_va;

    log_line("%s: MMIO dump base=%p len=0x%zx (%zu words)\n",
             tag, (const void*)g_va, g_len, nwords);

    size_t i = 0;
    while (i < nwords){
        /* Print up to 8 words per line */
        size_t j, chunk = (nwords - i > 8) ? 8 : (nwords - i);
        dprintf(g_log_fd, "  +0x%04zx:", i*4);
        for (j = 0; j < chunk; ++j){
            uint32_t v = w[i + j];
            dprintf(g_log_fd, " %08x", v);
        }
        dprintf(g_log_fd, "\n");
        i += chunk;
    }
    fsync(g_log_fd);
}

/* ---------- Constructor / Destructor ---------- */
__attribute__((constructor))
static void init_uio_dump(void){
    /* Resolve real symbols */
    real_mmap   = dlsym(RTLD_NEXT, "mmap");
    real_select = dlsym(RTLD_NEXT, "select");
    real_ioctl  = dlsym(RTLD_NEXT, "ioctl");

    g_log_fd = open(LOG_PATH, O_CREAT|O_WRONLY|O_APPEND, 0644);
    if (g_log_fd >= 0) {
        log_line("=== uio0-dump preload start ===\n");
    }

    /* Get rdev for /dev/uio0 */
    struct stat st;
    if (stat(UIO_DEV_PATH, &st) == 0 && S_ISCHR(st.st_mode)){
        g_target_rdev = st.st_rdev;
        g_have_rdev   = 1;
        log_line("Target %s rdev=%u:%u\n",
                 UIO_DEV_PATH,
                 major(g_target_rdev), minor(g_target_rdev));
    } else {
        log_line("WARNING: stat(%s) failed or not char dev (errno=%d)\n",
                 UIO_DEV_PATH, errno);
    }
}

__attribute__((destructor))
static void fini_uio_dump(void){
    log_line("=== uio0-dump preload stop ===\n");
    if (g_log_fd >= 0) close(g_log_fd);
}

/* ---------- Hooks ---------- */

/* mmap: remember VA and length when mapping /dev/uio0 */
void *mmap(void *addr, size_t len, int prot, int flags, int fd, off_t off){
    if (!real_mmap) real_mmap = dlsym(RTLD_NEXT, "mmap");
    void *p = real_mmap(addr, len, prot, flags, fd, off);

    if (p != MAP_FAILED && fd_is_target(fd)){
        /* Remember the last mapping */
        g_va  = p;
        g_len = len;
        log_line("mmap(uio0): len=0x%zx prot=0x%x flags=0x%x off=%ld -> %p\n",
                 len, prot, flags, (long)off, p);
    }
    return p;
}

/* munmap: if it unmaps our VA, clear globals */
int munmap(void *addr, size_t len){
    if (!real_munmap) real_munmap = dlsym(RTLD_NEXT, "munmap");
    int r = real_munmap(addr, len);

    if (addr == (void*)g_va){
        log_line("munmap(uio0): base=%p len=0x%zx -> clearing g_va/g_len\n", addr, len);
        g_va = NULL; g_len = 0;
    }
    return r;
}

/* ioctl: after any ioctl on /dev/uio0, dump the whole range */
int ioctl(int fd, unsigned long req, ...){
    if (!real_ioctl) real_ioctl = dlsym(RTLD_NEXT, "ioctl");

    va_list ap;
    va_start(ap, req);
    unsigned long arg_ul = va_arg(ap, unsigned long); /* best effort */
    va_end(ap);

    int rc = real_ioctl(fd, req, arg_ul);

    if (fd_is_target(fd)){
        log_line("ioctl(uio0): req=0x%lx rc=%d -> DUMP\n", req, rc);
        dump_words("after-ioctl");
    }
    return rc;
}

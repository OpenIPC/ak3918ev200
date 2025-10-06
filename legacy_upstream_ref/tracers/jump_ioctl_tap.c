/*
 * Author: Abel Romero
 * License: MIT
 */
#define _GNU_SOURCE
#include <dlfcn.h>
#include <link.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/syscall.h>

#ifndef DEFAULT_GHIDRA_VMA
#define DEFAULT_GHIDRA_VMA 0x000200f4UL
#endif

static uintptr_t parse_env_hex(const char *name, uintptr_t defv) {
    const char *s = getenv(name);
    if (!s || !*s) return defv;
    errno = 0;
    uintptr_t v = (uintptr_t)strtoull(s, NULL, 0);
    return errno ? defv : v;
}

static int getenv_flag(const char *name) {
    const char *s = getenv(name);
    return (s && *s && strcmp(s,"0")!=0 && strcasecmp(s,"false")!=0) ? 1 : 0;
}

struct exe_bias {
    uintptr_t dlpi_addr;     // load base (0 for ET_EXEC)
    uintptr_t min_vaddr;     // mínimo p_vaddr entre PT_LOAD
    int found;
};

static int phdr_cb(struct dl_phdr_info *info, size_t size, void *data) {
    struct exe_bias *out = (struct exe_bias*)data;
    // El ejecutable principal suele venir con info->dlpi_name vacío o NULL
    if (info->dlpi_name && info->dlpi_name[0] != '\0') return 0;

    uintptr_t minv = (uintptr_t)-1;
    for (int i = 0; i < info->dlpi_phnum; i++) {
        if (info->dlpi_phdr[i].p_type == PT_LOAD) {
            uintptr_t v = (uintptr_t)info->dlpi_phdr[i].p_vaddr;
            if (v < minv) minv = v;
        }
    }
    if (minv == (uintptr_t)-1) minv = 0;
    out->dlpi_addr = (uintptr_t)info->dlpi_addr;
    out->min_vaddr = minv;
    out->found = 1;
    return 1; // parar iteración
}

static void (*resolve_target(void))(void) {
    uintptr_t gh_addr = parse_env_hex("GHIDRA_VMA", (uintptr_t)DEFAULT_GHIDRA_VMA);

    struct exe_bias eb = {0};
    dl_iterate_phdr(phdr_cb, &eb);

    uintptr_t runtime = 0;
    if (!eb.found) {
        // Fallback: si no pudimos leer phdr, asumir ET_EXEC
        runtime = gh_addr;
    } else if (eb.dlpi_addr == 0) {
        // ET_EXEC (no-PIE): la VMA de Ghidra ya es runtime
        runtime = gh_addr;
    } else {
        // PIE (ET_DYN): add load base, subtract min vaddr
        runtime = eb.dlpi_addr + (gh_addr - eb.min_vaddr);
    }

    if (getenv_flag("GHIDRA_THUMB")) {
        runtime |= 1u; // puntero Thumb
    }

    return (void (*)(void))(uintptr_t)runtime;
}

/* --------- Wrap de main --------- */
static int (*saved_main)(int,char**,char**)=NULL;

static int my_main(int argc, char **argv, char **envp) {
    void (*fn)(void) = resolve_target();
    // Log mínimo por stderr (útil si algo va mal)
    dprintf(STDERR_FILENO, "[jump] calling target @ %p\n", (void*)fn);
    if (fn) fn();

    if (getenv_flag("KEEP_RUNNING")) {
        dprintf(STDERR_FILENO, "[jump] KEEP_RUNNING=1 -> continuing with real main\n");
        return saved_main ? saved_main(argc, argv, envp) : 0;
    } else {
        dprintf(STDERR_FILENO, "[jump] exiting after target return\n");
        _exit(0); // termina el proceso tras ejecutar tu función
    }
    return 0; // no se alcanza
}

/* --------- Interposición glibc/musl --------- */
typedef int (*libc_start_main_t)(int (*main)(int,char**,char**),
                                 int, char **, void (*)(void), void (*)(void),
                                 void (*)(void), void*);

int __libc_start_main(int (*main)(int,char**,char**),
                      int argc, char **ubp_av,
                      void (*init)(void), void (*fini)(void),
                      void (*rtld_fini)(void), void *stack_end)
{
    libc_start_main_t real = (libc_start_main_t)dlsym(RTLD_NEXT, "__libc_start_main");
    if (!real) _exit(127);

    saved_main = main; // guarda el main real
    return real(my_main, argc, ubp_av, init, fini, rtld_fini, stack_end);
}

/* --------- Interposición uClibc --------- */
/* uClibc usa un símbolo distinto en muchos builds antiguos. */
typedef int (*uclibc_main_t)(int (*main)(int,char**,char**),
                             int, char **, void (*)(void), void (*)(void),
                             void (*)(void), void*);

int __uClibc_main(int (*main)(int,char**,char**),
                  int argc, char **argv,
                  void (*app_init)(void), void (*app_fini)(void),
                  void (*rtld_fini)(void), void *stack_end)
{
    uclibc_main_t real = (uclibc_main_t)dlsym(RTLD_NEXT, "__uClibc_main");
    if (!real) {
        // Si no estamos en uClibc, intentar redirigir a glibc (por si el loader resuelve aquí)
        libc_start_main_t real_glibc = (libc_start_main_t)dlsym(RTLD_NEXT, "__libc_start_main");
        if (real_glibc) {
            saved_main = main;
            return real_glibc(my_main, argc, argv, app_init, app_fini, rtld_fini, stack_end);
        }
        _exit(127);
    }

    saved_main = main;
    return real(my_main, argc, argv, app_init, app_fini, rtld_fini, stack_end);
}
// ak_ioctl_tap.c
// LD_PRELOAD tracer to capture ioctls (and opens/mmap) for Anyka V200 vendor IPC.
// Focus: /dev/isp_char (type 0x49), /dev/ion, /dev/uio*, /dev/video*, /dev/akpcm*
// Captures 4-byte payloads and attempts nested-pointer dumps via /proc/self/mem.
// Writes a plain-text log easy to replay.
//
// Build: arm-linux-gnueabi-gcc -shared -fPIC -O2 -D_GNU_SOURCE -ldl -o ak_ioctl_tap.so ak_ioctl_tap.c
// Usage: LD_PRELOAD=./ak_ioctl_tap.so /ipc/ipc.original ...
// Output: /mnt/disc1/akisp_tap.log (falls back to /tmp/akisp_tap.log)
#define _GNU_SOURCE
#include <dlfcn.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

static int (*real_open)(const char *pathname, int flags, ...) = NULL;
static int (*real_open64)(const char *pathname, int flags, ...) = NULL;
static int (*real_openat)(int dirfd, const char *pathname, int flags, ...) = NULL;
static int (*real_close)(int fd) = NULL;
static int (*real_ioctl)(int fd, unsigned long req, ...) = NULL;
static void *(*real_mmap)(void *addr, size_t length, int prot, int flags, int fd, off_t offset) = NULL;
static void *(*real_mmap64)(void *addr, size_t length, int prot, int flags, int fd, off64_t offset) = NULL;

static FILE *g_logf = NULL;
static pthread_mutex_t g_mu = PTHREAD_MUTEX_INITIALIZER;
static int g_memfd = -1;

static const char *maps_path = "/proc/self/maps";
static const char *mem_path  = "/proc/self/mem";

typedef struct { uintptr_t start, end; } maprng;
static maprng *g_maps = NULL;
static size_t g_nmaps = 0;

static void log_open_file() {
    if (g_logf) return;
    const char *p = "/mnt/disc1/akisp_tap.log";
    g_logf = fopen(p, "a");
    if (!g_logf) g_logf = fopen("/tmp/akisp_tap.log", "a");
    if (!g_logf) g_logf = stderr;
    setvbuf(g_logf, NULL, _IOLBF, 0);
}

static void refresh_maps() {
    if (g_maps) { free(g_maps); g_maps=NULL; g_nmaps=0; }
    FILE *f = fopen(maps_path, "r");
    if (!f) return;
    char line[512];
    size_t cap=16; g_maps = (maprng*)malloc(cap*sizeof(maprng));
    while (fgets(line,sizeof(line),f)) {
        uintptr_t s=0,e=0;
        if (sscanf(line, "%lx-%lx", &s, &e) == 2) {
            if (g_nmaps==cap){ cap*=2; g_maps=(maprng*)realloc(g_maps,cap*sizeof(maprng)); }
            g_maps[g_nmaps++] = (maprng){ s,e };
        }
    }
    fclose(f);
}

static bool in_maps(uintptr_t p) {
    for (size_t i=0;i<g_nmaps;i++){
        if (p>=g_maps[i].start && p<g_maps[i].end) return true;
    }
    return false;
}

static void hex_dump_line(FILE *f, const uint8_t *buf, size_t n) {
    static const char *hexd = "0123456789abcdef";
    for (size_t i=0;i<n;i++){
        unsigned b = buf[i];
        fputc(hexd[b>>4], f);
        fputc(hexd[b&0xf], f);
    }
}

static void vlogf(const char *fmt, va_list ap) {
    log_open_file();
    vfprintf(g_logf, fmt, ap);
}

static void dlogf(const char *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    vlogf(fmt, ap);
    va_end(ap);
}

static void safe_read_mem(uintptr_t addr, uint8_t *out, size_t len, ssize_t *outn) {
    if (g_memfd < 0) g_memfd = open(mem_path, O_RDONLY);
    if (g_memfd >= 0) {
        ssize_t n = pread(g_memfd, out, len, (off_t)addr);
        if (outn) *outn = n;
    } else {
        if (outn) *outn = -1;
    }
}

// fd → path table
typedef struct { int fd; char path[128]; } fdent;
static fdent g_fds[256];
static int find_slot(int fd){ for (int i=0;i<256;i++) if (g_fds[i].fd==fd) return i; return -1; }
static int find_empty(){ for (int i=0;i<256;i++) if (g_fds[i].fd==0) return i; return -1; }
static void record_fd(int fd, const char *path){
    pthread_mutex_lock(&g_mu);
    int s = find_slot(fd);
    if (s<0) s = find_empty();
    if (s>=0){
        g_fds[s].fd = fd;
        strncpy(g_fds[s].path, path?path:"", sizeof(g_fds[s].path)-1);
        g_fds[s].path[sizeof(g_fds[s].path)-1] = 0;
    }
    pthread_mutex_unlock(&g_mu);
}
static const char *path_of(int fd){
    for (int i=0;i<256;i++) if (g_fds[i].fd==fd) return g_fds[i].path;
    return "?";
}

static void init_syms() {
    if (!real_open)   real_open   = dlsym(RTLD_NEXT, "open");
    if (!real_open64) real_open64 = dlsym(RTLD_NEXT, "open64");
    if (!real_openat) real_openat = dlsym(RTLD_NEXT, "openat");
    if (!real_close)  real_close  = dlsym(RTLD_NEXT, "close");
    if (!real_ioctl)  real_ioctl  = dlsym(RTLD_NEXT, "ioctl");
    if (!real_mmap)   real_mmap   = dlsym(RTLD_NEXT, "mmap");
    if (!real_mmap64) real_mmap64 = dlsym(RTLD_NEXT, "mmap64");
}

__attribute__((constructor))
static void on_load() {
    init_syms();
    log_open_file();
    refresh_maps();
    time_t t=time(NULL);
    dlogf("#TAP v1 start %ld\n", (long)t);
}

__attribute__((destructor))
static void on_unload() {
    time_t t=time(NULL);
    dlogf("#TAP end %ld\n", (long)t);
    if (g_memfd>=0) close(g_memfd);
    if (g_logf && g_logf!=stderr) fclose(g_logf);
}

// ---- wrappers ----
int open(const char *pathname, int flags, ...) {
    init_syms();
    mode_t mode = 0;
    if (flags & O_CREAT) {
        va_list ap; va_start(ap, flags); mode = va_arg(ap, mode_t); va_end(ap);
    }
    int fd = real_open(pathname, flags, mode);
    if (fd>=0) {
        pthread_mutex_lock(&g_mu);
        dlogf("OPEN fd=%d path=%s flags=0x%x\n", fd, pathname, flags);
        pthread_mutex_unlock(&g_mu);
        record_fd(fd, pathname);
    }
    return fd;
}
int open64(const char *pathname, int flags, ...) {
    init_syms();
    mode_t mode = 0;
    if (flags & O_CREAT) {
        va_list ap; va_start(ap, flags); mode = va_arg(ap, mode_t); va_end(ap);
    }
    int fd = real_open64(pathname, flags, mode);
    if (fd>=0) {
        pthread_mutex_lock(&g_mu);
        dlogf("OPEN fd=%d path=%s flags=0x%x\n", fd, pathname, flags);
        pthread_mutex_unlock(&g_mu);
        record_fd(fd, pathname);
    }
    return fd;
}
int openat(int dirfd, const char *pathname, int flags, ...) {
    init_syms();
    mode_t mode = 0;
    if (flags & O_CREAT) {
        va_list ap; va_start(ap, flags); mode = va_arg(ap, mode_t); va_end(ap);
    }
    int fd = real_openat(dirfd, pathname, flags, mode);
    if (fd>=0) {
        pthread_mutex_lock(&g_mu);
        dlogf("OPEN fd=%d path=%s flags=0x%x (openat)\n", fd, pathname, flags);
        pthread_mutex_unlock(&g_mu);
        record_fd(fd, pathname);
    }
    return fd;
}
int close(int fd) {
    init_syms();
    pthread_mutex_lock(&g_mu);
    dlogf("CLOSE fd=%d path=%s\n", fd, path_of(fd));
    pthread_mutex_unlock(&g_mu);
    int r = real_close(fd);
    // do not free mapping, we may still want name in log
    return r;
}

// Decode IOC macros
#define _IOC_NRBITS    8
#define _IOC_TYPEBITS  8
#define _IOC_SIZEBITS 14
#define _IOC_DIRBITS   2
#define _IOC_NRMASK    ((1 << _IOC_NRBITS)-1)
#define _IOC_TYPEMASK  ((1 << _IOC_TYPEBITS)-1)
#define _IOC_SIZEMASK  ((1 << _IOC_SIZEBITS)-1)
#define _IOC_DIRMASK   ((1 << _IOC_DIRBITS)-1)
#define _IOC_NRSHIFT   0
#define _IOC_TYPESHIFT (_IOC_NRSHIFT+_IOC_NRBITS)
#define _IOC_SIZESHIFT (_IOC_TYPESHIFT+_IOC_TYPEBITS)
#define _IOC_DIRSHIFT  (_IOC_SIZESHIFT+_IOC_SIZEBITS)
#define _IOC_DIR(nr)   (((nr) >> _IOC_DIRSHIFT) & _IOC_DIRMASK)
#define _IOC_SIZE(nr)  (((nr) >> _IOC_SIZESHIFT) & _IOC_SIZEMASK)
#define _IOC_TYPE(nr)  (((nr) >> _IOC_TYPESHIFT) & _IOC_TYPEMASK)
#define _IOC_NR(nr)    (((nr) >> _IOC_NRSHIFT) & _IOC_NRMASK)

static const char *dirstr(unsigned d) {
    switch (d){ case 0: return "NONE"; case 1: return "WRITE"; case 2: return "READ"; case 3: return "READ|WRITE"; }
    return "?";
}

int ioctl(int fd, unsigned long req, ...) {
    init_syms();
    void *argp = NULL;
    va_list ap; va_start(ap, req); argp = va_arg(ap, void*); va_end(ap);

    const char *path = path_of(fd);
    unsigned dir  = _IOC_DIR(req);
    unsigned type = _IOC_TYPE(req);
    unsigned nr   = _IOC_NR(req);
    unsigned size = _IOC_SIZE(req);

    // Log header
    pthread_mutex_lock(&g_mu);
    dlogf("IOCTL fd=%d path=%s req=0x%08lx dir=%s type=0x%02x nr=0x%02x size=%u arg=%p\n",
         fd, path, req, dirstr(dir), type, nr, size, argp);

    // Capture buffer (size bytes) if WRITE or READ|WRITE and argp != NULL
    if ((dir==1 || dir==3) && size>0 && argp) {
        uint8_t *tmp = (uint8_t*)malloc(size);
        if (tmp) {
            refresh_maps();
            ssize_t n=-1;
            safe_read_mem((uintptr_t)argp, tmp, size, &n);
            if (n>0) {
                dlogf("DATA ");
                hex_dump_line(g_logf, tmp, (size_t)n);
                fputc('\n', g_logf);

                // Heuristic nested pointer scan for 32-bit pointers
                for (unsigned off=0; off+4<=size; off+=4) {
                    uintptr_t pv = 0;
                    memcpy(&pv, tmp+off, 4);
                    if (in_maps(pv)) {
                        size_t nest_len = 256; // heuristic cap
                        uint8_t *nest = (uint8_t*)malloc(nest_len);
                        if (!nest) continue;
                        ssize_t rn=-1; safe_read_mem(pv, nest, nest_len, &rn);
                        if (rn>0) {
                            dlogf("NESTED off=%u ptr=%p len=%zd DATA ", off, (void*)pv, rn);
                            hex_dump_line(g_logf, nest, (size_t)rn);
                            fputc('\n', g_logf);
                        }
                        free(nest);
                    }
                }
            } else {
                dlogf("DATA (unreadable)\n");
            }
            free(tmp);
        }
    }
    pthread_mutex_unlock(&g_mu);

    int r = real_ioctl(fd, req, argp);

    // Log return
    pthread_mutex_lock(&g_mu);
    dlogf("RET fd=%d req=0x%08lx r=%d errno=%d\n", fd, req, r, (r<0)?errno:0);
    pthread_mutex_unlock(&g_mu);
    return r;
}

// We don't need to log mmap contents, but capturing parameters helps
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
    init_syms();
    void *r = real_mmap(addr,length,prot,flags,fd,offset);
    pthread_mutex_lock(&g_mu);
    dlogf("MMAP addr=%p len=%zu prot=0x%x flags=0x%x fd=%d off=0x%lx -> %p path=%s\n",
         addr, length, prot, flags, fd, (unsigned long)offset, r, path_of(fd));
    pthread_mutex_unlock(&g_mu);
    return r;
}

void *mmap64(void *addr, size_t length, int prot, int flags, int fd, off64_t offset) {
    init_syms();
    void *r = real_mmap64(addr,length,prot,flags,fd,offset);
    pthread_mutex_lock(&g_mu);
    dlogf("MMAP64 addr=%p len=%zu prot=0x%x flags=0x%x fd=%d off=0x%lx -> %p path=%s\n",
         addr, length, prot, flags, fd, (unsigned long)offset, r, path_of(fd));
    pthread_mutex_unlock(&g_mu);
    return r;
}

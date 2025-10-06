#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif


#include "ak3918/ion.h"
#include "ak3918/isp.h"
#include "ak3918/util.h"
#include "ak3918/sdk/akispsdk.h"
#include "ak3918/video.h"

#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <linux/videodev2.h>
#include <poll.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#ifndef _IOW
# include <linux/ioctl.h>
#endif

#define DEFAULT_CONF_PATH   "conf/isp_sc1345_dvp.conf"
#define DEFAULT_NR3D_BLOB   "data/isp_blobs/isp_3dnr_ref_attr_pid518_fd10_req0x40044967_20250930T130454.bin"
#define DEFAULT_USER_PARAMS "data/isp_blobs/isp_user_params_pid519_fd10_req0x4004496d_20250930T130029.bin"
#define DEFAULT_OUTPUT_PATH "/mnt/disc1/video_dump.h264"
#define DEFAULT_FRAME_COUNT 150U
#define DEFAULT_BUFFER_COUNT 4U

#define RING_WINDOW_BYTES 0x100000U
#define RING_WINDOW_MASK  (RING_WINDOW_BYTES - 1U)

#define REG_BASE_A      0x14U
#define REG_BASE_B      0x18U
#define REG_WP_A        0x1CU
#define REG_WP_B        0x20U
#define REG_IRQ_STATUS  0x38U
#define REG_PARAM_LEN   0x60U
#define REG_LEN_BYTES   REG_PARAM_LEN
#define REG_UNITS256_A  0x98U

#define DEFAULT_RING_OFF_A  0x00C50000U
#define DEFAULT_RING_OFF_B  0x00D4C800U
struct venc_context {
    int fd;
    const struct ion_region *ion;
    volatile uint8_t *regs;
    size_t regs_len;
    volatile uint8_t *map1;
    size_t map1_len;
    volatile uint8_t *map2;
    size_t map2_len;
    uint32_t last_wp;
    bool last_wp_valid;
    uint64_t flush_seq;
    uint32_t ion_phys_base;
    bool ion_phys_base_valid;
    uint32_t programmed_phys_base_a;
    uint32_t programmed_phys_base_b;
    uint32_t base_off_a;
    uint32_t base_off_b;
    bool programmed_base_a_valid;
    bool programmed_base_b_valid;
    bool base_off_a_valid;
    bool base_off_b_valid;
    uint32_t negotiated_param_len;
    bool negotiated_param_len_valid;
    uint64_t total_bytes_flushed;
};

struct dump_writer {
    int fd;
    const char *path;
    size_t pending_bytes;
    struct timespec last_sync;
    bool have_last_sync;
};

struct v4l2_context {
    unsigned int buffer_count;
    size_t buffer_stride;
    unsigned int width;
    uintptr_t userptrs[DEFAULT_BUFFER_COUNT];
    bool stream_on;
    uint64_t frames_dequeued;
    uint64_t frames_requeued;
    uint64_t frames_discarded;
};

static volatile sig_atomic_t g_stop = 0;

static int should_stop(void)
{
    return g_stop != 0;
}

static void on_signal(int sig)
{
    (void)sig;
    g_stop = 1;
}

static void venc_context_poll_flush(struct venc_context *ctx,
                                    struct dump_writer *writer,
                                    int force_log);

static int g_fd_spkr = -1;
static int g_fd_mic  = -1;
static bool g_spkr_configured = false;
static bool g_mic_configured  = false;

static int ensure_aux_devices_open(void)
{
    if (g_fd_spkr < 0) {
        g_fd_spkr = open("/dev/akpcm_cdev0", O_WRONLY | O_CLOEXEC);
        if (g_fd_spkr < 0) {
            perror("open(/dev/akpcm_cdev0)");
        }
    }
    if (g_fd_mic < 0) {
        g_fd_mic = open("/dev/akpcm_cdev1", O_RDONLY | O_CLOEXEC);
        if (g_fd_mic < 0) {
            perror("open(/dev/akpcm_cdev1)");
        }
    }
    return 0;
}

static void configure_mic_device(void)
{
    if (g_fd_mic < 0 || g_mic_configured) {
        return;
    }

    int fd = g_fd_mic;
    uint32_t v;
    unsigned char params[64];
    memset(params, 0, sizeof(params));

    v = 0x02;
    if (ioctl(fd, 0x40045010UL, &v) < 0) {
        perror("ioctl(akpcm1,0x40045010)");
    }

    v = 0x01;
    if (ioctl(fd, 0x40045070UL, &v) < 0) {
        perror("ioctl(akpcm1,0x40045070)");
    }

    v = 0x07;
    if (ioctl(fd, 0x40045030UL, &v) < 0) {
        perror("ioctl(akpcm1,0x40045030)");
    }

    if (ioctl(fd, 0x50e3UL) < 0) {
        perror("ioctl(akpcm1,0x50e3)");
    }

    v = 0x01;
    if (ioctl(fd, 0x40045088UL, &v) < 0) {
        perror("ioctl(akpcm1,0x40045088)");
    }

    if (ioctl(fd, 0x50e2UL) < 0) {
        perror("ioctl(akpcm1,0x50e2)");
    }

    unsigned char mic_cfg[28] = {
        0x80,0x3e,0x00,0x00,
        0x01,0x00,0x00,0x00,
        0x10,0x00,0x00,0x00,
        0x00,0x08,0x00,0x00,
        0x10,0x00,0x00,0x00,
        0x00,0x08,0x00,0x00,
        0x00,0x00,0x00,0x00
    };
    if (ioctl(fd, 0x401c50f2UL, mic_cfg) < 0) {
        perror("ioctl(akpcm1,0x401c50f2)");
    }

    if (ioctl(fd, 0x50e0UL) < 0) {
        perror("ioctl(akpcm1,0x50e0)");
    }

    if (ioctl(fd, 0x804050f0UL, params) < 0) {
        perror("ioctl(akpcm1,0x804050f0)");
    }

    if (ioctl(fd, 0x50e2UL) < 0) {
        perror("ioctl(akpcm1,0x50e2#2)");
    }

    if (ioctl(fd, 0x50e1UL, params) < 0) {
        perror("ioctl(akpcm1,0x50e1)");
    }

    if (ioctl(fd, 0x80045085UL, params) < 0) {
        perror("ioctl(akpcm1,0x80045085)");
    }

    v = 0;
    if (ioctl(fd, 0x40045086UL, &v) < 0) {
        perror("ioctl(akpcm1,0x40045086)");
    }

    g_mic_configured = true;
}

static void configure_spkr_device(void)
{
    if (g_fd_spkr < 0 || g_spkr_configured) {
        return;
    }

    int fd = g_fd_spkr;
    uint32_t v;
    unsigned char params[64];
    unsigned char buf28[28];

    memset(params, 0, sizeof(params));

    v = 0x01;
    if (ioctl(fd, 0x40045081UL, &v) < 0) {
        perror("ioctl(akpcm0,0x40045081)");
    }

    if (ioctl(fd, 0x50e3UL) < 0) {
        perror("ioctl(akpcm0,0x50e3)");
    }

    v = 0x05;
    if (ioctl(fd, 0x40045030UL, &v) < 0) {
        perror("ioctl(akpcm0,0x40045030=5)");
    }

    v = 0x04;
    if (ioctl(fd, 0x40045030UL, &v) < 0) {
        perror("ioctl(akpcm0,0x40045030=4)");
    }

    v = 0x04;
    if (ioctl(fd, 0x40045010UL, &v) < 0) {
        perror("ioctl(akpcm0,0x40045010=4)");
    }

    v = 0x01;
    if (ioctl(fd, 0x40045070UL, &v) < 0) {
        perror("ioctl(akpcm0,0x40045070)");
    }

    if (ioctl(fd, 0x50e2UL) < 0) {
        perror("ioctl(akpcm0,0x50e2)");
    }

    unsigned char spkr_cfg[28] = {
        0x80,0x3e,0x00,0x00,
        0x02,0x00,0x00,0x00,
        0x10,0x00,0x00,0x00,
        0x00,0x10,0x00,0x00,
        0x0c,0x00,0x00,0x00,
        0x00,0x10,0x00,0x00,
        0x00,0x00,0x00,0x00
    };
    if (ioctl(fd, 0x401c50f2UL, spkr_cfg) < 0) {
        perror("ioctl(akpcm0,0x401c50f2)");
    }

    if (ioctl(fd, 0x50e0UL) < 0) {
        perror("ioctl(akpcm0,0x50e0)");
    }

    if (ioctl(fd, 0x804050f0UL, params) < 0) {
        perror("ioctl(akpcm0,0x804050f0)");
    }

    memset(buf28, 0, sizeof(buf28));
    if (ioctl(fd, 0x801c50f2UL, buf28) < 0) {
        perror("ioctl(akpcm0,0x801c50f2)");
    }

    if (ioctl(fd, 0x80045010UL, &v) < 0) {
        perror("ioctl(akpcm0,0x80045010)");
    }
    if (ioctl(fd, 0x80045030UL, &v) < 0) {
        perror("ioctl(akpcm0,0x80045030)");
    }

    if (ioctl(fd, 0x50e3UL) < 0) {
        perror("ioctl(akpcm0,0x50e3#2)");
    }

    g_spkr_configured = true;
}



static int venc_pump_irqs(struct venc_context *ctx, int fd,
                          enum ak_uio_irq_mode *mode,
                          struct dump_writer *writer,
                          int log_first)
{
    if (!ctx || fd < 0 || !mode || !writer) {
        errno = EINVAL;
        return -1;
    }

    int handled = 0;
    int force_log = log_first ? 1 : 0;

    for (;;) {
        if (should_stop()) {
            break;
        }
        uint32_t irqcnt = 0;
        int rc = ak_uio_wait_irq(fd, mode, &irqcnt, should_stop);
        if (rc < 0) {
            return -1;
        }
        if (rc == 0) {
            return handled;
        }

        venc_context_poll_flush(ctx, writer, force_log);
        handled = 1;
        force_log = 0;
    }

    return handled;
}

static void dump_writer_init(struct dump_writer *w, int fd, const char *path)
{
    if (!w) {
        return;
    }
    memset(w, 0, sizeof(*w));
    w->fd = fd;
    w->path = path;
    if (clock_gettime(CLOCK_MONOTONIC, &w->last_sync) == 0) {
        w->have_last_sync = true;
    } else {
        w->have_last_sync = false;
    }
}

static uint64_t timespec_diff_ns(const struct timespec *a, const struct timespec *b)
{
    if (!a || !b) {
        return 0;
    }

    int64_t sec = (int64_t)a->tv_sec - (int64_t)b->tv_sec;
    int64_t nsec = (int64_t)a->tv_nsec - (int64_t)b->tv_nsec;
    if (nsec < 0) {
        --sec;
        nsec += 1000000000LL;
    }
    if (sec < 0) {
        return 0;
    }
    return (uint64_t)sec * 1000000000ULL + (uint64_t)nsec;
}

static int dump_writer_maybe_sync(struct dump_writer *w, int force)
{
    if (!w || w->fd < 0) {
        return 0;
    }

    struct timespec now;
    bool have_now = (clock_gettime(CLOCK_MONOTONIC, &now) == 0);

    if (!force) {
        const size_t threshold = 64U * 1024U;
        const uint64_t interval_ns = 2000000000ULL;

        if (w->pending_bytes < threshold) {
            if (have_now && w->have_last_sync) {
                uint64_t elapsed = timespec_diff_ns(&now, &w->last_sync);
                if (elapsed < interval_ns) {
                    return 0;
                }
            } else if (w->pending_bytes == 0) {
                return 0;
            }
        }
    }

    int rc;
    do {
        rc = fsync(w->fd);
    } while (rc < 0 && errno == EINTR);
    if (rc < 0) {
        perror("fsync(h264)");
        return -1;
    }

    w->pending_bytes = 0;
    if (have_now) {
        w->last_sync = now;
        w->have_last_sync = true;
    } else {
        w->have_last_sync = false;
    }
    return 0;
}

static int dump_writer_write(struct dump_writer *w, const void *data, size_t len)
{
    if (!w || w->fd < 0 || (!data && len)) {
        errno = EINVAL;
        return -1;
    }

    const uint8_t *p = (const uint8_t *)data;
    size_t written = 0;
    while (written < len) {
        ssize_t rc = write(w->fd, p + written, len - written);
        if (rc > 0) {
            written += (size_t)rc;
            w->pending_bytes += (size_t)rc;
            continue;
        }
        if (rc == 0) {
            errno = EIO;
            return -1;
        }
        if (errno == EINTR) {
            if (should_stop()) {
                errno = EINTR;
                return -1;
            }
            continue;
        }
        return -1;
    }
    return 0;
}

static void set_fd_nonblock(int fd, const char *name)
{
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags < 0) {
        if (name) {
            fprintf(stderr, "%s: fcntl(F_GETFL) fallo: %s\n", name, strerror(errno));
        } else {
            perror("fcntl(F_GETFL)");
        }
        return;
    }

    if ((flags & O_NONBLOCK) == 0) {
        if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) < 0) {
            if (name) {
                fprintf(stderr, "%s: fcntl(F_SETFL) fallo: %s\n", name, strerror(errno));
            } else {
                perror("fcntl(F_SETFL)");
            }
        }
    }
}

static void usage(const char *prog)
{
    fprintf(stderr,
            "Uso: %s [opciones]\n"
            "  --conf <path>       Ruta al .conf del ISP\n"
            "  --nr3d <path>       Ruta al blob para ak_isp_set_3d_nr_ref_attr\n"
            "  --user <path>       Ruta al blob de ak_isp_set_user_params\n"
            "  --pack <n>          Pack de la config ISP a aplicar (0 o 1, defecto 0)\n"
            "  --frames <n>        Nº de frames V4L2 a procesar (defecto %u)\n"
            "  --output <path>     Fichero de salida Annex-B (defecto %s)\n"
            "  --help              Muestra esta ayuda\n",
            prog, DEFAULT_FRAME_COUNT, DEFAULT_OUTPUT_PATH);
}

static size_t align_up(size_t value, size_t align)
{
    return (value + align - 1U) & ~(align - 1U);
}

static long get_page_size(void)
{
    long ps = sysconf(_SC_PAGESIZE);
    return (ps > 0) ? ps : 4096L;
}

static int resolve_uio_index(int fd)
{
    char link[64];
    char path[128];
    snprintf(link, sizeof(link), "/proc/self/fd/%d", fd);
    ssize_t n = readlink(link, path, sizeof(path) - 1);
    if (n <= 0) {
        return -1;
    }
    path[n] = '\0';
    const char *base = strrchr(path, '/');
    base = base ? base + 1 : path;
    if (strncmp(base, "uio", 3) != 0) {
        return -1;
    }
    return atoi(base + 3);
}

static int read_hex_sysfs(const char *path, unsigned long *out)
{
    int fd = open(path, O_RDONLY | O_CLOEXEC);
    if (fd < 0) {
        return -1;
    }
    char buf[64];
    ssize_t n = read(fd, buf, sizeof(buf) - 1);
    close(fd);
    if (n <= 0) {
        return -1;
    }
    buf[n] = '\0';
    char *endp = NULL;
    unsigned long val = strtoul(buf, &endp, 0);
    if (endp == buf) {
        return -1;
    }
    *out = val;
    return 0;
}

static volatile uint8_t *map_uio_regs(int fd, size_t *len_out)
{
    unsigned long map_len = 0x500UL;
    int idx = resolve_uio_index(fd);
    if (idx >= 0) {
        char path[128];
        snprintf(path, sizeof(path), "/sys/class/uio/uio%d/maps/map0/size", idx);
        if (read_hex_sysfs(path, &map_len) != 0 || map_len == 0) {
            map_len = 0x500UL;
        }
    }
    void *m = mmap(NULL, map_len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (m == MAP_FAILED) {
        return NULL;
    }
    if (len_out) {
        *len_out = (size_t)map_len;
    }
    return (volatile uint8_t *)m;
}

static volatile uint8_t *map_uio_region(int fd, int map_index, size_t *len_out)
{
    int idx = resolve_uio_index(fd);
    if (idx < 0) {
        return NULL;
    }
    char path[128];
    snprintf(path, sizeof(path), "/sys/class/uio/uio%d/maps/map%d/size", idx, map_index);
    unsigned long map_len = 0;
    if (read_hex_sysfs(path, &map_len) != 0 || map_len == 0) {
        map_len = RING_WINDOW_BYTES;
    }
    off_t off = (off_t)map_index * (off_t)get_page_size();
    void *m = mmap(NULL, map_len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, off);
    if (m == MAP_FAILED) {
        return NULL;
    }
    if (len_out) {
        *len_out = (size_t)map_len;
    }
    return (volatile uint8_t *)m;
}

static inline uint32_t rd32(const volatile uint8_t *base, uint32_t off)
{
    const volatile uint32_t *p = (const volatile uint32_t *)(base + (off & ~3U));
    return *p;
}

static inline void wr32(volatile uint8_t *base, uint32_t off, uint32_t value)
{
    volatile uint32_t *p = (volatile uint32_t *)(base + (off & ~3U));
    *p = value;
}

static inline uint32_t venc_wp_to_offset(const struct venc_context *ctx,
                                         uint32_t raw_wp)
{
    if (!ctx) {
        return raw_wp & RING_WINDOW_MASK;
    }

    if (ctx->programmed_base_a_valid) {
        return (raw_wp - ctx->programmed_phys_base_a) & RING_WINDOW_MASK;
    }

    if (ctx->ion_phys_base_valid && ctx->base_off_a_valid) {
        uint32_t base_phys = ctx->ion_phys_base + ctx->base_off_a;
        return (raw_wp - base_phys) & RING_WINDOW_MASK;
    }

    return raw_wp & RING_WINDOW_MASK;
}

static void venc_update_base_offsets(struct venc_context *ctx,
                                     uint32_t hw_base_a,
                                     uint32_t hw_base_b)
{
    if (!ctx || !ctx->ion) {
        return;
    }

    if (ctx->ion_phys_base_valid && hw_base_a >= ctx->ion_phys_base) {
        uint32_t off = hw_base_a - ctx->ion_phys_base;
        if ((size_t)off + RING_WINDOW_BYTES <= ctx->ion->len) {
            ctx->base_off_a = off;
            ctx->base_off_a_valid = true;
        }
    } else if (!ctx->ion_phys_base_valid && hw_base_a < ctx->ion->len) {
        ctx->base_off_a = hw_base_a;
        ctx->base_off_a_valid = true;
    }

    if (ctx->ion_phys_base_valid && hw_base_b >= ctx->ion_phys_base) {
        uint32_t off = hw_base_b - ctx->ion_phys_base;
        if ((size_t)off + RING_WINDOW_BYTES <= ctx->ion->len) {
            ctx->base_off_b = off;
            ctx->base_off_b_valid = true;
        }
    } else if (!ctx->ion_phys_base_valid && hw_base_b < ctx->ion->len) {
        ctx->base_off_b = hw_base_b;
        ctx->base_off_b_valid = true;
    }

    if (!ctx->base_off_b_valid && ctx->base_off_a_valid) {
        ctx->base_off_b = ctx->base_off_a;
        ctx->base_off_b_valid = true;
    }

    if (hw_base_a != 0U) {
        ctx->programmed_phys_base_a = hw_base_a;
        ctx->programmed_base_a_valid = true;
    }
    if (hw_base_b != 0U) {
        ctx->programmed_phys_base_b = hw_base_b;
        ctx->programmed_base_b_valid = true;
    }
}

static int venc_mmio_base_to_offset(struct venc_context *ctx, uint32_t mmio_val,
                                    uint32_t *off_out)
{
    if (!ctx->ion || !ctx->ion->map || ctx->ion->len < RING_WINDOW_BYTES) {
        return 0;
    }

    if (ctx->programmed_base_a_valid && mmio_val == ctx->programmed_phys_base_a) {
        if (ctx->base_off_a_valid) {
            if (off_out) {
                *off_out = ctx->base_off_a;
            }
            return 1;
        }
        if (ctx->ion_phys_base_valid) {
            if (off_out) {
                *off_out = ctx->programmed_phys_base_a - ctx->ion_phys_base;
            }
            return 1;
        }
        return 0;
    }

    if (ctx->programmed_base_b_valid && mmio_val == ctx->programmed_phys_base_b) {
        if (ctx->base_off_b_valid) {
            if (off_out) {
                *off_out = ctx->base_off_b;
            }
            return 1;
        }
        if (ctx->ion_phys_base_valid) {
            if (off_out) {
                *off_out = ctx->programmed_phys_base_b - ctx->ion_phys_base;
            }
            return 1;
        }
        return 0;
    }

    if (ctx->ion_phys_base_valid && mmio_val >= ctx->ion_phys_base) {
        uint32_t off = mmio_val - ctx->ion_phys_base;
        if (off < ctx->ion->len && ((size_t)off + RING_WINDOW_BYTES) <= ctx->ion->len) {
            if (off_out) {
                *off_out = off;
            }
            return 1;
        }
    }

    uint32_t candidates[6];
    size_t cand = 0;

    candidates[cand++] = mmio_val;

    if (ctx->ion_phys_base_valid && mmio_val >= ctx->ion_phys_base) {
        candidates[cand++] = mmio_val - ctx->ion_phys_base;
    }

    uint32_t hi = mmio_val & 0xF0000000U;
    if (hi && mmio_val >= hi) {
        uint32_t off = mmio_val - hi;
        candidates[cand++] = off;
        if (!ctx->ion_phys_base_valid) {
            ctx->ion_phys_base = hi;
            ctx->ion_phys_base_valid = true;
            fprintf(stderr, "[venc] inferida ION_PHYS_BASE=0x%08x\n", ctx->ion_phys_base);
        }
    }

    candidates[cand++] = mmio_val & 0x0FFFFFFFU;

    if (ctx->ion->len) {
        candidates[cand++] = (uint32_t)((uint64_t)mmio_val % (uint64_t)ctx->ion->len);
    }

    for (size_t i = 0; i < cand; ++i) {
        uint32_t off = candidates[i];
        if (off < ctx->ion->len && ((size_t)off + RING_WINDOW_BYTES) <= ctx->ion->len) {
            if (off_out) {
                *off_out = off;
            }
            return 1;
        }
    }

    return 0;
}

static const uint8_t *venc_resolve_ring(struct venc_context *ctx, size_t *len_out)
{
    if (ctx->map1 && ctx->map1_len >= RING_WINDOW_BYTES) {
        if (len_out) {
            *len_out = ctx->map1_len;
        }
        return (const uint8_t *)ctx->map1;
    }

    if (ctx->ion && ctx->ion->map && ctx->base_off_a_valid &&
        ((size_t)ctx->base_off_a + RING_WINDOW_BYTES) <= ctx->ion->len) {
        if (len_out) {
            *len_out = RING_WINDOW_BYTES;
        }
        return ((const uint8_t *)ctx->ion->map) + ctx->base_off_a;
    }

    if (!ctx->regs) {
        if (len_out) {
            *len_out = 0;
        }
        return NULL;
    }

    uint32_t base_reg = rd32(ctx->regs, REG_BASE_A);
    uint32_t base_off = 0;
    if (!venc_mmio_base_to_offset(ctx, base_reg, &base_off)) {
        if (len_out) {
            *len_out = 0;
        }
        return NULL;
    }

    if (len_out) {
        *len_out = RING_WINDOW_BYTES;
    }
    return ((const uint8_t *)ctx->ion->map) + base_off;
}

static ssize_t venc_flush_ring_to_file(struct venc_context *ctx,
                                       struct dump_writer *writer,
                                       uint32_t wp_now,
                                       uint32_t slot_bytes,
                                       uint32_t payload_bytes,
                                       int log_this)
{
    if (!ctx->regs) {
        return 0;
    }

    if (slot_bytes == 0 || slot_bytes > RING_WINDOW_BYTES) {
        if (log_this) {
            fprintf(stderr, "[venc] omito slot=%u (wp=0x%05x)\n", slot_bytes, wp_now);
        }
        return 0;
    }

    if (payload_bytes == 0 || payload_bytes > slot_bytes) {
        payload_bytes = slot_bytes;
        if (payload_bytes > RING_WINDOW_BYTES) {
            payload_bytes = RING_WINDOW_BYTES;
        }
    }

    uint32_t start_off = (wp_now + RING_WINDOW_BYTES - (payload_bytes & RING_WINDOW_MASK)) & RING_WINDOW_MASK;
    size_t ring_len = 0;
    const uint8_t *ring = venc_resolve_ring(ctx, &ring_len);
    if (!ring || ring_len < slot_bytes) {
        if (log_this) {
            fprintf(stderr, "[venc] anillo no disponible (ring=%p len=0x%zx)\n",
                    (void *)ring, ring_len);
        }
        return 0;
    }

    size_t first = RING_WINDOW_BYTES - start_off;
    if (first > payload_bytes) {
        first = payload_bytes;
    }
    size_t second = payload_bytes - first;

    if (!writer || writer->fd < 0) {
        if (log_this) {
            fprintf(stderr, "[venc] descarto %u bytes (sin fichero)\n", payload_bytes);
        }
        return (ssize_t)payload_bytes;
    }

    if (dump_writer_write(writer, ring + start_off, first) < 0) {
        perror("write(h264)");
        return -1;
    }
    if (second && dump_writer_write(writer, ring, second) < 0) {
        perror("write(h264)");
        return -1;
    }

    if (dump_writer_maybe_sync(writer, 0) < 0) {
        return -1;
    }

    ctx->total_bytes_flushed += (uint64_t)payload_bytes;

    if (log_this) {
        fprintf(stderr,
                "[venc] escrito %u bytes (total=%" PRIu64
                ") en %s (start=0x%05x wp=0x%05x)\n",
                payload_bytes, ctx->total_bytes_flushed,
                writer->path ? writer->path : "(desconocido)",
                start_off, wp_now);
    }
    return (ssize_t)payload_bytes;
}

static void venc_drain(struct venc_context *ctx, struct dump_writer *writer,
                       uint32_t wp_reg, uint32_t chunk_reg, int force_log)
{
    if (!ctx->regs) {
        return;
    }

    const uint32_t wp_now = venc_wp_to_offset(ctx, wp_reg);
    const uint32_t raw_chunk = chunk_reg & RING_WINDOW_MASK;
    uint32_t wp_b_now = 0U;
    uint32_t len_reg = chunk_reg;
    uint32_t units_a = 0U;
    uint32_t base_a_hw = 0U;
    uint32_t base_b_hw = 0U;
    if (ctx->regs) {
        base_a_hw = rd32(ctx->regs, REG_BASE_A);
        base_b_hw = rd32(ctx->regs, REG_BASE_B);
        venc_update_base_offsets(ctx, base_a_hw, base_b_hw);

        uint32_t wp_b_raw = rd32(ctx->regs, REG_WP_B);
        wp_b_now = venc_wp_to_offset(ctx, wp_b_raw);
        len_reg = rd32(ctx->regs, REG_PARAM_LEN);
        units_a = rd32(ctx->regs, REG_UNITS256_A);
    }

    uint32_t prev_wp = ctx->last_wp;
    if (!ctx->last_wp_valid) {
        prev_wp = wp_now;
        ctx->last_wp = wp_now;
        ctx->last_wp_valid = true;
    }

    uint32_t delta = (wp_now >= prev_wp)
                         ? (wp_now - prev_wp)
                         : ((RING_WINDOW_BYTES - prev_wp) + wp_now);

    uint32_t units_bytes = (units_a & 0xFFFU) << 8;
    uint32_t slot_bytes = raw_chunk;
    if (slot_bytes == 0U || slot_bytes > RING_WINDOW_BYTES) {
        if (units_bytes > 0U && units_bytes <= RING_WINDOW_BYTES) {
            slot_bytes = units_bytes;
        }
    }
    if (slot_bytes == 0U || slot_bytes > RING_WINDOW_BYTES) {
        slot_bytes = delta;
    }

    uint32_t payload_bytes = len_reg & RING_WINDOW_MASK;
    if (payload_bytes == 0U || payload_bytes > RING_WINDOW_BYTES) {
        payload_bytes = slot_bytes;
    }

    const bool have_bytes = (slot_bytes > 0U && slot_bytes <= RING_WINDOW_BYTES);
    if (have_bytes) {
        ctx->flush_seq++;
    }

    const int log_this = force_log || (have_bytes &&
                                       (ctx->flush_seq <= 8 || ((ctx->flush_seq & 0x3f) == 0)));
    if (log_this) {
        fprintf(stderr,
                "[venc] WP prev=0x%05x now=0x%05x delta=%u slot=%u raw=%u len=%u units256=%u wpB=0x%05x\n",
                prev_wp, wp_now, delta, slot_bytes, raw_chunk,
                payload_bytes, units_a & 0xFFFU, wp_b_now);
    }

    if (have_bytes) {
        ssize_t flushed = venc_flush_ring_to_file(ctx, writer, wp_now,
                                                  slot_bytes, payload_bytes,
                                                  log_this);
        if (flushed < 0) {
            goto ack_only;
        }
    }

    ctx->last_wp = wp_now;

ack_only:
    {
        uint32_t st = rd32(ctx->regs, REG_IRQ_STATUS);
        if (st & 1U) {
            wr32(ctx->regs, REG_IRQ_STATUS, st & ~1U);
            if (log_this) {
                fprintf(stderr, "[venc] ack IRQ status -> 0x%08x\n", st & ~1U);
            }
        }
    }
}

static void venc_context_poll_flush(struct venc_context *ctx,
                                    struct dump_writer *writer, int force_log)
{
    if (!ctx->regs) {
        return;
    }
    uint32_t wp_now = rd32(ctx->regs, REG_WP_A);
    uint32_t chunk = rd32(ctx->regs, REG_LEN_BYTES);
    venc_drain(ctx, writer, wp_now, chunk, force_log);
}

static void venc_context_destroy(struct venc_context *ctx)
{
    if (!ctx) {
        return;
    }
    if (ctx->regs) {
        munmap((void *)ctx->regs, ctx->regs_len);
        ctx->regs = NULL;
        ctx->regs_len = 0;
    }
    if (ctx->map1) {
        munmap((void *)ctx->map1, ctx->map1_len);
        ctx->map1 = NULL;
        ctx->map1_len = 0;
    }
    if (ctx->map2) {
        munmap((void *)ctx->map2, ctx->map2_len);
        ctx->map2 = NULL;
        ctx->map2_len = 0;
    }
    ctx->fd = -1;
    ctx->last_wp_valid = false;
}

static int venc_context_init(struct venc_context *ctx, int fd,
                             const struct ion_region *ion,
                             unsigned int width)
{
    if (!ctx || fd < 0 || !ion) {
        errno = EINVAL;
        return -1;
    }

    memset(ctx, 0, sizeof(*ctx));
    ctx->fd = fd;
    ctx->ion = ion;
    ctx->last_wp_valid = false;
    ctx->flush_seq = 0;

    ctx->negotiated_param_len = width >> 1;
    ctx->negotiated_param_len_valid = (width > 0U);
    if (!ctx->negotiated_param_len_valid) {
        fprintf(stderr,
                "[venc] aviso: ancho negociado 0, payload nominal indefinido\n");
    }

    if (ion->phys_base_valid) {
        ctx->ion_phys_base = ion->phys_base;
        ctx->ion_phys_base_valid = true;
        fprintf(stderr, "[venc] base física ION detectada=0x%08x\n",
                ctx->ion_phys_base);
    }

    const char *env = getenv("ION_PHYS_BASE");
    if (env && *env) {
        uint32_t env_base = (uint32_t)strtoul(env, NULL, 0);
        if (!ctx->ion_phys_base_valid || env_base != ctx->ion_phys_base) {
            fprintf(stderr, "[venc] usando ION_PHYS_BASE=0x%08x\n", env_base);
        } else {
            fprintf(stderr, "[venc] confirmada ION_PHYS_BASE=0x%08x\n", env_base);
        }
        ctx->ion_phys_base = env_base;
        ctx->ion_phys_base_valid = true;
    }

    if (ion->len < RING_WINDOW_BYTES) {
        fprintf(stderr,
                "[venc] dmabuf demasiado pequeño (0x%zx) para ventana 0x%x\n",
                ion->len, RING_WINDOW_BYTES);
        errno = EINVAL;
        return -1;
    }

    if (ctx->ion_phys_base_valid) {
        ctx->base_off_a = 0;
        ctx->base_off_a_valid = true;
        if (((size_t)RING_WINDOW_BYTES * 2U) <= ion->len) {
            ctx->base_off_b = RING_WINDOW_BYTES;
            ctx->base_off_b_valid = true;
        } else {
            ctx->base_off_b = 0;
            ctx->base_off_b_valid = true;
        }
    }

    struct ak_uio_triple t;
    int rc = 0;

    t.reg = 0x0800001c; t.off = 0x00100000; t.size = 0x00100000; rc = ak_uio_set_triple(fd, &t);
    fprintf(stderr, "[venc] UIO_SET_TRIPLE reg=0x%08x off=0x%08x size=0x%08x -> %d\n",
            t.reg, t.off, t.size, rc);
    if (rc < 0) {
        return -1;
    }

    t.reg = 0x08000020; t.off = 0x00100000; t.size = 0x00100000; rc = ak_uio_set_triple(fd, &t);
    fprintf(stderr, "[venc] UIO_SET_TRIPLE reg=0x%08x off=0x%08x size=0x%08x -> %d\n",
            t.reg, t.off, t.size, rc);
    t.reg = 0x0800001c; t.off = 0x00000000; t.size = 0x00100000; rc |= ak_uio_set_triple(fd, &t);
    fprintf(stderr, "[venc] UIO_SET_TRIPLE reg=0x%08x off=0x%08x size=0x%08x -> %d\n",
            t.reg, t.off, t.size, rc);
    t.reg = 0x08000020; t.off = 0x00000000; t.size = 0x00100000; rc |= ak_uio_set_triple(fd, &t);
    fprintf(stderr, "[venc] UIO_SET_TRIPLE reg=0x%08x off=0x%08x size=0x%08x -> %d\n",
            t.reg, t.off, t.size, rc);

    ctx->regs = map_uio_regs(fd, &ctx->regs_len);
    if (!ctx->regs) {
        perror("map_uio_regs");
        venc_context_destroy(ctx);
        return -1;
    }
    fprintf(stderr, "[venc] regs mapeados len=0x%zx @%p\n", ctx->regs_len, (void *)ctx->regs);

    uint32_t hw_base_a = rd32(ctx->regs, REG_BASE_A);
    uint32_t hw_base_b = rd32(ctx->regs, REG_BASE_B);

    if (ctx->ion_phys_base_valid) {
        uint32_t expected_a = ctx->ion_phys_base + DEFAULT_RING_OFF_A;
        uint32_t expected_b = ctx->ion_phys_base + DEFAULT_RING_OFF_B;
        if (hw_base_a == 0U || hw_base_a == ctx->ion_phys_base) {
            hw_base_a = expected_a;
            wr32(ctx->regs, REG_BASE_A, hw_base_a);
            wr32(ctx->regs, REG_WP_A, hw_base_a);
        }
        if (hw_base_b == 0U || hw_base_b == ctx->ion_phys_base) {
            hw_base_b = expected_b;
            wr32(ctx->regs, REG_BASE_B, hw_base_b);
            wr32(ctx->regs, REG_WP_B, hw_base_b);
        }
    }

    if (ctx->negotiated_param_len_valid) {
        wr32(ctx->regs, REG_PARAM_LEN, ctx->negotiated_param_len);
        fprintf(stderr,
                "[venc] REG_PARAM_LEN preset to %u bytes\n",
                ctx->negotiated_param_len);
    }

    venc_update_base_offsets(ctx, hw_base_a, hw_base_b);

    fprintf(stderr,
            "[venc] bases detectadas A=0x%08x(off=0x%05x valido=%d) B=0x%08x(off=0x%05x valido=%d)\n",
            ctx->programmed_phys_base_a, ctx->base_off_a,
            ctx->programmed_base_a_valid,
            ctx->programmed_phys_base_b, ctx->base_off_b,
            ctx->programmed_base_b_valid);

    ctx->map1 = map_uio_region(fd, 1, &ctx->map1_len);
    if (ctx->map1) {
        fprintf(stderr, "[venc] map1 len=0x%zx @%p\n", ctx->map1_len, (void *)ctx->map1);
    }
    ctx->map2 = map_uio_region(fd, 2, &ctx->map2_len);
    if (ctx->map2) {
        fprintf(stderr, "[venc] map2 len=0x%zx @%p\n", ctx->map2_len, (void *)ctx->map2);
    }

    uint32_t raw_wp = rd32(ctx->regs, REG_WP_A);
    ctx->last_wp = venc_wp_to_offset(ctx, raw_wp);
    ctx->last_wp_valid = true;
    fprintf(stderr, "[venc] WP inicial raw=0x%08x off=0x%05x\n",
            raw_wp, ctx->last_wp);

    return 0;
}

static int setup_v4l2(int fd, const struct ion_region *ion,
                      struct v4l2_context *ctx)
{
    if (!ctx || !ion || ion->len == 0) {
        errno = EINVAL;
        return -1;
    }

    memset(ctx, 0, sizeof(*ctx));

    struct v4l2_capability caps;
    memset(&caps, 0, sizeof(caps));
    if (xioctl(fd, VIDIOC_QUERYCAP, &caps) < 0) {
        return -1;
    }
    fprintf(stderr,
            "[v4l2] driver=%s card=%s bus=%s version=%u caps=0x%x dev_caps=0x%x\n",
            caps.driver, caps.card, caps.bus_info, caps.version,
            caps.capabilities, caps.device_caps);

    struct v4l2_cropcap cropcap;
    memset(&cropcap, 0, sizeof(cropcap));
    cropcap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (xioctl(fd, VIDIOC_CROPCAP, &cropcap) < 0) {
        return -1;
    }
    fprintf(stderr, "[v4l2] bounds %d,%d %ux%u defrect %d,%d %ux%u\n",
            cropcap.bounds.left, cropcap.bounds.top,
            cropcap.bounds.width, cropcap.bounds.height,
            cropcap.defrect.left, cropcap.defrect.top,
            cropcap.defrect.width, cropcap.defrect.height);

    struct v4l2_crop crop;
    memset(&crop, 0, sizeof(crop));
    crop.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    crop.c = cropcap.defrect;
    if (xioctl(fd, VIDIOC_S_CROP, &crop) < 0) {
        return -1;
    }

    struct v4l2_format fmt;
    memset(&fmt, 0, sizeof(fmt));
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = 1280;
    fmt.fmt.pix.height = 720;
    fmt.fmt.pix.pixelformat = v4l2_fourcc('Y', 'U', 'Y', 'V');
    fmt.fmt.pix.field = V4L2_FIELD_INTERLACED;
    if (xioctl(fd, VIDIOC_S_FMT, &fmt) < 0) {
        return -1;
    }
    fprintf(stderr,
            "[v4l2] fmt %ux%u fourcc=%.4s bytesperline=%u sizeimage=%u\n",
            fmt.fmt.pix.width, fmt.fmt.pix.height,
            (char *)&fmt.fmt.pix.pixelformat,
            fmt.fmt.pix.bytesperline, fmt.fmt.pix.sizeimage);

    ctx->width = fmt.fmt.pix.width;

    struct v4l2_streamparm parm;
    memset(&parm, 0, sizeof(parm));
    parm.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    parm.parm.capture.capability = 0x1;
    parm.parm.capture.capturemode = 0x280;
    parm.parm.capture.timeperframe.numerator = 360;
    parm.parm.capture.timeperframe.denominator = 0;
    parm.parm.capture.extendedmode = 0;
    parm.parm.capture.readbuffers = 0;
    if (xioctl(fd, VIDIOC_S_PARM, &parm) < 0) {
        return -1;
    }

    struct v4l2_requestbuffers req;
    memset(&req, 0, sizeof(req));
    req.count = DEFAULT_BUFFER_COUNT;
    req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req.memory = V4L2_MEMORY_USERPTR;
    if (xioctl(fd, VIDIOC_REQBUFS, &req) < 0) {
        return -1;
    }
    if (req.count > DEFAULT_BUFFER_COUNT) {
        req.count = DEFAULT_BUFFER_COUNT;
    }
    fprintf(stderr, "[v4l2] REQBUFS -> %u\n", req.count);

    size_t stride = align_up(fmt.fmt.pix.sizeimage, 4096U);
    if (stride * req.count > ion->len) {
        fprintf(stderr, "[v4l2] región ION insuficiente (%zu bytes necesarios, len=%zu)\n",
                stride * req.count, ion->len);
        errno = ENOMEM;
        return -1;
    }

    ctx->buffer_count = req.count;
    if (ctx->buffer_count == 0) {
        errno = EINVAL;
        return -1;
    }
    ctx->buffer_stride = stride;
    ctx->stream_on = false;

    uintptr_t base = (uintptr_t)ion->map;
    for (unsigned int i = 0; i < ctx->buffer_count; ++i) {
        ctx->userptrs[i] = base + i * stride;
        struct v4l2_buffer b;
        memset(&b, 0, sizeof(b));
        b.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        b.memory = V4L2_MEMORY_USERPTR;
        b.index = i;
        b.m.userptr = (unsigned long)ctx->userptrs[i];
        b.length = stride;
        if (xioctl(fd, VIDIOC_QBUF, &b) < 0) {
            return -1;
        }
    }
    return 0;
}

static int v4l2_discard_initial_frames(int fd, struct v4l2_context *ctx,
                                       unsigned int discard)
{
    if (!ctx || ctx->buffer_count == 0) {
        errno = EINVAL;
        return -1;
    }

    unsigned int dropped = 0;
    while (dropped < discard) {
        if (should_stop()) {
            return 0;
        }
        struct v4l2_buffer b;
        memset(&b, 0, sizeof(b));
        b.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        b.memory = V4L2_MEMORY_USERPTR;

        if (xioctl(fd, VIDIOC_DQBUF, &b) < 0) {
            if (errno == EAGAIN) {
                usleep(1000);
                continue;
            }
            return -1;
        }

        ctx->frames_dequeued++;
        ctx->frames_discarded++;
        if (b.index < ctx->buffer_count) {
            struct v4l2_buffer q;
            memset(&q, 0, sizeof(q));
            q.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
            q.memory = V4L2_MEMORY_USERPTR;
            q.index = b.index;
            q.m.userptr = (unsigned long)ctx->userptrs[b.index];
            q.length = ctx->buffer_stride;
            if (xioctl(fd, VIDIOC_QBUF, &q) < 0) {
                return -1;
            }
            ctx->frames_requeued++;
        }

        ++dropped;
        if (ctx->frames_discarded <= 5 || (ctx->frames_discarded % 30U) == 0U) {
            fprintf(stderr,
                    "[v4l2] descartado frame #%" PRIu64 " (sequence=%u)\n",
                    ctx->frames_discarded, b.sequence);
        }
    }
    return 0;
}

static int v4l2_start_capture(int fd, struct v4l2_context *ctx,
                              unsigned int discard_frames)
{
    if (!ctx) {
        errno = EINVAL;
        return -1;
    }

    if (ctx->stream_on) {
        return 0;
    }

    if (ctx->buffer_count == 0) {
        errno = EINVAL;
        return -1;
    }

    enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (xioctl(fd, VIDIOC_STREAMON, &type) < 0) {
        return -1;
    }
    ctx->stream_on = true;

    if (discard_frames == 0) {
        return 0;
    }

    if (v4l2_discard_initial_frames(fd, ctx, discard_frames) < 0) {
        return -1;
    }
    return 0;
}

static int handle_v4l2_frame(int fd, struct v4l2_context *ctx)
{
    if (!ctx) {
        errno = EINVAL;
        return -1;
    }

    struct v4l2_buffer b;
    memset(&b, 0, sizeof(b));
    b.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    b.memory = V4L2_MEMORY_USERPTR;

    if (xioctl(fd, VIDIOC_DQBUF, &b) < 0) {
        if (errno == EAGAIN) {
            return 0;
        }
        return -1;
    }

    ctx->frames_dequeued++;
    if (b.index < ctx->buffer_count) {
        struct v4l2_buffer q;
        memset(&q, 0, sizeof(q));
        q.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        q.memory = V4L2_MEMORY_USERPTR;
        q.index = b.index;
        q.m.userptr = (unsigned long)ctx->userptrs[b.index];
        q.length = ctx->buffer_stride;
        if (xioctl(fd, VIDIOC_QBUF, &q) < 0) {
            return -1;
        }
        ctx->frames_requeued++;
    }

    if (ctx->frames_dequeued <= 5 || (ctx->frames_dequeued % 30U) == 0U) {
        fprintf(stderr,
                "[v4l2] frame #%" PRIu64 " dequeued (sequence=%u bytesused=%u)\n",
                ctx->frames_dequeued, b.sequence, b.bytesused);
    }

    return 1;
}

int main(int argc, char **argv)
{
    const char *conf_path = DEFAULT_CONF_PATH;
    const char *nr3d_path = DEFAULT_NR3D_BLOB;
    const char *user_params_path = DEFAULT_USER_PARAMS;
    const char *output_path = DEFAULT_OUTPUT_PATH;
    unsigned int frame_target = DEFAULT_FRAME_COUNT;
    int conf_pack = 0;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--conf") == 0 && i + 1 < argc) {
            conf_path = argv[++i];
        } else if (strcmp(argv[i], "--nr3d") == 0 && i + 1 < argc) {
            nr3d_path = argv[++i];
        } else if (strcmp(argv[i], "--user") == 0 && i + 1 < argc) {
            user_params_path = argv[++i];
        } else if (strcmp(argv[i], "--pack") == 0 && i + 1 < argc) {
            conf_pack = (int)strtol(argv[++i], NULL, 10);
            if (conf_pack < 0 || conf_pack > 1) {
                fprintf(stderr, "Pack ISP invalido: %d\n", conf_pack);
                return EXIT_FAILURE;
            }
        } else if (strcmp(argv[i], "--frames") == 0 && i + 1 < argc) {
            frame_target = (unsigned int)strtoul(argv[++i], NULL, 10);
        } else if (strcmp(argv[i], "--output") == 0 && i + 1 < argc) {
            output_path = argv[++i];
        } else if (strcmp(argv[i], "--help") == 0) {
            usage(argv[0]);
            return EXIT_SUCCESS;
        } else {
            usage(argv[0]);
            return EXIT_FAILURE;
        }
    }

    int exit_code = EXIT_FAILURE;
    int vfd = -1;
    int uio_fd = -1;
    int out_fd = -1;
    struct dump_writer writer;
    memset(&writer, 0, sizeof(writer));
    writer.fd = -1;
    bool isp_initialized = false;
    bool isp_capture_enabled = false;
    struct ion_region ion = {
        .dmabuf_fd = -1,
        .map = MAP_FAILED,
        .len = 0,
        .phys_base = 0,
        .phys_base_valid = 0,
    };
    struct venc_context venc;
    memset(&venc, 0, sizeof(venc));
    struct v4l2_context v4l2_ctx;
    memset(&v4l2_ctx, 0, sizeof(v4l2_ctx));
    enum ak_uio_irq_mode irq_mode = AK_UIO_IRQ_MODE_AK;

    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = on_signal;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGINT, &sa, NULL) < 0) {
        perror("sigaction(SIGINT)");
    }
    if (sigaction(SIGTERM, &sa, NULL) < 0) {
        perror("sigaction(SIGTERM)");
    }

    ion = ion_reserve_and_map();
    fprintf(stderr, "[ion] fd=%d map=%p len=%zu\n", ion.dmabuf_fd, ion.map, ion.len);
    if (ion.phys_base_valid) {
        fprintf(stderr, "[ion] base física=0x%08x\n", ion.phys_base);
    }
    if (ion.dmabuf_fd < 0 || ion.map == MAP_FAILED || ion.len == 0) {
        fprintf(stderr, "[ion] reserva/mapa de región inválida\n");
        goto cleanup;
    }

    uio_fd = xopen("/dev/uio0", O_RDWR);
    set_fd_nonblock(uio_fd, "/dev/uio0");

    if (ak_isp_sdk_init() != 0) {
        fprintf(stderr, "ak_isp_sdk_init fallo\n");
        goto cleanup;
    }
    isp_initialized = true;

    vfd = xopen("/dev/video0", O_RDWR);
    set_fd_nonblock(vfd, "/dev/video0");


    if (conf_path && isp_apply_conf_pack(conf_path, conf_pack) != 0) {
        fprintf(stderr, "isp_apply_conf('%s') fallo\n", conf_path);
        goto cleanup;
    }

    if (nr3d_path && isp_load_3dnr_ref(nr3d_path) != 0) {
        fprintf(stderr, "isp_load_3dnr_ref('%s') fallo\n", nr3d_path);
        goto cleanup;
    }

    if (user_params_path && isp_load_user_params(user_params_path) != 0) {
        fprintf(stderr, "isp_load_user_params('%s') fallo\n", user_params_path);
        goto cleanup;
    }

    fprintf(stderr, "[main] llamando isp_configure_runtime\n");
    if (isp_configure_runtime() != 0) {
        fprintf(stderr, "isp_configure_runtime fallo\n");
    }
    fprintf(stderr, "[main] isp_configure_runtime retornó\n");

    fprintf(stderr, "[main] isp_configure_runtime ok, abriendo salida %s\n", output_path);

    out_fd = open(output_path, O_CREAT | O_WRONLY | O_TRUNC | O_CLOEXEC, 0644);
    if (out_fd < 0) {
        perror(output_path);
        goto cleanup;
    }

    fprintf(stderr, "[main] salida abierta, configurando V4L2\n");

    if (setup_v4l2(vfd, &ion, &v4l2_ctx) != 0) {
        perror("setup_v4l2");
        goto cleanup;
    }

    fprintf(stderr, "[main] V4L2 configurado (buffers=%u stride=%zu)\n",
            v4l2_ctx.buffer_count, v4l2_ctx.buffer_stride);

    if (venc_context_init(&venc, uio_fd, &ion, v4l2_ctx.width) != 0) {
        fprintf(stderr, "venc_context_init fallo\n");
        goto cleanup;
    }

    if (ak_uio_ack_read_mode(uio_fd) != 0) {
        fprintf(stderr, "ak_uio_ack_read_mode fallo: %s\n", strerror(errno));
    } else {
        uint32_t st = rd32(venc.regs, REG_IRQ_STATUS);
        if (st & 1U) {
            wr32(venc.regs, REG_IRQ_STATUS, st & ~1U);
            fprintf(stderr, "[venc] IRQ status inicial limpiado (0x%08x)\n", st);
        }
    }

    if (v4l2_start_capture(vfd, &v4l2_ctx, v4l2_ctx.buffer_count) != 0) {
        perror("v4l2_start_capture");
        goto cleanup;
    }

    struct isp_capturing_param capture_on = {
        .enable = 1U,
        .reserved = 0U,
    };
    if (ak_isp_set_isp_capturing(&capture_on) != 0) {
        fprintf(stderr, "ak_isp_set_isp_capturing(1) fallo\n");
    } else {
        fprintf(stderr, "[isp] captura habilitada\n");
        isp_capture_enabled = true;
    }

    ensure_aux_devices_open();
    configure_mic_device();
    configure_spkr_device();

    /*
     * testing.c nunca manipula el flag de captura del ISP de forma
     * explícita: confía en que el binario de fábrica deja la canalización
     * en un estado listo tras aplicar la configuración. Replicamos ese
     * comportamiento para evitar el NULL deref observado en
     * ak_isp_vo_set_main_channel_scale cuando llamábamos al ioctl directo.
     */
    dump_writer_init(&writer, out_fd, output_path);

    printf("Capturando %u frames a %s (stride=%zu buffers=%u)\n",
           frame_target, output_path, v4l2_ctx.buffer_stride, v4l2_ctx.buffer_count);

    struct pollfd v4l2_pfd;
    memset(&v4l2_pfd, 0, sizeof(v4l2_pfd));
    v4l2_pfd.fd = vfd;
    v4l2_pfd.events = POLLIN | POLLERR | POLLHUP;

    while (v4l2_ctx.frames_dequeued < (uint64_t)frame_target && !should_stop()) {
        int drained = venc_pump_irqs(&venc, uio_fd, &irq_mode, &writer, 0);
        if (drained < 0) {
            goto cleanup;
        }

        int timeout_ms = drained ? 0 : 100;
        v4l2_pfd.revents = 0;
        int pr = poll(&v4l2_pfd, 1, timeout_ms);
        if (pr < 0) {
            if (errno == EINTR) {
                if (should_stop()) {
                    break;
                }
                continue;
            }
            perror("poll");
            goto cleanup;
        }

        if (pr == 0) {
            continue;
        }

        if (v4l2_pfd.revents & (POLLERR | POLLHUP | POLLNVAL)) {
            fprintf(stderr, "[v4l2] evento revents=0x%x\n", v4l2_pfd.revents);
        }
        if (v4l2_pfd.revents & (POLLIN | POLLPRI)) {
            int rv = handle_v4l2_frame(vfd, &v4l2_ctx);
            if (rv < 0) {
                perror("VIDIOC_DQBUF");
                goto cleanup;
            } else if (rv > 0) {
                uint64_t frames_done = v4l2_ctx.frames_dequeued;
                if (frames_done <= 5ULL || (frames_done % 30ULL) == 0ULL) {
                    fprintf(stderr,
                            "[main] frames capturados=%" PRIu64 " (H264=%" PRIu64 " bytes)\n",
                            frames_done, venc.total_bytes_flushed);
                }
            }
        }

        if (venc_pump_irqs(&venc, uio_fd, &irq_mode, &writer, 0) < 0) {
            goto cleanup;
        }
    }

    if (venc_pump_irqs(&venc, uio_fd, &irq_mode, &writer, 0) < 0) {
        goto cleanup;
    }
    venc_context_poll_flush(&venc, &writer, 1);

    if (should_stop()) {
        fprintf(stderr,
                "[main] señal recibida, finalizando tras %" PRIu64 " frames y %" PRIu64
                " bytes H.264\n",
                v4l2_ctx.frames_dequeued, venc.total_bytes_flushed);
    } else {
        printf("Captura completada: %" PRIu64 " frames\n", v4l2_ctx.frames_dequeued);
    }

    exit_code = EXIT_SUCCESS;

cleanup:
    if (should_stop() && exit_code != EXIT_SUCCESS) {
        fprintf(stderr,
                "[main] limpieza tras señal: frames=%" PRIu64 " bytes=%" PRIu64
                " requeued=%" PRIu64 " discarded=%" PRIu64 "\n",
                v4l2_ctx.frames_dequeued, venc.total_bytes_flushed,
                v4l2_ctx.frames_requeued, v4l2_ctx.frames_discarded);
    }
    if (v4l2_ctx.stream_on) {
        enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        if (vfd >= 0) {
            if (xioctl(vfd, VIDIOC_STREAMOFF, &type) < 0) {
                perror("VIDIOC_STREAMOFF");
            }
        }
        v4l2_ctx.stream_on = false;
    }
    if (out_fd >= 0) {
        dump_writer_maybe_sync(&writer, 1);
        close(out_fd);
        writer.fd = -1;
    }
    if (vfd >= 0) {
        xclose(vfd);
    }
    venc_context_destroy(&venc);
    if (uio_fd >= 0) {
        xclose(uio_fd);
    }
    ion_region_release(&ion);

    if (g_fd_spkr >= 0) {
        close(g_fd_spkr);
        g_fd_spkr = -1;
        g_spkr_configured = false;
    }
    if (g_fd_mic >= 0) {
        close(g_fd_mic);
        g_fd_mic = -1;
        g_mic_configured = false;
    }

    if (isp_capture_enabled) {
        struct isp_capturing_param capture_off = {
            .enable = 0U,
            .reserved = 0U,
        };
        if (ak_isp_set_isp_capturing(&capture_off) != 0) {
            fprintf(stderr, "ak_isp_set_isp_capturing(0) fallo\n");
        }
        isp_capture_enabled = false;
    }

    if (isp_initialized && ak_isp_sdk_exit() != 0) {
        fprintf(stderr, "ak_isp_sdk_exit fallo\n");
    }

    return exit_code;
}

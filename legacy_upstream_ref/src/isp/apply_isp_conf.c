/*
 * apply_isp_conf.c — Parser simple + aplicador de secciones ISP con switch por ID (hex)
 * Autor: Abel Romero
 * Licencia: MIT
 *
 * Formato de fichero .conf (real):
 *   - magic LE32 = 3 en offset 0x00
 *   - cabecera de 0x200 bytes
 *   - a partir de 0x200: bloques consecutivos
 *       [u16 id][u16 size][size-4 bytes de payload]
 *     * size incluye los 4 bytes de cabecera del bloque
 *
 * Cambio solicitado: si el payload es demasiado corto para un offset,
 * se omite esa función y se continúa con la siguiente.
 *
 * Compilar (ejemplo):
 *   gcc -std=c99 -O2 -Wall -Wextra apply_isp_conf.c libakispsdk.so -o apply_isp -ldl
 *
 * Ejecutar:
 *   ./apply_isp /usr/local/isp_sc1345_dvp.conf
 */
#define _GNU_SOURCE
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <linux/videodev2.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define PACK_HDR 0x200

static void msleep(unsigned ms) {
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000UL;
    while (nanosleep(&ts, &ts) == -1 && errno == EINTR) {}
}

static void die_perror(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

static int xopen(const char *path, int flags) {
    int fd = open(path, flags, 0666);
    if (fd < 0) die_perror(path);
    return fd;
}

static void xclose(int fd) {
    if (fd >= 0) close(fd);
}

static int xioctl(int fd, unsigned long req, const void *arg) {
    int r;
    do { r = ioctl(fd, req, arg); } while (r == -1 && errno == EINTR);
    return r;
}

/*
* ---------------- ION (según traza) ----------------
* IOCTLs por valor literal (coinciden con la traza):
*   ION_IOC_ALLOC = 0xc0144900 (size=20)
*   ION_IOC_MAP   = 0xc0084902 (size=8)
*
* Estructuras mínimas compatibles con tamaño reportado en la traza.
*/

#define ION_IOC_ALLOC 0xc0144900UL
#define ION_IOC_MAP   0xc0084902UL

struct ion_allocation_data_compat {
    uint32_t len;           // 0x01800000 -> 25,165,824
    uint32_t align;         // 0x00001000
    uint32_t heap_id_mask;  // 0x000000ff
    uint32_t flags;         // 0x00000003
    uint32_t handle;        // OUT
}; // size == 20

struct ion_fd_data_compat {
    uint32_t handle;        // IN
    int32_t  fd;            // OUT
}; // size == 8

struct ion_region {
    int      dmabuf_fd;
    void    *map;
    size_t   len;
};

/* Estructura detectada en la traza */
struct blob_desc {
    uint32_t nwords; /* nº de palabras de 32 bits */
    void    *ptr;    /* puntero al blob de datos */
};

/* Reserva, mapea y devuelve región (según traza) */
static struct ion_region ion_reserve_and_map(void) {
    struct ion_region r = { .dmabuf_fd = -1, .map = MAP_FAILED, .len = 0 };

    // 1) OPEN /dev/ion
    int ionfd = xopen("/dev/ion", O_RDWR);

    // 2) ION_IOC_ALLOC
    struct ion_allocation_data_compat a;
    memset(&a, 0, sizeof(a));
    a.len          = 0x01800000U; // 25,165,824
    a.align        = 0x00001000U; // 4 KiB
    a.heap_id_mask = 0x000000ffU;
    a.flags        = 0x00000003U;

    if (xioctl(ionfd, ION_IOC_ALLOC, &a) < 0) {
        die_perror("ION_IOC_ALLOC");
    }

    // 3) ION_IOC_MAP
    struct ion_fd_data_compat m;
    memset(&m, 0, sizeof(m));
    m.handle = a.handle;
    m.fd     = 0;
    if (xioctl(ionfd, ION_IOC_MAP, &m) < 0) {
        die_perror("ION_IOC_MAP");
    }

    // 4) MMAP del dmabuf a 24 MiB
    r.len = a.len;
    r.dmabuf_fd = m.fd;
    r.map = mmap(NULL, r.len, PROT_READ | PROT_WRITE, MAP_SHARED, r.dmabuf_fd, 0);
    if (r.map == MAP_FAILED) die_perror("mmap(dmabuf)");

    // cerramos /dev/ion; el dmabuf sigue vivo por el fd
    xclose(ionfd);
    return r;
}

struct isp_3dnr_ref_desc {
    uint32_t base;    // p.ej. puntero base a la tabla/ref en la .conf
    uint32_t ptr_a;   // base + 2*index
    uint32_t ptr_b;   // ptr_a + 2*((index+3)>>2)
    uint32_t pitch;   // 2*index
    uint32_t height;  // 2*((index+3)>>2)
};

/* ===================== helpers LE ===================== */
static inline uint16_t rd_le16(const uint8_t *p) {
    return (uint16_t)p[0] | ((uint16_t)p[1] << 8);
}
static inline uint32_t rd_le32(const uint8_t *p) {
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

/* ===================== SDK ISP (prototipos) ===================== */
extern int AK_ISP_sdk_init(void);
extern int AK_ISP_sdk_exit(void);

extern int AK_ISP_set_blc_attr(void *p);
extern int AK_ISP_set_lsc_attr(void *p);
extern int AK_ISP_set_raw_lut_attr(void *p);
extern int AK_ISP_set_nr1_attr(void *p);
extern int AK_ISP_set_nr2_attr(void *p);
extern int AK_ISP_set_3d_nr_attr(void *p);
extern int AK_ISP_set_gb_attr(void *p);
extern int AK_ISP_set_demo_attr(void *p);
extern int AK_ISP_set_rgb_gamma_attr(void *p);
extern int AK_ISP_set_ccm_attr(void *p);
extern int AK_ISP_set_fcs_attr(void *p);
extern int AK_ISP_set_wdr_attr(void *p);
extern int AK_ISP_set_sharp_attr(void *p);
extern int AK_ISP_set_sharp_ex_attr(void *p);
extern int AK_ISP_set_saturation_attr(void *p);
extern int AK_ISP_set_contrast_attr(void *p);
extern int AK_ISP_set_rgb2yuv_attr(void *p);
extern int AK_ISP_set_effect_attr(void *p);
extern int AK_ISP_set_dpc_attr(void *p);
extern int AK_ISP_set_sdpc_attr(void *p);
extern int AK_ISP_set_weight_attr(void *p);
extern int AK_ISP_set_af_attr(void *p);
extern int AK_ISP_set_wb_type(void *p);
extern int AK_ISP_set_mwb_attr(void *p);
extern int AK_ISP_set_awb_attr(void *p);
extern int AK_ISP_set_awb_ex_attr(void *p);
extern int AK_ISP_set_raw_hist_attr(void *p);
extern int AK_ISP_set_rgb_hist_attr(void *p);
extern int AK_ISP_set_yuv_hist_attr(void *p);
extern int AK_ISP_set_exp_type(void *p);
extern int AK_ISP_set_frame_rate(void *p);
extern int AK_ISP_set_ae_attr(void *p);
extern int AK_ISP_set_misc_attr(void *p);
extern int AK_ISP_set_Y_gamma_attr(void *p);
extern int AK_ISP_set_hue_attr(void *p);
extern int AK_ISP_set_3d_nr_ref_attr(void *p);

extern int Ak_ISP_Set_Sensor_Fps(void *p);
extern int Ak_ISP_Set_User_Params(void *p);

extern int Ak_ISP_Get_Sensor_Fps(void *p);

extern int AK_ISP_get_frame_rate(void *p);
extern int AK_ISP_get_awb_attr(void * p);

extern int Ak_ISP_Sensor_Load_Conf(void *p);

/* ===================== loader de blobs ===================== */
typedef struct {
    void *data;    /* puntero a los bytes cargados (malloc) */
    size_t size;   /* tamaño en bytes */
} blob_t;

static int load_blob(const char *path, blob_t *out) {
    if (!path || !out) {
        errno = EINVAL;
        return -1;
    }
    out->data = NULL;
    out->size = 0;

    struct stat st;
    if (stat(path, &st) != 0) return -1;

    size_t size = (size_t)st.st_size;
    FILE *f = fopen(path, "rb");
    if (!f) return -1;

    if (size == 0) { fclose(f); return 0; }

    void *buf = malloc(size);
    if (!buf) { fclose(f); errno = ENOMEM; return -1; }

    size_t readn = 0;
    while (readn < size) {
        size_t r = fread((uint8_t*)buf + readn, 1, size - readn, f);
        if (r == 0) {
            if (feof(f)) break;
            if (ferror(f)) { int saved = errno; free(buf); fclose(f); errno = saved ? saved : EIO; return -1; }
        }
        readn += r;
    }
    fclose(f);

    if (readn != size) {
        void *shrunk = realloc(buf, readn ? readn : 1);
        if (shrunk || readn == 0) {
            buf = shrunk;
            out->data = buf;
            out->size = readn;
            return 0;
        } else {
            free(buf);
            errno = ENOMEM;
            return -1;
        }
    }

    out->data = buf;
    out->size = size;
    return 0;
}

static void free_blob(blob_t *b) {
    if (!b) return;
    if (b->data) { free(b->data); b->data = NULL; }
    b->size = 0;
}

/* ===================== list_isp_conf_simple ===================== */
/* Recorre la conf y llama cb(id, payload, payload_len, user) por bloque. */
static int list_isp_conf_simple(const char *path,
                                int (*cb)(uint32_t id, const uint8_t *payload, size_t payload_len, void *user),
                                void *user)
{
    if (!path || !cb) return -1;

    FILE *f = fopen(path, "rb");
    if (!f) { perror(path); return -2; }

    if (fseek(f, 0, SEEK_END) != 0) { perror("fseek"); fclose(f); return -3; }
    long n_long = ftell(f);
    if (n_long < 0) { perror("ftell"); fclose(f); return -4; }
    size_t n = (size_t)n_long;
    if (fseek(f, 0, SEEK_SET) != 0) { perror("fseek"); fclose(f); return -5; }

    uint8_t *buf = (uint8_t*)malloc(n ? n : 1);
    if (!buf) { perror("malloc"); fclose(f); return -6; }

    if (n && fread(buf, 1, n, f) != n) {
        perror("fread");
        free(buf);
        fclose(f);
        return -7;
    }
    fclose(f);

    const uint32_t MAGIC = 3;
    if (n < PACK_HDR + 4) {
        fprintf(stderr, "fichero demasiado pequeño (0x%zx bytes)\n", n);
        free(buf);
        return -8;
    }
    if (rd_le32(buf) != MAGIC) {
        fprintf(stderr, "magic inválido (esperaba 3)\n");
        free(buf);
        return -9;
    }

    size_t pos = PACK_HDR; /* empezamos tras la cabecera inicial de 0x200 */

    while (pos + 4 <= n) {
        if (pos + 4 > n) break;

        uint16_t id   = rd_le16(buf + pos + 0);
        uint16_t size = rd_le16(buf + pos + 2); /* incluye cabecera */

        /* Si no hay bloque válido, damos por terminado (relleno/ruido) */
        if (size < 4) {
            /* salir del bucle sin error: fin del pack/archivo */
            break;
        }
        if (pos + size > n) {
            /* no cabe el bloque entero: fin limpio */
            break;
        }

        const uint8_t *payload     = buf + pos + 4;
        size_t         payload_len = (size_t)size - 4;

        /* --- NUEVO: detectar trailer 0x00010100 tras 0x1c --- */
        size_t trailer4 = 0;
        if (id == 0x1c) {
            size_t after_block = pos + size;              // fin del bloque actual
            if (after_block + 4 <= n) {
                uint32_t tail = rd_le32(buf + after_block);
                if (tail == 0x00010100U) {
                    trailer4 = 4;
                    /* Exponemos al callback el payload extendido como hace el firmware (len=296) */
                    payload_len += trailer4;
                }
            }
        }

        int rc = cb((uint32_t)id, payload, payload_len, user);
        if (rc != 0) { free(buf); return rc; }

        pos += size;

        if (id == 0x1c) {
            /* El siguiente MAGIC puede estar en pos + 4 + trailer4 */
            size_t next_magic = pos + 4 + trailer4;
            if (next_magic + 4 > n) break;
            if (rd_le32(buf + next_magic) != MAGIC) break;
            size_t next_pos = next_magic + PACK_HDR;
            if (next_pos > n) break;
            pos = next_pos;
        }
        /* si no era 0x1c, seguimos con el siguiente bloque en este mismo pack */
    }

    /* aviso de residuo no nulo (opcional) */
    if (pos < n) {
        size_t rem = n - pos;
        int only_zeros = 1;
        for (size_t i = 0; i < rem; ++i) {
            if (buf[pos + i] != 0) { only_zeros = 0; break; }
        }
        if (!only_zeros) {
            fprintf(stderr, "aviso: residuo no nulo al final (%zu bytes)\n", rem);
        }
    }

    free(buf);
    return 0;
}

/* ======= política de “payload corto ⇒ omitir” ======= */
#define PAYLOAD_OK(off,need) ((payload_len) >= (size_t)((off) + (need)))
#define TRY(off,need,call) \
    do { \
        if (PAYLOAD_OK((off),(need))) { call; } \
        else { \
            size_t faltan = (size_t)((off)+(need)) - payload_len; \
            fprintf(stderr,"[skip] id=0x%x: faltan %zu bytes para %s (need off=0x%zx need=%zu, have=%zu)\n", \
                case_id_hex, faltan, #call, (size_t)(off), (size_t)(need), payload_len); \
        } \
    } while(0)

static int apply_vendor_case(uint32_t case_id_hex, uint8_t *payload, size_t payload_len)
{
    int rc = 0;

    switch (case_id_hex) {
        case 0x0:
            TRY(0x0000, 1, AK_ISP_set_blc_attr(payload + 0x0000));
            break;

        case 0x1:
            TRY(0x0000, 1, AK_ISP_set_lsc_attr(payload + 0x0000));
            break;

        case 0x2:
            TRY(0x0000, 1, AK_ISP_set_raw_lut_attr(payload + 0x0000));
            break;

        case 0x3:
            TRY(0x0000, 1,    AK_ISP_set_nr1_attr(payload + 0x0000));
            TRY(0x06fa, 1,    AK_ISP_set_nr2_attr(payload + 0x06fa));
            break;

        case 0x4:
            TRY(0x0000, 1, AK_ISP_set_3d_nr_attr(payload + 0x0000));
            break;

        case 0x5:
            TRY(0x0000, 1, AK_ISP_set_gb_attr(payload + 0x0000));
            break;

        case 0x6:
            TRY(0x0000, 1, AK_ISP_set_demo_attr(payload + 0x0000));
            break;

        case 0x7:
            TRY(0x0000, 1, AK_ISP_set_rgb_gamma_attr(payload + 0x0000));
            break;

        case 0x8:
            TRY(0x0000, 1, AK_ISP_set_ccm_attr(payload + 0x0000));
            break;

        case 0x9:
            TRY(0x0000, 1, AK_ISP_set_fcs_attr(payload + 0x0000));
            break;

        case 0xa:
            TRY(0x0000, 1, AK_ISP_set_wdr_attr(payload + 0x0000));
            break;

        case 0xb:
            TRY(0x0000, 1,    AK_ISP_set_sharp_attr(payload + 0x0000));
            TRY(0x2b3a, 1,    AK_ISP_set_sharp_ex_attr(payload + 0x2b3a));
            break;

        case 0xc:
            TRY(0x0000, 1, AK_ISP_set_saturation_attr(payload + 0x0000));
            break;

        case 0xd:
            TRY(0x0000, 1, AK_ISP_set_contrast_attr(payload + 0x0000));
            break;

        case 0xe:
            TRY(0x0000, 1, AK_ISP_set_rgb2yuv_attr(payload + 0x0000));
            break;

        case 0xf:
            TRY(0x0000, 1, AK_ISP_set_effect_attr(payload + 0x0000));
            break;

        case 0x10:
            TRY(0x0000, 1, AK_ISP_set_dpc_attr(payload + 0x0000));
            TRY(0x0058, 1, AK_ISP_set_sdpc_attr(payload + 0x0058));
            break;

        case 0x11:
            TRY(0x0000, 1, AK_ISP_set_weight_attr(payload + 0x0000));
            break;

        case 0x12:
            TRY(0x0000, 1, AK_ISP_set_af_attr(payload + 0x0000));
            break;

        case 0x13:
            TRY(0x0000, 1, AK_ISP_set_wb_type(payload + 0x0000));
            TRY(0x0006, 1, AK_ISP_set_mwb_attr(payload + 0x0006));
            TRY(0x0012, 1, AK_ISP_set_awb_attr(payload + 0x0012));
            TRY(0x00cc, 1, AK_ISP_set_awb_ex_attr(payload + 0x00cc));
            break;

        case 0x14: {
            TRY(0x0000, 1, AK_ISP_set_raw_hist_attr(payload + 0x0000));
            TRY(0x0006, 1, AK_ISP_set_rgb_hist_attr(payload + 0x0006));
            TRY(0x0008, 1, AK_ISP_set_yuv_hist_attr(payload + 0x0008));
            TRY(0x000a, 1, AK_ISP_set_exp_type(payload + 0x000a));
            TRY(0x000c, 1, AK_ISP_set_frame_rate(payload + 0x000c));
            TRY(0x0024, 1, AK_ISP_set_ae_attr(payload + 0x0024));

            if (PAYLOAD_OK(0x000c, 4)) {
                uint32_t raw = rd_le32(payload + 0x000c);
                uint16_t fps  = rd_le16(payload + 0x000c);
                uint16_t mode = rd_le16(payload + 0x000e);
                printf("[set] frame_rate: fps=%u, mode=%u (raw=0x%08x)\n", fps, mode, raw);

                AK_ISP_get_frame_rate(payload + 0x000c);
                raw  = rd_le32(payload + 0x000c);
                fps  = rd_le16(payload + 0x000c);
                mode = rd_le16(payload + 0x000e);
                printf("[get] frame_rate: fps=%u, mode=%u (raw=0x%08x)\n", fps, mode, raw);
            }

            uint32_t sensor_fps = 0x0000000f;
            Ak_ISP_Set_Sensor_Fps(&sensor_fps);
        } break;

        case 0x15:
            TRY(0x0000, 1, AK_ISP_set_misc_attr(payload + 0x0000));
            break;

        case 0x16:
            TRY(0x0000, 1, AK_ISP_set_Y_gamma_attr(payload + 0x0000));
            break;

        case 0x17:
            TRY(0x0000, 1, AK_ISP_set_hue_attr(payload + 0x0000));
            break;

        case 0x1c: {
            struct blob_desc desc = {
                .nwords = (uint32_t)(payload_len / 4),  // 73 si 292; 74 si 296 (con trailer)
                .ptr    = payload,
            };
            Ak_ISP_Sensor_Load_Conf(&desc);
        } break;

        default:
            fprintf(stderr, "[apply] id 0x%x desconocido\n", case_id_hex);
            if (rc == 0) rc = -1;
            break;
    }

    return rc; /* 0 si todo ok, o primer error del SDK si lo hubo */
}


/* ===================== callback del parser ===================== */
static int on_section(uint32_t id, const uint8_t *payload, size_t payload_len, void *user)
{
    (void)user;
    printf("[isp_conf] id: 0x%x, len: %zu\n", id, payload_len);
    return apply_vendor_case(id, (uint8_t*)payload, payload_len);
}

/* ===================== main ===================== */
int main(int argc, char **argv)
{
    const char *path = (argc > 1) ? argv[1] : "isp_sc1345_dvp.conf";

    /* 1) Reservamos buffer con /dev/ion, tal cual la traza (len=0x01800000) */
    struct ion_region ion = ion_reserve_and_map();
    fprintf(stderr, "[ion] dmabuf_fd=%d map=%p len=%zu\n", ion.dmabuf_fd, ion.map, ion.len);

    /* 2) Abrimos /dev/uio0 y /dev/null como en la traza (no se usan aquí) */
    int uiofd   = xopen("/dev/uio0", O_RDWR);
    int nullw   = xopen("/dev/null", O_WRONLY);

    /* 3) SDK + VIDEO */
    int rc = AK_ISP_sdk_init();
    if (rc != 0) {
        fprintf(stderr, "AK_ISP_sdk_init() fallo rc=%d\n", rc);
        goto cleanup_fail;
    }

    int vfd = xopen("/dev/video0",  O_RDWR | O_NONBLOCK);

    /* BLOQUE 1: aplicar secciones de la conf */
    rc = list_isp_conf_simple(path, on_section, NULL);
    if (rc != 0) {
        fprintf(stderr, "list_isp_conf_simple('%s') rc=%d\n", path, rc);
        goto cleanup_fail;
    }

    /* --- VIDIOC_CROPCAP (extra info) --- */
    struct v4l2_cropcap cap;
    memset(&cap, 0, sizeof(cap));
    cap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (xioctl(vfd, VIDIOC_CROPCAP, &cap) < 0) die_perror("VIDIOC_CROPCAP");
    printf("[v4l2_cropcap]\ntype=%u\n", cap.type);
    printf("bounds:   left=%d top=%d width=%u height=%u\n",
           cap.bounds.left, cap.bounds.top, cap.bounds.width, cap.bounds.height);
    printf("defrect:  left=%d top=%d width=%u height=%u\n",
           cap.defrect.left, cap.defrect.top, cap.defrect.width, cap.defrect.height);
    printf("pixelaspect: %u/%u\n", cap.pixelaspect.numerator, cap.pixelaspect.denominator);

    /* BLOQUE 2: llamadas sueltas (3DNR ref, AWB/FR) */
    blob_t nr3d_ref_blob;
    if (load_blob("isp_3dnr_ref_attr_pid518_fd10_req0x40044967_20250930T130454.bin", &nr3d_ref_blob) != 0) {
        perror("load_blob(3dnr_ref)");
        goto cleanup_fail;
    }
    AK_ISP_set_3d_nr_ref_attr(nr3d_ref_blob.data);

    uint32_t awb_attr = 0;
    AK_ISP_get_awb_attr(&awb_attr);
    printf("[get] awb_attr: 0x%x\n", awb_attr);

    awb_attr = 0x0008000f;
    AK_ISP_set_awb_attr(&awb_attr);
    printf("[set] awb_attr: 0x%x\n", awb_attr);

    uint32_t frame_rate_raw = 0;
    AK_ISP_get_frame_rate(&frame_rate_raw);
    const uint8_t *pf = (const uint8_t*)&frame_rate_raw;
    uint16_t fps  = rd_le16(pf);
    uint16_t mode = rd_le16(pf + 2);
    printf("[get] frame_rate: fps=%u, mode=%u (raw=0x%08x)\n",
           fps, mode, frame_rate_raw);

    uint32_t sens_fps = 0x0000000f;
    Ak_ISP_Set_Sensor_Fps(&sens_fps);

    // --- VIDIOC_QUERYCAP ---
    struct v4l2_capability caps;
    memset(&caps, 0, sizeof(caps));
    if (xioctl(vfd, VIDIOC_QUERYCAP, &caps) < 0) die_perror("VIDIOC_QUERYCAP");
    printf("driver=%s, card=%s, bus_info=%s, version=%u, capabilities=0x%x, device_caps=0x%x\n",
           caps.driver, caps.card, caps.bus_info, caps.version, caps.capabilities, caps.device_caps);

    // --- VIDIOC_CROPCAP ---
    struct v4l2_cropcap cropcap;
    memset(&cropcap, 0, sizeof(cropcap));
    cropcap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (xioctl(vfd, VIDIOC_CROPCAP, &cropcap) < 0) die_perror("VIDIOC_CROPCAP");
    printf("bounds: %d,%d %ux%u\n", cropcap.bounds.left, cropcap.bounds.top,
           cropcap.bounds.width, cropcap.bounds.height);
    printf("defrect: %d,%d %ux%u\n", cropcap.defrect.left, cropcap.defrect.top,
           cropcap.defrect.width, cropcap.defrect.height);
    printf("pixelaspect=%u/%u\n", cropcap.pixelaspect.numerator, cropcap.pixelaspect.denominator);

    // --- VIDIOC_S_CROP ---
    struct v4l2_crop crop;
    memset(&crop, 0, sizeof(crop));
    crop.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    crop.c = cropcap.defrect;  // igual que la traza
    if (xioctl(vfd, VIDIOC_S_CROP, &crop) < 0) die_perror("VIDIOC_S_CROP");

    // --- VIDIOC_S_FMT ---
    struct v4l2_format fmt;
    memset(&fmt, 0, sizeof(fmt));
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = 1280;
    fmt.fmt.pix.height = 720;
    fmt.fmt.pix.pixelformat = v4l2_fourcc('Y','U','Y','V');
    fmt.fmt.pix.field = V4L2_FIELD_INTERLACED; // prueba V4L2_FIELD_NONE si ves artefactos
    if (xioctl(vfd, VIDIOC_S_FMT, &fmt) < 0) die_perror("VIDIOC_S_FMT");
    printf("fmt: %ux%u, fourcc=%.4s, bytesperline=%u, sizeimage=%u\n",
           fmt.fmt.pix.width, fmt.fmt.pix.height,
           (char*)&fmt.fmt.pix.pixelformat,
           fmt.fmt.pix.bytesperline, fmt.fmt.pix.sizeimage);

    // --- VIDIOC_S_PARM ---
    struct v4l2_streamparm parm;
    memset(&parm, 0, sizeof(parm));
    parm.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    parm.parm.capture.capability   = 0x1;
    parm.parm.capture.capturemode  = 0x280;
    parm.parm.capture.timeperframe.numerator = 360;
    parm.parm.capture.timeperframe.denominator = 0; // según la traza
    parm.parm.capture.extendedmode = 0;
    parm.parm.capture.readbuffers  = 0;
    if (xioctl(vfd, VIDIOC_S_PARM, &parm) < 0) die_perror("VIDIOC_S_PARM");
    printf("S_PARM: cap=0x%x, mode=0x%x, tpf=%u/%u\n",
           parm.parm.capture.capability,
           parm.parm.capture.capturemode,
           parm.parm.capture.timeperframe.numerator,
           parm.parm.capture.timeperframe.denominator);

    /* BLOQUE 3: sensor fps y user params */
    printf("[set] sens_fps: 0x%x\n", sens_fps);
    Ak_ISP_Set_Sensor_Fps(&sens_fps);
    Ak_ISP_Get_Sensor_Fps(&sens_fps);
    printf("[get] sens_fps: 0x%x\n", sens_fps);

    blob_t user_params;
    if (load_blob("isp_user_params_pid519_fd10_req0x4004496d_20250930T130029.bin", &user_params) != 0) {
        perror("load_blob(user_params)");
        goto cleanup_fail_nr3d;
    }
    Ak_ISP_Set_User_Params(user_params.data);

    /* Audio: /dev/akpcm_cdev1 */
    int micfd = xopen("/dev/akpcm_cdev1", O_RDONLY);

    uint32_t dsp_0x10 = 0x00000002;
    if (xioctl(micfd, _IOC(_IOC_WRITE, 0x50, 0x10, 0x04), &dsp_0x10) < 0)
        die_perror("akpcm req 0x40045010 (nr=0x10)");

    uint32_t dsp_0x70 = 0x00000001;
    if (xioctl(micfd, _IOC(_IOC_WRITE, 0x50, 0x70, 0x04), &dsp_0x70) < 0)
        die_perror("akpcm req 0x40045070 (nr=0x70)");

    uint32_t dsp_0x30 = 0x00000007;
    if (xioctl(micfd, _IOC(_IOC_WRITE, 0x50, 0x30, 0x04), &dsp_0x30) < 0)
        die_perror("akpcm req 0x40045030 (nr=0x30)");

    if (xioctl(micfd, _IOC(0, 0x50, 0xe3, 0x00), &dsp_0x30) < 0)
        die_perror("akpcm req 0x000050e3 (nr=0xe3, size=0)");

    uint32_t dsp_0x88 = 0x00000001;
    if (xioctl(micfd, _IOC(_IOC_WRITE, 0x50, 0x88, 0x04), &dsp_0x88) < 0)
        die_perror("akpcm req 0x40045088 (nr=0x88)");

    /* V4L2: Req/Q/Stream/DQ/Q ciclo inicial (4 buffers) */
    struct v4l2_requestbuffers req;
    memset(&req, 0, sizeof(req));
    req.count  = 4;
    req.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req.memory = V4L2_MEMORY_USERPTR;
    if (xioctl(vfd, VIDIOC_REQBUFS, &req) < 0) { die_perror("VIDIOC_REQBUFS"); }
    if (req.count != 4) { fprintf(stderr, "Driver adjusted count to %u\n", req.count); die_perror("REQBUFS count"); }

    const size_t enqueue_len = 2306048;
    uintptr_t bptr = (uintptr_t) ion.map;
    uintptr_t bufs[4];
    for (int i = 0; i < 4; ++i) bufs[i] = bptr + i * enqueue_len;

    for (int i = 0; i < 4; ++i) {
        struct v4l2_buffer b; memset(&b, 0, sizeof(b));
        b.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        b.index  = i;
        b.memory = V4L2_MEMORY_USERPTR;
        b.m.userptr = (unsigned long)bufs[i];
        b.length = enqueue_len;
        b.bytesused = 0;
        if (xioctl(vfd, VIDIOC_QBUF, &b) < 0) { die_perror("VIDIOC_QBUF"); }
    }

    enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (xioctl(vfd, VIDIOC_STREAMON, &type) < 0) { die_perror("VIDIOC_STREAMON"); }

    const size_t frame_len = 1382400;
    for (int i = 0; i < 4; ++i) {
        struct v4l2_buffer b; memset(&b, 0, sizeof(b));
        b.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        b.memory = V4L2_MEMORY_USERPTR;
        if (xioctl(vfd, VIDIOC_DQBUF, &b) < 0) {
            if (errno == EAGAIN) { usleep(1000); --i; continue; }
            die_perror("VIDIOC_DQBUF");
        }
        double ts = b.timestamp.tv_sec + b.timestamp.tv_usec / 1e6;
        printf("DQBUF index=%u bytesused=%u length=%u ts=%.6f\n",
               b.index, b.bytesused, b.length, ts);

        struct v4l2_buffer q; memset(&q, 0, sizeof(q));
        q.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        q.index  = b.index;
        q.memory = V4L2_MEMORY_USERPTR;
        q.m.userptr = (unsigned long)bufs[b.index];
        q.length = frame_len;
        q.bytesused = frame_len;
        if (xioctl(vfd, VIDIOC_QBUF, &q) < 0) { die_perror("VIDIOC_QBUF(re)"); }
    }

    {
        int rc_exit = AK_ISP_sdk_exit();
        if (rc == 0 && rc_exit != 0) {
            rc = rc_exit;
            fprintf(stderr, "AK_ISP_sdk_exit() rc=%d\n", rc_exit);
        }
    }

    /* Limpieza ordenada */
    xclose(micfd);
    free_blob(&user_params);
    free_blob(&nr3d_ref_blob);

    xclose(vfd);
    xclose(uiofd);
    xclose(nullw);

    if (ion.map && ion.map != MAP_FAILED) munmap(ion.map, ion.len);
    xclose(ion.dmabuf_fd);

    return (rc == 0) ? 0 : 1;

cleanup_fail_nr3d:
    free_blob(&nr3d_ref_blob);
cleanup_fail:
    xclose(vfd);
    xclose(uiofd);
    xclose(nullw);
    if (ion.map && ion.map != MAP_FAILED) munmap(ion.map, ion.len);
    xclose(ion.dmabuf_fd);
    return 1;
}

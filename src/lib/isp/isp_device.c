#include "ak3918/isp.h"

#include "ak3918/sdk/akispsdk.h"
#include "ak3918/blob.h"
#include "ak3918/isp_blocks.h"
#include "ak3918/isp_conf.h"
#include "ak3918/util.h"

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MIN_CHUNK_SIZE 1U

static void warn_skip(uint16_t case_id, size_t offset, size_t need,
                      size_t payload_len)
{
    size_t have = (offset < payload_len) ? (payload_len - offset) : 0;
    fprintf(stderr,
            "[skip] pack0 id=0x%02x off=0x%zx need=%zu have=%zu\n",
            case_id, offset, need, have);
}

static int vendor_param_error(uint16_t case_id, size_t payload_len)
{
    fprintf(stderr,
            "\n[%s:%d] param err (id=0x%02x len=%zu)\n",
            "isp_set_attr", 0x60c, case_id, payload_len);
    return -1;
}

static int apply_vendor_case(int pack, const struct isp_block *block)
{
    if (!block) {
        return -EINVAL;
    }

    const uint16_t case_id = block->id;
    const uint8_t *payload = block->payload;
    const size_t payload_len = (size_t)block->payload_size;
    const uint8_t *header = block->header;
    const uint16_t block_size = block->size;

    const ak_isp_block_info_t *meta = ak_isp_get_block_info(case_id);
    if (meta && payload_len < meta->min_payload) {
        fprintf(stderr,
                "[isp_conf] warning: id=0x%02x payload=%zu smaller than known minimum %zu\n",
                case_id, payload_len, meta->min_payload);
    }

    if (header && block_size >= 4U) {
        uint16_t hdr_id = rd_le16(header);
        uint16_t hdr_sz = rd_le16(header + 2);
        printf("[isp_conf] pack=%d hdr id=0x%02x size=%u (block=%u payload=%zu)\n",
               pack, hdr_id, (unsigned)hdr_sz, (unsigned)block_size, payload_len);
    } else {
        printf("[isp_conf] pack=%d id=0x%02x block=%u payload=%zu (header missing)\n",
               pack, case_id, (unsigned)block_size, payload_len);
    }

    int rc = 0;

#define TRY(off, need_bytes, call_expr)                                             \
    do {                                                                            \
        size_t __off = (size_t)(off);                                               \
        size_t __need = (size_t)(need_bytes);                                       \
        if (__need == 0) {                                                          \
            __need = MIN_CHUNK_SIZE;                                                \
        }                                                                           \
        if (__off > payload_len || __need > (payload_len - __off)) {                \
            warn_skip(case_id, __off, __need, payload_len);                         \
        } else {                                                                    \
            call_expr;                                                              \
        }                                                                           \
    } while (0)

    switch (case_id) {
        case 0x0:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_blc_attr(payload + 0x0000));
            break;

        case 0x1:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_lsc_attr(payload + 0x0000));
            break;

        case 0x2:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_raw_lut_attr(payload + 0x0000));
            break;

        case 0x3:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_nr1_attr(payload + 0x0000));
            TRY(0x06f6, MIN_CHUNK_SIZE, ak_isp_set_nr2_attr(payload + 0x06f6));
            break;

        case 0x4:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_3d_nr_attr(payload + 0x0000));
            break;

        case 0x5:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_gb_attr(payload + 0x0000));
            break;

        case 0x6:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_demo_attr(payload + 0x0000));
            break;

        case 0x7:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_rgb_gamma_attr(payload + 0x0000));
            break;

        case 0x8:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_ccm_attr(payload + 0x0000));
            break;

        case 0x9:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_fcs_attr(payload + 0x0000));
            break;

        case 0x0a:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_wdr_attr(payload + 0x0000));
            break;

        case 0x0b:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_sharp_attr(payload + 0x0000));
            TRY(0x2b36, MIN_CHUNK_SIZE, ak_isp_set_sharp_ex_attr(payload + 0x2b36));
            break;

        case 0x0c:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_saturation_attr(payload + 0x0000));
            break;

        case 0x0d:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_contrast_attr(payload + 0x0000));
            break;

        case 0x0e:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_rgb2yuv_attr(payload + 0x0000));
            break;

        case 0x0f:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_effect_attr(payload + 0x0000));
            break;

        case 0x10:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_dpc_attr(payload + 0x0000));
            TRY(0x0054, MIN_CHUNK_SIZE, ak_isp_set_sdpc_attr(payload + 0x0054));
            break;

        case 0x11:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_weight_attr(payload + 0x0000));
            break;

        case 0x12:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_af_attr(payload + 0x0000));
            break;

        case 0x13:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_wb_type(payload + 0x0000));
            TRY(0x0002, MIN_CHUNK_SIZE, ak_isp_set_mwb_attr(payload + 0x0002));
            TRY(0x000e, MIN_CHUNK_SIZE, ak_isp_set_awb_attr(payload + 0x000e));
            TRY(0x00c8, MIN_CHUNK_SIZE, ak_isp_set_awb_ex_attr(payload + 0x00c8));
            break;

        case 0x14:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_raw_hist_attr(payload + 0x0000));
            TRY(0x0002, MIN_CHUNK_SIZE, ak_isp_set_rgb_hist_attr(payload + 0x0002));
            TRY(0x0004, MIN_CHUNK_SIZE, ak_isp_set_yuv_hist_attr(payload + 0x0004));
            TRY(0x0006, MIN_CHUNK_SIZE, ak_isp_set_exp_type(payload + 0x0006));
            TRY(0x0008, 4U, ak_isp_set_frame_rate(payload + 0x0008));
            TRY(0x0020, MIN_CHUNK_SIZE, ak_isp_set_ae_attr(payload + 0x0020));
            {
                uint32_t sensor_fps = 0x0000000fU;
                ak_isp_set_sensor_fps(&sensor_fps);
            }
            break;

        case 0x15:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_misc_attr(payload + 0x0000));
            break;

        case 0x16:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_y_gamma_attr(payload + 0x0000));
            break;

        case 0x17:
            TRY(0x0000, MIN_CHUNK_SIZE, ak_isp_set_hue_attr(payload + 0x0000));
            break;

        case 0x18: {
            TRY(0x0000, 16U, ak_isp_set_main_chan_mask_area(payload + 0x0000));
            TRY(0x0010, 16U, ak_isp_set_sub_chan_mask_area(payload + 0x0010));
            TRY(0x0020, 4U, ak_isp_set_mask_color(payload + 0x0020));

            const size_t cap_off = 0x0024U;
            const size_t need = sizeof(uint32_t);
            if (cap_off + need <= payload_len) {
                struct isp_capturing_param param = {
                    .enable = rd_le32(payload + cap_off),
                    .reserved = 0U,
                };

                const size_t reserved_off = cap_off + sizeof(uint32_t);
                if (reserved_off + sizeof(uint32_t) <= payload_len) {
                    param.reserved = rd_le32(payload + reserved_off);
                }

                /*
                 * El driver del ISP espera que el flag de captura se active a
                 * través de la misma secuencia que ejecuta el binario de
                 * fábrica. Forzar el ioctl desde aquí provoca que el kernel
                 * acabe invocando ak_isp_vo_set_main_channel_scale con un
                 * puntero nulo, provocando el Oops observado al ejecutar
                 * tools/video_dump (crash en ak_isp_vo_set_main_channel_scale).
                 *
                 * testing.c y el firmware original confían en que el pack ya
                 * deja la canalización en el estado adecuado, por lo que nos
                 * limitamos a registrar el valor sin propagarlo al ioctl.
                 */
                fprintf(stderr,
                        "[isp_conf] pack=%d id=0x%02x captura=%u (reservado=0x%08x)"
                        " -- omitido\n",
                        pack, case_id, param.enable, param.reserved);
            } else {
                warn_skip(case_id, cap_off, need, payload_len);
            }
            break;
        }

        case 0x1b:
        case 0x1c: {
            /*
             * Vendor firmware (FUN_00035de8 in decompiled ipc) reads the
             * 16-bit size field from the block header, shifts it by two, and
             * then advances the pointer past the header before calling
             * Ak_ISP_Sensor_Load_Conf(). The header size is included in the
             * count, hence the +4 adjustment when we work with payload-only
             * pointers.
             */
            uint32_t payload_words = (uint32_t)((payload_len + 4U) / 4U);
            struct blob_desc desc = {
                .nwords = payload_words,
                .ptr = (void *)payload,
            };
            if (payload && payload_len >= 4U) {
                uint16_t inner_id = rd_le16(payload);
                uint16_t inner_sz = rd_le16(payload + 2);
                printf("[isp_conf] pack=%d id=0x%02x inner_hdr=0x%02x size=%u\n",
                       pack, case_id, inner_id, (unsigned)inner_sz);
            }
            printf("[isp_conf] pack=%d id=0x%02x sensor_load_conf words=%u payload=%zu\n",
                   pack, case_id, desc.nwords, payload_len);
            ak_isp_sensor_load_conf(&desc);
        } break;

        default:
            rc = vendor_param_error(case_id, payload_len);
            break;
    }

#undef TRY

    return rc;
}

struct apply_conf_ctx {
    int desired_pack;
    bool pack_found;
};

static int on_section(int pack, const struct isp_block *block, void *user)
{
    struct apply_conf_ctx *ctx = user;
    if (ctx) {
        if (pack < ctx->desired_pack) {
            return 0;
        }
        if (pack > ctx->desired_pack) {
            return 1;
        }
    }

    if (!block) {
        return -EINVAL;
    }

    size_t payload_len = (size_t)block->payload_size;
    printf("[isp_conf] pack=%d id=0x%x len=%zu (block=%u)\n",
           pack, block->id, payload_len, (unsigned)block->size);

    if (ctx) {
        ctx->pack_found = true;
    }

    return apply_vendor_case(pack, block);
}

int isp_apply_conf_pack(const char *path, int pack)
{
    if (!path || pack < 0) {
        errno = EINVAL;
        return -1;
    }

    struct apply_conf_ctx ctx = {
        .desired_pack = pack,
        .pack_found = false,
    };

    int rc = parse_isp_conf_file(path, on_section, &ctx, NULL);
    if (rc == 0 && !ctx.pack_found) {
        errno = ENOENT;
        return -1;
    }
    return rc;
}

int isp_apply_conf(const char *path)
{
    return isp_apply_conf_pack(path, 0);
}

int isp_load_3dnr_ref(const char *path)
{
    blob_t blob;
    if (load_blob(path, &blob) != 0) {
        perror("load_blob(3dnr_ref)");
        return -1;
    }

    if (blob.data && blob.size) {
        fprintf(stderr,
                "[isp] TODO: ak_isp_set_3d_nr_ref_attr necesita reconstruir la estructura;"
                " blob '%s' (%zu bytes) se conserva pero no se reenvía al driver\n",
                path, blob.size);
    }

    free_blob(&blob);
    return 0;
}

int isp_load_user_params(const char *path)
{
    blob_t blob;
    if (load_blob(path, &blob) != 0) {
        perror("load_blob(user_params)");
        return -1;
    }

    if (blob.data && blob.size) {
        fprintf(stderr,
                "[isp] TODO: ak_isp_set_user_params exige el contenedor vendor;"
                " blob '%s' (%zu bytes) se omite por ahora\n",
                path, blob.size);
    }

    free_blob(&blob);
    return 0;
}

int isp_configure_runtime(void)
{
    uint32_t awb_attr = 0;
    ak_isp_get_awb_attr(&awb_attr);
    printf("[get] awb_attr: 0x%x\n", awb_attr);

    awb_attr = 0x0008000fU;
    ak_isp_set_awb_attr(&awb_attr);
    printf("[set] awb_attr: 0x%x\n", awb_attr);

    uint32_t frame_rate_raw = 0;
    ak_isp_get_frame_rate(&frame_rate_raw);
    const uint8_t *pf = (const uint8_t *)&frame_rate_raw;
    uint16_t fps = rd_le16(pf);
    uint16_t mode = rd_le16(pf + 2);
    printf("[get] frame_rate: fps=%u, mode=%u (raw=0x%08x)\n", fps, mode,
           frame_rate_raw);

    uint32_t sensor_fps = 0x0000000fU;
    ak_isp_set_sensor_fps(&sensor_fps);

    if (ak_isp_get_sensor_fps(&sensor_fps) == 0) {
        printf("[get] sens_fps: 0x%x\n", sensor_fps);
    }

    fprintf(stderr, "[isp] configure_runtime done\n");

    return 0;
}

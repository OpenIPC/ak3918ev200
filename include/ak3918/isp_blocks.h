#ifndef AK3918_ISP_BLOCKS_H
#define AK3918_ISP_BLOCKS_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ak_isp_subblock_info {
    uint32_t offset;       /* Offset within payload (bytes) */
    const char *function;  /* Name of the ak_isp_* call applied */
    size_t min_size;       /* Smallest payload bytes observed for the sub-block */
    size_t max_size;       /* Largest payload bytes observed (0 if unknown) */
} ak_isp_subblock_info_t;

typedef struct ak_isp_block_info {
    uint16_t id;
    const char *name;
    size_t min_payload;    /* Observed payload length (bytes) */
    size_t max_payload;
    const ak_isp_subblock_info_t *subs;
    size_t sub_count;
    int is_sensor_script;  /* Non-zero if block is 0x1B/0x1C (sensor load) */
} ak_isp_block_info_t;

const ak_isp_block_info_t *ak_isp_get_block_info(uint16_t id);
const ak_isp_block_info_t *ak_isp_block_info_first(void);
const ak_isp_block_info_t *ak_isp_block_info_next(const ak_isp_block_info_t *info);

#ifdef __cplusplus
}
#endif

#endif /* AK3918_ISP_BLOCKS_H */

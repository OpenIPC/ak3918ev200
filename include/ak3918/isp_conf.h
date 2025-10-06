#ifndef ISP_CONF_H
#define ISP_CONF_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct isp_block {
    uint16_t id;            /* Identificador del bloque */
    uint16_t size;          /* Tamaño total (incluye cabecera) */
    uint16_t payload_size;  /* Tamaño del payload (size-4 si size>=4) */
    const uint8_t *header;  /* Puntero al inicio del bloque (id|size|payload) */
    const uint8_t *payload; /* Puntero al payload (header+4) */
};

typedef int (*isp_block_cb)(int pack, const struct isp_block *block,
                            void *user);

struct parse_isp_conf_stats {
    int packs;
    int blocks;
};

int parse_isp_conf(const uint8_t *buf, size_t len,
                   isp_block_cb cb, void *user,
                   struct parse_isp_conf_stats *out);

int parse_isp_conf_file(const char *path,
                        isp_block_cb cb, void *user,
                        struct parse_isp_conf_stats *out);

#ifdef __cplusplus
}
#endif

#endif /* ISP_CONF_H */

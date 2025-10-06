#ifndef AK3918_SPIFLASH_H
#define AK3918_SPIFLASH_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct ak_spiflash_info {
    uint32_t size_bytes;
    uint32_t erase_block_bytes;
    uint32_t write_block_bytes;
    uint32_t oob_bytes;
    uint32_t region_count;
};

struct ak_spiflash_region {
    uint32_t offset_bytes;
    uint32_t length_bytes;
    uint32_t number;
};

struct ak_spiflash {
    int fd;
    char path[128];
    struct ak_spiflash_info info;
};

int ak_spiflash_open(struct ak_spiflash *flash, const char *device_path);
void ak_spiflash_close(struct ak_spiflash *flash);
const struct ak_spiflash_info *ak_spiflash_info(const struct ak_spiflash *flash);
int ak_spiflash_read(struct ak_spiflash *flash,
                     uint32_t offset,
                     void *buffer,
                     size_t length);
int ak_spiflash_dump(struct ak_spiflash *flash,
                     uint32_t offset,
                     size_t length,
                     const char *hex_prefix);

#ifdef __cplusplus
}
#endif

#endif /* AK3918_SPIFLASH_H */

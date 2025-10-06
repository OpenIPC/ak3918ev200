#include "ak3918/spiflash.h"

#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void usage(const char *argv0)
{
    fprintf(stderr,
            "Usage: %s <mtd-device> [--dump bytes] [--offset offset]\n",
            argv0);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *device = argv[1];
    size_t dump_len = 0;
    uint32_t offset = 0;

    for (int i = 2; i < argc; ++i) {
        if (strcmp(argv[i], "--dump") == 0 && i + 1 < argc) {
            dump_len = strtoul(argv[++i], NULL, 0);
        } else if (strcmp(argv[i], "--offset") == 0 && i + 1 < argc) {
            offset = strtoul(argv[++i], NULL, 0);
        } else {
            fprintf(stderr, "Unknown option '%s'\n", argv[i]);
            usage(argv[0]);
            return EXIT_FAILURE;
        }
    }

    struct ak_spiflash flash;
    if (ak_spiflash_open(&flash, device) < 0) {
        return EXIT_FAILURE;
    }

    const struct ak_spiflash_info *info = ak_spiflash_info(&flash);
    if (!info) {
        ak_spiflash_close(&flash);
        return EXIT_FAILURE;
    }

    printf("Device: %s\n", device);
    printf("  Size       : %u bytes (%0.2f MiB)\n",
           info->size_bytes, info->size_bytes / (1024.0 * 1024.0));
    printf("  Erase blk  : %u bytes\n", info->erase_block_bytes);
    printf("  Write blk  : %u bytes\n", info->write_block_bytes);
    printf("  OOB bytes  : %u\n", info->oob_bytes);
    printf("  Regions    : %u\n", info->region_count);

    if (dump_len > 0) {
        printf("\nHex dump offset=0x%08x len=%zu\n", offset, dump_len);
        if (ak_spiflash_dump(&flash, offset, dump_len, "    ") < 0) {
            fprintf(stderr, "Dump failed (%s)\n", strerror(errno));
            ak_spiflash_close(&flash);
            return EXIT_FAILURE;
        }
    }

    ak_spiflash_close(&flash);
    return EXIT_SUCCESS;
}


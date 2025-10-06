#include "ak3918/spiflash.h"

#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#if defined(__has_include)
#  if __has_include(<mtd/mtd-user.h>)
#    include <mtd/mtd-user.h>
#  else
#    include <linux/mtd/mtd-abi.h>
#  endif
#else
#  include <mtd/mtd-user.h>
#endif

static int ensure_open(const struct ak_spiflash *flash)
{
    if (!flash || flash->fd < 0) {
        errno = EBADF;
        return -1;
    }
    return 0;
}

int ak_spiflash_open(struct ak_spiflash *flash, const char *device_path)
{
    if (!flash || !device_path) {
        errno = EINVAL;
        return -1;
    }

    memset(flash, 0, sizeof(*flash));
    flash->fd = -1;

    int fd = open(device_path, O_RDONLY | O_CLOEXEC);
    if (fd < 0) {
        fprintf(stderr, "[ak-spiflash] open(%s) failed: %s\n",
                device_path, strerror(errno));
        return -1;
    }

    struct mtd_info_user info = {0};
    if (ioctl(fd, MEMGETINFO, &info) < 0) {
        fprintf(stderr, "[ak-spiflash] MEMGETINFO failed: %s\n",
                strerror(errno));
        close(fd);
        return -1;
    }

    flash->fd = fd;
    strncpy(flash->path, device_path, sizeof(flash->path) - 1);
    flash->path[sizeof(flash->path) - 1] = '\0';

    flash->info.size_bytes = info.size;
    flash->info.erase_block_bytes = info.erasesize;
    flash->info.write_block_bytes = info.writesize;
    flash->info.oob_bytes = info.oobsize;
    flash->info.region_count = 0;

    return 0;
}

void ak_spiflash_close(struct ak_spiflash *flash)
{
    if (!flash) {
        return;
    }

    if (flash->fd >= 0) {
        int fd = flash->fd;
        flash->fd = -1;
        while (close(fd) < 0) {
            if (errno == EINTR) {
                continue;
            }
            fprintf(stderr, "[ak-spiflash] close failed: %s\n", strerror(errno));
            break;
        }
    }
}

const struct ak_spiflash_info *ak_spiflash_info(const struct ak_spiflash *flash)
{
    if (!flash || flash->fd < 0) {
        return NULL;
    }
    return &flash->info;
}

int ak_spiflash_read(struct ak_spiflash *flash,
                     uint32_t offset,
                     void *buffer,
                     size_t length)
{
    if (ensure_open(flash) != 0 || !buffer) {
        errno = EINVAL;
        return -1;
    }

    if ((uint64_t)offset + length > flash->info.size_bytes) {
        errno = EINVAL;
        fprintf(stderr, "[ak-spiflash] read out of range (0x%x + %zu > %u)\n",
                offset, length, flash->info.size_bytes);
        return -1;
    }

    size_t total = 0;
    unsigned char *dst = buffer;
    while (total < length) {
        ssize_t rc = pread(flash->fd, dst + total, length - total, offset + total);
        if (rc < 0) {
            if (errno == EINTR) {
                continue;
            }
            fprintf(stderr, "[ak-spiflash] pread failed at 0x%x: %s\n",
                    offset + (uint32_t)total, strerror(errno));
            return -1;
        }
        if (rc == 0) {
            fprintf(stderr, "[ak-spiflash] unexpected EOF at 0x%x\n",
                    offset + (uint32_t)total);
            errno = EIO;
            return -1;
        }
        total += (size_t)rc;
    }
    return 0;
}

int ak_spiflash_dump(struct ak_spiflash *flash,
                     uint32_t offset,
                     size_t length,
                     const char *hex_prefix)
{
    if (ensure_open(flash) != 0) {
        return -1;
    }

    const size_t stride = 16;
    unsigned char *buf = malloc(stride);
    if (!buf) {
        return -1;
    }

    size_t remaining = length;
    uint32_t cursor = offset;
    while (remaining > 0) {
        size_t chunk = remaining < stride ? remaining : stride;
        if (ak_spiflash_read(flash, cursor, buf, chunk) < 0) {
            free(buf);
            return -1;
        }

        if (hex_prefix) {
            fputs(hex_prefix, stdout);
        }
        printf("0x%08x:", cursor);
        for (size_t i = 0; i < chunk; ++i) {
            printf(" %02x", buf[i]);
        }
        putchar('\n');

        cursor += chunk;
        remaining -= chunk;
    }

    free(buf);
    return 0;
}

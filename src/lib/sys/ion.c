#include "ak3918/ion.h"
#include "ak3918/util.h"

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

#ifndef O_CLOEXEC
#define O_CLOEXEC 0
#endif

static void ion_region_detect_phys_base(struct ion_region *region) {
    if (!region) {
        return;
    }

    region->phys_base = 0;
    region->phys_base_valid = 0;

    const char *env = getenv("ION_PHYS_BASE");
    if (env && *env) {
        region->phys_base = (uint32_t)strtoul(env, NULL, 0);
        region->phys_base_valid = 1;
        fprintf(stderr, "[ion] usando ION_PHYS_BASE=0x%08x\n", region->phys_base);
        return;
    }

    if (!region->map || region->map == MAP_FAILED) {
        return;
    }

    long page_size = sysconf(_SC_PAGESIZE);
    if (page_size <= 0) {
        page_size = 4096;
    }

    int pagemap_fd = open("/proc/self/pagemap", O_RDONLY | O_CLOEXEC);
    if (pagemap_fd < 0) {
        return;
    }

    uint64_t entry = 0;
    off_t index = (off_t)((uintptr_t)region->map / (uintptr_t)page_size) * (off_t)sizeof(entry);
    ssize_t rd = pread(pagemap_fd, &entry, sizeof(entry), index);
    close(pagemap_fd);
    if (rd != (ssize_t)sizeof(entry)) {
        return;
    }

    if (!(entry & (1ULL << 63))) {
        return;
    }

    uint64_t phys = (entry & ((1ULL << 55) - 1ULL)) * (uint64_t)page_size;
    region->phys_base = (uint32_t)phys;
    region->phys_base_valid = 1;
    fprintf(stderr, "[ion] detectada base física=0x%08x\n", region->phys_base);
}

struct ion_region ion_reserve_and_map(void) {
    struct ion_region region = {
        .dmabuf_fd = -1,
        .map = MAP_FAILED,
        .len = 0,
        .phys_base = 0,
        .phys_base_valid = 0,
    };

    int ionfd = xopen("/dev/ion", O_RDWR);

    struct ion_allocation_data_compat alloc;
    memset(&alloc, 0, sizeof(alloc));
    alloc.len          = 0x01800000U; /* 25,165,824 bytes (24 MiB) */
    alloc.align        = 0x00001000U; /* 4 KiB */
    alloc.heap_id_mask = 0x000000ffU;
    alloc.flags        = 0x00000003U;

    if (xioctl(ionfd, ION_IOC_ALLOC, &alloc) < 0) {
        int saved = errno;
        xclose(ionfd);
        errno = saved;
        die_perror("ION_IOC_ALLOC");
    }

    struct ion_fd_data_compat map_req;
    memset(&map_req, 0, sizeof(map_req));
    map_req.handle = alloc.handle;

    if (xioctl(ionfd, ION_IOC_MAP, &map_req) < 0) {
        int saved = errno;
        xclose(ionfd);
        errno = saved;
        die_perror("ION_IOC_MAP");
    }

    region.len = alloc.len;
    region.dmabuf_fd = map_req.fd;
    region.map = mmap(NULL, region.len, PROT_READ | PROT_WRITE,
                      MAP_SHARED, region.dmabuf_fd, 0);
    if (region.map == MAP_FAILED) {
        int saved = errno;
        xclose(region.dmabuf_fd);
        xclose(ionfd);
        errno = saved;
        die_perror("mmap(dmabuf)");
    }

    ion_region_detect_phys_base(&region);

    xclose(ionfd);
    return region;
}

void ion_region_release(struct ion_region *region) {
    if (!region) {
        return;
    }

    if (region->map && region->map != MAP_FAILED) {
        munmap(region->map, region->len);
        region->map = MAP_FAILED;
    }

    if (region->dmabuf_fd >= 0) {
        xclose(region->dmabuf_fd);
        region->dmabuf_fd = -1;
    }

    region->len = 0;
    region->phys_base = 0;
    region->phys_base_valid = 0;
}

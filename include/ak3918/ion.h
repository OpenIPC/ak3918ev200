#ifndef ION_H
#define ION_H

#include <stddef.h>
#include <stdint.h>

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
    uint32_t phys_base;
    int      phys_base_valid;
};

struct ion_region ion_reserve_and_map(void);
void ion_region_release(struct ion_region *region);

#endif /* ION_H */

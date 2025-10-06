#ifndef ISP_H
#define ISP_H

#include <stdint.h>

struct isp_3dnr_ref_desc {
    uint32_t base;    // p.ej. puntero base a la tabla/ref en la .conf
    uint32_t ptr_a;   // base + 2*index
    uint32_t ptr_b;   // ptr_a + 2*((index+3)>>2)
    uint32_t pitch;   // 2*index
    uint32_t height;  // 2*((index+3)>>2)
};

/*
 * Algunos ioctl del ISP (como set_isp_capturing) esperan una estructura de
 * 8 bytes en la que sólo el primer campo habilita/deshabilita la captura y el
 * segundo debe permanecer a cero. Pasar únicamente un uint32_t en la pila
 * provocaba que el kernel leyese basura en el segundo campo y lo interpretase
 * como puntero, llevando a "Oops". Usa siempre esta estructura cuando se
 * actúe manualmente sobre el flag de captura.
 */
struct isp_capturing_param {
    uint32_t enable;
    uint32_t reserved;
};

int isp_apply_conf(const char *path);
int isp_apply_conf_pack(const char *path, int pack);
int isp_load_3dnr_ref(const char *path);
int isp_load_user_params(const char *path);
int isp_configure_runtime(void);

#endif /* ISP_H */

#ifndef AK3918_VIDEO_H
#define AK3918_VIDEO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _IO
# include <linux/ioctl.h>
#endif

#define AK_UIO_WAIT_IRQ_LEGACY 0x80045565UL

struct ak_uio_sysreg_write {
    uint32_t phys;
    uint32_t value;
    uint32_t mask;
};

#define AK_UIO_SYSREG_WRITE _IOW('U', 100, struct ak_uio_sysreg_write)
#define AK_UIO_WAIT_IRQ_DRIVER _IOR('U', 101, int)
#define AK_UIO_INVALIDATE_L2CACHE _IOR('U', 102, int)
#define AK_UIO_INVALIDATE_L1CACHE _IOR('U', 103, int)

#ifndef UIO_WAIT_IRQ
# define UIO_WAIT_IRQ _IOR('U', 0x65, uint32_t)
#endif

struct ak_uio_triple {
    uint32_t reg;
    uint32_t off;
    uint32_t size;
};

#ifndef UIO_SET_TRIPLE
# define UIO_SET_TRIPLE _IOW('U', 0x64, struct ak_uio_triple)
#endif

enum ak_uio_irq_mode {
    AK_UIO_IRQ_MODE_AK = 0,
    AK_UIO_IRQ_MODE_DRIVER,
    AK_UIO_IRQ_MODE_STD,
    AK_UIO_IRQ_MODE_READ,
};

typedef int (*ak_uio_should_stop_fn)(void);

int ak_uio_wait_irq(int fd,
                    enum ak_uio_irq_mode *mode,
                    uint32_t *irqcnt,
                    ak_uio_should_stop_fn should_stop);

int ak_uio_set_triple(int fd, const struct ak_uio_triple *triple);

int ak_uio_ack_read_mode(int fd);

int ak_uio_sysreg_write(int fd, const struct ak_uio_sysreg_write *write);

int ak_uio_invalidate_l2cache(int fd);

int ak_uio_invalidate_l1cache(int fd);

#ifdef __cplusplus
}
#endif

#endif /* AK3918_VIDEO_H */

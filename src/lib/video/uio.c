#include "ak3918/video.h"

/* Secuencia de fallback derivada del binario ipc decompilado */

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

int ak_uio_set_triple(int fd, const struct ak_uio_triple *triple)
{
    if (fd < 0 || !triple) {
        errno = EINVAL;
        return -1;
    }
    if (ioctl(fd, UIO_SET_TRIPLE, triple) < 0) {
        fprintf(stderr, "[ak-uio] ioctl(UIO_SET_TRIPLE) falló: %s\n",
                strerror(errno));
        return -1;
    }
    return 0;
}

int ak_uio_ack_read_mode(int fd)
{
    if (fd < 0) {
        errno = EINVAL;
        return -1;
    }
    uint32_t ack = 1U;
    ssize_t written = write(fd, &ack, sizeof(ack));
    if (written < 0) {
        if (errno == EINTR || errno == EAGAIN) {
            return 0;
        }
        if (errno == ENOSYS || errno == EOPNOTSUPP || errno == EINVAL) {
            /* Algunos controladores UIO no implementan write() para ack */
            return 0;
        }
        fprintf(stderr, "[ak-uio] write(/dev/uio) falló: %s\n", strerror(errno));
        return -1;
    }
    return 0;
}

int ak_uio_wait_irq(int fd,
                    enum ak_uio_irq_mode *mode,
                    uint32_t *irqcnt,
                    ak_uio_should_stop_fn should_stop)
{
    if (fd < 0 || !mode) {
        errno = EINVAL;
        return -1;
    }

    uint32_t tmp = 0;
    uint32_t *counter = irqcnt ? irqcnt : &tmp;

    for (;;) {
        if (should_stop && should_stop()) {
            errno = EINTR;
            return 0;
        }

        switch (*mode) {
        case AK_UIO_IRQ_MODE_AK: {
            int rc = ioctl(fd, AK_UIO_WAIT_IRQ_LEGACY, counter);
            if (rc == 0) {
                return 1;
            }
            if (errno == EINTR) {
                continue;
            }
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                return 0;
            }
            if (errno == ENOTTY || errno == ENOSYS || errno == EOPNOTSUPP || errno == EINVAL) {
                fprintf(stderr, "[ak-uio] ioctl(0x80045565) no soportado, pruebo ioctl('U',101)\n");
                *mode = AK_UIO_IRQ_MODE_DRIVER;
                continue;
            }
            fprintf(stderr, "[ak-uio] ioctl(0x80045565) falló: %s\n", strerror(errno));
            return -1;
        }

        case AK_UIO_IRQ_MODE_DRIVER: {
            int rc = ioctl(fd, AK_UIO_WAIT_IRQ_DRIVER, counter);
            if (rc == 0) {
                return 1;
            }
            if (errno == EINTR) {
                continue;
            }
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                return 0;
            }
            if (errno == ENOTTY || errno == ENOSYS || errno == EOPNOTSUPP || errno == EINVAL) {
                fprintf(stderr, "[ak-uio] ioctl('U',101) no soportado, paso a UIO_WAIT_IRQ\n");
                *mode = AK_UIO_IRQ_MODE_STD;
                continue;
            }
            fprintf(stderr, "[ak-uio] ioctl('U',101) falló: %s\n", strerror(errno));
            return -1;
        }

        case AK_UIO_IRQ_MODE_STD: {
            int rc = ioctl(fd, UIO_WAIT_IRQ, counter);
            if (rc == 0) {
                return 1;
            }
            if (errno == EINTR) {
                continue;
            }
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                return 0;
            }
            if (errno == ENOTTY || errno == ENOSYS || errno == EOPNOTSUPP) {
                fprintf(stderr, "[ak-uio] ioctl(UIO_WAIT_IRQ) no soportado, pruebo read()/write()\n");
                *mode = AK_UIO_IRQ_MODE_READ;
                continue;
            }
            fprintf(stderr, "[ak-uio] ioctl(UIO_WAIT_IRQ) falló: %s\n", strerror(errno));
            return -1;
        }

        case AK_UIO_IRQ_MODE_READ: {
            ssize_t r = read(fd, counter, sizeof(*counter));
            if (r == (ssize_t)sizeof(*counter)) {
                uint32_t enable = *counter ? *counter : 1U;
                ssize_t w = write(fd, &enable, sizeof(enable));
                if (w < 0 && errno != EINTR && errno != EAGAIN) {
                    fprintf(stderr, "[ak-uio] write(/dev/uio) falló: %s\n", strerror(errno));
                }
                return 1;
            }
            if (r == 0) {
                errno = EAGAIN;
                return 0;
            }
            if (r < 0) {
                if (errno == EINTR) {
                    continue;
                }
                if (errno == EAGAIN || errno == EWOULDBLOCK) {
                    return 0;
                }
                if (errno == EINVAL || errno == ENOTTY || errno == ENOSYS) {
                    fprintf(stderr, "[ak-uio] read(/dev/uio) no soportado incluso tras fallback\n");
                    errno = EIO;
                    return -1;
                }
                fprintf(stderr, "[ak-uio] read(/dev/uio) falló: %s\n", strerror(errno));
                return -1;
            }
            fprintf(stderr, "[ak-uio] lectura corta de /dev/uio (%zd bytes)\n", r);
            return 0;
        }
        }
    }
}

int ak_uio_sysreg_write(int fd, const struct ak_uio_sysreg_write *write)
{
    if (fd < 0 || !write) {
        errno = EINVAL;
        return -1;
    }

    if (ioctl(fd, AK_UIO_SYSREG_WRITE, write) < 0) {
        fprintf(stderr, "[ak-uio] ioctl(AK_UIO_SYSREG_WRITE) falló: %s\n",
                strerror(errno));
        return -1;
    }
    return 0;
}

static int ak_uio_invalidate_cache_common(int fd, unsigned long req, const char *name)
{
    if (fd < 0) {
        errno = EINVAL;
        return -1;
    }

    int dummy = 0;
    if (ioctl(fd, req, &dummy) < 0) {
        fprintf(stderr, "[ak-uio] ioctl(%s) falló: %s\n", name, strerror(errno));
        return -1;
    }
    return 0;
}

int ak_uio_invalidate_l2cache(int fd)
{
    return ak_uio_invalidate_cache_common(fd, AK_UIO_INVALIDATE_L2CACHE,
                                          "AK_UIO_INVALIDATE_L2CACHE");
}

int ak_uio_invalidate_l1cache(int fd)
{
    return ak_uio_invalidate_cache_common(fd, AK_UIO_INVALIDATE_L1CACHE,
                                          "AK_UIO_INVALIDATE_L1CACHE");
}

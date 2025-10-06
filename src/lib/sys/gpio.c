#include "ak3918/gpio.h"

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int ensure_fd(struct ak_gpio *gpio)
{
    if (!gpio || gpio->fd < 0) {
        errno = EBADF;
        return -1;
    }
    return 0;
}

int ak_gpio_open(struct ak_gpio *gpio, const char *device_path)
{
    if (!gpio || !device_path) {
        errno = EINVAL;
        return -1;
    }

    int fd = open(device_path, O_RDWR | O_CLOEXEC);
    if (fd < 0) {
        fprintf(stderr, "[ak-gpio] no se pudo abrir %s: %s\n",
                device_path, strerror(errno));
        return -1;
    }

    gpio->fd = fd;
    return 0;
}

void ak_gpio_close(struct ak_gpio *gpio)
{
    if (!gpio || gpio->fd < 0) {
        return;
    }
    int fd = gpio->fd;
    gpio->fd = -1;
    while (close(fd) < 0) {
        if (errno == EINTR) {
            continue;
        }
        fprintf(stderr, "[ak-gpio] close falló: %s\n", strerror(errno));
        break;
    }
}

int ak_gpio_get_num(struct ak_gpio *gpio, unsigned int *count)
{
    if (ensure_fd(gpio) != 0 || !count) {
        errno = EINVAL;
        return -1;
    }

    unsigned int tmp = 0;
    if (ioctl(gpio->fd, AK_GPIO_GET_NUM, &tmp) < 0) {
        fprintf(stderr, "[ak-gpio] ioctl(GET_NUM) falló: %s\n", strerror(errno));
        return -1;
    }
    *count = tmp;
    return 0;
}

int ak_gpio_get_available(struct ak_gpio *gpio, unsigned int *pins, size_t max_pins)
{
    if (ensure_fd(gpio) != 0 || !pins || max_pins == 0) {
        errno = EINVAL;
        return -1;
    }

    /* Kernel copies ngpio * sizeof(unsigned int) regardless of max. */
    if (ioctl(gpio->fd, AK_GPIO_GET_AVAILABLE, pins) < 0) {
        fprintf(stderr, "[ak-gpio] ioctl(GET_AVAILABLE) falló: %s\n",
                strerror(errno));
        return -1;
    }
    (void)max_pins;
    return 0;
}

int ak_gpio_configure(struct ak_gpio *gpio, const struct ak_gpio_info *info)
{
    if (ensure_fd(gpio) != 0 || !info) {
        errno = EINVAL;
        return -1;
    }

    if (ioctl(gpio->fd, AK_GPIO_SET_FUNC, info) < 0) {
        fprintf(stderr, "[ak-gpio] ioctl(SET_FUNC) pin %d falló: %s\n",
                info->pin, strerror(errno));
        return -1;
    }
    return 0;
}

int ak_gpio_set_level(struct ak_gpio *gpio, int pin, enum ak_gpio_level level)
{
    struct ak_gpio_info info = {
        .pin = pin,
        .value = level,
    };

    if (ensure_fd(gpio) != 0) {
        errno = EINVAL;
        return -1;
    }

    if (ioctl(gpio->fd, AK_GPIO_SET_LEVEL, &info) < 0) {
        fprintf(stderr, "[ak-gpio] ioctl(SET_LEVEL) pin %d falló: %s\n",
                pin, strerror(errno));
        return -1;
    }
    return 0;
}

int ak_gpio_get_level(struct ak_gpio *gpio, struct ak_gpio_info *info)
{
    if (ensure_fd(gpio) != 0 || !info) {
        errno = EINVAL;
        return -1;
    }

    if (ioctl(gpio->fd, AK_GPIO_GET_LEVEL, info) < 0) {
        fprintf(stderr, "[ak-gpio] ioctl(GET_LEVEL) pin %d falló: %s\n",
                info->pin, strerror(errno));
        return -1;
    }
    return 0;
}

int ak_gpio_request_irq(struct ak_gpio *gpio, const struct ak_gpio_info *info)
{
    if (ensure_fd(gpio) != 0 || !info) {
        errno = EINVAL;
        return -1;
    }

    if (ioctl(gpio->fd, AK_GPIO_SET_IRQ, info) < 0) {
        fprintf(stderr, "[ak-gpio] ioctl(SET_IRQ) pin %d falló: %s\n",
                info->pin, strerror(errno));
        return -1;
    }
    return 0;
}

int ak_gpio_wait_irq(struct ak_gpio *gpio, unsigned int pin)
{
    if (ensure_fd(gpio) != 0) {
        errno = EINVAL;
        return -1;
    }

    if (ioctl(gpio->fd, AK_GPIO_LISTEN_IRQ, pin) < 0) {
        fprintf(stderr, "[ak-gpio] ioctl(LISTEN_IRQ) pin %u falló: %s\n",
                pin, strerror(errno));
        return -1;
    }
    return 0;
}

int ak_gpio_delete_irq(struct ak_gpio *gpio, unsigned int pin)
{
    if (ensure_fd(gpio) != 0) {
        errno = EINVAL;
        return -1;
    }

    if (ioctl(gpio->fd, AK_GPIO_DELETE_IRQ, pin) < 0) {
        fprintf(stderr, "[ak-gpio] ioctl(DELETE_IRQ) pin %u falló: %s\n",
                pin, strerror(errno));
        return -1;
    }
    return 0;
}

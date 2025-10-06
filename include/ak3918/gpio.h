#ifndef AK3918_GPIO_H
#define AK3918_GPIO_H

#include <stddef.h>
#include <stdint.h>
#include <sys/ioctl.h>

#ifdef __cplusplus
extern "C" {
#endif

#define AK_GPIO_IOC_MAGIC          'f'

#define AK_GPIO_GET_NUM            _IOR(AK_GPIO_IOC_MAGIC, 40, unsigned int)
#define AK_GPIO_GET_AVAILABLE      _IOR(AK_GPIO_IOC_MAGIC, 41, unsigned int)
#define AK_GPIO_SET_FUNC           _IOW(AK_GPIO_IOC_MAGIC, 42, struct ak_gpio_info)
#define AK_GPIO_GET_LEVEL          _IOWR(AK_GPIO_IOC_MAGIC, 43, struct ak_gpio_info)
#define AK_GPIO_SET_IRQ            _IOW(AK_GPIO_IOC_MAGIC, 44, struct ak_gpio_info)
#define AK_GPIO_LISTEN_IRQ         _IOW(AK_GPIO_IOC_MAGIC, 45, unsigned int)
#define AK_GPIO_DELETE_IRQ         _IOW(AK_GPIO_IOC_MAGIC, 46, unsigned int)
#define AK_GPIO_SET_LEVEL          _IOW(AK_GPIO_IOC_MAGIC, 47, struct ak_gpio_info)

enum ak_gpio_dir {
    AK_GPIO_DIR_INPUT  = 0,
    AK_GPIO_DIR_OUTPUT = 1,
};

enum ak_gpio_pull {
    AK_GPIO_PULL_DISABLE = 0,
    AK_GPIO_PULL_ENABLE  = 1,
};

enum ak_gpio_level {
    AK_GPIO_LEVEL_LOW  = 0,
    AK_GPIO_LEVEL_HIGH = 1,
};

enum ak_gpio_irq_polarity {
    AK_GPIO_IRQ_LOW  = 0,
    AK_GPIO_IRQ_HIGH = 1,
};

struct ak_gpio_info {
    int pin;                   /* Absolute GPIO number */
    int pulldown;              /* enum ak_gpio_pull */
    int pullup;                /* enum ak_gpio_pull */
    int value;                 /* enum ak_gpio_level */
    int dir;                   /* enum ak_gpio_dir */
    int int_pol;               /* enum ak_gpio_irq_polarity */
};

struct ak_gpio {
    int fd;
};

int ak_gpio_open(struct ak_gpio *gpio, const char *device_path);
void ak_gpio_close(struct ak_gpio *gpio);

int ak_gpio_get_num(struct ak_gpio *gpio, unsigned int *count);
int ak_gpio_get_available(struct ak_gpio *gpio, unsigned int *pins, size_t max_pins);

int ak_gpio_configure(struct ak_gpio *gpio, const struct ak_gpio_info *info);
int ak_gpio_set_level(struct ak_gpio *gpio, int pin, enum ak_gpio_level level);
int ak_gpio_get_level(struct ak_gpio *gpio, struct ak_gpio_info *info);

int ak_gpio_request_irq(struct ak_gpio *gpio, const struct ak_gpio_info *info);
int ak_gpio_wait_irq(struct ak_gpio *gpio, unsigned int pin);
int ak_gpio_delete_irq(struct ak_gpio *gpio, unsigned int pin);

#ifdef __cplusplus
}
#endif

#endif /* AK3918_GPIO_H */

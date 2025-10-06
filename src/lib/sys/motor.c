#include "ak3918/motor.h"

#include <errno.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct ak_motor {
    int fd;
    int index;
    char path[32];
};

struct notify_data_kernel {
    int hit_num;
    int event;
    int remain_angle;
};

static int ensure_fd(const struct ak_motor *motor)
{
    if (!motor || motor->fd < 0) {
        errno = EBADF;
        return -1;
    }
    return 0;
}

static int open_path(struct ak_motor *motor, const char *path)
{
    int fd = open(path, O_RDWR | O_CLOEXEC);
    if (fd < 0) {
        return -1;
    }
    strncpy(motor->path, path, sizeof(motor->path) - 1);
    motor->path[sizeof(motor->path) - 1] = '\0';
    motor->fd = fd;
    return 0;
}

struct ak_motor *ak_motor_open(int index)
{
    if (index < 0) {
        errno = EINVAL;
        return NULL;
    }

    struct ak_motor *motor = calloc(1, sizeof(*motor));
    if (!motor) {
        return NULL;
    }

    motor->fd = -1;
    motor->index = index;

    char path[32];
    snprintf(path, sizeof(path), "/dev/ak-motor%d", index);
    if (open_path(motor, path) == 0) {
        return motor;
    }

    /* fallback to legacy name without hyphen */
    snprintf(path, sizeof(path), "/dev/akmotor%d", index);
    if (open_path(motor, path) == 0) {
        return motor;
    }

    fprintf(stderr, "[ak-motor] unable to open motor %d: %s\n",
            index, strerror(errno));
    free(motor);
    return NULL;
}

void ak_motor_close(struct ak_motor *motor)
{
    if (!motor) {
        return;
    }

    if (motor->fd >= 0) {
        int fd = motor->fd;
        motor->fd = -1;
        while (close(fd) < 0) {
            if (errno == EINTR) {
                continue;
            }
            fprintf(stderr, "[ak-motor] close failed: %s\n", strerror(errno));
            break;
        }
    }
    free(motor);
}

const char *ak_motor_path(const struct ak_motor *motor)
{
    if (!motor) {
        return NULL;
    }
    return motor->path;
}

int ak_motor_fd(const struct ak_motor *motor)
{
    if (!motor) {
        errno = EBADF;
        return -1;
    }
    return motor->fd;
}

static int clamp_speed(int speed)
{
    if (speed < AK_MOTOR_MIN_SPEED) {
        return AK_MOTOR_MIN_SPEED;
    }
    if (speed > AK_MOTOR_MAX_SPEED) {
        return AK_MOTOR_MAX_SPEED;
    }
    return speed;
}

int ak_motor_set_speed(struct ak_motor *motor, int degrees_per_sec)
{
    if (ensure_fd(motor) != 0) {
        return -1;
    }

    int val = clamp_speed(degrees_per_sec);
    if (ioctl(motor->fd, AK_MOTOR_SET_ANG_SPEED, &val) < 0) {
        fprintf(stderr, "[ak-motor] SET_ANG_SPEED failed (%s)\n", strerror(errno));
        return -1;
    }
    return 0;
}

int ak_motor_get_speed(struct ak_motor *motor, int *degrees_per_sec)
{
    if (ensure_fd(motor) != 0 || !degrees_per_sec) {
        errno = EINVAL;
        return -1;
    }

    int val = 0;
    if (ioctl(motor->fd, AK_MOTOR_GET_ANG_SPEED, &val) < 0) {
        fprintf(stderr, "[ak-motor] GET_ANG_SPEED failed (%s)\n", strerror(errno));
        return -1;
    }
    *degrees_per_sec = val;
    return 0;
}

int ak_motor_move(struct ak_motor *motor, enum ak_motor_direction dir, int angle_deg)
{
    if (ensure_fd(motor) != 0 || angle_deg <= 0) {
        errno = EINVAL;
        return -1;
    }

    int cmd = (dir == AK_MOTOR_DIR_CCW) ? AK_MOTOR_TURN_ANTICLKWISE
                                        : AK_MOTOR_TURN_CLKWISE;
    if (ioctl(motor->fd, cmd, &angle_deg) < 0) {
        fprintf(stderr, "[ak-motor] TURN_%s failed (%s)\n",
                (dir == AK_MOTOR_DIR_CCW) ? "ANTICLK" : "CLK",
                strerror(errno));
        return -1;
    }
    return 0;
}

int ak_motor_stop(struct ak_motor *motor)
{
    if (ensure_fd(motor) != 0) {
        return -1;
    }

    int dummy = 0;
    if (ioctl(motor->fd, AK_MOTOR_TURN_STOP, &dummy) < 0) {
        fprintf(stderr, "[ak-motor] TURN_STOP failed (%s)\n", strerror(errno));
        return -1;
    }
    return 0;
}

int ak_motor_get_hits(struct ak_motor *motor, int *hit_flags)
{
    if (ensure_fd(motor) != 0 || !hit_flags) {
        errno = EINVAL;
        return -1;
    }

    int flags = 0;
    if (ioctl(motor->fd, AK_MOTOR_GET_HIT_STATUS, &flags) < 0) {
        fprintf(stderr, "[ak-motor] GET_HIT_STATUS failed (%s)\n", strerror(errno));
        return -1;
    }
    *hit_flags = flags;
    return 0;
}

static int read_notify(int fd, struct notify_data_kernel *data)
{
    ssize_t ret;

    while (1) {
        ret = read(fd, data, sizeof(*data));
        if (ret >= 0) {
            return 0;
        }
        if (errno == EINTR) {
            continue;
        }
        return -1;
    }
}

int ak_motor_wait_event(struct ak_motor *motor,
                        struct ak_motor_event *event,
                        int timeout_ms)
{
    if (ensure_fd(motor) != 0 || !event) {
        errno = EINVAL;
        return -1;
    }

    struct pollfd pfd = {
        .fd = motor->fd,
        .events = POLLIN,
        .revents = 0,
    };

    int poll_timeout = timeout_ms;
    for (;;) {
        int rc = poll(&pfd, 1, poll_timeout);
        if (rc > 0) {
            break;
        }
        if (rc == 0) {
            errno = ETIMEDOUT;
            return 1;
        }
        if (errno == EINTR) {
            continue;
        }
        fprintf(stderr, "[ak-motor] poll failed (%s)\n", strerror(errno));
        return -1;
    }

    struct notify_data_kernel data;
    if (read_notify(motor->fd, &data) < 0) {
        fprintf(stderr, "[ak-motor] read event failed (%s)\n", strerror(errno));
        return -1;
    }

    event->hit_index = data.hit_num;
    event->type = (enum ak_motor_event_type)data.event;
    event->remaining_angle = data.remain_angle;
    return 0;
}

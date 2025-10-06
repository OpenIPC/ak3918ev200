#ifndef AK3918_MOTOR_H
#define AK3918_MOTOR_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _IO
# include <linux/ioctl.h>
#endif

#define AK_MOTOR_IOC_MAGIC      'm'
#define AK_MOTOR_SET_ANG_SPEED  _IOW(AK_MOTOR_IOC_MAGIC, 11, int)
#define AK_MOTOR_GET_ANG_SPEED  _IOR(AK_MOTOR_IOC_MAGIC, 12, int)
#define AK_MOTOR_TURN_CLKWISE   _IOW(AK_MOTOR_IOC_MAGIC, 13, int)
#define AK_MOTOR_TURN_ANTICLKWISE _IOW(AK_MOTOR_IOC_MAGIC, 14, int)
#define AK_MOTOR_GET_HIT_STATUS _IOR(AK_MOTOR_IOC_MAGIC, 15, int)
#define AK_MOTOR_TURN_STOP      _IOW(AK_MOTOR_IOC_MAGIC, 16, int)

#define AK_MOTOR_EVENT_HIT      1
#define AK_MOTOR_EVENT_UNHIT    2
#define AK_MOTOR_EVENT_STOP     3

#define AK_MOTOR_HITTING_LEFT   (1 << 0)
#define AK_MOTOR_HITTING_RIGHT  (1 << 1)

#define AK_MOTOR_MIN_SPEED      1
#define AK_MOTOR_MAX_SPEED      16

struct ak_motor;

enum ak_motor_direction {
    AK_MOTOR_DIR_CW = 0,
    AK_MOTOR_DIR_CCW = 1,
};

enum ak_motor_event_type {
    AK_MOTOR_EVT_HIT = AK_MOTOR_EVENT_HIT,
    AK_MOTOR_EVT_UNHIT = AK_MOTOR_EVENT_UNHIT,
    AK_MOTOR_EVT_STOP = AK_MOTOR_EVENT_STOP,
};

struct ak_motor_event {
    int hit_index;              /* 0 = left, 1 = right */
    enum ak_motor_event_type type;
    int remaining_angle;        /* degrees left according to kernel */
};

struct ak_motor *ak_motor_open(int index);
void ak_motor_close(struct ak_motor *motor);
const char *ak_motor_path(const struct ak_motor *motor);
int ak_motor_fd(const struct ak_motor *motor);
int ak_motor_set_speed(struct ak_motor *motor, int degrees_per_sec);
int ak_motor_get_speed(struct ak_motor *motor, int *degrees_per_sec);
int ak_motor_move(struct ak_motor *motor, enum ak_motor_direction dir, int angle_deg);
int ak_motor_stop(struct ak_motor *motor);
int ak_motor_get_hits(struct ak_motor *motor, int *hit_flags);
int ak_motor_wait_event(struct ak_motor *motor,
                        struct ak_motor_event *event,
                        int timeout_ms);

#ifdef __cplusplus
}
#endif

#endif /* AK3918_MOTOR_H */

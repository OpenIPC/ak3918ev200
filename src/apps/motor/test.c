#include "ak3918/motor.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void usage(const char *argv0)
{
    fprintf(stderr,
            "Usage: %s <index> [--speed N] [--angle deg] [--dir cw|ccw] [--hits-only]\n",
            argv0);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    int idx = atoi(argv[1]);
    int speed = -1;
    int angle = 45;
    enum ak_motor_direction dir = AK_MOTOR_DIR_CW;
    int hits_only = 0;

    for (int i = 2; i < argc; ++i) {
        if (strcmp(argv[i], "--speed") == 0 && i + 1 < argc) {
            speed = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--angle") == 0 && i + 1 < argc) {
            angle = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--dir") == 0 && i + 1 < argc) {
            const char *val = argv[++i];
            if (strcmp(val, "cw") == 0) {
                dir = AK_MOTOR_DIR_CW;
            } else if (strcmp(val, "ccw") == 0) {
                dir = AK_MOTOR_DIR_CCW;
            } else {
                fprintf(stderr, "Unknown direction '%s'\n", val);
                return EXIT_FAILURE;
            }
        } else if (strcmp(argv[i], "--hits-only") == 0) {
            hits_only = 1;
        } else {
            fprintf(stderr, "Unknown option '%s'\n", argv[i]);
            usage(argv[0]);
            return EXIT_FAILURE;
        }
    }

    struct ak_motor *motor = ak_motor_open(idx);
    if (!motor) {
        return EXIT_FAILURE;
    }

    printf("Motor %d opened (%s)\n", idx, ak_motor_path(motor));

    if (speed > 0) {
        if (ak_motor_set_speed(motor, speed) == 0) {
            printf("Set speed to %d deg/s\n", speed);
        } else {
            ak_motor_close(motor);
            return EXIT_FAILURE;
        }
    }

    if (hits_only) {
        int hits = 0;
        if (ak_motor_get_hits(motor, &hits) == 0) {
            printf("Hit status: 0x%x (LEFT=%s RIGHT=%s)\n", hits,
                   (hits & AK_MOTOR_HITTING_LEFT) ? "yes" : "no",
                   (hits & AK_MOTOR_HITTING_RIGHT) ? "yes" : "no");
        }
        ak_motor_close(motor);
        return 0;
    }

    if (angle > 0) {
        if (ak_motor_move(motor, dir, angle) < 0) {
            ak_motor_close(motor);
            return EXIT_FAILURE;
        }
        printf("Issued move %s %d degrees\n",
               (dir == AK_MOTOR_DIR_CCW) ? "CCW" : "CW",
               angle);
    }

    puts("Waiting for events (Ctrl+C to exit)...");
    while (1) {
        struct ak_motor_event ev;
        int rc = ak_motor_wait_event(motor, &ev, 2000);
        if (rc == 1) {
            puts("  timeout");
            continue;
        }
        if (rc < 0) {
            perror("ak_motor_wait_event");
            break;
        }

        const char *etype = (ev.type == AK_MOTOR_EVT_HIT) ? "HIT"
                                : (ev.type == AK_MOTOR_EVT_UNHIT) ? "UNHIT"
                                : "STOP";
        printf("  event=%s hit=%d remain=%d\n",
               etype, ev.hit_index, ev.remaining_angle);
        if (ev.type == AK_MOTOR_EVT_STOP) {
            break;
        }
    }

    ak_motor_close(motor);
    return 0;
}


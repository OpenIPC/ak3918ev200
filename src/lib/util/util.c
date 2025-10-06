#include "ak3918/util.h"

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

void die_perror(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int xopen(const char *path, int flags) {
    int fd;
    do {
        fd = open(path, flags, 0666);
    } while (fd < 0 && errno == EINTR);

    if (fd < 0) {
        die_perror(path);
    }
    return fd;
}

void xclose(int fd) {
    if (fd < 0) {
        return;
    }

    int rc;
    do {
        rc = close(fd);
    } while (rc < 0 && errno == EINTR);
}

int xioctl(int fd, unsigned long req, void *arg) {
    int rc;
    do {
        rc = ioctl(fd, req, arg);
    } while (rc == -1 && errno == EINTR);
    return rc;
}


#include "ak3918/audio.h"

/* Basado en la traza reconstruida desde decompiled/ipc_untouched.c */

#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define AK_AO_ENABLE_OUTPUT   0x40045081UL
#define AK_AO_RESET_BUF       0x50e3UL
#define AK_AO_SET_MODE        0x40045030UL
#define AK_AO_GET_MODE        0x80045030UL
#define AK_AO_SET_SOURCE      0x40045010UL
#define AK_AO_GET_SOURCE      0x80045010UL
#define AK_AO_SET_CLOCK       0x40045070UL
#define AK_AO_COMMIT_PARAMS   0x401c50f2UL
#define AK_AO_FETCH_PARAMS    0x801c50f2UL
#define AK_AO_SYNC_PARAMS     0x804050f0UL
#define AK_AO_POWER_CTRL      0x50e2UL
#define AK_AO_STREAM_ENABLE   0x50e0UL
#define AK_AUDIO_PORT_SYNC    0x50e1UL

#define AK_AI_SET_SOURCE      0x40045010UL
#define AK_AI_SET_CLOCK       0x40045070UL
#define AK_AI_SET_MODE        0x40045030UL
#define AK_AI_RESET_BUF       0x50e3UL
#define AK_AI_ENABLE_ADC      0x40045088UL
#define AK_AI_POWER_CTRL      0x50e2UL
#define AK_AI_COMMIT_PARAMS   0x401c50f2UL
#define AK_AI_STREAM_ENABLE   0x50e0UL
#define AK_AI_SYNC_PARAMS     0x804050f0UL
#define AK_AI_SYNC_SHADOW     AK_AUDIO_PORT_SYNC
#define AK_AI_READ_POSITION   0x80045085UL
#define AK_AI_ACK_POSITION    0x40045086UL
#define AK_AI_QUERY_AVAIL     0x800450e8UL

static int run_ioctl(int fd, unsigned long req, void *arg, const char *what)
{
    int rc;
    if (arg) {
        rc = ioctl(fd, req, arg);
    } else {
        rc = ioctl(fd, req);
    }
    if (rc < 0) {
        fprintf(stderr, "[ak-audio] ioctl %s (0x%lx) falló: %s\n",
                what, req, strerror(errno));
        return -1;
    }
    return 0;
}

static void fill_audio_blob(uint32_t blob[7],
                            const struct ak_audio_format *fmt,
                            size_t chunk_bytes,
                            uint32_t frame_count)
{
    blob[0] = fmt->sample_rate;
    blob[1] = fmt->channels;
    blob[2] = fmt->bits_per_sample;
    blob[3] = (uint32_t)chunk_bytes;
    blob[4] = frame_count;
    blob[5] = (uint32_t)chunk_bytes;
    blob[6] = 0;
}

static void apply_defaults(struct ak_audio_device *dev,
                           struct ak_audio_params params,
                           enum ak_audio_direction direction)
{
    dev->direction = direction;
    dev->format = params.format;
    dev->chunk_bytes = params.chunk_bytes;
    memset(dev->shadow_params, 0, sizeof(dev->shadow_params));
    dev->shadow_param_len = 0;
    dev->shadow_valid = false;
    dev->pending_ack_addr = 0;
    dev->pending_ack_valid = false;
}

static int audio_kick_port(struct ak_audio_device *dev, const char *what)
{
    if (!dev) {
        errno = EINVAL;
        return -1;
    }

    int rc = ioctl(dev->fd, AK_AUDIO_PORT_SYNC);
    if (rc == 0) {
        return 0;
    }

    int first_err = errno;
    if ((first_err == EFAULT || first_err == EINVAL) && dev->shadow_valid) {
        rc = ioctl(dev->fd, AK_AUDIO_PORT_SYNC, dev->shadow_params);
        if (rc == 0) {
            return 0;
        }
    } else {
        errno = first_err;
    }

    fprintf(stderr, "[ak-audio] ioctl %s (0x%lx) falló: %s\n",
            what, AK_AUDIO_PORT_SYNC, strerror(errno));
    return -1;
}

static struct ak_audio_params default_params(enum ak_audio_direction direction)
{
    struct ak_audio_params params;
    if (direction == AK_AUDIO_PLAYBACK) {
        params.format.sample_rate = AK_AUDIO_DEFAULT_PLAYBACK_RATE;
        params.format.channels = AK_AUDIO_DEFAULT_PLAYBACK_CHANNELS;
        params.chunk_bytes = AK_AUDIO_DEFAULT_PLAYBACK_CHUNK;
    } else {
        params.format.sample_rate = AK_AUDIO_DEFAULT_CAPTURE_RATE;
        params.format.channels = AK_AUDIO_DEFAULT_CAPTURE_CHANNELS;
        params.chunk_bytes = AK_AUDIO_DEFAULT_CAPTURE_CHUNK;
    }
    params.format.bits_per_sample = AK_AUDIO_DEFAULT_BITS_PER_SAMPLE;
    return params;
}

static int configure_playback(struct ak_audio_device *dev)
{
    uint32_t enable = 1;
    uint32_t mode = 5;
    uint32_t mode_ready = 4;
    uint32_t source_i2s = 4;
    uint32_t clk_enable = 1;
    uint32_t params_blob[7];
    uint32_t tmp32 = 0;
    uint8_t sync_buf[64];

    memset(sync_buf, 0, sizeof(sync_buf));
    fill_audio_blob(params_blob, &dev->format, dev->chunk_bytes, 12U);

    if (run_ioctl(dev->fd, AK_AO_ENABLE_OUTPUT, &enable, "AK_AO_ENABLE_OUTPUT")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AO_RESET_BUF, NULL, "AK_AO_RESET_BUF")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AO_SET_MODE, &mode, "AK_AO_SET_MODE(5)")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AO_SET_MODE, &mode_ready, "AK_AO_SET_MODE(4)")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AO_SET_SOURCE, &source_i2s, "AK_AO_SET_SOURCE")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AO_SET_CLOCK, &clk_enable, "AK_AO_SET_CLOCK")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AO_POWER_CTRL, NULL, "AK_AO_POWER_CTRL")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AO_COMMIT_PARAMS, params_blob, "AK_AO_COMMIT_PARAMS")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AO_STREAM_ENABLE, NULL, "AK_AO_STREAM_ENABLE")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AO_SYNC_PARAMS, sync_buf, "AK_AO_SYNC_PARAMS")) {
        return -1;
    }
    memcpy(dev->shadow_params, sync_buf, sizeof(sync_buf));
    dev->shadow_param_len = sizeof(sync_buf);
    dev->shadow_valid = true;
    if (run_ioctl(dev->fd, AK_AO_FETCH_PARAMS, params_blob, "AK_AO_FETCH_PARAMS")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AO_GET_SOURCE, &tmp32, "AK_AO_GET_SOURCE")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AO_GET_MODE, &tmp32, "AK_AO_GET_MODE")) {
        return -1;
    }
    if (audio_kick_port(dev, "AK_AO_PORT_SYNC")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AO_RESET_BUF, NULL, "AK_AO_RESET_BUF(end)")) {
        return -1;
    }
    return 0;
}

static int configure_capture(struct ak_audio_device *dev)
{
    uint32_t source_i2s = 2;
    uint32_t clk_enable = 1;
    uint32_t mode = 7;
    uint32_t adc_enable = 1;
    uint32_t zero = 0;
    uint32_t params_blob[7];
    uint8_t sync_buf[64];

    memset(sync_buf, 0, sizeof(sync_buf));
    fill_audio_blob(params_blob, &dev->format, dev->chunk_bytes, 16U);

    if (run_ioctl(dev->fd, AK_AI_SET_SOURCE, &source_i2s, "AK_AI_SET_SOURCE")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AI_SET_CLOCK, &clk_enable, "AK_AI_SET_CLOCK")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AI_SET_MODE, &mode, "AK_AI_SET_MODE")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AI_RESET_BUF, NULL, "AK_AI_RESET_BUF")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AI_ENABLE_ADC, &adc_enable, "AK_AI_ENABLE_ADC")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AI_POWER_CTRL, NULL, "AK_AI_POWER_CTRL")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AI_COMMIT_PARAMS, params_blob, "AK_AI_COMMIT_PARAMS")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AI_STREAM_ENABLE, NULL, "AK_AI_STREAM_ENABLE")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AI_SYNC_PARAMS, sync_buf, "AK_AI_SYNC_PARAMS")) {
        return -1;
    }
    memcpy(dev->shadow_params, sync_buf, sizeof(sync_buf));
    dev->shadow_param_len = sizeof(sync_buf);
    dev->shadow_valid = true;
    if (run_ioctl(dev->fd, AK_AI_POWER_CTRL, NULL, "AK_AI_POWER_CTRL(2)")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AI_SYNC_SHADOW, sync_buf, "AK_AI_SYNC_SHADOW")) {
        return -1;
    }
    if (run_ioctl(dev->fd, AK_AI_READ_POSITION, dev->shadow_params, "AK_AI_READ_POSITION")) {
        return -1;
    }
    memcpy(&dev->pending_ack_addr, dev->shadow_params, sizeof(uint32_t));
    dev->pending_ack_valid = true;
    memcpy(dev->shadow_params, &zero, sizeof(uint32_t));
    if (run_ioctl(dev->fd, AK_AI_ACK_POSITION, dev->shadow_params, "AK_AI_ACK_POSITION")) {
        return -1;
    }
    dev->pending_ack_valid = false;
    return 0;
}

static int open_audio_device(const char *device_path, int flags)
{
    int fd = open(device_path, flags);
    if (fd < 0) {
        fprintf(stderr, "[ak-audio] no se pudo abrir %s: %s\n",
                device_path, strerror(errno));
    }
    return fd;
}

int ak_audio_open_playback(struct ak_audio_device *dev,
                           const char *device_path,
                           const struct ak_audio_params *params)
{
    if (!dev || !device_path) {
        errno = EINVAL;
        return -1;
    }

    struct ak_audio_params effective = params ? *params : default_params(AK_AUDIO_PLAYBACK);
    if (effective.format.bits_per_sample == 0) {
        effective.format.bits_per_sample = AK_AUDIO_DEFAULT_BITS_PER_SAMPLE;
    }
    if (effective.format.channels == 0) {
        effective.format.channels = AK_AUDIO_DEFAULT_PLAYBACK_CHANNELS;
    }
    if (effective.format.sample_rate == 0) {
        effective.format.sample_rate = AK_AUDIO_DEFAULT_PLAYBACK_RATE;
    }
    if (effective.chunk_bytes == 0) {
        effective.chunk_bytes = AK_AUDIO_DEFAULT_PLAYBACK_CHUNK;
    }

    int fd = open_audio_device(device_path, O_WRONLY);
    if (fd < 0) {
        return -1;
    }

    dev->fd = fd;
    apply_defaults(dev, effective, AK_AUDIO_PLAYBACK);

    if (configure_playback(dev) != 0) {
        ak_audio_close(dev);
        return -1;
    }
    return 0;
}

int ak_audio_open_capture(struct ak_audio_device *dev,
                          const char *device_path,
                          const struct ak_audio_params *params)
{
    if (!dev || !device_path) {
        errno = EINVAL;
        return -1;
    }

    struct ak_audio_params effective = params ? *params : default_params(AK_AUDIO_CAPTURE);
    if (effective.format.bits_per_sample == 0) {
        effective.format.bits_per_sample = AK_AUDIO_DEFAULT_BITS_PER_SAMPLE;
    }
    if (effective.format.channels == 0) {
        effective.format.channels = AK_AUDIO_DEFAULT_CAPTURE_CHANNELS;
    }
    if (effective.format.sample_rate == 0) {
        effective.format.sample_rate = AK_AUDIO_DEFAULT_CAPTURE_RATE;
    }
    if (effective.chunk_bytes == 0) {
        effective.chunk_bytes = AK_AUDIO_DEFAULT_CAPTURE_CHUNK;
    }

    int fd = open_audio_device(device_path, O_RDWR | O_NONBLOCK);
    if (fd < 0) {
        return -1;
    }

    dev->fd = fd;
    apply_defaults(dev, effective, AK_AUDIO_CAPTURE);

    if (configure_capture(dev) != 0) {
        ak_audio_close(dev);
        return -1;
    }
    return 0;
}

ssize_t ak_audio_playback_write(struct ak_audio_device *dev,
                                const void *data,
                                size_t len)
{
    if (!dev || dev->fd < 0 || dev->direction != AK_AUDIO_PLAYBACK) {
        errno = EINVAL;
        return -1;
    }
    const uint8_t *p = (const uint8_t *)data;
    size_t total = 0;
    while (total < len) {
        if (audio_kick_port(dev, "AK_AO_PORT_SYNC(write)")) {
            return -1;
        }

        size_t remaining = len - total;
        ssize_t rc = write(dev->fd, p + total, remaining);
        if (rc < 0) {
            if (errno == EINTR) {
                continue;
            }
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                usleep(5000);
                continue;
            }
            if (errno == EINVAL) {
                const size_t fallback_sizes[] = { 576U, 384U };
                bool wrote_any = false;
                for (size_t i = 0; i < sizeof(fallback_sizes) / sizeof(fallback_sizes[0]); ++i) {
                    size_t attempt = fallback_sizes[i];
                    if (attempt > remaining) {
                        continue;
                    }
                    rc = write(dev->fd, p + total, attempt);
                    if (rc > 0) {
                        wrote_any = true;
                        break;
                    }
                    if (rc < 0 && errno == EINTR) {
                        i--;
                        continue;
                    }
                }
                if (!wrote_any) {
                    return -1;
                }
            } else {
                return -1;
            }
        }
        if (rc <= 0) {
            break;
        }
        total += (size_t)rc;
    }
    return (ssize_t)total;
}

ssize_t ak_audio_capture_read(struct ak_audio_device *dev,
                              void *data,
                              size_t len)
{
    if (!dev || dev->fd < 0 || dev->direction != AK_AUDIO_CAPTURE) {
        errno = EINVAL;
        return -1;
    }
    uint8_t *p = (uint8_t *)data;
    size_t total = 0;
    while (total < len) {
        if (audio_kick_port(dev, "AK_AI_PORT_SYNC(read)")) {
            return -1;
        }

        ssize_t rc = read(dev->fd, p + total, len - total);
        if (rc < 0) {
            if (errno == EINTR) {
                continue;
            }
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                break;
            }
            return -1;
        }
        if (rc == 0) {
            break;
        }
        total += (size_t)rc;
        if (dev->pending_ack_valid) {
            memcpy(dev->shadow_params, &dev->pending_ack_addr, sizeof(uint32_t));
            if (run_ioctl(dev->fd, AK_AI_ACK_POSITION, dev->shadow_params, "AK_AI_ACK_POSITION(loop)")) {
                return -1;
            }
            dev->pending_ack_valid = false;
        }
    }
    return (ssize_t)total;
}

int ak_audio_capture_avail(struct ak_audio_device *dev,
                           uint32_t *avail_bytes)
{
    if (!dev || dev->fd < 0 || dev->direction != AK_AUDIO_CAPTURE || !avail_bytes) {
        errno = EINVAL;
        return -1;
    }
    if (audio_kick_port(dev, "AK_AI_PORT_SYNC(avail)")) {
        return -1;
    }
    uint32_t value = 0;
    if (run_ioctl(dev->fd, AK_AI_QUERY_AVAIL, &value, "AK_AI_QUERY_AVAIL") != 0) {
        return -1;
    }
    if (value > 0) {
        if (run_ioctl(dev->fd, AK_AI_READ_POSITION, dev->shadow_params, "AK_AI_READ_POSITION(loop)")) {
            return -1;
        }
        memcpy(&dev->pending_ack_addr, dev->shadow_params, sizeof(uint32_t));
        dev->pending_ack_valid = true;
    }
    *avail_bytes = value;
    return 0;
}

void ak_audio_close(struct ak_audio_device *dev)
{
    if (!dev) {
        return;
    }
    if (dev->fd >= 0) {
        close(dev->fd);
    }
    dev->fd = -1;
    dev->shadow_param_len = 0;
    dev->shadow_valid = false;
    memset(dev->shadow_params, 0, sizeof(dev->shadow_params));
    dev->pending_ack_addr = 0;
    dev->pending_ack_valid = false;
}

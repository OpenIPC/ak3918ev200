#ifndef AK3918_AUDIO_H
#define AK3918_AUDIO_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

enum ak_audio_direction {
    AK_AUDIO_PLAYBACK = 0,
    AK_AUDIO_CAPTURE  = 1,
};

struct ak_audio_format {
    uint32_t sample_rate;
    uint16_t channels;
    uint16_t bits_per_sample;
};

struct ak_audio_params {
    struct ak_audio_format format;
    size_t chunk_bytes;
};

struct ak_audio_device {
    int fd;
    enum ak_audio_direction direction;
    struct ak_audio_format format;
    size_t chunk_bytes;
    uint8_t shadow_params[64];
    size_t shadow_param_len;
    bool shadow_valid;
    uint32_t pending_ack_addr;
    bool pending_ack_valid;
};

#define AK_AUDIO_DEFAULT_BITS_PER_SAMPLE   16U
#define AK_AUDIO_DEFAULT_PLAYBACK_RATE     16000U
#define AK_AUDIO_DEFAULT_PLAYBACK_CHANNELS 2U
#define AK_AUDIO_DEFAULT_CAPTURE_RATE      16000U
#define AK_AUDIO_DEFAULT_CAPTURE_CHANNELS  1U
#define AK_AUDIO_DEFAULT_PLAYBACK_CHUNK    4096U
#define AK_AUDIO_DEFAULT_CAPTURE_CHUNK     2048U

int ak_audio_open_playback(struct ak_audio_device *dev,
                           const char *device_path,
                           const struct ak_audio_params *params);

int ak_audio_open_capture(struct ak_audio_device *dev,
                          const char *device_path,
                          const struct ak_audio_params *params);

ssize_t ak_audio_playback_write(struct ak_audio_device *dev,
                                const void *data,
                                size_t len);

ssize_t ak_audio_capture_read(struct ak_audio_device *dev,
                              void *data,
                              size_t len);

int ak_audio_capture_avail(struct ak_audio_device *dev,
                           uint32_t *avail_bytes);

void ak_audio_close(struct ak_audio_device *dev);

#ifdef __cplusplus
}
#endif

#endif /* AK3918_AUDIO_H */

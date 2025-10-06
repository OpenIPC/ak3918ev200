#include "ak3918/audio.h"

#include <errno.h>
#include <getopt.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

static volatile sig_atomic_t g_stop = 0;

static void on_signal(int sig)
{
    (void)sig;
    g_stop = 1;
}

static void print_usage(FILE *out, const char *prog)
{
    fprintf(out,
            "Uso: %s [opciones] /dev/akpcm_cdev1 salida.pcm\n"
            "\n"
            "Opciones:\n"
            "  -r <Hz>       Frecuencia de muestreo (por defecto %u)\n"
            "  -c <canales>  Número de canales (por defecto %u)\n"
            "  -b <bits>     Bits por muestra (por defecto %u)\n"
            "  -s <bytes>    Tamaño de lectura recomendado (por defecto %u)\n"
            "  -m <bytes>    Límite de captura (0 = ilimitado)\n"
            "  -h            Mostrar esta ayuda\n",
            prog,
            AK_AUDIO_DEFAULT_CAPTURE_RATE,
            AK_AUDIO_DEFAULT_CAPTURE_CHANNELS,
            AK_AUDIO_DEFAULT_BITS_PER_SAMPLE,
            AK_AUDIO_DEFAULT_CAPTURE_CHUNK);
}

static void msleep(unsigned int ms)
{
    struct timespec ts;
    ts.tv_sec = ms / 1000U;
    ts.tv_nsec = (long)(ms % 1000U) * 1000000L;
    nanosleep(&ts, NULL);
}

static void hexdump(const unsigned char *buf, size_t len)
{
    const size_t limit = len < 64 ? len : 64;
    for (size_t i = 0; i < limit; ++i) {
        if ((i % 16) == 0) {
            printf("%04zx: ", i);
        }
        printf("%02x ", buf[i]);
        if ((i % 16) == 15) {
            putchar('\n');
        }
    }
    if ((limit % 16) != 0) {
        putchar('\n');
    }
}

int main(int argc, char **argv)
{
    struct ak_audio_params params = {
        .format = {
            .sample_rate = AK_AUDIO_DEFAULT_CAPTURE_RATE,
            .channels = AK_AUDIO_DEFAULT_CAPTURE_CHANNELS,
            .bits_per_sample = AK_AUDIO_DEFAULT_BITS_PER_SAMPLE,
        },
        .chunk_bytes = AK_AUDIO_DEFAULT_CAPTURE_CHUNK,
    };

    size_t limit_bytes = 0;

    int opt;
    while ((opt = getopt(argc, argv, "r:c:b:s:m:h")) != -1) {
        switch (opt) {
        case 'r':
            params.format.sample_rate = (uint32_t)strtoul(optarg, NULL, 0);
            break;
        case 'c':
            params.format.channels = (uint16_t)strtoul(optarg, NULL, 0);
            break;
        case 'b':
            params.format.bits_per_sample = (uint16_t)strtoul(optarg, NULL, 0);
            break;
        case 's':
            params.chunk_bytes = (size_t)strtoul(optarg, NULL, 0);
            break;
        case 'm':
            limit_bytes = (size_t)strtoull(optarg, NULL, 0);
            break;
        case 'h':
            print_usage(stdout, argv[0]);
            return 0;
        default:
            print_usage(stderr, argv[0]);
            return 1;
        }
    }

    if (argc - optind != 2) {
        print_usage(stderr, argv[0]);
        return 1;
    }

    const char *device_path = argv[optind];
    const char *output_path = argv[optind + 1];

    if (params.chunk_bytes == 0) {
        params.chunk_bytes = AK_AUDIO_DEFAULT_CAPTURE_CHUNK;
    }

    FILE *output = fopen(output_path, "wb");
    if (!output) {
        fprintf(stderr, "[capture] no se pudo abrir %s: %s\n",
                output_path, strerror(errno));
        return 1;
    }

    struct ak_audio_device dev = { .fd = -1 };
    if (ak_audio_open_capture(&dev, device_path, &params) != 0) {
        fprintf(stderr, "[capture] error al inicializar %s: %s\n",
                device_path, strerror(errno));
        fclose(output);
        return 1;
    }

    printf("[capture] %u Hz, %u canales, %u bits, chunk %zu bytes\n",
           dev.format.sample_rate,
           dev.format.channels,
           dev.format.bits_per_sample,
           dev.chunk_bytes);

    unsigned char *buffer = malloc(dev.chunk_bytes);
    if (!buffer) {
        fprintf(stderr, "[capture] sin memoria para buffer de %zu bytes\n", dev.chunk_bytes);
        ak_audio_close(&dev);
        fclose(output);
        return 1;
    }

    signal(SIGINT, on_signal);
    signal(SIGTERM, on_signal);

    size_t total_written = 0;
    bool dumped_first = false;

    while (!g_stop) {
        if (limit_bytes && total_written >= limit_bytes) {
            break;
        }

        uint32_t avail = 0;
        if (ak_audio_capture_avail(&dev, &avail) != 0) {
            if (errno == EINTR) {
                continue;
            }
            fprintf(stderr, "[capture] ioctl avail falló: %s\n", strerror(errno));
            msleep(10);
            continue;
        }

        if (avail == 0) {
            msleep(10);
            continue;
        }

        size_t want = avail;
        if (want > dev.chunk_bytes) {
            want = dev.chunk_bytes;
        }
        if (limit_bytes && want > (limit_bytes - total_written)) {
            want = limit_bytes - total_written;
        }

        ssize_t rc = ak_audio_capture_read(&dev, buffer, want);
        if (rc < 0) {
            if (errno == EINTR || errno == EAGAIN || errno == EWOULDBLOCK) {
                continue;
            }
            fprintf(stderr, "[capture] read falló: %s\n", strerror(errno));
            break;
        }
        if (rc == 0) {
            msleep(5);
            continue;
        }

        size_t wrote = fwrite(buffer, 1, (size_t)rc, output);
        if (wrote != (size_t)rc) {
            fprintf(stderr, "[capture] fwrite falló: %s\n", strerror(errno));
            break;
        }
        total_written += wrote;

        if (!dumped_first) {
            printf("[capture] primeros %zu bytes:\n", (size_t)rc < 64 ? (size_t)rc : (size_t)64);
            hexdump(buffer, (size_t)rc);
            dumped_first = true;
        }
    }

    printf("[capture] total capturado: %zu bytes\n", total_written);

    free(buffer);
    ak_audio_close(&dev);
    fclose(output);
    return 0;
}

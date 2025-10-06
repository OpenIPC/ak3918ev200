#include "ak3918/audio.h"

#include <errno.h>
#include <getopt.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
            "Uso: %s [opciones] /dev/akpcm_cdev0 input.pcm\n"
            "\n"
            "Opciones:\n"
            "  -r <Hz>       Frecuencia de muestreo (por defecto %u)\n"
            "  -c <canales>  Número de canales (por defecto %u)\n"
            "  -b <bits>     Bits por muestra (por defecto %u)\n"
            "  -s <bytes>    Tamaño de bloque a escribir (por defecto %u)\n"
            "  -h            Mostrar esta ayuda\n",
            prog,
            AK_AUDIO_DEFAULT_PLAYBACK_RATE,
            AK_AUDIO_DEFAULT_PLAYBACK_CHANNELS,
            AK_AUDIO_DEFAULT_BITS_PER_SAMPLE,
            AK_AUDIO_DEFAULT_PLAYBACK_CHUNK);
}

int main(int argc, char **argv)
{
    struct ak_audio_params params = {
        .format = {
            .sample_rate = AK_AUDIO_DEFAULT_PLAYBACK_RATE,
            .channels = AK_AUDIO_DEFAULT_PLAYBACK_CHANNELS,
            .bits_per_sample = AK_AUDIO_DEFAULT_BITS_PER_SAMPLE,
        },
        .chunk_bytes = AK_AUDIO_DEFAULT_PLAYBACK_CHUNK,
    };

    int opt;
    while ((opt = getopt(argc, argv, "r:c:b:s:h")) != -1) {
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
    const char *input_path = argv[optind + 1];

    if (params.chunk_bytes == 0) {
        params.chunk_bytes = AK_AUDIO_DEFAULT_PLAYBACK_CHUNK;
    }

    FILE *input = fopen(input_path, "rb");
    if (!input) {
        fprintf(stderr, "[playback] no se pudo abrir %s: %s\n",
                input_path, strerror(errno));
        return 1;
    }

    struct ak_audio_device dev = { .fd = -1 };
    if (ak_audio_open_playback(&dev, device_path, &params) != 0) {
        fprintf(stderr, "[playback] error al inicializar %s: %s\n",
                device_path, strerror(errno));
        fclose(input);
        return 1;
    }

    printf("[playback] %u Hz, %u canales, %u bits, chunk %zu bytes\n",
           dev.format.sample_rate,
           dev.format.channels,
           dev.format.bits_per_sample,
           dev.chunk_bytes);

    unsigned char *buffer = malloc(dev.chunk_bytes);
    if (!buffer) {
        fprintf(stderr, "[playback] sin memoria para buffer de %zu bytes\n", dev.chunk_bytes);
        ak_audio_close(&dev);
        fclose(input);
        return 1;
    }

    signal(SIGINT, on_signal);
    signal(SIGTERM, on_signal);

    size_t total_written = 0;
    while (!g_stop) {
        size_t n = fread(buffer, 1, dev.chunk_bytes, input);
        if (n == 0) {
            if (feof(input)) {
                break;
            }
            if (ferror(input)) {
                fprintf(stderr, "[playback] fallo al leer %s: %s\n",
                        input_path, strerror(errno));
                break;
            }
        }

        size_t offset = 0;
        while (offset < n && !g_stop) {
            ssize_t rc = ak_audio_playback_write(&dev, buffer + offset, n - offset);
            if (rc < 0) {
                if (errno == EINTR) {
                    continue;
                }
                fprintf(stderr, "[playback] write falló: %s\n", strerror(errno));
                g_stop = 1;
                break;
            }
            if (rc == 0) {
                break;
            }
            offset += (size_t)rc;
            total_written += (size_t)rc;
        }
    }

    printf("[playback] total enviado: %zu bytes\n", total_written);

    free(buffer);
    ak_audio_close(&dev);
    fclose(input);
    return 0;
}

# Estructura de la base de código

Este documento resume la reorganización del árbol de fuentes para el proyecto **AK3918EV200_GWELL_V1**. El objetivo es aislar el código de usuario del kernel, agrupar los módulos por dominio funcional y documentar cómo se generan las herramientas de audio y video a partir de la ingeniería inversa del *ipc* original.

## Vista general

```
include/
  ak3918/
    audio.h            # API de alto nivel para /dev/akpcm_cdev{0,1}
    blob.h, util.h     # Utilidades compartidas
    ion.h              # Abstracciones para el asignador ION/DMABUF
    isp.h, isp_conf.h  # Interfaces del pipeline ISP
    video.h            # Abstracciones para el UIO del codificador H.264
    motor.h            # Control de /dev/ak-motorN
    spiflash.h         # Utilidades para NOR (MTD)
    sdk/akispsdk.h     # Prototipos de la librería propietaria
src/
  lib/
    audio/akpcm_device.c   # Secuencia de ioctls reconstruida para DAC/ADC
    video/uio.c            # Helpers UIO portados del ipc decompilado
    isp/*.c                # Parser y aplicación de blobs ISP
    sys/ion.c              # Acceso a /dev/ion
    util/*.c               # Funciones de soporte
    sys/gpio.c             # Control GPIO
    sys/motor.c            # Envoltura para /dev/ak-motor*
    sys/spiflash.c         # Lecturas desde MTD SPI NOR
  apps/
    audio/{playback,capture}.c  # Herramientas CLI derivadas del IPC
    video/dump.c                 # Dumpeo de la ring buffer H.264
    isp/dump_conf.c              # Inspector de configuraciones ISP
    motor/test.c                 # Smoke test pan/tilt
    storage/spiflash_info.c      # Lectura de geometría NOR
    testing/main.c               # Harness de pruebas heredado
```

El árbol mantiene al kernel (`linux-3.4.35/`) intacto.

## Herramientas generadas

### Audio

La implementación de `ak_audio_open_playback()` y `ak_audio_open_capture()` reproduce la secuencia de `ioctl()` observada en `decompiled/ipc_untouched.c`. Se encapsula en `src/lib/audio/akpcm_device.c` para compartir lógica entre las herramientas:

* `ak3918_audio_play` (`src/apps/audio/playback.c`): reproduce PCM S16LE desde disco.
* `ak3918_audio_capture` (`src/apps/audio/capture.c`): captura audio hacia un archivo, con límite opcional.

### Video

`src/lib/video/uio.c` formaliza la máquina de estados que descubrimos en la versión decompilada del *ipc*. La aplicación `ak3918_video_dump` reutiliza esos helpers para esperar interrupciones, programar `UIO_SET_TRIPLE` y vaciar el ring del codificador.

### ISP

El parser de `.conf` vive en `src/lib/isp/parse_conf.c` y se consume desde `ak3918_dump_isp_conf`, manteniendo la estructura de "packs" descrita en la documentación original.

## Registro y trazas

Las trazas históricas viven ahora en `data/logs/`, reclasificadas por dominio:

```
data/logs/
  audio/   # /dev/akpcm, PCM y ruteo
  ipc/     # strace, trazas del binario propietario
  isp/     # dumps de configuración del sensor/ISP
  system/  # logs generales (ioctl, shadow, init)
  video/   # camtrace, uio0, trace_replayer, etc.
```

## Compilación

El `Makefile` produce una librería estática `libak3918.a` con todos los módulos compartidos y ahora siete binarios en `build/bin/`:

* `ak3918_video_dump`
* `ak3918_audio_play`
* `ak3918_audio_capture`
* `ak3918_dump_isp_conf`
* `ak3918_testing`
* `ak3918_motor_test`
* `ak3918_spiflash_info`

Están pensados para GCC 4.8.5 y uClibc 0.9.33.2 en ARM32, según el entorno indicado.

## Siguientes pasos sugeridos

1. Portar `src/apps/testing/main.c` a las nuevas APIs para eliminar dependencias directas del código legaciado.
2. Documentar el mapa de registros del codificador H.264 conforme se valide en hardware.
3. Automatizar la generación de paquetes para `/mnt/bin` y `/mnt/disc1`.

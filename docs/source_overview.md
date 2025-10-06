# Mapa de código fuente

Este documento resume la organización actual del árbol de código del proyecto `AK3918EV200_GWELL_V1`. Está pensado como un punto de entrada rápido para localizar bibliotecas reutilizables, aplicaciones de prueba y artefactos auxiliares al trabajar en el SoC Anyka AK3918EV200.

## Directorios de nivel superior

| Directorio | Descripción |
|------------|-------------|
| `data/` | Artefactos capturados de la plataforma: `isp_blobs/` (payloads ISP) y `logs/` (trazas clasificadas por dominio). |
| `conf/` | Colección de perfiles ISP (`*.conf`) para sensores compatibles; se consumen mediante el parser genérico y el agente de configuración del ISP. |
| `docs/` | Documentación técnica: guías de arquitectura, runbooks y, ahora, este mapa de código. |
| `include/` | Interfaces públicas propias (`include/ak3918/*.h`) que describen los contratos para audio, video, ISP, ION y utilidades compartidas. |
| `src/` | Implementación principal, separada en bibliotecas (`src/lib`) y aplicaciones/ejemplos (`src/apps`). |
| `ld_preload/` | Preload mantenido (`ipc_tracer.c`) para instrumentar el binario propietario y extraer secuencias de ioctls. |
| `tools/` | Utilidades de apoyo (por ejemplo, `type_extractor.py`) usadas durante el análisis del SDK y de binarios propietarios. |
| `vendor/` | Referencias descompiladas de módulos y bibliotecas originales; sirven para contrastar comportamientos y parámetros. |
| `downloaded/`, `patches/`, `toolchain/` | Material auxiliar: PDFs originales, parches de kernel y definiciones de toolchain. |

## Bibliotecas compartidas (`src/lib`)

Las subbibliotecas encapsulan el acceso a cada subsistema del SoC. Todas exponen cabeceras bajo `include/ak3918/`.

- `audio/akpcm_device.c`: Implementa la capa de control para los dispositivos PCM (`/dev/akpcm_cdev0/1`), incluyendo las secuencias de `ioctl()` reconstruidas a partir de las trazas del firmware.【F:src/lib/audio/akpcm_device.c†L1-L56】
- `isp/`: Contiene la lógica para orquestar el ISP.
  - `parse_conf.c`: Parser de packs/subpacks ISP que separa encabezados y carga útil.【F:src/lib/isp/parse_conf.c†L1-L63】
  - `isp_device.c`: Abstracciones sobre `/dev/isp_char` y llamadas `AK_ISP_*`.
  - `akispsdk_shim.c`: Capa de adaptación para enlazar con el SDK propietario cuando no está disponible el binario original.
- `sys/ion.c`: Helper para asignaciones DMA a través de `/dev/ion`, usado por video y audio.【F:src/lib/sys/ion.c†L1-L52】
- `util/`: Utilidades de propósito general (gestión de blobs binarios, helpers misceláneos) compartidas por los agentes.【F:src/lib/util/blob.c†L1-L54】
- `video/uio.c`: Manejo del encoder H.264 expuesto vía `UIO`, incluyendo la espera por interrupciones y el drenaje del ring buffer.【F:src/lib/video/uio.c†L1-L64】

## Aplicaciones y ejemplos (`src/apps`)

Los binarios de demostración se organizan por dominio y ejercitan las bibliotecas anteriores.

- `audio/`
  - `capture.c`: Configura el dispositivo de captura y ejecuta un bucle de adquisición controlado; útil para validar la ruta del micrófono.【F:src/apps/audio/capture.c†L1-L62】
  - `playback.c`: Inicializa la salida PCM y reproduce buffers de prueba para verificar la ruta de altavoz.【F:src/apps/audio/playback.c†L1-L60】
- `isp/dump_conf.c`: Utiliza el parser para inspeccionar y volcar packs/subpacks ISP, ayudando a depurar nuevos perfiles de sensor.【F:src/apps/isp/dump_conf.c†L1-L64】
- `video/dump.c`: Abre el encoder (`/dev/uio0`), espera IRQs y persiste unidades H.264 para análisis offline.【F:src/apps/video/dump.c†L1-L66】
- `testing/main.c`: Programa de bring-up completo que respeta el orden crítico de apertura de dispositivos y mantiene activo el pipeline V4L2.【F:src/apps/testing/main.c†L1-L54】

## Encabezados públicos (`include/ak3918`)

Las cabeceras describen estructuras de datos y firmas compartidas:

- `audio.h`: Tipos `ak_audio_device`, formatos soportados y prototipos para inicialización/captura/reproducción.
- `video.h`: Interfaces del agente UIO y helpers para flujos H.264.
- `isp.h` y `isp_conf.h`: API para aplicar configuraciones ISP y constantes de packs/subpacks.
- `ion.h`: Funciones para reservar/liberar buffers DMA.
- `blob.h` y `util.h`: utilidades genéricas (gestión de blobs, logging, helpers de memoria).

## Recursos adicionales

- `docs/HW-VENC-*.md` y `docs/video_dump_runbook.md` contienen información práctica sobre el encoder y los flujos de trabajo de depuración.
- Los volcados en `data/isp_blobs/` y los binarios en `vendor/decompiled/` permiten cotejar parámetros al adaptar nuevos sensores o funcionalidades.

> **Nota:** Conforme se agreguen nuevos agentes o herramientas, extiende este documento para mantener una visión global coherente del árbol de código.

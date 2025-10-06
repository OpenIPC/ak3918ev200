# AK3918EV200 ISP Reverse Engineering

This repository contains research, tools, and experiments around the Image Signal Processor (ISP) used in AK3918EV200-based IP cameras.  
The project documents the initialization sequence, driver interactions, and ioctl payloads extracted from the vendor firmware and SDK.

## Contents

- **Decompiled SDK analysis**  
  Mapping of ioctl request codes (`NR`, `type`, `size`) to ISP functions with offsets and payload structure references.

- **Binary payload dumps**  
  Real captured blobs under `data/isp_blobs/` for calls like:
  - `Ak_ISP_Set_User_Params`
  - `AK_ISP_set_3d_nr_ref_attr`

- **C tools**  
  - Parser for `.conf` ISP configuration files.
  - Replay tools to reproduce ioctl sequences from logs.
  - `LD_PRELOAD` hooks to intercept, dump, and inject ISP payloads.
  - `testing`: standalone bring-up harness that opens `/dev/{ion, isp_char, video0, akpcm_cdev0, akpcm_cdev1}` and exercises the
    camera/audio setup used for early debugging on target hardware.
  - `ak3918_video_dump`: minimal encoder bring-up that reproduces the vendor
    pipeline to save Annex-B streams. See `docs/video_dump_runbook.md` for the
    step-by-step sequence recovered from the decompiled firmware.
  - SDK helpers for `/dev/akgpio`, `/dev/uio0`, and audio codecs (see
    `include/ak3918/*.h`).
  - Smoke test tools: `ak3918_motor_test` (pan/tilt via `/dev/ak-motorN`) and
    `ak3918_spiflash_info` (query / dump SPI NOR geometry).

- **Python scripts**  
  Helpers to extract symbol-to-offset mappings from decompiled sources and build tables associating `case id` → `symbol + offset`.

- **Logs and traces**  
  Archived under `data/logs/` for reference (`jump_tap4.log`, `akisp_tap-completo.log`, etc.); useful to replicate real hardware behaviour.

- **Documentation**
  - `docs/sdk/ak3918_sdk_notes.md` – consolidated notes on ioctls, GPIO
    controller, audio codec, motors, Wi-Fi, and other peripherals recovered from
    the BSP and board manuals.
  - `docs/OpenIPC_AK3918_programming.md` – recommended workflow to build an
    OpenIPC-friendly firmware image around these primitives.
  - `docs/reference/` – English translations and structured summaries of the
    vendor PDFs (hardware specs, board manuals, multimedia libraries, tooling)
    with action items for the OpenIPC AK3918 runtime.
  - `docs/reference/isp/isp_block_catalog.md` – per-block breakdown of the ISP
    configuration packs (`0x00`…`0x1C`) with offsets and expected payload sizes.

## Goals

- Document the closed-source ISP API and its configuration workflow.  
- Provide reproducible examples to initialize the video pipeline, configure noise reduction, histograms, AWB, exposure, etc.  
- Serve as a base for further research in embedded security, custom firmware, and video processing.

## Disclaimer

This project is for **educational and research purposes only**.  
It is not affiliated with the vendor, and comes with **no warranty**.  
Use responsibly.

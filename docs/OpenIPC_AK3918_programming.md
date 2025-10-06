# OpenIPC / AK3918EV200 Programming Guide

This document distils what we know about the AK3918EV200 platform so far and
outlines a path to ship an OpenIPC-flavoured firmware targeting generic
AK3918EV200 boards (GWELL V1 and relatives).

## 1. Platform Overview

| Block | Notes |
| --- | --- |
| CPU | ARM926EJ-S @ 600 MHz (default). 16 KiB I/D cache. |
| Memory | 64 MiB DDR2 stacked on-die. LPDDR interface is fixed; budget your heap carefully. |
| Video in | Parallel sensor interface exposed via `/dev/video0` (V4L2). Requires ISP bring-up before streaming. |
| ISP | `/dev/isp_char`, `AK_ISP_*` ioctls. Needs sensor `.conf` pack replay. |
| Encoder | `/dev/uio0` backed by `uio_video_codec`. IRQ + ring buffer in L2 memory. |
| Audio | `/dev/akpcm_cdev0/1`. Proprietary codec ioctls (see `docs/sdk/ak3918_sdk_notes.md`). |
| DMA / Buffers | `/dev/ion` provider. Use for ISP/encoder shared buffers. |
| GPIO | `/dev/akgpio` misc device. Controls LEDs, IR-cut, motors, Wi-Fi power, sensors. |
| Storage | AKMCI SDIO controller (mmc0); SPI NOR via on-chip controller. |
| Connectivity | Broadcom `bcmdhd` Wi-Fi, USB OTG, UART/debug UART. |
| Power mgmt | Android-style wake locks + autosleep (`/sys/power/*`). |

## 2. Kernel Expectations

The Anyka BSP is a 3.4.35 tree with heavy vendor patches. For an OpenIPC port you
have two options:

1. **Carry the vendor kernel** – easiest short term. Apply patches in `patches/` and
   build with their defconfig (`aimer39_ak3918_defconfig`).
2. **Forward-port drivers** – long-term goal. Identify the minimum set of drivers
   required: ISP (`plat-anyka/ak39_isp.c`), UIO video codec, `akgpios`, `akpcm`,
   `ak_motor`, `akmci`, `bcmdhd`.

For OpenIPC we currently stick to option #1 while documenting the interfaces so
we can eventually upstream replacements.

### Device Nodes

- `/dev/isp_char` – ISP control plane.
- `/dev/video0` – V4L2 capture (YUV frames, must stay streaming).
- `/dev/uio0` – H.264 encoder queue/IRQ gate.
- `/dev/ion` – buffer allocator.
- `/dev/akpcm_cdev0` (playback) / `/dev/akpcm_cdev1` (capture) – PCM I/O.
- `/dev/akgpio` – GPIO control + IRQ wait.
- `/dev/ak-motor?` – stepper control for pan/tilt (board-dependent).
- `/dev/akadc` – SAR ADC (LDR, battery, etc.).
- `/dev/mmcblk0` – SD card.
- `/dev/mtd*` / `/dev/spidev0.0` – SPI NOR (calibration + firmware storage).
- `/dev/ttyS*` – standard UART; `/dev/ttyGU0` for GPIO-bitbang variant.

## 3. Userspace Stack Blueprint

1. **Supervisor** (`init` replacement)
   - Mount persistent storage (`/mnt/disc1`).
   - Spawn device bring-up agent (see `AGENTS.md`).
   - Kick watchdog if needed (`drivers/watchdog/ak39_wdt.c`).

2. **Device Bring-Up Agent**
   - Open `/dev/video0` → `/dev/isp_char` → `/dev/uio0` → `/dev/ion`.
   - Load ISP packs using `ak_isp_sdk_init()` + `isp_apply_conf()`. Sensor-specific
     `.conf` comes from `/mnt/bin/conf/<sensor>/packX`. Hook config reload to
     persistent JSON to support remote updates.
   - Pre-allocate ION buffers for V4L2 and encoder rings.

3. **V4L2 Agent**
   - Keep a circular queue (3–4 buffers). Use `VIDIOC_REQBUFS` + `VIDIOC_QBUF`
     loop. We do not store RAW frames on disk—just service the ISP.

4. **Encoder Agent**
   - Use `ak_uio_wait_irq()` to block for frames. Read ring descriptors from the
     UIO MMIO window (reverse engineering in progress; align with
     `docs/video_dump_runbook.md`).
   - Write out Annex-B slices or feed a muxer.
   - Call `ak_uio_sysreg_write()` when registers need poking (e.g. bit rate).

5. **Audio Agents**
   - Playback: configure via `ak_audio_open_playback()`; feed PCM (16 kHz stereo).
   - Capture: `ak_audio_capture_read()` yields near/far audio; add Speex/Opus as
     required. AEC bits exist but can be disabled for low-power builds.

6. **GPIO / Sensors**
   - Wrap leds/IR/motor limit switches via `ak_gpio_*` helpers.
   - Use `/dev/akadc` for LDR (set thresholds to toggle IR-cut automatically).
   - Wi-Fi power cycle through GPIOs defined in board pdata.

7. **Motor Control** (optional)
   - Use `ak_motor_*` helpers (see `src/lib/sys/motor.c`) to drive `/dev/ak-motorN`.
     Handle `AK_MOTOR_EVENT_HIT` to stop before ramming limit switches.

8. **Networking**
   - Load `bcmdhd` firmware, bring up `wlan0` with wpa_supplicant/hostapd.
   - For wired Ethernet (if present) use standard MAC driver.

## 4. Build & Packaging

- Cross-compiler: vendor uses `arm-shivaya-linux-uclibcgnueabi-gcc`. Musl or
  glibc cross toolchains also work if you rebuild busybox + userspace.
- Root filesystem: BusyBox + dropbear + our agents. Mount `/mnt/disc1` (SD card)
  for configs/logs.
- Firmware layout (OpenIPC style):
  - Kernel (`uImage`) from vendor tree.
  - Rootfs squashfs/ubifs with our binaries under `/usr/bin/`.
  - Overlay `/etc` on persistent partition (`overlayfs: lower = squashfs, upper = /mnt/disc1/etc, work = /tmp/overlay-work`).
  - Grab a wake lock (`echo openipc_main > /sys/power/wake_lock`) during boot and
    release once services settle; revisit autosleep when suspend/resume is proven stable.

## 5. Development Checklist

- [ ] Confirm sensor `.conf` pack loads without ISP errors (use UART console).
- [ ] Verify `/dev/uio0` IRQ counter increments (see `uio0_dump.log`).
- [ ] Capture short H.264 clip via encoder agent.
- [ ] Record 5 s audio clip from `/dev/akpcm_cdev1`.
- [ ] Toggle IR-cut relay (`ak_gpio_set_level()`), ensure limit switches report.
- [ ] Run Wi-Fi connect/disconnect cycle with `wpa_supplicant`.
- [ ] Exercise motors (if populated) and ensure limit IRQs fire.
- [ ] Read board serial from `/sys/kernel/serial_number/sn` and surface in logs.
- [ ] Mount overlayfs for `/etc` and validate persistence across reboot.
- [ ] Validate SD card hot-plug via AKMCI (GPIO card-detect low-level IRQ).

## 6. Further Reading

- `docs/sdk/ak3918_sdk_notes.md` – ioctl tables, register references, and pin
  assignments distilled from the BSP.
- `AGENTS.md` – living map of the runtime components and their responsibilities.
- `docs/video_dump_runbook.md` – chronological bring-up of the encoder from the
  vendor firmware trace.
- `downloaded/` PDFs – schematics, board user guides, camera module notes.

Keep iterating: every time we reverse an ioctl, capture it in the SDK headers
and update the docs so the rest of the OpenIPC community can reuse the work.

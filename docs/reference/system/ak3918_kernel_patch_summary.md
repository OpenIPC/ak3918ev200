# AK3918 Linux 3.4.35 Patch Stack Overview

This note captures the effect of applying the vendor patch series (`001-ak3918-kernel-3.4.35.patch`, `002-gcc8_err_encountered.patch`, `003-overlayfs-v13-3.4-rc7.patch`) on vanilla Linux 3.4.35. Use it alongside `kernel_patched_filepaths.txt` and the extracted sources under `vendor/linux-3.4.35-ak3918-diff/` when cross-referencing driver behaviour with the user-space SDK.

## Patch 001 – Anyka AK39 platform enablement
- Adds the **`mach-ak39` platform** with board files for Aimer39 AK3916/AK3918 and the SDK reference design. Includes clock trees, reset/power domains, GPIO tables, PWM timers, cpufreq policies, and PM hooks.
- Introduces **`plat-anyka/` headers** that define register maps and ioctl contracts for ISP, GPIO, motor, sensor, ION and audio subsystems. These mirror the structures we expose through `include/ak3918/*.h` in the SDK.
- Brings in vendor **multimedia and peripheral drivers**:
  - ISP/video: `drivers/media/video/plat-anyka/{ak_camera.c, ak39_isp.c}` plus ISP interface headers.
  - Encoder: `drivers/uio/uio_video_codec.c` (with `AKUIO_*` ioctls) and the associated `/dev/uio0` sysfs glue.
  - Memory: `drivers/gpu/ion/plat-anyka/ak_ion.c` and `drivers/mmc/host/akmci.c` for DMABUF and SD/MMC access.
  - I/O devices: GPIO (`drivers/misc/akgpios.c`), motor (`drivers/misc/ak_motor.c`), watchdog, UART, RTC, SPI flash (`ak_spiflash`), ADC, keypad (`akgpio_keys`).
  - Audio: `sound/arm/ak_pcm.c`, `sound/arm/ak39_codec.c`, and `include/sound/ak_pcm.h` backing `/dev/akpcm_cdev{0,1}`.
  - Connectivity: Broadcom `bcmdhd` Wi-Fi stack and platform glue in `plat-anyka/wifi.h`.
- Merges **Android-oriented power management** (wake locks, autosleep, suspend time tracking) and updates documentation for the new sysfs attributes.
- Extends kernel subsystems (scheduler, cpufreq, mm, netfilter, tracing) to align with Anyka's Android BSP expectations.

## Patch 002 – GCC 8 compatibility
- Adjusts `arch/arm/include/asm/uaccess.h` to silence `-Werror=address-of-packed-member` seen when building the 3.4.35 tree with modern GCC (required for current cross-toolchains).

## Patch 003 – OverlayFS backport
- Imports the upstream OverlayFS v13 implementation (Kconfig, Makefile, core sources, documentation) enabling read/write overlay roots for the vendor rootfs layout.

## Artefacts generated during analysis
- `vendor/linux-3.4.35/` – patched kernel tree.
- `vendor/linux-3.4.35-vanilla/` – pristine unpack of Linux 3.4.35 for diffing.
- `vendor/linux-3.4.35-ak3918-diff/` – tree containing only files added or modified by the patches (layout preserved).
- `kernel_patched_filepaths.txt` – sorted list of every file touched by the patch stack.
- `kernel_patch_difflist.txt` – verbose comparison output (Spanish locale) from `diff -rq`.

Refer back to this note when validating that user-space components (e.g., `ak_uio_wait_irq`, GPIO SDK, motor agent) are consistent with the kernel interfaces.

## SDK / Documentation coverage check

| Area | Kernel component(s) | User-space coverage | Notes |
| --- | --- | --- | --- |
| Video encoder | `drivers/uio/uio_video_codec.c`, `include/linux/akuio_driver.h` | ✅ `include/ak3918/video.h`, `src/lib/video/uio.c`, `docs/HW-VENC-*`, `docs/sdk/ak3918_sdk_notes.md` | IOCTLs and IRQ flows mirrored in SDK; matches AGENTS encoder agent description. |
| ISP pipeline | `drivers/media/video/plat-anyka/ak39_isp.c`, `include/plat-anyka/isp_interface.h` | ✅ `include/ak3918/isp_interface.h`, `src/isp/*`, `docs/` ISP guides | Structs synced from kernel header; parser/apply agents documented. |
| ION / DMABUF | `drivers/gpu/ion/plat-anyka/ak_ion.c` | ✅ `include/ak3918/ion.h`, `src/lib/sys/ion.c`, bring-up docs | Userland allocator matches kernel ABI; documented in programming guide. |
| GPIO / keys | `drivers/misc/akgpios.c`, `drivers/input/keyboard/akgpio_keys.c` | ✅ `include/ak3918/gpio.h`, `src/lib/sys/gpio.c`, docs | Code + docs cover control + IRQ patterns; need runtime testing on hardware. |
| PCM audio | `sound/arm/ak_pcm.c`, `sound/arm/ak39_codec.c` | ✅ `src/lib/audio/akpcm_device.c`, audio sections in docs | Ioctl sequences reconstructed; awaiting configurable params. |
| Motor control | `drivers/misc/ak_motor.c`, `include/plat-anyka/ak_motor.h` | ✅ `include/ak3918/motor.h`, `src/lib/sys/motor.c`, `ak3918_motor_test` | Wrapper + docs cover ioctls/events; pending hardware validation. |
| Wi-Fi | `drivers/net/wireless/bcmdhd/*`, `include/plat-anyka/wifi.h` | ⚠️ Documented in guides, but no tooling to manage firmware/calibration in repo. | Capture deployment steps and provide scripts. |
| SPI flash / storage | `drivers/mtd/devices/ak_spiflash.c`, `drivers/mmc/host/akmci.c` | ✅ `include/ak3918/spiflash.h`, `src/lib/sys/spiflash.c`, `ak3918_spiflash_info` | Provides geometry/dump helpers; write support remains TODO. |
| Serial number / manufacturing | `drivers/misc/ak_sn.c` | ✅ Documented in `docs/sdk/ak3918_sdk_notes.md` and programming guide. | Cache `/sys/kernel/serial_number/sn` at boot for telemetry. |
| Power management | `kernel/power/wakelock.c`, autosleep sysfs updates | ✅ Guidance in `docs/sdk/ak3918_sdk_notes.md` + supervisor checklist. | Review suspend/resume once hardware tests available. |
| OverlayFS | `fs/overlayfs/*` (patch 003) | ✅ Mount recipe + best practices documented in `docs/sdk/ak3918_sdk_notes.md`. | Integrate into init scripts when assembling images. |
| FIQ debugger | `arch/arm/common/fiq_debugger*` | ❌ Uncovered. | Consider documenting how to enable for field debugging. |

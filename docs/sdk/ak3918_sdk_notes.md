# AK3918 SDK Notes

This page collects the runtime-facing interfaces we have derived from the Anyka
kernel drops and datasheets. Keep it close when touching the ISP or encoder
agents.

## UIO Video Codec Driver

The vendor `uio_video_codec` driver (see kernel patch `001-ak3918-kernel-3.4.35`) exposes
the following ioctl codes; the wrappers live in `include/ak3918/video.h` and
`src/lib/video/uio.c`:

| API | Description | Notes |
| --- | --- | --- |
| `AK_UIO_SYSREG_WRITE` | Programs one MMIO register through the UIO front-end. | Use `ak_uio_sysreg_write()` with `struct ak_uio_sysreg_write { phys, value, mask; }`. |
| `AK_UIO_WAIT_IRQ_DRIVER` | Blocks until the codec raises an IRQ (newer vendor ABI). | `ak_uio_wait_irq()` now tries legacy `0x80045565`, falls back to this code, and finally to `UIO_WAIT_IRQ`/`read()`. |
| `AK_UIO_INVALIDATE_L2CACHE` / `AK_UIO_INVALIDATE_L1CACHE` | Flush L2/L1 cache lines in hardware. | Wrapped by `ak_uio_invalidate_l2cache()` / `ak_uio_invalidate_l1cache()`. |

**Usage sketch**

```c
int fd = open("/dev/uio0", O_RDWR | O_CLOEXEC);
struct ak_uio_sysreg_write wr = {
    .phys = 0x20180000 + 0x104,
    .value = 0x1,
    .mask = 0x1,
};
ak_uio_sysreg_write(fd, &wr);

enum ak_uio_irq_mode mode = AK_UIO_IRQ_MODE_AK;
uint32_t irqcnt;
ak_uio_wait_irq(fd, &mode, &irqcnt, NULL);
ak_uio_ack_read_mode(fd);
```

Fallback logic prints explicit messages when an ioctl is missing so we can
distinguish between kernels that ship the new driver and the plain UIO core.

## ISP PC-Tool Interface

The Anyka ISP tooling drives `/dev/isp_char` using vendor structures defined in
`include/plat-anyka/isp_interface.h`. We mirrored the definitions into
`include/ak3918/isp_interface.h`; notable blocks:

- `struct isp_channel2_info`, `struct isp_mode_info`: describe secondary channel
  routing and the active `enum isp_working_mode` (JPEG/YUV/RGB, bypass variants).
- `struct isp_osd_info`, `struct isp_occlusion_info`, `struct isp_zoom_info`: OSD
  overlays, privacy masks, and zoom/cut rectangles (with comments matching the
  register table offsets documented by Anyka).
- ISP tuning entries such as `struct isp_lens_correct`, `struct isp_auto_white_balance`,
  `struct isp_gamma_calculate`, `struct isp_special_effect` mirror the payloads
  we parse from vendor `.conf` files. Keep these around when decoding new sensor
  packs or when generating synthetic payloads.

Every structure carries hints about the corresponding hardware register window
(`reg table 0x20/0x24/0x28` etc.); these annotations came straight from the
vendor header and are useful when cross-checking LD_PRELOAD dumps against MMIO
captures.

### ISP configuration packs (`conf/*.conf`)

- Binary layout is now summarised in [docs/reference/tools/isp_conf_format.md](../reference/tools/isp_conf_format.md).
- `parse_isp_conf.c` scans for `{uint16_t id, uint16_t size}` headers, enforcing
  sequential IDs (`0x00`–`0x17`) plus a terminating `0x1B/0x1C` sensor blob.
- `isp_device.c` maps each ID to the corresponding `ak_isp_set_*` call; refer to
  the ISP block catalogue when adding sensors or tweaking offsets.
- All vendor blobs we captured contain two packs (likely day/night variants).
  Make sure the supervisor selects the correct pack for lighting conditions.

## Audio Codec (`/dev/akpcm_cdev0`, `/dev/akpcm_cdev1`)

The ALSA wrapper in `src/lib/audio/akpcm_device.c` was reconstructed from the
vendor binary. Key private ioctls:

| Direction | Code | Purpose |
| --- | --- | --- |
| Playback | `0x40045081` | Enable DAC output path |
| Playback | `0x40045030` | Set codec mode (5 → prep, 4 → ready) |
| Playback | `0x40045010` | Select source (4 = I²S) |
| Playback | `0x40045070` | Enable clocks |
| Playback | `0x401c50f2` / `0x801c50f2` | Commit / fetch 7-word parameter blob |
| Capture  | `0x40045030` | Configure ADC path (mode 7) |
| Capture  | `0x40045088` | Enable ADC block |
| Capture  | `0x804050f0` | Sync shadow registers |
| Capture  | `0x800450e8` | Query available bytes |
| Both     | `0x50e1`      | Port sync / kick DMA (use buffer from `0x804050f0`) |
| Capture  | `0x80045085` / `0x40045086` | Read & acknowledge ring position (per buffer) |

Typical blob layout (per traces):

```
param[0] = sample_rate (Hz)
param[1] = channels
param[2] = bits_per_sample
param[3] = chunk_bytes (period size)
param[4] = frame_count (playback 12, capture 16)
param[5] = chunk_bytes mirror
param[6] = reserved 0
```

Our helper functions (`ak_audio_open_playback/capture()`) fill the standard
defaults (16-bit @ 16 kHz). After each parameter sync (`0x804050f0`) we keep the
64-byte shadow buffer and reuse it when issuing `0x50e1`; the driver expects the
pointer to remain valid or it silently stalls. For capture, remember to fetch
the ring position (`0x80045085`) before each read and acknowledge it with
`0x40045086` after consuming the buffer. Adjust the chunk size when enabling AEC
support—the vendor driver expects 512-byte periods for both playback and
capture.

## GPIO (`/dev/akgpio`)

The misc-driver (`drivers/misc/akgpios.c`) exposes ioctls defined in
`include/ak3918/gpio.h`:

| ioctl | Description |
| --- | --- |
| `AK_GPIO_GET_NUM` | Return number of exported GPIOs. |
| `AK_GPIO_GET_AVAILABLE` | Dump table of free pins (array of `unsigned int`). |
| `AK_GPIO_SET_FUNC` | Apply direction/pull/value using `struct ak_gpio_info`. |
| `AK_GPIO_SET_LEVEL` | Change output level (reuse `struct ak_gpio_info`). |
| `AK_GPIO_GET_LEVEL` | Read current input level into `struct ak_gpio_info`. |
| `AK_GPIO_SET_IRQ` | Configure interrupt (level high/low) for given pin. |
| `AK_GPIO_LISTEN_IRQ` | Block until the IRQ fires (internal semaphore). |
| `AK_GPIO_DELETE_IRQ` | Release handler and free IRQ line. |

**Quirks**

- Interrupt polarity flips automatically inside the handler to emulate edge
  triggers; re-arm by calling `ak_gpio_wait_irq()` again.
- Group-level writes exist in the kernel (`SET_GROUP_GPIO_LEVEL`) but the driver
  dereferences a user pointer directly. Stick to single-pin updates for now.

## Motor Driver (`plat-anyka/ak_motor`)

The board files register two stepper assemblies (`ak-motor0`, `ak-motor1`).
Typical wiring (motor 0, see `mach-aimer39_ak3918.c`):

- Phases A/B/C/D → GPIO37/38/39/40 (push-pull outputs).
- Limit switches `gpio_hit[0/1]` → GPIO62/63 (input, IRQ-type low → high toggle).
- Default angular speed 100 °/s (`angular_speed` platform datum).

### Device model

Each motor appears as a misc device `/dev/ak-motorN`. The vendor header
(`include/plat-anyka/ak_motor.h`) defines the ABI:

| ioctl | Meaning | Notes |
| --- | --- | --- |
| `AK_MOTOR_SET_ANG_SPEED` | Set angular velocity (°/s, 1–16) | Driver clamps outside range. |
| `AK_MOTOR_GET_ANG_SPEED` | Read current target speed | Returns integer via pointer. |
| `AK_MOTOR_TURN_CLKWISE` / `AK_MOTOR_TURN_ANTICLKWISE` | Start motion for requested angle (degrees) | Driver converts to step count (`angle * 360/64`). |
| `AK_MOTOR_TURN_STOP` | Stop immediately | Cancels timers, keeps current position. |
| `AK_MOTOR_GET_HIT_STATUS` | Read limit switch bitmap | Bits `AK_MOTOR_HITTING_LEFT/RIGHT`. |

`read(2)` (or `poll(2)` + `read`) returns `struct notify_data { int hit_num; int event; int remain_angle; }`
whenever a limit switch toggles or the motor finishes a run. Events map to
`AK_MOTOR_EVENT_{HIT,UNHIT,STOP}`.

Our new helpers in `src/lib/sys/motor.c` wrap these idioms:

```c
struct ak_motor *m = ak_motor_open(0);              // /dev/ak-motor0
ak_motor_set_speed(m, 8);                           // 8 deg/s
ak_motor_move(m, AK_MOTOR_DIR_CW, 45);              // turn 45°
struct ak_motor_event ev;
while (ak_motor_wait_event(m, &ev, 500) == 0) {
    // react to limit switch or completion
}
ak_motor_close(m);
```

Call `ak_motor_wait_event()` periodically even when you expect no hits—the
driver re-arms GPIO polarity after each interrupt inside the event path.

## Storage / SDIO (AKMCI)

`include/plat-anyka/akmci.h` documents the MMC controller registers. Highlights:

- Clock register offsets (`MCI_CLK_REG`, `MCI_ARGUMENT_REG`, …) and bit masks
  (`MCI_CLK_ENABLE`, `MCI_CPSM_RESPONSE`, etc.).
- L2 FIFO integration via base `0x2002c000`, DMA control register at 0x03c.
- FIFO size 4 bytes, 2 L2 buffers defined (`MCI_L2FIFO_NUM = 2`).

Use this when reverse engineering `/dev/mmcblk*` performance issues or when
building a custom SD boot pipeline.

## SPI Flash (`ak_spiflash` / MTD)

The SPI NOR controller registers as an MTD device (`drivers/mtd/devices/ak_spiflash.c`).
Kernel boards wire it on SPI bus 1, CS0, and expose partitions through
`/dev/mtd*` and `/dev/mtdblock*`. Supported operations (from the driver):

- JEDEC identification (`get_device_id`), block erases (`_erase`), reads and
  writes with bounce buffers for DMA alignment.
- Quad/Dual I/O enablement via `ak_spiflash_cfg_quad_mode()` when the chip
  advertises the capability.
- Optional manufacturing metadata via `T_SPI_BURN_INIT_INFO` inside the driver.

In userspace we now provide `ak_spiflash_ident()` and `ak_spiflash_read()` wrappers
backed by `/dev/mtdX` + `MEMGETINFO` ioctls (see `src/lib/sys/spiflash.c`). Use
them to fetch calibration blobs (sensor OTP, motor homing tables) stored in the
first few sectors and to validate firmware flashing workflows before writing to
NOR.

## Serial Number (`serial_number/sn`)

`drivers/misc/ak_sn.c` exports the production serial as a sysfs attribute:

```
/sys/kernel/serial_number/sn → ASCII string (64 B max)
```

The driver reads `SERADDR` from the factory ASA (Anyka Secure Area) region every
time the node is accessed. Our supervisor should cache it on startup and expose
the value through telemetry/logs for traceability. If the file is missing the
attribute prints an empty string; treat this as a production fault.

## Power Management (Wake Locks & Autosleep)

Patch `001-ak3918-kernel-3.4.35` brings in Android-style power management:

- `/sys/power/wake_lock` / `/sys/power/wake_unlock` → create and toggle wakeup
  sources from userspace (strings without whitespace). Optional timeout argument
  (nanoseconds) auto clears the lock.
- `/sys/power/autosleep` → write a sleep state (`mem`, `standby`, …) to enable
  opportunistic suspend when no wake locks are held; write `off` to disable.
- `/sys/power/wakeup_count`, `/sys/devices/.../power/wakeup_*` counters track
  aborts, expirations, and blocked transitions.

For now the supervisor should:

1. Acquire a wake lock named `openipc_main` during critical sections (boot,
   recording start/stop) and release it once the pipeline is stable.
2. Export metrics for `wakeup_abort_count`/`wakeup_expire_count` so we can spot
   sensors that prevent suspend.
3. Leave `autosleep` off until we verify ISP/encoder recovery after resume.

Document these steps in deployment guides to avoid unnecessary overnight power
drain on battery-backed setups.

## OverlayFS for Persistent Config

OverlayFS v13 is backported (patch `003-overlayfs-v13-3.4-rc7`). Mount syntax:

```
mount -t overlayfs overlayfs \
    -olowerdir=/mnt/romfs/etc,upperdir=/mnt/disc1/etc \
    /etc
```

Recommendations for OpenIPC builds:

- Keep writable overlays (`upperdir`) on `/mnt/disc1` (SD/flash) and point
  `workdir` to a small tmpfs (`/tmp/overlay-work`).
- Place configuration seeds in the read-only squashfs (`lowerdir`) and let field
  upgrades edit only the upper layer.
- After switching, update `pivot_root` scripts to bind-mount `/mnt/disc1/logs`
  so log rotation keeps working.

We track overlay usage in the supervisor roadmap; mark nodes in `fstab`/initrd
accordingly when assembling firmware images.

## Wireless (Broadcom BCM43362 – `bcmdhd`)

The BSP ships Broadcom’s `bcmdhd` Android driver. Board data (`plat-anyka/wifi.h`)
configures:

- SDIO interface via AKMCI controller, IRQ mapped through GPIO179 (per board
  file).
- Power and reset lines tied to board-specific GPIOs (check
  `ak39_wifi_sdmmc_carddetect` platform data in `mach-aimer39_ak3916.c`).
- Firmware/CLM blobs expected under `/lib/firmware/bcmdhd/`.

Our userspace should treat Wi-Fi as a standard `wlan0` once the kernel module
loads; no bespoke ioctls beyond cfg80211.

## Serial & Debug UART

`drivers/misc/gpio_uart.c` implements a bit-banged UART using GPIOs and PWM
timer 2. Default wiring (from board file):

- TX: configurable via `guart.tx_pin` (default board uses GPIOXX, see
  `struct gpio_uart guart`).
- Clock derived from `TIMER_CLOCK / baud - correction`.
- Supports 8N1 framing; flow control disabled by default.

Use this as last-resort console if the on-die UART is unavailable; the driver
exposes a character device (commonly `/dev/ttyGU0`).

## Sensors, LEDs, and Aux Peripherals

From the platform file and PDFs:

- **LEDs** – `drivers/leds/leds-gpio` with entries for status, IR-cut, etc.
  Active levels often inverted (see `active_level` logic in the driver); refer
  to the board data for exact GPIO numbers.
- **LDR / CDS light sensor** – wired to SAR ADC channel (`/dev/akadc`). The
  vendor stack polls it to toggle IR-cut and fill light. Configure conversion via
  the ADC driver (`drivers/iio/adc/ak_saradc.c`).
- **IR-cut / Fill light** – controlled by dedicated GPIO pairs in the motor/LED
  platform data. Use `ak_gpio_set_level()` helpers.
- **I²C sensors** – the board enables bit-banged I²C via GPIO-based controller
  (`i2c-gpio`): see `i2c_gpios[]` in the board file (SCL/SDA pins). Sensors like
  OV9712/GC0308 hang off `i2c-0`.

Cross-check the schematics (`downloaded/Aimer39_*`) for voltage/pin mappings
before driving additional accessories.

## Hardware & Programming References

Relevant vendor manuals are stored under `downloaded/` (converted with
`pdftotext` when we need quick grepping). Key takeaways so far:

- **AK3918 Specification (Rev. 0.5.0)** – documents the ARM926EJ-S core with
  16KB+16KB caches, stacked 64 MB DDR2, hardware H.264/MJPEG encoders capable of
  720p@30 fps, multi-stream output (H.264/H.264, H.264/MJPEG, MJPEG/MJPEG) and
  bitrate range 10 kbps–20 Mbps. Power rails and DDR2 routing details sit around
  the 2.6 VDD sections.
- **AK3918 Programmer’s Guide (Rev. 0.5.0)** – covers the multimedia pipeline,
  sensor bring-up sequence and BSP expectations (ISP initialization before VENC,
  reliance on stacked DDR bandwidth, and cache maintenance requirements before
  handing buffers to hardware codecs).
- **AK39 视频驱动库接口说明** – describes the legacy userspace ISP/VENC API (in
  Chinese). It matches the ioctl naming we expose through `akispsdk_shim.c` and
  is indispensable when reverse engineering obscure subpack IDs.
- **Aimer39 board manuals** – wiring diagrams for LEDs, motors, LDR, Wi-Fi and
  daughter boards. Start with `downloaded/Aimer39_V1平台产品板使用说明_V1.1.0.pdf` and
  `downloaded/Aimer39_OV9712_camera_V1.1.0.pdf` for camera-specific notes.

Keep these PDFs handy; when in doubt, convert them (`pdftotext downloaded/<file>.pdf -`)
and search for register names or ioctl numbers before touching the SDK.

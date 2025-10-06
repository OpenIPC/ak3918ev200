# Linux Kernel Configuration & Modification Notes

Source: `Linux 平台内核配置及修改手册.pdf`

## English summary
Detailed manual for configuring and extending Anyka's Linux kernel (AK37/AK39 family). Covers menuconfig options, driver locations, and modification guides for major peripherals.

## Key topics
- **Defconfig setup**: Chip-level and board-level options; explains how to select AK37/AK39 board profiles and pass boot arguments.
- **Driver locations**: Lists directories for NAND, MMC/SD, USB OTG, Wi-Fi, I²C, CAMERA, PMEM, UIO, touchscreen, keypad, GPIO, battery monitoring, RTC, LCD, audio, power management, cpufreq.
- **GPIO API**: Structures and ioctl usage for kernel GPIO library (consistent with `/dev/akgpio`).
- **Driver extension**: Step-by-step modifications for I²C bus, PWM backlight, SD frequency tuning, USB host, camera power pins, keypad matrix, ADC keys, LCD addition, audio routing, NAND timings, UART debug configuration.

## OpenIPC integration
1. Map kernel paths to our `vendor/` patches to ensure we track driver diffs.
2. Reconcile GPIO ioctl descriptions with our SDK wrappers (`src/lib/sys/gpio.c`) and consider adding runtime checks for buffer length as suggested in TODO.
3. Use the documented driver extension process to inform community contributions (e.g., adding new sensors or Wi-Fi modules).
4. Update build scripts to mirror vendor defconfig targets for easier comparison.

## TODO
- Extract relevant Kconfig fragments into `docs/reference/system/linux_defconfig_snippets.md` (future work).
- Document UIO-specific kernel hooks referenced in `src/lib/video/uio.c` to aid debugging.

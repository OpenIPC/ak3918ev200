# Linux Kernel Interface Manual Notes

Source: `Linux平台内核接口使用手册_v1.0.0.pdf`

## English summary
Manual describing how userland interacts with Anyka kernel drivers via ioctl, read/write, and standard libc APIs. Focuses on GPIO, keypad, UART, ISP, encoder, audio, and other AK39-specific devices.

## Key sections & takeaways
- **Standard C library usage**: Explains glibc components included in vendor SDK, cross-compile environment setup.
- **GPIO interface**: Enumerates ioctl commands to query available pins, set direction, read/write levels, configure interrupts, and poll events. Matches the struct layout we mirrored in `include/ak3918/gpio.h`.
- **Keypad**: Provides read format for key events (scan code, press/release) via `/dev/keypad`.
- **UART**: Example code for configuring baud rate, parity, and timeouts with `termios` wrappers.
- **ISP**: High-level description of `/dev/isp_char` control plane; emphasises calling sequence (open → configure → start streaming).
- **Advanced devices**: Summaries for LCD, Touchscreen, PWM, ADC, RTC, battery monitor, watchdog.

## OpenIPC integration
- Confirms our SDK struct definitions; we should document any deviations in `docs/sdk/ak3918_sdk_notes.md`.
- Suggests adding examples to `src/examples/` showing keypad and UART usage for completeness.
- Use keypad and ADC notes to plan future agent modules (e.g., button handling, LDR-based day/night switching).

## TODO
- Translate ioctl constant table verbatim into markdown appendix (pending manual copy).
- Evaluate whether keypad driver is present in current kernel patches; if so, expose wrappers.

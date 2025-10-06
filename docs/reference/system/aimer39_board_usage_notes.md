# Aimer39 Product Board Usage Notes

Source: `Aimer39_V1平台产品板使用说明_V1.1.0.pdf`

## English summary
User manual explaining how to operate the Aimer39 product board: power connection, switch settings, firmware flashing, and peripheral setup.

## Key instructions
- **Power-up**: Connect 12 V supply; ensure polarity; wait for power LED; prepare serial console on UART0 for boot logs.
- **Boot mode selection**: DIP switches select SPI boot vs. UART download; default to SPI. Document exact switch positions (translated in table inside file).
- **Firmware update**: Use vendor upgrade tool via Ethernet or UART; place firmware package on TFTP/HTTP server as required.
- **Peripheral usage**: Steps for connecting sensor board, enabling IR-cut, attaching microphone/speaker, verifying alarm IO.
- **Debugging**: LED behaviour codes (power, network, watchdog) and serial console commands for diagnostics.

## OpenIPC integration
- Add boot mode table to README for newcomers flashing OpenIPC.
- Ensure supervisor monitors LEDs/watchdog status and logs anomalies.
- Provide instructions for safe firmware updates using our tooling, referencing vendor procedure for fallback.

## TODO
- Translate DIP switch legend into ASCII art diagram.
- Create quick-start checklist summarizing these steps for field technicians.

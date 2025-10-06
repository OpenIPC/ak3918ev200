# AK3918 Programmer's Guide Notes

Source: `AK3918 Programmer's Guide_Microstar_V0.5.0.pdf`

## Overview (English translation)
The programmer's guide details the AK3918 boot flow, low-level initialization sequences, peripheral bring-up procedures, register programming examples, and debugging interfaces. It bridges the gap between hardware specs and the vendor Linux BSP.

## Key sections
- **Boot sequence**: Boot ROM order (SPI NOR → NAND → UART download), strap pin meanings, watchdog behaviour, and emergency recovery paths.
- **Clock & power setup**: PLL configuration steps, register values for 24/27 MHz sensor clocks, gating matrices for media subsystems.
- **DDR init**: Sample register tables for DDR2/DDR3 timing; outlines the required training steps before enabling ISP/encoder.
- **Peripheral bring-up**: Step-by-step sequences for ISP, V4L2 capture, JPEG encoder (legacy), audio codec, Ethernet MAC.
- **Debug tooling**: UART command monitor, JTAG pinout, and vendor diagnostic registers for thermal/voltage monitoring.

## OpenIPC integration
1. **Supervisor agent** – incorporate documented boot retries and watchdog petting timing; add UART recovery instructions to deployment docs.
2. **Device Bring-Up agent** – replicate register write ordering prior to opening `/dev/video0` and `/dev/uio0`; record required delays in code comments.
3. **DDR configuration** – cross-check vendor timing tables against `conf/board/*.dtsi` to ensure we do not under-clock; capture differences in `docs/reference/hardware/aimer39_mainboard_notes.md`.
4. **Ethernet** – reuse strap descriptions to configure AR8032 resets; note fallback to 10/100 when RGMII calibration fails.
5. **Diagnostics** – expose UART monitor triggers via our supervisor for field debugging (document command list under `docs/reference/system/ak3918_debugging.md`, TODO).

## Action items
- Port PLL setup code snippets into `src/bringup/clock.c` (planned).
- Document DDR timing tables in YAML for validation scripts.
- Evaluate if ROM UART downloader can be used for automated flashing pipeline; update `tools/` once proven.

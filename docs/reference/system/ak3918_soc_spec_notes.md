# AK3918 SoC Specification Notes

Source documents:
- `AK3918 Specification_Microstar_V0.5.0.pdf`
- `AK3918 HD IP Camera SoC Specification.pdf`

## Overview (English translation)
Both specifications describe the Anyka AK3918 HD IP Camera system-on-chip. The combined material covers the silicon block diagram, clock tree, memory subsystem, interrupt controller, peripheral interfaces, and maximum multimedia capabilities (ISP + H.264 pipeline + audio codecs).

## Key technical takeaways
- **CPU & memory**: Dual ARM9-class cores with shared AXI fabric, on-chip SRAM (128 KB), external DDR2/DDR3 controller (800 MHz max) supporting 16-bit bus; boot from SPI NOR, optional NAND.
- **Clocking**: PLL0/PLL1 for media/CPU, dedicated sensor clock outputs (24/27 MHz), and independent audio PLL. Reset module exposes watchdog, soft reset, and cold boot states.
- **ISP pipeline**: Bayer input via MIPI or parallel DVP; supports 1x or 2x RAW input with configurable 3A (AE/AWB/AF) blocks. Output feeds scaler and H.264 encoder through shared buffer manager.
- **Encoder**: H.264 BP/MP up to 1080p30; dual-stream supported via macroblock reuse. Hardware packets in Annex B format with per-frame metadata registers (QP, keyframe flags).
- **Audio**: Integrated I²S/PCM, ADC/DAC with 16-bit 8–48 kHz support; optional I²S master/slave configuration.
- **I/O**: Rich GPIO bank, UART x3, SPI x2, I²C x3, USB 2.0 OTG, SDIO 2.0, Ethernet MAC (RMII/RGMII), PWM timers, watchdog, RTC.
- **Power domains**: Core 1.2 V, IO 3.3 V, sensor analog 2.8 V; DVFS hooks via clock gating and PLL dividers. Low-power standby retains RTC and DDR (self-refresh).

## OpenIPC integration checklist
1. **Clock/reset sequencing** – align Device Bring-Up Agent with documented reset order (release DDR first, then media engines). Add validation logs comparing PLL targets.
2. **ISP agent coverage** – ensure subpack IDs span all blocks listed in the spec (gamma, NR, LSC, HDR). Document missing IDs in `src/isp/apply_isp_conf.c` comments.
3. **UIO encoder mapping** – cross-reference register offsets for stream status, bitstream length, and IRQ ack with vendor tables; update `include/ak3918/video.h` once confirmed.
4. **Audio pipeline** – confirm `/dev/akpcm_cdev*` matches I²S block described here; plan for multi-rate support and external codec control via I²C.
5. **GPIO voltage caution** – spec highlights mixed-voltage banks; expose safe defaults in SDK to avoid setting outputs beyond rail maximum.
6. **Security features** – note boot ROM strap options (signed boot, UART download) for future secure firmware design.

## Cross-links
- Clock/reset info copied into `src/lib/sys/gpio.c` TODOs for voltage domain awareness.
- ISP register coverage verified in `docs/sdk/ak3918_sdk_notes.md` (see ISP section).
- Encoder capability summary referenced in `README.md` feature matrix.

## Next steps
- Extract detailed interrupt controller mapping into a dedicated table for runtime configuration (planned under `docs/reference/system/ak3918_interrupts.md`).
- Translate PLL configuration examples into scripts for the supervisor agent.

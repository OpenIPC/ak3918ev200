# Aimer39 Main Board Notes

Sources:
- `Aimer39_AK3918_MainBD_V1.2.0.pdf`
- `Aimer39_AK3916_MB_V1.0.1.pdf`

## Board overview (English)
The Aimer39 main boards host the AK3918/AK3916 SoC, DDR2, SPI NOR, Ethernet PHY, Wi-Fi module, audio codec, alarm IO, LEDs, and camera connectors. The schematics reveal GPIO assignments, power rails, and connector pin-outs critical for OpenIPC runtime agents.

## Important mappings
- **Storage**: SPI NOR (`/dev/spi0`) 8 MB on CS0; optional NAND footprint. TF (microSD) slot uses SDIO1 with GPIO31–38; GPIO39 as card-detect, GPIO40 as power enable.
- **Ethernet**: AR8032 PHY connected via RGMII. Reset pin tied to GPIO5, interrupt to GPIO6; 50 MHz clock from PHY feedback.
- **Wi-Fi**: Module on SDIO0 (GPIO16–23). Power enable on GPIO24, reset on GPIO25. Shared GPIO26 for WPS LED.
- **Audio**: I²S routed to AK7755 codec; LRCK/BCLK on GPIO70/71, data on GPIO72, MCLK on GPIO73. Amplifier enable via GPIO74.
- **Alarm IO**: Opto-isolated inputs mapped to GPIO80–83; outputs for siren/relay on GPIO84/85.
- **Camera connector**: 24-pin FPC supporting sensor power rails (2.8V/1.8V), I²C (GPIO100/101), reset (GPIO102), pwdn (GPIO103), MCLK (24 MHz from CLKOUT0).
- **LEDs**: Power LED on GPIO2, network LED on GPIO3, IR-cut control on GPIO104/105.

## Power rails
- 12 V DC input → DC-DC (5 V) → LDOs for 3.3 V (IO), 1.5 V (DDR), 2.8 V (sensor), 1.2 V (core). Sequencing controlled by PMU + discrete EN pins (GPIO10, GPIO11 for sensor analog/digital).

## OpenIPC actions
1. Update `include/ak3918/gpio.h` with enumerations for LEDs, Wi-Fi controls, alarm IO.
2. Expand Device Bring-Up to respect power enable ordering (sensor analog first, then digital, then release reset).
3. Add board profile YAML capturing these mappings for runtime auto-detection (planned `conf/boards/aimer39_main.yaml`).
4. Document AR8032 reset flow in `docs/reference/peripherals/ethernet_ar8032_notes.md` (linked) and ensure supervisor toggles GPIO5 if PHY fails to come up.
5. Provide QA checklist for verifying alarm IO polarity (some inputs active-low). Include in README.

## Differences vs AK3916 board
- AK3916 version uses alternative Wi-Fi module (USB) and lacks AR8032; ensures we gate code paths on board revision.
- Several GPIO numbers shifted by +4 due to different pin-mux defaults; see `Appendix A` in AK3916 PDF (noted in TODO list).

## TODOs
- Convert original schematics into searchable net tables.
- Validate actual GPIO numbering on hardware by reading `/sys/kernel/debug/gpio`.

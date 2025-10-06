# Aimer39 Bill of Materials Summary

Sources:
- `Aimer39_AK3918_BOM_V1.0.4.pdf`
- `Aimer39_AK3916_MB_BOM_V1.0.1.pdf`
- `Aimer39_DaughterBD_BOM_V1.0.1.pdf`
- `Aimer39_GC0308_DaughterBD_BOM_V1.0.0.pdf`

## Overview
These spreadsheets list components, suppliers, and reference designators for main and daughter boards. They inform sourcing, maintenance, and alternative part selection for OpenIPC-compatible hardware builds.

## Highlights
- **Core components**: AK3918 SoC, 64 MB DDR2 (Samsung K4T51163QJ-BCE7), 64 Mb SPI NOR (GD25Q64), optional 128 Mb upgrade.
- **Power**: Step-down converter MP1584 (5 V), LDOs RT9193 (2.8 V), MIC5205 (1.5 V), AMS1117 (3.3 V). Provide part tolerances in notes.
- **Audio path**: AK7755 codec, NS4263 speaker amp, WM8731 optional.
- **Sensors**: GC0308, HM1375, OV9712 modules including lens assemblies and IR LED boards.
- **Connectivity**: AR8032 Ethernet PHY, RT5370 Wi-Fi module (USB variant) or RTL8188 Wi-Fi SDIO module depending on board revision.

## OpenIPC actions
1. Maintain a living compatibility table pointing to drop-in replacements (e.g., W25Q64 for SPI flash). Add to `docs/reference/peripherals/aimer39_peripheral_support.md`.
2. When building custom firmware, document how regulator current limits affect enabling heaters/IR LEDs simultaneously.
3. Track BOM revisions to ensure kernel DTS matches actual hardware (e.g., I²C addresses of PMICs).

## TODO
- Convert key tables into CSV for automated validation (future script under `tools/`).

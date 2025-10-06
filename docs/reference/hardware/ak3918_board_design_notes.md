# AK3918 Product Board PCB Guide Notes

Source: `AK3918产品板PCB设计指南_V1.0.0.pdf`

## Summary
Vendor guidance for designing production PCBs around AK3918, covering board stack-up, component placement, connector pin-outs, and sensor wiring.

## Key technical points
- **Layer stack**: Recommends 4-layer PCB with top/bottom signal, internal ground, and combined power plane. DDR and sensor lanes should stay on inner layers when possible.
- **Power domains**: Lists dedicated LDO rails for sensor analog, Wi-Fi module, audio amplifier; emphasises separate analog ground islands.
- **Camera connectors**: Provides pin assignments for 24-pin FPC supporting MIPI or parallel DVP (SYNC/HS/VS). Includes default GPIO numbers for reset and power-enable lines.
- **SD/USB**: Layout advice for SD slot (series resistors on CMD/DAT lines) and USB differential pair routing.
- **Debug connectors**: UART0/1 header pinouts, JTAG 14-pin layout, LED indicators mapping.

## OpenIPC integration
- Use camera pin mapping to expand sensor table in `docs/reference/hardware/aimer39_daughterboard_notes.md` and `conf/sensors/` templates.
- Document regulator control GPIOs for Device Bring-Up agent (power rails toggled before ISP enable).
- Include debug header layout in README to help flashing via UART.

## TODOs
- Translate the connector diagrams into SVG/ASCII art for quick reference (future commit).
- Verify if the recommended LDO part numbers align with BOM files; note replacements if not available.

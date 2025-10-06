# AR8032 Ethernet PHY Notes

Source: `ATHENA_AR8032_V2.pdf`

## Summary
Schematic excerpt for the Qualcomm/Atheros AR8032 RGMII PHY as used on the Aimer39 main board. It documents strap pins, configuration resistors, and host interface signals.

## Key information
- **Power rails**: 1.0 V core (generated on-board), 2.5/3.3 V analog, 1.8 V for RGMII. Requires separate ferrite beads per rail for noise isolation.
- **Reset sequence**: `RST` pin driven by SoC GPIO (GPIO5). Hold low for >10 ms after power stable; release to start auto-negotiation.
- **Strap pins**: RXD[3:0], RXDV, RXER, and LED pins sampled on reset. Current schematic straps for RGMII, 1000BASE-T full duplex, auto-MDI/MDIX enabled.
- **Clocking**: PHY provides 125 MHz reference back to SoC via `CLK_25M` pin; ensure SoC expects RGMII timing with delay. Series resistors (33 Ω) on TX/RX pairs recommended.
- **Interrupt**: `INTR` routed to GPIO6 with pull-up. Use to detect link state changes without polling MDIO.

## OpenIPC integration
- Device Bring-Up agent must toggle GPIO5 with documented delay, and configure GPIO6 as interrupt source for link events (update `include/ak3918/gpio.h`).
- Validate MDIO addresses (default 0x00) when multiple PHYs present; note in network bring-up docs.
- Add monitoring to supervisor to log strap status read via MDIO register 0x18 (confirm strap results).

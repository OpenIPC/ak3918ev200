# AK3916 Platform PCB Guide Notes

Source: `AK3916平台PCB设计指南_V1.0.0.pdf`

## Summary
Although targeted at AK3916, the guide describes a closely related board architecture. It is valuable for understanding optional peripherals and alternative power trees used in earlier designs.

## Key differences vs AK3918 board
- AK3916 uses a slightly lower DDR clock; timing diagrams highlight generous margins that we can mirror if we need conservative settings during bring-up.
- Lists legacy Ethernet PHY options (KSZ8041) with strap values similar to AR8032; helps cross-reference fallback parts.
- Provides guidance on integrated Wi-Fi module power enable sequencing, including dedicated GPIOs and delay requirements.

## OpenIPC takeaways
- Document optional strap differences to avoid assuming AK3918-only behaviour in SDK (note in `docs/reference/peripherals/aimer39_peripheral_support.md`).
- Consider including compatibility layer that detects board revision and adjusts regulators/clock settings accordingly.

## TODO
- Extract table of alternate component suggestions for quick lookup when porting to non-Gwell boards.

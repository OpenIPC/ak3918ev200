# Aimer39 Platform Specification Notes

Source: `Aimer39_V1产品开发平台规格说明书_V1.1.00.pdf`

## English summary
Hardware specification for the Aimer39 development platform, including block diagrams, electrical characteristics, mechanical dimensions, and interface listings.

## Highlights
- **System architecture**: Shows AK3918 SoC connected to DDR2, SPI NOR, Ethernet PHY, Wi-Fi, audio codec, USB host, SD card, IR peripherals.
- **Power**: 12 V DC input, 5 V main rail, multiple LDOs. Provides consumption estimates per subsystem (camera, IR LEDs, Wi-Fi) for thermal budgeting.
- **Interfaces**: Enumerates all connectors (RJ45, USB, TF, alarm terminal blocks, UART headers) with voltage and pin assignments.
- **Environmental**: Operating temperature 0–60 °C; outlines humidity tolerance and EMI requirements.
- **Mechanical**: Board dimensions, mounting holes, recommended enclosure clearance.

## OpenIPC usage
- Use power consumption data to design power budgeting when enabling simultaneous audio/video/IR features.
- Document connector pinouts for accessory boards; support customizing harnesses for sensors or alarm IO.
- Incorporate mechanical drawings into hardware README to help community design 3D-printed enclosures.

## TODO
- Create quick-reference diagrams for connectors (RJ45, alarm block) based on spec tables.
- Compare power budget vs. actual measurements once hardware available.

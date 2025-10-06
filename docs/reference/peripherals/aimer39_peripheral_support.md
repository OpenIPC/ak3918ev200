# Aimer39 Peripheral Support List (English Summary)

Source: `Aimer39关键外围器件的支持列表_V1.0.0.pdf`

## Supported devices

### DDR2 SDRAM
| Manufacturer | Part | Capacity | Notes |
| --- | --- | --- | --- |
| Samsung | K4T51163QJ-BCE7 | 64 MB | Default production option |
| ProMOS | PME809416BKR | 64 MB | Drop-in replacement |

### SPI NOR Flash
| Manufacturer | Part | Density | Notes |
| --- | --- | --- | --- |
| GigaDevice | GD25Q64BS1G | 64 Mbit | Default boot flash |
| GigaDevice | GD25Q128F1G | 128 Mbit | High-capacity option |
| Macronix | MX25L6406EM2I-12G | 64 Mbit | Pin-compatible |
| Macronix | MX25L12806EZNI-10G | 128 Mbit | Requires updated partition layout |

### Image Sensors
| Sensor | Resolution | Interface | Remarks |
| --- | --- | --- | --- |
| GC0308 | VGA | Parallel | Legacy daylight sensor |
| HM1375 | 1.3 MP | MIPI/Parallel | Needs 1.5 V core rail |
| OV9712 | 1 MP | Parallel | Used for 720p pipeline |
| OV2710 | 2 MP | MIPI | Listed as future support |

### Ethernet PHY
| Manufacturer | Part | Interface | Notes |
| --- | --- | --- | --- |
| Qualcomm/Atheros | AR8032 | RGMII | Default on Aimer39 mainboard |
| Micrel | KSZ8041 | RMII | Alternative for cost-down boards |

### Wi-Fi Modules
| Vendor | Part | Interface | Notes |
| --- | --- | --- | --- |
| Ralink | RT5370 | USB | Requires USB host enable, 5 V supply |
| Realtek | RTL8188 | SDIO | SDIO0 lines; ensure 3.3 V supply |
| Broadcom | BCM4330 | SDIO | Listed but needs closed firmware |

## OpenIPC recommendations
- Maintain board profiles that capture which module is actually populated; this affects DTS, firmware blobs, and power controls.
- For unsupported sensors, extend ISP config conversions carefully—HM1375 requires polarity adjustments for PWDN, while OV9712 expects 27 MHz clock.
- Document the requirement for external regulatory approvals when swapping Wi-Fi modules (FCC/CE).

## Follow-up
- Add ADC peripheral support list (mentioned but not detailed) as soon as we obtain datasheet.
- Validate kernel driver availability for alternative parts; update `docs/sdk/ak3918_sdk_notes.md` accordingly.

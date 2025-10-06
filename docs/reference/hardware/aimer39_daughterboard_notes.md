# Aimer39 Daughter & Sensor Board Notes

Sources:
- `Aimer39_DaughterBD_V1.0.1.pdf`
- `Aimer39_DaughterBD_BOM_V1.0.1.pdf`
- `Aimer39_GC0308_DaughterBD_V1.0.0.pdf`
- `Aimer39_GC0308_DaughterBD_BOM_V1.0.0.pdf`
- `Aimer39_HM1375_SensorBD_V1.1.0.pdf`
- `Aimer39_OV9712_camera_V1.1.0.pdf`

## Summary (English)
These documents describe the plug-in boards hosting image sensors and supplementary components (IR-cut driver, illumination, lens assemblies). They provide connector pin-outs, regulator selections, and GPIO usage for sensor reset/power management.

## Key data for OpenIPC
- **Common connector**: 24-pin FPC linking back to main board. Pins supply 2.8 V analog, 1.8 V digital, I²C (SCL/SDA), pixel clock, HS/VS, data lines, and two GPIOs for reset (`S_RST`) and power-down (`PWDN`).
- **GC0308 module**:
  - Uses 27 MHz MCLK.
  - Reset active low, tied to main-board GPIO102.
  - IR-cut control lines pass through board to drive dual-coil actuator (GPIO110/111).
  - BOM lists RT9193 regulator for analog 2.8 V.
- **HM1375 module**:
  - Requires 1.5 V core rail (on-board LDO from 2.8 V).
  - PWDN active high; ensure SDK toggles accordingly.
  - Integrates photoresistor (LDR) feed to ADC input for day/night detection.
- **OV9712 module**:
  - Supports 720p@30 input; uses I²C address 0x30.
  - Provides test pads for SPI flash containing calibration tables.

## Integration steps
1. Extend sensor profiles in `conf/sensors/` with GPIO polarity, power rails, I²C addresses, clock requirements as captured above.
2. Document IR-cut control strategy in the Supervisor (toggle coils with delay, avoid simultaneous activation).
3. Update AGENTS doc to mention LDR/IR LED control path (via GPIO + ADC on daughter board).
4. Add calibration data structure references (where vendor stores OTP) for future extraction.

## TODO
- Create per-sensor YAML templates for ISP conf default selection.
- Verify actual GPIO assignments on hardware; schematics may use placeholder numbering.

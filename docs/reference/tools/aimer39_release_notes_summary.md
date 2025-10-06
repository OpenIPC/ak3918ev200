# Aimer39 Platform Release Notes Summary

Source: `Aimer39_V1平台项目版本发布说明.pdf`

## Summary
The release notes track official Public Development Kit (PDK) versions for the Aimer39 (AK3916/AK3918) platform, including delivered components, new features, and cautions.

## Version history (translated)
- **V1.0.00 (2013-05-17)** – Initial BSP release with recording, playback, reference multimedia applications.
- **V1.0.01 (2013-07-09)** – Adds board support packages for AK3916 evaluation board and AK3918 product board.
- **V1.1.00 (2013-10-18)** – Pilot production build; enables motion detection, two-way audio, dual-stream H.264 + MJPEG.

## Notes for OpenIPC
- Vendor explicitly calls out ISP tuning as “in-progress”; expect to create our own calibration pipeline.
- Supported codecs limited to H.264/MJPEG; other advertised formats (e.g., H.265) are not in this release — avoid misleading documentation.
- Dual-stream configuration (720p main + D1 sub) should be our baseline test scenario.

## Action items
- Maintain changelog parity in `docs/OpenIPC_AK3918_programming.md` to highlight divergence from vendor firmware.
- Use release dates to align with kernel patch revisions stored under `patches/`.
- Document missing features (e.g., secure boot, advanced analytics) so community knows they require new work.

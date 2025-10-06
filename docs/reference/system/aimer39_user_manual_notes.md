# Aimer39 Platform User Development Manual Notes

Source: `Aimer39_V1用户开发手册_V1.0.0.pdf`

## English summary
Comprehensive developer manual for the Aimer39 (AK39) platform, covering hardware overview, software layers, development workflow, and deployment guidance.

## Key topics
- **Platform intro**: Focus on IP camera use cases; highlights available peripherals (Ethernet, Wi-Fi, audio, alarm IO, motor control options).
- **Board interfaces**: Describes connectors, DIP switches, LEDs, UART headers.
- **Software architecture**: Layered diagram from hardware abstraction → middleware (media libs, network stack) → applications (camera, web UI).
- **Integration guidance**: Steps for building and flashing firmware, customizing applications, and using vendor SDKs.
- **System logic**: Explains dual-stream encoding, recording flow, playback/download features, remote upgrade process.

## OpenIPC integration
- Use architecture diagrams to ensure our AGENTS responsibilities align with vendor layering (ISP, V4L2, encoder, audio, network, web).
- Extract hardware interface descriptions (e.g., DIP switch mapping) to inform board profile docs.
- Provide translation of remote upgrade process to design OpenIPC OTA updates.

## TODO
- Capture original diagrams (converted to vector) for inclusion in README.
- Map vendor application modules to our planned open replacements (table to be added in `docs/OpenIPC_AK3918_programming.md`).

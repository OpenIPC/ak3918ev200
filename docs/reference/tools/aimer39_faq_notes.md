# Aimer39 Platform FAQ Notes

Source: `Aimer39_V1常见问题说明_V1.0.0.pdf`

## Summary
Vendor FAQ covering the most common integration and production issues across networking, web UI, ISP, encoder, and audio subsystems.

## Highlights
- **Ethernet**: Recommend DHCP in LAN mode; manual IP assignment required for direct PC connections (peer-to-peer). Reminds users to align subnet and disable DHCP auto when using static config.
- **Wi-Fi**: Troubleshooting WEP/WPA setups and SoftAP scanning failures; emphasises regulatory domain settings and antenna checks.
- **Web module**: Reset admin password via serial console if web UI inaccessible.
- **ISP**: Advises keeping `/dev/video0` open; warns against rapid sensor hot-plug (causes ISP reset).
- **Encoder**: Dual-channel (main/sub) configuration tips, constant vs. variable bitrate adjustments, GOP tuning guidelines.
- **Audio**: Notes on resampling (16 kHz target) and mitigating recording noise by grounding microphone shield.

## OpenIPC actions
- Convert these operational tips into automated sanity checks: e.g., supervisor verifying IP configuration, watchdog for ISP faults.
- Document SoftAP defaults in README to avoid confusion during field tests.
- Add audio noise mitigation recommendations to hardware bring-up docs.

## TODO
- Extract specific parameter ranges (e.g., recommended bitrate/GOP) into `docs/reference/software/ak39_video_lib_notes.md` for quick reference.

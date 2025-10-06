# Aimer39 Integration Guide Notes

Source: `Aimer39_V1集成说明_V1.0.0.pdf`

## English summary
The integration guide describes the contents of the Aimer39_V1 software package and explains how to assemble a bootable firmware image, including kernel, root filesystem, web UI, and demo applications.

## Key points
- **Package contents**: Kernel source (`kernel_V1.0.05.tar.gz`), rootfs (`rootfs_V1.1.00.tar.gz`), Wi-Fi libraries, multimedia libraries, demo binaries, and camera application sources.
- **Integration workflow**:
  1. Extract kernel and apply board-specific patches (GPIO definitions, sensor configs).
  2. Build root filesystem with vendor scripts; integrate Wi-Fi firmware and multimedia libs.
  3. Configure web server and CGI endpoints for camera control; update configuration files under `/usr/local/etc`.
  4. Package everything using the image tool (see separate notes) and flash via bootloader utility.
- **Known limitations**: Multi-sensor switching unsupported; Wi-Fi library closed-source; motion detection configured only for 720p.
- **Known defects**: Occasional ISP hang after hot-plugging sensor; requires power cycle.

## OpenIPC integration
- Use the package list to identify components that must be replaced with open alternatives (e.g., web UI, streaming server).
- Document closed binary dependencies to avoid licensing conflicts; track progress replacing them in `docs/sdk/ak3918_sdk_notes.md`.
- Incorporate known defects into QA checklist and mention in AGENTS troubleshooting section.

## TODO
- Extract default configuration files for reference (copy into `docs/reference/raw/config/` in future).
- Reproduce the packaging steps with open tools and script them for CI.

# AK3918 Reference Documentation Catalog

This catalog summarizes all vendor and third-party documentation bundled in `downloaded/`, translated into English, and tied back to the OpenIPC AK3918EV200 effort. Use it as a roadmap: every entry links to new, structured notes under `docs/reference/` and calls out specific follow-up tasks for the SDK, firmware, and runtime agents.

## How to use this catalog
- Start with the **SoC Core References** to understand the silicon capabilities and register maps.
- Consult **Board & Hardware Guides** when wiring sensors, tuning power, or laying out PCBs.
- Use **Peripherals & Drivers** and **Multimedia Libraries** when enabling new devices or codecs in the SDK.
- Follow the **System Software** notes for kernel, rootfs, and factory tooling guidance.
- Check **Project Notes & FAQ** for vendor caveats that affect stability and production deployments.

Each entry contains:
- **Summary** – Concise English overview of the source document.
- **Key Technical Data** – Highlights worth encoding into our SDK/runtime.
- **OpenIPC Integration** – Concrete actions or checks for the project.
- **Detailed Notes** – Link to the expanded markdown file we generated for deeper dives.

> All raw text extractions remain available under `docs/reference/raw/` for cross-checking against the original PDFs.

## SoC core references

| Title | Summary | OpenIPC Integration | Notes |
| --- | --- | --- | --- |
| `AK3918 Specification (Microstar V0.5.0)` | Full architecture reference: clock tree, memory map, peripheral blocks, interrupt matrix, pin mux, power domains. | Cross-verify register definitions used in `include/ak3918/*.h`; align clock/reset bring-up sequences in Device Bring-Up and GPIO agents. | [docs/reference/system/ak3918_soc_spec_notes.md](system/ak3918_soc_spec_notes.md) |
| `AK3918 HD IP Camera SoC Specification` | Marketing + technical brief for HD pipeline: ISP chain, H.264 encoder, audio codecs, sensor interfaces, DDR constraints. | Use for high-level capability matrix (max resolutions, FPS, encoder profiles) in README and SDK docs; ensure ISP agent respects supported pixel formats. | [docs/reference/system/ak3918_soc_spec_notes.md](system/ak3918_soc_spec_notes.md) |
| `AK3918 Programmer's Guide (Microstar V0.5.0)` | Firmware-centric view of boot flow, register programming, media subsystem initialization, debug UART usage. | Mirror boot/clock init steps in supervisor; extract ISP/uio init sequences into SDK examples. | [docs/reference/system/ak3918_programmer_guide_notes.md](system/ak3918_programmer_guide_notes.md) |
| `AK3918 Kernel Patch Stack` | Summary of vendor Linux-3.4.35 patches (mach-ak39, multimedia drivers, wake locks, OverlayFS). | Keep kernel tree buildable; align SDK wrappers with driver ABIs; plan forward-port work. | [docs/reference/system/ak3918_kernel_patch_summary.md](system/ak3918_kernel_patch_summary.md) |
| `AK391X Hardware Design Guide V1.0.1` | Reference for PCB power, crystal specs, DDR routing, EMI/ESD, GPIO voltage domains across AK391X family. | Validate GPIO level tolerances before exposing SDK toggles; ensure bring-up scripts check LDO rails. | [docs/reference/hardware/ak391x_hardware_design_notes.md](hardware/ak391x_hardware_design_notes.md) |
| `AK3918 Product Board PCB Design Guide V1.0.0` | Concrete layout instructions for AK3918 product boards: stack-up, impedance, camera connector pinouts. | Documented pinouts feed sensor adapter board definitions; add to hardware README for makers building custom boards. | [docs/reference/hardware/ak3918_board_design_notes.md](hardware/ak3918_board_design_notes.md) |
| `AK3916 Platform PCB Design Guide V1.0.0` | AK3916 variant PCB notes (shared IP with AK3918). Useful to compare power rails and alternate BOM options. | Capture differences to guard against cross-porting mistakes; highlight reusable analog front-end blocks. | [docs/reference/hardware/ak3916_board_design_notes.md](hardware/ak3916_board_design_notes.md) |

## Board & hardware guides

| Title | Summary | OpenIPC Integration | Notes |
| --- | --- | --- | --- |
| `Aimer39_AK3918_MainBD_V1.2.0` | Main board schematic walk-through: DDR, PMU, audio codec, network PHY (AR8032), LED/LDR connectors. | Use to map GPIO numbers to physical headers; feed LED/LDR agent mappings; confirm PHY reset GPIO for bring-up. | [docs/reference/hardware/aimer39_mainboard_notes.md](hardware/aimer39_mainboard_notes.md) |
| `Aimer39_AK3916_MB_V1.0.1` | Older AK3916 main board; shows alternative power sequences and BOM differences. | Highlight divergences for compatibility mode; warn about voltage rails when reusing firmware. | [docs/reference/hardware/aimer39_mainboard_notes.md](hardware/aimer39_mainboard_notes.md) |
| `Aimer39 Daughter Board Guides (generic + sensor variants)` | Layout + connection details for daughter/sensor boards (GC0308, HM1375, OV9712). | Sensor agent: map I²C, reset, power-enable GPIOs; maintain per-sensor config table in SDK. | [docs/reference/hardware/aimer39_daughterboard_notes.md](hardware/aimer39_daughterboard_notes.md) |
| `Aimer39_* BOM files` | Component lists for main and daughter boards. | Link part numbers to sourcing doc; ensure power mods documented when replacing regulators or sensors. | [docs/reference/hardware/aimer39_bom_summary.md](hardware/aimer39_bom_summary.md) |
| `Aimer39 peripheral support list` | Vendor-approved peripheral catalogue (Wi-Fi, audio codecs, sensors, motors). | Prioritize driver support in SDK; update README compatibility matrix. | [docs/reference/peripherals/aimer39_peripheral_support.md](peripherals/aimer39_peripheral_support.md) |
| `ATHENA_AR8032_V2` | AR8032 Ethernet PHY datasheet excerpt: pin definitions and configuration straps. | Align PHY init in Device Bring-Up; double-check RGMII timing and reset GPIO. | [docs/reference/peripherals/ethernet_ar8032_notes.md](peripherals/ethernet_ar8032_notes.md) |

## Tools & production process

| Title | Summary | OpenIPC Integration | Notes |
| --- | --- | --- | --- |
| `Aimer39 platform image generation tool guide` | Step-by-step on vendor firmware packaging, partition layout, signing. | Inform OpenIPC firmware packaging workflow; verify compatibility with extroot design. | [docs/reference/tools/aimer39_image_tool_notes.md](tools/aimer39_image_tool_notes.md) |
| `Aimer39 V1 integration guide` | System assembly instructions: flashing, environment variables, configuration scripts. | Mirror essential environment steps in Supervisor agent and deployment scripts. | [docs/reference/tools/aimer39_integration_notes.md](tools/aimer39_integration_notes.md) |
| `Aimer39 V1 project release notes` | Version history, bug fixes, known issues for vendor firmware. | Track regressions; populate AGENTS troubleshooting tips; map bugs to tests. | [docs/reference/tools/aimer39_release_notes_summary.md](tools/aimer39_release_notes_summary.md) |
| `Aimer39 V1 platform common issues` | FAQ on boot failures, sensor mismatch, audio noise, SD mounting. | Feed troubleshooting section in README; add monitoring hooks to detect listed failure modes. | [docs/reference/tools/aimer39_faq_notes.md](tools/aimer39_faq_notes.md) |
| `ISP parameter configuration tool guide` | UI workflow for ISP tuning, pack/subpack export, parameter semantics. | Ensure ISP Config agent covers all block types; document conversion script in SDK. | [docs/reference/tools/isp_tool_notes.md](tools/isp_tool_notes.md) |
| `ISP .conf reverse engineering` | Pack/sub-pack framing rules and sensor load handling. | Use as canonical reference when adding new sensors or validating exported configs. | [docs/reference/tools/isp_conf_format.md](tools/isp_conf_format.md) |
| `ISP block catalogue` | Enumerates every block ID (`0x00`–`0x1C`), associated `ak_isp_*` calls, and observed payload sizes. | Useful when editing packs or generating configs programmatically. | [docs/reference/isp/isp_block_catalog.md](isp/isp_block_catalog.md) |

## System software & Linux platform

| Title | Summary | OpenIPC Integration | Notes |
| --- | --- | --- | --- |
| `Linux kernel configuration & modification manual` | Vendor workflow for kernel defconfig changes, driver enablement, rebuild steps. | Align with `build/` scripts; document required patches; confirm CONFIG options for UIO, GPIO, audio. | [docs/reference/system/linux_kernel_mod_notes.md](system/linux_kernel_mod_notes.md) |
| `Linux kernel interface manual` | ioctl, /proc, /sys interface summary for vendor drivers (gpio, isp, uio, audio). | Cross-reference SDK wrappers; ensure structs match; highlight undocumented ioctls needing reverse engineering. | [docs/reference/system/linux_kernel_interface_notes.md](system/linux_kernel_interface_notes.md) |
| `Linux Wi-Fi module user guide` | Setup for approved Wi-Fi modules, including firmware, wpa_supplicant integration. | Expand supervisor Wi-Fi bring-up; document power-save toggles; plan for open firmware replacements. | [docs/reference/peripherals/wifi_module_notes.md](peripherals/wifi_module_notes.md) |
| `Aimer39 platform user development manual` | End-to-end tutorial: filesystem layout, SDK usage, debugging, production tips. | Mirror best practices in README; ensures new contributors follow vendor bootstrap when porting. | [docs/reference/system/aimer39_user_manual_notes.md](system/aimer39_user_manual_notes.md) |
| `Aimer39 platform specification` | High-level spec for the dev platform; includes block diagrams, power budget. | Feed hardware overview section of docs; validate supply constraints when enabling new features. | [docs/reference/hardware/aimer39_platform_spec_notes.md](hardware/aimer39_platform_spec_notes.md) |
| `Aimer39 product board usage manual` | Load images, connect peripherals, DIP switch settings. | Document required bootstrapping steps in supervisor; ensures bring-up agent toggles correct power rails. | [docs/reference/system/aimer39_board_usage_notes.md](system/aimer39_board_usage_notes.md) |

## Multimedia & DSP libraries

| Title | Summary | OpenIPC Integration | Notes |
| --- | --- | --- | --- |
| `AK39 video driver library interface` | Lists encoder/decoder APIs, buffer management, sync controls. | Map to our `video/uio` wrappers; confirm ioctl constants; extend docs for H.264 drain path. | [docs/reference/software/ak39_video_lib_notes.md](software/ak39_video_lib_notes.md) |
| `Audio/video overall usage manual` | Overview of multimedia pipeline, module interconnects, recommended configs. | Align agent responsibilities; ensure audio optional path matches vendor expectations. | [docs/reference/software/ak39_multimedia_overview.md](software/ak39_multimedia_overview.md) |
| `Audio library interface` | PCM playback/capture APIs, mixer controls, echo cancellation hooks. | Document mapping to `/dev/akpcm_cdev*`; plan future SDK wrappers for advanced audio. | [docs/reference/software/ak39_audio_lib_notes.md](software/ak39_audio_lib_notes.md) |
| `Echo cancellation library interface` | API for vendor AEC; parameters for mic/speaker alignment. | Evaluate viability for OpenIPC; mark licensing concerns. | [docs/reference/software/ak39_audio_lib_notes.md](software/ak39_audio_lib_notes.md) |
| `Media parser/composer/playback libraries` | APIs for container parsing, muxing, playback control (TS, MP4). | Inform optional muxer roadmap; consider compatibility with open libraries. | [docs/reference/software/ak39_media_lib_notes.md](software/ak39_media_lib_notes.md) |
| `Motion detection library V2 interface` | API for motion detection overlays, ROI configuration, integration with ISP. | Feed optional analytics agent; evaluate replacing with open algorithms. | [docs/reference/software/ak39_motion_lib_notes.md](software/ak39_motion_lib_notes.md) |
|

## Miscellaneous hardware references

| Title | Summary | OpenIPC Integration | Notes |
| --- | --- | --- | --- |
| `Aimer39 V1 product development platform FAQ` | Answers to typical hardware/software issues. | Use as baseline for troubleshooting guides; integrate checks in supervisor (voltage, sensor presence). | [docs/reference/tools/aimer39_faq_notes.md](tools/aimer39_faq_notes.md) |
| `Lamobo D1 guides` | Assembly and lens replacement instructions for Lamobo D1 (Allwinner-based) used as comparative reference. | Extract best practices for mechanical assembly; note differences vs AK3918 but keep for inspiration. | [docs/reference/hardware/lamobo_d1_notes.md](hardware/lamobo_d1_notes.md) |

All detailed notes include actionable TODO lists and direct quotations (translated) for future development. Keep this catalog updated when new PDFs arrive or when detailed notes evolve.

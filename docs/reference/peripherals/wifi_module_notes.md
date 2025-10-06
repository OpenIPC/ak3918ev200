# Linux Wi-Fi Module User Guide Notes

Source: `Linux平台Wifi模块用户操作指南_V1.0.0.pdf`

## English summary
Instructions for configuring Wi-Fi modules on the Anyka Linux platform, including driver loading, firmware placement, and AP/STA operation.

## Highlights
- **Supported modules**: RT5370 (USB), RTL8188 (SDIO), BCM4330 (SDIO). Each requires specific kernel modules and firmware blobs placed under `/lib/firmware`.
- **Driver loading**: `insmod` sequences with module parameters (MAC address, power-save). For SDIO modules, instructs enabling SDIO power before inserting module.
- **Wireless configuration**: Commands for `iwpriv`, `iwconfig`, `wpa_supplicant`, and SoftAP scripts. Provides default SSID/password for vendor firmware.
- **Troubleshooting**: Check `dmesg` for `mmc0: new high speed SDIO card` lines; ensure regulatory domain matches region; adjust antenna connectors.

## OpenIPC integration
- Document required firmware filenames to guide users replacing closed binaries (preface open-source alternatives).
- Add power control GPIOs to Device Bring-Up to ensure Wi-Fi modules power cycle correctly.
- Provide sample `wpa_supplicant.conf` and hostapd configs derived from vendor scripts (store under `docs/reference/peripherals/wifi_configs/`, TODO).

## TODO
- Verify driver availability in our kernel tree; note differences (e.g., we may use upstream cfg80211). Update doc once mainline replacements confirmed.

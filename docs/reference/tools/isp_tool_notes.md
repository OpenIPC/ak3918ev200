# ISP Parameter Configuration Tool Notes

Source: `ISP参数配置工具使用说明.pdf`

## English summary
Describes the Windows GUI utility used to tune ISP parameters on Anyka cameras. The tool connects to devices over the LAN, streams preview frames, and allows exporting/importing `.conf` packs and generated C headers.

## Workflow
1. **Discover device** via broadcast search; connect using admin credentials.
2. **Preview** live video and review grayscale histogram (normal/log scale) while adjusting ISP blocks (AE, AWB, noise reduction, gamma, LSC, etc.).
3. **Export** configuration to vendor `.conf` format (pack/subpack) or generate `.h` file for kernel integration.
4. **Import** existing configs to compare and tweak.

## OpenIPC integration
- Confirms our parser’s subpack layout; ensures `parse_isp_conf.c` handles exported files.
- Introduce a conversion script to transform `.conf` into YAML/JSON for version control (`tools/isp_conf_convert.py`, planned).
- Add guidance for using the preview histogram to calibrate day/night profiles; document in `docs/sdk/ak3918_sdk_notes.md`.

## TODO
- Capture screenshots (if permitted) to illustrate mapping between GUI controls and subpack IDs.
- Document network protocol the tool uses; could help reimplement an open-source alternative.

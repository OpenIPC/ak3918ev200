# AK3918 ISP Block Catalogue

This document maps each block ID found inside Anyka ISP `.conf` packs to the SDK
entry points (`ak_isp_*`), expected payload sizes, and underlying structures. The
information is derived from:

- The vendor dispatcher embedded in the original firmware
  (`FUN_00035de8` / `FUN_00035ebc` in `vendor/decompiled/ipc.c`).
- The open-source reimplementation (`src/lib/isp/isp_device.c`).
- Empirical measurements across all configuration files under `conf/`.

The table below uses the metadata exported by `ak_isp_get_block_info()` (see
`include/ak3918/isp_blocks.h`). Sizes are payload bytes (sub-pack size minus the
4-byte header). Min/max values correspond to the smallest/largest payloads that
appear in the captured sensor packs.

| ID | Name | SDK call(s) / offset | Payload size (min–max) | Notes |
| -- | ---- | -------------------- | ----------------------- | ----- |
| `0x00` | Black level correction | `ak_isp_set_blc_attr @0x0000` | 182 | Matches `struct isp_black_balance`. |
| `0x01` | Lens shading correction | `ak_isp_set_lsc_attr @0x0000` | 188 | `struct isp_lens_correct`. |
| `0x02` | RAW LUT | `ak_isp_set_raw_lut_attr @0x0000` | 872 | 64-entry LUTs for sensor linearisation. |
| `0x03` | Noise reduction stage 1/2 | `ak_isp_set_nr1_attr @0x0000`, `ak_isp_set_nr2_attr @0x06f6` | 2184–2264 | Inner structures not documented; offsets align with vendor blob split. |
| `0x04` | 3D noise reduction | `ak_isp_set_3d_nr_attr @0x0000` | 514–1084 | Large table (varies by sensor). |
| `0x05` | Green balance | `ak_isp_set_gb_attr @0x0000` | 82 | Fixed-size registers. |
| `0x06` | Demosaic | `ak_isp_set_demo_attr @0x0000` | 18 | Small control block. |
| `0x07` | RGB gamma | `ak_isp_set_rgb_gamma_attr @0x0000` | 872 | 32-point gamma curve per channel. |
| `0x08` | Color correction matrix | `ak_isp_set_ccm_attr @0x0000` | 132–148 | Contains 3×3 matrix and thresholds. |
| `0x09` | False color suppression | `ak_isp_set_fcs_attr @0x0000` | 102 | Fixed layout. |
| `0x0A` | Wide dynamic range | `ak_isp_set_wdr_attr @0x0000` | 8898–9962 | Two large tables (strength curves). |
| `0x0B` | Sharpness | `ak_isp_set_sharp_attr @0x0000`, `ak_isp_set_sharp_ex_attr @0x2b36` | 194–11092 | Base parameters + 0x2b36-sized lookup (only populated on some sensors). |
| `0x0C` | Saturation | `ak_isp_set_saturation_attr @0x0000` | 202–11092 | Some packs reuse the same buffer as sharpness (hence large max). |
| `0x0D` | Contrast | `ak_isp_set_contrast_attr @0x0000` | 60–122 | `struct isp_brightness_enhance`. |
| `0x0E` | RGB → YUV | `ak_isp_set_rgb2yuv_attr @0x0000` | 2–60 | Simple coefficient set. |
| `0x0F` | Special effects | `ak_isp_set_effect_attr @0x0000` | 2–10 | Enables sepia/negative etc. |
| `0x10` | Defect pixel correction | `ak_isp_set_dpc_attr @0x0000`, `ak_isp_set_sdpc_attr @0x0054` | 10–4184 | First block configures thresholds, second is the static DPC table (`struct isp_defect_pixel`). |
| `0x11` | AE weighting | `ak_isp_set_weight_attr @0x0000` | 256–4144 | Per-scene AE weights (zones). |
| `0x12` | Auto focus | `ak_isp_set_af_attr @0x0000` | 42–256 | Hardware focus window config. |
| `0x13` | White balance | `ak_isp_set_wb_type @0x0000`, `ak_isp_set_mwb_attr @0x0002`, `ak_isp_set_awb_attr @0x000e`, `ak_isp_set_awb_ex_attr @0x00c8` | 10–524 | Mix of manual and auto-WB thresholds. |
| `0x14` | Histogram & exposure | `ak_isp_set_raw_hist_attr @0x0000`, `ak_isp_set_rgb_hist_attr @0x0002`, `ak_isp_set_yuv_hist_attr @0x0004`, `ak_isp_set_exp_type @0x0006`, `ak_isp_set_frame_rate @0x0008`, `ak_isp_set_ae_attr @0x0020` | 180–236 | Histogram enables plus AE curve; we also set `sensor_fps = 0x0f` after applying this block. |
| `0x15` | Miscellaneous | `ak_isp_set_misc_attr @0x0000` | 26–240 | Contains ISP global toggles (debayer mode, black clamp, etc.). |
| `0x16` | Y gamma | `ak_isp_set_y_gamma_attr @0x0000` | 18–302 | 32-point luma gamma curve. |
| `0x17` | Hue | `ak_isp_set_hue_attr @0x0000` | 992 | Only present on some sensors (SC1135/SC1145/SC1235 variants). |
| `0x18` | Mask / privacy zones | `ak_isp_set_main_chan_mask_area @0x0000`, `ak_isp_set_sub_chan_mask_area @0x0010`, `ak_isp_set_mask_color @0x0020` (+ capture flag at 0x0024, logged only) | 32–36 | Capturing flag is read but not written to the kernel (vendor firmware toggles it elsewhere). |
| `0x1B` | Sensor script (type B) | `ak_isp_sensor_load_conf @0x0000` | 144–568 | Returns array of 32-bit register/value pairs. |
| `0x1C` | Sensor script (type C) | `ak_isp_sensor_load_conf @0x0000` | 144–504 | Same semantics as `0x1B`; different sensors use different endings. |

## Sensor load (`0x1B` / `0x1C`)

The terminating block encapsulates the full sensor register script. The firmware
reads the sub-pack `size` (inclusive of the 4-byte header), divides it by four
(`size >> 2`), then advances the pointer past the header before calling
`Ak_ISP_Sensor_Load_Conf()`. Replicating that logic requires adding one extra
32-bit word to the payload length:

```c
struct blob_desc desc = {
    .nwords = (payload_len + 4) / 4,
    .ptr    = payload,   // payload excludes the 4-byte header
};
ak_isp_sensor_load_conf(&desc);
```

All known payloads are multiples of four, so the extra word only introduces
harmless padding. Dropping the `+4` truncates the script and prevents sensors
from booting.

## User parameters (`Ak_ISP_Set_User_Params`)

The vendor IPC periodically pushes runtime-generated blobs via ioctl
`0x4004496d`. These structures seem to aggregate live statistics (AE/AWB/TNR
state) encoded by proprietary routines; the official SDK does not expose a
static definition and the payload length varies. We currently rely on blobs
captured from the running firmware (`data/isp_blobs/isp_user_params_*.bin`).
Generating them from scratch remains an open research task.

## Working with the metadata

`include/ak3918/isp_blocks.h` exports helper descriptors so tooling can reason
about block layout without hardcoding offsets. Example usage:

```c
const ak_isp_block_info_t *info = ak_isp_get_block_info(block_id);
if (info && payload_len < info->min_payload) {
    fprintf(stderr, "payload too small\n");
}
for (size_t i = 0; info && i < info->sub_count; ++i) {
    const ak_isp_subblock_info_t *sub = &info->subs[i];
    printf("%-24s offset=0x%04x\n", sub->function, (unsigned)sub->offset);
}
```

Use these descriptors when writing editors or generators for the `.conf` packs.

## Known gaps

- The binary preamble at the beginning of each `.conf` remains undocumented.
- Many `ak_isp_*` settlement structures (NR, WDR, sharpness tables) lack public
  field definitions; editing them still requires external tooling or vendor
  knowledge.
- `Ak_ISP_Set_User_Params` payloads are not yet reverse engineered. Capturing
  and diffing these blobs under different ISP states should be prioritised to
  eliminate dependencies on vendor binaries.

Refer to `docs/reference/tools/isp_conf_format.md` for the pack framing rules
and sensor script details.

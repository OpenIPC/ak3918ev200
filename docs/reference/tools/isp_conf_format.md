# Anyka ISP `.conf` Layout

Validated against the blobs under `conf/` (AR0130, GC1024, H42, SC10xx/11xx/12xx/13xx variants). The notes consolidate what our parser (`src/lib/isp/parse_conf.c`) and apply routine (`src/lib/isp/isp_device.c`) already implement, with the gaps and TODOs called out explicitly.

## 1. File preamble

* The files start with an opaque vendor header (typically the first 0x80–0x100 bytes).  
  Examples show ASCII strings such as `"3.007"`, `"2.003"`, or Chinese comments (`"3DNR denoise"`, `"2.8.29 exp"`).  
  We have not reverse-engineered the exact structure; the runtime parser simply scans past this header when hunting for the first sub-pack.
* Practical implication: treat everything before the first `uint16_t id == 0x0000` header as metadata.  
  The parser therefore linearly scans the buffer in 4-byte steps until it finds a candidate header `{id, size}`.

## 2. Pack & sub-pack framing

* Each configuration is split in **packs**, typically two of them per file.  
  Observed pattern: pack 0 and pack 1 carry the same set of IDs in the same order but the payloads differ (likely day vs. night / indoor vs. outdoor tuning).  
  In all vendor blobs studied the total blocks per pack are:
  * 24 sequential IDs `0x00` … `0x17`, followed by
  * a terminating block `0x1B` or `0x1C` (sensor load).
* A pack is encoded as a consecutive sequence of **sub-packs**:
  * Header: two little-endian 16-bit words (`struct { uint16_t id; uint16_t size; }`).
  * `size` counts the header itself. Payload length = `size - 4`.
  * IDs increment monotonically from 0 upwards; after `0x17` the driver tolerates a jump to `0x1B`/`0x1C` which is treated as the "final" block of the pack.
  * The parser collects sub-packs until it sees the first header whose ID is not `previous_id + 1`; that element is still considered part of the pack and the pack terminates immediately after it.
* Between packs there is no extra padding; parsing resumes right after the last byte of the terminating sub-pack.

### Pseudocode (matching `parse_isp_conf.c`)

1. Scan forward in 4-byte increments until a header with `id == 0` and sane `size` is found; this marks a pack candidate.
2. Jump by `size` bytes, checking that the next header increments the ID.  
   Keep pushing headers into a temporary list.
3. The first header that breaks the strict increment rule is still accepted as the **pack terminator** (`0x1B`/`0x1C`).
4. Invoke the callback for every collected sub-pack (`pack_index`, `id`, `payload` pointer, `payload_size`).
5. Continue scanning from the byte immediately after the terminator.

The parser exposes `struct isp_block` with both header and payload pointers so higher layers can pass the vendor header to the SDK when required.

## 3. Block ID catalogue

The `isp_apply_conf.c` switch mirrors how the original firmware applies each block. Offsets below are offsets inside the payload (header removed). When multiple calls are listed, the vendor blob concatenates the corresponding parameter blocks.

| ID | Offsets | ISP call(s) |
| -- | ------- | ----------- |
| `0x00` | `0x0000` | `ak_isp_set_blc_attr` (black level correction). |
| `0x01` | `0x0000` | `ak_isp_set_lsc_attr` (lens shading). |
| `0x02` | `0x0000` | `ak_isp_set_raw_lut_attr`. |
| `0x03` | `0x0000`, `0x06f6` | `ak_isp_set_nr1_attr`, `ak_isp_set_nr2_attr`. |
| `0x04` | `0x0000` | `ak_isp_set_3d_nr_attr`. |
| `0x05` | `0x0000` | `ak_isp_set_gb_attr`. |
| `0x06` | `0x0000` | `ak_isp_set_demo_attr` (demosaic). |
| `0x07` | `0x0000` | `ak_isp_set_rgb_gamma_attr`. |
| `0x08` | `0x0000` | `ak_isp_set_ccm_attr` (color correction matrix). |
| `0x09` | `0x0000` | `ak_isp_set_fcs_attr` (false color suppression). |
| `0x0A` | `0x0000` | `ak_isp_set_wdr_attr`. |
| `0x0B` | `0x0000`, `0x2b36` | `ak_isp_set_sharp_attr`, `ak_isp_set_sharp_ex_attr`. |
| `0x0C` | `0x0000` | `ak_isp_set_saturation_attr`. |
| `0x0D` | `0x0000` | `ak_isp_set_contrast_attr`. |
| `0x0E` | `0x0000` | `ak_isp_set_rgb2yuv_attr`. |
| `0x0F` | `0x0000` | `ak_isp_set_effect_attr` (special effects). |
| `0x10` | `0x0000`, `0x0054` | `ak_isp_set_dpc_attr`, `ak_isp_set_sdpc_attr` (defect pixel correction). |
| `0x11` | `0x0000` | `ak_isp_set_weight_attr` (AE weighting). |
| `0x12` | `0x0000` | `ak_isp_set_af_attr`. |
| `0x13` | `0x0000`, `0x0002`, `0x000e`, `0x00c8` | `ak_isp_set_wb_type`, `ak_isp_set_mwb_attr`, `ak_isp_set_awb_attr`, `ak_isp_set_awb_ex_attr`. |
| `0x14` | `0x0000`, `0x0002`, `0x0004`, `0x0006`, `0x0008`, `0x0020` | `ak_isp_set_raw_hist_attr`, `ak_isp_set_rgb_hist_attr`, `ak_isp_set_yuv_hist_attr`, `ak_isp_set_exp_type`, `ak_isp_set_frame_rate`, `ak_isp_set_ae_attr`; afterwards we set `sensor_fps` to `0x0f`. |
| `0x15` | `0x0000` | `ak_isp_set_misc_attr`. |
| `0x16` | `0x0000` | `ak_isp_set_y_gamma_attr`. |
| `0x17` | `0x0000` | `ak_isp_set_hue_attr`. |
| `0x18` | `0x0000`, `0x0010`, `0x0020`, `0x0024` | `ak_isp_set_main_chan_mask_area`, `ak_isp_set_sub_chan_mask_area`, `ak_isp_set_mask_color`; capture flag is logged but not applied (vendor firmware toggles it elsewhere). |
| `0x1B` / `0x1C` | payload-only | `ak_isp_sensor_load_conf` (see below). |

> Offsets are taken directly from the vendor tables; we keep them to remain binary-compatible with Anyka blobs. Missing IDs fall into the `default` clause and raise a diagnostic (`param err`), so the block map above is essentially the canonical list shipped by the BSP.

## 4. Sensor configuration block (`0x1B` / `0x1C`)

* The terminating block embeds the sensor register script. Two IDs have been observed:
  * `0x1B` on the HE05/H42/AR0130/SC10x5 variants.
  * `0x1C` on GC1024 / SC1135 / SC1145 / SC1235 / SC1245 / SC1345.
* The payload is a flat array of 32-bit words (register/value pairs). The vendor
  loader (`FUN_00035de8` in `vendor/decompiled/ipc.c`) reads the 16-bit `size`
  field from the sub-pack header, divides it by four, and places the result in
  the `blob_desc.nwords` field **before** skipping the 4-byte header:

  ```c
  uint16_t size = *(uint16_t *)(block + 2);      // includes header
  struct blob_desc desc;
  desc.nwords = size >> 2;                       // i.e. (payload_len + 4) / 4
  desc.ptr    = block + 4;                       // payload without header
  Ak_ISP_Sensor_Load_Conf(&desc);
  ```

  This explains why our implementation mirrors the formula
  `nwords = (payload_len + 4) / 4`: the pack builder stores the block length
  inclusive of the 4-byte header, yet the ioctl expects a pointer that already
  skips it. Removing the `+4` truncates the last register pair in practice.
* In all captured blobs the payload length is a multiple of four, so the extra
  word only adds harmless padding (the following bytes are part of the inter-pack
  gap). Nonetheless we stay faithful to the vendor logic to avoid off-by-one
  regressions on other sensor scripts.

## 5. Observable patterns across sensors

* **Two packs** per file. Differences between pack 0 and pack 1 align with typical day/night tuning (gain, shading, gamma). We have not confirmed this with the vendor but the pattern is consistent.
* **Block sizes** vary by sensor family but IDs remain stable, which means the parser/callback layer can be generic.
* Some blobs (e.g. `isp_h42.conf`) have smaller 3D-NR sections, while others (`isp_sc1135.conf`) pack significantly larger NR/sharpness tables—the offsets remain unchanged, only the payload content grows.

## 6. Known unknowns / TODO

* The file preamble is still undocumented. Capturing it from the Windows ISP tool (or diffing exports from multiple revisions) might reveal explicit version fields.
* The precise semantics of pack 0 vs pack 1 need to be validated on hardware (log ISP gain/exposure after switching lighting conditions).
* Some sensors only ship `0x1B` while others use `0x1C`; we assume both map to the same sensor-load ioctl, but we should confirm whether the difference is meaningful (e.g. parallel vs. MIPI sensors).
* No blocks beyond `0x1C` have been observed; if future blobs introduce new features, the dispatcher in `isp_device.c` must be extended.

## 7. References

* `src/lib/isp/parse_conf.c` – low-level parser used by CLI and runtime.
* `src/lib/isp/isp_device.c` – block-to-`ak_isp_*` mapping documented above.
* `docs/reference/isp/isp_block_catalog.md` – per-block metadata, offsets and statistics.
* `docs/reference/tools/isp_tool_notes.md` – workflow for the vendor GUI that produces these `.conf` packs.
* `build/bin/ak3918_dump_isp_conf` – CLI utility to inspect packs, blocks, and payloads (`--pack`, `--id`, `--hexdump`).

Document last updated: 2025-10-06. EOF

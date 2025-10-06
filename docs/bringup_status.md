# AK3918EV200 Bring-Up Status (2025-10-06)

## 1. Vendor pipeline: what we observe

All references come from the IPC traces under `data/logs/ipc/…` (mostly `ipc_multimedia_controller.log`, `ipc_trace*.log`, `ipc-vitrace.log`) and from the decompiled helpers in `vendor/decompiled/ipc.c` and related sources.

### Device bring-up order
1. `open("/dev/ion", O_RDWR)` → reserve/map ~24 MiB DMABUF (ioctls `ION_IOC_ALLOC`, `ION_IOC_MAP`).
2. `open("/dev/isp_char", O_RDWR)` → all ISP/VENC control ioctls go through this fd.
3. `open("/dev/video0", O_RDWR|O_NONBLOCK)`.
4. `open("/dev/uio0", O_RDWR)` (encoder registers and IRQ).
5. `open("/dev/akpcm_cdev0", O_RDWR)` (speaker path).
6. `open("/dev/akpcm_cdev1", O_RDWR)` (mic path).

### `/dev/isp_char` ioctls before streaming
The vendor issues **39 unique requests** (many repeated) before the first interrupt from `/dev/uio0`. The first block is a burst that loads every ISP module:

```
0x40044902, 0x40044904, 0x4004490A, 0x4004490C,
0x4004492B, 0x4004492F, 0x40044906, 0x4004490E,
0x4004491A, 0x40044912, 0x40044936, 0x4004491B,
0x40044925, 0x40044927, 0x4004493B, 0x40044939,
0x4004493F, 0x40044941, 0x40044910, 0x4004495E,
0x40044960, 0x40044953, 0x40044963, 0x40044955,
0x40044973, 0x40044943, 0x40044946, 0x40044949,
0x4004494C, 0x4004494E, 0x40044950, 0x4004497A,
0x4004496E, 0x40044975, 0x40044977, 0x40044969,
0x40044967, 0x4004496D, 0x40044972
```

Most of them correspond 1:1 with `ak_isp_set_*` wrappers (check `include/ak3918/sdk/akispsdk.h` and `src/lib/isp/isp_device.c`). In particular:

- `0x40044969` / `0x4004496D` are the user-parameter uploads (executed periodically while streaming).
- `0x40044967` loads the 3D-NR reference tables.
- `0x4004496E` sets the sensor FPS.
- The rest configure BLC, LSC, NR1/NR2/3DNR, sharpness, mask areas, AWB/AWB-EX/MWB, histograms, contrast/saturation/effect, etc.

The vendor always performs this burst **after** loading the `.conf` pack and **before** enabling `/dev/uio0` interrupts.

### Audio paths
After opening `akpcm_cdev0/1`, the IPC configures each device via a fixed sequence of ioctls (visible in `ipc_multimedia_controller.log` and mirrored in the decompiled vendor routines under `vendor/decompiled/ipc.c`). Highlights:

- Mic (`/dev/akpcm_cdev1`): `0x40045010`, `0x40045070`, `0x40045030`, `0x50e3`, `0x40045088`, `0x50e2`, `0x401c50f2` (28-byte struct at 48 kHz), `0x50e0`, `0x804050f0`, `0x50e2`, `0x50e1`, `0x80045085`, `0x40045086`.
- Speaker (`/dev/akpcm_cdev0`): `0x40045081`, `0x50e3`, two `0x40045030` writes, `0x40045010`, `0x40045070`, `0x50e2`, `0x401c50f2`, `0x50e0`, `0x804050f0`, `0x801c50f2`, two `0x8004501x` reads, another `0x50e3`.

These sequences appear necessary for the encoder to become active even if we are not capturing audio.

### Encoder/U   IO registers
From the vendor preloads (`data/logs/ipc/venc/uio_venc.log`):

- After the `UIO_SET_TRIPLE` burst, the hardware programs Base A/B to `0x80c50000` and `0x80d4c800` (physical ring windows inside the ION buffer).
- `REG_UNITS256_A = 920` → slot size = 920 × 256 = **235 520** bytes. Each IRQ advances the write pointer by ±0x39800.
- `REG_PARAM_LEN` holds the actual payload size for the current frame (typically 2–6 KB).
- `REG_IRQ_STATUS` bit0 toggles per frame and must be cleared by writing `st & ~1`.
- Frames arrive only after `/dev/isp_char` has received the complete configuration burst.

## 2. Our `ak3918_video_dump` tool: current behavior

✅ Reproduces:
- Device open order (ion → isp_char → video0 → uio0 → akpcm0/1).
- Loads the `.conf` pack, 3D-NR blob, and user params.
- Configures `/dev/akpcm_cdev0` and `/dev/akpcm_cdev1` with the same ioctl sequence as the vendor.
- Forces encoder bases to `0x80c50000` / `0x80d4c800`, uses `units256` to compute the slot size, and writes only the `REG_PARAM_LEN` bytes.

⚠️ Missing pieces:
- The burst of ISP ioctls (`0x40044902 … 0x40044972`). Without replaying that block, `/dev/uio0` never raises the first IRQ (our logs show only the initial `UIO_SET_TRIPLE`).
- The periodic `0x4004496D` refresh that the vendor issues while streaming.
- Verification that each payload matches what the driver expects (some structures include offsets or little-endian words that the vendor patches at runtime; we currently send the raw blob once).
- Detailed documentation for each payload/structure (e.g., layout of `user_params`, 3D-NR tables, mask areas, etc.).

## 3. Next actions

1. **Map every ISP ioctl payload.** Extract the byte sequences from the vendor (either from the `.conf` machinery or from auxiliary blobs) so we can replay them in our tool. Document the structure alongside the driver fields.
2. **Implement an ISP replayer** inside `ak3918_video_dump` that mirrors the vendor sequence (`ak_isp_set_*` calls) before entering the IRQ loop.
3. **Monitor `/dev/uio0`** with the preloader once the replayer is in place; we expect to see the same `[VENC] slot=235520 … len=…` lines and `.h264` should grow.
4. **Document each structure.** As we reverse the payloads, record the meaning of each field (consult `linux-3.4.35/drivers/media/` patches in this repo for authoritative definitions).

This document will be updated as soon as we decode and replay the missing ISP calls.

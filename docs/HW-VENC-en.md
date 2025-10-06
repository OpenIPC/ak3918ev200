# AK3918EV200 — H.264 Encoder (/dev/uio0) — Bring‑Up & Bitstream Extraction Guide

**Author:** Abel Romero · **License:** MIT

This document consolidates what we **inferred from traces** (LD_PRELOAD on `/dev/uio0`) and **verified in the decompiler** for the **AK3918EV200** SoC. It is a **practical map** to initialize the H.264 encoder, understand its **buffer organization**, and **extract the bitstream** directly from ION/DMABUF **without scanning** for start codes.

---

## Quick summary

- **MMIO via `/dev/uio0`**: ~`0x500`‑byte window (on many boards `map0/size` ≈ `0x430`).  
- **Two bitstream rings** (A/B), each within a **1 MiB window** inside the large ION DMABUF.  
- **Write pointers** per ring: regs **`0x1C`** (A) and **`0x20`** (B). Windows are set/reset through a **triple‑word ioctl (REG, OFFSET, SIZE)**.  
- **IRQ register**: **`0x38`** (read then **ack** by clearing the bit).  
- **Produced block size**:  
  - A: reg **`0x98`** publishes size in **256‑byte units** (observed in traces).  
  - B: the “twin” is not obvious in the binary, but **`wp_B` jumps** confirm 256B slotting (e.g., `0x1CC00` = 460×256).  
- **RAW ring (VI/ISP→VENC)**: regs **`0x2C/0x30/0x34`** rotate exactly by **`0x233000`** (2,306,048) per buffer (our V4L2 `enqueue_len`).  
- **Bitstream bases**: reg **`0x14`** (A) and **likely** `0x18` (B).  
- Reg **`0x60`**: initialized with `width>>1`, **observed at runtime** to reflect **payload bytes**.

> Many registers are **mirrored** starting at `0x200` (shadow/duplicate view).

---

## MMIO and offset convention (bytes vs words)

The binary uses helpers `write32(ctx, off, val)` and `read32(ctx, off)` (friendly names for `FUN_000bb8f0` and `FUN_000bba64`).  
- Callers that hold **register indices** in **words** first apply **`<< 2`** and pass a **byte offset**.  
- The read helper aligns via `off & ~3` and dereferences `*(base + byte_off)`.

**Conclusion**: offsets in this guide (`0x14`, `0x1C`, `0x20`, `0x38`, `0x60`, `0x98`, …) are **byte offsets** and match your MMIO dumps.

---

## Register map (offset from MMIO base)

| Off | R/W | Description                                                                 |
|:---:|:---:|------------------------------------------------------------------------------|
| 0x14|  W  | **Bitstream base A** (DMABUF base address)                                   |
| 0x18|  W? | **Bitstream base B** (build‑dependent; verify)                               |
| 0x1C| R/W | **Write pointer A** (within 1 MiB window, in 256‑B slots)                    |
| 0x20| R/W | **Write pointer B** (same as 0x1C for the second ring)                       |
| 0x38| R/W | **IRQ status**; read then **ack** (write `value & ~1`)                       |
| 0x60| R/W | **Multi‑purpose**: init `width>>1`; at runtime seen as **payload_len** bytes |
| 0x98|  R  | **Block size A** in **256‑byte units** (e.g., `0x398` → `0x39800`)           |
|0x2C/0x30/0x34| R | **RAW ring** pointers; rotate in steps of `0x233000` (V4L2 buffer size) |
|0x200..| – | **Mirror** of 0x000.. (shadow/duplicate view)                                |

> **MMIO window size**: on UIO `map0/size` is often ~`0x430`. Avoid reading past that.

---

## Initialization sequence (decompiler ↔ traces)

**Functions (friendly names):**  
- `FUN_000b0ae4` → *encoder_reset_windows* (configure 1 MiB windows and reset write pointers).  
- `FUN_000b82a4` → *encoder_setup_base_and_params* (program `0x14` and `0x60`).  
- `FUN_000bbc60` → *irq_ack* (read/write `0x38`).  
- `FUN_000bb8f0` → *write32(ctx, byte_off, val)*.  
- `FUN_000bba64` → *read32(ctx, byte_off)*.

**Ring programming (observed as “3×32 ioctl”):**

1. Define 1 MiB windows (A & B) and reset pointers:  
   ```text
   (REG=0x0800001C, OFFSET=0x00100000, SIZE=0x00100000)
   (REG=0x08000020, OFFSET=0x00100000, SIZE=0x00100000)
   (REG=0x0800001C, OFFSET=0x00000000, SIZE=0x00100000)  // reset wp
   (REG=0x08000020, OFFSET=0x00000000, SIZE=0x00100000)  // reset wp
   ```
2. Load **bitstream base** and **params**:  
   ```c
   write32(mmio, 0x14, base_A);          // from setup structure
   write32(mmio, 0x60, width >> 1);      // later observed as payload_len
   // base_B via 0x18 if applicable
   ```

**Practical notes**  
- Some builds perform **two mmaps** of `/dev/uio0`: one **R/O** (~0x430) and another **R/W** (~0x500), both returning the **same VA**; respect protection.  
- Several registers are **read‑only** (e.g., `0x98`).

---

## Runtime loop (IRQ → read → copy → ack)

1. **Wait for IRQ**: `select/epoll` on `/dev/uio0`.  
2. **Handle IRQ**: `ioctl(uio0, AKUIO_WAIT_IRQ)` (or `read(uio0)` depending on driver).  
3. **Read key regs**:  
   ```c
   baseA = RD32(mmio+0x14);
   wpA   = RD32(mmio+0x1C);
   unitsA= RD32(mmio+0x98) & 0xFFF;      // A block size in 256‑B units
   len   = RD32(mmio+0x60);              // actual payload bytes
   // For B: wpB = RD32(mmio+0x20); (and find the “unitsB” twin near 0x98)
   ```
4. **Locate within 1 MiB window** and **copy** from DMABUF:  
   ```c
   off   = wpA & 0xFFFFF;                // wp % 1MiB
   addr  = baseA + off;                  // start of hardware block (adjust if WP points past end)
   slotB = unitsA * 256;                 // hardware slot size for A
   src   = dmabuf + addr - len;          // adjust depending on advance direction
   write(out_h264, src, len);
   ```
5. **Ack IRQ**: clear bit in `0x38`.  
   ```c
   st = RD32(mmio+0x38);
   WR32(mmio+0x38, st & ~1);
   ```

> **Important**: read MMIO **after** the `ioctl` that services the event; avoid dumping immediately after `select()`.

---

## RAW ring (V4L2 correlation)

- Initial userptr enqueues: **`len=0x233000`**, subsequent DQBUF around **`0x151800` (1382400)**.  
- MMIO `0x2C/0x30/0x34` rotate by **`0x233000`**, matching the **capture ring** feeding the encoder.  
- Not required for bitstream extraction, but useful for **synchronization debugging**.

---

## Safety & best practices

- **Do not read** beyond `map0/size` (≈ `0x430` on your board).  
- Before any dump, **verify** `[g_va..g_va+g_len)` is mapped/readable (`/proc/self/maps`).  
- Avoid MMIO reads at `select()` return; **dump after the `ioctl`** that handles the IRQ.  
- If the process does `munmap/mremap/exec`, your VA is invalid: rediscover mapping.

---

## Conclusion

With **`0x14/0x18` (bases), `0x1C/0x20` (write pointers), `0x98` (256‑B slot units, A), `0x60` (payload_len)** and the **IRQ at `0x38`**, we can **extract H.264** directly from DMABUF **without scanning NALs**, for both **main** (A) and **substream** (B). The decompiler confirms **1 MiB window programming** via the 3×32 ioctl and the **ack routine**. RAW ring data matches V4L2 (`0x233000`). What remains is to **integrate the copy loop** into `stream_setup_test_CLEAN.c` right after `AKUIO_WAIT_IRQ`.

---

## Handy C constants

```c
#define MMIO_BASE_SIZE     0x500    // map0 often ~0x430
#define REG_BASE_A         0x14
#define REG_BASE_B         0x18
#define REG_WP_A           0x1C
#define REG_WP_B           0x20
#define REG_IRQ_STATUS     0x38
#define REG_PARAM_LEN      0x60     // init: width>>1; runtime: payload_len
#define REG_UNITS256_A     0x98     // A block size = (RD32 & 0xFFF) * 256

#define RING_WINDOW_BYTES  0x100000
#define RAW_STEP_BYTES     0x233000
```

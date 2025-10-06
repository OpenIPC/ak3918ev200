# AGENTS.md

**Project:** OpenIPC AK3918EV200 (Codex)  
**Goal:** Make OpenIPC-style userspace work reliably on Anyka **AK3918EV200** SoCs: bring up the ISP pipeline, drain the H.264 encoder, and persist streams to SD, with optional audio.  
**Author:** Abel Romero  
**License:** MIT

---

## 1) Overview

This document defines the **agents** (processes/threads/modules) and their responsibilities, inputs/outputs, and interfaces to the device nodes and SDK wrappers we use. It is written for contributors joining the Codex effort so they can understand *who does what* in our runtime.

### Key device nodes

- `/dev/video0` — V4L2 capture (must be opened to make the ISP happy).
- `/dev/isp_char` — ISP control plane (AK_ISP_* ioctls).
- `/dev/uio0` — H.264 encoder (IRQ + MMIO window; ring buffer of encoded frames).
- `/dev/ion` — DMA/DMABUF allocation (shared buffers).
- `/dev/akpcm_cdev0` — speaker (PCM out).
- `/dev/akpcm_cdev1` — microphone (PCM in).

### Filesystem layout (target camera)

- Persistent data: `/mnt/disc1`  
- Binaries, libs, configs: `/mnt/bin`  
- Use `/tmp` **only** for scratch/ephemeral data.

---

## 2) Agent map (who does what)

> Each agent is a self-contained unit. Some are threads inside the same process; others can be stand-alone binaries. The names below map to current source files where applicable.

### A. **ISP Config Agent**  
**Purpose:** Parse sensor `.conf` files and apply all ISP blocks in the correct order.

- **Inputs:** Sensor `.conf` blob (all vendors), pack & subpack structure.  
- **Outputs:** Series of `AK_ISP_*` ioctls to `/dev/isp_char`.  
- **Key rules:**
  - Subpack header is `{ uint16_t id; uint16_t size; }`.
  - The last subpack is **sensor load**; for `Ak_ISP_Sensor_Load_Conf` the SDK expects **size in 32-bit words of (payload + 4)** and a pointer to **payload** (without the subpack header).
  - Most other `AK_ISP_*` setters take **payload only** (no header).
- **Code:**  
  - `src/conf/parse_isp_conf.c` — walks packs/subpacks and invokes a callback.  
  - `src/isp/apply_isp_conf.c` — switch over subpack `id` → calls `ak_isp_*` wrappers.  
  - `include/akispsdk.h` — externs for all `AK_ISP_*`/`Ak_ISP_*`.

### B. **Device Bring-Up Agent**  
**Purpose:** Open devices in the right order and keep them alive.

- **Order (current best-known):**  
  1. Open `/dev/video0` (enables ISP data path).  
  2. Open `/dev/isp_char` (control).  
  3. Open `/dev/uio0` (encoder interrupts/MMIO).  
  4. Open `/dev/ion` (buffers).  
- **Also:** Set non-blocking where appropriate, install signal pipe for clean shutdowns.

### C. **ION/DMABUF Agent**  
**Purpose:** Allocate and track physically contiguous buffers for video pipeline and encoder.

- **Inputs:** Requested sizes from pipeline; alignment constraints.
- **Outputs:** DMABUF fds, exported to V4L2 or encoder as needed.
- **Notes:** Keep allocations small; devices are memory-constrained. Persist allocation metadata to `/mnt/disc1` if you need to re-use across restarts.

### D. **Encoder (UIO) Agent**  
**Purpose:** Drain encoded H.264 frames from the hardware ring through `/dev/uio0`.

- **UIO workflow (generic):**  
  1. `mmap()` the UIO region(s) to read encoder registers/ring descriptors.  
  2. `read(uio_fd, &irq_cnt, 4)` blocks until an IRQ (frame ready).  
  3. Parse head/tail and frame length fields; copy the encoded frame out.  
  4. `write(uio_fd, &ack, 4)` to re-enable IRQs (standard UIO pattern).  
- **SDK helpers:** `ak_uio_wait_irq()` now understands the vendor `uio_video_codec`
  ioctls (`AK_UIO_SYSREG_WRITE`, cache invalidation, alt IRQ waits). See
  `include/ak3918/video.h`, `src/lib/video/uio.c`, and `docs/sdk/ak3918_sdk_notes.md`
  before touching encoder registers.  
- **Outputs:** H.264 access units written to `/mnt/disc1/stream/` or a FIFO/UDP.  
- **Open items:** Exact offsets for head/tail/len registers are hardware-specific; we correlate *uio0 dump* and vendor *ipc* traces to finalize these (see §7).

### E. **V4L2 Agent**  
**Purpose:** Maintain the capture pipeline running (enqueue/dequeue loop) so the ISP/encoder keep producing.

- **Notes:** Even if we don’t save RAW, keep the QBUF/DQBUF loop alive at a modest depth. The vendor pipeline does this; starving queues can stall the encoder.

### F. **Audio Agents (optional)**  
**Mic Agent** (`/dev/akpcm_cdev1`) and **Speaker Agent** (`/dev/akpcm_cdev0`)

- **Purpose:** Provide synchronized PCM capture/playback when needed.  
- **Notes:** Both devices require an `ioctl()` configuration step **before** streaming. For development builds where we don’t want audio I/O, **comment out** the read/write loops after setup (we keep setup to validate the path). Keep the private ioctls documented in `docs/sdk/ak3918_sdk_notes.md#audio-codec-devakpcm_cdev0-devakpcm_cdev1` close by—codec mode/source clocks must be staged exactly in that order.

### G. **Trace/Hook Agent** (LD_PRELOAD)  
**Purpose:** Interpose `open/ioctl/mmap/read/write/...` to learn the vendor’s parameters and to dump structured payloads on selected ioctls.

- **Artifacts:** `ioctl_dump_map.txt` supports `(req, direction, dumps, struct_mode)`; for `0x40044969` (sensor load) we enable *struct mode* to follow the detected `struct blob_desc { uint32_t nwords; void* ptr; }`.

### H. **Supervisor Agent**  
**Purpose:** Orchestrate startup/shutdown of all agents, handle retries, and move logs to `/mnt/disc1/logs`.

---

## 3) Runtime flow (happy path)

1. **Open devices** in order (Video0 → ISP → UIO → ION).  
2. **Apply ISP config** (packs/subpacks) using `parse_isp_conf` callback → `apply_isp_conf`:
   - For most ids: call corresponding `AK_ISP_set_*` with `payload`.  
   - For sensor load: compute `(payload_bytes + 4) / 4` and pass pointer to `payload`.  
3. **Start V4L2 loop** with a small buffer queue (prevent stalls).  
4. **Start Encoder Agent**: block on `/dev/uio0` IRQs, consume frames from ring, write `.h264` segments to `/mnt/disc1/` (or mux later if desired).  
5. (Optional) **Audio setup** only (no continuous I/O unless required).  
6. **Monitor**: basic counters (frames/second, IRQs, queue depth), and rotate logs.

---

## 4) Interfaces (minimal contracts)

- **ISP wrappers:** Each `ak_isp_*` wrapper takes a `void* payload` already pointing to the subpack body (no header).  
- **Sensor load:** `ak_isp_sensor_load_conf(nwords, ptr)` where `nwords = (payload_len + 4) / 4`.  
- **UIO encoder:** `uio_encoder_wait_and_drain()` returns one complete H.264 frame (Annex B), or 0 if spurious, or negative on error.  
- **V4L2:** `v4l2_maintain_pipeline()` keeps QBUF/DQBUF running; it does **not** write frames to disk (we don’t want RAW to SD).
- **GPIO / Aux:** Use the helpers in `include/ak3918/gpio.h` (`ak_gpio_*`) to drive LEDs, IR-cut, limit switches, etc. Stepper motion now has first-party wrappers in `include/ak3918/motor.h` (`ak_motor_*`). The platform wiring for motors, IR, Wi-Fi and sensors is summarised in `docs/sdk/ak3918_sdk_notes.md`.

---

## 5) Logging & persistence

- Write all binary dumps, traces, and resulting `.h264` chunks to **`/mnt/disc1`**.  
- Avoid `/tmp` for anything you’ll need after a reboot.  
- Keep dumps small: by default **4096–8192 bytes** per capture unless explicitly unbounded for short sessions.

---

## 6) Deliverables (current modules & expected roles)

- `include/akispsdk.h` — declarations for all `AK_ISP_*`/`Ak_ISP_*`.  
- `src/conf/parse_isp_conf.c` — generic parser (callback-driven).  
- `src/isp/apply_isp_conf.c` — maps subpack IDs → SDK calls (no TRY/PAYLOAD_OK macros; direct calls with corrected offsets).  
- `src/stream/stream_setup_test.c` — opens devices in order and spins agents.  
- `src/audio/capture_akpcm.c`, `src/audio/play_akpcm.c` — audio setup examples (loops may be disabled).  
- `tools/ldpreload/*` — ioctl dumper + wrappers (prints args/returns; special handling for `0x40044969`).  
- Logs/dumps: `ipc__traces.log*`, `uio0_dump.log`, `nr_map.txt` (nr→function map).

---

## 7) Known facts vs. unknowns (T-chart)

**Known / confirmed**
- `/dev/video0` must be opened for ISP/encoder to operate.  
- ISP subpacks: header `{id,size}`, ids commonly `0x00..0x18`, sometimes jump to `0x1B/0x1C`.  
- `Ak_ISP_Sensor_Load_Conf` requires **payload size in words + one extra word** and a pointer to the payload body (no header).  
- Many `AK_ISP_*` setters take payload with **+0x4** offset relative to subpack start in vendor blobs; our parser already strips headers, so we pass `payload` directly.

**Unknown / under validation**
- Exact **UIO ring registers** (head/tail/size/IRQ ack) offsets for AK3918EV200 variants. We follow standard UIO semantics: `read()` to wait, `write()` to re-enable, `mmap()` for registers and ring. Correlation between `uio0_dump.log` and vendor IPC trace is ongoing; adjust offsets as you test on your board.
- Whether audio has any hidden dependency on the encoder path. So far, ISP/encoder proceed without audio streaming as long as initialization ioctls are issued.

---

## 8) How to contribute

1. Keep changes **local and incremental**: do not refactor the whole program unless unavoidable.  
2. Preserve **call order** and **payload lengths** exactly as the vendor does; annotate any deviation.  
3. For new sensors: add a small `.conf` explainer (pack/subpack list, unusual ids).  
4. If you add I/O that persists across reboots, write to `/mnt/disc1`.  
5. Respect the **dump size limits** unless debugging a single, very short path.  
6. Comment your code generously; readability over cleverness.  
7. **Lee la documentación**: empieza por `docs/reference/ak3918_reference_catalog.md`
   (traducciones/resúmenes de los PDFs en `downloaded/`) y complementa con
   `docs/sdk/ak3918_sdk_notes.md` para detalles de ISP, UIO y cachés.

---

## 9) Quick runbook

- **Build:** cross-compile for ARM/uClibc; static where feasible for tools.  
- **Deploy:** copy artifacts to `/mnt/bin`; configs to `/mnt/disc1`.  
- **Run:**  
  - `stream_setup_test` (or your supervisor)  
  - Check logs in `/mnt/disc1/logs`  
  - Confirm ISP ok (no errors from `AK_ISP_*`), then watch for `/dev/uio0` IRQ increments and emitted `.h264` files in `/mnt/disc1/stream/`.  
- **Troubleshoot:**  
  - If no frames: ensure `/dev/video0` open and V4L2 agent running.  
  - If encoder silent: verify UIO `read()` unblocks; if not, re-enable with a `write()` and confirm MMIO region mapping.  
  - Use LD_PRELOAD wrappers to compare our ioctls with vendor IPC.

---

## 10) Roadmap (short list)

- [ ] Finalize UIO register map and ring descriptor layout for AK3918EV200.  
- [ ] Add lightweight MP4/TS muxer (optional), keeping raw `.h264` option.  
- [ ] Sensor matrix: test multiple `.conf` formats; document per-sensor quirks.  
- [ ] Minimal CLI: start/stop agents, select sensor pack, set FPS, dump stats.  
- [ ] Continuous integration for cross-builds.

---

## 11) Contacts

- **Codex contributors:** open una PR o discusión en el repositorio OpenIPC:
  - `https://github.com/OpenIPC/ak3918ev200`

Please keep discussions technical and reproducible (logs, exact binaries, steps).

---

*Let’s keep it simple, readable, and faithful to the hardware. Small, verifiable steps beat big rewrites.*

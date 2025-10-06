# OpenIPC AK3918EV200 Payload (2025-02 build)

This bundle contains everything we have validated while reverse engineering the
AK3918EV200 firmware, including the Anyka 3.4.35 kernel sources, decompiled
userland, SDK headers, libraries, tools, and documentation.

## Top-level files

- `README.md` – project overview and current module list.
- `AGENTS.md` – agent map for the OpenIPC runtime.
- `LICENSE` – MIT license for all userland artefacts.
- `Makefile` – builds `libak3918.a` and the sample utilities.
- `kernel_patch_difflist.txt`, `kernel_patched_filepaths.txt` – helper lists for
  kernel patch tracking.

## Directories

- `conf/` – ISP sensor packs (`*.conf`) and notes.
- `data/` – captured ISP blobs, logs (IPC, ISP, UIO, audio, system).
- `docs/` – runbooks, SDK notes, hardware references, translations.
- `include/` – public SDK headers (audio, video, ISP, GPIO, ION, motors…).
- `ld_preload/` – tracing helpers (IPC/encoder/ioctl instrumentation).
- `patches/` – Anyka kernel patches and fixes used on the reference board.
- `src/` – userland libraries and sample apps (`ak3918_video_dump`, audio tools,
  ISP inspectors, motor tests, etc.).
- `toolchain/` – metadata for the cross-compilation environment.
- `tools/` – analysis utilities, type extractors, new LD_PRELOAD tracer.
- `vendor/` – vendor drops:
  - `linux-3.4.35` (vanilla kernel).
  - `linux-3.4.35-vanilla`, `linux-3.4.35-ak3918-diff` (patched sources).
  - `decompiled/` (Anyka IPC, SDK libraries, auxiliary tools).
  - `bin/` (original binaries where available).

## Notes

- Userland blobs (`isp_3dnr_ref_attr`, `isp_user_params`) are preserved for
  reference but not yet replayed automatically—the current code documents the
  missing structure.
- The new LD_PRELOAD tracer can be built with `make` under `ld_preload/` and
  injected via `LD_PRELOAD` to capture V4L2/UIO activity.
- Kernel sources are unmodified; compare against the patch list above before
  rebuilding.

Copy this tree into a fresh clone of `github.com/OpenIPC/ak3918ev200`, verify
builds (`make`), and run hardware smoke tests before publishing.

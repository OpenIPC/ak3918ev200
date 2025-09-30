# AK3918EV200 ISP Reverse Engineering

This repository contains research, tools, and experiments around the Image Signal Processor (ISP) used in AK3918EV200-based IP cameras.  
The project documents the initialization sequence, driver interactions, and ioctl payloads extracted from the vendor firmware and SDK.

## Contents

- **Decompiled SDK analysis**  
  Mapping of ioctl request codes (`NR`, `type`, `size`) to ISP functions with offsets and payload structure references.

- **Binary payload dumps**  
  Real captured blobs for calls like:
  - `Ak_ISP_Set_User_Params`
  - `AK_ISP_set_3d_nr_ref_attr`

- **C tools**  
  - Parser for `.conf` ISP configuration files.  
  - Replay tools to reproduce ioctl sequences from logs.  
  - `LD_PRELOAD` hooks to intercept, dump, and inject ISP payloads.

- **Python scripts**  
  Helpers to extract symbol-to-offset mappings from decompiled sources and build tables associating `case id` → `symbol + offset`.

- **Logs and traces**  
  - `jump_tap4.log`, `akisp_tap-completo.log` – raw syscall traces during bring-up and video capture.  
  - Useful for replicating real hardware behavior.

## Goals

- Document the closed-source ISP API and its configuration workflow.  
- Provide reproducible examples to initialize the video pipeline, configure noise reduction, histograms, AWB, exposure, etc.  
- Serve as a base for further research in embedded security, custom firmware, and video processing.

## Disclaimer

This project is for **educational and research purposes only**.  
It is not affiliated with the vendor, and comes with **no warranty**.  
Use responsibly.

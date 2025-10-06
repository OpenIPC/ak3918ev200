# AK39 Audio/Video Library Overview

Source: `音视频库总体使用说明_V1.0.0.pdf`

## English summary
High-level manual describing Anyka's multimedia framework for AK39: how audio/video capture, encoding, streaming, playback, and storage modules interact.

## Main components
- **Capture modules**: Video capture (ISP/V4L2), audio capture (`akpcm`), sensor drivers.
- **Processing**: Video encoder (H.264/MJPEG), audio encoder (AAC/G.711), motion detection module, OSD overlay.
- **Networking**: RTSP/HTTP streaming, cloud service hooks, local recording.
- **Control flow**: State machine for live preview, recording, playback, and configuration updates.

## OpenIPC integration
- Use diagrams to validate our AGENTS separation (ISP, V4L2, encoder, audio) and ensure consistent terminology.
- Identify modules we must replace with open equivalents (e.g., RTSP server, OSD overlays) and track progress in roadmap.
- Build test scenarios mirroring vendor workflow: start capture → stream → record → playback.

## TODO
- Summarize message queues and shared memory segments described in manual; map to our runtime design.
- Extract configuration file structure if referenced (likely under `/etc/anyka/` in vendor firmware).

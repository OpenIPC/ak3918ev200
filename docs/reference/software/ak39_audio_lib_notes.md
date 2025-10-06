# AK39 Audio Library & Echo Cancellation Notes

Sources:
- `音频库接口说明_v1.0.0.pdf`
- `回声消除库接口说明V1.0.0.pdf`

## English summary
The audio library manual explains APIs for playback and capture on AK39, while the echo cancellation (AEC) manual documents the vendor DSP for full-duplex audio.

## Core API concepts
- **Initialization**: Functions to open playback/capture handles, configure sample rate (8/16/32/48 kHz), channel count, bit depth.
- **Buffering**: Callbacks for providing PCM frames (playback) and receiving captured data; includes ring-buffer pointers and recommended sizes.
- **Controls**: Volume, mute, AGC parameters, input gain, output attenuation.
- **AEC module**: Requires simultaneous mic & speaker streams; exposes `AK_AEC_Init`, `AK_AEC_DoProcess`, `AK_AEC_SetParam`. Parameters include tail length, echo path delay, noise suppression.
- **Resampling**: Library offers resampler utilities to convert between 8 kHz telephony and 16 kHz capture.

## OpenIPC integration
- Document expected device nodes (`/dev/akpcm_cdev0` speaker, `/dev/akpcm_cdev1` mic) and align our audio agents accordingly.
- Evaluate whether AEC library can be replaced by open-source solutions; note licensing concerns if vendor binary required.
- Provide sample code in SDK to configure full-duplex audio with optional AEC, referencing parameter ranges from manual.

## TODO
- Translate parameter tables (gain, AGC levels) into markdown for quick reference.
- Implement runtime checks to ensure resampler settings match supported sample rates.

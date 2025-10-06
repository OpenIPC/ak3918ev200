# AK39 Video Driver Library Notes

Source: `AK39视频驱动库接口说明_V1.1.0.pdf`

## English summary
API manual for the proprietary video driver library powering H.264 encoding on Anyka AK39 platforms. Provides module overview, integration steps, data structures, and function descriptions.

## Key APIs & structures
- **Initialization**: `VideoStream_Enc_Init`, `VideoStream_Enc_Open`, `VideoStream_Enc_Close`, `VideoStream_Enc_Reset`.
- **Encoding loop**: `VideoStream_Enc_Encode` accepts input buffer struct (raw frame info, timestamps) and produces encoded bitstream pointers; supports callbacks for buffer allocation.
- **Rate control**: `VideoStream_Enc_setRC` configures CBR/VBR parameters, QP range, GOP length.
- **Data structures**: Defines encoder open params (resolution, frame rate, bitrate, profile, GOP), input frame descriptor (YUV plane pointers, stride), callback prototypes for MMU/ION integration.
- **Integration flow**: Acquire library, implement system API dependencies (memory allocation, logging, timer), link with application.
- **FAQ**: Address dual-channel encoding conflicts, buffer underruns, rate-control tuning.

## OpenIPC implications
- Map struct fields to our UIO/encoder agent: ensure we replicate expected metadata (frame type, timestamp) when draining hardware buffers.
- Document rate control parameters in `include/ak3918/video.h`; align with vendor defaults for stability.
- Provide wrappers or translation layer for community apps migrating from vendor library to our open implementation.

## TODO
- Translate struct definitions verbatim to ensure no field mismatch; compare with our existing header.
- Investigate whether library expects special alignment/padding (document in SDK if so).

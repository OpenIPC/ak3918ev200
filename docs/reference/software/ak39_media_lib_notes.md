# AK39 Media Parser/Composer/Playback Library Notes

Sources:
- `媒体解析库接口说明_v1.0.0.pdf`
- `媒体合成库接口说明_V1.0.0.pdf`
- `媒体播放库接口说明_v1.0.0.pdf`

## English summary
These manuals describe vendor middleware for working with multimedia containers (TS, MP4, AVI), composing recording files, and playing back audio/video streams on the AK39 platform.

## Key capabilities
- **Parser library**: APIs to demux file streams, extract audio/video tracks, retrieve metadata (duration, codec, resolution). Supports TS, MP4, AVI, proprietary `.rec` format.
- **Composer library**: Functions to create recording files, multiplex audio/video/hints, write index tables, manage segment rotation.
- **Playback library**: High-level interface to feed demuxed frames to decoder/display pipeline, handle trick modes (pause, seek), synchronize audio/video clocks.

## OpenIPC integration
- Use format support information to plan open-source replacements (GStreamer/ffmpeg). Identify vendor-specific `.rec` details for compatibility.
- Document how vendor handles file rotation and indexing; replicate best practices in our recorder agent.
- Consider writing shims to read existing recordings, enabling migration to OpenIPC while preserving legacy footage.

## TODO
- Extract structure definitions for headers/index tables if we later implement compatibility readers.
- Investigate licensing of vendor libraries before redistributing.

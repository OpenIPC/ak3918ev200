# AK39 Motion Detection Library (V2) Notes

Source: `运动检测库V2接口说明_V1.0.0.pdf`

## English summary
Manual for the vendor's motion detection (MD) library, version 2. It details API calls that analyse video frames for motion, configure regions of interest, and tune sensitivity.

## Key API elements
- **Initialization**: `AK_MD_Init` with parameters for frame size, block grid, detection mode (pixel difference vs. background modelling).
- **Configuration**: Set detection regions, sensitivity levels (1–5), noise suppression, and alarm thresholds.
- **Processing**: `AK_MD_Run` accepts luminance frames or downscaled macroblocks; returns per-region flags and global motion score.
- **Callbacks**: Optional function pointers for asynchronous alerts.

## OpenIPC integration
- Our analytics agent can mirror this interface using open methods (OpenCV, motion). Document vendor parameter semantics to ease replacing library while maintaining config compatibility.
- Sensor board includes LDR; combine motion detection with ambient light for smarter alerts (document interplay).

## TODO
- Map vendor grid resolution to actual pixel dimensions for each supported resolution (D1, 720p, 1080p).
- Define JSON schema for motion settings that matches vendor structure for migration purposes.

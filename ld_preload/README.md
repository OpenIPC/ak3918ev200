# AK3918 LD_PRELOAD Tools

This directory keeps the maintained preload helper for tracing the vendor IPC
binary.  Build it with `make` (optionally overriding `CROSS_COMPILE`) to obtain
`ipc_tracer.so`, then follow `docs/ipc_tracer.md` for deployment and runtime
tips.

Older experimental wrappers have been removed to avoid confusion; the current
tracer already covers the device nodes we rely on (`/dev/ion`, `/dev/uio0`,
`/dev/isp_char`, `/dev/video0`, `/dev/akgpio`, `/dev/akpcm_cdev0/1`).

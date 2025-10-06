# IPC Tracer LD_PRELOAD helper

This helper library provides a set of wrappers to instrument the vendor IPC
process on the camera. It intercepts `open`, `ioctl`, `mmap`, poll/select calls
and other interesting syscalls so we can inspect how the proprietary binary
interacts with the ISP and audio drivers.

## Building

```sh
cd ld_preload
make            # produces ipc_tracer.so
```

Cross compilation is supported via the `CROSS_COMPILE` variable, e.g.:

```sh
make CROSS_COMPILE=arm-openipc-linux-musleabi-
```

## Usage

1. Copy `ipc_tracer.so` to the target filesystem.
2. Pick an output file for the trace using `IPC_TRACE_LOG` (default:
   `/tmp/ipc_trace.log`).
3. Optionally tweak the dump length (`IPC_TRACE_DUMP`, bytes) and whether the
   ASCII column is printed (`IPC_TRACE_ASCII=0` disables it).
4. Launch the target process with the library preloaded:

```sh
export IPC_TRACE_LOG=/tmp/ipc_trace.log
export IPC_TRACE_DUMP=512
LD_PRELOAD=/mnt/ipc_tracer.so /usr/bin/ipcdaemon
```

The log captures:

- `open/openat` of relevant device nodes (`/dev/ion`, `/dev/uio0`, `video0`,
  etc.).
- Every `ioctl` on those descriptors with before/after hexdumps when the ioctl
  reads or writes payloads.
- DMA buffer mappings (`mmap/munmap`), read/write payloads and poll/epoll
  activity to understand how queues are driven.

These traces should make it easier to compare our reimplementation with the
vendor firmware and spot missing steps in the video pipeline setup.

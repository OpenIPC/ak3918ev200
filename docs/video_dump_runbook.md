# Video dump bring-up runbook

This runbook documents how to reproduce the vendor firmware's video pipeline
initialisation in order to dump the H.264 bitstream. The sequence below mirrors
the call order recovered from the decompiled blobs under `decompiled/` and shows
how each stage is implemented in the cleaned tooling that ships with this
repository.

## 1. Summary of vendor-side steps

1. **Reserve the encoder ring via ION and map `/dev/uio0`.** The vendor library
   (`libakuio`) reads the reserved size from sysfs, opens `/dev/ion`, performs an
   `ION_IOC_ALLOC/SHARE`, mmaps the buffer and finally opens `/dev/uio0` so the
   encoder registers can be accessed.【F:decompiled/ipc_untouched.c†L124513-L124609】
2. **Open `/dev/video0` and configure V4L2.** The firmware verifies the node,
   applies `VIDIOC_QUERYCAP`, programs format/parms/crop and requests userptr
   buffers before the capture loop starts.【F:decompiled/ipc_untouched.c†L32358-L32580】
3. **Load ISP packs, including the 3D-NR reference.** After calling
   `AK_ISP_sdk_init`, the binary allocates scratch space and invokes
   `AK_ISP_set_3d_nr_ref_attr` so the encoder sees the same denoise tables as in
   production.【F:decompiled/ipc_untouched.c†L33192-L33241】
4. **Pump the encoder IRQs.** The main loop waits on `ioctl(fd_uio0,
   0x80045565, …)` and, once bytes are available, copies the window from the
   circular buffer into the Annex-B file before acknowledging the status
   register.【F:decompiled/ipc_untouched.c†L124962-L125066】

## 2. Reproducing the sequence with `ak3918_video_dump`

`src/apps/video/dump.c` implements a cleaned version of the vendor workflow:

1. **Device bring-up.** The helper opens `/dev/video0`, `/dev/uio0` and reserves
   the encoder ring through `ion_reserve_and_map()` before touching the ISP, just
   like the vendor blob.【F:src/apps/video/dump.c†L253-L314】
2. **ISP configuration.** It calls `ak_isp_sdk_init()`, replays the selected
   `.conf` pack, loads the 3D-NR reference blob and the user parameter payload so
   that the hardware is left in the same state as the stock firmware.【F:src/apps/video/dump.c†L327-L413】
3. **Encoder window configuration.** `venc_context_init()` issues the sequence of
   `UIO_SET_TRIPLE` ioctls, mmaps the register space plus the ring windows and
   seeds the write pointer tracker used to trim the circular buffer.【F:src/apps/video/dump.c†L124-L233】
4. **V4L2 capture.** `setup_v4l2()` mirrors the vendor logic when it validates
   capabilities, applies format/crop and queues user pointer buffers backed by
   the ION allocation.【F:src/apps/video/dump.c†L436-L542】
5. **IRQ-driven drain.** The main loop polls both `/dev/video0` and `/dev/uio0`,
   consuming V4L2 buffers and, whenever the encoder signals bytes ready, copies
   the `[rptr..wptr)` window into the Annex-B output before acknowledging
   `REG_IRQ_STATUS`.【F:src/apps/video/dump.c†L615-L777】

## 3. Building and running

1. Cross-compile the utilities (the default toolchain targets ARM32/uClibc):

   ```bash
   make
   ```

   The binary is placed under `build/bin/ak3918_video_dump` together with the
   other sample applications.

2. Copy the resulting executable plus the ISP blobs from `data/isp_blobs/` to the
   camera filesystem.

3. On the device, execute for example:

   ```bash
   /mnt/bin/ak3918_video_dump \
       --conf /mnt/bin/conf/isp_sc1345_dvp.conf \
       --nr3d /mnt/bin/data/isp_blobs/isp_3dnr_ref_attr_pid518_fd10_req0x40044967_20250930T130454.bin \
       --user /mnt/bin/data/isp_blobs/isp_user_params_pid519_fd10_req0x4004496d_20250930T130029.bin \
       --frames 300 \
       --output /mnt/disc1/dump.h264
   ```

   The tool keeps the ISP/V4L2/encoder pipeline running until the requested
   number of frames have been processed, writing Annex-B data to the output path.

## 4. Notes

- Persistent artefacts should live under `/mnt/disc1`; scratch data can use
  `/tmp` as in the original firmware.
- If your sensor requires a different ISP pack, point `--conf` to the matching
  `.conf` extracted from the firmware.
- The run loop automatically acknowledges encoder IRQs to prevent the status
  register from overflowing, matching the behaviour observed in the vendor
  binary.

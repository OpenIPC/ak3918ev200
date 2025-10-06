# Aimer39 Image Generation Tool Notes

Source: `Aimer39平台镜像文件生成工具使用说明_V1.0.0.pdf`

## English summary
Vendor manual for creating firmware filesystem images (JFFS2, initramfs, SquashFS) used on Aimer39/AK3918 devices.

## Key instructions
- **JFFS2**: Use `mkfs.jffs2 -d <dir> -s 256 -e 4096 -m none -o <out>`; page size fixed at 256 bytes, erase block 4 KB for the bundled GD25Q64 flash.
- **Initramfs**: Vendor scripts `extract.sh` and `create_fs_image.sh` unpack the rootfs tarball and build `rootfs.init`. Requires cpio with `newc` format.
- **SquashFS**: Use `mksquashfs <rootfs> <out> -comp lzma -noappend`; note that rootfs is read-only and paired with JFFS2 overlay for persistence.
- **Deployment**: Toolchain integrates images into package manifest that the vendor upgrade utility expects; partition offsets defined in configuration XML.

## OpenIPC relevance
- Align our build pipeline (Buildroot/OpenWrt) with these partition sizes for compatibility with stock bootloaders.
- Document overlay strategy (SquashFS + JFFS2) for users migrating from vendor firmware; ensure supervisor remount logic respects these partitions.
- Provide equivalents using open-source tools (mkfs.jffs2/mksquashfs) with deterministic options.

## TODO
- Translate vendor XML manifest format and create converter script for OpenIPC packaging (`tools/convert_vendor_manifest.py`, future work).
- Validate large-flash (128 Mb) parameters; update doc when we confirm new eraseblock sizes.

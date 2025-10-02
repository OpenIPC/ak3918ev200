# NOTES

These files contain the parameters required to bring up the ISP pipeline and enable the camera.

Basically, depending on the file for each sensor, they present different structures. Although all of them contain a recognizable type of information.

The algorithm I have found to use them (in theory, since I could only test with my hardware) is to read a sequence of blocks.

These blocks have a structure like the following:

```
[header][payload]
```

where `[header]` is divided into 2 words of 16 bits: `id` and `size`.

Normally, `size` includes the total block size with the header.

They usually follow a sequence from `0` to `0x18` (24 blocks), then they jump to `0x1b`, `0x1c` (and I don’t know which others).

The last block is the sensor configuration.

The sensor configuration is applied with 4 additional bytes (on my hardware, and in theory on all) compared to the block size minus the header.

All payloads are usually applied without the header (only the payload), but in the case of the configuration (`Ak_ISP_Load_Conf`), the full size declared in the header is used, which is confusing because that block has 4 extra bytes (including the header).

Normally, the configuration is applied by calling the dedicated routine from `libakispsdk.so`, which I assume is available in the manufacturer’s firmware.  
I imagine that these dynamic libraries have the raw `ioctl` requests hardcoded for the operation, abstracted by symbols.  
Offsets are typically used on the payload buffer so that, depending on the `id`, one or more symbols are invoked.

In the case of `Load_Conf`, a structure with two 32-bit words is used as a parameter:

```
[number of 32-bit words in the payload][pointer to the payload]
```

In this project’s development, the following structure is used:

```c
struct blob_desc desc = {
    .nwords = (uint32_t)((payload_len + 4) / 4), // as you can see, 4 bytes are added to get one more word
    .ptr    = payload,
};
```

Some calls I had to dump by tracing the IPC software, because they perform calculations and fill structures that I haven’t had time to isolate yet.  
But basically, up to now I’ve managed to dump raw frames from the camera (without cleanup implemented yet). However, these frames appear in green, either because of the format I’m using to replay them, or because that’s how they come.  
Even after trying several formats, I haven’t been able to display the image correctly.

You might think it’s due to bad implementation, but in fact, even when dumping the frames from a dynamic library loaded in the manufacturer’s software, I still couldn’t; they look wrong (green).

This makes me think that:

1. I haven’t found the correct format to replay them, **or**  
2. The raw frames obtained with `DQBUF` through V4L2 cannot be used directly, and instead, the hardware H.264 encoder `/dev/uio0` must be used.

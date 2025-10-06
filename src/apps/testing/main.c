/*
 * stream_setup_test.c — Cleaned & Documented
 * -------------------------------------------
 * Author: Abel Romero
 * License: MIT
 * Project: AK3918EV200_GWELL_V1 / OpenIPC
 *
 * Notes
 * -----
 * - Call order is preserved EXACTLY as in the original.
 * - No functional calls removed. No reordering.
 * - Cosmetic clean-up and documentation to improve readability.
 * - Use /mnt/disc1 and /mnt/bin for persistent data; /tmp is transient.
 *
 * (c) 2025 Abel Romero
 */

// =============================== MIT License ===============================
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =========================================================================

// ---------------------------------------------------------------------------
// Implementation notes (formatting & comments only)
// ---------------------------------------------------------------------------
// • This file keeps your working logic intact. To help future readers, we
//   group the code with section banners and add concise comments to blocks.
// • If you later want deeper refactors (variable renames, factorization into
//   helpers, removal of unused temporaries), we can do that incrementally,
//   running a quick compile after each small change.
// ---------------------------------------------------------------------------



// =========================== BEGIN ORIGINAL CODE ===========================
// Below is your working code, kept 1:1 in call order.
// Minor renames and cosmetic adjustments applied.
// ---------------------------------------------------------------------------
/*
 * AK3918EV200 stream setup skeleton plus test
 * Author: Abel Romero
 * License: MIT
 *
 * Overview
 * --------
 * - Centralizes device open/close and signal-safe shutdown.
 * - stream_setup() runs the bring-up sequence up to the (pending) /dev/uio0 encoder note.
 * - main() handles: start v4l2_queue_thread(), idle loop, and cleanup (STREAMOFF, joins).
 * - V4L2 queue thread uses poll() and USERPTR, logs DQ/Q FPS every 3 seconds.
 *
 * Build
 * -----
 *   arm-...-gcc -Wall -Wextra -O2 -pthread -o stream stream.c
 */

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <poll.h>
#include <pthread.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <linux/videodev2.h>

/* ============================================================
 *                      Global file descriptors
 * ============================================================ */
int fd_ion         = -1;
int fd_isp_char    = -1;
int fd_video0      = -1;
int fd_uio0        = -1;
int fd_akpcm0      = -1; /* spkr out (playback)  */
int fd_akpcm1      = -1; /* mic in (capture) */

/* ============================================================
 *                  Global run/cleanup state
 * ============================================================ */
static volatile sig_atomic_t g_running = 0;   /* 0=stopped, 1=running */
static pthread_t g_v4l2_thread;

static pthread_t g_mic_thread;
static pthread_t g_spkr_thread;
static volatile sig_atomic_t g_mic_thread_alive = 0;
static volatile sig_atomic_t g_spkr_thread_alive = 0;
static pthread_t g_v4l2_thread;
static volatile sig_atomic_t g_v4l2_thread_alive = 0;

const size_t frame_len = 1382400;

/*
 * Thin inline ioctl wrappers for AK ISP functions (decompiled mapping).
 */
/* Histograms */
static inline int ak_isp_set_raw_hist_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x43,4), arg); } /* req = 0x40044943 */
static inline int ak_isp_get_raw_hist_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x44,4), arg); }  /* req = 0x80044944 */
static inline int ak_isp_get_raw_hist_stat_info(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x45,4), arg); } /* req = 0x80044945 */
static inline int ak_isp_set_rgb_hist_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x46,4), arg); } /* req = 0x40044946 */
static inline int ak_isp_get_rgb_hist_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x47,4), arg); }  /* req = 0x80044947 */
static inline int ak_isp_get_rgb_hist_stat_info(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x48,4), arg); } /* req = 0x80044948 */
static inline int ak_isp_set_yuv_hist_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x49,4), arg); } /* req = 0x40044949 */
static inline int ak_isp_get_yuv_hist_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x4a,4), arg); }  /* req = 0x8004494a */
static inline int ak_isp_get_yuv_hist_stat_info(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x4b,4), arg); } /* req = 0x8004494b */

/* Exposure / AE / WB */
static inline int ak_isp_set_exp_type(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x4c,4), arg); } /* req = 0x4004494c */
static inline int ak_isp_get_exp_type(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x4d,4), arg); }  /* req = 0x8004494d */
static inline int ak_isp_set_ae_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x50,4), arg); } /* req = 0x40044950 */
static inline int ak_isp_get_ae_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x51,4), arg); }  /* req = 0x80044951 */
static inline int ak_isp_get_ae_run_info(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x52,4), arg); } /* req = 0x80044952 */
static inline int ak_isp_set_wb_type(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x53,4), arg); } /* req = 0x40044953 */
static inline int ak_isp_get_wb_type(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x54,4), arg); }  /* req = 0x80044954 */
static inline int ak_isp_set_awb_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x55,4), arg); } /* req = 0x40044955 */
static inline int ak_isp_get_awb_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x56,4), arg); }  /* req = 0x80044956 */
static inline int ak_isp_set_awb_ex_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x73,4), arg); } /* req = 0x40044973 */
static inline int ak_isp_get_awb_ex_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x74,4), arg); }  /* req = 0x80044974 */
static inline int ak_isp_get_awb_stat_info(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x59,4), arg); } /* req = 0x80044959 */

/* AF */
static inline int ak_isp_set_af_attr(void *arg) {
    return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x60,4), arg); // req = 0x40044960
}

/* MWB */
static inline int ak_isp_set_mwb_attr(void *arg) {
    return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x63,4), arg); // req = 0x40044963
}

/* SDPC
 * NOTE: in the decompiled library this function is a stub that returns 0 (no ioctl present),
 * so we implement the same behavior to match the binary. If you prefer a real ioctl wrapper
 * (at your own risk), see the commented example after the stub.
 */
static inline int ak_isp_set_sdpc_attr(void *arg) {
    (void)arg;
    return 0;
}

/* Weight / masks / colors */
static inline int ak_isp_set_weight_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x5e,4), arg); } /* req = 0x4004495e */
static inline int ak_isp_get_weight_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x5f,4), arg); }  /* req = 0x8004495f */
static inline int ak_isp_set_main_chan_mask_area(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x5a,4), arg); } /* req = 0x4004495a */
static inline int ak_isp_get_main_chan_mask_area(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x5b,4), arg); }  /* req = 0x8004495b */
static inline int ak_isp_set_sub_chan_mask_area(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x65,4), arg); } /* req = 0x40044965 */
static inline int ak_isp_get_sub_chan_mask_area(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x66,4), arg); }  /* req = 0x80044966 */
static inline int ak_isp_set_mask_color(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x5c,4), arg); } /* req = 0x4004495c */
static inline int ak_isp_get_mask_color(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x5d,4), arg); }  /* req = 0x8004495d */

/* BLC / DPC / LSC / NR */
static inline int ak_isp_set_blc_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x02,4), arg); } /* req = 0x40044902 */
static inline int ak_isp_get_blc_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x01,4), arg); }  /* req = 0x80044901 */
static inline int ak_isp_set_dpc_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x10,4), arg); } /* req = 0x40044910 */
static inline int ak_isp_get_dpc_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x0f,4), arg); }  /* req = 0x8004490f */
static inline int ak_isp_set_lsc_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x04,4), arg); } /* req = 0x40044904 */
static inline int ak_isp_get_lsc_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x03,4), arg); }  /* req = 0x80044903 */
static inline int ak_isp_set_nr1_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x0c,4), arg); } /* req = 0x4004490c */
static inline int ak_isp_get_nr1_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x0b,4), arg); }  /* req = 0x8004490b */
static inline int ak_isp_set_nr2_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x2b,4), arg); } /* req = 0x4004492b */
static inline int ak_isp_get_nr2_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x2c,4), arg); }  /* req = 0x8004492c */
static inline int ak_isp_set_3d_nr_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x2f,4), arg); } /* req = 0x4004492f */
static inline int ak_isp_get_3d_nr_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x30,4), arg); }  /* req = 0x80044930 */
static inline int ak_isp_set_3d_nr_ref_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x67,4), arg); } /* req = 0x40044967 */
static inline int ak_isp_get_3d_nr_ref_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x68,4), arg); }  /* req = 0x80044968 */
static inline int ak_isp_get_3d_nr_stat_info(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x70,4), arg); } /* req = 0x80044970 */

/* GB / demo / gamma / LUT / CCM / sharp / FCS / WDR */
static inline int ak_isp_set_gb_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x06,4), arg); } /* req = 0x40044906 */
static inline int ak_isp_get_gb_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x05,4), arg); }  /* req = 0x80044905 */
static inline int ak_isp_set_demo_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x0e,4), arg); } /* req = 0x4004490e */
static inline int ak_isp_get_demo_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x0d,4), arg); }  /* req = 0x8004490d */
static inline int ak_isp_set_rgb_gamma_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x1a,4), arg); } /* req = 0x4004491a */
static inline int ak_isp_get_rgb_gamma_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x19,4), arg); }  /* req = 0x80044919 */
static inline int ak_isp_set_raw_lut_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x0a,4), arg); } /* req = 0x4004490a */
static inline int ak_isp_get_raw_lut_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x09,4), arg); }  /* req = 0x80044909 */
static inline int ak_isp_set_ccm_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x12,4), arg); } /* req = 0x40044912 */
static inline int ak_isp_get_ccm_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x11,4), arg); }  /* req = 0x80044911 */
static inline int ak_isp_set_sharp_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x25,4), arg); } /* req = 0x40044925 */
static inline int ak_isp_get_sharp_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x26,4), arg); }  /* req = 0x80044926 */
static inline int ak_isp_set_sharp_ex_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x27,4), arg); } /* req = 0x40044927 */
static inline int ak_isp_get_sharp_ex_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x28,4), arg); }  /* req = 0x80044928 */
static inline int ak_isp_set_fcs_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x36,4), arg); } /* req = 0x40044936 */
static inline int ak_isp_get_fcs_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x35,4), arg); }  /* req = 0x80044935 */
static inline int ak_isp_set_wdr_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x1b,4), arg); } /* req = 0x4004491b */
static inline int ak_isp_get_wdr_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x1c,4), arg); }  /* req = 0x8004491c */

/* Contrast / saturation / rgb2yuv / effect */
static inline int ak_isp_set_contrast_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x39,4), arg); } /* req = 0x40044939 */
static inline int ak_isp_get_contrast_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x3a,4), arg); }  /* req = 0x8004493a */
static inline int ak_isp_set_saturation_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x3b,4), arg); } /* req = 0x4004493b */
static inline int ak_isp_get_saturation_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x3c,4), arg); }  /* req = 0x8004493c */
static inline int ak_isp_set_rgb2yuv_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x3f,4), arg); } /* req = 0x4004493f */
static inline int ak_isp_get_rgb2yuv_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x40,4), arg); }  /* req = 0x80044940 */
static inline int ak_isp_set_effect_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x41,4), arg); } /* req = 0x40044941 */
static inline int ak_isp_get_effect_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x42,4), arg); }  /* req = 0x80044942 */

/* Misc / blobs / sensor control */
static inline int ak_isp_sensor_load_conf(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x69,4), arg); } /* req = 0x40044969 */
static inline int ak_isp_sensor_set_reg(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x6b,4), arg); }  /* req = 0x4004496b */
static inline int ak_isp_sensor_get_reg(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x6c,4), arg); }   /* req = 0x8004496c */
static inline int ak_isp_set_user_params(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x6d,4), arg); } /* req = 0x4004496d */
static inline int ak_isp_set_misc_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x6e,4), arg); } /* req = 0x4004496e */
static inline int ak_isp_get_misc_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x6f,4), arg); }  /* req = 0x8004496f */
static inline int ak_isp_set_y_gamma_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x75,4), arg); } /* req = 0x40044975 */
static inline int ak_isp_get_y_gamma_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x76,4), arg); }  /* req = 0x80044976 */
static inline int ak_isp_set_hue_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x77,4), arg); } /* req = 0x40044977 */
static inline int ak_isp_get_hue_attr(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x78,4), arg); }  /* req = 0x80044978 */
static inline int ak_isp_set_frame_rate(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x4e,4), arg); } /* req = 0x4004494e */
static inline int ak_isp_get_frame_rate(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x4f,4), arg); }  /* req = 0x8004494f */
static inline int ak_isp_set_isp_capturing(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x72,4), arg); } /* req = 0x40044972 */
static inline int ak_isp_sensor_get_id(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x71,4), arg); } /* req = 0x80044971 */
static inline int ak_isp_set_flip_mirror(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x79,4), arg); } /* req = 0x40044979 */
static inline int ak_isp_set_sensor_fps(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_WRITE,0x49,0x7a,4), arg); } /* req = 0x4004497a */
static inline int ak_isp_get_sensor_fps(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x7b,4), arg); }  /* req = 0x8004497b */
static inline int ak_isp_get_work_scene(void *arg) { return ioctl(fd_isp_char, (unsigned long)_IOC(_IOC_READ,0x49,0x7c,4), arg); }  /* req = 0x8004497c */

/* ============================================================
 *                         Utilities
 * ============================================================ */

static void warn_errno(const char *fmt, ...) {
    int saved = errno;
    va_list ap; va_start(ap, fmt);
    fprintf(stderr, "[WARN] ");
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    if (saved) fprintf(stderr, ": %s\n", strerror(saved));
    else       fputc('\n', stderr);
}

static void info(const char *fmt, ...) {
    va_list ap; va_start(ap, fmt);
    fprintf(stderr, "[INFO] ");
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    fputc('\n', stderr);
}

static void safe_close(int *pfd) {
    if (pfd && *pfd >= 0) {
        close(*pfd);
        *pfd = -1;
    }
}

static double monotonic_sec(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec * 1e-9;
}

/* ============================================================
 *                    Signal handling (Ctrl+C, kill…)
 * ============================================================ */
static void handle_signal(int sig) {
    (void)sig;
    g_running = 0; /* triggers main loop exit and cleanup */
}


/* =========================
 * Tipos expuestos al usuario
 * ========================= */
typedef int (*isp_block_cb)(int pack, uint16_t id, uint16_t size, const uint8_t *payload, void *user);

struct parse_isp_conf_stats {
    int packs;   /* nº de packs encontrados */
    int blocks;  /* nº de subpacks (bloques) entregados al callback */
};

/* Prototipos exportables (por si quieres un .h más tarde) */
int parse_isp_conf(const uint8_t *buf, size_t len,
                   isp_block_cb cb, void *user,
                   struct parse_isp_conf_stats *out);

int parse_isp_conf_file(const char *path,
                        isp_block_cb cb, void *user,
                        struct parse_isp_conf_stats *out);

/* ======================
 * Estructura de cabecera
 * ====================== */
#pragma pack(push,1)
struct lehdr {
    uint16_t id;    /* 0.. */
    uint16_t size;  /* bytes, incluye cabecera */
};
#pragma pack(pop)

/* ============
 * Utilidades IO
 * ============ */
static int load_file(const char *path, uint8_t **out_buf, size_t *out_len) {
    FILE *f = fopen(path, "rb");
    if (!f) { return -1; }
    if (fseek(f, 0, SEEK_END) != 0) { fclose(f); return -2; }
    long ln = ftell(f);
    if (ln < 0) { fclose(f); return -3; }
    if (fseek(f, 0, SEEK_SET) != 0) { fclose(f); return -4; }

    size_t n = (size_t)ln;
    uint8_t *buf = (uint8_t*)malloc(n ? n : 1);
    if (!buf) { fclose(f); return -5; }
    if (n && fread(buf, 1, n, f) != n) { free(buf); fclose(f); return -6; }
    fclose(f);

    *out_buf = buf;
    *out_len = n;
    return 0;
}

/* ===========================================
 * Núcleo: detectar packs y llamar a callbacks
 * ===========================================
 *
 * Implementación paso a paso con comentarios de bloque:
 * 1) Escaneo lineal de 4 en 4 para cazar un id==0 (candidato a inicio de pack).
 * 2) Validación del pack:
 *      - Recorremos subpacks saltando por 'size' y exigiendo id==prev+1;
 *      - Cuando encontramos el primer mismatch, incluimos ese subpack como "final";
 *      - Guardamos offsets de TODOS los subpacks en un vector temporal.
 * 3) Si la validación fue OK, iteramos el vector y llamamos a 'cb' por cada subpack.
 * 4) Actualizamos 'scan_off' al final del pack para buscar el siguiente.
 */
int parse_isp_conf(const uint8_t *buf, size_t len,
                   isp_block_cb cb, void *user,
                   struct parse_isp_conf_stats *out)
{
    if (!buf || !cb) return -1;

    int total_packs = 0;
    int total_blocks = 0;
    size_t scan_off = 0;

    /* Vector temporal para acumular subpacks de un pack (crece dinámicamente) */
    struct item { size_t off; uint16_t id; uint16_t size; };
    struct item *items = NULL;
    size_t items_cap = 0;

    while (scan_off + 4 <= len) {

        /* ---- 1) buscar id==0 candidato ---- */
        size_t candidate_off = (size_t)-1;
        for (size_t off = scan_off; off + 4 <= len; off += 4) {
            struct lehdr h;
            memcpy(&h, buf + off, 4);
            if (h.id == 0x0000) {
                /* size mínimo y no fuera de rango (chequeo único) */
                if (h.size != 0 && off + (size_t)h.size <= len) {
                    candidate_off = off;
                    break;
                }
            }
        }
        if (candidate_off == (size_t)-1) break; /* no hay más packs */

            /* ---- 2) validar pack y recolectar subpacks ---- */
            size_t p = candidate_off;
        uint16_t expect = 0;
        int ok = 0;

        /* reset vector */
        size_t items_len = 0;

        while (1) {
            if (p + 4 > len) { ok = 0; break; }
            struct lehdr h;
            memcpy(&h, buf + p, 4);
            if (p + (size_t)h.size > len || h.size == 0) { ok = 0; break; }

            /* push actual */
            if (items_len == items_cap) {
                size_t new_cap = items_cap ? items_cap * 2 : 32;
                void *new_ptr = realloc(items, new_cap * sizeof(*items));
                if (!new_ptr) { free(items); return -2; }
                items = (struct item*)new_ptr;
                items_cap = new_cap;
            }
            items[items_len].off  = p;
            items[items_len].id   = h.id;
            items[items_len].size = h.size;
            items_len++;

            size_t next = p + (size_t)h.size;

            /* ¿hemos completado id esperado y vamos a chequear el siguiente? */
            if (next + 4 > len) { ok = 0; break; }

            struct lehdr hn;
            memcpy(&hn, buf + next, 4);
            if (next + (size_t)hn.size > len || hn.size == 0) { ok = 0; break; }

            if (hn.id == (uint16_t)(expect + 1)) {
                /* correlativa continúa */
                p = next;
                expect++;
                continue;
            }

            /* mismatch: hn es el "bloque final" -> incluirlo y cerrar pack */
            if (items_len == items_cap) {
                size_t new_cap = items_cap ? items_cap * 2 : 32;
                void *new_ptr = realloc(items, new_cap * sizeof(*items));
                if (!new_ptr) { free(items); return -2; }
                items = (struct item*)new_ptr;
                items_cap = new_cap;
            }
            items[items_len].off  = next;
            items[items_len].id   = hn.id;
            items[items_len].size = hn.size;
            items_len++;

            ok = 1; /* pack válido */
            p = next; /* 'p' apunta al bloque final (no es necesario, pero deja consistente) */
            break;
        }

        if (!ok) {
            /* Falló candidato: seguir buscando detrás de candidate_off */
            scan_off = candidate_off + 4;
            continue;
        }

        /* ---- 3) invocar callback por cada subpack del pack ---- */
        for (size_t i = 0; i < items_len; ++i) {
            const size_t off  = items[i].off;
            const uint16_t id = items[i].id;
            const uint16_t sz = items[i].size;

            const uint8_t *payload = buf + off + 4;
            const uint16_t payload_size = (sz >= 4) ? (uint16_t)(sz - 4) : 0;

            /* Si el callback devuelve !=0, interpretamos como “stop” */
            int rc = cb(total_packs, id, payload_size, payload, user);
            if (rc != 0) { free(items); if (out) { out->packs = total_packs+1; out->blocks = total_blocks + (int)i + 1; } return 0; }
            total_blocks++;
        }

        total_packs++;

        /* ---- 4) buscar siguiente pack a partir del final de este ---- */
        size_t pack_end = items[items_len - 1].off + (size_t)items[items_len - 1].size;
        scan_off = pack_end;
    }

    free(items);
    if (out) { out->packs = total_packs; out->blocks = total_blocks; }
    return 0;
}

/* Conveniencia: parsear desde fichero */
int parse_isp_conf_file(const char *path,
                        isp_block_cb cb, void *user,
                        struct parse_isp_conf_stats *out)
{
    if (!path || !cb) return -1;
    uint8_t *buf = NULL; size_t n = 0;
    int rc = load_file(path, &buf, &n);
    if (rc != 0) return rc;
    rc = parse_isp_conf(buf, n, cb, user, out);
    free(buf);
    return rc;
}

static void die_perror(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

static int xioctl(int fd, unsigned long req, const void *arg) {
    int r;
    do { r = ioctl(fd, req, arg); usleep(100); } while (r == -1 && errno == EINTR);
    return r;
}

static int setup_signals(void) {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGINT,  &sa, NULL) < 0) { warn_errno("sigaction(SIGINT)");  return -1; }
    if (sigaction(SIGTERM, &sa, NULL) < 0) { warn_errno("sigaction(SIGTERM)"); return -1; }
    if (sigaction(SIGHUP,  &sa, NULL) < 0) { warn_errno("sigaction(SIGHUP)");  return -1; }
    if (sigaction(SIGQUIT, &sa, NULL) < 0) { warn_errno("sigaction(SIGQUIT)"); return -1; }
    return 0;
}

void close_devices(void) {
    info("Closing devices…");
    safe_close(&fd_akpcm1);
    safe_close(&fd_akpcm0);
    safe_close(&fd_uio0);
    safe_close(&fd_video0);
    safe_close(&fd_isp_char);
    safe_close(&fd_ion);
}

/* ============================================================
 *                   Section: Device open/close
 * ============================================================ */

/* Open all required /dev/… with O_RDWR. Non-blocking for video makes sense. */
int open_devices(void) {
    info("Opening devices…");

    fd_ion      = open("/dev/ion",         O_RDWR | O_CLOEXEC);
    if (fd_ion < 0) { warn_errno("open /dev/ion"); goto fail; }

    fd_isp_char = open("/dev/isp_char",    O_RDWR | O_CLOEXEC);
    if (fd_isp_char < 0) { warn_errno("open /dev/isp_char"); goto fail; }

    info("Deferring /dev/video0 open until after ISP setup.");

    fd_uio0     = open("/dev/uio0",        O_RDWR | O_CLOEXEC);
    if (fd_uio0 < 0) { warn_errno("open /dev/uio0"); goto fail; }

    fd_akpcm0   = open("/dev/akpcm_cdev0", O_RDWR | O_CLOEXEC); /* SPKR (playback) */
    if (fd_akpcm0 < 0) { warn_errno("open /dev/akpcm_cdev0"); goto fail; }

    fd_akpcm1   = open("/dev/akpcm_cdev1", O_RDWR | O_CLOEXEC); /* MIC (capture) */
    if (fd_akpcm1 < 0) { warn_errno("open /dev/akpcm_cdev1"); goto fail; }

    info("All devices opened.");
    return 0;

fail:
    /* Partial cleanup on failure */
    close_devices();
    return -1;
}

static int ensure_video0_open(void) {
    if (fd_video0 >= 0) {
        return 0;
    }

    fd_video0 = open("/dev/video0", O_RDWR | O_NONBLOCK | O_CLOEXEC);
    if (fd_video0 < 0) {
        warn_errno("open /dev/video0");
        return -1;
    }
    info("open /dev/video0 -> fd=%d", fd_video0);
    return 0;
}

/*
 * ---------------- ION (según traza) ----------------
 * IOCTLs por valor literal (coinciden con la traza):
 *   ION_IOC_ALLOC = 0xc0144900 (size=20)
 *   ION_IOC_MAP   = 0xc0084902 (size=8)
 *
 * Estructuras mínimas compatibles con tamaño reportado en la traza.
 */

#define ION_IOC_ALLOC 0xc0144900UL
#define ION_IOC_MAP   0xc0084902UL

struct ion_allocation_data_compat {
    uint32_t len;           // 0x01800000 -> 25,165,824
    uint32_t align;         // 0x00001000
    uint32_t heap_id_mask;  // 0x000000ff
    uint32_t flags;         // 0x00000003
    uint32_t handle;        // OUT
}; // size == 20

struct ion_fd_data_compat {
    uint32_t handle;        // IN
    int32_t  fd;            // OUT
}; // size == 8

struct ion_region {
    int      dmabuf_fd;
    void    *map;
    size_t   len;
};

struct ion_region ion = { .dmabuf_fd = -1, .map = MAP_FAILED, .len = 0 };

/* Reserva, mapea y devuelve región (según traza) */
int ion_reserve_and_map(void) {

    // 2) ION_IOC_ALLOC
    struct ion_allocation_data_compat a;
    memset(&a, 0, sizeof(a));
    a.len          = 0x01800000U; // 25,165,824
    a.align        = 0x00001000U; // 4 KiB
    a.heap_id_mask = 0x000000ffU;
    a.flags        = 0x00000003U;

    if (xioctl(fd_ion, ION_IOC_ALLOC, &a) < 0) {
        die_perror("ION_IOC_ALLOC");
    }

    // 3) ION_IOC_MAP
    struct ion_fd_data_compat m;
    memset(&m, 0, sizeof(m));
    m.handle = a.handle;
    m.fd     = 0;
    if (xioctl(fd_ion, ION_IOC_MAP, &m) < 0) {
        die_perror("ION_IOC_MAP");
    }

    // 4) MMAP del dmabuf a 24 MiB
    ion.len = a.len;
    ion.dmabuf_fd = m.fd;
    ion.map = mmap(NULL, ion.len, PROT_READ | PROT_WRITE, MAP_SHARED, ion.dmabuf_fd, 0);
    if (ion.map == MAP_FAILED) die_perror("mmap(dmabuf)");

    return 0;
}

struct isp_3dnr_ref_desc {
    uint32_t base;    // p.ej. puntero base a la tabla/ref en la .conf
    uint32_t ptr_a;   // base + 2*index
    uint32_t ptr_b;   // ptr_a + 2*((index+3)>>2)
    uint32_t pitch;   // 2*index
    uint32_t height;  // 2*((index+3)>>2)
};

/* ===================== helpers LE ===================== */
static inline uint16_t rd_le16(const uint8_t *p) {
    return (uint16_t)p[0] | ((uint16_t)p[1] << 8);
}
static inline uint32_t rd_le32(const uint8_t *p) {
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}


/* ===================== loader de blobs ===================== */
typedef struct {
    void *data;    /* puntero a los bytes cargados (malloc) */
    size_t size;   /* tamaño en bytes */
} blob_t;

struct blob_desc {
    uint32_t nwords; /* nº de palabras de 32 bits */
    void    *ptr;    /* puntero al blob de datos */
};

static int load_blob(const char *path, blob_t *out) {
    if (!path || !out) {
        errno = EINVAL;
        return -1;
    }
    out->data = NULL;
    out->size = 0;

    struct stat st;
    if (stat(path, &st) != 0) return -1;

    size_t size = (size_t)st.st_size;
    FILE *f = fopen(path, "rb");
    if (!f) return -1;

    if (size == 0) { fclose(f); return 0; }

    void *buf = malloc(size);
    if (!buf) { fclose(f); errno = ENOMEM; return -1; }

    size_t readn = 0;
    while (readn < size) {
        size_t r = fread((uint8_t*)buf + readn, 1, size - readn, f);
        if (r == 0) {
            if (feof(f)) break;
            if (ferror(f)) { int saved = errno; free(buf); fclose(f); errno = saved ? saved : EIO; return -1; }
        }
        readn += r;
    }
    fclose(f);

    if (readn != size) {
        void *shrunk = realloc(buf, readn ? readn : 1);
        if (shrunk || readn == 0) {
            buf = shrunk;
            out->data = buf;
            out->size = readn;
            return 0;
        } else {
            free(buf);
            errno = ENOMEM;
            return -1;
        }
    }

    out->data = buf;
    out->size = size;
    return 0;
}

static void free_blob(blob_t *b) {
    if (!b) return;
    if (b->data) { free(b->data); b->data = NULL; }
    b->size = 0;
}

/* Autor: Abel Romero
 * apply_vendor_case() sin macros TRY / PAYLOAD_OK
 * offsets ajustados (-4, si queda 0 → se omite)
 */

static int apply_vendor_case(uint32_t case_id_hex, uint8_t *payload, size_t payload_len)
{
    int rc = 0;

    switch (case_id_hex) {
        case 0x0:
            ak_isp_set_blc_attr(payload);
            break;

        case 0x1:
            ak_isp_set_lsc_attr(payload);
            break;

        case 0x2:
            ak_isp_set_raw_lut_attr(payload);
            break;

        case 0x3:
            ak_isp_set_nr1_attr(payload);
            ak_isp_set_nr2_attr(payload + 0x06f6); // 0x06fa-4
            break;

        case 0x4:
            ak_isp_set_3d_nr_attr(payload);
            break;

        case 0x5:
            ak_isp_set_gb_attr(payload);
            break;

        case 0x6:
            ak_isp_set_demo_attr(payload);
            break;

        case 0x7:
            ak_isp_set_rgb_gamma_attr(payload);
            break;

        case 0x8:
            ak_isp_set_ccm_attr(payload);
            break;

        case 0x9:
            ak_isp_set_fcs_attr(payload);
            break;

        case 0xa:
            ak_isp_set_wdr_attr(payload);
            break;

        case 0xb:
            ak_isp_set_sharp_attr(payload);
            ak_isp_set_sharp_ex_attr(payload + 0x2b36); // 0x2b3a-4
            break;

        case 0xc:
            ak_isp_set_saturation_attr(payload);
            break;

        case 0xd:
            ak_isp_set_contrast_attr(payload);
            break;

        case 0xe:
            ak_isp_set_rgb2yuv_attr(payload);
            break;

        case 0xf:
            ak_isp_set_effect_attr(payload);
            break;

        case 0x10:
            ak_isp_set_dpc_attr(payload);
            ak_isp_set_sdpc_attr(payload + 0x0054); // 0x58-4
            break;

        case 0x11:
            ak_isp_set_weight_attr(payload);
            break;

        case 0x12:
            ak_isp_set_af_attr(payload);
            break;

        case 0x13:
            ak_isp_set_wb_type(payload);
            ak_isp_set_mwb_attr(payload + 0x0002);  // 0x6-4
            ak_isp_set_awb_attr(payload + 0x000e);  // 0x12-4
            ak_isp_set_awb_ex_attr(payload + 0x00c8); // 0xcc-4
            break;

        case 0x14: {
            ak_isp_set_raw_hist_attr(payload);
            ak_isp_set_rgb_hist_attr(payload + 0x0002); // 0x6-4
            ak_isp_set_yuv_hist_attr(payload + 0x0004); // 0x8-4
            ak_isp_set_exp_type(payload + 0x0006);      // 0xa-4
            ak_isp_set_frame_rate(payload + 0x0008);    // 0xc-4
            ak_isp_set_ae_attr(payload + 0x0020);       // 0x24-4
            uint32_t sensor_fps = 0x0000000f;
            ak_isp_set_sensor_fps(&sensor_fps);
        } break;

        case 0x15:
            ak_isp_set_misc_attr(payload);
            break;

        case 0x16:
            ak_isp_set_y_gamma_attr(payload);
            break;

        case 0x17:
            ak_isp_set_hue_attr(payload);
            break;

        case 0x1b:
        case 0x1c: {
            struct blob_desc desc = {
                .nwords = (uint32_t)((payload_len + 4) / 4),
                .ptr    = payload,
            };
            ak_isp_sensor_load_conf(&desc);
        } break;

        default:
            fprintf(stderr, "[apply] id 0x%x desconocido\n", case_id_hex);
            if (rc == 0) rc = -1;
            break;
    }

    return rc;
}

/* ===================== callback del parser ===================== */
static int on_section(int pack, uint16_t id, uint16_t size, const uint8_t *payload, void *user)
//static int on_section(uint32_t id, const uint8_t *payload, size_t payload_len, void *user)
{
    (void)user;
    if (pack == 0) {
        printf("[isp_conf] pack: 0x%x, id: 0x%x, size: %hu\n", pack, id, size);
        return apply_vendor_case(id, (uint8_t*)payload, size);
    }
    return 0;
}

int isp_setup(const char* sensor_conf_path) {

    int rc = -1;
    rc = parse_isp_conf_file(sensor_conf_path, on_section, NULL, NULL);
    if (rc < 0) {
        fprintf(stderr, "parse_isp_conf_file() fallo rc=%d\n", rc);
        return rc;
    }

    blob_t nr3d_ref_blob;
    if (load_blob("isp_3dnr_ref_attr_pid518_fd10_req0x40044967_20250930T130454.bin", &nr3d_ref_blob) != 0) {
        fprintf(stderr, "load_blob(3dnr_ref)\n");
        return -1;
    }
    ak_isp_set_3d_nr_ref_attr(nr3d_ref_blob.data);
    free_blob(&nr3d_ref_blob);

    //uint32_t sens_fps = 0x0000000f;
    //Ak_ISP_Set_Sensor_Fps(&sens_fps);

    blob_t user_params;
    if (load_blob("isp_user_params_pid519_fd10_req0x4004496d_20250930T130029.bin", &user_params) != 0) {
        fprintf(stderr, "load_blob(user_params)\n");
        return -1;
    }
    ak_isp_set_user_params(user_params.data);
    free_blob(&user_params);

    return 0;
}

int v4l2_setup(void) {
    if (ensure_video0_open() < 0) {
        return -1;
    }

    /* --- VIDIOC_CROPCAP (extra info) --- */
    struct v4l2_cropcap cap;
    memset(&cap, 0, sizeof(cap));
    cap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (xioctl(fd_video0, VIDIOC_CROPCAP, &cap) < 0) die_perror("VIDIOC_CROPCAP");
    printf("[v4l2_cropcap]\ntype=%u\n", cap.type);
    printf("bounds:   left=%d top=%d width=%u height=%u\n",
           cap.bounds.left, cap.bounds.top, cap.bounds.width, cap.bounds.height);
    printf("defrect:  left=%d top=%d width=%u height=%u\n",
           cap.defrect.left, cap.defrect.top, cap.defrect.width, cap.defrect.height);
    printf("pixelaspect: %u/%u\n", cap.pixelaspect.numerator, cap.pixelaspect.denominator);

    /* BLOQUE 2: llamadas sueltas (3DNR ref, AWB/FR) */
    // blob_t nr3d_ref_blob;
    // if (load_blob("isp_3dnr_ref_attr_pid518_fd10_req0x40044967_20250930T130454.bin", &nr3d_ref_blob) != 0) {
    //     fprintf(stderr, "load_blob(3dnr_ref)\n");
    //     return -1;
    // }
    // AK_ISP_set_3d_nr_ref_attr(nr3d_ref_blob.data);
    // free_blob(&nr3d_ref_blob);
    //
    // uint32_t sens_fps = 0x0000000f;
    // Ak_ISP_Set_Sensor_Fps(&sens_fps);

    // --- VIDIOC_QUERYCAP ---
    struct v4l2_capability caps;
    memset(&caps, 0, sizeof(caps));
    if (xioctl(fd_video0, VIDIOC_QUERYCAP, &caps) < 0) die_perror("VIDIOC_QUERYCAP");
    printf("driver=%s, card=%s, bus_info=%s, version=%u, capabilities=0x%x, device_caps=0x%x\n",
           caps.driver, caps.card, caps.bus_info, caps.version, caps.capabilities, caps.device_caps);

    // --- VIDIOC_CROPCAP ---
    struct v4l2_cropcap cropcap;
    memset(&cropcap, 0, sizeof(cropcap));
    cropcap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (xioctl(fd_video0, VIDIOC_CROPCAP, &cropcap) < 0) die_perror("VIDIOC_CROPCAP");
    printf("bounds: %d,%d %ux%u\n", cropcap.bounds.left, cropcap.bounds.top,
           cropcap.bounds.width, cropcap.bounds.height);
    printf("defrect: %d,%d %ux%u\n", cropcap.defrect.left, cropcap.defrect.top,
           cropcap.defrect.width, cropcap.defrect.height);
    printf("pixelaspect=%u/%u\n", cropcap.pixelaspect.numerator, cropcap.pixelaspect.denominator);

    // --- VIDIOC_S_CROP ---
    struct v4l2_crop crop;
    memset(&crop, 0, sizeof(crop));
    crop.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    crop.c = cropcap.defrect;  // igual que la traza
    if (xioctl(fd_video0, VIDIOC_S_CROP, &crop) < 0) die_perror("VIDIOC_S_CROP");

    // --- VIDIOC_S_FMT ---
    struct v4l2_format fmt;
    memset(&fmt, 0, sizeof(fmt));
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = 1280;
    fmt.fmt.pix.height = 720;
    fmt.fmt.pix.pixelformat = v4l2_fourcc('Y','U','Y','V');
    fmt.fmt.pix.field = V4L2_FIELD_INTERLACED; // prueba V4L2_FIELD_NONE si ves artefactos
    if (xioctl(fd_video0, VIDIOC_S_FMT, &fmt) < 0) die_perror("VIDIOC_S_FMT");
    printf("fmt: %ux%u, fourcc=%.4s, bytesperline=%u, sizeimage=%u\n",
           fmt.fmt.pix.width, fmt.fmt.pix.height,
           (char*)&fmt.fmt.pix.pixelformat,
           fmt.fmt.pix.bytesperline, fmt.fmt.pix.sizeimage);

    // --- VIDIOC_S_PARM ---
    struct v4l2_streamparm parm;
    memset(&parm, 0, sizeof(parm));
    parm.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

    parm.parm.capture.capability   = 0x1;
    parm.parm.capture.capturemode  = 0x280;

    parm.parm.capture.timeperframe.numerator = 360;
    parm.parm.capture.timeperframe.denominator = 0; // según la traza

    parm.parm.capture.extendedmode = 0;
    parm.parm.capture.readbuffers  = 0;
    if (xioctl(fd_video0, VIDIOC_S_PARM, &parm) < 0) die_perror("VIDIOC_S_PARM");
    printf("S_PARM: cap=0x%x, mode=0x%x, tpf=%u/%u\n",
           parm.parm.capture.capability,
           parm.parm.capture.capturemode,
           parm.parm.capture.timeperframe.numerator,
           parm.parm.capture.timeperframe.denominator);

    // blob_t user_params;
    // if (load_blob("isp_user_params_pid519_fd10_req0x4004496d_20250930T130029.bin", &user_params) != 0) {
    //     fprintf(stderr, "load_blob(user_params)\n");
    //     return -1;
    // }
    // Ak_ISP_Set_User_Params(user_params.data);
    // free_blob(&user_params);

    /* V4L2: Req/Q/Stream/DQ/Q ciclo inicial (4 buffers) */
    struct v4l2_requestbuffers req;
    memset(&req, 0, sizeof(req));
    req.count  = 4;
    req.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req.memory = V4L2_MEMORY_USERPTR;
    if (xioctl(fd_video0, VIDIOC_REQBUFS, &req) < 0) { die_perror("VIDIOC_REQBUFS"); }
    if (req.count != 4) { fprintf(stderr, "Driver adjusted count to %u\n", req.count); die_perror("REQBUFS count"); }

    const size_t enqueue_len = 2306048;
    uintptr_t bptr = (uintptr_t) ion.map;
    uintptr_t bufs[4];
    for (int i = 0; i < 4; ++i) bufs[i] = bptr + i * enqueue_len;

    for (int i = 0; i < 4; ++i) {
        struct v4l2_buffer b; memset(&b, 0, sizeof(b));
        b.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        b.index  = i;
        b.memory = V4L2_MEMORY_USERPTR;
        b.m.userptr = (unsigned long)bufs[i];
        b.length = enqueue_len;
        b.bytesused = 0;
        if (xioctl(fd_video0, VIDIOC_QBUF, &b) < 0) { die_perror("VIDIOC_QBUF"); }
    }

    enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (xioctl(fd_video0, VIDIOC_STREAMON, &type) < 0) { die_perror("VIDIOC_STREAMON"); }

    // discard first 4 frames
    for (int i = 0; i < 4; ++i) {
        struct v4l2_buffer b; memset(&b, 0, sizeof(b));
        b.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        b.memory = V4L2_MEMORY_USERPTR;
        if (xioctl(fd_video0, VIDIOC_DQBUF, &b) < 0) {
            if (errno == EAGAIN) { usleep(1000); --i; continue; }
            die_perror("VIDIOC_DQBUF");
        }
        double ts = b.timestamp.tv_sec + b.timestamp.tv_usec / 1e6;
        printf("DQBUF index=%u bytesused=%u length=%u ts=%.6f\n",
               b.index, b.bytesused, b.length, ts);

        struct v4l2_buffer q; memset(&q, 0, sizeof(q));
        q.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        q.index  = b.index;
        q.memory = V4L2_MEMORY_USERPTR;
        q.m.userptr = (unsigned long)bufs[b.index];
        q.length = frame_len;
        q.bytesused = frame_len;
        if (xioctl(fd_video0, VIDIOC_QBUF, &q) < 0) { die_perror("VIDIOC_QBUF(re)"); }
    }
    return 0;
}

static void hexdump(const void *data, size_t len) {
    const unsigned char *p = (const unsigned char *)data;
    for (size_t i = 0; i < len; i += 16) {
        fprintf(stderr, "%06zx  ", i);
        for (size_t j = 0; j < 16; ++j) {
            if (i + j < len) fprintf(stderr, "%02x ", p[i + j]);
            else             fprintf(stderr, "   ");
        }
        fprintf(stderr, " |");
        for (size_t j = 0; j < 16 && i + j < len; ++j) {
            unsigned char c = p[i + j];
            fputc((c >= 32 && c <= 126) ? c : '.', stderr);
        }
        fprintf(stderr, "|\n");
    }
}

/*
 * mic_setup()
 * -----------
 * Applies the exact ioctl sequence you provided for the MICROPHONE path.
 * Device: /dev/akpcm_cdev1  (fd_akpcm1)
 * Only setup — capture loop is commented out.
 */
int mic_setup(void) {
    int rc;
    int fd = fd_akpcm1;

    /* params buffer shared by multiple ioctls */
    unsigned char params[64];
    memset(params, 0, sizeof(params));

    /* === Sequence from your trace === */

    /* 0x40045010 (val=2) */
    { unsigned long req=0x40045010UL; uint32_t v=2;
      rc=ioctl(fd,req,&v); if(rc<0) perror("ioctl 0x40045010"); }

    /* 0x40045070 (val=1) */
    { unsigned long req=0x40045070UL; uint32_t v=1;
      rc=ioctl(fd,req,&v); if(rc<0) perror("ioctl 0x40045070"); }

    /* 0x40045030 (val=7) */
    { unsigned long req=0x40045030UL; uint32_t v=7;
      rc=ioctl(fd,req,&v); if(rc<0) perror("ioctl 0x40045030"); }

    /* 0x50e3 (no arg) */
    { unsigned long req=0x50e3UL;
      rc=ioctl(fd,req); if(rc<0) perror("ioctl 0x50e3"); }

    /* 0x40045088 (val=1) */
    { unsigned long req=0x40045088UL; uint32_t v=1;
      rc=ioctl(fd,req,&v); if(rc<0) perror("ioctl 0x40045088"); }

    /* 0x50e2 (no arg) */
    { unsigned long req=0x50e2UL;
      rc=ioctl(fd,req); if(rc<0) perror("ioctl 0x50e2"); }

    /* 0x401c50f2 (WRITE 28 bytes) — exactly your bytes */
    { unsigned long req=0x401c50f2UL;
      unsigned char buf28[28] = {
        0x80,0x3e,0x00,0x00, 0x01,0x00,0x00,0x00, 0x10,0x00,0x00,0x00, 0x00,0x08,0x00,0x00,
        0x10,0x00,0x00,0x00, 0x00,0x08,0x00,0x00, 0x00,0x00,0x00,0x00
      };
      rc=ioctl(fd,req,buf28); if(rc<0) perror("ioctl 0x401c50f2"); }

    /* 0x50e0 (no arg) */
    { unsigned long req=0x50e0UL;
      rc=ioctl(fd,req); if(rc<0) perror("ioctl 0x50e0"); }

    /* 0x804050f0 (READ 64) — fills params (has 0x0000bb80=48000 Hz in your run) */
    { unsigned long req=0x804050f0UL;
      rc=ioctl(fd,req,params);
      if(rc<0) perror("ioctl 0x804050f0");
      else { printf("0x804050f0 OK (first 48 bytes):\n"); hexdump(params, 48); }
    }

    /* 0x50e2 (again) */
    { unsigned long req=0x50e2UL;
      rc=ioctl(fd,req); if(rc<0) perror("ioctl 0x50e2 (2)"); }

    /* 0x50e1 — MUST receive the same pointer (params) */
    { unsigned long req=0x50e1UL;
      rc=ioctl(fd,req,params);             /* <-- important: NOT NULL */
      if(rc<0) perror("ioctl 0x50e1"); }

    /* 0x80045085 (READ 4) — driver writes into params[0..3] */
    { unsigned long req=0x80045085UL;
      rc=ioctl(fd,req,params);
      if(rc<0) perror("ioctl 0x80045085");
      else {
        uint32_t h; memcpy(&h, params, 4);
        printf("0x80045085 -> 0x%08x\n", h);
      }
    }

    /* 0x40045086 (WRITE 4) — app sends zero in first 4 bytes */
    { unsigned long req=0x40045086UL; uint32_t zero=0;
      memcpy(params, &zero, 4);
      rc=ioctl(fd,req,params);
      if(rc<0) perror("ioctl 0x40045086");
    }

    /* === Capture loop intentionally disabled (setup only) ===
    printf("Entering capture loop (DISABLED).\n");
    const size_t BUFSZ = 4096;
    unsigned char *rbuf = (unsigned char*)malloc(BUFSZ);
    if(!rbuf){ fprintf(stderr,"malloc failed\n"); return 0; }
    for(;;){
        unsigned long req=0x800450e8UL; uint32_t avail=0;
        rc = ioctl(fd, req, &avail);
        if(rc < 0){ perror("ioctl 0x800450e8"); msleep(10); continue; }
        if(avail == 0){ msleep(10); continue; }
        size_t want = avail; if(want > BUFSZ) want = BUFSZ;
        ssize_t n = read(fd, rbuf, want);
        if(n <= 0){ if(errno==EAGAIN||errno==EWOULDBLOCK){ msleep(5); continue; } perror("read"); break; }
        // Normally write rbuf to /mnt/disc1/mic_capture.raw …
    }
    free(rbuf);
    */

    return 0; /* best-effort: do not fail the whole stream on partial errors */
}

/* mic_record_thread
 * -----------------
 * - Assumes mic_setup() already configured /dev/akpcm_cdev1 (fd_akpcm1).
 * - Polls for readable frames and appends raw PCM S16LE mono to /mnt/disc1/record_s16le_mono_16kHz.pcm.
 */
static void *mic_record_thread(void *arg) {
    (void)arg;
    g_mic_thread_alive = 1;

    const char *out_path = "/mnt/disc1/record_s16le_mono_16kHz.pcm";
    FILE *fout = fopen(out_path, "ab");
    if (!fout) {
        warn_errno("mic_record_thread: fopen(record_s16le_mono_16kHz.pcm) failed");
        g_mic_thread_alive = 0;
        return NULL;
    }

    /* Non-blocking read with poll */
    int fd = fd_akpcm1;
    struct pollfd pfd = { .fd = fd, .events = POLLIN };
    const size_t BUFSZ = 2048;
    unsigned char *buf = (unsigned char*)malloc(BUFSZ);
    if (!buf) {
        fprintf(stderr, "mic_record_thread: malloc failed\n");
        fclose(fout);
        g_mic_thread_alive = 0;
        return NULL;
    }

    while (g_running) {
        int pr = poll(&pfd, 1, 500 /*ms*/);
        if (pr < 0) {
            if (errno == EINTR) continue;
            warn_errno("mic_record_thread: poll failed");
            usleep(2000);
            continue;
        }
        if (pr == 0) {
            continue; /* timeout */
        }
        if (pfd.revents & (POLLERR | POLLHUP)) {
            warn_errno("mic_record_thread: POLLERR/POLLHUP");
            usleep(2000);
            continue;
        }
        if (pfd.revents & (POLLIN | POLLPRI)) {
            ssize_t n = read(fd, buf, BUFSZ);
            if (n > 0) {
                size_t w = fwrite(buf, 1, (size_t)n, fout);
                if (w != (size_t)n) {
                    warn_errno("mic_record_thread: fwrite short");
                }
                fflush(fout);
            } else if (n == 0) {
                /* no data; small backoff */
                usleep(1000);
            } else {
                if (errno == EAGAIN || errno == EWOULDBLOCK) {
                    /* try again */
                } else if (errno == EINTR) {
                    continue;
                } else {
                    warn_errno("mic_record_thread: read failed");
                    usleep(2000);
                }
            }
        }
    }

    free(buf);
    fclose(fout);
    g_mic_thread_alive = 0;
    return NULL;
}

/* spkr_play_thread
 * ----------------
 * - Assumes spkr_setup() already configured /dev/akpcm_cdev0 (fd_akpcm0).
 * - Continuously plays /mnt/disc1/play_s16le_stereo_16kHz.pcm in a loop.
 */
static void *spkr_play_thread(void *arg) {
    (void)arg;
    g_spkr_thread_alive = 1;

    const char *in_path = "/mnt/disc1/play_s16le_stereo_16kHz.pcm";
    FILE *fin = fopen(in_path, "rb");
    if (!fin) {
        warn_errno("spkr_play_thread: fopen(play_s16le_stereo_16kHz.pcm) failed (thread exits)");
        g_spkr_thread_alive = 0;
        return NULL;
    }

    int fd = fd_akpcm0;
    struct pollfd pfd = { .fd = fd, .events = POLLOUT };
    const size_t CHUNK = 4096; /* conservative chunk from your player */
    unsigned char *buf = (unsigned char*)malloc(CHUNK);
    if (!buf) {
        fprintf(stderr, "spkr_play_thread: malloc failed\n");
        fclose(fin);
        g_spkr_thread_alive = 0;
        return NULL;
    }

    while (g_running) {
        /* refill from file; loop back at EOF */
        size_t r = fread(buf, 1, CHUNK, fin);
        if (r == 0) {
            if (feof(fin)) {
                clearerr(fin);
                fseek(fin, 0, SEEK_SET);
                continue;
            } else {
                warn_errno("spkr_play_thread: fread failed");
                usleep(2000);
                continue;
            }
        }

        unsigned char params[64]; memset(params, 0, sizeof(params));
        unsigned long req = 0x50e1UL;
        int rc = ioctl(fd, req);
        if(rc < 0 && (errno == EFAULT || errno == EINVAL)){
            rc = ioctl(fd, req, params);
        }

        size_t off = 0;
        while (off < r && g_running) {
            int pr = poll(&pfd, 1, 500 /*ms*/);
            if (pr < 0) {
                if (errno == EINTR) continue;
                warn_errno("spkr_play_thread: poll failed");
                usleep(2000);
                continue;
            }
            if (pr == 0) continue;
            if (pfd.revents & (POLLERR | POLLHUP)) {
                warn_errno("spkr_play_thread: POLLERR/POLLHUP");
                usleep(2000);
                break;
            }
            if (pfd.revents & POLLOUT) {
                ssize_t n = write(fd, buf + off, r - off);
                if (n > 0) {
                    off += (size_t)n;
                } else if (n == 0) {
                    usleep(1000);
                } else {
                    if (errno == EAGAIN || errno == EWOULDBLOCK) {
                        /* try again */
                    } else if (errno == EINTR) {
                        continue;
                    } else {
                        warn_errno("spkr_play_thread: write failed");
                        usleep(2000);
                        break;
                    }
                }
            }
        }
    }

    free(buf);
    fclose(fin);
    g_spkr_thread_alive = 0;
    return NULL;
}

/*
 * spkr_setup()
 * ------------
 * Applies your playback ioctl sequence for the SPEAKER path.
 * Device: /dev/akpcm_cdev0  (fd_akpcm0)
 * Only setup — playback loop is commented out.
 */
int spkr_setup(void) {
    int rc;
    int fd = fd_akpcm0;

    /* params buffer used by some ioctls below */
    unsigned char params[64];
    memset(params, 0, sizeof(params));

    /* (A) Enable route/output */
    { unsigned long req=0x40045081UL; uint32_t v=1;
      rc=ioctl(fd,req,&v);
      if(rc<0) perror("ioctl 0x40045081 (enable=1)"); else printf("0x40045081 OK\n");
    }

    /* (B) 0x50e3 (optional, often before 0x40045030) */
    { unsigned long req=0x50e3UL;
      rc=ioctl(fd,req);
      if(rc<0) perror("ioctl 0x50e3"); else printf("0x50e3 OK\n");
    }

    /* (C) 0x40045030 = 5 */
    { unsigned long req=0x40045030UL; uint32_t v=5;
      rc=ioctl(fd,req,&v);
      if(rc<0) perror("ioctl 0x40045030=5"); else printf("0x40045030=5 OK\n");
    }

    /* (D) 0x40045030 = 4 */
    { unsigned long req=0x40045030UL; uint32_t v=4;
      rc=ioctl(fd,req,&v);
      if(rc<0) perror("ioctl 0x40045030=4"); else printf("0x40045030=4 OK\n");
    }

    /* (E) 0x40045010 = 4 */
    { unsigned long req=0x40045010UL; uint32_t v=4;
      rc=ioctl(fd,req,&v);
      if(rc<0) perror("ioctl 0x40045010=4"); else printf("0x40045010=4 OK\n");
    }

    /* (F) 0x40045070 = 1 */
    { unsigned long req=0x40045070UL; uint32_t v=1;
      rc=ioctl(fd,req,&v);
      if(rc<0) perror("ioctl 0x40045070=1"); else printf("0x40045070=1 OK\n");
    }

    /* (G) 0x50e2 */
    { unsigned long req=0x50e2UL;
      rc=ioctl(fd,req);
      if(rc<0) perror("ioctl 0x50e2"); else printf("0x50e2 OK\n");
    }

    /* (H) 0x401c50f2 — 28 bytes */
    { unsigned long req=0x401c50f2UL;
      unsigned char b28[28] = {
        0x80,0x3e,0x00,0x00,  /* 0x3e80 = 16000 */
        0x02,0x00,0x00,0x00,
        0x10,0x00,0x00,0x00, 0x00,0x10,0x00,0x00,
        0x0c,0x00,0x00,0x00, 0x00,0x10,0x00,0x00,
        0x00,0x00,0x00,0x00
      };
      rc=ioctl(fd,req,b28);
      if(rc<0) perror("ioctl 0x401c50f2"); else printf("0x401c50f2 (28B) OK\n");
    }

    /* (I) 0x50e0 */
    { unsigned long req=0x50e0UL;
      rc=ioctl(fd,req);
      if(rc<0) perror("ioctl 0x50e0"); else printf("0x50e0 OK\n");
    }

    /* (J) 0x804050f0 — read 64 bytes into params */
    { unsigned long req=0x804050f0UL;
      rc=ioctl(fd,req,params);
      if(rc<0) perror("ioctl 0x804050f0");
      else { printf("0x804050f0 OK (first 32B):\n"); hexdump(params, 32); }
    }

    /* (K) 0x801c50f2 — read 28 bytes */
    { unsigned long req=0x801c50f2UL; unsigned char b28[28]; memset(b28,0,sizeof(b28));
      rc=ioctl(fd,req,b28);
      if(rc<0) perror("ioctl 0x801c50f2");
      else { printf("0x801c50f2 OK (28B):\n"); hexdump(b28, 28); }
    }

    /* (L) 0x80045010 and 0x80045030 — in your log both return 0x00000004 */
    { unsigned long req=0x80045010UL; uint32_t r=0;
      rc=ioctl(fd,req,&r); if(rc<0) perror("ioctl 0x80045010"); else printf("0x80045010 -> 0x%08x\n", r);
    }
    { unsigned long req=0x80045030UL; uint32_t r=0;
      rc=ioctl(fd,req,&r); if(rc<0) perror("ioctl 0x80045030"); else printf("0x80045030 -> 0x%08x\n", r);
    }

    /* (M) 0x50e3 — optional repeat */
    { unsigned long req=0x50e3UL;
      rc=ioctl(fd,req);
      if(rc<0) perror("ioctl 0x50e3 (2)"); else printf("0x50e3 (2) OK\n");
    }

    return 0; /* best-effort */
}

/* ============================================================
 *        Section: V4L2 queue worker (poll + DQBUF + QBUF + FPS)
 * ============================================================
 *
 * Implemented as requested:
 *  - poll() on fd_video0 with ~100ms timeout
 *  - When ready, VIDIOC_DQBUF then VIDIOC_QBUF
 *  - Every 3 seconds print FPS based on dequeued/enqueued counts
 *  - Uses V4L2_MEMORY_USERPTR (project requirement)
 */
static void *v4l2_queue_thread(void *arg) {
    (void)arg;
    g_v4l2_thread_alive = 1;
    info("v4l2_queue_thread: started (USERPTR).");

    /* FPS accounting */
    double last_log = monotonic_sec();
    uint64_t dq_count = 0;
    uint64_t q_count  = 0;

    /* poll() setup */
    struct pollfd pfd;
    pfd.fd      = fd_video0;
    pfd.events  = POLLIN | POLLPRI | POLLERR | POLLHUP;
    pfd.revents = 0;

    while (g_running) {
        /* Poll video fd; small timeout to keep responsiveness on shutdown */
        int pr = poll(&pfd, 1, 100 /* ms */);
        if (pr < 0) {
            if (errno == EINTR) continue;
            warn_errno("poll(/dev/video0) failed");
            usleep(2000);
            continue;
        }
        if (pr == 0) {
            /* timeout: fall through to FPS window check */
        } else {
            if (pfd.revents & (POLLERR | POLLHUP)) {
                warn_errno("v4l2_queue_thread: POLLERR/POLLHUP");
                /* Small backoff to avoid tight loop on persistent error */
                usleep(2000);
            }

            if (pfd.revents & (POLLIN | POLLPRI)) {
                /* Try to dequeue one buffer */
                struct v4l2_buffer buf;
                memset(&buf, 0, sizeof(buf));
                buf.type   = V4L2_BUF_TYPE_VIDEO_CAPTURE;
                buf.memory = V4L2_MEMORY_USERPTR; /* USERPTR required here */

                if (ioctl(fd_video0, VIDIOC_DQBUF, &buf) == 0) {
                    dq_count++;

                    /* Re-queue same USERPTR buffer back to the driver.
                     * With USERPTR, the driver expects m.userptr + length to be valid.
                     * Reusing the same buf struct (as returned by DQBUF) is common.
                     */
                    if (ioctl(fd_video0, VIDIOC_QBUF, &buf) == 0) {
                        q_count++;
                    } else {
                        warn_errno("VIDIOC_QBUF failed (userptr=%" PRIuPTR ", len=%u)",
                                   (uintptr_t)buf.m.userptr, buf.length);
                        /* Don't break; try to keep loop alive */
                    }
                } else {
                    if (errno != EAGAIN && errno != EIO) {
                        warn_errno("VIDIOC_DQBUF failed");
                    }
                    /* If nothing was ready despite poll, brief nap */
                    usleep(1000);
                }
            }
        }

        /* Periodic FPS log every ~3 seconds */
        double now = monotonic_sec();
        if ((now - last_log) >= 3.0) {
            double dt = now - last_log;
            double fps_dq = dq_count / (dt > 0.0 ? dt : 1.0);
            double fps_q  = q_count  / (dt > 0.0 ? dt : 1.0);
            fprintf(stderr,
                    "[V4L2][USERPTR] %.1f s — DQ: %.2f fps, Q: %.2f fps (dq=%" PRIu64 ", q=%" PRIu64 ")\n",
                    dt, fps_dq, fps_q, dq_count, q_count);
            dq_count = 0;
            q_count  = 0;
            last_log = now;
        }
    }

    info("v4l2_queue_thread: stopping.");
    g_v4l2_thread_alive = 0;
    return NULL;
}

/* ============================================================
 *                Section: Stream bring-up sequence
 * ============================================================
 *
 * stream_setup()
 * --------------
 * Order:
 *  1) ion_reserve_and_map()
 *  2) isp_setup()
 *  3) v4l2_setup()         (USERPTR expected)
 *  4) mic_setup()
 *  5) spkr_setup()
 *  6) NOTE about /dev/uio0 encoder init (pending reverse engineering)
 *
 * Returns 0 on success, <0 on failure.
 * The caller (main) will do steps:
 *  7) start v4l2_queue_thread()
 *  8) main idle loop (10ms)
 *  9) cleanup: stop thread, stream-off, close devices
 */
int stream_setup(void) {
    int rc;

    /* 1) ION */
    rc = ion_reserve_and_map();
    if (rc < 0) { warn_errno("ion_reserve_and_map()"); return -1; }

    /* 2) ISP */
    rc = isp_setup("isp_sc1345_dvp.conf");
    if (rc < 0) { warn_errno("isp_setup()"); return -1; }

    /* 3) V4L2 core (format, reqbufs USERPTR, initial QBUF, STREAMON) */
    rc = v4l2_setup();
    if (rc < 0) { warn_errno("v4l2_setup()"); return -1; }

    /* 4) MIC (audio capture path) */
    rc = mic_setup();
    if (rc < 0) { warn_errno("mic_setup()"); return -1; }

    /* 6) Video encoder via /dev/uio0
     *
     *    Intentional placeholder — we need to confirm the exact bring-up
     *    sequence from tracing logs and the decompiled binary before coding it.
     *    DO NOT implement by guesswork; mirror the vendor IPC behavior.
     */
    info("NOTE: Video encoder (/dev/uio0) init is pending (trace+decompile required).");

    /* 5) Speaker (audio playback path) */
    rc = spkr_setup();
    if (rc < 0) { warn_errno("spkr_setup()"); return -1; }

    return 0;
}

int stream_stop(void) {
    enum v4l2_buf_type type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (fd_video0 >= 0) {
        if (ioctl(fd_video0, VIDIOC_STREAMOFF, &type) < 0) {
            warn_errno("VIDIOC_STREAMOFF");
        } else {
            info("VIDIOC_STREAMOFF done.");
        }
    }

    return 0;
}

/* ============================================================
 *                           main()
 * ============================================================ */
// ============================================================================
// Entry point
// ----------------------------------------------------------------------------
int main(void) {
    if (setup_signals() < 0) return 1;
    if (open_devices() < 0)  return 1;

    /* Steps 1–6 */
    if (stream_setup() < 0) {
        close_devices();
        return 1;
    }

    /* 7) Start V4L2 queue worker */
    g_running = 1;
    if (pthread_create(&g_v4l2_thread, NULL, v4l2_queue_thread, NULL) != 0) {
        warn_errno("pthread_create(v4l2_queue_thread)");
        g_running = 0;
        close_devices();
        return 1;
    }

    /* Start mic and speaker threads (best-effort) */
    if (fd_akpcm1 >= 0) {
        if (pthread_create(&g_mic_thread, NULL, mic_record_thread, NULL) != 0) {
            warn_errno("pthread_create(mic_record_thread)");
        }
    }
    if (fd_akpcm0 >= 0) {
        if (pthread_create(&g_spkr_thread, NULL, spkr_play_thread, NULL) != 0) {
            warn_errno("pthread_create(spkr_play_thread)");
        }
    }

    /* 8) Idle loop (10 ms) until a signal arrives */
    info("Streaming… Press Ctrl+C to quit.");
    while (g_running) {
        usleep(10000); /* 10ms */
    }

    /* 9) Cleanup (stop thread and V4L2 stream-off if applicable) */
    info("Shutting down…");

    /* Stop worker threads */
    if (g_v4l2_thread_alive) pthread_join(g_v4l2_thread, NULL);
    if (g_mic_thread_alive)  pthread_join(g_mic_thread, NULL);
    if (g_spkr_thread_alive) pthread_join(g_spkr_thread, NULL);

    /* STREAMOFF (if v4l2_setup() did STREAMON) */
    stream_stop();

    close_devices();
    return 0;
}

// ============================ END ORIGINAL CODE ============================

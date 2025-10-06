#include "ak3918/sdk/akispsdk.h"

#include <errno.h>
#include <fcntl.h>
#include <linux/ioctl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define ISP_DEVICE      "/dev/isp_char"
#define ISP_IOCTL_TYPE  0x49
#define ISP_ARG_SIZE    4

static int g_fd_isp = -1;

static int ensure_isp_fd(void) {
    if (g_fd_isp >= 0) {
        return 0;
    }

    int fd = open(ISP_DEVICE, O_RDWR | O_CLOEXEC);
    if (fd < 0) {
        return -1;
    }

    g_fd_isp = fd;
    return 0;
}

static int do_isp_ioctl(unsigned long req, void *param) {
    if (ensure_isp_fd() != 0) {
        return -1;
    }
    return ioctl(g_fd_isp, req, param);
}

int ak_isp_sdk_init(void) {
    return ensure_isp_fd();
}

int ak_isp_fd(void) {
    if (ensure_isp_fd() != 0) {
        return -1;
    }
    return g_fd_isp;
}

int ak_isp_sdk_exit(void) {
    if (g_fd_isp < 0) {
        return 0;
    }

    int rc;
    do {
        rc = close(g_fd_isp);
    } while (rc < 0 && errno == EINTR);

    if (rc < 0) {
        return -1;
    }

    g_fd_isp = -1;
    return 0;
}

#define DEF_ISP_SET(name, nr, raw_req)                                           \
    int ak_isp_##name(const void *param) {                                       \
        const unsigned long req = _IOC(_IOC_WRITE, ISP_IOCTL_TYPE, (nr),         \
                                       ISP_ARG_SIZE);                            \
        return do_isp_ioctl(req, (void *)param);                                 \
    } /* req = raw_req */

#define DEF_ISP_GET(name, nr, raw_req)                                           \
    int ak_isp_##name(void *param) {                                             \
        const unsigned long req = _IOC(_IOC_READ, ISP_IOCTL_TYPE, (nr),          \
                                       ISP_ARG_SIZE);                            \
        return do_isp_ioctl(req, param);                                         \
    } /* req = raw_req */

int ak_isp_sensor_load_conf(const struct blob_desc *desc) {
    const unsigned long req = _IOC(_IOC_WRITE, ISP_IOCTL_TYPE, 0x69, ISP_ARG_SIZE);
    return do_isp_ioctl(req, (void *)desc);
} /* req = 0x40044969UL */

DEF_ISP_SET(sensor_set_reg,        0x6b, 0x4004496bUL);
DEF_ISP_GET(sensor_get_reg,        0x6c, 0x8004496cUL);
DEF_ISP_GET(sensor_get_id,         0x71, 0x80044971UL);
DEF_ISP_SET(set_flip_mirror,       0x79, 0x40044979UL);
DEF_ISP_SET(set_sensor_fps,        0x7a, 0x4004497aUL);
DEF_ISP_GET(get_sensor_fps,        0x7b, 0x8004497bUL);
int ak_isp_set_user_params(void *params) {
    const unsigned long req = _IOC(_IOC_WRITE, ISP_IOCTL_TYPE, 0x6d, ISP_ARG_SIZE);
    return do_isp_ioctl(req, params);
} /* req = 0x4004496dUL */

DEF_ISP_GET(get_work_scene,        0x7c, 0x8004497cUL);

DEF_ISP_SET(set_raw_hist_attr,     0x43, 0x40044943UL);
DEF_ISP_GET(get_raw_hist_attr,     0x44, 0x80044944UL);
DEF_ISP_GET(get_raw_hist_stat_info,0x45, 0x80044945UL);

DEF_ISP_SET(set_rgb_hist_attr,     0x46, 0x40044946UL);
DEF_ISP_GET(get_rgb_hist_attr,     0x47, 0x80044947UL);
DEF_ISP_GET(get_rgb_hist_stat_info,0x48, 0x80044948UL);

DEF_ISP_SET(set_yuv_hist_attr,     0x49, 0x40044949UL);
DEF_ISP_GET(get_yuv_hist_attr,     0x4a, 0x8004494aUL);
DEF_ISP_GET(get_yuv_hist_stat_info,0x4b, 0x8004494bUL);

DEF_ISP_SET(set_exp_type,          0x4c, 0x4004494cUL);
DEF_ISP_GET(get_exp_type,          0x4d, 0x8004494dUL);
DEF_ISP_SET(set_ae_attr,           0x50, 0x40044950UL);
DEF_ISP_GET(get_ae_attr,           0x51, 0x80044951UL);
DEF_ISP_GET(get_ae_run_info,       0x52, 0x80044952UL);
DEF_ISP_SET(set_frame_rate,        0x4e, 0x4004494eUL);
DEF_ISP_GET(get_frame_rate,        0x4f, 0x8004494fUL);

DEF_ISP_SET(set_wb_type,           0x53, 0x40044953UL);
DEF_ISP_GET(get_wb_type,           0x54, 0x80044954UL);
DEF_ISP_SET(set_awb_attr,          0x55, 0x40044955UL);
DEF_ISP_GET(get_awb_attr,          0x56, 0x80044956UL);
DEF_ISP_SET(set_awb_ex_attr,       0x73, 0x40044973UL);
DEF_ISP_GET(get_awb_ex_attr,       0x74, 0x80044974UL);
DEF_ISP_GET(get_awb_stat_info,     0x59, 0x80044959UL);
DEF_ISP_SET(set_mwb_attr,          0x63, 0x40044963UL);
DEF_ISP_GET(get_mwb_attr,          0x64, 0x80044964UL);

DEF_ISP_SET(set_af_attr,           0x60, 0x40044960UL);
DEF_ISP_GET(get_af_attr,           0x61, 0x80044961UL);
DEF_ISP_GET(get_af_stat_info,      0x62, 0x80044962UL);

DEF_ISP_SET(set_blc_attr,          0x02, 0x40044902UL);
DEF_ISP_GET(get_blc_attr,          0x01, 0x80044901UL);
DEF_ISP_SET(set_lsc_attr,          0x04, 0x40044904UL);
DEF_ISP_GET(get_lsc_attr,          0x03, 0x80044903UL);
DEF_ISP_SET(set_dpc_attr,          0x10, 0x40044910UL);
DEF_ISP_GET(get_dpc_attr,          0x0f, 0x8004490fUL);

int ak_isp_set_sdpc_attr(const void *param) {
    (void)param;
    if (ensure_isp_fd() != 0) {
        return -1;
    }
    return 0;
}

int ak_isp_get_sdpc_attr(void *param) {
    (void)param;
    if (ensure_isp_fd() != 0) {
        return -1;
    }
    return 0;
}

DEF_ISP_SET(set_gb_attr,           0x06, 0x40044906UL);
DEF_ISP_GET(get_gb_attr,           0x05, 0x80044905UL);
DEF_ISP_SET(set_demo_attr,         0x0e, 0x4004490eUL);
DEF_ISP_GET(get_demo_attr,         0x0d, 0x8004490dUL);

DEF_ISP_SET(set_ccm_attr,          0x12, 0x40044912UL);
DEF_ISP_GET(get_ccm_attr,          0x11, 0x80044911UL);
DEF_ISP_SET(set_rgb2yuv_attr,      0x3f, 0x4004493fUL);
DEF_ISP_GET(get_rgb2yuv_attr,      0x40, 0x80044940UL);
DEF_ISP_SET(set_contrast_attr,     0x39, 0x40044939UL);
DEF_ISP_GET(get_contrast_attr,     0x3a, 0x8004493aUL);
DEF_ISP_SET(set_saturation_attr,   0x3b, 0x4004493bUL);
DEF_ISP_GET(get_saturation_attr,   0x3c, 0x8004493cUL);
DEF_ISP_SET(set_hue_attr,          0x77, 0x40044977UL);
DEF_ISP_GET(get_hue_attr,          0x78, 0x80044978UL);
DEF_ISP_SET(set_effect_attr,       0x41, 0x40044941UL);
DEF_ISP_GET(get_effect_attr,       0x42, 0x80044942UL);

DEF_ISP_SET(set_raw_lut_attr,      0x0a, 0x4004490aUL);
DEF_ISP_GET(get_raw_lut_attr,      0x09, 0x80044909UL);
DEF_ISP_SET(set_rgb_gamma_attr,    0x1a, 0x4004491aUL);
DEF_ISP_GET(get_rgb_gamma_attr,    0x19, 0x80044919UL);
DEF_ISP_SET(set_y_gamma_attr,      0x75, 0x40044975UL);
DEF_ISP_GET(get_y_gamma_attr,      0x76, 0x80044976UL);

DEF_ISP_SET(set_sharp_attr,        0x25, 0x40044925UL);
DEF_ISP_GET(get_sharp_attr,        0x26, 0x80044926UL);
DEF_ISP_SET(set_sharp_ex_attr,     0x27, 0x40044927UL);
DEF_ISP_GET(get_sharp_ex_attr,     0x28, 0x80044928UL);
DEF_ISP_SET(set_fcs_attr,          0x36, 0x40044936UL);
DEF_ISP_GET(get_fcs_attr,          0x35, 0x80044935UL);
DEF_ISP_SET(set_wdr_attr,          0x1b, 0x4004491bUL);
DEF_ISP_GET(get_wdr_attr,          0x1c, 0x8004491cUL);
DEF_ISP_SET(set_nr1_attr,          0x0c, 0x4004490cUL);
DEF_ISP_GET(get_nr1_attr,          0x0b, 0x8004490bUL);
DEF_ISP_SET(set_nr2_attr,          0x2b, 0x4004492bUL);
DEF_ISP_GET(get_nr2_attr,          0x2c, 0x8004492cUL);
DEF_ISP_SET(set_3d_nr_attr,        0x2f, 0x4004492fUL);
DEF_ISP_GET(get_3d_nr_attr,        0x30, 0x80044930UL);
DEF_ISP_SET(set_3d_nr_ref_attr,    0x67, 0x40044967UL);
DEF_ISP_GET(get_3d_nr_ref_attr,    0x68, 0x80044968UL);
DEF_ISP_GET(get_3d_nr_stat_info,   0x70, 0x80044970UL);

DEF_ISP_SET(set_weight_attr,       0x5e, 0x4004495eUL);
DEF_ISP_GET(get_weight_attr,       0x5f, 0x8004495fUL);
DEF_ISP_SET(set_main_chan_mask_area,0x5a,0x4004495aUL);
DEF_ISP_GET(get_main_chan_mask_area,0x5b,0x8004495bUL);
DEF_ISP_SET(set_sub_chan_mask_area,0x65,0x40044965UL);
DEF_ISP_GET(get_sub_chan_mask_area,0x66,0x80044966UL);
DEF_ISP_SET(set_mask_color,        0x5c, 0x4004495cUL);
DEF_ISP_GET(get_mask_color,        0x5d, 0x8004495dUL);

DEF_ISP_SET(set_misc_attr,         0x6e, 0x4004496eUL);
DEF_ISP_GET(get_misc_attr,         0x6f, 0x8004496fUL);
DEF_ISP_SET(set_isp_capturing,     0x72, 0x40044972UL);

#undef DEF_ISP_SET
#undef DEF_ISP_GET

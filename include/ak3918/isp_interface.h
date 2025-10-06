#ifndef AK3918_ISP_INTERFACE_H
#define AK3918_ISP_INTERFACE_H

/* Bits for isp_param_config::type flags */
#define ISP_PARM_MODE             0x01
#define ISP_PARM_CHANNEL2         0x02
#define ISP_PARM_OSD              0x04
#define ISP_PARM_OCCLUSION        0x08
#define ISP_PARM_OCCLUSION_COLOR  0x10
#define ISP_PARM_ZOOM             0x20

enum isp_working_mode {
    ISP_JPEG_MODE,           /* JPEG compression single frame */
    ISP_JPEG_VIDEO,          /* JPEG video stream */
    ISP_YUV_OUT,             /* YUV single frame, no minor channel */
    ISP_YUV_BYPASS,          /* YUV single frame bypass */
    ISP_YUV_MERGER_OUT,
    ISP_YUV_BIG,             /* YUV single frame, big image mode */
    ISP_YUV_VIDEO_OUT,       /* YUV video stream */
    ISP_YUV_VIDEO_BYPASS,    /* YUV video stream bypass */
    ISP_YUV_VIDEO_MERGER_OUT,
    ISP_RGB_OUT,             /* RGB single frame */
    ISP_RGB_VIDEO_OUT,       /* RGB video stream */
    ISP_RGB_BIG,             /* RGB single frame, big image mode */
};

enum isp_mode_class {
    ISP_RGB_CLASS,
    ISP_YUV_CLASS,
    ISP_JPEG_CLASS,
};

struct isp_channel2_info {
    int type;
    int width;
    int height;
    int enable;
};

struct isp_mode_info {
    int type;
    enum isp_working_mode mode;
};

struct isp_osd_info {
    int type;
    int channel;
    int color_depth;
    int color_transparency;
    int start_xpos;
    int end_xpos;
    int start_ypos;
    int end_ypos;
    int enable;
    unsigned long phys_addr;
    unsigned long virt_addr;
};

struct isp_occlusion_info {
    int type;
    int channel;
    int number;
    int start_xpos;
    int end_xpos;
    int start_ypos;
    int end_ypos;
    int enable;
};

struct isp_occlusion_color {
    int type;
    int color_type;
    int transparency;
    int y_component;
    int u_component;
    int v_component;
};

struct isp_zoom_info {
    int type;
    int channel;          /* 1 = master channel, 2 = secondary */
    int cut_xpos;
    int cut_ypos;
    int cut_width;
    int cut_height;
    int out_width;
    int out_height;
};

/* Command identifiers for PC tooling */
#define ISP_CID_BLACK_BALANCE      0x60
#define ISP_CID_LENS               0x61
#define ISP_CID_DEMOSAIC           0x62
#define ISP_CID_RGB_FILTER         0x63
#define ISP_CID_UV_FILTER          0x64
#define ISP_CID_DEFECT_PIXEL       0x65
#define ISP_CID_WHITE_BALANCE      0x66
#define ISP_CID_AUTO_WHITE_BALANCE 0x67
#define ISP_CID_COLOR              0x68
#define ISP_CID_GAMMA              0x69
#define ISP_CID_BRIGHTNESS_ENHANCE 0x70
#define ISP_CID_SATURATION         0x72
#define ISP_CID_HISTOGRAM          0x73
#define ISP_CID_SPECIAL_EFFECT     0x74
#define ISP_CID_SET_SENSOR_PARAM   0x75

struct isp_black_balance {
    int type;
    int enable;
    unsigned int r_offset; /* reg table 0x20: offset 13 [31:22] */
    unsigned int g_offset; /* reg table 0x20: offset 14 [31:22] */
    unsigned int b_offset; /* reg table 0x20: offset 15 [31:22] */
};

struct isp_lens_correct {
    int type;
    int enable;             /* reg table 0x20: offset 24 [31] */
    int lens_coefa[10];     /* reg table 0x20: offset 13 [21:0] */
    int lens_coefb[10];
    int lens_coefc[10];
    unsigned int lens_range[10];
    unsigned int lens_xref; /* reg table 0x20: offset 23 [31:22] */
    unsigned int lens_yref; /* reg table 0x20: offset 23 [31:22] */
};

struct isp_demosaic {
    int type;
    int enable;             /* reg table 0x20: offset 2 [12] */
    unsigned int threshold; /* reg table 0x20: offset 2 [11:0] */
};

struct isp_rgb_filter {
    int type;
    int enable;             /* reg table 0x24: offset 1 [31] */
    unsigned int threshold; /* reg table 0x24: offset 1 [21:12] */
};

struct isp_uv_filter {
    int type;
    int enable;             /* reg table 0x24: offset 13 [30] */
};

struct isp_defect_pixel {
    int type;
    int enable;             /* reg table 0x24: offset 1 [30] */
    unsigned int threshold; /* reg table 0x24: offset 1 [29:28] */
};

struct isp_white_balance {
    int type;
    int enable;
    unsigned int co_r;      /* reg table 0x24: offset 0 [11:0] */
    unsigned int co_g;      /* reg table 0x24: offset 0 [23:12] */
    unsigned int co_b;      /* reg table 0x24: offset 1 [11:0] */
};

struct isp_auto_white_balance {
    int type;
    int enable;             /* reg table 0x20: offset 25 [31] */
    unsigned int gr_low;
    unsigned int gr_high;
    unsigned int gb_low;
    unsigned int gb_high;
    unsigned int grb_low;
    unsigned int grb_high;
    unsigned int r_low;
    unsigned int r_high;
    unsigned int g_low;
    unsigned int g_high;
    unsigned int b_low;
    unsigned int b_high;
    unsigned int co_r;      /* reg table 0x24: offset 0 [11:0] */
    unsigned int co_g;      /* reg table 0x24: offset 0 [23:12] */
    unsigned int co_b;      /* reg table 0x24: offset 1 [11:0] */
};

struct isp_color_correct {
    int type;
    int enable;             /* reg table 0x24: offset 11 [31] */
    unsigned int cc_thrs_low;
    unsigned int cc_thrs_high;
    int ccMtrx[3][3];
};

struct isp_gamma_calculate {
    int type;
    int enable;             /* reg table 0x24: offset 11 [30] */
    int is_sync;            /* 0 or 1 */
    unsigned int gamma[32]; /* reg table 0x28: 64 registers */
};

struct isp_brightness_enhance {
    int type;
    int enable;             /* reg table 0x24: offset 11 [29] */
    int ygain;              /* reg table 0x24: offset 12 [31:24] */
    unsigned int y_thrs;    /* reg table 0x24: offset 12 [22:12] */
    unsigned int y_edgek;   /* reg table 0x24: offset 12 [10:0] */
};

struct isp_saturation {
    int type;
    int enable;             /* reg table 0x24: offset 13 [31] */
    int Khigh;              /* reg table 0x24: offset 13 [29:20], (0.1~3)*256 */
    int Klow;               /* reg table 0x24: offset 13 [19:10] */
    int Kslope;             /* reg table 0x24: offset 13 [9:0] */
    unsigned int Chigh;     /* reg table 0x24: offset 14 [31:24] */
    unsigned int Clow;      /* reg table 0x24: offset 14 [23:16] */
};

struct isp_histogram {
    int type;
    int enable;
    int sync;
    unsigned int hist[32];
};

struct isp_special_effect {
    int type;
    int enable;             /* reg table 0x24: offset 11 [28] */
    int solar_enable;       /* reg table 0x24: offset 11 [27] */
    unsigned int solar_thrs;/* reg table 0x24: offset 0 [31:24] */
    int y_eff_coefa;        /* reg table 0x24: offset 14 [15:8] */
    unsigned int y_eff_coefb;/* reg table 0x24: offset 14 [7:0] */
    int u_eff_coefa;        /* reg table 0x24: offset 15 [31:24] */
    unsigned int u_eff_coefb;/* reg table 0x24: offset 15 [23:16] */
    int v_eff_coefa;        /* reg table 0x24: offset 15 [15:8] */
    unsigned int v_eff_coefb;/* reg table 0x24: offset 15 [7:0] */
};

struct isp_config_sensor_reg {
    int type;
    int enable;
    unsigned int cmd;
    unsigned int data;
};

#endif /* AK3918_ISP_INTERFACE_H */

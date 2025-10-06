#include "ak3918/isp_blocks.h"

#include <stddef.h>

static const ak_isp_subblock_info_t block00_subs[] = {
    {0x0000, "ak_isp_set_blc_attr", 182, 182},
};

static const ak_isp_subblock_info_t block01_subs[] = {
    {0x0000, "ak_isp_set_lsc_attr", 188, 188},
};

static const ak_isp_subblock_info_t block02_subs[] = {
    {0x0000, "ak_isp_set_raw_lut_attr", 872, 872},
};

static const ak_isp_subblock_info_t block03_subs[] = {
    {0x0000, "ak_isp_set_nr1_attr", 1782, 1782},
    {0x06f6, "ak_isp_set_nr2_attr", 402, 482},
};

static const ak_isp_subblock_info_t block04_subs[] = {
    {0x0000, "ak_isp_set_3d_nr_attr", 514, 1084},
};

static const ak_isp_subblock_info_t block05_subs[] = {
    {0x0000, "ak_isp_set_gb_attr", 82, 82},
};

static const ak_isp_subblock_info_t block06_subs[] = {
    {0x0000, "ak_isp_set_demo_attr", 18, 18},
};

static const ak_isp_subblock_info_t block07_subs[] = {
    {0x0000, "ak_isp_set_rgb_gamma_attr", 872, 872},
};

static const ak_isp_subblock_info_t block08_subs[] = {
    {0x0000, "ak_isp_set_ccm_attr", 132, 148},
};

static const ak_isp_subblock_info_t block09_subs[] = {
    {0x0000, "ak_isp_set_fcs_attr", 102, 102},
};

static const ak_isp_subblock_info_t block0a_subs[] = {
    {0x0000, "ak_isp_set_wdr_attr", 8898, 9962},
};

static const ak_isp_subblock_info_t block0b_subs[] = {
    {0x0000, "ak_isp_set_sharp_attr", 194, 11062},
    {0x2b36, "ak_isp_set_sharp_ex_attr", 30, 30},
};

static const ak_isp_subblock_info_t block0c_subs[] = {
    {0x0000, "ak_isp_set_saturation_attr", 202, 11092},
};

static const ak_isp_subblock_info_t block0d_subs[] = {
    {0x0000, "ak_isp_set_contrast_attr", 60, 122},
};

static const ak_isp_subblock_info_t block0e_subs[] = {
    {0x0000, "ak_isp_set_rgb2yuv_attr", 2, 60},
};

static const ak_isp_subblock_info_t block0f_subs[] = {
    {0x0000, "ak_isp_set_effect_attr", 2, 10},
};

static const ak_isp_subblock_info_t block10_subs[] = {
    {0x0000, "ak_isp_set_dpc_attr", 10, 84},
    {0x0054, "ak_isp_set_sdpc_attr", 4100, 4100},
};

static const ak_isp_subblock_info_t block11_subs[] = {
    {0x0000, "ak_isp_set_weight_attr", 256, 4144},
};

static const ak_isp_subblock_info_t block12_subs[] = {
    {0x0000, "ak_isp_set_af_attr", 42, 256},
};

static const ak_isp_subblock_info_t block13_subs[] = {
    {0x0000, "ak_isp_set_wb_type", 2, 2},
    {0x0002, "ak_isp_set_mwb_attr", 8, 12},
    {0x000e, "ak_isp_set_awb_attr", 0, 186},
    {0x00c8, "ak_isp_set_awb_ex_attr", 324, 324},
};

static const ak_isp_subblock_info_t block14_subs[] = {
    {0x0000, "ak_isp_set_raw_hist_attr", 2, 2},
    {0x0002, "ak_isp_set_rgb_hist_attr", 2, 2},
    {0x0004, "ak_isp_set_yuv_hist_attr", 2, 2},
    {0x0006, "ak_isp_set_exp_type", 2, 2},
    {0x0008, "ak_isp_set_frame_rate", 24, 24},
    {0x0020, "ak_isp_set_ae_attr", 148, 204},
};

static const ak_isp_subblock_info_t block15_subs[] = {
    {0x0000, "ak_isp_set_misc_attr", 26, 240},
};

static const ak_isp_subblock_info_t block16_subs[] = {
    {0x0000, "ak_isp_set_y_gamma_attr", 18, 302},
};

static const ak_isp_subblock_info_t block17_subs[] = {
    {0x0000, "ak_isp_set_hue_attr", 992, 992},
};

static const ak_isp_subblock_info_t block18_subs[] = {
    {0x0000, "ak_isp_set_main_chan_mask_area", 16, 16},
    {0x0010, "ak_isp_set_sub_chan_mask_area", 16, 16},
    {0x0020, "ak_isp_set_mask_color", 4, 4},
    {0x0024, "ak_isp_set_capturing_param (logged)", 0, 0},
};

static const ak_isp_subblock_info_t block1b_subs[] = {
    {0x0000, "ak_isp_sensor_load_conf", 144, 568},
};

static const ak_isp_subblock_info_t block1c_subs[] = {
    {0x0000, "ak_isp_sensor_load_conf", 144, 504},
};

static const ak_isp_block_info_t block_infos[] = {
    {0x00, "Black level correction", 182, 182, block00_subs, sizeof(block00_subs)/sizeof(block00_subs[0]), 0},
    {0x01, "Lens shading correction", 188, 188, block01_subs, sizeof(block01_subs)/sizeof(block01_subs[0]), 0},
    {0x02, "RAW LUT", 872, 872, block02_subs, sizeof(block02_subs)/sizeof(block02_subs[0]), 0},
    {0x03, "Noise reduction stage 1/2", 2184, 2264, block03_subs, sizeof(block03_subs)/sizeof(block03_subs[0]), 0},
    {0x04, "3D noise reduction", 514, 1084, block04_subs, sizeof(block04_subs)/sizeof(block04_subs[0]), 0},
    {0x05, "Green balance", 82, 82, block05_subs, sizeof(block05_subs)/sizeof(block05_subs[0]), 0},
    {0x06, "Demosaic", 18, 18, block06_subs, sizeof(block06_subs)/sizeof(block06_subs[0]), 0},
    {0x07, "RGB gamma", 872, 872, block07_subs, sizeof(block07_subs)/sizeof(block07_subs[0]), 0},
    {0x08, "Color correction matrix", 132, 148, block08_subs, sizeof(block08_subs)/sizeof(block08_subs[0]), 0},
    {0x09, "False color suppression", 102, 102, block09_subs, sizeof(block09_subs)/sizeof(block09_subs[0]), 0},
    {0x0A, "Wide dynamic range", 8898, 9962, block0a_subs, sizeof(block0a_subs)/sizeof(block0a_subs[0]), 0},
    {0x0B, "Sharpness", 194, 11092, block0b_subs, sizeof(block0b_subs)/sizeof(block0b_subs[0]), 0},
    {0x0C, "Saturation", 202, 11092, block0c_subs, sizeof(block0c_subs)/sizeof(block0c_subs[0]), 0},
    {0x0D, "Contrast", 60, 122, block0d_subs, sizeof(block0d_subs)/sizeof(block0d_subs[0]), 0},
    {0x0E, "RGB to YUV", 2, 60, block0e_subs, sizeof(block0e_subs)/sizeof(block0e_subs[0]), 0},
    {0x0F, "Special effects", 2, 10, block0f_subs, sizeof(block0f_subs)/sizeof(block0f_subs[0]), 0},
    {0x10, "Defect pixel correction", 10, 4184, block10_subs, sizeof(block10_subs)/sizeof(block10_subs[0]), 0},
    {0x11, "AE weighting", 256, 4144, block11_subs, sizeof(block11_subs)/sizeof(block11_subs[0]), 0},
    {0x12, "Auto focus", 42, 256, block12_subs, sizeof(block12_subs)/sizeof(block12_subs[0]), 0},
    {0x13, "White balance", 10, 524, block13_subs, sizeof(block13_subs)/sizeof(block13_subs[0]), 0},
    {0x14, "Histogram & exposure", 180, 236, block14_subs, sizeof(block14_subs)/sizeof(block14_subs[0]), 0},
    {0x15, "Misc", 26, 240, block15_subs, sizeof(block15_subs)/sizeof(block15_subs[0]), 0},
    {0x16, "Y gamma", 18, 302, block16_subs, sizeof(block16_subs)/sizeof(block16_subs[0]), 0},
    {0x17, "Hue", 992, 992, block17_subs, sizeof(block17_subs)/sizeof(block17_subs[0]), 0},
    {0x18, "Mask areas", 32, 36, block18_subs, sizeof(block18_subs)/sizeof(block18_subs[0]), 0},
    {0x1B, "Sensor load script (type B)", 144, 568, block1b_subs, sizeof(block1b_subs)/sizeof(block1b_subs[0]), 1},
    {0x1C, "Sensor load script (type C)", 144, 504, block1c_subs, sizeof(block1c_subs)/sizeof(block1c_subs[0]), 1},
};

const ak_isp_block_info_t *ak_isp_get_block_info(uint16_t id)
{
    for (size_t i = 0; i < sizeof(block_infos)/sizeof(block_infos[0]); ++i) {
        if (block_infos[i].id == id) {
            return &block_infos[i];
        }
    }
    return NULL;
}

const ak_isp_block_info_t *ak_isp_block_info_first(void)
{
    if (sizeof(block_infos) == 0) {
        return NULL;
    }
    return &block_infos[0];
}

const ak_isp_block_info_t *ak_isp_block_info_next(const ak_isp_block_info_t *info)
{
    if (!info) {
        return NULL;
    }
    size_t index = (size_t)(info - block_infos);
    if (index + 1 >= sizeof(block_infos)/sizeof(block_infos[0])) {
        return NULL;
    }
    return &block_infos[index + 1];
}


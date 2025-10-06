#ifndef AKISPSDK_H
#define AKISPSDK_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Descriptor de blob visto en trazas */
struct blob_desc {
    uint32_t nwords; /* nº de palabras de 32 bits */
    void *ptr;       /* puntero a los datos */
};

/* ----------------------------------------------------------------------------------
 * Init / Exit
 * ---------------------------------------------------------------------------------- */
int ak_isp_sdk_init(void);
int ak_isp_sdk_exit(void);
int ak_isp_fd(void);

/* ----------------------------------------------------------------------------------
 * Sensor I/F y parámetros globales
 * ---------------------------------------------------------------------------------- */
int ak_isp_sensor_load_conf(const struct blob_desc *desc);
int ak_isp_sensor_set_reg(const void *param);
int ak_isp_sensor_get_reg(void *param);
int ak_isp_sensor_get_id(void *param);
int ak_isp_set_flip_mirror(const void *param);
int ak_isp_set_sensor_fps(const void *param);
int ak_isp_get_sensor_fps(void *param);
int ak_isp_set_user_params(void *params);
int ak_isp_get_work_scene(void *param);

/* ----------------------------------------------------------------------------------
 * Histogramas RAW / RGB / YUV
 * ---------------------------------------------------------------------------------- */
int ak_isp_set_raw_hist_attr(const void *param);
int ak_isp_get_raw_hist_attr(void *param);
int ak_isp_get_raw_hist_stat_info(void *param);

int ak_isp_set_rgb_hist_attr(const void *param);
int ak_isp_get_rgb_hist_attr(void *param);
int ak_isp_get_rgb_hist_stat_info(void *param);

int ak_isp_set_yuv_hist_attr(const void *param);
int ak_isp_get_yuv_hist_attr(void *param);
int ak_isp_get_yuv_hist_stat_info(void *param);

/* ----------------------------------------------------------------------------------
 * AE / Exposición
 * ---------------------------------------------------------------------------------- */
int ak_isp_set_exp_type(const void *param);
int ak_isp_get_exp_type(void *param);
int ak_isp_set_ae_attr(const void *param);
int ak_isp_get_ae_attr(void *param);
int ak_isp_get_ae_run_info(void *param);
int ak_isp_set_frame_rate(const void *param);
int ak_isp_get_frame_rate(void *param);

/* ----------------------------------------------------------------------------------
 * AWB / MWB
 * ---------------------------------------------------------------------------------- */
int ak_isp_set_wb_type(const void *param);
int ak_isp_get_wb_type(void *param);
int ak_isp_set_awb_attr(const void *param);
int ak_isp_get_awb_attr(void *param);
int ak_isp_set_awb_ex_attr(const void *param);
int ak_isp_get_awb_ex_attr(void *param);
int ak_isp_get_awb_stat_info(void *param);
int ak_isp_set_mwb_attr(const void *param);
int ak_isp_get_mwb_attr(void *param);

/* ----------------------------------------------------------------------------------
 * AF
 * ---------------------------------------------------------------------------------- */
int ak_isp_set_af_attr(const void *param);
int ak_isp_get_af_attr(void *param);
int ak_isp_get_af_stat_info(void *param);

/* ----------------------------------------------------------------------------------
 * Bloques de corrección / mejoras
 * ---------------------------------------------------------------------------------- */
int ak_isp_set_blc_attr(const void *param);
int ak_isp_get_blc_attr(void *param);
int ak_isp_set_lsc_attr(const void *param);
int ak_isp_get_lsc_attr(void *param);
int ak_isp_set_dpc_attr(const void *param);
int ak_isp_get_dpc_attr(void *param);
int ak_isp_set_sdpc_attr(const void *param);
int ak_isp_get_sdpc_attr(void *param);
int ak_isp_set_gb_attr(const void *param);
int ak_isp_get_gb_attr(void *param);
int ak_isp_set_demo_attr(const void *param);
int ak_isp_get_demo_attr(void *param);

/* ----------------------------------------------------------------------------------
 * Color / Matrices / Conversión
 * ---------------------------------------------------------------------------------- */
int ak_isp_set_ccm_attr(const void *param);
int ak_isp_get_ccm_attr(void *param);
int ak_isp_set_rgb2yuv_attr(const void *param);
int ak_isp_get_rgb2yuv_attr(void *param);
int ak_isp_set_contrast_attr(const void *param);
int ak_isp_get_contrast_attr(void *param);
int ak_isp_set_saturation_attr(const void *param);
int ak_isp_get_saturation_attr(void *param);
int ak_isp_set_hue_attr(const void *param);
int ak_isp_get_hue_attr(void *param);
int ak_isp_set_effect_attr(const void *param);
int ak_isp_get_effect_attr(void *param);

/* ----------------------------------------------------------------------------------
 * LUT / Gamma
 * ---------------------------------------------------------------------------------- */
int ak_isp_set_raw_lut_attr(const void *param);
int ak_isp_get_raw_lut_attr(void *param);
int ak_isp_set_rgb_gamma_attr(const void *param);
int ak_isp_get_rgb_gamma_attr(void *param);
int ak_isp_set_y_gamma_attr(const void *param);
int ak_isp_get_y_gamma_attr(void *param);

/* ----------------------------------------------------------------------------------
 * Sharpness / NR
 * ---------------------------------------------------------------------------------- */
int ak_isp_set_sharp_attr(const void *param);
int ak_isp_get_sharp_attr(void *param);
int ak_isp_set_sharp_ex_attr(const void *param);
int ak_isp_get_sharp_ex_attr(void *param);
int ak_isp_set_fcs_attr(const void *param);
int ak_isp_get_fcs_attr(void *param);
int ak_isp_set_wdr_attr(const void *param);
int ak_isp_get_wdr_attr(void *param);
int ak_isp_set_nr1_attr(const void *param);
int ak_isp_get_nr1_attr(void *param);
int ak_isp_set_nr2_attr(const void *param);
int ak_isp_get_nr2_attr(void *param);
int ak_isp_set_3d_nr_attr(const void *param);
int ak_isp_get_3d_nr_attr(void *param);
int ak_isp_set_3d_nr_ref_attr(const void *param);
int ak_isp_get_3d_nr_ref_attr(void *param);
int ak_isp_get_3d_nr_stat_info(void *param);

/* ----------------------------------------------------------------------------------
 * Pesos / ROI / Máscaras
 * ---------------------------------------------------------------------------------- */
int ak_isp_set_weight_attr(const void *param);
int ak_isp_get_weight_attr(void *param);
int ak_isp_set_main_chan_mask_area(const void *param);
int ak_isp_get_main_chan_mask_area(void *param);
int ak_isp_set_sub_chan_mask_area(const void *param);
int ak_isp_get_sub_chan_mask_area(void *param);
int ak_isp_set_mask_color(const void *param);
int ak_isp_get_mask_color(void *param);

/* ----------------------------------------------------------------------------------
 * Miscelánea
 * ---------------------------------------------------------------------------------- */
int ak_isp_set_misc_attr(const void *param);
int ak_isp_get_misc_attr(void *param);
int ak_isp_set_isp_capturing(const void *param);

/* ----------------------------------------------------------------------------------
 * Compatibilidad con nombres AK_ISP*
 * ---------------------------------------------------------------------------------- */
#define AK_ISP_sdk_init               ak_isp_sdk_init
#define AK_ISP_sdk_exit               ak_isp_sdk_exit
#define Ak_ISP_Sensor_Load_Conf       ak_isp_sensor_load_conf
#define Ak_ISP_Sensor_Set_Reg         ak_isp_sensor_set_reg
#define Ak_ISP_Sensor_Get_Reg         ak_isp_sensor_get_reg
#define Ak_ISP_Sensor_Get_Id          ak_isp_sensor_get_id
#define Ak_ISP_Set_Flip_Mirror        ak_isp_set_flip_mirror
#define Ak_ISP_Set_Sensor_Fps         ak_isp_set_sensor_fps
#define Ak_ISP_Get_Sensor_Fps         ak_isp_get_sensor_fps
#define Ak_ISP_Set_User_Params        ak_isp_set_user_params
#define Ak_ISP_Get_Work_Scene         ak_isp_get_work_scene
#define AK_ISP_set_raw_hist_attr      ak_isp_set_raw_hist_attr
#define AK_ISP_get_raw_hist_attr      ak_isp_get_raw_hist_attr
#define AK_ISP_get_raw_hist_stat_info ak_isp_get_raw_hist_stat_info
#define AK_ISP_set_rgb_hist_attr      ak_isp_set_rgb_hist_attr
#define AK_ISP_get_rgb_hist_attr      ak_isp_get_rgb_hist_attr
#define AK_ISP_get_rgb_hist_stat_info ak_isp_get_rgb_hist_stat_info
#define AK_ISP_set_yuv_hist_attr      ak_isp_set_yuv_hist_attr
#define AK_ISP_get_yuv_hist_attr      ak_isp_get_yuv_hist_attr
#define AK_ISP_get_yuv_hist_stat_info ak_isp_get_yuv_hist_stat_info
#define AK_ISP_set_exp_type           ak_isp_set_exp_type
#define AK_ISP_get_exp_type           ak_isp_get_exp_type
#define AK_ISP_set_ae_attr            ak_isp_set_ae_attr
#define AK_ISP_get_ae_attr            ak_isp_get_ae_attr
#define AK_ISP_get_ae_run_info        ak_isp_get_ae_run_info
#define AK_ISP_set_wb_type            ak_isp_set_wb_type
#define AK_ISP_get_wb_type            ak_isp_get_wb_type
#define AK_ISP_set_awb_attr           ak_isp_set_awb_attr
#define AK_ISP_get_awb_attr           ak_isp_get_awb_attr
#define AK_ISP_set_awb_ex_attr        ak_isp_set_awb_ex_attr
#define AK_ISP_get_awb_ex_attr        ak_isp_get_awb_ex_attr
#define Ak_ISP_get_awb_stat_info      ak_isp_get_awb_stat_info
#define AK_ISP_set_mwb_attr           ak_isp_set_mwb_attr
#define AK_ISP_get_mwb_attr           ak_isp_get_mwb_attr
#define AK_ISP_set_af_attr            ak_isp_set_af_attr
#define AK_ISP_get_af_attr            ak_isp_get_af_attr
#define AK_ISP_get_af_stat_info       ak_isp_get_af_stat_info
#define AK_ISP_set_blc_attr           ak_isp_set_blc_attr
#define AK_ISP_get_blc_attr           ak_isp_get_blc_attr
#define AK_ISP_set_lsc_attr           ak_isp_set_lsc_attr
#define AK_ISP_get_lsc_attr           ak_isp_get_lsc_attr
#define AK_ISP_set_dpc_attr           ak_isp_set_dpc_attr
#define AK_ISP_get_dpc_attr           ak_isp_get_dpc_attr
#define AK_ISP_set_sdpc_attr          ak_isp_set_sdpc_attr
#define AK_ISP_get_sdpc_attr          ak_isp_get_sdpc_attr
#define AK_ISP_set_gb_attr            ak_isp_set_gb_attr
#define AK_ISP_get_gb_attr            ak_isp_get_gb_attr
#define AK_ISP_set_demo_attr          ak_isp_set_demo_attr
#define AK_ISP_get_demo_attr          ak_isp_get_demo_attr
#define AK_ISP_set_ccm_attr           ak_isp_set_ccm_attr
#define AK_ISP_get_ccm_attr           ak_isp_get_ccm_attr
#define AK_ISP_set_rgb2yuv_attr       ak_isp_set_rgb2yuv_attr
#define AK_ISP_get_rgb2yuv_attr       ak_isp_get_rgb2yuv_attr
#define AK_ISP_set_contrast_attr      ak_isp_set_contrast_attr
#define AK_ISP_get_contrast_attr      ak_isp_get_contrast_attr
#define AK_ISP_set_saturation_attr    ak_isp_set_saturation_attr
#define AK_ISP_get_saturation_attr    ak_isp_get_saturation_attr
#define AK_ISP_set_hue_attr           ak_isp_set_hue_attr
#define AK_ISP_get_hue_attr           ak_isp_get_hue_attr
#define AK_ISP_set_effect_attr        ak_isp_set_effect_attr
#define AK_ISP_get_effect_attr        ak_isp_get_effect_attr
#define AK_ISP_set_raw_lut_attr       ak_isp_set_raw_lut_attr
#define AK_ISP_get_raw_lut_attr       ak_isp_get_raw_lut_attr
#define AK_ISP_set_rgb_gamma_attr     ak_isp_set_rgb_gamma_attr
#define AK_ISP_get_rgb_gamma_attr     ak_isp_get_rgb_gamma_attr
#define AK_ISP_set_Y_gamma_attr       ak_isp_set_y_gamma_attr
#define AK_ISP_get_Y_gamma_attr       ak_isp_get_y_gamma_attr
#define AK_ISP_set_sharp_attr         ak_isp_set_sharp_attr
#define AK_ISP_get_sharp_attr         ak_isp_get_sharp_attr
#define AK_ISP_set_sharp_ex_attr      ak_isp_set_sharp_ex_attr
#define AK_ISP_get_sharp_ex_attr      ak_isp_get_sharp_ex_attr
#define AK_ISP_set_fcs_attr           ak_isp_set_fcs_attr
#define AK_ISP_get_fcs_attr           ak_isp_get_fcs_attr
#define AK_ISP_set_wdr_attr           ak_isp_set_wdr_attr
#define AK_ISP_get_wdr_attr           ak_isp_get_wdr_attr
#define AK_ISP_set_nr1_attr           ak_isp_set_nr1_attr
#define AK_ISP_get_nr1_attr           ak_isp_get_nr1_attr
#define AK_ISP_set_nr2_attr           ak_isp_set_nr2_attr
#define AK_ISP_get_nr2_attr           ak_isp_get_nr2_attr
#define AK_ISP_set_3d_nr_attr         ak_isp_set_3d_nr_attr
#define AK_ISP_get_3d_nr_attr         ak_isp_get_3d_nr_attr
#define AK_ISP_set_3d_nr_ref_attr     ak_isp_set_3d_nr_ref_attr
#define AK_ISP_get_3d_nr_ref_attr     ak_isp_get_3d_nr_ref_attr
#define AK_ISP_get_3d_nr_stat_info    ak_isp_get_3d_nr_stat_info
#define AK_ISP_set_weight_attr        ak_isp_set_weight_attr
#define AK_ISP_get_weight_attr        ak_isp_get_weight_attr
#define AK_ISP_set_main_chan_mask_area ak_isp_set_main_chan_mask_area
#define AK_ISP_get_main_chan_mask_area ak_isp_get_main_chan_mask_area
#define AK_ISP_set_sub_chan_mask_area ak_isp_set_sub_chan_mask_area
#define AK_ISP_get_sub_chan_mask_area ak_isp_get_sub_chan_mask_area
#define AK_ISP_set_mask_color         ak_isp_set_mask_color
#define AK_ISP_get_mask_color         ak_isp_get_mask_color
#define AK_ISP_set_misc_attr          ak_isp_set_misc_attr
#define AK_ISP_get_misc_attr          ak_isp_get_misc_attr
#define AK_ISP_set_isp_capturing      ak_isp_set_isp_capturing

#ifdef __cplusplus
}
#endif

#endif /* AKISPSDK_H */

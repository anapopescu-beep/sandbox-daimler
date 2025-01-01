/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_Cbk.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Callback header file
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CBK_H
# define RTE_CBK_H

# include "Com.h"


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * COM Callbacks for Rx Indication
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbk_BeltHdOvr_FL_Stat_ST3_3489841d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BeltHdOvr_FR_Stat_ST3_0eefd507_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PN14_DDP_Sw_Stat_ST3_568ad7e6_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PS_Curve_FL_Rq_HU_ST3_6cd299ba_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PS_Curve_FR_Rq_HU_ST3_90527677_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_PT4_PTCoor9_Pr5_ST3_6r95o81sst3tk9w2lzz600cw3_5dfe4b97_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_VSS_TP_Auth_ST3_6j4id7sghlvlbroli4wjozjik_2ac87786_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_VSS_TP_RealTmOffset_ST3_1t7vc44gftc0wv35k5kgc2in9_d3385ce4_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_VSS_TP_SecTickCount_Lvl2_ST3_9eubq13iosat764o0lqh5xb6r_01efe31e_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_VSS_TP_SharedSecret_ST3_8pj4t8t4rm3tw3pk5hj7vonti_d9a21e4b_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_VSS_TP_VIN_ST3_bz1xsv84cxzl09j028gn39p69_f31ab3e3_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbk_VehSpd_Disp_ST3_4922a2fd_Rx(void);

/**********************************************************************************************************************
 * COM Callbacks for Rx Timeout Notification
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BeltHdOvr_FL_Stat_ST3_3489841d_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BeltHdOvr_FR_Stat_ST3_0eefd507_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_PS_Curve_FL_Rq_HU_ST3_6cd299ba_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_PS_Curve_FR_Rq_HU_ST3_90527677_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_PT4_PTCoor9_Pr5_ST3_6r95o81sst3tk9w2lzz600cw3_5dfe4b97_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_VSS_TP_SecTickCount_Lvl2_ST3_9eubq13iosat764o0lqh5xb6r_01efe31e_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_VSS_TP_VIN_ST3_bz1xsv84cxzl09j028gn39p69_f31ab3e3_Rx(void);
FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_VehSpd_Disp_ST3_4922a2fd_Rx(void);

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* RTE_CBK_H */

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
 *             File:  Rte_DIA_AC_DiagOnCAN.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <DIA_AC_DiagOnCAN>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_DIA_AC_DIAGONCAN_H
# define RTE_DIA_AC_DIAGONCAN_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_DIA_AC_DiagOnCAN_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

#  include "Com.h"


/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_DIA_psePresafeDisplay_b8TriggerPreSafeRequestStatus;
extern VAR(c02_Off_On, RTE_VAR_NOINIT) Rte_CIL_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3;
extern VAR(c02_Off_Stage1_Stage2, RTE_VAR_NOINIT) Rte_CIL_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3;
extern VAR(c02_Off_Stage1_Stage2, RTE_VAR_NOINIT) Rte_CIL_P_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3;
extern VAR(c06_RBTM_Lvl_Stat, RTE_VAR_NOINIT) Rte_CIL_RBTMFL_Actv_Lvl_ST35_RBTMFL_Actv_Lvl_ST35;
extern VAR(c04_RBTM_ActvClient, RTE_VAR_NOINIT) Rte_CIL_P_RBTMFL_SP_ActvClient_ST35_RBTMFL_SP_ActvClient_ST35;
extern VAR(c10_RBTM_Fct_Precond, RTE_VAR_NOINIT) Rte_CIL_P_RBTMFL_SP_FctPrecond_Stat_ST35_RBTMFL_SP_FctPrecond_Stat_ST35;
extern VAR(c06_RBTM_Lvl_Stat, RTE_VAR_NOINIT) Rte_CIL_RBTMFR_Actv_Lvl_ST35_RBTMFR_Actv_Lvl_ST35;
extern VAR(c04_RBTM_ActvClient, RTE_VAR_NOINIT) Rte_CIL_P_RBTMFR_SP_ActvClient_ST35_RBTMFR_SP_ActvClient_ST35;
extern VAR(c10_RBTM_Fct_Precond, RTE_VAR_NOINIT) Rte_CIL_P_RBTMFR_SP_FctPrecond_Stat_ST35_RBTMFR_SP_FctPrecond_Stat_ST35;
extern VAR(c02_Presf_Disp_Rq, RTE_VAR_NOINIT) Rte_CIL_IF_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3;
extern VAR(c02_Presf_Disp_Rq, RTE_VAR_NOINIT) Rte_CIL_P_RBTM_FR_Disp_Rq_ST3_RBTM_FR_Disp_Rq_ST3;
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_MMG_AvailabilityDataHandler_AvailabilityDataCategory;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_ERH_psrDTCConfirmed_b8DTCConfirmed;
extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedCycle_u8CycleNumber;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrExtTestPres_b8ExtTesterPresent;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_IF_BeltHdOvr_XX_Stat_ST3_BeltHdOvr_XX_Stat_ST3 (3U)
#  define Rte_InitValue_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3 (3U)
#  define Rte_InitValue_IF_DidA_ExtTest_Pres_ST3_DidA_ExtTest_Pres_ST3 (3U)
#  define Rte_InitValue_IF_PN14_DDP_Sw_Stat_ST3_PN14_DDP_Sw_Stat_ST3 (0U)
#  define Rte_InitValue_IF_PN14_ProdMd_Stat_ST3_PN14_ProdMd_Stat_ST3 (7U)
#  define Rte_InitValue_IF_PN14_SupBat_Volt_ST3_PN14_SupBat_Volt_ST3 (1023U)
#  define Rte_InitValue_IF_PN14_TransMd_Stat_ST3_PN14_TransMd_Stat_ST3 (3U)
#  define Rte_InitValue_IF_VehSpd_Disp_ST3_VehSpd_Disp_ST3 (0U)
#  define Rte_InitValue_R_AvailabilityDataHandler_AvailabilityDataCategory (0U)
#  define Rte_InitValue_R_BltSlckDec_Md_Rq_HU_ST3_BltSlckDec_Md_Rq_HU_ST3 (3U)
#  define Rte_InitValue_prrDTCConfirmed_b8DTCConfirmed (85U)
#  define Rte_InitValue_prrDTCConfirmed_b8ExtTesterPresent (85U)
#  define Rte_InitValue_prrExecutedCycle_u8CycleNumber (255U)
#  define Rte_InitValue_psePresafeDisplay_b8TriggerPreSafeRequestStatus (85U)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_Irv_DIA_u8DiagRequestedCycle;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IF_BeltHdOvr_XX_Stat_ST3_BeltHdOvr_XX_Stat_ST3(P2VAR(c02_BeltHdOvr_Stat, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3(P2VAR(REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3(P2VAR(REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3(P2VAR(REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3(P2VAR(REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3(P2VAR(REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(P2VAR(REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3(P2VAR(REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3(P2VAR(REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(uint8, RTE_CODE) Rte_Mode_DIA_AC_DiagOnCAN_EcuM_CurrentMode_currentMode(void);

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_IF_BeltHdOvr_XX_Stat_ST3_BeltHdOvr_XX_Stat_ST3 Rte_Read_DIA_AC_DiagOnCAN_IF_BeltHdOvr_XX_Stat_ST3_BeltHdOvr_XX_Stat_ST3
#  define Rte_Read_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3 Rte_Read_DIA_AC_DiagOnCAN_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3(data) (*(data) = Rte_CIL_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_IF_DidA_ExtTest_Pres_ST3_DidA_ExtTest_Pres_ST3 Rte_Read_DIA_AC_DiagOnCAN_IF_DidA_ExtTest_Pres_ST3_DidA_ExtTest_Pres_ST3
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_DidA_ExtTest_Pres_ST3_DidA_ExtTest_Pres_ST3(data) (Com_ReceiveSignal(ComConf_ComSignal_DidA_ExtTest_Pres_ST3_7e50ca1d_Rx, (data)))
#  define Rte_Read_IF_PN14_DDP_Sw_Stat_ST3_PN14_DDP_Sw_Stat_ST3 Rte_Read_DIA_AC_DiagOnCAN_IF_PN14_DDP_Sw_Stat_ST3_PN14_DDP_Sw_Stat_ST3
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_PN14_DDP_Sw_Stat_ST3_PN14_DDP_Sw_Stat_ST3(data) (Com_ReceiveSignal(ComConf_ComSignal_PN14_DDP_Sw_Stat_ST3_568ad7e6_Rx, (data)))
#  define Rte_Read_IF_PN14_ProdMd_Stat_ST3_PN14_ProdMd_Stat_ST3 Rte_Read_DIA_AC_DiagOnCAN_IF_PN14_ProdMd_Stat_ST3_PN14_ProdMd_Stat_ST3
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_PN14_ProdMd_Stat_ST3_PN14_ProdMd_Stat_ST3(data) (Com_ReceiveSignal(ComConf_ComSignal_PN14_ProdMd_Stat_ST3_be2b5dfe_Rx, (data)))
#  define Rte_Read_IF_PN14_SupBat_Volt_ST3_PN14_SupBat_Volt_ST3 Rte_Read_DIA_AC_DiagOnCAN_IF_PN14_SupBat_Volt_ST3_PN14_SupBat_Volt_ST3
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_PN14_SupBat_Volt_ST3_PN14_SupBat_Volt_ST3(data) (Com_ReceiveSignal(ComConf_ComSignal_PN14_SupBat_Volt_ST3_946fd9c6_Rx, (data)))
#  define Rte_Read_IF_PN14_TransMd_Stat_ST3_PN14_TransMd_Stat_ST3 Rte_Read_DIA_AC_DiagOnCAN_IF_PN14_TransMd_Stat_ST3_PN14_TransMd_Stat_ST3
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_PN14_TransMd_Stat_ST3_PN14_TransMd_Stat_ST3(data) (Com_ReceiveSignal(ComConf_ComSignal_PN14_TransMd_Stat_ST3_2208da29_Rx, (data)))
#  define Rte_Read_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3 Rte_Read_DIA_AC_DiagOnCAN_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3(data) (*(data) = Rte_CIL_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_IF_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3 Rte_Read_DIA_AC_DiagOnCAN_IF_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3(data) (*(data) = Rte_CIL_P_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_IF_RBTMFL_Actv_Lvl_ST35_RBTMFL_Actv_Lvl_ST35 Rte_Read_DIA_AC_DiagOnCAN_IF_RBTMFL_Actv_Lvl_ST35_RBTMFL_Actv_Lvl_ST35
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_RBTMFL_Actv_Lvl_ST35_RBTMFL_Actv_Lvl_ST35(data) (*(data) = Rte_CIL_RBTMFL_Actv_Lvl_ST35_RBTMFL_Actv_Lvl_ST35, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_IF_RBTMFL_SP_ActvClient_ST35_RBTMFL_SP_ActvClient_ST35 Rte_Read_DIA_AC_DiagOnCAN_IF_RBTMFL_SP_ActvClient_ST35_RBTMFL_SP_ActvClient_ST35
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_RBTMFL_SP_ActvClient_ST35_RBTMFL_SP_ActvClient_ST35(data) (*(data) = Rte_CIL_P_RBTMFL_SP_ActvClient_ST35_RBTMFL_SP_ActvClient_ST35, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_IF_RBTMFL_SP_FctPrecond_Stat_ST35_RBTMFL_SP_FctPrecond_Stat_ST35 Rte_Read_DIA_AC_DiagOnCAN_IF_RBTMFL_SP_FctPrecond_Stat_ST35_RBTMFL_SP_FctPrecond_Stat_ST35
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_RBTMFL_SP_FctPrecond_Stat_ST35_RBTMFL_SP_FctPrecond_Stat_ST35(data) (*(data) = Rte_CIL_P_RBTMFL_SP_FctPrecond_Stat_ST35_RBTMFL_SP_FctPrecond_Stat_ST35, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_IF_RBTMFR_Actv_Lvl_ST35_RBTMFR_Actv_Lvl_ST35 Rte_Read_DIA_AC_DiagOnCAN_IF_RBTMFR_Actv_Lvl_ST35_RBTMFR_Actv_Lvl_ST35
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_RBTMFR_Actv_Lvl_ST35_RBTMFR_Actv_Lvl_ST35(data) (*(data) = Rte_CIL_RBTMFR_Actv_Lvl_ST35_RBTMFR_Actv_Lvl_ST35, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_IF_RBTMFR_SP_ActvClient_ST35_RBTMFR_SP_ActvClient_ST35 Rte_Read_DIA_AC_DiagOnCAN_IF_RBTMFR_SP_ActvClient_ST35_RBTMFR_SP_ActvClient_ST35
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_RBTMFR_SP_ActvClient_ST35_RBTMFR_SP_ActvClient_ST35(data) (*(data) = Rte_CIL_P_RBTMFR_SP_ActvClient_ST35_RBTMFR_SP_ActvClient_ST35, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_IF_RBTMFR_SP_FctPrecond_Stat_ST35_RBTMFR_SP_FctPrecond_Stat_ST35 Rte_Read_DIA_AC_DiagOnCAN_IF_RBTMFR_SP_FctPrecond_Stat_ST35_RBTMFR_SP_FctPrecond_Stat_ST35
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_RBTMFR_SP_FctPrecond_Stat_ST35_RBTMFR_SP_FctPrecond_Stat_ST35(data) (*(data) = Rte_CIL_P_RBTMFR_SP_FctPrecond_Stat_ST35_RBTMFR_SP_FctPrecond_Stat_ST35, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_IF_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3 Rte_Read_DIA_AC_DiagOnCAN_IF_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3(data) (*(data) = Rte_CIL_IF_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_IF_RBTM_FR_Disp_Rq_ST3_RBTM_FR_Disp_Rq_ST3 Rte_Read_DIA_AC_DiagOnCAN_IF_RBTM_FR_Disp_Rq_ST3_RBTM_FR_Disp_Rq_ST3
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_RBTM_FR_Disp_Rq_ST3_RBTM_FR_Disp_Rq_ST3(data) (*(data) = Rte_CIL_P_RBTM_FR_Disp_Rq_ST3_RBTM_FR_Disp_Rq_ST3, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_IF_VehSpd_Disp_ST3_VehSpd_Disp_ST3 Rte_Read_DIA_AC_DiagOnCAN_IF_VehSpd_Disp_ST3_VehSpd_Disp_ST3
#  define Rte_Read_DIA_AC_DiagOnCAN_IF_VehSpd_Disp_ST3_VehSpd_Disp_ST3(data) (Com_ReceiveSignal(ComConf_ComSignal_VehSpd_Disp_ST3_4922a2fd_Rx, (data)))
#  define Rte_Read_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3 Rte_Read_DIA_AC_DiagOnCAN_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3
#  define Rte_Read_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3 Rte_Read_DIA_AC_DiagOnCAN_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3
#  define Rte_Read_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3 Rte_Read_DIA_AC_DiagOnCAN_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3
#  define Rte_Read_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3 Rte_Read_DIA_AC_DiagOnCAN_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3
#  define Rte_Read_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3 Rte_Read_DIA_AC_DiagOnCAN_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3
#  define Rte_Read_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3 Rte_Read_DIA_AC_DiagOnCAN_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3
#  define Rte_Read_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3 Rte_Read_DIA_AC_DiagOnCAN_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3
#  define Rte_Read_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3 Rte_Read_DIA_AC_DiagOnCAN_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3
#  define Rte_Read_R_AvailabilityDataHandler_AvailabilityDataCategory Rte_Read_DIA_AC_DiagOnCAN_R_AvailabilityDataHandler_AvailabilityDataCategory
#  define Rte_Read_DIA_AC_DiagOnCAN_R_AvailabilityDataHandler_AvailabilityDataCategory(data) (*(data) = Rte_MMG_AvailabilityDataHandler_AvailabilityDataCategory, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_R_BltSlckDec_Md_Rq_HU_ST3_BltSlckDec_Md_Rq_HU_ST3 Rte_Read_DIA_AC_DiagOnCAN_R_BltSlckDec_Md_Rq_HU_ST3_BltSlckDec_Md_Rq_HU_ST3
#  define Rte_Read_DIA_AC_DiagOnCAN_R_BltSlckDec_Md_Rq_HU_ST3_BltSlckDec_Md_Rq_HU_ST3(data) (Com_ReceiveSignal(ComConf_ComSignal_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx, (data)))
#  define Rte_Read_prrDTCConfirmed_b8DTCConfirmed Rte_Read_DIA_AC_DiagOnCAN_prrDTCConfirmed_b8DTCConfirmed
#  define Rte_Read_DIA_AC_DiagOnCAN_prrDTCConfirmed_b8DTCConfirmed(data) (*(data) = Rte_ERH_psrDTCConfirmed_b8DTCConfirmed, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrExecutedCycle_u8CycleNumber Rte_Read_DIA_AC_DiagOnCAN_prrExecutedCycle_u8CycleNumber
#  define Rte_Read_DIA_AC_DiagOnCAN_prrExecutedCycle_u8CycleNumber(data) (*(data) = Rte_BFE_psrExecutedCycle_u8CycleNumber, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrExtTestPres_b8ExtTesterPresent Rte_Read_DIA_AC_DiagOnCAN_prrExtTestPres_b8ExtTesterPresent
#  define Rte_Read_DIA_AC_DiagOnCAN_prrExtTestPres_b8ExtTesterPresent(data) (*(data) = Rte_CIL_psrExtTestPres_b8ExtTesterPresent, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_psePresafeDisplay_b8TriggerPreSafeRequestStatus Rte_Write_DIA_AC_DiagOnCAN_psePresafeDisplay_b8TriggerPreSafeRequestStatus
#  define Rte_Write_DIA_AC_DiagOnCAN_psePresafeDisplay_b8TriggerPreSafeRequestStatus(data) (Rte_DIA_psePresafeDisplay_b8TriggerPreSafeRequestStatus = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Mode_<p>_<m>
 *********************************************************************************************************************/
#  define Rte_Mode_EcuM_CurrentMode_currentMode Rte_Mode_DIA_AC_DiagOnCAN_EcuM_CurrentMode_currentMode


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE) EOL_Get_Obsolescence_Data(P2CONST(Impl_Obsolescense_Data, AUTOMATIC, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_DATA) pObsData); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_ERH_AC_ERRORHANDLER_APPL_CODE) ERH_runGetAecGroupsStatus(P2VAR(u32AecGroupsType, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu32AecGroupsStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ERH_AC_ERRORHANDLER_APPL_CODE) ERH_runGetAecStatus(u8AecIdentifierType u8AecIdentifier, P2VAR(u8AecStatusType, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu8AecStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ERH_AC_ERRORHANDLER_APPL_CODE) ERH_runGetNumberOfImplementedAec(P2VAR(UInt8, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu8NbOfAec); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_EraseNvBlock(NvM_BlockIdType parg0); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_ReadBlock(NvM_BlockIdType parg0, dtRef_VOID DstPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_GetErrorStatus(NvM_BlockIdType parg0, P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_NVM_APPL_VAR) ErrorStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_WriteBlock(NvM_BlockIdType parg0, dtRef_const_VOID SrcPtr); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_NVM_APPL_CODE) NvM_SetRamBlockStatus(NvM_BlockIdType parg0, boolean RamBlockStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_NVM_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_runReadMotorCurrentInA(P2VAR(s8MotorCurrentInAType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) ps8MotorCurrentInA); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_runReadMotorCurrentInmA(P2VAR(s32MotorCurrentInmAType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) ps32MotorCurrentInmA); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetFilteredTemperature_deg(P2VAR(s16InternalTemperature_deg_Type, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) ps16InternalTemperature_deg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetBatteryVoltage(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetMotorVp(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE) RCM_runGetResetCause(P2VAR(u32ResetCauseType, AUTOMATIC, RTE_RCM_AC_RESETCAUSEMANAGEMENT_APPL_VAR) pu32ResetCause); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_RCM_AC_RESETCAUSEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_If_Obsolescence_Data_Get_Data(arg1) (EOL_Get_Obsolescence_Data(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_AEC_STATUS_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)81))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_AEC_STATUS_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)81, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_AEE_TRACEABILITY_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)38, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_AEE_TRACEABILITY_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)38, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_BELT_ASSEMBLY_MANUF_DATE_AND_SN_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)35, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_CYCLE_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)43, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_CYCLE_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)43, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_ECU_LOCATION_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)34, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_ECU_LOCATION_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)34, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_HB_CALIBRATION_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)36, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_HB_CALIBRATION_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)36, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_HB_CALIBRATION_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)36, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_HW_VERSION_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)37, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_HW_VERSION_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)37, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_HW_VERSION_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)37, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)41, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)41, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_MEASUREMENT_FRAME_12_CONFIG_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)41, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)42, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)42, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_MEASUREMENT_FRAME_CONFIG_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)42, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_PCBA_PPN_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)100, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_PCBA_PPN_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)100, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_PCBA_PPN_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)100, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)71))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)71, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)71, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)71, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_PRE_SAFE_RECORDER_1_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)71, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_EraseBlock() (NvM_EraseNvBlock((NvM_BlockIdType)74))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)74, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_ReadBlock(arg1) (NvM_ReadBlock((NvM_BlockIdType)74, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)74, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_PRE_SAFE_RECORDER_2_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)74, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_STEP_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)47, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_STEP_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)47, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_VELOCITY_PID_PARAM_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)80, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_VELOCITY_PID_PARAM_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)80, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_ID_VELOCITY_PID_PARAM_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)80, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_TEMP_SENSOR_TABLE_GetErrorStatus(arg1) (NvM_GetErrorStatus((NvM_BlockIdType)76, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_TEMP_SENSOR_TABLE_SetRamBlockStatus(arg1) (NvM_SetRamBlockStatus((NvM_BlockIdType)76, arg1))
#  define Rte_Call_NvMService_NVP_BLOCK_TEMP_SENSOR_TABLE_WriteBlock(arg1) (NvM_WriteBlock((NvM_BlockIdType)76, arg1))
#  define Rte_Call_icsResetCause_GetResetCause(arg1) (RCM_runGetResetCause(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAecStatus_GetAecGroupsStatus(arg1) (ERH_runGetAecGroupsStatus(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAecStatus_GetAecStatus(arg1, arg2) (ERH_runGetAecStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAecStatus_GetNumberOfImplementedAec(arg1) (ERH_runGetNumberOfImplementedAec(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclECUT_T_GetFiltered_deg(arg1) (PMP_runGetFilteredTemperature_deg(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_Get(arg1) (PMP_runGetBatteryVoltage(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_I_Get_A(arg1) (PAL_runReadMotorCurrentInA(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_I_Get_mA(arg1) (PAL_runReadMotorCurrentInmA(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vp_Get(arg1) (PMP_runGetMotorVp(arg1), ((Std_ReturnType)RTE_E_OK))

/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_DIA_cyclicProcessingTask_u8DiagRequestedCycle(data) \
  (Rte_Irv_DIA_u8DiagRequestedCycle = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_DIA_runClearDiagRequestCycle_u8DiagRequestedCycle(data) \
  (Rte_Irv_DIA_u8DiagRequestedCycle = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_DIA_runGetDiagRequestCycle_u8DiagRequestedCycle() \
  Rte_Irv_DIA_u8DiagRequestedCycle
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_DIA_runRid0329_TriggerBSRRequestResults_u8DiagRequestedCycle() \
  Rte_Irv_DIA_u8DiagRequestedCycle
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_DIA_runRid0329_TriggerBSRStart_u8DiagRequestedCycle(data) \
  (Rte_Irv_DIA_u8DiagRequestedCycle = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_DIA_runRid0330_TriggerTensioningCycleRequestResults_u8DiagRequestedCycle() \
  Rte_Irv_DIA_u8DiagRequestedCycle
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_DIA_runRid0330_TriggerTensioningCycleStart_u8DiagRequestedCycle(data) \
  (Rte_Irv_DIA_u8DiagRequestedCycle = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_DIA_runRidF703_CycleExecutionRequestResults_u8DiagRequestedCycle() \
  Rte_Irv_DIA_u8DiagRequestedCycle
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_DIA_runRidF703_CycleExecutionStart_u8DiagRequestedCycle() \
  Rte_Irv_DIA_u8DiagRequestedCycle
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_DIA_runRidF703_CycleExecutionStart_u8DiagRequestedCycle(data) \
  (Rte_Irv_DIA_u8DiagRequestedCycle = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_DIA_runRidF703_CycleExecutionStop_u8DiagRequestedCycle() \
  Rte_Irv_DIA_u8DiagRequestedCycle
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_DIA_runRidF703_CycleExecutionStop_u8DiagRequestedCycle(data) \
  (Rte_Irv_DIA_u8DiagRequestedCycle = (data))
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define DIA_AC_DiagOnCAN_START_SEC_CODE
# include "DIA_AC_DiagOnCAN_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_DIA_cyclicProcessingTask DIA_cyclicProcessingTask
#  define RTE_RUNNABLE_DIA_runClearDiagRequestCycle DIA_runClearDiagRequestCycle
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_BSR_Current_Value_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_BSR_Current_Value_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_BSR_Current_Value_Read DIA_runDid00140_Obsolescence_Data_BSR_Current_Value_Read
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Green_To_Yellow_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Green_To_Yellow_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Green_To_Yellow_Read DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Green_To_Yellow_Read
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Yellow_To_Red_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Yellow_To_Red_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Yellow_To_Red_Read DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Yellow_To_Red_Read
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Current_Value_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Current_Value_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Current_Value_Read DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Current_Value_Read
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Green_To_Yellow_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Green_To_Yellow_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Green_To_Yellow_Read DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Green_To_Yellow_Read
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Yellow_To_Red_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Yellow_To_Red_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Yellow_To_Red_Read DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Yellow_To_Red_Read
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Current_Value_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Current_Value_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Current_Value_Read DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Current_Value_Read
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Green_To_Yellow_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Green_To_Yellow_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Green_To_Yellow_Read DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Green_To_Yellow_Read
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Yellow_To_Red_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Yellow_To_Red_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Yellow_To_Red_Read DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Yellow_To_Red_Read
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_Read DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_Read
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Green_To_Yellow_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Green_To_Yellow_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Green_To_Yellow_Read DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Green_To_Yellow_Read
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Yellow_To_Red_ConditionCheckRead DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Yellow_To_Red_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Yellow_To_Red_Read DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Yellow_To_Red_Read
#  define RTE_RUNNABLE_DIA_runDid0142_AvailabilityDataConditionsCheckRead DIA_runDid0142_AvailabilityDataConditionsCheckRead
#  define RTE_RUNNABLE_DIA_runDid0142_AvailabilityDataRead DIA_runDid0142_AvailabilityDataRead
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_1_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_1_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_1_ReadData DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_1_ReadData
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_2_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_2_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_2_ReadData DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_2_ReadData
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_3_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_3_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_3_ReadData DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_3_ReadData
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_4_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_4_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_4_ReadData DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_4_ReadData
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_5_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_5_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_5_ReadData DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_5_ReadData
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_6_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_6_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_6_ReadData DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_6_ReadData
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_7_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_7_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_7_ReadData DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_7_ReadData
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_8_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_8_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_8_ReadData DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_8_ReadData
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Supply_battery_voltage_ConditionCheckRead DIA_runDid0200_CAN_input_Read_Supply_battery_voltage_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0200_CAN_input_Read_Supply_battery_voltage_ReadData DIA_runDid0200_CAN_input_Read_Supply_battery_voltage_ReadData
#  define RTE_RUNNABLE_DIA_runDid0210_CAN_output_Read_CANoutput1_ConditionCheckRead DIA_runDid0210_CAN_output_Read_CANoutput1_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0210_CAN_output_Read_CANoutput1_ReadData DIA_runDid0210_CAN_output_Read_CANoutput1_ReadData
#  define RTE_RUNNABLE_DIA_runDid0210_CAN_output_Read_PS_Curve_XX_Stat_ST3_ConditionCheckRead DIA_runDid0210_CAN_output_Read_PS_Curve_XX_Stat_ST3_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0210_CAN_output_Read_PS_Curve_XX_Stat_ST3_ReadData DIA_runDid0210_CAN_output_Read_PS_Curve_XX_Stat_ST3_ReadData
#  define RTE_RUNNABLE_DIA_runDid0210_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ConditionCheckRead DIA_runDid0210_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0210_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ReadData DIA_runDid0210_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ReadData
#  define RTE_RUNNABLE_DIA_runDid0210_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ConditionCheckRead DIA_runDid0210_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0210_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ReadData DIA_runDid0210_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ReadData
#  define RTE_RUNNABLE_DIA_runDid0210_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ConditionCheckRead DIA_runDid0210_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0210_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ReadData DIA_runDid0210_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ReadData
#  define RTE_RUNNABLE_DIA_runDid0220_HW_input_Read_Voltage_KL30t_ConditionCheckRead DIA_runDid0220_HW_input_Read_Voltage_KL30t_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0220_HW_input_Read_Voltage_KL30t_ReadData DIA_runDid0220_HW_input_Read_Voltage_KL30t_ReadData
#  define RTE_RUNNABLE_DIA_runDid0220_HW_input_Read_Voltage_Motor_ConditionCheckRead DIA_runDid0220_HW_input_Read_Voltage_Motor_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0220_HW_input_Read_Voltage_Motor_ReadData DIA_runDid0220_HW_input_Read_Voltage_Motor_ReadData
#  define RTE_RUNNABLE_DIA_runDid0240_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ConditionCheckRead DIA_runDid0240_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0240_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ReadData DIA_runDid0240_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ReadData
#  define RTE_RUNNABLE_DIA_runDid0240_Internal_ECU_information_Read_ECU_Temperature_ConditionCheckRead DIA_runDid0240_Internal_ECU_information_Read_ECU_Temperature_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0240_Internal_ECU_information_Read_ECU_Temperature_ReadData DIA_runDid0240_Internal_ECU_information_Read_ECU_Temperature_ReadData
#  define RTE_RUNNABLE_DIA_runDid0240_Internal_ECU_information_Read_MOTOR_Current_ConditionCheckRead DIA_runDid0240_Internal_ECU_information_Read_MOTOR_Current_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0240_Internal_ECU_information_Read_MOTOR_Current_ReadData DIA_runDid0240_Internal_ECU_information_Read_MOTOR_Current_ReadData
#  define RTE_RUNNABLE_DIA_runDid0241_PRE_SAFE_Recorder_1_ConditionCheckRead DIA_runDid0241_PRE_SAFE_Recorder_1_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0241_PRE_SAFE_Recorder_1_ReadData DIA_runDid0241_PRE_SAFE_Recorder_1_ReadData
#  define RTE_RUNNABLE_DIA_runDid0241_PRE_SAFE_Recorder_1_ReadDataLength DIA_runDid0241_PRE_SAFE_Recorder_1_ReadDataLength
#  define RTE_RUNNABLE_DIA_runDid0241_PRE_SAFE_Recorder_1_WriteData DIA_runDid0241_PRE_SAFE_Recorder_1_WriteData
#  define RTE_RUNNABLE_DIA_runDid0242_PRE_SAFE_Recorder_2_ConditionCheckRead DIA_runDid0242_PRE_SAFE_Recorder_2_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0242_PRE_SAFE_Recorder_2_ReadData DIA_runDid0242_PRE_SAFE_Recorder_2_ReadData
#  define RTE_RUNNABLE_DIA_runDid0242_PRE_SAFE_Recorder_2_ReadDataLength DIA_runDid0242_PRE_SAFE_Recorder_2_ReadDataLength
#  define RTE_RUNNABLE_DIA_runDid0242_PRE_SAFE_Recorder_2_WriteData DIA_runDid0242_PRE_SAFE_Recorder_2_WriteData
#  define RTE_RUNNABLE_DIA_runDid0340_UniqueSeatbeltSerialNumberConditionCheckRead DIA_runDid0340_UniqueSeatbeltSerialNumberConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDid0340_UniqueSeatbeltSerialNumberRead DIA_runDid0340_UniqueSeatbeltSerialNumberRead
#  define RTE_RUNNABLE_DIA_runDid0340_UniqueSeatbeltSerialNumberWrite DIA_runDid0340_UniqueSeatbeltSerialNumberWrite
#  define RTE_RUNNABLE_DIA_runDidF18C_EcuSerialNumberConditionCheckRead DIA_runDidF18C_EcuSerialNumberConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDidF18C_EcuSerialNumberRead DIA_runDidF18C_EcuSerialNumberRead
#  define RTE_RUNNABLE_DIA_runDidF18C_EcuSerialNumberReadDataLength DIA_runDidF18C_EcuSerialNumberReadDataLength
#  define RTE_RUNNABLE_DIA_runDidF18C_EcuSerialNumberWrite DIA_runDidF18C_EcuSerialNumberWrite
#  define RTE_RUNNABLE_DIA_runDidFD01_SWVersionConditionCheckRead DIA_runDidFD01_SWVersionConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDidFD01_SWVersionRead DIA_runDidFD01_SWVersionRead
#  define RTE_RUNNABLE_DIA_runDidFD03_ECUTraceabilityNumberConditionCheckRead DIA_runDidFD03_ECUTraceabilityNumberConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDidFD03_ECUTraceabilityNumberRead DIA_runDidFD03_ECUTraceabilityNumberRead
#  define RTE_RUNNABLE_DIA_runDidFD03_ECUTraceabilityNumberWrite DIA_runDidFD03_ECUTraceabilityNumberWrite
#  define RTE_RUNNABLE_DIA_runDidFD03_PCBAProgrammedPartNumberConditionCheckRead DIA_runDidFD03_PCBAProgrammedPartNumberConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDidFD03_PCBAProgrammedPartNumberRead DIA_runDidFD03_PCBAProgrammedPartNumberRead
#  define RTE_RUNNABLE_DIA_runDidFD03_PCBAProgrammedPartNumberWrite DIA_runDidFD03_PCBAProgrammedPartNumberWrite
#  define RTE_RUNNABLE_DIA_runDidFD08_ResetCauseManagementConditionCheckRead DIA_runDidFD08_ResetCauseManagementConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDidFD08_ResetCauseManagementRead DIA_runDidFD08_ResetCauseManagementRead
#  define RTE_RUNNABLE_DIA_runDidFD09_LastWarmReseConditionChecktRead_LastDetectedWarmResetCause DIA_runDidFD09_LastWarmReseConditionChecktRead_LastDetectedWarmResetCause
#  define RTE_RUNNABLE_DIA_runDidFD09_LastWarmResetConditionCheckRead_ResetCauseCounter DIA_runDidFD09_LastWarmResetConditionCheckRead_ResetCauseCounter
#  define RTE_RUNNABLE_DIA_runDidFD09_LastWarmResetRead_LastDetectedWarmResetCause DIA_runDidFD09_LastWarmResetRead_LastDetectedWarmResetCause
#  define RTE_RUNNABLE_DIA_runDidFD09_LastWarmResetRead_ResetCauseCounter DIA_runDidFD09_LastWarmResetRead_ResetCauseCounter
#  define RTE_RUNNABLE_DIA_runDidFD10_CycleConfigurationRead DIA_runDidFD10_CycleConfigurationRead
#  define RTE_RUNNABLE_DIA_runDidFD10_CycleConfigurationWrite DIA_runDidFD10_CycleConfigurationWrite
#  define RTE_RUNNABLE_DIA_runDidFD2A_StepsLibraryRead DIA_runDidFD2A_StepsLibraryRead
#  define RTE_RUNNABLE_DIA_runDidFD2A_StepsLibraryWrite DIA_runDidFD2A_StepsLibraryWrite
#  define RTE_RUNNABLE_DIA_runDidFD2F_EcuLocationRead DIA_runDidFD2F_EcuLocationRead
#  define RTE_RUNNABLE_DIA_runDidFD2F_EcuLocationWrite DIA_runDidFD2F_EcuLocationWrite
#  define RTE_RUNNABLE_DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ConditionCheckRead DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ReadData DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ReadData
#  define RTE_RUNNABLE_DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_WriteData DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_WriteData
#  define RTE_RUNNABLE_DIA_runDidFD31_HBCalibrationRead DIA_runDidFD31_HBCalibrationRead
#  define RTE_RUNNABLE_DIA_runDidFD31_HBCalibrationWrite DIA_runDidFD31_HBCalibrationWrite
#  define RTE_RUNNABLE_DIA_runDidFD31_HBCalibrationWriteConditionCheckRead DIA_runDidFD31_HBCalibrationWriteConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDidFD50_Hardware_Version_Information_Write_HW_patch_level DIA_runDidFD50_Hardware_Version_Information_Write_HW_patch_level
#  define RTE_RUNNABLE_DIA_runDidFD50_Hardware_Version_Information_Write_HW_week DIA_runDidFD50_Hardware_Version_Information_Write_HW_week
#  define RTE_RUNNABLE_DIA_runDidFD50_Hardware_Version_Information_Write_HW_year DIA_runDidFD50_Hardware_Version_Information_Write_HW_year
#  define RTE_RUNNABLE_DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ConditionCheckRead DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ReadData DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ReadData
#  define RTE_RUNNABLE_DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_WriteData DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_WriteData
#  define RTE_RUNNABLE_DIA_runDidFDFF_MeasurementFrameBlock12ConfigConditionCheckRead DIA_runDidFDFF_MeasurementFrameBlock12ConfigConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDidFDFF_MeasurementFrameBlock12ConfigRead DIA_runDidFDFF_MeasurementFrameBlock12ConfigRead
#  define RTE_RUNNABLE_DIA_runDidFDFF_MeasurementFrameBlock12ConfigWrite DIA_runDidFDFF_MeasurementFrameBlock12ConfigWrite
#  define RTE_RUNNABLE_DIA_runDidFE00_AECStatusConditionCheckRead DIA_runDidFE00_AECStatusConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDidFE00_AECStatusRead DIA_runDidFE00_AECStatusRead
#  define RTE_RUNNABLE_DIA_runDidFE00_AECStatusReadDataLength DIA_runDidFE00_AECStatusReadDataLength
#  define RTE_RUNNABLE_DIA_runDidFEFF_MeasuruementFrameConfigurationConditionCheckRead DIA_runDidFEFF_MeasuruementFrameConfigurationConditionCheckRead
#  define RTE_RUNNABLE_DIA_runDidFEFF_MeasuruementFrameConfigurationRead DIA_runDidFEFF_MeasuruementFrameConfigurationRead
#  define RTE_RUNNABLE_DIA_runDidFEFF_MeasuruementFrameConfigurationWrite DIA_runDidFEFF_MeasuruementFrameConfigurationWrite
#  define RTE_RUNNABLE_DIA_runGetDiagRequestCycle DIA_runGetDiagRequestCycle
#  define RTE_RUNNABLE_DIA_runRid0203_CheckProgrammingPreconditionsStart DIA_runRid0203_CheckProgrammingPreconditionsStart
#  define RTE_RUNNABLE_DIA_runRid0302_TriggerPresafeDisplayRequestRequestResults DIA_runRid0302_TriggerPresafeDisplayRequestRequestResults
#  define RTE_RUNNABLE_DIA_runRid0302_TriggerPresafeDisplayRequestStart DIA_runRid0302_TriggerPresafeDisplayRequestStart
#  define RTE_RUNNABLE_DIA_runRid0302_TriggerPresafeDisplayRequestStop DIA_runRid0302_TriggerPresafeDisplayRequestStop
#  define RTE_RUNNABLE_DIA_runRid0329_TriggerBSRRequestResults DIA_runRid0329_TriggerBSRRequestResults
#  define RTE_RUNNABLE_DIA_runRid0329_TriggerBSRStart DIA_runRid0329_TriggerBSRStart
#  define RTE_RUNNABLE_DIA_runRid0329_TriggerBSRStop DIA_runRid0329_TriggerBSRStop
#  define RTE_RUNNABLE_DIA_runRid0330_TriggerTensioningCycleRequestResults DIA_runRid0330_TriggerTensioningCycleRequestResults
#  define RTE_RUNNABLE_DIA_runRid0330_TriggerTensioningCycleStart DIA_runRid0330_TriggerTensioningCycleStart
#  define RTE_RUNNABLE_DIA_runRid0330_TriggerTensioningCycleStop DIA_runRid0330_TriggerTensioningCycleStop
#  define RTE_RUNNABLE_DIA_runRidF703_CycleExecutionRequestResults DIA_runRidF703_CycleExecutionRequestResults
#  define RTE_RUNNABLE_DIA_runRidF703_CycleExecutionStart DIA_runRidF703_CycleExecutionStart
#  define RTE_RUNNABLE_DIA_runRidF703_CycleExecutionStop DIA_runRidF703_CycleExecutionStop
# endif

FUNC(void, DIA_AC_DiagOnCAN_CODE) DIA_cyclicProcessingTask(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, DIA_AC_DiagOnCAN_CODE) DIA_runClearDiagRequestCycle(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Current_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Green_To_Yellow_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Yellow_To_Red_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_BSR_Threshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Current_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Green_To_Yellow_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Yellow_To_Red_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_Haptic_Warning_Treshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Current_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Green_To_Yellow_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Yellow_To_Red_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_CRASH_Treshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Green_To_Yellow_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Green_To_Yellow_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Yellow_To_Red_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid00140_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Treshold_Yellow_To_Red_Read(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0142_AvailabilityDataConditionsCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0142_AvailabilityDataRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0142_AvailabilityDataRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_2_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_3_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_4_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_4_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_4_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_5_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_5_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_5_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_6_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_6_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_6_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_7_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_7_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_7_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_8_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_8_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Neues_Bitfeld_8_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Supply_battery_voltage_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Supply_battery_voltage_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0200_CAN_input_Read_Supply_battery_voltage_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0210_CAN_output_Read_CANoutput1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0210_CAN_output_Read_CANoutput1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0210_CAN_output_Read_CANoutput1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0210_CAN_output_Read_PS_Curve_XX_Stat_ST3_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0210_CAN_output_Read_PS_Curve_XX_Stat_ST3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0210_CAN_output_Read_PS_Curve_XX_Stat_ST3_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0210_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0220_HW_input_Read_Voltage_KL30t_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0220_HW_input_Read_Voltage_KL30t_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0220_HW_input_Read_Voltage_KL30t_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0220_HW_input_Read_Voltage_Motor_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0220_HW_input_Read_Voltage_Motor_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0220_HW_input_Read_Voltage_Motor_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0240_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0240_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0240_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0240_Internal_ECU_information_Read_ECU_Temperature_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0240_Internal_ECU_information_Read_ECU_Temperature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0240_Internal_ECU_information_Read_ECU_Temperature_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0240_Internal_ECU_information_Read_MOTOR_Current_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0240_Internal_ECU_information_Read_MOTOR_Current_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0240_Internal_ECU_information_Read_MOTOR_Current_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data2ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0241_PRE_SAFE_Recorder_1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0241_PRE_SAFE_Recorder_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0241_PRE_SAFE_Recorder_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data22ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0241_PRE_SAFE_Recorder_1_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0241_PRE_SAFE_Recorder_1_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0241_PRE_SAFE_Recorder_1_WriteData(P2CONST(Dcm_Data22ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0242_PRE_SAFE_Recorder_2_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0242_PRE_SAFE_Recorder_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0242_PRE_SAFE_Recorder_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data22ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0242_PRE_SAFE_Recorder_2_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0242_PRE_SAFE_Recorder_2_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0242_PRE_SAFE_Recorder_2_WriteData(P2CONST(Dcm_Data22ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, uint16 DataLength, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0340_UniqueSeatbeltSerialNumberConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0340_UniqueSeatbeltSerialNumberRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0340_UniqueSeatbeltSerialNumberRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data28ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0340_UniqueSeatbeltSerialNumberWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDid0340_UniqueSeatbeltSerialNumberWrite(P2CONST(Dcm_Data28ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidF18C_EcuSerialNumberConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidF18C_EcuSerialNumberRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidF18C_EcuSerialNumberRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data33ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidF18C_EcuSerialNumberReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, DIA_AC_DiagOnCAN_CODE) DIA_runDidF18C_EcuSerialNumberWrite(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD01_SWVersionConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD01_SWVersionRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD01_SWVersionRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data12ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD03_ECUTraceabilityNumberConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD03_ECUTraceabilityNumberRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD03_ECUTraceabilityNumberRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data12ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD03_ECUTraceabilityNumberWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD03_ECUTraceabilityNumberWrite(P2CONST(Dcm_Data12ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD03_PCBAProgrammedPartNumberConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD03_PCBAProgrammedPartNumberRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD03_PCBAProgrammedPartNumberRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data10ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD03_PCBAProgrammedPartNumberWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD03_PCBAProgrammedPartNumberWrite(P2CONST(Dcm_Data10ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD08_ResetCauseManagementConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD08_ResetCauseManagementRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD08_ResetCauseManagementRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD09_LastWarmReseConditionChecktRead_LastDetectedWarmResetCause(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD09_LastWarmResetConditionCheckRead_ResetCauseCounter(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD09_LastWarmResetRead_LastDetectedWarmResetCause(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD09_LastWarmResetRead_LastDetectedWarmResetCause(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD09_LastWarmResetRead_ResetCauseCounter(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD09_LastWarmResetRead_ResetCauseCounter(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD10_CycleConfigurationRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD10_CycleConfigurationRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data420ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD10_CycleConfigurationWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD10_CycleConfigurationWrite(P2CONST(Dcm_Data420ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD2A_StepsLibraryRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD2A_StepsLibraryRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1160ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD2A_StepsLibraryWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD2A_StepsLibraryWrite(P2CONST(Dcm_Data1160ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD2F_EcuLocationRead(Dcm_OpStatusType_1 OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD2F_EcuLocationRead(Dcm_OpStatusType_1 OpStatus, P2VAR(Dcm_DataDID_FD2F_EcuLocationData_ArrayType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD2F_EcuLocationWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType_1 OpStatus, P2VAR(Dcm_NegativeResponseCodeType_1, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD2F_EcuLocationWrite(P2CONST(Dcm_DataDID_FD2F_EcuLocationData_ArrayType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType_1 OpStatus, P2VAR(Dcm_NegativeResponseCodeType_1, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD30_Temperature_Sensor_Calibration_Point_Read_Offset_Point_WriteData(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD31_HBCalibrationRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD31_HBCalibrationRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data40ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD31_HBCalibrationWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD31_HBCalibrationWrite(P2CONST(Dcm_Data40ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD31_HBCalibrationWriteConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD50_Hardware_Version_Information_Write_HW_patch_level(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD50_Hardware_Version_Information_Write_HW_patch_level(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD50_Hardware_Version_Information_Write_HW_week(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD50_Hardware_Version_Information_Write_HW_week(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD50_Hardware_Version_Information_Write_HW_year(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFD50_Hardware_Version_Information_Write_HW_year(P2CONST(Dcm_Data1ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_ReadData(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data30ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFDDF_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_WriteData(P2CONST(Dcm_Data30ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFDFF_MeasurementFrameBlock12ConfigConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFDFF_MeasurementFrameBlock12ConfigRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFDFF_MeasurementFrameBlock12ConfigRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data5ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFDFF_MeasurementFrameBlock12ConfigWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFDFF_MeasurementFrameBlock12ConfigWrite(P2CONST(Dcm_Data5ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFE00_AECStatusConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFE00_AECStatusRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFE00_AECStatusRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data240ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFE00_AECStatusReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFEFF_MeasuruementFrameConfigurationConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFEFF_MeasuruementFrameConfigurationRead(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFEFF_MeasuruementFrameConfigurationRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_Data4ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFEFF_MeasuruementFrameConfigurationWrite(P2CONST(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runDidFEFF_MeasuruementFrameConfigurationWrite(P2CONST(Dcm_Data4ByteType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(void, DIA_AC_DiagOnCAN_CODE) DIA_runGetDiagRequestCycle(P2VAR(u8CycleNumberType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) u8DiagRequestCycle); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# ifndef RTE_PTR2ARRAYTYPE_PASSING
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runRid0203_CheckProgrammingPreconditionsStart(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_Number_of_Unfulfilled_PreconditionsType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Number_of_Unfulfilled_Preconditions, P2VAR(uint8, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) List_of_Preconditions, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# else
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runRid0203_CheckProgrammingPreconditionsStart(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Check_Reprogramming_Preconditions_Start_Number_of_Unfulfilled_PreconditionsType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Number_of_Unfulfilled_Preconditions, P2VAR(Dcm_StartFlexibleOutArrayData_Routine_Check_Reprogramming_Preconditions_Start_List_of_PreconditionsType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) List_of_Preconditions, P2VAR(uint16, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
# endif
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runRid0302_TriggerPresafeDisplayRequestRequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_RequestDataOut_Routine_Trigger_Presafe_Display_Request_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runRid0302_TriggerPresafeDisplayRequestStart(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Trigger_Presafe_Display_Request_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runRid0302_TriggerPresafeDisplayRequestStop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StopDataOut_Routine_Trigger_Presafe_Display_Request_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runRid0329_TriggerBSRRequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Trigger_BSR_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_RequestDataOut_Routine_Trigger_BSR_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runRid0329_TriggerBSRStart(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Trigger_BSR_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Trigger_BSR_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runRid0329_TriggerBSRStop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StopDataOut_Routine_Trigger_BSR_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runRid0330_TriggerTensioningCycleRequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_RequestDataOut_Routine_Trigger_Tensioning_Cycle_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runRid0330_TriggerTensioningCycleStart(Dcm_StartDataIn_Routine_Trigger_Tensioning_Cycle_Start_Type_of_tensioning_cycleType Type_of_tensioning_cycle, Dcm_StartDataIn_Routine_Trigger_Tensioning_Cycle_Start_PreSafe_DurationType PreSafe_Duration, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_StartDataOut_Routine_Trigger_Tensioning_Cycle_Start_ResultType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runRid0330_TriggerTensioningCycleStop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StopDataOut_Routine_Trigger_Tensioning_Cycle_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runRidF703_CycleExecutionRequestResults(Dcm_OpStatusType OpStatus, P2VAR(Dcm_RequestDataOut_Routine_Cycle_Execution_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_RequestDataOut_Routine_Cycle_Execution_Start_Executed_CycleType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) Executed_Cycle, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runRidF703_CycleExecutionStart(Dcm_StartDataIn_Routine_Cycle_Execution_Start_CycleType Cycle, Dcm_OpStatusType OpStatus, P2VAR(Dcm_StartDataOut_Routine_Cycle_Execution_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, DIA_AC_DiagOnCAN_CODE) DIA_runRidF703_CycleExecutionStop(Dcm_OpStatusType OpStatus, P2VAR(Dcm_StopDataOut_Routine_Cycle_Execution_Start_routineInfoType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) ErrorCode); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define DIA_AC_DiagOnCAN_STOP_SEC_CODE
# include "DIA_AC_DiagOnCAN_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_DataServices_AEC_Status_Read_AEC_Status_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_AEC_Status_Read_AEC_Status_E_NOT_OK (1U)

#  define RTE_E_DataServices_Availability_Data_Read_Availability_Data_PRE_SAFE_haptic_warning_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Availability_Data_Read_Availability_Data_PRE_SAFE_haptic_warning_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_1_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_1_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_2_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_2_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_3_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_3_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_4_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_4_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_5_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_5_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_6_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_6_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_7_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_7_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_8_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Neues_Bitfeld_8_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_input_Read_Supply_battery_voltage_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_input_Read_Supply_battery_voltage_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_output_Read_CANoutput1_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_output_Read_CANoutput1_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_output_Read_PS_Curve_XX_Stat_ST3_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_output_Read_PS_Curve_XX_Stat_ST3_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_output_Read_RBTMxx_Actv_Lvl_ST35_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_output_Read_RBTMxx_SP_ActvClient_ST35_E_NOT_OK (1U)

#  define RTE_E_DataServices_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_CAN_output_Read_RBTMxx_SP_FctPrecond_Stat_ST35_E_NOT_OK (1U)

#  define RTE_E_DataServices_Cycle_configuration_Read_Cycles_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Cycle_configuration_Read_Cycles_E_NOT_OK (1U)

#  define RTE_E_DataServices_DID_FD2F_EcuLocationData_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_DID_FD2F_EcuLocationData_E_NOT_OK (1U)

#  define RTE_E_DataServices_ECUSerialNumberDataIdentifier_Read_ECU_Serial_Number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ECUSerialNumberDataIdentifier_Read_ECU_Serial_Number_E_NOT_OK (1U)

#  define RTE_E_DataServices_ECU_serial_number_Read_ECU_traceability_number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ECU_serial_number_Read_ECU_traceability_number_E_NOT_OK (1U)

#  define RTE_E_DataServices_ECU_serial_number_Read_PCBA_Programmed_Part_number_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_ECU_serial_number_Read_PCBA_Programmed_Part_number_E_NOT_OK (1U)

#  define RTE_E_DataServices_HB_Calibration_Read_CombinedSignal_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HB_Calibration_Read_CombinedSignal_E_NOT_OK (1U)

#  define RTE_E_DataServices_HW_input_Read_Voltage_KL30t_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HW_input_Read_Voltage_KL30t_E_NOT_OK (1U)

#  define RTE_E_DataServices_HW_input_Read_Voltage_Motor_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_HW_input_Read_Voltage_Motor_E_NOT_OK (1U)

#  define RTE_E_DataServices_Hardware_Version_Information_Write_HW_patch_level_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Hardware_Version_Information_Write_HW_patch_level_E_NOT_OK (1U)

#  define RTE_E_DataServices_Hardware_Version_Information_Write_HW_week_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Hardware_Version_Information_Write_HW_week_E_NOT_OK (1U)

#  define RTE_E_DataServices_Hardware_Version_Information_Write_HW_year_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Hardware_Version_Information_Write_HW_year_E_NOT_OK (1U)

#  define RTE_E_DataServices_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Internal_ECU_information_Read_Autosar_System_State_EcuM_State_E_NOT_OK (1U)

#  define RTE_E_DataServices_Internal_ECU_information_Read_ECU_Temperature_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Internal_ECU_information_Read_ECU_Temperature_E_NOT_OK (1U)

#  define RTE_E_DataServices_Internal_ECU_information_Read_MOTOR_Current_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Internal_ECU_information_Read_MOTOR_Current_E_NOT_OK (1U)

#  define RTE_E_DataServices_Last_Warm_Reset_Parameters_Read_Last_Detected_Warm_Reset_Cause_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Last_Warm_Reset_Parameters_Read_Last_Detected_Warm_Reset_Cause_E_NOT_OK (1U)

#  define RTE_E_DataServices_Last_Warm_Reset_Parameters_Read_Reset_Cause_Counter_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Last_Warm_Reset_Parameters_Read_Reset_Cause_Counter_E_NOT_OK (1U)

#  define RTE_E_DataServices_Measurement_Frame_Block_12_Config_Read_CombinedSignal_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Measurement_Frame_Block_12_Config_Read_CombinedSignal_E_NOT_OK (1U)

#  define RTE_E_DataServices_Measurement_Frames_Configuration_Read_CombinedSignal_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Measurement_Frames_Configuration_Read_CombinedSignal_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Current_Value_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Current_Value_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Green_to_Yellow_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Green_to_Yellow_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Yellow_to_Red_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_BSR_Threshold_Yellow_to_Red_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Current_Value_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Current_Value_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Green_to_Yellow_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Green_to_Yellow_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Yellow_to_Red_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_CRASH_Threshold_Yellow_to_Red_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Current_Value_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Green_to_Yellow_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Green_to_Yellow_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Yellow_to_Red_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_PRE_SAFE_Lvl_4_5_Threshold_Yellow_to_Red_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Current_Value_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Current_Value_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Green_to_Yellow_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Green_to_Yellow_E_NOT_OK (1U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Yellow_to_Red_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Obsolescence_Data_Read_Obsolescence_Data_haptic_Warning_Threshold_Yellow_to_Red_E_NOT_OK (1U)

#  define RTE_E_DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_PRE_SAFE_Recorder_1_read_Read_CombinedDataElement_E_NOT_OK (1U)

#  define RTE_E_DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_PRE_SAFE_Recorder_2_read_Read_CombinedDataElement_E_NOT_OK (1U)

#  define RTE_E_DataServices_Reset_Cause_Management_Read_Reset_Cause_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Reset_Cause_Management_Read_Reset_Cause_E_NOT_OK (1U)

#  define RTE_E_DataServices_SW_Version_Read_SW_Version_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_SW_Version_Read_SW_Version_E_NOT_OK (1U)

#  define RTE_E_DataServices_Seatbelt_Serial_Number_Read_Unique_Seatbelt_Serialnumber_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Seatbelt_Serial_Number_Read_Unique_Seatbelt_Serialnumber_E_NOT_OK (1U)

#  define RTE_E_DataServices_Steps_library_Read_Steps_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Steps_library_Read_Steps_E_NOT_OK (1U)

#  define RTE_E_DataServices_Temperature_Sensor_Calibration_Point_Read_Offset_Point_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Temperature_Sensor_Calibration_Point_Read_Offset_Point_E_NOT_OK (1U)

#  define RTE_E_DataServices_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_DCM_E_PENDING (10U)

#  define RTE_E_DataServices_Velocity_PI_Regulation_Coefficient_Read_Input_Velocity_Coefficient_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC2_SRBS_E_NOT_OK (1U)

#  define RTE_E_NvMService_AC3_SRBS_Defs_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Check_Reprogramming_Preconditions_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Check_Reprogramming_Preconditions_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Check_Reprogramming_Preconditions_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Cycle_Execution_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Cycle_Execution_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Cycle_Execution_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Trigger_BSR_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Trigger_BSR_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Trigger_BSR_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Trigger_Presafe_Display_Request_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Trigger_Presafe_Display_Request_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Trigger_Presafe_Display_Request_Start_E_NOT_OK (1U)

#  define RTE_E_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_DCM_E_FORCE_RCRRP (12U)

#  define RTE_E_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_DCM_E_PENDING (10U)

#  define RTE_E_RoutineServices_Routine_Trigger_Tensioning_Cycle_Start_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_DIA_AC_DIAGONCAN_H */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0786:  MISRA rule: Rule5.5
     Reason:     Same macro and idintifier names in first 63 characters are required to meet AUTOSAR spec.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3449:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3451:  MISRA rule: Rule8.5
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/

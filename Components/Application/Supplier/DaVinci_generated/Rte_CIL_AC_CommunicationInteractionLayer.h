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
 *             File:  Rte_CIL_AC_CommunicationInteractionLayer.h
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  Application header file for SW-C <CIL_AC_CommunicationInteractionLayer>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_H
# define RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_H

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

# include "Rte_CIL_AC_CommunicationInteractionLayer_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

#  include "Com.h"


/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(u8PreCrashSeverityLevelType, RTE_VAR_NOINIT) Rte_CIL_prrCrashSeverityLevel_u8PreCrashSeverityLevel;
extern VAR(u8lBuckleSwitchStatusType, RTE_VAR_NOINIT) Rte_CIL_psrBuckleDoorSwitch_u8BuckleSwitch;
extern VAR(b8IsCarAccelerationLowType, RTE_VAR_NOINIT) Rte_CIL_psrCarAcceleration_b8IsCarAccelerationLow;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8HardReleaseRequest;
extern VAR(b8IsCarCrankingActiveType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8IsCarCrankingActive;
extern VAR(b8IsCarCrashDetectedType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8IsCarCrashDetected;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8IsTrigOffEventAllowed;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8PreCrashRequestEnable;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8SignalRelInhibition;
extern VAR(u8BeltSlackStatusType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_u8BeltSlackStatus;
extern VAR(u8HapticRequestType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_u8HapticRequest;
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_u8TriggerRequest;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrEngStartStatus_b8EngStartStatus;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrExtTestPres_b8ExtTesterPresent;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrIgnitionStatus_b8TriggerIgnitionStatus;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition;
extern VAR(c04_Presf_Lvl_V2, RTE_VAR_NOINIT) Rte_CIL_psrPreSafeLvl_u8PreSafeLvl;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrProdModeStatus_b8TriggerProdModeStatus;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrTransportationModeStatus_b8TransportationModeStatus;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_SFR_psrBeltStackAntipatina_b8BeltStack;
extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedCycle_u8CycleNumber;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle0_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle1_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle10_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle11_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle12_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle13_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle14_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle15_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle16_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle17_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle18_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle19_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle2_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle20_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle21_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle22_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle23_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle24_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle25_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle26_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle27_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle28_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle3_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle4_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle5_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle6_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle7_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle8_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle9_b8CycleValidity;
extern VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_DIA_psePresafeDisplay_b8TriggerPreSafeRequestStatus;
extern VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFS_psrSelectedCycle_u8CycleNumber;
extern VAR(u8StepNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedStep_u8StepNumber;
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8CodingValidity;
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8VehicleEquipValidity;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3 (3U)
#  define Rte_InitValue_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3 (3U)
#  define Rte_InitValue_IF_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3 (0U)
#  define Rte_InitValue_IF_RBTM_FL_Tgl_ST3_RBTM_FL_Tgl_ST3 (FALSE)
#  define Rte_InitValue_P_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3 (3U)
#  define Rte_InitValue_P_RBTMFL_SP_ActvClient_ST35_RBTMFL_SP_ActvClient_ST35 (0U)
#  define Rte_InitValue_P_RBTMFL_SP_FctPrecond_Stat_ST35_RBTMFL_SP_FctPrecond_Stat_ST35 (0U)
#  define Rte_InitValue_P_RBTMFR_SP_ActvClient_ST35_RBTMFR_SP_ActvClient_ST35 (0U)
#  define Rte_InitValue_P_RBTMFR_SP_FctPrecond_Stat_ST35_RBTMFR_SP_FctPrecond_Stat_ST35 (0U)
#  define Rte_InitValue_P_RBTM_FR_Disp_Rq_ST3_RBTM_FR_Disp_Rq_ST3 (0U)
#  define Rte_InitValue_P_RBTM_FR_Tgl_ST3_RBTM_FR_Tgl_ST3 (FALSE)
#  define Rte_InitValue_RBTMFL_Actv_Lvl_ST35_RBTMFL_Actv_Lvl_ST35 (63U)
#  define Rte_InitValue_RBTMFR_Actv_Lvl_ST35_RBTMFR_Actv_Lvl_ST35 (63U)
#  define Rte_InitValue_R_BeltHdOvr_XX_Stat_ST3_BeltHdOvr_XX_Stat_ST3 (3U)
#  define Rte_InitValue_R_BltSlckDec_Md_Rq_HU_ST3_BltSlckDec_Md_Rq_HU_ST3 (3U)
#  define Rte_InitValue_R_PN14_ProdMd_Stat_ST3_PN14_ProdMd_Stat_ST3 (7U)
#  define Rte_InitValue_R_PN14_TransMd_Stat_ST3_PN14_TransMd_Stat_ST3 (3U)
#  define Rte_InitValue_R_PS_Curve_FL_Rq_HU_ST3_PS_Curve_FL_Rq_HU_ST3 (3U)
#  define Rte_InitValue_R_PS_Curve_FR_Rq_HU_ST3_PS_Curve_FR_Rq_HU_ST3 (3U)
#  define Rte_InitValue_prrAlgo01_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo01_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo01_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo01_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo01_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo02_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo02_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo02_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo02_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo02_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo03_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo03_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo03_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo03_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo03_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo04_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo04_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo04_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo04_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo04_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo05_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo05_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo05_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo05_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo05_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo06_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo06_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo06_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo06_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo06_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo07_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo07_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo07_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo07_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo07_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo08_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo08_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo08_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo08_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo08_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo09_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo09_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo09_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo09_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo09_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo10_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo10_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo10_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo10_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo10_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo11_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo11_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo11_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo11_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo11_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo12_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo12_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo12_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo12_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo12_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo13_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo13_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo13_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo13_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo13_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo14_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo14_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo14_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo14_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo14_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo15_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo15_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo15_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo15_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo15_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo16_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo16_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo16_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo16_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo16_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo17_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo17_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo17_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo17_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo17_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo18_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo18_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo18_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo18_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo18_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo19_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo19_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo19_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo19_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo19_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo20_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo20_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo20_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo20_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo20_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo21_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo21_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo21_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo21_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo21_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo22_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo22_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo22_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo22_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo22_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo23_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo23_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo23_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo23_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo23_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo24_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo24_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo24_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo24_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo24_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo25_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo25_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo25_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo25_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo25_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo26_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo26_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo26_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo26_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo26_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo30_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo30_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo30_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo30_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo30_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo31_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo31_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo31_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo31_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo31_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo32_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo32_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo32_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo32_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo32_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo33_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo33_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo33_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo33_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo33_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo34_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo34_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo34_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo34_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo34_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo35_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo35_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo35_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo35_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo35_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo36_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo36_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo36_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo36_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo36_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo37_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo37_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo37_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo37_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo37_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrAlgo38_Flags_b8InterruptFlag (85U)
#  define Rte_InitValue_prrAlgo38_Flags_b8PreActivationFlag (85U)
#  define Rte_InitValue_prrAlgo38_Flags_b8PreConditionsFlag (85U)
#  define Rte_InitValue_prrAlgo38_Flags_b8TriggerFlag (85U)
#  define Rte_InitValue_prrAlgo38_Flags_u8TriggeringSource (0U)
#  define Rte_InitValue_prrBeltStackAntipatina_b8BeltStack (0U)
#  define Rte_InitValue_prrCycleNumber_u8CycleNumber (255U)
#  define Rte_InitValue_prrEnableCycle0_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle1_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle10_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle11_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle12_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle13_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle14_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle15_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle16_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle17_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle18_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle19_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle2_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle20_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle21_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle22_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle23_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle24_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle25_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle26_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle27_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle28_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle3_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle4_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle5_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle6_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle7_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle8_b8CycleValidity (85U)
#  define Rte_InitValue_prrEnableCycle9_b8CycleValidity (85U)
#  define Rte_InitValue_prrPresafeDisplay_b8TriggerPreSafeRequestStatus (85U)
#  define Rte_InitValue_prrSelectedCycle_u8CycleNumber (255U)
#  define Rte_InitValue_prrStepNumber_u8StepNumber (255U)
#  define Rte_InitValue_prrVehicleEquipmentValidity_u8CodingValidity (85U)
#  define Rte_InitValue_prrVehicleEquipmentValidity_u8VehicleEquipValidity (85U)
#  define Rte_InitValue_psrBuckleDoorSwitch_u8BuckleSwitch (255U)
#  define Rte_InitValue_psrBuckleDoorSwitch_u8DoorSwitch (255U)
#  define Rte_InitValue_psrCarAcceleration_b8IsCarAccelerationLow (170U)
#  define Rte_InitValue_psrCustomerSpecific_b8HardReleaseRequest (85U)
#  define Rte_InitValue_psrCustomerSpecific_b8IsCarCrankingActive (170U)
#  define Rte_InitValue_psrCustomerSpecific_b8IsCarCrashDetected (85U)
#  define Rte_InitValue_psrCustomerSpecific_b8IsTrigOffEventAllowed (85U)
#  define Rte_InitValue_psrCustomerSpecific_b8PreCrashRequestEnable (85U)
#  define Rte_InitValue_psrCustomerSpecific_b8SignalRelInhibition (85U)
#  define Rte_InitValue_psrCustomerSpecific_u8BeltSlackStatus (2U)
#  define Rte_InitValue_psrCustomerSpecific_u8HapticRequest (8U)
#  define Rte_InitValue_psrCustomerSpecific_u8PreCrashRequest (255U)
#  define Rte_InitValue_psrCustomerSpecific_u8TriggerRequest (255U)
#  define Rte_InitValue_psrDriverControls_b8VehicleMovingBackwards (85U)
#  define Rte_InitValue_psrDriverControls_s16AccelerationPedalPositionRate (0)
#  define Rte_InitValue_psrDriverControls_s16BrakePressureRate (0)
#  define Rte_InitValue_psrDriverControls_s16HWAngle (0)
#  define Rte_InitValue_psrDriverControls_s16HWRate (0)
#  define Rte_InitValue_psrDriverControls_u16BrakePressure (0U)
#  define Rte_InitValue_psrDriverControls_u16VehicleSpeed (0U)
#  define Rte_InitValue_psrDriverControls_u8AccelerationPedalPosition (0U)
#  define Rte_InitValue_psrDriverControls_u8KlemmenStatus (0U)
#  define Rte_InitValue_psrExtTestPres_b8DTCConfirmed (85U)
#  define Rte_InitValue_psrExtTestPres_b8ExtTesterPresent (85U)
#  define Rte_InitValue_psrIgnitionStatus_b8TriggerIgnitionStatus (85U)
#  define Rte_InitValue_psrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition (85U)
#  define Rte_InitValue_psrPreSafeLvl_u8PreSafeLvl (0U)
#  define Rte_InitValue_psrProdModeStatus_b8TriggerProdModeStatus (170U)
#  define Rte_InitValue_psrTransportationModeStatus_b8TransportationModeStatus (170U)
# endif


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Buffers for inter-runnable variables
 *********************************************************************************************************************/

#  define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern VAR(b8IsCarCrashDetectedType, RTE_VAR_NOINIT) Rte_Irv_CIL_b8CarCrashDetected;
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_Irv_CIL_b8PreCrashRequestEnable;
extern VAR(uint8, RTE_VAR_NOINIT) Rte_Irv_CIL_u8ActvLvlSignal;
extern VAR(u8lBuckleSwitchStatusType, RTE_VAR_NOINIT) Rte_Irv_CIL_u8BuckleStatus;
extern VAR(UInt8, RTE_VAR_NOINIT) Rte_Irv_CIL_u8FctPrecond_ProfileNotImplemented;
extern VAR(uint8, RTE_VAR_NOINIT) Rte_Irv_CIL_u8RequestSource;

#  define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# endif /* !defined(RTE_CORE) */


# define RTE_START_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3(P2VAR(REC_Ign_Stat_Pr5_ST3, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3(P2VAR(REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3(P2VAR(REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3(P2VAR(REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3(P2VAR(REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_BeltHdOvr_XX_Stat_ST3_BeltHdOvr_XX_Stat_ST3(P2VAR(c02_BeltHdOvr_Stat, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_BltSlckDec_Md_Rq_HU_ST3_BltSlckDec_Md_Rq_HU_ST3(P2VAR(c02_Off_On, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3(P2VAR(REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PS_Curve_FL_Rq_HU_ST3_PS_Curve_FL_Rq_HU_ST3(P2VAR(c02_Off_Stage1_Stage2, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PS_Curve_FR_Rq_HU_ST3_PS_Curve_FR_Rq_HU_ST3(P2VAR(c02_Off_Stage1_Stage2, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3(P2VAR(REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(P2VAR(REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3(P2VAR(REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3(c02_Off_On data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3(c02_Off_Stage1_Stage2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3(c02_Presf_Disp_Rq data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_RBTM_FL_Tgl_ST3_RBTM_FL_Tgl_ST3(DC_BOOL data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_Meas_RBTM_FL_ST3_Meas8_RBTM_FL_ST3(P2CONST(REC_Meas_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_Meas_RBTM_FR_ST3_Meas8_RBTM_FR_ST3(P2CONST(REC_Meas_RBTM_FR_ST3_dgfi1nrxtb0voy6rb7ybeonmv, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_DATA) data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3(c02_Off_Stage1_Stage2 data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTMFL_SP_ActvClient_ST35_RBTMFL_SP_ActvClient_ST35(c04_RBTM_ActvClient data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTMFL_SP_FctPrecond_Stat_ST35_RBTMFL_SP_FctPrecond_Stat_ST35(c10_RBTM_Fct_Precond data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTMFR_SP_ActvClient_ST35_RBTMFR_SP_ActvClient_ST35(c04_RBTM_ActvClient data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTMFR_SP_FctPrecond_Stat_ST35_RBTMFR_SP_FctPrecond_Stat_ST35(c10_RBTM_Fct_Precond data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTM_FR_Disp_Rq_ST3_RBTM_FR_Disp_Rq_ST3(c02_Presf_Disp_Rq data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTM_FR_Tgl_ST3_RBTM_FR_Tgl_ST3(DC_BOOL data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_RBTMFL_Actv_Lvl_ST35_RBTMFL_Actv_Lvl_ST35(c06_RBTM_Lvl_Stat data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_RBTMFR_Actv_Lvl_ST35_RBTMFR_Actv_Lvl_ST35(c06_RBTM_Lvl_Stat data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCANInputBlockStatus_b8NVMBlockStatus(b8BooleanType data); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

# define RTE_STOP_SEC_CODE
# include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3 Rte_Read_CIL_AC_CommunicationInteractionLayer_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3
#  define Rte_Read_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3 Rte_Read_CIL_AC_CommunicationInteractionLayer_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3
#  define Rte_Read_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3 Rte_Read_CIL_AC_CommunicationInteractionLayer_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3
#  define Rte_Read_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3 Rte_Read_CIL_AC_CommunicationInteractionLayer_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3
#  define Rte_Read_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3 Rte_Read_CIL_AC_CommunicationInteractionLayer_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3
#  define Rte_Read_R_BeltHdOvr_XX_Stat_ST3_BeltHdOvr_XX_Stat_ST3 Rte_Read_CIL_AC_CommunicationInteractionLayer_R_BeltHdOvr_XX_Stat_ST3_BeltHdOvr_XX_Stat_ST3
#  define Rte_Read_R_BltSlckDec_Md_Rq_HU_ST3_BltSlckDec_Md_Rq_HU_ST3 Rte_Read_CIL_AC_CommunicationInteractionLayer_R_BltSlckDec_Md_Rq_HU_ST3_BltSlckDec_Md_Rq_HU_ST3
#  define Rte_Read_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3 Rte_Read_CIL_AC_CommunicationInteractionLayer_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3
#  define Rte_Read_R_PN14_ProdMd_Stat_ST3_PN14_ProdMd_Stat_ST3 Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PN14_ProdMd_Stat_ST3_PN14_ProdMd_Stat_ST3
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PN14_ProdMd_Stat_ST3_PN14_ProdMd_Stat_ST3(data) (Com_ReceiveSignal(ComConf_ComSignal_PN14_ProdMd_Stat_ST3_be2b5dfe_Rx, (data)))
#  define Rte_Read_R_PN14_TransMd_Stat_ST3_PN14_TransMd_Stat_ST3 Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PN14_TransMd_Stat_ST3_PN14_TransMd_Stat_ST3
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PN14_TransMd_Stat_ST3_PN14_TransMd_Stat_ST3(data) (Com_ReceiveSignal(ComConf_ComSignal_PN14_TransMd_Stat_ST3_2208da29_Rx, (data)))
#  define Rte_Read_R_PS_Curve_FL_Rq_HU_ST3_PS_Curve_FL_Rq_HU_ST3 Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PS_Curve_FL_Rq_HU_ST3_PS_Curve_FL_Rq_HU_ST3
#  define Rte_Read_R_PS_Curve_FR_Rq_HU_ST3_PS_Curve_FR_Rq_HU_ST3 Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PS_Curve_FR_Rq_HU_ST3_PS_Curve_FR_Rq_HU_ST3
#  define Rte_Read_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3 Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3
#  define Rte_Read_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3 Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3
#  define Rte_Read_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3 Rte_Read_CIL_AC_CommunicationInteractionLayer_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3
#  define Rte_Read_prrAlgo01_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo01_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo01_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo01_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo01_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo01_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo01_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo01_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo01_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo01_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo01_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo01_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo01_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo01_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo01_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo02_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo02_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo02_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo02_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo02_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo02_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo02_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo02_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo02_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo02_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo02_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo02_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo02_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo02_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo02_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo03_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo03_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo03_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo03_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo03_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo03_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo03_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo03_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo03_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo03_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo03_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo03_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo03_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo03_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo03_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo04_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo04_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo04_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo04_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo04_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo04_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo04_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo04_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo04_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo04_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo04_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo04_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo04_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo04_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo04_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo05_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo05_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo05_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo05_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo05_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo05_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo05_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo05_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo05_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo05_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo05_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo05_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo05_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo05_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo05_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo06_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo06_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo06_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo06_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo06_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo06_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo06_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo06_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo06_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo06_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo06_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo06_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo06_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo06_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo06_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo07_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo07_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo07_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo07_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo07_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo07_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo07_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo07_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo07_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo07_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo07_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo07_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo07_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo07_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo07_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo08_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo08_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo08_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo08_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo08_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo08_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo08_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo08_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo08_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo08_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo08_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo08_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo08_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo08_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo08_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo09_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo09_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo09_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo09_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo09_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo09_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo09_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo09_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo09_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo09_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo09_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo09_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo09_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo09_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo09_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo10_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo10_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo10_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo10_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo10_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo10_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo10_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo10_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo10_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo10_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo10_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo10_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo10_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo10_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo10_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo11_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo11_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo11_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo11_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo11_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo11_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo11_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo11_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo11_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo11_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo11_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo11_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo11_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo11_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo11_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo12_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo12_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo12_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo12_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo12_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo12_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo12_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo12_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo12_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo12_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo12_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo12_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo12_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo12_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo12_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo13_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo13_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo13_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo13_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo13_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo13_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo13_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo13_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo13_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo13_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo13_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo13_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo13_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo13_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo13_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo14_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo14_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo14_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo14_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo14_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo14_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo14_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo14_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo14_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo14_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo14_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo14_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo14_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo14_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo14_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo15_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo15_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo15_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo15_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo15_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo15_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo15_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo15_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo15_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo15_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo15_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo15_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo15_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo15_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo15_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo16_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo16_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo16_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo16_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo16_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo16_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo17_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo17_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo17_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo17_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo17_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo17_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo18_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo18_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo18_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo18_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo18_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo18_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo19_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo19_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo19_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo19_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo19_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo19_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo20_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo20_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo20_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo20_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo20_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo20_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo21_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo21_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo21_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo21_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo21_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo21_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo22_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo22_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo22_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo22_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo22_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo22_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo22_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo22_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo22_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo22_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo22_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo22_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo22_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo22_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo22_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo23_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo23_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo23_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo23_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo23_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo23_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo23_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo23_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo23_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo23_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo23_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo23_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo23_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo23_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo23_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo24_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo24_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo24_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo24_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo24_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo24_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo24_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo24_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo24_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo24_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo24_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo24_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo24_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo24_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo24_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo25_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo25_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo25_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo25_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo25_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo25_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo25_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo25_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo25_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo25_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo25_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo25_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo25_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo25_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo25_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo26_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo26_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo26_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo26_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo26_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo26_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo26_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo26_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo26_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo26_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo26_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo26_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo26_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo26_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo26_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo30_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo30_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo30_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo30_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo30_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo30_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo30_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo30_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo30_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo30_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo30_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo30_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo30_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo30_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo30_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo31_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo31_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo31_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo31_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo31_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo31_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo31_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo31_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo31_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo31_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo31_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo31_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo31_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo31_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo31_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo32_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo32_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo32_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo32_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo32_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo32_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo32_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo32_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo32_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo32_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo32_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo32_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo32_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo32_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo32_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo33_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo33_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo33_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo33_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo33_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo33_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo33_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo33_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo33_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo33_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo33_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo33_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo33_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo33_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo33_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo34_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo34_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo34_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo34_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo34_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo34_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo34_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo34_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo34_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo34_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo34_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo34_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo34_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo34_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo34_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo35_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo35_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo35_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo35_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo35_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo35_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo35_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo35_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo35_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo35_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo35_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo35_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo35_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo35_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo35_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo36_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo36_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo36_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo36_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo36_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo36_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo36_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo36_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo36_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo36_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo36_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo36_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo36_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo36_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo36_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo37_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo37_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo37_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo37_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo37_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo37_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo37_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo37_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo37_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo37_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo37_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo37_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo37_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo37_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo37_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo38_Flags_b8InterruptFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo38_Flags_b8InterruptFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo38_Flags_b8InterruptFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo38_Flags_b8PreActivationFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo38_Flags_b8PreActivationFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo38_Flags_b8PreActivationFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo38_Flags_b8PreConditionsFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo38_Flags_b8PreConditionsFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo38_Flags_b8PreConditionsFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo38_Flags_b8TriggerFlag Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo38_Flags_b8TriggerFlag

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo38_Flags_b8TriggerFlag(data) (*(data) = 85U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrAlgo38_Flags_u8TriggeringSource Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo38_Flags_u8TriggeringSource

#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrAlgo38_Flags_u8TriggeringSource(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED))
#  define Rte_Read_prrBeltStackAntipatina_b8BeltStack Rte_Read_CIL_AC_CommunicationInteractionLayer_prrBeltStackAntipatina_b8BeltStack
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrBeltStackAntipatina_b8BeltStack(data) (*(data) = Rte_SFR_psrBeltStackAntipatina_b8BeltStack, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrCycleNumber_u8CycleNumber Rte_Read_CIL_AC_CommunicationInteractionLayer_prrCycleNumber_u8CycleNumber
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrCycleNumber_u8CycleNumber(data) (*(data) = Rte_BFE_psrExecutedCycle_u8CycleNumber, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle0_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle0_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle0_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle0_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle1_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle1_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle1_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle1_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle10_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle10_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle10_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle10_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle11_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle11_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle11_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle11_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle12_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle12_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle12_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle12_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle13_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle13_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle13_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle13_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle14_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle14_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle14_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle14_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle15_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle15_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle15_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle15_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle16_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle16_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle16_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle16_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle17_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle17_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle17_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle17_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle18_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle18_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle18_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle18_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle19_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle19_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle19_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle19_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle2_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle2_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle2_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle2_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle20_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle20_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle20_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle20_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle21_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle21_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle21_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle21_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle22_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle22_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle22_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle22_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle23_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle23_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle23_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle23_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle24_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle24_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle24_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle24_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle25_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle25_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle25_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle25_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle26_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle26_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle26_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle26_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle27_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle27_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle27_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle27_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle28_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle28_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle28_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle28_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle3_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle3_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle3_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle3_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle4_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle4_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle4_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle4_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle5_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle5_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle5_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle5_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle6_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle6_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle6_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle6_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle7_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle7_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle7_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle7_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle8_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle8_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle8_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle8_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrEnableCycle9_b8CycleValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle9_b8CycleValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrEnableCycle9_b8CycleValidity(data) (*(data) = Rte_MMG_psrEnableCycle9_b8CycleValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrPresafeDisplay_b8TriggerPreSafeRequestStatus Rte_Read_CIL_AC_CommunicationInteractionLayer_prrPresafeDisplay_b8TriggerPreSafeRequestStatus
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrPresafeDisplay_b8TriggerPreSafeRequestStatus(data) (*(data) = Rte_DIA_psePresafeDisplay_b8TriggerPreSafeRequestStatus, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrSelectedCycle_u8CycleNumber Rte_Read_CIL_AC_CommunicationInteractionLayer_prrSelectedCycle_u8CycleNumber
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrSelectedCycle_u8CycleNumber(data) (*(data) = Rte_BFS_psrSelectedCycle_u8CycleNumber, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrStepNumber_u8StepNumber Rte_Read_CIL_AC_CommunicationInteractionLayer_prrStepNumber_u8StepNumber
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrStepNumber_u8StepNumber(data) (*(data) = Rte_BFE_psrExecutedStep_u8StepNumber, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrVehicleEquipmentValidity_u8CodingValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrVehicleEquipmentValidity_u8CodingValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrVehicleEquipmentValidity_u8CodingValidity(data) (*(data) = Rte_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8CodingValidity, ((Std_ReturnType)RTE_E_OK))
#  define Rte_Read_prrVehicleEquipmentValidity_u8VehicleEquipValidity Rte_Read_CIL_AC_CommunicationInteractionLayer_prrVehicleEquipmentValidity_u8VehicleEquipValidity
#  define Rte_Read_CIL_AC_CommunicationInteractionLayer_prrVehicleEquipmentValidity_u8VehicleEquipValidity(data) (*(data) = Rte_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8VehicleEquipValidity, ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3 Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3
#  define Rte_Write_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3 Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3
#  define Rte_Write_IF_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3 Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3
#  define Rte_Write_IF_RBTM_FL_Tgl_ST3_RBTM_FL_Tgl_ST3 Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_RBTM_FL_Tgl_ST3_RBTM_FL_Tgl_ST3
#  define Rte_Write_P_Meas_RBTM_FL_ST3_Meas8_RBTM_FL_ST3 Rte_Write_CIL_AC_CommunicationInteractionLayer_P_Meas_RBTM_FL_ST3_Meas8_RBTM_FL_ST3
#  define Rte_Write_P_Meas_RBTM_FR_ST3_Meas8_RBTM_FR_ST3 Rte_Write_CIL_AC_CommunicationInteractionLayer_P_Meas_RBTM_FR_ST3_Meas8_RBTM_FR_ST3
#  define Rte_Write_P_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3 Rte_Write_CIL_AC_CommunicationInteractionLayer_P_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3
#  define Rte_Write_P_RBTMFL_SP_ActvClient_ST35_RBTMFL_SP_ActvClient_ST35 Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTMFL_SP_ActvClient_ST35_RBTMFL_SP_ActvClient_ST35
#  define Rte_Write_P_RBTMFL_SP_FctPrecond_Stat_ST35_RBTMFL_SP_FctPrecond_Stat_ST35 Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTMFL_SP_FctPrecond_Stat_ST35_RBTMFL_SP_FctPrecond_Stat_ST35
#  define Rte_Write_P_RBTMFR_SP_ActvClient_ST35_RBTMFR_SP_ActvClient_ST35 Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTMFR_SP_ActvClient_ST35_RBTMFR_SP_ActvClient_ST35
#  define Rte_Write_P_RBTMFR_SP_FctPrecond_Stat_ST35_RBTMFR_SP_FctPrecond_Stat_ST35 Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTMFR_SP_FctPrecond_Stat_ST35_RBTMFR_SP_FctPrecond_Stat_ST35
#  define Rte_Write_P_RBTM_FR_Disp_Rq_ST3_RBTM_FR_Disp_Rq_ST3 Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTM_FR_Disp_Rq_ST3_RBTM_FR_Disp_Rq_ST3
#  define Rte_Write_P_RBTM_FR_Tgl_ST3_RBTM_FR_Tgl_ST3 Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTM_FR_Tgl_ST3_RBTM_FR_Tgl_ST3
#  define Rte_Write_RBTMFL_Actv_Lvl_ST35_RBTMFL_Actv_Lvl_ST35 Rte_Write_CIL_AC_CommunicationInteractionLayer_RBTMFL_Actv_Lvl_ST35_RBTMFL_Actv_Lvl_ST35
#  define Rte_Write_RBTMFR_Actv_Lvl_ST35_RBTMFR_Actv_Lvl_ST35 Rte_Write_CIL_AC_CommunicationInteractionLayer_RBTMFR_Actv_Lvl_ST35_RBTMFR_Actv_Lvl_ST35
#  define Rte_Write_prrCrashSeverityLevel_u8PreCrashSeverityLevel Rte_Write_CIL_AC_CommunicationInteractionLayer_prrCrashSeverityLevel_u8PreCrashSeverityLevel
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_prrCrashSeverityLevel_u8PreCrashSeverityLevel(data) (Rte_CIL_prrCrashSeverityLevel_u8PreCrashSeverityLevel = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrBuckleDoorSwitch_u8BuckleSwitch Rte_Write_CIL_AC_CommunicationInteractionLayer_psrBuckleDoorSwitch_u8BuckleSwitch
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrBuckleDoorSwitch_u8BuckleSwitch(data) (Rte_CIL_psrBuckleDoorSwitch_u8BuckleSwitch = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrBuckleDoorSwitch_u8DoorSwitch Rte_Write_CIL_AC_CommunicationInteractionLayer_psrBuckleDoorSwitch_u8DoorSwitch
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrBuckleDoorSwitch_u8DoorSwitch(data) (RTE_E_OK)
#  define Rte_Write_psrCANInputBlockStatus_b8NVMBlockStatus Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCANInputBlockStatus_b8NVMBlockStatus
#  define Rte_Write_psrCarAcceleration_b8IsCarAccelerationLow Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCarAcceleration_b8IsCarAccelerationLow
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCarAcceleration_b8IsCarAccelerationLow(data) (Rte_CIL_psrCarAcceleration_b8IsCarAccelerationLow = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrCustomerSpecific_b8HardReleaseRequest Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_b8HardReleaseRequest
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_b8HardReleaseRequest(data) (Rte_CIL_psrCustomerSpecific_b8HardReleaseRequest = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrCustomerSpecific_b8IsCarCrankingActive Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_b8IsCarCrankingActive
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_b8IsCarCrankingActive(data) (Rte_CIL_psrCustomerSpecific_b8IsCarCrankingActive = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrCustomerSpecific_b8IsCarCrashDetected Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_b8IsCarCrashDetected
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_b8IsCarCrashDetected(data) (Rte_CIL_psrCustomerSpecific_b8IsCarCrashDetected = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrCustomerSpecific_b8IsTrigOffEventAllowed Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_b8IsTrigOffEventAllowed
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_b8IsTrigOffEventAllowed(data) (Rte_CIL_psrCustomerSpecific_b8IsTrigOffEventAllowed = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrCustomerSpecific_b8PreCrashRequestEnable Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_b8PreCrashRequestEnable
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_b8PreCrashRequestEnable(data) (Rte_CIL_psrCustomerSpecific_b8PreCrashRequestEnable = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrCustomerSpecific_b8SignalRelInhibition Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_b8SignalRelInhibition
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_b8SignalRelInhibition(data) (Rte_CIL_psrCustomerSpecific_b8SignalRelInhibition = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrCustomerSpecific_u8BeltSlackStatus Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_u8BeltSlackStatus
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_u8BeltSlackStatus(data) (Rte_CIL_psrCustomerSpecific_u8BeltSlackStatus = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrCustomerSpecific_u8HapticRequest Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_u8HapticRequest
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_u8HapticRequest(data) (Rte_CIL_psrCustomerSpecific_u8HapticRequest = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrCustomerSpecific_u8PreCrashRequest Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_u8PreCrashRequest
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_u8PreCrashRequest(data) (RTE_E_OK)
#  define Rte_Write_psrCustomerSpecific_u8TriggerRequest Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_u8TriggerRequest
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCustomerSpecific_u8TriggerRequest(data) (Rte_CIL_psrCustomerSpecific_u8TriggerRequest = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrDriverControls_b8VehicleMovingBackwards Rte_Write_CIL_AC_CommunicationInteractionLayer_psrDriverControls_b8VehicleMovingBackwards
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrDriverControls_b8VehicleMovingBackwards(data) (RTE_E_OK)
#  define Rte_Write_psrDriverControls_s16AccelerationPedalPositionRate Rte_Write_CIL_AC_CommunicationInteractionLayer_psrDriverControls_s16AccelerationPedalPositionRate
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrDriverControls_s16AccelerationPedalPositionRate(data) (RTE_E_OK)
#  define Rte_Write_psrDriverControls_s16BrakePressureRate Rte_Write_CIL_AC_CommunicationInteractionLayer_psrDriverControls_s16BrakePressureRate
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrDriverControls_s16BrakePressureRate(data) (RTE_E_OK)
#  define Rte_Write_psrDriverControls_s16HWAngle Rte_Write_CIL_AC_CommunicationInteractionLayer_psrDriverControls_s16HWAngle
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrDriverControls_s16HWAngle(data) (RTE_E_OK)
#  define Rte_Write_psrDriverControls_s16HWRate Rte_Write_CIL_AC_CommunicationInteractionLayer_psrDriverControls_s16HWRate
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrDriverControls_s16HWRate(data) (RTE_E_OK)
#  define Rte_Write_psrDriverControls_u16BrakePressure Rte_Write_CIL_AC_CommunicationInteractionLayer_psrDriverControls_u16BrakePressure
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrDriverControls_u16BrakePressure(data) (RTE_E_OK)
#  define Rte_Write_psrDriverControls_u16VehicleSpeed Rte_Write_CIL_AC_CommunicationInteractionLayer_psrDriverControls_u16VehicleSpeed
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrDriverControls_u16VehicleSpeed(data) (RTE_E_OK)
#  define Rte_Write_psrDriverControls_u8AccelerationPedalPosition Rte_Write_CIL_AC_CommunicationInteractionLayer_psrDriverControls_u8AccelerationPedalPosition
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrDriverControls_u8AccelerationPedalPosition(data) (RTE_E_OK)
#  define Rte_Write_psrEngStartStatus_b8EngStartStatus Rte_Write_CIL_AC_CommunicationInteractionLayer_psrEngStartStatus_b8EngStartStatus
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrEngStartStatus_b8EngStartStatus(data) (Rte_CIL_psrEngStartStatus_b8EngStartStatus = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrExtTestPres_b8ExtTesterPresent Rte_Write_CIL_AC_CommunicationInteractionLayer_psrExtTestPres_b8ExtTesterPresent
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrExtTestPres_b8ExtTesterPresent(data) (Rte_CIL_psrExtTestPres_b8ExtTesterPresent = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrIgnitionStatus_b8TriggerIgnitionStatus Rte_Write_CIL_AC_CommunicationInteractionLayer_psrIgnitionStatus_b8TriggerIgnitionStatus
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrIgnitionStatus_b8TriggerIgnitionStatus(data) (Rte_CIL_psrIgnitionStatus_b8TriggerIgnitionStatus = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition Rte_Write_CIL_AC_CommunicationInteractionLayer_psrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition(data) (Rte_CIL_psrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrPreSafeLvl_u8PreSafeLvl Rte_Write_CIL_AC_CommunicationInteractionLayer_psrPreSafeLvl_u8PreSafeLvl
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrPreSafeLvl_u8PreSafeLvl(data) (Rte_CIL_psrPreSafeLvl_u8PreSafeLvl = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrProdModeStatus_b8TriggerProdModeStatus Rte_Write_CIL_AC_CommunicationInteractionLayer_psrProdModeStatus_b8TriggerProdModeStatus
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrProdModeStatus_b8TriggerProdModeStatus(data) (Rte_CIL_psrProdModeStatus_b8TriggerProdModeStatus = (data), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Write_psrTransportationModeStatus_b8TransportationModeStatus Rte_Write_CIL_AC_CommunicationInteractionLayer_psrTransportationModeStatus_b8TransportationModeStatus
#  define Rte_Write_CIL_AC_CommunicationInteractionLayer_psrTransportationModeStatus_b8TransportationModeStatus(data) (Rte_CIL_psrTransportationModeStatus_b8TransportationModeStatus = (data), ((Std_ReturnType)RTE_E_OK))


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_ATM_AC_AUTOTESTMANAGER_APPL_CODE) ATM_runGetTestResult(u8AutoTestIdType u8AutoTestId, P2VAR(u8TestResultType, AUTOMATIC, RTE_ATM_AC_AUTOTESTMANAGER_APPL_VAR) u8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ATM_AC_AUTOTESTMANAGER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_ADCIF_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetHBS_A_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetHBS_A_V_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetHBS_B_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetHBS_B_V_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetHS1_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetHS1_V_100ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetHS1_V_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetHS1_V_20ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetKL30_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetMotor_In(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetMotor_In_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetMotor_Ip(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetMotor_Ip_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetRefLow_V(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetRefLow_V_100ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ADCIF_APPL_CODE) AdcIf_runGetRefLow_V_10ms(P2VAR(u16SampledSignalType, AUTOMATIC, RTE_ADCIF_APPL_VAR) pu16SampledSignal); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ADCIF_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_runGetPositionFromMinPos_mm(P2VAR(s16BeltPosition_mmType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps16BeltPosition_mm); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_runGetPositionFromT0_deg(P2VAR(s16BeltPosition_degType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps16BeltPosition_deg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_runGetPositionFromT0_mm(P2VAR(s16BeltPosition_mmType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps16BeltPosition_mm); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_runGetPositionRange_mm(P2VAR(s16BeltPosition_mmType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps16BeltPosition_min_mm, P2VAR(s16BeltPosition_mmType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps16BeltPosition_max_mm); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_runGetSpeed_deg_s(P2VAR(s32BeltSpeed_deg_sType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) ps32BeltSpeed_deg_s); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE) BMM_runGetPyroActivationStatus(P2VAR(b8PyroActivationStatusType, AUTOMATIC, RTE_BMM_AC_BELTMOVEMENTMONITORING_APPL_VAR) pb8PyroActivationStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_BMM_AC_BELTMOVEMENTMONITORING_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_DIA_AC_DIAGONCAN_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_DIA_AC_DIAGONCAN_APPL_CODE) DIA_runGetDiagRequestCycle(P2VAR(u8CycleNumberType, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) u8DiagRequestCycle); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_DIA_AC_DIAGONCAN_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_ERH_AC_ERRORHANDLER_APPL_CODE) ERH_runGetAecGroupsStatus(P2VAR(u32AecGroupsType, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu32AecGroupsStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_ERH_AC_ERRORHANDLER_APPL_CODE) ERH_runGetAecStatus(u8AecIdentifierType u8AecIdentifier, P2VAR(u8AecStatusType, AUTOMATIC, RTE_ERH_AC_ERRORHANDLER_APPL_VAR) pu8AecStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_ERH_AC_ERRORHANDLER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_MMG_AC_MODEMANAGEMENT_APPL_CODE) MMG_runCheckModeStatus(u32ModeMaskType u32ModesToCheck, P2VAR(u8ModeStatusType, AUTOMATIC, RTE_MMG_AC_MODEMANAGEMENT_APPL_VAR) bModeStatus); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_MMG_AC_MODEMANAGEMENT_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_runReadMotorCurrentInA(P2VAR(s8MotorCurrentInAType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) ps8MotorCurrentInA); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_runReadMotorCurrentInmA(P2VAR(s32MotorCurrentInmAType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) ps32MotorCurrentInmA); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE) PAL_runGetPWMOrder(P2VAR(s16MotorPowerOrderType, AUTOMATIC, RTE_PAL_AC_POWERABSTRACTIONLAYER_APPL_VAR) ps16MotorPowerOrder); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_PAL_AC_POWERABSTRACTIONLAYER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define RTE_START_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_Autotest_CheckPowerSupplyUV(P2VAR(u8TestResultType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetFilteredTemperature(P2VAR(u16InternalTemperatureType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16FilteredTemperature); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetFilteredTemperature_deg(P2VAR(s16InternalTemperature_deg_Type, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) ps16InternalTemperature_deg); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetLowReferenceVoltage(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetLowReferenceVoltage_100ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetLowReferenceVoltage_20ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetHS1Level(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetBatteryVoltage(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetBatteryVoltage_100ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetBatteryVoltage_10ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetBatteryVoltage_20ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetBatteryVoltage_2ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetDeficiencyLevel(P2VAR(u32DeficiencyLevelType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu32DeficiencyLevel); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetMotorVn(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetMotorVn_100ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetMotorVn_20ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetMotorVp(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetMotorVp_100ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetMotorVp_20ms(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetCpuRegulatorVoltage(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetHighReferenceVoltage(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE) PMP_runGetMidReferenceVoltage(P2VAR(u16VoltageType, AUTOMATIC, RTE_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_VAR) pu16Voltage); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

#  define RTE_STOP_SEC_PMP_AC_PHYSICALMEASURESPROVIDER_APPL_CODE
#  include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#  define Rte_Call_pclAecStatus_GetAecGroupsStatus(arg1) (ERH_runGetAecGroupsStatus(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAecStatus_GetAecStatus(arg1, arg2) (ERH_runGetAecStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAutoTestCheckPowerUV_AutotestCallback(arg1) (PMP_Autotest_CheckPowerSupplyUV(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclAutotestServices_GetTestResult(arg1, arg2) (ATM_runGetTestResult(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclBelt_D_GetFromMinPos_mm(arg1) (BMM_runGetPositionFromMinPos_mm(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclBelt_D_GetFromT0_deg(arg1) (BMM_runGetPositionFromT0_deg(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclBelt_D_GetFromT0_mm(arg1) (BMM_runGetPositionFromT0_mm(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclBelt_D_GetRange_mm(arg1, arg2) (BMM_runGetPositionRange_mm(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclBelt_S_GetSpeed_deg_s(arg1) (BMM_runGetSpeed_deg_s(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclDiagRequestCycle_GetDiagRequestCycle(arg1) (DIA_runGetDiagRequestCycle(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclECU_T_GetFiltered(arg1) (PMP_runGetFilteredTemperature(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclECU_T_GetFiltered_deg(arg1) (PMP_runGetFilteredTemperature_deg(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclGND_V_Get(arg1) (PMP_runGetLowReferenceVoltage(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclGND_V_Get_100ms(arg1) (PMP_runGetLowReferenceVoltage_100ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclGND_V_Get_20ms(arg1) (PMP_runGetLowReferenceVoltage_20ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclHBS_A_V_raw_Get(arg1) (AdcIf_runGetHBS_A_V(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclHBS_A_V_raw_Get_10ms(arg1) (AdcIf_runGetHBS_A_V_10ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclHBS_B_V_raw_Get(arg1) (AdcIf_runGetHBS_B_V(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclHBS_B_V_raw_Get_10ms(arg1) (AdcIf_runGetHBS_B_V_10ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclHS1_V_Get(arg1) (PMP_runGetHS1Level(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclHS1_V_raw_Get(arg1) (AdcIf_runGetHS1_V(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclHS1_V_raw_Get_100ms(arg1) (AdcIf_runGetHS1_V_100ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclHS1_V_raw_Get_10ms(arg1) (AdcIf_runGetHS1_V_10ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclHS1_V_raw_Get_20ms(arg1) (AdcIf_runGetHS1_V_20ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_Get(arg1) (PMP_runGetBatteryVoltage(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_Get_100ms(arg1) (PMP_runGetBatteryVoltage_100ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_Get_10ms(arg1) (PMP_runGetBatteryVoltage_10ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_Get_20ms(arg1) (PMP_runGetBatteryVoltage_20ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_Get_2ms(arg1) (PMP_runGetBatteryVoltage_2ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclKL30_V_raw_Get(arg1) (AdcIf_runGetKL30_V(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclModeManagement_CheckModeStatus(arg1, arg2) (MMG_runCheckModeStatus(arg1, arg2), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_I_Get_A(arg1) (PAL_runReadMotorCurrentInA(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_I_Get_mA(arg1) (PAL_runReadMotorCurrentInmA(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_In_raw_raw_Get(arg1) (AdcIf_runGetMotor_In(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_In_raw_raw_Get_10ms(arg1) (AdcIf_runGetMotor_In_10ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Ip_raw_raw_Get(arg1) (AdcIf_runGetMotor_Ip(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Ip_raw_raw_Get_10ms(arg1) (AdcIf_runGetMotor_Ip_10ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_P_GetPowerOrder(arg1) (PAL_runGetPWMOrder(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_T_GetDeficiencyLevel(arg1) (PMP_runGetDeficiencyLevel(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vn_Get(arg1) (PMP_runGetMotorVn(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vn_Get_100ms(arg1) (PMP_runGetMotorVn_100ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vn_Get_20ms(arg1) (PMP_runGetMotorVn_20ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vp_Get(arg1) (PMP_runGetMotorVp(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vp_Get_100ms(arg1) (PMP_runGetMotorVp_100ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclMotor_Vp_Get_20ms(arg1) (PMP_runGetMotorVp_20ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclPyroDevice_GetPyroActivationStatus(arg1) (BMM_runGetPyroActivationStatus(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclREFCpuReg_V_Get(arg1) (PMP_runGetCpuRegulatorVoltage(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclREFHigh_V_Get(arg1) (PMP_runGetHighReferenceVoltage(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclREFLow_V_raw_Get(arg1) (AdcIf_runGetRefLow_V(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclREFLow_V_raw_Get_100ms(arg1) (AdcIf_runGetRefLow_V_100ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclREFLow_V_raw_Get_10ms(arg1) (AdcIf_runGetRefLow_V_10ms(arg1), ((Std_ReturnType)RTE_E_OK))
#  define Rte_Call_pclREFMid_V_Get(arg1) (PMP_runGetMidReferenceVoltage(arg1), ((Std_ReturnType)RTE_E_OK))

/**********************************************************************************************************************
 * Inter-runnable variables
 *********************************************************************************************************************/

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_CIL_runAppliToCAN_u8ActvLvlSignal() \
  Rte_Irv_CIL_u8ActvLvlSignal
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_CIL_runAppliToCAN_u8BuckleStatus() \
  Rte_Irv_CIL_u8BuckleStatus
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_CIL_runAppliToCAN_u8FctPrecond_ProfileNotImplemented() \
  Rte_Irv_CIL_u8FctPrecond_ProfileNotImplemented
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvRead_CIL_runAppliToCAN_u8RequestSource() \
  Rte_Irv_CIL_u8RequestSource
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_CIL_runCANToAppli_b8CarCrashDetected(data) \
  (Rte_Irv_CIL_b8CarCrashDetected = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_CIL_runCANToAppli_b8PreCrashRequestEnable(data) \
  (Rte_Irv_CIL_b8PreCrashRequestEnable = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_CIL_runCANToAppli_u8ActvLvlSignal(data) \
  (Rte_Irv_CIL_u8ActvLvlSignal = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_CIL_runCANToAppli_u8BuckleStatus(data) \
  (Rte_Irv_CIL_u8BuckleStatus = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_CIL_runCANToAppli_u8FctPrecond_ProfileNotImplemented(data) \
  (Rte_Irv_CIL_u8FctPrecond_ProfileNotImplemented = (data))
/* PRQA L:L1 */

/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#  define Rte_IrvWrite_CIL_runCANToAppli_u8RequestSource(data) \
  (Rte_Irv_CIL_u8RequestSource = (data))
/* PRQA L:L1 */


# endif /* !defined(RTE_CORE) */


# define CIL_AC_CommunicationInteractionLayer_START_SEC_CODE
# include "CIL_AC_CommunicationInteractionLayer_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_CIL_Autotest_Buckle_CheckTimeoutError CIL_Autotest_Buckle_CheckTimeoutError
#  define RTE_RUNNABLE_CIL_Autotest_CheckImplausibleData_API CIL_Autotest_CheckImplausibleData_API
#  define RTE_RUNNABLE_CIL_Autotest_CheckImplausibleData_Buckle CIL_Autotest_CheckImplausibleData_Buckle
#  define RTE_RUNNABLE_CIL_Autotest_CheckImplausibleData_Ignition CIL_Autotest_CheckImplausibleData_Ignition
#  define RTE_RUNNABLE_CIL_Autotest_CheckImplausibleData_ORC CIL_Autotest_CheckImplausibleData_ORC
#  define RTE_RUNNABLE_CIL_Autotest_CheckImplausibleData_PowertrainDrv CIL_Autotest_CheckImplausibleData_PowertrainDrv
#  define RTE_RUNNABLE_CIL_Autotest_CheckImplausibleData_PowertrainRdy CIL_Autotest_CheckImplausibleData_PowertrainRdy
#  define RTE_RUNNABLE_CIL_Autotest_CheckImplausibleData_Presafe CIL_Autotest_CheckImplausibleData_Presafe
#  define RTE_RUNNABLE_CIL_Autotest_CheckSteeringConfiguration CIL_Autotest_CheckSteeringConfiguration
#  define RTE_RUNNABLE_CIL_Autotest_CheckTimeoutError_API CIL_Autotest_CheckTimeoutError_API
#  define RTE_RUNNABLE_CIL_Autotest_CheckTimeoutError_BeltAdj CIL_Autotest_CheckTimeoutError_BeltAdj
#  define RTE_RUNNABLE_CIL_Autotest_CheckTimeoutError_BelthandoverL CIL_Autotest_CheckTimeoutError_BelthandoverL
#  define RTE_RUNNABLE_CIL_Autotest_CheckTimeoutError_BelthandoverR CIL_Autotest_CheckTimeoutError_BelthandoverR
#  define RTE_RUNNABLE_CIL_Autotest_CheckTimeoutError_Ignition CIL_Autotest_CheckTimeoutError_Ignition
#  define RTE_RUNNABLE_CIL_Autotest_CheckTimeoutError_OdoSpeedometer CIL_Autotest_CheckTimeoutError_OdoSpeedometer
#  define RTE_RUNNABLE_CIL_Autotest_CheckTimeoutError_Powertrain CIL_Autotest_CheckTimeoutError_Powertrain
#  define RTE_RUNNABLE_CIL_Autotest_CheckVariantCoding CIL_Autotest_CheckVariantCoding
#  define RTE_RUNNABLE_CIL_Autotest_Presafe_CheckTimeoutError CIL_Autotest_Presafe_CheckTimeoutError
#  define RTE_RUNNABLE_CIL_runAppliToCAN CIL_runAppliToCAN
#  define RTE_RUNNABLE_CIL_runCANToAppli CIL_runCANToAppli
#  define RTE_RUNNABLE_CIL_runGetInputSignalPresafeRecorderInfo CIL_runGetInputSignalPresafeRecorderInfo
#  define RTE_RUNNABLE_CIL_runManageMeasurementFrame CIL_runManageMeasurementFrame
# endif

FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_Buckle_CheckTimeoutError(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_CheckImplausibleData_API(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_CheckImplausibleData_Buckle(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_CheckImplausibleData_Ignition(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_CheckImplausibleData_ORC(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_CheckImplausibleData_PowertrainDrv(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_CheckImplausibleData_PowertrainRdy(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_CheckImplausibleData_Presafe(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_CheckSteeringConfiguration(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_CheckTimeoutError_API(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_CheckTimeoutError_BeltAdj(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_CheckTimeoutError_BelthandoverL(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_CheckTimeoutError_BelthandoverR(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_CheckTimeoutError_Ignition(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_CheckTimeoutError_OdoSpeedometer(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_CheckTimeoutError_Powertrain(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_CheckVariantCoding(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_Autotest_Presafe_CheckTimeoutError(P2VAR(u8TestResultType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pu8TestResult); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_runAppliToCAN(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_runCANToAppli(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_runGetInputSignalPresafeRecorderInfo(P2VAR(REC_PreSafeRecInputType, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) pustPreSafeRecInput); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */
FUNC(void, CIL_AC_CommunicationInteractionLayer_CODE) CIL_runManageMeasurementFrame(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

# define CIL_AC_CommunicationInteractionLayer_STOP_SEC_CODE
# include "CIL_AC_CommunicationInteractionLayer_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_H */

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

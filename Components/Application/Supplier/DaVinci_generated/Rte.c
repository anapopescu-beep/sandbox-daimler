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
 *             File:  Rte.c
 *           Config:  StartApplication.dpa
 *      ECU-Project:  StartApplication
 *
 *        Generator:  MICROSAR RTE Generator Version 4.32.0
 *                    RTE Core Version 4.32.0
 *          License:  CBD2200333
 *
 *      Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0857 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define RTE_CORE
#include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_Dir1.1, MD_Rte_Os */
#include "Rte_Type.h"
#include "Rte_Main.h"

#include "Rte_ATM_AC_AutoTestManager.h"
#include "Rte_AdcIf.h"
#include "Rte_BFE_AC_BeltFunctionExecution.h"
#include "Rte_BFS_AC_BeltFunctionSelection.h"
#include "Rte_BMM_AC_BeltMovementMonitoring.h"
#include "Rte_BSR_AC_BeltSlackReduction.h"
#include "Rte_BaseFunction.h"
#include "Rte_BeltAdjFunction.h"
#include "Rte_BeltTensionerFunction.h"
#include "Rte_BswM.h"
#include "Rte_CIL_AC_CommunicationInteractionLayer.h"
#include "Rte_Cdd_MBBL_EcuStatHandler.h"
#include "Rte_Cdd_MBBL_ResetExecutor.h"
#include "Rte_ComM.h"
#include "Rte_Csm.h"
#include "Rte_Ct_MBBL_ResetManager.h"
#include "Rte_Ct_MBBL_ResetPreconditionChecker.h"
#include "Rte_Ct_MBBL_SsaAppl_Coding.h"
#include "Rte_Ct_MBBL_SsaAppl_General.h"
#include "Rte_Ct_MBBL_SsaAppl_ProjectSpecific.h"
#include "Rte_Ct_MBBL_SsaAppl_TrustModel.h"
#include "Rte_Ct_ResourceMeasurement.h"
#include "Rte_DIA_AC_DiagOnCAN.h"
#include "Rte_Dcm.h"
#include "Rte_DemMaster_0.h"
#include "Rte_DemSatellite_0.h"
#include "Rte_Det.h"
#include "Rte_DiagFunction.h"
#include "Rte_EOL_AC_EndOfLifeManagement.h"
#include "Rte_ERH_AC_ErrorHandler.h"
#include "Rte_EcuM.h"
#include "Rte_HWA_AC_HapticWarning.h"
#include "Rte_KeyM.h"
#include "Rte_MMG_AC_ModeManagement.h"
#include "Rte_NvM.h"
#include "Rte_Os_OsCore0_swc.h"
#include "Rte_PAL_AC_PowerAbstractionLayer.h"
#include "Rte_PMP_AC_PhysicalMeasuresProvider.h"
#include "Rte_PRE_AC_PreTensioning.h"
#include "Rte_PRO_AC_ProductionCycles.h"
#include "Rte_PwmIf.h"
#include "Rte_RCM_AC_ResetCauseManagement.h"
#include "Rte_SBC.h"
#include "Rte_SCM_AC_SystemContextManagement.h"
#include "Rte_SFR_AC_StandardFunctionRecovery.h"
#include "Rte_SecOC.h"
#include "Rte_Ssa_BcTp.h"
#include "Rte_Ssa_Cdd.h"
#include "Rte_Ssa_CertP.h"
#include "Rte_Ssa_Coding.h"
#include "Rte_Ssa_FvM.h"
#include "Rte_Ssa_KeyM.h"
#include "Rte_Ssa_ProcCtrl.h"
#include "Rte_Ssa_RightsM.h"
#include "Rte_Ssa_SecLog.h"
#include "Rte_Ssa_TimeM.h"
#include "Rte_StbM_OsApplication_Trusted_Core0.h"
#include "Rte_StbM_SystemApplication_OsCore0.h"
#include "Rte_WdgM.h"
#include "SchM_Adc.h"
#include "SchM_BswM.h"
#include "SchM_Can.h"
#include "SchM_CanIf.h"
#include "SchM_CanNm.h"
#include "SchM_CanSM.h"
#include "SchM_CanTSyn.h"
#include "SchM_CanTp.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_ComXf.h"
#include "SchM_Crypto_30_LibCv.h"
#include "SchM_Crypto_30_vHsm.h"
#include "SchM_Csm.h"
#include "SchM_Dcm.h"
#include "SchM_Dem.h"
#include "SchM_Det.h"
#include "SchM_Dio.h"
#include "SchM_Dma.h"
#include "SchM_E2EXf.h"
#include "SchM_EcuM.h"
#include "SchM_Fee.h"
#include "SchM_Fls_17_Dmu.h"
#include "SchM_Gpt.h"
#include "SchM_Icu_17_TimerIp.h"
#include "SchM_IpduM.h"
#include "SchM_Irq.h"
#include "SchM_KeyM.h"
#include "SchM_McalLib.h"
#include "SchM_Mcu.h"
#include "SchM_Nm.h"
#include "SchM_NvM.h"
#include "SchM_PduR.h"
#include "SchM_Port.h"
#include "SchM_Pwm_17_GtmCcu6.h"
#include "SchM_Rtm.h"
#include "SchM_SecOC.h"
#include "SchM_Smu.h"
#include "SchM_Spi.h"
#include "SchM_StbM.h"
#include "SchM_Stm.h"
#include "SchM_WdgM.h"
#include "SchM_Wdg_17_Scu.h"

#include "Rte_Hook.h"

#include "Com.h"
#if defined(IL_ASRCOM_VERSION)
# define RTE_USE_COM_TXSIGNAL_RDACCESS
#endif

#include "Rte_Cbk.h"

#include "ComXf.h"
#include "E2EXf.h"

#if defined(COMMONASR_CANOEEMU_IMPL_COMPABSTRACT_ANSI_VERSION) || defined(COMMONASR_VTT_IMPL_COMPABSTRACT_ANSI_VERSION)
# include "CANoeApi.h"
# if defined(VTT_TIMING_BACKGROUND_TASK_TICKS)
#  define RTE_TIMING_BACKGROUND_TASK_TICKS VTT_TIMING_BACKGROUND_TASK_TICKS
# else
#  if (defined(_MSC_VER) && !defined(__PRQA__))
#   pragma message("preprocessor definition VTT_TIMING_BACKGROUND_TASK_TICKS is not defined. Using default value of 500.")
#  endif
#  define RTE_TIMING_BACKGROUND_TASK_TICKS 500
# endif
#endif

/* AUTOSAR 3.x compatibility */
#if !defined (RTE_LOCAL)
# define RTE_LOCAL static
#endif


/**********************************************************************************************************************
 * API for enable / disable interrupts global
 *********************************************************************************************************************/

#if defined(osDisableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterrupts() osDisableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterrupts() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterrupts() osEnableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterrupts() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#if defined(osDisableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterrupts() osDisableLevelKM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterrupts() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterrupts() osEnableLevelKM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterrupts() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif
#define RTE_START_SEC_CONST_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

CONST(SchM_ConfigType, RTE_CONST) Rte_Config_Left = { /* PRQA S 3408, 1533 */ /* MD_Rte_3408, MD_Rte_1533 */
  0U
};

CONST(SchM_ConfigType, RTE_CONST) Rte_Config_Right = { /* PRQA S 3408, 1533 */ /* MD_Rte_3408, MD_Rte_1533 */
  1U
};


#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

P2CONST(SchM_ConfigType, AUTOMATIC, RTE_CONST) Rte_VarCfgPtr;

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Rte Init State Variable
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_ZERO_INIT_8BIT
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_InitState = RTE_STATE_UNINIT; /* PRQA S 3408 */ /* MD_Rte_3408 */
volatile VAR(uint8, RTE_VAR_ZERO_INIT) Rte_StartTiming_InitState = RTE_STATE_UNINIT; /* PRQA S 0850, 3408, 1514 */ /* MD_MSR_MacroArgumentEmpty, MD_Rte_3408, MD_Rte_1514 */

#define RTE_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedCycle_u8CycleNumber;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8StepNumberType, RTE_VAR_NOINIT) Rte_BFE_psrExecutedStep_u8StepNumber;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_BFS_psrSelectedCycle_u8CycleNumber;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_BSR_psrAlgo_Flags_BSR_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_BSR_psrAlgo_Flags_BSR_b8PreActivationFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_BSR_psrAlgo_Flags_BSR_b8PreConditionsFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_BSR_psrAlgo_Flags_BSR_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_BSR_psrAlgo_Flags_BSR_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(c02_Off_On, RTE_VAR_NOINIT) Rte_CIL_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(c02_Off_Stage1_Stage2, RTE_VAR_NOINIT) Rte_CIL_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(c02_Presf_Disp_Rq, RTE_VAR_NOINIT) Rte_CIL_IF_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(c02_Off_Stage1_Stage2, RTE_VAR_NOINIT) Rte_CIL_P_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(c04_RBTM_ActvClient, RTE_VAR_NOINIT) Rte_CIL_P_RBTMFL_SP_ActvClient_ST35_RBTMFL_SP_ActvClient_ST35;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(c10_RBTM_Fct_Precond, RTE_VAR_NOINIT) Rte_CIL_P_RBTMFL_SP_FctPrecond_Stat_ST35_RBTMFL_SP_FctPrecond_Stat_ST35;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(c04_RBTM_ActvClient, RTE_VAR_NOINIT) Rte_CIL_P_RBTMFR_SP_ActvClient_ST35_RBTMFR_SP_ActvClient_ST35;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(c10_RBTM_Fct_Precond, RTE_VAR_NOINIT) Rte_CIL_P_RBTMFR_SP_FctPrecond_Stat_ST35_RBTMFR_SP_FctPrecond_Stat_ST35;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(c02_Presf_Disp_Rq, RTE_VAR_NOINIT) Rte_CIL_P_RBTM_FR_Disp_Rq_ST3_RBTM_FR_Disp_Rq_ST3;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(c06_RBTM_Lvl_Stat, RTE_VAR_NOINIT) Rte_CIL_RBTMFL_Actv_Lvl_ST35_RBTMFL_Actv_Lvl_ST35;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(c06_RBTM_Lvl_Stat, RTE_VAR_NOINIT) Rte_CIL_RBTMFR_Actv_Lvl_ST35_RBTMFR_Actv_Lvl_ST35;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8PreCrashSeverityLevelType, RTE_VAR_NOINIT) Rte_CIL_prrCrashSeverityLevel_u8PreCrashSeverityLevel;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8lBuckleSwitchStatusType, RTE_VAR_NOINIT) Rte_CIL_psrBuckleDoorSwitch_u8BuckleSwitch;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCANInputBlockStatus_b8NVMBlockStatus;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8IsCarAccelerationLowType, RTE_VAR_NOINIT) Rte_CIL_psrCarAcceleration_b8IsCarAccelerationLow;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8HardReleaseRequest;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8IsCarCrankingActiveType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8IsCarCrankingActive;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8IsCarCrashDetectedType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8IsCarCrashDetected;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8IsTrigOffEventAllowed;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8PreCrashRequestEnable;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_b8SignalRelInhibition;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8BeltSlackStatusType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_u8BeltSlackStatus;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8HapticRequestType, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_u8HapticRequest;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(UInt8, RTE_VAR_NOINIT) Rte_CIL_psrCustomerSpecific_u8TriggerRequest;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrEngStartStatus_b8EngStartStatus;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrExtTestPres_b8ExtTesterPresent;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrIgnitionStatus_b8TriggerIgnitionStatus;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(c04_Presf_Lvl_V2, RTE_VAR_NOINIT) Rte_CIL_psrPreSafeLvl_u8PreSafeLvl;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrProdModeStatus_b8TriggerProdModeStatus;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_CIL_psrTransportationModeStatus_b8TransportationModeStatus;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(BswM_ESH_KillAllRun, RTE_VAR_NOINIT) Rte_Cdd_MBBL_ResetExecutor_Request_ESH_KillAllRunRequest_requestedMode;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(UInt8, RTE_VAR_NOINIT) Rte_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8CodingValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(UInt8, RTE_VAR_NOINIT) Rte_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8VehicleEquipValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_DIA_psePresafeDisplay_b8TriggerPreSafeRequestStatus;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(UInt8, RTE_VAR_NOINIT) Rte_EOL_ObsolescenceDataBlockNumber_BlockNumber;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_EOL_pseExecutionCounterBlockStatus_b8NVMBlockStatus;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_ERH_psrAECsBlockStatus_b8NVMBlockStatus;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_ERH_psrDTCConfirmed_b8DTCConfirmed;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_NOINIT) Rte_ERH_psrSnapshotData_u8SnapshotAecId;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA10_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA10_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA10_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA11_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA11_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA11_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA20_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA20_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA20_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA21_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA21_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA21_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA30_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA30_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA30_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA31_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA31_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA31_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA40_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA40_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA40_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA41_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA41_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_HWA_psrAlgo_Flags_HWA41_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(UInt8, RTE_VAR_NOINIT) Rte_MMG_AvailabilityDataHandler_AvailabilityDataCategory;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle0_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle1_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle10_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle11_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle12_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle13_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle14_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle15_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle16_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle17_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle18_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle19_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle2_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle20_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle21_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle22_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle23_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle24_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle25_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle26_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle27_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle28_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle3_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle4_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle5_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle6_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle7_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle8_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_MMG_psrEnableCycle9_b8CycleValidity;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_PMP_isrSupBatStatus_b8SupBatStatus;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR1_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR1_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR1_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR2_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR2_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR2_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR3_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR3_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_BSR3_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE1_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE1_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE1_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE10_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE10_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE10_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE11_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE11_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE11_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE12_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE12_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE12_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE13_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE13_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE13_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE14_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE14_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE14_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE15_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE15_b8PreActivationFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE15_b8PreConditionsFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE15_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE15_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE16_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE16_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE16_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE17_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE17_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE17_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE18_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE18_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE18_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE2_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE2_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE2_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE3_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE3_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE3_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE4_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE4_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE4_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE5_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE5_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE5_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE6_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE6_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE6_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE7_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE7_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE7_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE8_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE8_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE8_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE9_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE9_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRE_psrAlgo_Flags_PRE9_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8IsCarAccelerationLowType, RTE_VAR_NOINIT) Rte_PRE_psrTrigOFF_b8IsCarAccelerationLow;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO1_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO1_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO1_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO2_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO2_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_PRO_psrAlgo_Flags_PRO2_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_BCK_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_BCK_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_BCK_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_HRD_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_HRD_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_HRD_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_PAT_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_PAT_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_PAT_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_SMO_b8InterruptFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8AlgorithmFlagsStatusType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_SMO_b8TriggerFlag;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8TriggeringSourceType, RTE_VAR_NOINIT) Rte_SFR_psrAlgo_Flags_SMO_u8TriggeringSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8BooleanType, RTE_VAR_NOINIT) Rte_SFR_psrBeltStackAntipatina_b8BeltStack;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Coding_VINDataType, RTE_VAR_NOINIT) Rte_Ssa_BcTp_Coding_ReceiveVIN_VIN;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_NOINIT) Rte_Ssa_BcTp_Coding_ReceiveVINTimeout_state;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Ssa_Data6ByteType, RTE_VAR_NOINIT) Rte_Ssa_BcTp_FvM_ReceiveTickCount_tickCount;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_NOINIT) Rte_Ssa_BcTp_FvM_ReceiveTickCountTimeout_state;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(KeyM_SharedSecretType, RTE_VAR_NOINIT) Rte_Ssa_BcTp_KeyM_ReceiveSharedSecret_sharedSecret;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(RightsM_AuthenticationBroadcastType, RTE_VAR_NOINIT) Rte_Ssa_BcTp_RightsM_ReceiveAuthenticationBroadcast_authentication;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(SecOC_VerificationStatusType, RTE_VAR_NOINIT) Rte_Ssa_BcTp_SecLog_MacVerificationSecureBroadcastEvent_verificationStatus;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Ssa_Data12ByteType, RTE_VAR_NOINIT) Rte_Ssa_BcTp_TimeM_ReceiveRealTimeOffset_realTimeOffset;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Ssa_LocalTickCountAndSyncStatusType, RTE_VAR_NOINIT) Rte_Ssa_FvM_FvM_SendLocalTickCountAndSyncStatus_Data;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Ssa_ChangeTickCountEventIdType, RTE_VAR_NOINIT) Rte_Ssa_FvM_SendChangeTickCountEvent_Id;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Ssa_Data5ByteType, RTE_VAR_NOINIT) Rte_Ssa_FvM_SendChangeTickCountEvent_TickCount;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_NOINIT) Rte_Ssa_ProcCtrl_ProcCtrl_DispatchServices_Sender_ServiceId;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Ssa_Data7ByteType, RTE_VAR_NOINIT) Rte_Ssa_SecLog_SecLog_EventNotification_Data;
/* PRQA L:L1 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Constants
 *********************************************************************************************************************/

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(ARR_08_UInt_noSNA_7, RTE_CONST) Rte_XDIS_6146w3b2vgdunnu49c413rpbf_ARR_08_UInt_noSNA_7 = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Coding_VINDataType, RTE_CONST) Rte_Ssa_Init_VIN_Coding_VINDataType = {
  63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(KeyM_SharedSecretType, RTE_CONST) Rte_Ssa_Init_Zero_32Byte_KeyM_SharedSecretType = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(RightsM_AuthenticationBroadcastType, RTE_CONST) Rte_Ssa_Init_Zero_20Byte_RightsM_AuthenticationBroadcastType = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Ssa_Data12ByteType, RTE_CONST) Rte_Ssa_Init_Zero_12Byte_Ssa_Data12ByteType = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Ssa_Data5ByteType, RTE_CONST) Rte_Ssa_Init_Zero_5Byte_Ssa_Data5ByteType = {
  0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Ssa_Data6ByteType, RTE_CONST) Rte_Ssa_Init_Zero_6Byte_Ssa_Data6ByteType = {
  0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Ssa_Data7ByteType, RTE_CONST) Rte_Ssa_Init_Zero_7Byte_Ssa_Data7ByteType = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Ssa_Data8ByteType, RTE_CONST) Rte_Ssa_Init_ComSignal_8Byte_Ssa_Data8ByteType = {
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx, RTE_CONST) Rte_XDIS_38xd6mxe7w4h211xfx307v7jd_REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx = {
  3U, 3U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt, RTE_CONST) Rte_XDIS_by5k2ulzqy4hav7734lki195k_REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt = {
  15U, 3U, 3U, 33522U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx, RTE_CONST) Rte_XDIS_5tgkwvedu4465t8unm4y2yblo_REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx = {
  3U, 3U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh, RTE_CONST) Rte_XDIS_6b75pabydagdo3iwsn1mn0uh1_REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh = {
  16777215U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_DPC_Md_Rq_ESP_Pr5_ST3_18cj3r9lb95cc7w4q3mwqkn86, RTE_CONST) Rte_XDIS_2akyi0yafm6v4b7rnlmtzqky2_REC_DPC_Md_Rq_ESP_Pr5_ST3_18cj3r9lb95cc7w4q3mwqkn86 = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby, RTE_CONST) Rte_XDIS_69fckmg12bk5g7417pzn53395_REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby = {
  3U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw, RTE_CONST) Rte_XDIS_7tqm5jy9oba0thvws62i3l28n_REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw = {
  3U, 3U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_Ign_Stat_Pr5_ST3, RTE_CONST) Rte_Const_Ign_Stat_InitVal_REC_Ign_Stat_Pr5_ST3 = {
  0U, 0U, 0U, 0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_Ign_Stat_Pr5_ST3_b0ko81o0x5jgvwtduf99gvzi0, RTE_CONST) Rte_XDIS_cfagkw6zyn9r952v5onwpwdur_REC_Ign_Stat_Pr5_ST3_b0ko81o0x5jgvwtduf99gvzi0 = {
  7U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96, RTE_CONST) Rte_XDIS_8ptnmozvvqneybwnb1dteqblf_REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96 = {
  7U, 0U, 20886U, 0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96, RTE_CONST) Rte_XDIS_9fnatjo7ibmc7ug14uhxholnb_REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96 = {
  7U, 0U, 20886U, 0U, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh, RTE_CONST) Rte_XDIS_6l5b88fcuqpu2imoz1fzls07a_REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh = {
  FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19, RTE_CONST) Rte_XDIS_7frhrem3wt9j2oidbosrki6rx_REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19 = {
  FALSE, FALSE, FALSE, FALSE, 11251U, 0U, FALSE, FALSE, FALSE, FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58, RTE_CONST) Rte_XDIS_ayiqyrhz0dpk9ygbqo5e5w1f7_REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58 = {
  FALSE
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_PT4_PTCoor4_Pr5_ST3_6v3sj55wsjghho72slblc9pby, RTE_CONST) Rte_XDIS_9yh6bo4rxot1fkk0920219751_REC_PT4_PTCoor4_Pr5_ST3_6v3sj55wsjghho72slblc9pby = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh, RTE_CONST) Rte_XDIS_1j2e7ey8q28fsybvpbxfqeop8_REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh = {
  0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw, RTE_CONST) Rte_XDIS_9h6oqehaueepowg2tijus0mir_REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw = {
  0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_PT4_PTCoor9_Pr5_ST3_cl82h0erzy2xfmj19jwk97p4u, RTE_CONST) Rte_XDIS_86xn4hwzmz58ui3sqboz24rhd_REC_PT4_PTCoor9_Pr5_ST3_cl82h0erzy2xfmj19jwk97p4u = {
  7U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh, RTE_CONST) Rte_XDIS_8ocy3iwo1ditemd6qwphg7b7i_REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh = {
  15U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh, RTE_CONST) Rte_XDIS_bjxptj1w89so7fpxm4dpms8ww_REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh = {
  15U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j, RTE_CONST) Rte_XDIS_1lex2znuqx5p6s5yy1dyffpdg_REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j = {
  0U, 255U, 0U, 0U, 2U, 3U, 3U, 7U, 56639U, 0U, 15U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j, RTE_CONST) Rte_XDIS_dw79s45ha1z03s9jiw4xye2p4_REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j = {
  0U, 255U, 0U, 0U, 2U, 3U, 3U, 7U, 56639U, 0U, 15U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr, RTE_CONST) Rte_XDIS_klz6op2k9wci74l4e72gktkb_REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr = {
  0U, 2U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt, RTE_CONST) Rte_XDIS_4wiqeqoz18rz4k73xcp12oii1_REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt = {
  10339U, 0U, 0U, 15U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(REC_VehSpd8_Pr5_ST3_4y11fh5xzvk3axiqy3atn5wk4, RTE_CONST) Rte_XDIS_dj45cy8ua216iwtra2tj416zq_REC_VehSpd8_Pr5_ST3_4y11fh5xzvk3axiqy3atn5wk4 = {
  255U, 19913U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SecOC_VerificationStatusType, RTE_CONST) Rte_C_SecOC_VerificationStatusType_0 = {
  0U, 1U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(SecOC_VerificationStatusType, RTE_CONST) Rte_Ssa_Init_SecOcVerificationState_SecOC_VerificationStatusType = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Ssa_IgnitionStatusType, RTE_CONST) Rte_Ssa_Init_IgnitionStatus_Ssa_IgnitionStatusType = {
  7U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Ssa_LocalTickCountAndSyncStatusType, RTE_CONST) Rte_Ssa_Init_LocalTickCountAndSyncStatus_Ssa_LocalTickCountAndSyncStatusType = {
  0ULL, 0U
};
/* PRQA L:L1 */
/* PRQA S 1514, 1533 L1 */ /* MD_Rte_1514, MD_Rte_1533 */
CONST(Ssa_OdometerRecordType, RTE_CONST) Rte_Ssa_Init_BusOdometerRecord_Ssa_OdometerRecordType = {
  16777215U
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Calibration Parameters (SW-C local and calibration component calibration parameters)
 *********************************************************************************************************************/

#define RTE_START_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_Ct_ProjectInformation_Pp_InputFileVersions_DiagnosticVariant = 2U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint8, RTE_CONST_DEFAULT_RTE_CALPRM_GROUP) Rte_Ct_ProjectInformation_Pp_InputFileVersions_DiagnosticVersion = 0U;
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_DEFAULT_RTE_CALPRM_GROUP_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(uint64, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_TimeM_NvM_TimeM_LocalTimeBase_DefaultValue = 0ULL;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Ssa_TrustModelChainState_Type, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_KeyM_NvM_KeyM_TrustModelChainOfTrustState_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Ssa_PostProductionStatusType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_RightsM_NvM_RightsM_PostProductionStatus_DefaultValue = 0U;
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(SecLog_AclVersionType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_RightsM_NvM_RightsM_AclVersion_DefaultValue = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(SecLog_CtrlDataType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_SecLog_NvM_SecLog_CtrlData_DefaultValue = {
  {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 
  0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}, {0U, 0U, 0U}
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Idt_codingData, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_Cal_CodingDataInit = {
  0U, 0U, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(Coding_StorageType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_Coding_Coding_Storage_DefaultValue = {
  {63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U, 63U}, 0U
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(RightsM_NonceType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_RightsM_NvM_RightsM_Nonce_DefaultValue = {
  {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U}, 0ULL, FALSE
};
/* PRQA L:L1 */
/* PRQA S 3408, 1514, 1533 L1 */ /* MD_Rte_3408, MD_Rte_1514, MD_Rte_1533 */
CONST(TimeM_RealTimeOffsetType, RTE_CONST_DEFAULT_RTE_CDATA_GROUP) Rte_Ssa_TimeM_NvM_TimeM_RealTimeOffset_DefaultValue = {
  0ULL, {2016U, 1U, 1U, 0U, 0U, 0U}
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_DEFAULT_RTE_CDATA_GROUP_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Per-Instance Memory
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_TrustModel_Pim_RealTime_Unix; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_FvM_LastSecuredTickCount; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_FvM_TickCount; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_TimeM_TickCount; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_TimeM_TickCountMirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(uint64, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_TimeM_TickCountValueToBeStoredToNvM; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(uint32, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Cdd_MBBL_EcuStatHandler_NetworkRepeatMessageState; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(uint16, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_EOL_PerInstanceMemory; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(uint8, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_PIM_OldCodingState; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Ssa_TrustModelChainState_Type, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_KeyM_KeyMTrustModelChainOfTrustState; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Ssa_PostProductionStatusType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMPostProductionStatus; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Ssa_PostProductionStatusType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMPostProductionStatusMirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Ssa_PostProductionStatusType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMPostProductionStatusMirror2; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Dcm_Data4092ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DiagFunction_CustomerSettings; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Dcm_Data12ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DiagFunction_DiagnosticTraceMemory; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Dcm_Data1ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DiagFunction_ISO_15675_2_BlockSize; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Dcm_Data1ByteType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_DiagFunction_ISO_15675_2_STmin; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_AclVersionType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMAclVersion; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt10_FailedPduMacVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt10_FailedPduMacVerif; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt10_FailedPduMacVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt10_FailedPduMacVerif_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt11_SecOrAuthBootType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt11_SecOrAuthBoot; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt11_SecOrAuthBootType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt11_SecOrAuthBoot_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt12_ChangeOfVinType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt12_ChangeOfVin; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt12_ChangeOfVinType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt12_ChangeOfVin_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt13_AclReplacementType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt13_AclReplacement; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt13_AclReplacementType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt13_AclReplacement_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt1_FailedCertVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt1_FailedCertVerif; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt1_FailedCertVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt1_FailedCertVerif_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt2_SucCertVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt2_SucCertVerif; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt2_SucCertVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt2_SucCertVerif_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt3_SucAuthAndEnhanceRightsType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt3_SucAuthAndEnhanceRightsType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt4_AuthBySecAccessType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt4_AuthBySecAccess; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt4_AuthBySecAccessType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt4_AuthBySecAccess_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt5_SucDiagServiceExecType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt5_SucDiagServiceExec; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt5_SucDiagServiceExecType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt5_SucDiagServiceExec_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt6_RightsMgmtType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt6_RightsMgmt; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt6_RightsMgmtType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt6_RightsMgmt_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt7_SigVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt7_SigVerif; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt7_SigVerifType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt7_SigVerif_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt8_TickCountDateAndTimeType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt8_TickCountDateAndTime; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt8_TickCountDateAndTimeType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt8_TickCountDateAndTime_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt9_SecOcMisconfigType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt9_SecOcMisconfig; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogDataEvnt9_SecOcMisconfigType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogDataEvnt9_SecOcMisconfig_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh1; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh1_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh2; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh2_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh3; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(SecLog_LogFailedMacVerifCount_ExceededThType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_SecLog_LogFailedMacVerifCount_ExceededTh3_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_BeltTensionerFunction_IgnStatBuffer; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(CalibrationIdentifications_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_CalibrationID; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(CalibrationIdentifications_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_CalibrationID_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Idt_codingData, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_PIM_CodingData; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(PreSafeCyclesLevel_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_PreSafeCyclesLevel; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(PreSafeCyclesLevel_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_PreSafeCyclesLevel_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(ReleaseCyclesBSRAndPresafe_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_ReleaseCyclesBsrAndPreSafe; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(ReleaseCyclesBSRAndPresafe_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_ReleaseCyclesBsrAndPreSafe_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(TensioningCycleBSR_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_TensioningCycleBSR; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(TensioningCycleBSR_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_TensioningCycleBSR_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(VehicleEquipment_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_VehicleEquipment; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(VehicleEquipment_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_VehicleEquipment_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(ZZZ_VehicleEquipment_Development_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_ZZZ_VehicleEquipment_Development; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(ZZZ_VehicleEquipment_Development_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ct_MBBL_SsaAppl_Coding_ZZZ_VehicleEquipment_Development_Mirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Coding_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_Coding_CodingVIN; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Coding_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_Coding_CodingVINMirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Coding_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_Coding_CurrentVIN; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(Coding_StorageType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_Coding_CurrentVINMirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(RightsM_NonceType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMNonce; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(RightsM_NonceType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_RightsM_RightsMNonceMirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(TimeM_RealTimeOffsetType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_TimeM_RealTimeOffset; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */
VAR(TimeM_RealTimeOffsetType, RTE_VAR_DEFAULT_RTE_PIM_GROUP) Rte_Ssa_TimeM_RealTimeOffsetMirror; /* PRQA S 3408, 1504, 1514, 1533 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514, MD_Rte_1533 */

#define RTE_STOP_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * TxAck/ModeSwitchAck Flags
 *********************************************************************************************************************/


#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_AckFlagsType, RTE_VAR_NOINIT) Rte_AckFlags;

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_AckFlagsInit() (Rte_MemClr(&Rte_AckFlags, sizeof(Rte_AckFlagsType)))


/**********************************************************************************************************************
 * Timeout Flags for each external Rx Signals with aliveTimeout != 0
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_RxTimeoutFlagsType, RTE_VAR_ZERO_INIT) Rte_RxTimeoutFlags = {
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U
};

#define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_RxTimeoutFlagsInit() (Rte_MemClr(&Rte_RxTimeoutFlags, sizeof(Rte_RxTimeoutFlagsType)))


/**********************************************************************************************************************
 * Update Flags for each Receiver with enableUpdate != 0
 *********************************************************************************************************************/


#define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_RxUpdateFlagsType, RTE_VAR_ZERO_INIT) Rte_RxUpdateFlags = {
  0U,
  0U,
  0U,
};

#define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define Rte_RxUpdateFlagsInit() (Rte_MemClr(&Rte_RxUpdateFlags, sizeof(Rte_RxUpdateFlagsType)))


/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(Rte_tsOsTask_ALV_BeltFunctionAlgo, RTE_VAR_NOINIT) Rte_OsTask_ALV_BeltFunctionAlgo; /* PRQA S 0759, 3408, 1514 */ /* MD_MSR_Union, MD_Rte_3408, MD_Rte_1514 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * Buffer for inter-runnable variables
 *********************************************************************************************************************/
#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(s16MotorPowerOrderType, RTE_VAR_NOINIT) Rte_Irv_BFE_s16MotorPowerOrder;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(s32OrderValueType, RTE_VAR_NOINIT) Rte_Irv_BFE_s32FirstOrderValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(s32OrderValueType, RTE_VAR_NOINIT) Rte_Irv_BFE_s32OrderIncrementValue;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u16StepDurationType, RTE_VAR_NOINIT) Rte_Irv_BFE_u16StepDuration;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8MotorStageStatusType, RTE_VAR_NOINIT) Rte_Irv_BFE_u8MotorStageStatus;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8OrdersListType, RTE_VAR_NOINIT) Rte_Irv_BFE_u8OrderType;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8VelocityTargetType, RTE_VAR_NOINIT) Rte_Irv_BFE_u8VelocityTarget;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint16, RTE_VAR_NOINIT) Rte_Irv_BaseFunction_NmTimer;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(b8IsCarCrashDetectedType, RTE_VAR_NOINIT) Rte_Irv_CIL_b8CarCrashDetected;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(UInt8, RTE_VAR_NOINIT) Rte_Irv_CIL_b8PreCrashRequestEnable;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_NOINIT) Rte_Irv_CIL_u8ActvLvlSignal;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8lBuckleSwitchStatusType, RTE_VAR_NOINIT) Rte_Irv_CIL_u8BuckleStatus;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(UInt8, RTE_VAR_NOINIT) Rte_Irv_CIL_u8FctPrecond_ProfileNotImplemented;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_NOINIT) Rte_Irv_CIL_u8RequestSource;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_Irv_DIA_u8DiagRequestedCycle;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(UInt8, RTE_VAR_NOINIT) Rte_Irv_MMG_b8PreSafeRecorder1Update;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(UInt8, RTE_VAR_NOINIT) Rte_Irv_MMG_b8PreSafeRecorder2Update;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u32DeficiencyLevelType, RTE_VAR_NOINIT) Rte_Irv_PMP_u32DeficiencyLevel;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u32ResetCauseType, RTE_VAR_NOINIT) Rte_Irv_RCM_u8ResetCause;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_Irv_SCM_u8CurrentTensioningState;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(u8CycleNumberType, RTE_VAR_NOINIT) Rte_Irv_SCM_u8LastTensioningSituation;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(uint8, RTE_VAR_NOINIT) Rte_Irv_Ssa_FvM_FvM_IrvCountUpSecTimeMsg;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(boolean, RTE_VAR_NOINIT) Rte_Irv_Ssa_FvM_FvM_IrvFirstTickCountMessageAfterStartUpReceived;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Ssa_TickCountSyncStateType, RTE_VAR_NOINIT) Rte_Irv_Ssa_FvM_FvM_IrvTickCountSyncState;
/* PRQA L:L1 */
/* PRQA S 3408, 1504, 1514 L1 */ /* MD_Rte_3408, MD_MSR_Rule8.7, MD_Rte_1514 */
VAR(Ssa_TickCountSyncStateType, RTE_VAR_NOINIT) Rte_Irv_Ssa_TimeM_TimeM_IrvTickCountSyncState;
/* PRQA L:L1 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 * RTE internal IOC replacements
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint8, RTE_VAR_INIT) Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Queue[1] = { RTE_MODE_Dcm_DcmDiagnosticSessionControl_DEFAULT_SESSION }; /* PRQA S 1514 */ /* MD_Rte_1514 */

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint8, RTE_VAR_INIT) Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_tail = 1;

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_head = 0;

#define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint8, RTE_VAR_NOINIT) Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_Queue[1]; /* PRQA S 1514 */ /* MD_Rte_1514 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint8, RTE_VAR_INIT) Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail = 0;

#define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define RTE_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

VAR(uint8, RTE_VAR_ZERO_INIT) Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head = 0;

#define RTE_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define RTE_START_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num); /* PRQA S 1505, 3408 */ /* MD_MSR_Rule8.7, MD_Rte_3408 */
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num); /* PRQA S 1505, 3408 */ /* MD_MSR_Rule8.7, MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_BswM_CommunicationMode(uint8 mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_BswM_ESH_Mode(BswM_ESH_Mode mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmControlDtcSetting(Dcm_ControlDtcSettingType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmEcuReset(Dcm_EcuResetType mode); /* PRQA S 3408 */ /* MD_Rte_3408 */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define RTE_START_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Helper functions for mode management
 *********************************************************************************************************************/
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_BswM_CommunicationMode(uint8 mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 1U;
  }
  else if (mode == 1U)
  {
    ret = 2U;
  }
  else if (mode == 2U)
  {
    ret = 0U;
  }
  else
  {
    ret = 3U;
  }

  return ret;
}

/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_BswM_ESH_Mode(BswM_ESH_Mode mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 3U;
  }
  else if (mode == 1U)
  {
    ret = 1U;
  }
  else if (mode == 2U)
  {
    ret = 0U;
  }
  else if (mode == 3U)
  {
    ret = 4U;
  }
  else if (mode == 4U)
  {
    ret = 2U;
  }
  else
  {
    ret = 5U;
  }

  return ret;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmControlDtcSetting(Dcm_ControlDtcSettingType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 1U;
  }
  else if (mode == 1U)
  {
    ret = 0U;
  }
  else
  {
    ret = 2U;
  }

  return ret;
}

FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 1U)
  {
    ret = 0U;
  }
  else if (mode == 2U)
  {
    ret = 3U;
  }
  else if (mode == 3U)
  {
    ret = 2U;
  }
  else if (mode == 126U)
  {
    ret = 1U;
  }
  else
  {
    ret = 4U;
  }

  return ret;
}

/* PRQA S 6080 1 */ /* MD_MSR_STMIF */
FUNC(uint8, RTE_CODE) Rte_GetInternalModeIndex_Dcm_DcmEcuReset(Dcm_EcuResetType mode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 ret;

  if (mode == 0U)
  {
    ret = 5U;
  }
  else if (mode == 1U)
  {
    ret = 1U;
  }
  else if (mode == 2U)
  {
    ret = 4U;
  }
  else if (mode == 3U)
  {
    ret = 6U;
  }
  else if (mode == 4U)
  {
    ret = 2U;
  }
  else if (mode == 5U)
  {
    ret = 3U;
  }
  else if (mode == 6U)
  {
    ret = 0U;
  }
  else
  {
    ret = 7U;
  }

  return ret;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Data structures for mode management
 *********************************************************************************************************************/

VAR(uint8, RTE_VAR_NOINIT) Rte_ModeMachine_BswM_Switch_BswMSwitchPort_SwcDiagCommunicationMode_Mode; /* PRQA S 3408 */ /* MD_Rte_3408 */
VAR(BswM_ESH_Mode, RTE_VAR_NOINIT) Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode; /* PRQA S 3408 */ /* MD_Rte_3408 */

VAR(Dcm_ControlDtcSettingType, RTE_VAR_NOINIT) Rte_ModeMachine_Dcm_DcmControlDtcSetting_DcmControlDtcSetting; /* PRQA S 3408 */ /* MD_Rte_3408 */
VAR(Dcm_DiagnosticSessionControlType, RTE_VAR_NOINIT) Rte_ModeMachine_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl; /* PRQA S 3408 */ /* MD_Rte_3408 */
VAR(Dcm_EcuResetType, RTE_VAR_NOINIT) Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset; /* PRQA S 3408 */ /* MD_Rte_3408 */

VAR(EcuM_StateType, RTE_VAR_NOINIT) Rte_ModeMachine_EcuM_currentMode_currentMode; /* PRQA S 3408 */ /* MD_Rte_3408 */

VAR(Coding_ModeType, RTE_VAR_NOINIT) Rte_ModeMachine_Ssa_Coding_Coding_Mode_CodingStatus; /* PRQA S 3408 */ /* MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#if defined OS_US2TICKS_SystemTimer
# define RTE_USEC_SystemTimer OS_US2TICKS_SystemTimer
#else
# define RTE_USEC_SystemTimer(val) ((TickType)RTE_CONST_USEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_MS2TICKS_SystemTimer
# define RTE_MSEC_SystemTimer OS_MS2TICKS_SystemTimer
#else
# define RTE_MSEC_SystemTimer(val) ((TickType)RTE_CONST_MSEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#if defined OS_SEC2TICKS_SystemTimer
# define RTE_SEC_SystemTimer OS_SEC2TICKS_SystemTimer
#else
# define RTE_SEC_SystemTimer(val)  ((TickType)RTE_CONST_SEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_MSR_Rule20.10_0342 */
#endif

#define RTE_CONST_MSEC_SystemTimer_0U (0UL)
#define RTE_CONST_MSEC_SystemTimer_1U (1UL)
#define RTE_CONST_MSEC_SystemTimer_10U (10UL)
#define RTE_CONST_MSEC_SystemTimer_100U (100UL)
#define RTE_CONST_MSEC_SystemTimer_2U (2UL)
#define RTE_CONST_MSEC_SystemTimer_20U (20UL)
#define RTE_CONST_MSEC_SystemTimer_3U (3UL)
#define RTE_CONST_MSEC_SystemTimer_5U (5UL)
#define RTE_CONST_MSEC_SystemTimer_50U (50UL)

#define RTE_CONST_SEC_SystemTimer_0U (0UL)
#define RTE_CONST_SEC_SystemTimer_1U (1000UL)


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)

/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num) /* PRQA S 3408, 1505 */ /* MD_Rte_3408, MD_MSR_Rule8.7 */
{
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA)) source; /* PRQA S 0316 */ /* MD_Rte_0316 */
  P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR) dst = (P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR)) destination; /* PRQA S 0316 */ /* MD_Rte_0316 */
  uint32_least i;
  for (i = 0; i < num; i++) /* FETA_RTE_MEMCPY */
  {
    dst[i] = src[i];
  }
}

#define RTE_MEMCPY32ALIGN (sizeof(uint32) - 1U)

FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_VAR) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num)
{
  P2CONST(uint32, AUTOMATIC, RTE_APPL_DATA) asrc = (P2CONST(uint32, AUTOMATIC, RTE_APPL_DATA)) source; /* PRQA S 0316 */ /* MD_Rte_0316 */
  P2VAR(uint32, AUTOMATIC, RTE_APPL_VAR) adst = (P2VAR(uint32, AUTOMATIC, RTE_APPL_VAR)) destination; /* PRQA S 0316 */ /* MD_Rte_0316 */
  P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA)) source; /* PRQA S 0316 */ /* MD_Rte_0316 */
  P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR) dst = (P2VAR(uint8, AUTOMATIC, RTE_APPL_VAR)) destination; /* PRQA S 0316 */ /* MD_Rte_0316 */
  uint32_least i = 0;

  if (num >= 16U)
  {
    if (((((uint32)src) & RTE_MEMCPY32ALIGN) == 0U) && ((((uint32)dst) & RTE_MEMCPY32ALIGN) == 0U)) /* PRQA S 0306 */ /* MD_Rte_0306 */
    {
      uint32_least asize = num / sizeof(uint32);
      uint32_least rem = num & RTE_MEMCPY32ALIGN;
      for (i = 0; i < (asize - 3U); i += 4U) /* FETA_RTE_MEMCPY32 */
      {
        adst[i] = asrc[i];
        adst[i+1U] = asrc[i+1U];
        adst[i+2U] = asrc[i+2U];
        adst[i+3U] = asrc[i+3U];
      }

      while (i < asize) /* FETA_RTE_MEMCPY32 */
      {
        adst[i] = asrc[i];
        ++i;
      }
      i = num - rem;
    }
    else
    {
      for (i = 0; (i + 15U) < num; i += 16U) /* FETA_RTE_MEMCPY32 */
      {
        dst[i] = src[i];
        dst[i+1U] = src[i+1U];
        dst[i+2U] = src[i+2U];
        dst[i+3U] = src[i+3U];
        dst[i+4U] = src[i+4U];
        dst[i+5U] = src[i+5U];
        dst[i+6U] = src[i+6U];
        dst[i+7U] = src[i+7U];
        dst[i+8U] = src[i+8U];
        dst[i+9U] = src[i+9U];
        dst[i+10U] = src[i+10U];
        dst[i+11U] = src[i+11U];
        dst[i+12U] = src[i+12U];
        dst[i+13U] = src[i+13U];
        dst[i+14U] = src[i+14U];
        dst[i+15U] = src[i+15U];
      }
    }

  }
  while (i < num) /* FETA_RTE_MEMCPY32 */
  {
    dst[i] = src[i];
    ++i;
  }
}

FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint32_least num)
{
  P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT) dst = (P2VAR(uint8, AUTOMATIC, RTE_VAR_NOINIT))ptr; /* PRQA S 0316 */ /* MD_Rte_0316 */
  uint32_least i;
  for (i = 0; i < num; i++) /* FETA_RTE_MEMCLR */
  {
    dst[i] = 0;
  }
}

FUNC(Rte_EventMaskType, RTE_CODE) Rte_GetModeExitEventMask_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType mode)
{
  Rte_EventMaskType eventMask;
  switch (mode)
  {
    case 2U:
      eventMask = Rte_Ev_Run_Cdd_MBBL_EcuStatHandler_DiagSessionChange_ExitExtendedSession; /* EXTENDED_SESSION */
      break;
    default: /* COV_RTE_MISRA */
      eventMask = (Rte_EventMaskType)0U;
      break;
  }

  return eventMask;
}

FUNC(Rte_EventMaskType, RTE_CODE) Rte_GetModeEntryEventMask_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType mode)
{
  Rte_EventMaskType eventMask;
  switch (mode)
  {
    case 0U:
      eventMask = Rte_Ev_Run_Ssa_RightsM_Ssa_RightsM_DiagnosticSessionChangeIndication; /* DEFAULT_SESSION */
      break;
    case 2U:
      eventMask = Rte_Ev_OnEntry_ApplTask_Core0_LowPrio_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_EXTENDED_SESSION; /* EXTENDED_SESSION */
      break;
    default: /* COV_RTE_MISRA */
      eventMask = (Rte_EventMaskType)0U;
      break;
  }

  return eventMask;
}

FUNC(Rte_EventMaskType, RTE_CODE) Rte_GetModeEntryEventMask_Dcm_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType mode)
{
  Rte_EventMaskType eventMask;
  switch (mode)
  {
    case 0U:
      eventMask = Rte_Ev_Run_Ct_MBBL_ResetManager_ResetServiceExecution; /* EXECUTE */
      break;
    case 1U:
      eventMask = Rte_Ev_Run_Ct_MBBL_ResetManager_ResetServiceExecution; /* HARD */
      break;
    case 2U:
      eventMask = Rte_Ev_Run_Ct_MBBL_ResetManager_ResetServiceExecution; /* JUMPTOBOOTLOADER */
      break;
    case 3U:
      eventMask = Rte_Ev_Run_Ct_MBBL_ResetManager_ResetServiceExecution; /* JUMPTOSYSSUPPLIERBOOTLOADER */
      break;
    case 6U:
      eventMask = Rte_Ev_Run_Ct_MBBL_ResetManager_ResetServiceExecution; /* SOFT */
      break;
    default: /* COV_RTE_MISRA */
      eventMask = (Rte_EventMaskType)0U;
      break;
  }

  return eventMask;
}

FUNC(void, RTE_CODE) SchM_Start(void)
{
  Rte_InitState = RTE_STATE_SCHM_START;
}

FUNC(void, RTE_CODE) SchM_Init(P2CONST(SchM_ConfigType, AUTOMATIC, RTE_CONST) ConfigPtr)
{
  Rte_VarCfgPtr = ConfigPtr;
  /* activate the tasks */
  (void)ActivateTask(BackgroundTask_Core0); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(BswTask_Core0_HighPrio); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(BswTask_Core0_LowPrio); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_SCHM_INIT;
}

FUNC(void, RTE_CODE) SchM_StartTiming(void)
{
  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE2_BswTask_Core0_HighPrio_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_BswTask_Core0_HighPrio_0_3ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(3U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_BswTask_Core0_HighPrio_0_5ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(5U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_BswTask_Core0_LowPrio_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_BswTask_Core0_LowPrio_0_5ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(5U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */

}

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void)
{
  /* set default values for internal data */
  Rte_BFE_psrExecutedCycle_u8CycleNumber = 255U;
  Rte_BFE_psrExecutedStep_u8StepNumber = 255U;
  Rte_BFS_psrSelectedCycle_u8CycleNumber = 255U;
  Rte_BSR_psrAlgo_Flags_BSR_b8InterruptFlag = 85U;
  Rte_BSR_psrAlgo_Flags_BSR_b8PreActivationFlag = 85U;
  Rte_BSR_psrAlgo_Flags_BSR_b8PreConditionsFlag = 85U;
  Rte_BSR_psrAlgo_Flags_BSR_b8TriggerFlag = 85U;
  Rte_BSR_psrAlgo_Flags_BSR_u8TriggeringSource = 0U;
  Rte_CIL_prrCrashSeverityLevel_u8PreCrashSeverityLevel = 255U;
  Rte_CIL_psrBuckleDoorSwitch_u8BuckleSwitch = 255U;
  Rte_CIL_psrCANInputBlockStatus_b8NVMBlockStatus = 85U;
  Rte_CIL_psrCarAcceleration_b8IsCarAccelerationLow = 170U;
  Rte_CIL_psrCustomerSpecific_b8HardReleaseRequest = 85U;
  Rte_CIL_psrCustomerSpecific_b8IsCarCrankingActive = 170U;
  Rte_CIL_psrCustomerSpecific_b8IsCarCrashDetected = 85U;
  Rte_CIL_psrCustomerSpecific_b8IsTrigOffEventAllowed = 85U;
  Rte_CIL_psrCustomerSpecific_b8PreCrashRequestEnable = 85U;
  Rte_CIL_psrCustomerSpecific_b8SignalRelInhibition = 85U;
  Rte_CIL_psrCustomerSpecific_u8BeltSlackStatus = 2U;
  Rte_CIL_psrCustomerSpecific_u8HapticRequest = 8U;
  Rte_CIL_psrCustomerSpecific_u8TriggerRequest = 255U;
  Rte_CIL_psrEngStartStatus_b8EngStartStatus = 85U;
  Rte_CIL_psrExtTestPres_b8ExtTesterPresent = 85U;
  Rte_CIL_psrIgnitionStatus_b8TriggerIgnitionStatus = 85U;
  Rte_CIL_psrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition = 85U;
  Rte_CIL_psrPreSafeLvl_u8PreSafeLvl = 0U;
  Rte_CIL_psrProdModeStatus_b8TriggerProdModeStatus = 170U;
  Rte_CIL_psrTransportationModeStatus_b8TransportationModeStatus = 170U;
  Rte_Cdd_MBBL_ResetExecutor_Request_ESH_KillAllRunRequest_requestedMode = 0U;
  Rte_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8CodingValidity = 85U;
  Rte_Ct_MBBL_SsaAppl_Coding_psrVariantCodingValidity_u8VehicleEquipValidity = 85U;
  Rte_DIA_psePresafeDisplay_b8TriggerPreSafeRequestStatus = 85U;
  Rte_EOL_ObsolescenceDataBlockNumber_BlockNumber = 0U;
  Rte_EOL_pseExecutionCounterBlockStatus_b8NVMBlockStatus = 85U;
  Rte_ERH_psrAECsBlockStatus_b8NVMBlockStatus = 85U;
  Rte_ERH_psrDTCConfirmed_b8DTCConfirmed = 85U;
  Rte_ERH_psrSnapshotData_u8SnapshotAecId = 255U;
  Rte_HWA_psrAlgo_Flags_HWA10_b8InterruptFlag = 85U;
  Rte_HWA_psrAlgo_Flags_HWA10_b8TriggerFlag = 85U;
  Rte_HWA_psrAlgo_Flags_HWA10_u8TriggeringSource = 0U;
  Rte_HWA_psrAlgo_Flags_HWA11_b8InterruptFlag = 85U;
  Rte_HWA_psrAlgo_Flags_HWA11_b8TriggerFlag = 85U;
  Rte_HWA_psrAlgo_Flags_HWA11_u8TriggeringSource = 0U;
  Rte_HWA_psrAlgo_Flags_HWA20_b8InterruptFlag = 85U;
  Rte_HWA_psrAlgo_Flags_HWA20_b8TriggerFlag = 85U;
  Rte_HWA_psrAlgo_Flags_HWA20_u8TriggeringSource = 0U;
  Rte_HWA_psrAlgo_Flags_HWA21_b8InterruptFlag = 85U;
  Rte_HWA_psrAlgo_Flags_HWA21_b8TriggerFlag = 85U;
  Rte_HWA_psrAlgo_Flags_HWA21_u8TriggeringSource = 0U;
  Rte_HWA_psrAlgo_Flags_HWA30_b8InterruptFlag = 85U;
  Rte_HWA_psrAlgo_Flags_HWA30_b8TriggerFlag = 85U;
  Rte_HWA_psrAlgo_Flags_HWA30_u8TriggeringSource = 0U;
  Rte_HWA_psrAlgo_Flags_HWA31_b8InterruptFlag = 85U;
  Rte_HWA_psrAlgo_Flags_HWA31_b8TriggerFlag = 85U;
  Rte_HWA_psrAlgo_Flags_HWA31_u8TriggeringSource = 0U;
  Rte_HWA_psrAlgo_Flags_HWA40_b8InterruptFlag = 85U;
  Rte_HWA_psrAlgo_Flags_HWA40_b8TriggerFlag = 85U;
  Rte_HWA_psrAlgo_Flags_HWA40_u8TriggeringSource = 0U;
  Rte_HWA_psrAlgo_Flags_HWA41_b8InterruptFlag = 85U;
  Rte_HWA_psrAlgo_Flags_HWA41_b8TriggerFlag = 85U;
  Rte_HWA_psrAlgo_Flags_HWA41_u8TriggeringSource = 0U;
  Rte_MMG_AvailabilityDataHandler_AvailabilityDataCategory = 0U;
  Rte_MMG_psrEnableCycle0_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle1_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle10_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle11_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle12_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle13_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle14_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle15_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle16_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle17_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle18_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle19_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle2_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle20_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle21_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle22_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle23_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle24_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle25_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle26_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle27_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle28_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle3_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle4_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle5_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle6_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle7_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle8_b8CycleValidity = 85U;
  Rte_MMG_psrEnableCycle9_b8CycleValidity = 85U;
  Rte_PMP_isrSupBatStatus_b8SupBatStatus = 85U;
  Rte_PRE_psrAlgo_Flags_BSR1_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_BSR1_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_BSR1_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_BSR2_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_BSR2_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_BSR2_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_BSR3_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_BSR3_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_BSR3_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE1_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE1_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE1_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE10_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE10_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE10_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE11_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE11_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE11_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE12_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE12_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE12_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE13_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE13_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE13_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE14_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE14_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE14_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE15_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE15_b8PreActivationFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE15_b8PreConditionsFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE15_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE15_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE16_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE16_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE16_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE17_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE17_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE17_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE18_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE18_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE18_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE2_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE2_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE2_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE3_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE3_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE3_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE4_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE4_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE4_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE5_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE5_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE5_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE6_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE6_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE6_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE7_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE7_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE7_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE8_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE8_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE8_u8TriggeringSource = 0U;
  Rte_PRE_psrAlgo_Flags_PRE9_b8InterruptFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE9_b8TriggerFlag = 85U;
  Rte_PRE_psrAlgo_Flags_PRE9_u8TriggeringSource = 0U;
  Rte_PRE_psrTrigOFF_b8IsCarAccelerationLow = 170U;
  Rte_PRO_psrAlgo_Flags_PRO1_b8InterruptFlag = 85U;
  Rte_PRO_psrAlgo_Flags_PRO1_b8TriggerFlag = 85U;
  Rte_PRO_psrAlgo_Flags_PRO1_u8TriggeringSource = 0U;
  Rte_PRO_psrAlgo_Flags_PRO2_b8InterruptFlag = 85U;
  Rte_PRO_psrAlgo_Flags_PRO2_b8TriggerFlag = 85U;
  Rte_PRO_psrAlgo_Flags_PRO2_u8TriggeringSource = 0U;
  Rte_SFR_psrAlgo_Flags_BCK_b8InterruptFlag = 85U;
  Rte_SFR_psrAlgo_Flags_BCK_b8TriggerFlag = 85U;
  Rte_SFR_psrAlgo_Flags_BCK_u8TriggeringSource = 0U;
  Rte_SFR_psrAlgo_Flags_HRD_b8InterruptFlag = 85U;
  Rte_SFR_psrAlgo_Flags_HRD_b8TriggerFlag = 85U;
  Rte_SFR_psrAlgo_Flags_HRD_u8TriggeringSource = 0U;
  Rte_SFR_psrAlgo_Flags_PAT_b8InterruptFlag = 85U;
  Rte_SFR_psrAlgo_Flags_PAT_b8TriggerFlag = 85U;
  Rte_SFR_psrAlgo_Flags_PAT_u8TriggeringSource = 0U;
  Rte_SFR_psrAlgo_Flags_SMO_b8InterruptFlag = 85U;
  Rte_SFR_psrAlgo_Flags_SMO_b8TriggerFlag = 85U;
  Rte_SFR_psrAlgo_Flags_SMO_u8TriggeringSource = 0U;
  Rte_SFR_psrBeltStackAntipatina_b8BeltStack = 0U;
  Rte_MemCpy32(Rte_Ssa_BcTp_Coding_ReceiveVIN_VIN, Rte_Ssa_Init_VIN_Coding_VINDataType, sizeof(Coding_VINDataType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_Ssa_BcTp_Coding_ReceiveVINTimeout_state = 0U;
  Rte_MemCpy(Rte_Ssa_BcTp_FvM_ReceiveTickCount_tickCount, Rte_Ssa_Init_Zero_6Byte_Ssa_Data6ByteType, sizeof(Ssa_Data6ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_Ssa_BcTp_FvM_ReceiveTickCountTimeout_state = 0U;
  Rte_MemCpy32(Rte_Ssa_BcTp_KeyM_ReceiveSharedSecret_sharedSecret, Rte_Ssa_Init_Zero_32Byte_KeyM_SharedSecretType, sizeof(KeyM_SharedSecretType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_MemCpy32(Rte_Ssa_BcTp_RightsM_ReceiveAuthenticationBroadcast_authentication, Rte_Ssa_Init_Zero_20Byte_RightsM_AuthenticationBroadcastType, sizeof(RightsM_AuthenticationBroadcastType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_Ssa_BcTp_SecLog_MacVerificationSecureBroadcastEvent_verificationStatus = Rte_Ssa_Init_SecOcVerificationState_SecOC_VerificationStatusType;
  Rte_MemCpy(Rte_Ssa_BcTp_TimeM_ReceiveRealTimeOffset_realTimeOffset, Rte_Ssa_Init_Zero_12Byte_Ssa_Data12ByteType, sizeof(Ssa_Data12ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_Ssa_FvM_FvM_SendLocalTickCountAndSyncStatus_Data = Rte_Ssa_Init_LocalTickCountAndSyncStatus_Ssa_LocalTickCountAndSyncStatusType;
  Rte_Ssa_FvM_SendChangeTickCountEvent_Id = 4U;
  Rte_MemCpy(Rte_Ssa_FvM_SendChangeTickCountEvent_TickCount, Rte_Ssa_Init_Zero_5Byte_Ssa_Data5ByteType, sizeof(Ssa_Data5ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_Ssa_ProcCtrl_ProcCtrl_DispatchServices_Sender_ServiceId = 0U;
  Rte_MemCpy(Rte_Ssa_SecLog_SecLog_EventNotification_Data, Rte_XDIS_6146w3b2vgdunnu49c413rpbf_ARR_08_UInt_noSNA_7, sizeof(Ssa_Data7ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  Rte_CIL_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3 = 3U;
  Rte_CIL_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3 = 3U;
  Rte_CIL_IF_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3 = 0U;
  Rte_CIL_P_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3 = 3U;
  Rte_CIL_P_RBTMFL_SP_ActvClient_ST35_RBTMFL_SP_ActvClient_ST35 = 0U;
  Rte_CIL_P_RBTMFL_SP_FctPrecond_Stat_ST35_RBTMFL_SP_FctPrecond_Stat_ST35 = 0U;
  Rte_CIL_P_RBTMFR_SP_ActvClient_ST35_RBTMFR_SP_ActvClient_ST35 = 0U;
  Rte_CIL_P_RBTMFR_SP_FctPrecond_Stat_ST35_RBTMFR_SP_FctPrecond_Stat_ST35 = 0U;
  Rte_CIL_P_RBTM_FR_Disp_Rq_ST3_RBTM_FR_Disp_Rq_ST3 = 0U;
  Rte_CIL_RBTMFL_Actv_Lvl_ST35_RBTMFL_Actv_Lvl_ST35 = 63U;
  Rte_CIL_RBTMFR_Actv_Lvl_ST35_RBTMFR_Actv_Lvl_ST35 = 63U;

  /* reset Tx Ack Flags */
  Rte_AckFlagsInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */
  Rte_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack = 1U;
  Rte_AckFlags.Rte_ModeSwitchAck_EcuM_currentMode_currentMode_Ack = 1U;

  /* initialize inter-runnable variables */
  Rte_Irv_BFE_s16MotorPowerOrder = 0;
  Rte_Irv_BFE_s32FirstOrderValue = 0;
  Rte_Irv_BFE_s32OrderIncrementValue = 0;
  Rte_Irv_BFE_u16StepDuration = 0U;
  Rte_Irv_BFE_u8MotorStageStatus = 170U;
  Rte_Irv_BFE_u8OrderType = 0U;
  Rte_Irv_BFE_u8VelocityTarget = 0U;
  Rte_Irv_BaseFunction_NmTimer = 0U;
  Rte_Irv_CIL_b8CarCrashDetected = 85U;
  Rte_Irv_CIL_b8PreCrashRequestEnable = 85U;
  Rte_Irv_CIL_u8ActvLvlSignal = 0U;
  Rte_Irv_CIL_u8BuckleStatus = 2U;
  Rte_Irv_CIL_u8FctPrecond_ProfileNotImplemented = 0U;
  Rte_Irv_CIL_u8RequestSource = 15U;
  Rte_Irv_DIA_u8DiagRequestedCycle = 255U;
  Rte_Irv_MMG_b8PreSafeRecorder1Update = 85U;
  Rte_Irv_MMG_b8PreSafeRecorder2Update = 85U;
  Rte_Irv_PMP_u32DeficiencyLevel = 0U;
  Rte_Irv_RCM_u8ResetCause = 0U;
  Rte_Irv_SCM_u8CurrentTensioningState = 255U;
  Rte_Irv_SCM_u8LastTensioningSituation = 255U;
  Rte_Irv_Ssa_FvM_FvM_IrvCountUpSecTimeMsg = 0U;
  Rte_Irv_Ssa_FvM_FvM_IrvFirstTickCountMessageAfterStartUpReceived = FALSE;
  Rte_Irv_Ssa_FvM_FvM_IrvTickCountSyncState = 0U;
  Rte_Irv_Ssa_TimeM_TimeM_IrvTickCountSyncState = 0U;

  /* mode management initialization part 1 */

  Rte_ModeMachine_BswM_Switch_BswMSwitchPort_SwcDiagCommunicationMode_Mode = RTE_MODE_BswM_CommunicationMode_COMM_NO_COMMUNICATION;

  Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_BswM_ESH_Mode_STARTUP;

  Rte_ModeMachine_Dcm_DcmControlDtcSetting_DcmControlDtcSetting = RTE_MODE_Dcm_DcmControlDtcSetting_ENABLEDTCSETTING;

  Rte_ModeMachine_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl = RTE_MODE_Dcm_DcmDiagnosticSessionControl_DEFAULT_SESSION;

  Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset = RTE_MODE_Dcm_DcmEcuReset_NONE;

  Rte_ModeMachine_EcuM_currentMode_currentMode = RTE_MODE_EcuM_EcuM_Mode_STARTUP;

  Rte_ModeMachine_Ssa_Coding_Coding_Mode_CodingStatus = RTE_MODE_Ssa_Coding_Coding_Mode_CODING_OK;

  /* activate the tasks */
  (void)ActivateTask(ApplInitTask_Core0); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(ApplTask_Core0_HighPrio); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(ApplTask_Core0_LowPrio); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(OsTask_ALV_BeltFunctionAlgo); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE_SBC_SBC_MainFunction, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_AdcIf_AdcIf_MainFunction, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(1U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_BFE_BFE_runExecuteStandardSteps, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(2U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_OsTask_ALV_BeltFunctionAlgo_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_ApplTask_Core0_LowPrio_0_100ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(100U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_ApplTask_Core0_LowPrio_0_10ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(10U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_ApplTask_Core0_LowPrio_0_2ms, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(2U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_BaseFunction_BaseFunction_Main, RTE_SEC_SystemTimer(0U) + (TickType)1U, RTE_SEC_SystemTimer(1U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_DIA_DIA_cyclicProcessingTask, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(50U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_DiagFunction_DiagFunction_MainFunction, RTE_MSEC_SystemTimer(0U) + (TickType)1U, RTE_MSEC_SystemTimer(20U)); /* PRQA S 3417, 1840 */ /* MD_Rte_Os, MD_Rte_Os */

  Rte_StartTiming_InitState = RTE_STATE_INIT;
  /* mode management initialization part 2 */
  (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_Ssa_RightsM_Ssa_RightsM_DiagnosticSessionChangeIndication); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_INIT;

  return RTE_E_OK;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void)
{
  Rte_StartTiming_InitState = RTE_STATE_UNINIT;
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE_ApplTask_Core0_LowPrio_0_100ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_ApplTask_Core0_LowPrio_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_ApplTask_Core0_LowPrio_0_2ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_BaseFunction_BaseFunction_Main); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_DIA_DIA_cyclicProcessingTask); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_DiagFunction_DiagFunction_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_SBC_SBC_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_AdcIf_AdcIf_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_BFE_BFE_runExecuteStandardSteps); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_OsTask_ALV_BeltFunctionAlgo_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_SCHM_INIT;

  return RTE_E_OK;
}

FUNC(void, RTE_CODE) SchM_Deinit(void)
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE2_BswTask_Core0_HighPrio_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_BswTask_Core0_HighPrio_0_3ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_BswTask_Core0_HighPrio_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_BswTask_Core0_LowPrio_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_BswTask_Core0_LowPrio_0_5ms); /* PRQA S 3417 */ /* MD_Rte_Os */

  Rte_InitState = RTE_STATE_UNINIT;
}

FUNC(void, RTE_CODE) Rte_InitMemory(void)
{
  Rte_InitState = RTE_STATE_UNINIT;
  Rte_StartTiming_InitState = RTE_STATE_UNINIT;

  /* reset Rx Timeout Flags */
  Rte_RxTimeoutFlagsInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */

  /* initialize flags for update handling */
  Rte_RxUpdateFlagsInit(); /* PRQA S 0315 */ /* MD_Rte_0315 */

  /* mode management initialization part 1 */
  Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Queue[0U] = RTE_MODE_Dcm_DcmDiagnosticSessionControl_DEFAULT_SESSION;
  Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_Queue[0U] = RTE_MODE_Dcm_DcmEcuReset_NONE;

  Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_tail = 1;
  Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_head = 0;
  Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail = 0;
  Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head = 0;
}


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BaseFunction_P_Awake_Diag_Actv_RBTM_FL_ST3_Awake_Diag_Actv_RBTM_FL_ST3(DC_BOOL data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_Awake_Diag_Actv_RBTM_FL_ST3_5efe61d8_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BaseFunction_P_Awake_Ignition_On_RBTM_FL_ST3_Awake_Ignition_On_RBTM_FL_ST3(DC_BOOL data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_Awake_Ignition_On_RBTM_FL_ST3_49d22bbd_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BaseFunction_P_Awake_NwStart_RBTM_FL_ST3_Awake_NwStart_RBTM_FL_ST3(DC_BOOL data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_Awake_NwStart_RBTM_FL_ST3_393ce9b3_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BaseFunction_P_ECU_Id_RBTM_FL_ST3_ECU_Id_RBTM_FL_ST3(c12_0_4094_1_SNA data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_ECU_Id_RBTM_FL_ST3_b4de0ce2_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BaseFunction_P_WakeupRsn_RBTM_FL_ST3_WakeupRsn_RBTM_FL_ST3(c10_WakeupRsn_ST3 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_WakeupRsn_RBTM_FL_ST3_91bb10a0_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_BeltAdjFunction_P_RevBltTns_FL_ComCyc_Actv_ST3_RevBltTns_FL_ComCyc_Actv_ST3(c02_Ndef_False_True_ST3 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_RevBltTns_FL_ComCyc_Actv_ST3_4c5f745f_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3(c02_Off_On data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_BltSlckDec_Md_FL_Stat_ST3_e47e790a_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_BltSlckDec_Md_FR_Stat_ST3_8538ecdf_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  Rte_CIL_IF_BltSlckDec_Md_XX_Stat_ST3_BltSlckDec_Md_XX_Stat_ST3 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3(c02_Off_Stage1_Stage2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_PS_Curve_FL_Stat_ST3_b0d41119_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  Rte_CIL_IF_PS_Curve_FL_Stat_ST3_PS_Curve_FL_Stat_ST3 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3(c02_Presf_Disp_Rq data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_RBTM_FL_Disp_Rq_ST3_c372540c_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  Rte_CIL_IF_RBTM_FL_Disp_Rq_ST3_RBTM_FL_Disp_Rq_ST3 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_IF_RBTM_FL_Tgl_ST3_RBTM_FL_Tgl_ST3(DC_BOOL data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_RBTM_FL_Tgl_ST3_1fe530ed_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_Meas_RBTM_FL_ST3_Meas8_RBTM_FL_ST3(P2CONST(REC_Meas_RBTM_FL_ST3_dgfi1nrxtb0voy6rb7ybeonmv, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComGroupSignal_Meas_RBTM_FL_01_ST3_1999cf4b_Tx, &(*(data)).Meas_RBTM_FL_01); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_Meas_RBTM_FL_02_ST3_5e39b59b_Tx, &(*(data)).Meas_RBTM_FL_02); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_Meas_RBTM_FL_03_ST3_63599c2b_Tx, &(*(data)).Meas_RBTM_FL_03); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_Meas_RBTM_FL_04_ST3_d179403b_Tx, &(*(data)).Meas_RBTM_FL_04); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_Meas_RBTM_FL_05_ST3_ec19698b_Tx, &(*(data)).Meas_RBTM_FL_05); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_Meas_RBTM_FL_06_ST3_abb9135b_Tx, &(*(data)).Meas_RBTM_FL_06); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_Meas_RBTM_FL_07_ST3_96d93aeb_Tx, &(*(data)).Meas_RBTM_FL_07); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_Meas_RBTM_FL_08_ST3_1489ad3a_Tx, &(*(data)).Meas_RBTM_FL_08); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignalGroup(ComConf_ComSignalGroup_Meas8_RBTM_FL_ST3_72jyquhuktrmjm0hkqempja37_23ddfefa_Tx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_Meas_RBTM_FR_ST3_Meas8_RBTM_FR_ST3(P2CONST(REC_Meas_RBTM_FR_ST3_dgfi1nrxtb0voy6rb7ybeonmv, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    ret |= Com_SendSignal(ComConf_ComGroupSignal_Meas_RBTM_FR_01_ST3_6f6f342d_Tx, &(*(data)).Meas_RBTM_FR_01); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_Meas_RBTM_FR_02_ST3_28cf4efd_Tx, &(*(data)).Meas_RBTM_FR_02); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_Meas_RBTM_FR_03_ST3_15af674d_Tx, &(*(data)).Meas_RBTM_FR_03); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_Meas_RBTM_FR_04_ST3_a78fbb5d_Tx, &(*(data)).Meas_RBTM_FR_04); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_Meas_RBTM_FR_05_ST3_9aef92ed_Tx, &(*(data)).Meas_RBTM_FR_05); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_Meas_RBTM_FR_06_ST3_dd4fe83d_Tx, &(*(data)).Meas_RBTM_FR_06); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_Meas_RBTM_FR_07_ST3_e02fc18d_Tx, &(*(data)).Meas_RBTM_FR_07); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_Meas_RBTM_FR_08_ST3_627f565c_Tx, &(*(data)).Meas_RBTM_FR_08); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignalGroup(ComConf_ComSignalGroup_Meas8_RBTM_FR_ST3_7ba3lhjy9fnhufd3n9dyw0p9p_19ed5f9c_Tx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3(c02_Off_Stage1_Stage2 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_PS_Curve_FR_Stat_ST3_36a2193c_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  Rte_CIL_P_PS_Curve_FR_Stat_ST3_PS_Curve_FR_Stat_ST3 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTMFL_SP_ActvClient_ST35_RBTMFL_SP_ActvClient_ST35(c04_RBTM_ActvClient data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_RBTMFL_SP_ActvClient_ST35_bec76928_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  Rte_CIL_P_RBTMFL_SP_ActvClient_ST35_RBTMFL_SP_ActvClient_ST35 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTMFL_SP_FctPrecond_Stat_ST35_RBTMFL_SP_FctPrecond_Stat_ST35(c10_RBTM_Fct_Precond data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_RBTMFL_SP_FctPrecond_Stat_ST35_bbfa2c80_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  Rte_CIL_P_RBTMFL_SP_FctPrecond_Stat_ST35_RBTMFL_SP_FctPrecond_Stat_ST35 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTMFR_SP_ActvClient_ST35_RBTMFR_SP_ActvClient_ST35(c04_RBTM_ActvClient data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_RBTMFR_SP_ActvClient_ST35_1fd8ade4_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  Rte_CIL_P_RBTMFR_SP_ActvClient_ST35_RBTMFR_SP_ActvClient_ST35 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTMFR_SP_FctPrecond_Stat_ST35_RBTMFR_SP_FctPrecond_Stat_ST35(c10_RBTM_Fct_Precond data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_RBTMFR_SP_FctPrecond_Stat_ST35_ce5639ee_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  Rte_CIL_P_RBTMFR_SP_FctPrecond_Stat_ST35_RBTMFR_SP_FctPrecond_Stat_ST35 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTM_FR_Disp_Rq_ST3_RBTM_FR_Disp_Rq_ST3(c02_Presf_Disp_Rq data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_RBTM_FR_Disp_Rq_ST3_4c4b9655_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  Rte_CIL_P_RBTM_FR_Disp_Rq_ST3_RBTM_FR_Disp_Rq_ST3 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_P_RBTM_FR_Tgl_ST3_RBTM_FR_Tgl_ST3(DC_BOOL data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_RBTM_FR_Tgl_ST3_bb42027b_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_RBTMFL_Actv_Lvl_ST35_RBTMFL_Actv_Lvl_ST35(c06_RBTM_Lvl_Stat data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_RBTMFL_Actv_Lvl_ST35_6199228f_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  Rte_CIL_RBTMFL_Actv_Lvl_ST35_RBTMFL_Actv_Lvl_ST35 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_RBTMFR_Actv_Lvl_ST35_RBTMFR_Actv_Lvl_ST35(c06_RBTM_Lvl_Stat data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_RBTMFR_Actv_Lvl_ST35_77991ccb_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  Rte_CIL_RBTMFR_Actv_Lvl_ST35_RBTMFR_Actv_Lvl_ST35 = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CIL_AC_CommunicationInteractionLayer_psrCANInputBlockStatus_b8NVMBlockStatus(b8BooleanType data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_CIL_psrCANInputBlockStatus_b8NVMBlockStatus = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RxUpdateFlags.Rte_RxUpdate_MMG_prrCANInputBlockStatus_b8NVMBlockStatus = 1U;
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_Diag_Actv_Awake_Diag_Actv_RBTM_FL_ST3(DC_BOOL data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_Awake_Diag_Actv_RBTM_FL_ST3_5efe61d8_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_Diag_Actv_R_Awake_Diag_Actv_RBTM_FR_ST3(DC_BOOL data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_Awake_Diag_Actv_RBTM_FR_ST3_822fa87a_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_Ignition_On_Awake_Ignition_On_RBTM_FL_ST3(DC_BOOL data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_Awake_Ignition_On_RBTM_FL_ST3_49d22bbd_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_Ignition_On_R_Awake_Ignition_On_RBTM_FR_ST3(DC_BOOL data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_Awake_Ignition_On_RBTM_FR_ST3_df6a9d63_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_NwStart_Cluster_Awake_NwStart_RBTM_FL_ST3(DC_BOOL data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_Awake_NwStart_RBTM_FL_ST3_393ce9b3_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_Awake_NwStart_Cluster_R_Awake_NwStart_RBTM_FR_ST3(DC_BOOL data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_Awake_NwStart_RBTM_FR_ST3_59fd792e_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_WakeupRsn_WakeupRsn_RBTM_FL_ST3(c10_WakeupRsn_ST3 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_WakeupRsn_RBTM_FL_ST3_91bb10a0_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Cdd_MBBL_EcuStatHandler_Pp_WakeupRsn_R_WakeupRsn_RBTM_FR_ST3(c10_WakeupRsn_ST3 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    ret |= Com_SendSignal(ComConf_ComSignal_WakeupRsn_RBTM_FR_ST3_6ec4195b_Tx, (&data)); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DiagFunction_P_ROE_ROE_XX_ST3(P2CONST(REC_ROE_XX_ST3_dgfi1nrxtb0voy6rb7ybeonmv, AUTOMATIC, RTE_DIAGFUNCTION_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_SendSignal(ComConf_ComGroupSignal_ROE_0_RBTM_FL_ST3_7255ce21_Tx, &(*(data)).ROE_0); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_ROE_1_RBTM_FL_ST3_afc317a4_Tx, &(*(data)).ROE_1); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_ROE_2_RBTM_FL_ST3_12097b6a_Tx, &(*(data)).ROE_2); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_ROE_3_RBTM_FL_ST3_cf9fa2ef_Tx, &(*(data)).ROE_3); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_ROE_4_RBTM_FL_ST3_b2eca4b7_Tx, &(*(data)).ROE_4); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_ROE_5_RBTM_FL_ST3_6f7a7d32_Tx, &(*(data)).ROE_5); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_ROE_6_RBTM_FL_ST3_d2b011fc_Tx, &(*(data)).ROE_6); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_ROE_7_RBTM_FL_ST3_0f26c879_Tx, &(*(data)).ROE_7); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignalGroup(ComConf_ComSignalGroup_ROE_RBTM_FL_ST3_6e0rxnifai2txra0wamb18g4m_4feaeebf_Tx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    ret |= Com_SendSignal(ComConf_ComGroupSignal_ROE_0_RBTM_FR_ST3_418450d2_Tx, &(*(data)).ROE_0); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_ROE_1_RBTM_FR_ST3_9c128957_Tx, &(*(data)).ROE_1); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_ROE_2_RBTM_FR_ST3_21d8e599_Tx, &(*(data)).ROE_2); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_ROE_3_RBTM_FR_ST3_fc4e3c1c_Tx, &(*(data)).ROE_3); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_ROE_4_RBTM_FR_ST3_813d3a44_Tx, &(*(data)).ROE_4); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_ROE_5_RBTM_FR_ST3_5cabe3c1_Tx, &(*(data)).ROE_5); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_ROE_6_RBTM_FR_ST3_e1618f0f_Tx, &(*(data)).ROE_6); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignal(ComConf_ComGroupSignal_ROE_7_RBTM_FR_ST3_3cf7568a_Tx, &(*(data)).ROE_7); /* PRQA S 0315, 1340, 2986 */ /* MD_Rte_0315, MD_Rte_1340, MD_Rte_2986 */
    ret |= Com_SendSignalGroup(ComConf_ComSignalGroup_ROE_RBTM_FR_ST3_3f1btonh6ivdn6ytgyuu9rtt1_5c720902_Tx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_AC_EndOfLifeManagement_ObsolescenceDataBlockNumber_BlockNumber(UInt8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_EOL_ObsolescenceDataBlockNumber_BlockNumber = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RoELite_ObsolescenceDataHandler */
  (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_DiagFunction_RoELite_ObsolescenceDataHandler); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_EOL_AC_EndOfLifeManagement_pseExecutionCounterBlockStatus_b8NVMBlockStatus(b8BooleanType data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_EOL_pseExecutionCounterBlockStatus_b8NVMBlockStatus = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RxUpdateFlags.Rte_RxUpdate_MMG_prrExecutionCountersBlockStatus_b8NVMBlockStatus = 1U;
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ERH_AC_ErrorHandler_psrAECsBlockStatus_b8NVMBlockStatus(b8BooleanType data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_ERH_psrAECsBlockStatus_b8NVMBlockStatus = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  SuspendOSInterrupts();
  Rte_RxUpdateFlags.Rte_RxUpdate_MMG_prrAECsBlockStatus_b8NVMBlockStatus = 1U;
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_MMG_AC_ModeManagement_AvailabilityDataHandler_AvailabilityDataCategory(UInt8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MMG_AvailabilityDataHandler_AvailabilityDataCategory = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: RoELite_AvailabilityDataHandler */
  (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_DiagFunction_RoELite_AvailabilityDataHandler); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_SecOC_VerificationStatus_verificationStatus(P2CONST(SecOC_VerificationStatusType, AUTOMATIC, RTE_SECOC_APPL_DATA) data) /* PRQA S 1505, 3206, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_2982 */
{

  return RTE_E_OK;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_Coding_ReceiveVIN_VIN(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(Rte_Ssa_BcTp_Coding_ReceiveVIN_VIN, data, sizeof(Coding_VINDataType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  /* scheduled trigger for runnables: Ssa_Coding_VIN_Receive */
  (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_Ssa_Coding_Ssa_Coding_VIN_Receive); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_Coding_ReceiveVINTimeout_state(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_Ssa_BcTp_Coding_ReceiveVINTimeout_state = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: Ssa_Coding_VIN_Receive_Timeout */
  (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_Ssa_Coding_Ssa_Coding_VIN_Receive_Timeout); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_FvM_ReceiveTickCount_tickCount(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy(Rte_Ssa_BcTp_FvM_ReceiveTickCount_tickCount, data, sizeof(Ssa_Data6ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  /* scheduled trigger for runnables: Ssa_FvM_Com_ReceiveTickCount */
  (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_Ssa_FvM_Ssa_FvM_Com_ReceiveTickCount); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_FvM_ReceiveTickCountTimeout_state(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_Ssa_BcTp_FvM_ReceiveTickCountTimeout_state = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: Ssa_FvM_Com_ReceiveTickCountTimeout */
  (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_Ssa_FvM_Ssa_FvM_Com_ReceiveTickCountTimeout); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_KeyM_ReceiveSharedSecret_sharedSecret(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(Rte_Ssa_BcTp_KeyM_ReceiveSharedSecret_sharedSecret, data, sizeof(KeyM_SharedSecretType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  /* scheduled trigger for runnables: Ssa_KeyM_Com_VehicleSharedSecretNotification */
  (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_Ssa_KeyM_Ssa_KeyM_Com_VehicleSharedSecretNotification); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_RightsM_ReceiveAuthenticationBroadcast_authentication(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy32(Rte_Ssa_BcTp_RightsM_ReceiveAuthenticationBroadcast_authentication, data, sizeof(RightsM_AuthenticationBroadcastType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  /* scheduled trigger for runnables: Ssa_RightsM_Com_ReceiveBroadcastAuthentication */
  (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_Ssa_RightsM_Ssa_RightsM_Com_ReceiveBroadcastAuthentication); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_SecLog_MacVerificationSecureBroadcastEvent_verificationStatus(P2CONST(SecOC_VerificationStatusType, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_Ssa_BcTp_SecLog_MacVerificationSecureBroadcastEvent_verificationStatus = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast */
  (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_Ssa_SecLog_Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_BcTp_TimeM_ReceiveRealTimeOffset_realTimeOffset(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy(Rte_Ssa_BcTp_TimeM_ReceiveRealTimeOffset_realTimeOffset, data, sizeof(Ssa_Data12ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  /* scheduled trigger for runnables: Ssa_TimeM_Com_ReceiveRealTimeOffset */
  (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_Ssa_TimeM_Ssa_TimeM_Com_ReceiveRealTimeOffset); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_FvM_FvM_SendLocalTickCountAndSyncStatus_Data(P2CONST(Ssa_LocalTickCountAndSyncStatusType, AUTOMATIC, RTE_SSA_FVM_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_Ssa_FvM_FvM_SendLocalTickCountAndSyncStatus_Data = *(data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_FvM_SendChangeTickCountEvent_Id(Ssa_ChangeTickCountEventIdType data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_Ssa_FvM_SendChangeTickCountEvent_Id = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: Ssa_TimeM_ReceiveChangeTickCountEvent */
  (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_Ssa_TimeM_Ssa_TimeM_ReceiveChangeTickCountEvent); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_FvM_SendChangeTickCountEvent_TickCount(P2CONST(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy(Rte_Ssa_FvM_SendChangeTickCountEvent_TickCount, data, sizeof(Ssa_Data5ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_ProcCtrl_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_Ssa_ProcCtrl_ProcCtrl_DispatchServices_Sender_ServiceId = *(&data); /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  /* scheduled trigger for runnables: Ssa_ProcCtrl_ServiceDispatcher */
  (void)ActivateTask(ApplBackgroundTask_Core0); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_Ssa_SecLog_SecLog_EventNotification_Data(P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) data) /* PRQA S 1505, 2982 */ /* MD_MSR_Rule8.7, MD_Rte_2982 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy(Rte_Ssa_SecLog_SecLog_EventNotification_Data, data, sizeof(Ssa_Data7ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();
  /* scheduled trigger for runnables: RoELite_SecureEventNotification */
  (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_DiagFunction_RoELite_SecureEventNotification); /* PRQA S 3417 */ /* MD_Rte_Os */

  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * Internal/External Rx connections
 *********************************************************************************************************************/

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3(P2VAR(REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[4U] = {0U, 0U, 0U, 0U};

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
    lengthBuffer = sizeof(transformationBuffer_0);
    retTransformer = E2EXf_Inv_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_BeltAdjFunction_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    *data = Rte_XDIS_38xd6mxe7w4h211xfx307v7jd_REC_Bckl_Sw_Fx_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx;
    ret = RTE_E_UNCONNECTED;
  }
  if (Rte_RxTimeoutFlags.Rte_RxTimeout_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_BltSlckDec_Md_Rq_HU_ST3_BltSlckDec_Md_Rq_HU_ST3(P2VAR(c02_Off_On, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    {
      c02_Off_On localBltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx = 3U;
      ret = Com_ReceiveSignal(ComConf_ComSignal_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx, &localBltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      *((data)) = localBltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    *data = 3U;
    ret = RTE_E_UNCONNECTED;
  }
  if (Rte_RxTimeoutFlags.Rte_RxTimeout_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3(P2VAR(REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[4U] = {0U, 0U, 0U, 0U};

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_CLkS_DrRltch_Stat_Pr5_ST3_7at68qvnk0r9npofyykyfq82v_10e0cb0e_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = sizeof(transformationBuffer_0);
    retTransformer = E2EXf_Inv_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_BeltAdjFunction_R_CLkS_DrRltch_Stat_Pr5_ST3_CLkS_DrRltch_Stat_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    *data = Rte_XDIS_5tgkwvedu4465t8unm4y2yblo_REC_CLkS_DrRltch_Stat_Pr5_ST3_42w45002bze5mo286svxxsdbx;
    ret = RTE_E_UNCONNECTED;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_DPC_Md_Rq_ESP_Pr5_ST3_DPC_Md_Rq_ESP_Pr5_ST3(P2VAR(REC_DPC_Md_Rq_ESP_Pr5_ST3_18cj3r9lb95cc7w4q3mwqkn86, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_DPC_Md_Rq_ESP_Pr5_ST3_dcsny138uwpesz5bmssj1scqi_6b0a3c02_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
    ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_DPC_Md_PT_Rq_ST3_221f27a4_Rx, &(*(data)).DPC_Md_PT_Rq_ST3); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    *data = Rte_XDIS_2akyi0yafm6v4b7rnlmtzqky2_REC_DPC_Md_Rq_ESP_Pr5_ST3_18cj3r9lb95cc7w4q3mwqkn86;
    ret = RTE_E_UNCONNECTED;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3(P2VAR(REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[8U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
    lengthBuffer = sizeof(transformationBuffer_0);
    retTransformer = E2EXf_Inv_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_BeltAdjFunction_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    *data = Rte_XDIS_69fckmg12bk5g7417pzn53395_REC_EVC_CfgList_01_08_Pr5_ST3_6v3sj55wsjghho72slblc9pby;
    ret = RTE_E_UNCONNECTED;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3(P2VAR(REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[4U] = {0U, 0U, 0U, 0U};

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_ORC_Impact2_Pr5_ST3_b9l09rrslyv7vj3o92j69irnd_2f5ae8ac_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    lengthBuffer = sizeof(transformationBuffer_0);
    retTransformer = E2EXf_Inv_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_BeltAdjFunction_R_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    *data = Rte_XDIS_6l5b88fcuqpu2imoz1fzls07a_REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh;
    ret = RTE_E_UNCONNECTED;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3(P2VAR(REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[4U] = {0U, 0U, 0U, 0U};

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_ORC_Impact3_Pr5_ST3_c4pqnkonfjwv3uiohsxhe9dwu_1bc89a3a_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
    lengthBuffer = sizeof(transformationBuffer_0);
    retTransformer = E2EXf_Inv_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_BeltAdjFunction_R_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    *data = Rte_XDIS_ayiqyrhz0dpk9ygbqo5e5w1f7_REC_ORC_Impact3_Pr5_ST3_b4auermbjwizt3ufwg8j8br58;
    ret = RTE_E_UNCONNECTED;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_PN14_DDP_Sw_Stat_ST3_PN14_DDP_Sw_Stat_ST3(P2VAR(c03_PN14_TDP_Sw_Stat, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    {
      c03_PN14_TDP_Sw_Stat localPN14_DDP_Sw_Stat_ST3_568ad7e6_Rx = 0U;
      ret = Com_ReceiveSignal(ComConf_ComSignal_PN14_DDP_Sw_Stat_ST3_568ad7e6_Rx, &localPN14_DDP_Sw_Stat_ST3_568ad7e6_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      *((data)) = localPN14_DDP_Sw_Stat_ST3_568ad7e6_Rx;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    *data = 0U;
    ret = RTE_E_UNCONNECTED;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3(P2VAR(REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[4U] = {0U, 0U, 0U, 0U};

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
    lengthBuffer = sizeof(transformationBuffer_0);
    retTransformer = E2EXf_Inv_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_BeltAdjFunction_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    *data = Rte_XDIS_1j2e7ey8q28fsybvpbxfqeop8_REC_PT4_PTCoor4_Pr5_ST3_9t50popkpz30is106xpis1iyh;
    ret = RTE_E_UNCONNECTED;
  }
  if (Rte_RxTimeoutFlags.Rte_RxTimeout_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_PT4_PTCoor9_Pr5_ST3_PT4_PTCoor9_Pr5_ST3(P2VAR(REC_PT4_PTCoor9_Pr5_ST3_cl82h0erzy2xfmj19jwk97p4u, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_PT4_PTCoor9_Pr5_ST3_6r95o81sst3tk9w2lzz600cw3_5dfe4b97_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
    ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_PT4_PTCoor_Accel_Md_ST3_cd32fba3_Rx, &(*(data)).PT4_PTCoor_Accel_Md_ST3); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    *data = Rte_XDIS_86xn4hwzmz58ui3sqboz24rhd_REC_PT4_PTCoor9_Pr5_ST3_cl82h0erzy2xfmj19jwk97p4u;
    ret = RTE_E_UNCONNECTED;
  }
  if (Rte_RxTimeoutFlags.Rte_RxTimeout_BeltAdjFunction_R_PT4_PTCoor9_Pr5_ST3_PT4_PTCoor9_Pr5_ST3 != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(P2VAR(REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[8U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_5p8cvrni3ypvuac33rj2asfy9_2f73a7b3_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
    lengthBuffer = sizeof(transformationBuffer_0);
    retTransformer = E2EXf_Inv_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_BeltAdjFunction_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    *data = Rte_XDIS_bjxptj1w89so7fpxm4dpms8ww_REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh;
    ret = RTE_E_UNCONNECTED;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3(P2VAR(REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[8U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_PresfAct_Adj_Pr5_ST3_2joar1a41xrgjqab60epnbplm_25141edc_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
    lengthBuffer = sizeof(transformationBuffer_0);
    retTransformer = E2EXf_Inv_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
    if (!Rte_IsHardTransformerError(retTransformer))
    {
      retTransformer |= ComXf_Inv_BeltAdjFunction_R_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
    }
    if (ret != RTE_E_COM_STOPPED)
    {
      if (Rte_IsHardTransformerError(retTransformer))
      {
        ret = RTE_E_HARD_TRANSFORMER_ERROR;
      }
      else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
      {
        ret = RTE_E_SOFT_TRANSFORMER_ERROR;
      }
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    *data = Rte_XDIS_klz6op2k9wci74l4e72gktkb_REC_PresfAct_Adj_Pr5_ST3_1fn392wedbq10w68dtk77u1sr;
    ret = RTE_E_UNCONNECTED;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_RevBltTns_FR_ComCyc_Actv_ST3_RevBltTns_FR_ComCyc_Actv_ST3(P2VAR(c02_Ndef_False_True_ST3, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    {
      c02_Ndef_False_True_ST3 localRevBltTns_FR_ComCyc_Actv_ST3_4c00d29e_Rx = 3U;
      ret = Com_ReceiveSignal(ComConf_ComSignal_RevBltTns_FR_ComCyc_Actv_ST3_4c00d29e_Rx, &localRevBltTns_FR_ComCyc_Actv_ST3_4c00d29e_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      *((data)) = localRevBltTns_FR_ComCyc_Actv_ST3_4c00d29e_Rx;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    *data = 3U;
    ret = RTE_E_UNCONNECTED;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BeltAdjFunction_R_VehSpd_Disp_ST3_VehSpd_Disp_ST3(P2VAR(c12_km_p_h_0_409k4_0k1, AUTOMATIC, RTE_BELTADJFUNCTION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    {
      c12_km_p_h_0_409k4_0k1 localVehSpd_Disp_ST3_4922a2fd_Rx = 4095U;
      ret = Com_ReceiveSignal(ComConf_ComSignal_VehSpd_Disp_ST3_4922a2fd_Rx, &localVehSpd_Disp_ST3_4922a2fd_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      *((data)) = localVehSpd_Disp_ST3_4922a2fd_Rx;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    *data = 4095U;
    ret = RTE_E_UNCONNECTED;
  }
  if (Rte_RxTimeoutFlags.Rte_RxTimeout_VehSpd_Disp_ST3_4922a2fd_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_KillAllRunRequest_requestedMode(P2VAR(BswM_ESH_KillAllRun, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  *(data) = Rte_Cdd_MBBL_ResetExecutor_Request_ESH_KillAllRunRequest_requestedMode; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_PostRunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_0_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BswM_Request_ESH_RunRequest_1_requestedMode(P2VAR(BswM_ESH_RunRequest, AUTOMATIC, RTE_BSWM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  *data = 0U;

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3(P2VAR(REC_Ign_Stat_Pr5_ST3, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[4U] = {0U, 0U, 0U, 0U};

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_CIL_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_CIL_IG_Ign_Stat_Pr5_ST3_Ign_Stat_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3(P2VAR(REC_ORC_Impact2_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[4U] = {0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_ORC_Impact2_Pr5_ST3_b9l09rrslyv7vj3o92j69irnd_2f5ae8ac_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_CIL_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_CIL_IG_ORC_Impact2_Pr5_ST3_ORC_Impact2_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3(P2VAR(REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[4U] = {0U, 0U, 0U, 0U};

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_ORC_Impact3_Pr5_ST3_c4pqnkonfjwv3uiohsxhe9dwu_1bc89a3a_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_CIL_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_CIL_IG_ORC_Impact3_Pr5_ST3_ORC_Impact3_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3(P2VAR(REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[8U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_PresfAct_Adj_Pr5_ST3_2joar1a41xrgjqab60epnbplm_25141edc_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_CIL_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_CIL_IG_PresfAct_Adj_Pr5_ST3_PresfAct_Adj_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3(P2VAR(REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[4U] = {0U, 0U, 0U, 0U};

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_CIL_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_CIL_R_Bckl_Sw_Fx_Stat_Pr5_ST3_Bckl_Sw_Fx_Stat_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_BeltHdOvr_XX_Stat_ST3_BeltHdOvr_XX_Stat_ST3(P2VAR(c02_BeltHdOvr_Stat, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    {
      c02_BeltHdOvr_Stat localBeltHdOvr_FL_Stat_ST3_3489841d_Rx = 3U;
      ret = Com_ReceiveSignal(ComConf_ComSignal_BeltHdOvr_FL_Stat_ST3_3489841d_Rx, &localBeltHdOvr_FL_Stat_ST3_3489841d_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      *((data)) = localBeltHdOvr_FL_Stat_ST3_3489841d_Rx;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    {
      c02_BeltHdOvr_Stat localBeltHdOvr_FR_Stat_ST3_0eefd507_Rx = 3U;
      ret = Com_ReceiveSignal(ComConf_ComSignal_BeltHdOvr_FR_Stat_ST3_0eefd507_Rx, &localBeltHdOvr_FR_Stat_ST3_0eefd507_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      *((data)) = localBeltHdOvr_FR_Stat_ST3_0eefd507_Rx;
    }
  }
  if (Rte_RxTimeoutFlags.Rte_RxTimeout_Graph_3c51f51b5e8aaf813b8f9a89a7827e7c_BeltHdOvr_XX_Stat_ST3 != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_BltSlckDec_Md_Rq_HU_ST3_BltSlckDec_Md_Rq_HU_ST3(P2VAR(c02_Off_On, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  {
    c02_Off_On localBltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx = 3U;
    ret = Com_ReceiveSignal(ComConf_ComSignal_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx, &localBltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
    *((data)) = localBltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx;
  }
  if (Rte_RxTimeoutFlags.Rte_RxTimeout_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3(P2VAR(REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[8U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_CIL_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_CIL_R_EVC_CfgList_01_08_Pr5_ST3_EVC_CfgList_01_08_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }
  if (Rte_RxTimeoutFlags.Rte_RxTimeout_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PS_Curve_FL_Rq_HU_ST3_PS_Curve_FL_Rq_HU_ST3(P2VAR(c02_Off_Stage1_Stage2, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    {
      c02_Off_Stage1_Stage2 localPS_Curve_FL_Rq_HU_ST3_6cd299ba_Rx = 3U;
      ret = Com_ReceiveSignal(ComConf_ComSignal_PS_Curve_FL_Rq_HU_ST3_6cd299ba_Rx, &localPS_Curve_FL_Rq_HU_ST3_6cd299ba_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      *((data)) = localPS_Curve_FL_Rq_HU_ST3_6cd299ba_Rx;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    *data = 3U;
    ret = RTE_E_UNCONNECTED;
  }
  if (Rte_RxTimeoutFlags.Rte_RxTimeout_CIL_R_PS_Curve_FL_Rq_HU_ST3_PS_Curve_FL_Rq_HU_ST3 != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PS_Curve_FR_Rq_HU_ST3_PS_Curve_FR_Rq_HU_ST3(P2VAR(c02_Off_Stage1_Stage2, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    {
      c02_Off_Stage1_Stage2 localPS_Curve_FR_Rq_HU_ST3_90527677_Rx = 3U;
      ret = Com_ReceiveSignal(ComConf_ComSignal_PS_Curve_FR_Rq_HU_ST3_90527677_Rx, &localPS_Curve_FR_Rq_HU_ST3_90527677_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      *((data)) = localPS_Curve_FR_Rq_HU_ST3_90527677_Rx;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    *data = 3U;
    ret = RTE_E_UNCONNECTED;
  }
  if (Rte_RxTimeoutFlags.Rte_RxTimeout_CIL_R_PS_Curve_FR_Rq_HU_ST3_PS_Curve_FR_Rq_HU_ST3 != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3(P2VAR(REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[4U] = {0U, 0U, 0U, 0U};

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_CIL_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_CIL_R_PT4_PTCoor4_Pr5_ST3_PT4_PTCoor4_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }
  if (Rte_RxTimeoutFlags.Rte_RxTimeout_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(P2VAR(REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[8U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_5p8cvrni3ypvuac33rj2asfy9_2f73a7b3_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_CIL_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_CIL_R_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_CIL_AC_CommunicationInteractionLayer_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3(P2VAR(REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt, AUTOMATIC, RTE_CIL_AC_COMMUNICATIONINTERACTIONLAYER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[5U] = {0U, 0U, 0U, 0U, 0U};

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_CIL_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_CIL_R_SBeltTens_SP_Lvl_Pr5_ST3_SBeltTens_SP_Lvl_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }
  if (Rte_RxTimeoutFlags.Rte_RxTimeout_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3(P2VAR(REC_Ign_Stat_Pr5_ST3, AUTOMATIC, RTE_CDD_MBBL_ECUSTATHANDLER_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[4U] = {0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_Cdd_MBBL_EcuStatHandler_Pp_Ign_Stat_Ign_Stat_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IF_BeltHdOvr_XX_Stat_ST3_BeltHdOvr_XX_Stat_ST3(P2VAR(c02_BeltHdOvr_Stat, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    {
      c02_BeltHdOvr_Stat localBeltHdOvr_FL_Stat_ST3_3489841d_Rx = 3U;
      ret = Com_ReceiveSignal(ComConf_ComSignal_BeltHdOvr_FL_Stat_ST3_3489841d_Rx, &localBeltHdOvr_FL_Stat_ST3_3489841d_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      *((data)) = localBeltHdOvr_FL_Stat_ST3_3489841d_Rx;
    }
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    {
      c02_BeltHdOvr_Stat localBeltHdOvr_FR_Stat_ST3_0eefd507_Rx = 3U;
      ret = Com_ReceiveSignal(ComConf_ComSignal_BeltHdOvr_FR_Stat_ST3_0eefd507_Rx, &localBeltHdOvr_FR_Stat_ST3_0eefd507_Rx); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
      *((data)) = localBeltHdOvr_FR_Stat_ST3_0eefd507_Rx;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3(P2VAR(REC_Bckl_Sw_Fx_Stat_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[4U] = {0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_DIA_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_DIA_IG_Bckl_Sw_Fx_Stat_Pr5_ST3_6ckxfn8j26ez9slws8s7zuact_Bckl_Sw_Fx_Stat_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3(P2VAR(REC_EVC_CfgList_01_08_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[8U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_DIA_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_DIA_IG_EVC_CfgList_01_08_Pr5_ST3_40zxqtxkwyhasb66rr3qexjf2_EVC_CfgList_01_08_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3(P2VAR(REC_Ign_Stat_Pr5_ST3_bt5mk3546wsooydubq849n96, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[4U] = {0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_DIA_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_DIA_IG_Ign_Stat_Pr5_ST3_46s203zrl2qg54zbkbmirlx2b_Ign_Stat_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3(P2VAR(REC_ORC_Impact3_Pr5_ST3_8q27fswita0fglxxeoewe0y19, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[4U] = {0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_ORC_Impact3_Pr5_ST3_c4pqnkonfjwv3uiohsxhe9dwu_1bc89a3a_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_DIA_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_DIA_IG_ORC_Impact3_Pr5_ST3_35qgq57bw73eamvx4gelk7iiv_ORC_Impact3_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3(P2VAR(REC_PT4_PTCoor4_Pr5_ST3_ezyv7tcqxjqun5qfzxokvhqqw, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[4U] = {0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_DIA_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_DIA_IG_PT4_PTCoor4_Pr5_ST3_3rxtipq9xm5agzf69e8usehmj_PT4_PTCoor4_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(P2VAR(REC_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[8U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_5p8cvrni3ypvuac33rj2asfy9_2f73a7b3_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_DIA_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_DIA_IG_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3_c8lirmw9wm5odas0h648yyd4w_PT4_PTCoor_DrvPosn_Gear_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3(P2VAR(REC_PresfAct_Adj_Pr5_ST3_14lojwgkcazelrb438elf5h0j, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[8U] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_PresfAct_Adj_Pr5_ST3_2joar1a41xrgjqab60epnbplm_25141edc_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_DIA_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_DIA_IG_PresfAct_Adj_Pr5_ST3_863uuptg5wch3t7i31c8crpa2_PresfAct_Adj_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DIA_AC_DiagOnCAN_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3(P2VAR(REC_SBeltTens_SP_Lvl_Pr5_ST3_cp6wyrd9cg7ec7y2w3khz1gyt, AUTOMATIC, RTE_DIA_AC_DIAGONCAN_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[5U] = {0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_DIA_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_DIA_IG_SBeltTens_SP_Lvl_Pr5_ST3_aljrkz9re372o0jtum2i5lh8w_SBeltTens_SP_Lvl_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3(P2VAR(REC_DI_Odo_Pr5_ST3_9t50popkpz30is106xpis1iyh, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[6U] = {0U, 0U, 0U, 0U, 0U, 0U};

  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_DI_Odo_Pr5_ST3_e68xmtlkywxgxsdwekdjjhw3t_eb760b63_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_DiagFunction_R_DI_Odo_Pr5_ST3_DI_Odo_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DiagFunction_R_Sec_Event_ST3_Data(P2VAR(c08_UInt_SNA_na, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy(data, Rte_Ssa_SecLog_SecLog_EventNotification_Data, sizeof(ARR_08_UInt_noSNA_7)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MMG_AC_ModeManagement_prrAECsBlockStatus_b8NVMBlockStatus(P2VAR(b8BooleanType, AUTOMATIC, RTE_MMG_AC_MODEMANAGEMENT_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_ERH_psrAECsBlockStatus_b8NVMBlockStatus; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_RxUpdateFlags.Rte_RxUpdate_MMG_prrAECsBlockStatus_b8NVMBlockStatus = 0U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MMG_AC_ModeManagement_prrCANInputBlockStatus_b8NVMBlockStatus(P2VAR(b8BooleanType, AUTOMATIC, RTE_MMG_AC_MODEMANAGEMENT_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_CIL_psrCANInputBlockStatus_b8NVMBlockStatus; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_RxUpdateFlags.Rte_RxUpdate_MMG_prrCANInputBlockStatus_b8NVMBlockStatus = 0U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_MMG_AC_ModeManagement_prrExecutionCountersBlockStatus_b8NVMBlockStatus(P2VAR(b8BooleanType, AUTOMATIC, RTE_MMG_AC_MODEMANAGEMENT_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  *(data) = Rte_EOL_pseExecutionCounterBlockStatus_b8NVMBlockStatus; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  Rte_RxUpdateFlags.Rte_RxUpdate_MMG_prrExecutionCountersBlockStatus_b8NVMBlockStatus = 0U;
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_BcTp_ReceiveDiagnosticAuthentication_VSS_TP_Auth_ST3(P2VAR(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_VSS_TP_Auth_ST3_6j4id7sghlvlbroli4wjozjik_2ac87786_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_Auth_0_ST3_8d2bd1cf_Rx, &data[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_Auth_1_ST3_b04bf87f_Rx, &data[1]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_Auth_2_ST3_f7eb82af_Rx, &data[2]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_Auth_3_ST3_ca8bab1f_Rx, &data[3]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_Auth_4_ST3_78ab770f_Rx, &data[4]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_Auth_5_ST3_45cb5ebf_Rx, &data[5]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_Auth_6_ST3_026b246f_Rx, &data[6]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_Auth_7_ST3_3f0b0ddf_Rx, &data[7]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_BcTp_ReceiveRealTimeOffset_VSS_TP_RealTmOffset_ST3(P2VAR(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_VSS_TP_RealTmOffset_ST3_1t7vc44gftc0wv35k5kgc2in9_d3385ce4_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_RealTmOffset_0_ST3_a2539a58_Rx, &data[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_RealTmOffset_1_ST3_9f33b3e8_Rx, &data[1]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_RealTmOffset_2_ST3_d893c938_Rx, &data[2]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_RealTmOffset_3_ST3_e5f3e088_Rx, &data[3]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_RealTmOffset_4_ST3_57d33c98_Rx, &data[4]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_RealTmOffset_5_ST3_6ab31528_Rx, &data[5]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_RealTmOffset_6_ST3_2d136ff8_Rx, &data[6]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_RealTmOffset_7_ST3_10734648_Rx, &data[7]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_BcTp_ReceiveSharedSecret_VSS_TP_SharedSecret_ST3(P2VAR(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_VSS_TP_SharedSecret_ST3_8pj4t8t4rm3tw3pk5hj7vonti_d9a21e4b_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_SharedSecret_0_ST3_74e3db3b_Rx, &data[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_SharedSecret_1_ST3_4983f28b_Rx, &data[1]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_SharedSecret_2_ST3_0e23885b_Rx, &data[2]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_SharedSecret_3_ST3_3343a1eb_Rx, &data[3]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_SharedSecret_4_ST3_81637dfb_Rx, &data[4]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_SharedSecret_5_ST3_bc03544b_Rx, &data[5]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_SharedSecret_6_ST3_fba32e9b_Rx, &data[6]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_SharedSecret_7_ST3_c6c3072b_Rx, &data[7]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_BcTp_ReceiveTickCount_VSS_TP_SecTickCount_ST3(P2VAR(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_VSS_TP_SecTickCount_Lvl2_ST3_9eubq13iosat764o0lqh5xb6r_01efe31e_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_SecTickCount_Lvl2_0_ST3_dac5ba08_Rx, &data[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_SecTickCount_Lvl2_1_ST3_e7a593b8_Rx, &data[1]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_SecTickCount_Lvl2_2_ST3_a005e968_Rx, &data[2]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_SecTickCount_Lvl2_3_ST3_9d65c0d8_Rx, &data[3]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_SecTickCount_Lvl2_4_ST3_2f451cc8_Rx, &data[4]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_SecTickCount_Lvl2_5_ST3_12253578_Rx, &data[5]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_SecTickCount_Lvl2_6_ST3_55854fa8_Rx, &data[6]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_SecTickCount_Lvl2_7_ST3_68e56618_Rx, &data[7]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  if (Rte_RxTimeoutFlags.Rte_RxTimeout_VSS_TP_SecTickCount_Lvl2_ST3_9eubq13iosat764o0lqh5xb6r_01efe31e_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_BcTp_ReceiveVIN_VSS_TP_VIN_ST3(P2VAR(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  ret = Com_ReceiveSignalGroup(ComConf_ComSignalGroup_VSS_TP_VIN_ST3_bz1xsv84cxzl09j028gn39p69_f31ab3e3_Rx); /* PRQA S 0315 */ /* MD_Rte_0315 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_VIN_0_ST3_fc3604d4_Rx, &data[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_VIN_1_ST3_c1562d64_Rx, &data[1]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_VIN_2_ST3_86f657b4_Rx, &data[2]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_VIN_3_ST3_bb967e04_Rx, &data[3]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_VIN_4_ST3_09b6a214_Rx, &data[4]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_VIN_5_ST3_34d68ba4_Rx, &data[5]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_VIN_6_ST3_7376f174_Rx, &data[6]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ret |= Com_ReceiveSignal(ComConf_ComGroupSignal_VSS_TP_VIN_7_ST3_4e16d8c4_Rx, &data[7]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  if (Rte_RxTimeoutFlags.Rte_RxTimeout_VSS_TP_VIN_ST3_bz1xsv84cxzl09j028gn39p69_f31ab3e3_Rx != 0U)
  {
    ret |= RTE_E_MAX_AGE_EXCEEDED; /* PRQA S 2986 */ /* MD_Rte_2986 */
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_Coding_Coding_Com_ReceiveVIN_VIN(P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy32(data, Rte_Ssa_BcTp_Coding_ReceiveVIN_VIN, sizeof(Coding_VINDataType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_FvM_FvM_Com_ReceiveTickCount_tickCount(P2VAR(uint8, AUTOMATIC, RTE_SSA_FVM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy(data, Rte_Ssa_BcTp_FvM_ReceiveTickCount_tickCount, sizeof(Ssa_Data6ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_KeyM_KeyM_Com_ReceiveSharedSecret_sharedSecret(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy32(data, Rte_Ssa_BcTp_KeyM_ReceiveSharedSecret_sharedSecret, sizeof(KeyM_SharedSecretType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_RightsM_RightsM_ReceiveAuthenticationBroadcast_authentication(P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy32(data, Rte_Ssa_BcTp_RightsM_ReceiveAuthenticationBroadcast_authentication, sizeof(RightsM_AuthenticationBroadcastType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3(P2VAR(Ssa_OdometerRecordType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[6U] = {0U, 0U, 0U, 0U, 0U, 0U};

  SuspendOSInterrupts();
  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_DI_Odo_Pr5_ST3_e68xmtlkywxgxsdwekdjjhw3t_eb760b63_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  ResumeOSInterrupts();
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_Ssa_RightsM_Ssa_BusOdometer_DI_Odo_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_SecLog_BcTp_SecureBroadcastVerificationStatus_verificationStatus(P2VAR(SecOC_VerificationStatusType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_Ssa_BcTp_SecLog_MacVerificationSecureBroadcastEvent_verificationStatus; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_SecLog_ReceiveLocalTickCountAndSyncStatus_Data(P2VAR(Ssa_LocalTickCountAndSyncStatusType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_Ssa_FvM_FvM_SendLocalTickCountAndSyncStatus_Data; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3(P2VAR(Ssa_IgnitionStatusType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  Std_ReturnType retTransformer;
  uint32 lengthBuffer;
  uint8 transformationBuffer_0[4U] = {0U, 0U, 0U, 0U};

  Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  ret |= Com_ReceiveSignalGroupArray(ComConf_ComSignalGroup_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx, &transformationBuffer_0[0]); /* PRQA S 0315, 2986 */ /* MD_Rte_0315, MD_Rte_2986 */
  Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */
  lengthBuffer = sizeof(transformationBuffer_0);
  retTransformer = E2EXf_Inv_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3(&(transformationBuffer_0[0]), &lengthBuffer, lengthBuffer);
  if (!Rte_IsHardTransformerError(retTransformer))
  {
    retTransformer |= ComXf_Inv_Ssa_SecLog_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3(&(transformationBuffer_0[0]), lengthBuffer, data); /* PRQA S 2983 */ /* MD_Rte_2983 */
  }
  if (ret != RTE_E_COM_STOPPED)
  {
    if (Rte_IsHardTransformerError(retTransformer))
    {
      ret = RTE_E_HARD_TRANSFORMER_ERROR;
    }
    else if (retTransformer != RTE_E_OK) /* PRQA S 2004 */ /* MD_MSR_EmptyClause */
    {
      ret = RTE_E_SOFT_TRANSFORMER_ERROR;
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_TimeM_ReceiveChangeTickCountEvent_TickCount(P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Rte_MemCpy(data, Rte_Ssa_FvM_SendChangeTickCountEvent_TickCount, sizeof(Ssa_Data5ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_TimeM_ReceiveLocalTickCountAndSyncStatus_Data(P2VAR(Ssa_LocalTickCountAndSyncStatusType, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  *(data) = Rte_Ssa_FvM_FvM_SendLocalTickCountAndSyncStatus_Data; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_Ssa_TimeM_TimeM_Com_ReceiveRealTimeOffset_realTimeOffset(P2VAR(uint8, AUTOMATIC, RTE_SSA_TIMEM_APPL_VAR) data) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  SuspendOSInterrupts();
  Rte_MemCpy(data, Rte_Ssa_BcTp_TimeM_ReceiveRealTimeOffset_realTimeOffset, sizeof(Ssa_Data12ByteType)); /* PRQA S 0314, 0315, 0316 */ /* MD_Rte_0314, MD_Rte_0315, MD_Rte_0316 */
  ResumeOSInterrupts();

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_1_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_DCM_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Dcm_DataServices_DID_0136_Trigger_Event_Activation_Status_Byte_2_WriteData(P2CONST(uint8, AUTOMATIC, RTE_DCM_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APPL_VAR) ErrorCode) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_CBReadData_Data_DID_0x133_Operating_Time_Status_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_DemSc_GetCurrentOdometer(P2VAR(uint32, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) Odometer) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemMaster_0_DemSc_GetExternalTesterStatus(P2VAR(boolean, AUTOMATIC, RTE_DEMMASTER_0_APPL_VAR) TesterPresent) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x10a_Vehicle_Odometer_in_Low_Resolution_ReadData(P2VAR(DataPrimitiveType_uint16, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x133_Current_Operating_Time_ReadData(P2VAR(DataPrimitiveType_uint32, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x133_Operating_Time_Status_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0x18b_SecOcDataID_ReadData(P2VAR(uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_DemSatellite_0_CBReadData_Data_DID_0xfd05_Root_Causes_ReadData(P2VAR(DataPrimitiveType_uint8, AUTOMATIC, RTE_DEMSATELLITE_0_APPL_VAR) Data) /* PRQA S 1505, 3206, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_3206, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_UNCONNECTED; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* call to server runnable removed as client is never triggered */

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_KeyM_KeyMCertificateNotification_Ssa_TrustModelBackendCert_CertificateVerifyCallbackNotification(KeyM_CertificateStatusType Result) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelBackend(Result);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_KeyM_KeyMCertificateNotification_Ssa_TrustModelBackendCert_ServiceCertificateCallbackNotification(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelBackend(Result, ResponseDataLength, ResponseData);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_KeyM_KeyMCertificateNotification_Ssa_TrustModelBackendPeerCert_CertificateVerifyCallbackNotification(KeyM_CertificateStatusType Result) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelBackendPeer(Result);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_KeyM_KeyMCertificateNotification_Ssa_TrustModelBackendPeerCert_ServiceCertificateCallbackNotification(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelBackendPeer(Result, ResponseDataLength, ResponseData);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_KeyM_KeyMCertificateNotification_Ssa_TrustModelEcuCert_CertificateVerifyCallbackNotification(KeyM_CertificateStatusType Result) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelEcu(Result);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_KeyM_KeyMCertificateNotification_Ssa_TrustModelEcuCert_ServiceCertificateCallbackNotification(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelEcu(Result, ResponseDataLength, ResponseData);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_KeyM_KeyMCertificateNotification_Ssa_TrustModelEcuCsr_CertificateVerifyCallbackNotification(KeyM_CertificateStatusType Result) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelEcuCsr(Result);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_KeyM_KeyMCertificateNotification_Ssa_TrustModelEcuCsr_ServiceCertificateCallbackNotification(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelEcuCsr(Result, ResponseDataLength, ResponseData);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_KeyM_KeyMCertificateNotification_Ssa_TrustModelEcuPeerCert_CertificateVerifyCallbackNotification(KeyM_CertificateStatusType Result) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelEcuPeer(Result);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_KeyM_KeyMCertificateNotification_Ssa_TrustModelEcuPeerCert_ServiceCertificateCallbackNotification(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelEcuPeer(Result, ResponseDataLength, ResponseData);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_KeyM_KeyMCertificateNotification_Ssa_TrustModelIntermediateCert_CertificateVerifyCallbackNotification(KeyM_CertificateStatusType Result) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelIntermediate(Result);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_KeyM_KeyMCertificateNotification_Ssa_TrustModelIntermediateCert_ServiceCertificateCallbackNotification(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelIntermediate(Result, ResponseDataLength, ResponseData);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_KeyM_KeyMCertificateNotification_Ssa_TrustModelIntermediatePeerCert_CertificateVerifyCallbackNotification(KeyM_CertificateStatusType Result) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelIntermediatePeer(Result);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_KeyM_KeyMCertificateNotification_Ssa_TrustModelIntermediatePeerCert_ServiceCertificateCallbackNotification(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelIntermediatePeer(Result, ResponseDataLength, ResponseData);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_KeyM_KeyMCertificateNotification_Ssa_TrustModelRootCert_CertificateVerifyCallbackNotification(KeyM_CertificateStatusType Result) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Ssa_KeyM_KeyMCertificateVerifyCallback_TrustModelRoot(Result);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_KeyM_KeyMCertificateNotification_Ssa_TrustModelRootCert_ServiceCertificateCallbackNotification(KeyM_ResultType Result, uint16 ResponseDataLength, KeyM_const_CryptoKeyDataType ResponseData) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Ssa_KeyM_KeyMServiceCertificateCallback_TrustModelRoot(Result, ResponseDataLength, ResponseData);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_BcTp_MacVerify_Authentication_MacVerify(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) dataBuffer, uint32 dataLength, P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) macBuffer, uint32 macLength, P2VAR(Crypto_VerifyResultType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) verifyBuffer) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = Csm_MacVerify((uint32)29, (Crypto_OperationModeType)7, dataBuffer, dataLength, macBuffer, macLength, verifyBuffer);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_BcTp_MacVerify_RealTime_MacVerify(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) dataBuffer, uint32 dataLength, P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) macBuffer, uint32 macLength, P2VAR(Crypto_VerifyResultType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) verifyBuffer) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = Csm_MacVerify((uint32)30, (Crypto_OperationModeType)7, dataBuffer, dataLength, macBuffer, macLength, verifyBuffer);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_BcTp_MacVerify_TickCount_MacVerify(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) dataBuffer, uint32 dataLength, P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) macBuffer, uint32 macLength, P2VAR(Crypto_VerifyResultType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) verifyBuffer) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = Csm_MacVerify((uint32)31, (Crypto_OperationModeType)7, dataBuffer, dataLength, macBuffer, macLength, verifyBuffer);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_BcTp_MacVerify_VIN_MacVerify(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) dataBuffer, uint32 dataLength, P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) macBuffer, uint32 macLength, P2VAR(Crypto_VerifyResultType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) verifyBuffer) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = Csm_MacVerify((uint32)32, (Crypto_OperationModeType)7, dataBuffer, dataLength, macBuffer, macLength, verifyBuffer);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_Issuer_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelBackendCert_Issuer_002((KeyM_CertificateIdType)0, (KeyM_CertElementIdType)3, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_SerialNo_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelBackendCert_SerialNo_002((KeyM_CertificateIdType)0, (KeyM_CertElementIdType)1, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelBackendCert_SubjectPublicKeyInfoKey_002((KeyM_CertificateIdType)0, (KeyM_CertElementIdType)8, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_Version_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelBackendCert_Version_002((KeyM_CertificateIdType)0, (KeyM_CertElementIdType)0, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_authKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_authKeyId_002((KeyM_CertificateIdType)0, (KeyM_CertElementIdType)10, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_basicConstraints_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_basicConstraints_002((KeyM_CertificateIdType)0, (KeyM_CertElementIdType)11, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_ext_subKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelBackendCert_ext_subKeyId_002((KeyM_CertificateIdType)0, (KeyM_CertElementIdType)9, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_subject_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelBackendCert_subject_002((KeyM_CertificateIdType)0, (KeyM_CertElementIdType)6, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendCert_validityNotAfter_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelBackendCert_validityNotAfter_002((KeyM_CertificateIdType)0, (KeyM_CertElementIdType)5, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_Version_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_Version_004((KeyM_CertificateIdType)1, (KeyM_CertElementIdType)0, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_authKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_authKeyId_004((KeyM_CertificateIdType)1, (KeyM_CertElementIdType)10, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_basicConstraints_004((KeyM_CertificateIdType)1, (KeyM_CertElementIdType)11, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_ext_subKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_ext_subKeyId_004((KeyM_CertificateIdType)1, (KeyM_CertElementIdType)9, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelBackendPeerCert_validityNotAfter_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelBackendPeerCert_validityNotAfter_004((KeyM_CertificateIdType)1, (KeyM_CertElementIdType)5, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_Issuer_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelEcuCert_Issuer_005((KeyM_CertificateIdType)2, (KeyM_CertElementIdType)3, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_SerialNo_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelEcuCert_SerialNo_005((KeyM_CertificateIdType)2, (KeyM_CertElementIdType)1, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelEcuCert_SubjectPublicKeyInfoKey_005((KeyM_CertificateIdType)2, (KeyM_CertElementIdType)8, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_Version_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelEcuCert_Version_005((KeyM_CertificateIdType)2, (KeyM_CertElementIdType)0, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_authKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_authKeyId_005((KeyM_CertificateIdType)2, (KeyM_CertElementIdType)11, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_specialEcu_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_specialEcu_005((KeyM_CertificateIdType)2, (KeyM_CertElementIdType)14, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_subKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_subKeyId_005((KeyM_CertificateIdType)2, (KeyM_CertElementIdType)10, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_ext_uniqueECUID_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelEcuCert_ext_uniqueECUID_005((KeyM_CertificateIdType)2, (KeyM_CertElementIdType)13, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_subject_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelEcuCert_subject_005((KeyM_CertificateIdType)2, (KeyM_CertElementIdType)6, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuCert_validityNotAfter_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelEcuCert_validityNotAfter_005((KeyM_CertificateIdType)2, (KeyM_CertElementIdType)5, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_Version_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_Version_006((KeyM_CertificateIdType)4, (KeyM_CertElementIdType)0, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_authKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_authKeyId_006((KeyM_CertificateIdType)4, (KeyM_CertElementIdType)11, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_specialEcu_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_specialEcu_006((KeyM_CertificateIdType)4, (KeyM_CertElementIdType)12, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_ext_subKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_ext_subKeyId_006((KeyM_CertificateIdType)4, (KeyM_CertElementIdType)10, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelEcuPeerCert_validityNotAfter_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelEcuPeerCert_validityNotAfter_006((KeyM_CertificateIdType)4, (KeyM_CertElementIdType)5, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Issuer_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_Issuer_003((KeyM_CertificateIdType)5, (KeyM_CertElementIdType)3, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SerialNo_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SerialNo_003((KeyM_CertificateIdType)5, (KeyM_CertElementIdType)1, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_SubjectPublicKeyInfoKey_003((KeyM_CertificateIdType)5, (KeyM_CertElementIdType)8, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_Version_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_Version_003((KeyM_CertificateIdType)5, (KeyM_CertElementIdType)0, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_authKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_authKeyId_003((KeyM_CertificateIdType)5, (KeyM_CertElementIdType)10, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_basicConstraints_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_basicConstraints_003((KeyM_CertificateIdType)5, (KeyM_CertElementIdType)11, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_ext_subKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_ext_subKeyId_003((KeyM_CertificateIdType)5, (KeyM_CertElementIdType)9, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_subject_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_subject_003((KeyM_CertificateIdType)5, (KeyM_CertElementIdType)6, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediateCert_validityNotAfter_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelIntermediateCert_validityNotAfter_003((KeyM_CertificateIdType)5, (KeyM_CertElementIdType)5, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_Version_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_Version_007((KeyM_CertificateIdType)6, (KeyM_CertElementIdType)0, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_authKeyId_007((KeyM_CertificateIdType)6, (KeyM_CertElementIdType)10, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_basicConstraints_005((KeyM_CertificateIdType)6, (KeyM_CertElementIdType)11, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_ext_subKeyId_007((KeyM_CertificateIdType)6, (KeyM_CertElementIdType)9, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelIntermediatePeerCert_validityNotAfter_007((KeyM_CertificateIdType)6, (KeyM_CertElementIdType)5, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_Issuer_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelRootCert_Issuer((KeyM_CertificateIdType)7, (KeyM_CertElementIdType)3, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_SerialNo_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelRootCert_SerialNo((KeyM_CertificateIdType)7, (KeyM_CertElementIdType)1, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelRootCert_SubjectPublicKeyInfoKey((KeyM_CertificateIdType)7, (KeyM_CertElementIdType)8, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_Version_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelRootCert_Version((KeyM_CertificateIdType)7, (KeyM_CertElementIdType)0, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_basicConstraints_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_basicConstraints((KeyM_CertificateIdType)7, (KeyM_CertElementIdType)10, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_keyUsage_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_keyUsage((KeyM_CertificateIdType)7, (KeyM_CertElementIdType)11, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_ext_subKeyId_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelRootCert_ext_subKeyId((KeyM_CertificateIdType)7, (KeyM_CertElementIdType)9, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_subject_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelRootCert_subject((KeyM_CertificateIdType)7, (KeyM_CertElementIdType)6, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_KeyM_KeyMCertificateElement_Ssa_TrustModelRootCert_validityNotAfter_CertificateElementGet(P2VAR(uint8, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateElementData, P2VAR(uint32, AUTOMATIC, RTE_SSA_KEYM_APPL_VAR) CertificateDataLength) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = KeyM_CertElementGet_Ssa_TrustModelRootCert_validityNotAfter((KeyM_CertificateIdType)7, (KeyM_CertElementIdType)5, CertificateElementData, CertificateDataLength);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)8, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)8, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_WriteBlock((NvM_BlockIdType)8, SrcPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)9, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)9, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_WriteBlock((NvM_BlockIdType)9, SrcPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)10, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)10, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_WriteBlock((NvM_BlockIdType)10, SrcPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt13_AclReplacement_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)11, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt13_AclReplacement_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)11, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt13_AclReplacement_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_WriteBlock((NvM_BlockIdType)11, SrcPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)12, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)12, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_WriteBlock((NvM_BlockIdType)12, SrcPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt2_SucCertVerif_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)13, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt2_SucCertVerif_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)13, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt2_SucCertVerif_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_WriteBlock((NvM_BlockIdType)13, SrcPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)14, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)14, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_WriteBlock((NvM_BlockIdType)14, SrcPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)15, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)15, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_WriteBlock((NvM_BlockIdType)15, SrcPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)16, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)16, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_WriteBlock((NvM_BlockIdType)16, SrcPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt6_RightsMgmt_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)17, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt6_RightsMgmt_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)17, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt6_RightsMgmt_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_WriteBlock((NvM_BlockIdType)17, SrcPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt7_SigVerif_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)18, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt7_SigVerif_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)18, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt7_SigVerif_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_WriteBlock((NvM_BlockIdType)18, SrcPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)19, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)19, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_WriteBlock((NvM_BlockIdType)19, SrcPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)20, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)20, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_WriteBlock((NvM_BlockIdType)20, SrcPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)21, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)21, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_WriteBlock((NvM_BlockIdType)21, SrcPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)22, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)22, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_WriteBlock((NvM_BlockIdType)22, SrcPtr);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_GetErrorStatus((NvM_BlockIdType)23, ErrorStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_SetRamBlockStatus((NvM_BlockIdType)23, RamBlockStatus);

  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_Ssa_SecLog_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 1505, 3673 */ /* MD_MSR_Rule8.7, MD_Rte_Qac */
{
  Std_ReturnType ret;

  ret = NvM_WriteBlock((NvM_BlockIdType)23, SrcPtr);

  return ret;
}


/**********************************************************************************************************************
 * Exclusive area access
 *********************************************************************************************************************/

FUNC(void, RTE_CODE) SchM_Enter_Adc_KernelData(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Adc_KernelData(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Adc_SrcRegAccess(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Adc_SrcRegAccess(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_ChEventStatus(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_ChEventStatus(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelConfigUpdate(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelConfigUpdate(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelFreezeResume(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelFreezeResume(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelHWTrigger(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelHWTrigger(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelInitDeinit(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelInitDeinit(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelStartStop(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelStartStop(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_ChannelSwitchBuffer(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_ChannelSwitchBuffer(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_InterruptStatus(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_InterruptStatus(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Dma_MEErrorStatus(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Dma_MEErrorStatus(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Dmu_Erase(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Dmu_Erase(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Dmu_Init(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Dmu_Init(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Dmu_Main(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Dmu_Main(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Dmu_ResumeErase(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Dmu_ResumeErase(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Dmu_UserContentCount(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Dmu_UserContentCount(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Fls_17_Dmu_Write(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Fls_17_Dmu_Write(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Gpt_Get100UsPredefTimerValue(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Gpt_Get100UsPredefTimerValue(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Gpt_Get1UsPredefTimerValue(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Gpt_Get1UsPredefTimerValue(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Gpt_Gpt12StartTimer(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Gpt_Gpt12StartTimer(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Gpt_GtmStartTimer(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Gpt_GtmStartTimer(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_TimerIp_CcuInterruptHandle(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_TimerIp_CcuInterruptHandle(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_TimerIp_CcuVariableupdate(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_TimerIp_CcuVariableupdate(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_TimerIp_EnableNotification(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_TimerIp_EnableNotification(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_TimerIp_EnableWakeup(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_TimerIp_EnableWakeup(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_TimerIp_GtmEnableEdgeCount(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_TimerIp_GtmEnableEdgeCount(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_TimerIp_GtmGetDutyCycle(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_TimerIp_GtmGetDutyCycle(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_TimerIp_ResetEdgeCount(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_TimerIp_ResetEdgeCount(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Icu_17_TimerIp_SetActivationCondition(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Icu_17_TimerIp_SetActivationCondition(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Mcu_AtomAgcReg(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Mcu_AtomAgcReg(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Mcu_TomTgcReg(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Mcu_TomTgcReg(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Pwm_17_GtmCcu6_HandleNotification(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Pwm_17_GtmCcu6_HandleNotification(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Pwm_17_GtmCcu6_PeriodAndDutyUpdate(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Pwm_17_GtmCcu6_PeriodAndDutyUpdate(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Smu_CmdAccess(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Smu_CmdAccess(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Smu_DriverAccess(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Smu_DriverAccess(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Buffer_Update(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Buffer_Update(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Cancel_Seq(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Cancel_Seq(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_ChannelLock(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_ChannelLock(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI0(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI0(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI1(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI1(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI2(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI2(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI3(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI3(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI4(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI4(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_Queue_Update_QSPI5(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_Queue_Update_QSPI5(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Spi_SyncLock(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Spi_SyncLock(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Wdg_17_Scu_ChangeMode(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Wdg_17_Scu_ChangeMode(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Wdg_17_Scu_CpuEndInit(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Wdg_17_Scu_CpuEndInit(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Wdg_17_Scu_TimerHandling(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Wdg_17_Scu_TimerHandling(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}


FUNC(void, RTE_CODE) SchM_Enter_Wdg_17_Scu_Trigger(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  SuspendAllInterrupts();
}

FUNC(void, RTE_CODE) SchM_Exit_Wdg_17_Scu_Trigger(void)
{
  /* RteAnalyzer(ExclusiveArea, ALL_INTERRUPT_BLOCKING) */
  ResumeAllInterrupts();
}



/**********************************************************************************************************************
 * RTE internal IOC replacements
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_IocSend_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(CONST(uint8, RTE_CONST) data0)
{
  Std_ReturnType result = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_head != Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_tail)
  {
    result = RTE_E_LIMIT;
  }
  else
  {
    if (Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_tail == 1U)
    {
      Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_tail = 0U;
    }
    else
    {
      Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_tail = 1U;
    }

    Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Queue[0] = data0;
  }

  return result;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_IocReceive_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data0)
{
  Std_ReturnType result;

  if (Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_tail == Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_head)
  {
    result = RTE_E_NO_DATA;
  }
  else
  {
    if (Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_head == 1U)
    {
      Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_head = 0U;
    }
    else
    {
      Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_head = 1U;
    }
    *data0 = Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Queue[0];
    result = RTE_E_OK;
  }
  return result;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_IocPeek_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data0)
{
  Std_ReturnType ret = RTE_E_NO_DATA; /* PRQA S 2981 */ /* MD_MSR_RetVal */


  if (Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_tail != Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_head)
  {
    *data0 = Rte_ioc_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Queue[0];
    ret = RTE_E_OK;
  }
  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_IocSend_Rte_M_Dcm_DcmEcuReset_DcmEcuReset(CONST(uint8, RTE_CONST) data0)
{
  Std_ReturnType result = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head != Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail)
  {
    result = RTE_E_LIMIT;
  }
  else
  {
    if (Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail == 1U)
    {
      Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail = 0U;
    }
    else
    {
      Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail = 1U;
    }

    Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_Queue[0] = data0;
  }

  return result;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_IocReceive_Rte_M_Dcm_DcmEcuReset_DcmEcuReset(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data0)
{
  Std_ReturnType result;

  if (Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail == Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head)
  {
    result = RTE_E_NO_DATA;
  }
  else
  {
    if (Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head == 1U)
    {
      Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head = 0U;
    }
    else
    {
      Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head = 1U;
    }
    *data0 = Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_Queue[0];
    result = RTE_E_OK;
  }
  return result;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_IocPeek_Rte_M_Dcm_DcmEcuReset_DcmEcuReset(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) data0)
{
  Std_ReturnType ret = RTE_E_NO_DATA; /* PRQA S 2981 */ /* MD_MSR_RetVal */


  if (Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_tail != Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_head)
  {
    *data0 = Rte_ioc_Rte_M_Dcm_DcmEcuReset_DcmEcuReset_Queue[0];
    ret = RTE_E_OK;
  }
  return ret;
}



/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_BswMSwitchPort_SwcDiagCommunicationMode_Mode(uint8 nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 internalIndexNextMode = Rte_GetInternalModeIndex_BswM_CommunicationMode(nextMode);
  uint8 internalIndexCurrentMode;
  uint8 currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_BswM_Switch_BswMSwitchPort_SwcDiagCommunicationMode_Mode;
  internalIndexCurrentMode = Rte_GetInternalModeIndex_BswM_CommunicationMode(currentMode);
  if (internalIndexNextMode >= 3U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (internalIndexCurrentMode >= 3U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_BswM_Switch_BswMSwitchPort_SwcDiagCommunicationMode_Mode = nextMode;
    ResumeOSInterrupts();
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(BswM_ESH_Mode nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 internalIndexNextMode = Rte_GetInternalModeIndex_BswM_ESH_Mode(nextMode);
  uint8 internalIndexCurrentMode;
  BswM_ESH_Mode currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;
  internalIndexCurrentMode = Rte_GetInternalModeIndex_BswM_ESH_Mode(currentMode);
  if (internalIndexNextMode >= 5U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (internalIndexCurrentMode >= 5U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = nextMode;
    ResumeOSInterrupts();
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(BswM_ESH_Mode, RTE_CODE) Rte_Mode_BswM_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  BswM_ESH_Mode curMode;
  curMode = Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;
  return curMode;
}


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_Mode_Cdd_MBBL_EcuStatHandler_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  if (Rte_AckFlags.Rte_ModeSwitchAck_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Ack == 0U)
  {
    curMode = RTE_TRANSITION_Cdd_MBBL_EcuStatHandler_DcmDiagnosticSessionControl;
  }
  else
  {
    curMode = Rte_ModeMachine_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl;
  }
  return curMode;
}


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_Mode_Ct_MBBL_ResetManager_Pp_DcmEcuReset_DcmEcuReset(P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_RESETMANAGER_APPL_VAR) previousMode, P2VAR(uint8, AUTOMATIC, RTE_CT_MBBL_RESETMANAGER_APPL_VAR) nextMode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  if (Rte_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack == 0U)
  {
    curMode = RTE_TRANSITION_Ct_MBBL_ResetManager_DcmEcuReset;
    (void)Rte_IocPeek_Rte_M_Dcm_DcmEcuReset_DcmEcuReset(nextMode);
    *(previousMode) = Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset;
  }
  else
  {
    curMode = Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset;
    *(previousMode) = curMode;
    *(nextMode) = curMode;
  }
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  return curMode;
}


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_Mode_Ct_MBBL_SsaAppl_Coding_P_MDG_Coding_Stat_ST3_Coding_Status(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  curMode = Rte_ModeMachine_Ssa_Coding_Coding_Mode_CodingStatus;
  return curMode;
}


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_Mode_DIA_AC_DiagOnCAN_EcuM_CurrentMode_currentMode(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  curMode = Rte_ModeMachine_EcuM_currentMode_currentMode;
  return curMode;
}


/**********************************************************************************************************************
 * Transmission/Mode Switch Acknowledgement handling (Rte_Feedback/Rte_SwitchAck)
 *********************************************************************************************************************/

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_Dcm_DcmEcuReset_DcmEcuReset(void)
{
  Std_ReturnType ret = RTE_E_TRANSMIT_ACK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  if (Rte_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack == 0U)
  {
    ret = RTE_E_NO_DATA;
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_Dcm_DcmModeRapidPowerShutDown_DcmModeRapidPowerShutDown(void)
{

  return RTE_E_UNCONNECTED;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FL_BODY3_8uqv9blm85ehm0msat385m76v_03d5f5f6(Dcm_CommunicationModeType nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */


  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727_DcmCommunicationControl_ComMConf_ComMChannel_RBTM_FR_BODY3_4xwwtd59665s787n6ctawh7k8_23a94727(Dcm_CommunicationModeType nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */


  return ret;
}

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmControlDtcSetting_DcmControlDtcSetting(Dcm_ControlDtcSettingType nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 internalIndexNextMode = Rte_GetInternalModeIndex_Dcm_DcmControlDtcSetting(nextMode);
  uint8 internalIndexCurrentMode;
  Dcm_ControlDtcSettingType currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_Dcm_DcmControlDtcSetting_DcmControlDtcSetting;
  internalIndexCurrentMode = Rte_GetInternalModeIndex_Dcm_DcmControlDtcSetting(currentMode);
  if (internalIndexNextMode >= 2U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (internalIndexCurrentMode >= 2U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_Dcm_DcmControlDtcSetting_DcmControlDtcSetting = nextMode;
    ResumeOSInterrupts();
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 internalIndexNextMode = Rte_GetInternalModeIndex_Dcm_DcmDiagnosticSessionControl(nextMode);
  uint8 internalIndexCurrentMode;
  Dcm_DiagnosticSessionControlType currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl;
  internalIndexCurrentMode = Rte_GetInternalModeIndex_Dcm_DcmDiagnosticSessionControl(currentMode);
  if (internalIndexNextMode >= 4U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (Rte_AckFlags.Rte_ModeSwitchAck_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Ack == 0U)
  {
    ret = RTE_E_LIMIT;
    ResumeOSInterrupts();
  }
  else if (internalIndexCurrentMode >= 4U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_EventMaskType ModeSwitchEventMask;

    ModeSwitchEventMask = Rte_GetModeExitEventMask_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(internalIndexCurrentMode); /* PRQA S 2986 */ /* MD_Rte_2986 */
    ModeSwitchEventMask |= Rte_GetModeEntryEventMask_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(internalIndexNextMode); /* PRQA S 2986 */ /* MD_Rte_2986 */

    if (ModeSwitchEventMask != (Rte_EventMaskType)0)
    {
      ret = Rte_IocSend_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(nextMode);

      Rte_AckFlags.Rte_ModeSwitchAck_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Ack = 0U;
      ResumeOSInterrupts();

      (void)SetEvent(ApplTask_Core0_LowPrio, ModeSwitchEventMask); /* PRQA S 3417 */ /* MD_Rte_Os */
    }
    else
    {
      Rte_ModeMachine_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl = nextMode;
      Rte_AckFlags.Rte_ModeSwitchAck_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Ack = 1U;
      ResumeOSInterrupts();
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmEcuReset_DcmEcuReset(Dcm_EcuResetType nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  uint8 internalIndexNextMode = Rte_GetInternalModeIndex_Dcm_DcmEcuReset(nextMode);
  uint8 internalIndexCurrentMode;
  Dcm_EcuResetType currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset;
  internalIndexCurrentMode = Rte_GetInternalModeIndex_Dcm_DcmEcuReset(currentMode);
  if (internalIndexNextMode >= 7U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (Rte_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack == 0U)
  {
    ret = RTE_E_LIMIT;
    ResumeOSInterrupts();
  }
  else if (internalIndexCurrentMode >= 7U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_EventMaskType ModeSwitchEventMask;

    ModeSwitchEventMask = Rte_GetModeEntryEventMask_Dcm_DcmEcuReset_DcmEcuReset(internalIndexNextMode); /* PRQA S 2986 */ /* MD_Rte_2986 */

    if (ModeSwitchEventMask != (Rte_EventMaskType)0)
    {
      ret = Rte_IocSend_Rte_M_Dcm_DcmEcuReset_DcmEcuReset(nextMode);

      Rte_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack = 0U;
      ResumeOSInterrupts();

      (void)SetEvent(ApplTask_Core0_LowPrio, ModeSwitchEventMask); /* PRQA S 3417 */ /* MD_Rte_Os */
    }
    else
    {
      Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset = nextMode;
      Rte_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack = 1U;
      ResumeOSInterrupts();
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Dcm_DcmModeRapidPowerShutDown_DcmModeRapidPowerShutDown(Dcm_ModeRapidPowerShutDownType nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */


  return ret;
}


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_Mode_DiagFunction_CommunicationModeMSI_Mode(P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) previousMode, P2VAR(uint8, AUTOMATIC, RTE_DIAGFUNCTION_APPL_VAR) nextMode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  curMode = Rte_ModeMachine_BswM_Switch_BswMSwitchPort_SwcDiagCommunicationMode_Mode;
  *(previousMode) = curMode;
  *(nextMode) = curMode;
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  return curMode;
}


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_Mode_ERH_AC_ErrorHandler_prrControlAECSetting_DcmControlDtcSetting(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  uint8 curMode;
  curMode = Rte_ModeMachine_Dcm_DcmControlDtcSetting_DcmControlDtcSetting;
  return curMode;
}


/**********************************************************************************************************************
 * Transmission/Mode Switch Acknowledgement handling (Rte_Feedback/Rte_SwitchAck)
 *********************************************************************************************************************/

/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
FUNC(Std_ReturnType, RTE_CODE) Rte_SwitchAck_EcuM_currentMode_currentMode(void)
{
  Std_ReturnType ret = RTE_E_TRANSMIT_ACK; /* PRQA S 2981 */ /* MD_MSR_RetVal */


  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_EcuM_currentMode_currentMode(EcuM_StateType nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  EcuM_StateType currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_EcuM_currentMode_currentMode;
  if (nextMode >= 6U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (currentMode >= 6U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_EcuM_currentMode_currentMode = nextMode;
    Rte_AckFlags.Rte_ModeSwitchAck_EcuM_currentMode_currentMode_Ack = 1U;
    ResumeOSInterrupts();
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

/* PRQA S 6050 1 */ /* MD_MSR_STCAL */
FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_Ssa_Coding_Coding_Mode_CodingStatus(Coding_ModeType nextMode) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  Coding_ModeType currentMode;
  SuspendOSInterrupts();
  currentMode = Rte_ModeMachine_Ssa_Coding_Coding_Mode_CodingStatus;
  if (nextMode >= 3U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else if (currentMode >= 3U)
  {
    ResumeOSInterrupts();
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_ModeMachine_Ssa_Coding_Coding_Mode_CodingStatus = nextMode;
    ResumeOSInterrupts();
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(Dcm_DiagnosticSessionControlType, RTE_CODE) Rte_Mode_Ssa_RightsM_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(P2VAR(Dcm_DiagnosticSessionControlType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) previousMode, P2VAR(Dcm_DiagnosticSessionControlType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) nextMode) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  Dcm_DiagnosticSessionControlType curMode;
  SuspendOSInterrupts();
  if (Rte_AckFlags.Rte_ModeSwitchAck_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Ack == 0U)
  {
    curMode = RTE_TRANSITION_Ssa_RightsM_DcmDiagnosticSessionControl;
    (void)Rte_IocPeek_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(nextMode);
    *(previousMode) = Rte_ModeMachine_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl;
  }
  else
  {
    curMode = Rte_ModeMachine_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl;
    *(previousMode) = curMode;
    *(nextMode) = curMode;
  }
  ResumeOSInterrupts();
  return curMode;
}


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_WdgM_globalmode_Core0_currentMode(WdgMMode nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */


  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_WdgM_mode_WdgMSupervisedEntity_currentMode(WdgMMode nextMode) /* PRQA S 1505, 3206 */ /* MD_MSR_Rule8.7, MD_Rte_3206 */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */


  return ret;
}
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbk_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx_Left(void);
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbk_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx_Left(void);
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbk_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx_Left(void);
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbk_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_Left(void);
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbk_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_Right(void);
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbk_PN14_DDP_Sw_Stat_ST3_568ad7e6_Rx_Left(void);
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbk_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx_Left(void);
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbk_VehSpd_Disp_ST3_4922a2fd_Rx_Left(void);
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx_Left(void);
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx_Left(void);
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx_Left(void);
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx_Left(void);
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_VehSpd_Disp_ST3_4922a2fd_Rx_Left(void);


/**********************************************************************************************************************
 * COM-Callbacks for DataReceivedEvent triggered runnables, inter-ECU client/server communication, for queued com. and for Rx timeout / Rx inv. flag (reset)
 *********************************************************************************************************************/

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbk_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx_Left(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_RxTimeoutFlags.Rte_RxTimeout_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx = 0U;
    Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_BeltHdOvr_FL_Stat_ST3_3489841d_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_RxTimeoutFlags.Rte_RxTimeout_Graph_3c51f51b5e8aaf813b8f9a89a7827e7c_BeltHdOvr_XX_Stat_ST3 = 0U;
    Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_BeltHdOvr_FR_Stat_ST3_0eefd507_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_RxTimeoutFlags.Rte_RxTimeout_Graph_3c51f51b5e8aaf813b8f9a89a7827e7c_BeltHdOvr_XX_Stat_ST3 = 0U;
    Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbk_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx_Left(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_RxTimeoutFlags.Rte_RxTimeout_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx = 0U;
    Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbk_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx_Left(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_RxTimeoutFlags.Rte_RxTimeout_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx = 0U;
    Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbk_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_Left(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: Ssa_SecLog_IgnitionStatusChanged */
    (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_Ssa_SecLog_Ssa_SecLog_IgnitionStatusChanged); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbk_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_Right(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: Ssa_SecLog_IgnitionStatusChanged */
    (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_Ssa_SecLog_Ssa_SecLog_IgnitionStatusChanged); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbk_PN14_DDP_Sw_Stat_ST3_568ad7e6_Rx_Left(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: Ssa_TimeM_PowernetMgmtStateChanged */
    (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_Ssa_TimeM_Ssa_TimeM_PowernetMgmtStateChanged); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbk_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx_Left(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_RxTimeoutFlags.Rte_RxTimeout_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx = 0U;
    Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbk_VehSpd_Disp_ST3_4922a2fd_Rx_Left(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_RxTimeoutFlags.Rte_RxTimeout_VehSpd_Disp_ST3_4922a2fd_Rx = 0U;
    Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx(void)
{
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_COMCbk_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx_Left();
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx(void)
{
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_COMCbk_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx_Left();
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx(void)
{
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_COMCbk_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx_Left();
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx(void)
{
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_COMCbk_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_Left();
  }
  if (Rte_VarCfgPtr == &Rte_Config_Right)
  {
    Rte_COMCbk_Ign_Stat_Pr5_ST3_csgs1dv6drms80o1i9p49677w_7bdae87d_Rx_Right();
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_PN14_DDP_Sw_Stat_ST3_568ad7e6_Rx(void)
{
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_COMCbk_PN14_DDP_Sw_Stat_ST3_568ad7e6_Rx_Left();
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_PS_Curve_FL_Rq_HU_ST3_6cd299ba_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_RxTimeoutFlags.Rte_RxTimeout_CIL_R_PS_Curve_FL_Rq_HU_ST3_PS_Curve_FL_Rq_HU_ST3 = 0U;
    Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_PS_Curve_FR_Rq_HU_ST3_90527677_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_RxTimeoutFlags.Rte_RxTimeout_CIL_R_PS_Curve_FR_Rq_HU_ST3_PS_Curve_FR_Rq_HU_ST3 = 0U;
    Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx(void)
{
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_COMCbk_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx_Left();
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_PT4_PTCoor9_Pr5_ST3_6r95o81sst3tk9w2lzz600cw3_5dfe4b97_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_RxTimeoutFlags.Rte_RxTimeout_BeltAdjFunction_R_PT4_PTCoor9_Pr5_ST3_PT4_PTCoor9_Pr5_ST3 = 0U;
    Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_RxTimeoutFlags.Rte_RxTimeout_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx = 0U;
    Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_VSS_TP_Auth_ST3_6j4id7sghlvlbroli4wjozjik_2ac87786_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: Ssa_BcTp_ReceiveDiagnosticAuthentication */
    (void)SetEvent(ApplTask_Core0_HighPrio, Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveDiagnosticAuthentication); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_VSS_TP_RealTmOffset_ST3_1t7vc44gftc0wv35k5kgc2in9_d3385ce4_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: Ssa_BcTp_ReceiveRealTimeOffset */
    (void)SetEvent(ApplTask_Core0_HighPrio, Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveRealTimeOffset); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_VSS_TP_SecTickCount_Lvl2_ST3_9eubq13iosat764o0lqh5xb6r_01efe31e_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_RxTimeoutFlags.Rte_RxTimeout_VSS_TP_SecTickCount_Lvl2_ST3_9eubq13iosat764o0lqh5xb6r_01efe31e_Rx = 0U;
    Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    /* scheduled trigger for runnables: Ssa_BcTp_ReceiveTickCount */
    (void)SetEvent(ApplTask_Core0_HighPrio, Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveTickCount); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_VSS_TP_SharedSecret_ST3_8pj4t8t4rm3tw3pk5hj7vonti_d9a21e4b_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: Ssa_BcTp_ReceiveSharedSecret */
    (void)SetEvent(ApplTask_Core0_HighPrio, Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveSharedSecret); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_VSS_TP_VIN_ST3_bz1xsv84cxzl09j028gn39p69_f31ab3e3_Rx(void)
{

  if (Rte_InitState == RTE_STATE_INIT)
  {
    Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    Rte_RxTimeoutFlags.Rte_RxTimeout_VSS_TP_VIN_ST3_bz1xsv84cxzl09j028gn39p69_f31ab3e3_Rx = 0U;
    Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
    /* scheduled trigger for runnables: Ssa_BcTp_ReceiveVIN */
    (void)SetEvent(ApplTask_Core0_HighPrio, Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveVIN); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */

/* PRQA S 6010, 6050 1 */ /* MD_MSR_STPTH, MD_MSR_STCAL */
FUNC(void, RTE_CODE) Rte_COMCbk_VehSpd_Disp_ST3_4922a2fd_Rx(void)
{
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_COMCbk_VehSpd_Disp_ST3_4922a2fd_Rx_Left();
  }
} /* PRQA S 6010, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCAL */


/**********************************************************************************************************************
 * COM Callbacks for Rx Timeout Notification
 *********************************************************************************************************************/

RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx_Left(void)
{

  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RxTimeoutFlags.Rte_RxTimeout_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx = 1U;
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BeltHdOvr_FL_Stat_ST3_3489841d_Rx(void)
{

  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RxTimeoutFlags.Rte_RxTimeout_Graph_3c51f51b5e8aaf813b8f9a89a7827e7c_BeltHdOvr_XX_Stat_ST3 = 1U;
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BeltHdOvr_FR_Stat_ST3_0eefd507_Rx(void)
{

  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RxTimeoutFlags.Rte_RxTimeout_Graph_3c51f51b5e8aaf813b8f9a89a7827e7c_BeltHdOvr_XX_Stat_ST3 = 1U;
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
}

RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx_Left(void)
{

  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RxTimeoutFlags.Rte_RxTimeout_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx = 1U;
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
}

RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx_Left(void)
{

  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RxTimeoutFlags.Rte_RxTimeout_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx = 1U;
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
}

RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx_Left(void)
{

  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RxTimeoutFlags.Rte_RxTimeout_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx = 1U;
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
}

RTE_LOCAL FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_VehSpd_Disp_ST3_4922a2fd_Rx_Left(void)
{

  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RxTimeoutFlags.Rte_RxTimeout_VehSpd_Disp_ST3_4922a2fd_Rx = 1U;
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx(void)
{
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_COMCbkRxTOut_Bckl_Sw_Fx_Stat_Pr5_ST3_dihag5a55iw4h5qk539fx0kup_4c948f24_Rx_Left();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx(void)
{
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_COMCbkRxTOut_BltSlckDec_Md_Rq_HU_ST3_64a95ccf_Rx_Left();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx(void)
{
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_COMCbkRxTOut_EVC_CfgList_01_08_Pr5_ST3_co3q1mwsf7pwxo2ix5jryc04x_3a43a00a_Rx_Left();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_PS_Curve_FL_Rq_HU_ST3_6cd299ba_Rx(void)
{

  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RxTimeoutFlags.Rte_RxTimeout_CIL_R_PS_Curve_FL_Rq_HU_ST3_PS_Curve_FL_Rq_HU_ST3 = 1U;
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_PS_Curve_FR_Rq_HU_ST3_90527677_Rx(void)
{

  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RxTimeoutFlags.Rte_RxTimeout_CIL_R_PS_Curve_FR_Rq_HU_ST3_PS_Curve_FR_Rq_HU_ST3 = 1U;
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx(void)
{
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_COMCbkRxTOut_PT4_PTCoor4_Pr5_ST3_af4fxb1ykieox3itqdfzs0kpb_2277a854_Rx_Left();
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_PT4_PTCoor9_Pr5_ST3_6r95o81sst3tk9w2lzz600cw3_5dfe4b97_Rx(void)
{

  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RxTimeoutFlags.Rte_RxTimeout_BeltAdjFunction_R_PT4_PTCoor9_Pr5_ST3_PT4_PTCoor9_Pr5_ST3 = 1U;
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx(void)
{

  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RxTimeoutFlags.Rte_RxTimeout_SBeltTens_SP_Lvl_Pr5_ST3_4tqpkri37441o5ht9g9ekmyzh_4719328f_Rx = 1U;
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_VSS_TP_SecTickCount_Lvl2_ST3_9eubq13iosat764o0lqh5xb6r_01efe31e_Rx(void)
{

  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RxTimeoutFlags.Rte_RxTimeout_VSS_TP_SecTickCount_Lvl2_ST3_9eubq13iosat764o0lqh5xb6r_01efe31e_Rx = 1U;
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: Ssa_BcTp_ReceiveTickCountTimeout */
    (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveTickCountTimeout); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_VSS_TP_VIN_ST3_bz1xsv84cxzl09j028gn39p69_f31ab3e3_Rx(void)
{

  Rte_DisableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
  Rte_RxTimeoutFlags.Rte_RxTimeout_VSS_TP_VIN_ST3_bz1xsv84cxzl09j028gn39p69_f31ab3e3_Rx = 1U;
  Rte_EnableAllInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */

  if (Rte_InitState == RTE_STATE_INIT)
  {
    /* scheduled trigger for runnables: Ssa_BcTp_ReceiveVINTimeout */
    (void)SetEvent(ApplTask_Core0_LowPrio, Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveVINTimeout); /* PRQA S 3417 */ /* MD_Rte_Os */
  }
}

FUNC(void, RTE_CODE) Rte_COMCbkRxTOut_VehSpd_Disp_ST3_4922a2fd_Rx(void)
{
  if (Rte_VarCfgPtr == &Rte_Config_Left)
  {
    Rte_COMCbkRxTOut_VehSpd_Disp_ST3_4922a2fd_Rx_Left();
  }
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/
#define RTE_START_SEC_APPLBACKGROUNDTASK_CORE0_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     ApplBackgroundTask_Core0
 * Priority: 5
 * Schedule: FULL
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(ApplBackgroundTask_Core0) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{

  /* call runnable */
  Ssa_ProcCtrl_ServiceDispatcher(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_APPLBACKGROUNDTASK_CORE0_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_APPLINITTASK_CORE0_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     ApplInitTask_Core0
 * Priority: 90
 * Schedule: NON
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(ApplInitTask_Core0) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{

  /* call runnable */
  Ssa_BcTp_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Ssa_Cdd_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Ssa_CertP_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Ssa_Coding_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Ssa_FvM_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Ssa_KeyM_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Ssa_ProcCtrl_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Ssa_RightsM_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Ssa_SecLog_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Ssa_TimeM_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Ct_MBBL_SsaAppl_ProjectSpecific_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Ct_MBBL_SsaAppl_General_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Ct_MBBL_SsaAppl_Coding_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Ct_MBBL_SsaAppl_TrustModel_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  BaseFunction_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  BeltAdjFunction_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  BeltTensionerFunction_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Ct_MBBL_ResetPreconditionChecker_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Ct_MBBL_ResetManager_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Cdd_MBBL_ResetExecutor_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  Cdd_MBBL_EcuStatHandler_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  MMG_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  DiagFunction_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  PAL_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  PMP_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  RCM_runConfirmResetCause(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  ERH_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  BMM_runInit(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  ATM_Init(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  /* call runnable */
  SCM_runRestoreSystemContext(); /* PRQA S 2987 */ /* MD_Rte_2987 */

  (void)TerminateTask(); /* PRQA S 3417 */ /* MD_Rte_Os */
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_APPLINITTASK_CORE0_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_APPLTASK_CORE0_HIGHPRIO_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     ApplTask_Core0_HighPrio
 * Priority: 50
 * Schedule: FULL
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(ApplTask_Core0_HighPrio) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;) /* FETA_RTE_EXTENDED_TASK */
  {
    (void)WaitEvent(Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveDiagnosticAuthentication | Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveRealTimeOffset | Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveSharedSecret | Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveTickCount | Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveVIN); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(ApplTask_Core0_HighPrio, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveDiagnosticAuthentication | Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveRealTimeOffset | Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveSharedSecret | Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveTickCount | Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveVIN)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveDiagnosticAuthentication) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_BcTp_ReceiveDiagnosticAuthentication(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveRealTimeOffset) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_BcTp_ReceiveRealTimeOffset(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveSharedSecret) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_BcTp_ReceiveSharedSecret(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveTickCount) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_BcTp_ReceiveTickCount(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveVIN) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_BcTp_ReceiveVIN(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_APPLTASK_CORE0_HIGHPRIO_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_APPLTASK_CORE0_LOWPRIO_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     ApplTask_Core0_LowPrio
 * Priority: 20
 * Schedule: FULL
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(ApplTask_Core0_LowPrio) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;
  EventMaskType evRun;

  for(;;) /* FETA_RTE_EXTENDED_TASK */
  {
    (void)WaitEvent(Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_100ms | Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_10ms | Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_2ms | Rte_Ev_OnEntry_ApplTask_Core0_LowPrio_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_EXTENDED_SESSION | Rte_Ev_Run_BaseFunction_BaseFunction_Main | Rte_Ev_Run_Cdd_MBBL_EcuStatHandler_DiagSessionChange_ExitExtendedSession | Rte_Ev_Run_Ct_MBBL_ResetManager_ResetServiceExecution | Rte_Ev_Run_DIA_DIA_cyclicProcessingTask | Rte_Ev_Run_DiagFunction_DiagFunction_MainFunction | Rte_Ev_Run_DiagFunction_RoELite_ObsolescenceDataHandler | Rte_Ev_Run_DiagFunction_RoELite_SecureEventNotification | Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveTickCountTimeout | Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveVINTimeout | Rte_Ev_Run_Ssa_Coding_Ssa_Coding_VIN_Receive | Rte_Ev_Run_Ssa_FvM_Ssa_FvM_Com_ReceiveTickCount | Rte_Ev_Run_Ssa_KeyM_Ssa_KeyM_Com_VehicleSharedSecretNotification | Rte_Ev_Run_Ssa_RightsM_Ssa_RightsM_Com_ReceiveBroadcastAuthentication | Rte_Ev_Run_Ssa_RightsM_Ssa_RightsM_DiagnosticSessionChangeIndication | Rte_Ev_Run_Ssa_SecLog_Ssa_SecLog_IgnitionStatusChanged | Rte_Ev_Run_Ssa_SecLog_Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast | Rte_Ev_Run_Ssa_TimeM_Ssa_TimeM_Com_ReceiveRealTimeOffset | Rte_Ev_Run_Ssa_TimeM_Ssa_TimeM_PowernetMgmtStateChanged); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(ApplTask_Core0_LowPrio, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_100ms | Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_10ms | Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_2ms | Rte_Ev_OnEntry_ApplTask_Core0_LowPrio_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_EXTENDED_SESSION | Rte_Ev_Run_BaseFunction_BaseFunction_Main | Rte_Ev_Run_Cdd_MBBL_EcuStatHandler_DiagSessionChange_ExitExtendedSession | Rte_Ev_Run_Ct_MBBL_ResetManager_ResetServiceExecution | Rte_Ev_Run_DIA_DIA_cyclicProcessingTask | Rte_Ev_Run_DiagFunction_DiagFunction_MainFunction | Rte_Ev_Run_DiagFunction_RoELite_ObsolescenceDataHandler | Rte_Ev_Run_DiagFunction_RoELite_SecureEventNotification | Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveTickCountTimeout | Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveVINTimeout | Rte_Ev_Run_Ssa_Coding_Ssa_Coding_VIN_Receive | Rte_Ev_Run_Ssa_FvM_Ssa_FvM_Com_ReceiveTickCount | Rte_Ev_Run_Ssa_KeyM_Ssa_KeyM_Com_VehicleSharedSecretNotification | Rte_Ev_Run_Ssa_RightsM_Ssa_RightsM_Com_ReceiveBroadcastAuthentication | Rte_Ev_Run_Ssa_RightsM_Ssa_RightsM_DiagnosticSessionChangeIndication | Rte_Ev_Run_Ssa_SecLog_Ssa_SecLog_IgnitionStatusChanged | Rte_Ev_Run_Ssa_SecLog_Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast | Rte_Ev_Run_Ssa_TimeM_Ssa_TimeM_Com_ReceiveRealTimeOffset | Rte_Ev_Run_Ssa_TimeM_Ssa_TimeM_PowernetMgmtStateChanged)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_Coding_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      Ssa_KeyM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      Ssa_FvM_Mainfunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      Ssa_RightsM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      Ssa_SecLog_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      Ssa_TimeM_Mainfunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveTickCountTimeout) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_BcTp_ReceiveTickCountTimeout(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Ssa_Coding_Ssa_Coding_VIN_Receive) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_Coding_VIN_Receive(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Ssa_FvM_Ssa_FvM_Com_ReceiveTickCount) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_FvM_Com_ReceiveTickCount(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    (void)GetEvent(ApplTask_Core0_LowPrio, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if ((evRun & Rte_Ev_Run_Ssa_FvM_Ssa_FvM_Com_ReceiveTickCountTimeout) != (EventMaskType)0)
    {
      (void)ClearEvent(Rte_Ev_Run_Ssa_FvM_Ssa_FvM_Com_ReceiveTickCountTimeout); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      Ssa_FvM_Com_ReceiveTickCountTimeout(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Ssa_KeyM_Ssa_KeyM_Com_VehicleSharedSecretNotification) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_KeyM_Com_VehicleSharedSecretNotification(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Ssa_RightsM_Ssa_RightsM_Com_ReceiveBroadcastAuthentication) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_RightsM_Com_ReceiveBroadcastAuthentication(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Cdd_MBBL_EcuStatHandler_DiagSessionChange_ExitExtendedSession) != (EventMaskType)0)
    {
      /* call runnable */
      DiagSessionChange_ExitExtendedSession(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Ssa_TimeM_Ssa_TimeM_PowernetMgmtStateChanged) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_TimeM_PowernetMgmtStateChanged(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Ssa_SecLog_Ssa_SecLog_IgnitionStatusChanged) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_SecLog_IgnitionStatusChanged(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Ssa_SecLog_Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Ssa_TimeM_Ssa_TimeM_Com_ReceiveRealTimeOffset) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_TimeM_Com_ReceiveRealTimeOffset(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    (void)GetEvent(ApplTask_Core0_LowPrio, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if ((evRun & Rte_Ev_Run_Ssa_TimeM_Ssa_TimeM_ReceiveChangeTickCountEvent) != (EventMaskType)0)
    {
      (void)ClearEvent(Rte_Ev_Run_Ssa_TimeM_Ssa_TimeM_ReceiveChangeTickCountEvent); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      Ssa_TimeM_ReceiveChangeTickCountEvent(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Ct_MBBL_SsaAppl_Coding_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_BaseFunction_BaseFunction_Main) != (EventMaskType)0)
    {
      /* call runnable */
      BaseFunction_Main(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_100ms) != (EventMaskType)0)
    {
      /* call runnable */
      BeltAdjFunction_Main(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      BeltTensionerFunction_Main(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Ct_MBBL_ResetManager_ResetServiceExecution) != (EventMaskType)0)
    {
      /* call runnable */
      ResetServiceExecution(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_Ssa_BcTp_Ssa_BcTp_ReceiveVINTimeout) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_BcTp_ReceiveVINTimeout(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    (void)GetEvent(ApplTask_Core0_LowPrio, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if ((evRun & Rte_Ev_Run_Ssa_Coding_Ssa_Coding_VIN_Receive_Timeout) != (EventMaskType)0)
    {
      (void)ClearEvent(Rte_Ev_Run_Ssa_Coding_Ssa_Coding_VIN_Receive_Timeout); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      Ssa_Coding_VIN_Receive_Timeout(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_OnEntry_ApplTask_Core0_LowPrio_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_EXTENDED_SESSION) != (EventMaskType)0)
    {
      /* call runnable */
      DiagSessionChange_EnterExtendedSession(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if (((ev & Rte_Ev_Run_Ssa_RightsM_Ssa_RightsM_DiagnosticSessionChangeIndication) != (EventMaskType)0) || ((ev & Rte_Ev_OnEntry_ApplTask_Core0_LowPrio_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_EXTENDED_SESSION) != (EventMaskType)0))
    {
      /* call runnable */
      Ssa_RightsM_DiagnosticSessionChangeIndication(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      CIL_runCANToAppli(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      CIL_runAppliToCAN(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      MMG_runManageModeDelays(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      MMG_runUpdateModeStatus(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      MMG_runPreSafeRecorder(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_100ms) != (EventMaskType)0)
    {
      /* call runnable */
      PMP_runComputeDeficiencyLevel(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_2ms) != (EventMaskType)0)
    {
      /* call runnable */
      PAL_runMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Ssa_Cdd_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      CIL_runManageMeasurementFrame(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      EOL_runMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_2ms) != (EventMaskType)0)
    {
      /* call runnable */
      ATM_runMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      BMM_runMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_DIA_DIA_cyclicProcessingTask) != (EventMaskType)0)
    {
      /* call runnable */
      DIA_cyclicProcessingTask(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    (void)GetEvent(ApplTask_Core0_LowPrio, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if (((ev & Rte_Ev_Run_DiagFunction_RoELite_SecureEventNotification) != (EventMaskType)0) || ((evRun & Rte_Ev_Run_DiagFunction_RoELite_SecureEventNotification) != (EventMaskType)0))
    {
      (void)ClearEvent(Rte_Ev_Run_DiagFunction_RoELite_SecureEventNotification); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      RoELite_SecureEventNotification(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    (void)GetEvent(ApplTask_Core0_LowPrio, &evRun); /* PRQA S 3417 */ /* MD_Rte_Os */
    if ((evRun & Rte_Ev_Run_DiagFunction_RoELite_AvailabilityDataHandler) != (EventMaskType)0)
    {
      (void)ClearEvent(Rte_Ev_Run_DiagFunction_RoELite_AvailabilityDataHandler); /* PRQA S 3417 */ /* MD_Rte_Os */

      /* call runnable */
      RoELite_AvailabilityDataHandler(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_DiagFunction_RoELite_ObsolescenceDataHandler) != (EventMaskType)0)
    {
      /* call runnable */
      RoELite_ObsolescenceDataHandler(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_2ms) != (EventMaskType)0)
    {
      /* call runnable */
      SCM_runManageSystemContext(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_ApplTask_Core0_LowPrio_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      SCM_runMonitoreExecutedCycle(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      MMG_runUpdateNVMBlocks(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      ERH_cyclic(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_DiagFunction_DiagFunction_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      DiagFunction_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if (((ev & (Rte_Ev_OnEntry_ApplTask_Core0_LowPrio_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_EXTENDED_SESSION | Rte_Ev_Run_Cdd_MBBL_EcuStatHandler_DiagSessionChange_ExitExtendedSession | Rte_Ev_Run_Ssa_RightsM_Ssa_RightsM_DiagnosticSessionChangeIndication)) != (EventMaskType)0) && (Rte_AckFlags.Rte_ModeSwitchAck_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Ack == 0U))
    {
      Dcm_DiagnosticSessionControlType nextMode = 0U; /* PRQA S 2982 */ /* MD_Rte_2982 */

      Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
      (void)Rte_IocReceive_Rte_M_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(&nextMode);

      Rte_ModeMachine_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl = nextMode;

      Rte_AckFlags.Rte_ModeSwitchAck_Dcm_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl_Ack = 1U;

      Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */


    }

    if (((ev & Rte_Ev_Run_Ct_MBBL_ResetManager_ResetServiceExecution) != (EventMaskType)0) && (Rte_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack == 0U))
    {
      Dcm_EcuResetType nextMode = 0U; /* PRQA S 2982 */ /* MD_Rte_2982 */

      Rte_DisableOSInterrupts(); /* PRQA S 1881, 4558 */ /* MD_Rte_Os, MD_Rte_Os */
      (void)Rte_IocReceive_Rte_M_Dcm_DcmEcuReset_DcmEcuReset(&nextMode);

      Rte_ModeMachine_Dcm_DcmEcuReset_DcmEcuReset = nextMode;

      Rte_AckFlags.Rte_ModeSwitchAck_Dcm_DcmEcuReset_DcmEcuReset_Ack = 1U;

      Rte_EnableOSInterrupts(); /* PRQA S 1881, 4558, 2983 */ /* MD_Rte_Os, MD_Rte_Os, MD_Rte_2983 */


    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_APPLTASK_CORE0_LOWPRIO_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_BACKGROUNDTASK_CORE0_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     BackgroundTask_Core0
 * Priority: 0
 * Schedule: FULL
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(BackgroundTask_Core0) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  for(;;) /* FETA_RTE_EXTENDED_TASK */
  {
    /* Wait event skipped for background task */

    /* call schedulable entity */
    KeyM_MainBackgroundFunction();
#if defined (CANOEAPI_VERSION)
# if (CANOEAPI_VERSION >= 212)
    CANoeAPI_ConsumeTicks(RTE_TIMING_BACKGROUND_TASK_TICKS); /* prevent CANoe from detecting an infinite loop */
# endif
#endif
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_BACKGROUNDTASK_CORE0_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_BSWTASK_CORE0_HIGHPRIO_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     BswTask_Core0_HighPrio
 * Priority: 60
 * Schedule: NON
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(BswTask_Core0_HighPrio) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;) /* FETA_RTE_EXTENDED_TASK */
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_10ms | Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_3ms | Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_5ms | Rte_Ev_Run_SBC_SBC_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(BswTask_Core0_HighPrio, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_10ms | Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_3ms | Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_5ms | Rte_Ev_Run_SBC_SBC_MainFunction)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      CanTp_MainFunctionRx();

      /* call schedulable entity */
      CanTp_MainFunctionTx();
    }

    if ((ev & Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      IpduM_MainFunctionRx();

      /* call runnable */
      SecOC_MainFunctionRx(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call schedulable entity */
      Com_MainFunctionRx_ComMainFunctionRx();

      /* call schedulable entity */
      Com_MainFunctionTx_ComMainFunctionTx();

      /* call schedulable entity */
      Com_MainFunctionRouteSignals_ComMainFunctionRouteSignals();
    }

    if ((ev & Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Dcm_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      SecOC_MainFunctionTx(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call schedulable entity */
      IpduM_MainFunctionTx();
    }

    if ((ev & Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_3ms) != (EventMaskType)0)
    {
      /* call runnable */
      WdgM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_SBC_SBC_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      SBC_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_BswTask_Core0_HighPrio_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      StbM_MainFunction_OsApplication_Trusted_Core0(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_BSWTASK_CORE0_HIGHPRIO_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_BSWTASK_CORE0_LOWPRIO_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     BswTask_Core0_LowPrio
 * Priority: 30
 * Schedule: FULL
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(BswTask_Core0_LowPrio) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;) /* FETA_RTE_EXTENDED_TASK */
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_BswTask_Core0_LowPrio_0_10ms | Rte_Ev_Cyclic2_BswTask_Core0_LowPrio_0_5ms | Rte_Ev_Run_AdcIf_AdcIf_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(BswTask_Core0_LowPrio, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_BswTask_Core0_LowPrio_0_10ms | Rte_Ev_Cyclic2_BswTask_Core0_LowPrio_0_5ms | Rte_Ev_Run_AdcIf_AdcIf_MainFunction)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_BswTask_Core0_LowPrio_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      Dem_MasterMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      Dem_SatelliteMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      NvM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call schedulable entity */
      Fee_MainFunction();

      /* call schedulable entity */
      Fls_17_Dmu_MainFunction();

      /* call runnable */
      KeyM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      Csm_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_BswTask_Core0_LowPrio_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Crypto_30_LibCv_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_BswTask_Core0_LowPrio_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Can_MainFunction_BusOff();

      /* call schedulable entity */
      Can_MainFunction_Mode();

      /* call schedulable entity */
      Can_MainFunction_Wakeup();
    }

    if ((ev & Rte_Ev_Cyclic2_BswTask_Core0_LowPrio_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      ComM_MainFunction_0(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      ComM_MainFunction_1(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_BswTask_Core0_LowPrio_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      CanNm_MainFunction();

      /* call schedulable entity */
      Crypto_30_vHsm_MainFunction();

      /* call schedulable entity */
      CanSM_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_BswTask_Core0_LowPrio_0_5ms) != (EventMaskType)0)
    {
      /* call runnable */
      EcuM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      BswM_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call schedulable entity */
      Spi_MainFunction_Handling();
    }

    if ((ev & Rte_Ev_Run_AdcIf_AdcIf_MainFunction) != (EventMaskType)0)
    {
      /* call runnable */
      AdcIf_MainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic2_BswTask_Core0_LowPrio_0_5ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      CanTSyn_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_BswTask_Core0_LowPrio_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Rtm_MainFunction();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_BSWTASK_CORE0_LOWPRIO_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define RTE_START_SEC_OSTASK_ALV_BELTFUNCTIONALGO_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Task:     OsTask_ALV_BeltFunctionAlgo
 * Priority: 21
 * Schedule: FULL
 *********************************************************************************************************************/
/* PRQA S 6010, 6030, 6050, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
TASK(OsTask_ALV_BeltFunctionAlgo) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_Unreachable */
{
  EventMaskType ev;

  for(;;) /* FETA_RTE_EXTENDED_TASK */
  {
    (void)WaitEvent(Rte_Ev_Cyclic_OsTask_ALV_BeltFunctionAlgo_0_10ms | Rte_Ev_Run_BFE_BFE_runExecuteStandardSteps); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(OsTask_ALV_BeltFunctionAlgo, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic_OsTask_ALV_BeltFunctionAlgo_0_10ms | Rte_Ev_Run_BFE_BFE_runExecuteStandardSteps)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic_OsTask_ALV_BeltFunctionAlgo_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      BSR_runBeltSlackReductionAlgo(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      PRE_runPreTensioning(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      HWA_runMainFunction(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      SFR_runStandardFunctionRecovery(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* call runnable */
      PRO_runProductionCycles(); /* PRQA S 2987 */ /* MD_Rte_2987 */

      /* START PRE RUNNABLE BFS_runBeltFunctionSelection */
      /* read implicit data */
      *(&Rte_OsTask_ALV_BeltFunctionAlgo.Rte_RB.Rte_BFS_AC_BeltFunctionSelection_BFS_runBeltFunctionSelection.Rte_prrExecutedCycle_u8CycleNumber.value) = Rte_BFE_psrExecutedCycle_u8CycleNumber; /* PRQA S 1339, 2982 */ /* MD_Rte_1339, MD_Rte_2982 */
      /* STOP PRE RUNNABLE BFS_runBeltFunctionSelection */
      /* call runnable */
      BFS_runBeltFunctionSelection(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Run_BFE_BFE_runExecuteStandardSteps) != (EventMaskType)0)
    {
      /* call runnable */
      BFE_runExecuteStandardSteps(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }

    if ((ev & Rte_Ev_Cyclic_OsTask_ALV_BeltFunctionAlgo_0_10ms) != (EventMaskType)0)
    {
      /* call runnable */
      BFE_runScheduleStep(); /* PRQA S 2987 */ /* MD_Rte_2987 */
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_OSTASK_ALV_BELTFUNCTIONALGO_CODE
#include "Rte_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0306:  MISRA rule: Rule11.4
     Reason:     An optimized copy algorithm can be used for aligned data. To check if pointers are aligned, pointers need to be casted to an integer type.
     Risk:       No functional risk. Only the lower 8 bits of the address are checked, therefore all integer types are sufficient.
     Prevention: Not required.

   MD_Rte_0314:  MISRA rule: Dir1.1
     Reason:     Pointer cast to void because a direct byte access is necessary.
     Risk:       No functional risk. Only a cast to void is performed.
     Prevention: Not required.

   MD_Rte_0315:  MISRA rule: Dir1.1
     Reason:     Pointer cast to void because generic access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_0316:  MISRA rule: Dir1.1
     Reason:     Pointer cast to uint8* because a direct byte access is necessary.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_1339:  MISRA rule: Rule17.8
     Reason:     Passing elements by pointer is a well known concept.
     Risk:       No functional risk. Data flow is handled with care.
     Prevention: Not required.

   MD_Rte_1340:  MISRA rule: Rule17.8
     Reason:     Passing elements by pointer is a well known concept.
     Risk:       No functional risk. Data flow is handled with care.
     Prevention: Not required.

   MD_Rte_1514:  MISRA rule: Rule8.9
     Reason:     Because of external definition, misra does not see the call.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_1533:  MISRA rule: Rule8.9
     Reason:     Object is referenced by more than one function in different configurations.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_2982:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2983:  MISRA rule: Rule2.2
     Reason:     For generated code it is difficult to check the usage of each object.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2986:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_2987:  MISRA rule: Rule2.2
     Reason:     Used to simplify code generation.
     Risk:       No functional risk. There is no side effect.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3408:  MISRA rule: Rule8.4
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Qac:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 9.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/

/**********************************************************************************************************************
 Code coverage justifications
 *********************************************************************************************************************/

/* COV_JUSTIFICATION_BEGIN
   \ID COV_RTE_MISRA
     \ACCEPT XX
     \REASON [COV_MSR_MISRA]

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
  Finite Execution Time Analysis justifications
 *********************************************************************************************************************/

/* COV_JUSTIFICATION_BEGIN

  \ID FETA_RTE_EXTENDED_TASK
  \DESCRIPTION    An extended task is used if more than one runnable entity is mapped to a task with different activation periods
  \COUNTERMEASURE \S SMI-2063

  \ID FETA_RTE_MEMCLR
  \DESCRIPTION    Iterations to initialize memory with zero.
  \COUNTERMEASURE \S SMI-322

  \ID FETA_RTE_MEMCPY
  \DESCRIPTION    Iterations to copy data from source to destination.
  \COUNTERMEASURE \S SMI-322

  \ID FETA_RTE_MEMCPY32
  \DESCRIPTION    Iterations to copy data from source to destination.
  \COUNTERMEASURE \S SMI-322

COV_JUSTIFICATION_END */

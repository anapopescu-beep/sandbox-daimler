/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Isr_Lcfg.c
 *   Generation Time: 2023-10-05 14:21:23
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_ISR_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Isr_Lcfg.h"
#include "Os_Isr.h"

/* Os kernel module dependencies */
#include "Os_AccessCheck_Lcfg.h"
#include "Os_Application_Lcfg.h"
#include "Os_Common.h"
#include "Os_Core_Lcfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_MemoryProtection_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Thread.h"
#include "Os_Timer.h"
#include "Os_TimingProtection_Lcfg.h"
#include "Os_Trace_Lcfg.h"
#include "Os_XSignal_Lcfg.h"
#include "Os_XSignal.h"

/* Os hal dependencies */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Interrupt_Lcfg.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic ISR data: CanIsr_1 */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CanIsr_1_Dyn;

/*! Dynamic ISR data: CounterIsr_SystemTimer */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_CounterIsr_SystemTimer_Dyn;

/*! Dynamic ISR data: RCM_PFlashEccFailure_Notification */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_RCM_PFlashEccFailure_Notification_Dyn;

/*! Dynamic ISR data: RCM_SRamEccFailure_Notification */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_RCM_SRamEccFailure_Notification_Dyn;

/*! Dynamic ISR data: vHsmResponseIsr */
OS_LOCAL VAR(Os_IsrType, OS_VAR_NOINIT) OsCfg_Isr_vHsmResponseIsr_Dyn;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: CanIsr_1 */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsr_1_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CanIsr_1,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CanIsr_1,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_1 =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CanIsr_1,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level3_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CanIsr_1_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_CanIsr_1,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CanIsr_1_HwConfig,
  /* .IsrId                     = */ CanIsr_1,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: CounterIsr_SystemTimer */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_CounterIsr_SystemTimer,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_CounterIsr_SystemTimer,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer =
{
  /* .Isr     = */
  {
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_CounterIsr_SystemTimer,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_CounterIsr_SystemTimer_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_CounterIsr_SystemTimer,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_CounterIsr_SystemTimer_HwConfig,
  /* .IsrId                     = */ CounterIsr_SystemTimer,
  /* .IsEnabledOnInitialization = */ FALSE
}
,
  /* .Counter = */ OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(OsCfg_Counter_SystemTimer)
};
/*! ISR configuration data: OS_ISR_BMM_HES_IT */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_OS_ISR_BMM_HES_IT_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_OS_ISR_BMM_HES_IT,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_OS_ISR_BMM_HES_IT,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_OS_ISR_BMM_HES_IT =
{
  /* .HwConfig = */ &OsCfg_Cat1Isr_OS_ISR_BMM_HES_IT_HwConfig,
};
/*! ISR configuration data: OS_ISR_BMM_HES_TOUT */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_OS_ISR_BMM_HES_TOUT_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_OS_ISR_BMM_HES_TOUT,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_OS_ISR_BMM_HES_TOUT,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_OS_ISR_BMM_HES_TOUT =
{
  /* .HwConfig = */ &OsCfg_Cat1Isr_OS_ISR_BMM_HES_TOUT_HwConfig,
};
/*! ISR configuration data: RCM_PFlashEccFailure_Notification */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_RCM_PFlashEccFailure_Notification_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_RCM_PFlashEccFailure_Notification,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_RCM_PFlashEccFailure_Notification,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_RCM_PFlashEccFailure_Notification =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_RCM_PFlashEccFailure_Notification,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level5_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_RCM_PFlashEccFailure_Notification_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_RCM_PFlashEccFailure_Notification,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_RCM_PFlashEccFailure_Notification_HwConfig,
  /* .IsrId                     = */ RCM_PFlashEccFailure_Notification,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: RCM_SRamEccFailure_Notification */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_RCM_SRamEccFailure_Notification_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_RCM_SRamEccFailure_Notification,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_RCM_SRamEccFailure_Notification,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_RCM_SRamEccFailure_Notification =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_RCM_SRamEccFailure_Notification,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level4_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_RCM_SRamEccFailure_Notification_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_SystemApplication_OsCore0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_RCM_SRamEccFailure_Notification,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_RCM_SRamEccFailure_Notification_HwConfig,
  /* .IsrId                     = */ RCM_SRamEccFailure_Notification,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
/*! ISR configuration data: vHsmResponseIsr */
CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_vHsmResponseIsr_HwConfig =
{
  /* .HwConfig                  = */ &OsCfg_Hal_IntIsr_vHsmResponseIsr,
  /* .MapConfig                 = */ &OsCfg_Hal_IntIsrMap_vHsmResponseIsr,
  /* .IsMapped                  = */ FALSE,
  /* .IsPostActionRequired      = */ FALSE
}
;  
CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_vHsmResponseIsr =
{
  /* .Thread   = */
  {
    /* .ContextConfig         = */ &OsCfg_Hal_Context_vHsmResponseIsr,
    /* .Context               = */ &OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn,
    /* .Stack                 = */ &OsCfg_Stack_OsCore0_Isr_Core,
    /* .Dyn                   = */ OS_ISR_CASTDYN_ISR_2_THREAD(OsCfg_Isr_vHsmResponseIsr_Dyn),
    /* .OwnerApplication      = */ &OsCfg_App_OsApplication_Trusted_Core0,
    /* .Core                  = */ &OsCfg_Core_OsCore0,
    /* .IntApiState           = */ &OsCfg_Core_OsCore0_Dyn.IntApiState,
    /* .TimeProtConfig        = */ NULL_PTR,
    /* .MpAccessRightsInitial = */ NULL_PTR,
    /* .AccessRights          = */ &OsCfg_AccessCheck_NoAccess,
    /* .Trace                 = */ &OsCfg_Trace_vHsmResponseIsr,
    /* .FpuContext            = */ NULL_PTR,
    /* .InitialCallContext    = */ OS_CALLCONTEXT_ISR2,
    /* .PreThreadHook         = */ NULL_PTR,
    /* .InitDuringStartUp     = */ FALSE,
    /* .UsesFpu               = */ FALSE
  },
  /* .SourceConfig              = */ &OsCfg_Isr_vHsmResponseIsr_HwConfig,
  /* .IsrId                     = */ vHsmResponseIsr,
  /* .IsEnabledOnInitialization = */ TRUE
}
;
#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for category 2 ISRs. */
CONSTP2CONST(Os_IsrConfigType, OS_CONST, OS_CONST) OsCfg_IsrRefs[OS_ISRID_COUNT + 1] =  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */
{
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_CanIsr_1),
  OS_TIMER_CASTCONFIG_TIMERISR_2_ISR(OsCfg_Isr_CounterIsr_SystemTimer),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_RCM_PFlashEccFailure_Notification),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_RCM_SRamEccFailure_Notification),
  OS_ISR_CASTCONFIG_ISR_2_ISR(OsCfg_Isr_vHsmResponseIsr),
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Isr_Lcfg.c
 *********************************************************************************************************************/

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
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_XSignal_Lcfg.c
 *   Generation Time: 2022-09-22 10:43:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_XSIGNAL_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_XSignal_Lcfg.h"
#include "Os_XSignal.h"

/* Os kernel module dependencies */
#include "Os_Common.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Lcfg.h"

/* Os hal dependencies */


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

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define OS_STOP_SEC_CORE0_VAR_NOCACHE_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! X-Signal used services map. */
CONST(OSServiceIdType, OS_CONST) OsCfg_XSig_ServiceMap[OS_XSIGFUNCTIONIDX_COUNT + 1] =                                  /* PRQA S 1533, 4521 */ /* MD_Os_Rule8.9_1533, MD_Os_Rule10.1_4521 */
{
  /* USED */
  /* UNUSED */
  OSServiceId_ActivateTask,
  OSServiceId_CancelAlarm,
  OSServiceId_ControlIdle,
  OSServiceId_GetAlarm,
  OSServiceId_GetApplicationState,
  OSServiceId_GetCounterValue,
  OSServiceId_GetErrorHookStackUsage,
  OSServiceId_GetEvent,
  OSServiceId_GetISRStackUsage,
  OSServiceId_GetKernelStackUsage,
  OSServiceId_GetNonTrustedFunctionStackUsage,
  OSServiceId_GetProtectionHookStackUsage,
  OSServiceId_GetScheduleTableStatus,
  OSServiceId_GetShutdownHookStackUsage,
  OSServiceId_GetStartupHookStackUsage,
  OSServiceId_GetTaskStackUsage,
  OSServiceId_GetTaskState,
  OSServiceId_HookCallCallback,
  OSServiceId_NextScheduleTable,
  OSServiceId_SetAbsAlarm,
  OSServiceId_SetEvent,
  OSServiceId_SetRelAlarm,
  OSServiceId_ShutdownAllCores,
  OSServiceId_StartScheduleTableAbs,
  OSServiceId_StartScheduleTableRel,
  OSServiceId_StopScheduleTable,
  OSServiceId_TerminateApplication,
  OSSERVICEID_COUNT
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
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
 *  END OF FILE: Os_XSignal_Lcfg.c
 *********************************************************************************************************************/

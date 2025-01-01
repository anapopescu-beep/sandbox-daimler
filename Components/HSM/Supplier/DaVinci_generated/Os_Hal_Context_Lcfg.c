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
 *              File: Os_Hal_Context_Lcfg.c
 *   Generation Time: 2023-04-06 15:03:15
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_HAL_CONTEXT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Context.h"

/* Os kernel module dependencies */
#include "OsInt.h"
#include "Os_Core.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

/* Os hal dependencies */
#include "Os_Hal_Core.h"


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

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: StartupHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_StartupHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ShutdownHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ShutdownHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn;

/*! HAL dynamic ISR2 level context data: Level2 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level2_Dyn;

/*! HAL dynamic task context data: Default_Init_Task */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Init_Task_Dyn;

/*! HAL dynamic task context data: Default_Init_Task_Trusted */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Default_Init_Task_Trusted_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore0_Dyn;

/*! HAL dynamic task context data: OsTask */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_Dyn;

/*! HAL dynamic task context data: Ostask_HighPrio */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Ostask_HighPrio_Dyn;

/*! HAL dynamic task context data: vHsmMainFunctionTask */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_vHsmMainFunctionTask_Dyn;

/*! HAL exception context data: OsCore0 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_ExceptionContext;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Init_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306*/ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (64u),
  /* .Entry            = */ (uint32)&Os_HookWrapperOs_CoreInitHook,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .StackRegionStart = */ 0uL, /* not used */
  /* .StackRegionInfo  = */ 0uL, /* not used */

}
;

/*! HAL hook context configuration data: StartupHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_StartupHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Startup_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306*/ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (64u),
  /* .Entry            = */ (uint32)&Os_HookWrapperCallback,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .StackRegionStart = */ 0uL, /* not used */
  /* .StackRegionInfo  = */ 0uL, /* not used */

}
;

/*! HAL hook context configuration data: ShutdownHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ShutdownHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Shutdown_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306*/ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (32u),
  /* .Entry            = */ (uint32)&Os_HookWrapperStatusHook,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .StackRegionStart = */ 0uL, /* not used */
  /* .StackRegionInfo  = */ 0uL, /* not used */

}
;

/*! HAL hook context configuration data: ErrorHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Error_Dyn)+1),  /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306*/ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (64u),
  /* .Entry            = */ (uint32)&Os_HookWrapperStatusHook,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .StackRegionStart = */ 0uL, /* not used */
  /* .StackRegionInfo  = */ 0uL, /* not used */

}
;

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306*/ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ 32u,
  /* .Entry            = */ (uint32)&Os_Isr_Os_TimerPitIsr,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .StackRegionStart = */ 0uL, /* not used */
  /* .StackRegionInfo  = */ 0uL, /* not used */

}
;

/*! HAL ISR2 context configuration data: vHsm_Hal_InternalRequestIsr */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_vHsm_Hal_InternalRequestIsr =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306*/ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ 32u,
  /* .Entry            = */ (uint32)&Os_Isr_vHsm_Hal_InternalRequestIsr,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .StackRegionStart = */ 0uL, /* not used */
  /* .StackRegionInfo  = */ 0uL, /* not used */

}
;

/*! HAL task context configuration data: Default_Init_Task */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Init_Task =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967294_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306*/ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Default_Init_Task,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .StackRegionStart = */ 0uL, /* not used */
  /* .StackRegionInfo  = */ 0uL, /* not used */

}
;

/*! HAL task context configuration data: Default_Init_Task_Trusted */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Default_Init_Task_Trusted =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967293_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306*/ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Default_Init_Task_Trusted,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .StackRegionStart = */ 0uL, /* not used */
  /* .StackRegionInfo  = */ 0uL, /* not used */

}
;

/*! HAL task context configuration data: IdleTask_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306*/ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Os_IdleTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .StackRegionStart = */ 0uL, /* not used */
  /* .StackRegionInfo  = */ 0uL, /* not used */

}
;

/*! HAL task context configuration data: OsTask */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio10_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306*/ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_OsTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .StackRegionStart = */ 0uL, /* not used */
  /* .StackRegionInfo  = */ 0uL, /* not used */

}
;

/*! HAL task context configuration data: Ostask_HighPrio */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Ostask_HighPrio =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio20_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306*/ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Ostask_HighPrio,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .StackRegionStart = */ 0uL, /* not used */
  /* .StackRegionInfo  = */ 0uL, /* not used */

}
;

/*! HAL task context configuration data: vHsmMainFunctionTask */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_vHsmMainFunctionTask =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_vHsmMainFunctionTask_Dyn)+1),   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306*/ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_vHsmMainFunctionTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305 */ /* MD_Os_Hal_Rule11.1_0305 */ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .StackRegionStart = */ 0uL, /* not used */
  /* .StackRegionInfo  = */ 0uL, /* not used */

}
;

/*! HAL kernel stack configuration data: OsCore0_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore0_Kernel =
{
  /* .StackRegionEnd   = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn)+1),  /* OsCore0_Kernel */   /* PRQA S 0306 */ /* MD_Os_Hal_Rule11.4_0306*/ /* COMP_WARN_OS_HAL_EXPR_NOT_ARITHMETIC_TYPE */ /* COMP_WARN_OS_EXTENDED_CONST_INITIALIZER */
  /* .StackRegionStart = */ 0uL, /* not used */
  /* .StackRegionInfo  = */ 0uL, /* not used */

}
;

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for HAL exception context. */
CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1u] =
{
  &OsCfg_Hal_Context_OsCore0_ExceptionContext,
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
 *  END OF FILE: Os_Hal_Context_Lcfg.c
 *********************************************************************************************************************/

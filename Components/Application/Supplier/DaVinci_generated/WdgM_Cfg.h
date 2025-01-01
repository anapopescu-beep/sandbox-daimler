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
 *            Module: WdgM
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: WdgM_Cfg.h
 *   Generation Time: 2023-07-10 14:36:09
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#if !defined (WDGM_CFG_H)
# define WDGM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "WdgM_Types.h"


/**********************************************************************************************************************
 *  VERSION INFORMATION
 *********************************************************************************************************************/
#define WDGM_CFG_MAJOR_VERSION (6u) 
#define WDGM_CFG_MINOR_VERSION (0u) 
#define WDGM_CFG_PATCH_VERSION (2u) 


/* Module specific general defines */ 
#ifndef WDGM_USE_DUMMY_STATEMENT
#define WDGM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef WDGM_DUMMY_STATEMENT
#define WDGM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef WDGM_DUMMY_STATEMENT_CONST
#define WDGM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef WDGM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define WDGM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef WDGM_ATOMIC_VARIABLE_ACCESS
#define WDGM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef WDGM_PROCESSOR_TC322L
#define WDGM_PROCESSOR_TC322L
#endif
#ifndef WDGM_COMP_TASKING
#define WDGM_COMP_TASKING
#endif
#ifndef WDGM_GEN_GENERATOR_MSR
#define WDGM_GEN_GENERATOR_MSR
#endif
#ifndef WDGM_CPUTYPE_BITORDER_LSB2MSB
#define WDGM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef WDGM_CONFIGURATION_VARIANT_PRECOMPILE
#define WDGM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef WDGM_CONFIGURATION_VARIANT_LINKTIME
#define WDGM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef WDGM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define WDGM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef WDGM_CONFIGURATION_VARIANT
#define WDGM_CONFIGURATION_VARIANT WDGM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef WDGM_POSTBUILD_VARIANT_SUPPORT
#define WDGM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif
 

 
/* Module config related defines */ 
# define WDGM_NR_OF_CHECKPOINTS           (1u) 
# define WDGM_NR_OF_ENTITIES              (1u) 
# define WDGM_NR_OF_ALLOWED_CALLERS       (1u) 
# define WDGM_NR_OF_GLOBAL_TRANSITIONS    (0u) 
# define WDGM_NR_OF_LOCAL_TRANSITIONS     (0u) 
# define WDGM_NR_OF_WATCHDOGS_CORE0       (1u) 
# define WDGM_NR_OF_TRIGGER_MODES_CORE0   (1u) 

/* Checkpoints for supervised entity 'WdgMSupervisedEntity' */ 
# define WdgMConf_WdgMCheckpoint_WdgMCheckpoint (0u) 
 

# define WdgMConf_WdgMSupervisedEntity_WdgMSupervisedEntity (0u) 


#define WDGM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

extern CONST(WdgM_ConfigType, WDGM_CONST) WdgMConfig_Mode0_core0; 

#define WDGM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*
 * Status reporting (WdgMStatusReportingMechanism) configured to WDGM_USE_MODE_SWITCH_PORTS
 */

#define WDGM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
 
/* 
 * Local callback routines for mode switch ports of core 0 
 */ 
/* Local state callback for supervised entity 'WdgMSupervisedEntity' */ 
FUNC(void, WDGM_CODE) WdgM_LocalStatusChangeNotificationSE0(WdgMMode Status); /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */ 
 
/* 
 * Global callback routine for mode switch ports of core0 
 */ 
FUNC(void, WDGM_CODE) WdgM_GlobalStatusChangeNotificationCore0(WdgMMode Status); /* PRQA S 0777 */ /* MD_MSR_Rule5.1 */ 

#define WDGM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */ 

#endif /* WDGM_CFG_H*/

/**********************************************************************************************************************
 *  END OF FILE: WdgM_Cfg.h
 *********************************************************************************************************************/


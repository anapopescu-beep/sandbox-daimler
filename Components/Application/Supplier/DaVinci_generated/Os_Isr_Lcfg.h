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
 *              File: Os_Isr_Lcfg.h
 *   Generation Time: 2023-10-05 14:21:23
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/

#ifndef OS_ISR_LCFG_H
# define OS_ISR_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Isr_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"
# include "Os_Timer_Types.h"
# include "Os_XSignal_Types.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! ISR configuration data: OS_ISR_BMM_HES_IT */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_OS_ISR_BMM_HES_IT_HwConfig;
extern CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_OS_ISR_BMM_HES_IT;

/*! ISR configuration data: OS_ISR_BMM_HES_TOUT */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Cat1Isr_OS_ISR_BMM_HES_TOUT_HwConfig;
extern CONST(Os_IsrCat1ConfigType, OS_CONST) OsCfg_Cat1Isr_OS_ISR_BMM_HES_TOUT;

/*! ISR configuration data: CanIsr_1 */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CanIsr_1_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_CanIsr_1;

/*! ISR configuration data: CounterIsr_SystemTimer */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer_HwConfig;
extern CONST(Os_TimerIsrConfigType, OS_CONST) OsCfg_Isr_CounterIsr_SystemTimer;

/*! ISR configuration data: RCM_PFlashEccFailure_Notification */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_RCM_PFlashEccFailure_Notification_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_RCM_PFlashEccFailure_Notification;

/*! ISR configuration data: RCM_SRamEccFailure_Notification */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_RCM_SRamEccFailure_Notification_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_RCM_SRamEccFailure_Notification;

/*! ISR configuration data: vHsmResponseIsr */
extern CONST(Os_IsrHwConfigType, OS_CONST) OsCfg_Isr_vHsmResponseIsr_HwConfig;
extern CONST(Os_IsrConfigType, OS_CONST) OsCfg_Isr_vHsmResponseIsr;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Object reference table for category 2 ISRs. */
extern CONSTP2CONST(Os_IsrConfigType, OS_CONST, OS_CONST) OsCfg_IsrRefs[OS_ISRID_COUNT + 1];  /* PRQA S 4521 */ /* MD_Os_Rule10.1_4521 */

# define OS_STOP_SEC_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_ISR_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Isr_Lcfg.h
 *********************************************************************************************************************/

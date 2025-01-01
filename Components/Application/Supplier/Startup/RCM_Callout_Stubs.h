
#ifndef RCM_CALLOUT_STUBS_H_
#define RCM_CALLOUT_STUBS_H_ 1

/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------------------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
H-File Template Version: 
Template version: AEM_PROCESS_1.17.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2021-10
*******************************************************************************

Overview of the interfaces:
   This file defines the information (interfaces, definitions and data) provided
   by the component RCM.
   These are globally visible.
   This file is intended to be included in a package header file;
   all components should include the package header file instead of this file.

******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.3 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Supplier/Startup/project.pj $
*/
/* PRQA S 0288 -- */
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Std_Types.h"
#include "Rte_Type.h"
#include "Mcu.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 *		MCU_RAW_POWER_ON_RESET_2
 */
#define MCU_RAW_RESET_PIN          ((Mcu_RawResetType)0x00010000U)
/**
 * \brief
 *		MCU_RAW_STM0_RESET
 */
#define MCU_RAW_CLK_FAILURE      ((Mcu_RawResetType)(0x00000020U))
/**
 * \brief
 *		MCU_SW_RESET
 */
#define MCU_SW_RESET             ((Mcu_RawResetType)(0x00000010U))
/******************************************************************************
DECLARATION OF TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF VARIABLES
******************************************************************************/

/******************************************************************************
DECLARATION OF CONSTANT DATA
******************************************************************************/

/******************************************************************************
DECLARATION OF FUNCTIONS
******************************************************************************/

void RCM_ClockFailure_Notification(void);
void RCM_PllFailure_Notification(void);
void RCM_DFlashEccFailure_Notification(void);

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* RCM_CALLOUT_STUBS_H_ */

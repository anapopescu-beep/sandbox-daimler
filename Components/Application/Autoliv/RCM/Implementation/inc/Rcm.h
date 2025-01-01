
#ifndef _RCM_H_
#define _RCM_H_ 1

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
$Revision: 1.1.1.2.1.2 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/RCM/Implementation/inc/project.pj $
*/
/* PRQA S 0288 -- */
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Std_Types.h"
#include "common.h"
#include "Rte_Type.h"
#include "Ifx_reg.h"

#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/
/**
 * \brief
 *		Defined macro from H file.
 */
#define KU8_RESET_CAUSE_EXTERNAL_WATCHDOG                         ((uint8)0x90)

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
void RCM_WDT_Init(void);
void RCM_TimerNotification(void);
void RCM_Autotest_RunExtWDTest(u8TestResultType * pu8TestResult);
void RCM_runGetResetCause(u32ResetCauseType * pu32ResetCause);
void RCM_runGetTestResult (P2VAR(u8WdgTestResultType, AUTOMATIC, RTE_APPL_DATA) pu8WdgTestResult);
void RCM_PreInit(void);
/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* _RCM_H_ */





















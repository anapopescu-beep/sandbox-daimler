
#ifndef RCM_PUBLIC_H_
#define RCM_PUBLIC_H_ 1

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
$Revision: 1.1.2.1 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/RCM/Implementation/inc/project.pj $
*/
/* PRQA S 0288 -- */
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/******************************************************************************
DEFINITION OF CONSTANTS
******************************************************************************/

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

/******************************************************************************
DECLARATION OF FUNCTION-LIKE MACROS
******************************************************************************/
extern void RCM_runDetermineResetCause(void);
extern void RCM_runConfirmResetCause(void);
extern void RCM_runNotifyResetCause(u32ResetReasonNotificationType u32ResetCauseNotification, u32ResetReasonNotificationStatusType u32ResetCauseStatus);

#ifdef __cplusplus
}
#endif
/******************************************************************************
End Of File
*****************************************************************************/

#endif /* RCM_PUBLIC_H_ */






















#ifndef SCM_PUBLIC_H_
#define SCM_PUBLIC_H_ 1

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
   <Describes details of this header file>

******************************************************************************/
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1.1.3.2.3 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/SCM/Implementation/inc/project.pj $
*/
/* PRQA S 0288 -- */
/*****************************************************************************/
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/

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
#define SCM_AC_SystemContextManagement_START_SEC_CODE
#include "SCM_AC_SystemContextManagement_MemMap.h"

extern void SCM_runWriteSystemContextShutdown (void);
extern void SCM_runRestoreSystemContext(void);

#define SCM_AC_SystemContextManagement_STOP_SEC_CODE
#include "SCM_AC_SystemContextManagement_MemMap.h"

/******************************************************************************
End Of File
*****************************************************************************/

#endif /* SCM_PUBLIC_H_ */

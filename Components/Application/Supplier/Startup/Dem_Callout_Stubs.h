#ifndef DEM_CALLOUT_STUBS_H
#define DEM_CALLOUT_STUBS_H 1

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
$Revision: 1.1 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Supplier/Startup/project.pj $
*/
/* PRQA S 0288 -- */
/*****************************************************************************/
/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/

#include "vstdlib.h"

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/
#define DEM_START_SEC_CALLOUT_CODE
#include "MemMap.h"

void Dem_ClearDTC_Callback_Notification_StartClear(void);

/**********************************************************************************************************************
  END of User implementation area
**********************************************************************************************************************/
#define DEM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"

#endif /*DEM_CALLOUT_STUBS_H_*/
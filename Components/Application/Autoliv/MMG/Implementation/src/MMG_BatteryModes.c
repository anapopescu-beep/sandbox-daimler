
/******************************************************************************

AUTOLIV ELECTRONIC document.

-------------------------------------

Copyright Autoliv Inc. All rights reserved.

*******************************************************************************
C-File Template Version:
Template version: AEM_PROCESS_1.17.00
Last template change: AEM_PROCESS_1.00.00
Template release date: 2021-10
******************************************************************************/
/* PRQA S 0288 ++ */
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.1.5.14 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/MMG/Implementation/src/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup MMG_BatteryModes.c MMG
 *  This is a new created group, this will create a new man3 file with
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file.
 */

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_MMG_AC_ModeManagement.h"
#include "common.h"
#include "MMG_Private.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED CONSTANT DATA
******************************************************************************/

/******************************************************************************
MODULE FUNCTION-LIKE MACROS
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define MMG_AC_ModeManagement_START_SEC_CODE
#include "MMG_AC_ModeManagement_MemMap.h"

/**
 * \brief
 *	    USED FOR EXTENDED VOLTAGE RANGE INHIBITION & ABORTION
 *
 * \param
 * 		void
 * \exception
 *     None
 * \pre
 *     None
 * \post
 *     None
 * \return
 * 		void
 */
void mmg_UpdateModeStatus_PowerVoltageUnstable(void)
{
   /* This variable is used to store the status of battery survey */
   u8BatteryVoltageSurveyStatusType u8BatteryVoltageSurveyStatus;

   /* Get the status of battery survey */
   /* [COVERS: DSG_MMG_0018, DSG_MMG_0035] */
   Rte_Call_pclSurveyBatteryVoltage_GetStatus( &u8BatteryVoltageSurveyStatus );

   /* Update running context flag according to the battery survey status */
   if (KU8_BATTERY_UNSTABLE == u8BatteryVoltageSurveyStatus)
   {
      /* battery survey status is unstable => context is ON */
      M_SET_MODE_MASK_ON (MMG_KU32_MASK_POWER_VOLTAGE_UNSTABLE);
   }
   else
   {
      /* battery survey status is stable => context is OFF */
      M_SET_MODE_MASK_OFF (MMG_KU32_MASK_POWER_VOLTAGE_UNSTABLE);
   }

}

/**
 * \brief
 *		Defined macro from C file.
 */
#define MMG_AC_ModeManagement_STOP_SEC_CODE
#include "MMG_AC_ModeManagement_MemMap.h"


/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

/******************************************************************************
End Of File
*****************************************************************************/

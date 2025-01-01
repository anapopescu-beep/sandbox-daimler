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
$Revision: 1.1.2.10 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/MMG/Quality_Assurance/Static_Analysis/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup MMG_CriticalAutoTestsModes.c MMG
 *  This is a new created group, this will create a new man3 file with
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file.
 */
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "common.h"
#include "Rte_MMG_AC_ModeManagement.h"
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

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define MMG_AC_ModeManagement_START_SEC_CODE
#include "MMG_AC_ModeManagement_MemMap.h"
/**
 * \brief
 *	    Function used Update the Critical Autotests context.
 *
 * \parm
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
void mmg_UpdateModeStatus_CriticalAutotestsNok(void)
{
   /* This variable is used to store the autotests statuses from ATM */
   u8TestResultType u8StatusOfLastCriticalAutoTest;
   UInt8 u8AutoTestId;

   /* First, check if the "critical autotests NOK" system context status is not already OK */
   if (KU32_ZERO != (MMG_u32ModesStatus & MMG_KU32_MASK_CRITICAL_AT_NOK))
   {
      /* Get the Last critical Autotest ID */
      /* [COVERS: DSG_MMG_0017, DSG_MMG_0033] */
      Rte_Call_pclAutotestServices_GetLastCriticalAutotestID(&u8AutoTestId);

      /* Get the status of the last executed startup auto test */
      /* [COVERS: DSG_MMG_0034] */
      Rte_Call_pclAutotestServices_GetTestResult(u8AutoTestId, &u8StatusOfLastCriticalAutoTest);

      if (KU8_ATM_TEST_OK == u8StatusOfLastCriticalAutoTest)
      {
         /* All critical auto tests have reported OK at least once during ATM startup phase:
            de activate the "Critical Auto tests NOK" mode */
         M_SET_MODE_MASK_OFF (MMG_KU32_MASK_CRITICAL_AT_NOK);
      }
      else
      {
         /* At least one startup auto test is not successful yet */
         /* Do nothing */
         /* By default this mode has been initialized at activated status */
         /* see M_U32_INITIAL_VALUES_FOR_ALL_MODES */
      }
   }
   else
   {
      /* Do nothing */
      /* Since this mode becomes OFF, it can never come back to ON */
   }
}
/**
 * \brief
 *		Defined macro from C file.
 */
#define MMG_AC_ModeManagement_STOP_SEC_CODE
#include "MMG_AC_ModeManagement_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/

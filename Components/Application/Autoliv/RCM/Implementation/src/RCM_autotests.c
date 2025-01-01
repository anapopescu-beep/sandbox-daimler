
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
$Revision: 1.1.1.3.3.1 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/RCM/Implementation/src/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup RCM_autotests.c RCM
 *  This is a new created group, this will create a new man3 file with 
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file. 
 */
 
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Rte_RCM_AC_ResetCauseManagement.h"
#include "Rcm.h"

#include "NVP_Stubs.h"
#include "RCM_Callout_Stubs.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

/**
 * \brief
 *		Defined macro from C file.
 */
#define RCM_AC_ResetCauseManagement_START_SEC_VAR_UNSPECIFIED
#include "RCM_AC_ResetCauseManagement_MemMap.h"
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
/**
 * @ingroup RCM
 * \brief
 *		Variable used to check if the search for the reset cause was executed.
 */
static boolean b8IsResetCauseChecked = B_FALSE;

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
/**
 * \brief
 *		Defined macro from C file.
 */
#define RCM_AC_ResetCauseManagement_STOP_SEC_VAR_UNSPECIFIED
#include "RCM_AC_ResetCauseManagement_MemMap.h"

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
#define RCM_AC_ResetCauseManagement_START_SEC_CODE
#include "RCM_AC_ResetCauseManagement_MemMap.h"

/**
* \brief
*     This autotest aims at checking if an unexpected reset cause has been detected.
* \param
*     None.
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     The test result (uint8):
*        - KU8_ATM_TEST_OK
*        - KU8_ATM_TEST_NOK
*        - KU8_ATM_TEST_NOT_DECIDED
**/
void RCM_Autotest_RunResetCause(u8TestResultType * pu8TestResult)
{
   uint8 u8ResultOfAutoTest;
   uint32 u32ResetCause;

   /* If the reset cause has not been checked */
   if ( B_FALSE == b8IsResetCauseChecked )
   {
      RCM_runGetResetCause(&u32ResetCause);

      /* If the reset cause is an unexpected one */
      if ( (KU32_ZERO != (u32ResetCause & (KU32_CRYSTAL_FAILURE_MASK
                                         | KU32_PLL_FAILURE_MASK
                                         | KU32_INVALID_INTERRUPT_MASK
                                         | KU32_MACHINE_EXCEPTION_MASK
                                         | KU32_ECC_UNIDENTIFIED_MASK
                                         | KU32_OS_EXCEPTION_MASK
                                         | KU32_STACK_OVERFLOW_MASK
                                         | KU32_ECC_RAM_MASK
                                         | KU32_ECC_PFLASH_MASK
                                         | KU32_ECC_E2P_MASK
                               | KU32_EXTERNAL_WDG_MASK)))
            || (KU32_RESET_CAUSE_UNKNOWN == u32ResetCause)
         )
      {
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
      else
      {
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }

      /* Indicate reset cause has been checked */
      b8IsResetCauseChecked = B_TRUE;
   }
   else
   {
      /* Reset cause status already checked -> indicate test is successful */
      u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }

   /* Return the auto test status */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
* \brief
*     This autotest aims at checking if external watchdog test has been passed.
* \param
*     None.
* \exception
*     None. 
* \pre
*     None.
* \post
*     None.
* \return
*     The test result (uint8):
*        - KU8_ATM_TEST_OK
*        - KU8_ATM_TEST_NOK
*        - KU8_ATM_TEST_NOT_DECIDED
**/
void RCM_Autotest_RunExtWDTest(u8TestResultType * pu8TestResult)
{
   uint8 u8ResultOfAutoTest = (uint8)KU32_ZERO;
   uint8 pu8WdtTestResult = (uint8)KU32_ZERO;

   RCM_runGetTestResult(&pu8WdtTestResult);

   /* Check if external WDG Test has failed */
   if(pu8WdtTestResult == KU8_WDG_TEST_FAILED)
   {
      /* Signal error */
      u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }
   else
   {
      u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }


   /* Return the auto test status */
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
 * \brief
 *		Defined macro from C file.
 */
#define RCM_AC_ResetCauseManagement_STOP_SEC_CODE
#include "RCM_AC_ResetCauseManagement_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/





















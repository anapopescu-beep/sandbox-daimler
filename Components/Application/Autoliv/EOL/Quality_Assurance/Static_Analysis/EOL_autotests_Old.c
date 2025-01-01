
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
$Revision: 1.6.1.5 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/EOL/Quality_Assurance/Static_Analysis/project.pj $
*/
/* PRQA S 0288 -- */

/**
 *  @defgroup TEMPLATE_FILES_Group_Example Group_Example_Name_In_Document
 *  This is a new created group, this will create a new man3 file with 
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file. 
 */
 
/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "common.h"
#include "Rte_EOL_AC_EndOfLifeManagement.h"
#include "EOL.h"
#include "EOL_private.h"
#include "Nvp_Generated.h"
#include "Nvp_Cfg.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/
#define COUNTER_LIMIT_ENABLED   (uint8)0x00
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
#define EOL_AC_EndOfLifeManagement_START_SEC_CODE
#include "EOL_AC_EndOfLifeManagement_MemMap.h"
/**
* \brief
*     Check if comfort counter "end of life" is reached or not
* \param
*     *u8TestResultType - test result of the autotest
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
void EOL_Autotest_CheckProductEndOfLifeComfort(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   if(NVP_stVehicleEquipmentData.CounterLimitActivation == COUNTER_LIMIT_ENABLED)
   {
      /* [COVERS: DSG_EOL_0008] */
      /* Check if "Comfort end of life" is reached */
      if (NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_COMFORT_LEVEL] >= CALIB_BLOCK_ID_EOL_PARAM_RomBlockData.NVP_u32ComfortCyclesEOLThrs)
      {
         /* Indicate the auto test is failed */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
      else
      {
         /* Indicate the auto test is successful */
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
   }
   else
   {
      /* autotest disabled */
   }

   *pu8TestResult = u8ResultOfAutoTest;
}

/**
* \brief
*     Check if low force counter "end of life" is reached or not
* \param
*     *u8TestResultType - test result of the autotest
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
void EOL_Autotest_CheckProductEndOfLifeLowForce(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   if(NVP_stVehicleEquipmentData.CounterLimitActivation == COUNTER_LIMIT_ENABLED)
   {
      /* [COVERS: DSG_EOL_0006] */
      /* Check if "Low end of life" is reached */
      if (NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_LOW_FORCE_LEVEL] >= CALIB_BLOCK_ID_EOL_PARAM_RomBlockData.NVP_u32LowForceEOLThrs)
      {
         /* Indicate the auto test is failed */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
      else
      {
         /* Indicate the auto test is successful */
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
   }
   else
   {
      /* autotest disabled */
   }
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
* \brief
*     Check if high force counter "end of life" is reached or not
* \param
*     *u8TestResultType - test result of the autotest
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
void EOL_Autotest_CheckProductEndOfLifeHighForce(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;


   if(NVP_stVehicleEquipmentData.CounterLimitActivation == COUNTER_LIMIT_ENABLED)
   {
      /* [COVERS: DSG_EOL_0007] */
      /* Check if "High end of life" is reached */
      if (NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_HIGH_FORCE_LEVEL] >= CALIB_BLOCK_ID_EOL_PARAM_RomBlockData.NVP_u32HighForceEOLThrs )
      {
         /* Indicate the auto test is failed */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
      else
      {
         /* Indicate the auto test is successful */
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
   }
   else
   {
      /* autotest disabled */
   }

   *pu8TestResult = u8ResultOfAutoTest;
}

/**
* \brief
*     Check if max force counter "end of life" is reached or not
* \param
*     *u8TestResultType - test result of the autotest
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
void EOL_Autotest_CheckProductEndOfLifeMaxForce(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* [COVERS: DSG_EOL_0010] */
   if(NVP_stVehicleEquipmentData.CounterLimitActivation == COUNTER_LIMIT_ENABLED)
   {
      /* Check if "Max end of life" is reached */
      if (NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_MAX_FORCE_LEVEL] >= CALIB_BLOCK_ID_EOL_PARAM_RomBlockData.NVP_u32MaxForceEOLThrs )
      {
         /* Indicate the auto test is failed */
         u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
      else
      {
         /* Indicate the auto test is successful */
         u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
   }
   else
   {
      /* autotest disabled */
   }
   *pu8TestResult = u8ResultOfAutoTest;
}

/**
 * \brief
 *		Defined macro from C file.
 */
#define EOL_AC_EndOfLifeManagement_STOP_SEC_CODE
#include "EOL_AC_EndOfLifeManagement_MemMap.h"
/******************************************************************************
End Of File
*****************************************************************************/

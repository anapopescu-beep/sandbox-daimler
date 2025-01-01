
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
$Revision: 1.34.1.39 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/CIL/Implementation/src/project.pj $
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
#include "Rte_CIL_AC_CommunicationInteractionLayer.h"
#include "common.h"

#include "CIL.h"
#include "Nvp_Cfg.h"

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
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *    This variable is used for deskill timout for Presafe
 * \remarks
 *    None.
 */
LOCAL uint8 cil_u8DeskillCounterPresf = KU8_ZERO;
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *    This variable is used for deskill timout for Buckle
 * \remarks
 *    None.
 */
LOCAL uint8 cil_u8DeskillCounterBckl = KU8_ZERO;
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *    This variable is used for deskill timout for Belthandover L
 * \remarks
 *    None.
 */
LOCAL uint8 cil_u8DeskillCounterBltL = KU8_ZERO;
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *    This variable is used for deskill timout for Belthandover R
 * \remarks
 *    None.
 */
LOCAL uint8 cil_u8DeskillCounterBltR = KU8_ZERO;
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *    This variable is used for deskill timout for Powertrain
 * \remarks
 *    None.
 */
LOCAL uint8 cil_u8DeskillCounterPwt = KU8_ZERO;

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
 ******************************************************************************/
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *    This variable is used for holding the Implausible Data status on Presafe frame
 * \remarks
 *    None.
 */
uint8 cil_u8ImplausibleData_Presafe = RTE_E_OK;
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *    This variable is used for holding the Implausible Data status on Ignition frame
 * \remarks
 *    None.
 */
uint8 cil_u8ImplausibleData_Ignition = RTE_E_OK;
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *    This variable is used for holding the Implausible Data status on Buckle frame
 * \remarks
 *    None.
 */
uint8 cil_u8ImplausibleData_Buckle = RTE_E_OK;
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *    This variable is used for holding the Implausible Data status on ORC frame
 * \remarks
 *    None.
 */
uint8 cil_u8ImplausibleData_ORC = RTE_E_OK;
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *    This variable is used for holding the Implausible Data status on API frame
 * \remarks
 *    None.
 */
uint8 cil_u8ImplausibleData_API = RTE_E_OK;
/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
******************************************************************************/
/**
* \brief
*		Belt handover availability disabled value
* \remarks
*		None.
*/
#define BLTHANDOVER_AVAILABILITY_DISABLED    ((uint8) 0x01)
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
#define CIL_AC_CommunicationInteractionLayer_START_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"

/**
* \brief
*     This is the test function for Timeout on Presafe frame.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/

void CIL_Autotest_Presafe_CheckTimeoutError(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   /* This is the status of the AEC associated to this auto-test */
   u8AecStatusType cil_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;
   /* [COVERS: DSG_CIL_0300, DSG_CIL_0301, DSG_CIL_0303] */
   /* Read last state of autotest */
   (void)Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_TIMEOUT_PRESAFE_AEC_CFG, &cil_u8AECStatus);
   /* [COVERS: DSG_CIL_0209, DSG_CIL_0210, DSG_CIL_0211] */
   /* Check timeout error flag */
   if(B_TRUE == CIL_bTimeoutError_Presf)
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }
   else
   {
      /* Bit ERH_KU8_AEC_QUALIFIED_STATUS_MASK clear means that AEC is cleared */
      if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK != (cil_u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
      {
         cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
      /*  AEC is qualified */
      else
      {
         /* Increment deskill counter*/
         cil_u8DeskillCounterPresf++;

         /*  Check if dskill counter vs notification counter in order to deskill AEC */
         if(cil_u8CounterNotifPresf >= cil_u8DeskillCounterPresf)
         {
            /*  Check if 3 consecutive frames were received in order to deskill AEC */
            if (KU8_THREE <= cil_u8DeskillCounterPresf)
            {
               /*  Reset counters */
               cil_u8DeskillCounterPresf = KU8_ZERO;
               cil_u8CounterNotifPresf = KU8_ZERO;

               /* return OK */
               cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
            }
            else
            {
               /* return NOK */
               cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
            }
         }
         else
         {
            /*  Reset counters */
            cil_u8DeskillCounterPresf = KU8_ZERO;
            cil_u8CounterNotifPresf = KU8_ZERO;

            /* return NOK */
            cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
      }
   }

   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}

/**
* \brief
*     This is the test function for Timeout on Buckle frame.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/
void CIL_Autotest_Buckle_CheckTimeoutError(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   /* This is the status of the AEC associated to this auto-test */
   u8AecStatusType cil_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;
   /* [COVERS: DSG_CIL_0300, DSG_CIL_0301, DSG_CIL_0303] */
   /* Read last state of autotest */
   (void)Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_TIMEOUT_BUCKLE_AEC_CFG, &cil_u8AECStatus);
   /* [COVERS: DSG_CIL_0212, DSG_CIL_0213, DSG_CIL_0214] */
   /* Check timeout error flag */
   if(B_TRUE == CIL_bTimeoutError_Bckl)
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }
   else
   {
      /* Bit ERH_KU8_AEC_QUALIFIED_STATUS_MASK clear means that AEC is cleared */
      if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK != (cil_u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
      {
         cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
      }
      /*  AEC is qualified */
      else
      {
         /* Increment deskill counter*/
         cil_u8DeskillCounterBckl++;

         /*  Check if dskill counter vs notification counter in order to deskill AEC */
         if((cil_u8CounterNotifBckl == cil_u8DeskillCounterBckl) || (cil_u8CounterNotifBckl == (cil_u8DeskillCounterBckl + KU8_ONE)) )
         {
            /*  Check if 3 consecutive frames were received in order to deskill AEC */
            if (KU8_THREE == cil_u8CounterNotifBckl)
            {
               /*  Reset counters */
               cil_u8DeskillCounterBckl = KU8_ZERO;
               cil_u8CounterNotifBckl = KU8_ZERO;

               /* return OK */
               cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
            }
            else
            {
               /* return NOK */
               cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
            }
         }
         else
         {
            /*  Reset counters */
            cil_u8DeskillCounterBckl = KU8_ZERO;
            cil_u8CounterNotifBckl = KU8_ZERO;

            /* return NOK */
            cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
      }
   }

   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}

/**
* \brief
*     This is the test function for Timeout on API frame.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/
void CIL_Autotest_CheckTimeoutError_API(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* [COVERS: DSG_CIL_0215, DSG_CIL_0216, DSG_CIL_0217] */
   if(B_FALSE == CIL_bTimeoutError_API)
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }
   else
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }

   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}

/**
* \brief
*     This is the test function for Timeout on Belthandover L frame.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/
void CIL_Autotest_CheckTimeoutError_BelthandoverL(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   /* This is the status of the AEC associated to this auto-test */
   u8AecStatusType cil_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;
   /* [COVERS: DSG_CIL_0300, DSG_CIL_0301, DSG_CIL_0303] */
   /* Read last state of autotest */
   (void)Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_TIMEOUT_BLTHD_L_AEC_CFG, &cil_u8AECStatus);

   /* Bit ERH_KU8_AEC_QUALIFIED_STATUS_MASK clear means that AEC is cleared */
   if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK != (cil_u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
   {
      if(NVP_stVehicleEquipmentData.BltHandOverAvailabiliy != BLTHANDOVER_AVAILABILITY_DISABLED)
      {
         /* [COVERS: DSG_CIL_0218, DSG_CIL_0219, DSG_CIL_0220] */
         if(B_FALSE == CIL_bTimeoutError_BHL)
         {
            cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
         else
         {
            cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
      }
      else
      {
         /* autotest disabled */
      }

   }
   /*  AEC is qualified */
   else
   {

      /* Increment deskill counter*/
      cil_u8DeskillCounterBltL++;

      /*  Check if 3 consecutive frames were received in order to deskill AEC */
      if((cil_u8CounterNotifBltL == cil_u8DeskillCounterBltL ) || (cil_u8CounterNotifBltL == (cil_u8DeskillCounterBltL + KU8_ONE)))
      {
         if(KU8_THREE == cil_u8CounterNotifBltL)
         {
            /*  Reset counters */
            cil_u8DeskillCounterBltL = KU8_ZERO;
            cil_u8CounterNotifBltL = KU8_ZERO;
            if(NVP_stVehicleEquipmentData.BltHandOverAvailabiliy != BLTHANDOVER_AVAILABILITY_DISABLED)
            {
               /* [COVERS: DSG_CIL_0218, DSG_CIL_0219, DSG_CIL_0220] */
               if(B_FALSE == CIL_bTimeoutError_BHL)
               {
                  cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
               }
               else
               {
                  cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
               }
            }
            else
            {
               /* autotest disabled */
            }
         }
         else
         {
            cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
      }
      else
      {
         /*  Reset counters */
         cil_u8CounterNotifBltL = KU8_ZERO;
         cil_u8DeskillCounterBltL = KU8_ZERO;

         cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }

   }
   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}

/**
* \brief
*     This is the test function for Timeout on Belthandover R frame.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/
void CIL_Autotest_CheckTimeoutError_BelthandoverR(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   /* This is the status of the AEC associated to this auto-test */
   u8AecStatusType cil_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;
   /* [COVERS: DSG_CIL_0300, DSG_CIL_0301, DSG_CIL_0303] */
   /* Read last state of autotest */
   (void)Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_TIMEOUT_BLTHD_R_AEC_CFG, &cil_u8AECStatus);
   /* [COVERS: DSG_CIL_0221, DSG_CIL_0222, DSG_CIL_0223] */
   /* Bit ERH_KU8_AEC_QUALIFIED_STATUS_MASK clear means that AEC is cleared */
   if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK != (cil_u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
   {
      if(NVP_stVehicleEquipmentData.BltHandOverAvailabiliy != BLTHANDOVER_AVAILABILITY_DISABLED)
      {
         /* [COVERS: DSG_CIL_0218, DSG_CIL_0219, DSG_CIL_0220] */
         if(B_FALSE == CIL_bTimeoutError_BHR)
         {
            cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
         else
         {
            cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
      }
      else
      {
         /* autotest disabled */
      }

   }
   /*  AEC is qualified */
   else
   {
      /* Increment deskill counter*/
      cil_u8DeskillCounterBltR++;

      /*  Check if 3 consecutive frames were received in order to deskill AEC */
      if((cil_u8CounterNotifBltR == cil_u8DeskillCounterBltR) || (cil_u8CounterNotifBltR == (cil_u8DeskillCounterBltR + KU8_ONE)))
      {
         if(KU8_THREE == cil_u8DeskillCounterBltR)
         {
            /*  Reset counters */
            cil_u8DeskillCounterBltR = KU8_ZERO;
            cil_u8CounterNotifBltR = KU8_ZERO;
            if(NVP_stVehicleEquipmentData.BltHandOverAvailabiliy != BLTHANDOVER_AVAILABILITY_DISABLED)
            {
               /* [COVERS: DSG_CIL_0218, DSG_CIL_0219, DSG_CIL_0220] */
               if(B_FALSE == CIL_bTimeoutError_BHR)
               {
                  cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
               }
               else
               {
                  cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
               }
            }
            else
            {
               /* autotest disabled */
            }
         }
         else
         {
            cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
         }
      }
      else
      {
         /*  Reset counters */
         cil_u8CounterNotifBltR = KU8_ZERO;
         cil_u8DeskillCounterBltR = KU8_ZERO;

         cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }

   }
   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}

/**
* \brief
*     This is the test function for Timeout on Ignition frame.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/
void CIL_Autotest_CheckTimeoutError_Ignition(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* [COVERS: DSG_CIL_0224, DSG_CIL_0225, DSG_CIL_0226] */
   if(B_FALSE == CIL_bTimeoutError_Ign)
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }
   else
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }

   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}

/**
* \brief
*     This is the test function for Timeout on Powertrain frame.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/
void CIL_Autotest_CheckTimeoutError_Powertrain(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;
   /* This is the status of the AEC associated to this auto-test */
   u8AecStatusType cil_u8AECStatus = ERH_KU8_AEC_QUALIFIED_STATUS_MASK;
   /* [COVERS: DSG_CIL_0300, DSG_CIL_0301, DSG_CIL_0303] */
   /* Read last state of autotest */
   (void)Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_TIMEOUT_POWERTRAIN_AEC_CFG, &cil_u8AECStatus);
   /* [COVERS: DSG_CIL_0227, DSG_CIL_0228, DSG_CIL_0229] */
   /* Check timeout error flag */
      if(B_TRUE == CIL_bTimeoutError_PwTrain)
      {
         cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
      }
      else
      {
         /* Bit ERH_KU8_AEC_QUALIFIED_STATUS_MASK clear means that AEC is cleared */
         if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK != (cil_u8AECStatus & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
         {
            cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
         }
         /*  AEC is qualified */
         else
         {
            /* Increment deskill counter*/
            cil_u8DeskillCounterPwt++;

            /*  Check if dskill counter vs notification counter in order to deskill AEC */
            if((cil_u8CounterNotifPwt == cil_u8DeskillCounterPwt) || (cil_u8CounterNotifPwt == (cil_u8DeskillCounterPwt + KU8_ONE)) )
            {
               /*  Check if 3 consecutive frames were received in order to deskill AEC */
               if (KU8_THREE == cil_u8CounterNotifPwt)
               {
                  /*  Reset counters */
                  cil_u8DeskillCounterPwt = KU8_ZERO;
                  cil_u8CounterNotifPwt = KU8_ZERO;

                  /* return OK */
                  cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
               }
               else
               {
                  /* return NOK */
                  cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
               }
            }
            else
            {
               /*  Reset counters */
               cil_u8DeskillCounterPwt = KU8_ZERO;
               cil_u8CounterNotifPwt = KU8_ZERO;

               /* return NOK */
               cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
            }
         }
      }
   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}

/**
* \brief
*     This is the test function for Implausible Data on Buckle frame.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/
void CIL_Autotest_CheckImplausibleData_Buckle(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* [COVERS: DSG_CIL_0056, DSG_CIL_0206, DSG_CIL_0207, DSG_CIL_0208] */
   if((RTE_E_SOFT_TRANSFORMER_ERROR == cil_u8ImplausibleData_Buckle) ||
         (RTE_E_HARD_TRANSFORMER_ERROR == cil_u8ImplausibleData_Buckle) ||
         (I_C02_BCKL_SW_STAT_SNA == cil_u8BcklSwStatSignal) ||
         (I_C02_BCKL_SW_STAT_FLT == cil_u8BcklSwStatSignal))
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }
   else
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }

   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}


/**
* \brief
*     This is the test function for Implausible Data on Ignition frame.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/
void CIL_Autotest_CheckImplausibleData_Ignition(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* [COVERS: DSG_CIL_0055, DSG_CIL_0239, DSG_CIL_0240, DSG_CIL_0241] */
   if((RTE_E_SOFT_TRANSFORMER_ERROR == cil_u8ImplausibleData_Ignition) ||
         (RTE_E_HARD_TRANSFORMER_ERROR == cil_u8ImplausibleData_Ignition) ||
         (I_C03_ISW_STAT_SNA == cil_stIgnStatFrame.ISw_Stat_ST3))
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }
   else
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }

   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}

	/**
* \brief
*     This is the test function for Implausible Data on Presafe frame.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/
void CIL_Autotest_CheckImplausibleData_Presafe(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* [COVERS: DSG_CIL_0054, DSG_CIL_0233, DSG_CIL_0234, DSG_CIL_0235] */
   if((RTE_E_SOFT_TRANSFORMER_ERROR == cil_u8ImplausibleData_Presafe) ||
         (RTE_E_HARD_TRANSFORMER_ERROR == cil_u8ImplausibleData_Presafe) ||
         (I_C04_PRESF_FRCT_ST3_SNA == cil_stPresfActAdjFrame.Presf_Lvl_ST3) )
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }
   else
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }

   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}

/**
* \brief
*     This is the test function for Steering configuration.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/
void CIL_Autotest_CheckSteeringConfiguration(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* [COVERS: DSG_CIL_0230, DSG_CIL_0231, DSG_CIL_0232] */
   if( ((KU8_ONE == NVP_stVehicleEquipmentData.VehicleSteeringConfig) && (KU8_ONE == NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8SteeringWheelConfig)) ||
         ((KU8_ZERO == NVP_stVehicleEquipmentData.VehicleSteeringConfig) && (KU8_TWO == NVP_BLOCK_ID_CAN_INPUT_SIGNALS_RamBlockData.NVP_u8SteeringWheelConfig)) )
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }
   else
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }

   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}
/**
* \brief
*     This is the test function for ORC.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/
void CIL_Autotest_CheckImplausibleData_ORC(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* [COVERS: DSG_CIL_0236, DSG_CIL_0237, DSG_CIL_0238] */
   if((RTE_E_SOFT_TRANSFORMER_ERROR == cil_u8ImplausibleData_ORC) ||
         (RTE_E_HARD_TRANSFORMER_ERROR == cil_u8ImplausibleData_ORC))
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }
   else
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }

   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}
/**
* \brief
*     This is the test function for Powertrain.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/
void CIL_Autotest_CheckImplausibleData_PowertrainRdy(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* [COVERS: DSG_CIL_0182, DSG_CIL_0183, DSG_CIL_0184] */
   if(I_C02_PT_RDY_V2_SNA == cil_stPTCoor4Pr5St3.PT4_PTCoor_PT_Rdy_ST3)
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }
   else
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }

   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}
/**
* \brief
*     This is the test function for Powertrain.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/
void CIL_Autotest_CheckImplausibleData_PowertrainDrv(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* [COVERS: DSG_CIL_0277, DSG_CIL_0276, DSG_CIL_0275] */
   if(I_C04_DRVPOSN_ST3_SNA == cil_stPTCoorDrvPos.PT4_PTCoor_DrvPosn_Stat_ST3)
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }
   else
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }

   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}
/**
* \brief
*     This is the test function for Timeout on Ignition frame.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/
void CIL_Autotest_CheckTimeoutError_OdoSpeedometer(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* [COVERS: DSG_CIL_0272, DSG_CIL_0273, DSG_CIL_0274] */
   if(B_FALSE == CIL_bTimeoutError_OdoS)
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }
   else
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }

   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}


/**
* \brief
*     This is the test function for Timeout on BeltAdj frame.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/
void CIL_Autotest_CheckTimeoutError_BeltAdj(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   /* [COVERS: DSG_CIL_0305, DSG_CIL_0306, DSG_CIL_0307] */
   if(B_FALSE == CIL_bTimeoutError_BeltAdj)
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }
   else
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }

   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}
/**
* \brief
*     This is the test function for Implausible data API.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/
void CIL_Autotest_CheckImplausibleData_API(u8TestResultType * pu8TestResult)
{
	/* Returned status */
	u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

	/* [COVERS: DSG_CIL_0280, DSG_CIL_0279, DSG_CIL_0278] */
	if(((KU8_CIL_ECU_SIDE_FRONT_LEFT == KU8_CIL_ECU_LOCATION) && (I_C06_RBTM_LVL_RQ_SNA == cil_stAPIInterface.RBTMFL_SP_Lvl_Rq_ST35)) ||
	   ((KU8_CIL_ECU_SIDE_FRONT_RIGHT == KU8_CIL_ECU_LOCATION) && (I_C06_RBTM_LVL_RQ_SNA == cil_stAPIInterface.RBTMFR_SP_Lvl_Rq_ST35)))
	{
		cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
	}
	else  if((RTE_E_SOFT_TRANSFORMER_ERROR == cil_u8ImplausibleData_API) ||
			(RTE_E_HARD_TRANSFORMER_ERROR == cil_u8ImplausibleData_API))
	{
		cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
	}
	else
	{
		cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
	}

	/* Return the auto test status */
	*pu8TestResult = cil_u8ResultOfAutoTest;
}
/**
* \brief
*     This is the test function for VariantCoding.
* \param
*      [u8TestResultType * pu8TestResult]
*      The test result (uint8):
*      - KU8_ATM_TEST_OK
*      - KU8_ATM_TEST_NOK
*      - KU8_ATM_TEST_NOT_DECIDED
*
* \exception
*     None.
* \pre
* \post
*     None.
* \return
*     None.
**/

void CIL_Autotest_CheckVariantCoding(u8TestResultType * pu8TestResult)
{
   /* Returned status */
   u8TestResultType cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOT_DECIDED;

   uint8 ErrorFlag_Variant = KU8_FALSE;
   uint8 ErrorFlag_Vehicle = KU8_FALSE;

   /* [COVERS: DSG_CIL_0283, DSG_CIL_0282, DSG_CIL_0281] */
   (void)Rte_Read_CIL_AC_CommunicationInteractionLayer_prrVehicleEquipmentValidity_u8CodingValidity(&ErrorFlag_Variant);
   (void)Rte_Read_CIL_AC_CommunicationInteractionLayer_prrVehicleEquipmentValidity_u8VehicleEquipValidity(&ErrorFlag_Vehicle);

   if( (KU8_TRUE == ErrorFlag_Variant) && (KU8_TRUE == ErrorFlag_Vehicle) )
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_OK;
   }
   else
   {
      cil_u8ResultOfAutoTest = KU8_ATM_TEST_NOK;
   }

   /* Return the auto test status */
   *pu8TestResult = cil_u8ResultOfAutoTest;
}
/**
 * \brief
 *		Defined macro from C file.
 */

#define CIL_AC_CommunicationInteractionLayer_STOP_SEC_CODE
#include "CIL_AC_CommunicationInteractionLayer_MemMap.h"

/******************************************************************************
End Of File
*****************************************************************************/

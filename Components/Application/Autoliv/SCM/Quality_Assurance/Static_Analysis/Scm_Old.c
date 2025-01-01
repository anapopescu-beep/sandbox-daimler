
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
/*
 * Explanation:
 *    Disabled for MKS keywords
 */
/*
$Revision: 1.9.1.4 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/SCM/Quality_Assurance/Static_Analysis/project.pj $
 */
/**
 *  This is a new created group, this will create a new man3 file with 
 *  group members described in that file. Members description of a group
 *  will contain only description from brief section in their original file. 
 */

/******************************************************************************
EXTERNAL DEPENDENCIES
******************************************************************************/
#include "Common.h"
#include "Config.h"
#include "Rte_SCM_AC_SystemContextManagement.h"
#include "Nvp_Generated.h"
#include "Scm_Public.h"
#include "Scm_Cfg.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *      Value for system context storage delay
 * \remarks
 *		None.
 */
#define SCM_KU32_DELAY_SYSTEM_CONTEXT_STORAGE                   ((uint32)1)

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
#define SCM_AC_SystemContextManagement_START_SEC_VAR_INIT_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

/**
 * \brief 
 *      Boolean set to TRUE when the battery level is OK after a battery loss situation
 * \remarks
 *		None.
 */
LOCAL boolean scm_bIsSystemContextReallocationRequested     = KU8_FALSE;
/**
* \brief 
*       Boolean write in shutdown in order to perform only one time the saving of System context
* \remarks
*		None.
*/
LOCAL boolean scm_bIsSystemContextShutdownStored            = KU8_FALSE;
/**
* \brief 
*      Previous Executed cycle.Only used by SCM_runMonitoreExecutedCycle
* \remarks
*		None.
*/
LOCAL u8CycleNumberType scm_u8ExecutedCycleMemory           = KU8_NO_CYCLE;
/**
* \brief 
*      Indicates if system context needs to be saved.
* \remarks
*		None.
*/
LOCAL uint8 scm_b8NeedSystemContextToBeKeptForCycle         = KU8_FALSE;

#define SCM_AC_SystemContextManagement_STOP_SEC_VAR_INIT_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
 ******************************************************************************/

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
 ******************************************************************************/
#define SCM_AC_SystemContextManagement_START_SEC_VAR_INIT_32
#include "SCM_AC_SystemContextManagement_MemMap.h"
/**
* \brief 
*      Data to store the last System Time used for the last System Context telegram
* \remarks
*		None.
*/ 
uint32 SCM_u32OldSystemTime                        = KU32_ZERO;

#define SCM_AC_SystemContextManagement_STOP_SEC_VAR_INIT_32
#include "SCM_AC_SystemContextManagement_MemMap.h"

#define SCM_AC_SystemContextManagement_START_SEC_VAR_INIT_8
#include "SCM_AC_SystemContextManagement_MemMap.h"
/**
* \brief 
*      Data to know if a Release has to be triggered
* \remarks
*		None.
*/ 
uint8 SCM_b8ReleaseHasToBeTriggered                = KU8_FALSE;
/**
* \brief 
* Boolean set to TRUE when a battery loss is detected
* \remarks
*		None.
*/
boolean SCM_bIsSystemContextStorageRequested       = KU8_FALSE;

#define SCM_AC_SystemContextManagement_STOP_SEC_VAR_INIT_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

#define SCM_AC_SystemContextManagement_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SCM_AC_SystemContextManagement_MemMap.h"
/**
* \brief 
*      Buffer for system context in order to know what belt function Id shall be stored in NVM during shutdown
* \remarks
*		None.
*/
uint8 SCM_u8LastInterruptedCycleNumber;
/**
* \brief 
*      Mirror data to validate data integrity
* \remarks
*		None.
*/
uint8 SCM_u8LastInterruptedCycleNumber_Mirror;

#define SCM_AC_SystemContextManagement_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SCM_AC_SystemContextManagement_MemMap.h"

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
 ******************************************************************************/
#define SCM_AC_SystemContextManagement_START_SEC_CODE
#include "SCM_AC_SystemContextManagement_MemMap.h"
/**
 * \brief
 *     Function called in the context of a battery loss detection or standard shutdown situation
 * \param
 *     b8IsBatteryLoss - KU8_TRUE : function called in the context of a battery loss detection
                        KU8_FALSE : function called in the context of a standard shutdown situation.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
LOCAL void scm_ManageSystemContextStorage (const uint8 b8IsBatteryLoss)
{
	uint32 u32DelaySystemContextStorage;
	stAbsoluteSystemTimeType stAbsoluteSystemTimeTemp;
   uint8 u8SWProtectionAECState;
   b8PyroActivationStatusType pb8PyroActivationStatus;

   /* Read System time */
   (void)Rte_Call_pclSystemTime_ReadAbsoluteSystemTime(&stAbsoluteSystemTimeTemp);
   SCM_stCurrentSystemContextContent.u32StoreSystemTime = stAbsoluteSystemTimeTemp.u32SystemTimeInSec;

   if((KU8_FALSE == scm_b8NeedSystemContextToBeKeptForCycle) || (KU8_NO_CYCLE != SCM_u8LastInterruptedCycleNumber))
   {
      /* Get current executed cycle */
      SCM_stCurrentSystemContextContent.u8StoreExecutedCycle = SCM_u8LastInterruptedCycleNumber;
   }
   else
   {
      /* Do not update interrupted cycle number to remember a cycle was aborted but system context could
       * not have been stored */
      if(KU8_TRUE == scm_b8NeedSystemContextToBeKeptForCycle)
      {
         scm_b8NeedSystemContextToBeKeptForCycle = KU8_FALSE;
      }
   }

   /* Get deficiency level */
   (void)Rte_Call_pclMotor_T_GetDeficiencyLevel(&SCM_stCurrentSystemContextContent.u32StoreDeficiencyLevel);

   /* Get SW Self protection AEC State */
   (void)Rte_Call_pclAecStatus_GetAecStatus(ERH_KU8_SW_SELF_PROTECTION_AEC_CFG, &u8SWProtectionAECState);

   /* Check if SW self protection is actually qualified */
   if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK == (u8SWProtectionAECState & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
   {
      /* AEC is qualified, set MSB of deficiency to keep the information for the next startup  */
      U32_BIT_SET( SCM_stCurrentSystemContextContent.u32StoreDeficiencyLevel, SCM_KU32_SW_PROTECTION_BIT_MASK );
   }
   else
   {
      /* AEC is not qualified, clear the MSB of the deficiency level */
      U32_BIT_CLEAR( SCM_stCurrentSystemContextContent.u32StoreDeficiencyLevel, SCM_KU32_SW_PROTECTION_BIT_MASK );
   }

   /* Update KL30 loss status */
   SCM_stCurrentSystemContextContent.b8StoreKL30Lost = b8IsBatteryLoss;

   /* Update pyro activation source if different from previous stored one and different from "no activation source" */
   (void)Rte_Call_pclPyroDevice_GetPyroActivationStatus(&pb8PyroActivationStatus);

   SCM_stCurrentSystemContextContent.u8CPLstatus = KU8_FALSE;

   if (pb8PyroActivationStatus == KB8_PYRO_DEVICE_ACTIVATED)
   {
      SCM_stCurrentSystemContextContent.u8CPLstatus = KU8_TRUE;
   }

   /* Compute the system context checksum */
   SCM_stCurrentSystemContextContent.u8StoreSystemContextChecksum = SCM_ComputeSystemContextChecksum(&SCM_stCurrentSystemContextContent);

   /* Compute Delay between two requests to store system context */
   u32DelaySystemContextStorage = SCM_stCurrentSystemContextContent.u32StoreSystemTime - SCM_u32OldSystemTime;

   /* If 1s Delay has overlapped between to request to store system context and place has been reallocated in NVM */
   if((SCM_KU32_DELAY_SYSTEM_CONTEXT_STORAGE < u32DelaySystemContextStorage) && (SCM_KU8_REALLOCATION_FINISHED == SCM_u8SystemContextReallocationStatus))
   {
      /* Update old system time for next check */
      SCM_u32OldSystemTime = SCM_stCurrentSystemContextContent.u32StoreSystemTime;
      SCM_StoreSystemContext();
   }
   else
   {
      /* If a cycle was executed during KL30 loss */
      if(KU8_NO_CYCLE != SCM_stCurrentSystemContextContent.u8StoreExecutedCycle)
      {
         /* Indicate this information shall be kept for next recording */
         scm_b8NeedSystemContextToBeKeptForCycle = KU8_TRUE;
      }
   }
}

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
/**
 * \brief
 *     Periodic function that shall be called with the same period that the Belt Function slack
 * \param
 *     None
 * \exception
 *     None
 * \pre
 *    None
 * \post
 *     None
 * \return
 *     None
  **/
EXPORTED void SCM_runMonitoreExecutedCycle (void)
{
   uint8 u8LocalCurrentCycleNumber;
   uint8 u8LocalIndex;
   boolean bIsReleaseCompleted = KU8_FALSE;
   boolean bIsReleaseAborted   = KU8_FALSE;
   /* To check there is a tensioning cycle */
   u8ModeStatusType u8TensioningModeStatus; // TBD

   /* Read current executed cycle */
   (void)Rte_Read_prrExecutedCycle_u8CycleNumber(&u8LocalCurrentCycleNumber);

   /* Get the "no tensioning" system context status */
   (void)Rte_Call_pclModeManagement_CheckModeStatus(MMG_KU32_MASK_TENSIONING, &u8TensioningModeStatus);

   /* Only process the function if a change has occurred since the last call */
   if ( u8LocalCurrentCycleNumber != scm_u8ExecutedCycleMemory )
   {
      /* In case of a new valid executed cycle */
      if (  (KU8_NO_CYCLE        != u8LocalCurrentCycleNumber) &&
            (KU8_NB_MAX_CYCLES   >  u8LocalCurrentCycleNumber)
      )
      {
         /* A cycle is currently executed
          * Store its identifier into RAM no init variable
          * In case of interruption of this cycle by warm reset
          * */
         if (KU8_MODE_STATUS_ON == u8TensioningModeStatus)
         {
            SCM_u8LastInterruptedCycleNumber = u8LocalCurrentCycleNumber;
         }

         /* Fill in the Mirror variable */
         SCM_u8LastInterruptedCycleNumber_Mirror = (uint8)(~SCM_u8LastInterruptedCycleNumber);

         /* A release has to be triggered */
         SCM_b8ReleaseHasToBeTriggered = KU8_TRUE;
      }
      /* A belt function has just finished */
      else if( KU8_NO_CYCLE == u8LocalCurrentCycleNumber )
      {
         /* Depending of the belt function Identifier and depending of the context
          * abortion or successfully completion
          * */

         /* Capture all interrupt flags before processing */
         SCM_GetReleaseInterruptionFlags();

         /* For each release configured in the application */
         for ( u8LocalIndex = KU8_ZERO ; SCM_KU8_NUMBER_OF_RELEASE > u8LocalIndex ; u8LocalIndex++ )
         {
            if ( ( scm_u8ExecutedCycleMemory == scm_kau8ReleaseIdList[u8LocalIndex]     ) &&
                  ( KU8_TRUE                  == SCM_au8AbortionFlagsArray[u8LocalIndex] )
            )
            {
               /* A release was aborted */
               bIsReleaseAborted = KU8_TRUE;
            }
            else if ( ( scm_u8ExecutedCycleMemory == scm_kau8ReleaseIdList[u8LocalIndex]     ) &&
                  ( KU8_FALSE               == SCM_au8AbortionFlagsArray[u8LocalIndex] )
            )
            {
               /* The release was performed successfully */
               bIsReleaseCompleted = KU8_TRUE;
            }
            else
            {
               /* Nothing to do */
            }
         }
         /* For each production cycle configured in the application */
         for ( u8LocalIndex = KU8_ZERO ; u8LocalIndex  < SCM_KU8_NUMBER_OF_PRODUCTION_CYCLE ; u8LocalIndex++ )
         {
            if (scm_u8ExecutedCycleMemory == scm_kau8ProductionCycleIdList[u8LocalIndex])
            {
               /* Set parameters as if a release were played. Otherwise, there is a 5s delay at initialization before startup cycle */
               bIsReleaseCompleted = KU8_TRUE;
            }
         }
         /* Releasing has just been interrupted, by a cause different from warm reset
          * As release has not been successfully completed a new release will be necessary
          * for instance, after a warm reset, instead of anti-patina cycle.
          * */
         if ( KU8_TRUE == bIsReleaseAborted )
         {
            /* Store the identifier of the interrupted releasing cycle */
            SCM_u8LastInterruptedCycleNumber = scm_u8ExecutedCycleMemory;

            /* Fill in the Mirror variable */
            SCM_u8LastInterruptedCycleNumber_Mirror = (uint8)(~SCM_u8LastInterruptedCycleNumber);

            /* A release has to be triggered */
            SCM_b8ReleaseHasToBeTriggered = KU8_TRUE;
         }
         /* If Release cycle has been successfully completed */
         else if ( KU8_TRUE == bIsReleaseCompleted )
         {
            /* Store no cycle */
            SCM_u8LastInterruptedCycleNumber = KU8_NO_CYCLE;

            /* Fill in the Mirror variable */
            SCM_u8LastInterruptedCycleNumber_Mirror = (uint8)(~SCM_u8LastInterruptedCycleNumber);

            /* NO new release has to be triggered */
            SCM_b8ReleaseHasToBeTriggered = KU8_FALSE;

            /* Clear Release Request for the next System Context storage request */
            SCM_stCurrentSystemContextContent.u8StoreExecutedCycle = KU8_NO_CYCLE;
         }
         /* Not a release */
         else
         {
            /* Nothing to do : no change of the RAM NO INIT data */
         }
      }
      /* In case no cycle was triggered and none was interrupted
       * No need to trig a release instead of startup if a warm reset occurs
       * */
      else if(KU8_TRUE != SCM_b8ReleaseHasToBeTriggered)
      {
         /* Store no cycle */
         SCM_u8LastInterruptedCycleNumber = KU8_NO_CYCLE;

         /* Fill in the Mirror variable */
         SCM_u8LastInterruptedCycleNumber_Mirror = (uint8)(~SCM_u8LastInterruptedCycleNumber);
      }
      else
      {
         /* Do nothing
          * Do not update the RAM no init variable
          * */
      }
   }

   /* Store the current executed cycle for the next function call */
   scm_u8ExecutedCycleMemory = u8LocalCurrentCycleNumber;

   /* If the reallocation failed or was not started */
   if ( SCM_KU8_REALLOCATION_NEEDED == SCM_u8SystemContextReallocationStatus )
   {
      scm_bIsSystemContextReallocationRequested = B_TRUE;
   }
}

#define SCM_AC_SystemContextManagement_STOP_SEC_CODE
#include "SCM_AC_SystemContextManagement_MemMap.h"

/**************************************************************************
Exported Functions
**************************************************************************/
#define SCM_AC_SystemContextManagement_START_SEC_CODE
#include "SCM_AC_SystemContextManagement_MemMap.h"
/**
 * \brief
 *      Callback function provided to the rest of the application to get the last tensioning state
 * \param
 *     pu8LastExecutedCycle - Refer to the type scaling (RTE) for more details
 * \exception
 *     None
 * \pre
 *    None
 * \post
 *     None
 * \return
 *     None
 **/
EXPORTED void SCM_runGetLastTensioningState (u8CycleNumberType * pu8LastExecutedCycle)
{
   *pu8LastExecutedCycle = Rte_IrvRead_SCM_runGetLastTensioningState_u8LastTensioningSituation();
}

/**
 * \brief
 *      Function called during Init sequence to load the last Valid system context stored in E2P
 *      This function shall not be called during the tasks scheduling !!
 * \param
 *     None
 * \exception
 *     None
 * \pre
 *    None
 * \post
 *     None
 * \return
 *     None
 **/
EXPORTED void SCM_runRestoreSystemContext (void)
{
   /* Function call in Cfg part*/
   SCM_RecoverSystemContext();
}

/**
* \brief
*      Periodic main function that shall be called in the same task that the NV stack
*      It collects all notifications from battery loss/recovery mechanism and
*       supervises the executed belt function
* \param
*     None
* \exception
*     None
* \pre
*    None
* \post
*     None
* \return
*     None
**/
EXPORTED void SCM_runManageSystemContext (void)
{
   /* if a request to store system context is pending */
   if(B_TRUE == SCM_bIsSystemContextStorageRequested)
   {
      scm_ManageSystemContextStorage(B_TRUE);
      SCM_bIsSystemContextStorageRequested = B_FALSE;

   }
   /* If a request to reallocate place in NVM for system context is pending */
   else if (B_TRUE == scm_bIsSystemContextReallocationRequested)
   {
      SCM_PrepareSystemContextStorage();
      scm_bIsSystemContextReallocationRequested = B_FALSE;
   }
   else
   {
      /* Do nothing */
   }
}

/**
 * \brief
 *     Function called during shutdown phase by ESM
 * \param
 *     None
 * \exception
 *     None
 * \pre
 *    None
 * \post
 *     None
 * \return
 *     None
 **/
EXPORTED void SCM_runWriteSystemContextShutdown (void)
{
   if ( KU8_FALSE == scm_bIsSystemContextShutdownStored )
   {
      /* Start Write operation */
      scm_ManageSystemContextStorage ( KU8_FALSE );
      /* Clear the "Write once" Flag */
      scm_bIsSystemContextShutdownStored = KU8_TRUE;
   }
}
#define SCM_AC_SystemContextManagement_STOP_SEC_CODE
#include "SCM_AC_SystemContextManagement_MemMap.h"

/******************************************************************************
End Of File
*****************************************************************************/

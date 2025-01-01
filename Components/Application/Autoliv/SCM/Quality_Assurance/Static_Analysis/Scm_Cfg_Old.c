
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
$Revision: 1.10.1.4 $
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
#include "common.h"
#include "Nvp_Generated.h"
#include "SchM_Fee.h"
#include "Fee.h"
#include "SchM_Fls_17_Dmu.h"
#include "Fls_17_Dmu.h"
#include "NvM.h"
#include "MemIf_Types.h"
#include "Nvp_Generated.h"
#include "Rte_SCM_AC_SystemContextManagement.h"
#include "Scm_Cfg.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/
/**
 * \brief
 *		 KL30 & KL30bg multiply factor to be applied on voltage threshold parameters to convert from mV into 10 bits ADC raw format.
 * \remarks
 *		None.
 */
#define SCM_KU32_KL30_MUL_FACTOR                    ((uint32)6 * (uint32)5000)
/**
 * \brief
 *		 KL30 & KL30bg divide factor to be applied on voltage threshold parameters to convert from mV into 10 bits ADC raw format.
 * \remarks
 *		None.
 */
#define SCM_KU32_KL30_DIV_FACTOR                    ((uint32) 1024)
/**
 * \brief
 *		 System context blocks ID 0
 * \remarks
 *		None.
 */
#define SCM_KU8_BLOCK_ID_0                          ((uint8) 0)
/**
 * \brief
 *		 System context blocks ID 1
 * \remarks
 *		None.
 */
#define SCM_KU8_BLOCK_ID_1                          ((uint8) 1)
/**
 * \brief
 *		 System context blocks ID 2
 * \remarks
 *		None.
 */
#define SCM_KU8_BLOCK_ID_2                          ((uint8) 2)


/******************************************************************************
DEFINITION OF LOCAL VARIABLES
 ******************************************************************************/
#define SCM_AC_SystemContextManagement_START_SEC_VAR_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

/**
 * \brief
 *		Local variable which indicates which NvM block of system context is currently used
 * \remarks
 *		None.
 */
LOCAL uint8 scm_u8IndexCurrentSystemContext; /* Initialized during Init function call */

#define SCM_AC_SystemContextManagement_STOP_SEC_VAR_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

#define SCM_AC_SystemContextManagement_START_SEC_VAR_INIT_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

#define SCM_AC_SystemContextManagement_STOP_SEC_VAR_INIT_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

#define SCM_AC_SystemContextManagement_START_SEC_VAR_INIT_16
#include "SCM_AC_SystemContextManagement_MemMap.h"
/**
 * \brief
 *		Local variable which holds the treshold for battery loss
 * \remarks
 *		None.
 */
LOCAL uint16 scm_u16BatteryHysteresisThrs = KU16_ZERO;

#define SCM_AC_SystemContextManagement_STOP_SEC_VAR_INIT_16
#include "SCM_AC_SystemContextManagement_MemMap.h"

/******************************************************************************
DEFINITION OF LOCAL CONSTANT DATA
 ******************************************************************************/
#define SCM_AC_SystemContextManagement_START_SEC_CONST_8
#include "SCM_AC_SystemContextManagement_MemMap.h"
/**
 * \brief
 *		Release belt function position in the cycle library
 * \remarks
 *		None.
 */
const u8CycleNumberType scm_kau8ReleaseIdList[SCM_KU8_NUMBER_OF_RELEASE] =
{
		KU8_BELT_FUNCTION_32   ,  /* Anti Patina    */
		KU8_BELT_FUNCTION_30   ,  /* Hard Release   */
		KU8_BELT_FUNCTION_29   ,  /* Smooth Release */
		KU8_BELT_FUNCTION_31      /* Backup release */
};
/**
 * \brief
 *		Production cycles
 * \remarks
 *		None.
 */
const u8CycleNumberType scm_kau8ProductionCycleIdList[SCM_KU8_NUMBER_OF_PRODUCTION_CYCLE] =
{
		KU8_BELT_FUNCTION_33   ,  /*ANG cycle */
		KU8_BELT_FUNCTION_34     /*AEE cycle */
};

#define SCM_AC_SystemContextManagement_STOP_SEC_CONST_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

#define SCM_AC_SystemContextManagement_START_SEC_CONST_UNSPECIFIED
#include "SCM_AC_SystemContextManagement_MemMap.h"
/**
 * \brief
 *		Default value for system Context in case of recovery error
 * \remarks
 *		None.
 */
const SCM_stSystemContextType scm_kstDefautSystemContextValue =
{
   0u             ,
   0u             ,
   B_FALSE        ,
   KU8_NO_CYCLE   ,
   B_FALSE        ,
   KU8_MAX
};

#define SCM_AC_SystemContextManagement_STOP_SEC_CONST_UNSPECIFIED
#include "SCM_AC_SystemContextManagement_MemMap.h"

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
 ******************************************************************************/
#define SCM_AC_SystemContextManagement_START_SEC_VAR_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

/**
 * \brief
 *		Abortion flags for Release cycles
 * \remarks
 *		None.
 */
uint8 SCM_au8AbortionFlagsArray[SCM_KU8_NUMBER_OF_RELEASE];

#define SCM_AC_SystemContextManagement_STOP_SEC_VAR_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

#define SCM_AC_SystemContextManagement_START_SEC_VAR_INIT_8
#include "SCM_AC_SystemContextManagement_MemMap.h"
/**
 * \brief
 *		Variable used to store system context reallocation status
 * \remarks
 *		None.
 */
uint8 SCM_u8SystemContextReallocationStatus = SCM_KU8_REALLOCATION_FINISHED;

#define SCM_AC_SystemContextManagement_STOP_SEC_VAR_INIT_8
#include "SCM_AC_SystemContextManagement_MemMap.h"

#define SCM_AC_SystemContextManagement_START_SEC_VAR_UNSPECIFIED
#include "SCM_AC_SystemContextManagement_MemMap.h"
/**
 * \brief
 *		Variable used to store the current system context
 * \remarks
 *		None.
 */
SCM_stSystemContextType SCM_stCurrentSystemContextContent;

#define SCM_AC_SystemContextManagement_STOP_SEC_VAR_UNSPECIFIED
#include "SCM_AC_SystemContextManagement_MemMap.h"

/******************************************************************************
DEFINITION OF LOCAL FUNCTION
 ******************************************************************************/
#define SCM_AC_SystemContextManagement_START_SEC_CODE
#include "SCM_AC_SystemContextManagement_MemMap.h"
/**
 * \brief
 *     The goal of this private function is to perform a read operation on
        a System context block in E2P during Init sequence
        This function shall not be called if the NV stack is already running !!!!
 * \param
 *     cu8ScIndex - Block Identifier value that will be read during function execution
 *     pstSystContext - Pointer used as an output parameter to store the system context
                  data
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
LOCAL void scm_RecoverSystemContextContent(const uint8 cu8ScIndex, SCM_stSystemContextType * const pstSystContext)
{
   uint8 u8RequestStatus;
   uint8 u8ReqSynchronousRes;

   /* Read system context data based on cu8ScIndex */
   switch(cu8ScIndex)
   {
   case SCM_KU8_BLOCK_ID_0:
      u8RequestStatus = Rte_Call_NvMService_SYSTEM_CONTEXT_0_ReadBlock(pstSystContext);
      break;

   case SCM_KU8_BLOCK_ID_1:
      u8RequestStatus = Rte_Call_NvMService_SYSTEM_CONTEXT_1_ReadBlock(pstSystContext);
      break;

   case SCM_KU8_BLOCK_ID_2:
      u8RequestStatus = Rte_Call_NvMService_SYSTEM_CONTEXT_2_ReadBlock(pstSystContext);
      break;

   default:
      /* Wrong System context ID, abort function */
      u8RequestStatus = E_NOT_OK;
      break;
   }

   if ( E_OK == u8RequestStatus )
   {
       switch (cu8ScIndex) {
       case KU8_ZERO:
           (void)Rte_Call_NvMService_SYSTEM_CONTEXT_0_GetErrorStatus( &u8ReqSynchronousRes);
           break;
       case KU8_ONE:
           (void)Rte_Call_NvMService_SYSTEM_CONTEXT_1_GetErrorStatus( &u8ReqSynchronousRes);
           break;
       case KU8_TWO:
           (void)Rte_Call_NvMService_SYSTEM_CONTEXT_2_GetErrorStatus( &u8ReqSynchronousRes);
           break;

       default:
           break;
       }

      while(NVM_REQ_PENDING == u8ReqSynchronousRes)
      {
          NvM_MainFunction();
          Fee_MainFunction();
          Fls_17_Dmu_MainFunction();

         /* Check if job is pending or finished */
          switch (cu8ScIndex) {
          case KU8_ZERO:
              (void)Rte_Call_NvMService_SYSTEM_CONTEXT_0_GetErrorStatus( &u8ReqSynchronousRes);
              break;
          case KU8_ONE:
              (void)Rte_Call_NvMService_SYSTEM_CONTEXT_1_GetErrorStatus( &u8ReqSynchronousRes);
              break;
          case KU8_TWO:
              (void)Rte_Call_NvMService_SYSTEM_CONTEXT_2_GetErrorStatus( &u8ReqSynchronousRes);
              break;

          default:
              break;
          }
      }

      /* If read is not successful, use default value */
      if(NVM_REQ_OK != u8ReqSynchronousRes)
      {
         *pstSystContext = scm_kstDefautSystemContextValue;
      }
   }
}

#define SCM_AC_SystemContextManagement_STOP_SEC_CODE
#include "SCM_AC_SystemContextManagement_MemMap.h"

/******************************************************************************
DEFINITION OF APIs
 ******************************************************************************/
#define SCM_AC_SystemContextManagement_START_SEC_CODE
#include "SCM_AC_SystemContextManagement_MemMap.h"

/**
 * \brief
 *     Specific function to retrieve all interruption flags from BFD release algo
        This function is hand coded without function pointers because the RTE macros
        generated by SystemDesk are *********** and can't be handled in a generic way
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
EXPORTED void SCM_GetReleaseInterruptionFlags (void)
{
   (void)Rte_Read_prrAlgo33_Flags_b8InterruptFlag(&SCM_au8AbortionFlagsArray[KU8_ZERO]);

   (void)Rte_Read_prrAlgo31_Flags_b8InterruptFlag(&SCM_au8AbortionFlagsArray[KU8_ONE]);

   (void)Rte_Read_prrAlgo30_Flags_b8InterruptFlag(&SCM_au8AbortionFlagsArray[KU8_TWO]);

   (void)Rte_Read_prrAlgo32_Flags_b8InterruptFlag(&SCM_au8AbortionFlagsArray[KU8_THREE]);
}
/**
 * \brief
 *     Specific function to prepare the E2P blocks before a write operation
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
EXPORTED void SCM_PrepareSystemContextStorage(void)
{
      /* Indicate that reallocation is completed because already done */
      SCM_u8SystemContextReallocationStatus =  SCM_KU8_REALLOCATION_FINISHED;
}
/**
 * \brief
 *     Specific function to recover System Context and select the more recent one
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
EXPORTED void SCM_RecoverSystemContext(void)
{
   stAbsoluteSystemTimeType stAbsoluteSystemTime;
   SCM_stSystemContextType astSystContextTemp[SCM_KU8_MAX_SYSTEM_CONTEXT_SUBBLOCKS];
   uint32 u32ResetCause;
   uint32 u32MaxSystemTime = KU32_ZERO;
   uint16 u16BlockNumberToReallocate;
   uint8 u8ContextIndex;
   uint8 u8IndexToRestore = SCM_KU8_MAX_SYSTEM_CONTEXT_SUBBLOCKS;
   uint8 u8ReadScIndex;

   /* temporary: loop to wait for Fee/Fls initialization to be finished -> should be already finished */
   while(MEMIF_IDLE != Fee_GetStatus())
   {
      Fee_MainFunction();
      Fls_17_Dmu_MainFunction();
   }

   /* Read the three system context blocks */
   /* All system context blocks shall be continus */
   for(u8ReadScIndex = KU8_ZERO ; u8ReadScIndex < SCM_KU8_MAX_SYSTEM_CONTEXT_SUBBLOCKS ; u8ReadScIndex++ )
   {
      scm_RecoverSystemContextContent(u8ReadScIndex, &astSystContextTemp[u8ReadScIndex]);
   }

   /* Check system context validity and search for last stored system context */
   for (u8ContextIndex = KU8_ZERO ; u8ContextIndex < SCM_KU8_MAX_SYSTEM_CONTEXT_SUBBLOCKS ; u8ContextIndex++)
   {
      /* Compute the block checksum and compares it to the recorded one */
      if ((astSystContextTemp[u8ContextIndex].u8StoreSystemContextChecksum == SCM_ComputeSystemContextChecksum(&(astSystContextTemp[u8ContextIndex])))
            && (KU32_MAX != astSystContextTemp[u8ContextIndex].u32StoreSystemTime))
      {
         /* Checksum is OK and system time content is valid ; The block can be taken in account */
         /* If the block has an higher system time that the previous one */
         if (u32MaxSystemTime < astSystContextTemp[u8ContextIndex].u32StoreSystemTime)
         {
            /* Remember the new higher system time */
            u32MaxSystemTime = astSystContextTemp[u8ContextIndex].u32StoreSystemTime;
            /* store current index of system context*/
            u8IndexToRestore = u8ContextIndex;
         }
      }
   }
      /* Has a system context to restore been found ? */
   if (SCM_KU8_MAX_SYSTEM_CONTEXT_SUBBLOCKS != u8IndexToRestore)
   {
      /* Restore the value of last system time recorded */
      SCM_stCurrentSystemContextContent.u32StoreSystemTime = astSystContextTemp[u8IndexToRestore].u32StoreSystemTime;

      stAbsoluteSystemTime.u32SystemTimeInSec = astSystContextTemp[u8IndexToRestore].u32StoreSystemTime;
      stAbsoluteSystemTime.u8SystemTimeOffset = KU8_ZERO;

      /* Update OldSystemTime with recovered value */
      SCM_u32OldSystemTime = SCM_stCurrentSystemContextContent.u32StoreSystemTime;

      /* Restore deficiency level */
      SCM_stCurrentSystemContextContent.u32StoreDeficiencyLevel = astSystContextTemp[u8IndexToRestore].u32StoreDeficiencyLevel;

      /* Check is SW protection AEC was qualified in the previous cycle */
      if ( SCM_KU8_SW_PROTECTION_QUALIFIED_MASK == U32_GET_HIGH_BYTE( SCM_stCurrentSystemContextContent.u32StoreDeficiencyLevel) )
      {
         /* SW protection AEC was qualified in the previous execution cycle */
         /* Set SW Protection AEC => Direct call to ERH module */
    	  (void)Rte_Call_pclAecStatus_SetAecEvent(ERH_KU8_SW_SELF_PROTECTION_AEC_CFG,KU8_AEC_FAILED);

         /* Clear the SW Protection bit before deficiency level initialization */
         U32_BIT_CLEAR(SCM_stCurrentSystemContextContent.u32StoreDeficiencyLevel, SCM_KU32_SW_PROTECTION_BIT_MASK);
      }

      /* Restore battery loss status */
      SCM_stCurrentSystemContextContent.b8StoreKL30Lost = astSystContextTemp[u8IndexToRestore].b8StoreKL30Lost;

      /* Restore eCPL activation status */
      SCM_stCurrentSystemContextContent.u8CPLstatus = astSystContextTemp[u8IndexToRestore].u8CPLstatus;

      if (KU8_TRUE == SCM_stCurrentSystemContextContent.b8StoreKL30Lost)
      {
         (void)Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_BATTERY_LOSS_NOTIFICATION,KU32_RESET_CAUSE_ACTIVE);
      }
      else
      {
         (void)Rte_Call_pclResetCauseNotification_NotifyResetCause(KU32_BATTERY_LOSS_NOTIFICATION,KU32_RESET_CAUSE_INACTIVE);
      }

      /* Restore the last Interrupted Cycle from NVM */
      SCM_stCurrentSystemContextContent.u8StoreExecutedCycle = astSystContextTemp[u8IndexToRestore].u8StoreExecutedCycle;

      /* Remember the index for next recording */
      scm_u8IndexCurrentSystemContext = (u8IndexToRestore + KU8_ONE) % SCM_KU8_MAX_SYSTEM_CONTEXT_SUBBLOCKS;

      /* reserve the size for the immediate data storage block */
      switch(u8IndexToRestore)
      {
         case KU8_ZERO : u16BlockNumberToReallocate = NVM_BLOCK_ID_SYSTEM_CONTEXT_1;
         break;

         case KU8_ONE : u16BlockNumberToReallocate = NVM_BLOCK_ID_SYSTEM_CONTEXT_2;
         break;

         /* Case KU8_TWO or other */
         default: u16BlockNumberToReallocate = NVM_BLOCK_ID_SYSTEM_CONTEXT_0;
         break;
      }

   }
   else
   {
      /* No context to restore ; set the first position to be used during first recording */
      scm_u8IndexCurrentSystemContext = KU8_ZERO;

      /* No deficiency level to restore */
      SCM_stCurrentSystemContextContent.u32StoreDeficiencyLevel = KU32_ZERO;

      /* No system Time to restore */
      SCM_stCurrentSystemContextContent.u32StoreSystemTime = KU32_ZERO;

      /* No executed cycle to restore */
      SCM_stCurrentSystemContextContent.u8StoreExecutedCycle = KU8_NO_CYCLE;

      /* Set battery loss status to no battery loss */
      SCM_stCurrentSystemContextContent.b8StoreKL30Lost = KU8_FALSE;

      /* Set eCPL activation status to not activated */
      SCM_stCurrentSystemContextContent.u8CPLstatus = KU8_FALSE;
   }


   /* get reset cause from RCM module */
   (void)Rte_Call_pclResetCause_GetResetCause(&u32ResetCause);

   /* If a warm reset occurred and the last interrupted cycle in RAM No Init value is consistent => restore the value from RAM No Init */
   /* It is ok because after the NOT operation the result is converted back from int to uint8 */
   if((KU32_RESET_CAUSE_UNKNOWN == u32ResetCause) &&   (SCM_u8LastInterruptedCycleNumber_Mirror == (UInt8)(~SCM_u8LastInterruptedCycleNumber) ) )
   {
      SCM_stCurrentSystemContextContent.u8StoreExecutedCycle = SCM_u8LastInterruptedCycleNumber;
   }
   else if ( (KU32_ZERO !=(u32ResetCause & (KU32_CRYSTAL_FAILURE_MASK
                                          | KU32_PLL_FAILURE_MASK
                                          | KU32_INTERNAL_WDG_MASK
                                          | KU32_SW_INTERNAL_WDG_MASK
										  | KU32_EXTERNAL_WDG_MASK
                                          | KU32_ECC_RAM_MASK
                                          | KU32_ECC_PFLASH_MASK
                                          | KU32_OS_EXCEPTION_MASK
                                          | KU32_INVALID_INTERRUPT_MASK
                                          | KU32_ECC_UNIDENTIFIED_MASK
                                          | KU32_SW_RESET_MASK
                                          | KU32_BTLD_RESET_MASK)))
      &&   (SCM_u8LastInterruptedCycleNumber_Mirror == (UInt8)(~SCM_u8LastInterruptedCycleNumber))
     )
   {
      SCM_stCurrentSystemContextContent.u8StoreExecutedCycle = SCM_u8LastInterruptedCycleNumber;
   }
   else
   {
      /* Do nothing : keep the value previously restored from system context */
   }

   /* Initialization of SW deficiency level */
   (void)Rte_Call_pclMotor_T_InitializeDeficiencyLevel(SCM_stCurrentSystemContextContent.u32StoreDeficiencyLevel);

   /* Indicate to application the last executed cycle number */
   (void)Rte_IrvWrite_SCM_runRestoreSystemContext_u8LastTensioningSituation(SCM_stCurrentSystemContextContent.u8StoreExecutedCycle);

   /* Restore RAM no init variable */
   SCM_u8LastInterruptedCycleNumber = SCM_stCurrentSystemContextContent.u8StoreExecutedCycle;
   /* Fill in the Mirror variable */
   SCM_u8LastInterruptedCycleNumber_Mirror = (uint8)(~(uint32)SCM_u8LastInterruptedCycleNumber);

   /* Check if a release shall be programmed */
   if(KU8_NO_CYCLE != SCM_stCurrentSystemContextContent.u8StoreExecutedCycle)
   {
      SCM_b8ReleaseHasToBeTriggered = B_TRUE;
   }

   /* Initialize the threshold to detect a battery loss */
   scm_u16BatteryHysteresisThrs = CALIB_BLOCK_ID_BATTERY_LOSS_DETECTION_THRS_RomBlockData.NVP_ku16KL30LossDetectionThr;
}
/**
 * \brief
 *     This function is called to manage the system context write operation
 * \param
 *     None.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
EXPORTED void SCM_StoreSystemContext(void)
{
   uint8 u8RequestStatus;
   uint8 u8ReqSynchronousRes;

   /* if KL30 is lost -> cancel all current write operations to be sure to store system context */
   if(B_TRUE == SCM_stCurrentSystemContextContent.b8StoreKL30Lost)
   {
      /* Cancel current executed Fee job */
      Fee_Cancel();
   }

   if(KU8_ZERO == scm_u8IndexCurrentSystemContext)
   {
      u8RequestStatus = Rte_Call_NvMService_SYSTEM_CONTEXT_0_WriteBlock(&SCM_stCurrentSystemContextContent);
   }
   else if(KU8_ONE == scm_u8IndexCurrentSystemContext)
   {
      u8RequestStatus = Rte_Call_NvMService_SYSTEM_CONTEXT_1_WriteBlock(&SCM_stCurrentSystemContextContent);
   }
   else if(KU8_TWO == scm_u8IndexCurrentSystemContext)
   {
      u8RequestStatus = Rte_Call_NvMService_SYSTEM_CONTEXT_2_WriteBlock(&SCM_stCurrentSystemContextContent);
   }
   else
   {
      /* Nothing to do, wrong ID */
      u8RequestStatus = E_NOT_OK;
   }

   if ( E_OK == u8RequestStatus )
   {
       switch (scm_u8IndexCurrentSystemContext) {
       case KU8_ZERO:
           (void)Rte_Call_NvMService_SYSTEM_CONTEXT_0_GetErrorStatus( &u8ReqSynchronousRes);
           break;
       case KU8_ONE:
           (void)Rte_Call_NvMService_SYSTEM_CONTEXT_1_GetErrorStatus( &u8ReqSynchronousRes);
           break;
       case KU8_TWO:
           (void)Rte_Call_NvMService_SYSTEM_CONTEXT_2_GetErrorStatus( &u8ReqSynchronousRes);
           break;

       default:
           break;
       }

      while( NVM_REQ_PENDING == u8ReqSynchronousRes )
      {
         NvM_MainFunction();

         while(MEMIF_IDLE != Fee_GetStatus())
         {
            Fee_MainFunction();
            Fls_17_Dmu_MainFunction();
         }

         /* Check if job is pending or finished */
         switch (scm_u8IndexCurrentSystemContext) {
         case KU8_ZERO:
             (void)Rte_Call_NvMService_SYSTEM_CONTEXT_0_GetErrorStatus( &u8ReqSynchronousRes);
             break;
         case KU8_ONE:
             (void)Rte_Call_NvMService_SYSTEM_CONTEXT_1_GetErrorStatus( &u8ReqSynchronousRes);
             break;
         case KU8_TWO:
             (void)Rte_Call_NvMService_SYSTEM_CONTEXT_2_GetErrorStatus( &u8ReqSynchronousRes);
             break;

         default:
             break;
         }
      }
   }

   /* Set index for next recording */
   scm_u8IndexCurrentSystemContext = (scm_u8IndexCurrentSystemContext + KU8_ONE) % SCM_KU8_MAX_SYSTEM_CONTEXT_SUBBLOCKS;
}
/**
 * \brief
 *     This function is called to compute system context checksum
 * \param
 *     pstSystemContext - Pointer to the structure containing the data for which we need to
            compute a checksum.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     u8ChkSum - hecksum value for the system context structure passed as argument.
 **/
EXPORTED uint8 SCM_ComputeSystemContextChecksum (const SCM_stSystemContextType * const pstSystemContext)
{
   /* Pointer to the system context structure */
   const uint8 * const pu8Index = (const uint8 *)pstSystemContext;

   uint8 u8Index;
   uint8 u8ChkSum = KU8_ZERO;

   if (KPU8_NULL != pu8Index)
   {
      /* compute system context checksum */
      for( u8Index = KU8_ZERO;  u8Index < (SCM_KU8_SYSTEM_CONTEXT_SIZE - KU8_ONE) ; u8Index++ )
      {
         u8ChkSum += * (pu8Index + u8Index);
      }
   }

   return (u8ChkSum);
}
/**
 * \brief
 *     Function call under ADC interrupt context to check the battery loss hysteresis
 * \param
 *     u16KL30bgAdcLevel - Logic Supply level directly read from ADC peripheral without rescaling.
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
EXPORTED void SCM_runKL30bgSupervision ( u16SampledSignalType u16KL30bgLevel )
{
   uint16 u16LocalAdcSample;

   /* Copy input argument in local data */
   u16LocalAdcSample = (uint16)u16KL30bgLevel;

   /* ADC sample shall be Right aligned before any other operations */
   u16LocalAdcSample = (uint16)((uint32)((uint32)u16LocalAdcSample * SCM_KU32_KL30_MUL_FACTOR) / SCM_KU32_KL30_DIV_FACTOR);

   if ( ( scm_u16BatteryHysteresisThrs  > u16LocalAdcSample            ) &&
        ( CALIB_BLOCK_ID_BATTERY_LOSS_DETECTION_THRS_RomBlockData.NVP_ku16KL30LossDetectionThr == scm_u16BatteryHysteresisThrs )
       )
   {
      /* Set event to store system context */
      SCM_bIsSystemContextStorageRequested = KU8_TRUE;

      /* Change the thrs value to detect battery recovery */
      scm_u16BatteryHysteresisThrs = CALIB_BLOCK_ID_BATTERY_LOSS_DETECTION_THRS_RomBlockData.NVP_ku16KL30EndLossDetectionThr;
   }
   else if ( ( scm_u16BatteryHysteresisThrs     < u16LocalAdcSample            )  &&
             ( CALIB_BLOCK_ID_BATTERY_LOSS_DETECTION_THRS_RomBlockData.NVP_ku16KL30EndLossDetectionThr == scm_u16BatteryHysteresisThrs )
           )
   {
      /* Change the thrs value to detect a next battery loss */
      scm_u16BatteryHysteresisThrs = CALIB_BLOCK_ID_BATTERY_LOSS_DETECTION_THRS_RomBlockData.NVP_ku16KL30LossDetectionThr;
   }
   else
   {
      /* Do nothing : we are under the Hysteresis "grey" area */
   }

}
/**
 * \brief
 *     Function called to compare the the current systeme context index with the context index declared into a WMBA frame
 * \param
 *     IndexWriteBlock - Index of system contexty block given into the frame
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     bCompareResult - True if it is the same index
 *                       False if it is not the case
 **/
EXPORTED boolean SCM_CompareSystemContext(uint8 IndexWriteBlock)
{
   boolean bCompareResult;
   bCompareResult = FALSE;

   if (IndexWriteBlock == scm_u8IndexCurrentSystemContext)
   {
      bCompareResult = TRUE;
   }

   return bCompareResult;
}
#define SCM_AC_SystemContextManagement_STOP_SEC_CODE
#include "SCM_AC_SystemContextManagement_MemMap.h"

/******************************************************************************
End Of File
*****************************************************************************/

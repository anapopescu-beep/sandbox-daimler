
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
$Revision: 1.11.1.10 $
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
#include "EOL.h"
#include "EOL_private.h"

#include "common.h"
#include "Nvp_Generated.h"
#include "Rte_EOL_AC_EndOfLifeManagement.h"
#include "Rte_Type.h"
#include "vstdlib.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/
/* Define used to limit the number of cycles monitored by the EOL module. 
	It is used to exclude release and production cycles from monitoring */
/**
 * \brief
 * 		Number monitored cycles
 *    MAX VALUE = 31
 */
#define KU8_NB_MONITORED_CYCLES		 (uint8)31
/**
 * \brief
 * 		Variable counter low id
 */
#define KU8_VARIABLE_COUNTER_LOW	    (uint8)1
/**
 * \brief
 * 		Variable counter low id
 */
#define KU8_VARIABLE_COUNTER_HIGH    (uint8)2
/**
 * \brief
 * 		Variable counter low id
 */
#define KU8_VARIABLE_COUNTER_MAX     (uint8)4
/**
 * \brief
 * 		Variable counter low id
 */
#define KU8_VARIABLE_COUNTER_COMFORT (uint8)8

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
#define EOL_AC_EndOfLifeManagement_START_SEC_CODE
#include "EOL_AC_EndOfLifeManagement_MemMap.h"

LOCAL void  eol_ManageCycleCounters(void);
LOCAL uint8 eol_GetCounterIndex(const uint8 u8ExecutedCycleNumber);

/**
 * \brief
 *		Defined macro from C file.
 */
#define EOL_AC_EndOfLifeManagement_STOP_SEC_CODE
#include "EOL_AC_EndOfLifeManagement_MemMap.h"
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
/**
 * @ingroup TEMPLATE_FILES_Group_Example
 * \brief
 *		Store the old value of the executed cycle number
 * \remarks
 *		None
 */
LOCAL u8CycleNumberType eol_u8OldExecutedCycleNumber = KU8_NO_CYCLE;
LOCAL Impl_Obsolescense_Data eol_stObsolescenseData = {0};

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
#define EOL_AC_EndOfLifeManagement_START_SEC_CODE
#include "EOL_AC_EndOfLifeManagement_MemMap.h"

/**
* \brief
*     Computes obsolescense data values
* \param
*     None
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
LOCAL void eol_CalculateObsolescenseData(void)
{
   /*Check to calculate BSR for Obsolescense Data*/
   if (CALIB_BLOCK_ID_EOL_PARAM_RomBlockData.NVP_u32ComfortCyclesEOLThrs < NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_COMFORT_LEVEL])
   {
      eol_stObsolescenseData.BSR.Current_Value = KU8_ZERO;
   }
   else
   {
      eol_stObsolescenseData.BSR.Current_Value = (uint16) (CALIB_BLOCK_ID_EOL_PARAM_RomBlockData.NVP_u32ComfortCyclesEOLThrs - NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_COMFORT_LEVEL]);
   }

   /*Check to calculate hapting warning (low force) for Obsolescense Data*/
   if (CALIB_BLOCK_ID_EOL_PARAM_RomBlockData.NVP_u32LowForceEOLThrs < NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_LOW_FORCE_LEVEL])
   {
      eol_stObsolescenseData.Haptic_Warning.Current_Value = KU8_ZERO;
   }
   else
   {
      eol_stObsolescenseData.Haptic_Warning.Current_Value = (uint16) (CALIB_BLOCK_ID_EOL_PARAM_RomBlockData.NVP_u32LowForceEOLThrs - NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_LOW_FORCE_LEVEL]);
   }

   /*Check to calculate PreSafe LVL 4-5 (high force) for Obsolescense Data*/
   if (CALIB_BLOCK_ID_EOL_PARAM_RomBlockData.NVP_u32HighForceEOLThrs < NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_HIGH_FORCE_LEVEL])
   {
      eol_stObsolescenseData.PRE_SAFE_LVL_4_5.Current_Value = KU8_ZERO;
   }
   else
   {
      eol_stObsolescenseData.PRE_SAFE_LVL_4_5.Current_Value = (uint16) (CALIB_BLOCK_ID_EOL_PARAM_RomBlockData.NVP_u32HighForceEOLThrs - NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_HIGH_FORCE_LEVEL]);
   }

   /*Check to calculate pre_crash (max force) for Obsolescense Data*/
   if (CALIB_BLOCK_ID_EOL_PARAM_RomBlockData.NVP_u32MaxForceEOLThrs < NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_MAX_FORCE_LEVEL])
   {
      eol_stObsolescenseData.PRE_CRASH.Current_Value = KU8_ZERO;
   }
   else
   {
      eol_stObsolescenseData.PRE_CRASH.Current_Value = (uint16) (CALIB_BLOCK_ID_EOL_PARAM_RomBlockData.NVP_u32MaxForceEOLThrs - NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_MAX_FORCE_LEVEL]);
   }
}

/**
* \brief
*     Computes cycles counters
* \param
*     None
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
/* [COVERS: DSG_EOL_0017] */
LOCAL void eol_ManageCycleCounters(void)
{
   u8CycleNumberType u8ExecutedCycleNumber;
   uint8 u8Index;
   uint8 u8CILTriggerRequest = KU8_MAX;
   uint8 u8PreSafeLvl = I_C04_PRESF_LVL_V2_NOLVL;
   static uint8 u8OldPreSafeLvl = I_C04_PRESF_LVL_V2_NOLVL;
   /* Read executed cycle index */
   /* [COVERS: DSG_EOL_0004] */
   (void) Rte_Read_prrExecutedCycle_u8CycleNumber(&u8ExecutedCycleNumber);
   /* [COVERS: DSG_EOL_0013] */
   (void) Rte_Read_prrCustomerSpecific_u8TriggerRequest(&u8CILTriggerRequest);
   /* [COVERS: DSG_EOL_0014] */
   (void) Rte_Read_prrPreSafeLvl_u8PreSafeLvl(&u8PreSafeLvl);

   /* Check if a request on PRE-SAFE is active */
   /* [COVERS: DSG_EOL_0012] */
   if ((KU8_TWO == u8CILTriggerRequest) && (u8OldPreSafeLvl != u8PreSafeLvl))
   {
      if(u8PreSafeLvl != I_C04_PRESF_LVL_V2_NOLVL)
      {
         /* Check data overflow */
         if (KU32_MAX > NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_REQUEST_COUNTER_LEVEL])
         {
            /* Increase counter value */
           NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_REQUEST_COUNTER_LEVEL]++;
           /* [COVERS: DSG_EOL_0015] */
           (void)Rte_Write_pseExecutionCounterBlockStatus_b8NVMBlockStatus(KU8_TRUE);
         }
         else
         {
            /* Do nothing due to data overflow */
         }
      }
      
   }


   /* Check executed cycle identifier is valid */
   if (KU8_NB_MONITORED_CYCLES > u8ExecutedCycleNumber)
   {
      /* Get level from executed cycle */
      u8Index = eol_GetCounterIndex(u8ExecutedCycleNumber);

      /* Check if a cycle has been started */
      if (    (u8ExecutedCycleNumber  != eol_u8OldExecutedCycleNumber)
           && (KU8_MAX != u8Index)
         )
      {
         switch (u8Index)
         {
         /* [COVERS: DSG_EOL_0003, DSG_EOL_0009] */
         case KU8_EOL_COMFORT_LEVEL:
            /* Check data overflow */
            if (KU32_MAX > NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_COMFORT_LEVEL])
            {
               /* Increase counter value */
               NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_COMFORT_LEVEL]++;
               /* [COVERS: DSG_EOL_0015] */
               (void)Rte_Write_pseExecutionCounterBlockStatus_b8NVMBlockStatus(KU8_TRUE);
               /* [COVERS: DSG_EOL_0016] */
               (void)Rte_Write_EOL_AC_EndOfLifeManagement_ObsolescenceDataBlockNumber_BlockNumber(u8Index);
            }
            else
            {
               /* Do nothing due to data overflow */
            }

            break;
         /* [COVERS: DSG_EOL_0011] */
         case KU8_EOL_MAX_FORCE_LEVEL:
            /* Check data overflow */
            if (KU32_MAX > NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_MAX_FORCE_LEVEL])
            {
               /* Increase counter value */
               NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_MAX_FORCE_LEVEL]++;
               /* [COVERS: DSG_EOL_0015] */
               (void)Rte_Write_pseExecutionCounterBlockStatus_b8NVMBlockStatus(KU8_TRUE);
               /* [COVERS: DSG_EOL_0016] */
               (void)Rte_Write_EOL_AC_EndOfLifeManagement_ObsolescenceDataBlockNumber_BlockNumber(u8Index);
            }
            else
            {
               /* Do nothing due to data overflow */
            }

            break;
         /* [COVERS: DSG_EOL_0002, DSG_EOL_0005] */
         case KU8_EOL_HIGH_FORCE_LEVEL:
            /* Check data overflow */
            if (KU32_MAX > NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_HIGH_FORCE_LEVEL])
            {
               /* Increase counter value */
               NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_HIGH_FORCE_LEVEL]++;
               /* [COVERS: DSG_EOL_0015] */
               (void)Rte_Write_pseExecutionCounterBlockStatus_b8NVMBlockStatus(KU8_TRUE);
               /* [COVERS: DSG_EOL_0016] */
               (void)Rte_Write_EOL_AC_EndOfLifeManagement_ObsolescenceDataBlockNumber_BlockNumber(u8Index);
            }
            else
            {
               /* Do nothing due to data overflow */
            }


         /* High force should increment low force too*/
         /* [COVERS: DSG_EOL_0001] */
         case KU8_EOL_LOW_FORCE_LEVEL:
            /* Check data overflow */
            if (KU32_MAX > NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_LOW_FORCE_LEVEL])
            {
               /* Increase counter value */
               NVP_BLOCK_ID_EXECUTION_COUNTERS_RamBlockData.NVP_au32ExecutedCycleCounters[KU8_EOL_LOW_FORCE_LEVEL]++;
               /* [COVERS: DSG_EOL_0015] */
               (void)Rte_Write_pseExecutionCounterBlockStatus_b8NVMBlockStatus(KU8_TRUE);
               /* [COVERS: DSG_EOL_0016] */
               (void)Rte_Write_EOL_AC_EndOfLifeManagement_ObsolescenceDataBlockNumber_BlockNumber(u8Index);
            }
            else
            {
               /* Do nothing due to data overflow */
            }

            break;
         default:
            break;
         }

      }
      else
      {
         /* Do nothing due to same cycle */
      }
   }
   else
   {
      /* Do nothing due to cycle index invalid */
   }
   /* Remember current executed cycle number for next check */
   eol_u8OldExecutedCycleNumber = u8ExecutedCycleNumber;
   u8OldPreSafeLvl = u8PreSafeLvl;
}

/**
* \brief
*     Checks if a cyle has variable counter 
* \param
*     uint8 - executed cycle number
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     uint8 - value of the variable counter or 0xFF if no counter is configured
**/
LOCAL uint8 eol_GetVariableCounterValue(const uint8 u8ExecutedCycleNumber)
{
   uint8 u8NVPValue = KU8_ZERO;

   switch(u8ExecutedCycleNumber)
   {
      case KU8_PRECRASH_SEVERITY_LEVEL_8:
         u8NVPValue = (uint8)(NVP_BLOCK_ID_EOL_MAPPING_MB_RamBlockData.NVP_uAssociatedCounter[KU8_THREE] & KU8_FIFTEEN);
      break;

      case KU8_PRECRASH_SEVERITY_LEVEL_9:
         u8NVPValue = (uint8)(NVP_BLOCK_ID_EOL_MAPPING_MB_RamBlockData.NVP_uAssociatedCounter[KU8_THREE] >> KU8_FOUR);
      break;

      case KU8_PRECRASH_SEVERITY_LEVEL_10:
         u8NVPValue = (uint8)(NVP_BLOCK_ID_EOL_MAPPING_MB_RamBlockData.NVP_uAssociatedCounter[KU8_TWO] & KU8_FIFTEEN);
      break;

      case KU8_PRECRASH_SEVERITY_LEVEL_11:
         u8NVPValue = (uint8)(NVP_BLOCK_ID_EOL_MAPPING_MB_RamBlockData.NVP_uAssociatedCounter[KU8_TWO] >> KU8_FOUR);
      break;

      case KU8_PRECRASH_SEVERITY_LEVEL_12:
         u8NVPValue = (uint8)(NVP_BLOCK_ID_EOL_MAPPING_MB_RamBlockData.NVP_uAssociatedCounter[KU8_ONE] & KU8_FIFTEEN);
      break;

      case KU8_PRECRASH_SEVERITY_LEVEL_13:
         u8NVPValue = (uint8)(NVP_BLOCK_ID_EOL_MAPPING_MB_RamBlockData.NVP_uAssociatedCounter[KU8_ONE] >> KU8_FOUR);
      break;

      case KU8_PRECRASH_SEVERITY_LEVEL_14:
         u8NVPValue = (uint8)(NVP_BLOCK_ID_EOL_MAPPING_MB_RamBlockData.NVP_uAssociatedCounter[KU8_ZERO] & KU8_FIFTEEN);
      break;

      default:
         u8NVPValue = KU8_ZERO;
      break;
   }

   return u8NVPValue;
}

/**
* \brief
*     Defines the cycle counter
* \param
*     uint8 - executed cycle number
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     uint8 - counter index
**/
LOCAL uint8 eol_GetCounterIndex(const uint8 u8ExecutedCycleNumber)
{
   uint8 u8CounterIndex;
   const uint8 u8VariableCounterStatus = eol_GetVariableCounterValue(u8ExecutedCycleNumber);

   /* Index calculation for map comparison */
   const uint32 u32Index = (KU32_ONE << u8ExecutedCycleNumber);

   /* Check if executed cycle is a comfort cycle managed by EOL */
   if ((u32Index & CALIB_BLOCK_ID_EOL_PARAM_RomBlockData.NVP_u32EOLComfortCyclesMAP) == u32Index)
   {
      u8CounterIndex = KU8_EOL_COMFORT_LEVEL;
   }
   /* Check if executed cycle is a max cycle managed by EOL */
   else if ((u32Index & CALIB_BLOCK_ID_EOL_PARAM_RomBlockData.NVP_u32EOLMaxForceCyclesMAP) == u32Index)
   {
      u8CounterIndex = KU8_EOL_MAX_FORCE_LEVEL;
   }
   /* Check if executed cycle is a high cycle managed by EOL */
   else if ((u32Index & CALIB_BLOCK_ID_EOL_PARAM_RomBlockData.NVP_u32EOLHighForceCyclesMAP) == u32Index)
   {
      u8CounterIndex = KU8_EOL_HIGH_FORCE_LEVEL;
   }
   /* Check if executed cycle is a low power cycle managed by EOL */
   else if ((u32Index & CALIB_BLOCK_ID_EOL_PARAM_RomBlockData.NVP_u32EOLLowForceCyclesMAP) == u32Index)
   {
      u8CounterIndex = KU8_EOL_LOW_FORCE_LEVEL;
   }
   /* [COVERS: DSG_EOL_0017] */
   else if((u8ExecutedCycleNumber >= KU8_PRECRASH_SEVERITY_LEVEL_8) && (u8ExecutedCycleNumber <= KU8_PRECRASH_SEVERITY_LEVEL_14))
   {
      switch(u8VariableCounterStatus)
      {
         /* [COVERS: DSG_EOL_0018] */
         case KU8_VARIABLE_COUNTER_LOW:
            u8CounterIndex = KU8_EOL_LOW_FORCE_LEVEL;
         break;
         /* [COVERS: DSG_EOL_0019] */
         case KU8_VARIABLE_COUNTER_HIGH:
            u8CounterIndex = KU8_EOL_HIGH_FORCE_LEVEL;
         break;
         /* [COVERS: DSG_EOL_0020] */
         case KU8_VARIABLE_COUNTER_MAX:
            u8CounterIndex = KU8_EOL_MAX_FORCE_LEVEL;
         break;
         /* [COVERS: DSG_EOL_0021] */
         case KU8_VARIABLE_COUNTER_COMFORT:
            u8CounterIndex = KU8_EOL_COMFORT_LEVEL;
         break;
         /* [COVERS: DSG_EOL_0022] */
         default:
            u8CounterIndex = KU8_EOL_LOW_FORCE_LEVEL;
         break;
      }
   }
   else 
   {
      /* Cycle not managed by EOL */
      u8CounterIndex = KU8_MAX;
   }

   /* Return function level */
   return u8CounterIndex;
}

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/

/**
* \brief
*     EOL main function
* \param
*     None
* \exception
*     None
* \pre
*     None
* \post
*     None
* \return
*     None
**/
void EOL_runMainFunction(void)
{
   eol_ManageCycleCounters();
   eol_CalculateObsolescenseData();
}

FUNC(void, EOL_AC_EndOfLifeManagement_CODE) EOL_Get_Obsolescence_Data(P2CONST(Impl_Obsolescense_Data, AUTOMATIC, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_DATA) pObsData)
{
   VStdMemCpy(pObsData, &eol_stObsolescenseData, sizeof (eol_stObsolescenseData));
}

FUNC(void, EOL_AC_EndOfLifeManagement_CODE) EOL_Write_Obsolescence_Data(P2VAR(Impl_Obsolescense_Data, AUTOMATIC, RTE_EOL_AC_ENDOFLIFEMANAGEMENT_APPL_VAR) pObsData)
{

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


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
$Revision: 1.2.1.23 $
$ProjectName: e:/MKSProjects/SBE/PP/DAIMLER_MMA/Phase_02/View_Development/Components/Application/Autoliv/ERH/Quality_Assurance/Static_Analysis/project.pj $
 */
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
#include "Rte_ERH_AC_ErrorHandler.h"
#include "Config.h"

#include "ERH_private.h"
#include "ERH_public.h"

#include "Nvp_Generated.h"

#include "ERH_cfg_public.h"
#include "Dem.h"

#pragma optimize 0
/******************************************************************************
MODULE DEFINES
 ******************************************************************************/
/**
 * \brief
 *      Maximum number of pending events allowed
 */
#define KU8_MAX_PENDING_EVENT                    ((uint8)8)
/**
 * \brief
 *      Size array with the number of AEC groups
 */
#define KU8_NUMBER_OF_GROUPS                     ((uint8)30)
/**
 * \brief
 *      The NVP Recording OK value of "Ever qualified" AEC informations
 */
#define KU8_NVP_AEC_RECORDING_OK                 ((uint8)0)
/**
 * \brief
 *      The NVP Recording “Not OK” value of "Ever qualified" AEC informations
 */
#define KU8_NVP_AEC_RECORDING_NOK                ((uint8)0xFF)
/**
 * \brief
 *      The NVP Recording “In Progress” value of "Ever qualified" AEC informations
 */
#define KU8_NVP_AEC_RECORDING_IN_PROGRESS        ((uint8)0x55)
/**
 * \brief
 *      Counter tresholf for Ignition cycle
 */
#define KU16_COUNTER_TRESHOLD_IGN                  ((uint16)1000)
/**
 * \brief
 * 		Macro used for bit clearing inhibition status
 */
#define ERH_SET_STORAGE_CONDITION_MASK_OFF(mask)           U16_BIT_CLEAR(ERH_u16StorageConditionStatus, (mask))
/**
 * \brief
 * 		Macro used for bit setting inhibition status
 */
#define ERH_SET_STORAGE_CONDITION_MASK_ON(mask)            U16_BIT_SET(ERH_u16StorageConditionStatus, (mask))
/**
 * \brief
 *
 */
#define KU16_ERH_SC1_ControlDTC            (1u)
/**
 * \brief
 *
 */
#define KU16_ERH_SC2_IgnitonStatus         (2u)
/**
 * \brief
 *
 */
#define KU16_ERH_SC3_LocalVoltage          (4u)
/**
 * \brief
 *
 */
#define KU16_ERH_SC4_SystemVoltage         (8u)
/**
 * \brief
 *
 */
#define KU16_ERH_SC5_TransportationMode    (16u)
/**
 * \brief
 *
 */
#define KU16_ERH_SC8_CommunicationStatus   (32u)
/**
 * \brief
 *
 */
#define KU16_ERH_SC10_0_debounceTimer        (64u)
/**
 * \brief
 *
 */
#define KU16_ERH_SC10_1_debounceTimer        (128u)
/**
 * \brief
 *
 */
#define KU16_ERH_SC10_2_debounceTimer        (256u)
/**
 * \brief
 *
 */
#define KU16_ERH_SC11_VehicleStartup       (512u)
/**
 * \brief
 *
 */
#define KU16_ERH_SC12_ProductionMode          (1024u)

/**
 * \brief
 *
 */
#define KU16_ERH_MASK_DEBOUNCE_TIMER_NC      ((uint16) 0x63B)
/**
 * \brief
 *
 */
#define KU16_ERH_MASK_DEBOUNCE_TIMER_NC15      ((uint16) 0x639)
/**
 * \brief
 *
 */
#define KU16_ERH_MASK_DEBOUNCE_TIMER_PD      ((uint16) 0x633)
/**
 * \brief
 *
 */
#define KU16_ERH_TIMER_TRESHOLD              (500u)
/**
 * \brief
 *
 */
#define BOOL_ERH_SET_STORAGE_CONDITION       (1u)
/**
 * \brief
 *
 */
#define BOOL_ERH_CLEAR_STORAGE_CONDITION     (0u)
/**
 * \brief
 *
 */
#define KU16_ERH_MASK_CONTROL_DTC            (1u)
/**
 * \brief
 *
 */
#define KU16_ERH_MASK_ECU_LEVEL              (517u)
/**
 * \brief
 *
 */
#define KU16_ERH_MASK_POWER_DISTRIBUTION     ((uint16)0x673)
/**
 * \brief
 *
 */
#define KU16_ERH_MASK_NETWORK_COM           ((uint16)0x6BB)
/**
 * \brief
 *
 */
#define KU16_ERH_MASK_NETWORK_COM15         ((uint16)0x739)

#define KU16_ERH_MASK_DTC_CONFIRMED         ((uint16)0x008)
/******************************************************************************
MODULE TYPES
 ******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
 ******************************************************************************/
#define ERH_AC_ErrorHandler_START_SEC_CODE
#include "ERH_AC_ErrorHandler_MemMap.h"

LOCAL boolean erh_CheckAecId(const uint8 cu8AecId, uint8 *const cpu8Index, erh_stAECConfigurationType * const cpstAecData);
LOCAL void erh_ManageFailedCounterEvent(const uint8 cu8Index, const erh_stAECConfigurationType * const cpstAecData);
LOCAL void erh_ManagePassedCounterEvent(const uint8 cu8Index, const erh_stAECConfigurationType * const cpstAecData);
LOCAL void erh_ManageAECCommand(const u8AecCommandType cu8Command, const uint8 cu8Index, const erh_stAECConfigurationType * const cpstAecData);
LOCAL void erh_UpdateGroup(const uint8 cu8AecId, const erh_stAECConfigurationType * const cpstAecData);

#define ERH_AC_ErrorHandler_STOP_SEC_CODE
#include "ERH_AC_ErrorHandler_MemMap.h"
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
 ******************************************************************************/
#define ERH_AC_ErrorHandler_START_SEC_VAR_16
#include "ERH_AC_ErrorHandler_MemMap.h"
/*QAC_WARNING S 2022 ++ */ /* A tentative definition is being used. Is it appropriate to include an explicit initializer */
                    /* All of these variables are initialized during Init function and will not be accessed until
                     * the init function execution */

/**
 * \brief
 *    Array of current debouncing counters for AEC’s
 * \remarks
 *    None.
 */
LOCAL uint16 erh_au16AecCounter[ERH_KU8_NUMBER_OF_AEC];

/* Bit field of AEC group qualification (bit = 1 if at least one AEC from group is currently qualified) */
/**
 * \brief
 *    Status of AEC groups
 * \remarks
 *    None.
 */
 static uint32 erh_u32GroupsStatus;

/* Bit field of AEC group qualification (bit = 1 if at least one AEC from group is currently qualified) */
/**
 * \brief
 *    Array of counters for AEC group
 * \remarks
 *    None.
 */
LOCAL uint32 erh_au32GroupCounter[KU8_NUMBER_OF_GROUPS];
/**
 * \brief
 *    Counter for debounce befor start of Ign cycle
 * \remarks
 *    None.
 */
LOCAL uint16 erh_u16DebounceCounter = KU16_ZERO;
#define ERH_AC_ErrorHandler_STOP_SEC_VAR_16
#include "ERH_AC_ErrorHandler_MemMap.h"

#define ERH_AC_ErrorHandler_START_SEC_VAR_8
#include "ERH_AC_ErrorHandler_MemMap.h"
/* For each AEC, stores the AEC status. */
/**
 * \brief
 *    Array of counters for AEC group
 * \remarks
 *    None.
 */
LOCAL uint8 erh_au8AecStatus[ERH_KU8_NUMBER_OF_AEC];

/* Storage of pending event, in case of nested ERH_runGetAecStatus services calls */
/**
 * \brief
 *    Index pointing to the free spot of the pending event list
 * \remarks
 *    None.
 */
LOCAL uint8 erh_u8PendingEventAddIndex;
/**
 * \brief
 *    Index pointing to the current item to process in the pending list
 * \remarks
 *    None.
 */
LOCAL uint8 erh_u8PendingEventRunIndex;

/* Storage of pending event, in case of nested ERH_runGetAecStatus services calls.
 * Note: At startup both FIFO below are empty thank to the equality of
 *       erh_u8PendingEventAddIndex and erh_u8PendingEventRunIndex.
 *       The empty FIFO content don't care and arrays are not initialized. */
/**
 * \brief
 *    Array of u8AecCommandType
 * \remarks
 *    None.
 */
LOCAL u8AecCommandType erh_au8PendingEventCommand[KU8_MAX_PENDING_EVENT];
/**
 * \brief
 *    Array of u8AecIdentifierType
 * \remarks
 *    None.
 */
LOCAL u8AecIdentifierType erh_au8PendingEventAecIdentifier[KU8_MAX_PENDING_EVENT];
/**
 * \brief
 *    Result of the AEC status write process
 * \remarks
 *    None.
 */
LOCAL uint8 erh_u8StAECWriteStatusResult;
/**
 * \brief
 *    Variable used to indicate when the condition is met to store data in NVP
 * \remarks
 *    None.
 */
LOCAL boolean erh_bNvmRecordRequested;
/**
 * \brief
 *   The number of qualified AEC in the group
 * \remarks
 *    None.
 */
LOCAL uint8  erh_u8OtherGroupValue;
/**
 * \brief
 *   The Status mask used for Storage Conditions
 * \remarks
 *    None.
 */
LOCAL uint16 ERH_u16StorageConditionStatus;
/**
 * \brief
 *   The Counter of Network Comunication storage Group
 * \remarks
 *    None.
 */
LOCAL uint16 ERH_u16DebounceCounter_NetworkComunication = KU16_ZERO;
/**
 * \brief
 *   The Counter of Power Distribution storage Group
 * \remarks
 *    None.
 */
LOCAL uint16 ERH_u16DebounceCounter_PowerDistribution = KU16_ZERO;
/**
 * \brief
 *   The Counter of Network Comunication 15 storage Group
 * \remarks
 *    None.
 */
LOCAL uint16 ERH_u16DebounceCounter_NetworkComunication15 = KU16_ZERO;


LOCAL uint16 ERH_u16AECsForECULevel_StorageGroup[KU8_FIFTEEN] = {ERH_KU8_ENABLE_OUT_OF_ORDER_AEC_CFG,
																 ERH_KU8_MOSFET_HIGH_SC_AEC_CFG,
																 ERH_KU8_MOSFET_LOW_SC_AEC_CFG,
																 ERH_KU8_MOTOR_DISCONNECTED_AEC_CFG,
																 ERH_KU8_HALL_SENSOR_AEC_CFG,
																 ERH_KU8_TEMPERATURE_SENSOR_FAILURE_AEC_CFG,
																 ERH_KU8_EXT_WDG_OUT_OF_ORDER_AEC_CFG,
																 ERH_KU8_HW_SELF_PROTECTION_AEC_CFG,
																 ERH_KU8_SW_SELF_PROTECTION_AEC_CFG,
																 ERH_KU8_END_OF_LIFE_COMFORT_AEC_CFG,
																 ERH_KU8_END_OF_LIFE_LOW_AEC_CFG,
																 ERH_KU8_END_OF_LIFE_HIGH_AEC_CFG,
																 ERH_KU8_END_OF_LIFE_MAX_FORCE_AEC_CFG,
																 ERH_KU8_STEERING_CONFIG_AEC_CFG,
																 ERH_KU8_VARIANT_CODING_AEC_CFG};

LOCAL uint16 ERH_u16AECsForPowerDistribution_StorageGroup[KU8_SIX] = {ERH_KU8_OVO_POWER_AEC_CFG,
		                                                           ERH_KU8_UVO_POWER_AEC_CFG,
																   ERH_KU8_UVO_TENSIONING_POWER_AEC_CFG,
																   ERH_KU8_OVO_TENSIONING_POWER_AEC_CFG,
																   ERH_KU8_SYSTEM_OV_AEC_CFG,
																   ERH_KU8_SYSTEM_UV_AEC_CFG};

LOCAL uint16 ERH_u16AECsForNetworkCom_StorageGroup[KU8_FIFTEEN] = {ERH_KU8_TIMEOUT_PRESAFE_AEC_CFG,
		                                                        ERH_KU8_TIMEOUT_BUCKLE_AEC_CFG,
																ERH_KU8_IMPLAUSIBLE_DATA_PRESAFE_AEC_CFG,
																ERH_KU8_IMPLAUSIBLE_DATA_IGNITION_AEC_CFG,
																ERH_KU8_IMPLAUSIBLE_DATA_BUCKLE_AEC_CFG,
																ERH_KU8_IMPLAUSIBLE_DATA_ORC_AEC_CFG,
																ERH_KU8_IMPLAUSIBLE_DATA_POWERTRAIN_RDY_AEC_CFG,
																ERH_KU8_IMPLAUSIBLE_DATA_POWERTRAIN_DRV_AEC_CFG,
																ERH_KU8_TIMEOUT_BLTHD_R_AEC_CFG,
																ERH_KU8_TIMEOUT_BLTHD_L_AEC_CFG,
																ERH_KU8_TIMEOUT_POWERTRAIN_AEC_CFG,
																ERH_KU8_TIMEOUT_ODOSPEEDOMETER_AEC_CFG,
																ERH_KU8_IMPLAUSIBLE_DATA_API_AEC_CFG,
																ERH_KU8_TIMEOUT_BELT_ADJ_AEC_CFG,
																ERH_KU8_TIMEOUT_API};

LOCAL uint16 ERH_u16AECsForControlDTC_StorageGroup[KU8_EIGHT] = { ERH_KU8_SPI_ERROR_AEC_CFG,
		                                                         ERH_KU8_HIGH_SIDE_SWITCH_AEC_CFG,
																 ERH_KU8_MOSFET_OC_AEC_CFG,
																 ERH_KU8_WARM_RESET_AEC_CFG,
																 ERH_KU8_MOTOR_CURRENT_AEC_CFG,
																 ERH_KU8_MOTOR_BLOCKED_AEC_CFG,
																 ERH_KU8_MOTOR_ORDER_AEC_CFG,
																 ERH_KU8_MOTOR_IN_SC_AEC_CFG};


LOCAL uint8 ERH_u8Index_ECULevel = KU8_ZERO;

LOCAL uint8 ERH_u8Index_PowerDistribution = KU8_ZERO;

LOCAL uint8 ERH_u8Index_NetworkCom = KU8_ZERO;

LOCAL uint8 ERH_u8Index_NoStorageCondition = KU8_ZERO;

LOCAL boolean bIgnitionCounterTrigger = KU8_FALSE;


#define ERH_AC_ErrorHandler_STOP_SEC_VAR_8
#include "ERH_AC_ErrorHandler_MemMap.h"

/*QAC_WARNING S 2022 -- */

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


#define ERH_AC_ErrorHandler_START_SEC_CONST_UNSPECIFIED
#include "ERH_AC_ErrorHandler_MemMap.h"
/* QAC_WARNING S 0310 5 */  /* Casting to different object pointer type. The content of
                      * NVP_astAECsDefinitions is based on the structure erh_stAECConfigurationType
                      * 2 uint16 and 4 uint8 for 1 AEC*/
/* QAC_WARNING S 3305 2 */ /* The content of the NVP_astAECsDefinitions is aligned on 32bits */
/**
 * \brief
 *    Indirection pointer to access AEC configuration data
 * \remarks
 *    None.
 */
LOCAL const erh_stAECConfigurationType * const erh_cpstAecData = (const erh_stAECConfigurationType *)(&ERH_astAECsDefinitions[KU8_ZERO]);
#define ERH_AC_ErrorHandler_STOP_SEC_CONST_UNSPECIFIED
#include "ERH_AC_ErrorHandler_MemMap.h"


/******************************************************************************
DEFINITION OF LOCAL FUNCTION
 ******************************************************************************/
#define ERH_AC_ErrorHandler_START_SEC_CODE
#include "ERH_AC_ErrorHandler_MemMap.h"

/**
 * \brief
 *     This function shall check the validity of the current AEC identifier.
 * \param
 *     uint8 cu8AecId = The identifier to check
 *     uint8* cpu8Index = The address where to output the index (converted identifier)
 *     stAECConfigurationType* cpstAecData = The corresponding debouncing threshold parameter
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     boolean
 **/
LOCAL boolean erh_CheckAecId(const uint8 cu8AecId, uint8 *const cpu8Index, erh_stAECConfigurationType * const cpstAecData)
{
   boolean bReturn = B_TRUE;
   /* [COVERS: DSG_ERH_00001; DSG_ERH_00002; DSG_ERH_00003; DSG_ERH_00004] */

   /* Test if the identifier corresponds to a valid generic AEC */
   if ((ERH_KU8_UNDEFINED_AEC_CFG < cu8AecId) && (ERH_KU8_NUMBER_OF_AEC >= cu8AecId))
   {
      /* QAC_WARNING S 0506 ++ */ /* Possible dereference of NULL pointer. */
              /* cpu8Index and pu16Limit arguments are not "NULL" tested before use in this LOCAL function,
               * because the callers always use the address of a variable as argument (&var) which
               * can not be NULL. */
      /* Convert the generic AEC identifier into an array index */
      (*cpu8Index) = cu8AecId - KU8_ONE;

      /* Get the AEC data associated to this generic AEC */
      /* QAC_WARNING S 0556 2 */ /* Left operand of assignment must be a modifiable object. */
                          /* The "cpstAecData" is the address of a structure instanciated localy by each caller. */
      (*cpstAecData) = *(erh_cpstAecData + (cu8AecId - KU8_ONE));
   }
   else
   {
      /* Invalid identifier :  *cpu8Index is not updated, and B_FALSE is returned */
      bReturn = B_FALSE;
   }
   /* Return B_TRUE if the identifier is valid, else B_FALSE */

   return (bReturn);
}
/**
 * \brief
 *      This function shall manage the current AEC counter on a failed event and update the AEC status
 * \param
 *     Uint8 cpu8Index: AEC ID related to the failed event
 *     stAECConfigurationType* pstAecData: The corresponding debouncing threshold parameter
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
LOCAL void erh_ManageFailedCounterEvent(const uint8 cu8Index, const erh_stAECConfigurationType * const cpstAecData)
{
   uint16 u16AECQualificationThresold;
   uint16 u16AECDeskillThresold;
   uint8 u8NvmBlockStatus;
   /* [COVERS: DSG_ERH_00005] */
   //switch from big endian to little endian
   u16AECQualificationThresold = ((uint16)((cpstAecData->u16AECQualificationThrs & (uint32)KU16_MASK_BYTE_LOW) << KU8_EIGHT)) + ((cpstAecData->u16AECQualificationThrs & KU16_MASK_BYTE_HIGH) >> KU8_EIGHT);
   u16AECDeskillThresold = ((uint16)((cpstAecData->u16AECDeskillThrs & (uint32)KU16_MASK_BYTE_LOW) << KU8_EIGHT)) + ((cpstAecData->u16AECDeskillThrs & KU16_MASK_BYTE_HIGH) >> KU8_EIGHT);

   /* First check that the AEC qualification is not inhibited */
   if (KU16_ZERO != u16AECQualificationThresold)
   {
      /* Test if AEC is not qualified yet */
      if (KU8_ZERO == (erh_au8AecStatus[cu8Index] & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
      {
         /* AEC qualification threshold */
         if (erh_au16AecCounter[cu8Index] >= (u16AECQualificationThresold - KU16_ONE))
         {
            /* AEC counter has reached the qualification limit:
               AEC is qualified here - Set ERH counter to Deskill value if deskill is allowed */
            /* [COVERS: DSG_ERH_00006] */
            if( KU16_ZERO != u16AECDeskillThresold)
            {
               erh_au16AecCounter[cu8Index] = u16AECDeskillThresold;
            }
            else
            {
               /* AEC cannot be deskilled, add one to the counter (counter equals qualification threshold) */
               /* [COVERS: DSG_ERH_00007] */
               erh_au16AecCounter[cu8Index] += KU16_ONE;
            }

            /* Check if this AEC was not ever qualified. */
            if (KU8_ZERO == (ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK & erh_au8AecStatus[cu8Index]))
            {
               /* This AEC was not qualified before, and "ever qualified" status shall be stored in NVP */
               erh_bNvmRecordRequested = B_TRUE;
            }
            else
            {
               /* This AEC was already ever qualified. Thus no need to memorize again. Do nothing */
            }

            /* Manage the AEC status bitfield:
               - set "ever tested", "ever qualified" and "qualified"
               - clear "in progress" */
            /* [COVERS: DSG_ERH_00008] */
            erh_au8AecStatus[cu8Index] = ERH_KU8_AEC_QUALIFIED_STATUS_MASK
                                       | ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK
                                       | ERH_KU8_AEC_EVER_TESTED_STATUS_MASK
                                       | ERH_KU8_AEC_FAILED_AT_LEAST_ONCE_MASK;

            /* Update the group of the AEC */
            /* [COVERS: DSG_ERH_00009] */
            erh_UpdateGroup(cu8Index, cpstAecData);
         }
         else
         {
            /* Increment the AEC counter by one */
            erh_au16AecCounter[cu8Index] += KU16_ONE;

            /* Manage the AEC status bitfield:
               - set "ever tested", "in progress", and "failed at least once"
               - keep "ever qualified" and "qualified" statuses */
            /* [COVERS: DSG_ERH_00011] */
            erh_au8AecStatus[cu8Index] |= (ERH_KU8_AEC_EVER_TESTED_STATUS_MASK | ERH_KU8_AEC_IN_PROGRESS_STATUS_MASK | ERH_KU8_AEC_FAILED_AT_LEAST_ONCE_MASK);
         }

         /* Store the whole local status (except "ever tested" bit) in NVP structure for record in shutdown */
         /* [COVERS: DSG_ERH_00010] */
         NVP_BLOCK_ID_AEC_STATUS_RamBlockData.NVP_au8AECStatus[cu8Index] = (erh_au8AecStatus[cu8Index] & (uint8)(~(uint32)ERH_KU8_AEC_EVER_TESTED_STATUS_MASK));

         /* QAC_WARNING S 3417 5 */ /* The comma operator has been used outside a 'for' statement. */
         /* QAC_WARNING S 3426 4 */ /* Right hand side of comma expression has no side effect and its value is not used. */
                             /* The following Macro is generated by system desk and can't be changed. */
         /* Notify NVP that AEC status shall be stored in EEPROM during shutdown */
         Rte_Call_pclNvmServicesAecBlock_GetErrorStatus(&u8NvmBlockStatus);

         if (NVM_REQ_PENDING != u8NvmBlockStatus)
         {

            (void)Rte_Call_pclNvmServicesAecBlock_SetRamBlockStatus(TRUE);
         }
         else
         {
            /* QAC */
         }
      }
      else
      {
         /* AEC is still qualified */
         /* Check if the counter can be increased until deskill threshold */
         if(erh_au16AecCounter[cu8Index] < u16AECDeskillThresold)
         {
            /* At least one passed event occurred, increment back the counter */
            erh_au16AecCounter[cu8Index] += KU16_ONE;

            /* Manage the AEC status bitfield:
               - set "ever tested", "ever qualified" and "qualified"
               - clear "in progress" */
            erh_au8AecStatus[cu8Index] = ERH_KU8_AEC_QUALIFIED_STATUS_MASK
                                         | ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK
                                         | ERH_KU8_AEC_EVER_TESTED_STATUS_MASK
                                         | ERH_KU8_AEC_FAILED_AT_LEAST_ONCE_MASK;

            /* Store the whole local status (except "ever tested" bit) in NVP structure for record in shutdown */
            NVP_BLOCK_ID_AEC_STATUS_RamBlockData.NVP_au8AECStatus[cu8Index] = (erh_au8AecStatus[cu8Index] & (uint8)(~(uint32)ERH_KU8_AEC_EVER_TESTED_STATUS_MASK));

            /* QAC_WARNING S 3417 5 */ /* The comma operator has been used outside a 'for' statement. */
            /* QAC_WARNING S 3426 4 */ /* Right hand side of comma expression has no side effect and its value is not used. */
                                /* The following Macro is generated by system desk and can't be changed. */
            /* Notify NVP that AEC status shall be stored in EEPROM during shutdown */
            Rte_Call_pclNvmServicesAecBlock_GetErrorStatus(&u8NvmBlockStatus);

            if (NVM_REQ_PENDING != u8NvmBlockStatus)
            {

               (void)Rte_Call_pclNvmServicesAecBlock_SetRamBlockStatus(TRUE);
            }
            else
            {
               /* QAC */
            }
         }
         else
         {
            /*  deskill threshold reached: set "ever tested"  and "failed at least once" bits */
            erh_au8AecStatus[cu8Index] |= (ERH_KU8_AEC_EVER_TESTED_STATUS_MASK | ERH_KU8_AEC_FAILED_AT_LEAST_ONCE_MASK);
         }
      }
   }
   else
   {
      /* The AEC qualification is inhibited */
      erh_au8AecStatus[cu8Index] = ERH_KU8_AEC_EVER_TESTED_STATUS_MASK;
   }
}

/**
 * \brief
 *      This function shall manage the current AEC debounce counter and update the current AEC status on a Passed event
 * \param
 *     Uint8 cpu8Index: AEC ID related to the passed event
 *     stAECConfigurationType* pstAecData: Pointer to the corresponding AEC configuration
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
LOCAL void erh_ManagePassedCounterEvent(const uint8 cu8Index, const erh_stAECConfigurationType * const cpstAecData)
{
   uint16 u16AECDeskillThresold;
   uint8 u8NvmBlockStatus;
   /* [COVERS: DSG_ERH_00012] */
   //switch from big endian to little endian
   u16AECDeskillThresold = ((uint16)((cpstAecData->u16AECDeskillThrs & (uint32)KU16_MASK_BYTE_LOW) << KU8_EIGHT)) + ((cpstAecData->u16AECDeskillThrs & KU16_MASK_BYTE_HIGH) >> KU8_EIGHT);

   /* Check if the AEC can be deskilled */
   if ((KU16_ZERO != erh_au16AecCounter[cu8Index]) && (KU16_ZERO != u16AECDeskillThresold))
   {
      /* Decrement weight is not null , thus AEC can be deskilled when its counter reaches 0. */
      if (KU16_ONE >= erh_au16AecCounter[cu8Index])
      {
         /* AEC counter is under or equal to the decrement weight: it has to be deskilled here */
         erh_au16AecCounter[cu8Index] = KU16_ZERO;

         /* Verify if it is a transition from error qualified to disqualified */
         if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK == (erh_au8AecStatus[cu8Index] & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
         {
            /* Manage the AEC status bitfield:
              - set "ever tested"
            - keep only "ever qualified" and "ever failed" status */
            erh_au8AecStatus[cu8Index] = erh_au8AecStatus[cu8Index]
            & (ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK | ERH_KU8_AEC_FAILED_AT_LEAST_ONCE_MASK);
            U8_BIT_SET(erh_au8AecStatus[cu8Index], ERH_KU8_AEC_EVER_TESTED_STATUS_MASK);

            /* [COVERS: DSG_ERH_00013] */
            /* Update the group of the AEC */
            erh_UpdateGroup(cu8Index, cpstAecData);
         }
         else
         {
            /* Manage the AEC status bitfield:
              - set "ever tested"
            - keep only "ever qualified" and "ever failed" status */
            erh_au8AecStatus[cu8Index] = erh_au8AecStatus[cu8Index]
            & (ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK | ERH_KU8_AEC_FAILED_AT_LEAST_ONCE_MASK);
            U8_BIT_SET(erh_au8AecStatus[cu8Index], ERH_KU8_AEC_EVER_TESTED_STATUS_MASK);

            /* Do not update the groups because there was a transition from disqualified to disqualified */
         }
      }
      else
      {
         /* [COVERS: DSG_ERH_00015] */
         /* AEC counter is above the decrement weight, decrement the counter */
         erh_au16AecCounter[cu8Index] -= KU16_ONE;

         /* Check if the AEC is qualified */
         if (KU8_ONE == (ERH_KU8_AEC_QUALIFIED_STATUS_MASK & erh_au8AecStatus[cu8Index]))
         {
            /* Manage the AEC status bitfield:
              Force "in progress" flag if ever it was the first "passed" event after qualification */
            erh_au8AecStatus[cu8Index] |= (ERH_KU8_AEC_IN_PROGRESS_STATUS_MASK | ERH_KU8_AEC_EVER_TESTED_STATUS_MASK);
         }
         else
         {
            /* Fault threshold was not reached during the qualification phase, clear "In progress" flag */
            U8_BIT_CLEAR(erh_au8AecStatus[cu8Index], ERH_KU8_AEC_IN_PROGRESS_STATUS_MASK);
         }
      }
      /* [COVERS: DSG_ERH_00014] */
      /* Store the whole local status (except "ever tested" bit) in NVP structure for record in shutdown */
      NVP_BLOCK_ID_AEC_STATUS_RamBlockData.NVP_au8AECStatus[cu8Index] = (erh_au8AecStatus[cu8Index] & (uint8)(~(uint32)ERH_KU8_AEC_EVER_TESTED_STATUS_MASK));

      /* QAC_WARNING S 3417 5 */ /* The comma operator has been used outside a 'for' statement. */
      /* QAC_WARNING S 3426 4 */ /* Right hand side of comma expression has no side effect and its value is not used. */
      /* The following Macro is generated by system desk and can't be changed. */
      /* Notify NVP that AEC status shall be stored in EEPROM during shutdown */
      Rte_Call_pclNvmServicesAecBlock_GetErrorStatus(&u8NvmBlockStatus);

      if (NVM_REQ_PENDING != u8NvmBlockStatus)
      {

         (void)Rte_Call_pclNvmServicesAecBlock_SetRamBlockStatus(TRUE);
      }
      else
      {
         /* QAC */
      }
   }
   else
   {
      /* The AEC is already deskilled */
      /* Check if the qualification process was started */
      if(    (KU16_ZERO < erh_au16AecCounter[cu8Index])
          && (KU8_ZERO == (ERH_KU8_AEC_QUALIFIED_STATUS_MASK & erh_au8AecStatus[cu8Index])))
      {
         /* Decrease the counter */
         erh_au16AecCounter[cu8Index] -= KU16_ONE;

         /* Clear "in progress" flag */
         U8_BIT_CLEAR(erh_au8AecStatus[cu8Index], ERH_KU8_AEC_IN_PROGRESS_STATUS_MASK);

         /* Store the whole local status (except "ever tested" bit) in NVP structure for record in shutdown */
         NVP_BLOCK_ID_AEC_STATUS_RamBlockData.NVP_au8AECStatus[cu8Index] = (erh_au8AecStatus[cu8Index] & (uint8)(~(uint32)ERH_KU8_AEC_EVER_TESTED_STATUS_MASK));

         /* QAC_WARNING S 3417 5 */ /* The comma operator has been used outside a 'for' statement. */
         /* QAC_WARNING S 3426 4 */ /* Right hand side of comma expression has no side effect and its value is not used. */
         /* The following Macro is generated by system desk and can't be changed. */
         /* Notify NVP that AEC status shall be stored in EEPROM during shutdown */
         Rte_Call_pclNvmServicesAecBlock_GetErrorStatus(&u8NvmBlockStatus);

         if (NVM_REQ_PENDING != u8NvmBlockStatus)
         {

            (void)Rte_Call_pclNvmServicesAecBlock_SetRamBlockStatus(TRUE);
         }
         else
         {
            /* QAC */
         }
      }
      else
      {
         /* AEC can't be deskilled (Decrement weight is null) */
         /* Set the ever tested mask */
         erh_au8AecStatus[cu8Index] |= ERH_KU8_AEC_EVER_TESTED_STATUS_MASK;
      }
   }
}

/**
 * \brief
 *     This function shall check the validity of the current AEC identifier.
 * \param
 *     u8AecCommandType cu8Command:
 *     uint8* cpu8Index: AEC Index in the configuration table
 *     stAECConfigurationType* cpstAecData: Pointer to the corresponding AEC data structure where are stored the qualification/deskill thresholds and the AEC group status
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
* \return
 *     None.
 **/
LOCAL void erh_ManageAECCommand(const u8AecCommandType cu8Command, const uint8 cu8Index, const erh_stAECConfigurationType * const cpstAecData)
{
   uint8 u8NvmBlockStatus;
   /* [COVERS: DSG_ERH_00031;] */
   switch (cu8Command)
   {
   case KU8_AEC_FAILED:

      /* Update AEC status and counter */
      erh_ManageFailedCounterEvent(cu8Index, cpstAecData);

      break;

   case KU8_AEC_PASSED:

      /* Update AEC status and counter */
      erh_ManagePassedCounterEvent(cu8Index, cpstAecData);

      break;

   case KU8_AEC_RST_COUNTER:

      /* Reset the qualification counter */
      erh_au16AecCounter[cu8Index] = KU16_ZERO;

      /* Clear the qualified and in progress flag, keep ever qualified and ever tested */
      erh_au8AecStatus[cu8Index] = erh_au8AecStatus[cu8Index] & (ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK |
                                                                 ERH_KU8_AEC_EVER_TESTED_STATUS_MASK |
                                                                 ERH_KU8_AEC_FAILED_AT_LEAST_ONCE_MASK);

      /* Store the whole local status (except "ever tested" bit) in NVP structure for record in shutdown */
      NVP_BLOCK_ID_AEC_STATUS_RamBlockData.NVP_au8AECStatus[cu8Index] = (erh_au8AecStatus[cu8Index] & (uint8)(~(uint32)ERH_KU8_AEC_EVER_TESTED_STATUS_MASK));

      /* QAC_WARNING S 3417 5 */ /* The comma operator has been used outside a 'for' statement. */
      /* QAC_WARNING S 3426 4 */ /* Right hand side of comma expression has no side effect and its value is not used. */
                                 /* The following Macro is generated by system desk and can't be changed. */
      /* Notify NVP that AEC status shall be stored in EEPROM during shutdown */
      Rte_Call_pclNvmServicesAecBlock_GetErrorStatus(&u8NvmBlockStatus);

      if (NVM_REQ_PENDING != u8NvmBlockStatus)
      {
         (void)Rte_Call_pclNvmServicesAecBlock_SetRamBlockStatus(TRUE);
      }
      else
      {
         /* QAC */
      }

      break;

   case KU8_AEC_RST_ALL:

      /* Reset the qualification counter */
      erh_au16AecCounter[cu8Index] = KU16_ZERO;

      /* Set NVM Record requested to TRUE */
      erh_bNvmRecordRequested = B_TRUE;

      /* If AEC qualified */
      if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK == (erh_au8AecStatus[cu8Index] & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
      {
         /* Reset all status flags:              */
         /*    ERH_KU8_AEC_QUALIFIED_STATUS_MASK          cleared */
         /*    ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK     cleared */
         /*    ERH_KU8_AEC_EVER_TESTED_STATUS_MASK        cleared */
         /*    ERH_KU8_AEC_IN_PROGRESS_STATUS_MASK        cleared */
         /*    ERH_KU8_AEC_FAILED_AT_LEAST_ONCE_MASK      cleared */
         erh_au8AecStatus[cu8Index] = KU8_ZERO;

         /* Update the group of the AEC */
         erh_UpdateGroup(cu8Index, cpstAecData);
      }
      else
      {
         /* Reset all status flags:              */
         /*    ERH_KU8_AEC_QUALIFIED_STATUS_MASK          cleared */
         /*    ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK     cleared */
         /*    ERH_KU8_AEC_EVER_TESTED_STATUS_MASK        cleared */
         /*    ERH_KU8_AEC_IN_PROGRESS_STATUS_MASK        cleared */
         /*    ERH_KU8_AEC_FAILED_AT_LEAST_ONCE_MASK      cleared */
         erh_au8AecStatus[cu8Index] = KU8_ZERO;
      }
      /* Store the whole local status (except "ever tested" bit) in NVP structure for record in shutdown */
      NVP_BLOCK_ID_AEC_STATUS_RamBlockData.NVP_au8AECStatus[cu8Index] = (erh_au8AecStatus[cu8Index] & (uint8)(~(uint32)ERH_KU8_AEC_EVER_TESTED_STATUS_MASK));

      /* QAC_WARNING S 3417 5 */ /* The comma operator has been used outside a 'for' statement. */
      /* QAC_WARNING S 3426 4 */ /* Right hand side of comma expression has no side effect and its value is not used. */
                                 /* The following Macro is generated by system desk and can't be changed. */
      /* Notify NVP that AEC status shall be stored in EEPROM during shutdown */
      Rte_Call_pclNvmServicesAecBlock_GetErrorStatus(&u8NvmBlockStatus);

      if (NVM_REQ_PENDING != u8NvmBlockStatus)
      {

         (void)Rte_Call_pclNvmServicesAecBlock_SetRamBlockStatus(TRUE);
      }
      else
      {
         /* QAC */
      }

      break;

   default:

      break;
   }
}

/**
 * \brief
 *     This function shall update the group status and the number of qualified AECs in the group.
 * \param
 *     uint8 cu8AecId = The identifier to update
 *     erh_stAECConfigurationType* cpstAecData: Pointer to the corresponding AEC configuration
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/

LOCAL void erh_UpdateGroup(const uint8 cu8AecId, const erh_stAECConfigurationType * const cpstAecData)
{
   uint8 u8Group;
   uint32 u32GroupStatusForDTC = KU32_ZERO;
   uint8 u8AecIdSnapshotData = cu8AecId;

   /* Extract the associated group from AEC parameters in NVP */
   u8Group = cpstAecData->u8AECGroup;

   /* Check if the Group is invalid (superior than Other Failure group)*/
   if (u8Group > erh_u8OtherGroupValue)
   {
      /* Set the group identifier to OTHER FAILURE */
      u8Group = erh_u8OtherGroupValue;
   }
   else
   {
      /* Do nothing as the group identifier is valid */
   }

   u32GroupStatusForDTC = (uint32)KU32_ONE << u8Group;

   /* Test the type of event (just qualified, or just deskilled AEC) */
   if (KU8_ZERO != (ERH_KU8_AEC_QUALIFIED_STATUS_MASK & erh_au8AecStatus[cu8AecId]))
   {
      /* [COVERS: DSG_ERH_00016; DSG_ERH_00017] */
      /* At least one qualified AEC, qualification of the group */
      erh_au32GroupCounter[u8Group]++;
      erh_u32GroupsStatus |= (uint32)(KU32_ONE << u8Group);

      /* Send update trigger */
      /* [COVERS: DSG_ERH_00034] */
      (void)Rte_Write_psrAECsBlockStatus_b8NVMBlockStatus(KU8_TRUE);

      (void)Rte_Write_ERH_AC_ErrorHandler_psrSnapshotData_u8SnapshotAecId(u8AecIdSnapshotData);

      /* [COVERS: DSG_ERH_00022;] */
      /* Set DTC */
      switch (u32GroupStatusForDTC)
      {
      case (uint32)KU32_AEC_GROUP_MASK_HARDWARE:
         (void)Rte_Call_DTC_0x28b49_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_MOTOR:
         (void)Rte_Call_DTC_0x28b71_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_OVER_VO:
         (void)Rte_Call_DTC_0x10e00_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_UNDER_VO:
         (void)Rte_Call_DTC_0x10d00_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_OVER_VO_TENS:
         (void)Rte_Call_DTC_0x28b17_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_UNDER_VO_TENS:
         (void)Rte_Call_DTC_0x28b16_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_NVM:
         (void)Rte_Call_DTC_0x28b45_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_WARM_RESET:
         (void)Rte_Call_DTC_0x28b47_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_EOL_COMFORT:
         (void)Rte_Call_DTC_0x28b97_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_EOL_LOW_HIGH:
         (void)Rte_Call_DTC_0x28b96_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_EOL_MAX:
         (void)Rte_Call_DTC_0x28bfa_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_SELF_PROTECTION:
         (void)Rte_Call_DTC_0x28b4b_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_TIMEOUT_PRESAFE:
         (void)Rte_Call_DTC_0x12287_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_TIMEOUT_BUCKLE:
         (void)Rte_Call_DTC_0x15187_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_PRESAFE:
         (void)Rte_Call_DTC_0x41608_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_IGNITION:
         (void)Rte_Call_DTC_0x42708_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_BUCKLE_ORC:
         (void)Rte_Call_DTC_0x45208_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_POWERTRAIN:
         (void)Rte_Call_DTC_0xc44286_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_TIMEOUT_IGNITION:
         (void)Rte_Call_DTC_0xc16887_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_TIMEOUT_BH_R:
         (void)Rte_Call_DTC_0xc20287_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_TIMEOUT_BH_L:
         (void)Rte_Call_DTC_0xc20187_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_TIMEOUT_POWERTRAIN:
         (void)Rte_Call_DTC_0xc11587_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_STEERING_CONFIG:
         (void)Rte_Call_DTC_0xa20400_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_SYSTEM_OV:
         (void)Rte_Call_DTC_0xa10b00_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_SYSTEM_UV:
         (void)Rte_Call_DTC_0xa10a00_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_ODOSEEPDOMETER:
            (void)Rte_Call_DTC_0xc15587_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_API:
            (void)Rte_Call_DTC_0xd88a08_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_VARIANT_CODING:
            (void)Rte_Call_DTC_0x1ca000_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_TIMEOUT_API:
            (void)Rte_Call_DTC_0xd88987_SetEventStatus(DEM_EVENT_STATUS_FAILED);
         break;
      default:
         /* do nothing*/
         break;
      }
   }
   else if (erh_au32GroupCounter[u8Group] > KU32_ONE)
   {
      /* One qualified AEC less in the group */
      erh_au32GroupCounter[u8Group]--;
   }
   else
   {
      /* [COVERS: DSG_ERH_00018] */
      /* No more qualified AEC in group: Group deskill */
      erh_u32GroupsStatus &= ((uint32)(~(KU32_ONE << u8Group)));
      /* [COVERS: DSG_ERH_00025] */
      erh_au32GroupCounter[u8Group] = KU32_ZERO;

      /* Send update trigger */
      /* [COVERS: DSG_ERH_00034] */
      (void)Rte_Write_psrAECsBlockStatus_b8NVMBlockStatus(KU8_TRUE);

      /* [COVERS: DSG_ERH_00021;] */
      switch (u32GroupStatusForDTC)
      {
      case (uint32)KU32_AEC_GROUP_MASK_HARDWARE:
         (void)Rte_Call_DTC_0x28b49_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_MOTOR:
         (void)Rte_Call_DTC_0x28b71_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_OVER_VO:
         (void)Rte_Call_DTC_0x10e00_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_UNDER_VO:
         (void)Rte_Call_DTC_0x10d00_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_OVER_VO_TENS:
         (void)Rte_Call_DTC_0x28b17_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_UNDER_VO_TENS:
         (void)Rte_Call_DTC_0x28b16_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_NVM:
         (void)Rte_Call_DTC_0x28b45_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_WARM_RESET:
         (void)Rte_Call_DTC_0x28b47_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_EOL_COMFORT:
         (void)Rte_Call_DTC_0x28b97_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_EOL_LOW_HIGH:
         (void)Rte_Call_DTC_0x28b96_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_EOL_MAX:
         (void)Rte_Call_DTC_0x28bfa_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_SELF_PROTECTION:
         (void)Rte_Call_DTC_0x28b4b_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_TIMEOUT_PRESAFE:
         (void)Rte_Call_DTC_0x12287_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_TIMEOUT_BUCKLE:
         (void)Rte_Call_DTC_0x15187_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_PRESAFE:
         (void)Rte_Call_DTC_0x41608_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_IGNITION:
         (void)Rte_Call_DTC_0x42708_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_BUCKLE_ORC:
         (void)Rte_Call_DTC_0x45208_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_POWERTRAIN:
         (void)Rte_Call_DTC_0xc44286_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_TIMEOUT_IGNITION:
         (void)Rte_Call_DTC_0xc16887_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_TIMEOUT_BH_R:
         (void)Rte_Call_DTC_0xc20287_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_TIMEOUT_BH_L:
         (void)Rte_Call_DTC_0xc20187_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_TIMEOUT_POWERTRAIN:
         (void)Rte_Call_DTC_0xc11587_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_STEERING_CONFIG:
         (void)Rte_Call_DTC_0xa20400_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_SYSTEM_OV:
         (void)Rte_Call_DTC_0xa10b00_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_SYSTEM_UV:
         (void)Rte_Call_DTC_0xa10a00_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_ODOSEEPDOMETER:
            (void)Rte_Call_DTC_0xc15587_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_IMPLAUSIBLE_DATA_API:
            (void)Rte_Call_DTC_0xd88a08_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_VARIANT_CODING:
            (void)Rte_Call_DTC_0x1ca000_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      case (uint32)KU32_AEC_GROUP_MASK_TIMEOUT_API:
            (void)Rte_Call_DTC_0xd88987_SetEventStatus(DEM_EVENT_STATUS_PASSED);
         break;
      default:
         /* do nothing*/
         break;
      }
   }
}
/******************************************************************************
DEFINITION OF APIs
 ******************************************************************************/
/**
 * \brief
 *     This service shall initialize all AEC status and associated counters to default values. The “EVER QUALIFIED” status should be updated according to its value from NVM.
 *     This service shall be called only once during MCU initialization phase.
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
/* QAC_WARNING S 4641 3 */ /* The identifier 'ERH_Init' could conflict in the future with the name of a macro in '<errno.h>' */
                    /* This library is not expected to be used in the project. */
void ERH_Init(void)
{
   /* AEC corresponding index in the erh_au16AecCounter and erh_au8AecStatus arrays */
   uint8 u8Index;
   uint8 u8OutputIndex;
   /* Qualification threshold of the AEC */
   erh_stAECConfigurationType stAecData;

   ERH_u16StorageConditionStatus = KU16_ONE;

   erh_u8OtherGroupValue = ERH_KU8_NUMBER_OF_GROUPS;

   /* Initialize the pending event indexes for no pending events */
   erh_u8PendingEventAddIndex = KU8_ZERO;
   erh_u8PendingEventRunIndex = KU8_ZERO;

   /* By default no group is qualified */
   /* [COVERS: DSG_ERH_00019] */
   erh_u32GroupsStatus = KU16_ZERO;
   for (u8Index = KU8_ZERO ; u8Index < KU8_NUMBER_OF_GROUPS ; u8Index++)
   {
      erh_au32GroupCounter[u8Index] = KU32_ZERO;
   }

   /* Browse all AEC element to initialize status and qualification counters */
   /* [COVERS: DSG_ERH_00020] */
   for (u8Index = KU8_ZERO ; u8Index < ERH_KU8_NUMBER_OF_AEC ; u8Index++)
   {
	   (void) erh_CheckAecId((u8Index + KU8_ONE), &u8OutputIndex, &stAecData);

       /* Reset all status flags:              */
       /*    ERH_KU8_AEC_QUALIFIED_STATUS_MASK          cleared */
       /*    ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK     cleared */
       /*    ERH_KU8_AEC_EVER_TESTED_STATUS_MASK        cleared */
       /*    ERH_KU8_AEC_IN_PROGRESS_STATUS_MASK        cleared */
       /*    ERH_KU8_AEC_FAILED_AT_LEAST_ONCE_MASK      cleared */
       erh_au8AecStatus[u8OutputIndex] = KU8_ZERO;

       /* Update the group of the AEC */
       erh_UpdateGroup(u8OutputIndex, &stAecData);


      /* Reset the qualification counter */
      erh_au16AecCounter[u8Index] = KU16_ZERO;

      /* Load EVER QUALIFIED status and QUALIFIED status from NVP */
      /* and reset all others status flags. */
      /*    ERH_KU8_AEC_QUALIFIED_STATUS_MASK          read from NVP */
      /*    ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK     cleared       */
      /*    ERH_KU8_AEC_EVER_TESTED_STATUS_MASK        read from NVP */
      /*    ERH_KU8_AEC_IN_PROGRESS_STATUS_MASK        cleared       */

      /* Initialize Aec Status */
      erh_au8AecStatus[u8Index] = KU8_ZERO;

      /* [COVERS: DSG_ERH_00033] */
      /* Read EVER QUALIFIED status in NVP and update status tables according its value */
      if (ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK == (NVP_BLOCK_ID_AEC_STATUS_RamBlockData.NVP_au8AECStatus[u8Index] & ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK))
      {
         /* AEC "ever qualified" flag is set */
         erh_au8AecStatus[u8Index] |= ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK;
      }
      else
      {
         /* Do nothing as already initialized */
      }
      /* [COVERS: DSG_ERH_00032] */
      /* Read QUALIFIED status in NVP and update status tables according its value */
      if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK == (NVP_BLOCK_ID_AEC_STATUS_RamBlockData.NVP_au8AECStatus[u8Index] & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
      {
         /* AEC "ever qualified" flag is set */
         erh_au8AecStatus[u8Index] |= ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK;
      }
      else
      {
         /* Do nothing as already initialized */
      }
   }
   /* Set the "ever qualified" status as synchronous between RAM and NVP */
   erh_bNvmRecordRequested       = B_FALSE;
   erh_u8StAECWriteStatusResult  = KU8_NVP_AEC_RECORDING_OK;

   /* [COVERS: DSG_ERH_00028] */
   (void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_PowerCycle, DEM_CYCLE_STATE_START);
   (void)Dem_SetEnableCondition(DemConf_DemEnableCondition_DemEnableCondition_ECUPowerUp,TRUE);
   (void)Dem_SetEnableCondition(DemConf_DemEnableCondition_DemEnableCondition_CodingAPI,TRUE);
   (void)Dem_SetEnableCondition(DemConf_DemEnableCondition_DemEnableCondition_CodingRBTMFL,TRUE);
   (void)Dem_SetEnableCondition(DemConf_DemEnableCondition_DemEnableCondition_CodingRBTMFR,TRUE);
   (void)Dem_SetEnableCondition(DemConf_DemEnableCondition_DemEnableCondition_IgnitionON,TRUE);
}
/**
 * \brief
 *     Runnable(10ms) used for debounce mechanism befor start of Dem Ignition cycle
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

void ERH_cyclic(void)
{
	ComM_ModeType ComM_Status;

	uint8 u8IgnitionStatus;
	uint8 u8IgnitionStatusStorage;
	uint8 u8EngStartStatus;
	uint8 u8ProductionMode;
	uint8 u8TransportationMode;
	uint8 u8SupBatStatus;


	uint8 u8AutotestResultSOV;
	uint8 u8AutotestResultSUV;

	uint8 u8AutotestResultOV;
	uint8 u8AutotestResultUV;

	uint8 u8AutotestResultVariantCoding;

	uint8 u8DtcState;

	uint16 EventId;
	uint8 EventStatusByte;
	uint8 u8EvtIndex;

	/* [COVERS: DSG_ERH_00040] */
	u8DtcState = Rte_Mode_prrControlAECSetting_DcmControlDtcSetting();

	/* Check if signal status is SNA */
	/* [COVERS: DSG_ERH_00042] */
	(void)Rte_Read_isrSupBatStatus_b8SupBatStatus(&u8SupBatStatus);

	/* Get current ComM mode */
	/* [COVERS: DSG_ERH_00044] */
	(void)Rte_Call_pcsGetComMStatus_GetCurrentComMode(&ComM_Status);

	/* Get status of Engine Start signal*/
	/* [COVERS: DSG_ERH_00046] */
	(void)Rte_Read_prrEngStartStatus_b8EngStartStatus(&u8EngStartStatus);

	/* Get status of Production Mode signal*/
	/* [COVERS: DSG_ERH_00048] */
	(void)Rte_Read_prrProdModeStatus_b8TriggerProdModeStatus(&u8ProductionMode);

	/* Get status of Transportation Mode signal*/
	/* [COVERS: DSG_ERH_00050] */
	(void)Rte_Read_prrTransportationModeStatus_b8TransportationModeStatus(&u8TransportationMode);

	/* Get test result for System Voltage*/
	/* [COVERS: DSG_ERH_00052] */
	(void)Rte_Call_pcsAutotestServices_GetTestResult(ATM_KU8_ID_SYSTEM_OV, &u8AutotestResultSOV);
	(void)Rte_Call_pcsAutotestServices_GetTestResult(ATM_KU8_ID_SYSTEM_UV, &u8AutotestResultSUV);

	/* Get test result for Local Voltage*/
	/* [COVERS: DSG_ERH_00052] */
	(void)Rte_Call_pcsAutotestServices_GetTestResult(ATM_KU8_ID_TEST_OVER_VOLTAGE_POWER, &u8AutotestResultOV);
	(void)Rte_Call_pcsAutotestServices_GetTestResult(ATM_KU8_ID_TEST_UNDER_VOLTAGE_POWER, &u8AutotestResultUV);

	(void)Rte_Call_pcsAutotestServices_GetTestResult(ATM_KU8_ID_VARIANT_CODING, &u8AutotestResultVariantCoding);

	/* Get status of Ignition signal for storage */
	/* [COVERS: DSG_ERH_00038] */
	(void)Rte_Read_prrIgnitionStatus_b8TriggerIgnitionStatusEnableStorageCondition(&u8IgnitionStatusStorage);

	/* [COVERS: DSG_ERH_00035] */
	/* Get status of Ignition signal*/
	(void)Rte_Read_prrIgnitionStatus_b8TriggerIgnitionStatus(&u8IgnitionStatus);


	/* [COVERS: DSG_ERH_00036; DSG_ERH_00037] */
	/* Manage Ignition Power cycle */
	if(KU8_TRUE== u8IgnitionStatus)
	{
		/* start debounce counter */
		erh_u16DebounceCounter++;

		if((KU16_COUNTER_TRESHOLD_IGN == erh_u16DebounceCounter) && (KU8_FALSE == bIgnitionCounterTrigger))
		{
		   if(KU8_ATM_TEST_OK == u8AutotestResultVariantCoding)
		            {
		               (void)Rte_Call_DTC_0x1ca000_SetEventStatus(DEM_EVENT_STATUS_PASSED);
		            }
		            else
		            {
		               /* do nothing*/
		            }
			/* Start of IGN cycle  */
			(void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_IgnitionCycle, DEM_CYCLE_STATE_START);


			bIgnitionCounterTrigger = KU8_TRUE;


		}
		else if( KU16_COUNTER_TRESHOLD_IGN <= erh_u16DebounceCounter)
		{
		   /* reset counter */
		      erh_u16DebounceCounter = KU8_ZERO;
		}
		else
		{
		   /* do nothing */
		}
	}
	else
	{
		/* END of IGN cycle  */
		(void)Dem_SetOperationCycleState(DemConf_DemOperationCycle_IgnitionCycle, DEM_CYCLE_STATE_END);
		 bIgnitionCounterTrigger = KU8_FALSE;
	}

	/* [COVERS: DSG_ERH_00041] */
	if(RTE_MODE_DcmControlDtcSetting_ENABLEDTCSETTING == u8DtcState)
	{
		ERH_SET_STORAGE_CONDITION_MASK_ON(KU16_ERH_SC1_ControlDTC);
		(void)Rte_Call_pclStorageConditionSC1_SetStorageCondition(BOOL_ERH_SET_STORAGE_CONDITION);
	}
	else
	{
		ERH_SET_STORAGE_CONDITION_MASK_OFF(KU16_ERH_SC1_ControlDTC);
		(void)Rte_Call_pclStorageConditionSC1_SetStorageCondition(BOOL_ERH_CLEAR_STORAGE_CONDITION);
	}


	/* Set SC2 if condition is fulfilled */
	/* [COVERS: DSG_ERH_00039] */
	if(KU8_TRUE == u8IgnitionStatusStorage)
	{
		ERH_SET_STORAGE_CONDITION_MASK_ON(KU16_ERH_SC2_IgnitonStatus);
		(void)Rte_Call_pclStorageConditionSC2_SetStorageCondition(BOOL_ERH_SET_STORAGE_CONDITION);
	}
	else
	{
		ERH_SET_STORAGE_CONDITION_MASK_OFF(KU16_ERH_SC2_IgnitonStatus);
		(void)Rte_Call_pclStorageConditionSC2_SetStorageCondition(BOOL_ERH_CLEAR_STORAGE_CONDITION);
	}


	/* Set SC3 if condition is fulfilled */
	/* [COVERS: DSG_ERH_00053] */
	if((KU8_ATM_TEST_OK == u8AutotestResultOV) && (KU8_ATM_TEST_OK == u8AutotestResultUV))
	{
		ERH_SET_STORAGE_CONDITION_MASK_ON(KU16_ERH_SC3_LocalVoltage);
		(void)Rte_Call_pclStorageConditionSC3_SetStorageCondition(BOOL_ERH_SET_STORAGE_CONDITION);
	}
	else
	{
		ERH_SET_STORAGE_CONDITION_MASK_OFF(KU16_ERH_SC3_LocalVoltage);
		(void)Rte_Call_pclStorageConditionSC3_SetStorageCondition(BOOL_ERH_CLEAR_STORAGE_CONDITION);
	}


	/* Set SC4 if condition is fulfilled */
	/* [COVERS: DSG_ERH_00043] */
	if( KU8_FALSE == u8SupBatStatus)
	{
		if((KU8_ATM_TEST_OK == u8AutotestResultSOV) && (KU8_ATM_TEST_OK == u8AutotestResultSUV))
		{
			ERH_SET_STORAGE_CONDITION_MASK_ON(KU16_ERH_SC4_SystemVoltage);
			(void)Rte_Call_pclStorageConditionSC4_SetStorageCondition(BOOL_ERH_SET_STORAGE_CONDITION);
		}
		else
		{
			ERH_SET_STORAGE_CONDITION_MASK_OFF(KU16_ERH_SC4_SystemVoltage);
			(void)Rte_Call_pclStorageConditionSC4_SetStorageCondition(BOOL_ERH_CLEAR_STORAGE_CONDITION);
		}
	}
	else
	{
		if((KU8_ATM_TEST_OK == u8AutotestResultOV) && (KU8_ATM_TEST_OK == u8AutotestResultUV))
		{
			ERH_SET_STORAGE_CONDITION_MASK_ON(KU16_ERH_SC3_LocalVoltage);
			(void)Rte_Call_pclStorageConditionSC3_SetStorageCondition(BOOL_ERH_SET_STORAGE_CONDITION);
		}
		else
		{
			ERH_SET_STORAGE_CONDITION_MASK_OFF(KU16_ERH_SC3_LocalVoltage);
			(void)Rte_Call_pclStorageConditionSC3_SetStorageCondition(BOOL_ERH_CLEAR_STORAGE_CONDITION);
		}

	}


	/* Set SC5 if condition is fulfilled */
	/* [COVERS: DSG_ERH_00051] */
	if(KU8_TRUE == u8TransportationMode)
	{
		ERH_SET_STORAGE_CONDITION_MASK_ON(KU16_ERH_SC5_TransportationMode);
		(void)Rte_Call_pclStorageConditionSC5_SetStorageCondition(BOOL_ERH_SET_STORAGE_CONDITION);
	}
	else
	{
		ERH_SET_STORAGE_CONDITION_MASK_OFF(KU16_ERH_SC5_TransportationMode);
		(void)Rte_Call_pclStorageConditionSC5_SetStorageCondition(BOOL_ERH_CLEAR_STORAGE_CONDITION);
	}


	/* Set SC8 if condition is fulfilled */
	/* [COVERS: DSG_ERH_00045] */
	if(COMM_FULL_COMMUNICATION == ComM_Status)
	{
		ERH_SET_STORAGE_CONDITION_MASK_ON(KU16_ERH_SC8_CommunicationStatus);
		(void)Rte_Call_pclStorageConditionSC8_SetStorageCondition(BOOL_ERH_SET_STORAGE_CONDITION);
	}
	else
	{
		ERH_SET_STORAGE_CONDITION_MASK_OFF(KU16_ERH_SC8_CommunicationStatus);
		(void)Rte_Call_pclStorageConditionSC8_SetStorageCondition(BOOL_ERH_CLEAR_STORAGE_CONDITION);
	}


	/* Set S11 if condition is fulfilled */
	/* [COVERS: DSG_ERH_00047] */
	if(KU8_TRUE == u8EngStartStatus)
	{
		ERH_SET_STORAGE_CONDITION_MASK_ON(KU16_ERH_SC11_VehicleStartup);
		(void)Rte_Call_pclStorageConditionSC11_SetStorageCondition(BOOL_ERH_SET_STORAGE_CONDITION);
	}
	else
	{
		ERH_SET_STORAGE_CONDITION_MASK_OFF(KU16_ERH_SC11_VehicleStartup);
		(void)Rte_Call_pclStorageConditionSC11_SetStorageCondition(BOOL_ERH_CLEAR_STORAGE_CONDITION);
	}



	/* Set SC12 if condition is fulfilled */
	/* [COVERS: DSG_ERH_00049] */
	if(KU8_TRUE == u8ProductionMode)
	{
		ERH_SET_STORAGE_CONDITION_MASK_ON(KU16_ERH_SC12_ProductionMode);
		(void)Rte_Call_pclStorageConditionSC12_SetStorageCondition(BOOL_ERH_SET_STORAGE_CONDITION);
	}
	else
	{
		ERH_SET_STORAGE_CONDITION_MASK_OFF(KU16_ERH_SC12_ProductionMode);
		(void)Rte_Call_pclStorageConditionSC12_SetStorageCondition(BOOL_ERH_CLEAR_STORAGE_CONDITION);
	}



	/* Set SC10 Debounce timer NC group*/
	/* [COVERS: DSG_ERH_00066; DSG_ERH_00063] */
	if(KU16_ERH_MASK_DEBOUNCE_TIMER_NC == (KU16_ERH_MASK_DEBOUNCE_TIMER_NC & ERH_u16StorageConditionStatus))
	{
		if(KU16_ERH_TIMER_TRESHOLD > ERH_u16DebounceCounter_NetworkComunication)
		{
			ERH_u16DebounceCounter_NetworkComunication++;
		}

		if(KU16_ERH_TIMER_TRESHOLD == ERH_u16DebounceCounter_NetworkComunication)
		{
			ERH_SET_STORAGE_CONDITION_MASK_ON(KU16_ERH_SC10_1_debounceTimer);
			(void)Rte_Call_pclStorageConditionSC10_1_SetStorageCondition(BOOL_ERH_SET_STORAGE_CONDITION);
		}
		else
		{
			ERH_SET_STORAGE_CONDITION_MASK_OFF(KU16_ERH_SC10_1_debounceTimer);
			(void)Rte_Call_pclStorageConditionSC10_1_SetStorageCondition(BOOL_ERH_CLEAR_STORAGE_CONDITION);
		}
	}
	else
	{
		ERH_u16DebounceCounter_NetworkComunication = KU16_ZERO;
		(void)Rte_Call_pclStorageConditionSC10_1_SetStorageCondition(BOOL_ERH_CLEAR_STORAGE_CONDITION);
	}

	/* Set SC10 Debounce timer NK15 group*/
	/* [COVERS: DSG_ERH_00065; DSG_ERH_00063] */
	if(KU16_ERH_MASK_DEBOUNCE_TIMER_NC15 == (KU16_ERH_MASK_DEBOUNCE_TIMER_NC15 & ERH_u16StorageConditionStatus))
	{
		if(KU16_ERH_TIMER_TRESHOLD > ERH_u16DebounceCounter_NetworkComunication15)
		{
			ERH_u16DebounceCounter_NetworkComunication15++;
		}

		if(KU16_ERH_TIMER_TRESHOLD == ERH_u16DebounceCounter_NetworkComunication15)
		{
			ERH_SET_STORAGE_CONDITION_MASK_ON(KU16_ERH_SC10_2_debounceTimer);
			(void)Rte_Call_pclStorageConditionSC10_2_SetStorageCondition(BOOL_ERH_SET_STORAGE_CONDITION);
		}
		else
		{
			ERH_SET_STORAGE_CONDITION_MASK_OFF(KU16_ERH_SC10_2_debounceTimer);
			(void)Rte_Call_pclStorageConditionSC10_2_SetStorageCondition(BOOL_ERH_CLEAR_STORAGE_CONDITION);
		}
	}
	else
	{
		ERH_u16DebounceCounter_NetworkComunication15 = KU16_ZERO;
		(void)Rte_Call_pclStorageConditionSC10_2_SetStorageCondition(BOOL_ERH_CLEAR_STORAGE_CONDITION);
	}

	/* Set SC10 Debounce timer PD group*/
	/* [COVERS: DSG_ERH_00064; DSG_ERH_00063] */
	if(KU16_ERH_MASK_DEBOUNCE_TIMER_PD == (KU16_ERH_MASK_DEBOUNCE_TIMER_PD & ERH_u16StorageConditionStatus))
	{
		if(KU16_ERH_TIMER_TRESHOLD > ERH_u16DebounceCounter_PowerDistribution)
		{
			ERH_u16DebounceCounter_PowerDistribution++;
		}

		if(KU16_ERH_TIMER_TRESHOLD == ERH_u16DebounceCounter_PowerDistribution)
		{
			ERH_SET_STORAGE_CONDITION_MASK_ON(KU16_ERH_SC10_0_debounceTimer);
			(void)Rte_Call_pclStorageConditionSC10_0_SetStorageCondition(BOOL_ERH_SET_STORAGE_CONDITION);
		}
		else
		{
			ERH_SET_STORAGE_CONDITION_MASK_OFF(KU16_ERH_SC10_0_debounceTimer);

			(void)Rte_Call_pclStorageConditionSC10_0_SetStorageCondition(BOOL_ERH_CLEAR_STORAGE_CONDITION);
		}
	}
	else
	{
		ERH_u16DebounceCounter_PowerDistribution = KU16_ZERO;
		(void)Rte_Call_pclStorageConditionSC10_0_SetStorageCondition(BOOL_ERH_CLEAR_STORAGE_CONDITION);
	}

	/* [COVERS: DSG_ERH_00067] */
	for (u8EvtIndex = KU8_ZERO; u8EvtIndex < KU8_NUMBER_OF_GROUPS; u8EvtIndex++)
	{
		(void)Dem_GetEventUdsStatus(EventId, &EventStatusByte);
		/* [COVERS: DSG_ERH_00068] */
		if ( (EventStatusByte & KU16_ERH_MASK_DTC_CONFIRMED) == KU16_ERH_MASK_DTC_CONFIRMED)
		{
			(void)Rte_Write_ERH_AC_ErrorHandler_psrDTCConfirmed_b8DTCConfirmed(B_TRUE);
		}
		else
		{
			(void)Rte_Write_ERH_AC_ErrorHandler_psrDTCConfirmed_b8DTCConfirmed(B_FALSE);
		}
	}
}
/**
 * \brief
 *     This service shall supply the AEC status to DemIf module if the AEC identifier is valid.
 *     The AEC identifier transmitted by the input parameter “u8AecIdentifier” is between 0x00 and 0x37
 *     this service shall send by the output parameter “pu8AecStatus” the current AEC status, and if the AEC identifier
 *     is out of range the transmitted AEC status shall be set to "UNPLAUSIBLE_STATUS".
 * \param
 *     u8AecIdentifierType u8AecIdentifier: The AEC Identifier
 *     u8AecStatusType u8AecStatus: The value for AEC status
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
/* QAC_WARNING S 3227 5 */  /* The parameter 'u8AecIdentifier' is never modified and so it could be declared with the 'const' qualifier. */
                     /* The parameter 'pu8AecStatus' is never modified and so it could be declared with the 'const' qualifier. */
                     /* These functions are auto-generated by System Desk wherein with it's not possible to insert the 'const' qualifier. */
/* QAC_WARNING S 4641 11 */ /* The identifier 'ERH_runGetAecStatus' could conflict in the future with the name of a macro in '<errno.h>'. */
                     /* This library is not expected to be used in the project. */
void ERH_runGetAecStatus(u8AecIdentifierType u8AecIdentifier, u8AecStatusType * pu8AecStatus)
{
   /* AEC corresponding index in the erh_au16AecCounter and erh_au8AecStatus arrays */
   uint8 u8Index;

   /* Qualification threshold of the AEC */
   erh_stAECConfigurationType stAecData;
   /* [COVERS: DSG_ERH_00029] */
   if ( NULL_PTR != pu8AecStatus)
   {
      /* Check the identifier validity, and get the corresponding index if valid */
      if (B_TRUE == erh_CheckAecId(u8AecIdentifier, &u8Index, &stAecData))
      {
         /* Output the current validity flags */
         /* If ever the pointer was NULL, the following test prevent from writing to address zero.
          * (QAC check compliant). Anyway, thanks to return value, the function allows to know that
          * the QAC identifier exists, even if there is no valid container to output its status. */
         (*pu8AecStatus) = erh_au8AecStatus[u8Index];
      }
      else
      {
         /* The AEC identifier is out of range.
          * Notify this to the client. */
         (*pu8AecStatus) = ERH_KU8_AEC_UNPLAUSIBLE_STATUS;
      }
   }
   else
   {
      /* The pointer passed to the function is NULL. Should never happen. */
      /* No status can be output */
      /* TODO error notification */
   }
}

/**
 * \brief
 *     This service shall provide the the current AEC groups status bitfield.
 * \param
 *     u32AecGroupsType pu16AecGroupsStatus: The value for AECs group status
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
/* QAC_WARNING S 3227 4 */  /* The parameter 'pu16AecGroupsStatus' is never modified and so it could be declared with the 'const' qualifier. */
/* QAC_WARNING S 4641 3 */  /* The identifier 'ERH_runGetAecGroupsStatus' could conflict in the future with the name of a macro in '<errno.h>'. */
                     /* This function is auto-generated by System Desk wherein with it's not possible to insert the 'const' qualifier
                      * nor to change its name. */
void ERH_runGetAecGroupsStatus(u32AecGroupsType * pu32AecGroupsStatus)
{
   /* [COVERS: DSG_ERH_00030] */
   /* Directly output the current groups status bitfield */
   *pu32AecGroupsStatus = erh_u32GroupsStatus;
}



/**
 * \brief
 *     Update a given AEC status applying the denouncing mechanism:
 *     - From a new failure state (received in u8Command argument).
 *     - Basing of the  previous AEC status.
 * \param
 *     u8AecIdentifierType u8AecIdentifier: the AEC identifier
 *     u8AecCommandType u8Command: KU8_AEC_FAILED: Update the error status regarding a test failed result
 *                                 KU8_AEC_PASSED      : Update the error status regarding a test passed result
 * \exception
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
/* QAC_WARNING S 3227 5 */  /* The parameter 'u8AecIdentifier' is never modified and so it could be declared with the 'const' qualifier. */
                     /* The parameter 'u8Command' is never modified and so it could be declared with the 'const' qualifier. */
                     /* These functions are auto-generated by System Desk wherein with it's not possible to insert the 'const' qualifier. */
/* QAC_WARNING S 4641 11 */ /* The identifier 'ERH_SetEvent' could conflict in the future with the name of a macro in '<errno.h>'. */
                    /* This library is not expected to be used in the project. */
void ERH_runSetAecEvent(u8AecIdentifierType u8AecIdentifier, u8AecCommandType u8Command)
{
	/* AEC corresponding index in the erh_au16AecCounter and erh_au8AecStatus arrays */
	uint8 u8Index;

	/* Qualification threshold of the AEC */
	erh_stAECConfigurationType stAecData;

	/* Indicates that the current event has to be processed now (not just stored for future processing) */
	boolean bRunEvent;

	/* [COVERS: DSG_ERH_00032;] */
	/* Check if an event is already in progress */
	if (erh_u8PendingEventRunIndex != erh_u8PendingEventAddIndex)
	{
		/* Since one event is already in progress, the current event has to be stored for future processing,... */
		erh_au8PendingEventAecIdentifier[erh_u8PendingEventAddIndex] = u8AecIdentifier;
		erh_au8PendingEventCommand[erh_u8PendingEventAddIndex] = u8Command;
		/* ...and is not going to be processed in this function instance. */
		bRunEvent = B_FALSE;
	}
	else
	{
		/* Since there is no other event being processed, the current one has to be processed in this function instance */
		bRunEvent = B_TRUE;
	}
	/* Make nested event see the current event presence */
	erh_u8PendingEventAddIndex = (erh_u8PendingEventAddIndex + KU8_ONE) % KU8_MAX_PENDING_EVENT;

	/* - Either process current event, then possible pending event which can have occurred during
	 *   the current event processing.
	 * - Or process no event now, since the current one has just been added to the pending list
	 *   for a delayed processing. */

	while (B_TRUE == bRunEvent)
	{
		/* Check the identifier validity, and get the corresponding index if valid */
		if ((B_TRUE == erh_CheckAecId(u8AecIdentifier, &u8Index, &stAecData)))
		{

			/* [COVERS: DSG_ERH_00059; DSG_ERH_00054] */
			for(ERH_u8Index_ECULevel= KU8_ZERO; ERH_u8Index_ECULevel < KU8_FIFTEEN; ERH_u8Index_ECULevel++)
			{
				if (ERH_u16AECsForECULevel_StorageGroup[ERH_u8Index_ECULevel] == (u8Index + KU8_ONE))
				{
					if ((ERH_u16StorageConditionStatus & KU16_ERH_MASK_ECU_LEVEL) == KU16_ERH_MASK_ECU_LEVEL)
					{
						/* Process separately the 4 possible cases regarding the function second argument:
						 *    KU8_AEC_FAILED
						 *    KU8_AEC_PASSED
						 *    KU8_AEC_RST_COUNTER
						 *    KU8_AEC_RST_ALL
						 *    other values  */
						erh_ManageAECCommand(u8Command, u8Index, &stAecData);
					}
				}
			}


			/* [COVERS: DSG_ERH_00062; DSG_ERH_00057;] */
			for(ERH_u8Index_PowerDistribution= KU8_ZERO; ERH_u8Index_PowerDistribution < KU8_SIX; ERH_u8Index_PowerDistribution++)
			{
				if (ERH_u16AECsForPowerDistribution_StorageGroup[ERH_u8Index_PowerDistribution] == (u8Index + KU8_ONE))
				{
					if ((ERH_u16StorageConditionStatus & KU16_ERH_MASK_POWER_DISTRIBUTION) == KU16_ERH_MASK_POWER_DISTRIBUTION)
					{
						/* Process separately the 4 possible cases regarding the function second argument:
						 *    KU8_AEC_FAILED
						 *    KU8_AEC_PASSED
						 *    KU8_AEC_RST_COUNTER
						 *    KU8_AEC_RST_ALL
						 *    other values  */
						erh_ManageAECCommand(u8Command, u8Index, &stAecData);
					}
				}
			}



			/* [COVERS: DSG_ERH_00060;DSG_ERH_00055] */
			for(ERH_u8Index_NetworkCom = KU8_ZERO; ERH_u8Index_NetworkCom < KU8_FIFTEEN; ERH_u8Index_NetworkCom++)
			{
				if (ERH_u16AECsForNetworkCom_StorageGroup[ERH_u8Index_NetworkCom] == (u8Index + KU8_ONE))
				{
					if( KU16_ERH_MASK_NETWORK_COM == (ERH_u16StorageConditionStatus & KU16_ERH_MASK_NETWORK_COM))
					{
						/* Process separately the 4 possible cases regarding the function second argument:
						 *    KU8_AEC_FAILED
						 *    KU8_AEC_PASSED
						 *    KU8_AEC_RST_COUNTER
						 *    KU8_AEC_RST_ALL
						 *    other values  */
						erh_ManageAECCommand(u8Command, u8Index, &stAecData);
					}
				}

			}
			/* [COVERS: DSG_ERH_00061;DSG_ERH_00056] */
			if((ERH_KU8_TIMEOUT_IGNITION_AEC_CFG == (u8Index + KU8_ONE)) &&
					((ERH_u16StorageConditionStatus & KU16_ERH_MASK_NETWORK_COM15) == KU16_ERH_MASK_NETWORK_COM15))
			{
				/* Process separately the 4 possible cases regarding the function second argument:
				 *    KU8_AEC_FAILED
				 *    KU8_AEC_PASSED
				 *    KU8_AEC_RST_COUNTER
				 *    KU8_AEC_RST_ALL
				 *    other values  */
				erh_ManageAECCommand(u8Command, u8Index, &stAecData);
			}
			/* [COVERS: DSG_ERH_00058;] */
			for(ERH_u8Index_NoStorageCondition = KU8_ZERO; ERH_u8Index_NoStorageCondition < KU8_EIGHT; ERH_u8Index_NoStorageCondition++)
			{
				if (ERH_u16AECsForControlDTC_StorageGroup[ERH_u8Index_NoStorageCondition] == (u8Index + KU8_ONE))
				{
					if( KU16_ERH_MASK_CONTROL_DTC == (uint16)(ERH_u16StorageConditionStatus & KU16_ERH_MASK_CONTROL_DTC) )
					{
						/* Process separately the 4 possible cases regarding the function second argument:
						 *    KU8_AEC_FAILED
						 *    KU8_AEC_PASSED
						 *    KU8_AEC_RST_COUNTER
						 *    KU8_AEC_RST_ALL
						 *    other values  */
						erh_ManageAECCommand(u8Command, u8Index, &stAecData);
					}
				}

			}



		}
		else
		{
			/* The AEC identifier is out of rang. Should never happen */
			/* TODO error notification */
		}

		/* Update the "run from list" index regarding the just completed event processing */
		erh_u8PendingEventRunIndex = (erh_u8PendingEventRunIndex + KU8_ONE) % KU8_MAX_PENDING_EVENT;

		/* Check if additional events have occurred and were stored during this processing */
		if (erh_u8PendingEventRunIndex != erh_u8PendingEventAddIndex)
		{
			/* Retrieves the nested execution arguments */
			u8AecIdentifier = erh_au8PendingEventAecIdentifier[erh_u8PendingEventRunIndex];
			u8Command = erh_au8PendingEventCommand[erh_u8PendingEventRunIndex];
			/* Note : Here, bRunEvent shall be kept to B_TRUE */
		}
		else
		{
			/* No more event to process */
			bRunEvent = B_FALSE;
		}
	}
}


/**
 * \brief
 *     This service shall reset all AECs status.
 * \param
 *     None.
 * \pre
 *     None.
 * \post
 *     None.
 * \return
 *     None.
 **/
Std_ReturnType ERH_ResetAllAECStatus(void)
{
   uint8 u8AECIndex;
   uint8 u8Index;
   uint8 u8OutputIndex;
   Std_ReturnType Result;
   /* Qualification threshold of the AEC */
   erh_stAECConfigurationType stAecData;
   uint8 u8NvmBlockStatus;
   
   /* Set NVM Record requested to TRUE */
   erh_bNvmRecordRequested = B_TRUE;

   for (u8Index = KU8_ZERO; u8Index < ERH_KU8_NUMBER_OF_AEC; u8Index++)
   {
      /* Reset the qualification counter */
      erh_au16AecCounter[u8Index] = KU16_ZERO;
      /*Clear all AECs counter*/
   }
   /* [COVERS: DSG_ERH_00026; DSG_ERH_00027] */
   for (u8AECIndex = KU8_ONE; u8AECIndex <= ERH_KU8_NUMBER_OF_AEC; ++u8AECIndex)
   {
      (void) erh_CheckAecId(u8AECIndex, &u8OutputIndex, &stAecData);

      /* If AEC qualified */
      if (ERH_KU8_AEC_QUALIFIED_STATUS_MASK == (erh_au8AecStatus[u8OutputIndex] & ERH_KU8_AEC_QUALIFIED_STATUS_MASK))
      {
         /* Reset all status flags:              */
         /*    ERH_KU8_AEC_QUALIFIED_STATUS_MASK          cleared */
         /*    ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK     cleared */
         /*    ERH_KU8_AEC_EVER_TESTED_STATUS_MASK        cleared */
         /*    ERH_KU8_AEC_IN_PROGRESS_STATUS_MASK        cleared */
         /*    ERH_KU8_AEC_FAILED_AT_LEAST_ONCE_MASK      cleared */
         erh_au8AecStatus[u8OutputIndex] = KU8_ZERO;

         /* Update the group of the AEC */
         erh_UpdateGroup(u8OutputIndex, &stAecData);
      }
      else
      {
         /* Reset all status flags:              */
         /*    ERH_KU8_AEC_QUALIFIED_STATUS_MASK          cleared */
         /*    ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK     cleared */
         /*    ERH_KU8_AEC_EVER_TESTED_STATUS_MASK        cleared */
         /*    ERH_KU8_AEC_IN_PROGRESS_STATUS_MASK        cleared */
         /*    ERH_KU8_AEC_FAILED_AT_LEAST_ONCE_MASK      cleared */
         erh_au8AecStatus[u8OutputIndex] = KU8_ZERO;

         erh_UpdateGroup(u8OutputIndex, &stAecData);
      }

      /* Store the whole local status (except "ever tested" bit) in NVP structure for record in shutdown */
      NVP_BLOCK_ID_AEC_STATUS_RamBlockData.NVP_au8AECStatus[u8OutputIndex] = (erh_au8AecStatus[u8OutputIndex] & (uint8) (~(uint32) ERH_KU8_AEC_EVER_TESTED_STATUS_MASK));
   }

   /* Update block checksum */
   //erh_UpdateChecksum();

   /* QAC_WARNING S 315 5 */ /* Implicit conversion from a pointer to object type to a pointer to void */
   /* These functions are auto-generated by System Desk. */
   /* Copy the data of the RAM block to its corresponding NVM block  */
   Rte_Call_pclNvmServicesAecBlock_GetErrorStatus(&u8NvmBlockStatus);

   if (NVM_REQ_PENDING != u8NvmBlockStatus)
   {
      Result = Rte_Call_pclNvmServicesAecBlock_WriteBlock(&NVP_BLOCK_ID_AEC_STATUS_RamBlockData);
   }
   else
   {
      /* QAC */
   }

   return Result;
}



#define ERH_AC_ErrorHandler_STOP_SEC_CODE
#include "ERH_AC_ErrorHandler_MemMap.h"
#pragma optimize restore
/******************************************************************************
End Of File
 *****************************************************************************/

/*************************************************************************

 AUTOLIV ELECTRONIC document.

 -------------------------------------

 DUPLICATION or DISCLOSURE PROHIBITED without prior written consent

 **************************************************************************

COMPONENT DemIf

Current revision: $Revision: 1.1 $
Checked in:       $Date: 2021/10/04 07:14:25CEST $

 **************************************************************************


Overview of the component :
   Part of DemIf module

------------------------------------------------------------------------

Design document:
<Document reference>

 *************************************************************************/

/*************************************************************************
Packages inclusion
 *************************************************************************/
#include "common.h"
#include "Dem.h"
#include <Std_Types.h>
#include "ERH_public.h"
#include "Crc.h"
#include "NvM.h"
#include "BswM_Callouts.h"
#include "Dem_Callouts.h"
#include "Nvp_Generated.h"

/******************************************************************************
MODULE DEFINES
******************************************************************************/
#define ERH_KU8_AEC_QUALIFIED_STATUS_MASK 1U
#define ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK 2U
#define ERH_KU8_AEC_EVER_TESTED_STATUS_MASK 4U
#define ERH_KU8_AEC_IN_PROGRESS_STATUS_MASK 8U
#define ERH_KU8_AEC_FAILED_AT_LEAST_ONCE_MASK 16U
#define KU8_AEC_PASSED 1u
#define KU8_AEC_FAILED 0u

#define DEMIF_INIT_NOT_STARTED 0u
#define DEMIF_INIT_STARTED 1u
#define DEMIF_INIT_PREVIOUS_AEC_STATUS KU16_MAX

#define KU8_DTC_INIT_STATUS ((uint8)0x40)

#define KU16_DEMIF_CRC32_INIT_LEN ((uint16)256u)
#define KU8_DEMIF_LOGICAL_BLOCK_BOOTLOADER ((uint8)0u)
#define KU8_DEMIF_LOGICAL_BLOCK_APPLICATION ((uint8)1u)
#define KU8_DEMIF_LOGICAL_BLOCK_CALIBRATION ((uint8)2u)
#define KU8_DEMIF_LOGICAL_BLOCK_INT_VECT_APPLICATION ((uint8)3u)
#define KU8_DEMIF_LOGICAL_BLOCK_DEFAULT ((uint8)4u)
#define KU8_DEMIF_LOGICAL_BLOCK_POS_APPLICATION ((uint8)0u)
#define KU8_DEMIF_LOGICAL_BLOCK_POS_CALIBRATION ((uint8)1u)
#define KU8_DEMIF_NO_OF_LOGICAL_BLOCKS ((uint8)2u)
#define KU32_DEMIF_CRC32_START_VALUE ((uint32)0xFFFFFFFFUL)

/******************************************************************************
MODULE TYPES
******************************************************************************/

/******************************************************************************
DECLARATION OF LOCAL FUNCTIONS
******************************************************************************/

#define DEM_START_SEC_VAR_INIT_UNSPECIFIED
#include <Dem_MemMap.h>
/******************************************************************************
DEFINITION OF LOCAL VARIABLES
******************************************************************************/
LOCAL uint32 u32TempCrcVal = 0u;
LOCAL uint32 u32CurrentCrcAddr;
LOCAL uint32 u32CurrentCrcSize = KU16_DEMIF_CRC32_INIT_LEN;
LOCAL uint32 u32RemainingCrcSize;
LOCAL boolean bCrcStarted = FALSE;
LOCAL uint8 u8CurrentLogicalBlock = KU8_DEMIF_LOGICAL_BLOCK_INT_VECT_APPLICATION;
LOCAL boolean b8InitCrc = FALSE;
LOCAL uint32 u32CrcArray[KU8_DEMIF_NO_OF_LOGICAL_BLOCKS];
LOCAL boolean bLastCrc = FALSE;
LOCAL boolean bFinalBlock = FALSE;

LOCAL uint8 u8DemInitState;

LOCAL uint8 DemIf_EventStatus[ERH_KU8_NUMBER_OF_AEC] = {
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
      {KU8_DTC_INIT_STATUS},
};

LOCAL uint16 DemIf_PreviousEventStatus[ERH_KU8_NUMBER_OF_AEC] = {
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
      {DEMIF_INIT_PREVIOUS_AEC_STATUS},
};

/******************************************************************************
DEFINITION OF EXPORTED VARIABLES
******************************************************************************/
#define DEM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <Dem_MemMap.h>


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
LOCAL void DemIf_UpdateApplicationCrc(void);

/******************************************************************************
DEFINITION OF APIs
******************************************************************************/
#define DEM_START_SEC_CODE
#include <Dem_MemMap.h>
/*!****************************************************************************
* @details
*     PreInit call
* @param[in]
*     ConfigPtr configuration pointer
* @return
*     none
* @invocation_criteria
*     called before every other Autosar call
******************************************************************************/
/*COVERS: DSG_DemIf_00002, */
void Dem_PreInit(Dem_ConfigType const * ConfigPtr)
{
   u8DemInitState = DEMIF_INIT_NOT_STARTED;
}

/*!****************************************************************************
* @details
*     Call after Nvm was read
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     Init
******************************************************************************/
/*COVERS: DSG_DemIf_00001, */
void Dem_Init(void)
{
   uint8 u8Idx;
   u8DemInitState = DEMIF_INIT_STARTED;

   for(u8Idx = 0u; u8Idx < ERH_KU8_NUMBER_OF_AEC; u8Idx++)
   {
      if (DEMIF_INIT_PREVIOUS_AEC_STATUS != DemIf_PreviousEventStatus[u8Idx])
      {
         Dem_ReportErrorStatus(DemIf_PreviousEventStatus[u8Idx], DEM_EVENT_STATUS_FAILED);
         DemIf_PreviousEventStatus[u8Idx] = DEMIF_INIT_PREVIOUS_AEC_STATUS;
      }
   }
}

/*!****************************************************************************
* @details
*     Stub call
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
void Dem_Shutdown(void)
{
}

/*!****************************************************************************
* @details
*     Queues the reported events from the BSW modules (API is only used by BSW modules).
* The interface has an asynchronous behavior, because the processing of the event is done within the Dem main function.
* @param[in]
*     EventId Identification of an event by assigned Event ID.
* @param[in]
*     EventStatus Monitor test result
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
/*COVERS: DSG_DemIf_00003, */
void Dem_ReportErrorStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
   if(u8DemInitState == DEMIF_INIT_STARTED)
   {
      if((EventStatus == DEM_EVENT_STATUS_PASSED) || (EventStatus == DEM_EVENT_STATUS_PREPASSED))
      {
         ERH_runSetAecEvent(EventId, KU8_AEC_PASSED);
      }
      else if((EventStatus == DEM_EVENT_STATUS_FAILED) || (EventStatus == DEM_EVENT_STATUS_PREFAILED))
      {
         ERH_runSetAecEvent(EventId, KU8_AEC_FAILED);
      }
      else
      {
         /* case DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED - nothing to do */
      }
   }
   else
   {
      if((EventStatus == DEM_EVENT_STATUS_FAILED) || (EventStatus == DEM_EVENT_STATUS_PREFAILED))
      {
         DemIf_PreviousEventStatus[EventId] = EventId;
      }
   }
}


/*!****************************************************************************
* @details
*     Processes the events reported by SW-Cs via RTE. This API can only be used through the RTE
* @param[in]
*     EventId Identification of an event by assigned EventId.
* @param[in]
*     EventStatus Monitor test result
* @return
*     E_OK: set of event status was successful
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
/*COVERS: DSG_DemIf_00004, */
Std_ReturnType Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
  Std_ReturnType result = E_OK;

  if(u8DemInitState == DEMIF_INIT_STARTED)
  {
     if((EventStatus == DEM_EVENT_STATUS_PASSED) || (EventStatus == DEM_EVENT_STATUS_PREPASSED))
     {
        ERH_runSetAecEvent(EventId, KU8_AEC_PASSED);
     }
     else if((EventStatus == DEM_EVENT_STATUS_FAILED) || (EventStatus == DEM_EVENT_STATUS_PREFAILED))
     {
        ERH_runSetAecEvent(EventId, KU8_AEC_FAILED);
     }
     else
     {
        /* case DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED - nothing to do */
     }
  }

  return result;
}

/*!****************************************************************************
* @details
*     Stub function
* @param[in]
*     OperationCycleId stub parameter
* @param[in]
*     CycleState stub parameter
* @return
*     E_OK always
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
Std_ReturnType Dem_SetOperationCycleState(Dem_OperationCycleIdType OperationCycleId, Dem_OperationCycleStateType CycleState)
{
  return E_OK;
}

/*!****************************************************************************
* @details
*     Gets the current extended event status of an event.
* @param[in]
*     EventId Identification of an event by assigned EventId.
* @param[out]
*     EventStatusExtended UDS DTC status byte of the requested event
* @return
*     E_OK always
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
/*COVERS: DSG_DemIf_00005, */
Std_ReturnType Dem_GetEventStatus(Dem_EventIdType EventId, Dem_EventStatusExtendedType* EventStatusExtended)
{
   u8AecStatusType u8Status;

   if(u8DemInitState == DEMIF_INIT_STARTED)
   {
      ERH_runGetAecStatus(EventId, &u8Status);

      if((u8Status & ERH_KU8_AEC_QUALIFIED_STATUS_MASK) != 0u)
      {
         DemIf_EventStatus[EventId] |= DEM_UDS_STATUS_TF;
         DemIf_EventStatus[EventId] |= DEM_UDS_STATUS_TFTOC;
         DemIf_EventStatus[EventId] |= DEM_UDS_STATUS_CDTC;
         DemIf_EventStatus[EventId] |= DEM_UDS_STATUS_PDTC;
         DemIf_EventStatus[EventId] |= DEM_UDS_STATUS_TFSLC;
      }
      else
      {
         DemIf_EventStatus[EventId] &= ~DEM_UDS_STATUS_TF;
      }

      if((u8Status & ERH_KU8_AEC_EVER_QUALIFIED_STATUS_MASK) != 0u)
      {
         DemIf_EventStatus[EventId] |= DEM_UDS_STATUS_TFSLC;
      }

      if((u8Status & ERH_KU8_AEC_EVER_TESTED_STATUS_MASK) != 0u)
      {
         DemIf_EventStatus[EventId] &= ~DEM_UDS_STATUS_TNCTOC;
      }

      if((u8Status & ERH_KU8_AEC_IN_PROGRESS_STATUS_MASK) != 0u)
      {
         /* no equal value in DEM */
      }

      if((u8Status & ERH_KU8_AEC_FAILED_AT_LEAST_ONCE_MASK) != 0u)
      {
         /* no equal value in DEM */
      }

      *EventStatusExtended = DemIf_EventStatus[EventId];
   }

   return E_OK;
}

/*!****************************************************************************
* @details
*     Clears all DTCs.
* @param[in]
*     DTC stub parameter
* @param[in]
*     DTCFormat stub parameter
* @param[in]
*     DTCOrigin stub parameter
* @return
*     DEM_CLEAR_OK always
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
Dem_ReturnClearDTCType Dem_ASR42_ClearDTC(Dem_DTCType DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin)
{
  uint8 u8Idx = 0u;

  for(u8Idx = 0u; u8Idx < ERH_KU8_NUMBER_OF_AEC; u8Idx++)
  {
     DemIf_EventStatus[u8Idx] = KU8_DTC_INIT_STATUS;
  }

  return DEM_CLEAR_OK;
}

/*!****************************************************************************
* @details
*     Processes all not event based Dem internal functions.
* @return
*     none
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
/*COVERS: DSG_DemIf_00006, */
void Dem_MainFunction(void)
{
   ERH_runStoreEverQualifiedAECsToNVP();
   DemIf_UpdateApplicationCrc();
}

/*!****************************************************************************
* @details
*     Stub function
* @param[in]
*     DTCGroup stub parameter
* @param[in]
*     Dem_DTCKindType stub parameter
* @return
*     DEM_CONTROL_DTC_SETTING_OK always
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
/*COVERS: DSG_DemIf_00007, */
Dem_ReturnControlDTCSettingType Dem_EnableDTCSetting(Dem_DTCGroupType DTCGroup,  Dem_DTCKindType  DTCKind)
{
   return DEM_CONTROL_DTC_SETTING_OK;
}

/*!****************************************************************************
* @details
*     Stub function
* @param[in]
*     DTCGroup stub parameter
* @param[in]
*     Dem_DTCKindType stub parameter
* @return
*     DEM_CONTROL_DTC_SETTING_OK always
* @constraints
*     <>
* @invocation_criteria
*     <>
******************************************************************************/
/*COVERS: DSG_DemIf_00008, */
Dem_ReturnControlDTCSettingType Dem_DisableDTCSetting(Dem_DTCGroupType DTCGroup, Dem_DTCKindType  DTCKind)
{
   return DEM_CONTROL_DTC_SETTING_OK;
}

LOCAL void DemIf_UpdateApplicationCrc(void)
{

   if (((NVP_au8Crc[KU8_FOUR] == KU8_MAX)  &&
        (NVP_au8Crc[KU8_FIVE] == KU8_MAX)  &&
        (NVP_au8Crc[KU8_SIX] == KU8_MAX)  &&
        (NVP_au8Crc[KU8_SEVEN] == KU8_MAX))
        ||
       ((NVP_au8Crc[KU8_EIGHT] == KU8_MAX)  &&
        (NVP_au8Crc[KU8_NINE] == KU8_MAX)  &&
        (NVP_au8Crc[KU8_TEN] == KU8_MAX) &&
        (NVP_au8Crc[KU8_ELEVEN] == KU8_MAX))
        ||
        (bswmIf_bUpdateCrc == B_TRUE))
   {
      switch(u8CurrentLogicalBlock)
      {
         case KU8_DEMIF_LOGICAL_BLOCK_INT_VECT_APPLICATION:
         {
            if (bFinalBlock == TRUE)
            {
               u32CrcArray[KU8_DEMIF_LOGICAL_BLOCK_POS_APPLICATION] = u32TempCrcVal;
               u8CurrentLogicalBlock = KU8_DEMIF_LOGICAL_BLOCK_DEFAULT;
               bFinalBlock = FALSE;
            }
            else if (bCrcStarted == FALSE)
            {
               u32CurrentCrcSize = KU16_DEMIF_CRC32_INIT_LEN;
               u32CurrentCrcAddr = (uint32)&_ApplIntVect_Start;
               u32RemainingCrcSize = (uint32)&_ApplIntVect_Size;
               u32TempCrcVal = KU32_DEMIF_CRC32_START_VALUE;
               b8InitCrc = TRUE;
               bCrcStarted = TRUE;
            }
            else
            {
               /* do nothing */
            }

            break;
         }

         case KU8_DEMIF_LOGICAL_BLOCK_DEFAULT:
         {
            if (bFinalBlock == TRUE)
            {
               u32CrcArray[KU8_DEMIF_LOGICAL_BLOCK_POS_APPLICATION] = u32TempCrcVal;
               u8CurrentLogicalBlock = KU8_DEMIF_LOGICAL_BLOCK_APPLICATION;
               bFinalBlock = FALSE;
            }
            else if (bCrcStarted == FALSE)
            {
               u32CurrentCrcSize = KU16_DEMIF_CRC32_INIT_LEN;
               u32CurrentCrcAddr = (uint32)&_EEP_Def_Start;
               u32RemainingCrcSize = (uint32)&_EEP_Def_Size;
               u32TempCrcVal = u32CrcArray[KU8_DEMIF_LOGICAL_BLOCK_POS_APPLICATION];
               b8InitCrc = FALSE;
               bCrcStarted = TRUE;
            }
            else
            {
               /* do nothing */
            }

            break;
         }

         case KU8_DEMIF_LOGICAL_BLOCK_APPLICATION:
         {
            if (bFinalBlock == TRUE)
            {
               u32CrcArray[KU8_DEMIF_LOGICAL_BLOCK_POS_APPLICATION] = u32TempCrcVal;
               u8CurrentLogicalBlock = KU8_DEMIF_LOGICAL_BLOCK_CALIBRATION;
               bFinalBlock = FALSE;
            }
            else if (bCrcStarted == FALSE)
            {
               u32CurrentCrcSize = KU16_DEMIF_CRC32_INIT_LEN;
               u32CurrentCrcAddr = (uint32)&_Appl_Start;
               u32RemainingCrcSize = (uint32)&_Appl_Size;
               u32TempCrcVal = u32CrcArray[KU8_DEMIF_LOGICAL_BLOCK_POS_APPLICATION];
               b8InitCrc = FALSE;
               bCrcStarted = TRUE;
            }
            else
            {
               /* do nothing */
            }

            break;
         }

         case KU8_DEMIF_LOGICAL_BLOCK_CALIBRATION:
         {
            if (bFinalBlock == TRUE)
            {
               u32CrcArray[KU8_DEMIF_LOGICAL_BLOCK_POS_CALIBRATION] = u32TempCrcVal;
               u8CurrentLogicalBlock = KU8_DEMIF_LOGICAL_BLOCK_INT_VECT_APPLICATION;
               bFinalBlock = FALSE;
               bLastCrc = TRUE;
            }
            else if (bCrcStarted == FALSE)
            {
               u32CurrentCrcSize = KU16_DEMIF_CRC32_INIT_LEN;
               u32CurrentCrcAddr = (uint32)&_Calib_Start;
               u32RemainingCrcSize = (uint32)&_Calib_Size;
               u32TempCrcVal = KU32_DEMIF_CRC32_START_VALUE;
               b8InitCrc = TRUE;
               bCrcStarted = TRUE;
            }
            else
            {
               /* do nothing */
            }

            break;
         }

         default:
         {
            break;
         }
      }

      if (bCrcStarted == TRUE)
      {
         if(u32RemainingCrcSize <= u32CurrentCrcSize)
         {
            /* Invalid length remaining */
            u32CurrentCrcSize = u32RemainingCrcSize;
            bCrcStarted = FALSE;
            bFinalBlock = TRUE;
         }

         u32TempCrcVal = Crc_CalculateCRC32
               (
                     (const uint8 *)u32CurrentCrcAddr,
                     u32CurrentCrcSize,
                     u32TempCrcVal,
                     b8InitCrc
               );

         b8InitCrc = FALSE;

         u32CurrentCrcAddr += u32CurrentCrcSize;
         if(u32CurrentCrcSize != u32RemainingCrcSize)
         {
            u32RemainingCrcSize -= u32CurrentCrcSize;
         }
         else
         {
            u32RemainingCrcSize = 0u;
         }
      }

      if(bLastCrc == TRUE)
      {
         NVP_au8Crc[KU8_FOUR] = U32_GET_HIGH_BYTE(u32CrcArray[KU8_DEMIF_LOGICAL_BLOCK_POS_APPLICATION]);
         NVP_au8Crc[KU8_FIVE] = U32_GET_HIGH_MIDDLE_BYTE(u32CrcArray[KU8_DEMIF_LOGICAL_BLOCK_POS_APPLICATION]);
         NVP_au8Crc[KU8_SIX] = U32_GET_LOW_MIDDLE_BYTE(u32CrcArray[KU8_DEMIF_LOGICAL_BLOCK_POS_APPLICATION]);
         NVP_au8Crc[KU8_SEVEN] = U32_GET_LOW_BYTE(u32CrcArray[KU8_DEMIF_LOGICAL_BLOCK_POS_APPLICATION]);

         NVP_au8Crc[KU8_EIGHT] =  U32_GET_HIGH_BYTE(u32CrcArray[KU8_DEMIF_LOGICAL_BLOCK_POS_CALIBRATION]);
         NVP_au8Crc[KU8_NINE] =  U32_GET_HIGH_MIDDLE_BYTE(u32CrcArray[KU8_DEMIF_LOGICAL_BLOCK_POS_CALIBRATION]);
         NVP_au8Crc[KU8_TEN] = U32_GET_LOW_MIDDLE_BYTE(u32CrcArray[KU8_DEMIF_LOGICAL_BLOCK_POS_CALIBRATION]);
         NVP_au8Crc[KU8_ELEVEN] = U32_GET_LOW_BYTE(u32CrcArray[KU8_DEMIF_LOGICAL_BLOCK_POS_CALIBRATION]);

         (void) NvM_SetRamBlockStatus(NvMConf_NvMBlockDescriptor_NVM_BLOCK_CRC, TRUE);

         bLastCrc = FALSE;
         bswmIf_bUpdateCrc = B_FALSE;
      }
   }
}

#define DEM_STOP_SEC_CODE
#include <Dem_MemMap.h>
/*************************************************************************
Evolution of the component

Created by : F.GILBERT

$Log: DemIf.c  $
Revision 1.1 2021/10/04 07:14:25CEST Lucian Ardeleanu (lucian.ardeleanu) 
Initial revision
Member added to project e:/MKSProjects/SBE/Exploration/Python_Workspace/Automate_line_number_script/Executables/source_files/project.pj
Revision 1.17 2021/08/02 15:24:26EEST Razvan Badiu (razvan.badiu) 
fix app crc
Revision 1.16 2021/07/19 12:12:22EEST Dan Dustinta (dan.dustinta) 
update QAC
Revision 1.15 2021/07/19 10:16:55EEST Dan Dustinta (dan.dustinta) 
add UNECE RID 0x0544 Parameters
Revision 1.14 2021/07/16 16:37:31EEST Dan Dustinta (dan.dustinta) 
add UNECE implementation
Revision 1.13 2020/12/17 09:48:52EET Dan Nitulescu (dan.nitulescu) 
QAC corrections DemIf
End Of File
*****************************************************************************/

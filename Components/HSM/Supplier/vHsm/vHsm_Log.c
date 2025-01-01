/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  vHsm_Log.c
 *        \brief  Vector Hardware Security Module Firmware (vHsm)
 *
 *      \details  Provides an implemenation for loggin events inside HSM which can be exported to the application.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#define VHSM_LOG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "vHsm.h"
#include "vHsm_Log.h"
#include "vstdlib.h"
#include "vHsm_Trace.h"
#include "vHsm_Nvm.h"

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (VHSM_LOCAL) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL                                                   static
#endif

#if !defined (VHSM_LOCAL_INLINE) /* COV_VHSM_LOCAL_DEFINE */
# define VHSM_LOCAL_INLINE                                            LOCAL_INLINE
#endif

#define LOG_MNGT_SIZE                                                 sizeof(vHsm_Log_MngtType)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define VHSM_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (VHSM_LOG == STD_ON)

# if(VHSM_NVBLOCKDESCRIPTOROFLOGEVENT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Log_AddEntry_Persist()
 *********************************************************************************************************************/
/*!\brief       Persist the event
 * \details     -
 * \param[in]   logEventId            Id of the event
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Log_AddEntry_Persist(uint32 logEventId);
# endif

/**********************************************************************************************************************
 *  vHsm_Log_AddEntry_Counter()
 *********************************************************************************************************************/
/*!\brief       Write the current counter value to the event
 * \details     -
 * \param[in]     logEventId            Id of the event
 * \param[in,out] offset                Offset which will be used to write the data. Before returning the offset set to the new value
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Log_AddEntry_Counter(
  uint32 logEventId,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) offset);

/**********************************************************************************************************************
 *  vHsm_Log_AddEntry_Data()
 *********************************************************************************************************************/
/*!\brief       Write the provided data to the event
 * \details     -
 * \param[in]     logEventId            Id of the event
 * \param[in,out] offset                Offset which will be used to write the data. Before returning the offset set to the new value
 * \param[in]     dataPtr               Pointer to the data
 * \param[in]     dataLength            Length of the provided data
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Log_AddEntry_Data(
  uint32 logEventId,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) offset,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) dataPtr,
  uint32 dataLength);

/**********************************************************************************************************************
 *  vHsm_Log_AddEntry_Timestamp()
 *********************************************************************************************************************/
/*!\brief       Get the current timestamp with a callout and write it to the event
 * \details     -
 * \param[in]     logEventId            Id of the event
 * \param[in,out] offset                Offset which will be used to write the data. Before returning the offset set to the new value
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Log_AddEntry_Timestamp(
  uint32 logEventId,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) offset);

/**********************************************************************************************************************
 *  vHsm_Log_AddEntry_EventCallout()
 *********************************************************************************************************************/
/*!\brief       Call the callout to indicate the occurrence of the event if it is configured
 * \details     -
 * \param[in]     logEventId            Id of the event
 * \param[in,out] offset                Offset which will be used to write the data. Before returning the offset set to the new value
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Log_AddEntry_EventCallout(
  uint32 logEventId);

/**********************************************************************************************************************
 *  vHsm_Log_GetEntry_ExportAll()
 *********************************************************************************************************************/
/*!\brief       Do basic checks for export all operations and compute necessary values
 * \details     -
 * \param[in]     logEventId            Id of the event
 * \param[in,out] dataToCopyPtr         Pointer to the number of data to write
 * \param[in,out] bufferLengthPtr       Pointer to the size of the buffer
 * \param[out]    overflowCounterPtr    Pointer to the overflowcounter
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Log_GetEntry_ExportAll(
  uint32 logEventId,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) dataToCopyPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) bufferLengthPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) overflowCounterPtr);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
# if(VHSM_NVBLOCKDESCRIPTOROFLOGEVENT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Log_AddEntry_Persist()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(Std_ReturnType, VHSM_CODE) vHsm_Log_AddEntry_Persist(uint32 logEventId)
{
  Std_ReturnType retVal;
  switch (vHsm_GetNvProcessingOfLogEvent(logEventId))
  {
  case VHSM_NV_PROCESSING_NONE:
    /* #20 Do not persist the element */
    retVal = E_OK;
    /* Nothing to do */
    break;
  case VHSM_NV_PROCESSING_IMMEDIATE:
    /* #21 Persist the event immediately */
    retVal = NvM_SetRamBlockStatus((NvM_BlockIdType)vHsm_GetNvBlockDescriptorOfLogEvent(logEventId), TRUE);
    retVal |= vHsm_Api_NvM_WriteBlock((NvM_BlockIdType)vHsm_GetNvBlockDescriptorOfLogEvent(logEventId), NULL_PTR);
    break;
  case VHSM_NV_PROCESSING_DEFERRED:
    /* #22 Persist the event deferred */
    retVal = NvM_SetRamBlockStatus((NvM_BlockIdType)vHsm_GetNvBlockDescriptorOfLogEvent(logEventId), TRUE);
    break;
  default: /* COV_VHSM_CASE_DEFAULT */
    retVal = E_NOT_OK;
    break;
  }
  return retVal;
}
# endif

/**********************************************************************************************************************
 *  vHsm_Log_AddEntry_Counter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Log_AddEntry_Counter(
  uint32 logEventId,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) offset)
{
  /* #10 Check if option is enabled */
  if (vHsm_GetCounterSizeOfLogEvent(logEventId) != 0u)
  {
    /* #20 Store the current counter value to the event */
    switch (vHsm_GetCounterSizeOfLogEvent(logEventId))
    {
    case sizeof(uint8) :
      *vHsm_Log_GetMemory(logEventId, *offset) = (uint8)vHsm_Log_GetCounter(logEventId);
      break;
    case sizeof(uint16) :
      *vHsm_Log_GetMemory(logEventId, *offset) = (uint8)vHsm_Log_GetCounter(logEventId);
      *vHsm_Log_GetMemory(logEventId, *offset + 1u) = (uint8)((vHsm_Log_GetCounter(logEventId) & 0x0000FF00u) >> 8u);
      break;
    case sizeof(uint32) :
      *vHsm_Log_GetMemory(logEventId, *offset) = (uint8)vHsm_Log_GetCounter(logEventId);
      *vHsm_Log_GetMemory(logEventId, *offset + 1u) = (uint8)((vHsm_Log_GetCounter(logEventId) & 0x0000FF00u) >> 8u);
      *vHsm_Log_GetMemory(logEventId, *offset + 2u) = (uint8)((vHsm_Log_GetCounter(logEventId) & 0x00FF0000u) >> 16u);
      *vHsm_Log_GetMemory(logEventId, *offset + 3u) = (uint8)((vHsm_Log_GetCounter(logEventId) & 0xFF000000u) >> 24u);
      break;
    default: /* COV_VHSM_CASE_DEFAULT */
      break;
    }
    *offset += vHsm_GetCounterSizeOfLogEvent(logEventId);
  }
}

/**********************************************************************************************************************
 *  vHsm_Log_AddEntry_Data()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Log_AddEntry_Data(
  uint32 logEventId,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) offset,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) dataPtr,
  uint32 dataLength)
{
  /* #10 Check if option is enabled */
  if (vHsm_GetDataSizeOfLogEvent(logEventId) != 0u)
  {
    /* #20 Store the provided data to the event */
    VStdMemCpy(vHsm_Log_GetMemory(logEventId, *offset), dataPtr, dataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    *offset += dataLength;
    VStdMemClr(vHsm_Log_GetMemory(logEventId, *offset), vHsm_GetDataSizeOfLogEvent(logEventId) - dataLength); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
    *offset += vHsm_GetDataSizeOfLogEvent(logEventId) - dataLength;
  }
}

/**********************************************************************************************************************
 *  vHsm_Log_AddEntry_Timestamp()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL_INLINE FUNC(void, VHSM_CODE) vHsm_Log_AddEntry_Timestamp(
  uint32 logEventId,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) offset)
{
  /* #10 Check if option is enabled */
  if (vHsm_GetTimestampSizeOfLogEvent(logEventId) != 0u)
  {
    /* #20 Call timestamp callout to get the current timestamp */
# if (VHSM_LOG_TIMESTAMP_CALLOUT_ENABLED == STD_ON)
    uint32 length = vHsm_GetTimestampSizeOfLogEvent(logEventId);
    vHsm_Log_GetTimestamp_Callout(logEventId, vHsm_Log_GetMemory(logEventId, *offset), &length);

    /* Pad with zero if not enough data was written */
    VStdMemSet(vHsm_Log_GetMemory(logEventId, *offset + length), 0x00, vHsm_GetTimestampSizeOfLogEvent(logEventId)-length); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
# endif
    *offset += vHsm_GetTimestampSizeOfLogEvent(logEventId);
  }
}

/**********************************************************************************************************************
 *  vHsm_Log_AddEntry_EventCallout()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
VHSM_LOCAL FUNC(void, VHSM_CODE) vHsm_Log_AddEntry_EventCallout(
  uint32 logEventId)
{
  /* #10 Check if option is enabled */
  if (vHsm_IsEventCalloutOfLogEvent(logEventId) == TRUE)
  {
# if (VHSM_LOG_EVENT_CALLOUT_ENABLED == STD_ON)
    /* #20 Call the user callout */
    vHsm_Log_Event_Callout(logEventId);
# endif
  }
}

/**********************************************************************************************************************
 *  vHsm_Log_GetEntry_ExportAll()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
VHSM_LOCAL FUNC(Std_ReturnType, VHSM_CODE) vHsm_Log_GetEntry_ExportAll(
  uint32 logEventId,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) dataToCopyPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) bufferLengthPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) overflowCounterPtr)
{
  Std_ReturnType retVal;

  /* #10 Check for empty log */
  if (vHsm_Log_GetCounter(logEventId) == 0u)
  {
    *bufferLengthPtr = 0u;
    retVal = E_OK;
  }
  else
  {
    /* #20 Calculate overflow counter */
    *overflowCounterPtr = (vHsm_Log_GetCounter(logEventId) % vHsm_GetMaxEntriesOfLogEvent(logEventId));
    if (*overflowCounterPtr == 0u)
    {
      *overflowCounterPtr = vHsm_GetMaxEntriesOfLogEvent(logEventId);
    }

    /* #30 Calculate data size for the output */
    if (vHsm_Log_GetCounter(logEventId) < vHsm_GetMaxEntriesOfLogEvent(logEventId))
    {
      *dataToCopyPtr = (vHsm_Log_GetMaxEntrySize(logEventId))*(vHsm_Log_GetCounter(logEventId));
    }
    else
    {
      *dataToCopyPtr = (vHsm_Log_GetMaxEntrySize(logEventId))*(vHsm_GetMaxEntriesOfLogEvent(logEventId));
    }

    /* #40 Check for too small buffer */
    if (*bufferLengthPtr < *dataToCopyPtr)
    {
      retVal = CRYPTO_E_SMALL_BUFFER;
    }
    else
    {
      retVal = E_OK;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  vHsm_Log_AddEntry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Log_AddEntry(
  uint32 logEventId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) dataPtr,
  uint32 dataLength)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint32 offset;

  /* #10 Check for valid logEventId */
  if (logEventId >= vHsm_GetSizeOfLogEvent())
  {
    /* retVal already set */
  }
  /* #11 Check for valid pointer */
  else if (dataPtr == NULL_PTR)
  {
    /* retVal already set */
  }
  /* #12 Check for valid length */
  else if (dataLength > vHsm_GetDataSizeOfLogEvent(logEventId))
  {
    /* retVal already set */
  }
  else
  {
    boolean alreadyFull = FALSE;

    retVal = E_OK;

    /* #13 Check for event counter overflow */
    if ((vHsm_GetCounterSizeOfLogEvent(logEventId) != 0u)
      && (vHsm_Log_GetCounter(logEventId) >= vHsm_Log_GetMaxCounterValue(logEventId)))
    {
      vHsm_Trace(VHSM_TRACE_INFO, "Log is already full (%i of %i)\r\n", vHsm_Log_GetCounter(logEventId), vHsm_Log_GetMaxCounterValue(logEventId));
      /* Log is full (Counter is at max) */
      alreadyFull = TRUE;
    }
    /* #14 Check for log counter overflow */
    else if ((vHsm_GetCounterSizeOfLogEvent(logEventId) == 0u)
      && (vHsm_Log_GetCounter(logEventId) >= 0xFFFFFFFFuL))
    {
      vHsm_Trace(VHSM_TRACE_INFO, "Log is already full (%i of %i)\r\n", vHsm_Log_GetCounter(logEventId), vHsm_Log_GetMaxCounterValue(logEventId));
      /* Log is full (Counter is at max) */
      alreadyFull = TRUE;
    }
    else
    {
      /* #20 Increment counter */
      vHsm_Log_GetCounter(logEventId) += 1u;
    }

    if ((vHsm_IsDiscardWhenFullOfLogEvent(logEventId) == TRUE)
      && (alreadyFull == TRUE))
    {
      /* Only call the callout if configured as nothing else is to be done */
      vHsm_Log_AddEntry_EventCallout(logEventId); /*lint !e522 */
    }
    else
    {
      /* #21 Check if at least one element can be stored */
      if (vHsm_Log_GetMaxEntrySize(logEventId) != 0u)
      {
        /* #30 Calculate the offset used to store the new event */
        if (vHsm_Log_GetOffset(logEventId) == 0u)
        {
          vHsm_Log_GetOffset(logEventId) = LOG_MNGT_SIZE;
        }
        offset = (((vHsm_Log_GetOffset(logEventId) - (uint32)LOG_MNGT_SIZE) % ((vHsm_Log_GetMaxEntrySize(logEventId))*vHsm_GetMaxEntriesOfLogEvent(logEventId))) + (uint32)LOG_MNGT_SIZE);

        /* #31 Handle the event counter */
        vHsm_Log_AddEntry_Counter(logEventId, &offset);

        /* #32 Handle event data */
        vHsm_Log_AddEntry_Data(logEventId, &offset, dataPtr, dataLength);

        /* #33 Handle event timestamp */
        vHsm_Log_AddEntry_Timestamp(logEventId, &offset);

        /* #34 Set new offset */
        vHsm_Log_GetOffset(logEventId) = offset;

        /* #35 Handle user callout */
        /* Call the user callout at the end. This way, it can read the last entry and see what happened. */
        vHsm_Log_AddEntry_EventCallout(logEventId); /*lint !e522 */

        /* #36 Check if fill level callout shall be called */
        if ((vHsm_GetFillLevelThresholdOfLogEvent(logEventId) != 0u)
          && (vHsm_GetFillLevelThresholdOfLogEvent(logEventId) <= (vHsm_FillLevelThresholdOfLogEventType)((vHsm_Log_GetCounter(logEventId) * 100u) / vHsm_GetMaxEntriesOfLogEvent(logEventId)))
          && (vHsm_Log_GetCounter(logEventId) <= vHsm_GetMaxEntriesOfLogEvent(logEventId)))
        {
# if(VHSM_LOG_THRESHOLD_CALLOUT_ENABLED == STD_ON)
          vHsm_Log_FillLevelThreshold_Callout(logEventId);
# endif
        }

# if(VHSM_NVBLOCKDESCRIPTOROFLOGEVENT == STD_ON)
        /* #40 Perform persisting */
        retVal = vHsm_Log_AddEntry_Persist(logEventId);
# endif
      }
      else
      {
        /* #50 Only call the callout if configured as nothing else is to be done */
        vHsm_Log_AddEntry_EventCallout(logEventId); /*lint !e522 */
      }
    }
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsm_Log_GetEntry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Log_GetEntry(
  uint32 logEventId,
  uint32 exportStrategy,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) dataPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) dataLengthPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint32 offset = 0u;
  boolean alreadyHandled = FALSE;

  /* #10 Check for errors */
  if (logEventId >= vHsm_GetSizeOfLogEvent())
  {
    /* retVal already set */
  }
  else if (exportStrategy > VHSM_EXPORT_OLDEST)
  {
    /* retVal already set */
  }
  else if (dataLengthPtr == NULL_PTR)
  {
    /* retVal already set to E_NOT_OK */
  }
  else if (dataPtr == NULL_PTR)
  {
    /* retVal already set to E_NOT_OK */
  }
  else
  {
    uint32 dataToCopy = 0u;
    boolean checkAvailable = FALSE;

    /* #20 Decide what should be exported */
    switch (exportStrategy)
    {
    case VHSM_EXPORT_ALL_FILO:
    {
      uint32 overflowCounter;

      retVal = vHsm_Log_GetEntry_ExportAll(logEventId, &dataToCopy, dataLengthPtr, &overflowCounter);

      if ((retVal == E_OK)
        && (*dataLengthPtr != 0u))
      {
        uint32 i;
        uint32 outOffset = 0u;

        /* copy from newest to oldest */
        for (i = overflowCounter; i > 0u; i--)
        {
          VStdMemCpy(&dataPtr[outOffset], vHsm_Log_GetMemoryOfEntry(logEventId, (i - 1u)), vHsm_Log_GetMaxEntrySize(logEventId)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
          outOffset += vHsm_Log_GetMaxEntrySize(logEventId);
        }

        /* process not already overwritten data */
        if (vHsm_Log_GetCounter(logEventId) > vHsm_GetMaxEntriesOfLogEvent(logEventId))
        {
          for (i = vHsm_GetMaxEntriesOfLogEvent(logEventId); i > overflowCounter; i--)
          {
            VStdMemCpy(&dataPtr[outOffset], vHsm_Log_GetMemoryOfEntry(logEventId, (i - 1u)), vHsm_Log_GetMaxEntrySize(logEventId)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
            outOffset += vHsm_Log_GetMaxEntrySize(logEventId);
          }
        }

        *dataLengthPtr = dataToCopy;
        retVal = E_OK;
      }
      alreadyHandled = TRUE;
    }
    break;
    case VHSM_EXPORT_ALL_FIFO:
    {
      uint32 overflowCounter;

      retVal = vHsm_Log_GetEntry_ExportAll(logEventId, &dataToCopy, dataLengthPtr, &overflowCounter);

      if ((retVal == E_OK)
        && (*dataLengthPtr != 0u))
      {
        uint32 i;
        uint32 outOffset = 0u;

        /* process not already overwritten data */
        if (vHsm_Log_GetCounter(logEventId) > vHsm_GetMaxEntriesOfLogEvent(logEventId))
        {
          for (i = overflowCounter; i < vHsm_GetMaxEntriesOfLogEvent(logEventId); i++)
          {
            VStdMemCpy(&dataPtr[outOffset], vHsm_Log_GetMemoryOfEntry(logEventId, i), vHsm_Log_GetMaxEntrySize(logEventId)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
            outOffset += vHsm_Log_GetMaxEntrySize(logEventId);
          }
        }

        /* copy from newest to oldest */
        for (i = 0u; i < overflowCounter; i++)
        {
          VStdMemCpy(&dataPtr[outOffset], vHsm_Log_GetMemoryOfEntry(logEventId, i), vHsm_Log_GetMaxEntrySize(logEventId)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
          outOffset += vHsm_Log_GetMaxEntrySize(logEventId);
        }

        *dataLengthPtr = dataToCopy;
        retVal = E_OK;
      }
      alreadyHandled = TRUE;
    }
    break;
    case VHSM_EXPORT_LATEST:
      dataToCopy = vHsm_Log_GetMaxEntrySize(logEventId);
      offset = LOG_MNGT_SIZE;
      if (dataToCopy != 0u)
      {
        if ((vHsm_Log_GetOffset(logEventId) % ((vHsm_Log_GetMaxEntrySize(logEventId))*vHsm_GetMaxEntriesOfLogEvent(logEventId))) != LOG_MNGT_SIZE)
        {
          offset = vHsm_Log_GetOffset(logEventId) - vHsm_Log_GetMaxEntrySize(logEventId);
        }
      }
      checkAvailable = TRUE;
      break;
    case VHSM_EXPORT_NONE:
      /* dataToCopy is already none */
      break;
    case VHSM_EXPORT_OCCURRENCES:
      dataToCopy = sizeof(uint32);
      /* first 4 bytes contain the counter */
      offset = 0u;
      break;
    case VHSM_EXPORT_OLDEST:
      dataToCopy = vHsm_Log_GetMaxEntrySize(logEventId);
      if (vHsm_Log_GetCounter(logEventId) <= vHsm_GetMaxEntriesOfLogEvent(logEventId))
      {
        /* Not already overflowed. Use first entry */
        offset = LOG_MNGT_SIZE;
      }
      else
      {
        /* Already overflowed. Next entry points to the already written oldest one */
        offset = vHsm_Log_GetOffset(logEventId);
      }
      checkAvailable = TRUE;
      break;
    default: /* COV_VHSM_CASE_DEFAULT */
      break;
    }

    /* #30 Check if output has already been written */
    if (alreadyHandled == FALSE)
    {
      /* #35 Only output data when an entry is available */
      if ((checkAvailable == TRUE)
        && (vHsm_Log_GetCounter(logEventId) == 0u))
      {
        /* No entry to output */
        dataToCopy = 0u;
        *dataLengthPtr = 0u;
      }

      /* #36 Check if the buffer is big enough */
      if (*dataLengthPtr >= dataToCopy)
      {
        /* #40 Copy the output data */
        VStdMemCpy(dataPtr, vHsm_Log_GetMemory(logEventId, offset), dataToCopy); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
        *dataLengthPtr = dataToCopy;
        retVal = E_OK;
      }
      else
      {
        retVal = CRYPTO_E_SMALL_BUFFER;
      }
    }
  }

  return retVal;
} /* PRQA S 6010,6030,6080 */ /* MD_MSR_STPTH */ /* MD_MSR_STCYC */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  vHsm_Log_Reset()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Log_Reset(
  uint32 logEventId,
  boolean clearMemory,
  boolean persist)
{
  Std_ReturnType retVal = E_OK;

  /* #10 Clear counter */
  vHsm_Log_GetCounter(logEventId) = 0u;

  /* #11 Clear offset */
  vHsm_Log_GetOffset(logEventId) = 0u;

  /* #20 Clear memory if needed */
  if (clearMemory == TRUE)
  {
    VStdMemClr(vHsm_Log_GetMemory(logEventId, LOG_MNGT_SIZE), vHsm_Log_GetLogEventMemorySize(logEventId)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
  }

# if(VHSM_NVBLOCKDESCRIPTOROFLOGEVENT == STD_ON)
  /* #30 Persist if needed */
  if ((persist == TRUE)
    && (vHsm_GetNvProcessingOfLogEvent(logEventId) != VHSM_NV_PROCESSING_NONE))
  {
    retVal = NvM_SetRamBlockStatus((NvM_BlockIdType)vHsm_GetNvBlockDescriptorOfLogEvent(logEventId), TRUE);
    retVal |= vHsm_Api_NvM_WriteBlock((NvM_BlockIdType)vHsm_GetNvBlockDescriptorOfLogEvent(logEventId), NULL_PTR);
  }
# else
  VHSM_DUMMY_STATEMENT(persist); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
# endif

  return retVal;
}

# if(VHSM_NVBLOCKDESCRIPTOROFLOGEVENT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_LogEvent_NvBlockReadFromBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_LogEvent_NvBlockReadFromBlock(
  vHsm_SizeOfLogEventType blockIdx,
  P2CONST(void, AUTOMATIC, VHSM_APPL_DATA) NvMBuffer)
{
  uint32 logEventId = blockIdx;
  VStdMemCpy(vHsm_Log_GetMemory(logEventId, 0u), NvMBuffer, (uint32)(vHsm_Log_GetLogEventMemorySize(logEventId) + LOG_MNGT_SIZE)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
  return E_OK;
}

/**********************************************************************************************************************
 *  vHsm_LogEvent_NvBlockWriteToBlock()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_LogEvent_NvBlockWriteToBlock(
  vHsm_SizeOfLogEventType blockIdx,
  P2VAR(void, AUTOMATIC, VHSM_APPL_VAR) NvMBuffer)
{
  uint32 logEventId = blockIdx;
  VStdMemCpy(NvMBuffer, vHsm_Log_GetMemory(logEventId, 0u), (uint32)(vHsm_Log_GetLogEventMemorySize(logEventId) + LOG_MNGT_SIZE)); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */
  return E_OK;
}

/**********************************************************************************************************************
 *  vHsm_LogEvent_NvBlockInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_LogEvent_NvBlockInit(
  vHsm_SizeOfLogEventType blockIdx)
{
  Std_ReturnType retVal = E_OK;
  uint32 logEventId = blockIdx;

  /* #10 Init the event log */
  vHsm_Log_GetCounter(logEventId) = 0u;
  vHsm_Log_GetOffset(logEventId) = 0u;

  VStdMemClr(vHsm_Log_GetMemory(logEventId, LOG_MNGT_SIZE), (uint32)((vHsm_Log_GetMaxEntrySize(logEventId))*vHsm_GetMaxEntriesOfLogEvent(logEventId))); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */

  return retVal;
}

/**********************************************************************************************************************
 *  vHsm_LogEvent_NvBlockCallback()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, VHSM_CODE) vHsm_LogEvent_NvBlockCallback(
  vHsm_SizeOfLogEventType blockIdx,
  uint8 ServiceId,
  NvM_RequestResultType JobResult)
{
  VHSM_DUMMY_STATEMENT(blockIdx); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(ServiceId); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */
  VHSM_DUMMY_STATEMENT(JobResult); /* PRQA S 3112, 1338, 2983 */ /* MD_MSR_DummyStmt */

  /* #10 Always return E_OK */
  return E_OK;
}
# endif
#endif
#define VHSM_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Log.c
 *********************************************************************************************************************/

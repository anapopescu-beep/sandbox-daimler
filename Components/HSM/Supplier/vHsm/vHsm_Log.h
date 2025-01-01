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
/*!        \file  vHsm_Log.h
 *        \brief  header file for logging
 *
 *      \details  -
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (VHSM_LOG_H)
# define VHSM_LOG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "vHsm_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
# define vHsm_Log_GetMaxEntrySize(logEventId)                         ((uint32)vHsm_GetCounterSizeOfLogEvent(logEventId) + (uint32)vHsm_GetTimestampSizeOfLogEvent(logEventId) + (uint32)vHsm_GetDataSizeOfLogEvent(logEventId))
# define vHsm_Log_GetLogEventMemorySize(logEventId)                   ((vHsm_Log_GetMaxEntrySize(logEventId))*vHsm_GetMaxEntriesOfLogEvent(logEventId))
# define vHsm_Log_GetMemory(logEventId, offset)                       (&((P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR))(&vHsm_GetLogEventMemory(vHsm_GetLogEventMemoryStartIdxOfLogEvent(logEventId))))[offset])
# define vHsm_Log_GetMemoryOfEntry(logEventId, nr)                    (vHsm_Log_GetMemory(logEventId, (sizeof(vHsm_Log_MngtType) + (vHsm_Log_GetMaxEntrySize(logEventId)*(nr)))))
# define vHsm_Log_GetCounter(logEventId)                              (vHsm_GetLogEventMemory(vHsm_GetLogEventMemoryStartIdxOfLogEvent(logEventId)))
# define vHsm_Log_GetOffset(logEventId)                               (vHsm_GetLogEventMemory(vHsm_GetLogEventMemoryStartIdxOfLogEvent(logEventId)+1u))
# define vHsm_Log_GetMaxCounterValue(logEventId)                      (((uint64)1 << (vHsm_GetCounterSizeOfLogEvent(logEventId) * 8uL))-1Lu)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct
{
  uint32 counter;
  uint32 offset;
}vHsm_Log_MngtType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define VHSM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
# if (VHSM_LOG == STD_ON)

/**********************************************************************************************************************
 *  vHsm_Log_AddEntry()
 **********************************************************************************************************************/
/*!\brief       Write an entry to the event log
 * \details     -
 * \param[in]   logEventId            Id of the event
 * \param[in]   dataPtr               Pointer to the data
 * \param[in]   dataLength            Length of the provided data
 * \return      E_OK      Entry could be written
 * \return      E_NOT_OK  An error occurred
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Log_AddEntry(
  uint32 logEventId,
  P2CONST(uint8, AUTOMATIC, VHSM_APPL_VAR) dataPtr,
  uint32 dataLength);

#  if (VHSM_LOG_TIMESTAMP_CALLOUT_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Log_GetTimestamp_Callout()
 **********************************************************************************************************************/
/*!\brief       Callout which is called if an event has a timestamp size configured.
 * \details     If less data than requested is provided by the callout, the rest will be padded with 0x00.
 * \param[in]     logEventId            Id of the event
 * \param[out]    timestampPtr          Pointer to the timestamp which shall to be filled by the callout
 * \param[in,out] timestampLengthPtr    Pointer to the length of the timestamp buffer. After calling this function, the number of written bytes needs to be stored there.
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_Log_GetTimestamp_Callout(
  uint32 LogEventId,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) timestampPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) timestampLengthPtr);
#  endif

#  if(VHSM_LOG_EVENT_CALLOUT_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Log_Event_Callout()
 **********************************************************************************************************************/
/*!\brief       Callout which is called if an event occurs which has the callout enabled
 * \details     -
 * \param[in]   logEventId               Id of the event
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_Log_Event_Callout(uint32 logEventId);
#  endif

#  if(VHSM_LOG_THRESHOLD_CALLOUT_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  vHsm_Log_FillLevelThreshold_Callout()
 **********************************************************************************************************************/
/*!\brief       Callout which is called if the configured fill level is reached
 * \details     -
 * \param[in]   logEventId               Id of the event
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, VHSM_CODE) vHsm_Log_FillLevelThreshold_Callout(uint32 logEventId);
#  endif

/**********************************************************************************************************************
 *  vHsm_Log_GetEntry()
 **********************************************************************************************************************/
/*!\brief       Read one or multiple entries form the event log
 * \details     -
 * \param[in]     logEventId            Id of the event
 * \param[in]     exportStrategy        The format for the export e.g. newest, all, occurrences,...
 * \param[out]    dataPtr               Pointer to the buffer which will hold the result
 * \param[in,out] dataLengthPtr         Pointer to the length of the buffer. After calling this function, the number of written bytes will be stored there.
 * \return      E_OK      Entry could be read
 *              E_NOT_OK  An error occurred
 *              CRYPTO_E_SMALL_BUFFER  The provided buffer was to small to hold the result
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Log_GetEntry(
  uint32 logEventId,
  uint32 exportStrategy,
  P2VAR(uint8, AUTOMATIC, VHSM_APPL_VAR) dataPtr,
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) dataLengthPtr);

/**********************************************************************************************************************
 *  vHsm_Log_Reset()
 **********************************************************************************************************************/
/*!\brief       Clear the event log from all occurred events for that specific Id
 * \details     -
 * \param[in]   logEventId            Id of the event
 * \param[in]   clearMemory           additionally clear the memory
 * \param[in]   persist               additionally persist afterwards
 * \return      E_OK      Reset successful
 *              E_NOT_OK  An error happened during resetting of the event log
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_Log_Reset(
  uint32 logEventId,
  boolean clearMemory,
  boolean persist);

#  if(VHSM_NVBLOCKDESCRIPTOROFLOGEVENT == STD_ON)
/**********************************************************************************************************************
 *  vHsm_LogEvent_NvBlockReadFromBlock()
 **********************************************************************************************************************/
/*!\brief       Read from Block callback routine.
 * \details     Block specific callback routine which is called by NvM in order to let the Crypto driver copy data from
 *              NvM RAM mirror to Crypto RAM block.
 * \param[in]   blockIdx               The internal identifier of the NvM block.
 * \param[in]   NvMBuffer   RAM mirror where Ram block data can be read from.
 * \return      E_OK      Data was copied from buffer.
 *              E_NOT_OK  Data was not copied.
 * \pre         blockIdx need to be valid.
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_LogEvent_NvBlockReadFromBlock(
  vHsm_SizeOfLogEventType blockIdx,
  P2CONST(void, AUTOMATIC, VHSM_APPL_DATA) NvMBuffer);

/**********************************************************************************************************************
 *  vHsm_LogEvent_NvBlockWriteToBlock()
 **********************************************************************************************************************/
/*!\brief       Write to Block callback routine.
 * \details     Block specific callback routine which is called by NvM in order to let the Crypto driver copy data from
 *              RAM block to NvM RAM mirror.
 * \param[in]   blockIdx               The internal identifier of the NvM block.
 * \param[out]  NvMBuffer  RAM mirror where Ram block data shall be written to.
 * \return      E_OK      Data was copied to buffer.
 *              E_NOT_OK  No data was copied.
 * \pre         blockIdx need to be valid.
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_LogEvent_NvBlockWriteToBlock(
  vHsm_SizeOfLogEventType blockIdx,
  P2VAR(void, AUTOMATIC, VHSM_APPL_VAR) NvMBuffer);

/**********************************************************************************************************************
 *  vHsm_LogEvent_NvBlockInit()
 **********************************************************************************************************************/
/*!\brief       Init Block callback routine.
 * \details     Block specific callback routine which is called by NvM in order to let the Crypto driver copy default
 *              data to a RAM block.
 * \param[in]   blockIdx               The internal identifier of the NvM block.
 * \return      E_OK      Data initialized.
 *              E_NOT_OK  Any error occurred.
 * \pre         blockIdx need to be valid.
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_LogEvent_NvBlockInit(
  vHsm_SizeOfLogEventType blockIdx);

/**********************************************************************************************************************
 *  vHsm_LogEvent_NvBlockCallback()
 **********************************************************************************************************************/
/*!\brief       Request finished Block callback routine.
 * \details     Block specific callback routine which is called by NvM in order to notify the Crypto driver that an
 *              asynchronous single block request has been finished.
 * \param[in]   blockIdx               The internal identifier of the NvM block.
 * \param[in]   NvM_ServiceIdType      The service identifier of the completed request.
 * \param[in]   NvM_RequestResultType  Result of the single block job.
 * \return      E_OK      Callback function has been processed successfully.
 *              E_NOT_OK  Callback function has not been processed successfully.
 * \pre         blockIdx need to be valid.
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, VHSM_CODE) vHsm_LogEvent_NvBlockCallback(
  vHsm_SizeOfLogEventType blockIdx,
  uint8 ServiceId,
  NvM_RequestResultType JobResult);
#  endif
# endif

# define VHSM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* VHSM_LOG_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Log.h
 *********************************************************************************************************************/

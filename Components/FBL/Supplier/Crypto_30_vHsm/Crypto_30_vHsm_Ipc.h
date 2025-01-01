/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Crypto_30_vHsm_Ipc.h
 *        \brief  MICROSAR vHsm Crypto Driver (Crypto)
 *
 *      \details  Inter-processor communication between Host and Vector Hardware Security Module Firmware.
 *
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

#if !defined (CRYPTO_30_VHSM_IPC_H)
# define CRYPTO_30_VHSM_IPC_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Crypto_30_vHsm_Cfg.h"
# include "Crypto_30_vHsm_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* API services IDs */
# define CRYPTO_30_VHSM_IPC_SID_TRANSMITJOBREQUEST                    (0x80u)
# define CRYPTO_30_VHSM_IPC_SID_RECEIVEJOBRESPONSES                   (0x81u)

/* Development error types */
# define CRYPTO_30_VHSM_IPC_E_NO_ERROR                                (0xFFu)
# define CRYPTO_30_VHSM_IPC_E_PARAM_POINTER                           (0x81u)
# define CRYPTO_30_VHSM_IPC_E_INVALID_CHANNEL                         (0x82u)
# define CRYPTO_30_VHSM_IPC_E_CANNOT_ALLOCATE_JOBREQUEST_BUFFER       (0x83u)
# define CRYPTO_30_VHSM_IPC_E_CANNOT_COPY_JOBREQUEST_DATA             (0x84u)

# define CRYPTO_30_VHSM_MANAGEMENT_JOBREQUEST_ID                      Crypto_30_vHsm_GetManagementDriverObjectOfvHsm()
# define CRYPTO_30_VHSM_ACCEPT_ANY_JOBID                              (0xFFFFFFFFu)

# define CRYPTO_30_VHSM_JOBREQUEST_ID_BITPOSITION                     (0u)
# define CRYPTO_30_VHSM_JOBREQUEST_OBJECTID_BITPOSITION               (8u)
# define CRYPTO_30_VHSM_JOBREQUEST_REDIRECTION_BITPOSITION            (16u)
# define CRYPTO_30_VHSM_JOBREQUEST_COUNTER_BITPOSITION                (24u)

# define CRYPTO_30_VHSM_JOBRESPONSE_ID_BITPOSITION                    (0u)
# define CRYPTO_30_VHSM_JOBRESPONSE_STATE_BITPOSITION                 (8u)
# define CRYPTO_30_VHSM_JOBRESPONSE_RESULT_BITPOSITION                (16u)
# define CRYPTO_30_VHSM_JOBRESPONSE_COUNTER_BITPOSITION               (24u)

# define CRYPTO_30_VHSM_JOBRESPONSE_ID_MASK                           (0x000000FFu)
# define CRYPTO_30_VHSM_JOBRESPONSE_COUNTER_MASK                      (0xFF000000u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/* IPC */
/* PRQA S 3453 IpcMacros3543 */ /* MD_CRYPTO_30_VHSM_3453_IPC_MACRO */
# define Crypto_30_vHsm_Ipc_IsHsmReady()                              (Crypto_30_vHsm_Ipc_GetReadyFlag() == 0xdeadbeefu)
# define Crypto_30_vHsm_Ipc_EndRamExec()                              Crypto_30_vHsm_Ipc_SetEndRamExecFlag(TRUE)
# define Crypto_30_vHsm_Ipc_IsRamExec()                               Crypto_30_vHsm_Ipc_GetRamExecFlag()
# define Crypto_30_vHsm_Ipc_IsDetReported()                           Crypto_30_vHsm_Ipc_GetDetReportFlag()

# define Crypto_30_vHsm_Ipc_GetMemoryPtr8(offset)                     (&(((P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR))Crypto_30_vHsm_Ipc_MemoryPtr)[offset]))
# define Crypto_30_vHsm_Ipc_GetMemoryValue32(offset)                  (*(volatile uint32*)&(((P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR))Crypto_30_vHsm_Ipc_MemoryPtr)[offset]))

# define Crypto_30_vHsm_Ipc_GetTxChannelBuffer(txChannelId)           (Crypto_30_vHsm_Ipc_GetMemoryPtr8(Crypto_30_vHsm_Ipc_MemoryLayout.txChannelMemoryLayout[txChannelId].bufferOffset))

# define Crypto_30_vHsm_Ipc_GetTxChannelWriteIdx(txChannelId)         (Crypto_30_vHsm_Ipc_GetMemoryValue32(Crypto_30_vHsm_Ipc_MemoryLayout.txChannelMemoryLayout[txChannelId].writeIdxOffset))

# define Crypto_30_vHsm_Ipc_GetTxChannelReadIdx(txChannelId)          (Crypto_30_vHsm_Ipc_GetMemoryValue32(Crypto_30_vHsm_Ipc_MemoryLayout.txChannelMemoryLayout[txChannelId].readIdxOffset))

# define Crypto_30_vHsm_Ipc_GetRxChannelBuffer(rxChannelId)           (Crypto_30_vHsm_Ipc_GetMemoryPtr8(Crypto_30_vHsm_Ipc_MemoryLayout.rxChannelMemoryLayout[rxChannelId].bufferOffset))

# define Crypto_30_vHsm_Ipc_GetRxChannelWriteIdx(rxChannelId)         (Crypto_30_vHsm_Ipc_GetMemoryValue32(Crypto_30_vHsm_Ipc_MemoryLayout.rxChannelMemoryLayout[rxChannelId].writeIdxOffset))

# define Crypto_30_vHsm_Ipc_GetRxChannelReadIdx(rxChannelId)          (Crypto_30_vHsm_Ipc_GetMemoryValue32(Crypto_30_vHsm_Ipc_MemoryLayout.rxChannelMemoryLayout[rxChannelId].readIdxOffset))

# define Crypto_30_vHsm_Ipc_GetRamExecFlag()                          ((boolean)Crypto_30_vHsm_Ipc_GetMemoryValue32(Crypto_30_vHsm_Ipc_MemoryLayout.ramExecFlagOffset))
# define Crypto_30_vHsm_Ipc_SetEndRamExecFlag(value)                  (Crypto_30_vHsm_Ipc_GetMemoryValue32(Crypto_30_vHsm_Ipc_MemoryLayout.endRamExecFlagOffset) = (value))

# define Crypto_30_vHsm_Ipc_GetReadyFlag()                            (Crypto_30_vHsm_Ipc_GetMemoryValue32(Crypto_30_vHsm_Ipc_MemoryLayout.readyFlagOffset))

# define Crypto_30_vHsm_Ipc_GetDetReportFlag()                        ((boolean)Crypto_30_vHsm_Ipc_GetMemoryValue32(Crypto_30_vHsm_Ipc_MemoryLayout.detReportFlagOffset))
# define Crypto_30_vHsm_Ipc_SetDetReportFlag(value)                   (Crypto_30_vHsm_Ipc_GetMemoryValue32(Crypto_30_vHsm_Ipc_MemoryLayout.detReportFlagOffset) = (value))
# define Crypto_30_vHsm_Ipc_GetDetModuleId()                          ((uint16)Crypto_30_vHsm_Ipc_GetMemoryValue32(Crypto_30_vHsm_Ipc_MemoryLayout.detModuleIdOffset))
# define Crypto_30_vHsm_Ipc_GetDetInstanceId()                        ((uint8)Crypto_30_vHsm_Ipc_GetMemoryValue32(Crypto_30_vHsm_Ipc_MemoryLayout.detInstanceIdOffset))
# define Crypto_30_vHsm_Ipc_GetDetApiId()                             ((uint8)Crypto_30_vHsm_Ipc_GetMemoryValue32(Crypto_30_vHsm_Ipc_MemoryLayout.detApiIdOffset))
# define Crypto_30_vHsm_Ipc_GetDetErrorId()                           ((uint8)Crypto_30_vHsm_Ipc_GetMemoryValue32(Crypto_30_vHsm_Ipc_MemoryLayout.detErrorIdOffset))

# define Crypto_30_vHsm_Ipc_vHsmProtocolVersion()                     (Crypto_30_vHsm_Ipc_GetMemoryValue32(Crypto_30_vHsm_Ipc_MemoryLayout.protocolInfoOffset))
# define Crypto_30_vHsm_Ipc_DriverProtocolVersion()                   (Crypto_30_vHsm_Ipc_GetMemoryValue32(Crypto_30_vHsm_Ipc_MemoryLayout.protocolInfoOffset+4u))

/* PRQA L:IpcMacros3543 */

# if(CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION == 3)
#  define CRYPTO_30_VHSM_IPC_TX_CHANNEL_ENTRY_MEMORY_SIZE             (116U)
#  define CRYPTO_30_VHSM_IPC_RX_CHANNEL_ENTRY_MEMORY_SIZE             (56U)
#  define CRYPTO_30_VHSM_JOBREQUEST_HEADER_SIZE                       (8U)
#  define CRYPTO_30_VHSM_JOBRESPONSE_HEADER_SIZE                      (4U)
# else
#  define CRYPTO_30_VHSM_IPC_TX_CHANNEL_ENTRY_MEMORY_SIZE             (96U)
#  define CRYPTO_30_VHSM_IPC_RX_CHANNEL_ENTRY_MEMORY_SIZE             (24U)
#  define CRYPTO_30_VHSM_JOBREQUEST_HEADER_SIZE                       (16U)
#  define CRYPTO_30_VHSM_JOBRESPONSE_HEADER_SIZE                      (16U)
# endif

# define CRYPTO_30_VHSM_IPC_GLOBALINFO_MEMORY_SIZE                    (44U)

# define CRYPTO_30_VHSM_IPC_CHANNEL_WRITE_INDEX_MEMORY_SIZE           (4U)
# define CRYPTO_30_VHSM_IPC_CHANNEL_READ_INDEX_MEMORY_SIZE            (4U)

# define CRYPTO_30_VHSM_IPC_CHANNEL_HEADER_MEMORY_SIZE                \
                                                                      (CRYPTO_30_VHSM_IPC_CHANNEL_WRITE_INDEX_MEMORY_SIZE +   \
                                                                      CRYPTO_30_VHSM_IPC_CHANNEL_READ_INDEX_MEMORY_SIZE)

# define CRYPTO_30_VHSM_IPC_TX_CHANNEL_MEMORY_SIZE                    \
                                                                      (CRYPTO_30_VHSM_IPC_CHANNEL_HEADER_MEMORY_SIZE + CRYPTO_30_VHSM_IPC_TX_CHANNEL_ENTRY_MEMORY_SIZE)

# define CRYPTO_30_VHSM_IPC_RX_CHANNEL_MEMORY_SIZE                    \
                                                                      (CRYPTO_30_VHSM_IPC_CHANNEL_HEADER_MEMORY_SIZE + CRYPTO_30_VHSM_IPC_RX_CHANNEL_ENTRY_MEMORY_SIZE)

# define CRYPTO_30_VHSM_IPC_MEMORY_SIZE                               \
                                                                      ((Crypto_30_vHsm_GetIpcChannelsOfvHsm() * CRYPTO_30_VHSM_IPC_TX_CHANNEL_MEMORY_SIZE) +     \
                                                                      (Crypto_30_vHsm_GetIpcChannelsOfvHsm() * CRYPTO_30_VHSM_IPC_RX_CHANNEL_MEMORY_SIZE) +     \
                                                                      CRYPTO_30_VHSM_IPC_GLOBALINFO_MEMORY_SIZE + \
                                                                      CRYPTO_30_VHSM_IPC_PROTOCOL_INFO_SIZE)

# define CRYPTO_30_VHSM_IPC_CHANNELSTATE_FREE                         (0x00u)
# define CRYPTO_30_VHSM_IPC_CHANNELSTATE_ASYNC                        (CRYPTO_PROCESSING_ASYNC + 1u)
# define CRYPTO_30_VHSM_IPC_CHANNELSTATE_SYNC                         (CRYPTO_PROCESSING_SYNC + 1u)

/*! Serialize a uint32 to the IPC buffer with the offset and increment the offset by 4 afterwards */
# define Crypto_30_vHsm_Serialize_Uint32(value, bufferPtr)            (*(P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR))(bufferPtr)) = (uint32)(value) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Serialize a pointer to the IPC buffer with the offset and increment the offset by 4 afterwards */
# define Crypto_30_vHsm_Serialize_Ptr32(value, bufferPtr)             (*(P2VAR(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR))(bufferPtr)) = (uint32)(value) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Deserialize a uint32 to the IPC buffer with the offset and increment the offset by 4 afterwards */
# define Crypto_30_vHsm_Deserialize_Uint32(bufferPtr)                 (*(P2CONST(uint32, AUTOMATIC, CRYPTO_30_VHSM_APPL_DATA))(bufferPtr)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

typedef struct Crypto_30_vHsm_Ipc_Channel_MemoryLayoutTypeStruct
{
  uint32 writeIdxOffset;    /*!< Shared memory offset to buffer reserved for write index (value equals index of next free entry) of channel. */
  uint32 readIdxOffset;     /*!< Shared memory offset to buffer reserved for read index (value equals index of next pending entry) of channel. */
  uint32 bufferOffset;      /*!< Shared memory offset to buffer reserved for all channel entries. */
} Crypto_30_vHsm_Ipc_Channel_MemoryLayoutType;

typedef struct Crypto_30_vHsm_Ipc_MemoryLayoutTypeStruct
{
  uint32 protocolInfoOffset;              /*!< Shared memory offsets to buffers reserved for vHSM protocol info. */
  Crypto_30_vHsm_Ipc_Channel_MemoryLayoutType txChannelMemoryLayout[Crypto_30_vHsm_GetIpcChannelsOfvHsm()];  /*!< Describes the memory layout of all TX channels. */
  Crypto_30_vHsm_Ipc_Channel_MemoryLayoutType rxChannelMemoryLayout[Crypto_30_vHsm_GetIpcChannelsOfvHsm()];  /*!< Describes the memory layout of all RX channels. */
  uint32 stackProtectionCanaryPE1Offset;  /*!< Shared memory offsets to buffers reserved for vHSM stack protection canary Appl Core 1. */
  uint32 stackProtectionCanaryPE2Offset;  /*!< Shared memory offsets to buffers reserved for vHSM stack protection canary Appl Core 2. */
  uint32 seedOffset;                      /*!< Shared memory offset to buffer reserved for vHSM random seed. */
  uint32 detModuleIdOffset;               /*!< Shared memory offsets to buffers reserved for vHSM development error detection (DET module). */
  uint32 detInstanceIdOffset;             /*!< Shared memory offsets to buffers reserved for vHSM development error detection (DET instance id). */
  uint32 detApiIdOffset;                  /*!< Shared memory offsets to buffers reserved for vHSM development error detection (DET api id). */
  uint32 detErrorIdOffset;                /*!< Shared memory offsets to buffers reserved for vHSM development error detection (DET error id). */
  uint32 readyFlagOffset;                 /*!< Shared memory offset to buffer reserved for vHSM Ready flag. */
  uint32 endRamExecFlagOffset;            /*!< Shared memory offset to buffer reserved for vHSM End-RAM-Execution flag. */
  uint32 ramExecFlagOffset;               /*!< Shared memory offset to buffer reserved for vHSM Is-RAM-Execution flag. */
  uint32 detReportFlagOffset;             /*!< Shared memory offset to buffer reserved for vHSM Det-Report flag. */

} Crypto_30_vHsm_Ipc_MemoryLayoutType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define CRYPTO_30_VHSM_START_SEC_IPC_MEMORY_VAR_NOINIT_32BIT
# include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Memory of the IPC */
extern VAR(uint32, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_Ipc_Memory[CRYPTO_30_VHSM_IPC_MEMORY_SIZE / 4u];

# define CRYPTO_30_VHSM_STOP_SEC_IPC_MEMORY_VAR_NOINIT_32BIT
# include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT
# include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Pointer to the IPC memory */
extern P2VAR(uint32, CRYPTO_30_VHSM_VAR_NOINIT, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_Ipc_MemoryPtr;

# define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT
# include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
# include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Layout of the IPC memory */
extern CONST(Crypto_30_vHsm_Ipc_MemoryLayoutType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_Ipc_MemoryLayout;

# define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
# include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define CRYPTO_30_VHSM_START_SEC_CODE
# include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Crypto_30_vHsm_Ipc_TransmitRequest()
 *********************************************************************************************************************/
/*!
 * \brief       Transmit job request
 * \details     -
 * \param[in]   txChannelId            Valid TX channel Id
 * \param[in]   jobRequestId           Valid job request Id
 * \return      TRUE if the job request was correctly transmitted, otherwise E_NOT_OK
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(Std_ReturnType, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_Ipc_TransmitRequest(
  Crypto_30_vHsm_ChannelIdType txChannelId,
  Crypto_30_vHsm_JobRequestIterType jobRequestId);

# define CRYPTO_30_VHSM_STOP_SEC_CODE
# include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define CRYPTO_30_VHSM_START_SEC_RAMCODE
# include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/**********************************************************************************************************************
 *  Crypto_30_vHsm_Ipc_ReceiveResponse()
 *********************************************************************************************************************/
/*!
 * \brief       Receive job responses
 * \details     -
 * \param[in]   rxChannelId            Valid RX channel Id
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_Ipc_ReceiveResponse(
  Crypto_30_vHsm_ChannelIdType rxChannelId);

# define CRYPTO_30_VHSM_STOP_SEC_RAMCODE
# include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define CRYPTO_30_VHSM_START_SEC_CODE
# include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (CRYPTO_30_VHSM_DEV_ERROR_REPORT == STD_ON)
/**********************************************************************************************************************
 *  Crypto_30_vHsm_Ipc_GetDet()
 *********************************************************************************************************************/
/*!
 * \brief       Get DET error
 * \details     -
 * \param[out]   moduleId            Valid pointer to hold module ID
 * \param[out]   instanceId          Valid pointer to hold instance ID
 * \param[out]   apiId               Valid pointer to hold API ID
 * \param[out]   errorId             Valid pointer to hold error ID
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_Ipc_GetDet(
  P2VAR(uint16, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) moduleId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) instanceId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) apiId,
  P2VAR(uint8, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) errorId);
# endif

/**********************************************************************************************************************
 *  Crypto_30_vHsm_Ipc_ProcessChannels()
 *********************************************************************************************************************/
/*!
 * \brief       Process IPC channels
 * \details     -
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_Ipc_ProcessChannels(void);

/**********************************************************************************************************************
 *  Crypto_30_vHsm_Ipc_ProcessCallbacks()
 *********************************************************************************************************************/
/*!
 * \brief       Process IPC callbacks
 * \details     -
 * \pre         -
 * \context     ANY
 * \reentrant   FALSE
 * \synchronous TRUE
 *********************************************************************************************************************/
FUNC(void, CRYPTO_30_VHSM_CODE) Crypto_30_vHsm_Ipc_ProcessCallbacks(void);

# define CRYPTO_30_VHSM_STOP_SEC_CODE
# include "Crypto_30_vHsm_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* CRYPTO_30_VHSM_IPC_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_Ipc.h
 *********************************************************************************************************************/

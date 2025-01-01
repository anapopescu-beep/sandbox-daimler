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
/*!        \file  CanTSyn.c
 *        \brief  Vector AUTOSAR CanTSyn code file
 *
 *      \details  This is the main implementation file of the Vector AUTOSAR module CanTSyn.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define CANTSYN_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "CanTSyn.h"
#include "CanTSyn_Cbk.h"
#include "SchM_CanTSyn.h"
#include "StbM.h"
#if (CANTSYN_MASTERCONFIG == STD_ON)
# include "CanIf.h"
#endif
#if (CANTSYN_CRC_USED)
# include "Crc.h"
#endif
#if (CANTSYN_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif
#if (CANTSYN_SLAVECONFIG == STD_ON)
# include "vstdlib.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of CanTSyn header file */
#if (  (CANTSYN_SW_MAJOR_VERSION != (6u)) \
    || (CANTSYN_SW_MINOR_VERSION != (1u)) \
    || (CANTSYN_SW_PATCH_VERSION != (0u)) )
# error "Vendor specific version numbers of CanTSyn.c and CanTSyn.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (CANTSYN_CFG_MAJOR_VERSION != (6u)) \
    || (CANTSYN_CFG_MINOR_VERSION != (1u)) )
# error "Version numbers of CanTSyn.c and CanTSyn_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define CANTSYN_INV_MASTER_IDX                             (255u)
#define CANTSYN_INV_SEQUENCE_COUNTER                       (255u)
#define CANTSYN_MAX_SEQUENCE_COUNTER                       (15u)
#define CANTSYN_START_OFFSET_TIME_DOMAIN_ID                (16u)

#define CANTSYN_CRC_START_VALUE                            (0xFFu)

#define CANTSYN_NANOSECONDS_IN_ONE_SECOND                  (1000000000uL)
#define CANTSYN_TIMESTAMP_MAX_NANOSECONDS                  (999999999uL) /* 10^9 nanoseconds per second */
#define CANTSYN_TIMESTAMP_MAX_SECONDS                      (4294967295uL)


/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#define CanTSyn_GetGlobalTimeBaseBit(status)               ((status) & StbM_Global_Time_Base_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define CanTSyn_GetSyncToGatewayBit(status)                ((status) & StbM_Sync_To_Gateway_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define CanTSyn_GetTimeoutBit(status)                      ((status) & StbM_Timeout_BflMask) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#define CanTSyn_IsSyncMsg(type)                            (((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_NOT_CRC) || ((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_CRC)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define CanTSyn_IsFupMsg(type)                             (((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_NOT_CRC) || ((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_CRC)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define CanTSyn_IsOfsMsg(type)                             (((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_NOT_CRC) || ((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_CRC)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define CanTSyn_IsOfnsMsg(type)                            (((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_NOT_CRC) || ((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_CRC)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#define CanTSyn_IsSyncCrcSecured(type)                     (((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_CRC) || ((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_CRC)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define CanTSyn_IsFupCrcSecured(type)                      (((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_CRC) || ((type) == CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_CRC)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Get Message type (Multiplexer value) */
#define CanTSyn_CanSignal_GetType(msg)                     ((*msg)[0]) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Get CRC */
#define CanTSyn_CanSignal_GetCRC(msg)                      ((*msg)[1]) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Get Sequence counter */
#define CanTSyn_CanSignal_GetSC(msg)                       ((*msg)[2] & 0x0Fu) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Get Time Domain */
#define CanTSyn_CanSignal_GetD(msg)                        ((*msg)[2] >> 4u) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Get SGW from FUP message */
#define CanTSyn_CanSignal_GetSGW(fupMsg)                   ((uint8)(((*fupMsg)[3] & 0x04u) >> 2u)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Get OVS from FUP message */
#define CanTSyn_CanSignal_GetOVS(fupMsg)                   ((uint8)((*fupMsg)[3] & 0x03u)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Get secondsHi from OFS/OFNS message */
#define CanTSyn_CanSignal_GetSecHi(msg)                    ((*msg)[3]) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Get the time value (seconds from SYNC/OFS message or nanoseconds from FUP/OFNS message) */
#define CanTSyn_CanSignal_GetTime(msg)                     (((uint32) (*msg)[7]) | ((uint32) (*msg)[6] << 8u) | ((uint32) (*msg)[5] << 16u) | ((uint32) (*msg)[4] << 24u)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Get User bytes (SYNC: Byte 0 and 1; FUP: Byte 2; Byte 1 and 2 only valid for not CRC secured messages) */
#define CanTSyn_CanSignal_GetUserByte0(syncMsg)            ((*syncMsg)[3]) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define CanTSyn_CanSignal_GetUserByte1(syncMsg)            ((*syncMsg)[1]) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define CanTSyn_CanSignal_GetUserByte2(fupMsg)             ((*fupMsg)[1]) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Set Message type (Multiplexer value) */
#define CanTSyn_CanSignal_SetType(msg, value)              (*msg)[0] = (uint8) (value) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Set CRC */
#define CanTSyn_CanSignal_SetCRC(msg, value)               (*msg)[1] = (uint8) (value) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Set message byte 2 (Time Domain and Sequence counter) */
#define CanTSyn_CanSignal_SetByte2(msg, domain, sc)        (*msg)[2] = (uint8) (((domain) << 4u) | ((sc) & 0x0Fu)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Set reserved byte from OFS/OFNS message */
#define CanTSyn_CanSignal_ClearOfsReserved(msg)            (*msg)[1] = (uint8) (0u) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Set message byte 3 from FUP message (SGW, OVS and reserved) */
#define CanTSyn_CanSignal_SetByte3(fupMsg, ovs, sgw)       (*fupMsg)[3] = (uint8) (((uint8)((ovs) & 0x03u) | ((sgw) & 0x04u)) & 0x07u) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Set secondsHi from OFS/OFNS message */
#define CanTSyn_CanSignal_SetSecHi(msg, value)             (*msg)[3] = (uint8) (value) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Set the time value (seconds from SYNC/OFS message or nanoseconds from FUP/OFNS message) */
#define CanTSyn_CanSignal_SetTime(msg, value)              {(*msg)[7] = (uint8) (value);          \
                                                            (*msg)[6] = (uint8) ((value) >>  8u); \
                                                            (*msg)[5] = (uint8) ((value) >> 16u); \
                                                            (*msg)[4] = (uint8) ((value) >> 24u);}

/* Set User bytes (SYNC: Byte 0 and 1; FUP: Byte 2; Byte 1 and 2 only valid for not CRC secured messages) */
#define CanTSyn_CanSignal_SetUserByte0(syncMsg, value)     (*syncMsg)[3] = (uint8) (value) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define CanTSyn_CanSignal_SetUserByte1(syncMsg, value)     (*syncMsg)[1] = (uint8) (value) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define CanTSyn_CanSignal_SetUserByte2(fupMsg, value)      (*fupMsg)[1] = (uint8) (value) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Set the reserved bytes of an Extended SYNC/FUP message */
#define CanTSyn_ExtendedCanSignal_SetReserved(msg)         {(*msg)[8] = (uint8) (0u);  \
                                                            (*msg)[9] = (uint8) (0u);  \
                                                            (*msg)[10] = (uint8) (0u); \
                                                            (*msg)[11] = (uint8) (0u); \
                                                            (*msg)[12] = (uint8) (0u); \
                                                            (*msg)[13] = (uint8) (0u); \
                                                            (*msg)[14] = (uint8) (0u); \
                                                            (*msg)[15] = (uint8) (0u);}

/* Check if component is already pre initialized */
#define CanTSyn_IsPreInitialized()                         (CanTSyn_PreInitialized != FALSE) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#if !defined (CANTSYN_LOCAL) /* COV_CANTSYN_MSR_COMPATIBILITY */
# define CANTSYN_LOCAL static
#endif

#if !defined (CANTSYN_LOCAL_INLINE) /* COV_CANTSYN_MSR_COMPATIBILITY */
# define CANTSYN_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define CANTSYN_START_SEC_CODE
#include "CanTSyn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CANTSYN_MULTIPARTITION_USED == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_GetCurrentPartitionIndexByOsApplication
 *********************************************************************************************************************/
/*! \brief      Get the current partition index.
 *  \details    This function might call GetApplicationID() from Os.h which might cause high runtime overhead.
 *  \param[in]  osAppId             Os application id to find the partition for
 *  \return     partitionIdx        Check partitionIdx < CanTSyn_GetSizeOfPartitionIdentifiers() before usage.
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL FUNC(CanTSyn_PartitionIdentifiersIterType, CANTSYN_CODE) CanTSyn_GetCurrentPartitionIndexByOsApplication(ApplicationType osAppId);

# if (CANTSYN_MASTERCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_GetCurrentPartitionIndexByControllerId
 *********************************************************************************************************************/
/*! \brief      Get the current partition index by the given controller id.
 *  \details    -
 *  \param[in]  ctrIdx              Controller id to find mapping for
 *  \return     partitionIdx        Check partitionIdx < CanTSyn_GetSizeOfPartitionIdentifiers() before usage.
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL FUNC(CanTSyn_PartitionIdentifiersIterType, CANTSYN_CODE) CanTSyn_GetCurrentPartitionIndexByControllerId(uint8 ctrIdx);

/**********************************************************************************************************************
 *  CanTSyn_GetCurrentPartitionIndexByMasterPdu
 *********************************************************************************************************************/
/*! \brief      Get the current partition index by the given master pdu.
 *  \details    -
 *  \param[in]  txPduId             Pdu to find mapping for
 *  \return     partitionIdx        Check partitionIdx < CanTSyn_GetSizeOfPartitionIdentifiers() before usage.
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL FUNC(CanTSyn_PartitionIdentifiersIterType, CANTSYN_CODE) CanTSyn_GetCurrentPartitionIndexByMasterPdu(PduIdType txPduId);
# endif /* CANTSYN_MASTERCONFIG == STD_ON */

# if (CANTSYN_SLAVECONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_GetCurrentPartitionIndexBySlavePdu
 *********************************************************************************************************************/
/*! \brief      Get the current partition index by the given slave pdu.
 *  \details    -
 *  \param[in]  rxPduId             Pdu to find mapping for
 *  \return     partitionIdx        Check partitionIdx < CanTSyn_GetSizeOfPartitionIdentifiers() before usage.
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL FUNC(CanTSyn_PartitionIdentifiersIterType, CANTSYN_CODE) CanTSyn_GetCurrentPartitionIndexBySlavePdu(PduIdType rxPduId);
# endif /* CANTSYN_SLAVECONFIG == STD_ON */
#endif /* CANTSYN_MULTIPARTITION_USED == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_TimestampPlusTimestamp
 *********************************************************************************************************************/
/*! \brief      Adds two timestamps
 *  \details    This function calculates the sum of two timestamps.
 *  \param[in]  timestamp1Ptr       Pointer to timestamp where the first summand is stored
 *  \param[in]  timestamp2Ptr       Pointer to timestamp where the second summand is stored
 *  \param[out] timesumPtr          Pointer to timestamp where the calculated sum is stored
 *  \return     E_OK                Timesum is valid
 *  \return     E_NOT_OK            Timesum is invalid
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_TimestampPlusTimestamp(
    P2CONST(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_DATA) timestamp1Ptr,
    P2CONST(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_DATA) timestamp2Ptr,
    P2VAR(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_VAR) timesumPtr);

/**********************************************************************************************************************
 *   CanTSyn_SubtractVirtualLocalTime
 *********************************************************************************************************************/
/*! \brief      Subtract two VirtualLocalTime types
 *  \details    This function calculates the difference of two VirtualLocalTime types.
 *  \param[in]  lhs                 Pointer to a VirtualLocalTime type where the minuend is stored
 *  \param[in]  rhs                 Pointer to a VirtualLocalTime type where the subtrahend is stored
 *  \param[out] timediffPtr         Pointer to the calculated difference
 *  \return     E_OK                Timediff is valid
 *  \return     E_NOT_OK            Timediff is invalid
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_SubtractVirtualLocalTime(
    P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_DATA) lhs,
    P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_DATA) rhs,
    P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_VAR) timediffPtr);

/**********************************************************************************************************************
 *   CanTSyn_VirtualLocalTimeToTimestamp
 *********************************************************************************************************************/
/*! \brief      Converts a VirtualLocalTime type to a timestamp
 *  \details    -
 *  \param[in]  timePtr             Pointer to a VirtualLocalTime type
 *  \param[out] timestampPtr        Pointer to the calculated timestamp
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_VirtualLocalTimeToTimestamp(
    P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_DATA) timePtr,
    P2VAR(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_VAR) timestampPtr);

#if (CANTSYN_CRC_USED == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_CalculateMsgCrc
 *********************************************************************************************************************/
/*! \brief      Calculate CRC over byte 2-7 of the CAN message and data Id.
 *  \details    -
 *  \param[in]  ptrDataId           Pointer to dataId
 *  \param[in]  ptrMsgInfo          Pointer to CAN message
 *  \param[in]  crcLength           Length to calculate the CRC over
 *  \return     CRC                 Calculated CRC value
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL FUNC(uint8, CANTSYN_CODE) CanTSyn_CalculateMsgCrc(
    P2CONST(uint8, AUTOMATIC, CANTSYN_APPL_DATA) ptrDataId,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    uint32 crcLength);

/**********************************************************************************************************************
 *  CanTSyn_GetCrcLength
 *********************************************************************************************************************/
/*! \brief      Get the length of the CRC of the given domain.
 *  \details    -
 *  \param[in]  domainIdx           Valid index of domain
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     CRCLength           Length of the CRC of the given domain.
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(uint32, CANTSYN_CODE) CanTSyn_GetCrcLength(
    CanTSyn_DomainConfigIterType domainIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
#endif /* CANTSYN_CRC_USED == STD_ON */

#if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_IsOffsetDomain
 *********************************************************************************************************************/
/*! \brief      Check if given domain is an offset domain.
 *  \details    -
 *  \param[in]  domainIdx           Valid index of domain
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                Domain is an offset domain
 *  \return     FALSE               Domain is no offset domain
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_IsOffsetDomain(
    CanTSyn_DomainConfigIterType domainIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
#endif /* CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON */


/**********************************************************************************************************************
 *
 *
 *  MASTER
 *
 *
 *********************************************************************************************************************/

#if (CANTSYN_MASTERCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_Init
 *********************************************************************************************************************/
/*! \brief      Initialization of transmit unit
 *  \details    -
 *  \param[in]  partitionIndex     Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_Init(CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_Update
 *********************************************************************************************************************/
/*! \brief      Update Tx unit
 *  \details    -
 *  \param[in]  partitionIndex     Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_Update(CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_InitMasters
 *********************************************************************************************************************/
/*! \brief      Initialization of masters
 *  \details    -
 *  \param[in]  partitionIndex     Valid partition index
 *  \pre        -
 *  \unit       Transmit
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_InitMasters(CanTSyn_PartitionIdentifiersIterType partitionIndex);

# if (CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_InitImmediateSendMode
 *********************************************************************************************************************/
/*! \brief      Initialization state of immediate send mode
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Transmit
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_InitImmediateSendMode(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
# endif /* CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateMasters
 *********************************************************************************************************************/
/*! \brief      Updates all configured masters
 *  \details    -
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateMasters(CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_ProcessTxConfirmation
 *********************************************************************************************************************/
/*! \brief      Check the message confirmation based on type of message
 *  \details    -
 *  \param[in]  TxPduId             Valid ID of the I-PDU that has been transmitted
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     E_OK                Tx confirmation could be processed
 *  \return     E_NOT_OK            Tx confirmation could not be processed
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_Tx_ProcessTxConfirmation(
    PduIdType txPduId,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateCounters
 *********************************************************************************************************************/
/*! \brief      Update counters
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Transmit.Protocol
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateCounters(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateWaitingForTxConfirmation
 *********************************************************************************************************************/
/*! \brief      Update the state 'wait for Tx confirmation'
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Transmit.Protocol
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateWaitingForTxConfirmation(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnFailedTransmit
 *********************************************************************************************************************/
/*! \brief      Executed after unsuccessful transmission of SYNC/OFS message.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Transmit.Protocol
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnFailedTransmit(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateWaitingForSyncSend
 *********************************************************************************************************************/
/*! \brief      Update the state 'wait to send SYNC'
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateWaitingForSyncSend(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnSyncTxConfirmation
 *********************************************************************************************************************/
/*! \brief      Process the SYNC/OFS Tx confirmation.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnSyncTxConfirmation(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_TransmitSync
 *********************************************************************************************************************/
/*! \brief      Transmit SYNC message.
 *  \details    Assembles SYNC, OFS messages and transmits the message via CAN interface.
 *  \param[in]  masterIdx           Valid index of the master for which SYNC/OFS message should be transmitted
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Transmit.Protocol.Sync
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_TransmitSync(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnSuccessTransmitSync
 *********************************************************************************************************************/
/*! \brief      Executed after successfully transmission of SYNC/OFS message.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Transmit.Protocol.Sync
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnSuccessTransmitSync(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateWaitingForFupSend
 *********************************************************************************************************************/
/*! \brief      Update the state 'wait to send FUP'
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateWaitingForFupSend(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnFupTxConfirmation
 *********************************************************************************************************************/
/*! \brief      Process the FUP/OFNS Tx confirmation.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnFupTxConfirmation(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnSuccessFupTransmit
 *********************************************************************************************************************/
/*! \brief      Executed after successfully transmission of FUP/OFNS message.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Transmit.Protocol.Fup
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnSuccessFupTransmit(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_TransmitFup
 *********************************************************************************************************************/
/*! \brief      Transmit FUP message.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Transmit.Protocol.Fup
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_TransmitFup(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_GetTimeSync
 *********************************************************************************************************************/
/*! \brief      Get the current time for SYNC/OFS message.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     E_OK                OFS/SYNC time retrieval was successful
 *  \return     E_NOT_OK            OFS/SYNC time retrieval was not successful
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_Tx_GetTimeSync(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_GetTimeFup
 *********************************************************************************************************************/
/*! \brief      Get the current time for FUP message.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_Tx_GetTimeFup(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnGetTimeSync
 *********************************************************************************************************************/
/*! \brief      Get time for SYNC message
 *  \details    Gets the time from StbM
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     E_OK                Time retrieval was successful
 *  \return     E_NOT_OK            Time retrieval was not successful
 *  \pre        -
 *  \unit       Transmit.Protocol.CurrentTime
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_Tx_OnGetTimeSync(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnGetTimeFup
 *********************************************************************************************************************/
/*! \brief      Get the time from StbM for FUP message.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     E_OK                Time retrieval was successful
 *  \return     E_NOT_OK            Time retrieval was not successful
 *  \pre        -
 *  \unit       Transmit.Protocol.CurrentTime
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_Tx_OnGetTimeFup(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

# if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_OnGetTimeOfs
 *********************************************************************************************************************/
/*! \brief      Get the time from StbM for OFS message.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     E_OK                Time retrieval was successful
 *  \return     E_NOT_OK            Time retrieval was not successful
 *  \pre        -
 *  \unit       Transmit.Protocol.CurrentTime
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_Tx_OnGetTimeOfs(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
# endif /* CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_Tx_AssembleSyncMsg
 *********************************************************************************************************************/
/*! \brief      Assemble SYNC/OFS message.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[out] syncMsg             CAN message to write to
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_AssembleSyncMsg(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) syncMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_AssembleFupMsg
 *********************************************************************************************************************/
/*! \brief      Assemble FUP/OFNS message.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[out] fupMsg              CAN message to write to
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_AssembleFupMsg(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) fupMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnAssembleSync
 *********************************************************************************************************************/
/*! \brief      Assemble message using SYNC/OFS format.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[out] syncMsg             CAN message to write to
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Transmit.Protocol.AssembleMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnAssembleSync(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) syncMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnAssembleFup
 *********************************************************************************************************************/
/*! \brief      Assemble message using FUP/OFNS format.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[out] fupMsg              CAN message to write to
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Transmit.Protocol.AssembleMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnAssembleFup(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) fupMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

# if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_OnAssembleOfs
 *********************************************************************************************************************/
/*! \brief      Assemble message using OFS format.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[out] ofsMsg              CAN message to write to
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        Need to call CanTSyn_Tx_OnAssembleSync before calling this function
 *  \unit       Transmit.Protocol.AssembleMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnAssembleOfs(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) ofsMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnAssembleOfns
 *********************************************************************************************************************/
/*! \brief      Assemble message using OFNS format.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[out] ofnsMsg             CAN message to write to
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        Need to call CanTSyn_Tx_OnAssembleFup before calling this function
 *  \unit       Transmit.Protocol.AssembleMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnAssembleOfns(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) ofnsMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
# endif /* CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON */

# if ((CANTSYN_EXISTS_SYNC_TXCRCSECUREDOFMASTERCONFIG == STD_ON) || (CANTSYN_EXISTS_OFS_TXCRCSECUREDOFMASTERCONFIG == STD_ON))
/**********************************************************************************************************************
 *  CanTSyn_Tx_SetUserByte1ToSync
 *********************************************************************************************************************/
/*! \brief      Set user byte 1 for SYNC/OFS message without CRC
*  \details    -
*  \param[in]  masterIdx           Valid index of master
*  \param[out] syncMsg             CAN message to write to
 * \param[in]  partitionIndex      Valid partition index
*  \pre        -
*  \unit       Transmit.Protocol.AssembleMsg
*  \visibility Private
*********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_SetUserByte1ToSync(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) syncMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
# endif /* (CANTSYN_EXISTS_SYNC_TXCRCSECUREDOFMASTERCONFIG == STD_ON) || (CANTSYN_EXISTS_OFS_TXCRCSECUREDOFMASTERCONFIG == STD_ON) */

# if ((CANTSYN_EXISTS_SYNC_CRC_TXCRCSECUREDOFMASTERCONFIG == STD_ON) || (CANTSYN_EXISTS_OFS_CRC_TXCRCSECUREDOFMASTERCONFIG == STD_ON))
/**********************************************************************************************************************
 *  CanTSyn_Tx_SetCrcToSync
 *********************************************************************************************************************/
/*! \brief      Set the CRC to the SYNC/OFS message
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[out] syncMsg             CAN message to write to
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Transmit.Protocol.AssembleMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL FUNC(void, CANTSYN_CODE) CanTSyn_Tx_SetCrcToSync(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) syncMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_SetCrcToFup
 *********************************************************************************************************************/
/*! \brief      Set the CRC to the FUP/OFNS message
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[out] fupMsg              CAN message to write to
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Transmit.Protocol.AssembleMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL FUNC(void, CANTSYN_CODE) CanTSyn_Tx_SetCrcToFup(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) fupMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
# endif /* (CANTSYN_EXISTS_SYNC_CRC_TXCRCSECUREDOFMASTERCONFIG == STD_ON) || (CANTSYN_EXISTS_OFS_CRC_TXCRCSECUREDOFMASTERCONFIG == STD_ON) */

/**********************************************************************************************************************
 *  CanTSyn_Tx_ValidateSendSyncConditions
 *********************************************************************************************************************/
/*! \brief      Validates if a SYNC/OFS message can be sent
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                All send conditions for sending a SYNC/OFS message are true
 *  \return     FALSE               At least one send condition is not fulfilled
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_ValidateSendSyncConditions(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_ValidateSendFupConditions
 *********************************************************************************************************************/
/*! \brief      Validates if a FUP/OFNS message can be sent
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                All send conditions for sending a FUP/OFNS message are true
 *  \return     FALSE               At least one send condition is not fulfilled
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_ValidateSendFupConditions(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

# if (CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_ValidateImmediateSync
 *********************************************************************************************************************/
/*! \brief      Validate if the immediate send SYNC has to be triggered.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                SYNC message must be sent in immediate mode
 *  \return     FALSE               Immediate send mode conditions are not fulfilled
 *  \pre        -
 *  \unit       Transmit.Protocol.Validation
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_ValidateImmediateSync(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
# endif /* CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_Tx_IsTxReady
 *********************************************************************************************************************/
/*! \brief      Checks if sending is possible.
 *  \details    -
 *  \param[in]  masterIdx           Valid master index
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                Tx is ready to be used for sending
 *  \return     FALSE               Tx is not ready
 *  \pre        -
 *  \unit       Transmit.Protocol.Validation
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_IsTxReady(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_StopTxPeriodCounter
 *********************************************************************************************************************/
/*! \brief      Stop the Tx period counter.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_StopTxPeriodCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_ResetTxPeriodCounter
 *********************************************************************************************************************/
/*! \brief      Reset the Tx period counter.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_ResetTxPeriodCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateTxPeriodCounter
 *********************************************************************************************************************/
/*! \brief      Update the Tx period counter.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateTxPeriodCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_IsTxPeriodTimeExpired
 *********************************************************************************************************************/
/*! \brief      Check if Tx period time is expired.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_IsTxPeriodTimeExpired(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_InitTxSequenceCounter
 *********************************************************************************************************************/
/*! \brief      Initialize the Tx sequence counter to the maximum value.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_InitTxSequenceCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_IncrementTxSequenceCounter
 *********************************************************************************************************************/
/*! \brief      Increment sequence counter
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_IncrementTxSequenceCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

# if (CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_InitCyclicMsgResumeCounter
 *********************************************************************************************************************/
/*! \brief      Initialize the cyclic message resume counter.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_InitCyclicMsgResumeCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_ResetCyclicMsgResumeCounter
 *********************************************************************************************************************/
/*! \brief      Reset cyclic message resume counter to configured value.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_ResetCyclicMsgResumeCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateCyclicMsgResumeCounter
 *********************************************************************************************************************/
/*! \brief      Update the cyclic message resume counter.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateCyclicMsgResumeCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_IsCyclicMsgResumeTimeExpired
 *********************************************************************************************************************/
/*! \brief      Check if cyclic message resume time is expired.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                Cyclic message resume time is expired
 *  \return     FALSE               Cyclic message resume time is not expired
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_IsCyclicMsgResumeTimeExpired(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
# endif /* CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_Tx_InitTxConfirmationTimeout
 *********************************************************************************************************************/
/*! \brief      Initialize the Tx confirmation timeout.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_InitTxConfirmationTimeout(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_ResetTxConfirmationTimeout
 *********************************************************************************************************************/
/*! \brief      Reset the Tx confirmation timeout to the configured value.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_ResetTxConfirmationTimeout(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateTxConfirmationTimeout
 *********************************************************************************************************************/
/*! \brief      Update the Tx confirmation timeout.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        TxConfirmationTimeoutCounter > 0
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateTxConfirmationTimeout(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_IsTxConfirmationTimeoutExpired
 *********************************************************************************************************************/
/*! \brief      Check if Tx confirmation timeout is expired.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                Tx confirmation timeout is expired
 *  \return     FALSE               Tx confirmation timeout is not expired
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_IsTxConfirmationTimeoutExpired(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

# if (CANTSYN_TXDEBOUNCECOUNTERIDXOFMASTERCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_InitDebounceCounter
 *********************************************************************************************************************/
/*! \brief      Initialization of Tx debouncing
 *  \details    -
 *  \param[in]  partitionIndex     Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_InitDebounceCounter(CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_ResetDebounceCounter
 *********************************************************************************************************************/
/*! \brief      Reset Tx debounce counter back to configured value.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL FUNC(void, CANTSYN_CODE) CanTSyn_Tx_ResetDebounceCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateDebounceCounter
 *********************************************************************************************************************/
/*! \brief      Update Tx debouncing
 *  \details    Configured Tx debounce counters are decremented.
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateDebounceCounter(CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_IsDebounceTimeExpired
 *********************************************************************************************************************/
/*! \brief      Check if Tx debounce time is expired.
 *  \details    Check if the Tx debounce counter is zero for the given master.
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                Tx is debounce time is expired
 *  \return     FALSE               Tx debounce time is not expired
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_IsDebounceTimeExpired(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

#  if (CANTSYN_TX_CONF_MIXED_DEBOUNCE_COUNTER == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_HasDebouncing
 *********************************************************************************************************************/
/*! \brief      Check if the given master has Tx debouncing configured.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Transmit.DebounceTime
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_HasDebouncing(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
#  endif /* CANTSYN_TX_CONF_MIXED_DEBOUNCE_COUNTER == STD_ON */
# endif /* CANTSYN_TXDEBOUNCECOUNTERIDXOFMASTERCONFIG == STD_ON */

# if (CANTSYN_EXISTS_SHARED_PDUS == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_InitPduIdStates
 *********************************************************************************************************************/
/*! \brief      Initialization of PduId state table.
 *  \details    -
 *  \param[in]  partitionIndex     Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_InitPduIdStates(CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_LockPduId
 *********************************************************************************************************************/
/*! \brief      Lock the PduId for the given master.
 *  \details    No other master can use the configured PduId after this call.
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        Check if PduId is already locked by calling CanTSyn_Tx_IsPduIdUnLocked
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_LockPduId(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_ReleasePduId
 *********************************************************************************************************************/
/*! \brief      Release the PduId for the given master.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        Check if PduId is already locked by calling CanTSyn_Tx_IsPduIdUnLocked
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_ReleasePduId(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Tx_IsPduIdUnLocked
 *********************************************************************************************************************/
/*! \brief      Check if the configured PduId is unlocked.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                Pdu is not locked from another master
 *  \return     FALSE               Pdu is locked from another master
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_IsPduIdUnLocked(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
# endif /* CANTSYN_EXISTS_SHARED_PDUS == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_InitCanController
 *********************************************************************************************************************/
/*! \brief      Initialization of CAN controller.
 *  \details    -
 *  \param[in]  partitionIndex     Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_InitCanController(CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_IsCanControllerReady
 *********************************************************************************************************************/
/*! \brief      Checks if the configured CAN controller is online.
 *  \details    -
 *  \param[in]  masterIdx           Valid index of master
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                CAN controller is ready to use
 *  \return     FALSE               CAN controller is not ready
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_IsCanControllerReady(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_SetCanControllerTransmissionMode
 *********************************************************************************************************************/
/*! \brief      Set the transmission mode
 *  \details    -
 *  \param[in]  ctrlIdx             CAN controller index
 *  \param[in]  mode                Valid values are CANTSYN_TX_OFF or CANTSYN_TX_ON
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                The controller index is valid
 *  \return     FALSE               The controller index is invalid
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_SetCanControllerTransmissionMode(
    uint8 ctrlIdx,
    CanTSyn_TransmissionModeType mode,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
#endif /* CANTSYN_MASTERCONFIG == STD_ON */

/**********************************************************************************************************************
 *
 *
 *  SLAVE
 *
 *
 *********************************************************************************************************************/

#if (CANTSYN_SLAVECONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Rx_Init
 *********************************************************************************************************************/
/*! \brief      Initialization of receive unit
 *  \details    -
 *  \param[in]  partitionIndex     Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_Init(CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_Update
 *********************************************************************************************************************/
/*! \brief      Update receive (Rx) unit
 *  \details    -
 *  \param[in]  partitionIndex     Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_Update(CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_GetSlaveIdxByDomainId
 *********************************************************************************************************************/
/*! \brief      Get the domainId of received message
 *  \details    Get the domainId stored in the message info considering also offset time domain calculation.
 *  \param[in]  domainId            Domain id
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     domainId            Valid domain index also considering whether domain is an offset or SYNC time domain
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(CanTSyn_SlaveConfigIterType, CANTSYN_CODE) CanTSyn_Rx_GetSlaveIdxByDomainId(
    uint8 domainId,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_GetDomainId
 *********************************************************************************************************************/
/*! \brief      Get the domainId of received message
 *  \details    Get the domainId stored in the message info considering also offset time domain calculation.
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \return     domainId            Valid domain index also considering whether domain is an offset or SYNC time domain
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(uint8, CANTSYN_CODE) CanTSyn_Rx_GetDomainId(
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo);

/**********************************************************************************************************************
 *  CanTSyn_Rx_ProcessRxIndication
 *********************************************************************************************************************/
/*! \brief      Dispatches the Rx Indication based on the state of the slave.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_ProcessRxIndication(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_UpdateSlaves
 *********************************************************************************************************************/
/*! \brief      Update configured slaves
 *  \details    -
 *  \param[in]  partitionIndex     Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_UpdateSlaves(CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_ResetStateToSync
 *********************************************************************************************************************/
/*! \brief      Resets the state of the slave to 'wait for SYNC'.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL FUNC(void, CANTSYN_CODE) CanTSyn_Rx_ResetStateToSync(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_UpdateWaitingForFollowUp
 *********************************************************************************************************************/
/*! \brief      Update the state 'wait for Rx follow-up message'.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Receive.Protocol
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_UpdateWaitingForFollowUp(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_ProcessReceivedSyncMsg
 *********************************************************************************************************************/
/*! \brief      Processes received SYNC/OFS messages
 *  \details    Retrieves reception time and payload of OFS/SYNC message.
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[in]  virtualLocalTime    Virtual Local Time
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_ProcessReceivedSyncMsg(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_DATA) virtualLocalTime,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_OnReceiveSyncMsg
 *********************************************************************************************************************/
/*! \brief      Receive SYNC message
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[in]  virtualLocalTime    Virtual Local Time
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Receive.Protocol.Sync
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnReceiveSyncMsg(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_DATA) virtualLocalTime,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_OnSuccessSyncReceive
 *********************************************************************************************************************/
/*! \brief      Perform actions after successfully received SYNC message.
 *  \details    Sets slave to the next state.
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Receive.Protocol.Sync
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnSuccessSyncReceive(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_ProcessReceivedFupMsg
 *********************************************************************************************************************/
/*! \brief      Processes received FUP/OFNS messages
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[in]  virtualLocalTime    Virtual Local Time
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_ProcessReceivedFupMsg(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_DATA) virtualLocalTime,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_OnReceiveFupMsg
 *********************************************************************************************************************/
/*! \brief      Receive FUP message.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[in]  virtualLocalTime    Virtual Local Time
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Receive.Protocol.Fup
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnReceiveFupMsg(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_DATA) virtualLocalTime,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

# if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Rx_OnReceiveOfnsMsg
 *********************************************************************************************************************/
/*! \brief      Receive OFNS message.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[in]  virtualLocalTime    Virtual Local Time
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Receive.Protocol.Fup
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnReceiveOfnsMsg(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_DATA) virtualLocalTime,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
# endif /* CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_Rx_OnSuccessFupReceive
 *********************************************************************************************************************/
/*! \brief      Perfom actions after successfully received SYNC message.
 *  \details    Actions are like: Set to next state, reset counter, etc.
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Receive.Protocol.Fup
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnSuccessFupReceive(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_OnFailedFupReceive
 *********************************************************************************************************************/
/*! \brief      Perform actions after unsuccessful received SYNC message.
 *  \details    Actions are like: Set no next state
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Receive.Protocol.Fup
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnFailedFupReceive(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_GetPayload
 *********************************************************************************************************************/
/*! \brief      Retrieve the payload from a FUP message.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[out] timeStamp           Retrieved timestamp
 *  \param[out] userData            Retrieved user data
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_GetPayload(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2VAR(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_VAR) timeStamp,
    P2VAR(StbM_UserDataType, AUTOMATIC, CANTSYN_APPL_VAR) userData,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

# if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Rx_GetOffsetPayload
 *********************************************************************************************************************/
/*! \brief      Retrieve the payload from an Offset message.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[out] timeStamp           Retrieved timestamp
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_GetOffsetPayload(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2VAR(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_VAR) timeStamp,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
# endif /* CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_Rx_OnGetTimeStamp
 *********************************************************************************************************************/
/*! \brief      Retrieve the time stamp from the payload of FUP message.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[out] timeStamp           Retrieved timestamp
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Receive.Protocol.DisassembleMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnGetTimeStamp(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2VAR(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_VAR) timeStamp,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

# if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Rx_OnGetOffsetTimeStamp
 *********************************************************************************************************************/
/*! \brief      Retrieve the timestamp payload from offset message.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[out] timeStamp           Retrieved timestamp
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Receive.Protocol.DisassembleMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnGetOffsetTimeStamp(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2VAR(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_VAR) timeStamp,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
# endif /* CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON */

# if ((CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON))
/**********************************************************************************************************************
 *  CanTSyn_Rx_OnGetUserDataCrc
 *********************************************************************************************************************/
/*! \brief      Retrieve the user data with CRC from payload of FUP message.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[out] userData            Retrieved user data
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Receive.Protocol.DisassembleMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnGetUserDataCrc(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2VAR(StbM_UserDataType, AUTOMATIC, CANTSYN_APPL_VAR) userData,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
# endif /* ((CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)) */

# if ((CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON))
/**********************************************************************************************************************
 *  CanTSyn_Rx_OnGetUserData
 *********************************************************************************************************************/
/*! \brief      Retrieve the user data without CRC from payload of FUP message.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[out] userData            Retrieved user data
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *  \unit       Receive.Protocol.DisassembleMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnGetUserData(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2VAR(StbM_UserDataType, AUTOMATIC, CANTSYN_APPL_VAR) userData,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
# endif /* ((CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)) */

/**********************************************************************************************************************
 *  CanTSyn_Rx_InitFollowUpTimeout
 *********************************************************************************************************************/
/*! \brief      Initialize the Rx follow-up timeout to zero.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_InitFollowUpTimeout(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_StopFollowUpTimeout
 *********************************************************************************************************************/
/*! \brief      Reset the Rx follow-up timeout to zero and stop timout handling.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_StopFollowUpTimeout(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_ResetFollowUpTimeout
 *********************************************************************************************************************/
/*! \brief      Reset the Rx follow-up timeout to the configured value.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_ResetFollowUpTimeout(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_UpdateFollowUpTimeout
 *********************************************************************************************************************/
/*! \brief      Update the Rx follow-up timeout.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_UpdateFollowUpTimeout(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_IsFollowUpTimeoutExpired
 *********************************************************************************************************************/
/*! \brief      Check if Rx follow-up timeout is expired.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  partitionIndex      Valid partition index
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_IsFollowUpTimeoutExpired(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateSync
 *********************************************************************************************************************/
/*! \brief      Validate the SYNC/OFS message
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                All conditions for received SYNC message are valid
 *  \return     FALSE               At least one the validation check failed
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateSync(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateFup
 *********************************************************************************************************************/
/*! \brief      Validate the FUP/OFNS message
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Received MsgInfo
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                All conditions for received FUP message are valid
 *  \return     FALSE               At least one the validation check failed
 *  \pre        -
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateFup(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateSyncMessageType
 *********************************************************************************************************************/
/*! \brief      Validate the message type
 *  \details    Validate if the message type is either SYNC or OFS, and if it is CRC secured or not secured.
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \return     TRUE                Message type fits any of the defined message types
 *  \return     FALSE               No corresponding message type was found
 *  \pre        -
 *  \unit       Receive.ValidationMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateSyncMessageType(
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo);

/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateFupMessageType
 *********************************************************************************************************************/
/*! \brief      Validate the message type
 *  \details    Validate if the message type is either FUP or OFNS, and if it is CRC secured or not secured.
 *  \param[in]  ptrMsgInfo          Received MsgInfo
 *  \return     TRUE                Message type fits any of the defined message types
 *  \return     FALSE               No corresponding message type was found
 *  \pre        -
 *  \unit       Receive.ValidationMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateFupMessageType(
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo);

/**********************************************************************************************************************
 *  CanTSyn_Rx_HasRefTimebaseTimeout
 *********************************************************************************************************************/
/*! \brief      Check if timeout occurred at referred timebase.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                At referred timebase a timeout occurred
 *  \return     FALSE               No timeout or retrieval of timebase status was not working
 *  \pre        -
 *  \unit       Receive.ValidationMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_HasRefTimebaseTimeout(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateSequenceCounterSync
 *********************************************************************************************************************/
/*! \brief      Validate the sequence counter in the SYNC/OFS message.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                The received sequence counter is valid
 *  \return     FALSE               The received sequence counter is invalid
 *  \pre        -
 *  \unit       Receive.ValidationMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateSequenceCounterSync(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_CalculateSequenceCounterJumpWidth
 *********************************************************************************************************************/
/*! \brief      Calculate the jump with between last received sequence counter and given one.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  sequenceCounter     Received sequence counter
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     jumpWidth           Calculated jump width
 *  \pre        -
 *  \unit       Receive.ValidationMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(uint8, CANTSYN_CODE) CanTSyn_Rx_CalculateSequenceCounterJumpWidth(
    CanTSyn_SlaveConfigIterType slaveIdx,
    uint8 sequenceCounter,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

# if ((CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON))
/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateCrcSync
 *********************************************************************************************************************/
/*! \brief      Validate the CRC in the SYNC message.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                CRC is valid
 *  \return     FALSE               CRC is invalid
 *  \pre        -
 *  \unit       Receive.ValidationMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateCrcSync(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateCrcFup
 *********************************************************************************************************************/
/*! \brief      Validate the CRC in the FUP message.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                CRC is valid
 *  \return     FALSE               CRC is invalid
 *  \pre        -
 *  \unit       Receive.ValidationMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateCrcFup(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
# endif /* ((CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)) */

/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateSequenceCounterFup
 *********************************************************************************************************************/
/*! \brief      Validate the sequence counter in the FUP message.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                Sequence counter is valid
 *  \return     FALSE               Sequence counter is invalid
 *  \pre        -
 *  \unit       Receive.ValidationMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateSequenceCounterFup(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateNanosecondsFup
 *********************************************************************************************************************/
/*! \brief      Validate the range of the nanoseconds in received MsgInfo.
 *  \details    -
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \return     TRUE                Nanoseconds in received time are in valid range
 *  \return     FALSE               Nanoseconds in received time are not in valid range
 *  \pre        -
 *  \unit       Receive.ValidationMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateNanosecondsFup(
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo);

# if ((CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON))
#  if (CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Rx_OnValidateCrcIgnored
 *********************************************************************************************************************/
/*! \brief      Validate the CRC for CRC-IGNORED configured slave.
 *  \details    -
 *  \return     TRUE                always TRUE, since CRC gets ignored
 *  \pre        -
 *  \unit       Receive.ValidationMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_OnValidateCrcIgnored(void);
#  endif /* CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON */
# endif /* ((CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON))*/

# if (CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Rx_OnValidateSyncCrcNotValidated
 *********************************************************************************************************************/
/*! \brief      Validate the CRC in SYNC message for CRC-NOT_VALIDATED configured slave.
 *  \details    -
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \return     TRUE                Message type has no CRC
 *  \return     FALSE               Message type has CRC
 *  \pre        -
 *  \unit       Receive.ValidationMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_OnValidateSyncCrcNotValidated(
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo);

/**********************************************************************************************************************
 *  CanTSyn_Rx_OnValidateFupCrcNotValidated
 *********************************************************************************************************************/
/*! \brief      Validate the CRC in FUP message for CRC-NOT_VALIDATED configured slave.
 *  \details    -
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \return     TRUE                Message type has no CRC
 *  \return     FALSE               Message type has CRC
 *  \pre        -
 *  \unit       Receive.ValidationMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_OnValidateFupCrcNotValidated(
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo);
# endif /* CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON */

# if (CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Rx_OnValidateSyncCrcValidated
 *********************************************************************************************************************/
/*! \brief      Validate the CRC in SYNC message for CRC-VALIDATED configured slave.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                Message has CRC set and the CRC is valid
 *  \return     FALSE               Message does not contain CRC or CRC value check failed
 *  \pre        -
 *  \unit       Receive.ValidationMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_OnValidateSyncCrcValidated(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);

/**********************************************************************************************************************
 *  CanTSyn_Rx_OnValidateFupCrcValidated
 *********************************************************************************************************************/
/*! \brief      Validate the CRC in FUP message for CRC-VALIDATED configured slave.
 *  \details    -
 *  \param[in]  slaveIdx            Valid slave index
 *  \param[in]  ptrMsgInfo          Pointer to received message
 *  \param[in]  partitionIndex      Valid partition index
 *  \return     TRUE                Message has CRC set and the CRC is valid
 *  \return     FALSE               Message does not contain CRC or CRC value check failed
 *  \pre        -
 *  \unit       Receive.ValidationMsg
 *  \visibility Private
 *********************************************************************************************************************/
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_OnValidateFupCrcValidated(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex);
# endif /* CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON */
#endif /* CANTSYN_SLAVECONFIG == STD_ON */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#if (CANTSYN_MULTIPARTITION_USED == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_GetCurrentPartitionIndexByOsApplication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL FUNC(CanTSyn_PartitionIdentifiersIterType, CANTSYN_CODE) CanTSyn_GetCurrentPartitionIndexByOsApplication(ApplicationType osAppId)
{
  /* ----- Local Variables ---------------------------------------------- */
  CanTSyn_PartitionIdentifiersIterType i;

  /* #10 Set partition index to infinite */
  CanTSyn_PartitionIdentifiersIterType partitionIdx = CANTSYN_MAX_PARTITION_INDEX_VALUE;

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Find partition index by application id in os application to partition mapping table */
  for (i = 0u; i < CanTSyn_GetSizeOfPartitionIdentifiers(); i++)
  {
    if (CanTSyn_GetPartitionSNVOfPartitionIdentifiers(i) == osAppId)
    {
      partitionIdx = CanTSyn_GetPCPartitionConfigIdxOfPartitionIdentifiers(i);
      break;
    }
  }

  return partitionIdx;
} /* CanTSyn_GetCurrentPartitionIndexByOsApplication */

# if (CANTSYN_MASTERCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_GetCurrentPartitionIndexByControllerId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL FUNC(CanTSyn_PartitionIdentifiersIterType, CANTSYN_CODE) CanTSyn_GetCurrentPartitionIndexByControllerId(uint8 ctrIdx)
{
  /* ----- Local Variables ---------------------------------------------- */
  CanTSyn_PartitionIdentifiersIterType i;

  /* #10 Set partition index to infinite */
  CanTSyn_PartitionIdentifiersIterType partitionIdx = CANTSYN_MAX_PARTITION_INDEX_VALUE;

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Find partition index by controller id in controller id to partition mapping table */
  for (i = 0u; i < CanTSyn_GetSizeOfControllerPduPartitionMapping(); i++)
  {
    if (CanTSyn_GetControllerIdOfControllerPduPartitionMapping(i) == ctrIdx)
    {
      partitionIdx = CanTSyn_GetPartitionConfigIdxOfControllerPduPartitionMapping(i);
      break;
    }
  }

  return partitionIdx;
} /* CanTSyn_GetCurrentPartitionIndexByControllerId */

/**********************************************************************************************************************
 *  CanTSyn_GetCurrentPartitionIndexByMasterPdu
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL FUNC(CanTSyn_PartitionIdentifiersIterType, CANTSYN_CODE) CanTSyn_GetCurrentPartitionIndexByMasterPdu(PduIdType txPduId)
{
  /* ----- Local Variables ---------------------------------------------- */
  CanTSyn_PartitionIdentifiersIterType i;

  /* #10 Set partition index to infinite */
  CanTSyn_PartitionIdentifiersIterType partitionIdx = CANTSYN_MAX_PARTITION_INDEX_VALUE;

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Find partition index by master pdu in slave pdu to partition mapping table */
  for (i = 0u; i < CanTSyn_GetSizeOfMasterPduPartitionMapping(); i++)
  {
    if (CanTSyn_GetPduIdOfMasterPduPartitionMapping(i) == txPduId)
    {
      partitionIdx = CanTSyn_GetPartitionConfigIdxOfMasterPduPartitionMapping(i);
      break;
    }
  }

  return partitionIdx;
} /* CanTSyn_GetCurrentPartitionIndexByMasterPdu */
#endif /* # CANTSYN_MASTERCONFIG == STD_ON */

# if (CANTSYN_SLAVECONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_GetCurrentPartitionIndexBySlavePdu
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL FUNC(CanTSyn_PartitionIdentifiersIterType, CANTSYN_CODE) CanTSyn_GetCurrentPartitionIndexBySlavePdu(PduIdType rxPduId)
{
  /* ----- Local Variables ---------------------------------------------- */
  CanTSyn_PartitionIdentifiersIterType i;

  /* #10 Set partition index to infinite */
  CanTSyn_PartitionIdentifiersIterType partitionIdx = CANTSYN_MAX_PARTITION_INDEX_VALUE;

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Find partition index by slave pdu in slave pdu to partition mapping table */
  for (i = 0u; i < CanTSyn_GetSizeOfSlavePduPartitionMapping(); i++)
  {
    if (CanTSyn_GetPduIdOfSlavePduPartitionMapping(i) == rxPduId)
    {
      partitionIdx = CanTSyn_GetPartitionConfigIdxOfSlavePduPartitionMapping(i);
      break;
    }
  }

  return partitionIdx;
} /* CanTSyn_GetCurrentPartitionIndexBySlavePdu */
# endif /* CANTSYN_SLAVECONFIG == STD_ON */

#endif /* CANTSYN_MULTIPARTITION_USED == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_TimestampPlusTimestamp
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_TimestampPlusTimestamp(
        P2CONST(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_DATA) timestamp1Ptr,
        P2CONST(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_DATA) timestamp2Ptr,
        P2VAR(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_VAR) timesumPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add the two timestamps */
  timesumPtr->nanoseconds = timestamp1Ptr->nanoseconds + timestamp2Ptr->nanoseconds; /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
  timesumPtr->seconds = timestamp1Ptr->seconds + timestamp2Ptr->seconds; /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
  timesumPtr->secondsHi = timestamp1Ptr->secondsHi + timestamp2Ptr->secondsHi; /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */

  /* #20 Verify that no overflow of nanoseconds occurred */
  /* no real overflow of nanoseconds possible, since max value is 10^9 - 1 */
  if (timesumPtr->nanoseconds > CANTSYN_TIMESTAMP_MAX_NANOSECONDS)
  {
    timesumPtr->seconds++; /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
    timesumPtr->nanoseconds -= CANTSYN_NANOSECONDS_IN_ONE_SECOND; /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
  }

  /* #30 Verify that no overflow of seconds occurred */
  if (timesumPtr->seconds < (timestamp1Ptr->seconds | timestamp2Ptr->seconds))
  {
    timesumPtr->secondsHi++; /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
  }

  /* #40 Verify that no overflow of seconds high occurred */
  /* calculated sum is invalid, if overflow of seconds high occurred */
  if ((timesumPtr->secondsHi >= timestamp1Ptr->secondsHi) && (timesumPtr->secondsHi >= timestamp2Ptr->secondsHi))
  {
    retVal = E_OK;
  }

  return retVal;
} /* CanTSyn_TimestampPlusTimestamp */

/**********************************************************************************************************************
 *  CanTSyn_SubtractVirtualLocalTime
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_SubtractVirtualLocalTime(
    P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_DATA) lhs,
    P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_DATA) rhs,
    P2VAR(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_VAR) timediffPtr)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint64 left;
  uint64 right;
  uint64 timespan;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Convert StbM_VirtualLocalTimeType to uint64 */
  left = ((((uint64)lhs->nanosecondsHi) << 32u) + lhs->nanosecondsLo);
  right = ((((uint64)rhs->nanosecondsHi) << 32u) + rhs->nanosecondsLo);

  /* #20 If left time is greater than or equal to right time: */
  if (left >= right)
  {
    /* #30 Calculate time difference */
    timespan = (left - right); /* (left - right) */

    /* #40 Convert uint64 to StbM_VirtualLocalTimeType */
    timediffPtr->nanosecondsLo = (uint32)(timespan & 0x00000000FFFFFFFFu); /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
    timediffPtr->nanosecondsHi = (uint32)((timespan & 0xFFFFFFFF00000000u) >> 32u); /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */

    retVal = E_OK;
  }
  return retVal;
} /* CanTSyn_SubtractVirtualLocalTime */

/**********************************************************************************************************************
 *  CanTSyn_VirtualLocalTimeToTimestamp
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_VirtualLocalTimeToTimestamp(
    P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_DATA) timePtr,
    P2VAR(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_VAR) timestampPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint64 timespan;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Convert StbM_VirtualLocalTimeType to uint64 */
  timespan = ((((uint64)timePtr->nanosecondsHi) << 32u) + timePtr->nanosecondsLo);

  /* #20 Calculate StbM_TimeStampType from uint64 */
  timestampPtr->secondsHi = (uint16) ((timespan / (uint64)CANTSYN_NANOSECONDS_IN_ONE_SECOND) / ((uint64)CANTSYN_TIMESTAMP_MAX_SECONDS + 1u)); /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
  timestampPtr->seconds = (uint32) ((timespan / (uint64)CANTSYN_NANOSECONDS_IN_ONE_SECOND) % ((uint64)CANTSYN_TIMESTAMP_MAX_SECONDS + 1u)); /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
  timestampPtr->nanoseconds = (uint32) (timespan % (uint64)CANTSYN_NANOSECONDS_IN_ONE_SECOND); /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
} /* CanTSyn_VirtualLocalTimeToTimestamp */

#if (CANTSYN_CRC_USED == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_CalculateMsgCrc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL FUNC(uint8, CANTSYN_CODE) CanTSyn_CalculateMsgCrc(
    P2CONST(uint8, AUTOMATIC, CANTSYN_APPL_DATA) ptrDataId,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    uint32 crcLength)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 crcResult;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate CRC over byte 2-7 */
  crcResult = Crc_CalculateCRC8H2F(&((*ptrMsgInfo)[2]), crcLength, CANTSYN_CRC_START_VALUE, TRUE); /* SBSW_CANTSYN_ACCESS_CANMSG */ /* VCA_CANTSYN_CALL_EXTERNAL_FUNCTION_WITH_CONST_POINTER_ARGUMENT */

  /* #20 Calculate CRC with dataId */
  crcResult = Crc_CalculateCRC8H2F(ptrDataId, 1u, crcResult, FALSE); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */ /* VCA_CANTSYN_CALL_EXTERNAL_FUNCTION_WITH_CONST_POINTER_ARGUMENT */

  return crcResult;
} /* CanTSyn_CalculateMsgCrc */

/**********************************************************************************************************************
 *  CanTSyn_GetCrcLength
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(uint32, CANTSYN_CODE) CanTSyn_GetCrcLength(
    CanTSyn_DomainConfigIterType domainIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Calculate the length of the CRC depending on the message length */
  return ((uint32)CanTSyn_GetMessageDlcOfDomainConfig(domainIdx, partitionIndex) - 2u);
} /* CanTSyn_GetCrcLength */
#endif /* CANTSYN_CRC_USED == STD_ON */

#if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_IsOffsetDomain
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_IsOffsetDomain(
    CanTSyn_DomainConfigIterType domainIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Check if the given domain is an offset domain */
  return (boolean) (CanTSyn_GetOffsetDomainOfDomainConfig(domainIdx, partitionIndex) == CANTSYN_OFFSET_OFFSETDOMAINOFDOMAINCONFIG); /* PRQA S 1881, 4304 */ /* MD_MSR_AutosarBoolean */
} /* CanTSyn_IsOffsetDomain */
#endif /* CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON */


/**********************************************************************************************************************
 *
 *
 *  MASTER
 *
 *
 *********************************************************************************************************************/

#if (CANTSYN_MASTERCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_Init(CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* #10 Initialize masters */
  CanTSyn_Tx_InitMasters(partitionIndex);

# if (CANTSYN_EXISTS_SHARED_PDUS == STD_ON)
  /* #20 Initialize PduId states */
  CanTSyn_Tx_InitPduIdStates(partitionIndex);
# endif

  /* #30 If debouncing is configured: */
# if (CANTSYN_TXDEBOUNCECOUNTERIDXOFMASTERCONFIG == STD_ON)
  /* #40 Initialize debouncing */
  CanTSyn_Tx_InitDebounceCounter(partitionIndex);
# endif
} /* CanTSyn_Tx_Init */

/**********************************************************************************************************************
 *  CanTSyn_Tx_Update
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_Update(CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* #10 Update masters */
  CanTSyn_Tx_UpdateMasters(partitionIndex);

# if (CANTSYN_TXDEBOUNCECOUNTERIDXOFMASTERCONFIG == STD_ON)
  /* #20 Update Tx debouncing, if configured */
  CanTSyn_Tx_UpdateDebounceCounter(partitionIndex);
# endif
} /* CanTSyn_Tx_Update */

/**********************************************************************************************************************
 *  CanTSyn_Tx_InitMasters
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
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_InitMasters(CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  CanTSyn_MasterConfigIterType masterIdx;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each configured master: */
  for (masterIdx = 0u; masterIdx < CanTSyn_GetSizeOfMasterConfig(partitionIndex); masterIdx++)
  {
    /* #20 Initialize Tx period counter to zero */
    CanTSyn_Tx_StopTxPeriodCounter(masterIdx, partitionIndex);

    /* #30 Set initial state of master to: wait to send a SYNC message */
    CanTSyn_SetStateOfMasterState(masterIdx, CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */

    /* #40 Initialize the sequence counter to the maximum value */
    CanTSyn_Tx_InitTxSequenceCounter(masterIdx, partitionIndex);

    /* #50 Initialize Tx confirmation timeout to zero */
    CanTSyn_Tx_InitTxConfirmationTimeout(masterIdx, partitionIndex);

    /* #60 If immediate send mode is configured: */
# if (CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON)
    /* #70 Initialize the immediate send mode */
    CanTSyn_Tx_InitImmediateSendMode(masterIdx, partitionIndex);
# endif
  }
} /* CanTSyn_Tx_InitMasters */

# if (CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_InitImmediateSendMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_InitImmediateSendMode(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Reset the flag to identify an immediate sent of SYNC message to false */
  CanTSyn_SetTransmitImmediateSyncOfMasterState(masterIdx, FALSE, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */

  /* #20 Reset last stored time base update counter to zero */
  CanTSyn_SetLastUpdateCounterOfMasterState(masterIdx, 0u, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */

  /* #30 Initialize cyclic message resume counter */
  CanTSyn_Tx_InitCyclicMsgResumeCounter(masterIdx, partitionIndex);
} /* CanTSyn_Tx_InitImmediateSendMode */
# endif /* CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateMasters
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
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateMasters(CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  CanTSyn_MasterConfigIterType masterIdx;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each configured master: */
  for (masterIdx = 0u; masterIdx < CanTSyn_GetSizeOfMasterConfig(partitionIndex); masterIdx++)
  {
    /* #20 Update Tx counters */
    CanTSyn_Tx_UpdateCounters(masterIdx, partitionIndex);

    /* #30 Switch to current state: */
    switch (CanTSyn_GetStateOfMasterState(masterIdx, partitionIndex))
    {
      case CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND:
        /* #40 Update send SYNC state */
        CanTSyn_Tx_UpdateWaitingForSyncSend(masterIdx, partitionIndex);
        break;

      case CANTSYN_STATE_SEND_WAITING_FOR_FOLLOW_UP_SEND:
        /* #50 Update send FUP state */
        CanTSyn_Tx_UpdateWaitingForFupSend(masterIdx, partitionIndex);
        break;

      case CANTSYN_STATE_SEND_WAITING_FOR_SYNC_TX_CONFIRMATION:
      case CANTSYN_STATE_SEND_WAITING_FOR_FOLLOW_UP_TX_CONFIRMATION:
        /* #60 Update wait for SYNC or FUP Tx confirmation state */
        CanTSyn_Tx_UpdateWaitingForTxConfirmation(masterIdx, partitionIndex);
        break;

      default: /* COV_CANTSYN_MSR_MISRA */
        /* #70 there is no default case */
        break;
    }
  }
} /* CanTSyn_Tx_UpdateMasters */

/**********************************************************************************************************************
*  CanTSyn_Tx_ProcessTxConfirmation
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
CANTSYN_LOCAL_INLINE FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_Tx_ProcessTxConfirmation(
    PduIdType txPduId,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  CanTSyn_MasterConfigIterType masterIdx;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each configured master: */
  for (masterIdx = 0u; masterIdx < CanTSyn_GetSizeOfMasterConfig(partitionIndex); masterIdx++)
  {
    /* #20 Find master with provided PduId */
    if (CanTSyn_GetMasterConfHandleIdOfMasterConfig(masterIdx, partitionIndex) == txPduId) /* COV_CANTSYN_TXCONFIRMATION_VALID_OTHER_OR_INVALID_PDUID */
    {
      retVal = E_OK;

      /* #30 Dispatch master state to: */
      switch (CanTSyn_GetStateOfMasterState(masterIdx, partitionIndex))
      {
        case CANTSYN_STATE_SEND_WAITING_FOR_SYNC_TX_CONFIRMATION:
          /* #40 Handle SYNC/OFS Tx confirmation */
          CanTSyn_Tx_OnSyncTxConfirmation(masterIdx, partitionIndex);
          break;
        case CANTSYN_STATE_SEND_WAITING_FOR_FOLLOW_UP_TX_CONFIRMATION:
          /* #50 Handle FUP/OFNS Tx confirmation */
          CanTSyn_Tx_OnFupTxConfirmation(masterIdx, partitionIndex);
          break;
        default:
          /* #60 ignore Tx confirmation for unexpected states */
          break;
      }
    }
  }

  return retVal;
} /* CanTSyn_Tx_ProcessTxConfirmation */

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateCounters
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateCounters(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* #10 Update Tx period counter */
  CanTSyn_Tx_UpdateTxPeriodCounter(masterIdx, partitionIndex);

  /* #20 If immediate send mode is configured: */
# if (CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON)
  /* #30 Update cyclic message resume counter */
  CanTSyn_Tx_UpdateCyclicMsgResumeCounter(masterIdx, partitionIndex);
# endif
} /* CanTSyn_Tx_UpdateCounters */

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateWaitingForTxConfirmation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateWaitingForTxConfirmation(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* #10 Enter critical area: Concurrent access to TxConfirmationTimeout in TxConfirmation and state transition */
  SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();

  /* #20 Update Tx confirmation timeout */
  CanTSyn_Tx_UpdateTxConfirmationTimeout(masterIdx, partitionIndex);

  /* #30 If Tx confirmation timeout or Tx period expired: */
  if ((CanTSyn_Tx_IsTxConfirmationTimeoutExpired(masterIdx, partitionIndex) == TRUE) || (CanTSyn_Tx_IsTxPeriodTimeExpired(masterIdx, partitionIndex) == TRUE)) /* COV_CANTSYN_TXCONFIRMATIONTIMEOUT */
  {
    /* #40 Perform actions for unsuccessful transmit */
    CanTSyn_Tx_OnFailedTransmit(masterIdx, partitionIndex);
  }

  /* #50 Exit critical area */
  SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
} /* CanTSyn_Tx_UpdateWaitingForTxConfirmation */

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnFailedTransmit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnFailedTransmit(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Reset master to 'wait to send SYNC' state */
  CanTSyn_SetStateOfMasterState(masterIdx, CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */

# if (CANTSYN_EXISTS_SHARED_PDUS == STD_ON)
  /* #20 Free the blocked PduId state */
  CanTSyn_Tx_ReleasePduId(masterIdx, partitionIndex);
# endif
} /* CanTSyn_Tx_OnFailedTransmit */

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateWaitingForSyncSend
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateWaitingForSyncSend(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* #10 If send conditions for SYNC/OFS message are met: */
  if (CanTSyn_Tx_ValidateSendSyncConditions(masterIdx, partitionIndex) == TRUE)
  {
    /* #20 Transmit SYNC/OFS message */
    CanTSyn_Tx_TransmitSync(masterIdx, partitionIndex);
  }
} /* CanTSyn_Tx_UpdateWaitingForSyncSend */

/**********************************************************************************************************************
*  CanTSyn_Tx_OnSyncTxConfirmation
*********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnSyncTxConfirmation(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get time of real SYNC transmission for FUP message */
  retVal = CanTSyn_Tx_GetTimeFup(masterIdx, partitionIndex);

  /* #20 If time retrieval was successful: */
  if (retVal == E_OK)
  {
    /* #30 Set the master to state: 'wait to send FUP' */
    CanTSyn_SetStateOfMasterState(masterIdx, CANTSYN_STATE_SEND_WAITING_FOR_FOLLOW_UP_SEND, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
  }
  else
  {
    /* #40 Otherwise set the master to state: 'wait for SYNC send' */
    CanTSyn_SetStateOfMasterState(masterIdx, CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
  }

  /* #50 If debouncing configured, reset the Tx debounce counter back to the configured value */
# if (CANTSYN_TXDEBOUNCECOUNTERIDXOFMASTERCONFIG == STD_ON)
  CanTSyn_Tx_ResetDebounceCounter(masterIdx, partitionIndex);
# endif
} /* CanTSyn_Tx_OnSyncTxConfirmation */

/**********************************************************************************************************************
 *  CanTSyn_Tx_TransmitSync
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
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_TransmitSync(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Enter critical area: Accuracy of transmitted time, state transition and PduId lock consistent to actual transmission */
  SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();

  /* #20 Get time for SYNC/OFS message, if succeeded: */
  if (CanTSyn_Tx_GetTimeSync(masterIdx, partitionIndex) == E_OK)
  {
    /* ----- Local Variables ---------------------------------------------- */
    PduInfoType pduInfo;
    CanTSyn_CanMsgType syncMsg = { 0u };

    /* #30 Prepare PduInfo */
    pduInfo.SduLength  = CanTSyn_GetMessageDlcOfDomainConfig(CanTSyn_GetDomainConfigIdxOfMasterConfig(masterIdx, partitionIndex), partitionIndex);
    pduInfo.SduDataPtr = syncMsg;

    /* #40 Increment Tx sequence counter */
    CanTSyn_Tx_IncrementTxSequenceCounter(masterIdx, partitionIndex);

    /* #50 Assemble SYNC/OFS message */
    CanTSyn_Tx_AssembleSyncMsg(masterIdx, &syncMsg, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */

    /* #60 Transmit SYNC/OFS message, if transmission succeeded: */
    if (CanIf_Transmit(CanTSyn_GetTxPduIdOfMasterConfig(masterIdx, partitionIndex), &pduInfo) == E_OK) /* SBSW_CANTSYN_FUNCTIONCALL_PDUINFO */ /* VCA_CANTSYN_CALL_EXTERNAL_FUNCTION_WITH_CONST_POINTER_ARGUMENT */
    {
      /* #70 Run actions for succeeded transmission */
      CanTSyn_Tx_OnSuccessTransmitSync(masterIdx, partitionIndex);
    }
  }
  /* #80 Exit critical area */
  SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
} /* CanTSyn_Tx_TransmitSync */

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnSuccessTransmitSync
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
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnSuccessTransmitSync(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set next state to: wait for SYNC Tx confirmation */
  CanTSyn_SetStateOfMasterState(masterIdx, CANTSYN_STATE_SEND_WAITING_FOR_SYNC_TX_CONFIRMATION, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */

# if (CANTSYN_EXISTS_SHARED_PDUS == STD_ON)
  /* #20 Block specific PduId of the given master in order to not interrupt SYNC-FUP sequence */
  CanTSyn_Tx_LockPduId(masterIdx, partitionIndex);
# endif

  /* #30 Reset Tx confirmation timeout to configured value */
  CanTSyn_Tx_ResetTxConfirmationTimeout(masterIdx, partitionIndex);

# if (CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON)
  /* #40 If SYNC/OFS send was immediate: */
  if (CanTSyn_IsTransmitImmediateSyncOfMasterState(masterIdx, partitionIndex))
  {
    /* #50 Reset cyclic message resume counter to configured value */
    CanTSyn_Tx_ResetCyclicMsgResumeCounter(masterIdx, partitionIndex);

    /* #60 Enable direct transmit after cyclic message resume time */
    CanTSyn_Tx_StopTxPeriodCounter(masterIdx, partitionIndex);

    /* #70 Reset flag for immediate SYNC/OFS transmission to false */
    CanTSyn_SetTransmitImmediateSyncOfMasterState(masterIdx, FALSE, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
  }
  else
# endif
  {
    /* #80 Reset Tx period counter to configured value */
    CanTSyn_Tx_ResetTxPeriodCounter(masterIdx, partitionIndex);
  }
} /* CanTSyn_Tx_OnSuccessTransmitSync */

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateWaitingForFupSend
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateWaitingForFupSend(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* #10 If send conditions for FUP/OFNS message are met: */
  if (CanTSyn_Tx_ValidateSendFupConditions(masterIdx, partitionIndex) == TRUE)
  {
    /* #20 Transmit FUP message */
    CanTSyn_Tx_TransmitFup(masterIdx, partitionIndex);
  }
} /* CanTSyn_Tx_UpdateWaitingForFupSend */

/**********************************************************************************************************************
*  CanTSyn_Tx_OnFupTxConfirmation
*********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnFupTxConfirmation(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Set the master to state: 'wait to send SYNC' */
  CanTSyn_SetStateOfMasterState(masterIdx, CANTSYN_STATE_SEND_WAITING_FOR_SYNC_SEND, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */

# if (CANTSYN_EXISTS_SHARED_PDUS == STD_ON)
  /* #20 Release PduId */
  CanTSyn_Tx_ReleasePduId(masterIdx, partitionIndex);
# endif

  /* #30 If debouncing configured, reset the Tx debounce counter back to the configured value */
# if (CANTSYN_TXDEBOUNCECOUNTERIDXOFMASTERCONFIG == STD_ON)
  CanTSyn_Tx_ResetDebounceCounter(masterIdx, partitionIndex);
# endif
} /* CanTSyn_Tx_OnFupTxConfirmation */

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnSuccessFupTransmit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnSuccessFupTransmit(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set next state to: wait for FUP Tx confirmation */
  CanTSyn_SetStateOfMasterState(masterIdx, CANTSYN_STATE_SEND_WAITING_FOR_FOLLOW_UP_TX_CONFIRMATION, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */

  /* #20 Reset Tx confirmation timeout to configured value */
  CanTSyn_Tx_ResetTxConfirmationTimeout(masterIdx, partitionIndex);
} /* CanTSyn_Tx_OnSuccessFupTransmit */

/**********************************************************************************************************************
 *  CanTSyn_Tx_TransmitFup
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
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_TransmitFup(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  PduInfoType pduInfo;
  CanTSyn_CanMsgType fupMsg = { 0u };

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Prepare PduInfo */
  pduInfo.SduLength  = CanTSyn_GetMessageDlcOfDomainConfig(CanTSyn_GetDomainConfigIdxOfMasterConfig(masterIdx, partitionIndex), partitionIndex);
  pduInfo.SduDataPtr = fupMsg;

  /* #20 Assembly FUP/OFNS message */
  CanTSyn_Tx_AssembleFupMsg(masterIdx, &fupMsg, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */

  /* #30 Enter critical area: State transition consistent to actual transmission */
  SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();

  /* #40 Transmit FUP/OFNS message, if transmission succeeded: */
  if (CanIf_Transmit(CanTSyn_GetTxPduIdOfMasterConfig(masterIdx, partitionIndex), &pduInfo) == E_OK) /* SBSW_CANTSYN_FUNCTIONCALL_PDUINFO */ /* VCA_CANTSYN_CALL_EXTERNAL_FUNCTION_WITH_CONST_POINTER_ARGUMENT */
  {
    /* #50 Run actions for succeeded transmission */
    CanTSyn_Tx_OnSuccessFupTransmit(masterIdx, partitionIndex);
  }
  /* #60 Exit critical area */
  SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
} /* CanTSyn_Tx_TransmitFup */

/**********************************************************************************************************************
 *  CanTSyn_Tx_GetTimeSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_Tx_GetTimeSync(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
# if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
  if (CanTSyn_IsOffsetDomain(CanTSyn_GetDomainConfigIdxOfMasterConfig(masterIdx, partitionIndex), partitionIndex) == TRUE)
  {
    /* #10 For OFS get the OFS time */
    retVal = CanTSyn_Tx_OnGetTimeOfs(masterIdx, partitionIndex);
  }
  else
# endif
  {
    /* #20 For SYNC get the SYNC time */
    retVal = CanTSyn_Tx_OnGetTimeSync(masterIdx, partitionIndex);
  }

  return retVal;
} /* CanTSyn_Tx_GetTimeSync */

/**********************************************************************************************************************
 *  CanTSyn_Tx_GetTimeFup
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_Tx_GetTimeFup(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
# if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
  if (CanTSyn_IsOffsetDomain(CanTSyn_GetDomainConfigIdxOfMasterConfig(masterIdx, partitionIndex), partitionIndex) == TRUE)
  {
    /* #10 For offset there is nothing more to do */
    retVal = E_OK;
  }
  else
#endif
  {
    /* #20 For FUP get the FUP time */
    retVal = CanTSyn_Tx_OnGetTimeFup(masterIdx, partitionIndex);
  }

  return retVal;
} /* CanTSyn_Tx_GetTimeFup */

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnGetTimeSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_Tx_OnGetTimeSync(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_TimeStampType currentGlobalTimeTSync = { 0u };
  StbM_VirtualLocalTimeType localTimeT0Vlt = { 0u };
  StbM_UserDataType userData = { 0u };

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get current Synchronized Time Base's Time Tuple from StbM */
  retVal = StbM_BusGetCurrentTime(CanTSyn_GetTimeBaseIdOfDomainConfig(CanTSyn_GetDomainConfigIdxOfMasterConfig(masterIdx, partitionIndex), partitionIndex), &currentGlobalTimeTSync, &localTimeT0Vlt, &userData); /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */ /* VCA_CANTSYN_CALL_STBM_FUNCTION_WITH_VAR_POINTER_ARGUMENT */

  /* #20 If time retrieval was successful and time base is synchronized: */
  if ((retVal == E_OK) && (CanTSyn_GetGlobalTimeBaseBit(currentGlobalTimeTSync.timeBaseStatus) != 0u))
  {
    /* #30 Store current GlobalTime and UserData */
    CanTSyn_SetSyncTimestampOfMasterState(masterIdx, currentGlobalTimeTSync, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
    CanTSyn_SetUserDataOfMasterState(masterIdx, userData, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */

    /* #40 Set current Virtual Local Time value from StbM */
    CanTSyn_SetVirtualLocalTimeOfMasterState(masterIdx, localTimeT0Vlt, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
  }

  /* #50 Check if time base is not synchronized */
  if ((CanTSyn_GetGlobalTimeBaseBit(currentGlobalTimeTSync.timeBaseStatus) == 0u))
  {
    retVal = E_NOT_OK;
  }

  return retVal;
} /* CanTSyn_Tx_OnGetTimeSync */

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnGetTimeFup
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_Tx_OnGetTimeFup(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_VirtualLocalTimeType localTimeT0Vlt;
  StbM_VirtualLocalTimeType localTimeT1Vlt = { 0u };
  StbM_VirtualLocalTimeType timeDelta = { 0u };
  StbM_TimeStampType syncTime;
  StbM_TimeStampType sumTimeStamp = { 0u };
  StbM_TimeStampType timestamp = { 0u };

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get current Virtual Local Time value from StbM */
  retVal = StbM_GetCurrentVirtualLocalTime(CanTSyn_GetTimeBaseIdOfDomainConfig(CanTSyn_GetDomainConfigIdxOfMasterConfig(masterIdx, partitionIndex), partitionIndex), &localTimeT1Vlt); /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */ /* VCA_CANTSYN_CALL_STBM_FUNCTION_WITH_VAR_POINTER_ARGUMENT */

  syncTime.secondsHi = 0u;
  syncTime.seconds = 0u;
  syncTime.nanoseconds = CanTSyn_GetSyncTimestampOfMasterState(masterIdx, partitionIndex).nanoseconds;
  localTimeT0Vlt = CanTSyn_GetVirtualLocalTimeOfMasterState(masterIdx, partitionIndex);

  /* #20 Subtract the time t0 from t1 and convert the difference to a timestamp */
  retVal |= CanTSyn_SubtractVirtualLocalTime(&localTimeT1Vlt, &localTimeT0Vlt, &timeDelta); /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */
  CanTSyn_VirtualLocalTimeToTimestamp(&timeDelta, &timestamp); /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */

  /* #30 Calculate T4 for FUP message as T4 = T0SYNCns + (T1VLT - T0VLT) with T0SYNCns as nanosecond portion of T0SYNC */
  retVal |= CanTSyn_TimestampPlusTimestamp(&syncTime, &timestamp, &sumTimeStamp); /* PRQA S 2985 */ /* MD_CanTSyn_Rule2.2_2985 */ /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */

  /* #40 If time retrieval was successful: */
  if (retVal == E_OK)
  {
    /* #50 Set current Virtual Local Time value from StbM */
    CanTSyn_SetFupTimeStampOfMasterState(masterIdx, sumTimeStamp, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
  }

  return retVal;
} /* CanTSyn_Tx_OnGetTimeFup */

# if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnGetTimeOfs
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(Std_ReturnType, CANTSYN_CODE) CanTSyn_Tx_OnGetTimeOfs(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_TimeStampType offsetTimeStamp = { 0u };

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get current offset time from StbM */
  retVal = StbM_GetOffset(CanTSyn_GetTimeBaseIdOfDomainConfig(CanTSyn_GetDomainConfigIdxOfMasterConfig(masterIdx, partitionIndex), partitionIndex), &offsetTimeStamp); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */ /* VCA_CANTSYN_CALL_STBM_FUNCTION_WITH_VAR_POINTER_ARGUMENT */
  CanTSyn_SetSyncTimestampOfMasterState(masterIdx, offsetTimeStamp, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */

  /* #20 If timebase is not synchronized, set return value to E_NOT_OK */
  if ((CanTSyn_GetGlobalTimeBaseBit(CanTSyn_GetSyncTimestampOfMasterState(masterIdx, partitionIndex).timeBaseStatus) == 0u))
  {
    retVal = E_NOT_OK;
  }

  return retVal;
} /* CanTSyn_Tx_OnGetTimeOfs */
# endif /* CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_Tx_AssembleSyncMsg
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
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_AssembleSyncMsg(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) syncMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Assemble common parts of all message types with SYNC message format */
  CanTSyn_Tx_OnAssembleSync(masterIdx, syncMsg, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */

  /* #20 Dispatch between SYNC/SYNC + CRC and OFS/OFS + CRC: */
  switch (CanTSyn_GetSyncMessageTypeOfMasterConfig(masterIdx, partitionIndex))
  {
# if (CANTSYN_EXISTS_SYNC_TXCRCSECUREDOFMASTERCONFIG == STD_ON)
    case CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_NOT_CRC:
      /* #30 Assemble with SYNC message format */
      CanTSyn_Tx_SetUserByte1ToSync(masterIdx, syncMsg, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
      break;
# endif

# if (CANTSYN_EXISTS_SYNC_CRC_TXCRCSECUREDOFMASTERCONFIG == STD_ON)
    case CANTSYN_TIME_SYNC_MESSAGE_TYPE_SYNC_CRC:
      /* #40 Assemble with SYNC + CRC message format */
      CanTSyn_Tx_SetCrcToSync(masterIdx, syncMsg, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
      break;
# endif

# if (CANTSYN_EXISTS_OFS_TXCRCSECUREDOFMASTERCONFIG == STD_ON)
    case CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_NOT_CRC:
      /* #50 Assemble with OFS message format */
      CanTSyn_Tx_OnAssembleOfs(masterIdx, syncMsg, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
      CanTSyn_Tx_SetUserByte1ToSync(masterIdx, syncMsg, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
      break;
# endif

# if (CANTSYN_EXISTS_OFS_CRC_TXCRCSECUREDOFMASTERCONFIG == STD_ON)
    case CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFS_CRC:
      /* #60 Assemble with OFS + CRC message format */
      CanTSyn_Tx_OnAssembleOfs(masterIdx, syncMsg, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
      CanTSyn_Tx_SetCrcToSync(masterIdx, syncMsg, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
      break;
# endif

    default: /* COV_CANTSYN_MSR_MISRA */
      /* #70 no default case available */
      break;
  }

#if (CANTSYN_EXTENDED_MESSAGE_USED == STD_ON)
  /* #80 Set Reserved Bytes 7-15 if Extended Format is used */
  CanTSyn_ExtendedCanSignal_SetReserved(syncMsg); /* SBSW_CANTSYN_ACCESS_EXTCANMSG */ /* SBSW_CANTSYN_ACCESS_EXTCANMSG */ /* SBSW_CANTSYN_ACCESS_EXTCANMSG */ /* SBSW_CANTSYN_ACCESS_EXTCANMSG */ /* SBSW_CANTSYN_ACCESS_EXTCANMSG */ /* SBSW_CANTSYN_ACCESS_EXTCANMSG */ /* SBSW_CANTSYN_ACCESS_EXTCANMSG */ /* SBSW_CANTSYN_ACCESS_EXTCANMSG */
#endif
#if (CANTSYN_STANDARD_MESSAGE_USED == STD_ON)
  /* Dummy switch for the CanTSyn_GetMessageDlcOfDomainConfig variant of 8 */
#endif
} /* CanTSyn_Tx_AssembleSyncMsg */

/**********************************************************************************************************************
 *  CanTSyn_Tx_AssembleFupMsg
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
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_AssembleFupMsg(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) fupMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Assemble common parts for all message types with FUP message format */
  CanTSyn_Tx_OnAssembleFup(masterIdx, fupMsg, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */

  /* #20 Dispatch between FUP/FUP + CRC and OFNS/OFNS + CRC: */
  switch (CanTSyn_GetFupMessageTypeOfMasterConfig(masterIdx, partitionIndex))
  {
# if (CANTSYN_EXISTS_SYNC_TXCRCSECUREDOFMASTERCONFIG == STD_ON)
    case CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_NOT_CRC:
      /* #30 Assemble with FUP message format */
      CanTSyn_CanSignal_SetTime(fupMsg, CanTSyn_GetFupTimeStampOfMasterState(masterIdx, partitionIndex).nanoseconds); /* SBSW_CANTSYN_ACCESS_CANMSG */ /* SBSW_CANTSYN_ACCESS_CANMSG */ /* SBSW_CANTSYN_ACCESS_CANMSG */ /* SBSW_CANTSYN_ACCESS_CANMSG */
      break;
# endif
#  if (CANTSYN_EXISTS_SYNC_CRC_TXCRCSECUREDOFMASTERCONFIG == STD_ON)
    case CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_CRC:
      /* #40 Assemble with FUP + CRC message format */
      CanTSyn_CanSignal_SetTime(fupMsg, CanTSyn_GetFupTimeStampOfMasterState(masterIdx, partitionIndex).nanoseconds); /* SBSW_CANTSYN_ACCESS_CANMSG */ /* SBSW_CANTSYN_ACCESS_CANMSG */ /* SBSW_CANTSYN_ACCESS_CANMSG */ /* SBSW_CANTSYN_ACCESS_CANMSG */
      CanTSyn_Tx_SetCrcToFup(masterIdx, fupMsg, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
      break;
#  endif

#  if (CANTSYN_EXISTS_OFS_TXCRCSECUREDOFMASTERCONFIG == STD_ON)
    case CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_NOT_CRC:
      /* #50 Assemble with OFNS message format */
      CanTSyn_Tx_OnAssembleOfns(masterIdx, fupMsg, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
      break;
#  endif

#  if (CANTSYN_EXISTS_OFS_CRC_TXCRCSECUREDOFMASTERCONFIG == STD_ON)
    case CANTSYN_TIME_SYNC_MESSAGE_TYPE_OFNS_CRC:
      /* #60 Assemble with OFNS + CRC message format */
      CanTSyn_Tx_OnAssembleOfns(masterIdx, fupMsg, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
      CanTSyn_Tx_SetCrcToFup(masterIdx, fupMsg, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
      break;
#  endif

    default: /* COV_CANTSYN_MSR_MISRA */
      /* #70 no default case available */
      break;
  }

#if (CANTSYN_EXTENDED_MESSAGE_USED == STD_ON)
  /* #80 Set Reserved Bytes 7-15 if Extended Format is used */
  CanTSyn_ExtendedCanSignal_SetReserved(fupMsg); /* SBSW_CANTSYN_ACCESS_EXTCANMSG */ /* SBSW_CANTSYN_ACCESS_EXTCANMSG */ /* SBSW_CANTSYN_ACCESS_EXTCANMSG */ /* SBSW_CANTSYN_ACCESS_EXTCANMSG */ /* SBSW_CANTSYN_ACCESS_EXTCANMSG */ /* SBSW_CANTSYN_ACCESS_EXTCANMSG */ /* SBSW_CANTSYN_ACCESS_EXTCANMSG */ /* SBSW_CANTSYN_ACCESS_EXTCANMSG */
#endif
#if (CANTSYN_STANDARD_MESSAGE_USED == STD_ON)
  /* Dummy switch for the CanTSyn_GetMessageDlcOfDomainConfig variant of 8 */
#endif
} /* CanTSyn_Tx_AssembleFupMsg */

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnAssembleSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnAssembleSync(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) syncMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Byte 0: Set message type */
  CanTSyn_CanSignal_SetType(syncMsg, CanTSyn_GetSyncMessageTypeOfMasterConfig(masterIdx, partitionIndex)); /* SBSW_CANTSYN_ACCESS_CANMSG */
  /* #20 Byte 2, Bit 0-3: Set sequence counter, Bit 4-7: Set domainId */
  CanTSyn_CanSignal_SetByte2(syncMsg, CanTSyn_GetMessageDomainIdOfMasterConfig(masterIdx, partitionIndex), CanTSyn_GetTxSequenceCounterOfMasterState(masterIdx, partitionIndex)); /* SBSW_CANTSYN_ACCESS_CANMSG */
  /* #30 Byte 3: Set user byte 0 */
  CanTSyn_CanSignal_SetUserByte0(syncMsg, CanTSyn_GetUserDataOfMasterState(masterIdx, partitionIndex).userByte0); /* SBSW_CANTSYN_ACCESS_CANMSG */
  /* #40 Byte 4-7: Set time */
  CanTSyn_CanSignal_SetTime(syncMsg, CanTSyn_GetAddrSyncTimestampOfMasterState(masterIdx, partitionIndex)->seconds); /* SBSW_CANTSYN_ACCESS_CANMSG */ /* SBSW_CANTSYN_ACCESS_CANMSG */ /* SBSW_CANTSYN_ACCESS_CANMSG */ /* SBSW_CANTSYN_ACCESS_CANMSG */
} /* CanTSyn_Tx_OnAssembleSync */

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnAssembleFup
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnAssembleFup(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) fupMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Byte 0: Set message type */
  CanTSyn_CanSignal_SetType(fupMsg, CanTSyn_GetFupMessageTypeOfMasterConfig(masterIdx, partitionIndex)); /* SBSW_CANTSYN_ACCESS_CANMSG */
  /* #20 Byte 1: Set user byte 2 */
  CanTSyn_CanSignal_SetUserByte2(fupMsg, CanTSyn_GetUserDataOfMasterState(masterIdx, partitionIndex).userByte2); /* SBSW_CANTSYN_ACCESS_CANMSG */
  /* #30 Byte 2, Bit 0-3: Set sequence counter, Bit 4-7: Set domainId */
  CanTSyn_CanSignal_SetByte2(fupMsg, CanTSyn_GetMessageDomainIdOfMasterConfig(masterIdx, partitionIndex), CanTSyn_GetTxSequenceCounterOfMasterState(masterIdx, partitionIndex)); /* SBSW_CANTSYN_ACCESS_CANMSG */
  /* #40 Byte 3, Bit 0-1: Set OVS bit, Bit 2: Set SGW bit, Bit 3-7: reserved */
  CanTSyn_CanSignal_SetByte3(fupMsg, CanTSyn_GetFupTimeStampOfMasterState(masterIdx, partitionIndex).seconds, CanTSyn_GetSyncToGatewayBit(CanTSyn_GetSyncTimestampOfMasterState(masterIdx, partitionIndex).timeBaseStatus)); /* PRQA S 2985 */ /* MD_CanTSyn_Rule2.2_2985 */ /* SBSW_CANTSYN_ACCESS_CANMSG */
} /* CanTSyn_Tx_OnAssembleFup */

# if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_OnAssembleOfs
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnAssembleOfs(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) ofsMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Clear byte 1, since we are not supporting user data for offset */
  CanTSyn_CanSignal_ClearOfsReserved(ofsMsg); /* SBSW_CANTSYN_ACCESS_CANMSG */
  /* #20 Set seconds Hi */
  CanTSyn_CanSignal_SetSecHi(ofsMsg, (uint8)(CanTSyn_GetSyncTimestampOfMasterState(masterIdx, partitionIndex).secondsHi)); /* SBSW_CANTSYN_ACCESS_CANMSG */
} /* CanTSyn_Tx_OnAssembleOfs */

/**********************************************************************************************************************
 *  CanTSyn_Tx_OnAssembleOfns
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CANTSYN_LOCAL FUNC(void, CANTSYN_CODE) CanTSyn_Tx_OnAssembleOfns(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) ofnsMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Clear byte 1, since we are not supporting user data for offset */
  CanTSyn_CanSignal_ClearOfsReserved(ofnsMsg); /* SBSW_CANTSYN_ACCESS_CANMSG */
  /* #20 Set seconds Hi */
  CanTSyn_CanSignal_SetSecHi(ofnsMsg, (uint8)(CanTSyn_GetSyncTimestampOfMasterState(masterIdx, partitionIndex).secondsHi >> 8u)); /* SBSW_CANTSYN_ACCESS_CANMSG */
  /* #30 Set time */
  CanTSyn_CanSignal_SetTime(ofnsMsg, CanTSyn_GetSyncTimestampOfMasterState(masterIdx, partitionIndex).nanoseconds); /* SBSW_CANTSYN_ACCESS_CANMSG */ /* SBSW_CANTSYN_ACCESS_CANMSG */ /* SBSW_CANTSYN_ACCESS_CANMSG */ /* SBSW_CANTSYN_ACCESS_CANMSG */
} /* CanTSyn_Tx_OnAssembleOfns */
# endif /* (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON) */

# if ((CANTSYN_EXISTS_SYNC_TXCRCSECUREDOFMASTERCONFIG == STD_ON) || (CANTSYN_EXISTS_OFS_TXCRCSECUREDOFMASTERCONFIG == STD_ON))
/**********************************************************************************************************************
 *  CanTSyn_Tx_SetUserByte1ToSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_SetUserByte1ToSync(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) syncMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set user byte 1 */
  CanTSyn_CanSignal_SetUserByte1(syncMsg, CanTSyn_GetUserDataOfMasterState(masterIdx, partitionIndex).userByte1); /* SBSW_CANTSYN_ACCESS_CANMSG */
} /* CanTSyn_Tx_SetUserByte1ToSync */
# endif /* (CANTSYN_EXISTS_SYNC_TXCRCSECUREDOFMASTERCONFIG == STD_ON) || (CANTSYN_EXISTS_OFS_TXCRCSECUREDOFMASTERCONFIG == STD_ON) */

# if((CANTSYN_EXISTS_SYNC_CRC_TXCRCSECUREDOFMASTERCONFIG == STD_ON) || (CANTSYN_EXISTS_OFS_CRC_TXCRCSECUREDOFMASTERCONFIG == STD_ON))
/**********************************************************************************************************************
 *  CanTSyn_Tx_SetCrcToSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL FUNC(void, CANTSYN_CODE) CanTSyn_Tx_SetCrcToSync(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) syncMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 crcResult, dataId;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate CRC */
  dataId = CanTSyn_GetSyncDataIDList(CanTSyn_GetSyncDataIDListStartIdxOfDomainConfig(
      CanTSyn_GetDomainConfigIdxOfMasterConfig(masterIdx, partitionIndex), partitionIndex)
          + CanTSyn_GetTxSequenceCounterOfMasterState(masterIdx, partitionIndex), partitionIndex);
  crcResult = CanTSyn_CalculateMsgCrc(&dataId, (P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA)) syncMsg, CanTSyn_GetCrcLength(CanTSyn_GetDomainConfigIdxOfMasterConfig(masterIdx, partitionIndex), partitionIndex)); /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR_PARAMPTR */

  /* #20 Set CRC to SYNC message */
  CanTSyn_CanSignal_SetCRC(syncMsg, crcResult); /* SBSW_CANTSYN_ACCESS_CANMSG */
} /* CanTSyn_Tx_SetCrcToSync */

/**********************************************************************************************************************
 *  CanTSyn_Tx_SetCrcToFup
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL FUNC(void, CANTSYN_CODE) CanTSyn_Tx_SetCrcToFup(
    CanTSyn_MasterConfigIterType masterIdx,
    P2VAR(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_VAR) fupMsg,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 crcResult, dataId;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Calculate CRC */
  dataId = CanTSyn_GetFupDataIDList(CanTSyn_GetFupDataIDListStartIdxOfDomainConfig(CanTSyn_GetDomainConfigIdxOfMasterConfig(masterIdx, partitionIndex), partitionIndex) + CanTSyn_GetTxSequenceCounterOfMasterState(masterIdx, partitionIndex), partitionIndex);
  crcResult = CanTSyn_CalculateMsgCrc(&dataId, (P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA)) fupMsg, CanTSyn_GetCrcLength(CanTSyn_GetDomainConfigIdxOfMasterConfig(masterIdx, partitionIndex), partitionIndex)); /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR_PARAMPTR */

  /* #20 Set CRC to FUP message */
  CanTSyn_CanSignal_SetCRC(fupMsg, crcResult); /* SBSW_CANTSYN_ACCESS_CANMSG */
} /* CanTSyn_Tx_SetCrcToFup */
# endif /* (CANTSYN_EXISTS_SYNC_CRC_TXCRCSECUREDOFMASTERCONFIG == STD_ON) || (CANTSYN_EXISTS_OFS_CRC_TXCRCSECUREDOFMASTERCONFIG == STD_ON) */

/**********************************************************************************************************************
 *  CanTSyn_Tx_ValidateSendSyncConditions
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
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_ValidateSendSyncConditions(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean sendSync;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if transmission channel is ready to send */
  if (CanTSyn_Tx_IsTxReady(masterIdx, partitionIndex) == FALSE)
  {
    sendSync = FALSE;
  }
  /* #20 If immediate send mode is configured: */
# if (CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON)
  /* #30 Validate if SYNC/OFS message has to be sent in immediate mode */
  else if (CanTSyn_Tx_ValidateImmediateSync(masterIdx, partitionIndex) == TRUE)
  {
    /* #40 Immediate SYNC/OFS send detected */
    sendSync = TRUE;
  }
  /* #50 Check if cyclic message resume time expired */
  else if (CanTSyn_Tx_IsCyclicMsgResumeTimeExpired(masterIdx, partitionIndex) == FALSE)
  {
    sendSync = FALSE;
  }
# endif

  /* #60 Check if Tx period time is expired */
  else if (CanTSyn_Tx_IsTxPeriodTimeExpired(masterIdx, partitionIndex) == FALSE)
  {
    sendSync = FALSE;
  }
  else
  {
    /* #70 Cyclic transmission of SYNC/OFS detected */
    sendSync = TRUE;
  }

  return sendSync;
} /* CanTSyn_Tx_ValidateSendSyncConditions */

/**********************************************************************************************************************
 *  CanTSyn_Tx_ValidateSendFupConditions
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_ValidateSendFupConditions(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  boolean sendFup;

  /* #10 Check if transmission channel is ready to send */
  if (CanTSyn_Tx_IsTxReady(masterIdx, partitionIndex) == FALSE)
  {
    sendFup = FALSE;
  }
    /* #20 FUP/OFNS message can be sent */
  else
  {
    sendFup = TRUE;
  }
  return sendFup;
} /* CanTSyn_Tx_ValidateSendFupConditions */

# if (CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_ValidateImmediateSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_ValidateImmediateSync(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;
  uint8 currentUpdateCounter;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If master has configured immediate send SYNC message type: */
#  if (CANTSYN_EXISTS_NOT_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON)
  if (CanTSyn_GetImmediateTimeSyncOfMasterConfig(masterIdx, partitionIndex) == CANTSYN_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG)
#  endif
  {
    /* #20 Get time base update counter from StbM */
    currentUpdateCounter = StbM_GetTimeBaseUpdateCounter(CanTSyn_GetTimeBaseIdOfDomainConfig(CanTSyn_GetDomainConfigIdxOfMasterConfig(masterIdx, partitionIndex), partitionIndex));

    /* #30 If last stored time base update counter has changed or previous Immediate Transmit was not executed: */
    if ((currentUpdateCounter != CanTSyn_GetLastUpdateCounterOfMasterState(masterIdx, partitionIndex)) || (CanTSyn_IsTransmitImmediateSyncOfMasterState(masterIdx, partitionIndex) == TRUE)) /* PRQA S 1881, 4304 */ /* MD_MSR_AutosarBoolean */
    {
      retVal = TRUE;

      /* #40 Save retrieved time base update counter */
      CanTSyn_SetLastUpdateCounterOfMasterState(masterIdx, currentUpdateCounter, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */

      /* #50 Set flag to indicate immediate SYNC message type */
      CanTSyn_SetTransmitImmediateSyncOfMasterState(masterIdx, TRUE, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
    }
  }

  return retVal;
} /* CanTSyn_Tx_ValidateImmediateSync */
# endif /* CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_Tx_IsTxReady
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_IsTxReady(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean txIsReady;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if configured CAN controller is ready */
  if (CanTSyn_IsCanControllerReady(masterIdx, partitionIndex) == FALSE)
  {
    txIsReady = FALSE;
  }

# if (CANTSYN_EXISTS_SHARED_PDUS == STD_ON)
  /* #20 Check if configured PduId is unlocked */
  else if (CanTSyn_Tx_IsPduIdUnLocked(masterIdx, partitionIndex) == FALSE)
  {
    txIsReady = FALSE;
  }
# endif

# if (CANTSYN_TXDEBOUNCECOUNTERIDXOFMASTERCONFIG == STD_ON)
  /* #30 Check if configured debounce time is expired */
  else if (CanTSyn_Tx_IsDebounceTimeExpired(masterIdx, partitionIndex) == FALSE)
  {
    txIsReady = FALSE;
  }
# endif
  /* #40 If #10-#30 are true, Tx is considered to be ready */
  else
  {
    txIsReady = TRUE;
  }

  return txIsReady;
} /* CanTSyn_Tx_IsTxReady */

/**********************************************************************************************************************
 *  CanTSyn_Tx_StopTxPeriodCounter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_StopTxPeriodCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Stop Tx period counter */
  CanTSyn_SetTxPeriodCounterOfMasterState(masterIdx, 0u, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
} /* CanTSyn_Tx_StopTxPeriodCounter */

/**********************************************************************************************************************
 *  CanTSyn_Tx_ResetTxPeriodCounter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_ResetTxPeriodCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Reset Tx period counter to configured value */
  CanTSyn_SetTxPeriodCounterOfMasterState(masterIdx, CanTSyn_GetTxPeriodOfMasterConfig(masterIdx, partitionIndex), partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
} /* CanTSyn_Tx_ResetTxPeriodCounter */

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateTxPeriodCounter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateTxPeriodCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 If Tx period counter is running */
  if (CanTSyn_GetTxPeriodCounterOfMasterState(masterIdx, partitionIndex) > 0u)
  {
    /* #20 Decrement Tx period */
    CanTSyn_DecTxPeriodCounterOfMasterState(masterIdx, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
  }
} /* CanTSyn_Tx_UpdateTxPeriodCounter */

/**********************************************************************************************************************
 *  CanTSyn_Tx_IsTxPeriodTimeExpired
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_IsTxPeriodTimeExpired(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Check if the Tx period time is expired */
  return (boolean) (CanTSyn_GetTxPeriodCounterOfMasterState(masterIdx, partitionIndex) == 0u); /* PRQA S 1881, 4304 */ /* MD_MSR_AutosarBoolean */
} /* CanTSyn_Tx_IsTxPeriodTimeExpired */

/**********************************************************************************************************************
 *  CanTSyn_Tx_InitTxSequenceCounter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_InitTxSequenceCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Initialize the Tx sequence counter to the maximum value */
  CanTSyn_SetTxSequenceCounterOfMasterState(masterIdx, CANTSYN_MAX_SEQUENCE_COUNTER, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
} /* CanTSyn_Tx_InitTxSequenceCounter */

/**********************************************************************************************************************
 *  CanTSyn_Tx_IncrementTxSequenceCounter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_IncrementTxSequenceCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 If sequence counter overflow occurs */
  if (CanTSyn_GetTxSequenceCounterOfMasterState(masterIdx, partitionIndex) == CANTSYN_MAX_SEQUENCE_COUNTER)
  {
    /* #20 Reset sequence counter to zero */
    CanTSyn_SetTxSequenceCounterOfMasterState(masterIdx, 0u, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
  }
  else
  {
    /* #30 Increment Tx sequence counter */
    CanTSyn_IncTxSequenceCounterOfMasterState(masterIdx, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
  }

} /* CanTSyn_Tx_IncrementTxSequenceCounter */

# if (CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_InitCyclicMsgResumeCounter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_InitCyclicMsgResumeCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set cyclic message resume counter to zero */
  CanTSyn_SetCyclicMsgResumeCounterOfMasterState(masterIdx, 0u, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
} /* CanTSyn_Tx_InitCyclicMsgResumeCounter */

/**********************************************************************************************************************
 *  CanTSyn_Tx_ResetCyclicMsgResumeCounter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_ResetCyclicMsgResumeCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Reset cyclic message resume counter to configured value */
  CanTSyn_SetCyclicMsgResumeCounterOfMasterState(masterIdx, CanTSyn_GetCyclicMsgResumeTimeOfMasterConfig(masterIdx, partitionIndex), partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
} /* CanTSyn_Tx_ResetCyclicMsgResumeCounter */

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateCyclicMsgResumeCounter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateCyclicMsgResumeCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 If cyclic message resume counter is running */
  if (CanTSyn_GetCyclicMsgResumeCounterOfMasterState(masterIdx, partitionIndex) > 0u)
  {
    /* #20 Decrement Tx cyclic message resume counter */
    CanTSyn_DecCyclicMsgResumeCounterOfMasterState(masterIdx, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
  }
} /* CanTSyn_Tx_UpdateCyclicMsgResumeCounter */

/**********************************************************************************************************************
 *  CanTSyn_Tx_IsCyclicMsgResumeTimeExpired
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_IsCyclicMsgResumeTimeExpired(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Check if the cyclic message resume time is expired */
  return (boolean) (CanTSyn_GetCyclicMsgResumeCounterOfMasterState(masterIdx, partitionIndex) == 0u); /* PRQA S 1881, 4304 */ /* MD_MSR_AutosarBoolean */
} /* CanTSyn_Tx_IsCyclicMsgResumeTimeExpired */
# endif /* CANTSYN_EXISTS_SUPPORTED_IMMEDIATETIMESYNCOFMASTERCONFIG == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_Tx_InitTxConfirmationTimeout
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_InitTxConfirmationTimeout(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set Tx confirmation timeout counter to zero */
  CanTSyn_SetTxConfirmationTimeoutCounterOfMasterState(masterIdx, 0u, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
} /* CanTSyn_Tx_InitTxConfirmationTimeout */

/**********************************************************************************************************************
 *  CanTSyn_Tx_ResetTxConfirmationTimeout
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_ResetTxConfirmationTimeout(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Reset Tx confirmation timeout to configured value */
  CanTSyn_SetTxConfirmationTimeoutCounterOfMasterState(masterIdx, CanTSyn_GetMasterConfTimeoutOfMasterConfig(masterIdx, partitionIndex), partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
} /* CanTSyn_Tx_ResetTxConfirmationTimeout */

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateTxConfirmationTimeout
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateTxConfirmationTimeout(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Decrement Tx confirmation timeout with the assumption that the counter is always greater than zero */
  CanTSyn_DecTxConfirmationTimeoutCounterOfMasterState(masterIdx, partitionIndex); /* SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR */
} /* CanTSyn_Tx_UpdateTxConfirmationTimeout */

/**********************************************************************************************************************
 *  CanTSyn_Tx_IsTxConfirmationTimeoutExpired
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_IsTxConfirmationTimeoutExpired(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Check if the Tx confirmation timeout is expired */
  return (boolean) (CanTSyn_GetTxConfirmationTimeoutCounterOfMasterState(masterIdx, partitionIndex) == 0u); /* PRQA S 1881, 4304 */ /* MD_MSR_AutosarBoolean */
} /* CanTSyn_Tx_IsTxConfirmationTimeoutExpired */

# if (CANTSYN_TXDEBOUNCECOUNTERIDXOFMASTERCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_InitDebounceCounter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_InitDebounceCounter(CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  CanTSyn_TxDebounceCounterIterType debounceCounterIdx;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each configured Tx debounce counter: */
  for (debounceCounterIdx = 0u; debounceCounterIdx < CanTSyn_GetSizeOfTxDebounceCounter(partitionIndex); debounceCounterIdx++)
  {
    /* #20 Set Tx debounce counter to zero */
    CanTSyn_SetTxDebounceCounter(debounceCounterIdx, 0u, partitionIndex); /* SBSW_CANTSYN_ACCESS_TXDEBOUNCECOUNTER */
  }

  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
} /* CanTSyn_Tx_InitDebounceCounter */

/**********************************************************************************************************************
 *  CanTSyn_Tx_ResetDebounceCounter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL FUNC(void, CANTSYN_CODE) CanTSyn_Tx_ResetDebounceCounter(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

#  if (CANTSYN_TX_CONF_MIXED_DEBOUNCE_COUNTER == STD_ON)
  /* #10 If given master has debouncing configured: */
  if (CanTSyn_Tx_HasDebouncing(masterIdx, partitionIndex) == TRUE)
#  endif
  {
    /* #20 Reset Tx debounce counter to configured value */
    CanTSyn_SetTxDebounceCounter(CanTSyn_GetTxDebounceCounterIdxOfMasterConfig(masterIdx, partitionIndex), CanTSyn_GetDebounceTimeOfMasterConfig(masterIdx, partitionIndex), partitionIndex); /* SBSW_CANTSYN_ACCESS_TXDEBOUNCECOUNTER_IND */ /* VCA_CANTSYN_ACCESS_TXDEBOUNCECOUNTER_IND */
  }
} /* CanTSyn_Tx_ResetDebounceCounter */

/**********************************************************************************************************************
 *  CanTSyn_Tx_UpdateDebounceCounter
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_UpdateDebounceCounter(CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  CanTSyn_TxDebounceCounterIterType txDebounceCounterIdx;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each configured Tx debounce counter */
  for (txDebounceCounterIdx = 0u; txDebounceCounterIdx < CanTSyn_GetSizeOfTxDebounceCounter(partitionIndex); txDebounceCounterIdx++)
  {
    /* #20 Check if Tx debounce counter can be decremented */
    if (CanTSyn_GetTxDebounceCounter(txDebounceCounterIdx, partitionIndex) > 0u)
    {
      /* #30 Decrement Tx debounce counter */
      CanTSyn_DecTxDebounceCounter(txDebounceCounterIdx, partitionIndex); /* SBSW_CANTSYN_ACCESS_TXDEBOUNCECOUNTER */
    }
  }

  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
} /* CanTSyn_Tx_UpdateDebounceCounter */

/**********************************************************************************************************************
 *  CanTSyn_Tx_IsDebounceTimeExpired
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_IsDebounceTimeExpired(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Set return value to: Tx debounce time is not expired */
  boolean txDebounceTimeExpired = FALSE;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
#  if (CANTSYN_TX_CONF_MIXED_DEBOUNCE_COUNTER == STD_ON)
  /* #20 If given master has debouncing configured: */
  if (CanTSyn_Tx_HasDebouncing(masterIdx, partitionIndex) == TRUE)
#  endif
  {
    /* #30 Check if Tx debounce counter is zero */
    if (CanTSyn_GetTxDebounceCounter(CanTSyn_GetTxDebounceCounterIdxOfMasterConfig(masterIdx, partitionIndex), partitionIndex) == 0u)
    {
      /* #40 Set return value to: Tx is debounced */
      txDebounceTimeExpired = TRUE;
    }
  }
#  if (CANTSYN_TX_CONF_MIXED_DEBOUNCE_COUNTER == STD_ON)
  else
  {
    txDebounceTimeExpired = TRUE;
  }
#  endif

  return txDebounceTimeExpired;
} /* CanTSyn_Tx_IsDebounceTimeExpired */

#  if (CANTSYN_TX_CONF_MIXED_DEBOUNCE_COUNTER == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_HasDebouncing
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_HasDebouncing(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Check if the given master has deboucing configured by comparing the debounce index with the size of debounce table */
  return (boolean) ((CanTSyn_GetTxDebounceCounterIdxOfMasterConfig(masterIdx, partitionIndex) < CanTSyn_GetSizeOfTxDebounceCounter(partitionIndex)) == TRUE); /* PRQA S 1881, 4304 */ /* MD_MSR_AutosarBoolean */
} /* CanTSyn_Tx_HasDebouncing */
#  endif /* CANTSYN_TX_CONF_MIXED_DEBOUNCE_COUNTER == STD_ON */
# endif /* CANTSYN_TXDEBOUNCECOUNTERIDXOFMASTERCONFIG == STD_ON */

# if (CANTSYN_EXISTS_SHARED_PDUS == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Tx_InitPduIdStates
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_InitPduIdStates(CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  CanTSyn_PduIdStatesIterType pduIdIdx;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  for (pduIdIdx = 0u; pduIdIdx < CanTSyn_GetSizeOfPduIdStates(partitionIndex); pduIdIdx++)
  {
    /* #20 Reset the PduId state to invalid master index */
    CanTSyn_SetPduIdStates(pduIdIdx, CANTSYN_INV_MASTER_IDX, partitionIndex); /* SBSW_CANTSYN_ACCESS_PDUIDSTATES */
  }

  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
} /* CanTSyn_Tx_InitPduIdStates */

/**********************************************************************************************************************
 *  CanTSyn_Tx_LockPduId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_LockPduId(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Lock the configured PduId for the given master */
  CanTSyn_SetPduIdStates(CanTSyn_GetPduIdStatesIdxOfMasterConfig(masterIdx, partitionIndex), (uint8) masterIdx, partitionIndex); /* SBSW_CANTSYN_ACCESS_PDUIDSTATES */
} /* CanTSyn_Tx_LockPduId */

/**********************************************************************************************************************
 *  CanTSyn_Tx_ReleasePduId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Tx_ReleasePduId(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Release the configured PduId for the given master */
  CanTSyn_SetPduIdStates(CanTSyn_GetPduIdStatesIdxOfMasterConfig(masterIdx, partitionIndex), CANTSYN_INV_MASTER_IDX, partitionIndex); /* SBSW_CANTSYN_ACCESS_PDUIDSTATES */
} /* CanTSyn_Tx_ReleasePduId */

/**********************************************************************************************************************
 *  CanTSyn_Tx_IsPduIdUnLocked
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Tx_IsPduIdUnLocked(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 blockingMasterIdx;
  boolean isPduIdUnlocked = FALSE;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if the configured PduId is either free or locked for the given master (for FUP message transmission) */
  blockingMasterIdx = CanTSyn_GetPduIdStates(CanTSyn_GetPduIdStatesIdxOfMasterConfig(masterIdx, partitionIndex), partitionIndex);
  if ((blockingMasterIdx == CANTSYN_INV_MASTER_IDX) || (blockingMasterIdx == masterIdx))
  {
    isPduIdUnlocked = TRUE;  
  }
  
  return isPduIdUnlocked; 
} /* CanTSyn_Tx_IsPduIdUnLocked */
# endif /* CANTSYN_EXISTS_SHARED_PDUS == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_InitCanController
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_InitCanController(CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  CanTSyn_TransmissionControllerStateIterType canControllerIdx;

  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each configured CAN controller: */
  for (canControllerIdx = 0u; canControllerIdx < CanTSyn_GetSizeOfTransmissionControllerState(partitionIndex); canControllerIdx++)
  {
    /* #20 Reset CAN controller state to TX_ON */
    CanTSyn_SetTransmissionControllerState(canControllerIdx, CANTSYN_TX_ON, partitionIndex); /* SBSW_CANTSYN_ACCESS_CONTROLLERSTATE */
  }
} /* CanTSyn_InitCanController */

/**********************************************************************************************************************
 *  CanTSyn_IsCanControllerReady
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_IsCanControllerReady(
    CanTSyn_MasterConfigIterType masterIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* #10 Check if the configured CAN controller is online */
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return (boolean) (CanTSyn_IsTransmissionControllerState(CanTSyn_GetControllerInfoIdxOfMasterConfig(masterIdx, partitionIndex), partitionIndex) == CANTSYN_TX_ON); /* PRQA S 1881, 4304 */ /* MD_MSR_AutosarBoolean */
} /* CanTSyn_IsCanControllerReady */


/**********************************************************************************************************************
 *  CanTSyn_SetCanControllerTransmissionMode
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_SetCanControllerTransmissionMode(
    uint8 ctrlIdx,
    CanTSyn_TransmissionModeType mode,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  CanTSyn_TransmissionControllerStateIterType canControllerIdx;
  boolean foundCtrlIdx = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /* #10 Search for CAN controllers with given controller index */
  for (canControllerIdx = 0u; canControllerIdx < CanTSyn_GetSizeOfTransmissionControllerState(partitionIndex); canControllerIdx++) /* COV_CANTSYN_SETTRANSMISSIONMODE_VALID_OTHER_OR_INVALID_CTRLID */
  {
    if (CanTSyn_GetSnvOfControllerInfo(canControllerIdx, partitionIndex) == ctrlIdx) /* COV_CANTSYN_SETTRANSMISSIONMODE_VALID_OTHER_OR_INVALID_CTRLID */
    {
      /* #20 Set transmission mode to given mode */
      CanTSyn_SetTransmissionControllerState(canControllerIdx, mode, partitionIndex); /* SBSW_CANTSYN_ACCESS_CONTROLLERSTATE */
      foundCtrlIdx = TRUE;
      break;
    }
  }

  return foundCtrlIdx;
} /* CanTSyn_SetCanControllerTransmissionMode */

#endif /* CANTSYN_MASTERCONFIG == STD_ON */

#if (CANTSYN_SLAVECONFIG == STD_ON)
/**********************************************************************************************************************
 *
 *
 *  SLAVE
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CanTSyn_Rx_Init
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_Init(CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  CanTSyn_SlaveStateIterType slaveIdx;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 For each configured slave: */
  for (slaveIdx = 0u; slaveIdx < CanTSyn_GetSizeOfSlaveState(partitionIndex); slaveIdx++)
  {
    /* #20 Set the state to 'wait for SYNC' */
    CanTSyn_SetStateOfSlaveState(slaveIdx, CANTSYN_STATE_RECEIVE_WAITING_FOR_SYNC, partitionIndex); /* SBSW_CANTSYN_ACCESS_SLAVESTATE_VAR */

    /* #30 Initialize follow-up timeout to zero */
    CanTSyn_Rx_InitFollowUpTimeout(slaveIdx, partitionIndex);

    /* #40 Reset last received sequence counter to maximum value, which indicates no sequence counter received yet */
    CanTSyn_SetRxSequenceCounterOfSlaveState(slaveIdx, CANTSYN_INV_SEQUENCE_COUNTER, partitionIndex); /* SBSW_CANTSYN_ACCESS_SLAVESTATE_VAR */
  }
} /* CanTSyn_Rx_Init */

/**********************************************************************************************************************
 *  CanTSyn_Rx_Update
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_Update(CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* #10 Update configured slaves */
  CanTSyn_Rx_UpdateSlaves(partitionIndex);
} /* CanTSyn_Rx_Update */

/**********************************************************************************************************************
 *  CanTSyn_Rx_GetSlaveIdxByDomainId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(CanTSyn_SlaveConfigIterType, CANTSYN_CODE) CanTSyn_Rx_GetSlaveIdxByDomainId(
    uint8 domainId,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* #10 Set slave index to infinite */
  CanTSyn_SlaveConfigIterType slaveIdx = CANTSYN_NO_SLAVECONFIGIDXOFDOMAINCONFIG;
  CanTSyn_DomainConfigIterType domainIdx;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Find slave index by given domain id */
  for(domainIdx = 0u; domainIdx < CanTSyn_GetSizeOfDomainConfig(partitionIndex); domainIdx++)
  {
    if (CanTSyn_GetDomainIdOfDomainConfig(domainIdx, partitionIndex) == domainId)
    {
      slaveIdx = CanTSyn_GetSlaveConfigIdxOfDomainConfig(domainIdx, partitionIndex);
      break;
    }
  }

  return slaveIdx;
} /* CanTSyn_Rx_GetSlaveIdxByDomainId */

/**********************************************************************************************************************
 *  CanTSyn_Rx_GetDomainId
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(uint8, CANTSYN_CODE) CanTSyn_Rx_GetDomainId(
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 messageType;
  uint8 domainId;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Retrieve the message type from the given message */
  messageType = CanTSyn_CanSignal_GetType(ptrMsgInfo);

  /* #20 Retrieve the domainId from the given message */
  domainId = CanTSyn_CanSignal_GetD(ptrMsgInfo);

  /* #30 Add offset to domainId, if the message is an offset message */
  if (CanTSyn_IsOfsMsg(messageType) || CanTSyn_IsOfnsMsg(messageType))
  {
    domainId += CANTSYN_START_OFFSET_TIME_DOMAIN_ID;
  }

  return domainId;
} /* CanTSyn_Rx_GetDomainId */

/**********************************************************************************************************************
 *  CanTSyn_Rx_ProcessRxIndication
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_ProcessRxIndication(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_VirtualLocalTimeType virtualLocalTime = { 0u };

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Retrieve Virtual Local Time from StbM */
  retVal = StbM_GetCurrentVirtualLocalTime(CanTSyn_GetTimeBaseIdOfDomainConfig(CanTSyn_GetDomainConfigIdxOfSlaveConfig(slaveIdx, partitionIndex), partitionIndex), &virtualLocalTime); /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */ /* VCA_CANTSYN_CALL_STBM_FUNCTION_WITH_VAR_POINTER_ARGUMENT */

  /* #20 Dispatch RxIndication to: */
  if (retVal == E_OK)
  {
    if (CanTSyn_GetStateOfSlaveState(slaveIdx, partitionIndex) == CANTSYN_STATE_RECEIVE_WAITING_FOR_SYNC)
    {
      /* #30 RxIndication for SYNC/OFS message */
      CanTSyn_Rx_ProcessReceivedSyncMsg(slaveIdx, ptrMsgInfo, &virtualLocalTime, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */ /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */
    }
    else /* CANTSYN_STATE_RECEIVE_WAITING_FOR_FOLLOW_UP */
    {
      /* #40 RxIndication for FUP/OFNS message */
      CanTSyn_Rx_ProcessReceivedFupMsg(slaveIdx, ptrMsgInfo, &virtualLocalTime, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */ /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */
    }
  }
} /* CanTSyn_Rx_ProcessRxIndication */

/**********************************************************************************************************************
 *  CanTSyn_Rx_UpdateSlaves
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_UpdateSlaves(CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  CanTSyn_SlaveConfigIterType slaveIdx;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Enter exclusive area: Concurrent access to FollowUpTimeout in RxIndication */
  SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();

  /* #20 For each configured slave: */
  for (slaveIdx = 0u; slaveIdx < CanTSyn_GetSizeOfSlaveConfig(partitionIndex); slaveIdx++)
  {
    /* #30 Update follow-up timeout */
    CanTSyn_Rx_UpdateFollowUpTimeout(slaveIdx, partitionIndex);

    if (CanTSyn_GetStateOfSlaveState(slaveIdx, partitionIndex) == CANTSYN_STATE_RECEIVE_WAITING_FOR_FOLLOW_UP)
    {
        /* #40 Update state 'wait for follow-up' */
        CanTSyn_Rx_UpdateWaitingForFollowUp(slaveIdx, partitionIndex);
    }
  }
  /* #50 Exit exclusive area */
  SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
} /* CanTSyn_Rx_UpdateSlaves */

/**********************************************************************************************************************
 *  CanTSyn_Rx_ResetStateToSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL FUNC(void, CANTSYN_CODE) CanTSyn_Rx_ResetStateToSync(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Reset slave to 'wait for SYNC' */
  CanTSyn_SetStateOfSlaveState(slaveIdx, CANTSYN_STATE_RECEIVE_WAITING_FOR_SYNC, partitionIndex); /* SBSW_CANTSYN_ACCESS_SLAVESTATE_VAR */

  /* #20 Reset follow-up timeout to zero and stop timout handling */
  CanTSyn_Rx_StopFollowUpTimeout(slaveIdx, partitionIndex);
} /* CanTSyn_Rx_ResetStateToSync */

/**********************************************************************************************************************
 *  CanTSyn_Rx_UpdateWaitingForFollowUp
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_UpdateWaitingForFollowUp(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* #10 If Rx follow-up timeout expired: */
  if (CanTSyn_Rx_IsFollowUpTimeoutExpired(slaveIdx, partitionIndex) == TRUE)
  {
    /* #20 Perform actions for unsuccessful receive */
    CanTSyn_Rx_OnFailedFupReceive(slaveIdx, partitionIndex);
  }
} /* CanTSyn_Rx_UpdateWaitingForFollowUp */

/**********************************************************************************************************************
 *  CanTSyn_Rx_ProcessReceivedSyncMsg
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_ProcessReceivedSyncMsg(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_DATA) virtualLocalTime,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* #10 Validate received MsgInfo: */
  if (CanTSyn_Rx_ValidateSync(slaveIdx, ptrMsgInfo, partitionIndex) == TRUE) /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
  {
    /* #20 Receive payload of SYNC/OFS message and perform actions for successful reception */
    CanTSyn_Rx_OnReceiveSyncMsg(slaveIdx, ptrMsgInfo, virtualLocalTime, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
  }
} /* CanTSyn_Rx_ProcessReceivedSyncMsg */

/**********************************************************************************************************************
 *  CanTSyn_Rx_OnReceiveSyncMsg
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnReceiveSyncMsg(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_DATA) virtualLocalTime,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Store virtual local time for usage in fup message */
  CanTSyn_SetVirtualLocalTimeOfSlaveState(slaveIdx, *virtualLocalTime, partitionIndex); /* SBSW_CANTSYN_ACCESS_SLAVESTATE_VAR */

  /* #20 Store SYNC message */
  VStdLib_MemCpy(*CanTSyn_GetAddrSyncMsgOfSlaveState(slaveIdx, partitionIndex), *ptrMsgInfo, sizeof(*CanTSyn_GetAddrSyncMsgOfSlaveState(slaveIdx, partitionIndex))); /* PRQA S 0315 */ /* MD_MSR_VStdLibCopy */ /* SBSW_CANTSYN_MEMCPY_SYNCMSG */ /* VCA_CANTSYN_CALL_VSTDLIB_FUNCTION_WITH_VAR_POINTER_ARGUMENT */

  /* #30 Perform action for successful SYNC reception */
  CanTSyn_Rx_OnSuccessSyncReceive(slaveIdx, partitionIndex);

  /* #40 Store received sequence counter */
  CanTSyn_SetRxSequenceCounterOfSlaveState(slaveIdx, CanTSyn_CanSignal_GetSC(ptrMsgInfo), partitionIndex); /* SBSW_CANTSYN_ACCESS_SLAVESTATE_VAR */
} /* CanTSyn_Rx_OnReceiveSyncMsg */

/**********************************************************************************************************************
 *  CanTSyn_Rx_OnSuccessSyncReceive
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnSuccessSyncReceive(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set state of slave to 'wait for SYNC' */
  CanTSyn_SetStateOfSlaveState(slaveIdx, CANTSYN_STATE_RECEIVE_WAITING_FOR_FOLLOW_UP, partitionIndex); /* SBSW_CANTSYN_ACCESS_SLAVESTATE_VAR */

  /* #20 Reset follow-up timeout to configured value */
  CanTSyn_Rx_ResetFollowUpTimeout(slaveIdx, partitionIndex);
} /* CanTSyn_Rx_OnSuccessSyncReceive */

/**********************************************************************************************************************
 *  CanTSyn_Rx_ProcessReceivedFupMsg
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_ProcessReceivedFupMsg(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_DATA) virtualLocalTime,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* #10 Validate received MsgInfo: */
  if (CanTSyn_Rx_ValidateFup(slaveIdx, ptrMsgInfo, partitionIndex) == TRUE ) /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
  {
# if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
    if (CanTSyn_IsOfnsMsg(CanTSyn_CanSignal_GetType(ptrMsgInfo)))
    {
      /* #20 Receive payload of OFNS message */
      CanTSyn_Rx_OnReceiveOfnsMsg(slaveIdx, ptrMsgInfo, virtualLocalTime, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
    }
    else
# endif
    {
      /* #30 Receive payload of FUP message */
      CanTSyn_Rx_OnReceiveFupMsg(slaveIdx, ptrMsgInfo, virtualLocalTime, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
    }
  }
} /* CanTSyn_Rx_ProcessReceivedFupMsg */

/**********************************************************************************************************************
 *  CanTSyn_Rx_OnReceiveFupMsg
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
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnReceiveFupMsg(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_DATA) virtualLocalTime,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  StbM_TimeStampType actualTime = { 0u };
  StbM_TimeStampType receivedTime = { 0u };
  StbM_TimeStampType timestamp = { 0u };
  StbM_UserDataType receivedUserData = { 0u };
  StbM_VirtualLocalTimeType localTimeT2Vlt;
  StbM_VirtualLocalTimeType timeDelta = { 0u };
  StbM_MeasurementType measureData;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  measureData.pathDelay = 0;

  /* #10 Get payload from FUP message */
  CanTSyn_Rx_GetPayload(slaveIdx, ptrMsgInfo, &receivedTime, &receivedUserData, partitionIndex);  /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */

  /* #20 Get Virtual Local Time T2 */
  localTimeT2Vlt = CanTSyn_GetVirtualLocalTimeOfSlaveState(slaveIdx, partitionIndex);

  /* #30 Convert the calculated timespan to a timestamp, where given virtualLocalTime is T5Vlt */
  retVal = CanTSyn_SubtractVirtualLocalTime(virtualLocalTime, &localTimeT2Vlt, &timeDelta); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */ /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */
  CanTSyn_VirtualLocalTimeToTimestamp(&timeDelta, &timestamp); /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */

  /* #40 Calculate T5 for FUP message as T5 = T0SYNCns + T4 + (T5VLT - T2VLT) with T0SYNCns as nanosecond portion of T0SYNC */
  retVal |= CanTSyn_TimestampPlusTimestamp(&receivedTime, &timestamp, &actualTime); /* PRQA S 2985 */ /* MD_CanTSyn_Rule2.2_2985 */ /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */

  /* #50 If time retrieval was successful: */
  if (retVal == E_OK)
  {
    if ((CanTSyn_CanSignal_GetSGW(ptrMsgInfo)) == 0u)
    {
      actualTime.timeBaseStatus = 0x00u;
    }
    else
    {
      actualTime.timeBaseStatus = StbM_Sync_To_Gateway_BflMask;
    }

    /* #60 Provide new global time to StbM */
    (void)StbM_BusSetGlobalTime(CanTSyn_GetTimeBaseIdOfDomainConfig(CanTSyn_GetDomainConfigIdxOfSlaveConfig(slaveIdx, partitionIndex), partitionIndex), &actualTime, &receivedUserData, &measureData, virtualLocalTime); /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */ /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */ /* VCA_CANTSYN_CALL_EXTERNAL_FUNCTION_WITH_CONST_POINTER_ARGUMENT */
  }

  /* #70 Perform action for successfully FUP reception */
  CanTSyn_Rx_OnSuccessFupReceive(slaveIdx, partitionIndex);
} /* CanTSyn_Rx_OnReceiveFupMsg */ /* PRQA S 6050 */ /* MD_MSR_STCAL */

# if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Rx_OnReceiveOfnsMsg
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
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnReceiveOfnsMsg(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2CONST(StbM_VirtualLocalTimeType, AUTOMATIC, CANTSYN_APPL_DATA) virtualLocalTime,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  StbM_MeasurementType measureData;
  StbM_TimeStampType receivedTime = { 0u };

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  measureData.pathDelay = 0;

  /* #20 Get payload of FUP type message */
  CanTSyn_Rx_GetOffsetPayload(slaveIdx, ptrMsgInfo, &receivedTime, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */

  /* #50 Provide new offset to StbM */
  (void)StbM_BusSetGlobalTime(CanTSyn_GetTimeBaseIdOfDomainConfig(CanTSyn_GetDomainConfigIdxOfSlaveConfig(slaveIdx, partitionIndex), partitionIndex), &receivedTime, NULL_PTR, &measureData, virtualLocalTime); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */ /* VCA_CANTSYN_CALL_EXTERNAL_FUNCTION_WITH_CONST_POINTER_ARGUMENT */

  /* #60 Perfom actions on successful reception of FUP type message */
  CanTSyn_Rx_OnSuccessFupReceive(slaveIdx, partitionIndex);
} /* CanTSyn_Rx_OnReceiveOfnsMsg */
# endif /* CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_Rx_OnSuccessFupReceive
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnSuccessFupReceive(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set state of slave to 'wait for FUP' */
  CanTSyn_SetStateOfSlaveState(slaveIdx, CANTSYN_STATE_RECEIVE_WAITING_FOR_SYNC, partitionIndex); /* SBSW_CANTSYN_ACCESS_SLAVESTATE_VAR */

  /* #20 Reset follow-up timeout to zero and stop timeout handling */
  CanTSyn_Rx_StopFollowUpTimeout(slaveIdx, partitionIndex);
} /* CanTSyn_Rx_OnSuccessFupReceive */

/**********************************************************************************************************************
 *  CanTSyn_Rx_OnFailedFupReceive
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnFailedFupReceive(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Reset the slave to state: 'wait for SYNC' */
  CanTSyn_SetStateOfSlaveState(slaveIdx, CANTSYN_STATE_RECEIVE_WAITING_FOR_SYNC, partitionIndex); /* SBSW_CANTSYN_ACCESS_SLAVESTATE_VAR */
} /* CanTSyn_Rx_OnFailedFupReceive */

/**********************************************************************************************************************
 *  CanTSyn_Rx_GetPayload
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
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_GetPayload(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2VAR(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_VAR) timeStamp,
    P2VAR(StbM_UserDataType, AUTOMATIC, CANTSYN_APPL_VAR) userData,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 messageType;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get message type */
  messageType = CanTSyn_CanSignal_GetType(ptrMsgInfo);

  /* #20 Get the timestamp from the payload */
  CanTSyn_Rx_OnGetTimeStamp(slaveIdx, ptrMsgInfo, timeStamp, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */

  /* #30 Dispatch from get user data based on message type: */
  switch (messageType)
  {
# if ((CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON))
    case CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_CRC:
      /* #40 FUP is CRC secured */
      CanTSyn_Rx_OnGetUserDataCrc(slaveIdx, userData, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
      break;
# endif

# if ((CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON))
    case CANTSYN_TIME_SYNC_MESSAGE_TYPE_FUP_NOT_CRC:
      /* #50 FUP is not CRC secured */
      CanTSyn_Rx_OnGetUserData(slaveIdx, ptrMsgInfo, userData, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
      break;
# endif

    default: /* COV_CANTSYN_MSR_MISRA */
      /* #60 no default available */
      break;
  }
} /* CanTSyn_Rx_GetPayload */

# if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Rx_GetOffsetPayload
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_GetOffsetPayload(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2VAR(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_VAR) timeStamp,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* #10 Get the timestamp from the payload */
  CanTSyn_Rx_OnGetOffsetTimeStamp(slaveIdx, ptrMsgInfo, timeStamp, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
} /* CanTSyn_Rx_GetOffsetPayload */
# endif /* CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_Rx_OnGetTimeStamp
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnGetTimeStamp(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2VAR(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_VAR) timeStamp,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 syncSeconds;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get seconds portion saved during SYNC message */
  syncSeconds = CanTSyn_CanSignal_GetTime(CanTSyn_GetAddrSyncMsgOfSlaveState(slaveIdx, partitionIndex));

  /* #20 Calculate seconds by adding OVS */
  timeStamp->seconds = syncSeconds + (CanTSyn_CanSignal_GetOVS(ptrMsgInfo)); /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */

  /* #30 Calculate seconds Hi */
  if (timeStamp->seconds < syncSeconds)
  {
    timeStamp->secondsHi = 1u; /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
  }
  else
  {
    timeStamp->secondsHi = 0u; /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
  }

  /* #40 Extract nanoseconds from MsgInfo */
  timeStamp->nanoseconds = CanTSyn_CanSignal_GetTime(ptrMsgInfo); /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
} /* CanTSyn_Rx_OnGetTimeStamp */

# if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Rx_OnGetOffsetTimeStamp
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnGetOffsetTimeStamp(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2VAR(StbM_TimeStampType, AUTOMATIC, CANTSYN_APPL_VAR) timeStamp,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Get secondsHi from MsgInfo */
  timeStamp->secondsHi = CanTSyn_CanSignal_GetSecHi(CanTSyn_GetAddrSyncMsgOfSlaveState(slaveIdx, partitionIndex)) + ((uint16) CanTSyn_CanSignal_GetSecHi(ptrMsgInfo) << 8u); /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */

  /* #20 Get seconds from MsgInfo */
  timeStamp->seconds = CanTSyn_CanSignal_GetTime(CanTSyn_GetAddrSyncMsgOfSlaveState(slaveIdx, partitionIndex)); /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */

  /* #30 Get nanoseconds from MsgInfo */
  timeStamp->nanoseconds = CanTSyn_CanSignal_GetTime(ptrMsgInfo); /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
} /* CanTSyn_Rx_OnGetOffsetTimeStamp */
# endif /* CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON */

# if ((CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON))
/**********************************************************************************************************************
 *  CanTSyn_Rx_OnGetUserDataCrc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnGetUserDataCrc(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2VAR(StbM_UserDataType, AUTOMATIC, CANTSYN_APPL_VAR) userData,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Get user byte 0 */
  userData->userByte0 = CanTSyn_CanSignal_GetUserByte0(CanTSyn_GetAddrSyncMsgOfSlaveState(slaveIdx, partitionIndex)); /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */

  /* #20 Set user data length to 1 */
  userData->userDataLength = 1u; /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
} /* CanTSyn_Rx_OnGetUserDataCrc */
# endif /* ((CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)) */

# if ((CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON))
/**********************************************************************************************************************
 *  CanTSyn_Rx_OnGetUserData
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_OnGetUserData(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    P2VAR(StbM_UserDataType, AUTOMATIC, CANTSYN_APPL_VAR) userData,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set user data length to 3 */
  userData->userDataLength = 3u; /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
  /* #20 Get user byte 0 */
  userData->userByte0 = CanTSyn_CanSignal_GetUserByte0(CanTSyn_GetAddrSyncMsgOfSlaveState(slaveIdx, partitionIndex)); /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
  /* #30 Get user byte 1 */
  userData->userByte1 = CanTSyn_CanSignal_GetUserByte1(CanTSyn_GetAddrSyncMsgOfSlaveState(slaveIdx, partitionIndex)); /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
  /* #40 Get user byte 2 */
  userData->userByte2 = CanTSyn_CanSignal_GetUserByte2(ptrMsgInfo); /* SBSW_CANTSYN_WRITE_OUTPARAM_POINTER */
} /* CanTSyn_Rx_OnGetUserData */
# endif /* ((CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)) */

/**********************************************************************************************************************
 *  CanTSyn_Rx_InitFollowUpTimeout
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_InitFollowUpTimeout(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set the Rx follow-up timeout to zero */
  CanTSyn_SetRxFollowUpTimeoutCountOfSlaveState(slaveIdx, 0u, partitionIndex); /* SBSW_CANTSYN_ACCESS_SLAVESTATE_VAR */
} /* CanTSyn_Rx_InitFollowUpTimeout */

/**********************************************************************************************************************
 *  CanTSyn_Rx_StopFollowUpTimeout
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_StopFollowUpTimeout(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Set the Rx follow-up timeout to zero and stop timeout handling */
  CanTSyn_SetRxFollowUpTimeoutCountOfSlaveState(slaveIdx, 0u, partitionIndex); /* SBSW_CANTSYN_ACCESS_SLAVESTATE_VAR */
} /* CanTSyn_Rx_StopFollowUpTimeout */

/**********************************************************************************************************************
 *  CanTSyn_Rx_ResetFollowUpTimeout
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_ResetFollowUpTimeout(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Reset the Rx follow-up timeout to configured value */
  CanTSyn_SetRxFollowUpTimeoutCountOfSlaveState(slaveIdx, CanTSyn_GetFollowUpTimeoutOfSlaveConfig(slaveIdx, partitionIndex), partitionIndex); /* SBSW_CANTSYN_ACCESS_SLAVESTATE_VAR */
} /* CanTSyn_Rx_ResetFollowUpTimeout */

/**********************************************************************************************************************
 *  CanTSyn_Rx_UpdateFollowUpTimeout
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(void, CANTSYN_CODE) CanTSyn_Rx_UpdateFollowUpTimeout(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 If Rx follow-up timeout is running: */
  if (CanTSyn_GetRxFollowUpTimeoutCountOfSlaveState(slaveIdx, partitionIndex) > 0u)
  {
    /* #20 Decrement the follow-up timeout counter */
    CanTSyn_DecRxFollowUpTimeoutCountOfSlaveState(slaveIdx, partitionIndex); /* SBSW_CANTSYN_ACCESS_SLAVESTATE_VAR */
  }
} /* CanTSyn_Rx_UpdateFollowUpTimeout */

/**********************************************************************************************************************
 *  CanTSyn_Rx_IsFollowUpTimeoutExpired
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_IsFollowUpTimeoutExpired(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* #10 Check if Rx follow-up timeout is expired */
  return (boolean) (CanTSyn_GetRxFollowUpTimeoutCountOfSlaveState(slaveIdx, partitionIndex) == 0u); /* PRQA S 1881, 4304 */ /* MD_MSR_AutosarBoolean */
} /* CanTSyn_Rx_IsFollowUpTimeoutExpired */

/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateSync(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isValid;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Validate message type */
  if (CanTSyn_Rx_ValidateSyncMessageType(ptrMsgInfo) == FALSE) /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
  {
    isValid = FALSE;
  }
  /* #20 Validate sequence counter */
  else if (CanTSyn_Rx_ValidateSequenceCounterSync(slaveIdx, ptrMsgInfo, partitionIndex) == FALSE) /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
  {
    isValid = FALSE;
  }
# if ((CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON))
  /* #30 Validate CRC */
  else if (CanTSyn_Rx_ValidateCrcSync(slaveIdx, ptrMsgInfo, partitionIndex) == FALSE) /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
  {
    isValid = FALSE;
  }
# endif /* ((CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)) */
  /* #40 Set message as valid */
  else
  {
    isValid = TRUE;
  }

  return isValid;
} /* CanTSyn_Rx_ValidateSync */

/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateFup
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
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateFup(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isValid;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Validate message type */
  if (CanTSyn_Rx_ValidateFupMessageType(ptrMsgInfo) == FALSE) /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
  {
    isValid = FALSE;
  }

    /* #20 If sequence counter is not valid: */
  else if(CanTSyn_Rx_ValidateSequenceCounterFup(slaveIdx, ptrMsgInfo, partitionIndex) == FALSE) /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
  {
    /* #30 Reset slave to 'wait for SYNC' */
    CanTSyn_Rx_ResetStateToSync(slaveIdx, partitionIndex);
    isValid = FALSE;
  }

    /* #40 Validate nanoseconds range */
  else if(CanTSyn_Rx_ValidateNanosecondsFup(ptrMsgInfo) == FALSE) /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
  {
    /* #50 Reset slave to 'wait for SYNC' */
    CanTSyn_Rx_ResetStateToSync(slaveIdx, partitionIndex);
    isValid = FALSE;
  }

# if ((CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON))
    /* #60 Validate CRC */
  else if(CanTSyn_Rx_ValidateCrcFup(slaveIdx, ptrMsgInfo, partitionIndex) == FALSE) /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
  {
    isValid = FALSE;
  }
# endif

    /* #70 Set message as valid */
  else
  {
    isValid = TRUE;
  }
  return isValid;
} /* CanTSyn_Rx_ValidateFup */

/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateSyncMessageType
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateSyncMessageType(
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isValid = FALSE;
  uint8 messageType;

  /* ----- Implementation ----------------------------------------------- */
  messageType = CanTSyn_CanSignal_GetType(ptrMsgInfo);

  /* #10 Check if the message type is either SYNC or OFS */
  if (CanTSyn_IsSyncMsg(messageType)
# if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
    || CanTSyn_IsOfsMsg(messageType)
# endif
      )
  {
    isValid = TRUE;
  }

  return isValid;
} /* CanTSyn_Rx_ValidateSyncMessageType */

/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateFupMessageType
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateFupMessageType(
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isValid = FALSE;
  uint8 messageType;

  /* ----- Implementation ----------------------------------------------- */
  messageType = CanTSyn_CanSignal_GetType(ptrMsgInfo);

  /* #10 Check if the message type is either FUP or OFNS */
  if (CanTSyn_IsFupMsg(messageType)
# if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
    || CanTSyn_IsOfnsMsg(messageType)
# endif
      )
  {
    isValid = TRUE;
  }
  return isValid;
} /* CanTSyn_Rx_ValidateFupMessageType */

/**********************************************************************************************************************
 *  CanTSyn_Rx_HasRefTimebaseTimeout
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_HasRefTimebaseTimeout(
    CanTSyn_SlaveConfigIterType slaveIdx,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  boolean isTimeout = FALSE;
  StbM_TimeBaseStatusType syncTimeBaseStatus = 0u;
  StbM_TimeBaseStatusType offsetTimeBaseStatus = 0u;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Retrieve timebase status of the referred timebase */
  retVal = StbM_GetTimeBaseStatus(CanTSyn_GetTimeBaseIdOfDomainConfig(CanTSyn_GetDomainConfigIdxOfSlaveConfig(slaveIdx, partitionIndex), partitionIndex), &syncTimeBaseStatus, &offsetTimeBaseStatus); /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */ /* VCA_CANTSYN_CALL_STBM_FUNCTION_WITH_VAR_POINTER_ARGUMENT */

  /* #20 If retrieval succeeded: */
  if(retVal == E_OK)
  {
    /* #30 Check timeout status based on timebase type */
#if (CANTSYN_EXISTS_OFFSET_OFFSETDOMAINOFDOMAINCONFIG == STD_ON)
    if (CanTSyn_IsOffsetDomain(CanTSyn_GetDomainConfigIdxOfSlaveConfig(slaveIdx, partitionIndex), partitionIndex) == TRUE)
    {
      isTimeout = (boolean)(CanTSyn_GetTimeoutBit(offsetTimeBaseStatus) != 0u);  /* PRQA S 1881, 4304 */ /* MD_MSR_AutosarBoolean */
    }
    else
#endif
    {
      isTimeout = (boolean)(CanTSyn_GetTimeoutBit(syncTimeBaseStatus) != 0u); /* PRQA S 1881, 4304 */ /* MD_MSR_AutosarBoolean */
    }
  }
  return isTimeout;
} /* CanTSyn_Rx_HasRefTimebaseTimeout */

/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateSequenceCounterSync
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
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateSequenceCounterSync(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 sequenceCounter;
  uint8 jumpWidth;

  /* #10 Set sequence counter as valid */
  boolean isValid = TRUE;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Retrieve the received sequence counter from the given message */
  sequenceCounter = CanTSyn_CanSignal_GetSC(ptrMsgInfo);

  /* #30 If it is not the first received sequence counter: */
  if (CanTSyn_GetRxSequenceCounterOfSlaveState(slaveIdx, partitionIndex) <= CANTSYN_MAX_SEQUENCE_COUNTER)
  {
    /* #40 Calculate sequence counter jump width from last received sequence counter */
    jumpWidth = CanTSyn_Rx_CalculateSequenceCounterJumpWidth(slaveIdx, sequenceCounter, partitionIndex);

    /* #50 If sequence counter is stuck (jump width == 0) or jump width is bigger as max allowed configured jump width: */
    if ((jumpWidth == 0u) || (jumpWidth > CanTSyn_GetSequenceCounterJumpWidthOfSlaveConfig(slaveIdx, partitionIndex)))
    {
      /* #60 Invalidate sequence counter */
      isValid = FALSE;

      if (jumpWidth > 0u)
      {
        /* #70 Set sequence counter as valid if a timeout occurred at the referred timebase */
        isValid = CanTSyn_Rx_HasRefTimebaseTimeout(slaveIdx, partitionIndex);
      }
    }
  }

  /* #80 Store received sequence counter */
  CanTSyn_SetRxSequenceCounterOfSlaveState(slaveIdx, sequenceCounter, partitionIndex); /* SBSW_CANTSYN_ACCESS_SLAVESTATE_VAR */

  return isValid;
} /* CanTSyn_Rx_ValidateSequenceCounterSync */

/**********************************************************************************************************************
 *  CanTSyn_Rx_CalculateSequenceCounterJumpWidth
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(uint8, CANTSYN_CODE) CanTSyn_Rx_CalculateSequenceCounterJumpWidth(
    CanTSyn_SlaveConfigIterType slaveIdx,
    uint8 sequenceCounter,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 jumpWidth;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 If no sequence counter overflow occurred: */
  if (sequenceCounter >= CanTSyn_GetRxSequenceCounterOfSlaveState(slaveIdx, partitionIndex))
  {
    /* #20 Calculate jump width without overflow handling */
    jumpWidth = sequenceCounter - CanTSyn_GetRxSequenceCounterOfSlaveState(slaveIdx, partitionIndex);
  }
  else
  {
    /* #30 Calculate jump width with overflow handling */
    jumpWidth = (CANTSYN_MAX_SEQUENCE_COUNTER - CanTSyn_GetRxSequenceCounterOfSlaveState(slaveIdx, partitionIndex)) + sequenceCounter + 1u;
  }

  return jumpWidth;
} /* CanTSyn_Rx_CalculateSequenceCounterJumpWidth */

# if ((CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON))
/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateCrcSync
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateCrcSync(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isValid = FALSE;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Dispatch CRC validation to: */
  switch (CanTSyn_GetRxCrcValidatedOfSlaveConfig(slaveIdx, partitionIndex))
  {
#  if (CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)
    /* #20 CRC validation in SYNC message for CRC-IGNORED configured slave */
    case CANTSYN_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG:
      isValid = CanTSyn_Rx_OnValidateCrcIgnored();
      break;
#  endif

#  if (CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)
    /* #30 CRC validation in SYNC message for CRC-NOT_VALIDATED configured slave */
    case CANTSYN_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG:
      isValid = CanTSyn_Rx_OnValidateSyncCrcNotValidated(ptrMsgInfo); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
      break;
#  endif

#  if (CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)
    /* #40 CRC validation in SYNC message for CRC-VALIDATED configured slave */
    case CANTSYN_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG:
      isValid = CanTSyn_Rx_OnValidateSyncCrcValidated(slaveIdx, ptrMsgInfo, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
      break;
#  endif

    default: /* COV_CANTSYN_MSR_MISRA */
      /* #50 no default available */
      break;
  }

  return isValid;
} /* CanTSyn_Rx_ValidateCrcSync */

/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateCrcFup
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateCrcFup(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isValid = FALSE;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Dispatch CRC validation to: */
  switch (CanTSyn_GetRxCrcValidatedOfSlaveConfig(slaveIdx, partitionIndex))
  {
#  if (CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)
    /* #20 CRC validation in FUP message for CRC-IGNORED configured salve */
    case CANTSYN_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG:
      isValid = CanTSyn_Rx_OnValidateCrcIgnored();
      break;
#  endif

#  if (CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)
      /* #30 CRC validation in FUP message for CRC-NOT_VALIDATED configured salve */
    case CANTSYN_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG:
      isValid = CanTSyn_Rx_OnValidateFupCrcNotValidated(ptrMsgInfo); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
      break;
#  endif

#  if (CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)
      /* #40 CRC validation in FUP message for CRC-VALIDATED configured salve */
    case CANTSYN_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG:
      isValid = CanTSyn_Rx_OnValidateFupCrcValidated(slaveIdx, ptrMsgInfo, partitionIndex); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
      break;
#  endif

    default: /* COV_CANTSYN_MSR_MISRA */
      /* #50 no default available */
      break;
  }
  return isValid;
} /* CanTSyn_Rx_ValidateCrcFup */
# endif /* (CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) */

/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateSequenceCounterFup
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateSequenceCounterFup(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 sequenceCounter;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the sequence counter form the MsgInfo */
  sequenceCounter = CanTSyn_CanSignal_GetSC(ptrMsgInfo);

  /* #20 Check if the sequence counter is equal to the sequence counter received in the SYNC message */
  return (boolean) (sequenceCounter == (CanTSyn_CanSignal_GetSC(CanTSyn_GetAddrSyncMsgOfSlaveState(slaveIdx, partitionIndex)))); /* PRQA S 1881, 4304 */ /* MD_MSR_AutosarBoolean */
} /* CanTSyn_Rx_ValidateSequenceCounterFup */

/**********************************************************************************************************************
 *  CanTSyn_Rx_ValidateNanosecondsFup
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_ValidateNanosecondsFup(
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint32 nanoseconds;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Get the nanoseconds form the MsgInfo */
  nanoseconds = CanTSyn_CanSignal_GetTime(ptrMsgInfo);

  /* #20 Check if the nanoseconds are in range */
  return (boolean) (nanoseconds <= CANTSYN_TIMESTAMP_MAX_NANOSECONDS); /* PRQA S 1881, 4304 */ /* MD_MSR_AutosarBoolean */
} /* CanTSyn_Rx_ValidateNanosecondsFup */

# if ((CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON))
#  if (CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Rx_OnValidateCrcIgnored
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_OnValidateCrcIgnored(void)
{
  /* #10 Always return true, since CRC is ignored */
  return TRUE;
} /* CanTSyn_Rx_OnValidateCrcIgnored */
#  endif /* CANTSYN_EXISTS_IGNORED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON */
# endif /* (CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) || (CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON) */

# if (CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Rx_OnValidateSyncCrcNotValidated
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_OnValidateSyncCrcNotValidated(
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo)
{
  /* #10 Check that SYNC message type has no CRC */
  return (boolean) ((CanTSyn_IsSyncCrcSecured(CanTSyn_CanSignal_GetType(ptrMsgInfo))) == FALSE); /* PRQA S 1881, 4304 */ /* MD_MSR_AutosarBoolean */
} /* CanTSyn_Rx_OnValidateSyncCrcNotValidated */

/**********************************************************************************************************************
 *  CanTSyn_Rx_OnValidateFupCrcNotValidated
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_OnValidateFupCrcNotValidated(P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 messageType;

  /* ----- Implementation ----------------------------------------------- */

  /* #10 Retrieve message type from MsgInfo */
  messageType = CanTSyn_CanSignal_GetType(ptrMsgInfo);

  /* #20 Check that FUP message has no CRC */
  return (boolean) ((CanTSyn_IsFupCrcSecured(messageType)) == FALSE); /* PRQA S 1881, 4304 */ /* MD_MSR_AutosarBoolean */
} /* CanTSyn_Rx_OnValidateFupCrcNotValidated */
# endif /* CANTSYN_EXISTS_NOT_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON */

# if (CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_Rx_OnValidateSyncCrcValidated
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_OnValidateSyncCrcValidated(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isValid = FALSE;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Check if SYNC message of actual message type has CRC */
  if (CanTSyn_IsSyncCrcSecured(CanTSyn_CanSignal_GetType(ptrMsgInfo)))
  {
    uint8 crcResult;
    uint8 dataId;

    /* #20 Calculate expected CRC */
    dataId = CanTSyn_GetSyncDataIDList(CanTSyn_GetSyncDataIDListStartIdxOfDomainConfig(CanTSyn_GetDomainConfigIdxOfSlaveConfig(slaveIdx, partitionIndex), partitionIndex) + CanTSyn_CanSignal_GetSC(ptrMsgInfo), partitionIndex);
    crcResult = CanTSyn_CalculateMsgCrc(&dataId, ptrMsgInfo, CanTSyn_GetCrcLength(CanTSyn_GetDomainConfigIdxOfSlaveConfig(slaveIdx, partitionIndex), partitionIndex)); /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR_PARAMPTR */

    /* #30 Check if CRC matches with expected one */
    if (crcResult == CanTSyn_CanSignal_GetCRC(ptrMsgInfo))
    {
      isValid = TRUE;
    }
  }

  return isValid;
} /* CanTSyn_Rx_OnValidateSyncCrcValidated */

/**********************************************************************************************************************
 *  CanTSyn_Rx_OnValidateFupCrcValidated
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CANTSYN_LOCAL_INLINE FUNC(boolean, CANTSYN_CODE) CanTSyn_Rx_OnValidateFupCrcValidated(
    CanTSyn_SlaveConfigIterType slaveIdx,
    P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA) ptrMsgInfo,
    CanTSyn_PartitionIdentifiersIterType partitionIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isValid = FALSE;
  uint8 sequenceCounter;
  uint8 messageType;

# if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  /* dummy statement because of partitionIndex is not used by the ComStackLib in a non multi-partition configuration */
  CANTSYN_DUMMY_STATEMENT(partitionIndex); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Retrieve sequence counter */
  sequenceCounter = CanTSyn_CanSignal_GetSC(ptrMsgInfo);

  /* #20 Retrieve message type */
  messageType = CanTSyn_CanSignal_GetType(ptrMsgInfo);

  /* #30 Check if FUP message has CRC */
  if (CanTSyn_IsFupCrcSecured(messageType))
  {
    uint8 crcResult, dataId;

    /* #40 Calculate expected CRC */
    dataId = CanTSyn_GetFupDataIDList(CanTSyn_GetFupDataIDListStartIdxOfDomainConfig(CanTSyn_GetDomainConfigIdxOfSlaveConfig(slaveIdx, partitionIndex), partitionIndex) + sequenceCounter, partitionIndex);
    crcResult = CanTSyn_CalculateMsgCrc(&dataId, ptrMsgInfo, CanTSyn_GetCrcLength(CanTSyn_GetDomainConfigIdxOfSlaveConfig(slaveIdx, partitionIndex), partitionIndex)); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */

    /* #50 Check if CRC matches with expected one */
    isValid = (boolean) (crcResult == (CanTSyn_CanSignal_GetCRC(ptrMsgInfo))); /* PRQA S 1881, 4304 */ /* MD_MSR_AutosarBoolean */
  }

  return isValid;
} /* CanTSyn_Rx_OnValidateFupCrcValidated */
# endif /* CANTSYN_EXISTS_VALIDATED_RXCRCVALIDATEDOFSLAVECONFIG == STD_ON */
#endif /* CANTSYN_SLAVECONFIG == STD_ON */

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CanTSyn_InitMemory
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, CANTSYN_CODE) CanTSyn_InitMemory(void)
{
  /* ----- Implementation ----------------------------------------------- */

  /* #10 Set module pre initialization state to false */
  CanTSyn_PreInitialized = FALSE;
} /* CanTSyn_InitMemory */

/**********************************************************************************************************************
 *  CanTSyn_PreInit
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, CANTSYN_CODE) CanTSyn_PreInit(P2CONST(CanTSyn_ConfigType, AUTOMATIC, CANTSYN_INIT_DATA) ConfigPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  CanTSyn_PartitionIdentifiersIterType partitionIdentifiersIdx;

  CANTSYN_DUMMY_STATEMENT(ConfigPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /* #10 Initialize all partition specific initialized flags to FALSE */
  for (partitionIdentifiersIdx = 0u; partitionIdentifiersIdx < CanTSyn_GetSizeOfPartitionIdentifiers(); partitionIdentifiersIdx++)
  {
    CanTSyn_SetInitialized(FALSE, partitionIdentifiersIdx); /* SBSW_CANTSYN_ACCESS_CSL_VAR */
  }

  /* #20 Set pre initialized state of component to TRUE */
  CanTSyn_PreInitialized = TRUE;
}

/**********************************************************************************************************************
 *  CanTSyn_Init
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
FUNC(void, CANTSYN_CODE) CanTSyn_Init(P2CONST(CanTSyn_ConfigType, AUTOMATIC, CANTSYN_APPL_DATA) configPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CANTSYN_E_NO_ERROR;

  /* ----- Implementation ----------------------------------------------- */
  CANTSYN_DUMMY_STATEMENT(configPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /* #10 Check if component is already pre initialized */
  if (CanTSyn_IsPreInitialized())
  {
    CanTSyn_PartitionIdentifiersIterType partitionIdx;

#if (CANTSYN_MULTIPARTITION_USED == STD_ON)
    ApplicationType osAppId;

    /* #20 Get current partition index by os application id: */
    osAppId = GetApplicationID();

    partitionIdx = CanTSyn_GetCurrentPartitionIndexByOsApplication(osAppId);

    if (partitionIdx < CanTSyn_GetSizeOfPartitionIdentifiers())
#else
    /* in a not multipartition configuration the partition is always 0. */
    partitionIdx = 0u;
#endif
    {
#if (CANTSYN_MASTERCONFIG == STD_ON)
      /* #30 Initialize Tx unit */
      CanTSyn_Tx_Init(partitionIdx);

      /* #40 Initialize CAN controller */
      CanTSyn_InitCanController(partitionIdx);
#endif

#if (CANTSYN_SLAVECONFIG == STD_ON)
      /* #50 Initialize Rx unit */
      CanTSyn_Rx_Init(partitionIdx);
#endif

#if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
      /* #60 Set partition specific initialized flag to TRUE */
      CanTSyn_SetInitialized(TRUE, partitionIdx); /* SBSW_CANTSYN_ACCESS_CSL_VAR */
#endif
    }
#if ((CANTSYN_DEV_ERROR_DETECT) == STD_ON && (CANTSYN_MULTIPARTITION_USED == STD_ON)) /* COV_CANTSYN_DEV_ERROR_DETECT_TF_tx_tf */
    else
    {
      errorId = CANTSYN_E_INIT_FAILED;
    }
#endif
  }
#if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  else
  {
    errorId = CANTSYN_E_INIT_FAILED;
  }
#endif

  /* ----- Development Error Report --------------------------------------- */
#if (CANTSYN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CANTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(CANTSYN_MODULE_ID, CANTSYN_INSTANCE_ID_DET, CANTSYN_SID_INIT, errorId);
  }
#else
  CANTSYN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
} /* CanTSyn_Init */

#if (CANTSYN_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_GetVersionInfo
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, CANTSYN_CODE) CanTSyn_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CANTSYN_APPL_VAR) versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CANTSYN_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check parameter versioninfo for NULL pointer */
  if (versioninfo == NULL_PTR)
  {
    errorId = CANTSYN_E_NULL_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Set versioninfo with corresponding macros from component header */
    versioninfo->vendorID = (CANTSYN_VENDOR_ID); /* SBSW_CANTSYN_VERSIONINFOPTR */
    versioninfo->moduleID = (CANTSYN_MODULE_ID); /* SBSW_CANTSYN_VERSIONINFOPTR */
    versioninfo->sw_major_version = (CANTSYN_SW_MAJOR_VERSION); /* SBSW_CANTSYN_VERSIONINFOPTR */
    versioninfo->sw_minor_version = (CANTSYN_SW_MINOR_VERSION); /* SBSW_CANTSYN_VERSIONINFOPTR */
    versioninfo->sw_patch_version = (CANTSYN_SW_PATCH_VERSION); /* SBSW_CANTSYN_VERSIONINFOPTR */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CANTSYN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CANTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(CANTSYN_MODULE_ID, CANTSYN_INSTANCE_ID_DET, CANTSYN_SID_GET_VERSION_INFO, errorId);
  }
# else
  CANTSYN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
} /* CanTSyn_GetVersionInfo */
#endif /* CANTSYN_VERSION_INFO_API == STD_ON */

/**********************************************************************************************************************
 *  CanTSyn_MainFunction
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
#if (CANTSYN_MULTIPARTITION_USED == STD_ON)
FUNC(void, CANTSYN_CODE) CanTSyn_MainFunction(CanTSyn_PartitionIdentifiersIterType partitionIndex)
#else
FUNC(void, CANTSYN_CODE) CanTSyn_MainFunction(void)
#endif
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CANTSYN_E_NO_ERROR;
#if (CANTSYN_MULTIPARTITION_USED == STD_OFF)
  CanTSyn_PartitionIdentifiersIterType partitionIndex = 0u;
#endif

  /* ----- Development Error Checks ------------------------------------- */
#if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if module is initialized */
  if(CanTSyn_IsInitialized(partitionIndex) == FALSE) /* PRQA S 1881 */ /* MD_MSR_AutosarBoolean */
  {
    errorId = CANTSYN_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
#if (CANTSYN_SLAVECONFIG == STD_ON)
    /* #20 Update Rx unit */
    CanTSyn_Rx_Update(partitionIndex);
#endif

#if (CANTSYN_MASTERCONFIG == STD_ON)
    /* #30 Update Tx unit */
    CanTSyn_Tx_Update(partitionIndex);
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CANTSYN_DEV_ERROR_REPORT == STD_ON)
  /* #40 Report Det-Error if error occurred and Det-Check configured */
  if (errorId != CANTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(CANTSYN_MODULE_ID, CANTSYN_INSTANCE_ID_DET, CANTSYN_SID_MAIN_FUNCTION, errorId);
  }
#else
  CANTSYN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
} /* CanTSyn_MainFunction */

#if (CANTSYN_MASTERCONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_SetTransmissionMode
 *********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
*/
FUNC(void, CANTSYN_CODE) CanTSyn_SetTransmissionMode(uint8 CtrlIdx, CanTSyn_TransmissionModeType Mode)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CANTSYN_E_NO_ERROR;
  /* the index is initialized with 0 for the case of no partitioning. */
  CanTSyn_PartitionIdentifiersIterType partitionIdx = 0u;

  /* ----- Development Error Checks ------------------------------------- */
# if (CANTSYN_MULTIPARTITION_USED == STD_ON)
  /* #10 Find current partition index */
  partitionIdx = CanTSyn_GetCurrentPartitionIndexByControllerId(CtrlIdx);
# endif

# if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
#  if (CANTSYN_MULTIPARTITION_USED == STD_ON)
  if (partitionIdx >= CanTSyn_GetSizeOfPartitionIdentifiers())
  {
    errorId = CANTSYN_E_INV_CTRL_IDX;
  }
  else
#  endif
  /* #20 Check initialization state of the component */
  if (CanTSyn_IsInitialized(partitionIdx) == FALSE) /* PRQA S 1881 */ /* MD_MSR_AutosarBoolean */
  {
    errorId = CANTSYN_E_UNINIT;
  }
    /* #30 Check if mode is invalid */
  else if ((Mode != CANTSYN_TX_OFF) && (Mode != CANTSYN_TX_ON))
  {
    errorId = CANTSYN_E_PARAM;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 Set transmission mode to given mode if controllerId is valid */
# if ((CANTSYN_DEV_ERROR_DETECT) == STD_ON && (CANTSYN_MULTIPARTITION_USED == STD_OFF)) /* COV_CANTSYN_DEV_ERROR_DETECT_TF_tx_tf */
    if (CanTSyn_SetCanControllerTransmissionMode(CtrlIdx, Mode, partitionIdx) == FALSE)
    {
      errorId = CANTSYN_E_INV_CTRL_IDX;
    }
# else
    (void) CanTSyn_SetCanControllerTransmissionMode(CtrlIdx, Mode, partitionIdx);
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CANTSYN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CANTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(CANTSYN_MODULE_ID, CANTSYN_INSTANCE_ID_DET, CANTSYN_SID_SET_TRANSMISSION_MODE, errorId);
  }
# else
  CANTSYN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
} /* CanTSyn_SetTransmissionMode */

/**********************************************************************************************************************
 *  CanTSyn_TxConfirmation
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, CANTSYN_CODE) CanTSyn_TxConfirmation(PduIdType TxPduId)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CANTSYN_E_NO_ERROR;
  CanTSyn_PartitionIdentifiersIterType partitionIdx = 0u;

  /* ----- Development Error Checks ------------------------------------- */
# if (CANTSYN_MULTIPARTITION_USED == STD_ON)
  /* #10 Find current partition index */
  partitionIdx = CanTSyn_GetCurrentPartitionIndexByMasterPdu(TxPduId); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
# endif

# if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
#  if (CANTSYN_MULTIPARTITION_USED == STD_ON)
  if (partitionIdx >= CanTSyn_GetSizeOfPartitionIdentifiers())
  {
    errorId = CANTSYN_E_INVALID_PDUID;
  }
  else
#  endif
  /* #20 Check initialization state of the component */
  if(CanTSyn_IsInitialized(partitionIdx) == FALSE) /* PRQA S 1881 */ /* MD_MSR_AutosarBoolean */
  {
    errorId = CANTSYN_E_UNINIT;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* #30 Enter exclusive area: Enhance precision of virtual local time */
    SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();

    /* #40 Check message confirmation message and set state accordingly. */
# if ((CANTSYN_DEV_ERROR_DETECT == STD_ON) && (CANTSYN_MULTIPARTITION_USED == STD_OFF)) /* COV_CANTSYN_DEV_ERROR_DETECT_TF_tx_tf */
    if (CanTSyn_Tx_ProcessTxConfirmation(TxPduId, partitionIdx) == E_NOT_OK)
    {
      /* found no corresponding domain index -> drop message */
      errorId = CANTSYN_E_INVALID_PDUID;
    }
# else
    (void)CanTSyn_Tx_ProcessTxConfirmation(TxPduId, partitionIdx);
# endif

    /* #50 Exit exclusive area */
    SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CANTSYN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CANTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(CANTSYN_MODULE_ID, CANTSYN_INSTANCE_ID_DET, CANTSYN_SID_TX_CONFIRMATION, errorId);
  }
# else
  CANTSYN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
} /* CanTSyn_TxConfirmation */
#endif /* CANTSYN_MASTERCONFIG == STD_ON */

#if (CANTSYN_SLAVECONFIG == STD_ON)
/**********************************************************************************************************************
 *  CanTSyn_RxIndication
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
 */
/* PRQA S 6080, 6050 1 */ /* MD_MSR_STMIF */ /* MD_MSR_STCAL */
FUNC(void, CANTSYN_CODE) CanTSyn_RxIndication(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTSYN_APPL_DATA) PduInfoPtr)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CANTSYN_E_NO_ERROR;
  CanTSyn_SlaveConfigIterType slaveIdx;
  CanTSyn_PartitionIdentifiersIterType partitionIndex = 0u;

  /* ----- Development Error Checks ------------------------------------- */
# if (CANTSYN_MULTIPARTITION_USED == STD_ON)
  /* #10 Find current partition index */
  partitionIndex = CanTSyn_GetCurrentPartitionIndexBySlavePdu(RxPduId); /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
# endif

# if (CANTSYN_DEV_ERROR_DETECT == STD_ON)
#  if (CANTSYN_MULTIPARTITION_USED == STD_ON)
  if (partitionIndex >= CanTSyn_GetSizeOfPartitionIdentifiers())
  {
    errorId = CANTSYN_E_INVALID_PDUID;
  }
  else
#  endif
  /* #20 Check initialization state of the component */
  if(CanTSyn_IsInitialized(partitionIndex) == FALSE) /* PRQA S 1881 */ /* MD_MSR_AutosarBoolean */
  {
    errorId = CANTSYN_E_UNINIT;
  }
  /* #30 Check pointer to Pdu Info and corresponding Sdu Data pointer for NULL pointer */
  else if ((PduInfoPtr == NULL_PTR) || (PduInfoPtr->SduDataPtr == NULL_PTR))
  {
    errorId = CANTSYN_E_NULL_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 Enter exclusive area: Enhance precision of virtual local time */
    SchM_Enter_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();

    /* #50 Find the corresponding slave to the Rx Indication */
    slaveIdx = CanTSyn_Rx_GetSlaveIdxByDomainId(
        CanTSyn_Rx_GetDomainId((P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA))PduInfoPtr->SduDataPtr), partitionIndex); /* PRQA S 0310 */ /* MD_CanTSyn_Rule11.3 */ /* SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR */ /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */

    if (slaveIdx < CanTSyn_GetSizeOfSlaveConfig(partitionIndex))
    {
      if (CanTSyn_GetSlaveHandleIdOfSlaveConfig(slaveIdx, partitionIndex) == RxPduId) /* COV_CANTSYN_RXINDICATION_VALID_SLAVE_INVALID_PDUID */
      {
        /* #60 If slave search was successful and Pdu Info length is correct: */
        if (PduInfoPtr->SduLength == CanTSyn_GetMessageDlcOfDomainConfig(CanTSyn_GetDomainConfigIdxOfSlaveConfig(slaveIdx, partitionIndex), partitionIndex))
        {
          /* #70 Conduct the Rx Indication processing */
          CanTSyn_Rx_ProcessRxIndication(slaveIdx, (P2CONST(CanTSyn_CanMsgType, AUTOMATIC, CANTSYN_APPL_DATA))PduInfoPtr->SduDataPtr, partitionIndex); /* PRQA S 0310 */ /* MD_CanTSyn_Rule11.3 */ /* SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR */
        }
      }
      else
      {
        errorId = CANTSYN_E_INVALID_PDUID;
      }
    }
    /* else, Slave search failed. Ignore failure because of invalid domainId */

#if (CANTSYN_EXTENDED_MESSAGE_USED == STD_ON)
    /* Dummy switch for the CanTSyn_GetMessageDlcOfDomainConfig variant of 16 */
#endif
#if (CANTSYN_STANDARD_MESSAGE_USED == STD_ON)
    /* Dummy switch for the CanTSyn_GetMessageDlcOfDomainConfig variant of 8 */
#endif

    /* #80 Exit exclusive area */
    SchM_Exit_CanTSyn_CANTSYN_EXCLUSIVE_AREA_0();
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CANTSYN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CANTSYN_E_NO_ERROR)
  {
    (void)Det_ReportError(CANTSYN_MODULE_ID, CANTSYN_INSTANCE_ID_DET, CANTSYN_SID_RX_INDICATION, errorId);
  }
# else
  CANTSYN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
} /* CanTSyn_RxIndication */  /* PRQA S 6080, 6050 */ /* MD_MSR_STMIF */ /* MD_MSR_STCAL */
#endif /* CANTSYN_SLAVECONFIG == STD_ON */

#define CANTSYN_STOP_SEC_CODE
#include "CanTSyn_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Justification for module-specific MISRA deviations:
 MD_CanTSyn_Rule2.2_2985:
      Reason:     A function like macro is implemented to handle different argument values. In the special case a part of the macro is not required.
      Risk:       no risk
      Prevention: Covered by code review.

 MD_CanTSyn_Rule11.3:
      Reason:     For the internal processing the internal data type is used. Therefore, the incoming data at the external interface has to be casted to the corresponding internal type.
      Risk:       no risk
      Prevention: Covered by code review.
*/

/* Safe BSW assumptions:
  Indirections:
    DomainConfig->SlaveConfig  1:0..1
    DomainConfig->MasterConfig 1:0..N
    MasterConfig->PduIdStates  1:1
    MasterConfig->ControllerInfo  1:1
    MasterConfig->TxDebounceCounter   1:0..1

  Size Constraints:
    SlaveConfig  <-> SlaveState
    MasterConfig <-> MasterState
    ControllerInfo <-> ControllerState

  These assumptions are modelled in ComStackLib
*/

/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_CANTSYN_ACCESS_MASTERSTATE_VAR
  \DESCRIPTION Access of master state (same size as master config) with same index using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL02 of ComStackLib

  \ID SBSW_CANTSYN_ACCESS_SLAVESTATE_VAR
  \DESCRIPTION Access of slave state (same size as slave config) with same index using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL02 of ComStackLib

  \ID SBSW_CANTSYN_ACCESS_PDUIDSTATES
  \DESCRIPTION Write access to PduIdStates using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_CANTSYN_ACCESS_CONTROLLERSTATE
  \DESCRIPTION Write access to ControllerState using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_CANTSYN_ACCESS_TXDEBOUNCECOUNTER
  \DESCRIPTION Write access to TxDebounceCounter using ComStackLib
  \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

  \ID SBSW_CANTSYN_ACCESS_TXDEBOUNCECOUNTER_IND
  \DESCRIPTION Access of debounce counter via indirection over master
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

  \ID SBSW_CANTSYN_ACCESS_CSL_VAR
  \DESCRIPTION A ComStackLib generated variable is accessed.
  \COUNTERMEASURE \N The variable is written using a generated macro of the CSL. It immediately dereferences the variables address without pointer arithmetic.

  \ID SBSW_CANTSYN_MEMCPY_SYNCMSG
  \DESCRIPTION Call to MemCpy with SyncMsgOfSlaveState as destination buffer. The index comes from the caller calculated by indirection of the DomainConfig.
              The DomainIndex is given as parameter on external interfaces or by iterating over the domains in the CanTSyn_MainFunction.
              The size parameter is calculated using sizeof(). The source parameter is a constant pointer.
  \COUNTERMEASURE \N Qualified use-case CSL02 and CSL03 of ComStackLib

  \ID SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR
  \DESCRIPTION Call of a function with pointer parameters where the pointers are pointing to local (stack) objects.
  \COUNTERMEASURE \N Compiler ensures validity of the pointers.

  \ID SBSW_CANTSYN_WRITE_OUTPARAM_POINTER
  \DESCRIPTION Write to a out parameter which was given as pointer.
  \COUNTERMEASURE \N Caller ensures validity of the pointers.

  \ID SBSW_CANTSYN_FUNCTIONCALL_PARAMPTR
  \DESCRIPTION Forwarding the pointer that was given as parameter, without modifying anything.
  \COUNTERMEASURE \N Caller ensures validity of the pointers.

  \ID SBSW_CANTSYN_FUNCTIONCALL_LOCALPTR_PARAMPTR
  \DESCRIPTION Call of a function with pointer parameters where the pointers are pointing to local (stack) objects and forward pointers that were given as parameter, without modifying anything.
  \COUNTERMEASURE \N Compiler and caller ensure validity of the pointers.

  \ID SBSW_CANTSYN_FUNCTIONCALL_PDUINFO
  \DESCRIPTION Call of a function with pointer parameter where PduInfo is a reference to a local (stack) object. SduLength is set to 8 or 16 and SduPtr is a reference to a local array with the corresponding number of elements.
  \COUNTERMEASURE \N Compiler ensures validity of the pointers.

  \ID SBSW_CANTSYN_ACCESS_CANMSG
  \DESCRIPTION Write access to CAN message of type CanTSyn_CanMsgType (array with 8 or 16 elements) using the CanTSyn_CanSignal_* macros or referencing an element with a static index. The macros only access index 0..7. The message is a reference to a local (stack) object.
  \COUNTERMEASURE \N Compiler ensures validity of the pointers.

  \ID SBSW_CANTSYN_ACCESS_EXTCANMSG
  \DESCRIPTION Write access to CAN message of type CanTSyn_CanMsgType (array with 16 elements) using the CanTSyn_ExtendedCanSignal_* macros or referencing an element with a static index. The macros only access index 8..15. The message is a reference to a local (stack) object.
  \COUNTERMEASURE \N Compiler ensures validity of the pointers.

  \ID SBSW_CANTSYN_VERSIONINFOPTR
  \DESCRIPTION The function CanTSyn_GetVersionInfo writes to the object referenced by parameter versioninfo.
  \COUNTERMEASURE \N The caller ensures that the pointers passed to the
                    parameters versioninfo is valid.

SBSW_JUSTIFICATION_END */

/* VCA_JUSTIFICATION_BEGIN

  \ID VCA_CANTSYN_CALL_EXTERNAL_FUNCTION_WITH_CONST_POINTER_ARGUMENT
  \DESCRIPTION A function with pointer parameters is directly called, but the function is not
              defined within the analyzed sources. VCA is unable to determine the
              behavior of the function.
  \COUNTERMEASURE \N The Compiler ensures the validity of the pointers because the pointer parameter is a constant pointer.

  \ID VCA_CANTSYN_CALL_STBM_FUNCTION_WITH_VAR_POINTER_ARGUMENT
  \DESCRIPTION A function with pointer parameters is directly called, but the function is not
              defined within the analyzed sources. VCA is unable to determine the
              behavior of the function.
  \COUNTERMEASURE \N Arguments that contain var pointer are checked by review: Pointer type corresponds to function
                    parameter type. If the pointer argument is a struct, this struct does not contain a pointer element.

  \ID VCA_CANTSYN_CALL_VSTDLIB_FUNCTION_WITH_VAR_POINTER_ARGUMENT
  \DESCRIPTION A function with pointer parameters is directly called, but the function is not
              defined within the analyzed sources. VCA is unable to determine the
              behavior of the function.
  \COUNTERMEASURE \N Arguments that contain var pointer are checked by review: Pointer type corresponds to function
                    parameter type. If the pointer argument is a struct, this struct does not contain a pointer element.
                    The message is copied byte by byte depending on a size given by the third parameter.

  \ID VCA_CANTSYN_ACCESS_TXDEBOUNCECOUNTER_IND
  \DESCRIPTION Access of debounce counter via indirection over master
  \COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

VCA_JUSTIFICATION_END */

/* COV_JUSTIFICATION_BEGIN

  \ID COV_CANTSYN_MSR_MISRA
  \ACCEPT XX
  \REASON [COV_MSR_MISRA]

  \ID COV_CANTSYN_TXCONFIRMATIONTIMEOUT
  \ACCEPT TF tf xf
  \APPLYOVERRIDE
  \REASON Not fully coverable if CanTSynMasterConfirmationTimeout smaller than CanTSynGlobalTimeTxPeriod for all masters.

  \ID COV_CANTSYN_RXINDICATION_VALID_SLAVE_INVALID_PDUID
  \ACCEPT TF
  \APPLYOVERRIDE
  \REASON Not fully coverable if no offset time domains are configured. Without offset time domains, the if-statement is always true. It is covered by other configurations.

  \ID COV_CANTSYN_SETTRANSMISSIONMODE_VALID_OTHER_OR_INVALID_CTRLID
  \ACCEPT TF
  \APPLYOVERRIDE
  \REASON Not fully coverable in multi-core/multi-partition configuration. In a multi-core/multi-partition configuration the partition index is checked already in the
          APIs Det-Checks and is therefore always valid. Furthermore for multi-core/multi-partitoin the CtrlId and partition index have a 1:1 relation.
          It is covered by other configurations.

  \ID COV_CANTSYN_TXCONFIRMATION_VALID_OTHER_OR_INVALID_PDUID
  \ACCEPT TF
  \APPLYOVERRIDE
  \REASON Not fully coverable in multi-core/multi-partition configuration. In a multi-core/multi-partition configuration the partition index is checked already in the
          APIs Det-Checks and is therefore always valid. Furthermore for multi-core/multi-partitoin the PduId and partition index have a 1:1 relation.
          It is covered by other configurations.

  --- Preprocessor Coverage Justifications ------------------------------------------------------------------------------

  \ID COV_CANTSYN_MSR_COMPATIBILITY
  \ACCEPT TX
  \REASON [COV_MSR_COMPATIBILITY]

  \ID COV_CANTSYN_DEV_ERROR_DETECT_TF_tx_tf
  \ACCEPT TF tx tf
  \REASON SafeBSW requires DEV_ERROR_DETECT to be always on. A MSSV Plugin enforces this configuration.

COV_JUSTIFICATION_END */

/**********************************************************************************************************************
 *  END OF FILE: CanTSyn.c
 *********************************************************************************************************************/

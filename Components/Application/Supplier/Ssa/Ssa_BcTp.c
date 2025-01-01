/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2024 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*!        \file  Ssa_BcTp.c
 *        \brief  Broadcast Transport Protocol of the Standard Security Architecture (Ssa).
 *
 *      \details  The Broadcast Transport Protocol provides services to send/receive data bigger than 8 Byte without
 *                the usage of a flow control.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * Crypto_VerifyResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Csm_DataType_MacAesCmacAuth
 *   Used as Buffer for service.
 *
 * Csm_DataType_MacAesCmacRealTimeOffset
 *   Used as Buffer for service.
 *
 * Csm_DataType_MacAesCmacTickCount
 *   Used as Buffer for service.
 *
 * Csm_DataType_MacAesCmacVin
 *   Used as Buffer for service.
 *
 * Csm_MacGenerateResultType_MacGenAesCmacTrunc
 *   Used as Buffer for service.
 *
 * Csm_MacVerifyCompareType_MacVerifyAesCmac
 *   Used as Buffer for service.
 *
 * SecOC_VerificationResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *
 * Port Prototypes:
 * ================
 * Coding_ReceiveVIN
 *   Configuration Variant(s): Not in VSM.
 *
 * Coding_ReceiveVINTimeout
 *   Configuration Variant(s): Not in VSM.
 *
 * Coding_SendVIN
 *   Configuration Variant(s): VSM only.
 *
 * FvM_ReceiveTickCount
 *   Configuration Variant(s): Not in VSM.
 *
 * FvM_ReceiveTickCountTimeout
 *   Configuration Variant(s): Not in VSM.
 *
 * FvM_SendTickCount
 *   Configuration Variant(s): VSM and GW only.
 *
 * KeyM_ReceiveSharedSecret
 *   Configuration Variant(s): Not in VSM.
 *
 * KeyM_SendSharedSecret
 *   Configuration Variant(s): VSM only.
 *
 * MacGen_Authentication
 *   Generates the mac for the diagnostic authentication broadcast.
 *      Connect to a Csm Mac Generate Job which uses the corresponding key for this broadcast.
 *      Configuration Variant(s): VSM only.
 *
 * MacGen_RealTime
 *   Generates the mac for the real time offset broadcast.
 *      Connect to a Csm Mac Generate Job which uses the corresponding key for this broadcast.
 *      Configuration Variant(s): VSM and GW only.
 *
 * MacGen_TickCount
 *   Generates the mac for the tick count broadcast.
 *      Connect to a Csm Mac Generate Job which uses the corresponding key for this broadcast.
 *      Configuration Variant(s): VSM and GW only.
 *
 * MacGen_VIN
 *   Generates the mac for the VIN broadcast.
 *      Connect to a Csm Mac Generate Job which uses the corresponding key for this broadcast.
 *      Configuration Variant(s): VSM only.
 *
 * MacVerify_Authentication
 *   Verifies the mac for a received diagnostic authentication broadcast.
 *      Connect to a Csm Mac Verify Job which uses the corresponding key of this broadcast.
 *      Configuration Variant(s): Not in VSM.
 *
 * MacVerify_RealTime
 *   Verifies the mac for a received real time offset broadcast.
 *      Connect to a Csm Mac Verify Job which uses the corresponding key of this broadcast.
 *      Configuration Variant(s): Not in VSM.
 *
 * MacVerify_TickCount
 *   Verifies the mac for a received tick count broadcast.
 *      Connect to a Csm Mac Verify Job which uses the corresponding key of this broadcast.
 *      Configuration Variant(s): Not in VSM.
 *
 * MacVerify_VIN
 *   Verifies the mac for a received VIN broadcast.
 *      Connect to a Csm Mac Verify Job which uses the corresponding key of this broadcast.
 *      Configuration Variant(s): Not in VSM.
 *
 * ReceiveDiagnosticAuthentication
 *   Configuration Variant(s): Not in VSM.
 *
 * ReceiveRealTimeOffset
 *   Configuration Variant(s): Not in VSM.
 *
 * ReceiveSharedSecret
 *   Configuration Variant(s): Not in VSM.
 *
 * ReceiveTickCount
 *   Configuration Variant(s): Not in VSM.
 *
 * ReceiveVIN
 *   Configuration Variant(s): Not in VSM.
 *
 * RightsM_ReceiveAuthenticationBroadcast
 *   Configuration Variant(s): Not in VSM.
 *
 * RightsM_SendAuthenticationBroadcast
 *   Configuration Variant(s): VSM only.
 *
 * SecLog_MacVerificationSecureBroadcastEvent
 *   Configuration Variant(s): Not in VSM.
 *
 * SendDiagnosticAuthentication
 *   Configuration Variant(s): VSM only.
 *
 * SendRealTimeOffset
 *   Configuration Variant(s): VSM and GW only.
 *
 * SendSharedSecret
 *   Configuration Variant(s): VSM only.
 *
 * SendTickCount
 *   Configuration Variant(s): VSM and GW only.
 *
 * SendVIN
 *   Configuration Variant(s): VSM only.
 *
 * TimeM_ReceiveRealTimeOffset
 *   Configuration Variant(s): Not in VSM.
 *
 * TimeM_SendRealTimeOffset
 *   Configuration Variant(s): VSM and GW only.
 *
 *
 * Data Element Prototypes:
 * ========================
 * VSS_TP_Auth_ST3 of Port Interface BcTp_Com_Data_Auth
 *   Data passed or received to Com.
 *
 * VSS_TP_RealTmOffset_ST3 of Port Interface BcTp_Com_Data_RealTmOffset
 *   Data passed or received to Com.
 *
 * VSS_TP_SharedSecret_ST3 of Port Interface BcTp_Com_Data_SharedSecret
 *   Data passed or received to Com.
 *
 * VSS_TP_SecTickCount_ST3 of Port Interface BcTp_Com_Data_SecTickCount
 *   Data passed or received to Com.
 *
 * VSS_TP_VIN_ST3 of Port Interface BcTp_Com_Data_VIN
 *   Data passed or received to Com.
 *
 *
 * Operation Prototypes:
 * =====================
 * MacGenerate of Port Interface CsmMacGenerate_MacGenAesCmacTruncAuth
 *   This interface shall be used to start the MAC generation service of the CSM module.
 *
 * MacGenerate of Port Interface CsmMacGenerate_MacGenAesCmacTruncRealTimeOffset
 *   This interface shall be used to start the MAC generation service of the CSM module.
 *
 * MacGenerate of Port Interface CsmMacGenerate_MacGenAesCmacTruncTickCount
 *   This interface shall be used to start the MAC generation service of the CSM module.
 *
 * MacGenerate of Port Interface CsmMacGenerate_MacGenAesCmacTruncVin
 *   This interface shall be used to start the MAC generation service of the CSM module.
 *
 * MacVerify of Port Interface CsmMacVerify_MacVerifyAesCmacAuth
 *   This interface shall be used to start the MAC verification service of the CSM module.
 *
 * MacVerify of Port Interface CsmMacVerify_MacVerifyAesCmacRealTimeOffset
 *   This interface shall be used to start the MAC verification service of the CSM module.
 *
 * MacVerify of Port Interface CsmMacVerify_MacVerifyAesCmacTickCount
 *   This interface shall be used to start the MAC verification service of the CSM module.
 *
 * MacVerify of Port Interface CsmMacVerify_MacVerifyAesCmacVin
 *   This interface shall be used to start the MAC verification service of the CSM module.
 *
 *
 * Mode Declaration Groups:
 * ========================
 * Coding_MemoryStatus
 *   Notifies the Ssa of memory status changes while storing or restoring the Variant Coding Data to or from non-volatile memory.
 *
 * Coding_Mode
 *   Notifies application about an ongoing, successful or failed coding attempt.
 *
 * RightsM_AuthenticationMode
 *   RIGHTSM_AUTHENTICATED - A Tester was successfully authenticated
 *      RIGHTSM_UNAUTHENTICATED - No tester was authenticated
 *
 * Ssa_MacKeyGeneration_State
 *   Notifies application of whether the generation of the symmetric MAC keys is OFF or ON.
 *
 *
 * Runnable Entities:
 * ==================
 * Ssa_BcTp_MainFunction
 *   Configuration Variant(s): VSM and GW only.
 *
 * Ssa_BcTp_ReceiveDiagnosticAuthentication
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_BcTp_ReceiveRealTimeOffset
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_BcTp_ReceiveSharedSecret
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_BcTp_ReceiveTickCount
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_BcTp_ReceiveTickCountTimeout
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_BcTp_ReceiveVIN
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_BcTp_ReceiveVINTimeout
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_BcTp_SendDiagnosticAuthentication
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_BcTp_SendRealTimeOffset
 *   Configuration Variant(s): VSM and GW only.
 *
 * Ssa_BcTp_SendSharedSecret
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_BcTp_SendTickCount
 *   Configuration Variant(s): VSM and GW only.
 *
 * Ssa_BcTp_SendVIN
 *   Configuration Variant(s): VSM only.
 *
 *********************************************************************************************************************/

#include "Rte_Ssa_BcTp.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ssa_Cfg.h"

#ifdef __VCA__  /* COV_SSA_VECTOR_CODE_ANALYZER_STUB_REDIRECTION */
# include "Ssa_BcTp_Redirection.vcaspecs.h"
#endif

/* After this comment only memory mapping files may be included. Due to this turn off lint rule requesting a standard
include guard. */
/*lint -e451 */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#if !defined (SSA_BCTP_LOCAL)                   /* COV_SSA_LOCAL */
# define SSA_BCTP_LOCAL                                               static
#endif

#if !defined (SSA_BCTP_LOCAL_INLINE)            /* COV_SSA_LOCAL_INLINE */
# define SSA_BCTP_LOCAL_INLINE                                        LOCAL_INLINE
#endif

/*! The time interval (in main cycles) between successive frames of a transmitted broadcast message. */
#define BCTP_TIME_TO_WAIT                                             (2u)

/*! Number of data bytes in a frame. */
#define BCTP_MAX_BYTES_IN_CF                                          (7u)

/*! The BcTp channel states. */
#define BCTP_CHANNELSTATE_FREE                                        (0u)
#define BCTP_CHANNELSTATE_START                                       (1u)
#define BCTP_CHANNELSTATE_WAIT                                        (2u)
#define BCTP_CHANNELSTATE_COPYDATA                                    (3u)

/*! Freshness value id. */
#define BCTP_FRESHNESSVALUE_ID                                        (1u)
/*! Freshness value: non-truncated length */
#define BCTP_FRESHNESSVALUE_LENGTH                                    (5u)

/*! The data id length. */
#define BCTP_DATA_ID_LENGTH                                           (2u)

/*! Size of truncated MAC. */
#define BCTP_TRUNC_MAC_LENGTH                                         (8u)
#define BCTP_TRUNC_MAC_LENGTH_MAX                                     (8u)
/*! Size of truncated freshness value. */
#define BCTP_TRUNC_FRESHNESS_LENGTH                                   (1u)

/*! Workspace identifier of the broadcast messages: It indexes into BcTp_MsgInfo */
#define BCTP_TICKCOUNT_ID                                             (0u)
#define BCTP_DIAGNOSTICAUTHENTICATION_ID                              (1u)
#define BCTP_REALTIMEOFFSET_ID                                        (2u)
#define BCTP_SHAREDSECRET_ID                                          (3u)
#define BCTP_VIN_ID                                                   (4u)
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY)
# define BCTP_TICKCOUNTTX_ID                                          (5u)
# define BCTP_REALTIMEOFFSETTX_ID                                     (6u)
# define BCTP_NUMBER_OF_MESSAGES                                      (7u)
#else
# define BCTP_TICKCOUNTTX_ID                                          BCTP_TICKCOUNT_ID
# define BCTP_REALTIMEOFFSETTX_ID                                     BCTP_REALTIMEOFFSET_ID
# define BCTP_NUMBER_OF_MESSAGES                                      (5u)
#endif

/*! The length of the broadcast messages and the size of the buffers needed by BcTp for them. */
#define BCTP_TICKCOUNT_LENGTH                                         (6u)
#define BCTP_TICKCOUNT_BUFFER_LENGTH                                  (BCTP_DATA_ID_LENGTH + BCTP_TICKCOUNT_LENGTH + BCTP_FRESHNESSVALUE_LENGTH + BCTP_TRUNC_MAC_LENGTH_MAX)

#define BCTP_DIAGNOSTICAUTHENTICATION_LENGTH                          (20u)
#define BCTP_DIAGNOSTICAUTHENTICATION_BUFFER_LENGTH                   (BCTP_DATA_ID_LENGTH + BCTP_DIAGNOSTICAUTHENTICATION_LENGTH + BCTP_FRESHNESSVALUE_LENGTH + BCTP_TRUNC_MAC_LENGTH_MAX)

#define BCTP_REALTIMEOFFSET_LENGTH                                    (12u)
#define BCTP_REALTIMEOFFSET_BUFFER_LENGTH                             (BCTP_DATA_ID_LENGTH + BCTP_REALTIMEOFFSET_LENGTH + BCTP_FRESHNESSVALUE_LENGTH + BCTP_TRUNC_MAC_LENGTH_MAX)

#define BCTP_SHAREDSECRET_LENGTH                                      (32u)
#define BCTP_SHAREDSECRET_BUFFER_LENGTH                               (BCTP_DATA_ID_LENGTH + BCTP_SHAREDSECRET_LENGTH)

#define BCTP_VIN_LENGTH                                               (17u)
#define BCTP_VIN_BUFFER_LENGTH                                        (BCTP_DATA_ID_LENGTH + BCTP_VIN_LENGTH + BCTP_FRESHNESSVALUE_LENGTH + BCTP_TRUNC_MAC_LENGTH_MAX)

#define BCTP_DATASTART_POS                                            BCTP_DATA_ID_LENGTH

/*! The status bit indicating an invalid tick-count message to FvM. */
#define BCTP_STATUS_INFO_INVALID_MESSAGE                              ((uint8)0x01u)
#define BCTP_STATUS_INFO_INVALID_MESSAGE_INV                          ((uint8)0xFEu)

/*! Error code PENDING. */
#define BCTP_E_PENDING                                                (2u)

/* ! Unused timeout event dummy state. */
#define TIMEOUT_EVENT_DUMMY_STATE                                     (1u)

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/
#define BcTp_GetLengthOfMsg(id)                                       (BcTp_MsgInfo[id].dataLength + BcTp_MsgInfo[id].freshnessLength + BcTp_MsgInfo[id].macLength)   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* compile time assertions */
#if !defined (Ssa_CompileTimeAssert)             /* COV_SSA_LOCAL_INLINE */
# define Ssa_CompileTimeAssert(cond, desc)                       typedef uint8 desc[(cond) ? 1 : 0] /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* The following compile time assertions ensure the sizes of data types used within the BcTp submodule
 * when calling RTE APIs expecting these data types. 
 * The assertions ensure that the size of these data types is consistent with respective buffer lengths defined in the Ssa.
 * For ASIL-D, the vector code analyzer checks the same conditions within the BcTp_Init() function. */
/* PRQA S 3205, 3493 10 */ /* MD_SSA_COMPILE_TIME_ASSERTION */
Ssa_CompileTimeAssert(sizeof(Coding_VINDataType) == 17u, InvalidSizeOf_Coding_VINDataType); /*lint !e506 */
#if (SSA_ECU_TYPE != SSA_ECU_TYPE_NORMAL)
Ssa_CompileTimeAssert(sizeof(Csm_MacGenerateResultType_MacGenAesCmacTrunc) == 8u, InvalidSizeOf_Csm_MacGenerateResultType_MacGenAesCmacTrunc); /*lint !e506 */
#endif
Ssa_CompileTimeAssert(sizeof(KeyM_SharedSecretType) == 32u, InvalidSizeOf_KeyM_SharedSecretType); /*lint !e506 */
Ssa_CompileTimeAssert(sizeof(RightsM_AuthenticationBroadcastType) == 20u, InvalidSizeOf_RightsM_AuthenticationBroadcastType); /*lint !e506 */
Ssa_CompileTimeAssert(sizeof(Ssa_Data12ByteType) == 12u, InvalidSizeOf_Ssa_Data12ByteType); /*lint !e506 */
Ssa_CompileTimeAssert(sizeof(Ssa_Data6ByteType) == 6u, InvalidSizeOf_Ssa_Data6ByteType); /*lint !e506 */
Ssa_CompileTimeAssert(sizeof(Ssa_Data8ByteType) == 8u, InvalidSizeOf_Ssa_Data8ByteType); /*lint !e506 */
Ssa_CompileTimeAssert(sizeof(freshnessValueType) == 8u, InvalidSizeOf_freshnessValueType); /*lint !e506 */

typedef P2FUNC(Std_ReturnType, Ssa_BcTp_CODE, BcTp_SendFctPtrType)(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) data);
typedef P2FUNC(Std_ReturnType, Ssa_BcTp_CODE, BcTp_MacVerifyFctPtrType)(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) dataBuffer, uint32 dataLength, P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) macBuffer, uint32 macLength, P2VAR(Crypto_VerifyResultType, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) verifyBuffer);
typedef P2FUNC(Std_ReturnType, Ssa_BcTp_CODE, BcTp_MacGenerateFctPtrType)(P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) dataBuffer, uint32 dataLength, P2VAR(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) macBuffer, P2VAR(uint32, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) macLength);

/*! Message state structure. */
typedef struct
{
  uint8 length;
  uint8 frame;
  uint8 state;
  uint8 retries_time;
} BcTp_MsgStateType;

/*! Message information structure. */
typedef struct
{
  uint16 dataId;
  uint8 dataLength;
  uint8 macLength;
  uint8 freshnessLength; /*!< The TRUNCATED length of the freshness value (as opposed to BCTP_FRESHNESSVALUE_LENGTH) */
  BcTp_SendFctPtrType sendFct;
  BcTp_MacGenerateFctPtrType macGenFct;
  BcTp_MacVerifyFctPtrType macVerifyFct;
  P2VAR(uint8, TYPEDEF, AUTOMATIC) msgData;
} BcTp_MsgInfoType;

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define Ssa_BcTp_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Ssa_BcTp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Buffer for tick-count broadcast message. */
SSA_BCTP_LOCAL VAR(uint8, Ssa_BcTp_VAR_NOINIT) BcTp_Buffer_Tickcount[BCTP_TICKCOUNT_BUFFER_LENGTH];
/*! Buffer for authentication broadcast message. */
SSA_BCTP_LOCAL VAR(uint8, Ssa_BcTp_VAR_NOINIT) BcTp_Buffer_DiagnosticAuthentication[BCTP_DIAGNOSTICAUTHENTICATION_BUFFER_LENGTH];
/*! Buffer for real-time offset broadcast message. */
SSA_BCTP_LOCAL VAR(uint8, Ssa_BcTp_VAR_NOINIT) BcTp_Buffer_RealtimeOffset[BCTP_REALTIMEOFFSET_BUFFER_LENGTH];
/*! Buffer for shared secret broadcast message. */
SSA_BCTP_LOCAL VAR(uint8, Ssa_BcTp_VAR_NOINIT) BcTp_Buffer_SharedSecret[BCTP_SHAREDSECRET_BUFFER_LENGTH];
/*! Buffer for VIN broadcast message. */
SSA_BCTP_LOCAL VAR(uint8, Ssa_BcTp_VAR_NOINIT) BcTp_Buffer_Vin[BCTP_VIN_BUFFER_LENGTH];

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY)
/*! Transmission buffer for tick-count broadcast message. */
SSA_BCTP_LOCAL VAR(uint8, Ssa_BcTp_VAR_NOINIT) BcTp_TxBuffer_Tickcount[BCTP_TICKCOUNT_BUFFER_LENGTH];
/*! Transmission buffer for real-time offset broadcast message. */
SSA_BCTP_LOCAL VAR(uint8, Ssa_BcTp_VAR_NOINIT) BcTp_TxBuffer_RealtimeOffset[BCTP_REALTIMEOFFSET_BUFFER_LENGTH];
#endif

/*! The message's channel state. */
SSA_BCTP_LOCAL volatile VAR(BcTp_MsgStateType, Ssa_BcTp_VAR_NOINIT) BcTp_MsgState[BCTP_NUMBER_OF_MESSAGES];

#define Ssa_BcTp_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Ssa_BcTp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL CONST DATA
 **********************************************************************************************************************/

#define Ssa_BcTp_START_SEC_CONST_UNSPECIFIED
#include "Ssa_BcTp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

SSA_BCTP_LOCAL CONST(BcTp_MsgInfoType, Ssa_BcTp_CONST) BcTp_MsgInfo[BCTP_NUMBER_OF_MESSAGES] =
{
  { /* === Tickcount === */
    /* Data Id */               SSA_DATAID_TICKCOUNT,
    /* Msg Length */            BCTP_TICKCOUNT_LENGTH,
    /* Mac Length */            BCTP_TRUNC_MAC_LENGTH,
    /* Freshness Length */      0u,
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
    /* SendFunction */          Rte_Write_SendTickCount_VSS_TP_SecTickCount_ST3,
    /* MacGenFunction */        Rte_Call_MacGen_TickCount_MacGenerate,
    /* MacVerifyFunction */     NULL_PTR,
#else
    /* SendFunction */          NULL_PTR,
    /* MacGenFunction */        NULL_PTR,
    /* MacVerifyFunction */     Rte_Call_MacVerify_TickCount_MacVerify,
#endif
    /* msgData */               BcTp_Buffer_Tickcount
  },

  { /* === Authentication === */
    /* Data Id */               SSA_DATAID_DIAGNOSTICAUTHENTICATION,
    /* Msg Length */            BCTP_DIAGNOSTICAUTHENTICATION_LENGTH,
    /* Mac Length */            BCTP_TRUNC_MAC_LENGTH,
    /* Freshness Length */      BCTP_TRUNC_FRESHNESS_LENGTH,
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
    /* SendFunction */          Rte_Write_SendDiagnosticAuthentication_VSS_TP_Auth_ST3,
    /* MacGenFunction */        Rte_Call_MacGen_Authentication_MacGenerate,
    /* MacVerifyFunction */     NULL_PTR,
#else
    /* SendFunction */          NULL_PTR,
    /* MacGenFunction */        NULL_PTR,
    /* MacVerifyFunction */     Rte_Call_MacVerify_Authentication_MacVerify,
#endif
    /* msgData */               BcTp_Buffer_DiagnosticAuthentication
  },

  { /* === Realtime === */
    /* Data Id */               SSA_DATAID_REALTIME,
    /* Msg Length */            BCTP_REALTIMEOFFSET_LENGTH,
    /* Mac Length */            BCTP_TRUNC_MAC_LENGTH,
    /* Freshness Length */      BCTP_TRUNC_FRESHNESS_LENGTH,
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
    /* SendFunction */          Rte_Write_SendRealTimeOffset_VSS_TP_RealTmOffset_ST3,
    /* MacGenFunction */        Rte_Call_MacGen_RealTime_MacGenerate,
    /* MacVerifyFunction */     NULL_PTR,
#else
    /* SendFunction */          NULL_PTR,
    /* MacGenFunction */        NULL_PTR,
    /* MacVerifyFunction */     Rte_Call_MacVerify_RealTime_MacVerify,
#endif
    /* msgData */               BcTp_Buffer_RealtimeOffset
  },

  { /* === SharedSecret === */
    /* Data Id */               0u,
    /* Msg Length */            BCTP_SHAREDSECRET_LENGTH,
    /* Mac Length */            0u,
    /* Freshness Length */      0u,
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
    /* SendFunction */          Rte_Write_SendSharedSecret_VSS_TP_SharedSecret_ST3,
#else
    /* SendFunction */          NULL_PTR,
#endif
    /* MacGenFunction */        NULL_PTR,
    /* MacVerifyFunction */     NULL_PTR,
    /* msgData */               BcTp_Buffer_SharedSecret
  },

  { /* === VIN === */
    /* Data Id */               SSA_DATAID_VIN,
    /* Msg Length */            BCTP_VIN_LENGTH,
    /* Mac Length */            BCTP_TRUNC_MAC_LENGTH,
    /* Freshness Length */      BCTP_TRUNC_FRESHNESS_LENGTH,
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
    /* SendFunction */          Rte_Write_SendVIN_VSS_TP_VIN_ST3,
    /* MacGenFunction */        Rte_Call_MacGen_VIN_MacGenerate,
    /* MacVerifyFunction */     NULL_PTR,
#else
    /* SendFunction */          NULL_PTR,
    /* MacGenFunction */        NULL_PTR,
    /* MacVerifyFunction */     Rte_Call_MacVerify_VIN_MacVerify,
#endif
    /* msgData */               BcTp_Buffer_Vin
  }
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY)
,

  { /* === Tickcount Send (Gw_Only) === */
    /* Data Id */               SSA_DATAID_TICKCOUNT,
    /* Data Length */           BCTP_TICKCOUNT_LENGTH,
    /* Mac Length */            BCTP_TRUNC_MAC_LENGTH,
    /* Freshness Length */      0u,
    /* SendFunction */          Rte_Write_SendTickCount_VSS_TP_SecTickCount_ST3,
    /* MacGenFunction */        Rte_Call_MacGen_TickCount_MacGenerate,
    /* MacVerifyFunction */     NULL_PTR,
    /* msgData */               BcTp_TxBuffer_Tickcount
  },

  { /* === Realtime Send (Gw_Only) === */
    /* Data Id */               SSA_DATAID_REALTIME,
    /* Data Length */           BCTP_REALTIMEOFFSET_LENGTH,
    /* Mac Length */            BCTP_TRUNC_MAC_LENGTH,
    /* Freshness Length */      BCTP_TRUNC_FRESHNESS_LENGTH,
    /* SendFunction */          Rte_Write_SendRealTimeOffset_VSS_TP_RealTmOffset_ST3,
    /* MacGenFunction */        Rte_Call_MacGen_RealTime_MacGenerate,
    /* MacVerifyFunction */     NULL_PTR,
    /* msgData */               BcTp_TxBuffer_RealtimeOffset
  }
#endif
};

#define Ssa_BcTp_STOP_SEC_CONST_UNSPECIFIED
#include "Ssa_BcTp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define Ssa_BcTp_START_SEC_CODE
#include "Ssa_BcTp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
/**********************************************************************************************************************
 * BcTp_Send()
 *********************************************************************************************************************/
/*!
 * \brief       Sends one BcTp frame.
 * \details     -
 * \param[in]   msgId  The identifier of the broadcast message to be sent.
 * \pre         BcTp_MsgState[msgId].state is BCTP_CHANNELSTATE_COPYDATA
 *              The value passed as parameter 'msgId' must be smaller than BCTP_NUMBER_OF_MESSAGES.
 * \context     TASK
 * \reentrant   TRUE, but not for the same msgId
 * \synchronous TRUE
 */
SSA_BCTP_LOCAL_INLINE FUNC(void, Ssa_BcTp_CODE) BcTp_Send(uint8 msgId);

/**********************************************************************************************************************
 * BcTp_StartTransmission()
 *********************************************************************************************************************/
/*!
 * \brief       Starts the transmission of a broadcast message.
 * \details     -
 * \param[in]   msgId  The identifier of the broadcast message to be sent.
 * \pre         The value passed as parameter 'msgId' must be smaller than BCTP_NUMBER_OF_MESSAGES.
 * \context     TASK
 * \reentrant   TRUE, but not for the same msgId
 * \synchronous TRUE
 */
SSA_BCTP_LOCAL FUNC(void, Ssa_BcTp_CODE) BcTp_StartTransmission(uint8 msgId);
#endif

/**********************************************************************************************************************
 * BcTp_Copy()
 *********************************************************************************************************************/
/*!
 * \brief       Copies the given number of bytes from the source buffer to the destination buffer.
 * \details     -
 * \param[out]  dest   The memory address of the destination buffer.
 * \param[in]   source The memory address of the source buffer.
 * \param[in]   length The number of bytes that shall be copied.
 * \pre         dest, source must be valid pointers
 *              dest must point to a buffer that is at least of the size given by parameter 'length'
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 * \note        No null-pointer check.
 * \spec        requires dest != NULL_PTR;
 *              requires $lengthOf(dest) >= length;                                                            \endspec
 */
SSA_BCTP_LOCAL_INLINE FUNC(void, Ssa_BcTp_CODE) BcTp_Copy(P2VAR(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) dest, P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) source, uint8 length);

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 * BcTp_Receive()
 *********************************************************************************************************************/
/*!
 * \brief       Receives a broadcast message frame by frame.
 * \details     This function is called each time a frame of a broadcast message is received. After all frames are received
 *              the MAC is verified.
 * \param[in]   msgId  The identifier of the broadcast message of which a frame is received.
 * \param[in]   data   The data of the frame.
 * \return      E_OK           The MAC verification succeeded.
 * \return      E_NOT_OK       The MAC verification failed (or any other error occurred).
 * \return      BCTP_E_PENDING Not all frames of the broadcast message are received yet. Only relevant for the tick-count broadcast message.
 * \pre         data must be a valid pointer.
 *              The value passed as parameter 'msgId' must be smaller than BCTP_NUMBER_OF_MESSAGES.
 * \context     TASK
 * \reentrant   TRUE, but not for the same msgId
 * \synchronous TRUE
 */
SSA_BCTP_LOCAL FUNC(Std_ReturnType, Ssa_BcTp_CODE) BcTp_Receive(uint8 msgId, P2CONST(uint8, AUTOMATIC, AUTOMATIC) data);

/**********************************************************************************************************************
 * BcTp_Verify()
 *********************************************************************************************************************/
/*!
 * \brief         Verifies the MAC of received broadcast message.
 * \details       -
 * \param[in]     msgId  The identifier of the broadcast message of which a frame is received.
 * \param[in,out] buffer Buffer containing the broadcast message data, freshness data and the MAC data.
 * \return        E_OK           The MAC verification succeeded.
 * \return        E_NOT_OK       The MAC verification failed (or any other error occurred).
 * \pre           BcTp_MsgInfo[msgId].macVerifyFct is a valid pointer pointing to a function of type BcTp_MacVerifyFctPtrType.
 *                'buffer' is referencing a buffer that is at least of size BcTp_MsgInfo[msgId].dataLength + BCTP_FRESHNESSVALUE_LENGTH + BcTp_MsgInfo[msgId].macLength
 *                The value passed as parameter 'msgId' must be smaller than BCTP_NUMBER_OF_MESSAGES.
 * \context       TASK
 * \reentrant     TRUE, but not for the same msgId
 * \synchronous   TRUE
 */
SSA_BCTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_BcTp_CODE) BcTp_Verify(uint8 msgId, P2VAR(uint8, AUTOMATIC, Ssa_BcTp_VAR_NOINIT) buffer);
#endif

#define Ssa_BcTp_STOP_SEC_CODE
#include "Ssa_BcTp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Crypto_VerifyResultType: Enumeration of integer in interval [0...1] with enumerators
 *   CRYPTO_E_VER_OK (0U)
 *   CRYPTO_E_VER_NOT_OK (1U)
 * SecOC_VerificationResultType: Enumeration of integer in interval [0...255] with enumerators
 *   SECOC_VERIFICATIONSUCCESS (0U)
 *   SECOC_VERIFICATIONFAILURE (1U)
 *   SECOC_FRESHNESSFAILURE (2U)
 *   SECOC_AUTHENTICATIONBUILDFAILURE (3U)
 *   SECOC_NO_VERIFICATION (4U)
 *   SECOC_VERIFICATIONFAILURE_OVERWRITTEN (5U)
 *
 * Array Types:
 * ============
 * Coding_VINDataType: Array with 17 element(s) of type uint8
 * Csm_DataType_MacAesCmacAuth: Array with 27 element(s) of type uint8
 * Csm_DataType_MacAesCmacRealTimeOffset: Array with 19 element(s) of type uint8
 * Csm_DataType_MacAesCmacTickCount: Array with 13 element(s) of type uint8
 * Csm_DataType_MacAesCmacVin: Array with 24 element(s) of type uint8
 * Csm_MacGenerateResultType_MacGenAesCmacTrunc: Array with 8 element(s) of type uint8
 * Csm_MacVerifyCompareType_MacVerifyAesCmac: Array with 8 element(s) of type uint8
 * KeyM_SharedSecretType: Array with 32 element(s) of type uint8
 * RightsM_AuthenticationBroadcastType: Array with 20 element(s) of type uint8
 * Ssa_Data12ByteType: Array with 12 element(s) of type uint8
 * Ssa_Data6ByteType: Array with 6 element(s) of type uint8
 * Ssa_Data8ByteType: Array with 8 element(s) of type uint8
 * freshnessValueType: Array with 8 element(s) of type uint8
 *
 * Record Types:
 * =============
 * SecOC_VerificationStatusType: Record with elements
 *   freshnessValueID of type uint16
 *   verificationStatus of type SecOC_VerificationResultType
 *   secOCDataId of type uint16
 *
 *********************************************************************************************************************/


#define Ssa_BcTp_START_SEC_CODE
#include "Ssa_BcTp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_BcTp_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_Init_doc
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
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_Init
 *********************************************************************************************************************/
  uint8 msgId;
  /* #10 Iterate over all broadcast messages. */
  for (msgId = 0u; msgId < BCTP_NUMBER_OF_MESSAGES; msgId++)
  {
    /* #20 Set the message's channel state to "free". */
    BcTp_MsgState[msgId].state = BCTP_CHANNELSTATE_FREE;

    /* #30 Data ID is constant, so it can be inserted in buffer at startup. */
    BcTp_MsgInfo[msgId].msgData[0] = (uint8)(BcTp_MsgInfo[msgId].dataId >> 8u);
    BcTp_MsgInfo[msgId].msgData[1] = (uint8)(BcTp_MsgInfo[msgId].dataId & 0xFFu);
  }

  /* Ensure type sizes once for the BcTp submodule which calls RTE APIs expecting these data types:
   * Coding_VINDataType must be an array with with 17 element(s) of type uint8
   * Csm_MacGenerateResultType_MacGenAesCmacTrunc must be an array with with 8 element(s) of type uint8
   * KeyM_SharedSecretType must be an array with with 32 element(s) of type uint8
   * RightsM_AuthenticationBroadcastType must be an array with with 20 element(s) of type uint8
   * Ssa_Data12ByteType must be an array with with 12 element(s) of type uint8
   * Ssa_Data6ByteType must be an array with with 6 element(s) of type uint8
   * Ssa_Data8ByteType must be an array with with 8 element(s) of type uint8
   * freshnessValueType must be an array with with 8 element(s) of type uint8 */

  /*@ assert sizeof(Coding_VINDataType) == 17; */
#if (SSA_ECU_TYPE != SSA_ECU_TYPE_NORMAL)
  /*@ assert sizeof(Csm_MacGenerateResultType_MacGenAesCmacTrunc) == 8; */
#endif
  /*@ assert sizeof(KeyM_SharedSecretType) == 32; */
  /*@ assert sizeof(RightsM_AuthenticationBroadcastType) == 20; */
  /*@ assert sizeof(Ssa_Data12ByteType) == 12; */
  /*@ assert sizeof(Ssa_Data6ByteType) == 6; */
  /*@ assert sizeof(Ssa_Data8ByteType) == 8; */
  /*@ assert sizeof(freshnessValueType) == 8; */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_BcTp_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SendDiagnosticAuthentication_VSS_TP_Auth_ST3(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data8ByteType
 *   Std_ReturnType Rte_Write_SendRealTimeOffset_VSS_TP_RealTmOffset_ST3(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data8ByteType
 *   Std_ReturnType Rte_Write_SendSharedSecret_VSS_TP_SharedSecret_ST3(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data8ByteType
 *   Std_ReturnType Rte_Write_SendTickCount_VSS_TP_SecTickCount_ST3(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data8ByteType
 *   Std_ReturnType Rte_Write_SendVIN_VSS_TP_VIN_ST3(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data8ByteType
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_MainFunction_doc
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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_MainFunction
 *********************************************************************************************************************/
  uint8 msgId;
  /* #10 Iterate over all broadcast messages. */
  for (msgId = 0u; msgId < BCTP_NUMBER_OF_MESSAGES; msgId++)
  {
    /* #20 Check the message's channel state is "wait". */
    if (BcTp_MsgState[msgId].state == BCTP_CHANNELSTATE_WAIT)
    {
      /* #30 Increment the retries counter. */
      BcTp_MsgState[msgId].retries_time += 1u;
      /* #40 Check that the configured "time to wait" is reached. */
      if (BcTp_MsgState[msgId].retries_time == BCTP_TIME_TO_WAIT)
      {
        /* #50 Reset the retries counter. */
        BcTp_MsgState[msgId].retries_time = 0u;
        /* #60 If there is still data in the transmit buffer set the message's channel state to "copy data",
         * else (transmit buffer is empty) to "free". */
        BcTp_MsgState[msgId].state = BCTP_CHANNELSTATE_COPYDATA;
      }
    }
    /* #70 If the message's channel state is "copy data" (i.e. there is data to transmit) call the broadcast send
     *  routine for handled message id. */
    if (BcTp_MsgState[msgId].state > BCTP_CHANNELSTATE_WAIT)
    {
      /* Hint for VCA analysis: 
       * For ECUs of type GATEWAY, BcTp_Send is only called for msgId = 5 or msgId = 6, see VCA_SSA_BCTP_SEND_FUNCTION.
       * (msgId 5 - TickCountSend, msgId 6 - RealTimeSend) */
      BcTp_Send(msgId);
    }
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_BcTp_ReceiveDiagnosticAuthentication
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <VSS_TP_Auth_ST3> of PortPrototype <ReceiveDiagnosticAuthentication>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ReceiveDiagnosticAuthentication_VSS_TP_Auth_ST3(uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data8ByteType
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_RightsM_ReceiveAuthenticationBroadcast_authentication(const uint8 *data)
 *     Argument data: uint8* is of type RightsM_AuthenticationBroadcastType
 *   Std_ReturnType Rte_Write_SecLog_MacVerificationSecureBroadcastEvent_verificationStatus(const SecOC_VerificationStatusType *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FvM_FreshnessManagement_GetRxFreshness(uint16 freshnessValueId, const uint8 *truncatedFreshnessValue, uint32 truncatedFreshnessValueLength, uint16 authVerifyAttempts, uint8 *freshnessValue, uint32 *freshnessValueLength)
 *     Argument truncatedFreshnessValue: uint8* is of type freshnessValueType
 *     Argument freshnessValue: uint8* is of type freshnessValueType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FvM_FreshnessManagement_E_BUSY, RTE_E_FvM_FreshnessManagement_E_NOT_OK, RTE_E_FvM_FreshnessManagement_E_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MacVerify_Authentication_MacVerify(const uint8 *dataBuffer, uint32 dataLength, const uint8 *macBuffer, uint32 macLength, Crypto_VerifyResultType *verifyBuffer)
 *     Argument dataBuffer: uint8* is of type Csm_DataType_MacAesCmacAuth
 *     Argument macBuffer: uint8* is of type Csm_MacVerifyCompareType_MacVerifyAesCmac
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmMacVerify_MacVerifyAesCmacAuth_CSM_E_BUSY, RTE_E_CsmMacVerify_MacVerifyAesCmacAuth_CSM_E_KEY_EMPTY, RTE_E_CsmMacVerify_MacVerifyAesCmacAuth_CSM_E_KEY_NOT_VALID, RTE_E_CsmMacVerify_MacVerifyAesCmacAuth_CSM_E_KEY_SIZE_MISMATCH, RTE_E_CsmMacVerify_MacVerifyAesCmacAuth_CSM_E_SMALL_BUFFER, RTE_E_CsmMacVerify_MacVerifyAesCmacAuth_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_ReceiveDiagnosticAuthentication_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_ReceiveDiagnosticAuthentication(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_ReceiveDiagnosticAuthentication
 *********************************************************************************************************************/
  uint8 buffer[8];
  /* #20 Read the broadcast frame data from the receive buffer. */
  if (Rte_Read_ReceiveDiagnosticAuthentication_VSS_TP_Auth_ST3(buffer) == E_OK)
  {
    /* #30 Process the received data. */
    if (BcTp_Receive(BCTP_DIAGNOSTICAUTHENTICATION_ID, buffer) == E_OK)
    {
      /* #40 If the message is complete and valid, forward it to regular receiver. */
      (void)Rte_Write_RightsM_ReceiveAuthenticationBroadcast_authentication(&BcTp_MsgInfo[BCTP_DIAGNOSTICAUTHENTICATION_ID].msgData[BCTP_DATASTART_POS]);
    }
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_BcTp_ReceiveRealTimeOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <VSS_TP_RealTmOffset_ST3> of PortPrototype <ReceiveRealTimeOffset>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ReceiveRealTimeOffset_VSS_TP_RealTmOffset_ST3(uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data8ByteType
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SecLog_MacVerificationSecureBroadcastEvent_verificationStatus(const SecOC_VerificationStatusType *data)
 *   Std_ReturnType Rte_Write_TimeM_ReceiveRealTimeOffset_realTimeOffset(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data12ByteType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FvM_FreshnessManagement_GetRxFreshness(uint16 freshnessValueId, const uint8 *truncatedFreshnessValue, uint32 truncatedFreshnessValueLength, uint16 authVerifyAttempts, uint8 *freshnessValue, uint32 *freshnessValueLength)
 *     Argument truncatedFreshnessValue: uint8* is of type freshnessValueType
 *     Argument freshnessValue: uint8* is of type freshnessValueType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FvM_FreshnessManagement_E_BUSY, RTE_E_FvM_FreshnessManagement_E_NOT_OK, RTE_E_FvM_FreshnessManagement_E_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MacVerify_RealTime_MacVerify(const uint8 *dataBuffer, uint32 dataLength, const uint8 *macBuffer, uint32 macLength, Crypto_VerifyResultType *verifyBuffer)
 *     Argument dataBuffer: uint8* is of type Csm_DataType_MacAesCmacRealTimeOffset
 *     Argument macBuffer: uint8* is of type Csm_MacVerifyCompareType_MacVerifyAesCmac
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmMacVerify_MacVerifyAesCmacRealTimeOffset_CSM_E_BUSY, RTE_E_CsmMacVerify_MacVerifyAesCmacRealTimeOffset_CSM_E_KEY_EMPTY, RTE_E_CsmMacVerify_MacVerifyAesCmacRealTimeOffset_CSM_E_KEY_NOT_VALID, RTE_E_CsmMacVerify_MacVerifyAesCmacRealTimeOffset_CSM_E_KEY_SIZE_MISMATCH, RTE_E_CsmMacVerify_MacVerifyAesCmacRealTimeOffset_CSM_E_SMALL_BUFFER, RTE_E_CsmMacVerify_MacVerifyAesCmacRealTimeOffset_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_ReceiveRealTimeOffset_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_ReceiveRealTimeOffset(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_ReceiveRealTimeOffset
 *********************************************************************************************************************/
  uint8 buffer[8];
  /* #20 Read the broadcast frame data from the receive buffer. */
  if (Rte_Read_ReceiveRealTimeOffset_VSS_TP_RealTmOffset_ST3(buffer) == E_OK)
  {
    /* #30 Process the received data. */
    if (BcTp_Receive(BCTP_REALTIMEOFFSET_ID, buffer) == E_OK)
    {
      /* #40 If the message is complete and valid, forward it to regular receiver. */
      (void)Rte_Write_TimeM_ReceiveRealTimeOffset_realTimeOffset(&BcTp_MsgInfo[BCTP_REALTIMEOFFSET_ID].msgData[BCTP_DATASTART_POS]);
    }
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_BcTp_ReceiveSharedSecret
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <VSS_TP_SharedSecret_ST3> of PortPrototype <ReceiveSharedSecret>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ReceiveSharedSecret_VSS_TP_SharedSecret_ST3(uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data8ByteType
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_KeyM_ReceiveSharedSecret_sharedSecret(const uint8 *data)
 *     Argument data: uint8* is of type KeyM_SharedSecretType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FvM_FreshnessManagement_GetRxFreshness(uint16 freshnessValueId, const uint8 *truncatedFreshnessValue, uint32 truncatedFreshnessValueLength, uint16 authVerifyAttempts, uint8 *freshnessValue, uint32 *freshnessValueLength)
 *     Argument truncatedFreshnessValue: uint8* is of type freshnessValueType
 *     Argument freshnessValue: uint8* is of type freshnessValueType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FvM_FreshnessManagement_E_BUSY, RTE_E_FvM_FreshnessManagement_E_NOT_OK, RTE_E_FvM_FreshnessManagement_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_ReceiveSharedSecret_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_ReceiveSharedSecret(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_ReceiveSharedSecret
 *********************************************************************************************************************/
  uint8 buffer[8];
  /* #20 Read the broadcast frame data from the receive buffer. */
  if (Rte_Read_ReceiveSharedSecret_VSS_TP_SharedSecret_ST3(buffer) == E_OK)
  {
    /* #30 Process the received data. */
    if (BcTp_Receive(BCTP_SHAREDSECRET_ID, buffer) == E_OK)
    {
      /* #40 If the message is complete and valid, forward it to regular receiver. */
      (void)Rte_Write_KeyM_ReceiveSharedSecret_sharedSecret(&BcTp_MsgInfo[BCTP_SHAREDSECRET_ID].msgData[BCTP_DATASTART_POS]);
    }
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_BcTp_ReceiveTickCount
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <VSS_TP_SecTickCount_ST3> of PortPrototype <ReceiveTickCount>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ReceiveTickCount_VSS_TP_SecTickCount_ST3(uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data8ByteType
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_FvM_ReceiveTickCount_tickCount(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data6ByteType
 *   Std_ReturnType Rte_Write_SecLog_MacVerificationSecureBroadcastEvent_verificationStatus(const SecOC_VerificationStatusType *data)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MacVerify_TickCount_MacVerify(const uint8 *dataBuffer, uint32 dataLength, const uint8 *macBuffer, uint32 macLength, Crypto_VerifyResultType *verifyBuffer)
 *     Argument dataBuffer: uint8* is of type Csm_DataType_MacAesCmacTickCount
 *     Argument macBuffer: uint8* is of type Csm_MacVerifyCompareType_MacVerifyAesCmac
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmMacVerify_MacVerifyAesCmacTickCount_CSM_E_BUSY, RTE_E_CsmMacVerify_MacVerifyAesCmacTickCount_CSM_E_KEY_EMPTY, RTE_E_CsmMacVerify_MacVerifyAesCmacTickCount_CSM_E_KEY_NOT_VALID, RTE_E_CsmMacVerify_MacVerifyAesCmacTickCount_CSM_E_KEY_SIZE_MISMATCH, RTE_E_CsmMacVerify_MacVerifyAesCmacTickCount_CSM_E_SMALL_BUFFER, RTE_E_CsmMacVerify_MacVerifyAesCmacTickCount_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_ReceiveTickCount_doc
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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_ReceiveTickCount(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_ReceiveTickCount
 *********************************************************************************************************************/
  uint8 buffer[8];
  /* #20 Read the broadcast frame data from the receive buffer. */
  if (Rte_Read_ReceiveTickCount_VSS_TP_SecTickCount_ST3(buffer) == E_OK)
  {
    Std_ReturnType retVal;
    /* #30 Process the received data. */
    retVal = BcTp_Receive(BCTP_TICKCOUNT_ID, buffer);
    /* #40 Check that the message is complete. */
    if (retVal != BCTP_E_PENDING)
    {
      if (retVal == E_OK)
      {
        /* #50 If the message is valid, clear the least significant bit of the status information byte. */
        BcTp_MsgInfo[BCTP_TICKCOUNT_ID].msgData[BCTP_DATASTART_POS] &= BCTP_STATUS_INFO_INVALID_MESSAGE_INV;
      }
      else
      {
        /* #55 If the message is not valid, mark the least significant bit of the status information byte. */
        BcTp_MsgInfo[BCTP_TICKCOUNT_ID].msgData[BCTP_DATASTART_POS] |= BCTP_STATUS_INFO_INVALID_MESSAGE;
      }
      /* #60 Forward the message to regular receiver. */
      (void)Rte_Write_FvM_ReceiveTickCount_tickCount(&BcTp_MsgInfo[BCTP_TICKCOUNT_ID].msgData[BCTP_DATASTART_POS]);
    }
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_BcTp_ReceiveTickCountTimeout
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <VSS_TP_SecTickCount_ST3> of PortPrototype <ReceiveTickCount>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_FvM_ReceiveTickCountTimeout_state(uint8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_ReceiveTickCountTimeout_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_ReceiveTickCountTimeout(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_ReceiveTickCountTimeout
 *********************************************************************************************************************/

  /* #10 Forward timeout event to FvM. */
  (void)Rte_Write_FvM_ReceiveTickCountTimeout_state(TIMEOUT_EVENT_DUMMY_STATE);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_BcTp_ReceiveVIN
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <VSS_TP_VIN_ST3> of PortPrototype <ReceiveVIN>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ReceiveVIN_VSS_TP_VIN_ST3(uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data8ByteType
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Coding_ReceiveVIN_VIN(const uint8 *data)
 *     Argument data: uint8* is of type Coding_VINDataType
 *   Std_ReturnType Rte_Write_SecLog_MacVerificationSecureBroadcastEvent_verificationStatus(const SecOC_VerificationStatusType *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FvM_FreshnessManagement_GetRxFreshness(uint16 freshnessValueId, const uint8 *truncatedFreshnessValue, uint32 truncatedFreshnessValueLength, uint16 authVerifyAttempts, uint8 *freshnessValue, uint32 *freshnessValueLength)
 *     Argument truncatedFreshnessValue: uint8* is of type freshnessValueType
 *     Argument freshnessValue: uint8* is of type freshnessValueType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FvM_FreshnessManagement_E_BUSY, RTE_E_FvM_FreshnessManagement_E_NOT_OK, RTE_E_FvM_FreshnessManagement_E_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MacVerify_VIN_MacVerify(const uint8 *dataBuffer, uint32 dataLength, const uint8 *macBuffer, uint32 macLength, Crypto_VerifyResultType *verifyBuffer)
 *     Argument dataBuffer: uint8* is of type Csm_DataType_MacAesCmacVin
 *     Argument macBuffer: uint8* is of type Csm_MacVerifyCompareType_MacVerifyAesCmac
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmMacVerify_MacVerifyAesCmacVin_CSM_E_BUSY, RTE_E_CsmMacVerify_MacVerifyAesCmacVin_CSM_E_KEY_EMPTY, RTE_E_CsmMacVerify_MacVerifyAesCmacVin_CSM_E_KEY_NOT_VALID, RTE_E_CsmMacVerify_MacVerifyAesCmacVin_CSM_E_KEY_SIZE_MISMATCH, RTE_E_CsmMacVerify_MacVerifyAesCmacVin_CSM_E_SMALL_BUFFER, RTE_E_CsmMacVerify_MacVerifyAesCmacVin_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_ReceiveVIN_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_ReceiveVIN(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_ReceiveVIN
 *********************************************************************************************************************/
  uint8 buffer[8];
  /* #20 Read the broadcast frame data from the receive buffer. */
  if (Rte_Read_ReceiveVIN_VSS_TP_VIN_ST3(buffer) == E_OK)
  {
    /* #30 Process the received data. */
    if (BcTp_Receive(BCTP_VIN_ID, buffer) == E_OK)
    {
      /* #40 If the message is complete and valid, forward it to regular receiver. */
      (void)Rte_Write_Coding_ReceiveVIN_VIN(&BcTp_MsgInfo[BCTP_VIN_ID].msgData[BCTP_DATASTART_POS]);
    }
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_BcTp_ReceiveVINTimeout
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceiveErrorEvent for DataElementPrototype <VSS_TP_VIN_ST3> of PortPrototype <ReceiveVIN>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Coding_ReceiveVINTimeout_state(uint8 data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_ReceiveVINTimeout_doc
 *********************************************************************************************************************/
 /*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_ReceiveVINTimeout(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_ReceiveVINTimeout
 *********************************************************************************************************************/
 /* #10 Forward timeout event to Coding. */
  (void)Rte_Write_Coding_ReceiveVINTimeout_state(TIMEOUT_EVENT_DUMMY_STATE);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
#endif

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_BcTp_SendDiagnosticAuthentication
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <authentication> of PortPrototype <RightsM_SendAuthenticationBroadcast>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_RightsM_SendAuthenticationBroadcast_authentication(uint8 *data)
 *     Argument data: uint8* is of type RightsM_AuthenticationBroadcastType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FvM_FreshnessManagement_GetTxFreshness(uint16 freshnessValueId, uint8 *freshnessValue, uint32 *freshnessValueLength)
 *     Argument freshnessValue: uint8* is of type freshnessValueType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FvM_FreshnessManagement_E_BUSY, RTE_E_FvM_FreshnessManagement_E_NOT_OK, RTE_E_FvM_FreshnessManagement_E_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MacGen_Authentication_MacGenerate(const uint8 *dataBuffer, uint32 dataLength, uint8 *macBuffer, uint32 *macLength)
 *     Argument dataBuffer: uint8* is of type Csm_DataType_MacAesCmacAuth
 *     Argument macBuffer: uint8* is of type Csm_MacGenerateResultType_MacGenAesCmacTrunc
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmMacGenerate_MacGenAesCmacTruncAuth_CSM_E_BUSY, RTE_E_CsmMacGenerate_MacGenAesCmacTruncAuth_CSM_E_KEY_EMPTY, RTE_E_CsmMacGenerate_MacGenAesCmacTruncAuth_CSM_E_KEY_NOT_VALID, RTE_E_CsmMacGenerate_MacGenAesCmacTruncAuth_CSM_E_KEY_SIZE_MISMATCH, RTE_E_CsmMacGenerate_MacGenAesCmacTruncAuth_CSM_E_SMALL_BUFFER, RTE_E_CsmMacGenerate_MacGenAesCmacTruncAuth_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_SendDiagnosticAuthentication_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_SendDiagnosticAuthentication(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_SendDiagnosticAuthentication
 *********************************************************************************************************************/
  /* #10 Check that the message broadcast buffer is free. */
  if (BcTp_MsgState[BCTP_DIAGNOSTICAUTHENTICATION_ID].state == BCTP_CHANNELSTATE_FREE)
  {
    /* #20 Transfer the broadcast message from the receive buffer to the message broadcast buffer. */
    if (Rte_Read_RightsM_SendAuthenticationBroadcast_authentication(&BcTp_MsgInfo[BCTP_DIAGNOSTICAUTHENTICATION_ID].msgData[BCTP_DATASTART_POS]) == E_OK)
    {
      /* #30 Start the transmission of the broadcast message. */
      BcTp_StartTransmission(BCTP_DIAGNOSTICAUTHENTICATION_ID);
    }
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_BcTp_SendRealTimeOffset
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <realTimeOffset> of PortPrototype <TimeM_SendRealTimeOffset>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_TimeM_SendRealTimeOffset_realTimeOffset(uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data12ByteType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FvM_FreshnessManagement_GetTxFreshness(uint16 freshnessValueId, uint8 *freshnessValue, uint32 *freshnessValueLength)
 *     Argument freshnessValue: uint8* is of type freshnessValueType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FvM_FreshnessManagement_E_BUSY, RTE_E_FvM_FreshnessManagement_E_NOT_OK, RTE_E_FvM_FreshnessManagement_E_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MacGen_RealTime_MacGenerate(const uint8 *dataBuffer, uint32 dataLength, uint8 *macBuffer, uint32 *macLength)
 *     Argument dataBuffer: uint8* is of type Csm_DataType_MacAesCmacRealTimeOffset
 *     Argument macBuffer: uint8* is of type Csm_MacGenerateResultType_MacGenAesCmacTrunc
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmMacGenerate_MacGenAesCmacTruncRealTimeOffset_CSM_E_BUSY, RTE_E_CsmMacGenerate_MacGenAesCmacTruncRealTimeOffset_CSM_E_KEY_EMPTY, RTE_E_CsmMacGenerate_MacGenAesCmacTruncRealTimeOffset_CSM_E_KEY_NOT_VALID, RTE_E_CsmMacGenerate_MacGenAesCmacTruncRealTimeOffset_CSM_E_KEY_SIZE_MISMATCH, RTE_E_CsmMacGenerate_MacGenAesCmacTruncRealTimeOffset_CSM_E_SMALL_BUFFER, RTE_E_CsmMacGenerate_MacGenAesCmacTruncRealTimeOffset_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_SendRealTimeOffset_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_SendRealTimeOffset(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_SendRealTimeOffset
 *********************************************************************************************************************/
  /* #10 Check that the message broadcast buffer is free. */
  if (BcTp_MsgState[BCTP_REALTIMEOFFSETTX_ID].state == BCTP_CHANNELSTATE_FREE)
  {
    /* #20 Transfer the broadcast message from the receive buffer to the message broadcast buffer. */
    if (Rte_Read_TimeM_SendRealTimeOffset_realTimeOffset(&BcTp_MsgInfo[BCTP_REALTIMEOFFSETTX_ID].msgData[BCTP_DATASTART_POS]) == E_OK)
    {
      /* #30 Start the transmission of the broadcast message. */
      BcTp_StartTransmission(BCTP_REALTIMEOFFSETTX_ID);
    }
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_BcTp_SendSharedSecret
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <sharedSecret> of PortPrototype <KeyM_SendSharedSecret>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_KeyM_SendSharedSecret_sharedSecret(uint8 *data)
 *     Argument data: uint8* is of type KeyM_SharedSecretType
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_SendSharedSecret_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_SendSharedSecret(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_SendSharedSecret
 *********************************************************************************************************************/
  /* #10 Check that the message broadcast buffer is free. */
  if (BcTp_MsgState[BCTP_SHAREDSECRET_ID].state == BCTP_CHANNELSTATE_FREE)
  {
    /* #20 Transfer the broadcast message from the receive buffer to the message broadcast buffer. */
    if (Rte_Read_KeyM_SendSharedSecret_sharedSecret(&BcTp_MsgInfo[BCTP_SHAREDSECRET_ID].msgData[BCTP_DATASTART_POS]) == E_OK)
    {
      /* #30 Start the transmission of the broadcast message. */
      BcTp_StartTransmission(BCTP_SHAREDSECRET_ID);
    }
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_BcTp_SendTickCount
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <tickCount> of PortPrototype <FvM_SendTickCount>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_FvM_SendTickCount_tickCount(uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data6ByteType
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MacGen_TickCount_MacGenerate(const uint8 *dataBuffer, uint32 dataLength, uint8 *macBuffer, uint32 *macLength)
 *     Argument dataBuffer: uint8* is of type Csm_DataType_MacAesCmacTickCount
 *     Argument macBuffer: uint8* is of type Csm_MacGenerateResultType_MacGenAesCmacTrunc
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmMacGenerate_MacGenAesCmacTruncTickCount_CSM_E_BUSY, RTE_E_CsmMacGenerate_MacGenAesCmacTruncTickCount_CSM_E_KEY_EMPTY, RTE_E_CsmMacGenerate_MacGenAesCmacTruncTickCount_CSM_E_KEY_NOT_VALID, RTE_E_CsmMacGenerate_MacGenAesCmacTruncTickCount_CSM_E_KEY_SIZE_MISMATCH, RTE_E_CsmMacGenerate_MacGenAesCmacTruncTickCount_CSM_E_SMALL_BUFFER, RTE_E_CsmMacGenerate_MacGenAesCmacTruncTickCount_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_SendTickCount_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_SendTickCount(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_SendTickCount
 *********************************************************************************************************************/
  /* #10 Check that the message broadcast buffer is free. */
  if (BcTp_MsgState[BCTP_TICKCOUNTTX_ID].state == BCTP_CHANNELSTATE_FREE)
  {
    /* #20 Transfer the broadcast message from the receive buffer to the message broadcast buffer. */
    if (Rte_Read_FvM_SendTickCount_tickCount(&BcTp_MsgInfo[BCTP_TICKCOUNTTX_ID].msgData[BCTP_DATASTART_POS]) == E_OK)
    {
      /* #30 Start the transmission of the broadcast message. */
      BcTp_StartTransmission(BCTP_TICKCOUNTTX_ID);
    }
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_BcTp_SendVIN
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <VIN> of PortPrototype <Coding_SendVIN>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Coding_SendVIN_VIN(uint8 *data)
 *     Argument data: uint8* is of type Coding_VINDataType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_FvM_FreshnessManagement_GetTxFreshness(uint16 freshnessValueId, uint8 *freshnessValue, uint32 *freshnessValueLength)
 *     Argument freshnessValue: uint8* is of type freshnessValueType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_FvM_FreshnessManagement_E_BUSY, RTE_E_FvM_FreshnessManagement_E_NOT_OK, RTE_E_FvM_FreshnessManagement_E_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_MacGen_VIN_MacGenerate(const uint8 *dataBuffer, uint32 dataLength, uint8 *macBuffer, uint32 *macLength)
 *     Argument dataBuffer: uint8* is of type Csm_DataType_MacAesCmacVin
 *     Argument macBuffer: uint8* is of type Csm_MacGenerateResultType_MacGenAesCmacTrunc
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmMacGenerate_MacGenAesCmacTruncVin_CSM_E_BUSY, RTE_E_CsmMacGenerate_MacGenAesCmacTruncVin_CSM_E_KEY_EMPTY, RTE_E_CsmMacGenerate_MacGenAesCmacTruncVin_CSM_E_KEY_NOT_VALID, RTE_E_CsmMacGenerate_MacGenAesCmacTruncVin_CSM_E_KEY_SIZE_MISMATCH, RTE_E_CsmMacGenerate_MacGenAesCmacTruncVin_CSM_E_SMALL_BUFFER, RTE_E_CsmMacGenerate_MacGenAesCmacTruncVin_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_SendVIN_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_BcTp_CODE) Ssa_BcTp_SendVIN(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_BcTp_SendVIN
 *********************************************************************************************************************/
  /* #10 Check that the message broadcast buffer is free. */
  if (BcTp_MsgState[BCTP_VIN_ID].state == BCTP_CHANNELSTATE_FREE)
  {
    /* #20 Transfer the broadcast message from the receive buffer to the message broadcast buffer. */
    if (Rte_Read_Coding_SendVIN_VIN(&BcTp_MsgInfo[BCTP_VIN_ID].msgData[BCTP_DATASTART_POS]) == E_OK)
    {
      /* #30 Start the transmission of the broadcast message. */
      BcTp_StartTransmission(BCTP_VIN_ID);
    }
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

#define Ssa_BcTp_STOP_SEC_CODE
#include "Ssa_BcTp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#define Ssa_BcTp_START_SEC_CODE
#include "Ssa_BcTp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  BcTp_Copy()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_BCTP_LOCAL_INLINE FUNC(void, Ssa_BcTp_CODE) BcTp_Copy(P2VAR(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR) dest, P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA) source, uint8 length)
{
  uint8_least i;
  /* #10 Copy the requested number of bytes byte-by-byte from the source buffer to the destination buffer. */
  for (i = 0u; i < length; i++) /* FETA_SSA_BCTP_MONOTONIC_FOR_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
  {
    dest[i] = source[i]; /* VCA_SSA_BCTP_WRITE_WITH_LENGTH_REQUIREMENT */
  }
}

#if ((SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))

/**********************************************************************************************************************
 *  BcTp_StartTransmission()
 **********************************************************************************************************************/
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
SSA_BCTP_LOCAL FUNC(void, Ssa_BcTp_CODE) BcTp_StartTransmission(uint8 msgId)
{
  /* #10 Check if a MAC needs to be appended to the message data. Otherwise the length of data to be transmitted is
   * given by the configured message length. */
# if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
  if (BcTp_MsgInfo[msgId].macLength > 0u)
# endif
  {
    uint32 resultLength;
# if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
    P2VAR(uint8, AUTOMATIC, Ssa_BcTp_VAR_NOINIT) buffer = &BcTp_MsgInfo[msgId].msgData[BCTP_DATASTART_POS];

    /* #20 If a freshness value needs to be appended (only for messages sent by ECU type VSM) get a freshness value
     * from timer manager. */
    if (BcTp_MsgInfo[msgId].freshnessLength > 0u)
    {
      resultLength = (uint32)BCTP_FRESHNESSVALUE_LENGTH << 3u;
      (void)Rte_Call_FvM_FreshnessManagement_GetTxFreshness(BCTP_FRESHNESSVALUE_ID, &buffer[BcTp_MsgInfo[msgId].dataLength], &resultLength);
    }
# endif

    resultLength = BcTp_MsgInfo[msgId].macLength;
# if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
    if (BcTp_MsgInfo[msgId].freshnessLength > 0u)
    {
      BcTp_MsgState[msgId].length = BCTP_DATA_ID_LENGTH + BCTP_FRESHNESSVALUE_LENGTH + BcTp_MsgInfo[msgId].dataLength;
    }
    else
# endif
    {
      BcTp_MsgState[msgId].length = BCTP_DATA_ID_LENGTH + BcTp_MsgInfo[msgId].dataLength;
    }

    /* #30 Calculate the MAC over the data id, the message data and the freshness value. */
    (void)BcTp_MsgInfo[msgId].macGenFct(BcTp_MsgInfo[msgId].msgData, BcTp_MsgState[msgId].length, &BcTp_MsgInfo[msgId].msgData[BcTp_MsgState[msgId].length], &resultLength);

    /* #40 The length of the data to be transmitted is the sum of the configured message length, freshness length
     * and the MAC length. */
    BcTp_MsgState[msgId].length = BcTp_MsgInfo[msgId].dataLength + BcTp_MsgInfo[msgId].freshnessLength + BcTp_MsgInfo[msgId].macLength;
    /* #50 Truncate the freshness for transmission. */
# if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
    if (BcTp_MsgInfo[msgId].freshnessLength > 0u)
    {
      /* Truncate Freshness by copying all data to the left */
      BcTp_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR))&buffer[BcTp_MsgInfo[msgId].dataLength], (P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA))&buffer[(BcTp_MsgInfo[msgId].dataLength + BCTP_FRESHNESSVALUE_LENGTH) - BcTp_MsgInfo[msgId].freshnessLength], (BcTp_MsgInfo[msgId].macLength+BcTp_MsgInfo[msgId].freshnessLength));
    }
# endif
  }
# if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
  else
  {
    BcTp_MsgState[msgId].length = BcTp_MsgInfo[msgId].dataLength;
  }
# endif

# if (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY)
  /* Assert that for GW ECUs, the message state is set to BCTP_CHANNELSTATE_COPYDATA only for messages
   * where the send function is not a null pointer. */
  /*@ assert msgId >= 5 && msgId <= 6; */
# endif

  /* #60 Reset the frame number, the retries counter and set the message's channel state to "copy data". */
  BcTp_MsgState[msgId].frame = 0u;
  BcTp_MsgState[msgId].retries_time = 0u;
  BcTp_MsgState[msgId].state = BCTP_CHANNELSTATE_COPYDATA;
}

/**********************************************************************************************************************
 *  BcTp_Send()
 **********************************************************************************************************************/
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
SSA_BCTP_LOCAL_INLINE FUNC(void, Ssa_BcTp_CODE) BcTp_Send(uint8 msgId)
{
  uint8 lengthLocal;
  uint8 buffer[8];

  /* #10 Get the number of bytes to be sent in the next frame (not more than 7 bytes). */
  if (BcTp_MsgState[msgId].length > BCTP_MAX_BYTES_IN_CF)
  {
    lengthLocal = BCTP_MAX_BYTES_IN_CF;
  }
  else
  {
    lengthLocal = BcTp_MsgState[msgId].length;
  }

  /* #20 Copy the data to be sent into the sent buffer at byte index 1. */
  BcTp_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR))&buffer[1], /* VCA_SSA_BCTP_FCT_CALL_COPY_DATA_INTO_TX_BUFFER */
    (P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA))&BcTp_MsgInfo[msgId].msgData[(BCTP_DATASTART_POS + BcTp_MsgInfo[msgId].dataLength + BcTp_MsgInfo[msgId].macLength + BcTp_MsgInfo[msgId].freshnessLength) - BcTp_MsgState[msgId].length],
    lengthLocal);

  /* #30 Set the frame number at byte index 0. */
  buffer[0] = BcTp_MsgState[msgId].frame;
  /* #40 Now increment frame counter for next frame. */
  BcTp_MsgState[msgId].frame += 1u;
  /* #50 Calculate the number of remaining bytes to be sent. */
  /* Length can be casted to uint8 because value is not greater than 7 */
  BcTp_MsgState[msgId].length -= lengthLocal;

# if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
  /*@ assert BcTp_MsgInfo[msgId].sendFct != NULL_PTR; */
# endif
# if (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY)
  /*@ assert (msgId == 5) || (msgId == 6); */ /* VCA_SSA_BCTP_SEND_FUNCTION */
  /*@ assert BcTp_MsgInfo[5].sendFct != NULL_PTR; */
  /*@ assert BcTp_MsgInfo[6].sendFct != NULL_PTR; */
# endif

  /* #60 Send the frame. */
  /* Discard return value. Transmission might fail only on one out of several channels (that are used for sending the frames). Thus, there is no re-sending.
   * The sendFct is not a null pointer according to VCA_SSA_BCTP_SEND_FUNCTION. */
  (void)BcTp_MsgInfo[msgId].sendFct(buffer);
  /* Assume data could be sent */
  BcTp_MsgState[msgId].retries_time = 0u;

  /* #70 Set new channel state depending on the remaining number of bytes to be sent. */
  if (BcTp_MsgState[msgId].length == 0u)
  {
    BcTp_MsgState[msgId].state = BCTP_CHANNELSTATE_FREE;
  }
  else
  {
    BcTp_MsgState[msgId].state = BCTP_CHANNELSTATE_WAIT;
  }
}
#endif

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *  BcTp_Receive()
 **********************************************************************************************************************/
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
 */
SSA_BCTP_LOCAL FUNC(Std_ReturnType, Ssa_BcTp_CODE) BcTp_Receive(uint8 msgId, P2CONST(uint8, AUTOMATIC, AUTOMATIC) data)
{
  Std_ReturnType retVal = E_NOT_OK;

  /* Assert that only 5 message kinds are handled by this function
   * and that the data to be serialized into a message is 8 bytes long. */
  /*@ assert msgId <= 5; */
  /*@ assert $lengthOf(data) >= 8; */

  /* #10 If the frame number of the received frame is 0, (re-)start the processing of the considered
   * broadcast message. */
  if (data[0] == 0u)
  {
    /* Start of frame received */
    BcTp_MsgState[msgId].length = 0u;
    BcTp_MsgState[msgId].frame = 1u;
  }

  /* #20 Else, the frame number is not 0 but the expected number: increment the frame counter the increase the
   * received length. */
  else if (data[0] == BcTp_MsgState[msgId].frame)
  {
    /* Consecutive frame */
    BcTp_MsgState[msgId].frame += 1u;
  }
  /* #30 Else, i.e., neither of the previous cases, it is a sequence error. Skip further processing */
  else
  {
    /* Frame order does not fit, skip processing by simulating a complete reception of message. */
    BcTp_MsgState[msgId].length = (uint8)BcTp_GetLengthOfMsg(msgId);
  }

  /* #40 Check that not all message data were received yet for the considered broadcast message. */
  if (BcTp_MsgState[msgId].length < BcTp_GetLengthOfMsg(msgId))
  {
    uint8 remainingBytes = (uint8)(BcTp_GetLengthOfMsg(msgId) - BcTp_MsgState[msgId].length);
    P2VAR(uint8, AUTOMATIC, Ssa_BcTp_VAR_NOINIT) buffer = &BcTp_MsgInfo[msgId].msgData[BCTP_DATASTART_POS];

    if (remainingBytes > BCTP_MAX_BYTES_IN_CF)
    {
      remainingBytes = BCTP_MAX_BYTES_IN_CF;
    }
    /* #50 Append the payload data of the received frame to the already received data in the receive buffer. */

    /*@ assert $lengthOf(buffer) >= BcTp_GetLengthOfMsg(msgId); */
    BcTp_Copy((P2VAR(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_VAR))&buffer[BcTp_MsgState[msgId].length], (P2CONST(uint8, AUTOMATIC, RTE_SSA_BCTP_APPL_DATA))&data[1], remainingBytes); /* VCA_SSA_BCTP_SERIALIZE_MESSAGE_IN_BUFFER */
    BcTp_MsgState[msgId].length += remainingBytes;

    /* #60 If the message is complete, verify the MAC of the message and return a positive response only when the
     * verification succeeded. Else, not complete, return "pending". */
    if (BcTp_MsgState[msgId].length == BcTp_GetLengthOfMsg(msgId))
    {
      /* Message completed. */
      if (BcTp_MsgInfo[msgId].macLength > 0u)
      {
        retVal = BcTp_Verify(msgId, buffer);
      }
      else
      {
        /* Message does not have a mac, verification not necessary */
        retVal = E_OK;
      }
    }
    else
    {
      retVal = BCTP_E_PENDING;
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  BcTp_Verify()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
SSA_BCTP_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_BcTp_CODE) BcTp_Verify(uint8 msgId, P2VAR(uint8, AUTOMATIC, Ssa_BcTp_VAR_NOINIT) buffer)
{
  /* Start Verification */
  uint8 truncFreshness = buffer[BcTp_MsgInfo[msgId].dataLength];
  Crypto_VerifyResultType result = CRYPTO_E_VER_NOT_OK;
  SecOC_VerificationStatusType verifStatus;
  /* E_OK will be returned if verification succeeds */
  Std_ReturnType retVal = E_OK;
  uint32 lengthLocal;

  /* #10 First check that the message is expected to have a freshness value. */
  if (BcTp_MsgInfo[msgId].freshnessLength > 0u)
  {
    /* #20 Move truncated MAC to the right to insert freshness. */
    /* Data must be copied reverse so do not use the Copy function. */
    for (lengthLocal = (uint32)(BcTp_MsgInfo[msgId].dataLength) + (uint32)(BcTp_MsgInfo[msgId].macLength) - 1u; lengthLocal >= (uint32)(BcTp_MsgInfo[msgId].dataLength); lengthLocal--) /* FETA_SSA_BCTP_MONOTONIC_FOR_LOOP_DOWN_WITH_UNCHANGED_LOWER_BOUND */
    {
      buffer[BCTP_FRESHNESSVALUE_LENGTH + lengthLocal] = buffer[BcTp_MsgInfo[msgId].freshnessLength + lengthLocal];
    }

    lengthLocal = ((uint32)BCTP_FRESHNESSVALUE_LENGTH) << 3u;
    /* #25 Get for the received truncated freshness value a freshness value from the timer manager. */
    if (Rte_Call_FvM_FreshnessManagement_GetRxFreshness(BCTP_FRESHNESSVALUE_ID, &truncFreshness, (uint32)(BCTP_TRUNC_FRESHNESS_LENGTH) << 3u, 0u, &buffer[BcTp_MsgInfo[msgId].dataLength], &lengthLocal) != RTE_E_OK)
    {
      retVal = E_NOT_OK;
    }
    else
    {
      lengthLocal = BCTP_FRESHNESSVALUE_LENGTH;
    }
  }
  else
  {
    lengthLocal = 0u;
  }

  /* #30 Verify the received MAC after inserting the freshness value. */
  if (retVal == E_OK)
  {
    lengthLocal = BCTP_DATA_ID_LENGTH + (uint32)(BcTp_MsgInfo[msgId].dataLength) + lengthLocal;
    if (BcTp_MsgInfo[msgId].macVerifyFct(BcTp_MsgInfo[msgId].msgData, lengthLocal, &BcTp_MsgInfo[msgId].msgData[lengthLocal], ((uint32)BcTp_MsgInfo[msgId].macLength) << 3u, &result) != E_OK)
    {
      retVal = E_NOT_OK;
    }
# if (SSA_IGNORE_SECURE_BROADCAST_VERIFICATION_RESULT == STD_OFF)  /* COV_SSA_DEBUG TX */
    else if (result != CRYPTO_E_VER_OK)
    {
      retVal = E_NOT_OK;
    }
    else
    {
      /* #35 Return success only if verification passed. */
      /* retVal is already E_OK */
    }
# endif
  }

  /* Write the security log event "Failed SecOC MAC verification" in both successful and failed verification with the
   * appropriate verification status. */
  verifStatus.secOCDataId = BcTp_MsgInfo[msgId].dataId;
  if (retVal == E_OK)
  {
    verifStatus.verificationStatus = SECOC_VERIFICATIONSUCCESS;
    (void)Rte_Write_SecLog_MacVerificationSecureBroadcastEvent_verificationStatus(&verifStatus);
  }
  else
  {
    verifStatus.verificationStatus = SECOC_VERIFICATIONFAILURE;
    (void)Rte_Write_SecLog_MacVerificationSecureBroadcastEvent_verificationStatus(&verifStatus);
  }

  return retVal;
}

#endif

#define Ssa_BcTp_STOP_SEC_CODE
#include "Ssa_BcTp_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/***********************************************************************************************************************
 *  SILENTBSW JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

  \ID  VCA_SSA_BCTP_WRITE_WITH_LENGTH_REQUIREMENT
    \DESCRIPTION      According to VCA, write access to buffer[idx] may be out of bounds.
    \COUNTERMEASURE   \R The function has a requirement that ensures that $lengthOf(buffer) >= len.
                         idx is limited by a for loop to a value < len.
                         The write access is thus in bounds.

  \ID VCA_SSA_BCTP_SERIALIZE_MESSAGE_IN_BUFFER
    \DESCRIPTION According to VCA, the following function call within BcTp_Receive() is possibly outside its specification:
                 BcTp_Copy(&buffer[BcTp_MsgState[msgId].length], &data[1], remainingBytes),
                 where
                 - buffer references a static variable &BcTp_MsgInfo[msgId].msgData[BCTP_DATASTART_POS],
                 - data is a buffer of eight bytes passed by the caller and
                 - the value of remaining bytes is computed at runtime and bound from above by BCTP_MAX_BYTES_IN_CF (7).
    \COUNTERMEASURE \N We need to show that
                         BcTp_MsgState[msgId].length + remainingBytes <= $lengthOf(buffer)
                    in order for the copy operation to be silent.
                    - It is asserted that BcTp_GetLengthOfMsg(msgId) <= $lengthOf(buffer).
                    - A runtime check ensures that BcTp_MsgState[msgId].length < BcTp_GetLengthOfMsg(msgId).
                    - Thus, no underflow occurs, when
                        remainingBytes = (uint8)(BcTp_GetLengthOfMsg(msgId) - BcTp_MsgState[msgId].length)
                      is computed.
                    - Due to the additional bound BCTP_MAX_BYTES_IN_CF from above, it holds that
                        remainingBytes <= (uint8)(BcTp_GetLengthOfMsg(msgId) - BcTp_MsgState[msgId].length).
                    - This implies that
                           BcTp_MsgState[msgId].length + remainingBytes
                        <= BcTp_MsgState[msgId].length + BcTp_GetLengthOfMsg(msgId) - BcTp_MsgState[msgId].length
                         = BcTp_GetLengthOfMsg(msgId)
                        <= $lengthOf(buffer)
                      and thus the provided buffer length is sufficient for the copy operation.

   \ID VCA_SSA_BCTP_FCT_CALL_COPY_DATA_INTO_TX_BUFFER
    \DESCRIPTION    According to VCA, the following function call within BcTp_Send() is possibly outside its specification:
                      BcTp_Copy(&buffer[1],
                                &BcTp_MsgInfo[msgId].msgData[(BCTP_DATASTART_POS + BcTp_MsgInfo[msgId].dataLength + BcTp_MsgInfo[msgId].macLength + BcTp_MsgInfo[msgId].freshnessLength) - BcTp_MsgState[msgId].length],
                                lengthLocal),
                    where buffer and lengthLocal are local variables.
    \COUNTERMEASURE \R The function checks before calling BcTp_Copy() that the number of bytes given by lengthLocal does not exceed the size of the passed
                    destination buffer given by &buffer[1]. The total length of buffer is 8 bytes, the maximal length passed to BcTp_Copy() is 7.
                    Thus, the specification of BcTp_Copy() is fulfilled.

   \ID VCA_SSA_BCTP_SEND_FUNCTION
    \DESCRIPTION    According to VCA, a null pointer might be dereferenced when calling
                    (void)BcTp_MsgInfo[msgId].sendFct(buffer);
                    within BcTp_Send(msgId).
    \COUNTERMEASURE \N The calling function BcTp_Send() is only active for VSM or gateway ECUs.
                    For each message type msgId, the send function to be used is stored in the struct array
                    BcTp_MsgInfo[msgId] in BcTp_MsgInfo[msgId].sendFct.
                    - For VSM ECUs, the send function is never a null pointer. This is asserted
                      before calling the send function within BcTp_Send.
                    - For gateway ECUs, the send function is not a null pointer for messages
                      of type "tickcount send" and "realtime send".
                      This is asserted before calling the send function within BcTp_Send.
                    - Only for these message types, the function BcTp_Send is called for gateway ECUs.
                    This is ensured by the following mechanism and state machine and verified by review:
                    - A message can either be in state
                      - BCTP_CHANNELSTATE_FREE,
                      - BCTP_CHANNELSTATE_START,
                      - BCTP_CHANNELSTATE_WAIT or
                      - BCTP_CHANNELSTATE_COPYDATA.
                    - In function Ssa_BcTp_Init, all message states are set to BCTP_CHANNELSTATE_FREE.
                      This is ensured by review.
                    - The messages are sent cyclically. Therefore, the Ssa_BcTp_MainFunction iterates
                      over all messages and calls BcTp_Send() for those with state BCTP_CHANNELSTATE_COPYDATA.
                      This is ensured by a runtime check.
                    - A message can reach state BCTP_CHANNELSTATE_COPYDATA in two ways:
                      - The state BCTP_CHANNELSTATE_COPYDATA is set in function BcTp_StartTransmission(msgId).
                        On a gateway ECU, the only messages for which BcTp_StartTransmission(msgId) is called,
                        are messages of type "tickcount send" and "realtime send". This is asserted within
                        function BcTp_StartTransmission(msgId).
                        As stated above, the send functions of these messages for gateway ECUs are not null pointers.
                      - The state BCTP_CHANNELSTATE_COPYDATA is set in Ssa_BcTp_MainFunction() itself. This is done
                        for messages in state BCTP_CHANNELSTATE_WAIT whose retry timer has reached the timing threshold.
                        This is ensured by runtime checks.
                        - A message state is set to BCTP_CHANNELSTATE_WAIT only in function BcTp_Send(msgId).
                          This is ensured by review.
                          As explained before, (for a gateway ECU) this function is only called for messages
                          whose send function is not a null pointer.

VCA_JUSTIFICATION_END */

/***********************************************************************************************************************
 *  FETA JUSTIFICATIONS
 **********************************************************************************************************************/

/* FETA_JUSTIFICATION_BEGIN
  \ID FETA_SSA_BCTP_MONOTONIC_FOR_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND
    \DESCRIPTION  According to FETA loop may not terminate
                  in function
                  - BcTp_Copy()
    \COUNTERMEASURE \N The here applied for loop uses a variable as upper bound that remains unchanged during loop execution.
                       The loop's type of the counter variable is appropriate for the loop's type of upper bound variable and is incremented once
                       within each single loop (strictly monotonically increasing).

  \ID FETA_SSA_BCTP_MONOTONIC_FOR_LOOP_DOWN_WITH_UNCHANGED_LOWER_BOUND
    \DESCRIPTION  According to FETA loop may not terminate
                  in function
                  - BcTp_Verify()
    \COUNTERMEASURE \N The here applied for loop uses a variable as lower bound that remains unchanged during loop execution.
                       The loop's type of the counter variable is appropriate for the loop's type of lower bound variable and is decremented once
                       within each single loop (strictly monotonically decreasing).
FETA_JUSTIFICATION_END */

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
/*!        \file  Ssa_RightsM.c
 *        \brief  Rights Manager of the Standard Security Architecture (Ssa).
 *
 *      \details  The Rights Manager provides interfaces to check for authentication before executing Diagnostic
 *                services.
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
 * CertP_PkiRoleType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * CertP_VerificationResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Coding_MemoryStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Coding_ModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Crypto_OperationModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Crypto_VerifyResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Csm_KeyDataType_Ssa_SignatureRamKey
 *   Used as Buffer for service.
 *
 * Csm_RandomGenerateResultType_Random
 *   Used as Buffer for service.
 *
 * Csm_ResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_ConfirmationStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_DiagnosticSessionControlType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_NegativeResponseCodeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_OpStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dem_EventStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * NvM_RequestResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * RightsM_ACL_BitMaskType
 *   uint32 represents integers with a minimum value of 0 and a maximum value
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 12234567, 104400.
 *
 * RightsM_AuthenticationModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * RightsM_AuthenticationStateType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * RightsM_DiagnosticUserRoleType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Ssa_KeyElementType
 *   uint32 represents integers with a minimum value of 0 and a maximum value
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 12234567, 104400.
 *
 * Ssa_OnOff_StateType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Ssa_OperationModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Ssa_PostProductionStatusType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * TimeM_CompareOperatorType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * TimeM_RealTimeChangeReasonType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * c24_km_0_999999k9_0k1_Invld_SNA
 *   uint32 represents integers with a minimum value of 0 and a maximum value
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 12234567, 104400.
 *
 *
 * Component Types:
 * ================
 * Ssa_RightsM
 *   Handles a received diagnostic authentication broadcast and enters authenticated state if valid.
 *
 *      Called by Ssa_BcTp whenever a Diagnostic Authentication broadcast message is received.
 *
 *
 * Port Prototypes:
 * ================
 * CallbackNotification_RandomGenerateNonce
 *   Callback notification from the CSM random generate job.
 *      Configuration Variant(s): Asynchronous job processing.
 *
 * CallbackNotification_SigVerify_SecurityAccess
 *   Callback notification from the CSM signature verification job used for the security access.
 *      Configuration Variant(s): Asynchronous job processing.
 *
 * CallbackNotification_SignatureVerify
 *   Callback notification from the CSM signature verification job used for verifying the proof of ownership during diagnostic tester authentication.
 *      Configuration Variant(s): Asynchronous job processing.
 *
 * CsmRandomGenerate
 *   Generates a random number.
 *      Connect to a Csm Random job.
 *
 * DTC_0x9A6857
 *   Set a Event Status to failed if a new AccessControlList does not match to the ECU's Diagnostic Variant and Diagnostic Version.
 *      Connect to corresponding event of Dem.
 *
 * DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer
 *   Reads issuer of current diagnostic authentication certificate and pass it to given data parameter.
 *      Connect to corresponding Dcm port.
 *
 * DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number
 *   Reads serial number of current diagnostic authentication certificate and pass it to given data parameter.
 *      Connect to corresponding Dcm port.
 *
 * DcmDiagnosticSessionControl
 *   Receives the current diagnostic session of dcm.
 *      Connect to corresponding Dcm port.
 *
 * Key_SignatureRamKey
 *   Sets the public key of a certificate to verify data signed by this certificate.
 *      Connect to a Csm Key which is able to store a public key and is used in job of port CsmSignatureVerify.
 *
 * NvMService_RightsM_AclVersion
 *   Controlling the NvM block which stores the version of the ECU individual ACL.
 *      Connect to NvM block storing the version of the ECU individual ACL.
 *
 * NvMService_RightsM_Nonce
 *   Controlling the NvM block which stores the nonce generated and used during synchronizing the secured system date and time or during distribution of the car-specific secert at the garage or dealerships.
 *      Connect to NvM block storing this nonce.
 *
 * NvMService_RightsM_PostProductionStatus
 *   Controlling the NvM block which stores the post production status.
 *      Connect to NvM block storing the post production status.
 *
 * RightsM_ReceiveAuthenticationBroadcast
 *   Configuration Variant(s): Not in VSM.
 *
 * RightsM_SendAuthenticationBroadcast
 *   Configuration Variant(s): VSM only.
 *
 * RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester
 *   Authenticate a diagnostic user or tester against the ECU to obtain the appropriate access rights (authorization).
 *
 * RoutineServices_Routine_Enhance_Access_Rights
 *   Request further access rights beyond the ones which are granted by the authentication of the diagnostic test tool.
 *
 * RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time
 *   Initiate time synchronization by requesting a one-time challenge (nonce).
 *
 * RoutineServices_Status_of_Post_Production_Flag
 *   Controls and returns the Post Production Status.
 *      Connect to corresponding Dcm port.
 *
 * ServiceRequestNotification
 *   Checks the access rights of the incoming diagnostic request for the currently authenticated user role. If not granted, request will be aborted!
 *      Connect to corresponding Dcm port.
 *
 * Ssa_BusOdometer
 *   This port receives the mileage value.
 *
 *
 * Data Element Prototypes:
 * ========================
 * currentLevel of Port Interface RightsM_SecurityLevelChange
 *   Current security level. Default is 0.
 *
 * DI_Odo_Pr5_ST3 of Port Interface Ssa_BusOdometer
 *   This is a sender receiver interface for communication of the bus odometer value.
 *
 *
 * Operation Prototypes:
 * =====================
 * RandomGenerate of Port Interface CsmRandomGenerate_Random
 *   This interface shall be used to start the random generate service of the CSM module.
 *
 * KeyElementSet of Port Interface CsmKeyManagement_Ssa_SignatureRamKey
 *   Sets the given key element bytes to the key.
 *
 * KeySetValid of Port Interface CsmKeyManagement_Ssa_SignatureRamKey
 *   Sets the given key element bytes to the key.
 *
 * GetDiagAuthCertSerialNumber_SecurityAccess of Port Interface Ssa_RightsM_Certificate
 *   Read the Diagnostic Authentication Certificate Serial Number belonging to the diagnostic channel the last successful security access was executed on.
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
 * Ssa_RightsM_Com_ReceiveBroadcastAuthentication
 *   Called by Com when Broadcast message from VSM is received.
 *      Configuration Variant(s): Not in VSM.
 *
 * Ssa_RightsM_CsmCallbackNotification_RandomGenerate
 *   Configuration Variant(s): Asynchronous job processing.
 *
 * Ssa_RightsM_CsmCallbackNotification_SigVerify_SecurityAccess
 *   Configuration Variant(s): Asynchronous job processing.
 *
 * Ssa_RightsM_CsmCallbackNotification_SignatureVerify
 *   Configuration Variant(s): Asynchronous job processing.
 *
 *********************************************************************************************************************/

#include "Rte_Ssa_RightsM.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Ssa_Cfg.h"
#include "Ssa_RightsM_Basic.h"
#include "Ssa_Utils.h"

#ifdef __VCA__  /* COV_SSA_VECTOR_CODE_ANALYZER_STUB_REDIRECTION */
# include "Ssa_RightsM_Redirection.vcaspecs.h"
#endif

/* After this comment only memory mapping files may be included. Due to this turn off lint rule requesting a standard
   include guard. */
/*lint -e451 */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SSA_RIGHTSM_LOCAL)                /* COV_SSA_LOCAL */
# define SSA_RIGHTSM_LOCAL                                                  static
#endif

#if !defined (SSA_RIGHTSM_LOCAL_INLINE)         /* COV_SSA_LOCAL_INLINE */
# define SSA_RIGHTSM_LOCAL_INLINE                                           LOCAL_INLINE
#endif

/* Mem operations */
#if !defined (Ssa_MemCpy)                   /* COV_SSA_MEMCPY */
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
# define Ssa_MemCpy(destination, source, num)                               Ssa_Utils_MemCpy(destination, source, num)
#endif
#define RightsM_CopyDataBuffer(destination, source, num)                    Ssa_Utils_MemCpy(destination, source, num) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define RightsM_CompareData(Data1, Data2, DataSize)                         Ssa_Utils_MemCmp((Data1), (Data2), (DataSize)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define RightsM_ClearDataBuffer(Data, DataSize)                             Ssa_Utils_MemClr((Data), (DataSize)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define RightsM_SetDataBuffer(Value, Data, DataSize)                        Ssa_Utils_MemSet((Data), (Value), (DataSize)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Negatives response codes to DCM */
#define RIGHTSM_DCM_NRC_CHALLENGE_CALCULATION_FAILED                        0x59u

/* Values for the verification results of the routine Authenticate Diagnostic User or Tester. */
#define RIGHTSM_RES_CERTIFICATE_VERIFIED_OWNERSHIP_VERIFICATION_NECESSARY   0x00u
#define RIGHTSM_RES_OWNERSHIP_VERIFIED                                      0x01u
#define RIGHTSM_RES_DEAUTHENTICATION_SUCCESSFUL                             0x02u
#define RIGHTSM_RES_OWNERSHIP_VERIFIED_CENTRAL_AUTH_BROADCAST_TRIGGERED     0x03u
#define RIGHTSM_RES_OWNERSHIP_VERIFICATION_FAILED                           0x20u
#define RIGHTSM_RES_DEAUTHENTICATION_FAILED                                 0x30u

/* Values for the negative response code of diagnostic services.
 * Values are different from DCM and only used internally to mask out different error states by logical AND.
 * Due to this, values are sorted and mask according their priority starting with E_OK = 0:
 */
#define RIGHTSM_E_ACL_AUTHENTICATIONREQUIRED                                0x10u
#define RIGHTSM_E_ACL_IDNOTSUPPORTED                                        0x11u
#define RIGHTSM_E_ACL_SUBFUNCTIONNOTSUPPORTED                               0x13u
#define RIGHTSM_E_ACL_SERVICENOTSUPPORTED                                   0x17u

/*!
 * The validity period of a generated nonce in 10ms ticks  (24h = 24 * 60 * 60 * 100).
 */
#define RIGHTSM_NONCE_VALID_TIME                                            0x83D600u

/* The size of one entry in the enhanced access control list. */
#define RIGHTSM_ENHANCED_ACCESS_ENTRY_SIZE                                  6u
/* The number of entries in the enhanced access control list. */
#if (SSA_RIGHTSM_ENHANCED_ACCESS_RIGHTS_TABLE_SIZE >= RIGHTSM_ENHANCED_ACCESS_ENTRY_SIZE)     /* COV_MSR_CONFIG TX */
/* Calculate number of entries. Rounding down by integer division. */
# define RIGHTSM_ENHANCED_ACCESS_RIGHTS_TABLE_NUM_ENTRIES                   ((uint16)(SSA_RIGHTSM_ENHANCED_ACCESS_RIGHTS_TABLE_SIZE / RIGHTSM_ENHANCED_ACCESS_ENTRY_SIZE))
#else
# error "Size of enhanced access control list too small for enhancing at least one service!"
#endif

/* Dummy PKI role */
#define RIGHTSM_DUMMY_PKI_ROLE                                              (0u)

/* ASN.1 DER encoding tags. */
#define RIGHTSM_ASN1_TAG_OCTET_STRING                                       (0x04u)

/* Local identifiers for diagnostic services that shall trigger an security log event. */
#define RIGHTSM_SECLOG_BY_INDICATION_NONE                                   (0u)
#define RIGHTSM_SECLOG_BY_INDICATION_ACT_DBG_IF_RID_0x0265                  (1u)
#define RIGHTSM_SECLOG_BY_INDICATION_ERASE_MEM_RID_0xFF00                   (2u)
#define RIGHTSM_SECLOG_BY_INDICATION_CLEAR_SAR_MEM_RID_0x0242               (3u)
#define RIGHTSM_SECLOG_BY_INDICATION_ENABLE_SAR_MEM_OVERWRITE_DID_0x0137    (4u)
#define RIGHTSM_SECLOG_BY_INDICATION_SECURITY_ACCESS_SEND_KEY               (5u)

/* Size of the access control list version information stored in NVM. */
#define RIGHTSM_SIZE_OF_STORED_ACL_VERSION                                  (11u)

/*! States for asynchronous handling in routines Authenticate_Diagnostic_User_or_Tester and Enhance_Access_Rights. */
#define CSM_ASYNC_IDLE                                                      (0x00u)
#define CSM_ASYNC_VERIFY_CERTIFICATE                                        (0x01u)
#define CSM_ASYNC_VERIFY_SIGNATURE                                          (0x02u)
#define CSM_ASYNC_IDLE_DESTROY_NONCE                                        (0x03u)
#define CSM_ASYNC_GENERATE_RANDOM_DESTROY_NONCE                             (0x04u)
#define CSM_ASYNC_GENERATE_RANDOM                                           (0x05u)
#define CSM_ASYNC_GENERATE_SIGNATURE                                        (0x06u)

/*! States for asynchronous handling in RightsM_Nonce_Get. */
#define RIGHTSM_ASYNC_STATE_IDLE                                            (0u)
#define RIGHTSM_ASYNC_STATE_RAND_GEN                                        (1u)
#define RIGHTSM_ASYNC_STATE_NVM_WRITE                                       (2u)
#define RIGHTSM_ASYNC_STATE_NVM_WAIT                                        (3u)

/* Bit mask to blind out the suppressPositiveResponse bit when evaluating the byte containing the sub-function. */
#define RIGHTSM_SF_MASK                                                     (0x7Fu)

/* Options calling RightsM_IsEnhancedAccessRightGranted */
#define RIGHTSM_CHECK_SID_ONLY                                              (1u)
#define RIGHTSM_CHECK_ALL                                                   (4u)

/*! RightsM NVM Write states. */
#define RIGHTSM_NVM_WRITE_STATE_IDLE                                        (0u)
#define RIGHTSM_NVM_WRITE_STATE_START                                       (1u)
#define RIGHTSM_NVM_WRITE_STATE_PENDING                                     (2u)

/*! Extended Session Identifier */
#define SSA_RIGHTSM_DIAG_SESSION_ID_EXTENDED                                (0x03u)

#define SSA_RIGHTSM_E_DCM_REJECTED_SECURITYACCESS                           (0xFFu)

#ifndef DCM_E_AUTHENTICATIONREQUIRED   /* COV_SSA_OVERWRITEABLE TX */
# define DCM_E_AUTHENTICATIONREQUIRED                                       (52U)
#endif

/*!
 * The system descriptions defines the odometer signal based on
 * DataConstraint/CompuMethod c24_km_0_999999k9_0k1_Invld_SNA:
 * InvalidValue_c24_km_0_999999k9_0k1_Invld_SNA (16777215U)
 * c24_km_0_999999k9_0k1_Invld_SNA_LowerLimit (0U)
 * c24_km_0_999999k9_0k1_Invld_SNA_UpperLimit (16777215U)
 * I_C24_KM_0_999999K9_0K1_INVLD_SNA_INVLD (16777214U)
 * I_C24_KM_0_999999K9_0K1_INVLD_SNA_SNA (16777215U)
 * 
 * Define as upper limit for the received odometer value the lowest invalid value.
 */
#ifndef SSA_RIGHTSM_MAX_MILEAGE_THRESHOLD   /* COV_SSA_OVERWRITEABLE TX */
# define SSA_RIGHTSM_MAX_MILEAGE_THRESHOLD                                  (16777214U)
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
/* Build an uin16 value from two bytes. */
#define RightsM_GetUint16(hiByte, loByte)                                   ((uint16)((((uint16)(hiByte)) << 8u) | ((uint16)(loByte))))                                 /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Check if a diagnostic channel id is valid. */
#define RightsM_IsDiagChanValid(diagChanId)                                 ((diagChanId) < SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS)                                     /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Get the diagnostic channel id from the source address. */
#define RightsM_GetDiagChanIdFromSourceAddress(sourceAddress)               (Ssa_GetRightsM_TesterToChannel((sourceAddress)&0x000Fu))                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Check if bidirectional authentication is configured. */
#define RightsM_IsUnidirectionalAuthentication(Configuration)               (((Configuration) & 0x7Fu) == SSA_AUTHENTICATE_UNIDIRECTIONAL_AUTHETICATION_CONFIGURATION)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define RightsM_IsS29SubProcessing(Configuration)                           (((Configuration) & SSA_AUTHENTICATE_S29_SUB_PROCESSING_ACTIVE_CONFIGURATION) != 0x00u)     /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Get byte value from two BCDs. */
#define RightsM_GetByteValFromBcd(StrBuffer, StartIdx)                      ((uint8)((((StrBuffer)[(StartIdx)] - 0x30u) * 10u) + ((StrBuffer)[(StartIdx)+1u] - 0x30u))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/* Calculate parameter of subfunction of diagnostic request and decrement it. */
#define RightsM_DecrementSubfunctionParameter(x)                            (uint8)(((((x) + 1u) / 2u) * 2u) - (uint8)1u)                                                 /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/* Macros used for access to variables that are either static or on stack. */
#if (SSA_KEEP_BUFFER_VARIABLES_STATIC == STD_ON)
# define RightsM_GetNonceStored()                                            (RightsM_Workspace.nonceStored)
# define RightsM_GetParsedCert()                                             (RightsM_Workspace.parsedTesterOrEnhAccessCert)
#else
# define RightsM_GetNonceStored()                                            (nonceStored)
# define RightsM_GetParsedCert()                                             (parsedCert)
#endif
#define RightsM_GetAsyncState ()                                             (RightsM_Workspace.procState)
#define RightsM_SetAsyncState (state)                                        RightsM_Workspace.procState = (state)

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
/* The following compile time assertions ensure the sizes of data types used within the RightsM submodule
 * when calling RTE APIs expecting these data types.
 * The assertions ensure that the size of these data types is consistent with respective buffer lengths defined in the Ssa.
 * For ASIL-D, the vector code analyzer checks the same conditions within the RightsM_Init() function. */
 /* PRQA S 3205, 3493 4 */ /* MD_SSA_COMPILE_TIME_ASSERTION */
 Ssa_CompileTimeAssert(sizeof(Csm_RandomGenerateResultType_Random) == 32u, InvalidSizeOf_Csm_RandomGenerateResultType_Random); /*lint !e506 */
 Ssa_CompileTimeAssert(sizeof(Ssa_Data2ByteType) == 2u, InvalidSizeOf_Ssa_Data2ByteType); /*lint !e506 */
 Ssa_CompileTimeAssert(sizeof(Ssa_Data30ByteType) == 30u, InvalidSizeOf_Ssa_Data30ByteType); /*lint !e506 */
 Ssa_CompileTimeAssert(sizeof(RightsM_AuthenticationBroadcastType) == 20u, InvalidSizeOf_RightsM_AuthenticationBroadcastType); /*lint !e506 */

/*! RightsM asynchronous workspace structure. */
typedef struct
{
  uint16 DataLength;
  uint16 idxBufferIn;
  uint8 procState;
  uint8 verifResult;
  boolean timeSetAfterValidNonce;
#if (SSA_KEEP_BUFFER_VARIABLES_STATIC == STD_ON)
  RightsM_AuthNonceType nonceStored;
  CertP_ParsedCertStructureType parsedTesterOrEnhAccessCert;
#endif
} RightsM_WorkspaceType;

/**********************************************************************************************************************
 *  LOCAL DATA DEFINITIONS
 *********************************************************************************************************************/
#define Ssa_RightsM_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Ssa_RightsM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! The current diagnostic channel identifier. */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT)  RightsM_CurrentDiagChanId;
/*! The current diagnostic channel identifier related to the execution of a diagniostic service. */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT)  RightsM_CurrentDiagChanId_Service;
/*! The identifier of the diagnostic channel requesting for extended session. */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT)  RightsM_ExtSessionDiagChanId_Requested;
/*! The identifier of the diagnostic channel used for last successful security access. */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT)  RightsM_ChannelIdOfLastSuccessfulSecurityAccess;
/*! The identifier of the diagnostic channel being in extended session. */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT)  RightsM_ExtSessionDiagChanId;
/*! The current diagnostic channel identifier. */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT)  RightsM_CurrentDiagnosticChannel;
/*! Identifier for service to be logged. */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT)  RightsM_ServiceToFilterFor;
/*! Data for service to be logged. */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT)  RightsM_ServiceToFilterForData;

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
/*! The identifier of the diagnostic channel which was the last to send a broadcast message . */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT)  RightsM_DiagChanLastSentId;
/*! Counter variable used for the authentication broadcast timer. */
SSA_RIGHTSM_LOCAL VAR(uint16, Ssa_RightsM_VAR_NOINIT) RightsM_AuthenticationBroadcastTimer;
#endif

/*!
 * Diagnostic channel data (containing the security settings after successful authentication.
 */
SSA_RIGHTSM_LOCAL VAR(RightsM_DiagChannelDataType, Ssa_RightsM_VAR_NOINIT) RightsM_DiagChannelData[SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS];
/*! Preliminary security settings. */
SSA_RIGHTSM_LOCAL VAR(RightsM_SecuritySettingsType, Ssa_RightsM_VAR_NOINIT) RightsM_PreliminarySecuritySettings[SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS];
/*!
 * Enhanced access control list. One entry is of size 6 byte:  0: Size; 1: DiagChanId; 2-5: Data for service identification.
 */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT) RightsM_EnhancedAccessRights[RIGHTSM_ENHANCED_ACCESS_RIGHTS_TABLE_NUM_ENTRIES][RIGHTSM_ENHANCED_ACCESS_ENTRY_SIZE];
/*! Target subject key identifier temporarily stored in the RightsM. */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT) RightsM_TargetSubjectKeyIdentifier[SSA_SIZEOF_CERT_SUBJECT_KEY_ID];
/*! Flag indicating if there is a valid target subject key identifier temporarily stored in the RightsM. */
SSA_RIGHTSM_LOCAL VAR(boolean, Ssa_RightsM_VAR_NOINIT) RightsM_TargetSubjectKeyIdentifierValid;
/*! Pointer to the basic access control list. */
SSA_RIGHTSM_LOCAL P2CONST(uint8, AUTOMATIC, Ssa_RightsM_CONST) RightsM_BasicAcl;
/*! Pointer to the ECU individual access control list. */
SSA_RIGHTSM_LOCAL P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_CONST) RightsM_EcuIndividualAcl;

/*! Workspace for handling asynchronous CSM calls. */
SSA_RIGHTSM_LOCAL VAR(RightsM_WorkspaceType, Ssa_RightsM_VAR_NOINIT) RightsM_Workspace;

/*! Variable for asynchronous state handling in function RightsM_CsmSignatureVerify(). */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT) RightsM_CsmSignatureVerifyAsyncState;
/*! Storage for the CSM verification result used for asynchronous CAM call. */
SSA_RIGHTSM_LOCAL VAR(Crypto_VerifyResultType, Ssa_RightsM_VAR_NOINIT) RightsM_CsmVerificationResult;
#if (SSA_SECURITYACCESSLEVEL == STD_ON)
/*! Variable for asynchronous state handling in service routine Ssa_RightsM_SecurityAccess_CompareKey. */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT) RightsM_CompareKeyAsyncState;
#endif
/* Storages. */
#if (SSA_SECURITYACCESSLEVEL == STD_ON)
SSA_RIGHTSM_LOCAL VAR(Crypto_VerifyResultType, Ssa_RightsM_VAR_NOINIT) RightsM_CompareKeyVerifResult; /* PRQA S 3218 */ /* MD_SSA_OBJECT_AT_FILE_SCOPE */
SSA_RIGHTSM_LOCAL VAR(Ssa_SizeOfSecurityAccessLevelType, Ssa_RightsM_VAR_NOINIT) RightsM_SecLevelIndex;

/*! The seed state for security access. */
SSA_RIGHTSM_LOCAL VAR(boolean, Ssa_RightsM_VAR_NOINIT) RightsM_SecAccessIsSeeded[SSA_RIGHTSM_NUMBER_SECURITY_ACCESS_LEVELS];
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT) RightsM_SecAccess_StaticSeedArray[SSA_RIGHTSM_NUMBER_SECURITY_ACCESS_LEVELS][SSA_SIZEOF_NONCE];
#endif

/*! Global flag to indicate if an error has been logged by the Ssa */
SSA_RIGHTSM_LOCAL VAR(boolean, Ssa_RightsM_VAR_NOINIT) RightsM_IsErrorLoggedBySsa;

/*! State variable for asynchronous CSM handling in KeyM_CsmRandomGenerate. */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT) RightsM_RandomGenerateAsyncState;
/* Storages. */
SSA_RIGHTSM_LOCAL VAR(uint32, Ssa_RightsM_VAR_NOINIT) RightsM_RandomGenerateResultLength; /* PRQA S 3218 */ /* MD_SSA_OBJECT_AT_FILE_SCOPE */

/*! State variable for asynchronous handling in RightsM_Nonce_Get. */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT) RightsM_Nonce_Get_State;
/*! State variable for asynchronous handling in Ssa_RightsM_Nonce_Destroy. */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT) RightsM_Nonce_Destroy_State;
/* Storage for the current tick-count used for validating/generating a nonce. */
SSA_RIGHTSM_LOCAL VAR(uint64, Ssa_RightsM_VAR_NOINIT) RightsM_CurrentTickCount;

/*! State variable for writing the central authentication status for user role production. */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT) RightsM_WritePostProductionStatus_State;

/*! Storing the write request for the ACL version NvRam block. */
SSA_RIGHTSM_LOCAL VAR(boolean, Ssa_RightsM_VAR_NOINIT) RightsM_AclVersionNvmWriteRequested;
/*! The state of writing the ACl version NVRam block. */
SSA_RIGHTSM_LOCAL VAR(uint8, Ssa_RightsM_VAR_NOINIT) RightsM_AclVersionNvmWriteState;

#define Ssa_RightsM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Ssa_RightsM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define Ssa_RightsM_START_SEC_CODE
#include "Ssa_RightsM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  RightsM_AdoptPreliminarySecuritySettings()
 **********************************************************************************************************************/
/*!
 * \brief       Adopt the temporary security settings to the diagnostic channel data.
 * \details     -
 * \param[in]   diagnosticChannel  The identifier of the diagnostic channel whose security settings shall be adopted.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_AdoptPreliminarySecuritySettings(uint8 diagnosticChannel);

/**********************************************************************************************************************
 *  RightsM_ClearPreliminarySecuritySettings()
 **********************************************************************************************************************/
/*!
 * \brief       Resets the temporary security settings.
 * \details     -
 * \param[in]   diagnosticChannel  The identifier of the diagnostic channel whose security settings shall be clear.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL FUNC(void, Ssa_RightsM_CODE) RightsM_ClearPreliminarySecuritySettings(uint8 diagnosticChannel);

#if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)
/**********************************************************************************************************************
 *  RightsM_UpdateLocalAsyncState()
 **********************************************************************************************************************/
/*!
 * \brief           Updates the value of the asynchronous state (of a CSM job).
 * \details         The state is updated dependent on the callback's result only if a callback is awaited.
 * \param[in,out]   asyncState  (in)  The current value of state of asynchronous operation
 *                              (out) The updated value of the state of the asynchronous operation.
 * \param[in]       result      The result of the asynchronous CSM operation.
 * \pre             All provided pointers must be valid.
 * \context         ANY
 * \reentrant       FALSE
 * \synchronous     TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_UpdateLocalAsyncState(
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) asyncState,
  Csm_ResultType result);
#endif

/**********************************************************************************************************************
 *  RightsM_CopyOrClear()
 **********************************************************************************************************************/
/*!
 * \brief           Generic function called from ReadData APIs.
 * \details         This function copies the data to be read to the provided output buffer, if the input buffer is
 *                  not NULL_PTR. If it is, the output buffer is cleared.
 *                  If only a single byte is to be copied, a ASCII-binary-coded 2-digit decimal from the src buffer is
 *                  copied to position to the dst buffer.
 * \param[out]      dst         The buffer to copy data to or to clear.
 * \param[in]       src         The pointer to the data to be read.
 *                              If a NULL_PTR is passed for this parameter, the output buffer will be cleared and
 *                              no data is copied.
 * \param[in]       srcOffset   The start index of the relevant data in the src buffer.
 * \param[in]       cnt         The size of the data to be copied/to be cleared.
 * \note            src may be NULL_PTR.
 * \pre             dst must be a valid pointer to a buffer that provides at least cnt many bytes.
 * \context         ANY
 * \reentrant       TRUE
 * \synchronous     TRUE
 * \spec            requires dst != NULL_PTR;
 *                  requires $lengthOf(dst) >= cnt;                                                             \endspec
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_CopyOrClear(
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) dst,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) src,
  uint16 srcOffset,
  uint16 cnt);

/**********************************************************************************************************************
 *  RightsM_GenericConditionCheckRead()
 **********************************************************************************************************************/
/*!
 * \brief           Generic function called from ConditionCheckRead APIs.
 * \details         This function updates the error code and sets the return value based on the error condition.
 * \param[in]       errorCondition   If this error condition is fulfilled, a negative error code and return value
 *                                   will be set.
 * \param[in]       rteErrorCode     The rteErrorCode which will be returned in case the error condition is fulfilled.
 * \param[in,out]   errorCode   (in)  Buffer to store the DCM error code.
 *                              (out) Buffer storing the DCM error code.
 * \pre             All provided pointers must be valid.
 * \context         ANY
 * \reentrant       TRUE
 * \synchronous     TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_GenericConditionCheckRead(
  boolean errorCondition,
  Std_ReturnType rteErrorCode,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) errorCode);

/**********************************************************************************************************************
 *  RightsM_DeAuthenticate()
 **********************************************************************************************************************/
/*!
 * \brief       De-authenticates the diagnostic user or tester identified by the given diagnostic channel.
 * \details     -
 * \param[in]   diagnosticChannel   The identifier of the diagnostic channel.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL FUNC(void, Ssa_RightsM_CODE) RightsM_DeAuthenticate(uint8 diagnosticChannel);

/**********************************************************************************************************************
 *  RightsM_DeAuthenticateGlobalMode()
 **********************************************************************************************************************/
/*!
 * \brief       Switches the global authentication mode to unauthenticated.
 * \details     This function switches the global authentication mode to unauthenticated when all diagnostic user
 *              are not authenticated.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL FUNC(void, Ssa_RightsM_CODE) RightsM_DeAuthenticateGlobalMode(void);

#if ( SSA_ECU_TYPE == SSA_ECU_TYPE_VSM )
/**********************************************************************************************************************
*  RightsM_CheckForActiveDiagnosticChannels()
**********************************************************************************************************************/
/*!
* \brief       Checks if any of the diagnostic channels is sending cyclical broadcasts.
* \details     -
* \return      TRUE    There is at least one channel sending cyclical broadcasts
*              FALSE   There is no channel sending cyclical broadcasts
* \pre         called within exclusive area
* \context     TASK
* \reentrant   FALSE
* \synchronous TRUE
*/
SSA_RIGHTSM_LOCAL FUNC(boolean, Ssa_RightsM_CODE) RightsM_CheckForActiveDiagnosticChannels(void);
#endif


/**********************************************************************************************************************
 *  RightsM_IsEnhancedAccessRightGranted()
 **********************************************************************************************************************/
/*!
 * \brief       Checks whether for the given diagnostic service enhanced access right has been granted.
 * \details     -
 * \param[in]   diagnosticChannel  The id of the diagnostic channel whose enhanced access rights shall be checked.
 * \param[in]   sid                The service identifier.
 * \param[in]   subFunc            The sub function of the service.
 * \param[in]   id                 The DID or RID if of the service.
 * \param[in]   sizeEntryToCheck   Only entries of the enhanced access control list with size smaller than or equal to
 *                                 sizeEntryToCheck are considered.
 * \return      TRUE               Enhance access right is granted.
 *              FALSE              Enhance access right is not granted.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(boolean, Ssa_RightsM_CODE) RightsM_IsEnhancedAccessRightGranted(
  uint8 diagnosticChannel,
  RightsM_AccessRights_SidType sid,
  RightsM_AccessRights_SubFuncType subFunc,
  RightsM_AccessRights_IdType id,
  uint8 sizeEntryToCheck);

/**********************************************************************************************************************
 *  RightsM_GetAccessRights()
 **********************************************************************************************************************/
/*!
 * \brief       Gets the access rights granted to the user roles for the given diagnostic service by the given access
 *              control list (ACL).
 * \details     This function searches for the given diagnostic service defined by the triplet SID, sub-function and ID
 *              through the given access control list. If the service is found it returns E_OK and the corresponding
 *              access rights granted to the user roles. If the service is not found RIGHTSM_E_ACL_SERVICENOTSUPPORTED
 *              is returned.
 * \param[in]   acl            Pointer to an access control list.
 * \param[in]   sid            The service identifier.
 * \param[in]   subFunc        The sub function of the service. 0xFF if there is no sub-function for the service.
 * \param[in]   id             The DID or RID if of the service.
 * \param[out]  accessRights   The access rights granted to the user roles by the given access control list.
 * \return      E_OK                                  Access rights found and returned by parameter accessRights.
 *              RIGHTSM_E_ACL_IDNOTSUPPORTED          No access right for the given ID in the given ACL.
 *              RIGHTSM_E_ACL_SUBFUNCTIONNOTSUPPORTED No access right for the given sub-function in the given ACL.
 *              RIGHTSM_E_ACL_SERVICENOTSUPPORTED     No access rights for the given service in the given ACL.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_GetAccessRights(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_CONST) acl,
  RightsM_AccessRights_SidType sid,
  RightsM_AccessRights_SubFuncType subFunc,
  RightsM_AccessRights_IdType id,
  P2VAR(RightsM_AccessRights_AccessRightsType, AUTOMATIC, AUTOMATIC) accessRights);

/**********************************************************************************************************************
 *  RightsM_IsAccessRightGranted()
 **********************************************************************************************************************/
/*!
 * \brief       Checks whether for the given diagnostic service access right is granted.
 * \details     This function checks whether for the given diagnostic service access right is granted.
 *              For that it checks the enhanced ACL, then the basic ACL and finally the ECU-individual ACL.
 * \param[in]   diagnosticChannel  The id of the diagnostic channel whose access rights shall be checked.
 * \param[in]   sid                The service identifier.
 * \param[in]   subFunc            The sub function of the service.
 * \param[in]   id                 The DID or RID if of the service.
 * \return      E_OK                                  Enhance access right is granted.
 *              RIGHTSM_E_ACL_IDNOTSUPPORTED          No access right for the given ID in the given ACL.
 *              RIGHTSM_E_ACL_SUBFUNCTIONNOTSUPPORTED No access right for the given sub-function in the given ACL.
 *              RIGHTSM_E_ACL_SERVICENOTSUPPORTED     No access rights for the given service in the given ACL.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_IsAccessRightGranted(
  uint8 diagnosticChannel,
  RightsM_AccessRights_SidType sid,
  RightsM_AccessRights_SubFuncType subFunc,
  RightsM_AccessRights_IdType id);

/**********************************************************************************************************************
 *  RightsM_AppendDynamicallyDefinedIdentifier()
 **********************************************************************************************************************/
/*!
 * \brief       Appends a dynamically defined ReadDataByIdentifier service for the given DDID as ID to the enhanced ACL.
 * \details     -
 * \param[in]   ddid   The dynamically defined data identifier whose ReadDataByIdentifier service shall be appended.
 * \return      E_OK     Successfully appended.
 *              E_NOT_OK Not appended. Enhanced ACL is already completely filled.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_AppendDynamicallyDefinedIdentifier(RightsM_AccessRights_IdType ddid);

/**********************************************************************************************************************
 *  RightsM_ClearDynamicallyDefinedIdentifier()
 **********************************************************************************************************************/
/*!
 * \brief       Clears a dynamically defined ReadDataByIdentifier service from the enhanced access control list.
 * \details     -
 * \param[in]   ddid   The dynamically defined data identifier whose ReadDataByIdentifier service shall be cleared.
 * \return      E_OK     Successfully cleared.
 *              E_NOT_OK Service not found.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_ClearDynamicallyDefinedIdentifier(RightsM_AccessRights_IdType ddid);

/**********************************************************************************************************************
 *  RightsM_AccessRights_IsHashValueValid()
 **********************************************************************************************************************/
/*!
 * \brief       Verifies the hash value of the given access control list.
 * \details     -
 * \param[in]   acl    Pointer to an access control list.
 * \return      TRUE   Hash verification passed.
 *              FALSE  Hash verification failed.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL FUNC(boolean, Ssa_RightsM_CODE) RightsM_AccessRights_IsHashValueValid(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_CONST) acl);

/**********************************************************************************************************************
 *  RightsM_AccessRights_DoDiagVariantAndVersionMatch()
 **********************************************************************************************************************/
/*!
 * \brief       Verifies that diagnostic variant and version match.
 * \details     This function verifies that the given diagnostic variant and version match to the diagnostic variant and
 *              version in the given access control list.
 * \param[in]   acl          Pointer to an access control list
 * \param[in]   diagVariant  The diagnostic variant that shall be checked.
 * \param[in]   diagVersion  The diagnostic version that shall be checked.
 * \return      TRUE         Diagnostic variant and version match.
 *              FALSE        Diagnostic variant and version do bot match.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        acl may be NULL_PTR
 */
SSA_RIGHTSM_LOCAL FUNC(boolean, Ssa_RightsM_CODE) RightsM_AccessRights_DoDiagVariantAndVersionMatch(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_CONST) acl,
  uint8 diagVariant,
  uint8 diagVersion);

/**********************************************************************************************************************
 *  RightsM_GetDiagChanAndAuthenticationState()
 **********************************************************************************************************************/
/*!
 * \brief       Gets the diagnostic channel and the authentication state.
 * \details     This function gets the diagnostic channel and the authentication state.
 * \return      Diagnostic channel and authentication data
 *              Bit 0..3: Diagnostic Channel
 *              Bit 4..6: Reserved
 *              Bit 7   : Diagnostic test tool authenticated on this channel: 0=false, 1=true
 *              Returning 0xFF if there is no valid current diagnostic channel.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL FUNC(uint8, Ssa_RightsM_CODE) RightsM_GetDiagChanAndAuthenticationState(void);

/**********************************************************************************************************************
 *  RightsM_FindEnhancedAccessRightsEntry()
 **********************************************************************************************************************/
/*!
 * \brief       Finds entry with same content in the enhanced access control list.
 * \details     This function searches through the enhanced access control list for an entry with a given content and clears it if requested.
 * \param[in]   entryToFind  Pointer to entry data to be found-
 * \param[in]   clearEntry   TRUE  Clear entry in enhanced access control list.
 *                           FALSE Do not clear entry in enhanced access control list.
 * \return      TRUE    Entry with same content found.
 *              FALSE   Entry with same content not found.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE if parameter clearEntry is FALSE.
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL FUNC(boolean, Ssa_RightsM_CODE) RightsM_FindEnhancedAccessRightsEntry(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) entryToFind,
  boolean clearEntry);

/**********************************************************************************************************************
 *  RightsM_Nonce_Get_RandomGenerate()
 **********************************************************************************************************************/
/*!
 * \brief       Provides a newly generated nonce, if there is no valid nonce.
 * \details     If a newly generated nonce is requested this function provides
 *              a newly generated nonce only if there is no stored, valid nonce.
 * \param[in]   generateNew TRUE:  A new nonce is generated if there is no valid, stored nonce.
 *                          FALSE: A new nonce is not generated.
 * \param[out]  nonce       Pointer to the data buffer where the nonce shall be copied to.
 * \return      E_OK          Request successful.
 *              E_NOT_OK      Request failed.
 *              SSA_E_PENDING Requested service is busy due to writing to NVM (only if a new nonce is requested).
 *              SSA_E_INVALID There is no valid nonce (only if no new nonce is requested).
 * \pre         All provided pointers must be valid. The buffer referenced by nonce must provide at least
 *              SSA_SIZEOF_NONCE many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */
SSA_RIGHTSM_LOCAL FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_Nonce_Get_RandomGenerate(
  boolean generateNew,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) nonce);

/**********************************************************************************************************************
 *  RightsM_Nonce_Get()
 **********************************************************************************************************************/
/*!
 * \brief       Provides either the stored or a newly generated nonce.
 * \details     This function provides the stored nonce if there is a valid one. If a newly generated nonce is
 *              requested this function provides a newly generated nonce only if there is no stored, valid nonce. A
 *              generated nonce becomes invalid 24 hours after it has been generated.
 * \param[in]   generateNew TRUE:  A new nonce is generated if there is no valid, stored nonce.
 *                          FALSE: A new nonce is not generated.
 * \param[out]  nonce       Pointer to the data buffer where the nonce shall be copied to.
 * \return      E_OK          Request successful.
 *              E_NOT_OK      Request failed.
 *              SSA_E_PENDING Requested service is busy due to writing to NVM (only if a new nonce is requested).
 *              SSA_E_INVALID There is no valid nonce (only if no new nonce is requested).
 * \pre         All provided pointers must be valid. The buffer referenced by nonce must provide at least
 *              SSA_SIZEOF_NONCE many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */
SSA_RIGHTSM_LOCAL FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_Nonce_Get(
  boolean generateNew,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) nonce);

/**********************************************************************************************************************
 *  RightsM_CsmRandomGenerate()
 **********************************************************************************************************************/
/*!
 * \brief       Generates random data.
 * \details     This function generates random data of the given length.
 * \param[in]   resultBufferLength The number of random data bytes to be generated.
 * \param[out]  resultBuffer       Pointer to the data buffer where the generated random data shall be copied to.
 * \return      E_OK          Request successful.
 *              E_NOT_OK      Request failed.
 *              SSA_E_PENDING Requested service is busy.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous FALSE
 */
SSA_RIGHTSM_LOCAL FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_CsmRandomGenerate(
  const uint16 resultBufferLength,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) resultBuffer);

/**********************************************************************************************************************
 *  RightsM_HandleTaskInitiateAuthentication_AfterCertVerification()
 **********************************************************************************************************************/
/*!
 * \brief       Post certificate verification handling during authentication task.
 * \details     This function is called during an authentication task to adjust local real-time and to extract
 *              data from the diagnostic certificate after certificate verification.
 * \param[in]   dataTesterCert                            Pointer to challenge tester and diagnostic authentication certificate or proof of ownership tester.
 * \param[in]   parsedTesterCert                          Pointer to the parsed enhanced rights certificate data.
 * \param[in]   nonceStored                               Pointer to stored nonce data structure.
 * \param[out]  Verification_Result                       Pointer to buffer where the verification result shall be written to.
 * \param[out]  ErrorCode                                 Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      E_OK        Request successful.
 *              E_NOT_OK    Request failed.
 * \pre         This function is only called after successful validation of diagnostic authentication certificate.
 *              All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE)  RightsM_HandleTaskInitiateAuthentication_AfterCertVerification(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) dataTesterCert,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedTesterCert,
  P2CONST(RightsM_AuthNonceType, AUTOMATIC, AUTOMATIC) nonceStored,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) Verification_Result,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode);

/**********************************************************************************************************************
 *  RightsM_HandleTaskAuthenticate_StateIdle()
 **********************************************************************************************************************/
/*!
 * \brief         Process IDLE state during authentication task.
 * \details       This function is called from
 *                RightsM_AuthDiagUserOrTester_HandleTaskAuthenticate to process the state IDLE.
 * \param[in,out] Nonce                                     Pointer to buffer where the nonce is stored.
 * \param[in,out] ParsedCert                                Pointer to buffer where the parsed certificate is stored.
 * \param[in]     Configuration                             Bit 0: Uni- or bidirectional Authentication:
 *                                                                 0=unidirectional, 1=bidirectional
 *                                                          Bit 7: Standard or S29 sub-processing:
 *                                                                 0=standard, 1=S29 special sub-processing
 *                                                              Depending on this switch either provides index of first
 *                                                              iteration's data or of the second iteration's data
 * \param[in]     Challenge_Certificate_Proof_of_Ownership  Pointer to challenge tester and diagnostic authentication
 *                                                          certificate or proof of ownership tester.
 * \param[in]     DataLength                                Pointer to buffer where the length of the input data can be read from.
 * \param[out]    ErrorCode                                 Pointer to buffer where the error code shall be written to.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \spec          requires $lengthOf(Challenge_Certificate_Proof_of_Ownership) >= sizeof(Dcm_Data4004ByteType); \endspec
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_HandleTaskAuthenticate_StateIdle(
  P2VAR(RightsM_AuthNonceType, AUTOMATIC, AUTOMATIC) Nonce,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) ParsedCert,
  uint8 Configuration,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Challenge_Certificate_Proof_of_Ownership,
  P2CONST(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode);

/**********************************************************************************************************************
 *  RightsM_HandleTaskAuthenticate_StateCertificateVerify()
 **********************************************************************************************************************/
/*!
 * \brief         Process CERTIFICATE VERIFY state during authentication task.
 * \details       This function is called from
 *                RightsM_AuthDiagUserOrTester_HandleTaskAuthenticate to process the state CERTIFICATE VERIFY.
 * \param[in]     Nonce                                     Pointer to buffer where the nonce is stored.
 * \param[in,out] ParsedCert                                Pointer to buffer where the parsed certificate is stored.
 * \param[in]     Challenge_Certificate_Proof_of_Ownership  Pointer to challenge tester and diagnostic authentication
 *                                                          certificate or proof of ownership tester.
 * \param[out]    ErrorCode                                 Pointer to buffer where the error code shall be written to.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \spec          requires $lengthOf(Challenge_Certificate_Proof_of_Ownership) >= sizeof(Dcm_Data4004ByteType); \endspec
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_HandleTaskAuthenticate_StateCertificateVerify(
  P2CONST(RightsM_AuthNonceType, AUTOMATIC, AUTOMATIC) Nonce,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) ParsedCert,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Challenge_Certificate_Proof_of_Ownership,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode);

/**********************************************************************************************************************
 *  RightsM_HandleTaskAuthenticate_HandleDeleteNonce()
 **********************************************************************************************************************/
/*!
 * \brief         Deletes the local nonce during authentication task.
 * \details       This function is called from
 *                RightsM_AuthDiagUserOrTester_HandleTaskAuthenticate to delete the local nonce and to
 *                update RightsM_Workspace.procState thereafter.
 * \param[in]     Nonce   Pointer to buffer where the nonce is stored.
 * \param[in,out] retVal  (in)  Return value from previously processed state.
 *                        (out) Return value resulting from deleting the nonce, if nonce needs to be deleted.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_HandleTaskAuthenticate_HandleDeleteNonce(
  P2CONST(RightsM_AuthNonceType, AUTOMATIC, AUTOMATIC) Nonce,
  P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) retVal);

/**********************************************************************************************************************
 *  RightsM_HandleTaskAuthenticate_StateGenerateRandom()
 **********************************************************************************************************************/
/*!
 * \brief         Process GENERATE RANDOM state during authentication task.
 * \details       This function is called from
 *                RightsM_AuthDiagUserOrTester_HandleTaskAuthenticate to process the state GENERATE_RANDOM.
 * \param[out]    Authentication_Result   Pointer to buffer where the output data shall be copied to.
 * \param[out]    DataLength              Number of bytes written to Authentication_Result.
 * \param[out]    ErrorCode               Pointer to buffer where the error code shall be written to.
 * \pre           All provided pointers must be valid.
 *                Authentication_Result must refer to a buffer that consists of >= 38 bytes.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \spec          requires $lengthOf(Authentication_Result) >= 38;                                                \endspec
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_HandleTaskAuthenticate_StateGenerateRandom(
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Authentication_Result,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode);

/**********************************************************************************************************************
 *  RightsM_AuthDiagUserOrTester_HandleTaskAuthenticate()
 **********************************************************************************************************************/
/*!
 * \brief         Handle authentication task.
 * \details       This function is called from
 *                Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start if the
 *                task to be handled is authentication.
 * \param[in]     Configuration                             Bit 0: Uni- or bidirectional Authentication:
 *                                                                 0=unidirectional, 1=bidirectional
 *                                                          Bit 7: Standard or S29 sub-processing:
 *                                                                 0=standard, 1=S29 special sub-processing
 *                                                              Depending on this switch either provides index of first
 *                                                              iteration's data or of the second iteration's data
 * \param[in]     Challenge_Certificate_Proof_of_Ownership  Pointer to challenge tester and diagnostic authentication
 *                                                          certificate or proof of ownership tester.
 * \param[out]    Authentication_Result                     Pointer to buffer where the output data shall be copied to.
 * \param[in,out] DataLength                                in:  Length of Challenge_Certificate_Proof_of_Ownership
 *                                                               in bytes.
 *                                                          out: Number of bytes written to Authentication_Result.
 * \param[out]    ErrorCode                                 Pointer to buffer where the error code shall be written to.
 * \pre           All provided pointers must be valid.
 *                Authentication_Result must refer to a buffer that consists of >= 38 bytes.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \spec          requires $lengthOf(Challenge_Certificate_Proof_of_Ownership) >= sizeof(Dcm_Data4004ByteType);
 *                requires $lengthOf(Authentication_Result) >= 38;                                              \endspec
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_AuthDiagUserOrTester_HandleTaskAuthenticate(
  uint8 Configuration,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Challenge_Certificate_Proof_of_Ownership,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Authentication_Result,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode);

/**********************************************************************************************************************
 *  RightsM_AuthDiagUserOrTester_HandleTaskProofOfOwnership()
 **********************************************************************************************************************/
/*!
 * \brief         Handle task proof of ownership.
 * \details       This function is called from
 *                Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start if the
 *                task to be handled is proof of ownership.
 * \param[in]     Configuration                             Bit 0: Uni- or bidirectional Authentication:
 *                                                                 0=unidirectional, 1=bidirectional
 *                                                          Bit 7: Standard or S29 sub-processing:
 *                                                                 0=standard, 1=S29 special sub-processing
 *                                                              Depending on this switch either provides index of first
 *                                                              iteration's data or of the second iteration's data
 * \param[in]     Challenge_Certificate_Proof_of_Ownership  Pointer to challenge tester and diagnostic authentication
 *                                                          certificate or proof of ownership tester.
 * \param[in]     OpStatus                                  Status of DCM operation.
 * \param[out]    Authentication_Result                     Pointer to buffer where the output data shall be copied to.
 * \param[in,out] DataLength                                in:  Length of Challenge_Certificate_Proof_of_Ownership
 *                                                               in bytes.
 *                                                          out: Number of bytes written to Authentication_Result.
 * \param[out]    ErrorCode                                 Pointer to buffer where the error code shall be written to.
 * \pre           All provided pointers must be valid.
 *                Authentication_Result must refer to a buffer that consists of >= 6 bytes.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \spec          requires  $lengthOf(Challenge_Certificate_Proof_of_Ownership) >= sizeof(Dcm_Data4004ByteType);
 *                requires  $lengthOf(Challenge_Certificate_Proof_of_Ownership) >= *DataLength;
 *                requires $lengthOf(Authentication_Result) >= 6;                                              \endspec
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_AuthDiagUserOrTester_HandleTaskProofOfOwnership(
  uint8 Configuration,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Challenge_Certificate_Proof_of_Ownership,
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Authentication_Result,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode);

/**********************************************************************************************************************
 *  RightsM_AuthDiagUserOrTester_HandleTaskDeauthenticate()
 **********************************************************************************************************************/
/*!
 * \brief         Handle de-authentication task.
 * \details       This function is called from
 *                Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start if the
 *                task to be handled is de-authentication.
 * \param[out]    Verification_Result     Pointer to buffer where the verification result shall be written to.
 * \param[out]    Authentication_Result   Pointer to buffer where the output data shall be copied to.
 * \param[out]    DataLength              Number of bytes written to Authentication_Result.
 * \pre           All provided pointers must be valid.
 *                Authentication_Result must refer to a buffer that consists of >= 6 bytes.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \spec          requires $lengthOf(Authentication_Result) >= 6;                                                 \endspec
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE)  RightsM_AuthDiagUserOrTester_HandleTaskDeauthenticate(
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) Verification_Result,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Authentication_Result,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength);

/**********************************************************************************************************************
 *  RightsM_HandleTaskPostProcessing()
 **********************************************************************************************************************/
/*!
 * \brief         Processes outcome of authentication task handling.
 * \details       This function is called from
 *                Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start after all
 *                tasks have been handled to process the return value, the verification result and the authentication
 *                result.
 * \param[in,out] RetVal                  Return value retrieved from all tasks handled before.
 * \param[in]     Task                    Task to be handled when
 *                                        Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start
 *                                        was called.
 * \param[in,out] RoutineInfo             Pointer to buffer where the routine information shall be written to.
 * \param[out]    Verification_Result     Pointer to buffer where the verification result shall be written to.
 * \param[out]    Authentication_Result   Pointer to buffer where the output data shall be copied to.
 * \param[out]    DataLength              Number of bytes written to Authentication_Result.
 * \param[in]     LocalErrorCode          Error code retrieved from all tasks handled before.
 * \param[out]    ErrorCode               Pointer to buffer where the final error code shall be written to.
 * \pre           All provided pointers must be valid.
 *                Authentication_Result must refer to a buffer that consists of >= 6 bytes.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \spec          requires $lengthOf(Authentication_Result) >= 6;                                                 \endspec
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_AuthDiagUserOrTester_HandleTaskPostProcessing(
  P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetVal,
  uint8 Task,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) RoutineInfo,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Verification_Result,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Authentication_Result,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength,
  Dcm_NegativeResponseCodeType LocalErrorCode,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode);

/**********************************************************************************************************************
 *  RightsM_ValidateAcl()
 **********************************************************************************************************************/
/*!
 * \brief         Validates the given access control list.
 * \details       This function validates the given access control list and deactivates the access control list if it
 *                is not accepted.
 * \param[in]     acl                      Pointer to the access control list that shall be validated.
 * \param[in]     checkVariantAndVersion   TRUE: Check the diagnostic variant and version.
 *                                         FALSE: Do not check the diagnostic variant and version.
 * \pre           -
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \note          acl may be NULL_PTR
 */
SSA_RIGHTSM_LOCAL FUNC(boolean, Ssa_RightsM_CODE) RightsM_ValidateAcl(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_CONST) acl,
  boolean checkVariantAndVersion);

/**********************************************************************************************************************
 *  RightsM_CheckAccessControlLists()
 **********************************************************************************************************************/
/*!
 * \brief       Checks all access control list.
 * \details     This function validates the basic and the ECU-individual access control lists.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_CheckAccessControlLists(void);

/**********************************************************************************************************************
 *  RightsM_GetAccessRights_BisectTable()
 **********************************************************************************************************************/
/*!
 * \brief         Searches a sub-table of the given access control list for the assigned access rights using bisection.
 * \details       -
 * \param[in,out] left            (in)  The current left index of the bisection search.
 *                                (out) The updated left index of the bisection search, if the sought index
 *                                      is not yet found.
 * \param[in,out] right           (in)  The current right index of the bisection search.
 *                                (out) The updated right index of the bisection search, if the sought index
 *                                      is not yet found.
 * \param[in]     middle          The current middle index of the bisection search.
 * \param[in]     idFoundInTable  The ID (access right) found in the subtable at the middle index.
 * \param[in]     soughtId        The sought ID (access right).
 * \return        TRUE            The soughtID is found in the subtable.
 *                FALSE           The soughtID is not found in the subtable.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(boolean, Ssa_RightsM_CODE) RightsM_GetAccessRights_BisectTable(
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) left,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) right,
  uint16 middle,
  uint16 idFoundInTable,
  uint16 soughtId);

/**********************************************************************************************************************
 *  RightsM_GetAccessRights_SidSubtable()
 **********************************************************************************************************************/
/*!
 * \brief         Searches the service ID sub-table of the given access control list for the assigned access rights.
 * \details       -
 * \param[in]     acl       Pointer to the access control list that shall be evaluated.
 * \param[in]     sid       The service ID to be searched.
 * \param[out]    startIdx  The start index for searching the sub-func in the sub-func sub-table.
 * \param[in,out] endIdx    The end index for searching the sub-func in the sub-func sub-table.
 * \param[out]    accessRights   The access rights for the given service if startIdx is different from 0xFFFF.
 * \return        E_OK
 *                RIGHTSM_E_ACL_SERVICENOTSUPPORTED The service is not supported, i.e. to be rejected.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \note          The function RightsM_GetAccessRights_SubfuncSubtable() is called afterwards.
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_GetAccessRights_SidSubtable(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_CONST) acl,
  RightsM_AccessRights_SidType sid,
  P2VAR(RightsM_AccessRights_IdxType, AUTOMATIC, AUTOMATIC) startIdx,
  P2VAR(RightsM_AccessRights_IdxType, AUTOMATIC, AUTOMATIC) endIdx,
  P2VAR(RightsM_AccessRights_AccessRightsType, AUTOMATIC, AUTOMATIC) accessRights);

/**********************************************************************************************************************
 *  RightsM_GetAccessRights_SubfuncSubtable()
 **********************************************************************************************************************/
/*!
 * \brief         Searches the service sub-func sub-table of the given access control list for the assigned access rights.
 * \details       -
 * \param[in]     acl       Pointer to the access control list that shall be evaluated.
 * \param[in]     subFunc   The sub-function to be searched.
 * \param[in,out] startIdx  The start index for searching the id in the id sub-table.
 * \param[in,out] endIdx    The end index for searching the id in the id sub-table.
 * \param[out]    accessRights  The access rights for the given service if startIdx is different from 0xFFFF.
 * \return        E_OK                              Request successful.
 *                RIGHTSM_E_ACL_SUBFUNCTIONNOTSUPPORTED The service sub function is not supported, i.e. to be rejected.
 * \pre           The function RightsM_GetAccessRights_SidSubtable() has been called.
 *                All provided pointers must be valid.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \note          The function RightsM_GetAccessRights_IdSubtable() is called afterwards.
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_GetAccessRights_SubfuncSubtable(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_CONST) acl,
  RightsM_AccessRights_SubFuncType subFunc,
  P2VAR(RightsM_AccessRights_IdxType, AUTOMATIC, AUTOMATIC) startIdx,
  P2VAR(RightsM_AccessRights_IdxType, AUTOMATIC, AUTOMATIC) endIdx,
  P2VAR(RightsM_AccessRights_AccessRightsType, AUTOMATIC, AUTOMATIC) accessRights);

/**********************************************************************************************************************
 *  RightsM_GetAccessRights_IdSubtable()
 **********************************************************************************************************************/
/*!
 * \brief         Searches the ID sub-table of the given access control list for the assigned access rights.
 * \details       -
 * \param[in]     acl          Pointer to the access control list that shall be evaluated.
 * \param[in]     id           The ID to be searched.
 * \param[in]     startIdx     The start index for searching the id in the id sub-table.
 * \param[in,out] endIdx       The end index for searching the id in the id sub-table.
 * \param[out]    accessRights The access rights for the given service.
 * \return        E_OK                              Request successful.
 *                RIGHTSM_E_ACL_IDNOTSUPPORTED The id of the service is not supported, i.e. to be rejected.
 * \pre           The function RightsM_GetAccessRights_SubfuncSubtable() has been called.
 *                All provided pointers must be valid.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_GetAccessRights_IdSubtable(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_CONST) acl,
  RightsM_AccessRights_IdType id,
  P2CONST(RightsM_AccessRights_IdxType, AUTOMATIC, AUTOMATIC) startIdx,
  P2VAR(RightsM_AccessRights_IdxType, AUTOMATIC, AUTOMATIC) endIdx,
  P2VAR(RightsM_AccessRights_AccessRightsType, AUTOMATIC, AUTOMATIC) accessRights);

/**********************************************************************************************************************
 *  RightsM_CheckEnhanceAccessCert()
 **********************************************************************************************************************/
/*!
 * \brief       Checks the enhanced rights certificate.
 * \details     This functions checks the enhanced rights certificate. Mainly it parses it, verifies it against the backend
 *              certificate and verifies the holder serial number.
 * \param[in]   Enhanced_Rights_Certificate  Pointer to the enhanced rights certificate including preceding length info.
 * \param[in]   DataLength                   Length of input data.
 * \param[out]  parsedEnhanceAccessCert      Pointer to the parsed enhanced rights certificate data.
 * \param[out]  errCode                      The negative response code if an error occurred.
 * \return      E_NOT_OK   Either a verification failure or any other error occurred.
 *              E_OK       Verification passed.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_CheckEnhanceAccessCert(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Enhanced_Rights_Certificate,
  uint16 DataLength,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedEnhanceAccessCert,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) errCode);

/**********************************************************************************************************************
 *  RightsM_VerifyEnhanceAccessCert()
 **********************************************************************************************************************/
/*!
 * \brief         Verifies the enhanced access certificate against the backend certificate.
 * \details       -
 * \param[in]     Enhanced_Rights_Certificate  Pointer to the enhanced rights certificate.
 *                                             Must reference a buffer of at least sizeof(Dcm_Data2002ByteType) many bytes.
 * \param[in,out] ParsedCert                   Pointer to buffer where the parsed certificate is stored.
 * \param[out]    ErrorCode                    The negative response code if an error occurred.
 * \return        E_OK                                                              Verification successful.
 *                RTE_E_RoutineServices_Routine_Enhance_Access_Rights_DCM_E_PENDING Verification pending.
 *                RTE_E_RoutineServices_Routine_Enhance_Access_Rights_E_NOT_OK      Verification failure.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \spec          $lengthOf(Enhanced_Rights_Certificate) >= sizeof(Dcm_Data2002ByteType);                      \endspec
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_VerifyEnhanceAccessCert(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Enhanced_Rights_Certificate,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) ParsedCert,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode);

/**********************************************************************************************************************
 *  RightsM_ExtractEnhancedAccessRights_UpdateAccessRightsTable()
 **********************************************************************************************************************/
/*!
 * \brief       Extracts the enhanced access right from an enhanced rights certificate.
 * \details     This function extracts one single enhance access right from an enhanced rights certificate and stores
 *              it in the enhance access control list.
 * \param[in]   byteIdxSrc               Byte index of the service element of the enhanced rights certificate.
 * \param[in]   sizeEntry                Size of the service element of the enhanced rights certificate.
 * \param[in]   certificateEnhanceAccess Pointer to the enhanced rights certificate.
 * \param[out]  verResult                The verification result. Positive response code.
 * \param[out]  errCode                  The negative response code if an error occurred.
 * \return      E_OK        Extraction succeeded.
 *              E_NOT_OK    Either a verification failure or any other error occurred.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_ExtractEnhancedAccessRights_UpdateAccessRightsTable(
  uint32 byteIdxSrc,
  uint8 sizeEntry,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) certificateEnhanceAccess,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) verResult,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) errCode);

/**********************************************************************************************************************
 *  RightsM_ExtractEnhancedAccessRights()
 **********************************************************************************************************************/
/*!
 * \brief       Extracts the enhanced access rights from an enhanced rights certificate.
 * \details     This function extracts the enhance access rights from an enhanced rights certificate, stores them in
 *              the enhance access control list and stores the target key identifier, if there is one.
 * \param[in]   certificateEnhanceAccess Pointer to the enhanced rights certificate
 * \param[in]   parsedEnhanceAccessCert  Pointer to the parsed enhanced rights certificate data.
 * \param[out]  verResult                The verification result. Positive response code.
 * \param[out]  errCode                  The negative response code if an error occurred.
 * \return      E_OK        Extraction succeeded.
 *              E_NOT_OK    Either a verification failure or any other error occurred.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_ExtractEnhancedAccessRights(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) certificateEnhanceAccess,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedEnhanceAccessCert,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) verResult,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) errCode);

/**********************************************************************************************************************
 *  RightsM_GetSubfunc()
 **********************************************************************************************************************/
/*!
 * \brief       Gets the sub-function of the requested diagnostic service.
 * \details     This function gets the sub-function of the requested diagnostic service.
 * \param[in]   SID          The service identifier.
 * \param[in]   RequestData  Pointer to the whole data of the current request.
 * \param[in]   DataSize     Length of RequestData in bytes.
 * \param[out]  subFunc      The sub-function of the requested diagnostic service. 0xFF if there is no sub-function.
 * \param[out]  idIdx        Index position in the RequestData where the id can be read.
 * \param[out]  ErrorCode    Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      E_OK         SubFunc could be determined successfully
 *              E_NOT_OK     Sub-function could not be determined, e.g. data was to short
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_GetSubfunc(
uint8 SID,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData,
  uint16 DataSize,
  P2VAR(RightsM_AccessRights_SubFuncType, AUTOMATIC, AUTOMATIC) subFunc,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) idIdx,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode);

/**********************************************************************************************************************
 *  RightsM_ChangeErrorCodeIfServiceNotSupported()
 **********************************************************************************************************************/
/*!
 * \brief       Checks if the SID is supported and changes the ErrorCode if necessary.
 * \details     This function checks if the given SID is listed in one of the ACLs. If not, it changes ErrorCode to
 *              DCM_E_SERVICENOTSUPPORTED.
 * \param[in]   SID          The service identifier.
 * \param[out]  ErrorCode    Negative response code to be sent by DCM.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_ChangeErrorCodeIfServiceNotSupported(
  uint8 SID,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode);

/**********************************************************************************************************************
 *  RightsM_ProcessRequestedSessionInfo()
 **********************************************************************************************************************/
/*!
 * \brief         Evaluates access rights for the requested diagnostic service and processes requested session data.
 * \details       -
 * \param[in]     SID            The requested service identifier.
 * \param[in]     RequestData    Pointer to the whole data of the current request.
 * \param[in]     DataSize       Length of RequestData in bytes.
 * \param[in]     SourceAddress  Source address of tester.
 * \param[out]    ErrorCode      Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return        E_OK                                  Access rights found and returned by parameter accessRights.
 *                E_NOT_OK                              Error occurred, details in ErrorCode.
 *                RIGHTSM_E_ACL_IDNOTSUPPORTED          No access right for the given ID in the given ACL.
 *                RIGHTSM_E_ACL_SUBFUNCTIONNOTSUPPORTED No access right for the given sub-function in the given ACL.
 *                RIGHTSM_E_ACL_SERVICENOTSUPPORTED     No access rights for the given service in the given ACL.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_ProcessRequestedSessionInfo(
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData,
  uint16 DataSize,
  uint16 SourceAddress,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode);

/**********************************************************************************************************************
 *  RightsM_EvaluateAccessRightsForSid2C_InputCheck()
 **********************************************************************************************************************/
/*!
 * \brief         Input checks before evaluating access rights for Sid2C.
 * \details       This function is called from RightsM_EvaluateAccessRightsForSid2C() to perform
 *                basic input checks on all input parameters before further evaluating access rights.
 * \param[in]     RequestData  Pointer to the whole data of the current request.
 * \param[in]     DataSize     Length of RequestData in bytes.
 * \param[in]     subFunc      The sub-function of the service.
 * \param[in,out] idIdx        Index position in the RequestData where the id can be read.
 * \param[out]    ErrorCode    Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \param[out]    DDID         The DDID retrieved from RequestData.
 * \return        E_OK                                  Access rights found and returned by parameter accessRights.
 *                E_NOT_OK                              Error occurred, details in ErrorCode.
 *                RIGHTSM_E_ACL_IDNOTSUPPORTED          No access right for the given ID in the given ACL.
 *                RIGHTSM_E_ACL_SUBFUNCTIONNOTSUPPORTED No access right for the given sub-function in the given ACL.
 *                RIGHTSM_E_ACL_SERVICENOTSUPPORTED     No access rights for the given service in the given ACL.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_EvaluateAccessRightsForSid2C_InputCheck(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData,
  uint16 DataSize, RightsM_AccessRights_SubFuncType subFunc,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) idIdx,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode,
  P2VAR(RightsM_AccessRights_IdType, AUTOMATIC, AUTOMATIC) DDID);

/**********************************************************************************************************************
 *  RightsM_EvaluateAccessRightsForSid2C()
 **********************************************************************************************************************/
/*!
 * \brief         Evaluates the access rights only for the DynamicallyDefineDataIdentifier service.
 * \details       -
 * \param[in]     RequestData  Pointer to the whole data of the current request.
 * \param[in]     DataSize     Length of RequestData in bytes.
 * \param[in]     subFunc      The sub-function of the service.
 * \param[in,out] idIdx        Index position in the RequestData where the id can be read.
 * \param[out]    ErrorCode    Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return        E_OK                                  Access rights found and returned by parameter accessRights.
 *                E_NOT_OK                              Error occurred, details in ErrorCode.
 *                RIGHTSM_E_ACL_IDNOTSUPPORTED          No access right for the given ID in the given ACL.
 *                RIGHTSM_E_ACL_SUBFUNCTIONNOTSUPPORTED No access right for the given sub-function in the given ACL.
 *                RIGHTSM_E_ACL_SERVICENOTSUPPORTED     No access rights for the given service in the given ACL.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_EvaluateAccessRightsForSid2C(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData,
  uint16 DataSize,
  RightsM_AccessRights_SubFuncType subFunc,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) idIdx,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode);

/**********************************************************************************************************************
 *  RightsM_EvaluateAccessRightsForSid2A()
 **********************************************************************************************************************/
/*!
 * \brief         Evaluates the access rights only for the DynamicallyDefineDataIdentifier service.
 * \details       -
 * \param[in]     RequestData  Pointer to the whole data of the current request.
 * \param[in]     DataSize     Length of RequestData in bytes.
 * \param[in]     subFunc      The sub-function of the service.
 * \param[in,out] idIdx        Index position in the RequestData where the id can be read.
 * \return        E_OK                                  Access rights found and returned by parameter accessRights.
 *                RIGHTSM_E_ACL_IDNOTSUPPORTED          No access right for the given ID in the given ACL.
 *                RIGHTSM_E_ACL_SUBFUNCTIONNOTSUPPORTED No access right for the given sub-function in the given ACL.
 *                RIGHTSM_E_ACL_SERVICENOTSUPPORTED     No access rights for the given service in the given ACL.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_EvaluateAccessRightsForSid2A(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData,
  uint16 DataSize,
  RightsM_AccessRights_SubFuncType subFunc,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) idIdx);

/**********************************************************************************************************************
 *  RightsM_EvaluateAccessRights()
 **********************************************************************************************************************/
/*!
 * \brief         Evaluates the access rights for the requested diagnostic service except of the DynamicallyDefineDataIdentifier service.
 * \details       -
 * \param[in]     SID          Identifier of the requested diagnostic service.
 * \param[in]     RequestData  Pointer to the whole data of the current request.
 * \param[in]     DataSize     Length of RequestData in bytes.
 * \param[in]     subFunc      The sub-function of the service.
 * \param[in,out] idIdx        Index position in the RequestData where the id can be read.
 * \param[out]    ErrorCode    Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return        E_OK                                  Access rights found and returned by parameter accessRights.
 *                E_NOT_OK                              Error occurred, details in ErrorCode.
 *                RIGHTSM_E_ACL_IDNOTSUPPORTED          No access right for the given ID in the given ACL.
 *                RIGHTSM_E_ACL_SUBFUNCTIONNOTSUPPORTED No access right for the given sub-function in the given ACL.
 *                RIGHTSM_E_ACL_SERVICENOTSUPPORTED     No access rights for the given service in the given ACL.
 * \pre           All provided pointers must be valid.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_EvaluateAccessRights(
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData,
  uint16 DataSize, RightsM_AccessRights_SubFuncType subFunc,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) idIdx,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode);

/**********************************************************************************************************************
 *  RightsM_EvaluateAccessRightsForDiagService()
 **********************************************************************************************************************/
/*!
 * \brief       Evaluates the access rights for the requested diagnostic service.
 * \details     This function evaluates the access rights for the requested diagnostic service.
 * \param[in]   SID          Identifier of the requested diagnostic service.
 * \param[in]   RequestData  Pointer to the whole data of the current request.
 * \param[in]   DataSize     Length of RequestData in bytes.
 * \param[out]  ErrorCode    Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      E_OK                                  Access rights found and returned by parameter accessRights.
 *              E_NOT_OK                              Error occurred, details in ErrorCode.
 *              RIGHTSM_E_ACL_IDNOTSUPPORTED          No access right for the given ID in the given ACL.
 *              RIGHTSM_E_ACL_SUBFUNCTIONNOTSUPPORTED No access right for the given sub-function in the given ACL.
 *              RIGHTSM_E_ACL_SERVICENOTSUPPORTED     No access rights for the given service in the given ACL.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(uint8, Ssa_RightsM_CODE) RightsM_EvaluateAccessRightsForDiagService(
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData,
  uint16 DataSize,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode);

/**********************************************************************************************************************
 *  RightsM_InitiateAuth_CheckTesterCert()
 **********************************************************************************************************************/
/*!
 * \brief       Checks the diagnostic authentication certificate sent from the diagnostic user or tester.
 * \details     -
 * \param[in]   Configuration                            Bit 0: Uni-or bidirectional Authentication: 0=unidirectional, 1=bidirectional, Bit 1-7: Reserved.
 * \param[in]   Challenge_Certificate_Proof_of_Ownership Pointer to challenge tester and diagnostic authentication certificate or proof of ownership tester.
 * \param[out]  Verification_Result                      Positive response code of the routine.
 * \param[in]   DataLength                               Length in bytes of Challenge_Certificate_Proof_of_Ownership
 * \param[out]  parsedTesterCert                         Pointer to the parsed certificate data.
 * \param[out]  nonceStored                               Pointer to stored nonce data structure.
 * \param[out]  errCode                                   The negative response code if an error occurred.
 * \return      E_OK     The diagnostic authentication certificate has been successfully verified.
 *              E_NOT_OK An error occurred.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \spec        requires $lengthOf(Challenge_Certificate_Proof_of_Ownership) >= sizeof(Dcm_Data4004ByteType);
 *              requires  $lengthOf(Challenge_Certificate_Proof_of_Ownership) >= DataLength;
 *              requires parsedTesterCert != NULL_PTR;                                                         \endspec
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_InitiateAuth_CheckTesterCert(
  uint8 Configuration,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Challenge_Certificate_Proof_of_Ownership,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) Verification_Result,
  uint16 DataLength,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedTesterCert,
  P2VAR(RightsM_AuthNonceType, AUTOMATIC, AUTOMATIC) nonceStored,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) errCode);

/**********************************************************************************************************************
 *  RightsM_InitiateAuth_AdjustLocalTime()
 **********************************************************************************************************************/
/*!
 * \brief       Adjusts the local time.
 * \details     This function adjusts the local time based on the validNotBefore date and time info of the diagnostic
 *              authentication certificate.
 * \param[in]   parsedTesterCert     Pointer to the parsed certificate data.
 * \param[in]   nonceValidated       TRUE: A nonce has been successfully validated.
 * \param[out]  Verification_Result  Positive response code of the routine.
 * \param[out]  ErrorCode            Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      E_OK     The time has been successfully adjusted.
 *              E_NOT_OK An error occurred.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_InitiateAuth_AdjustLocalTime(
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedTesterCert,
  boolean nonceValidated,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) Verification_Result,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode);

/**********************************************************************************************************************
 *  RightsM_InitiateAuth_ExtractDataFromTesterCert()
 **********************************************************************************************************************/
/*!
 * \brief       Extracts data from the diagnostic authentication certificate that are needed for the verification of the ownership.
 * \details     This function extracts data from the diagnostic authentication certificate that are needed for the
 *              verification of the ownership and temporarily stores them as security settings for the current diagnostic channel.
 * \param[in]   certificateTester  Pointer to the tester certificate raw data.
 * \param[in]   parsedTesterCert   Pointer to the parsed tester certificate data.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL FUNC(void, Ssa_RightsM_CODE) RightsM_InitiateAuth_ExtractDataFromTesterCert(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) certificateTester,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedTesterCert);

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *  RightsM_IsBroadcastChannel()
 **********************************************************************************************************************/
/*!
 * \brief       Checks for a given diagnostic channel whether authentication broadcast shall be done.
 * \details     -
 * \param[in]   diagChan  Diagnostic channel identifier.
 * \return      TRUE if authentication broadcast is allowed resp. shall be done, else FALSE.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(boolean, Ssa_RightsM_CODE) RightsM_IsBroadcastChannel(uint8 diagChan);

/**********************************************************************************************************************
 *  RightsM_GetNextDiagChannelToSend()
 **********************************************************************************************************************/
/*!
 * \brief       Finds the next diagnostic channel whose turn it is to sent the authentication broadcast message.
 * \details     -
 * \param[out]  nextChannelToSend       The channel id.
 * \return      TRUE    Request succeeded.
 * \return      FALSE   Request failed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \note        nextChannelToSend may be NULL_PTR
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(boolean, Ssa_RightsM_CODE) RightsM_GetNextDiagChannelToSend(
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) nextChannelToSend);

#endif

/**********************************************************************************************************************
 *  RightsM_CheckForDiagServiceToLog()
 **********************************************************************************************************************/
/*!
 * \brief       Checks if the requested diagnostic service is a service that shall trigger a security log event.
 * \details     -
 * \param[in]   SID         The service identifier.
 * \param[in]   subFunc     The sub-function.
 * \param[in]   id          The DID or RID if of the service.
 * \param[in]   RequestData Pointer to the whole data of the current request.
 * \param[in]   DataSize    Length of RequestData in bytes.
 * \param[in]   idIdx       Index position in the RequestData where the id can be read.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_CheckForDiagServiceToLog(
  RightsM_AccessRights_SidType SID,
  RightsM_AccessRights_SubFuncType subFunc,
  RightsM_AccessRights_IdType id,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData,
  uint16 DataSize,
  P2CONST(uint16, AUTOMATIC, AUTOMATIC) idIdx);

/**********************************************************************************************************************
 *  RightsM_HandleTaskVerifyCertOwnership_PostCsmCall()
 **********************************************************************************************************************/
/*!
 * \brief       Handles the task verify certificate ownership after (post Csm processing steps).
 * \details     -
 * \param[out]  Verification_Result   Verification result.
 * \param[out]  Authentication_Result Authentication result.
 * \param[out]  DataLength            Data length out.
 * \param[out]  ErrorCode             Error code.
 * \pre         All provided pointers must be valid.
 *              Authentication_Result must refer to a buffer that consists of >= 6 bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \spec        requires $lengthOf(Authentication_Result) >= 6;                                                 \endspec
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE)  RightsM_HandleTaskVerifyCertOwnership_PostCsmCall(
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) Verification_Result,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Authentication_Result,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode);

/**********************************************************************************************************************
 *  RightsM_CsmSignatureVerify()
 **********************************************************************************************************************/
/*!
 * \brief       Asynchronously calls the CSM signature verify API function.
 * \details     -
 * \param[in]   dataProofOfOwnership  Proof of ownership
 * \param[out]  csmVerifyResult       The result of the signature verification.
 * \return      E_OK          Request succeeded.
 *              E_NOT_OK      Request failed.
 *              SSA_E_PENDING Request is pending.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \spec         requires dataProofOfOwnership != NULL_PTR;
 *               requires csmVerifyResult != NULL_PTR;                                                          \endspec
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_CsmSignatureVerify(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) dataProofOfOwnership,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) csmVerifyResult);

/**********************************************************************************************************************
 * RightsM_LogSuccessfulEnhanceRightsEvent()
 **********************************************************************************************************************/
/*!
 * \brief       Logs an successful enhance rights event.
 * \details     -
 * \param[in]   enhancedRightsCertificate The enhance rights certificate raw data.
 * \param[in]   parsedEnhanceAccessCert  Pointer to the parsed enhanced rights certificate data.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_LogSuccessfulEnhanceRightsEvent(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) enhancedRightsCertificate,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedEnhanceAccessCert);

/**********************************************************************************************************************
 *  RightsM_ClearEnhancedAccessRights()
 **********************************************************************************************************************/
/*!
 * \brief       Clears the enhanced access rights data related to a diagnostic channel.
 * \details     -
 * \param[in]   diagnosticChannel  The identifier of the diagnostic channel whose security settings shall be adopted.
 * \pre         called within exclusive area
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL FUNC(void, Ssa_RightsM_CODE) RightsM_ClearEnhancedAccessRights(uint8 diagnosticChannel);

#if ( SSA_ECU_TYPE == SSA_ECU_TYPE_VSM )

/**********************************************************************************************************************
 *  RightsM_TriggerCentralAuthenticationBroadcast()
 **********************************************************************************************************************/
/*!
 * \brief       (Re-)Triggers a central authentication broadcast after checking if broadcast shall be started.
 *              Starting with current channel
 * \details     -
 * \pre         called within exclusive area
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_TriggerCentralAuthenticationBroadcast(void);

#endif

/**********************************************************************************************************************
 *  RightsM_CompressEnhancedAccessRightsTable()
 **********************************************************************************************************************/
 /*!
 * \brief       Compresses Enhanced Access Rights Table.
 * \details     -
 * \pre         called within exclusive area
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL FUNC(void, Ssa_RightsM_CODE) RightsM_CompressEnhancedAccessRightsTable(void);

/**********************************************************************************************************************
 *  RightsM_GetSerialNumberFromCert()
 **********************************************************************************************************************/
/*!
 * \brief       Gets serial number from certificate.
 * \details     -
 * \param[in]   certificate         Raw data of certificate.
 * \param[in]   certSerialNumber    BER element of serial number to be extracted.
 * \param[out]  serialNumber        Buffer to store the serial number.
 * \param[in]   serialNumberLength  Length of buffer to store the serial number.
 * \return      E_OK      Serial number successfully extracted.
 *              E_NOT_OK  Serial number could not get since to long for provided buffer.
 * \pre         Certificate is parsed and verified.
 *              All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_GetSerialNumberFromCert(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) certificate,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) certSerialNumber,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) serialNumber,
  uint16 serialNumberLength);

/**********************************************************************************************************************
 *  RightsM_HandleNvm()
 *********************************************************************************************************************/
/*!
 * \brief       Writes the RightsM NVRam blocks if requested.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) RightsM_HandleNvm(void);

/**********************************************************************************************************************
 *  RightsM_CheckMileage()
 *********************************************************************************************************************/
/*!
 * \brief       Checks if mileage has succeeded threshold.
 * \details     If necessary rights for user role production are changed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_CheckMileage(void);

#if (SSA_SECURITYACCESSLEVEL == STD_ON)
/**********************************************************************************************************************
 *  RightsM_GetInternalIndexOfSecurityLevel()
 *********************************************************************************************************************/
/*!
 * \brief       Calculates the internal index of a security level.
 * \details     -
 * \param[in]   secLevel  Security level of security access
 * \param[out]  index     The internal index referencing the secLevel
 * \return      E_OK      The calculated index is valid.
 *              E_NOT_OK  Error, the calculated index is not valid.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_GetInternalIndexOfSecurityLevel(
  uint8 secLevel,
  P2VAR(Ssa_SizeOfSecurityAccessLevelType, AUTOMATIC, AUTOMATIC) index);

/**********************************************************************************************************************
 *  RightsM_CompareKeyByCsmSigVerify()
 *********************************************************************************************************************/
/*!
 * \brief       Verifies the given key (signature) against the stored seed for given security level.
 * \details     Doing this by calling Csm_SignatureVerify primitive via Ssa_Cdd.
 * \param[in]   secLevel    The security level to be accessed.
 * \param[in]   key         Pointer to the key (signature) to be verified.
 * \param[in]   secLevelIdx The internal index referencing the secLevel.
 * \param[out]  errorCode   Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                                      Key check passed
 *              RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK   Key check failed
 *              RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING  Key check pending.
 * \pre         Only to be called in Ssa_RightsM_SecurityAccess_CompareKey.
 *              All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_CompareKeyByCsmSigVerify(
  uint8 secLevel,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) key,
  Ssa_SizeOfSecurityAccessLevelType secLevelIdx,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) errorCode);
#endif

/**********************************************************************************************************************
 *  RightsM_NextIteration()
 *********************************************************************************************************************/
/*!
 * \brief           Determines the length and the offset of the next iteration in the data buffer.
 * \details         -
 * \param[in]       data              A data buffer containing iterations.
 * \param[in]       dataLength        The length of the data in the data buffer.
 * \param[in,out]   offset            [in]    The current position in the buffer /
 *                                            The (potential) index where the length field of the next iteration begins
 *                                    [out]   The index after the next iteration /
 *                                            The position of the (potential) next iteration after the detected iteration
 *                                            Returned value is guaranteed to be <= dataLength.
 * \param[out]      iterationLength   The length of the data contained in the iteration (without the length field)
 * \return          E_OK              Iteration was successfully processed
 *                  E_NOT_OK          Buffer is too short to contain an iteration /
 *                                    Buffer is too small to contain the complete advertised iteration
 * \pre             All provided pointers must be valid.
 *                  The in value of *offset must be <= dataLength.
 * \context         ANY
 * \reentrant       TRUE
 * \synchronous     TRUE
 * \spec            requires *offset <= dataLength;                                                             \endspec
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_NextIteration(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) data,
  uint16 dataLength,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) offset,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) iterationLength);

/**********************************************************************************************************************
 *  RightsM_CheckAuthenticationInputData()
 *********************************************************************************************************************/
/*!
 * \brief       Checks the input data of routine control service R260 for correct length and format.
 *              Extracts needed data (e.g. certificate, proof of ownership)
 * \details     -
 * \param[in]   Configuration Bit 0: Uni- or bidirectional Authentication: 0=unidirectional, 1=bidirectional,
 *                            Bit 7: Standard or S29 sub-processing: 0=standard, 1=S29 special sub-processing
 *                                   Depending on this switch either provides index of first iteration's data or
 *                                   of the second iteration's data
 * \param[in]   DataIn        Input data
 * \param[in]   DataLength    Length of input data
 * \param[out]  idxData       index of the certificate data within buffer DataIn
 * \param[out]  lenData       length of the certificate data within buffer DataIn
 * \param[out]  errCode       Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      E_OK          Check was successful
 *              E_NOT_OK      Error occurred
 * \pre         All provided pointers must be valid.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_RIGHTSM_LOCAL FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_CheckAuthenticationInputData(
  uint8 Configuration,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) DataIn,
  uint16 DataLength,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) idxData,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) lenData,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) errCode);

#define Ssa_RightsM_STOP_SEC_CODE
#include "Ssa_RightsM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
 * Dcm_DiagnosticSessionControlType: Integer in interval [0...255]
 * Ssa_ConstDataPtr: DataReference
 * Ssa_DataPtr: DataReference
 * Ssa_LengthPtr: DataReference
 * Ssa_VerifyResultPtr: DataReference
 * boolean: Boolean (standard type)
 * c24_km_0_999999k9_0k1_Invld_SNA: Integer in interval [0...16777215]
 * dtRef_const_VOID: DataReference
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint64: Integer in interval [0...18446744073709551615] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * CertP_PkiRoleType: Enumeration of integer in interval [0...255] with enumerators
 *   CERTP_PKI_ROLE_ROOT (1U)
 *   CERTP_PKI_ROLE_BACKEND (2U)
 *   CERTP_PKI_ROLE_TESTER (3U)
 *   CERTP_PKI_ROLE_ECU (4U)
 *   CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS (5U)
 *   CERTP_PKI_ROLE_VARIANT_CODING (7U)
 *   CERTP_PKI_ROLE_USER_CERT_FOR_CODING (9U)
 *   CERTP_PKI_ROLE_ROOT_CA_LINK_CERT (10U)
 *   CERTP_PKI_ROLE_BACKEND_CA_LINK_CERT (11U)
 *   CERTP_PKI_ROLE_TRUST_MODEL_ROOT_CA (12U)
 *   CERTP_PKI_ROLE_TRUST_MODEL_BACKEND_CA (13U)
 *   CERTP_PKI_ROLE_TRUST_MODEL_INTERMEDIATE_CA (14U)
 *   CERTP_PKI_ROLE_TRUST_MODEL_ECU (15U)
 *   CERTP_PKI_ROLE_TRUST_MODEL_ROOT_CA_LINK (16U)
 *   CERTP_PKI_ROLE_TRUST_MODEL_BACKEND_CA_LINK (17U)
 *   CERTP_PKI_ROLE_TRUST_MODEL_INTERMEDIATE_CA_LINK (18U)
 *   CERTP_PKI_ROLE_PQC_ROOT_CA (19U)
 *   CERTP_PKI_ROLE_PQC_BACKEND_CA (20U)
 *   CERTP_PKI_ROLE_PQC_TESTER (21U)
 *   CERTP_PKI_ROLE_PQC_ECU (22U)
 *   CERTP_PKI_ROLE_INVALID (0U)
 * CertP_VerificationResultType: Enumeration of integer in interval [0...255] with enumerators
 *   CERTP_VER_OK (0U)
 *   CERTP_VER_INVALID_TIME_PERIOD (16U)
 *   CERTP_VER_INVALID_SIGNATURE (17U)
 *   CERTP_VER_INVALID_CHAIN_OF_TRUST (18U)
 *   CERTP_VER_INVALID_TYPE (19U)
 *   CERTP_VER_INVALID_FORMAT (20U)
 *   CERTP_VER_INVALID_CONTENT (21U)
 *   CERTP_VER_INVALID_SCOPE (22U)
 *   CERTP_VER_SYNCHRONIZE_TIME_FAILED_NONCE_NOT_ACCEPTED (64U)
 *   CERTP_VER_PARSE_OK (253U)
 *   CERTP_VER_PARSE_FAILED (254U)
 *   CERTP_VER_NOT_PARSED (255U)
 * Coding_MemoryStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   CODING_OK (0U)
 *   CODING_FAILED (1U)
 *   CODING_ACTIVE (2U)
 * Coding_ModeType: Enumeration of integer in interval [0...255] with enumerators
 *   CODING_OK (0U)
 *   CODING_FAILED (1U)
 *   CODING_ACTIVE (2U)
 * Crypto_OperationModeType: Enumeration of integer in interval [0...255] with enumerators
 *   CRYPTO_OPERATIONMODE_START (1U)
 *   CRYPTO_OPERATIONMODE_UPDATE (2U)
 *   CRYPTO_OPERATIONMODE_STREAMSTART (3U)
 *   CRYPTO_OPERATIONMODE_FINISH (4U)
 *   CRYPTO_OPERATIONMODE_SINGLECALL (7U)
 * Crypto_VerifyResultType: Enumeration of integer in interval [0...1] with enumerators
 *   CRYPTO_E_VER_OK (0U)
 *   CRYPTO_E_VER_NOT_OK (1U)
 * Csm_ResultType: Enumeration of integer in interval [0...8] with enumerators
 *   E_NOT_OK (1U)
 *   E_SMALL_BUFFER (2U)
 *   E_ENTROPY_EXHAUSTION (3U)
 *   E_KEY_READ_FAIL (4U)
 *   E_KEY_NOT_AVAILABLE (4U)
 *   E_KEY_NOT_VALID (6U)
 *   E_JOB_CANCELED (7U)
 *   E_KEY_EMPTY (8U)
 * Dcm_ConfirmationStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_RES_POS_OK (0U)
 *   DCM_RES_POS_NOT_OK (1U)
 *   DCM_RES_NEG_OK (2U)
 *   DCM_RES_NEG_NOT_OK (3U)
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...254] with enumerators
 *   DCM_E_POSITIVERESPONSE (0U)
 *   DCM_E_GENERALREJECT (16U)
 *   DCM_E_SERVICENOTSUPPORTED (17U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
 *   DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
 *   DCM_E_RESPONSETOOLONG (20U)
 *   DCM_E_BUSYREPEATREQUEST (33U)
 *   DCM_E_CONDITIONSNOTCORRECT (34U)
 *   DCM_E_REQUESTSEQUENCEERROR (36U)
 *   DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
 *   DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
 *   DCM_E_REQUESTOUTOFRANGE (49U)
 *   DCM_E_SECURITYACCESSDENIED (51U)
 *   DCM_E_INVALIDKEY (53U)
 *   DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
 *   DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
 *   DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
 *   DCM_E_TRANSFERDATASUSPENDED (113U)
 *   DCM_E_GENERALPROGRAMMINGFAILURE (114U)
 *   DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
 *   DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING (120U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
 *   DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
 *   DCM_E_RPMTOOHIGH (129U)
 *   DCM_E_RPMTOOLOW (130U)
 *   DCM_E_ENGINEISRUNNING (131U)
 *   DCM_E_ENGINEISNOTRUNNING (132U)
 *   DCM_E_ENGINERUNTIMETOOLOW (133U)
 *   DCM_E_TEMPERATURETOOHIGH (134U)
 *   DCM_E_TEMPERATURETOOLOW (135U)
 *   DCM_E_VEHICLESPEEDTOOHIGH (136U)
 *   DCM_E_VEHICLESPEEDTOOLOW (137U)
 *   DCM_E_THROTTLE_PEDALTOOHIGH (138U)
 *   DCM_E_THROTTLE_PEDALTOOLOW (139U)
 *   DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
 *   DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
 *   DCM_E_BRAKESWITCH_NOTCLOSED (143U)
 *   DCM_E_SHIFTERLEVERNOTINPARK (144U)
 *   DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
 *   DCM_E_VOLTAGETOOHIGH (146U)
 *   DCM_E_VOLTAGETOOLOW (147U)
 *   DCM_E_VMSCNC_0 (240U)
 *   DCM_E_VMSCNC_1 (241U)
 *   DCM_E_VMSCNC_2 (242U)
 *   DCM_E_VMSCNC_3 (243U)
 *   DCM_E_VMSCNC_4 (244U)
 *   DCM_E_VMSCNC_5 (245U)
 *   DCM_E_VMSCNC_6 (246U)
 *   DCM_E_VMSCNC_7 (247U)
 *   DCM_E_VMSCNC_8 (248U)
 *   DCM_E_VMSCNC_9 (249U)
 *   DCM_E_VMSCNC_A (250U)
 *   DCM_E_VMSCNC_B (251U)
 *   DCM_E_VMSCNC_C (252U)
 *   DCM_E_VMSCNC_D (253U)
 *   DCM_E_VMSCNC_E (254U)
 * Dcm_OpStatusType: Enumeration of integer in interval [0...64] with enumerators
 *   DCM_INITIAL (0U)
 *   DCM_PENDING (1U)
 *   DCM_CANCEL (2U)
 *   DCM_FORCE_RCRRP_OK (3U)
 *   DCM_FORCE_RCRRP_NOT_OK (64U)
 * Dem_EventStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_EVENT_STATUS_PASSED (0U)
 *   DEM_EVENT_STATUS_FAILED (1U)
 *   DEM_EVENT_STATUS_PREPASSED (2U)
 *   DEM_EVENT_STATUS_PREFAILED (3U)
 *   DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED (4U)
 * NvM_RequestResultType: Enumeration of integer in interval [0...255] with enumerators
 *   NVM_REQ_OK (0U)
 *   NVM_REQ_NOT_OK (1U)
 *   NVM_REQ_PENDING (2U)
 *   NVM_REQ_INTEGRITY_FAILED (3U)
 *   NVM_REQ_BLOCK_SKIPPED (4U)
 *   NVM_REQ_NV_INVALIDATED (5U)
 *   NVM_REQ_CANCELED (6U)
 *   NVM_REQ_REDUNDANCY_FAILED (7U)
 *   NVM_REQ_RESTORED_FROM_ROM (8U)
 * RightsM_ACL_BitMaskType: Enumeration of integer in interval [0...4294967295] with enumerators
 *   RIGHTSM_ACL_BITMASK_ANYBODY (1U)
 *   RIGHTSM_ACL_BITMASK_SUPPLIER (2U)
 *   RIGHTSM_ACL_BITMASK_DEV_ENHANCED (4U)
 *   RIGHTSM_ACL_BITMASK_PRODUCTION (8U)
 *   RIGHTSM_ACL_BITMASK_AS_ENHANCED (16U)
 *   RIGHTSM_ACL_BITMASK_AS_STANDARD (32U)
 *   RIGHTSM_ACL_BITMASK_AS_BASIC (64U)
 *   RIGHTSM_ACL_BITMASK_INT_DIAG_TEST_TOOL (128U)
 *   RIGHTSM_ACL_BITMASK_EPTI_TEST_TOOL (256U)
 * RightsM_AuthenticationModeType: Enumeration of integer in interval [0...255] with enumerators
 *   RIGHTSM_UNAUTHENTICATED (0U)
 *   RIGHTSM_AUTHENTICATED (1U)
 * RightsM_AuthenticationStateType: Enumeration of integer in interval [0...255] with enumerators
 *   RIGHTSM_CHANNEL_NOT_AUTHENTICATED (0U)
 *   RIGHTSM_CHANNEL_LOCALLY_AUTHENTICATED (1U)
 *   RIGHTSM_CHANNEL_CENTRALLY_AUTHENTICATED (2U)
 * RightsM_DiagnosticUserRoleType: Enumeration of integer in interval [0...255] with enumerators
 *   RIGHTSM_USERROLE_ANYBODY (0U)
 *   RIGHTSM_USERROLE_SUPPLIER (1U)
 *   RIGHTSM_USERROLE_DEV_ENHANCED (2U)
 *   RIGHTSM_USERROLE_PRODUCTION (3U)
 *   RIGHTSM_USERROLE_AS_ENHANCED (4U)
 *   RIGHTSM_USERROLE_AS_STANDARD (5U)
 *   RIGHTSM_USERROLE_AS_BASIC (6U)
 *   RIGHTSM_USERROLE_INT_DIAG_TEST_TOOL (7U)
 *   RIGHTSM_USERROLE_EPTI_TEST_TOOL (8U)
 * Ssa_KeyElementType: Enumeration of integer in interval [0...4294967295] with enumerators
 *   SSA_KE_MAC_KEY (1U)
 *   SSA_KE_MAC_PROOF (2U)
 *   SSA_KE_SIGNATURE_KEY (1U)
 *   SSA_KE_RANDOM_SEED_STATE (3U)
 *   SSA_KE_RANDOM_ALGORITHM (4U)
 *   SSA_KE_CIPHER_KEY (1U)
 *   SSA_KE_CIPHER_IV (5U)
 *   SSA_KE_CIPHER_PROOF (6U)
 *   SSA_KE_CIPHER_2NDKEY (7U)
 *   SSA_KE_KEYEXCHANGE_BASE (8U)
 *   SSA_KE_KEYEXCHANGE_PRIVKEY (9U)
 *   SSA_KE_KEYEXCHANGE_OWNPUBKEY (10U)
 *   SSA_KE_KEYEXCHANGE_SHAREDVALUE (1U)
 *   SSA_KE_KEYEXCHANGE_ALGORITHM (12U)
 *   SSA_KE_KEYDERIVATION_PASSWORD (1U)
 *   SSA_KE_KEYDERIVATION_SALT (13U)
 *   SSA_KE_KEYDERIVATION_ITERATIONS (14U)
 *   SSA_KE_KEYDERIVATION_ALGORITHM (15U)
 *   SSA_KE_KEYGENERATE_KEY (1U)
 *   SSA_KE_KEYGENERATE_SEED (16U)
 *   SSA_KE_KEYGENERATE_ALGORITHM (17U)
 *   SSA_KE_CERTIFICATE_DATA (0U)
 * Ssa_OnOff_StateType: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_STATE_OFF (0U)
 *   SSA_STATE_ON (1U)
 * Ssa_OperationModeType: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_ACTIVE (0U)
 *   SSA_INACTIVE (1U)
 * Ssa_PostProductionStatusType: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_POST_PRODUCTION_STATUS_DEACTIVATED (0U)
 *   SSA_POST_PRODUCTION_STATUS_IRREVERSIBLY_ACTIVATED (1U)
 *   SSA_POST_PRODUCTION_STATUS_REVERSIBLY_ACTIVATED (2U)
 * TimeM_CompareOperatorType: Enumeration of integer in interval [0...255] with enumerators
 *   TIMEM_IS_GREATER (0U)
 *   TIMEM_IS_LESS (1U)
 * TimeM_RealTimeChangeReasonType: Enumeration of integer in interval [0...255] with enumerators
 *   TIMEM_REALTIMECHANGEREASON_NOTBEFORE (0U)
 *   TIMEM_REALTIMECHANGEREASON_NONCE (1U)
 *
 * Array Types:
 * ============
 * CertP_RawCertBufferType: Array with 910 element(s) of type uint8
 * Csm_KeyDataType_Ssa_SignatureRamKey: Array with 32 element(s) of type uint8
 * Csm_RandomGenerateResultType_Random: Array with 32 element(s) of type uint8
 * Dcm_Data15ByteType: Array with 15 element(s) of type uint8
 * Dcm_Data16ByteType: Array with 16 element(s) of type uint8
 * Dcm_Data1ByteType: Array with 1 element(s) of type uint8
 * Dcm_Data2002ByteType: Array with 2002 element(s) of type uint8
 * Dcm_Data3006ByteType: Array with 3006 element(s) of type uint8
 * Dcm_Data32ByteType: Array with 32 element(s) of type uint8
 * Dcm_Data4004ByteType: Array with 4004 element(s) of type uint8
 * Dcm_Data64ByteType: Array with 64 element(s) of type uint8
 * Dcm_SsaDslBufferType: Array with 8195 element(s) of type uint8
 * RightsM_AuthenticationBroadcastType: Array with 20 element(s) of type uint8
 * RightsM_ChallengeEcuType: Array with 32 element(s) of type uint8
 * RightsM_IssuerType: Array with 15 element(s) of type uint8
 * RightsM_SerialNumberType: Array with 16 element(s) of type uint8
 * SecLog_AclVersionType: Array with 11 element(s) of type uint8
 * SecLog_AuthenticationContentType: Array with 18 element(s) of type uint8
 * Ssa_Data20ByteType: Array with 20 element(s) of type uint8
 * Ssa_Data2ByteType: Array with 2 element(s) of type uint8
 * Ssa_Data30ByteType: Array with 30 element(s) of type uint8
 * Ssa_Data32ByteType: Array with 32 element(s) of type uint8
 *
 * Record Types:
 * =============
 * CertP_BerElementType: Record with elements
 *   validContent of type boolean
 *   elemDataIdx of type uint16
 *   elemDataLength of type uint16
 * CertP_ParsedCertStructureType: Record with elements
 *   verificationResult of type CertP_VerificationResultType
 *   parsedCertLength of type uint16
 *   signedCertData of type CertP_BerElementType
 *   version of type uint8
 *   serialNumber of type CertP_BerElementType
 *   certSignatureAlgOID of type CertP_BerElementType
 *   issuer of type CertP_BerElementType
 *   validNotBefore of type CertP_TimeType
 *   validNotAfter of type CertP_TimeType
 *   subject of type CertP_BerElementType
 *   publicKey of type CertP_BerElementType
 *   subjectKeyIdentifier of type CertP_BerElementType
 *   authorityKeyIdentifier of type CertP_BerElementType
 *   keyUsage of type uint16
 *   basicConstraints of type uint8
 *   pkiRole of type CertP_PkiRoleType
 *   userRole of type RightsM_DiagnosticUserRoleType
 *   targetECU of type CertP_BerElementType
 *   targetVIN of type CertP_BerElementType
 *   nonce of type CertP_BerElementType
 *   prodQualifier of type uint8
 *   uniqueEcuId of type CertP_BerElementType
 *   service of type CertP_BerElementType
 *   holderIssuer of type CertP_BerElementType
 *   holderSerialNumber of type CertP_BerElementType
 *   signatureAlgorithmOID of type CertP_BerElementType
 *   signature of type CertP_BerElementType
 *   specialECU of type uint8
 *   targetSubjectKeyIdentifier of type CertP_BerElementType
 * CertP_TimeType: Record with elements
 *   validContent of type boolean
 *   dateTime of type TimeM_DateTimeType
 * RightsM_AuthNonceType: Record with elements
 *   data of type Ssa_Data32ByteType
 *   validated of type boolean
 * RightsM_DiagChannelDataType: Record with elements
 *   currentDiagnosticChannel of type uint8
 *   authentication_State of type RightsM_AuthenticationStateType
 *   authentication_ExpectedTask of type uint8
 *   authentication_ChallengeEcu of type RightsM_ChallengeEcuType
 *   authenticationTimeoutTimer of type uint16
 *   defaultSessionRequestFlag of type boolean
 *   securitySettings of type RightsM_SecuritySettingsType
 * RightsM_NonceType: Record with elements
 *   data of type Ssa_Data32ByteType
 *   timestamp of type uint64
 *   isValid of type boolean
 * RightsM_SecuritySettingsType: Record with elements
 *   testerPublicKey of type Ssa_Data32ByteType
 *   testerSerialNumber of type RightsM_SerialNumberType
 *   testerIssuer of type RightsM_IssuerType
 *   diagnosticUserRole of type RightsM_DiagnosticUserRoleType
 *   restrictedAuthentication of type boolean
 * Ssa_OdometerRecordType: Record with elements
 *   Odo_ST3 of type c24_km_0_999999k9_0k1_Invld_SNA
 * TimeM_DateTimeType: Record with elements
 *   year of type uint16
 *   month of type uint8
 *   day of type uint8
 *   hour of type uint8
 *   minute of type uint8
 *   second of type uint8
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
 *   Ssa_PostProductionStatusType *Rte_Pim_RightsMPostProductionStatus(void)
 *   Ssa_PostProductionStatusType *Rte_Pim_RightsMPostProductionStatusMirror(void)
 *   Ssa_PostProductionStatusType *Rte_Pim_RightsMPostProductionStatusMirror2(void)
 *   uint8 *Rte_Pim_RightsMAclVersion(void)
 *     Returnvalue: uint8* is of type SecLog_AclVersionType
 *   RightsM_NonceType *Rte_Pim_RightsMNonce(void)
 *   RightsM_NonceType *Rte_Pim_RightsMNonceMirror(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   Ssa_PostProductionStatusType Rte_CData_NvM_RightsM_PostProductionStatus_DefaultValue(void)
 *   uint8 *Rte_CData_NvM_RightsM_AclVersion_DefaultValue(void)
 *     Returnvalue: uint8* is of type SecLog_AclVersionType
 *   RightsM_NonceType *Rte_CData_NvM_RightsM_Nonce_DefaultValue(void)
 *
 *********************************************************************************************************************/

#define Ssa_RightsM_START_SEC_CODE
#include "Ssa_RightsM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_Certificate_GetDiagAuthCertSerialNumber_SecurityAccess
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDiagAuthCertSerialNumber_SecurityAccess> of PortPrototype <RightsM_Certificate>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_Certificate_GetDiagAuthCertSerialNumber_SecurityAccess(uint8 *serialNumber)
 *     Argument serialNumber: uint8* is of type RightsM_SerialNumberType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Ssa_RightsM_Certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_Certificate_GetDiagAuthCertSerialNumber_SecurityAccess_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(serialNumber) >= sizeof(RightsM_SerialNumberType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_Certificate_GetDiagAuthCertSerialNumber_SecurityAccess(P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) serialNumber) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_Certificate_GetDiagAuthCertSerialNumber_SecurityAccess (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_Ssa_RightsM_Certificate_E_NOT_OK;
  uint8 channelIdOfLastSuccessfulSecurityAccess;

  /* Keep diagnostic channel ID in a local buffer so it can't be modified in a different context. */
  channelIdOfLastSuccessfulSecurityAccess = RightsM_ChannelIdOfLastSuccessfulSecurityAccess;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (serialNumber == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Check if the diagnostic channel ID used for last successful security access is valid. */
    if (!RightsM_IsDiagChanValid(channelIdOfLastSuccessfulSecurityAccess))
    {
      /* retVal already set */
    }
    else
    {
      uint8 byteIdx;
      retVal = RTE_E_OK;

      /* #20 Return the tester serial number. */
      Rte_Enter_RightsM_ExclusiveArea();
      for (byteIdx = 0u; byteIdx < SSA_SIZEOF_SERIALNUMBER; byteIdx++)
      {
        serialNumber[byteIdx] = RightsM_DiagChannelData[channelIdOfLastSuccessfulSecurityAccess].securitySettings.testerSerialNumber[byteIdx];
      }
      Rte_Exit_RightsM_ExclusiveArea();
    }
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_Com_ReceiveBroadcastAuthentication
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <authentication> of PortPrototype <RightsM_ReceiveAuthenticationBroadcast>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_RightsM_ReceiveAuthenticationBroadcast_authentication(uint8 *data)
 *     Argument data: uint8* is of type RightsM_AuthenticationBroadcastType
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_Authentication_Mode(RightsM_AuthenticationModeType mode)
 *   Modes of Rte_ModeType_RightsM_AuthenticationMode:
 *   - RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_AUTHENTICATED
 *   - RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_UNAUTHENTICATED
 *   - RTE_TRANSITION_RightsM_AuthenticationMode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_KeyM_Certificate_GetBackendSerialNumber(uint8 *serialNumber, uint16 *serialNumberLength)
 *     Argument serialNumber: uint8* is of type Ssa_Data2ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_KeyM_Certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_SecLog_SuccessfulAuthAndEnhanceRights_SuccessfulAuthAndEnhanceRights(uint8 diagChanAuthStatus, CertP_PkiRoleType pkiRole, const uint8 *authenticationContent)
 *     Argument authenticationContent: uint8* is of type SecLog_AuthenticationContentType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_SuccessfulAuthAndEnhanceRights_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_Com_ReceiveBroadcastAuthentication_doc
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
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_RightsM_CODE) Ssa_RightsM_Com_ReceiveBroadcastAuthentication(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_Com_ReceiveBroadcastAuthentication
 *********************************************************************************************************************/
  /* SSA-IS-827
     DataIdx   Length  Parameter / Description
     0         1       Diagnostic Channel
     1         1       DiagnosticUserRole
     2-17      16      Serial Number of Diagnostic Authentication Certificate
     18-19     2       Serial Number of Backend CA Certificate
    (20        1       SecOC Truncated Timestamp)
    (21-28     8       SecOC MAC) */
  uint8 broadcastData[SSA_RIGHTSM_SIZEOF_AUTHENTICATION_BROADCAST];
  uint8 diagnosticChannel;

  /* Check if authentication broadcast is active/ allowed at all. */
  /* #10 Read broadcast message. */
  (void)Rte_Read_RightsM_ReceiveAuthenticationBroadcast_authentication(broadcastData);

  /* #20 Initially identify the diagnostic channel from the broadcast data. */
  diagnosticChannel = RightsM_GetDiagChanIdFromSourceAddress(broadcastData[0]);

  /* #30 If a diagnostic user or tester is already locally authenticated ignore the authentication broadcast.
   *     Also check user-role and post production status in case of user-role production. */
  if (RightsM_IsDiagChanValid(diagnosticChannel)
    && (RightsM_DiagChannelData[diagnosticChannel].authentication_State != RIGHTSM_CHANNEL_LOCALLY_AUTHENTICATED)
    && (((broadcastData[1] == RIGHTSM_USERROLE_PRODUCTION) && (*Rte_Pim_RightsMPostProductionStatus() == SSA_POST_PRODUCTION_STATUS_DEACTIVATED))
    || (broadcastData[1] == RIGHTSM_USERROLE_AS_ENHANCED)
    || (broadcastData[1] == RIGHTSM_USERROLE_AS_STANDARD)
    || (broadcastData[1] == RIGHTSM_USERROLE_AS_BASIC)
    || (broadcastData[1] == RIGHTSM_USERROLE_INT_DIAG_TEST_TOOL)
    || (broadcastData[1] == RIGHTSM_USERROLE_EPTI_TEST_TOOL)))
  {
    Std_ReturnType rVal;
    uint8 backendSerialNumber[SSA_SIZEOF_BACKEND_SERIALNUMBER];
    uint16 backendSerialNumberLength = SSA_SIZEOF_BACKEND_SERIALNUMBER;

    /* #40 Get backend serial number from KeyM. */
    rVal = Rte_Call_KeyM_Certificate_GetBackendSerialNumber(backendSerialNumber, &backendSerialNumberLength);
    if ((rVal == E_OK) && (backendSerialNumberLength == SSA_SIZEOF_BACKEND_SERIALNUMBER))
    {
      Rte_Enter_RightsM_ExclusiveArea();
      /* #50 Check serial number of backend certificate (SSA-IS-466). */
      if (RightsM_CompareData((P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))&(broadcastData[2u + SSA_SIZEOF_SERIALNUMBER]), (P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))backendSerialNumber, SSA_SIZEOF_BACKEND_SERIALNUMBER) == TRUE)
      {
        boolean securitySettingsChanged = (RightsM_DiagChannelData[diagnosticChannel].authentication_State == RIGHTSM_CHANNEL_NOT_AUTHENTICATED) ? TRUE : FALSE;

        /* #60 Check if security settings have changed (SSA-IS-470). */
        if (RightsM_CompareData((P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))&(broadcastData[2]), (P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))RightsM_DiagChannelData[diagnosticChannel].securitySettings.testerSerialNumber, SSA_SIZEOF_SERIALNUMBER) == FALSE)
        {
          securitySettingsChanged = TRUE;
        }
        if (RightsM_DiagChannelData[diagnosticChannel].securitySettings.diagnosticUserRole != broadcastData[1])
        {
          securitySettingsChanged = TRUE;
        }

        if (securitySettingsChanged == TRUE)
        {
          uint8 authenticationContent[SSA_SIZEOF_SERIALNUMBER + SSA_SIZEOF_BACKEND_SERIALNUMBER] = { 0u };

          /* #70 Get diag. channel source address from broadcast message. */
          RightsM_DiagChannelData[diagnosticChannel].currentDiagnosticChannel = broadcastData[0];

          /* #71 Enter authenticated state (SSA-IS-472). */
          RightsM_DiagChannelData[diagnosticChannel].authentication_State = RIGHTSM_CHANNEL_CENTRALLY_AUTHENTICATED;

          /* #72 Extract and store the serial number from the authentication broadcast (SSA-IS-474). */
          Ssa_MemCpy((P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR))RightsM_DiagChannelData[diagnosticChannel].securitySettings.testerSerialNumber, (P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))&broadcastData[2], SSA_SIZEOF_SERIALNUMBER);

          /* #73 Store received diagnostic user role (SSA-IS-472). */
          RightsM_DiagChannelData[diagnosticChannel].securitySettings.diagnosticUserRole = broadcastData[1];

          Rte_Exit_RightsM_ExclusiveArea();

          Ssa_MemCpy((P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR))authenticationContent, (P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))&broadcastData[2], SSA_SIZEOF_SERIALNUMBER + SSA_SIZEOF_BACKEND_SERIALNUMBER);

          /* #74 Log successful (central) authentication with dummy PKI role 0x00 (SSA-IS-1639, SSA-IS-1645). */
          (void)Rte_Call_SecLog_SuccessfulAuthAndEnhanceRights_SuccessfulAuthAndEnhanceRights((uint8)(broadcastData[0]|0x80u), 0x00u, authenticationContent);

          /* #75 Switch global authentication mode to "authenticated". */
          (void)Rte_Switch_Authentication_Mode(RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_AUTHENTICATED);

          Rte_Enter_RightsM_ExclusiveArea();
        }

        /* #80 On valid reception of an authentication broadcast restart the authentication timeout (SSA-IS-485). */
        RightsM_DiagChannelData[diagnosticChannel].authenticationTimeoutTimer = SSA_RIGHTSM_AUTHENTICATION_TIMEOUT;
      }
      Rte_Exit_RightsM_ExclusiveArea();
    }
  }
  /* PRQA S 6050 5 */ /* MD_MSR_STCAL */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

#if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_CsmCallbackNotification_RandomGenerate
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CallbackNotification> of PortPrototype <CallbackNotification_RandomGenerateNonce>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Ssa_RightsM_CsmCallbackNotification_RandomGenerate(Csm_ResultType result)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_CsmCallbackNotification_RandomGenerate_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_RightsM_CODE) Ssa_RightsM_CsmCallbackNotification_RandomGenerate(Csm_ResultType result) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_CsmCallbackNotification_RandomGenerate
 *********************************************************************************************************************/
  /* #10 Handle the Csm random generate state dependent on the callback's result.*/
  RightsM_UpdateLocalAsyncState(&RightsM_RandomGenerateAsyncState, result);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_CsmCallbackNotification_SigVerify_SecurityAccess
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CallbackNotification> of PortPrototype <CallbackNotification_SigVerify_SecurityAccess>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Ssa_RightsM_CsmCallbackNotification_SigVerify_SecurityAccess(Csm_ResultType result)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_CsmCallbackNotification_SigVerify_SecurityAccess_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_RightsM_CODE) Ssa_RightsM_CsmCallbackNotification_SigVerify_SecurityAccess(Csm_ResultType result) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_CsmCallbackNotification_SigVerify_SecurityAccess
 *********************************************************************************************************************/
# if (SSA_SECURITYACCESSLEVEL == STD_ON)
  /* #10 Do the security access signature verify state handling dependent on the callback's result. */
  RightsM_UpdateLocalAsyncState(&RightsM_CompareKeyAsyncState, result);
# else
  SSA_DUMMY_STATEMENT(result);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
# endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_CsmCallbackNotification_SignatureVerify
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CallbackNotification> of PortPrototype <CallbackNotification_SignatureVerify>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Ssa_RightsM_CsmCallbackNotification_SignatureVerify(Csm_ResultType result)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_CsmCallbackNotification_SignatureVerify_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_RightsM_CODE) Ssa_RightsM_CsmCallbackNotification_SignatureVerify(Csm_ResultType result) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_CsmCallbackNotification_SignatureVerify
 *********************************************************************************************************************/

  /* #10 Handle the Csm signature verify state dependent on the callback's result. */
  RightsM_UpdateLocalAsyncState(&RightsM_CsmSignatureVerifyAsyncState, result);
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0185_Basic_ACL_Hash>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Hash_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Hash_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_Basic_ACL_Hash_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Check if there is a basic access control list available (null pointer check). */
    boolean aclUndefined = (RightsM_BasicAcl == NULL_PTR) ? TRUE : FALSE;
    retVal = RightsM_GenericConditionCheckRead(aclUndefined, RTE_E_DataServices_DID_0185_Basic_ACL_Hash_E_NOT_OK, ErrorCode);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0185_Basic_ACL_Hash>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data64ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Hash_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Hash_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data64ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Hash_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_Basic_ACL_Hash_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Copy the hash of the access control list to the provided output buffer. */
    retVal = RightsM_CopyOrClear(Data, RightsM_BasicAcl, RIGHTSM_ACCESSRIGHTS_OFFSET_HASH, SSA_SIZEOF_HASHVALUE);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Check if there is a basic access control list available (null pointer check). */
    boolean aclUndefined = (RightsM_BasicAcl == NULL_PTR) ? TRUE : FALSE;
    retVal = RightsM_GenericConditionCheckRead(aclUndefined, RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_E_NOT_OK, ErrorCode);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data1ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Major_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Write the major version encoded as a 2-digit decimal to the first byte of the output buffer. */
    retVal = RightsM_CopyOrClear(Data, RightsM_BasicAcl, RIGHTSM_ACCESSRIGHTS_OFFSET_LABEL_REV_HISTORY_CDD, 1u);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Check if there is a basic access control list available (null pointer check). */
    boolean aclUndefined = (RightsM_BasicAcl == NULL_PTR) ? TRUE : FALSE;
    retVal = RightsM_GenericConditionCheckRead(aclUndefined, RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_E_NOT_OK, ErrorCode);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data1ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Minor_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Write the minor version encoded as a 2-digit decimal to the first byte of the output buffer. */
    retVal = RightsM_CopyOrClear(Data, RightsM_BasicAcl, RIGHTSM_ACCESSRIGHTS_OFFSET_LABEL_REV_HISTORY_CDD + 3u, 1u);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Check if there is a basic access control list available (null pointer check). */
    boolean aclUndefined = (RightsM_BasicAcl == NULL_PTR) ? TRUE : FALSE;
    retVal = RightsM_GenericConditionCheckRead(aclUndefined, RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_E_NOT_OK, ErrorCode);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data1ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_Basic_ACL_Version_Candela_File_Version_Patch_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Write the patch version encoded as a 2-digit decimal to the first byte of the output buffer. */
    retVal = RightsM_CopyOrClear(Data, RightsM_BasicAcl, RIGHTSM_ACCESSRIGHTS_OFFSET_LABEL_REV_HISTORY_CDD + 6u, 1u);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Check if there is a basic access control list available (null pointer check). */
    boolean aclUndefined = (RightsM_BasicAcl == NULL_PTR) ? TRUE : FALSE;
    retVal = RightsM_GenericConditionCheckRead(aclUndefined, RTE_E_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_E_NOT_OK, ErrorCode);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data15ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data15ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_Basic_ACL_Version_Generation_Time_GTC_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Copy the date and time string of the access control list to the output buffer. */
    retVal = RightsM_CopyOrClear(Data, RightsM_BasicAcl, RIGHTSM_ACCESSRIGHTS_OFFSET_EXPORT_DATE_TIME, RIGHTSM_ACCESSRIGHTS_SIZEOF_EXPORT_DATE_TIME);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0185_ECU_individual_ACL_Hash>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Hash_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Hash_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
 /* PRQA S 3673 10 */ /* MD_SSA_PARAM_NOT_P2CONST */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_ECU_individual_ACL_Hash_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Always successfully return since there might be no ECU individual ACL. */
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  SSA_DUMMY_STATEMENT(ErrorCode);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0185_ECU_individual_ACL_Hash>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data64ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Hash_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Hash_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data64ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Hash_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_ECU_individual_ACL_Hash_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 If there is an ECU individual ACL copy the hash of the access control list to the provided output buffer. */
    retVal = RightsM_CopyOrClear(Data, RightsM_EcuIndividualAcl, RIGHTSM_ACCESSRIGHTS_OFFSET_HASH, SSA_SIZEOF_HASHVALUE);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
 /* PRQA S 3673 10 */ /* MD_SSA_PARAM_NOT_P2CONST */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Always successfully return since there might be no ECU individual ACL. */
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  SSA_DUMMY_STATEMENT(ErrorCode);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data1ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Major_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 If there is an ECU individual ACL write the major version encoded as a 2-digit decimal to the first byte of the output buffer. */
    retVal = RightsM_CopyOrClear(Data, RightsM_EcuIndividualAcl, RIGHTSM_ACCESSRIGHTS_OFFSET_LABEL_REV_HISTORY_CDD, 1u);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
 /* PRQA S 3673 10 */ /* MD_SSA_PARAM_NOT_P2CONST */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Always successfully return since there might be no ECU individual ACL. */
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  SSA_DUMMY_STATEMENT(ErrorCode);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data1ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Minor_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 If there is an ECU individual ACL write the minor version encoded as a 2-digit decimal to the first byte of the output buffer. */
    retVal = RightsM_CopyOrClear(Data, RightsM_EcuIndividualAcl, RIGHTSM_ACCESSRIGHTS_OFFSET_LABEL_REV_HISTORY_CDD + 3u, 1u);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
 /* PRQA S 3673 10 */ /* MD_SSA_PARAM_NOT_P2CONST */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Always successfully return since there might be no ECU individual ACL. */
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  SSA_DUMMY_STATEMENT(ErrorCode);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data1ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Candela_File_Version_Patch_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 If there is an ECU individual ACL write the patch version encoded as a 2-digit decimal to the first byte of the output buffer. */
    retVal = RightsM_CopyOrClear(Data, RightsM_EcuIndividualAcl, RIGHTSM_ACCESSRIGHTS_OFFSET_LABEL_REV_HISTORY_CDD + 6u, 1u);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
 /* PRQA S 3673 10 */ /* MD_SSA_PARAM_NOT_P2CONST */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Always successfully return since there might be no ECU individual ACL. */
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  SSA_DUMMY_STATEMENT(ErrorCode);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data15ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data15ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0185_ECU_individual_ACL_Version_Generation_Time_GTC_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 If there is an ECU individual ACL copy the date and time string of the access control list to the output buffer. */
    retVal = RightsM_CopyOrClear(Data, RightsM_EcuIndividualAcl, RIGHTSM_ACCESSRIGHTS_OFFSET_EXPORT_DATE_TIME, RIGHTSM_ACCESSRIGHTS_SIZEOF_EXPORT_DATE_TIME);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_018C_Cebas_UserRole>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_018C_Cebas_UserRole_DCM_E_PENDING
 *   RTE_E_DataServices_DID_018C_Cebas_UserRole_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
 /* PRQA S 3673 10 */ /* MD_SSA_PARAM_NOT_P2CONST */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_018C_Cebas_UserRole_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Nothing to do. Always return successfully. */
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  SSA_DUMMY_STATEMENT(ErrorCode);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_018C_Cebas_UserRole>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_018C_Cebas_UserRole_DCM_E_PENDING
 *   RTE_E_DataServices_DID_018C_Cebas_UserRole_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data1ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_DID_018C_Cebas_UserRole_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_018C_Cebas_UserRole_E_NOT_OK;
  uint8 currentDiagChanId;

  /* Keep diagnostic channel ID in a local buffer so it can't be modified in a different context. */
  currentDiagChanId = RightsM_CurrentDiagChanId;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Check if the current diagnostic channel ID is valid. */
    if (!RightsM_IsDiagChanValid(currentDiagChanId))
    {
      /* retVal already set */
    }
    else
    {
      retVal = RTE_E_OK;
      /* #20 If channel is in unauthenticated state pass 0 else pass the current diagnostic
       *     user-role to the out buffer. */
      Rte_Enter_RightsM_ExclusiveArea();
      if (RightsM_DiagChannelData[currentDiagChanId].authentication_State == RIGHTSM_CHANNEL_NOT_AUTHENTICATED)
      {
        Data[0] = CERTP_PKI_ROLE_INVALID;
      }
      else
      {
        Data[0] = RightsM_DiagChannelData[currentDiagChanId].securitySettings.diagnosticUserRole;
      }
      Rte_Exit_RightsM_ExclusiveArea();
    }
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Check if the current diagnostic channel id is valid. */
    /* one atomic read access */
    boolean diagChannelInvalid = (!RightsM_IsDiagChanValid(RightsM_CurrentDiagChanId)) ? TRUE : FALSE;
    retVal = RightsM_GenericConditionCheckRead(diagChannelInvalid, RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_E_NOT_OK, ErrorCode);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_KeyM_Certificate_GetBackendSubject(uint8 *backendSubject, uint16 *dataLength)
 *     Argument backendSubject: uint8* is of type Ssa_Data30ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_KeyM_Certificate_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data15ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ReadData_doc
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
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data15ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Issuer_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    retVal = RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_E_NOT_OK;
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 byteIdx;
    uint8 currentDiagChanId;

    /* Keep diagnostic channel ID in a local buffer so it can't be modified in a different context. */
    currentDiagChanId = RightsM_CurrentDiagChanId;

    /* #5 Set all data elements to zero (padding). */
    for (byteIdx = 0u; byteIdx < SSA_SIZEOF_ISSUER; byteIdx++)
    {
      Data[byteIdx] = 0x00u;
    }

    /* #10 Check if the current diagnostic channel ID is valid. */
    if (!RightsM_IsDiagChanValid(currentDiagChanId))
    {
      *Data = 0u; /* return empty string */
      retVal = RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_E_NOT_OK;
    }
    /* #20 If the current diagnostic user oder tester is locally authenticated return the issuer of the tester certificate (SSA-IS-1145). */
    else if (RightsM_DiagChannelData[currentDiagChanId].authentication_State == RIGHTSM_CHANNEL_LOCALLY_AUTHENTICATED)
    {
      Rte_Enter_RightsM_ExclusiveArea();
      /* Return tester issuer field */
      for (byteIdx = 0u; byteIdx < SSA_SIZEOF_ISSUER; byteIdx++)
      {
        Data[byteIdx] = RightsM_DiagChannelData[currentDiagChanId].securitySettings.testerIssuer[byteIdx];
      }
      Rte_Exit_RightsM_ExclusiveArea();
    }
    /* #30 Else return the subject of the backend certificate. */
    else
    {
      /* #35 Before writing backend subject set all data elements to zero (padding). */
      Ssa_Data30ByteType backendSubject = { 0u };
      uint16 lengthBackendSubject = sizeof(Ssa_Data30ByteType);
      /* call RTE interface with matching buffer size */
      retVal = Rte_Call_KeyM_Certificate_GetBackendSubject(backendSubject, &lengthBackendSubject);
      if (retVal != RTE_E_OK)
      {
        /* return empty string */
        retVal = RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Issuer_E_NOT_OK;
      }
      else
      {
        /* Copy also possible trailing zeroes if subject length < SSA_SIZEOF_ISSUER.
           Copying is ok since SSA_SIZEOF_ISSUER < sizeof(Ssa_Data30ByteType). */
        Ssa_MemCpy(Data, backendSubject, SSA_SIZEOF_ISSUER);
      }
    }
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Check if the current diagnostic channel id is valid. */
    /* one atomic read access */
    boolean diagChannelInvalid = (!RightsM_IsDiagChanValid(RightsM_CurrentDiagChanId)) ? TRUE : FALSE;
    retVal = RightsM_GenericConditionCheckRead(diagChannelInvalid, RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_E_NOT_OK, ErrorCode);
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data16ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data16ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    retVal = RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_E_NOT_OK;
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 byteIdx;
    uint8 currentDiagChanId;

    /* Keep diagnostic channel ID in a local buffer so it can't be modified in a different context. */
    currentDiagChanId = RightsM_CurrentDiagChanId;

    /* #10 Check if the current diagnostic channel ID is valid. */
    if (!RightsM_IsDiagChanValid(currentDiagChanId))
    {
      Data[0] = 0xFFu;
      retVal = RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_E_NOT_OK;
    }
    /* #20 If the current diagnostic user oder tester is not authenticated return 0xFF. */
    else if (RightsM_DiagChannelData[currentDiagChanId].authentication_State == RIGHTSM_CHANNEL_NOT_AUTHENTICATED)
    {
      Data[0] = 0xFFu;
      retVal = RTE_E_OK;
    }
    /* #30 If the current diagnostic user oder tester is authenticated return the tester serial number. */
    else
    {
      /* Return tester serial number */
      Rte_Enter_RightsM_ExclusiveArea();
      for (byteIdx = 0u; byteIdx < SSA_SIZEOF_SERIALNUMBER; byteIdx++)
      {
        Data[byteIdx] = RightsM_DiagChannelData[currentDiagChanId].securitySettings.testerSerialNumber[byteIdx];
      }
      Rte_Exit_RightsM_ExclusiveArea();
    }
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_DCM_E_PENDING
 *   RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadDataLength_doc
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

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Serial_Number_ReadDataLength (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (DataLength == NULL_PTR)
  {
    retVal = RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_E_NOT_OK;
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 currentDiagChanId;

    /* Keep diagnostic channel ID in a local buffer so it can't be modified in a different context. */
    currentDiagChanId = RightsM_CurrentDiagChanId;

    /* #10 Check if the current diagnostic channel ID is valid. */
    if (!RightsM_IsDiagChanValid(currentDiagChanId))
    {
      retVal = RTE_E_DataServices_Diagnostic_Authentication_Certificate_Identification_Read_Diagnostic_Authentication_Certificate_Serial_Number_E_NOT_OK;
    }
    /* #20 If the current diagnostic user oder tester is not authenticated return length 1. */
    else if (RightsM_DiagChannelData[currentDiagChanId].authentication_State == RIGHTSM_CHANNEL_NOT_AUTHENTICATED)
    {
      *DataLength = 1u;
    }
    /* #30 If the current diagnostic user oder tester is authenticated return the length of the serial number. */
    else
    {
      *DataLength = SSA_SIZEOF_SERIALNUMBER;
    }
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DiagnosticChannel_GetDiagChanAndAuthenticationState
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDiagChanAndAuthStatus> of PortPrototype <RightsM_DiagnosticChannel>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DiagnosticChannel_GetDiagChanAndAuthenticationState(uint8 *diagChanAndAuthStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RightsM_DiagnosticChannel_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DiagnosticChannel_GetDiagChanAndAuthenticationState_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DiagnosticChannel_GetDiagChanAndAuthenticationState(P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) diagChanAndAuthStatus) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DiagnosticChannel_GetDiagChanAndAuthenticationState (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RightsM_DiagnosticChannel_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (diagChanAndAuthStatus == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Read the diagnostic channel and the authentication state. */
    *diagChanAndAuthStatus = RightsM_GetDiagChanAndAuthenticationState();
    retVal = RTE_E_OK;
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRole
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDiagnosticUserRole> of PortPrototype <RightsM_DiagnosticChannel>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRole(RightsM_DiagnosticUserRoleType *userRole)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RightsM_DiagnosticChannel_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRole_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRole(P2VAR(RightsM_DiagnosticUserRoleType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) userRole) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRole (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RightsM_DiagnosticChannel_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (userRole == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 currentDiagChanId;

    /* Keep diagnostic channel ID in a local buffer so it can't be modified in a different context. */
    currentDiagChanId = RightsM_CurrentDiagChanId;

    Rte_Enter_RightsM_ExclusiveArea();

    /* #10 If the diagnostic channel is valid and authenticated get the diagnostic user role. */
    /* be less susceptible to memory manipulations: do not check for not equal to zero */
    if (RightsM_IsDiagChanValid(currentDiagChanId)
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
      && (RightsM_DiagChannelData[currentDiagChanId].authentication_State == RIGHTSM_CHANNEL_LOCALLY_AUTHENTICATED))
#else
      && ((RightsM_DiagChannelData[currentDiagChanId].authentication_State == RIGHTSM_CHANNEL_LOCALLY_AUTHENTICATED) || (RightsM_DiagChannelData[currentDiagChanId].authentication_State == RIGHTSM_CHANNEL_CENTRALLY_AUTHENTICATED)))
#endif
    {
      *userRole = RightsM_DiagChannelData[currentDiagChanId].securitySettings.diagnosticUserRole;
    }
    else
    {
      /* #15 Else set user role to ANYBODY. */
      *userRole = RIGHTSM_USERROLE_ANYBODY;
    }

    Rte_Exit_RightsM_ExclusiveArea();

    retVal = RTE_E_OK;
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRolesBitMask
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDiagnosticUserRolesBitMask> of PortPrototype <RightsM_DiagnosticChannel>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRolesBitMask(RightsM_ACL_BitMaskType *userRolesBitMask)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RightsM_DiagnosticChannel_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRolesBitMask_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRolesBitMask(P2VAR(RightsM_ACL_BitMaskType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) userRolesBitMask) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DiagnosticChannel_GetDiagnosticUserRolesBitMask (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RightsM_DiagnosticChannel_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (userRolesBitMask == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 diagChan;

    /* #10 Set default bit mask to zero. */
    *userRolesBitMask = 0uL;

    Rte_Enter_RightsM_ExclusiveArea();

    /* #20 Iterate over all diagnostic channels and create bit mask. */
    for (diagChan = 0u; diagChan < SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS; ++diagChan)
    {
      *userRolesBitMask |= (1uL << RightsM_DiagChannelData[diagChan].securitySettings.diagnosticUserRole);
    }

    Rte_Exit_RightsM_ExclusiveArea();

    retVal = RTE_E_OK;
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DiagnosticChannel_GetPostProductionStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetPostProductionStatus> of PortPrototype <RightsM_DiagnosticChannel>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DiagnosticChannel_GetPostProductionStatus(Ssa_PostProductionStatusType *status)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RightsM_DiagnosticChannel_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DiagnosticChannel_GetPostProductionStatus_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DiagnosticChannel_GetPostProductionStatus(P2VAR(Ssa_PostProductionStatusType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) status) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DiagnosticChannel_GetPostProductionStatus (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RightsM_DiagnosticChannel_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (status == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Pass central authentication status for user role production from RAM to out buffer. */
    /* atomic read access */
    *status = *Rte_Pim_RightsMPostProductionStatus();
    retVal = RTE_E_OK;
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DiagnosticFirewall_GetDiagnosticUserRole
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetDiagnosticUserRole> of PortPrototype <RightsM_DiagnosticFirewall>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DiagnosticFirewall_GetDiagnosticUserRole(uint16 SourceAddress, RightsM_DiagnosticUserRoleType *UserRole)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RightsM_DiagnosticFirewall_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DiagnosticFirewall_GetDiagnosticUserRole_doc
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

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DiagnosticFirewall_GetDiagnosticUserRole(uint16 SourceAddress, P2VAR(RightsM_DiagnosticUserRoleType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) UserRole) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DiagnosticFirewall_GetDiagnosticUserRole (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RightsM_DiagnosticFirewall_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (UserRole == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Initially identify the diagnostic channel from the source address. */
     uint8 diagnosticChannel = RightsM_GetDiagChanIdFromSourceAddress(SourceAddress);

    Rte_Enter_RightsM_ExclusiveArea();

    /* be less susceptible to memory manipulations: do not check for not equal to zero */
    if (RightsM_IsDiagChanValid(diagnosticChannel)
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
      && (RightsM_DiagChannelData[diagnosticChannel].authentication_State == RIGHTSM_CHANNEL_LOCALLY_AUTHENTICATED))
#else
      && ((RightsM_DiagChannelData[diagnosticChannel].authentication_State == RIGHTSM_CHANNEL_LOCALLY_AUTHENTICATED) || (RightsM_DiagChannelData[diagnosticChannel].authentication_State == RIGHTSM_CHANNEL_CENTRALLY_AUTHENTICATED)))
#endif
    {
      /* #20 If the diagnostic channel is valid and authenticated get the diagnostic user role. */
      *UserRole = RightsM_DiagChannelData[diagnosticChannel].securitySettings.diagnosticUserRole;
    }
    else
    {
      /* #25 Else set user role to ANYBODY. */
      *UserRole = RIGHTSM_USERROLE_ANYBODY;
    }

    Rte_Exit_RightsM_ExclusiveArea();

    retVal = RTE_E_OK;
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DiagnosticFirewall_IsEnhancedAccessRightGranted
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <IsEnhancedAccessRightGranted> of PortPrototype <RightsM_DiagnosticFirewall>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_DiagnosticFirewall_IsEnhancedAccessRightGranted(uint16 SourceAddress, uint8 SID, boolean *AccessRightGranted)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RightsM_DiagnosticFirewall_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DiagnosticFirewall_IsEnhancedAccessRightGranted_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_DiagnosticFirewall_IsEnhancedAccessRightGranted(uint16 SourceAddress, uint8 SID, P2VAR(boolean, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) AccessRightGranted) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DiagnosticFirewall_IsEnhancedAccessRightGranted (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RightsM_DiagnosticFirewall_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (AccessRightGranted == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 diagnosticChannel;
    *AccessRightGranted = FALSE;

    /* #10 Initially identify the diagnostic channel from the source address. */
    diagnosticChannel = RightsM_GetDiagChanIdFromSourceAddress(SourceAddress);

    if (RightsM_IsDiagChanValid(diagnosticChannel))
    {
      /* #20 Check whether enhanced access right has been granted. */
      *AccessRightGranted = RightsM_IsEnhancedAccessRightGranted(diagnosticChannel, SID, 0xFFu, 0xFFFFu, RIGHTSM_CHECK_SID_ONLY);
    }
    retVal = RTE_E_OK;
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_DiagnosticSessionChangeIndication
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on entering of Mode <DEFAULT_SESSION> of ModeDeclarationGroupPrototype <DcmDiagnosticSessionControl> of PortPrototype <DcmDiagnosticSessionControl>
 *   - triggered on entering of Mode <EXTENDED_SESSION> of ModeDeclarationGroupPrototype <DcmDiagnosticSessionControl> of PortPrototype <DcmDiagnosticSessionControl>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_RightsM_SecurityLevelChange_currentLevel(uint8 data)
 *
 * Mode Interfaces:
 * ================
 *   Dcm_DiagnosticSessionControlType Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType *previousMode, Dcm_DiagnosticSessionControlType *nextMode)
 *   Modes of Rte_ModeType_DcmDiagnosticSessionControl:
 *   - RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_SafetySystem
 *   - RTE_TRANSITION_DcmDiagnosticSessionControl
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DiagnosticSessionChangeIndication_doc
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
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_RightsM_CODE) Ssa_RightsM_DiagnosticSessionChangeIndication(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_DiagnosticSessionChangeIndication
 *********************************************************************************************************************/
  uint8 previousMode = RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION;
  uint8 nextMode = RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION;
  uint8 diagChan;
  boolean defaultSessionRequestedByAnyUser = FALSE;

  /* #10 Read previous diagnostic session control mode. */
  (void)Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(&previousMode, &nextMode);

  /* #15 Filter for a change to the "extended session" and store the ID of the diagnostic channel that
   *     requested for extended session. There can be only one channel in extended session. */
  if ((previousMode != RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION) && (nextMode == RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION))
  {
    Rte_Enter_RightsM_ExclusiveArea();
    RightsM_ExtSessionDiagChanId = RightsM_ExtSessionDiagChanId_Requested;
    RightsM_ExtSessionDiagChanId_Requested = SSA_RIGHTSM_DIAG_INVALID_CHAN_ID;
    Rte_Exit_RightsM_ExclusiveArea();
  }
  else
  {
    /* #20 Else check that the previous mode is not the "default session". */
    if ((previousMode != RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION) && (nextMode == RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION))
    {
      (void)Rte_Write_RightsM_SecurityLevelChange_currentLevel(0x00u);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */

      Rte_Enter_RightsM_ExclusiveArea();
      /* #25 Check if there is at least one user that has requested for "Default Session" */
      for (diagChan = 0u; diagChan < SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS; ++diagChan)
      {
        if (RightsM_DiagChannelData[diagChan].defaultSessionRequestFlag)
        {
          defaultSessionRequestedByAnyUser = TRUE;
          break;
        }
      }

      if (RightsM_IsDiagChanValid(RightsM_ExtSessionDiagChanId) && (!defaultSessionRequestedByAnyUser))
      {
        /* #40 If locally authenticated and currently in a non-default diagnostic session leave the Authenticated State
         * for the corresponding Diagnostic Channel when a S3 timeout occurs (i.e. simultaneously with the ECU falling
         * back to defaultSession). */
        if (RightsM_DiagChannelData[RightsM_ExtSessionDiagChanId].authentication_State == RIGHTSM_CHANNEL_LOCALLY_AUTHENTICATED)
        {
          /* #50 By setting the authentication timeout timer to 1, the authenticated state will be left in next RightsM_MainFunction. */
          RightsM_DiagChannelData[RightsM_ExtSessionDiagChanId].authenticationTimeoutTimer = 1u;
        }
      }
      Rte_Exit_RightsM_ExclusiveArea();
    }

    Rte_Enter_RightsM_ExclusiveArea();
    /* #70 Always clear the default session requested flags- */
    for (diagChan = 0u; diagChan < SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS; ++diagChan)
    {
      RightsM_DiagChannelData[diagChan].defaultSessionRequestFlag = FALSE;
    }
    Rte_Exit_RightsM_ExclusiveArea();
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_EnhancedRights_VerifySubjectKeyIdentifier
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <VerifySubjectKeyIdentifier> of PortPrototype <RightsM_EnhancedRights>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_EnhancedRights_VerifySubjectKeyIdentifier(const uint8 *subjectKeyIdentifier)
 *     Argument subjectKeyIdentifier: uint8* is of type Ssa_Data20ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RightsM_EnhancedRights_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_EnhancedRights_VerifySubjectKeyIdentifier_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_EnhancedRights_VerifySubjectKeyIdentifier(P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) subjectKeyIdentifier) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_EnhancedRights_VerifySubjectKeyIdentifier (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RightsM_EnhancedRights_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (subjectKeyIdentifier == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    Rte_Enter_RightsM_ExclusiveArea();

    /* #10 Check if there is a temporarily stored target subject key identifier. */
    if (RightsM_TargetSubjectKeyIdentifierValid == TRUE)
    {
      /* #20 Compare the given subject key identifier with the temporarily stored one. */
      if (RightsM_CompareData(subjectKeyIdentifier, (P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))RightsM_TargetSubjectKeyIdentifier, SSA_SIZEOF_CERT_SUBJECT_KEY_ID) == TRUE)
      {
        retVal = RTE_E_OK;
      }
    }

    Rte_Exit_RightsM_ExclusiveArea();
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_Authentication_Mode(RightsM_AuthenticationModeType mode)
 *   Modes of Rte_ModeType_RightsM_AuthenticationMode:
 *   - RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_AUTHENTICATED
 *   - RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_UNAUTHENTICATED
 *   - RTE_TRANSITION_RightsM_AuthenticationMode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SecLog_EcuIndividualAclReplacementEvent_EcuIndividualAclReplacement(const uint8 *newAclVersion, uint8 compatibility)
 *     Argument newAclVersion: uint8* is of type SecLog_AclVersionType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_EcuIndividualAclReplacementEvent_E_NOT_OK
 *   Std_ReturnType Rte_Call_SsaCdd_Csm_Hash(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_DataPtr resultBuffer, Ssa_LengthPtr resultLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *   Std_ReturnType Rte_Call_Ssa_RightsM_DiagnosticInformation_Get(uint8 *diagVersion, uint8 *diagVariant)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_Ssa_RightsM_DiagnosticInformation_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DTC_0x9A6857_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_Init_doc
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
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_RightsM_CODE) Ssa_RightsM_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_Init
 *********************************************************************************************************************/
  uint16 idx;
  uint8 entryIdx;
  uint8 diagChan;

  /* #5 Initialize MirrorBlock for status of central authentication. */
  /* Initialize with the value of the respective Ram block at startup, which represents the value of the respective Nvm block.*/
  *Rte_Pim_RightsMPostProductionStatusMirror() = *Rte_Pim_RightsMPostProductionStatus();

  /* #10  Initialize the diagnostic channel data and the enhanced access. */
  RightsM_CurrentDiagChanId = SSA_RIGHTSM_DIAG_INVALID_CHAN_ID;
  RightsM_ExtSessionDiagChanId = SSA_RIGHTSM_DIAG_INVALID_CHAN_ID;
  RightsM_ExtSessionDiagChanId_Requested = SSA_RIGHTSM_DIAG_INVALID_CHAN_ID;
  RightsM_ChannelIdOfLastSuccessfulSecurityAccess = SSA_RIGHTSM_DIAG_INVALID_CHAN_ID;
  RightsM_CurrentDiagnosticChannel = SSA_RIGHTSM_DIAG_INVALID_CHANNEL;
  /* The initial value is never used. Nevertheless use a valid value here. */
  RightsM_CurrentDiagChanId_Service = 0;

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
  RightsM_AuthenticationBroadcastTimer = 0u;
  RightsM_DiagChanLastSentId = SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS;
#endif
  RightsM_TargetSubjectKeyIdentifierValid = FALSE;

  /* #20 Iterate over all diagnostic channels. */
  for (diagChan = 0u; diagChan < SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS; ++diagChan)
  {
    /* #30 Reset all diagnostic channel data. */
    RightsM_DiagChannelData[diagChan].currentDiagnosticChannel = SSA_RIGHTSM_DIAG_INVALID_CHANNEL;

    RightsM_DiagChannelData[diagChan].authentication_State = RIGHTSM_CHANNEL_NOT_AUTHENTICATED;
    RightsM_DiagChannelData[diagChan].securitySettings.restrictedAuthentication = TRUE;
    RightsM_DiagChannelData[diagChan].authentication_ExpectedTask = 0x00u;

    RightsM_DiagChannelData[diagChan].authenticationTimeoutTimer = 0u;

    RightsM_DiagChannelData[diagChan].defaultSessionRequestFlag = FALSE;

    /* #35 Reset the security settings. */
    RightsM_DiagChannelData[diagChan].securitySettings.diagnosticUserRole = 0x00u;
    RightsM_SetDataBuffer(0xFFu, RightsM_DiagChannelData[diagChan].securitySettings.testerSerialNumber, SSA_SIZEOF_SERIALNUMBER);
    RightsM_SetDataBuffer(0x00u, RightsM_DiagChannelData[diagChan].securitySettings.testerIssuer, SSA_SIZEOF_ISSUER);
    RightsM_SetDataBuffer(0xFFu, RightsM_DiagChannelData[diagChan].securitySettings.testerPublicKey, SSA_SIZEOF_PUBLICKEY);
  }
  /* #40 Initialize/reset the enhanced access control list. */
  for (idx = 0u; idx < RIGHTSM_ENHANCED_ACCESS_RIGHTS_TABLE_NUM_ENTRIES; idx++)
  {
    for (entryIdx = 0u; entryIdx < RIGHTSM_ENHANCED_ACCESS_ENTRY_SIZE; entryIdx++)
    {
      RightsM_EnhancedAccessRights[idx][entryIdx] = 0u;
    }
  }

  /* #60 Clear temporary security settings and workspace for asynchronous CSM handling. */
  for (diagChan = 0u; diagChan < SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS; ++diagChan)
  {
    RightsM_ClearPreliminarySecuritySettings(diagChan);
  }
  RightsM_Workspace.procState = CSM_ASYNC_IDLE;

  RightsM_RandomGenerateAsyncState = SSA_ASYNC_STATE_IDLE;
  RightsM_CsmSignatureVerifyAsyncState = SSA_ASYNC_STATE_IDLE;
  RightsM_CsmVerificationResult = CRYPTO_E_VER_NOT_OK;

  RightsM_Nonce_Get_State = RIGHTSM_ASYNC_STATE_IDLE;
  RightsM_Nonce_Destroy_State = RIGHTSM_ASYNC_STATE_IDLE;

#if (SSA_SECURITYACCESSLEVEL == STD_ON)
  RightsM_CompareKeyAsyncState = SSA_ASYNC_STATE_IDLE;
#endif

  RightsM_CurrentTickCount = 0uLL;

  RightsM_ServiceToFilterFor = RIGHTSM_SECLOG_BY_INDICATION_NONE;
  RightsM_ServiceToFilterForData = 0xFFu;

#if (SSA_SECURITYACCESSLEVEL == STD_ON)
  for (idx = 0u; idx < SSA_RIGHTSM_NUMBER_SECURITY_ACCESS_LEVELS; idx++)
  {
    RightsM_SecAccessIsSeeded[idx] = FALSE;
  }
#endif

  RightsM_AclVersionNvmWriteRequested = FALSE;
  RightsM_AclVersionNvmWriteState = RIGHTSM_NVM_WRITE_STATE_IDLE;
  RightsM_WritePostProductionStatus_State = RIGHTSM_NVM_WRITE_STATE_IDLE;

  /* #70 Validate the access control lists and check variant and version. */
  RightsM_CheckAccessControlLists();

#if (SSA_ENABLE_DEBUG_AUTHENTICATION_STATUS == STD_ON)          /* COV_SSA_DEBUG XF */
  Rte_Switch_Authentication_Mode(RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_AUTHENTICATED);
#endif

  /* Ensure type sizes once for the RightsM submodule which calls RTE APIs expecting these data types:
   * Csm_RandomGenerateResultType_Random must be an array with 32 element(s) of type uint8
   * Ssa_Data2ByteType must be an array with 2 element(s) of type uint8
   * Ssa_Data30ByteType must be an array with 30 element(s) of type uint8
   * RightsM_AuthenticationBroadcastType must be an array with 20 element(s) of type uint8 */

  /*@ assert sizeof(Csm_RandomGenerateResultType_Random) == 32; */
  /*@ assert sizeof(Ssa_Data2ByteType) == 2; */
  /*@ assert sizeof(Ssa_Data30ByteType) == 30; */
  /*@ assert sizeof(RightsM_AuthenticationBroadcastType) == 20; */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Ssa_BusOdometer_DI_Odo_Pr5_ST3(Ssa_OdometerRecordType *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_RightsM_SendAuthenticationBroadcast_authentication(const uint8 *data)
 *     Argument data: uint8* is of type RightsM_AuthenticationBroadcastType
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_Authentication_Mode(RightsM_AuthenticationModeType mode)
 *   Modes of Rte_ModeType_RightsM_AuthenticationMode:
 *   - RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_AUTHENTICATED
 *   - RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_UNAUTHENTICATED
 *   - RTE_TRANSITION_RightsM_AuthenticationMode
 *   Dcm_DiagnosticSessionControlType Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(Dcm_DiagnosticSessionControlType *previousMode, Dcm_DiagnosticSessionControlType *nextMode)
 *   Modes of Rte_ModeType_DcmDiagnosticSessionControl:
 *   - RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_EXTENDED_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_PROGRAMMING_SESSION
 *   - RTE_MODE_DcmDiagnosticSessionControl_SafetySystem
 *   - RTE_TRANSITION_DcmDiagnosticSessionControl
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_KeyM_Certificate_GetBackendSerialNumber(uint8 *serialNumber, uint16 *serialNumberLength)
 *     Argument serialNumber: uint8* is of type Ssa_Data2ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_KeyM_Certificate_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_RightsM_AclVersion_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_RightsM_AclVersion_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_RightsM_Nonce_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_RightsM_Nonce_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_MainFunction_doc
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
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_RightsM_CODE) Ssa_RightsM_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_MainFunction
 *********************************************************************************************************************/
  uint8 diagChan;

  /* #10 Handle authentication timeout. For that iterate over all diagnostic channels. */
  Rte_Enter_RightsM_ExclusiveArea();
  for (diagChan = 0u; diagChan < (uint8)SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS; ++diagChan) /* FETA_SSA_RIGHTSM_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
  {
    /* #20 Check if the timeout timer is active. */
    if (RightsM_DiagChannelData[diagChan].authenticationTimeoutTimer != 0u)
    {
      RightsM_DiagChannelData[diagChan].authenticationTimeoutTimer--;

      /* #30 Check if timeout timer elapsed. */
      if (RightsM_DiagChannelData[diagChan].authenticationTimeoutTimer == 0u)
      {
        uint8 previousMode;
        uint8 nextMode;
        Rte_Exit_RightsM_ExclusiveArea();

        /* #40 Read the previous and the next mode of the diagnostic session control. */
        (void)Rte_Mode_DcmDiagnosticSessionControl_DcmDiagnosticSessionControl(&previousMode, &nextMode);

        Rte_Enter_RightsM_ExclusiveArea();
        /* #50 If new mode is "default session" or if the diagnostic user or tester is centrally authenticated: */
        if ((nextMode == RTE_MODE_DcmDiagnosticSessionControl_DEFAULT_SESSION) || (RightsM_DiagChannelData[diagChan].authentication_State == RIGHTSM_CHANNEL_CENTRALLY_AUTHENTICATED))
        {
          /* #60 De-authenticate. */
          RightsM_DeAuthenticate(diagChan);

          Rte_Exit_RightsM_ExclusiveArea();

          /* #62 Switch global authenticate mode to "not authenticated" if there is no authenticated diagnostic user or tester left. */
          RightsM_DeAuthenticateGlobalMode();
          Rte_Enter_RightsM_ExclusiveArea();
        }
        /* #70 Else (ECU is in a non default session and not centrally authenticated): */
        else
        {
          /* #80 Restart authentication timeout. */
          RightsM_DiagChannelData[diagChan].authenticationTimeoutTimer = SSA_RIGHTSM_AUTHENTICATION_TIMEOUT;
        }
      }
    }
  }

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
  /* #100 If ECU type is VSM send the authentication broadcast message. */

  /* #110 Check if authentication broadcast timer (needed for the periodic broadcast) is active and if authentication is not restricted to this ECU. */
  if (RightsM_AuthenticationBroadcastTimer != 0u)
  {
    RightsM_AuthenticationBroadcastTimer--;
    /* #120 If authentication broadcast timer elapsed: */
    if (RightsM_AuthenticationBroadcastTimer == 0u)
    {
      /* #125 Restart the timer. */
      RightsM_AuthenticationBroadcastTimer = SSA_RIGHTSM_AUTHENTICATION_BROADCAST_CYCLE_TIME;

      /* #130 Find the next diagnostic channel whose turn it is to sent. */
      if (RightsM_GetNextDiagChannelToSend(&diagChan) == TRUE)
      {
        Std_ReturnType rVal;
        RightsM_AuthenticationBroadcastType authBcData;
        uint16 dataLength = SSA_SIZEOF_BACKEND_SERIALNUMBER;

        /* #132 Fill in the authentication broadcast message with diagnostic channel, user role and serial number. */
        authBcData[0] = RightsM_DiagChannelData[diagChan].currentDiagnosticChannel;
        authBcData[1] = RightsM_DiagChannelData[diagChan].securitySettings.diagnosticUserRole;
        Ssa_MemCpy((P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR))&(authBcData[2]), (P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))RightsM_DiagChannelData[diagChan].securitySettings.testerSerialNumber, SSA_SIZEOF_SERIALNUMBER);

        Rte_Exit_RightsM_ExclusiveArea();
        /* #134 Fill in the authentication broadcast message with the backend certificate serial number. */
        rVal = Rte_Call_KeyM_Certificate_GetBackendSerialNumber(&(authBcData[2u + SSA_SIZEOF_SERIALNUMBER]), &dataLength);

        /* #136 Send the authentication broadcast message. */
        if ((rVal == E_OK) && (dataLength == SSA_SIZEOF_BACKEND_SERIALNUMBER))
        {
          (void)Rte_Write_RightsM_SendAuthenticationBroadcast_authentication(authBcData);
        }

        RightsM_DiagChanLastSentId = diagChan;

        Rte_Enter_RightsM_ExclusiveArea();
      }
    }
  }
#endif

  Rte_Exit_RightsM_ExclusiveArea();

  /* #140 Check if writing the Rights NVRam block has been requested. */
  RightsM_HandleNvm();

  /* #150 Check mileage to adapt the rights for central authentication for user role production. */
  RightsM_CheckMileage();

  /* PRQA S 6050, 6080 4 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_Nonce_Destroy
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Destroy> of PortPrototype <RightsM_Nonce>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CsmRandomGenerate_RandomGenerate(uint8 *resultBuffer, uint32 *resultLength)
 *     Argument resultBuffer: uint8* is of type Csm_RandomGenerateResultType_Random
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmRandomGenerate_Random_CSM_E_BUSY, RTE_E_CsmRandomGenerate_Random_CSM_E_ENTROPY_EXHAUSTION, RTE_E_CsmRandomGenerate_Random_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_Nonce_Destroy(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RightsM_Nonce_E_NOT_OK
 *   RTE_E_RightsM_Nonce_E_PENDING
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_Nonce_Destroy_doc
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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_Nonce_Destroy(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_Nonce_Destroy (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RightsM_Nonce_E_PENDING;

  if (RightsM_Nonce_Destroy_State == RIGHTSM_ASYNC_STATE_IDLE)
  {
    /* #10 Overwrite the current nonce in NVRam block with zeroes. */
    CONST(uint8, AUTOMATIC) nonceDummy[SSA_SIZEOF_NONCE] = { 0u };

    Rte_Enter_RightsM_ExclusiveArea();
    if (Rte_Pim_RightsMNonce()->isValid == TRUE)
    {
      /* #20 Invalidate the current nonce. */
      Rte_Pim_RightsMNonce()->isValid = FALSE;
      /* #30 Overwrite nonce in NVRam block. */
      Ssa_MemCpy(Rte_Pim_RightsMNonce()->data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))nonceDummy, SSA_SIZEOF_NONCE);

      /* #35 Copy the RAM block to a RAM block mirror and change to sate.*/
      Ssa_MemCpy(Rte_Pim_RightsMNonceMirror()->data, Rte_Pim_RightsMNonce()->data, SSA_SIZEOF_NONCE);
      Rte_Pim_RightsMNonceMirror()->timestamp = Rte_Pim_RightsMNonce()->timestamp;
      Rte_Pim_RightsMNonceMirror()->isValid = Rte_Pim_RightsMNonce()->isValid;
      Rte_Exit_RightsM_ExclusiveArea();

      /* #40 Change state in order to write the NVRam block. */
      RightsM_Nonce_Destroy_State = RIGHTSM_ASYNC_STATE_NVM_WRITE;
    }
    else
    {
      Rte_Exit_RightsM_ExclusiveArea();
      /* Nonce is not valid. Stay in state. */
      retVal = RTE_E_OK;
    }
  }

  if ((RightsM_Nonce_Destroy_State == RIGHTSM_ASYNC_STATE_NVM_WRITE)
    || (RightsM_Nonce_Destroy_State == RIGHTSM_ASYNC_STATE_NVM_WAIT))
  {
    Std_ReturnType ret;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;

    /* #50 Get status of NVRAM block. */
    ret = Rte_Call_NvMService_RightsM_Nonce_GetErrorStatus(&errorStatus);
    if ((ret == E_OK) && (errorStatus != NVM_REQ_PENDING))
    {
      /* #60 Write NV block if it has been started and do not change back to idle state as long as NVRAM block status is pending . */
      if (RightsM_Nonce_Destroy_State == RIGHTSM_ASYNC_STATE_NVM_WRITE)
      {
        if (Rte_Call_NvMService_RightsM_Nonce_WriteBlock((dtRef_const_VOID)(Rte_Pim_RightsMNonceMirror())) == E_OK) /* PRQA S 0314 */ /* MD_SSA_P2VOID_CAST */
        {
          RightsM_Nonce_Destroy_State = RIGHTSM_ASYNC_STATE_NVM_WAIT;
        }
      }
      /* must be RIGHTSM_ASYNC_STATE_NVM_WAIT */
      else
      {
        RightsM_Nonce_Destroy_State = RIGHTSM_ASYNC_STATE_IDLE;
        if (errorStatus == NVM_REQ_OK)
        {
          retVal = RTE_E_OK;
        }
        else
        {
          /* Storing the cleared nonce in the NvM failed. Return E_NOT_OK. */
          retVal = RTE_E_RightsM_Nonce_E_NOT_OK;
        }
      }
    }
    else
    {
      /* Stay in current state */
    }
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_Nonce_Get
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <RightsM_Nonce>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_TimeM_TickCount_Get(uint64 *tickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_TickCount_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CsmRandomGenerate_RandomGenerate(uint8 *resultBuffer, uint32 *resultLength)
 *     Argument resultBuffer: uint8* is of type Csm_RandomGenerateResultType_Random
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmRandomGenerate_Random_CSM_E_BUSY, RTE_E_CsmRandomGenerate_Random_CSM_E_ENTROPY_EXHAUSTION, RTE_E_CsmRandomGenerate_Random_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_Nonce_Get(boolean generateNew, uint8 *nonce)
 *     Argument nonce: uint8* is of type Dcm_Data32ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RightsM_Nonce_E_INVALID
 *   RTE_E_RightsM_Nonce_E_NOT_OK
 *   RTE_E_RightsM_Nonce_E_PENDING
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_Nonce_Get_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(nonce) >= sizeof(Dcm_Data32ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_Nonce_Get(boolean generateNew, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) nonce) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_Nonce_Get (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (nonce == NULL_PTR)
  {
    retVal = RTE_E_RightsM_Nonce_E_NOT_OK;
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Get nonce. */
    retVal = RightsM_Nonce_Get(generateNew, nonce);
    if (retVal == SSA_E_PENDING)
    {
      retVal = RTE_E_RightsM_Nonce_E_PENDING;
    }
    else if (retVal == SSA_E_INVALID)
    {
      retVal = RTE_E_RightsM_Nonce_E_INVALID;
    }
    else if (retVal != E_OK)
    {
      retVal = RTE_E_RightsM_Nonce_E_NOT_OK;
    }
    else
    {
      retVal = RTE_E_OK;
    }
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester>
 *
 **********************************************************************************************************************
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_Authentication_Mode(RightsM_AuthenticationModeType mode)
 *   Modes of Rte_ModeType_RightsM_AuthenticationMode:
 *   - RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_AUTHENTICATED
 *   - RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_UNAUTHENTICATED
 *   - RTE_TRANSITION_RightsM_AuthenticationMode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CertP_Functions_Certificate_Parse(const uint8 *rawCertData, uint16 rawCertLength, CertP_ParsedCertStructureType *parsedCert)
 *     Argument rawCertData: uint8* is of type CertP_RawCertBufferType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CertP_Functions_E_NOT_OK
 *   Std_ReturnType Rte_Call_KeyM_Certificate_VerifyCertWithBackendCert(const uint8 *cert, CertP_ParsedCertStructureType *parsedCertStructure, uint16 certLength, CertP_PkiRoleType expectedPkiRole, const RightsM_AuthNonceType *expectedNonce)
 *     Argument cert: uint8* is of type CertP_RawCertBufferType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_KeyM_Certificate_E_NOT_OK, RTE_E_KeyM_Certificate_E_PENDING
 *   Std_ReturnType Rte_Call_SecLog_SuccessfulAuthAndEnhanceRights_SuccessfulAuthAndEnhanceRights(uint8 diagChanAuthStatus, CertP_PkiRoleType pkiRole, const uint8 *authenticationContent)
 *     Argument authenticationContent: uint8* is of type SecLog_AuthenticationContentType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_SuccessfulAuthAndEnhanceRights_E_NOT_OK
 *   Std_ReturnType Rte_Call_SsaCdd_Csm_SignatureVerify(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_ConstDataPtr compareBuffer, uint32 compareLength, Ssa_VerifyResultPtr resultBuffer)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *   Std_ReturnType Rte_Call_TimeM_RealTime_Compare(const TimeM_DateTimeType *t1, TimeM_CompareOperatorType compareOp, const TimeM_DateTimeType *t2, boolean *result)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_RealTime_E_NOT_OK
 *   Std_ReturnType Rte_Call_TimeM_RealTime_Get(TimeM_DateTimeType *realTime)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_RealTime_E_NOT_OK
 *   Std_ReturnType Rte_Call_TimeM_RealTime_Set(const TimeM_DateTimeType *realTime, TimeM_RealTimeChangeReasonType changeReason)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_RealTime_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CsmRandomGenerate_RandomGenerate(uint8 *resultBuffer, uint32 *resultLength)
 *     Argument resultBuffer: uint8* is of type Csm_RandomGenerateResultType_Random
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmRandomGenerate_Random_CSM_E_BUSY, RTE_E_CsmRandomGenerate_Random_CSM_E_ENTROPY_EXHAUSTION, RTE_E_CsmRandomGenerate_Random_E_NOT_OK
 *   Std_ReturnType Rte_Call_Key_SignatureRamKey_KeyElementSet(uint32 keyElementId, const uint8 *keyPtr, uint32 keyLength)
 *     Argument keyPtr: uint8* is of type Csm_KeyDataType_Ssa_SignatureRamKey
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_BUSY, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_NOT_AVAILABLE, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_SIZE_MISMATCH, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_KEY_WRITE_FAIL, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_SMALL_BUFFER, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_E_NOT_OK
 *   Std_ReturnType Rte_Call_Key_SignatureRamKey_KeySetValid(void)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_CSM_E_BUSY, RTE_E_CsmKeyManagement_Ssa_SignatureRamKey_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start(uint8 Configuration, uint8 Task, const uint8 *Challenge_Certificate_Proof_of_Ownership, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint8 *Authentication_Result, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Challenge_Certificate_Proof_of_Ownership: uint8* is of type Dcm_Data4004ByteType
 *     Argument Authentication_Result: uint8* is of type Dcm_Data3006ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start_doc
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
/*!
 * \spec
 *    requires $lengthOf(Challenge_Certificate_Proof_of_Ownership) >= sizeof(Dcm_Data4004ByteType);
 *    requires $lengthOf(Authentication_Result) >= sizeof(Dcm_Data3006ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start(uint8 Configuration, uint8 Task, P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Challenge_Certificate_Proof_of_Ownership, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Verification_Result, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Authentication_Result, P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_Start (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ( (Challenge_Certificate_Proof_of_Ownership == NULL_PTR)
    || (routineInfo                              == NULL_PTR)
    || (Verification_Result                      == NULL_PTR)
    || (Authentication_Result                    == NULL_PTR)
    || (DataLength                               == NULL_PTR)
    || (ErrorCode                                == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /*@ assert $lengthOf(Challenge_Certificate_Proof_of_Ownership) >= sizeof(Dcm_Data4004ByteType); */ /* VCA_SSA_RIGHTSM_DATAPROOFOFOWNERSHIP_NOT_NULL */

    /* Using local variables for error code since in- and out- buffer of DCM service might overlap. */
    Dcm_NegativeResponseCodeType errCode = DCM_E_POSITIVERESPONSE;

    /* Keep diagnostic channel ID in an extra buffer that is not changed anymore during execution of this service.
     * Do it only when this function is called initally to make sure that RightsM_CurrentDiagChanId_Service always
     * contains the identifier related to this service execution. */
    if (OpStatus == DCM_INITIAL)
    {
      RightsM_CurrentDiagChanId_Service = RightsM_CurrentDiagChanId;
    }

    /* #10 Check if current diagnostic channel identifier is valid. */
    if (!RightsM_IsDiagChanValid(RightsM_CurrentDiagChanId_Service))
    {
      /* Invalid channel, reject service. ErrorCode is set at the end of the function. */
    }
    else if (OpStatus == DCM_CANCEL)
    {
      errCode = DCM_E_GENERALREJECT;
    }
    /* #20 If task is 0x00 initiate authentication by verifying the certificate (SSA-IS-605). */
    else if (Task == SSA_AUTHENTICATE_INITIATE_AUTH_TASK)
    {
      retVal = RightsM_AuthDiagUserOrTester_HandleTaskAuthenticate(Configuration, Challenge_Certificate_Proof_of_Ownership, Authentication_Result, DataLength, &errCode); /* VCA_SSA_RIGHTSM_DATAPROOFOFOWNERSHIP_NOT_NULL */
    }
    /* #30 If task is 0x01 and if expected task is also 0x01 verify certificate ownership (SSA-IS-614). */
    /* Only handle task 'proof of ownership', if this task is expected. */
    else if ((Task == SSA_AUTHENTICATE_PROOF_OF_OWNERSHIP_TASK) && (RightsM_DiagChannelData[RightsM_CurrentDiagChanId_Service].authentication_ExpectedTask == SSA_AUTHENTICATE_PROOF_OF_OWNERSHIP_TASK))
    {
      retVal = RightsM_AuthDiagUserOrTester_HandleTaskProofOfOwnership(Configuration, Challenge_Certificate_Proof_of_Ownership, OpStatus, Authentication_Result, DataLength, &errCode); /* VCA_SSA_RIGHTSM_DATAPROOFOFOWNERSHIP_NOT_NULL */
    }
    /* #40 If task is 0x02 de-authenticate (SSA-IS-634). */
    else if (Task == SSA_AUTHENTICATE_DEAUTH_TASK)
    {
      /* Discard return value. All information is in verification result. */
      RightsM_AuthDiagUserOrTester_HandleTaskDeauthenticate(&(RightsM_Workspace.verifResult), Authentication_Result, DataLength);
    }
    /* #50 Else send return code E_NOT_OK with NRC "requestSequenceError" (SSA-IS-601). */
    else
    {
      errCode = DCM_E_REQUESTSEQUENCEERROR;
    }

    RightsM_AuthDiagUserOrTester_HandleTaskPostProcessing(&retVal, Task, routineInfo, Verification_Result, Authentication_Result, DataLength, errCode, ErrorCode);
  }

  return retVal;
  /* PRQA S 6060, 6080 4 */ /* MD_SSA_STPAR, MD_MSR_STMIF */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_RoutineServices_Routine_Enhance_Access_Rights_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_Enhance_Access_Rights>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_CertP_Functions_AttributeCertificate_Parse(const uint8 *rawCertData, uint16 rawCertLength, CertP_ParsedCertStructureType *parsedCert)
 *     Argument rawCertData: uint8* is of type CertP_RawCertBufferType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CertP_Functions_E_NOT_OK
 *   Std_ReturnType Rte_Call_KeyM_Certificate_VerifyCertWithBackendCert(const uint8 *cert, CertP_ParsedCertStructureType *parsedCertStructure, uint16 certLength, CertP_PkiRoleType expectedPkiRole, const RightsM_AuthNonceType *expectedNonce)
 *     Argument cert: uint8* is of type CertP_RawCertBufferType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_KeyM_Certificate_E_NOT_OK, RTE_E_KeyM_Certificate_E_PENDING
 *   Std_ReturnType Rte_Call_SecLog_SuccessfulAuthAndEnhanceRights_SuccessfulAuthAndEnhanceRights(uint8 diagChanAuthStatus, CertP_PkiRoleType pkiRole, const uint8 *authenticationContent)
 *     Argument authenticationContent: uint8* is of type SecLog_AuthenticationContentType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_SuccessfulAuthAndEnhanceRights_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_RoutineServices_Routine_Enhance_Access_Rights_Start(const uint8 *Enhanced_Rights_Certificate, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Enhanced_Rights_Certificate: uint8* is of type Dcm_Data2002ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_Enhance_Access_Rights_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_Enhance_Access_Rights_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_Enhance_Access_Rights_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_RoutineServices_Routine_Enhance_Access_Rights_Start_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Enhanced_Rights_Certificate) >= sizeof(Dcm_Data2002ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_RoutineServices_Routine_Enhance_Access_Rights_Start(P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Enhanced_Rights_Certificate, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_RoutineServices_Routine_Enhance_Access_Rights_Start (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Enhance_Access_Rights_E_NOT_OK;
  
  /* Keep diagnostic channel ID in an extra buffer that is not changed anymore during execution of this service.
   * Do it only when this function is called initally to make sure that RightsM_CurrentDiagChanId_Service always
   * contains the identifier related to this service execution. */
  if (OpStatus == DCM_INITIAL)
  {
    RightsM_CurrentDiagChanId_Service = RightsM_CurrentDiagChanId;
  }

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ( (Enhanced_Rights_Certificate == NULL_PTR)
    || (routineInfo == NULL_PTR)
    || (Verification_Result == NULL_PTR)
    || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* Any error code different from DCM_E_POSITIVERESPONSE causes a negative return. */
    Dcm_NegativeResponseCodeType errCode = DCM_E_POSITIVERESPONSE;
#if (SSA_KEEP_BUFFER_VARIABLES_STATIC == STD_OFF)
    CertP_ParsedCertStructureType parsedCert;
    parsedCert.parsedCertLength = 0u;
#endif
    /* Set default verification result. */
    RightsM_Workspace.verifResult = CERTP_VER_INVALID_FORMAT;

    /* #10 Check that the current diagnostic channel is valid. If not return error with NRC "general reject". */
    if (!RightsM_IsDiagChanValid(RightsM_CurrentDiagChanId_Service))
    {
      errCode = DCM_E_GENERALREJECT;
    }
    else
    {
      if ((OpStatus == DCM_PENDING) || (OpStatus == DCM_INITIAL))
      {
        if (RightsM_Workspace.procState == CSM_ASYNC_IDLE)
          /* #20 Check the enhanced rights certificate: parse it and verify its signature. */
        {
          RightsM_GetParsedCert().verificationResult = CERTP_VER_PARSE_FAILED;
          RightsM_GetParsedCert().serialNumber.elemDataIdx = 0u;
          RightsM_GetParsedCert().pkiRole = 0u;
          RightsM_GetParsedCert().serialNumber.elemDataLength = 0u;

          retVal = RightsM_CheckEnhanceAccessCert(Enhanced_Rights_Certificate, DataLength, &RightsM_GetParsedCert(), &errCode);
          if (retVal == E_OK)
          {
            RightsM_Workspace.procState = CSM_ASYNC_VERIFY_CERTIFICATE;
          }
          else
          {
            /* Verification is finished */
            RightsM_Workspace.verifResult = RightsM_GetParsedCert().verificationResult;
            RightsM_Workspace.procState = CSM_ASYNC_IDLE;
          }
        }

        /* OpStatus might be INITIAL or PENDING */
        /* #30 Check the enhanced rights certificate: verify its signature. */
        retVal = RightsM_VerifyEnhanceAccessCert(Enhanced_Rights_Certificate, &RightsM_GetParsedCert(), &errCode);
      }
      else
      {
        /* not supported operation status */
        errCode = DCM_E_GENERALREJECT;
      }
    }

    if (retVal != RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_PENDING)
    {
      /* Now writing the output values. */
      *routineInfo = SSA_ROUTINE_INFO_SUCCESFULLY_COMPLETED;
      *Verification_Result = RightsM_Workspace.verifResult;
      *ErrorCode = errCode;
      /* Check the error code for a negative return. */
      if (*ErrorCode != DCM_E_POSITIVERESPONSE)
      {
        retVal = RTE_E_RoutineServices_Routine_Enhance_Access_Rights_E_NOT_OK;
      }
      else
      {
        retVal = RTE_E_OK;
      }
    }
  }

  return retVal;
  /* PRQA S 6060, 6080 4 */ /* MD_SSA_STPAR, MD_MSR_STMIF */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_TimeM_TickCount_Get(uint64 *tickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_TickCount_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CsmRandomGenerate_RandomGenerate(uint8 *resultBuffer, uint32 *resultLength)
 *     Argument resultBuffer: uint8* is of type Csm_RandomGenerateResultType_Random
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmRandomGenerate_Random_CSM_E_BUSY, RTE_E_CsmRandomGenerate_Random_CSM_E_ENTROPY_EXHAUSTION, RTE_E_CsmRandomGenerate_Random_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_RightsM_Nonce_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start(Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Nonce, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Nonce: uint8* is of type Dcm_Data32ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Nonce) >= sizeof(Dcm_Data32ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Nonce, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_Start (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ( (routineInfo == NULL_PTR)
    || (Nonce == NULL_PTR)
    || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif
  {
    if ((OpStatus == DCM_INITIAL) || (OpStatus == DCM_PENDING))
    {
      /* #10 Generate a new nonce or get the stored nonce if there is a valid one. */
      retVal = RightsM_Nonce_Get(TRUE, Nonce);

      if (retVal == SSA_E_PENDING)
      {
        retVal = RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_DCM_E_PENDING;
      }
      else if (retVal != E_OK)
      {
        retVal = RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_E_NOT_OK;
      }
      else
      {
        retVal = RTE_E_OK;
      }
    }

    if (retVal != RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_DCM_E_PENDING)
    {
      if (retVal != RTE_E_OK)
      {
        *ErrorCode = RIGHTSM_DCM_NRC_CHALLENGE_CALCULATION_FAILED;
      }
      else
      {
        *ErrorCode = DCM_E_POSITIVERESPONSE;
      }
      *routineInfo = SSA_ROUTINE_INFO_SUCCESFULLY_COMPLETED;
    }
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <RoutineServices_Status_of_Post_Production_Flag>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_RequestResults(Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Post_Production_Flag_Out, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Status_of_Post_Production_Flag_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Status_of_Post_Production_Flag_DCM_E_PENDING
 *   RTE_E_RoutineServices_Status_of_Post_Production_Flag_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_RequestResults_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* PRQA S 3673 6 */ /* MD_SSA_PARAM_NOT_P2CONST */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_RequestResults(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Post_Production_Flag_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_RequestResults (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Status_of_Post_Production_Flag_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ( (routineInfo_Out == NULL_PTR)
    || (Post_Production_Flag_Out == NULL_PTR)
    || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif
  {
    /* Pass the post production status from RAM to out buffer. */
    *Post_Production_Flag_Out = *Rte_Pim_RightsMPostProductionStatus();

    /* Always set 'in progress'. Do not follow the state machine for asynchronous routines. */
    *routineInfo_Out = SSA_ROUTINE_INFO_SUCCESFULLY_COMPLETED;

    retVal = RTE_E_OK;

    SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
    SSA_DUMMY_STATEMENT(ErrorCode);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Status_of_Post_Production_Flag>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_RightsM_PostProductionStatus_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_RightsM_PostProductionStatus_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Start(uint8 In_Post_Production_Flag_In, Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Out_Post_Production_Flag_Out, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Status_of_Post_Production_Flag_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Status_of_Post_Production_Flag_DCM_E_PENDING
 *   RTE_E_RoutineServices_Status_of_Post_Production_Flag_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Start_doc
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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Start(uint8 In_Post_Production_Flag_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Out_Post_Production_Flag_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Start (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Status_of_Post_Production_Flag_DCM_E_PENDING;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ( (routineInfo_Out == NULL_PTR)
    || (Out_Post_Production_Flag_Out == NULL_PTR)
    || (ErrorCode == NULL_PTR))
  {
    retVal = RTE_E_RoutineServices_Status_of_Post_Production_Flag_E_NOT_OK;
  }
  else
#endif
  {
    uint8 routineInfo = SSA_ROUTINE_INFO_STOPPED_WITHOUT_RESULTS;
    if ((OpStatus == DCM_INITIAL) || (OpStatus == DCM_PENDING))
    {
      /* #5 Handle the following states for writing the post production status:
       *    RIGHTSM_NVM_WRITE_STATE_IDLE
       *    RIGHTSM_NVM_WRITE_STATE_START
       *    RIGHTSM_NVM_WRITE_STATE_PENDING. */

      if (RightsM_WritePostProductionStatus_State == RIGHTSM_NVM_WRITE_STATE_IDLE)
      {
        /* #10 Idle: If status 'irreversible activated' shall be set, trigger the writing of new status to non-volatile memory. */
        if (In_Post_Production_Flag_In == SSA_POST_PRODUCTION_STATUS_IRREVERSIBLY_ACTIVATED)
        {
          *Rte_Pim_RightsMPostProductionStatusMirror2() = SSA_POST_PRODUCTION_STATUS_IRREVERSIBLY_ACTIVATED;
          /* Data shall also be written to non-volatile memory */
          RightsM_WritePostProductionStatus_State = RIGHTSM_NVM_WRITE_STATE_START;
        }
        else if (In_Post_Production_Flag_In == SSA_POST_PRODUCTION_STATUS_REVERSIBLY_ACTIVATED)
        {
          *Rte_Pim_RightsMPostProductionStatus() = SSA_POST_PRODUCTION_STATUS_REVERSIBLY_ACTIVATED;
          /* State remains idle. */
          retVal = RTE_E_OK;
          routineInfo = SSA_ROUTINE_INFO_SUCCESFULLY_COMPLETED;
        }
        else
        {
          /* Invalid value of Data. */
          retVal = RTE_E_RoutineServices_Status_of_Post_Production_Flag_E_NOT_OK;
          *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
      }

      /* #20 Start/Pending: Write new status to non-volatile memory. Finally set new status is volatile memory. */
      if ((RightsM_WritePostProductionStatus_State == RIGHTSM_NVM_WRITE_STATE_START) ||
        (RightsM_WritePostProductionStatus_State == RIGHTSM_NVM_WRITE_STATE_PENDING))
      {
        uint8 nvmRetVal;
        NvM_RequestResultType errorStatus = NVM_REQ_PENDING;

        /* Check Read status of NVRAM block. */
        nvmRetVal = Rte_Call_NvMService_RightsM_PostProductionStatus_GetErrorStatus(&errorStatus);
        if ((nvmRetVal == E_OK) && (errorStatus != NVM_REQ_PENDING))
        {
          if (RightsM_WritePostProductionStatus_State == RIGHTSM_NVM_WRITE_STATE_START)
          {
            /* Write NV block if it has been started and do not change back to idle state as long as NVRAM block status is
             * pending. */
            if (Rte_Call_NvMService_RightsM_PostProductionStatus_WriteBlock(Rte_Pim_RightsMPostProductionStatusMirror2()) ==  /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
              RTE_E_OK)
            {
              /* retVal is already pending */
              RightsM_WritePostProductionStatus_State = RIGHTSM_NVM_WRITE_STATE_PENDING;
            }
            else
            {
              /* result of execution was negative */
              retVal = RTE_E_OK;
              RightsM_WritePostProductionStatus_State = RIGHTSM_NVM_WRITE_STATE_IDLE;
            }
          }
          else /* RIGHTSM_NVM_WRITE_STATE_PENDING */
          {
            if (errorStatus == NVM_REQ_OK)
            {
              /* Finally set new status */
              *Rte_Pim_RightsMPostProductionStatus() = SSA_POST_PRODUCTION_STATUS_IRREVERSIBLY_ACTIVATED;
              /* Set MirrorBlock to the same value that was written to the NvmBlock. */
              *Rte_Pim_RightsMPostProductionStatusMirror() = SSA_POST_PRODUCTION_STATUS_IRREVERSIBLY_ACTIVATED;
              /* writing has finished */
              routineInfo = SSA_ROUTINE_INFO_SUCCESFULLY_COMPLETED;
              retVal = RTE_E_OK;
              RightsM_WritePostProductionStatus_State = RIGHTSM_NVM_WRITE_STATE_IDLE;
            }
            else
            {
              /* Storing the PostProductionStatus in the NvM has failed. */
              RightsM_WritePostProductionStatus_State = RIGHTSM_NVM_WRITE_STATE_IDLE;
              retVal = RTE_E_RoutineServices_Status_of_Post_Production_Flag_E_NOT_OK;
              *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
            }
          }
        }
      }

      /* #30 Pass the set post production status to out buffer. */
      if ((retVal == RTE_E_OK) && (routineInfo == SSA_ROUTINE_INFO_SUCCESFULLY_COMPLETED))
      {
        *routineInfo_Out = SSA_ROUTINE_INFO_SUCCESFULLY_COMPLETED;
        /* Pass the post production status to out buffer. */
        *Out_Post_Production_Flag_Out = *Rte_Pim_RightsMPostProductionStatus();
      }
    }

    else /* OpStatus == DCM_CANCEL */
    {
      /* If NvM_WriteBlock has already been called, just ignore the result. Data may have been written or not. */
      RightsM_WritePostProductionStatus_State = RIGHTSM_NVM_WRITE_STATE_IDLE;
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      retVal = RTE_E_OK;
    }
  }

  return retVal;
  /* PRQA S 6030, 6080 4 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Stop
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Stop> of PortPrototype <RoutineServices_Status_of_Post_Production_Flag>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Stop(uint8 In_Post_Production_Flag_In, Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Out_Post_Production_Flag_Out, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Status_of_Post_Production_Flag_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Status_of_Post_Production_Flag_DCM_E_PENDING
 *   RTE_E_RoutineServices_Status_of_Post_Production_Flag_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Stop_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Stop(uint8 In_Post_Production_Flag_In, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) routineInfo_Out, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Out_Post_Production_Flag_Out, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_RoutineServices_Status_of_Post_Production_Flag_Stop (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Status_of_Post_Production_Flag_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ( (routineInfo_Out == NULL_PTR)
    || (Out_Post_Production_Flag_Out == NULL_PTR)
    || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif
  {
    /* #10 Check input data */
    if (In_Post_Production_Flag_In == SSA_POST_PRODUCTION_STATUS_DEACTIVATED) /* <- deactivated according to CDD */
    {
      /* #20 Deactivate only temporarily, thus write new status only to volatile memory */
      *Rte_Pim_RightsMPostProductionStatus() = SSA_POST_PRODUCTION_STATUS_DEACTIVATED;
      /* #30 Pass the post production status to out buffer */
      *Out_Post_Production_Flag_Out = SSA_POST_PRODUCTION_STATUS_DEACTIVATED;

      *routineInfo_Out = SSA_ROUTINE_INFO_SUCCESFULLY_COMPLETED;
      retVal = RTE_E_OK;
    }
    else
    {
      /* Invalid value */
      retVal = RTE_E_RoutineServices_Status_of_Post_Production_Flag_E_NOT_OK;
      *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    }

    SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_SecurityAccess_CompareKey
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CompareKey> of PortPrototype <RightsM_SecurityAccess>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_RightsM_SecurityLevelChange_currentLevel(uint8 data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SecLog_AuthorizationBySecurityAccess_AuthorizationBySecurityAccess(uint8 diagChanAuthStatus, uint8 securityLevel, uint8 securityAccessResult)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_AuthorizationBySecurityAccess_E_NOT_OK
 *   Std_ReturnType Rte_Call_SsaCdd_Csm_SignatureVerify(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_ConstDataPtr compareBuffer, uint32 compareLength, Ssa_VerifyResultPtr resultBuffer)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_SecurityAccess_CompareKey(uint8 secLevel, const uint8 *key, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode)
 *     Argument key: uint8* is of type Dcm_Data64ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK
 *   RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_SecurityAccess_CompareKey_doc
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
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_SecurityAccess_CompareKey(uint8 secLevel, P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) key, Dcm_OpStatusType opStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) errorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_SecurityAccess_CompareKey (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ( (key == NULL_PTR)
    || (errorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif
  {
    /* #10 Do the signature verification only if security access levels are configured. */
#if (SSA_SECURITYACCESSLEVEL == STD_ON)
    boolean writeSecLog = FALSE;
    retVal = RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING;

    /* #20 Handle opStatus DCM_CANCEL. */
    if (opStatus == DCM_CANCEL)
    {
      retVal = RTE_E_OK;
      /* Discard the result of a possibly sent asynchronous signatureVerify request. */
      RightsM_CompareKeyAsyncState = SSA_ASYNC_STATE_IDLE;
    }
    else
    {
      if (opStatus == DCM_INITIAL)
      {
        Ssa_SizeOfSecurityAccessLevelType index;
        /* Get index of securityLevel. */
        if (RightsM_GetInternalIndexOfSecurityLevel(secLevel, &index) == E_NOT_OK)
        {
          retVal = RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK;
          *errorCode = DCM_E_GENERALREJECT;
        }
        else
        {
          RightsM_SecLevelIndex = index;
        }
      }

      if ((opStatus == DCM_PENDING) || (retVal != RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK))
      {
        retVal = RightsM_CompareKeyByCsmSigVerify(
          secLevel,
          key,
          RightsM_SecLevelIndex,
          errorCode);
      }

      /* #100 Check that the service is finished. */
      if (retVal != RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING)
      {
        /* trigger writing security log */
        writeSecLog = TRUE;
      }
    }

    if (writeSecLog)
#else
    /* retVal already set */
    *errorCode = DCM_E_GENERALREJECT;
    SSA_DUMMY_STATEMENT(key);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
    SSA_DUMMY_STATEMENT(opStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#endif
    {
      /* #120 Write security log event "authorization by security access". */
      /* As the security level, the Standard Security Architecture shall store
       * the sub-function parameter of compareKey request decremented by 1 (SSA-IS-1659),
       * i.e. the subfunction parameter of the getSeed function. */
       /* According to DDS S-ISO14229 it is secLevel <= 0x30. */
      (void)Rte_Call_SecLog_AuthorizationBySecurityAccess_AuthorizationBySecurityAccess(RightsM_GetDiagChanAndAuthenticationState(), (uint8)((secLevel << 1u) - 1u), *errorCode);
      RightsM_IsErrorLoggedBySsa = TRUE;
    }
  }

  return retVal;
  /* PRQA S 6010, 6030, 6080 4 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_SecurityAccess_GetSeed
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetSeed> of PortPrototype <RightsM_SecurityAccess>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CsmRandomGenerate_RandomGenerate(uint8 *resultBuffer, uint32 *resultLength)
 *     Argument resultBuffer: uint8* is of type Csm_RandomGenerateResultType_Random
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_CsmRandomGenerate_Random_CSM_E_BUSY, RTE_E_CsmRandomGenerate_Random_CSM_E_ENTROPY_EXHAUSTION, RTE_E_CsmRandomGenerate_Random_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_SecurityAccess_GetSeed(uint8 secLevel, Dcm_OpStatusType opStatus, uint8 *seed, Dcm_NegativeResponseCodeType *errorCode)
 *     Argument seed: uint8* is of type Dcm_Data32ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK
 *   RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_SecurityAccess_GetSeed_doc
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
/* PRQA S 3673 10 */ /* MD_SSA_PARAM_NOT_P2CONST */
/*!
 * \spec
 *    requires $lengthOf(seed) >= sizeof(Dcm_Data32ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_SecurityAccess_GetSeed(uint8 secLevel, Dcm_OpStatusType opStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) seed, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) errorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_SecurityAccess_GetSeed (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ( (seed == NULL_PTR)
    || (errorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif
  {
#if (SSA_SECURITYACCESSLEVEL == STD_ON)
    retVal = RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING;
    /* #5 Handle opStatus DCM_CANCEL. */
    if (opStatus == DCM_CANCEL)
    {
      retVal = RTE_E_OK;
    }
    else
    {
      Std_ReturnType rVal;

      if (opStatus == DCM_INITIAL)
      {
        Ssa_SizeOfSecurityAccessLevelType index;
        /* Get index of securityLevel. */
        rVal = RightsM_GetInternalIndexOfSecurityLevel(secLevel, &index);
        if (rVal == E_NOT_OK)
        {
          retVal = RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK;
          *errorCode = DCM_E_GENERALREJECT;
        }
        else
        {
          RightsM_SecLevelIndex = index;
        }
      }

      if ((opStatus == DCM_PENDING) || (retVal == RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING))
      {
        /* The %-Operator is used to satisfy static code analysis of array access. In the function
         * RightsM_GetInternalIndexOfSecurityLevel() it is checked, that the RightsM_SecLevelIndex
         * is not out of bounds.*/
        RightsM_SecLevelIndex =
          RightsM_SecLevelIndex % (Ssa_SizeOfSecurityAccessLevelType)SSA_RIGHTSM_NUMBER_SECURITY_ACCESS_LEVELS;
        /*@ assert RightsM_SecLevelIndex < SSA_RIGHTSM_NUMBER_SECURITY_ACCESS_LEVELS; */ /* VCA_SSA_RIGHTSM_MODULO */

        /* #10 Check if security level is already seeded. */
        if (RightsM_SecAccessIsSeeded[RightsM_SecLevelIndex] == TRUE)
        {
          /* #20 Return stored static seed. */
          Ssa_MemCpy(
            (P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))seed,
            (P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR))&RightsM_SecAccess_StaticSeedArray[RightsM_SecLevelIndex][0],
            SSA_SIZEOF_NONCE);
          retVal = RTE_E_OK;
        }
        else
        {
          /* #30 Generate random data for the seed. */
          rVal = RightsM_CsmRandomGenerate(SSA_SIZEOF_NONCE, seed);
          if (rVal == SSA_E_PENDING)
          {
            retVal = RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING;
          }
          else if (rVal != E_OK)
          {
            retVal = RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK;
            *errorCode = DCM_E_CONDITIONSNOTCORRECT;
          }
          else
          {

# if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)
            /* Can only happen if DCM changes the secLevel after getting a PENDING (very unlikely).
               And this is only possible in async configs.
            */
            if (Ssa_GetLevelOfSecurityAccessLevel(RightsM_SecLevelIndex) != secLevel)
            {
              retVal = RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK;
              *errorCode = DCM_E_GENERALREJECT;
            }
            else
# endif
            {
              RightsM_SecAccessIsSeeded[RightsM_SecLevelIndex] = TRUE;
              /* #40 Store the seed for the respective security level temporarily in the static seed array. */
              Ssa_MemCpy(
                (P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR))&RightsM_SecAccess_StaticSeedArray[RightsM_SecLevelIndex][0],
                (P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))seed,
                SSA_SIZEOF_NONCE);
              retVal = RTE_E_OK;
            }
          }
        }
      }
    }
#else
    /* retVal already set */
    *errorCode = DCM_E_GENERALREJECT;
    SSA_DUMMY_STATEMENT(secLevel);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
    SSA_DUMMY_STATEMENT(opStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
    SSA_DUMMY_STATEMENT(seed);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#endif
  }

  return retVal;
  /* PRQA S 6010, 6030, 6080 4 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_ServiceRequestNotification_Confirmation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Confirmation> of PortPrototype <ServiceRequestNotification>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SecLog_AuthorizationBySecurityAccess_AuthorizationBySecurityAccess(uint8 diagChanAuthStatus, uint8 securityLevel, uint8 securityAccessResult)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_AuthorizationBySecurityAccess_E_NOT_OK
 *   Std_ReturnType Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_ActivateDebugIf_SuccessfulDiagServiceExecution(uint8 additionalInfo)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_SuccessfulDiagServiceExecutionEvent_E_NOT_OK
 *   Std_ReturnType Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_ClearSarMemory_SuccessfulDiagServiceExecution(uint8 additionalInfo)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_SuccessfulDiagServiceExecutionEvent_E_NOT_OK
 *   Std_ReturnType Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_EnableSarMemOverwrite_SuccessfulDiagServiceExecution(uint8 additionalInfo)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_SuccessfulDiagServiceExecutionEvent_E_NOT_OK
 *   Std_ReturnType Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_EraseMemory_SuccessfulDiagServiceExecution(uint8 additionalInfo)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_SuccessfulDiagServiceExecutionEvent_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_ServiceRequestNotification_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_ServiceRequestNotification_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_ServiceRequestNotification_Confirmation_doc
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
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_ServiceRequestNotification_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_ServiceRequestNotification_Confirmation (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_OK;
  uint8 secLevel;
  uint8 currentDiagChanId;

  /* Keep diagnostic channel ID in a local buffer so it can't be modified in a different context. */
  currentDiagChanId = RightsM_CurrentDiagChanId;

  /* #5 Check that the current diagnostic channel is valid. If not, return NRC "conditions not correct". */
  if (!RightsM_IsDiagChanValid(currentDiagChanId))
  {
    retVal = RTE_E_ServiceRequestNotification_E_NOT_OK;
  }
  else
  {
    /* #10 Write security log according to the stored service to be logged identifier. */
    if (ConfirmationStatus == DCM_RES_POS_OK)
    {
      switch (RightsM_ServiceToFilterFor)
      {
      case RIGHTSM_SECLOG_BY_INDICATION_NONE:
        /* Standard case. No action. */
        break;
      case RIGHTSM_SECLOG_BY_INDICATION_ACT_DBG_IF_RID_0x0265:
        (void)Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_ActivateDebugIf_SuccessfulDiagServiceExecution(0xFFu);
        break;
      case RIGHTSM_SECLOG_BY_INDICATION_ERASE_MEM_RID_0xFF00:
        (void)Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_EraseMemory_SuccessfulDiagServiceExecution(RightsM_ServiceToFilterForData);
        break;
      case RIGHTSM_SECLOG_BY_INDICATION_CLEAR_SAR_MEM_RID_0x0242:
        (void)Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_ClearSarMemory_SuccessfulDiagServiceExecution(0xFFu);
        break;
      case RIGHTSM_SECLOG_BY_INDICATION_ENABLE_SAR_MEM_OVERWRITE_DID_0x0137:
        (void)Rte_Call_SecLog_SuccessfulDiagServiceExecutionEvent_EnableSarMemOverwrite_SuccessfulDiagServiceExecution(RightsM_ServiceToFilterForData);
        break;
      case RIGHTSM_SECLOG_BY_INDICATION_SECURITY_ACCESS_SEND_KEY:
        /* Store channel id */
        RightsM_ChannelIdOfLastSuccessfulSecurityAccess = currentDiagChanId;
        break;
      default:
        /* Undefined case. No action. */
        break;
      }
    }
    else
    {
      /* Filter for security access */
      if (SID == 0x27u)
      {
        /* Clear channel id */
        RightsM_ChannelIdOfLastSuccessfulSecurityAccess = SSA_RIGHTSM_DIAG_INVALID_CHAN_ID;

        /* #12 Log security access errors that are detected only by Dcm. */
        if (RightsM_IsErrorLoggedBySsa == FALSE)
        {
          /* Write security log event "authorization by security access". */
          /* As the security level, the Standard Security Architecture shall store
          the sub-function parameter of compareKey request decremented by 1 (SSA-IS-1659),
          i.e. the subfunction parameter of the getSeed function. */
          secLevel = RightsM_DecrementSubfunctionParameter(RightsM_ServiceToFilterForData);
          (void)Rte_Call_SecLog_AuthorizationBySecurityAccess_AuthorizationBySecurityAccess(RightsM_GetDiagChanAndAuthenticationState(), secLevel, SSA_RIGHTSM_E_DCM_REJECTED_SECURITYACCESS);
          RightsM_IsErrorLoggedBySsa = TRUE;
        }
      }
    }

    Rte_Enter_RightsM_ExclusiveArea();
    /* #15 If being locally authenticated restart the authentication timeout on reception of a valid diagnostic request SSA-IS-486 */
    if ((RightsM_DiagChannelData[currentDiagChanId].authentication_State == RIGHTSM_CHANNEL_LOCALLY_AUTHENTICATED)
      && (RightsM_DiagChannelData[currentDiagChanId].authenticationTimeoutTimer == 0u))
    {
      /* Restart the authentication timeout. */
      RightsM_DiagChannelData[currentDiagChanId].authenticationTimeoutTimer = SSA_RIGHTSM_AUTHENTICATION_TIMEOUT;
    }
    Rte_Exit_RightsM_ExclusiveArea();
  }

  /* #20 Invalidate the current diagnostic channel. */
  RightsM_CurrentDiagChanId = SSA_RIGHTSM_DIAG_INVALID_CHAN_ID;
  RightsM_CurrentDiagnosticChannel = SSA_RIGHTSM_DIAG_INVALID_CHANNEL;
  RightsM_ServiceToFilterFor = RIGHTSM_SECLOG_BY_INDICATION_NONE;
  RightsM_ServiceToFilterForData = 0xFFu;

  SSA_DUMMY_STATEMENT(SID);                 /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  SSA_DUMMY_STATEMENT(SourceAddress);       /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  SSA_DUMMY_STATEMENT(ReqType);             /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
  /* PRQA S 6030 4 */ /* MD_MSR_STCYC */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_RightsM_ServiceRequestNotification_Indication
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Indication> of PortPrototype <ServiceRequestNotification>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SecLog_RightsManagementEvent_RightsManagement(uint8 diagChanAuthStatus, uint8 serviceId, uint8 subFunction, uint16 dataIdOrRoutineId)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_RightsManagementEvent_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_RightsM_ExclusiveArea(void)
 *   void Rte_Exit_RightsM_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_RightsM_ServiceRequestNotification_Indication(uint8 SID, const uint8 *RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument RequestData: uint8* is of type Dcm_SsaDslBufferType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_ServiceRequestNotification_E_NOT_OK
 *   RTE_E_ServiceRequestNotification_E_REQUEST_NOT_ACCEPTED
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_ServiceRequestNotification_Indication_doc
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
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_RightsM_CODE) Ssa_RightsM_ServiceRequestNotification_Indication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_RightsM_ServiceRequestNotification_Indication (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_ServiceRequestNotification_E_NOT_OK;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ( (RequestData == NULL_PTR)
    || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif
  {
    Dcm_NegativeResponseCodeType errCode = DCM_E_POSITIVERESPONSE;
    uint8 diagChanId;

    if (SID == 0x27u)
    {
      /* For SecurityAccess, reset the global logging flag */
      RightsM_IsErrorLoggedBySsa = FALSE;
    }

    /*  #10 Get the diagnostic channel id from the lowest nibble of the tester source address. */
    diagChanId = RightsM_GetDiagChanIdFromSourceAddress(SourceAddress); /* don't write the new channel id the the global variable until we know it's valid */

    /* #20 Check that the current diagnostic channel is valid and that no current diagnostic channel exists yet.
           If not, return NRC "conditions not correct". */
    if ((!RightsM_IsDiagChanValid(diagChanId)) || (RightsM_CurrentDiagChanId != SSA_RIGHTSM_DIAG_INVALID_CHAN_ID))
    {
      errCode = DCM_E_CONDITIONSNOTCORRECT;
      retVal = RTE_E_ServiceRequestNotification_E_NOT_OK;
    }
    else
    {
      RightsM_CurrentDiagChanId = diagChanId;
      /* #30 Evaluate and process the requested session data. */
      retVal = RightsM_ProcessRequestedSessionInfo(SID, RequestData, DataSize, SourceAddress, &errCode);
    }

    /* #40 Set the negative return code depending on which error occurred. */
    if (retVal != E_OK)
    {
      if (retVal == RIGHTSM_E_ACL_AUTHENTICATIONREQUIRED)
      {
        /* #41 Set negative response code to "authentication required" if the requested diagnostic service is
         *     contained in the access control lists but not available for the current Diagnostic Channel. */
        *ErrorCode = DCM_E_AUTHENTICATIONREQUIRED;
      }
      else if (retVal == RIGHTSM_E_ACL_SERVICENOTSUPPORTED)
      {
        /* #42 Set negative response code to "security not supported" if the requested diagnostic service is not
         * contained in the access control lists. */
        *ErrorCode = DCM_E_SERVICENOTSUPPORTED;
      }
      else if (retVal == RIGHTSM_E_ACL_SUBFUNCTIONNOTSUPPORTED)
      {
        /* #43 Set negative response code to "sub-function not supported" if the requested diagnostic sub function is not
        * contained in the access control lists. */
        *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
      }
      else if (retVal == RIGHTSM_E_ACL_IDNOTSUPPORTED)
      {
        /* #44 Set negative response code to "request out of range" if the requested diagnostic id (DDID, RID) is not
        * contained in the access control lists. */
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }
      else
      {
        /* #45 Accept the requested diagnostic service only if no error occurred. */
        *ErrorCode = errCode;
      }
      retVal = RTE_E_ServiceRequestNotification_E_NOT_OK;
    }

    SSA_DUMMY_STATEMENT(ReqType);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  }

  return retVal;
  /* PRQA S 6060, 6080 4 */ /* MD_SSA_STPAR, MD_MSR_STMIF */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#define Ssa_RightsM_STOP_SEC_CODE
#include "Ssa_RightsM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define Ssa_RightsM_START_SEC_CODE
#include "Ssa_RightsM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)
/**********************************************************************************************************************
 * RightsM_UpdateLocalAsyncState()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_UpdateLocalAsyncState(
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) asyncState,
  Csm_ResultType result)
{
   /* #10 Handle the Csm asynchronous state dependent on the callback's result only if a callback is awaited. */
  if (*asyncState == SSA_ASYNC_STATE_WAIT)
  {
    if (result == E_OK)
    {
      *asyncState = SSA_ASYNC_STATE_READY;
    }
    else
    {
      *asyncState = SSA_ASYNC_STATE_FAILED;
    }
  }
}
#endif
/**********************************************************************************************************************
 * RightsM_CopyOrClear()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_CopyOrClear(
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) dst,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) src,
  uint16 srcOffset,
  uint16 cnt)
{
  if (src == NULL_PTR)
  {
    Ssa_Utils_MemClr(dst, cnt);
  }
  else
  {
    if (cnt == 1u)
    {
      *dst = RightsM_GetByteValFromBcd(src, srcOffset);
    }
    else
    {
      Ssa_MemCpy(dst, &src[srcOffset], cnt);
    }
  }

  return RTE_E_OK;
}

/**********************************************************************************************************************
 * RightsM_GenericConditionCheckRead()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_GenericConditionCheckRead(
  boolean errorCondition,
  Std_ReturnType rteErrorCode,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) errorCode)
{
  Std_ReturnType rVal;

  /* #10 Check if the error condition is fulfilled. Adapt ErrorCode and return value accordingly. */
  if (errorCondition)
  {
    *errorCode = DCM_E_GENERALREJECT;
    rVal = rteErrorCode;
  }
  else
  {

    rVal = RTE_E_OK;
  }

  return rVal;
}

/**********************************************************************************************************************
 * RightsM_CheckAccessControlLists()
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
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_CheckAccessControlLists(void)
{
  SecLog_AclVersionType aclVersionLog = { 0u };
  uint8 aclCompatibility = 0x00u;

  /* #10 Validate the basic ACL, but do not check the diagnostic variant and version. Activate if validation succeeds. */
  if (RightsM_ValidateAcl((P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_CONST))RightsM_BasicAccessControlList(), FALSE) == TRUE)
  {
    /* Activate. */
    RightsM_BasicAcl = RightsM_BasicAccessControlList();
    RightsM_EcuIndividualAcl = SSA_RightsM_EcuIndividualAccessControlList();
  }
  else
  {
    /* #20 Validate the ECU individual ACL only if the Basic ACL has been accepted. Deactivate the ECU-individual ACL */
    RightsM_BasicAcl = NULL_PTR;
    RightsM_EcuIndividualAcl = NULL_PTR;
  }

  if (RightsM_EcuIndividualAcl != NULL_PTR)
  {
    /* #30 Extract the date (YYYYMMDD), major, minor and patch version from the ACL before validating it. */

    /* Date (first 8 bytes) */
    Ssa_MemCpy((P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR))&aclVersionLog[0],
      (P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))RightsM_AccessRights_GetExportDateTime(RightsM_EcuIndividualAcl),
      8u);
    /* Major */
    aclVersionLog[8] = RightsM_GetByteValFromBcd(RightsM_AccessRights_GetLabelRevHistoryCdd(RightsM_EcuIndividualAcl), 0u);
    /* Minor */
    aclVersionLog[9] = RightsM_GetByteValFromBcd(RightsM_AccessRights_GetLabelRevHistoryCdd(RightsM_EcuIndividualAcl), 3u);
    /* Patch */
    aclVersionLog[10] = RightsM_GetByteValFromBcd(RightsM_AccessRights_GetLabelRevHistoryCdd(RightsM_EcuIndividualAcl), 6u);

    /* #50 Validate the ECU individual ACL and also check the diagnostic variant and version. */
    if (RightsM_ValidateAcl(RightsM_EcuIndividualAcl, TRUE) == TRUE)
    {
      aclCompatibility = 0x01u;
    }
    else
    {
      /* #55 Deactivate the ECU-individual ACL if validation or version and variant check fail. */
      RightsM_EcuIndividualAcl = NULL_PTR;
      aclCompatibility = 0x00u;
    }
  }

  /* #60 Check if the version of the activated ECU-individual ACL is different from the version stored in the NVRam block. */
  if (RightsM_CompareData((P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))aclVersionLog,
                          (P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))(Rte_Pim_RightsMAclVersion()),  /*lint !e545 */
                          RIGHTSM_SIZE_OF_STORED_ACL_VERSION) == FALSE)
  {
    /* #70 Store new version information to NVRam block. */
    (void)Ssa_MemCpy((P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR))(Rte_Pim_RightsMAclVersion()),  /*lint !e545 */
                     (P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))aclVersionLog,
                     RIGHTSM_SIZE_OF_STORED_ACL_VERSION);

    /* #80 Request for writing the ACL version NVRam block. */
    RightsM_AclVersionNvmWriteRequested = TRUE;

    /* #90 Write security log event "ECU-individual ACL replacement. */
    (void)Rte_Call_SecLog_EcuIndividualAclReplacementEvent_EcuIndividualAclReplacement(aclVersionLog, aclCompatibility);
  }
}

/**********************************************************************************************************************
 *  RightsM_DeAuthenticate()
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
 */
SSA_RIGHTSM_LOCAL FUNC(void, Ssa_RightsM_CODE) RightsM_DeAuthenticate(uint8 diagnosticChannel)
{
  uint16 idx;
  uint8 entryIdx;

  /* #10 Set authentication state to "not authenticated", enable restricted authentication as default for the given
   * diagnostic channel id and invalidate the diagnostic channel source address. */
  RightsM_DiagChannelData[diagnosticChannel].authentication_State = RIGHTSM_CHANNEL_NOT_AUTHENTICATED;
  RightsM_DiagChannelData[diagnosticChannel].securitySettings.restrictedAuthentication = TRUE;
  RightsM_DiagChannelData[diagnosticChannel].currentDiagnosticChannel = SSA_RIGHTSM_DIAG_INVALID_CHANNEL;

  /* #20 Clear enhanced access control list for the given diagnostic channel id. */
  for (idx = 0u; idx < RIGHTSM_ENHANCED_ACCESS_RIGHTS_TABLE_NUM_ENTRIES; idx++)
  {
    /* #30 Clear all entries with the requested diagnostic channel id. */
    if ((RightsM_EnhancedAccessRights[idx][0u] != 0u) && (RightsM_EnhancedAccessRights[idx][1u] == diagnosticChannel))
    {
      for (entryIdx = 0u; entryIdx < RIGHTSM_ENHANCED_ACCESS_ENTRY_SIZE; entryIdx++)
      {
        RightsM_EnhancedAccessRights[idx][entryIdx] = 0u;
      }
    }
  }

  /* #35 Compress table. */
  RightsM_CompressEnhancedAccessRightsTable();

  /* #40 Clear the diagnostic channel data (including the security settings) for the given diagnostic channel id. */
  RightsM_DiagChannelData[diagnosticChannel].securitySettings.diagnosticUserRole = 0x00u;
  for (idx = 0u; idx < SSA_SIZEOF_SERIALNUMBER; idx++)
  {
    RightsM_DiagChannelData[diagnosticChannel].securitySettings.testerSerialNumber[idx] = 0xFFu;
  }
  for (idx = 0u; idx < SSA_SIZEOF_PUBLICKEY; idx++)
  {
    RightsM_DiagChannelData[diagnosticChannel].securitySettings.testerPublicKey[idx] = 0xFFu;
  }
  for (idx = 0u; idx < SSA_SIZEOF_ISSUER; idx++)
  {
    RightsM_DiagChannelData[diagnosticChannel].securitySettings.testerIssuer[idx] = 0x00u;
  }

#if ( SSA_ECU_TYPE == SSA_ECU_TYPE_VSM )
  /* #45 Reset authentication broadcast timer, if there is no diagnostic channel sending cyclical broadcast messages. */
  if (RightsM_CheckForActiveDiagnosticChannels() == FALSE)
  {
    /* Reset authentication broadcast timer */
    RightsM_AuthenticationBroadcastTimer = 0u;
  }
#endif
  RightsM_DiagChannelData[diagnosticChannel].authenticationTimeoutTimer = 0u;
  RightsM_DiagChannelData[diagnosticChannel].authentication_ExpectedTask = 0x00u;

  RightsM_TargetSubjectKeyIdentifierValid = FALSE;

  /* #50 Clear temporary security settings for the given diagnostic channel id. */
  RightsM_ClearPreliminarySecuritySettings(diagnosticChannel);

  RightsM_ServiceToFilterFor = RIGHTSM_SECLOG_BY_INDICATION_NONE;
  RightsM_ServiceToFilterForData = 0xFFu;
}

/**********************************************************************************************************************
 *  RightsM_DeAuthenticateGlobalMode()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL FUNC(void, Ssa_RightsM_CODE) RightsM_DeAuthenticateGlobalMode(void)
{
  uint16 idx;
  /* #10 Check the authentication state of all diagnostic users within an exclusive area. */
  Rte_Enter_RightsM_ExclusiveArea();
  for (idx = 0u; idx < SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS; idx++)
  {
    if (RightsM_DiagChannelData[idx].authentication_State != RIGHTSM_CHANNEL_NOT_AUTHENTICATED)
    {
      break;
    }
  }
  Rte_Exit_RightsM_ExclusiveArea();

  /* #20 If all diagnostic users are not authenticated switch the global authentication mode to unauthenticated. */
  if (idx == SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS)
  {
    (void)Rte_Switch_Authentication_Mode(RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_UNAUTHENTICATED);
  }
}

#if ( SSA_ECU_TYPE == SSA_ECU_TYPE_VSM )
/**********************************************************************************************************************
*  RightsM_CheckForActiveDiagnosticChannels()
**********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
*/
SSA_RIGHTSM_LOCAL FUNC(boolean, Ssa_RightsM_CODE) RightsM_CheckForActiveDiagnosticChannels(void)
{
  boolean activeDiagnosticChannel = FALSE;
  uint8 idx;

  /* #10 Search for the first diagnostic channel in non-restricted authenticated state. */
  for (idx = 0u; idx < SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS; idx++)
  {
    if (RightsM_IsBroadcastChannel(idx))
    {
      activeDiagnosticChannel = TRUE;
      break;
    }
  }

  return activeDiagnosticChannel;
}
#endif

/**********************************************************************************************************************
 *  RightsM_AdoptPreliminarySecuritySettings()
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
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_AdoptPreliminarySecuritySettings(uint8 diagnosticChannel)
{
  uint8 byteIdx;

  /* #10 Copy the security settings for the given diagnostic channel to the diagnostic channel data. */
  /* #20 Copy the diagnostic user role. */
  RightsM_DiagChannelData[diagnosticChannel].securitySettings.diagnosticUserRole = RightsM_PreliminarySecuritySettings[diagnosticChannel].diagnosticUserRole;
  /* #30 Copy the restricted authentication flag. */
  RightsM_DiagChannelData[diagnosticChannel].securitySettings.restrictedAuthentication = RightsM_PreliminarySecuritySettings[diagnosticChannel].restrictedAuthentication;
  /* #40 Copy the issuer of the diagnostic tester certificate. */
  for (byteIdx = 0u; byteIdx < SSA_SIZEOF_ISSUER; byteIdx++)
  {
    RightsM_DiagChannelData[diagnosticChannel].securitySettings.testerIssuer[byteIdx] = RightsM_PreliminarySecuritySettings[diagnosticChannel].testerIssuer[byteIdx];
  }
  /* #50 Copy the public key of the diagnostic tester certificate. */
  for (byteIdx = 0u; byteIdx < SSA_SIZEOF_PUBLICKEY; byteIdx++)
  {
    RightsM_DiagChannelData[diagnosticChannel].securitySettings.testerPublicKey[byteIdx] = RightsM_PreliminarySecuritySettings[diagnosticChannel].testerPublicKey[byteIdx];
  }
  /* #60 Copy the serial number of the diagnostic tester certificate. */
  for (byteIdx = 0u; byteIdx < SSA_SIZEOF_SERIALNUMBER; byteIdx++)
  {
    RightsM_DiagChannelData[diagnosticChannel].securitySettings.testerSerialNumber[byteIdx] = RightsM_PreliminarySecuritySettings[diagnosticChannel].testerSerialNumber[byteIdx];
  }
}

/**********************************************************************************************************************
 *  RightsM_ClearPreliminarySecuritySettings()
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
 */
SSA_RIGHTSM_LOCAL FUNC(void, Ssa_RightsM_CODE) RightsM_ClearPreliminarySecuritySettings(uint8 diagnosticChannel)
{
  /* #10 Reset the preliminary security settings for the given diagnostic channel. */

  /* #20 Set the diagnostic user role to the dummy PKIRole. */
  RightsM_PreliminarySecuritySettings[diagnosticChannel].diagnosticUserRole = 0x00u;
  /* #22 Enable restricted authentication. */
  RightsM_PreliminarySecuritySettings[diagnosticChannel].restrictedAuthentication = TRUE;
  /* #24 Clear the issuer from the tester certificate. */
  RightsM_SetDataBuffer(0x00u, RightsM_PreliminarySecuritySettings[diagnosticChannel].testerIssuer, SSA_SIZEOF_ISSUER);
  /* #26 Clear the public key from the tester certificate. */
  RightsM_SetDataBuffer(0x00u, RightsM_PreliminarySecuritySettings[diagnosticChannel].testerPublicKey, SSA_SIZEOF_PUBLICKEY);
  /* #28 Clear the serial number from the tester certificate. */
  RightsM_SetDataBuffer(0x00u, RightsM_PreliminarySecuritySettings[diagnosticChannel].testerSerialNumber, SSA_SIZEOF_SERIALNUMBER);
}

/**********************************************************************************************************************
 *  RightsM_IsEnhancedAccessRightGranted()
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
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(boolean, Ssa_RightsM_CODE) RightsM_IsEnhancedAccessRightGranted(
  uint8 diagnosticChannel,
  RightsM_AccessRights_SidType sid,
  RightsM_AccessRights_SubFuncType subFunc,
  RightsM_AccessRights_IdType id,
  uint8 sizeEntryToCheck)
{
  uint16 entryIdx = 0u;
  uint8 sizeEntry;
  /* No access right granted by default. */
  boolean accessRight = FALSE;
  boolean searchFinished = FALSE;

  Rte_Enter_RightsM_ExclusiveArea();

  /* #10 If an Enhanced AccessControlList for the current Diagnostic Channel is available, start verifying
   * access rights by evaluating the Enhanced AccessControlList (SSA-IS-514). */

  /* #15 Check the enhanced ACL only if authenticated. */
  /* be less susceptible to memory manipulations: do not check for not equal to zero */
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
  if (RightsM_DiagChannelData[diagnosticChannel].authentication_State == RIGHTSM_CHANNEL_LOCALLY_AUTHENTICATED)
#else
  if ((RightsM_DiagChannelData[diagnosticChannel].authentication_State == RIGHTSM_CHANNEL_LOCALLY_AUTHENTICATED) || (RightsM_DiagChannelData[diagnosticChannel].authentication_State == RIGHTSM_CHANNEL_CENTRALLY_AUTHENTICATED))
#endif
  {
    /* #20 Loop entry-by-entry through the enhanced access rights table. */
    while (entryIdx < RIGHTSM_ENHANCED_ACCESS_RIGHTS_TABLE_NUM_ENTRIES) /* FETA_SSA_RIGHTSM_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
    {
      /* #30 Get size of entry. */
      sizeEntry = RightsM_EnhancedAccessRights[entryIdx][0u];

      /* #40 Check for the current entry that the size is greater than 0 and that the diagnostic channel equals the
       * searched one.  */
      if ((sizeEntry <= sizeEntryToCheck) && (RightsM_EnhancedAccessRights[entryIdx][1u] == diagnosticChannel))
      {
        /* #50 Depending on the entry's size check if the entry contains the given service parameter. */
        switch (sizeEntry) {
        case 4u:
          /* #60 For size 4 the entry must contain [SID(1):SubFunc(2):ID(3-4)] */
          accessRight = (
            (RightsM_EnhancedAccessRights[entryIdx][2u] == sid) &&
            (RightsM_EnhancedAccessRights[entryIdx][3u] == subFunc) &&
            (RightsM_EnhancedAccessRights[entryIdx][4u] == (uint8)(id >> 8)) &&
            (RightsM_EnhancedAccessRights[entryIdx][5u] == (uint8)(id & 0xFFu))) ? TRUE : FALSE;
          break;
        case 3u:
          /* #62 For size 3 the entry must contain [SID(1):-:ID(2-3)] */
          accessRight = (
            (RightsM_EnhancedAccessRights[entryIdx][2u] == sid) &&
            (RightsM_EnhancedAccessRights[entryIdx][3u] == (uint8)(id >> 8)) &&
            (RightsM_EnhancedAccessRights[entryIdx][4u] == (uint8)(id & 0xFFu))) ? TRUE : FALSE;
          break;
        case 2u:
          /* #64 For size 2 the entry must contain [SID(1):SubFunc(2):-] */
          accessRight = (
            (RightsM_EnhancedAccessRights[entryIdx][2u] == sid) &&
            (RightsM_EnhancedAccessRights[entryIdx][3u] == subFunc)) ? TRUE : FALSE;
          break;
        case 1u:
          /* #66 For size 1 the entry must contain [SID(1):-:-] */
          accessRight = (
            (RightsM_EnhancedAccessRights[entryIdx][2u] == sid)) ? TRUE : FALSE;
          break;
        case 0u:
          /* #67 Stop searching table once an empty entry is found. */
          searchFinished = TRUE;
          break;
        default:
          /* #68 Ignore all other sizes.*/
          break;
        }
        /* #70 Once a suitable entry is found leave the loop and function and return that access right is granted. */
        if ((searchFinished == TRUE) || (accessRight == TRUE))
        {
          break;
        }
      }
      /* Set index to next entry. */
      entryIdx++;
    }
  }
  Rte_Exit_RightsM_ExclusiveArea();

  return accessRight;
}

/**********************************************************************************************************************
 *  RightsM_GetAccessRights()
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
 */
SSA_RIGHTSM_LOCAL FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_GetAccessRights(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_CONST) acl,
  RightsM_AccessRights_SidType sid,
  RightsM_AccessRights_SubFuncType subFunc,
  RightsM_AccessRights_IdType id,
  P2VAR(RightsM_AccessRights_AccessRightsType, AUTOMATIC, AUTOMATIC) accessRights)
{
  Std_ReturnType rVal;
  RightsM_AccessRights_IdxType startIdx = RIGHTSM_ACCESSRIGHTS_START_IDX_INVALID;
  RightsM_AccessRights_IdxType endIdx;

  /* #10 If there is no access control list (null pointer check) return NRC "service not supported". */
  if (acl == NULL_PTR)
  {
    rVal = RIGHTSM_E_ACL_SERVICENOTSUPPORTED;
  }
  else
  {
    /* #20 Initially set no access rights at all. */
    *accessRights = 0x0000u;

    /* #22 Check service ID table. */
    rVal = RightsM_GetAccessRights_SidSubtable(acl, sid, &startIdx, &endIdx, accessRights);

    /* #24 If SID supported and if the service ID tables refers to sub-function table check the sub-function table. */
    if ((rVal == E_OK) && (startIdx != RIGHTSM_ACCESSRIGHTS_START_IDX_INVALID))
    {
      rVal = RightsM_GetAccessRights_SubfuncSubtable(acl, subFunc, &startIdx, &endIdx, accessRights);
    }

    /* #26 If sub-func supported and if the sub-function table refers to the ID table check the ID table. */
    if ((rVal == E_OK) && (startIdx != RIGHTSM_ACCESSRIGHTS_START_IDX_INVALID))
    {
      rVal = RightsM_GetAccessRights_IdSubtable(acl, id, &startIdx, &endIdx, accessRights);
    }
  }
  /* #30 Finally return the access rights granted to the user-roles. */
  return rVal;
}

/**********************************************************************************************************************
 *  RightsM_IsAccessRightGranted()
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
SSA_RIGHTSM_LOCAL FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_IsAccessRightGranted(
  uint8 diagnosticChannel,
  RightsM_AccessRights_SidType sid,
  RightsM_AccessRights_SubFuncType subFunc,
  RightsM_AccessRights_IdType id)
{
  Std_ReturnType rVal;

  /* To verify access rights, the Standard Security Architecture shall evaluate the
  AccessControlLists in the following order:
  1. Enhanced AccessControlList
  2. Basic AccessControlList
  3. ECU-individual AccessControlList (SSA-IS-513) */

  /* #10 Verify access rights for the given service by evaluating the enhanced access control list. If no enhanced
   * access right is granted continue evaluating the other access control lists. */
  if (!RightsM_IsEnhancedAccessRightGranted(diagnosticChannel, sid, subFunc, id, RIGHTSM_CHECK_ALL))
  {
    RightsM_AccessRights_AccessRightsType accessRights;
    RightsM_DiagnosticUserRoleType currentUserRole;

    /* #20 If the considered channel is in an authenticated state get the current user role of the authenticated user
     * or tester, else set as current user role "anybody" */
    Rte_Enter_RightsM_ExclusiveArea();
    /* be less susceptible to memory manipulations: do not check for not equal to zero */
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
    if (RightsM_DiagChannelData[diagnosticChannel].authentication_State == RIGHTSM_CHANNEL_LOCALLY_AUTHENTICATED)
#else
    if ((RightsM_DiagChannelData[diagnosticChannel].authentication_State == RIGHTSM_CHANNEL_LOCALLY_AUTHENTICATED) || (RightsM_DiagChannelData[diagnosticChannel].authentication_State == RIGHTSM_CHANNEL_CENTRALLY_AUTHENTICATED))
#endif
    {
      currentUserRole = RightsM_DiagChannelData[diagnosticChannel].securitySettings.diagnosticUserRole;
      Rte_Exit_RightsM_ExclusiveArea();
    }
    else
    {
      Rte_Exit_RightsM_ExclusiveArea();
      /* Set user Role to anybody (SSA-IS-528). */
      currentUserRole = RIGHTSM_USERROLE_ANYBODY;
    }

    accessRights = 0x0000u;
    /* #30 Get the access rights granted to the current user-role by the basic ACL. */
    rVal = RightsM_GetAccessRights((P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_CONST))RightsM_BasicAcl, sid, subFunc, id, &accessRights);

    /* #35 If the diagnostic service to verify was not contained in the Basic AccessControlList
     * get the access rights granted to the current user-role by the ECU-individual ACL. */
    if (rVal > RIGHTSM_E_ACL_AUTHENTICATIONREQUIRED)
    {
      /* Mask result by binary and to get the highest priority result value */
      rVal &= RightsM_GetAccessRights(RightsM_EcuIndividualAcl, sid, subFunc, id, &accessRights);
    }

    /* #40 If the requested diagnostic service is contained in the AccessControlLists check the user role dependent access rights,
     *     else leave the return value as it is. */
    if (rVal == E_OK)
    {
      /* #50 Check if the current user qualifies to execute the service, i.e. check if the bit
       *     in access rights for the given user role is set. */
      if ((accessRights & ((RightsM_AccessRights_AccessRightsType)1u << currentUserRole)) == (RightsM_AccessRights_AccessRightsType)0u)
      {
        /* #60 If  the requested diagnostic service is contained in the access control lists but not available for the
         * current Diagnostic Channel, return "security access denied". */
        rVal = RIGHTSM_E_ACL_AUTHENTICATIONREQUIRED;
      }
    }
    /* #70 Set log entry if access is denied or not supported. */
    if (rVal != E_OK)
    {
      (void)Rte_Call_SecLog_RightsManagementEvent_RightsManagement(RightsM_GetDiagChanAndAuthenticationState(), sid, subFunc, id);
      RightsM_IsErrorLoggedBySsa = TRUE;
    }
  }
  else
  {
    /* Enhanced access right is granted. */
    rVal = E_OK;
  }

  return rVal;
}

/**********************************************************************************************************************
 *  RightsM_AppendDynamicallyDefinedIdentifier()
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
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_AppendDynamicallyDefinedIdentifier(RightsM_AccessRights_IdType ddid)
{
  Std_ReturnType rVal = E_OK;
  uint16 entryIdxDst;

  Rte_Enter_RightsM_ExclusiveArea();

  /* #10 Find next empty slot in the enhanced access control list for adding new entry.*/
  for (entryIdxDst = 0u; entryIdxDst < RIGHTSM_ENHANCED_ACCESS_RIGHTS_TABLE_NUM_ENTRIES; entryIdxDst++)
  {
    /* #20 For that check the size of the entry (i.e.) the first byte) if it is empty. */
    if (RightsM_EnhancedAccessRights[entryIdxDst][0u] == 0u)
    {
      /* Leave the for-loop. */
      break;
    }
  } /* end of for-loop */

  /* #30 If an empty slot has been found fill in the entry data, else reject the request. */
  if (entryIdxDst >= RIGHTSM_ENHANCED_ACCESS_RIGHTS_TABLE_NUM_ENTRIES)
  {
    /* conditions not correct */
    rVal = E_NOT_OK;
  }
  else
  {
    /* #40 Set byte 0  to 3 (size information). */
    RightsM_EnhancedAccessRights[entryIdxDst][0u] = 3u;
    /* #42 Set byte 1 to the  current diagnostic channel id. */
    /* using RightsM_CurrentDiagChanId in call context of Ssa_RightsM_ServiceRequestNotification_Indication, value chhecked */
    RightsM_EnhancedAccessRights[entryIdxDst][1u] = RightsM_CurrentDiagChanId;
    /* #44 Set byte 2 to service "ReadDataByIdentifier" (=0x22). */
    RightsM_EnhancedAccessRights[entryIdxDst][2u] = 0x22u;
    /* #46 Set byte 3 (id) to the high byte of the DDID. */
    RightsM_EnhancedAccessRights[entryIdxDst][3u] = (uint8)(ddid >> 8);
    /* #48 Set byte 4 (id) to the low byte of the DDID. */
    RightsM_EnhancedAccessRights[entryIdxDst][4u] = (uint8)(ddid & 0xFFu);
    /* #50 Set byte 4 (id) to 0 (unused). */
    RightsM_EnhancedAccessRights[entryIdxDst][5u] = 0x00u;
  }

  Rte_Exit_RightsM_ExclusiveArea();

  return rVal;
}

/**********************************************************************************************************************
 *  RightsM_ClearDynamicallyDefinedIdentifier()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_ClearDynamicallyDefinedIdentifier(RightsM_AccessRights_IdType ddid)
{
  Std_ReturnType rVal = E_NOT_OK;
  uint8 entryToFind[6];

  /* #10 Create entry data that shall be cleared. */
  entryToFind[0] = 0u;
  entryToFind[1] = 3u;
  entryToFind[2] = 0x22u;
  entryToFind[3] = (uint8)(ddid >> 8);
  entryToFind[4] = (uint8)(ddid & 0xFFu);
  entryToFind[5] = 0u;

  /* #20 Find and clear entry in the enhanced access control list. */
  if (RightsM_FindEnhancedAccessRightsEntry((P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))entryToFind, TRUE) == TRUE)
  {
    rVal = E_OK;
  }

  /* #30 Return result status. */
  return rVal;
}

/**********************************************************************************************************************
 *  RightsM_AccessRights_IsHashValueValid()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL FUNC(boolean, Ssa_RightsM_CODE) RightsM_AccessRights_IsHashValueValid(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) acl)
{
  Std_ReturnType retVal;
  uint8 aclHash[SSA_SIZEOF_HASHVALUE];
  uint32 aclHashLength = SSA_SIZEOF_HASHVALUE;
  boolean isValid = FALSE;

  /* #10 Calculate the Hash from the ACL's table values. */
  retVal = Rte_Call_SsaCdd_Csm_Hash(SSA_RIGHTSM_HASH_JOB_ID, CRYPTO_OPERATIONMODE_SINGLECALL, RightsM_AccessRights_VarIdPatTable(acl), RightsM_AccessRights_GetLengthOfTables(acl), aclHash, &aclHashLength);
  if ((retVal != E_OK) || (aclHashLength != SSA_SIZEOF_HASHVALUE))
  {
    /* Error. */
  }
  /* #20 Compare the calculated Hash value with the one from the ACL.*/
  else if (RightsM_CompareData((P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))RightsM_AccessRights_GetHash(acl), (P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))aclHash, SSA_SIZEOF_HASHVALUE) == FALSE)
  {
    /* Hashes differ. */
  }
  else
  {
    /* #30 Only if both hash values are equal return a positive response. */
    isValid = TRUE;
  }
  return isValid;
}

/**********************************************************************************************************************
 *  RightsM_AccessRights_DoDiagVariantAndVersionMatch()
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
SSA_RIGHTSM_LOCAL FUNC(boolean, Ssa_RightsM_CODE) RightsM_AccessRights_DoDiagVariantAndVersionMatch(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_CONST) acl, uint8 diagVariant, uint8 diagVersion)
{
  uint16 idx;
  boolean isFound = FALSE;

  /* #10 Check if access control list is available (null pointer check). */
  if (acl != NULL_PTR)
  {
    /* #20 If there is no variant id pattern sub-table all variants and versions are accepted. */
    if (RightsM_AccessRights_VarIdPatTable_GetNumItems(acl) == 0u)
    {
      isFound = TRUE;
    }
    /* #30 Else check Variant ID pattern table. */
    else
    {
      uint16 numVars = (uint16)RightsM_AccessRights_VarIdPatTable_GetNumItems(acl);
      /* #40 Iterate through the Variant ID pattern table. */
      for (idx = 0u; idx < numVars; ++idx) /* FETA_SSA_RIGHTSM_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
      {
        uint8 diagVar = RightsM_AccessRights_VarIdPatTable_GetVarIdPattern_DiagVariant(acl, idx);
        uint8 diagVer = RightsM_AccessRights_VarIdPatTable_GetVarIdPattern_DiagVersion(acl, idx);
        /* #50 Return TRUE if variant and version match. */
        if ((diagVar == diagVariant) &&
          ( diagVer == diagVersion))
        {
          /* Variant pattern has been found. Leave loop. */
          isFound = TRUE;
          break;
        }
      }
    }
  }
  return isFound;
}

/**********************************************************************************************************************
 *  RightsM_GetDiagChanAndAuthenticationState()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL FUNC(uint8, Ssa_RightsM_CODE) RightsM_GetDiagChanAndAuthenticationState(void)
{
  uint8 diagChanAndAuthStatus = 0x7Fu;
  uint8 currentDiagChanId;

  /* Keep diagnostic channel ID in a local buffer so it can't be modified in a different context. */
  currentDiagChanId = RightsM_CurrentDiagChanId;

  /* #10 Enter critical section (Reason: Ensuring consistency while reading diagnostic channel data). */
  Rte_Enter_RightsM_ExclusiveArea();

  /* #20 Check if there is a valid current diagnostic channel id. */
  if (RightsM_IsDiagChanValid(currentDiagChanId))
  {
    /* #30 Get diagnostic channel and authentication state. */
    diagChanAndAuthStatus = (uint8)(RightsM_CurrentDiagnosticChannel & 0x0Fu);
    if (RightsM_DiagChannelData[currentDiagChanId].authentication_State != RIGHTSM_CHANNEL_NOT_AUTHENTICATED)
    {
      diagChanAndAuthStatus |= (uint8)0x80u;
    }
  }
  /* #40 Leave critical section. */
  Rte_Exit_RightsM_ExclusiveArea();

  return diagChanAndAuthStatus;
}

/**********************************************************************************************************************
 *  RightsM_FindEnhancedAccessRightsEntry()
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
 */
SSA_RIGHTSM_LOCAL FUNC(boolean, Ssa_RightsM_CODE) RightsM_FindEnhancedAccessRightsEntry(P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) entryToFind, boolean clearEntry)
{
  uint16 entryIdxDst;
  boolean isFound;

  Rte_Enter_RightsM_ExclusiveArea();

  /* #10 Search through the enhanced access control list. */
  for (entryIdxDst = 0u; entryIdxDst < RIGHTSM_ENHANCED_ACCESS_RIGHTS_TABLE_NUM_ENTRIES; entryIdxDst++)
  {
    /* #20 Look at each entry of the enhanced access control list with size greater than zero. */
    if ((RightsM_EnhancedAccessRights[entryIdxDst][0u] > 0u)
      && (RightsM_EnhancedAccessRights[entryIdxDst][0u] == entryToFind[1]) /* size */
      && (RightsM_EnhancedAccessRights[entryIdxDst][1u] == RightsM_CurrentDiagChanId_Service))
    {
      boolean isEqual;
      /* #30 If the size and current diagnostic channel id are the same, compare the remaining bytes
       * depending on the entry's size. */
      switch (RightsM_EnhancedAccessRights[entryIdxDst][0u]) {
      case 4u:
        isEqual = ((RightsM_EnhancedAccessRights[entryIdxDst][5u] == entryToFind[5]) &&
                   (RightsM_EnhancedAccessRights[entryIdxDst][4u] == entryToFind[4]) &&
                   (RightsM_EnhancedAccessRights[entryIdxDst][3u] == entryToFind[3]) &&
                   (RightsM_EnhancedAccessRights[entryIdxDst][2u] == entryToFind[2])) ? TRUE : FALSE;
        break;
      case 3u:
        isEqual = ((RightsM_EnhancedAccessRights[entryIdxDst][4u] == entryToFind[4]) &&
                   (RightsM_EnhancedAccessRights[entryIdxDst][3u] == entryToFind[3]) &&
                   (RightsM_EnhancedAccessRights[entryIdxDst][2u] == entryToFind[2])) ? TRUE : FALSE;
        break;
      case 2u:
        isEqual = ((RightsM_EnhancedAccessRights[entryIdxDst][3u] == entryToFind[3]) &&
                   (RightsM_EnhancedAccessRights[entryIdxDst][2u] == entryToFind[2])) ? TRUE : FALSE;
        break;
      case 1u:
        isEqual = (RightsM_EnhancedAccessRights[entryIdxDst][2u] == entryToFind[2]) ? TRUE : FALSE;
        break;
      default:
        isEqual = FALSE;
        break;
      }
      if (isEqual == TRUE)
      {
        /* Entry with same content found. Leave the for-loop. */
        break;
      }
    }
  } /* end of for-loop */

  /* #50 If no entry with same content is found return FALSE. */
  if (entryIdxDst >= RIGHTSM_ENHANCED_ACCESS_RIGHTS_TABLE_NUM_ENTRIES)
  {
    isFound = FALSE;
  }
  /* #60 If entry found  (clear it if requested and) return TRUE. */
  else
  {
    if (clearEntry == TRUE)
    {
      RightsM_EnhancedAccessRights[entryIdxDst][0u] = 0u;
      RightsM_EnhancedAccessRights[entryIdxDst][1u] = 0u;
      RightsM_EnhancedAccessRights[entryIdxDst][2u] = 0u;
      RightsM_EnhancedAccessRights[entryIdxDst][3u] = 0u;
      RightsM_EnhancedAccessRights[entryIdxDst][4u] = 0u;
      RightsM_EnhancedAccessRights[entryIdxDst][5u] = 0u;
    }
    isFound = TRUE;
  }

  Rte_Exit_RightsM_ExclusiveArea();

  return isFound;
}

/**********************************************************************************************************************
 *  RightsM_Nonce_Get_RandomGenerate()
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
 */
SSA_RIGHTSM_LOCAL FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_Nonce_Get_RandomGenerate(
  boolean generateNew,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) nonce) /* PRQA S 0850 */ /* MD_MSR_MacroArgumentEmpty */
{
  Std_ReturnType retVal = E_OK;

  /* #10 Check if there is no valid nonce and if a newly generated nonce is requested. */
  if (Rte_Pim_RightsMNonce()->isValid == FALSE)
  {
    if (generateNew == TRUE)
    {
      /* #20 Generate a new nonce. */
#if (SSA_ENABLE_DEBUG_NONCE == STD_ON)                /* COV_SSA_DEBUG XF */
      uint8 nonceNew[SSA_SIZEOF_NONCE] = { 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu, 0xAAu };
      Ssa_MemCpy(nonce, (P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))nonceNew, SSA_SIZEOF_NONCE);
#else
      retVal = RightsM_CsmRandomGenerate(SSA_SIZEOF_NONCE, (P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR))nonce);

      if (retVal == SSA_E_PENDING)
      {
        /* No action. */
      }
      else if (retVal != E_OK)
      {
        retVal = E_NOT_OK;
        RightsM_Nonce_Get_State = RIGHTSM_ASYNC_STATE_IDLE;
      }
      else
#endif
      {
        /* #30 Enter critical section (Reason: Ensuring consistency while reading or writing nonce data). */
        Rte_Enter_RightsM_ExclusiveArea();
        /* #40 Locally store the newly generated nonce with a current time-stamp. */
        Ssa_MemCpy(Rte_Pim_RightsMNonce()->data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA))nonce, SSA_SIZEOF_NONCE);
        Rte_Pim_RightsMNonce()->timestamp = RightsM_CurrentTickCount;
        Rte_Pim_RightsMNonce()->isValid = TRUE;
        /* #50 Copy the RAM block to a RAM block mirror and change state.*/
        Ssa_MemCpy(Rte_Pim_RightsMNonceMirror()->data, Rte_Pim_RightsMNonce()->data, SSA_SIZEOF_NONCE);
        Rte_Pim_RightsMNonceMirror()->timestamp = Rte_Pim_RightsMNonce()->timestamp;
        Rte_Pim_RightsMNonceMirror()->isValid = Rte_Pim_RightsMNonce()->isValid;
        /* #60 Leave critical section */
        Rte_Exit_RightsM_ExclusiveArea();
        RightsM_Nonce_Get_State = RIGHTSM_ASYNC_STATE_NVM_WRITE;
      }
    }
    else
    {
      retVal = SSA_E_INVALID;
      RightsM_Nonce_Get_State = RIGHTSM_ASYNC_STATE_IDLE;
    }
  }
  else
  {
    /* retVal might be E_OK */
    RightsM_Nonce_Get_State = RIGHTSM_ASYNC_STATE_IDLE;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  RightsM_Nonce_Get()
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
 */
SSA_RIGHTSM_LOCAL FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_Nonce_Get(
  boolean generateNew,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) nonce) /* PRQA S 0850 */ /* MD_MSR_MacroArgumentEmpty */
{
  Std_ReturnType retVal = E_NOT_OK;
  uint64 tickCount = 0uLL;

  if (RightsM_Nonce_Get_State == RIGHTSM_ASYNC_STATE_IDLE)
  {
    /* #10 Get current local tick-count. */
    retVal = Rte_Call_TimeM_TickCount_Get(&tickCount);

    if (retVal == E_OK)
    {
      /* #20 Enter critical section (Reason: Ensuring consistency while reading or writing nonce data). */
      Rte_Enter_RightsM_ExclusiveArea();

      /* #25 Keep the tick-count for subsequent calls with operation status pending. */
      RightsM_CurrentTickCount = tickCount;

      if (Rte_Pim_RightsMNonce()->isValid == TRUE)
      {
        /* #30 If there is a valid nonce, i.e. its validity period has not elapsed, copy it to the provided output buffer. */
        if (RightsM_CurrentTickCount < Rte_Pim_RightsMNonce()->timestamp)
        {
          Rte_Pim_RightsMNonce()->isValid = FALSE;
        }
        else if ((RightsM_CurrentTickCount - Rte_Pim_RightsMNonce()->timestamp) > RIGHTSM_NONCE_VALID_TIME)
        {
          /* Validity period elapsed. */
          Rte_Pim_RightsMNonce()->isValid = FALSE;
        }
        else
        {
          /* Still valid. */
          Ssa_MemCpy(nonce, Rte_Pim_RightsMNonce()->data, SSA_SIZEOF_NONCE);
        }
      }
      /* #40 Leave critical section */
      Rte_Exit_RightsM_ExclusiveArea();

      RightsM_Nonce_Get_State = RIGHTSM_ASYNC_STATE_RAND_GEN;
    }
  }

  /* #50 Generate a new, random nonce if necessary. */
  if (RightsM_Nonce_Get_State == RIGHTSM_ASYNC_STATE_RAND_GEN)
  {
    retVal = RightsM_Nonce_Get_RandomGenerate(generateNew, nonce);
  }

  if ((RightsM_Nonce_Get_State == RIGHTSM_ASYNC_STATE_NVM_WRITE)
    || (RightsM_Nonce_Get_State == RIGHTSM_ASYNC_STATE_NVM_WAIT))
  {
    Std_ReturnType ret;
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;

    /* #60 Get status of NVRAM block. */
    ret = Rte_Call_NvMService_RightsM_Nonce_GetErrorStatus(&errorStatus);
    if ((ret == E_OK) && (errorStatus != NVM_REQ_PENDING))
    {
      /* #70 Write NV block if it has been started and do not change back to idle state as long as NVRAM block status is pending . */
      if (RightsM_Nonce_Get_State == RIGHTSM_ASYNC_STATE_NVM_WRITE)
      {
        if (Rte_Call_NvMService_RightsM_Nonce_WriteBlock((dtRef_const_VOID)(Rte_Pim_RightsMNonceMirror())) == E_OK) /* PRQA S 0314 */ /* MD_SSA_P2VOID_CAST */
        {
          RightsM_Nonce_Get_State = RIGHTSM_ASYNC_STATE_NVM_WAIT;
          retVal = SSA_E_PENDING;
        }
      }
      /* must be RIGHTSM_ASYNC_STATE_NVM_WAIT */
      else
      {
        RightsM_Nonce_Get_State = RIGHTSM_ASYNC_STATE_IDLE;
        if (errorStatus == NVM_REQ_OK)
        {
          retVal = E_OK;
        }
        else
        {
          /* Storing the new nonce in the NvM failed, return E_NOT_OK. */
          retVal = E_NOT_OK;
        }
      }
    }
    else
    {
      /* Stay in current state */
      retVal = SSA_E_PENDING;
    }
  }

  return retVal;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  RightsM_CsmRandomGenerate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_RIGHTSM_LOCAL FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_CsmRandomGenerate(
  const uint16 resultBufferLength,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) resultBuffer)
{
  Std_ReturnType retVal;
  boolean jobIsAsync;

#if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)
  jobIsAsync = TRUE;
  retVal = Ssa_AsyncPreAction(&RightsM_RandomGenerateAsyncState, jobIsAsync);
  if (retVal == E_OK)
#else
  jobIsAsync = FALSE;
  (void)Ssa_AsyncPreAction(&RightsM_RandomGenerateAsyncState, jobIsAsync);
#endif
  {
    RightsM_RandomGenerateResultLength = resultBufferLength;
    retVal = Rte_Call_CsmRandomGenerate_RandomGenerate(resultBuffer, &RightsM_RandomGenerateResultLength);

    Ssa_AsyncPostAction(&RightsM_RandomGenerateAsyncState, retVal, jobIsAsync);
  }

  retVal = Ssa_AsyncFinalize(&RightsM_RandomGenerateAsyncState, jobIsAsync);
  if (retVal == E_OK)
  {
    retVal = (uint8)((RightsM_RandomGenerateResultLength == resultBufferLength) ? E_OK : E_NOT_OK);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  RightsM_HandleTaskInitiateAuthentication_AfterCertVerification()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE)  RightsM_HandleTaskInitiateAuthentication_AfterCertVerification(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) dataTesterCert,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedTesterCert,
  P2CONST(RightsM_AuthNonceType, AUTOMATIC, AUTOMATIC) nonceStored,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) Verification_Result,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode)
{
  Std_ReturnType retVal;

  *Verification_Result = parsedTesterCert->verificationResult;

  /* #20 Adjust the local real-time. */
  retVal = RightsM_InitiateAuth_AdjustLocalTime(
    parsedTesterCert,
    nonceStored->validated,
    Verification_Result,
    ErrorCode);

  /* #30 Extract the needed data from diagnostic authentication certificate. */
  if (retVal == E_OK)
  {
    RightsM_InitiateAuth_ExtractDataFromTesterCert(
      dataTesterCert,
      parsedTesterCert);
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  RightsM_HandleTaskVerifyCertOwnership_PostCsmCall()
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
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE)  RightsM_HandleTaskVerifyCertOwnership_PostCsmCall(P2VAR(uint8, AUTOMATIC, AUTOMATIC) Verification_Result, P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Authentication_Result, P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode)
{
  SecLog_AuthenticationContentType authenticationContent;
  /* Set positive response as default value for error code. */
  *ErrorCode = DCM_E_POSITIVERESPONSE;

  /* #10 Clear challenge data (previously generated by ECU). */
  RightsM_SetDataBuffer(0x00, (P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR))&RightsM_DiagChannelData[RightsM_CurrentDiagChanId_Service].authentication_ChallengeEcu[0], SSA_RIGHTSM_SIZEOF_CHALLENGE_ECU);

  /* #20 Configure status record data: No data are returned. */
  *DataLength = 6u;
  RightsM_SetDataBuffer(0u, &Authentication_Result[0], *DataLength);

  /* #30 Set the current authentication state to locally authenticated. */
  Rte_Enter_RightsM_ExclusiveArea();
  RightsM_DiagChannelData[RightsM_CurrentDiagChanId_Service].authentication_ExpectedTask = SSA_AUTHENTICATE_INITIATE_AUTH_TASK;
  RightsM_DiagChannelData[RightsM_CurrentDiagChanId_Service].authentication_State = RIGHTSM_CHANNEL_LOCALLY_AUTHENTICATED;
  RightsM_DiagChannelData[RightsM_CurrentDiagChanId_Service].authenticationTimeoutTimer = SSA_RIGHTSM_AUTHENTICATION_TIMEOUT;
  /* #31 Set the source address as current diagnostic channel address. */
  RightsM_DiagChannelData[RightsM_CurrentDiagChanId_Service].currentDiagnosticChannel = RightsM_CurrentDiagnosticChannel;

  /* #35 Clear enhanced access rights. */
  RightsM_ClearEnhancedAccessRights(RightsM_CurrentDiagChanId_Service);

  /* #40 Adopt temporarily stored security settings. */
  RightsM_AdoptPreliminarySecuritySettings(RightsM_CurrentDiagChanId_Service);
  /* #50 Set verification result to ownership verified. */
  *Verification_Result = RIGHTSM_RES_OWNERSHIP_VERIFIED;

#if ( SSA_ECU_TYPE == SSA_ECU_TYPE_VSM )
  /* #60 ECU type is VSM: Trigger the sending of the authentication broadcast message in
   *     the main function if broadcast is allowed and overwrite verification result with
   *     'ownership verified and central authentication broadcast triggered'. */
  RightsM_TriggerCentralAuthenticationBroadcast();

  if (RightsM_IsBroadcastChannel(RightsM_CurrentDiagChanId_Service))
  {
    *Verification_Result = RIGHTSM_RES_OWNERSHIP_VERIFIED_CENTRAL_AUTH_BROADCAST_TRIGGERED;
  }
#endif
  Rte_Exit_RightsM_ExclusiveArea();

  /* #70 Write the security log containing the diagnostic certificate's serial number. */
  RightsM_CopyDataBuffer(authenticationContent, RightsM_DiagChannelData[RightsM_CurrentDiagChanId_Service].securitySettings.testerSerialNumber, SSA_SIZEOF_SERIALNUMBER);
  RightsM_SetDataBuffer(0xFFu, &authenticationContent[SSA_SIZEOF_SERIALNUMBER], SSA_SIZEOF_BACKEND_SERIALNUMBER);
  (void)Rte_Call_SecLog_SuccessfulAuthAndEnhanceRights_SuccessfulAuthAndEnhanceRights(
    RightsM_GetDiagChanAndAuthenticationState(), CERTP_PKI_ROLE_TESTER, authenticationContent);

  /* #80 Switch global authentication mode to authenticated. */
  (void)Rte_Switch_Authentication_Mode(RTE_MODE_RightsM_AuthenticationMode_RIGHTSM_AUTHENTICATED);
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 *  RightsM_HandleTaskAuthenticateStateIdle()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_HandleTaskAuthenticate_StateIdle(
  P2VAR(RightsM_AuthNonceType, AUTOMATIC, AUTOMATIC) Nonce,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) ParsedCert,
  uint8 Configuration,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Challenge_Certificate_Proof_of_Ownership,
  P2CONST(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode)
{
  /*@ assert $lengthOf(Challenge_Certificate_Proof_of_Ownership) >= sizeof(Dcm_Data4004ByteType); */ /* VCA_SSA_RIGHTSM_DATAPROOFOFOWNERSHIP_NOT_NULL */
  Std_ReturnType retVal;

  RightsM_Workspace.DataLength = 0u;
  Nonce->validated = FALSE;
  RightsM_Workspace.timeSetAfterValidNonce = FALSE;
  RightsM_Workspace.verifResult = RIGHTSM_RES_CERTIFICATE_VERIFIED_OWNERSHIP_VERIFICATION_NECESSARY;
  /* #10 Check the diagnostic authentication certificate sent from the diagnostic user or tester. */
  retVal = RightsM_InitiateAuth_CheckTesterCert( /* VCA_SSA_RIGHTSM_DATAPROOFOFOWNERSHIP_NOT_NULL */
    Configuration,
    Challenge_Certificate_Proof_of_Ownership,
    &RightsM_Workspace.verifResult,
    *DataLength,
    ParsedCert,
    Nonce,
    ErrorCode);

  /* #20 If checking the diagnostic authentication certificate has succeeded, change the asynchronous state to "verify certificate".
   *     If it has failed, change state back to "idle". */
  if (retVal != E_OK)
  {
    /* Error occurred. Verification is finished. Use returned NRC. */
    RightsM_Workspace.procState = CSM_ASYNC_IDLE;
  }
  else if (RightsM_Workspace.verifResult != CERTP_VER_PARSE_OK)
  {
    /* Check failed. Verification is finished. Use returned verification result. */
    RightsM_Workspace.procState = CSM_ASYNC_IDLE;
  }
  else
  {
    RightsM_Workspace.procState = CSM_ASYNC_VERIFY_CERTIFICATE;
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  RightsM_HandleTaskAuthenticate_StateCertificateVerify()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_HandleTaskAuthenticate_StateCertificateVerify(
  P2CONST(RightsM_AuthNonceType, AUTOMATIC, AUTOMATIC) Nonce,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) ParsedCert,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Challenge_Certificate_Proof_of_Ownership,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode)
{
  Std_ReturnType retVal;

  /* #10 Call the CSM signature verify function. */
  /* Check against RTE in buffer CertP_RawCertBufferType: Challenge_Certificate_Proof_of_Ownership: uint8* is of type Dcm_Data4004ByteType
     RightsM_Workspace.idxBufferIn points to second interation, first iteration (max 2 byte + 32 byte + 2 byte) is skipped */

  /*@ assert &Challenge_Certificate_Proof_of_Ownership[RightsM_Workspace.idxBufferIn] != NULL_PTR; */  /* VCA_SSA_RIGHTSM_ACCESS_CHALLENGE_CERTIFICATE_PROOF_OF_OWNERSHIP_AT_IDX */ 
  /*@ assert ParsedCert != NULL_PTR; */
  /*@ assert &Nonce != NULL_PTR; */
  /*@ assert $lengthOf(&Challenge_Certificate_Proof_of_Ownership[RightsM_Workspace.idxBufferIn]) >= sizeof(CertP_RawCertBufferType); */ /* VCA_SSA_RIGHTSM_ACCESS_CHALLENGE_CERTIFICATE_PROOF_OF_OWNERSHIP_AT_IDX */ 
  retVal = Rte_Call_KeyM_Certificate_VerifyCertWithBackendCert( /* VCA_SSA_RIGHTSM_ACCESS_CHALLENGE_CERTIFICATE_PROOF_OF_OWNERSHIP_AT_IDX */
    &Challenge_Certificate_Proof_of_Ownership[RightsM_Workspace.idxBufferIn],
    ParsedCert,
    ParsedCert->parsedCertLength,
    CERTP_PKI_ROLE_TESTER,
    Nonce);

  /* #20 Process return value and verification result. */
  if (retVal == RTE_E_KeyM_Certificate_E_PENDING)
  {
    RightsM_Workspace.procState = CSM_ASYNC_VERIFY_CERTIFICATE;
    retVal = RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_PENDING;
  }
  else if (retVal != E_OK)
  {
    RightsM_Workspace.procState = CSM_ASYNC_IDLE;
    *ErrorCode = DCM_E_GENERALREJECT;
  }
  else if (ParsedCert->verificationResult != CERTP_VER_OK)
  {
    RightsM_Workspace.verifResult = ParsedCert->verificationResult;
    RightsM_Workspace.procState = CSM_ASYNC_IDLE;
  }
  else
  {
    /* New asynchronous state is set within the function. */
    retVal = RightsM_HandleTaskInitiateAuthentication_AfterCertVerification(
      &Challenge_Certificate_Proof_of_Ownership[RightsM_Workspace.idxBufferIn],
      ParsedCert,
      Nonce,
      &RightsM_Workspace.verifResult,
      ErrorCode);

    if (retVal != E_OK)
    {
      retVal = E_NOT_OK;
      RightsM_Workspace.procState = CSM_ASYNC_IDLE;
    }
    else
    {
      RightsM_Workspace.verifResult = RIGHTSM_RES_CERTIFICATE_VERIFIED_OWNERSHIP_VERIFICATION_NECESSARY;
      RightsM_Workspace.procState = CSM_ASYNC_GENERATE_RANDOM;
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  RightsM_HandleTaskAuthenticate_HandleDeleteNonce()
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
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_HandleTaskAuthenticate_HandleDeleteNonce(
  P2CONST(RightsM_AuthNonceType, AUTOMATIC, AUTOMATIC) Nonce,
  P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) retVal)
{
  /* #10 Independently of the current state check if the stored nonce has been used and to be destroyed.
   *     Keep the current state.
   *     Since destroying the nonce is an asynchronous operation (i.e. leaving this routine is necessary),
   *     it is done right here after local data is not used any longer. */
  if ((RightsM_Workspace.procState == CSM_ASYNC_IDLE) || (RightsM_Workspace.procState == CSM_ASYNC_GENERATE_RANDOM))
  {
    if (Nonce->validated)
    {
      RightsM_Workspace.procState = (RightsM_Workspace.procState == CSM_ASYNC_IDLE) ? CSM_ASYNC_IDLE_DESTROY_NONCE : CSM_ASYNC_GENERATE_RANDOM_DESTROY_NONCE;
    }
  }

  /* #20 Destroy the locally stored nonce anyway. */
  if ((RightsM_Workspace.procState == CSM_ASYNC_IDLE_DESTROY_NONCE) || (RightsM_Workspace.procState == CSM_ASYNC_GENERATE_RANDOM_DESTROY_NONCE))
  {
    *retVal = Ssa_RightsM_Nonce_Destroy();
    if (*retVal == RTE_E_RightsM_Nonce_E_PENDING)
    {
      /* Stay in current state. */
      *retVal = RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_PENDING;
    }
    else
    {
      /* Change to next state. */
      RightsM_Workspace.procState = (RightsM_Workspace.procState == CSM_ASYNC_IDLE_DESTROY_NONCE) ? CSM_ASYNC_IDLE : CSM_ASYNC_GENERATE_RANDOM;
    }
  }
}

/**********************************************************************************************************************
 *  RightsM_HandleTaskAuthenticate_StateGenerateRandom()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_HandleTaskAuthenticate_StateGenerateRandom(
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Authentication_Result,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode)
{
  /* #10 Write length of challenge ECU in the first two bytes of the output buffer. */
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) challengeECU = &(Authentication_Result[2]);

  Std_ReturnType retVal = RightsM_CsmRandomGenerate(SSA_RIGHTSM_SIZEOF_CHALLENGE_ECU, challengeECU);

  if (retVal == SSA_E_PENDING)
  {
    RightsM_Workspace.procState = CSM_ASYNC_GENERATE_RANDOM;
    retVal = RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_PENDING;
  }
  else if (retVal != E_OK)
  {
    RightsM_Workspace.procState = CSM_ASYNC_IDLE;
    *ErrorCode = RIGHTSM_DCM_NRC_CHALLENGE_CALCULATION_FAILED;
  }
  else
  {
    Authentication_Result[0] = (uint8)(SSA_RIGHTSM_SIZEOF_CHALLENGE_ECU >> 8u); /*lint !e572 */ /* PRQA S 0499 */ /* MD_SSA_SHIFT_OPERATION */
    Authentication_Result[1] = (uint8)(SSA_RIGHTSM_SIZEOF_CHALLENGE_ECU & 0xFFu);
    RightsM_Workspace.DataLength = 2u;

    /* #20 Increase the total output buffer length by the size of the challenge. */
    RightsM_Workspace.DataLength += SSA_RIGHTSM_SIZEOF_CHALLENGE_ECU;

    Ssa_MemCpy((P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR))RightsM_DiagChannelData[RightsM_CurrentDiagChanId_Service].authentication_ChallengeEcu, challengeECU, SSA_RIGHTSM_SIZEOF_CHALLENGE_ECU);

    /* #30 Return "Certificate verified, Ownership verification necessary". */
    RightsM_SetDataBuffer(0u, &Authentication_Result[RightsM_Workspace.DataLength], 4u);
    RightsM_Workspace.DataLength += 4u;

    RightsM_Workspace.procState = CSM_ASYNC_IDLE;
    *DataLength = RightsM_Workspace.DataLength;

    /* No more data to append. */
  }

  return retVal;
}

/**********************************************************************************************************************
 *  RightsM_AuthDiagUserOrTester_HandleTaskAuthenticate()
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
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_AuthDiagUserOrTester_HandleTaskAuthenticate(
  uint8 Configuration,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Challenge_Certificate_Proof_of_Ownership,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Authentication_Result,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode)
{
  /*@ assert $lengthOf(Challenge_Certificate_Proof_of_Ownership) >= sizeof(Dcm_Data4004ByteType); */ /* VCA_SSA_RIGHTSM_DATAPROOFOFOWNERSHIP_NOT_NULL */
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_E_NOT_OK;

#if (SSA_KEEP_BUFFER_VARIABLES_STATIC == STD_OFF)
  CertP_ParsedCertStructureType parsedCert;

  /* satisfy QAC: initialize */
  RightsM_AuthNonceType nonceStored = { { 0u }, FALSE };

  parsedCert.parsedCertLength = 0u;
#endif

  /* #10 Handle the asynchronous state "idle". */
  if (RightsM_Workspace.procState == CSM_ASYNC_IDLE)
  {
    retVal = RightsM_HandleTaskAuthenticate_StateIdle(&RightsM_GetNonceStored(), &RightsM_GetParsedCert(), Configuration, Challenge_Certificate_Proof_of_Ownership, DataLength, ErrorCode); /* VCA_SSA_RIGHTSM_DATAPROOFOFOWNERSHIP_NOT_NULL */
  }

  /* #20 Handle the asynchronous states "verify certificate". */
  if (RightsM_Workspace.procState == CSM_ASYNC_VERIFY_CERTIFICATE)
  {
    retVal = RightsM_HandleTaskAuthenticate_StateCertificateVerify(&RightsM_GetNonceStored(), &RightsM_GetParsedCert(), Challenge_Certificate_Proof_of_Ownership, ErrorCode); /* VCA_SSA_RIGHTSM_DATAPROOFOFOWNERSHIP_NOT_NULL */
  }

  /* #30 Independently of the current state check if the stored nonce has been used and to be destroyed.
   *     Keep the current state.
   *     Since destroying the nonce is an asynchronous operation (i.e. leaving this routine is necessary),
   *     it is done right here after local data is not used any longer. */
  RightsM_HandleTaskAuthenticate_HandleDeleteNonce(&RightsM_GetNonceStored(), &retVal);

  /* #40 Generate challenge ECU from random data. */
  if (RightsM_Workspace.procState == CSM_ASYNC_GENERATE_RANDOM)
  {
    retVal = RightsM_HandleTaskAuthenticate_StateGenerateRandom(Authentication_Result, DataLength, ErrorCode);
  }

  return retVal;
}

/**********************************************************************************************************************
 *  RightsM_AuthDiagUserOrTester_HandleTaskProofOfOwnership()
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
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_AuthDiagUserOrTester_HandleTaskProofOfOwnership(
  uint8 Configuration,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Challenge_Certificate_Proof_of_Ownership,
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Authentication_Result,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode)
{
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_E_NOT_OK;

  if ((OpStatus == DCM_INITIAL) && (RightsM_Workspace.procState == CSM_ASYNC_IDLE))
  {
    uint16 proofOfOwnershipTesterLength;

    /* #10 Check the input data and get the proof of ownership (index and length). */
    RightsM_Workspace.verifResult = RIGHTSM_RES_OWNERSHIP_VERIFIED;
    retVal = RightsM_CheckAuthenticationInputData(
      Configuration,
      Challenge_Certificate_Proof_of_Ownership,
      *DataLength,
      &RightsM_Workspace.idxBufferIn,
      &proofOfOwnershipTesterLength,
      ErrorCode);

    if (retVal != E_OK)
    {
      retVal = RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_E_NOT_OK;
      /* Error occurred. Use returned NRC. */
      RightsM_Workspace.procState = CSM_ASYNC_IDLE;
    }
#if (SSA_ENABLE_DEBUG_AUTHENTICATION == STD_ON)       /* COV_SSA_DEBUG XF */
#else
    /* #20 Check length of proof of ownership. */
    else if (proofOfOwnershipTesterLength != SSA_SIZEOF_SIGNATURE)
    {
      retVal = RTE_E_OK;
      /* Verification is finished */
      RightsM_Workspace.procState = CSM_ASYNC_IDLE;
      Rte_Enter_RightsM_ExclusiveArea();
      /* #22 Discard temporarily stored security settings. */
      RightsM_ClearPreliminarySecuritySettings(RightsM_CurrentDiagChanId_Service);
      Rte_Exit_RightsM_ExclusiveArea();
      /* #24 Set verification result to ownership verification failed. */
      RightsM_Workspace.verifResult = RIGHTSM_RES_OWNERSHIP_VERIFICATION_FAILED;
    }
#endif
    else
    {
      RightsM_Workspace.procState = CSM_ASYNC_VERIFY_SIGNATURE;
    }
  }

  /* #30 Check if signature verification is prepared. */
  /* OpStatus might be INITIAL or PENNDING */
  if (RightsM_Workspace.procState == CSM_ASYNC_VERIFY_SIGNATURE)
  {
    Crypto_VerifyResultType csmVerifyResult;

    /* #40 Call the CSM signature verify function. */
    /* Verify proof of ownership. */
    retVal = RightsM_CsmSignatureVerify( /* VCA_SSA_RIGHTSM_ACCESS_CHALLENGE_CERTIFICATE_PROOF_OF_OWNERSHIP_AT_IDX */
      &(Challenge_Certificate_Proof_of_Ownership[RightsM_Workspace.idxBufferIn]),
      &csmVerifyResult);

    if (retVal == SSA_E_PENDING)
    {
      RightsM_Workspace.procState = CSM_ASYNC_VERIFY_SIGNATURE;
      retVal = RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_PENDING;
    }
#if (SSA_ENABLE_DEBUG_AUTHENTICATION == STD_ON)       /* COV_SSA_DEBUG XF */
#else
    else if (retVal != E_OK)
    {
      retVal = RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;

      Rte_Enter_RightsM_ExclusiveArea();
      /* #50 Discard temporarily stored security settings. */
      RightsM_ClearPreliminarySecuritySettings(RightsM_CurrentDiagChanId_Service);
      Rte_Exit_RightsM_ExclusiveArea();

      RightsM_Workspace.procState = CSM_ASYNC_IDLE;
    }
    else if (csmVerifyResult != CRYPTO_E_VER_OK)
    {
      Rte_Enter_RightsM_ExclusiveArea();
      /* #60 Discard temporarily stored security settings. */
      RightsM_ClearPreliminarySecuritySettings(RightsM_CurrentDiagChanId_Service);
      Rte_Exit_RightsM_ExclusiveArea();

      RightsM_Workspace.procState = CSM_ASYNC_IDLE;

      /* #70 Set verification result to ownership verification failed. */
      RightsM_Workspace.verifResult = RIGHTSM_RES_OWNERSHIP_VERIFICATION_FAILED;
    }
#endif
    else
    {
      RightsM_HandleTaskVerifyCertOwnership_PostCsmCall(&(RightsM_Workspace.verifResult), Authentication_Result, DataLength, ErrorCode);
      RightsM_Workspace.procState = CSM_ASYNC_IDLE;
    }
  }

  return retVal;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  RightsM_AuthDiagUserOrTester_HandleTaskDeauthenticate()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_AuthDiagUserOrTester_HandleTaskDeauthenticate(
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) Verification_Result,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Authentication_Result,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength)
{
  /* #10 Delete all security settings for the current diagnostic channel. */
  Rte_Enter_RightsM_ExclusiveArea();
  RightsM_DeAuthenticate(RightsM_CurrentDiagChanId_Service);
  RightsM_DiagChannelData[RightsM_CurrentDiagChanId_Service].authentication_ExpectedTask = SSA_AUTHENTICATE_INITIATE_AUTH_TASK;
  Rte_Exit_RightsM_ExclusiveArea();

  /* #20 Check and switch global authentication mode. */
  RightsM_DeAuthenticateGlobalMode();

  /* #30 Configure no data are returned in status record. */
  *DataLength = 6u;
  RightsM_SetDataBuffer(0u, &Authentication_Result[0], *DataLength);

  /* #40 Set verification result indicating de-authentication successful. */
  *Verification_Result = RIGHTSM_RES_DEAUTHENTICATION_SUCCESSFUL;
}

/**********************************************************************************************************************
 *  RightsM_AuthDiagUserOrTester_HandleTaskPostProcessing()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_AuthDiagUserOrTester_HandleTaskPostProcessing(
  P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) RetVal,
  uint8 Task,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) RoutineInfo,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Verification_Result,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) Authentication_Result,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) DataLength,
  Dcm_NegativeResponseCodeType LocalErrorCode,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode)
{
  /* #10 If retVal is PENDING, do nothing. */
  if (*RetVal != RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_PENDING)
  {
    /* #20 Else update *routineInfo always with 'sunccessfully completed'. */
    *RoutineInfo = SSA_ROUTINE_INFO_SUCCESFULLY_COMPLETED;

    if (!RightsM_IsDiagChanValid(RightsM_CurrentDiagChanId_Service))
    {
      /* Invalid channel, reject service. */
      *ErrorCode = DCM_E_GENERALREJECT;
      *RetVal = RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_E_NOT_OK;
    }
    else
    {
      /* Set return value depending on error code. */
      *ErrorCode = LocalErrorCode;
      if (LocalErrorCode == DCM_E_POSITIVERESPONSE)
      {
        /* #30 Set VerifyCertOwnership as next expected task. */
        if (RightsM_Workspace.verifResult == RIGHTSM_RES_CERTIFICATE_VERIFIED_OWNERSHIP_VERIFICATION_NECESSARY)
        {
          RightsM_DiagChannelData[RightsM_CurrentDiagChanId_Service].authentication_ExpectedTask = SSA_AUTHENTICATE_PROOF_OF_OWNERSHIP_TASK;
          *Verification_Result = RightsM_Workspace.timeSetAfterValidNonce ? SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFIED_TIME_SET : SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFIED_OWNERSHIP_VERIFICATION_NECESSARY;
        }
        else
        {
          RightsM_DiagChannelData[RightsM_CurrentDiagChanId_Service].authentication_ExpectedTask = SSA_AUTHENTICATE_INITIATE_AUTH_TASK;
          *Verification_Result = RightsM_Workspace.verifResult;
        }
        *RetVal = RTE_E_OK;
      }
      else
      {
        *RetVal = RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_E_NOT_OK;
      }

      /* #40 Clear authentication result if necessary. */
      if ((Task != SSA_AUTHENTICATE_INITIATE_AUTH_TASK)
        || ((*ErrorCode == DCM_E_POSITIVERESPONSE)
          && ((*Verification_Result != SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFIED_TIME_SET) && (*Verification_Result != SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFIED_OWNERSHIP_VERIFICATION_NECESSARY))))
      {
        /* No data are returned. */
        *DataLength = 6u;
        RightsM_SetDataBuffer(0u, &Authentication_Result[0], *DataLength);
      }
    }
  }
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  RightsM_ValidateAcl()
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
  */
SSA_RIGHTSM_LOCAL FUNC(boolean, Ssa_RightsM_CODE) RightsM_ValidateAcl(P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_CONST) acl, boolean checkVariantAndVersion)
{
  boolean isValid = FALSE;

  /* #10 Check that there is an access control list (ACL) (null pointer check). */
  if (acl == NULL_PTR)
  {
    /* There is no ACL. */
  }
  /* #20 Check that the version of the file format for 0x01, else the ACL is not accepted. */
  else if (RightsM_AccessRights_GetVersionFileFormat(acl) != (uint8)0x01u)
  {
    /* Version not valid. */
  }
  /* #30 Check that the access control list's hash value is valid, else the ACL is not accepted.. */
  else if (!RightsM_AccessRights_IsHashValueValid(acl))
  {
    /* Hash not valid. */
  }
  /* #40 If checking the variant and version is requested and if the access control list contains
   * a variant id pattern table, do the following: */
  else if ((checkVariantAndVersion == TRUE) && (RightsM_AccessRights_VarIdPatTable_GetNumItems(acl) > 0u))
  {
    uint8 diagVariant = 0u, diagVersion = 0u;

    /* #50 Get the ECU's diagnostic variant and version. */
    if (Rte_Call_Ssa_RightsM_DiagnosticInformation_Get(&diagVersion, &diagVariant) == RTE_E_OK)
    {
      /* #60  Verify that the diagnostic variant version of the ECU match to the diagnostic variant and version in the ACL. */
      if (!RightsM_AccessRights_DoDiagVariantAndVersionMatch(acl, diagVariant, diagVersion))
      {
        /* #70 If they do not match the access control list is not accepted. */
        /* #72 Set DEM event status for DTC 0x9A6857 to "failed". */
        (void)Rte_Call_DTC_0x9A6857_SetEventStatus(DEM_EVENT_STATUS_FAILED);
      }
      else
      {
        /* #80 If they do match the access control list is accepted. */
        isValid = TRUE;
        /* #82 Set DEM event status for DTC 0x9A6857 to "passed". */
        (void)Rte_Call_DTC_0x9A6857_SetEventStatus(DEM_EVENT_STATUS_PASSED);
      }
    }
    else
    {
      /* Failed to get the diagnostic version and diagnostic variant. */
    }
  }
  /* #90 Else the ACL is accepted independently of the ECU's diagnostic variant and version. */
  else
  {
    /* ACL accepted. */
    isValid = TRUE;
  }
  return isValid;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  RightsM_GetAccessRights_BisectTable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(boolean, Ssa_RightsM_CODE) RightsM_GetAccessRights_BisectTable(
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) left,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) right,
  uint16 middle,
  uint16 idFoundInTable,
  uint16 soughtId)
{
  boolean idFound = FALSE;

  /* #10 If the found ID is greater than the sought ID, continue search in left half only. */
  if (idFoundInTable > soughtId)
  {
    *right = middle;     /* Search in left part. */
  }
  /* #20 If the found ID is smaller than the sought ID, continue search in right half only. */
  else if (idFoundInTable < soughtId)
  {
    *left = middle + 1u;      /* Search in right part. */
  }
  /* #30 If the ID is found (at the middle index), return TRUE. */
  else
  {
    /* Middle is it. */
    idFound = TRUE;
  }

  return idFound;
}

/**********************************************************************************************************************
 *  RightsM_GetAccessRights_SidSubtable()
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
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_GetAccessRights_SidSubtable(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_CONST) acl,
  RightsM_AccessRights_SidType sid,
  P2VAR(RightsM_AccessRights_IdxType, AUTOMATIC, AUTOMATIC) startIdx,
  P2VAR(RightsM_AccessRights_IdxType, AUTOMATIC, AUTOMATIC) endIdx,
  P2VAR(RightsM_AccessRights_AccessRightsType, AUTOMATIC, AUTOMATIC) accessRights)
{
  Std_ReturnType rVal = E_OK;
  RightsM_AccessRights_AccessRightsType endIdxOrAccessRights = 0u;
  uint16 middle;
  uint16 left;
  uint16 right;
  boolean idFound;

  left = 0u;
  right = (uint16)RightsM_AccessRights_SidTable_GetNumItems(acl);

  /* Search as long as there is something to search in. */
  while (left < right) /* FETA_SSA_RIGHTSM_WHILE_LOOP_BINARY_SEARCH */
  {
    middle = (uint16)(left + ((uint16)(right - left) / 2u)); /* Divide in half.  */

    idFound = RightsM_GetAccessRights_BisectTable(&left, &right, middle, RightsM_AccessRights_SidTable_GetSid(acl, middle), (uint16)sid);
    if (idFound == TRUE)
    {
      /* Middle is it. */
      *startIdx = RightsM_AccessRights_SidTable_GetStartIdx(acl, (uint16)middle);
      endIdxOrAccessRights = RightsM_AccessRights_SidTable_GetEndIdx(acl, (uint16)middle);
      if (*startIdx == RIGHTSM_ACCESSRIGHTS_START_IDX_INVALID)
      {
        /* Get access rights. */
        *accessRights = endIdxOrAccessRights;
      }
      /* SID has been found. Leave loop. */
      break;
    }
  }

  if (left == right)
  {
    /* SID not found. Return. */
    rVal = RIGHTSM_E_ACL_SERVICENOTSUPPORTED;
  }

  *endIdx = endIdxOrAccessRights;
  return rVal;
}

/**********************************************************************************************************************
 *  RightsM_GetAccessRights_SubfuncSubtable()
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
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_GetAccessRights_SubfuncSubtable(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_CONST) acl,
  RightsM_AccessRights_SubFuncType subFunc,
  P2VAR(RightsM_AccessRights_IdxType, AUTOMATIC, AUTOMATIC) startIdx,
  P2VAR(RightsM_AccessRights_IdxType, AUTOMATIC, AUTOMATIC) endIdx,
  P2VAR(RightsM_AccessRights_AccessRightsType, AUTOMATIC, AUTOMATIC) accessRights)
{
  Std_ReturnType rVal = E_OK;
  RightsM_AccessRights_AccessRightsType endIdxOrAccessRights = 0u;
  uint16 middle;
  uint16 left;
  uint16 right;
  boolean idFound;

  /* #10 If start index equals the end index and if the sub-func value at this line is 0xFF get the start index and end
   * index for searching in the next sub-table. */
  if ((*startIdx == *endIdx) && (RightsM_AccessRights_SubFuncTable_GetSubFunc(acl, *endIdx) == RIGHTSM_ACCESSRIGHTS_SF_INVALID))
  {
    *startIdx = RightsM_AccessRights_SubFuncTable_GetStartIdx(acl, *endIdx);
    endIdxOrAccessRights = RightsM_AccessRights_SubFuncTable_GetEndIdx(acl, *endIdx);
  }
  else
  {
    left = *startIdx;
    right = *endIdx + 1u;

    /* Search as long as there is something to search in. */
    while (left < right) /* FETA_SSA_RIGHTSM_WHILE_LOOP_BINARY_SEARCH */
    {
      middle = (uint16)(left + ((uint16)(right - left) / 2u)); /* Divide in half.  */

      idFound = RightsM_GetAccessRights_BisectTable(&left, &right, middle, RightsM_AccessRights_SubFuncTable_GetSubFunc(acl, middle), (uint16)subFunc);
      if (idFound == TRUE)
      {
        /* Middle is it. */
        *startIdx = RightsM_AccessRights_SubFuncTable_GetStartIdx(acl, (uint16)middle);
        endIdxOrAccessRights = RightsM_AccessRights_SubFuncTable_GetEndIdx(acl, (uint16)middle);
        if (*startIdx == RIGHTSM_ACCESSRIGHTS_START_IDX_INVALID)
        {
          /* Get access rights. */
          *accessRights = endIdxOrAccessRights;
        }
        /* Sub-func has been found. Leave loop. */
        break;
      }
    }

    if (left == right)
    {
      /* Sub-func not found. Return. */
      rVal = RIGHTSM_E_ACL_SUBFUNCTIONNOTSUPPORTED;
    }
  }

  *endIdx = endIdxOrAccessRights;
  return rVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  RightsM_GetAccessRights_IdSubtable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_GetAccessRights_IdSubtable(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_CONST) acl,
  RightsM_AccessRights_IdType id,
  P2CONST(RightsM_AccessRights_IdxType, AUTOMATIC, AUTOMATIC) startIdx,
  P2VAR(RightsM_AccessRights_IdxType, AUTOMATIC, AUTOMATIC) endIdx,
  P2VAR(RightsM_AccessRights_AccessRightsType, AUTOMATIC, AUTOMATIC) accessRights)
{
  Std_ReturnType rVal = E_OK;
  RightsM_AccessRights_AccessRightsType endIdxOrAccessRights = 0u;
  uint16 middle;
  uint16 left;
  uint16 right;
  boolean idFound;

  left = *startIdx;
  right = *endIdx + 1u;

  /* Search as long as there is something to search in. */
  while (left < right) /* FETA_SSA_RIGHTSM_WHILE_LOOP_BINARY_SEARCH */
  {
    middle = (uint16)(left + ((uint16)(right - left) / 2u)); /* Divide in half.  */

    idFound = RightsM_GetAccessRights_BisectTable(&left, &right, middle, RightsM_AccessRights_IdTable_GetId(acl, middle), (uint16)id);
    if (idFound == TRUE)
    {
      /* Middle is it. */
      /* Get access rights. */
      *accessRights = RightsM_AccessRights_IdTable_GetAccessRights(acl, (uint16)middle);
      /* ID has been found. Leave loop. */
      break;
    }
  }

  if (left == right)
  {
    /* ID not found. Return. */
    rVal = RIGHTSM_E_ACL_IDNOTSUPPORTED;
  }

  *endIdx = endIdxOrAccessRights;
  return rVal;
}

/**********************************************************************************************************************
 *  RightsM_CheckEnhanceAccessCert()
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
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_CheckEnhanceAccessCert(P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Enhanced_Rights_Certificate, uint16 DataLength, P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedEnhanceAccessCert, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) errCode)
{
  uint16 certificateEnhanceAccessLength;
  Std_ReturnType retVal = E_OK;

  /* #10 Check that the data length of the input buffer is at least 2 byte (containing the certificate length), if not
   *     return NRC "incorrectMessageLengthOrInvalidFormat". */
  if (DataLength < (2u))
  {
    retVal = E_NOT_OK;
    *errCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {
    /* #20 Extract the length of the enhanced rights certificate length. */
    certificateEnhanceAccessLength = RightsM_GetUint16(Enhanced_Rights_Certificate[0], Enhanced_Rights_Certificate[1]);
    /* #30 Check that the input data length is at least 2 byte certificate length + X bytes certificate, if not return
     *     NRC "incorrectMessageLengthOrInvalidFormat". */
    if (DataLength < (2u + certificateEnhanceAccessLength))
    {
      retVal = E_NOT_OK;
      *errCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
    else
    {
      /* #40 Parse the enhanced rights certificate as attribute certificate. */
      /* Check against RTE in buffer CertP_RawCertBufferType: Enhanced_Rights_Certificate: uint8* is of type Dcm_Data2002ByteType */
      /*@ assert &(Enhanced_Rights_Certificate[2]) != NULL_PTR; */
      /*@ assert parsedEnhanceAccessCert != NULL_PTR; */
      if (Rte_Call_CertP_Functions_AttributeCertificate_Parse(&(Enhanced_Rights_Certificate[2]), certificateEnhanceAccessLength, parsedEnhanceAccessCert) != E_OK) /* VCA_SSA_RIGHTSM_NULL_PTR_REQUIREMENTS_VIOLATED */
      {
        parsedEnhanceAccessCert->verificationResult = CERTP_VER_INVALID_FORMAT;
        retVal = E_NOT_OK;
        /* #50 Return negative response code "general reject" if any error occurs. */
        *errCode = DCM_E_GENERALREJECT;
      }
      else if (parsedEnhanceAccessCert->verificationResult != CERTP_VER_PARSE_OK)
      {
        /* #60 Return verification result "invalid format" if the parse result is "not ok". */
        parsedEnhanceAccessCert->verificationResult = CERTP_VER_INVALID_FORMAT;
        retVal = E_NOT_OK;
      }
      else
      {
        /* #70 After the certificate has been successfully parsed check the authentication state for the current
         *     diagnostic channel. */
        if (RightsM_DiagChannelData[RightsM_CurrentDiagChanId_Service].authentication_State == RIGHTSM_CHANNEL_NOT_AUTHENTICATED)
        {
          retVal = E_NOT_OK;
          /* #72 If in "Unauthenticated State" return the verification result "Invalid Chain of Trust". */
          parsedEnhanceAccessCert->verificationResult = CERTP_VER_INVALID_CHAIN_OF_TRUST;
        }
      }
    }
  }

  /* #90 Verify the holder's serial number against the serial number of the diagnostic authentication certificate and
   * return the verification result "Invalid Chain of Trust" if it fails. */
  if (retVal == E_OK)
  {
    /* set default all zero since this is a prohibited value (MSS-10824 Specification for Certificate Structure V1.3) */
    uint8 holderSerialNum[SSA_SIZEOF_SERIALNUMBER] = { 0 };
    (void)RightsM_GetSerialNumberFromCert(&Enhanced_Rights_Certificate[2], &parsedEnhanceAccessCert->holderSerialNumber, holderSerialNum, SSA_SIZEOF_SERIALNUMBER);
    if (RightsM_CompareData(holderSerialNum, RightsM_DiagChannelData[RightsM_CurrentDiagChanId_Service].securitySettings.testerSerialNumber, SSA_SIZEOF_SERIALNUMBER) == FALSE)
    {
      retVal = E_NOT_OK;
      parsedEnhanceAccessCert->verificationResult = CERTP_VER_INVALID_CHAIN_OF_TRUST;
    }
  }

  return retVal;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  RightsM_VerifyEnhanceAccessCert()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_VerifyEnhanceAccessCert(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Enhanced_Rights_Certificate,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) ParsedCert,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode)
{
  Std_ReturnType retVal = E_OK;

  /* OpStatus might be INITIAL or PENDING */
  if (RightsM_Workspace.procState == CSM_ASYNC_VERIFY_CERTIFICATE)
  {
    RightsM_AuthNonceType  noNonce = { { 0u }, FALSE };

    /* #10 Verify the enhanced rights certificate's signature. */
    /* Check against RTE in buffer CertP_RawCertBufferType: Enhanced_Rights_Certificate: uint8* is of type Dcm_Data2002ByteType */

    /*@ assert &Enhanced_Rights_Certificate[2] != NULL_PTR; */
    /*@ assert ParsedCert != NULL_PTR; */
    /*@ assert &noNonce != NULL_PTR; */
    /*@ assert $lengthOf(&Enhanced_Rights_Certificate[2]) >= sizeof(CertP_RawCertBufferType); */ /* VCA_SSA_RIGHTSM_LENGTH_SPECIFIED_IN_FCT_CALL */
    retVal = Rte_Call_KeyM_Certificate_VerifyCertWithBackendCert( /* VCA_SSA_RIGHTSM_NULL_PTR_REQUIREMENTS_VIOLATED */
      &Enhanced_Rights_Certificate[2],
      ParsedCert,
      ParsedCert->parsedCertLength,
      CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS,
      &noNonce);

    if (retVal == RTE_E_KeyM_Certificate_E_PENDING)
    {
      RightsM_Workspace.procState = CSM_ASYNC_VERIFY_CERTIFICATE;
      retVal = RTE_E_RoutineServices_Routine_Enhance_Access_Rights_DCM_E_PENDING;
    }
    else if (retVal != RTE_E_OK)
    {
      RightsM_Workspace.procState = CSM_ASYNC_IDLE;
      retVal = RTE_E_RoutineServices_Routine_Enhance_Access_Rights_E_NOT_OK;
      *ErrorCode = DCM_E_GENERALREJECT;
    }
    else if (ParsedCert->verificationResult != CERTP_VER_OK)
    {
      RightsM_Workspace.verifResult = ParsedCert->verificationResult;
      RightsM_Workspace.procState = CSM_ASYNC_IDLE;
    }
    else
    {
      Std_ReturnType rVal;

      /* #20 Extract the list of additional diagnostic services from the Services field of the enhanced rights certificate. */
      rVal = RightsM_ExtractEnhancedAccessRights(&(Enhanced_Rights_Certificate[2]), ParsedCert, &(RightsM_Workspace.verifResult), ErrorCode);

      /* #30 If the rights enhancement has been successful write a security log entry containing the serial number from the certificate. */
      if (rVal == E_OK)
      {
        RightsM_LogSuccessfulEnhanceRightsEvent(&(Enhanced_Rights_Certificate[2]), ParsedCert);
      }

      /* #40 Change to idle state. */
      RightsM_Workspace.procState = CSM_ASYNC_IDLE;
    }
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  RightsM_ExtractEnhancedAccessRights_UpdateAccessRightsTable()
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
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_ExtractEnhancedAccessRights_UpdateAccessRightsTable(
  uint32 byteIdxSrc,
  uint8 sizeEntry,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) certificateEnhanceAccess,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) verResult,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) errCode)
{
  Std_ReturnType retVal = E_OK;
  uint16 entryIdxDst;

  /* #10 Check that no entry with same content is found. */
  if (!RightsM_FindEnhancedAccessRightsEntry(&certificateEnhanceAccess[byteIdxSrc], FALSE))
  {
    Rte_Enter_RightsM_ExclusiveArea();

    /* #20 Find next empty slot for the adding further entry by iterating through the enhance access control list and
     * searching an entry with size 0. */
    for (entryIdxDst = 0u; entryIdxDst < RIGHTSM_ENHANCED_ACCESS_RIGHTS_TABLE_NUM_ENTRIES; entryIdxDst++)
    {
      /* Check the size of the entry (the first byte) if empty. */
      if (RightsM_EnhancedAccessRights[entryIdxDst][0u] == 0u)
      {
        /* Leave the for-loop. */
        break;
      }
    } /* end of for-loop */

    /* #30 If an empty slot has been found, copy the identification data of the "enhanced"
     *     service to the enhance access control list. */
    if (entryIdxDst < RIGHTSM_ENHANCED_ACCESS_RIGHTS_TABLE_NUM_ENTRIES)
    {
      switch (sizeEntry) {
      case 4u:
        /* Copy byte 4. */
        RightsM_EnhancedAccessRights[entryIdxDst][5u] = certificateEnhanceAccess[byteIdxSrc + 5u];
        /* Fall through. */
      case 3u:                                                                                      /* PRQA S 2003 */ /* MD_SSA_SWITCH_FALLTHROUGH */
        /* Copy byte 3. */
        RightsM_EnhancedAccessRights[entryIdxDst][4u] = certificateEnhanceAccess[byteIdxSrc + 4u];
        /* Fall through. */
      case 2u:                                                                                      /* PRQA S 2003 */ /* MD_SSA_SWITCH_FALLTHROUGH */
        /* Copy byte 2. */
        RightsM_EnhancedAccessRights[entryIdxDst][3u] = certificateEnhanceAccess[byteIdxSrc + 3u];
        /* Fall through. */
      case 1u:                                                                                      /* PRQA S 2003 */ /* MD_SSA_SWITCH_FALLTHROUGH */
        /* Copy byte 1. */
        RightsM_EnhancedAccessRights[entryIdxDst][2u] = certificateEnhanceAccess[byteIdxSrc + 2u];
        /* Copy diagnostic channel id. */
        RightsM_EnhancedAccessRights[entryIdxDst][1u] = RightsM_CurrentDiagChanId_Service;
        /* Finally copy size information. */
        RightsM_EnhancedAccessRights[entryIdxDst][0u] = certificateEnhanceAccess[byteIdxSrc + 1u];
        break;
      default:
        /* #35 Set the verification result "Invalid format" if the entry size is not in [1,4]. */
        *verResult = CERTP_VER_INVALID_FORMAT;
        retVal = E_NOT_OK;
        break;
      }
    }
    /* #40 If no empty slot has been found, leave the function and return the negative response
     *     code "conditions not correct". */
    else
    {
      retVal = E_NOT_OK;
      *errCode = DCM_E_CONDITIONSNOTCORRECT;
    }

    Rte_Exit_RightsM_ExclusiveArea();
  }

  return retVal;
}

/**********************************************************************************************************************
 *  RightsM_ExtractEnhancedAccessRights()
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
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_ExtractEnhancedAccessRights(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) certificateEnhanceAccess,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedEnhanceAccessCert,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) verResult,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) errCode)
{
  StatusType retVal = E_OK;
  uint32 byteIdxSrc = parsedEnhanceAccessCert->service.elemDataIdx;
  uint8 sizeEntry = 0u;

  *verResult = CERTP_VER_OK;

  /* #10 Iterate through services element of the enhanced rights certificate raw data entry-by-entry. */
  while ((retVal == E_OK) /* FETA_SSA_RIGHTSM_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND_VARIABLE_INCREMENT */
    && ((byteIdxSrc - parsedEnhanceAccessCert->service.elemDataIdx + 1u) < (uint32)(parsedEnhanceAccessCert->service.elemDataLength)))
  {
    /* #20 Check for OCTET_STRING encoding tag and return verification result "invalid format" if different. */
    if (certificateEnhanceAccess[byteIdxSrc] == RIGHTSM_ASN1_TAG_OCTET_STRING)
    {
      /* #30 Get the size of the first entry (containing SID and/or sub-func and/or ID). */
      /* This access is still inside the element boundaries, since this is checked in the condition of the while loop. */
      sizeEntry = certificateEnhanceAccess[byteIdxSrc + 1u];

      /* Check that certificateEnhanceAccess[byteIdxSrc + sizeEntry + 1u] is a valid access inside
       * the service element boundaries in RightsM_ExtractEnhancedAccessRights_UpdateAccessRightsTable(). */
      if ((byteIdxSrc + (uint32)sizeEntry + 1u) < ((uint32)(parsedEnhanceAccessCert->service.elemDataIdx) + (uint32)(parsedEnhanceAccessCert->service.elemDataLength)))
      {
        /* #40 Update Access Rights Table with entries from enhanced access certificate. */
        retVal = RightsM_ExtractEnhancedAccessRights_UpdateAccessRightsTable(byteIdxSrc, sizeEntry, certificateEnhanceAccess, verResult, errCode);
      }
      else
      {
        *verResult = CERTP_VER_INVALID_FORMAT;
        retVal = E_NOT_OK;
      }

      if (retVal != E_OK)
      {
        /* Leave the while-loop. */
        break;
      }
    }
    else
    {
      /* Invalid format. */
      *verResult = CERTP_VER_INVALID_FORMAT;
      /* Leave the while-loop. */
      retVal = E_NOT_OK;
    }
    /* Set source index to next entry. */
    byteIdxSrc += (2u + (uint32)sizeEntry);
  } /* end of while-loop */

  /* #50 Store the target subject key identifier if there is one contained in the enhanced rights certificate. */
  if (retVal == E_OK)
  {
    if ((parsedEnhanceAccessCert->targetSubjectKeyIdentifier.validContent == TRUE) && (parsedEnhanceAccessCert->targetSubjectKeyIdentifier.elemDataLength == SSA_SIZEOF_CERT_SUBJECT_KEY_ID))
    {
      Rte_Enter_RightsM_ExclusiveArea();
      Ssa_MemCpy(
        (P2VAR(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR))&RightsM_TargetSubjectKeyIdentifier[0],
        &certificateEnhanceAccess[parsedEnhanceAccessCert->targetSubjectKeyIdentifier.elemDataIdx],
        parsedEnhanceAccessCert->targetSubjectKeyIdentifier.elemDataLength);
      RightsM_TargetSubjectKeyIdentifierValid = TRUE;
      Rte_Exit_RightsM_ExclusiveArea();
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 *  RightsM_GetSubfunc()
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
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_GetSubfunc(
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData,
  uint16 DataSize,
  P2VAR(RightsM_AccessRights_SubFuncType, AUTOMATIC, AUTOMATIC) subFunc,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) idIdx,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode)
{
  Std_ReturnType rVal = E_NOT_OK;
  *subFunc = 0xFFu;

  /* By default the id has to be read out at position 0. */
  *idIdx = 0u;

  /* #10 Filter for service identifiers depending on the position of the sub-function in the request data buffer. */
  switch (SID)
  {
  case 0x10:
  case 0x11:
  case 0x19:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2C:
  case 0x2A:
  case 0x31:
  case 0x3E:
  case 0x83:
  case 0x85:
  case 0x86:
  case 0x87:
    /* #20 The services 0x10, 0x11, 0x19, 0x27, 0x28, 0x29, 0x2C, 0x2A, 0x31, 0x3E, 0x83, 0x85, 0x86, 0x87 have a sub-function
     * at position 0. Service 0x31 has an ID in addition. */

    /* The id has to be read out at position 1. */
    *idIdx = 1u;
    if ((DataSize >= 3u) || ((SID != 0x31u) && (DataSize >= 1u)))
    {
      /* #25 To blind out the suppressPositiveResponse bit, the byte containing the sub-function
      parameter shall be calculated as "byte value AND 0x7F". */
      *subFunc = (RightsM_AccessRights_SubFuncType)(RequestData[0] & 0x7Fu);
      rVal = E_OK;
    }
    break;

  case 0x22:
  case 0x24:
  case 0x2E:
    /* #30 The service 0x22, 0x24, 0x2E have an ID (requiring two bytes). */
    if (DataSize >= 2u)
    {
      rVal = E_OK;
    }
    break;

  case 0x2Fu:
    /* #40 The service 0x2F has the so-called IOCP at position 2 (handled like sub-function). */
    if (DataSize >= 3u)
    {
      *subFunc = (RightsM_AccessRights_SubFuncType)(RequestData[2]);
      rVal = E_OK;
    }
    break;

  case 0x38u:
    /* #45 The service 0x38 has "MOOP" (mode of operation) at position 0 (handled like sub-function). */
    if (DataSize >= 1u)
    {
      *subFunc = (RightsM_AccessRights_SubFuncType)(RequestData[0]);
      rVal = E_OK;
    }
    break;

  default:
    /* #50 All other services have no sub-function but an ID, i.e. sub-function must be skipped and id has to be read out at position 0. */
    /* 0x01, 0x02, 0x03, 0x04, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x14, 0x23, 0x34, 0x35, 0x36, 0x37, 0x3D, 0x84, 0xB2, 0xB6, 0xB7 */
    rVal = E_OK;
    break;
  }

  /* #60 Check data size of services 0x22, 0x2A and 0x2C against configured maximum DID list length. */
  if (rVal == E_OK)
  {
    switch (SID)
    {
    case 0x22:
      /* RequestData = [DID1_HB|DID1_LB|DID2_HB|DID2_LB|...|DIDm_HB|DIDm_LB] */
      if (DataSize > (SSA_RIGHTSM_MAX_DID_LIST_LENGTH * 2u))
      {
        rVal = E_NOT_OK;
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      }
      break;
    case 0x2A:
      /* RequestData = [TM|PDID1|PDID2|...|PDIDm] */
      if (DataSize > (1u + (SSA_RIGHTSM_MAX_DID_LIST_LENGTH * 1u)))
      {
        rVal = E_NOT_OK;
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      }
      break;
    case 0x2C:
      /* RequestData = [SF|DDDDI_HB|DDDI_LB|SDI1_HB|SDI1_LB|PISDR1|MS1|...|SDIm_HB|SDIm_LB|PISDRm|MSm] */
      if (DataSize > (3u + (SSA_RIGHTSM_MAX_DID_LIST_LENGTH * 4u)))
      {
        rVal = E_NOT_OK;
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      }
      break;
    default:
      /* leave return value as it is */
      break;
    }
  }
  else
  {
    *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    RightsM_ChangeErrorCodeIfServiceNotSupported(SID, ErrorCode);
  }

  return rVal;
} /* PRQA S 6030, 6060 */ /* MD_MSR_STCYC, MD_MSR_STPAR */

/**********************************************************************************************************************
 *  RightsM_ChangeErrorCodeIfServiceNotSupported()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_ChangeErrorCodeIfServiceNotSupported(
  uint8 SID,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode)
{
  RightsM_AccessRights_AccessRightsType accessRights = 0;
  RightsM_AccessRights_IdxType startIdx = RIGHTSM_ACCESSRIGHTS_START_IDX_INVALID;
  RightsM_AccessRights_IdxType endIdx = 0;
  boolean isNotSupported = TRUE;

  /* #10 Check Basic ACL if the SID is supported. */
  if (RightsM_BasicAcl != NULL_PTR)
  {
    isNotSupported = (RightsM_GetAccessRights_SidSubtable(RightsM_BasicAcl, SID, &startIdx, &endIdx, &accessRights) == RIGHTSM_E_ACL_SERVICENOTSUPPORTED);
  }

  /* #20 Check Ecu indivicual ACL if the SID is supported. */
  if ((isNotSupported == TRUE) && (RightsM_EcuIndividualAcl != NULL_PTR))
  {
    isNotSupported = (RightsM_GetAccessRights_SidSubtable(RightsM_EcuIndividualAcl, SID, &startIdx, &endIdx, &accessRights) == RIGHTSM_E_ACL_SERVICENOTSUPPORTED);
  }

  /* #30 If not supported, switch NRC IncorrectMessageOrLength to ServiceNotSupported. */
  if (isNotSupported == TRUE)
  {
    *ErrorCode = DCM_E_SERVICENOTSUPPORTED;
  }
}

/**********************************************************************************************************************
 *  RightsM_ProcessRequestedSessionInfo()
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
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_ProcessRequestedSessionInfo(
  uint8 SID,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData,
  uint16 DataSize,
  uint16 SourceAddress,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) ErrorCode)
{
  Std_ReturnType rVal;

  /* #10 Set the lowest nibble of tester source address as current diagnostic channel address. */
  RightsM_CurrentDiagnosticChannel = (uint8)(SourceAddress & 0x0Fu);
  /* #20 Evaluate the access rights for the requested diagnostic service. */
  rVal = RightsM_EvaluateAccessRightsForDiagService(SID, RequestData, DataSize, ErrorCode);

#if (SSA_ENABLE_DEBUG_RIGHTS == STD_ON)               /* COV_SSA_DEBUG XF */
  rVal = E_OK;
#endif

  /* #30 Continue function only if access rights evaluation was successful. */
  if (rVal == E_OK)
  {
    Rte_Enter_RightsM_ExclusiveArea();
    /* using RightsM_CurrentDiagChanId only in call context of Ssa_RightsM_ServiceRequestNotification_Indication,
     * RightsM_CurrentDiagChanId has been checked for validity at the beginning of Ssa_RightsM_ServiceRequestNotification_Indication,
     * being in an exclusive area here. */

    /* #40 Store information that default session is requested (for knowing later that session state is not changed
     *     due to S3 timeout). Blind out the suppressPositiveResponse bit when evaluating the diagnostic session type.
     *     Clear default session request flag for session types other than default session. */
    if (SID == SSA_RIGHTSM_DIAG_SERVICE_SESSION_CONTROL)
    {
      if (((*RequestData) & RIGHTSM_SF_MASK) == SSA_RIGHTSM_DIAG_SESSION_ID_DEFAULT)
      {
        /* The Standard Security Architecture shall not leave an Authenticated State when
         * performing a DiagnosticSessionControl(e.g. switch to defaultSession) (SSA-IS-488). */
        RightsM_DiagChannelData[RightsM_CurrentDiagChanId].defaultSessionRequestFlag = TRUE;
      }
      else
      {
        RightsM_DiagChannelData[RightsM_CurrentDiagChanId].defaultSessionRequestFlag = FALSE;

        if (((*RequestData) & RIGHTSM_SF_MASK) == SSA_RIGHTSM_DIAG_SESSION_ID_EXTENDED)
        {
          RightsM_ExtSessionDiagChanId_Requested = RightsM_CurrentDiagChanId;
          /*@ assert RightsM_IsDiagChanValid(RightsM_ExtSessionDiagChanId_Requested); */
        }
      }
    }
    else
    {
      /* No action. */
    }

    /* #50 If being locally authenticated reset the authentication timeout on reception of a valid diagnostic request SSA-IS-486 */
    if (RightsM_DiagChannelData[RightsM_CurrentDiagChanId].authentication_State == RIGHTSM_CHANNEL_LOCALLY_AUTHENTICATED)
    {
      /* Reset the authentication timeout. */
      RightsM_DiagChannelData[RightsM_CurrentDiagChanId].authenticationTimeoutTimer = 0u;
    }
    Rte_Exit_RightsM_ExclusiveArea();
  }

  return rVal;
}

/**********************************************************************************************************************
 *  RightsM_EvaluateAccessRightsForSid2C_InputCheck()
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
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_EvaluateAccessRightsForSid2C_InputCheck(
P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData,
  uint16 DataSize,
  RightsM_AccessRights_SubFuncType subFunc,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) idIdx,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode,
  P2VAR(RightsM_AccessRights_IdType, AUTOMATIC, AUTOMATIC) DDID)
{
  Std_ReturnType rVal;

  /* #10 Check that the sub-func is either 0x01 or 0x03. Return NRC "subfunction not supported" if not. */
  if ((subFunc != 0x01u) && (subFunc != 0x03u))
  {
    *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
    rVal = E_NOT_OK;
  }
  /* #20 Check that the service "clear all DDIDs" is not requested. Return NRC "service not supported" if not. */
  else if ((subFunc == 0x03u) && (DataSize == 1u))
  {
    /* Clear all DDIDs. Feature not supported. */
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    rVal = E_NOT_OK;
  }
  /* #30 Check that the data size is sufficient to read the DDID. */
  else if (DataSize <= (*idIdx + 1u))
  {
    *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    rVal = E_NOT_OK;
  }
  /* #40 Handle the  DDID service. */
  else
  {
    /* #50 Compose the DDID from the next two bytes of the RequestData. */
    *DDID = RightsM_GetUint16(RequestData[*idIdx], RequestData[*idIdx + 1u]);
    *idIdx += 2u;

    /* #52 Check that the high byte of the DDID is either 0xF2 or 0xF3. Return NRC "request out of range" if not. */
    if (((uint8)(*DDID >> 8u) != 0xF2u) && ((uint8)(*DDID >> 8u) != 0xF3u))
    {
      *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
      rVal = E_NOT_OK;
    }
    /* #54 Check if the access rights for the service defined by (0x2C, sub-func, DDID) is granted. Leave the function
     * if access right is not granted. */
    else
    {
      /* using RightsM_CurrentDiagChanId only in call context of Ssa_RightsM_ServiceRequestNotification_Indication,
       * RightsM_CurrentDiagChanId has been checked for validity at the beginning of Ssa_RightsM_ServiceRequestNotification_Indication */
      rVal = RightsM_IsAccessRightGranted(RightsM_CurrentDiagChanId, 0x2Cu, subFunc, *DDID);
      /* rVal is either Missing access rights or service not supported  */
    }
  }

  return rVal;
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 *  RightsM_EvaluateAccessRightsForSid2C()
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
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_EvaluateAccessRightsForSid2C(
P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData,
  uint16 DataSize,
  RightsM_AccessRights_SubFuncType subFunc,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) idIdx,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode)
{
  Std_ReturnType rVal;
  RightsM_AccessRights_IdType id;
  RightsM_AccessRights_IdType DDID = 0xFFFFu;

  /* #10 Basic checks for all input parameters. */
  rVal = RightsM_EvaluateAccessRightsForSid2C_InputCheck(RequestData, DataSize, subFunc, idIdx, ErrorCode, &DDID);

  if (rVal == E_OK)
  {
    if (subFunc == 0x01u)
    {
      /* #20 If sub-func is 0x01 check if the access right for the service defined by (0x22, 0xFF, DDID) is granted.
       * Return NRC "request out of range" if it is granted or if access is denied. */

       /* using RightsM_CurrentDiagChanId only in call context of Ssa_RightsM_ServiceRequestNotification_Indication,
        * RightsM_CurrentDiagChanId has been checked for validity at the beginning of Ssa_RightsM_ServiceRequestNotification_Indication */
      rVal = RightsM_IsAccessRightGranted(RightsM_CurrentDiagChanId, 0x22u, 0xFFu, DDID);
      if (rVal <= RIGHTSM_E_ACL_AUTHENTICATIONREQUIRED)
      {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        rVal = E_NOT_OK;
      }
      else
      {
        rVal = E_OK;
      }

      /* #30 Iterate through the remaining data and get the identifiers. */
      while ((rVal == E_OK) && (*idIdx < DataSize))  /* FETA_SSA_RIGHTSM_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND_ADDITIONAL_STOP_COND */
      {
        if ((uint32)(DataSize) > ((uint32)(*idIdx) + 3u))
        {
          id = RightsM_GetUint16(RequestData[*idIdx], RequestData[*idIdx + 1u]);
          *idIdx += 4u; /* stepsize is 4 */
          /* #35 For each extracted ID check if access right is granted for the service defined by (0x22, 0xFF, id). */
          /* using RightsM_CurrentDiagChanId only in call context of Ssa_RightsM_ServiceRequestNotification_Indication,
           * RightsM_CurrentDiagChanId has been checked for validity at the beginning of Ssa_RightsM_ServiceRequestNotification_Indication */
          rVal = RightsM_IsAccessRightGranted(RightsM_CurrentDiagChanId, 0x22, 0xFF, id);
        }
        else
        {
          /* No ID could be read. */
          *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
          rVal = E_NOT_OK;
        }
      }

      if (rVal == E_OK)
      {
        /* #40 If for all checked services access rights are granted append DDID to the Enhanced AccessControlList. */
        if (RightsM_AppendDynamicallyDefinedIdentifier(DDID) != E_OK)
        {
          *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
          rVal = E_NOT_OK;
        }
      }
    }
    else
    {
      /* #50 If sub-func is 0x03 clear DDID from the Enhanced AccessControlList. */
      if (RightsM_ClearDynamicallyDefinedIdentifier(DDID) != E_OK)
      {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        rVal = E_NOT_OK;
      }
    }
  }

  return rVal;
}

/**********************************************************************************************************************
 *  RightsM_EvaluateAccessRightsForSid2A()
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
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_EvaluateAccessRightsForSid2A(P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData, uint16 DataSize, RightsM_AccessRights_SubFuncType subFunc, P2VAR(uint16, AUTOMATIC, AUTOMATIC) idIdx)
{
  Std_ReturnType rVal;
  RightsM_AccessRights_IdType id = 0xFFFFu;

  /* #10 Extract the ID from the RequestData. Though some services might not have an ID, compose an ID which is without
  * any effect since the ACL list does not have an ID in these cases. */
  if (DataSize > *idIdx)
  {
    id = (RightsM_AccessRights_IdType)0xF200u | RequestData[*idIdx];
    *idIdx += 1u;
  }

  /* #20 Check for service defined by SID, sub-func and ID if access right is granted. */
  /* using RightsM_CurrentDiagChanId only in call context of Ssa_RightsM_ServiceRequestNotification_Indication,
   * RightsM_CurrentDiagChanId has been checked for validity at the beginning of Ssa_RightsM_ServiceRequestNotification_Indication */
  rVal = RightsM_IsAccessRightGranted(RightsM_CurrentDiagChanId, 0x2A, subFunc, id);

  /* #30 Iterate for the service 0x2A through the remaining data and check the identifiers. */
  while ((rVal == E_OK) && (*idIdx < DataSize)) /* FETA_SSA_RIGHTSM_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND_FROM_PASSED_POINTER */
  {
    /* #31 Get the ID. */
    id = (RightsM_AccessRights_IdType)0xF200u | RequestData[*idIdx];
    /* step-size is 1 */
    *idIdx += 1u;
    /* #32 Check if access right is granted. */
    /* using RightsM_CurrentDiagChanId only in call context of Ssa_RightsM_ServiceRequestNotification_Indication,
     * RightsM_CurrentDiagChanId has been checked for validity at the beginning of Ssa_RightsM_ServiceRequestNotification_Indication */
    rVal = RightsM_IsAccessRightGranted(RightsM_CurrentDiagChanId, 0x2A, subFunc, id);
  }

  /* #40 Return the return value for the check if access right is granted. */
  return rVal;
}

/**********************************************************************************************************************
 *  RightsM_EvaluateAccessRights()
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
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_EvaluateAccessRights(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData, uint16 DataSize, RightsM_AccessRights_SubFuncType subFunc, P2VAR(uint16, AUTOMATIC, AUTOMATIC) idIdx, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode)
{
  Std_ReturnType rVal;
  RightsM_AccessRights_IdType id;

  /* #10 Extract the ID from the RequestData. Though some services might not have an ID, compose an ID which is without
   * any effect since the ACL list does not have an ID in these cases. */
  if (DataSize > (*idIdx + 1u))
  {
    id = RightsM_GetUint16(RequestData[*idIdx], RequestData[*idIdx + 1u]);
    /* step-size is 2 */
    *idIdx += 2u;
  }
  else
  {
    id = 0xFFFFu;
  }

  /* #20 Check for service defined by SID, sub-func and ID if access right is granted. */
  /* using RightsM_CurrentDiagChanId only in call context of Ssa_RightsM_ServiceRequestNotification_Indication,
   * RightsM_CurrentDiagChanId has been checked for validity at the beginning of Ssa_RightsM_ServiceRequestNotification_Indication */
  rVal = RightsM_IsAccessRightGranted(RightsM_CurrentDiagChanId, SID, subFunc, id);

  /* #25 Check if diagnostic service shall trigger a security log event in the confirmation function. */
  if (rVal == E_OK)
  {
    RightsM_CheckForDiagServiceToLog(SID, subFunc, id, RequestData, DataSize, idIdx);
  }

  /* #30 Iterate for the service 0x22 through the remaining data and check the identifiers. */
  while ((SID == 0x22u) && (rVal == E_OK) && (*idIdx < DataSize)) /* FETA_SSA_RIGHTSM_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND_ADDITIONAL_STOP_COND */
  {
    if (DataSize >(*idIdx + 1u))
    {
      /* #31 Get the ID. */
      id = RightsM_GetUint16(RequestData[*idIdx], RequestData[*idIdx + 1u]);
      /* step-size is 2 */
      *idIdx += 2u;
      /* #32 Check if access right is granted. */
      /* using RightsM_CurrentDiagChanId only in call context of Ssa_RightsM_ServiceRequestNotification_Indication,
       * RightsM_CurrentDiagChanId has been checked for validity at the beginning of Ssa_RightsM_ServiceRequestNotification_Indication */
      rVal = RightsM_IsAccessRightGranted(RightsM_CurrentDiagChanId, SID, subFunc, id);
    }
    else
    {
      /* No ID could be read. */
      *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      rVal = E_NOT_OK;
    }
  }

  /* #50 Return the return value for the check if access right is granted. */
  return rVal;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */

/**********************************************************************************************************************
 *  RightsM_EvaluateAccessRightsForDiagService()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(uint8, Ssa_RightsM_CODE) RightsM_EvaluateAccessRightsForDiagService(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData, uint16 DataSize, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode)
{
  Std_ReturnType rVal;
  RightsM_AccessRights_SubFuncType subFunc;
  uint16 idIdx = 0u;
  Dcm_NegativeResponseCodeType errorCode;

  /* #10 Get the sub-function resp. the IOCP of the requested diagnostic service. */
  rVal = RightsM_GetSubfunc(SID, RequestData, DataSize, &subFunc, &idIdx, &errorCode);

  /* For the security access the subfunction always has to be stored, in order to be able to log the correct security level in case of an error.
     The subfunction is stored at this position to not miss the error DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT. */
  if (SID == 0x27u)
  {
    RightsM_ServiceToFilterForData = subFunc;
  }

  if (rVal == E_NOT_OK)
  {
    *ErrorCode = errorCode;
  }
  /* #20 Depending on the SID handle the service concerning its access right. */
  else if (SID == 0x2Cu)
  {
    rVal = RightsM_EvaluateAccessRightsForSid2C(RequestData, DataSize, subFunc, &idIdx, ErrorCode);
  }
  else if (SID == 0x2Au)
  {
    rVal = RightsM_EvaluateAccessRightsForSid2A(RequestData, DataSize, subFunc, &idIdx);
  }
  else if ((SID >= 0x01u) && (SID <= 0x0Fu))
  {
    /* For OBD services do directly check if access rights are granted using the undefined SF and undefined Id. */
    /* using RightsM_CurrentDiagChanId only in call context of Ssa_RightsM_ServiceRequestNotification_Indication,
     * RightsM_CurrentDiagChanId has been checked for validity at the beginning of Ssa_RightsM_ServiceRequestNotification_Indication */
    rVal = RightsM_IsAccessRightGranted(RightsM_CurrentDiagChanId, SID, (RightsM_AccessRights_SubFuncType)0xFFu, (RightsM_AccessRights_IdType)0xFFFFu);
  }
  else if (SID == 0x38u)
  {
    /* For services that have a subfunction but no ID: using undefined ID */
    /* using RightsM_CurrentDiagChanId only in call context of Ssa_RightsM_ServiceRequestNotification_Indication,
     * RightsM_CurrentDiagChanId has been checked for validity at the beginning of Ssa_RightsM_ServiceRequestNotification_Indication */
    rVal = RightsM_IsAccessRightGranted(RightsM_CurrentDiagChanId, SID, subFunc, (RightsM_AccessRights_IdType)0xFFFFu);
  }
  else
  {
    rVal = RightsM_EvaluateAccessRights(SID, RequestData, DataSize, subFunc, &idIdx, ErrorCode);
  }

  return rVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  RightsM_InitiateAuth_CheckTesterCert()
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
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_InitiateAuth_CheckTesterCert(
  uint8 Configuration,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) Challenge_Certificate_Proof_of_Ownership,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) Verification_Result,
  uint16 DataLength,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedTesterCert,
  P2VAR(RightsM_AuthNonceType, AUTOMATIC, AUTOMATIC) nonceStored,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) errCode)
{
  Std_ReturnType retVal;
  uint16 certificateTesterIdx, certificateTesterLength;

  /* #10 Check input data and get the certificate data (index and length). */
  retVal = RightsM_CheckAuthenticationInputData(
    Configuration,
    Challenge_Certificate_Proof_of_Ownership,
    DataLength,
    &certificateTesterIdx,
    &certificateTesterLength,
    errCode);

  if (retVal == E_OK)
  {
    RightsM_Workspace.idxBufferIn = certificateTesterIdx;

    /* #40 Parse the tester certificate. */
    /* Check against RTE in buffer CertP_RawCertBufferType: Challenge_Certificate_Proof_of_Ownership: uint8* is of type Dcm_Data4004ByteType
      RightsM_Workspace.idxBufferIn points to second interation, first iteration (max 2 byte + 32 byte + 2 byte) is skipped */
    retVal = Rte_Call_CertP_Functions_Certificate_Parse(&Challenge_Certificate_Proof_of_Ownership[certificateTesterIdx], certificateTesterLength, parsedTesterCert); /* VCA_SSA_RIGHTSM_ACCESS_CHALLENGE_CERTIFICATE_PROOF_OF_OWNERSHIP_AT_IDX */
    *Verification_Result = parsedTesterCert->verificationResult;
    if ((retVal != E_OK) || (*Verification_Result != CERTP_VER_PARSE_OK) || (parsedTesterCert->publicKey.elemDataLength != SSA_SIZEOF_PUBLICKEY))
    {
      *Verification_Result = CERTP_VER_INVALID_FORMAT;
    }
    else
    {
      /* #50 Verify the tester certificate against the backend certificate. */
      if (parsedTesterCert->nonce.validContent == TRUE)
      {
        /* #60 If a nonce is contained in tester certificate, check if there is a valid nonce locally stored. If there
         * is no nonce locally stored set the verification result "nonce not accepted". */
        /* Get stored nonce, do not generate a new one. */
        if (RightsM_Nonce_Get(FALSE, nonceStored->data) == E_OK)
        {
          /* #64 Set the return value "nonce validated" to TRUE. */
          nonceStored->validated = TRUE;
        }
        else
        {
          *Verification_Result = SSA_VER_RES_AUTHENTICATE_SYNCHRONIZE_TIME_FAILED_NONCE_NOT_ACCEPTED;
        }
      }
    }
  }
  return retVal;
} /* PRQA S 6010, 6030, 6060 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_SSA_STPAR */

/**********************************************************************************************************************
 *  RightsM_InitiateAuth_AdjustLocalTime()
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
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_InitiateAuth_AdjustLocalTime(P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedTesterCert, boolean nonceValidated, P2VAR(uint8, AUTOMATIC, AUTOMATIC) Verification_Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode)
{
  Std_ReturnType retVal = E_OK;
  const TimeM_DateTimeType* notBefore = (const TimeM_DateTimeType*)&(parsedTesterCert->validNotBefore.dateTime);

  /* #10 Evaluate the "nonce validated" flag. */
  if (nonceValidated == TRUE)
  {
    /* #20 If a nonce has been successfully validated set the local real-time using the "notBefore" field of the
     *  tester certificate with change reason "nonce". */
    if (Rte_Call_TimeM_RealTime_Set(notBefore, TIMEM_REALTIMECHANGEREASON_NONCE) != E_OK)
    {
      *Verification_Result = SSA_VER_RES_AUTHENTICATE_SYNCHRONIZE_TIME_FAILED_NONCE_NOT_ACCEPTED;
      retVal = E_NOT_OK;
    }
    else
    {
      /* Keep info that time has been set after a valid nonce */
      RightsM_Workspace.timeSetAfterValidNonce = TRUE;
    }
  }
  else
  {
    /* #30 If no nonce has been successfully validated the local real-time may be only turned forward using the
     * "notBefore" field of the tester certificate. */
    TimeM_DateTimeType realTime;
    /* #40 For that get the current local real-time. */
    if (Rte_Call_TimeM_RealTime_Get(&realTime) != E_OK)
    {
      *ErrorCode = DCM_E_GENERALREJECT;
      retVal = E_NOT_OK;
    }
    else
    {
      boolean realTimeIsLessThanNotBefore = FALSE;
      /* #50 Check whether the locally stored real-time is less than that given by the "notBefore" field. */
      retVal = Rte_Call_TimeM_RealTime_Compare(&realTime, TIMEM_IS_LESS, notBefore, &realTimeIsLessThanNotBefore);
      if ((retVal == E_OK) && realTimeIsLessThanNotBefore)
      {
        /* #55 If the locally stored real-time is less set as new real-time the date and time given by the certificate's
         * "notBefore" field. */
        (void)Rte_Call_TimeM_RealTime_Set(notBefore, TIMEM_REALTIMECHANGEREASON_NOTBEFORE);
      }
    }
  }
  return retVal;
}

/**********************************************************************************************************************
 *  RightsM_InitiateAuth_ExtractDataFromTesterCert()
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
SSA_RIGHTSM_LOCAL FUNC(void, Ssa_RightsM_CODE) RightsM_InitiateAuth_ExtractDataFromTesterCert(P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) certificateTester, P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedTesterCert)
{
  uint16 byteIdx;

  /* Enter critical section (Reason: Ensuring consistency while reading or writing security settings data). */
  Rte_Enter_RightsM_ExclusiveArea();

  /* #10 Extract from the tester certificate and store the diagnostic user role for the current diagnostic channel. */
  RightsM_PreliminarySecuritySettings[RightsM_CurrentDiagChanId_Service].diagnosticUserRole = parsedTesterCert->userRole;

  /* #20 Extract from the tester certificate and store the tester certificate serial number for the current
   * diagnostic channel. */
  /* set default all zero since this is a prohibited value (MSS-10824 Specification for Certificate Structure V1.3) */
  RightsM_SetDataBuffer(0x0u, RightsM_PreliminarySecuritySettings[RightsM_CurrentDiagChanId_Service].testerSerialNumber, SSA_SIZEOF_SERIALNUMBER);
  (void)RightsM_GetSerialNumberFromCert(
    certificateTester,
    &parsedTesterCert->serialNumber,
    RightsM_PreliminarySecuritySettings[RightsM_CurrentDiagChanId_Service].testerSerialNumber,
    SSA_SIZEOF_SERIALNUMBER);

  /* 30 Extract from the tester certificate and store the public key for the current diagnostic channel. */
  for (byteIdx = 0u; byteIdx < SSA_SIZEOF_PUBLICKEY; byteIdx++)
  {
    RightsM_PreliminarySecuritySettings[RightsM_CurrentDiagChanId_Service].testerPublicKey[byteIdx] = certificateTester[parsedTesterCert->publicKey.elemDataIdx + byteIdx];
  }

  /* #40 Extract from the tester certificate and store the issuer of the tester certificate for the current diagnostic channel. */
  for (byteIdx = 0u; byteIdx < SSA_SIZEOF_ISSUER; byteIdx++)
  {
    if (byteIdx < parsedTesterCert->issuer.elemDataLength)
    {
      RightsM_PreliminarySecuritySettings[RightsM_CurrentDiagChanId_Service].testerIssuer[byteIdx] = certificateTester[parsedTesterCert->issuer.elemDataIdx + byteIdx];
    }
    else
    {
      /* #50 Terminate string resp. clear remaining bytes up to the maximum length of the issuer byte array. */
      RightsM_PreliminarySecuritySettings[RightsM_CurrentDiagChanId_Service].testerIssuer[byteIdx] = 0u;
    }
  }

  /* #60 Store if the authentication is restricted to an ECU for the current diagnostic channel.
   *     Restricted means: A target ECU is defined in the diag. auth. certificate or user role is
   *                       either SUPPLIER or DEV. ENHANCED. */
  RightsM_PreliminarySecuritySettings[RightsM_CurrentDiagChanId_Service].restrictedAuthentication =
    ((parsedTesterCert->targetECU.validContent)
    || (parsedTesterCert->userRole == RIGHTSM_USERROLE_SUPPLIER)
    || (parsedTesterCert->userRole == RIGHTSM_USERROLE_DEV_ENHANCED)) ? TRUE : FALSE;

  /* Leave critical section. */
  Rte_Exit_RightsM_ExclusiveArea();
}

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *  RightsM_IsBroadcastChannel()
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
SSA_RIGHTSM_LOCAL_INLINE FUNC(boolean, Ssa_RightsM_CODE) RightsM_IsBroadcastChannel(uint8 diagChan)
{
  /* #10 Check if authentication broadcast may be sent on the given diagnostic channel.
   *     The following conditions must be fulfilled: */
  return(
          /* #12 Diagnostic channel must be in authenticated state */
          (RightsM_DiagChannelData[diagChan].authentication_State == RIGHTSM_CHANNEL_LOCALLY_AUTHENTICATED) &&
          /* #14 Authentication must not be restricted to local ECU */
          (RightsM_DiagChannelData[diagChan].securitySettings.restrictedAuthentication == FALSE) &&
          /* #16 Diagnostic user role must be different from PRODUCTION or post production status must be deactivated */
          ((RightsM_DiagChannelData[diagChan].securitySettings.diagnosticUserRole != RIGHTSM_USERROLE_PRODUCTION) ||
            (*Rte_Pim_RightsMPostProductionStatus() == SSA_POST_PRODUCTION_STATUS_DEACTIVATED))) ? TRUE : FALSE;
}

/**********************************************************************************************************************
 *  RightsM_GetNextDiagChannelToSend()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(boolean, Ssa_RightsM_CODE)
    RightsM_GetNextDiagChannelToSend(P2VAR(uint8, AUTOMATIC, AUTOMATIC) nextChannelToSend)
{
  uint8 diagChanNext = SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 i;
  uint8 startOffest = 0u;
  boolean isFound = FALSE;

  /* #10 Check that a message has been already sent. */
  if (RightsM_DiagChanLastSentId != (uint8)SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS)
  {
    startOffest = RightsM_DiagChanLastSentId + 1u;
  }
  /* #20 Iterate over all diagnostic channels starting at the channel coming after the channel that last sent. */
  for (i = 0u; i <= SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS; ++i)
  {
    diagChanNext = (i + startOffest) % SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS;
    /* #30 Stop searching if a channel for broadcast is found. */
    if (RightsM_IsBroadcastChannel(diagChanNext))
    {
      /* #40 Assign the found channel id to out buffer. */
      *nextChannelToSend = diagChanNext;
      isFound = TRUE;
      break;
    }
  }


  return isFound;
}

#endif

/**********************************************************************************************************************
 * RightsM_CheckForDiagServiceToLog()
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
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_CheckForDiagServiceToLog(
  RightsM_AccessRights_SidType SID,
  RightsM_AccessRights_SubFuncType subFunc,
  RightsM_AccessRights_IdType id,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) RequestData,
  uint16 DataSize,
  P2CONST(uint16, AUTOMATIC, AUTOMATIC) idIdx)
{
  /* #10 Check service ID for RoutineControl. */
  if (SID == 0x31u)
  {
    switch (id)
    {
    /* #20 Identify and store RID 0x0242 (CLEAR_SAR_MEM). */
    case 0x0242u:
      RightsM_ServiceToFilterFor = RIGHTSM_SECLOG_BY_INDICATION_CLEAR_SAR_MEM_RID_0x0242;
      break;
    /* #22 Identify and store RID 0x0265 (ACT_DBG_IF). */
    case 0x0265u:
      RightsM_ServiceToFilterFor = RIGHTSM_SECLOG_BY_INDICATION_ACT_DBG_IF_RID_0x0265;
      break;
    /* #24 Identify and store RID 0xFF00 (ERASE_MEM). */
    case 0xFF00u:
      RightsM_ServiceToFilterFor = RIGHTSM_SECLOG_BY_INDICATION_ERASE_MEM_RID_0xFF00;
      if (DataSize > (*idIdx + 1u))
      {
        RightsM_ServiceToFilterForData = RequestData[*idIdx + 1u];
      }
      break;
    default:
      RightsM_ServiceToFilterFor = RIGHTSM_SECLOG_BY_INDICATION_NONE;
      break;
    }
  }
  /* #30 Check service ID for WriteByIdentifier and identify and store DID 0x0137 (CLEAR_SAR_MEM). */
  else if ((SID == 0x2Eu) && (id == 0x0137u))
  {
    RightsM_ServiceToFilterFor = RIGHTSM_SECLOG_BY_INDICATION_ENABLE_SAR_MEM_OVERWRITE_DID_0x0137;
    if (DataSize > (*idIdx))
    {
      RightsM_ServiceToFilterForData = RequestData[*idIdx];
    }
  }
  /* #40 Check SID and subfunction for service SecurityAccess sendKey. */
  else if ((SID == 0x27u) && ((subFunc&0x01u) == 0x00u))
  {
    RightsM_ServiceToFilterFor = RIGHTSM_SECLOG_BY_INDICATION_SECURITY_ACCESS_SEND_KEY;
  }
  else
  {
    RightsM_ServiceToFilterFor = RIGHTSM_SECLOG_BY_INDICATION_NONE;
  }
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 * RightsM_CsmSignatureVerify()
 *********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_CsmSignatureVerify(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) dataProofOfOwnership,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) csmVerifyResult)
{
  /*@ assert RightsM_CurrentDiagChanId_Service < SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS; */
  /*@ assert RightsM_DiagChannelData[RightsM_CurrentDiagChanId_Service].authentication_ChallengeEcu != NULL_PTR; */
  /*@ assert dataProofOfOwnership != NULL_PTR; */
  /*@ assert &RightsM_CsmVerificationResult != NULL_PTR; */
  Std_ReturnType retVal;
  boolean jobIsAsync;

  /* #10 This function is handling the states for asynchronously calling the CSM signature verify job. */
  /* Only called during authentication for proof of ownership. Thus no exclusive area needed for switching
   * from state Idle to Wait. */
#if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)
  jobIsAsync = TRUE;
  retVal = Ssa_AsyncPreAction(&RightsM_CsmSignatureVerifyAsyncState, jobIsAsync);
  if (retVal == E_OK)
#else
  jobIsAsync = FALSE;
  (void)Ssa_AsyncPreAction(&RightsM_CsmSignatureVerifyAsyncState, jobIsAsync);
#endif
  {
    retVal = Rte_Call_Key_SignatureRamKey_KeyElementSet(
        SSA_KE_SIGNATURE_KEY,
        RightsM_PreliminarySecuritySettings[RightsM_CurrentDiagChanId_Service].testerPublicKey,
        SSA_SIZEOF_PUBLICKEY);
    retVal |= Rte_Call_Key_SignatureRamKey_KeySetValid();

    if (retVal == E_OK)
    {
      retVal = Rte_Call_SsaCdd_Csm_SignatureVerify(
          SSA_RIGHTSM_SIGNATURE_VERIFY_JOB_ID,
          CRYPTO_OPERATIONMODE_SINGLECALL,
          RightsM_DiagChannelData[RightsM_CurrentDiagChanId_Service].authentication_ChallengeEcu,
          SSA_RIGHTSM_SIZEOF_CHALLENGE_ECU,
          dataProofOfOwnership,
          SSA_SIZEOF_SIGNATURE,
          &RightsM_CsmVerificationResult);
    }

    Ssa_AsyncPostAction(&RightsM_CsmSignatureVerifyAsyncState, retVal, jobIsAsync);
  }

  retVal = Ssa_AsyncFinalize(&RightsM_CsmSignatureVerifyAsyncState, jobIsAsync);
  if (retVal == E_OK)
  {
    *csmVerifyResult = RightsM_CsmVerificationResult;
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 * RightsM_LogSuccessfulEnhanceRightsEvent()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_LogSuccessfulEnhanceRightsEvent(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) enhancedRightsCertificate,
  P2CONST(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedEnhanceAccessCert)
{
  /* set default all zero since this is a prohibited value (MSS-10824 Specification for Certificate Structure V1.3) */
  SecLog_AuthenticationContentType authenticationContent;

  /* #10 Fill in data to be logged for a successful rights enhancement. */
  RightsM_SetDataBuffer(0xFFu, &authenticationContent[SSA_SIZEOF_SERIALNUMBER], SSA_SIZEOF_BACKEND_SERIALNUMBER);
  (void)RightsM_GetSerialNumberFromCert(
    enhancedRightsCertificate,
    &parsedEnhanceAccessCert->serialNumber,
    authenticationContent,
    SSA_SIZEOF_SERIALNUMBER);

  /* #20 Write the security log for event "Logging of successful authentication and enhance rights".  */
  (void)Rte_Call_SecLog_SuccessfulAuthAndEnhanceRights_SuccessfulAuthAndEnhanceRights(RightsM_GetDiagChanAndAuthenticationState(),
    CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS, authenticationContent);
}

/**********************************************************************************************************************
 * RightsM_ClearEnhancedAccessRights()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL FUNC(void, Ssa_RightsM_CODE) RightsM_ClearEnhancedAccessRights(uint8 diagnosticChannel)
{
  Ssa_EnhancedAccessRightsTableSizeOfRightsMType entryIdx;

  /* #20 Clear enhanced access control list for the given diagnostic channel id. */
  for (entryIdx = 0u; entryIdx < RIGHTSM_ENHANCED_ACCESS_RIGHTS_TABLE_NUM_ENTRIES; entryIdx++)
  {
    /* #30 Clear all entries with the requested diagnostic channel id. */
    if ((RightsM_EnhancedAccessRights[entryIdx][0u] != 0u) && (RightsM_EnhancedAccessRights[entryIdx][1u] == diagnosticChannel))
    {
      RightsM_EnhancedAccessRights[entryIdx][0u] = 0u;
      RightsM_EnhancedAccessRights[entryIdx][1u] = 0u;
      RightsM_EnhancedAccessRights[entryIdx][2u] = 0u;
      RightsM_EnhancedAccessRights[entryIdx][3u] = 0u;
      RightsM_EnhancedAccessRights[entryIdx][4u] = 0u;
      RightsM_EnhancedAccessRights[entryIdx][5u] = 0u;
    }
  }
}

#if ( SSA_ECU_TYPE == SSA_ECU_TYPE_VSM )

/**********************************************************************************************************************
 * RightsM_TriggerCentralAuthenticationBroadcast()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_TriggerCentralAuthenticationBroadcast(void)
{
  /* #10 Only if there is any channel to send the authentication broadcast on
   *     start the authentication broadcast timer (if not yet started)
   *     and let the next broadcast be on the current channel (if broadcast is allowed). */
  if (RightsM_CheckForActiveDiagnosticChannels() == TRUE)
  {
    if (RightsM_AuthenticationBroadcastTimer == 0u)
    {
      RightsM_AuthenticationBroadcastTimer = 1u;
      /* setting RightsM_DiagChanLastSentId to the channel id preceding the current channel id */
      RightsM_DiagChanLastSentId = (RightsM_CurrentDiagChanId_Service + (SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS - 1u)) %
                                   SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS;
    }
  }
  else
  {
    /* #20 Stop timer is there is no channel to send on found. */
    RightsM_AuthenticationBroadcastTimer = 0u;
  }
}

#endif

/**********************************************************************************************************************
 *  RightsM_CompressEnhancedAccessRightsTable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL FUNC(void, Ssa_RightsM_CODE) RightsM_CompressEnhancedAccessRightsTable(void)
{
  uint16 top = 0;
  uint16 bottom = RIGHTSM_ENHANCED_ACCESS_RIGHTS_TABLE_NUM_ENTRIES - 1u;
  uint8 index;

  /* #10 Iterate through enhanced access rights table starting at first entry. */
  while (top < bottom)  /* FETA_SSA_RIGHTSM_NESTED_LOOPS */
  {
    /* #20 If entry is empty move last filled entry to this position. */
    while ((RightsM_EnhancedAccessRights[top][0] == 0u) && (top < bottom)) /* FETA_SSA_RIGHTSM_NESTED_LOOPS */
    {
      if (RightsM_EnhancedAccessRights[bottom][0] != 0u)
      {
        for (index = 0; index < RIGHTSM_ENHANCED_ACCESS_ENTRY_SIZE; index++)
        {
          RightsM_EnhancedAccessRights[top][index] = RightsM_EnhancedAccessRights[bottom][index];

          /* Clean bottom */
          RightsM_EnhancedAccessRights[bottom][index] = 0;
        }
      }
      bottom--;
    }
    top++;
  }
}

/**********************************************************************************************************************
 * RightsM_GetSerialNumberFromCert()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_RIGHTSM_LOCAL FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_GetSerialNumberFromCert(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) certificate,
  P2CONST(CertP_BerElementType, AUTOMATIC, AUTOMATIC) certSerialNumber,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) serialNumber,
  uint16 serialNumberLength)
{
  Std_ReturnType retVal;

  /* #10 Convert Serial Number from certficate. */
  retVal = Ssa_Utils_ConvertSerialNumber(&certificate[certSerialNumber->elemDataIdx], certSerialNumber->elemDataLength,
                                   serialNumber, serialNumberLength);

  return retVal;
}

/**********************************************************************************************************************
 * RightsM_HandleNvm()
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
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_TimeM_CODE) RightsM_HandleNvm(void)
{
  Std_ReturnType ret;
  NvM_RequestResultType errorStatus = NVM_REQ_PENDING;

  /* #10 If the writing of NVRAM block has been requested and if writing is not ongoing copy the
  *     RAM block to a RAM block mirror. Then start the writing of the RAM block mirror to the NVM. */
  if ((RightsM_AclVersionNvmWriteRequested == TRUE) && (RightsM_AclVersionNvmWriteState == RIGHTSM_NVM_WRITE_STATE_IDLE))
  {
    Rte_Enter_RightsM_ExclusiveArea();
    /* there is no RAM block mirror */
    RightsM_AclVersionNvmWriteRequested = FALSE;
    RightsM_AclVersionNvmWriteState = RIGHTSM_NVM_WRITE_STATE_START;
    Rte_Exit_RightsM_ExclusiveArea();
  }

  /* #20 Check that writing to NVM has been started or is pending.*/
  if (RightsM_AclVersionNvmWriteState != RIGHTSM_NVM_WRITE_STATE_IDLE)
  {
    /* #30 Get status of NVRAM block. */
    ret = Rte_Call_NvMService_RightsM_AclVersion_GetErrorStatus(&errorStatus);
    if ((ret == E_OK) && (errorStatus != NVM_REQ_PENDING))
    {
      /* #40 Write NV block if it has been started and do not change back to idle state as long as NVRAM block status is pending . */
      if (RightsM_AclVersionNvmWriteState == RIGHTSM_NVM_WRITE_STATE_START)
      {
        if (Rte_Call_NvMService_RightsM_AclVersion_WriteBlock((dtRef_const_VOID)NULL_PTR) == E_OK) /* PRQA S 0314 */ /* MD_SSA_P2VOID_CAST */
        {
          RightsM_AclVersionNvmWriteState = RIGHTSM_NVM_WRITE_STATE_PENDING;
        }
      }
      /* must be RIGHTSM_NVM_WRITE_STATE_PENDING */
      else
      {
        RightsM_AclVersionNvmWriteState = RIGHTSM_NVM_WRITE_STATE_IDLE;
      }
    }
  }
  else
  {
    /* no action */
  }
} /* PRQA S 6010, 6030 */ /* MD_MSR_STPTH, MD_MSR_STCYC */

/**********************************************************************************************************************
 * RightsM_CheckMileage()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(void, Ssa_RightsM_CODE) RightsM_CheckMileage(void)
{
  Ssa_OdometerRecordType mileage;
  NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
  Std_ReturnType retVal;

  /* #10 Check if post production status stored in non-volatile memory is deactivated. */
  /* The Mirror RAM block is initialized with the post production status stored in non-volatile memory. */
  if (*Rte_Pim_RightsMPostProductionStatusMirror() == SSA_POST_PRODUCTION_STATUS_DEACTIVATED)
  {
    /* #20 Check if mileage has a valid value and has exceeded threshold. */
    /* Get the current value of the mileage. */
    retVal = Rte_Read_Ssa_BusOdometer_DI_Odo_Pr5_ST3(&mileage);
    if ((retVal == E_OK) &&
      (mileage.Odo_ST3 < SSA_RIGHTSM_MAX_MILEAGE_THRESHOLD) &&
      (mileage.Odo_ST3 > SSA_RIGHTSM_POST_PRODUCTION_STATUS_ACTIVATION_MILEAGE_THRESHOLD))
    {
      /* Write NV block once the NVRam block's status is not pending */
      retVal = Rte_Call_NvMService_RightsM_PostProductionStatus_GetErrorStatus(&errorStatus);
      if ((retVal == E_OK) && (errorStatus != NVM_REQ_PENDING))
      {
        /* #30 If post production status is deactivated and mileage has succeeded threshold,
         *     irreversibly activate the post production status. */
        *Rte_Pim_RightsMPostProductionStatusMirror() = SSA_POST_PRODUCTION_STATUS_IRREVERSIBLY_ACTIVATED;

        /* Write value of Ram Mirror to NV block. */
        /* if writing to NV block does not work, it will be tried again after next start-up */
        (void)Rte_Call_NvMService_RightsM_PostProductionStatus_WriteBlock(Rte_Pim_RightsMPostProductionStatusMirror()); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */

        /* Write value of Ram Mirror to RAM block. */
        *Rte_Pim_RightsMPostProductionStatus() = *Rte_Pim_RightsMPostProductionStatusMirror();
      }
    }
  }
}

#if (SSA_SECURITYACCESSLEVEL == STD_ON)
/**********************************************************************************************************************
 * RightsM_GetInternalIndexOfSecurityLevel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_GetInternalIndexOfSecurityLevel(uint8 secLevel, P2VAR(Ssa_SizeOfSecurityAccessLevelType, AUTOMATIC, AUTOMATIC) index)
{
  Ssa_SecurityAccessLevelIterType i;
  Std_ReturnType retVal;

  /* Get index of security level */
  for (i = 0u; i < (Ssa_SecurityAccessLevelIterType)SSA_RIGHTSM_NUMBER_SECURITY_ACCESS_LEVELS; i++)
  {
    if (Ssa_GetLevelOfSecurityAccessLevel(i) == secLevel)
    {
      /* break the for loop */
      break;
    }
  }

  if (i == (Ssa_SecurityAccessLevelIterType)SSA_RIGHTSM_NUMBER_SECURITY_ACCESS_LEVELS)
  {
    retVal = E_NOT_OK;
  }
  else
  {
    retVal = E_OK;
    *index = (Ssa_SizeOfSecurityAccessLevelType)i;
  }

  return retVal;
}

/**********************************************************************************************************************
 *  RightsM_CompareKeyByCsmSigVerify()
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
 */
SSA_RIGHTSM_LOCAL FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_CompareKeyByCsmSigVerify(
    uint8 secLevel,
    P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) key,
  Ssa_SizeOfSecurityAccessLevelType secLevelIdx,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_VAR) errorCode)
{
  Std_ReturnType retVal;
  Std_ReturnType rVal;

  boolean jobIsAsync;

  /* The %-Operator is used to satisfy static code analysis of array access. In the function
  * RightsM_GetInternalIndexOfSecurityLevel() it is checked, that the RightsM_SecLevelIndex
  * is not out of bounds.*/
  Ssa_SizeOfSecurityAccessLevelType secLevelIdxLocal =
    secLevelIdx % (Ssa_SizeOfSecurityAccessLevelType)SSA_RIGHTSM_NUMBER_SECURITY_ACCESS_LEVELS;
  /*@ assert secLevelIdxLocal < SSA_RIGHTSM_NUMBER_SECURITY_ACCESS_LEVELS; */ /* VCA_SSA_RIGHTSM_MODULO */

  /* #10 Asynchronously call Csm signature verify. */
# if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)
  jobIsAsync = TRUE;
  rVal = Ssa_AsyncPreAction(&RightsM_CompareKeyAsyncState, jobIsAsync);
  if (rVal == E_OK)
# else
  jobIsAsync = FALSE;
  (void)Ssa_AsyncPreAction(&RightsM_CompareKeyAsyncState, jobIsAsync);
# endif
  {
    RightsM_CompareKeyVerifResult = CRYPTO_E_VER_NOT_OK;
    rVal = Rte_Call_SsaCdd_Csm_SignatureVerify(
      Ssa_GetJobIdOfSecurityAccessLevel(secLevelIdxLocal),
      CRYPTO_OPERATIONMODE_SINGLECALL,
      &RightsM_SecAccess_StaticSeedArray[secLevelIdxLocal][0],
      SSA_SIZEOF_NONCE,
      key,
      SSA_SIZEOF_SIGNATURE,
      &RightsM_CompareKeyVerifResult);

    /* #20 Process the return value. */
    /* #30 Return error code "busy" and change asynchronous state back to "idle" if CSM returns "queue full" or
     * "busy". */
    Ssa_AsyncPostAction(&RightsM_CompareKeyAsyncState, rVal, jobIsAsync);
  }

  rVal = Ssa_AsyncFinalize(&RightsM_CompareKeyAsyncState, jobIsAsync);

  if (rVal == SSA_E_PENDING)
  {
    retVal = RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING;
  }
  else if (rVal == E_OK)
  {
    /* #40 Check verification result. */
    if (RightsM_CompareKeyVerifResult != CRYPTO_E_VER_OK)
    {
      /* Overwrite return value. */
      retVal = RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK;
      /* #50 If the signature verification is not successful send Return Code E_NOT_OK with NRC "invalidKey"
       *      to the DCM. */
      *errorCode = DCM_E_INVALIDKEY;
    }
    else
    {
      /* Overwrite return value. */
      retVal = RTE_E_OK;
      *errorCode = DCM_E_POSITIVERESPONSE;
      /* Communicate the Security Level via S/R port to the ECU. */
      /* According to DDS S-ISO14229 it is secLevel <= 0x30. */
      (void)Rte_Write_RightsM_SecurityLevelChange_currentLevel((uint8)((secLevel << 1u) - 1u)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */
      /* static seed may not be used again */
      if (Ssa_GetLevelOfSecurityAccessLevel(secLevelIdxLocal) == secLevel)
      {
        RightsM_SecAccessIsSeeded[secLevelIdxLocal] = FALSE;
      }
    }
  }
  else
  {
    /* #60 Reject the service and change asynchronous state back to "idle" if any other error occurs. */
    retVal = RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK;
    *errorCode = DCM_E_GENERALREJECT;
  }

  return retVal;
}
#endif

/**********************************************************************************************************************
 *  RightsM_NextIteration()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_RIGHTSM_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_NextIteration(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) data,
  uint16 dataLength,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) offset,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) iterationLength)
{
  CONST(uint16, AUTOMATIC) inOffset = *offset;
  uint16 outOffset = 0u;
  uint16 outIterationLength = 0u;
  Std_ReturnType retVal = E_NOT_OK;
  uint16 remainingDataLength = (uint16)(dataLength - inOffset); /* cannot underflow because of function specification */

  if (remainingDataLength >= 2u)
  {
    uint16 claimedIterationLength;

    claimedIterationLength = RightsM_GetUint16(data[inOffset], data[inOffset + 1u]);
    remainingDataLength -= 2u;

    if (remainingDataLength >= claimedIterationLength)
    {
      outIterationLength = claimedIterationLength;
      outOffset = inOffset + 2u;
      retVal = E_OK;
    }
  }

  *offset = outOffset;
  *iterationLength = outIterationLength;
  return retVal;
}

/**********************************************************************************************************************
 *  RightsM_CheckAuthenticationInputData()
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
SSA_RIGHTSM_LOCAL FUNC(Std_ReturnType, Ssa_RightsM_CODE) RightsM_CheckAuthenticationInputData(
  uint8 Configuration,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_RIGHTSM_APPL_DATA) DataIn,
  uint16 DataLength,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) idxData,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) lenData,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) errCode)
{
  Std_ReturnType retVal = E_NOT_OK;
  uint16 outIdxData = 0u;
  uint16 outLenData = 0u;

  if (!RightsM_IsUnidirectionalAuthentication(Configuration))
  {
    *errCode = DCM_E_REQUESTOUTOFRANGE;
  }
  else
  {
    uint16 offset = 0u;
    uint16 iterationLength = 0u;

    retVal = RightsM_NextIteration(DataIn, DataLength, &offset, &iterationLength);
    if (retVal != E_OK)
    {
      *errCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
    }
    else
    {
      if (RightsM_IsS29SubProcessing(Configuration)) /* PRQA S 2985 */ /* MD_SSA_REDUNDANT_OP_IN_MACRO */
      {
        outIdxData = offset;
        outLenData = iterationLength;
      }
      else
      {
        /* check for maximum length of challenge tester though it is skipped
         * but it must be ensured that the first iteration does not consume too much of the buffer
         * for following parse and verify calls that require an input buffer of size SSA_SIZEOF_CERT_MAX bytes */
        if (iterationLength > SSA_RIGHTSM_SIZEOF_CHALLENGE_TESTER)
        {
          *errCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        }
        else
        {
          offset += iterationLength; /* skip first iteration */
          retVal = RightsM_NextIteration(DataIn, DataLength, &offset, &iterationLength); /* VCA_SSA_RIGHTSM_OFFSET_BOUNDED_BY_DATALENGTH */
          if (retVal != E_OK)
          {
            *errCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
          }
          else
          {
            outIdxData = offset;
            outLenData = iterationLength;
          }
        }
      }
    }
  }

  *idxData = outIdxData;
  *lenData = outLenData;
  return retVal;
} /* PRQA S 6060, 6080 */ /* MD_SSA_STPAR, MD_MSR_STMIF */

#define Ssa_RightsM_STOP_SEC_CODE
#include "Ssa_RightsM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  SAFEBSW JUSTIFICATIONS
 *********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

  \ID  VCA_SSA_RIGHTSM_MODULO
    \DESCRIPTION      According to VCA, assertion (var < SOME_COSTANT) may fail.
    \COUNTERMEASURE   \R The value of var is the result of a modulo operation where the second operand is SOME_COSTANT.

  \ID  VCA_SSA_RIGHTSM_DATAPROOFOFOWNERSHIP_NOT_NULL
    \DESCRIPTION      According to VCA, assertions
                        - dataProofOfOwnership != NULL_PTR or
                        - $lengthOf(dataProofOfOwnership) >= sizeof(Dcm_Data4004ByteType)
                      may fail.
    \COUNTERMEASURE   \N It is ensured by specification and/or runtime checks that the assertions hold
                      when the respective function is called.

  \ID  VCA_SSA_RIGHTSM_OFFSET_BOUNDED_BY_DATALENGTH
    \DESCRIPTION      According to VCA, function RightsM_NextIteration() might be called outside its specification,
                      because the specification
                        *offset <= dataLength
                      is violated.
    \COUNTERMEASURE   \R The issue occurs in function RightsM_CheckAuthenticationInputData(), when
                      RightsM_NextIteration() is called a second time because the first iteration
                      contained in DataIn shall be skipped.
                      A runtime check within RightsM_NextIteration() ensures,
                      that if RightsM_NextIteration() returns with E_OK, DataIn is long enough to contain the
                      first iteration and two additional bytes storing the length completely.
                      (Hint: The runtime check ensures that
                        remainingDataLength = completeDataLength - 2 >= length of first iteration.)
                      If the first iteration shall be skipped, the offset is increased by the length
                      of the first iteration and hence equals (2 + the length of the first iteration).
                      Thus, when RightsM_NextIteration() is called again, it still holds that
                        newOffsetIn = 2 + length of first iteration <= remainingDataLength.

  \ID  VCA_SSA_RIGHTSM_ACCESS_CHALLENGE_CERTIFICATE_PROOF_OF_OWNERSHIP_AT_IDX
    \DESCRIPTION      According to VCA, the following functions might be called outside their specification:
                        - RightsM_CsmSignatureVerify(),
                        - Rte_Call_CertP_Functions_Certificate_Parse() and
                        - Rte_Call_KeyM_Certificate_VerifyCertWithBackendCert(),
                      i.e., the buffer passed to them as dataProofOfOwnership (or rawCertData or cert) may be a null pointer,
                      or when calling Rte_Call_KeyM_Certificate_VerifyCertWithBackendCert() the passed buffer 
                      &Challenge_Certificate_Proof_of_Ownership[RightsM_Workspace.idxBufferIn] is too small.
    \COUNTERMEASURE   \R The buffer passed to these functions is &(Challenge_Certificate_Proof_of_Ownership[<idx>]).
                       Buffer Challenge_Certificate_Proof_of_Ownership is at least of size sizeof(Dcm_Data4004ByteType).
                       This is ensured by a function specification at the outermost APIs.
                       Its actual length is given by parameter DataLength. This is ensured by specifications for
                       the calling functions (see below).
                       The issue occurs in three calling functions, namely
                       - RightsM_AuthDiagUserOrTester_HandleTaskProofOfOwnership(),
                       - RightsM_InitiateAuth_CheckTesterCert() and
                       - RightsM_HandleTaskAuthenticate_StateCertificateVerify().
                       In each of them, <idx> is set by a call to RightsM_CheckAuthenticationInputData().
                       Within this function, a runtime check ensures that if no error code is returned, it holds that
                       <idx> <= DataLength. This can be checked by reviewing VCA_SSA_RIGHTSM_OFFSET_BOUNDED_BY_DATALENGTH.
                       Only if no error occurs, the listed functions continue processing.
                       Thus, the function calls are valid.
                       Hint for RightsM_HandleTaskAuthenticate_StateCertificateVerify(): The call to
                       RightsM_CheckAuthenticationInputData(), in which <idx> is set, already occurs in
                       RightsM_HandleTaskAuthenticate_StateIdle(), following the same pattern as described above.
                       Only if no error was returned, RightsM_HandleTaskAuthenticate_StateCertificateVerify() is called.
                       Moreover, when calling Rte_Call_KeyM_Certificate_VerifyCertWithBackendCert() with buffer
                       &Challenge_Certificate_Proof_of_Ownership[RightsM_Workspace.idxBufferIn], RightsM_Workspace.idxBufferIn
                       points to second interation, first iteration (max 2 byte + 32 byte + 2 byte) is skipped. The length of 
                       first iteration is restricted to 32 byte by RightsM_CheckAuthenticationInputData() which is always called
                       before. The remaining buffer size is sufficiently large.

  \ID  VCA_SSA_RIGHTSM_NULL_PTR_REQUIREMENTS_VIOLATED
    \DESCRIPTION      According to VCA, the following functions might be called outside their specifications:
                        1. Rte_Call_CertP_Functions_AttributeCertificate_Parse
                        2. Rte_Call_KeyM_Certificate_VerifyCertWithBackendCert
    \COUNTERMEASURE   \R Before calling the functions, all function requirements (specified in Rte.vcaspecs.c) are checked by assertions:
                          1. - rawCertData != NULL_PTR;
                             - parsedCert != NULL_PTR;
                          2. - cert != NULL_PTR;
                             - parsedCertStructure != NULL_PTR
                             - expectedNonce != NULL_PTR;
                         If all assertions are okay, no specifications are violated.

  \ID  VCA_SSA_RIGHTSM_LENGTH_SPECIFIED_IN_FCT_CALL
    \DESCRIPTION      According to VCA, the following assertion is possibly violated:
                        $lengthOf(&Enhanced_Rights_Certificate[2]) >= sizeof(CertP_RawCertBufferType).
    \COUNTERMEASURE   \N A specification ensures that when the function is called,
                      $lengthOf(Enhanced_Rights_Certificate) >= sizeof(Dcm_Data2002ByteType) holds.
                      Since sizeof(CertP_RawCertBufferType) is hard-coded to 910 there is no violation.

  VCA_JUSTIFICATION_END */

/* FETA_JUSTIFICATION_BEGIN
  \ID FETA_SSA_RIGHTSM_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND
    \DESCRIPTION  According to FETA loop may not terminate
                  in function
                  - Ssa_RightsM_MainFunction()
                  - RightsM_IsEnhancedAccessRightGranted()
                  - RightsM_AccessRights_DoDiagVariantAndVersionMatch()
    \COUNTERMEASURE \N The here applied loop uses as upper bound a constant value or a variable that remains unchanged during loop
                       execution. The loop's type of the counter variable is appropriate for the loop's type of upper
                       bound value / variable and is increased once within each single loop (strictly monotonically increasing)
                       until it reaches a value that makes the loop stop without any occurences of overflows. This
                       is done by a comparison used as loop termination condition that considers the amount of the 
                       increment that is applied within each single loop.

  \ID FETA_SSA_RIGHTSM_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND_FROM_PASSED_POINTER
    \DESCRIPTION  According to FETA loop may not terminate
                  in function
                  - RightsM_EvaluateAccessRightsForSid2A()
    \COUNTERMEASURE \N The here applied loop uses a variable as upper bound that remains unchanged during loop
                       execution. The loop's type of the counter variable is appropriate for the loop's type of upper
                       bound variable and is increased once within each single loop (strictly monotonically increasing)
                       until it reaches a value that makes the loop stop without any occurences of overflows. This
                       is done by a comparison used as loop termination condition that considers the amount of the 
                       increment that is applied within each single loop.
                       The loop counter variable is passed by pointer to this function but points in the calling function
                       to a stack variable.

  \ID FETA_SSA_RIGHTSM_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND_VARIABLE_INCREMENT
    \DESCRIPTION  According to FETA loop may not terminate
                  in function
                  - RightsM_ExtractEnhancedAccessRights()
    \COUNTERMEASURE \N The here applied loop uses a value as upper bound that remains unchanged during loop
                       execution. The loop's type of the counter variable is appropriate for the loop's type of upper
                       bound variable and is increased once within each single loop by a value greater 1 (strictly monotonically increasing)
                       until it reaches a value that makes the loop stop without any occurences of overflows
                       which is ensured by doing the calculation on uint32.

  \ID FETA_SSA_RIGHTSM_MONOTONIC_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND_ADDITIONAL_STOP_COND
    \DESCRIPTION  According to FETA loop may not terminate
                  in function
                  - RightsM_EvaluateAccessRightsForSid2C()
                  - RightsM_EvaluateAccessRights()
    \COUNTERMEASURE \N The here applied loop uses a value as upper bound that remains unchanged during loop
                       execution. The loop's type of the counter variable is appropriate for the loop's type of upper
                       bound variable and is increased once within each single loop by constant value (strictly monotonically increasing)
                       until it reaches a value that makes the loop stop without any occurences of overflows
                       which is ensured by an additional condition within the loop which takes the increment into account for 
                       the comparison.
                       The loop counter variable is passed by pointer to this function but points in the calling function
                       to a stack variable.

  \ID FETA_SSA_RIGHTSM_NESTED_LOOPS
    \DESCRIPTION  According to FETA loop may not terminate
                  in function
                  - RightsM_CompressEnhancedAccessRightsTable()
    \COUNTERMEASURE \N Both outer and inner loop are controlled by a comparison of the variables top and bottom 'top < bottom'
                       which are of the same type.
                       The variable top remains unchanged during inner loop execution.
                       The variable bottom is decremented within each single inner loop execution (strictly monotonically decreasing)
                       until it reaches the value of top that makes the inner loop stop without any occurences of overflows.
                       The variable top is inremented within each single outer loop execution (strictly monotonically increasing)
                       until it reaches the value of bottom which might have been decreased by the inner loop  that makes the 
                       outer loop stop without any occurences of overflows.

  \ID FETA_SSA_RIGHTSM_WHILE_LOOP_BINARY_SEARCH
    \DESCRIPTION  According to FETA loop may not terminate
                  in function
                  - RightsM_GetAccessRights_SidSubtable()
                  - RightsM_GetAccessRights_SubfuncSubtable()
                  - RightsM_GetAccessRights_IdSubtable()
    \COUNTERMEASURE \N The here applied while loop is controlled by a comparison of the variables left and rigth 'top < bottom'
                       which are of the same type.
                       Within each signle loop execution:
                       - the value of variable middle, which is of an approriate type, is caluclated and then it is: left <= middle < right,
                       - RightsM_GetAccessRights_BisectTable is called and then it is
                         - either right becomes middle, so right decreases
                         - or left becomes (middle + 1), so left increases
                         - or idFound becomes TRUE which makes the loop stop by a call of break
                         So with each single loop the difference (right - left) becomes smaller (strictly monotonically decreasing) and 
                         the loop will finally stop after a maximum of (right - left) loop executions.
FETA_JUSTIFICATION_END */

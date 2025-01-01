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
/*!        \file  Ssa_SecLog.c
 *        \brief  Security Logging of the Standard Security Architecture (Ssa).
 *
 *      \details  The Security Logging provides interfaces to store occurred security relevant events.
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
 * Dem_InitMonitorReasonType
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
 * RightsM_AuthenticationModeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * SecOC_VerificationResultType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Ssa_IgnitionStatus_Prim
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
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
 * Ssa_ThresholdExceededType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Ssa_TickCountSyncStateType
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
 * BcTp_SecureBroadcastVerificationStatus
 *   Configuration Variant(s): Not in VSM.
 *
 * CSDataServices_DID_018B_SecOcDataID
 *   Reads the SecOcDataID as Environmental Data for DTC 0xD12083.
 *      Connect to corresponding Dem port.
 *
 * CallbackInitMonitorForEvent_DTC_0xD12083
 *   Notifies that this event is cleared, or that the operation (monitoring) cycle restarts.
 *      Connect to corresponding event of Dem.
 *
 * DTC_0xD12083
 *   Set an Event Status to failed if any one of the  PDU-specific counters exceeds its configured threshold.
 *      Connect to corresponding event of Dem.
 *
 * DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values
 *   Reads the current counter values of the security event log.
 *
 * DataServices_Security_Event_Log_Read_Security_Event_Log_Entry
 *   Reads security event log.
 *
 * NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif
 *   Controlling the NvM block which stores the security log data of event 10, "Failed PDU MAC verification".
 *      Connect to NvM block storing the the security log data of event 10.
 *
 * NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot
 *   Controlling the NvM block which stores the security log data of event 11, "Secure boot or authenticated boot".
 *      Connect to NvM block storing the the security log data of event 11.
 *
 * NvMService_SecLog_LogDataEvnt12_ChangeOfVin
 *   Controlling the NvM block which stores the security log data of event 12, "Change of VIN".
 *      Connect to NvM block storing the the security log data of event 12.
 *
 * NvMService_SecLog_LogDataEvnt13_AclReplacement
 *   Controlling the NvM block which stores the security log data of event 13, "ECU-individual AccessControlList replacement".
 *      Connect to NvM block storing the the security log data of event 13.
 *
 * NvMService_SecLog_LogDataEvnt1_FailedCertVerif
 *   Controlling the NvM block which stores the security log data of event 1, "Failed certificate verification".
 *      Connect to NvM block storing the the security log data of event 1.
 *
 * NvMService_SecLog_LogDataEvnt2_SucCertVerif
 *   Controlling the NvM block which stores the security log data of event 2, "Successful certificate verification".
 *      Connect to NvM block storing the the security log data of event 2.
 *
 * NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights
 *   Controlling the NvM block which stores the security log data of event 3, "Successful authentication and enhance rights".
 *      Connect to NvM block storing the the security log data of event 3.
 *
 * NvMService_SecLog_LogDataEvnt4_AuthBySecAccess
 *   Controlling the NvM block which stores the security log data of event 4, "Authorization by Security Access".
 *      Connect to NvM block storing the the security log data of event 4.
 *
 * NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec
 *   Controlling the NvM block which stores the security log data of event 5, "Successful diagnostic service execution".
 *      Connect to NvM block storing the the security log data of event 5.
 *
 * NvMService_SecLog_LogDataEvnt6_RightsMgmt
 *   Controlling the NvM block which stores the security log data of event 6, "Rights management".
 *      Connect to NvM block storing the the security log data of event 6.
 *
 * NvMService_SecLog_LogDataEvnt7_SigVerif
 *   Controlling the NvM block which stores the security log data of event 7, "Signature verification".
 *      Connect to NvM block storing the the security log data of event 7.
 *
 * NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime
 *   Controlling the NvM block which stores the security log data of event 8, "Change of tick count or date and time".
 *      Connect to NvM block storing the the security log data of event 8.
 *
 * NvMService_SecLog_LogDataEvnt9_SecOcMisconfig
 *   Controlling the NvM block which stores the security log data of event 9, "SecOC misconfiguration".
 *      Connect to NvM block storing the the security log data of event 9.
 *
 * NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1
 *   Controlling the NvM block which stores the security log data of counter Exceeded Threshold 1 (belonging to event 10, Failed PDU MAC verification).
 *      Connect to NvM block storing this data.
 *
 * NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2
 *   Controlling the NvM block which stores the security log data of counter Exceeded Threshold 2 (belonging to event 10, Failed PDU MAC verification).
 *      Connect to NvM block storing this data.
 *
 * NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3
 *   Controlling the NvM block which stores the security log data of counter Exceeded Threshold 3 (belonging to event 10, Failed PDU MAC verification).
 *      Connect to NvM block storing this data.
 *
 * SecLog_SuccessfulDiagServiceExecutionEvent_EcuSharedSecretDistribution
 *   Configuration Variant(s): Not in VSM.
 *
 * SecLog_SuccessfulDiagServiceExecutionEvent_EcuSharedSecretEncryption
 *   Configuration Variant(s): VSM only.
 *
 * SecLog_SuccessfulDiagServiceExecutionEvent_InjectSeed
 *   Configuration Variant(s): Not in VSM.
 *
 * SecLog_SuccessfulDiagServiceExecutionEvent_TrustModeEcuSharedSecretDistribution
 *   Configuration Variant(s): Not in VSM.
 *
 * SecLog_SuccessfulDiagServiceExecutionEvent_TrustModelEcuSharedSecretEncryption
 *   Configuration Variant(s): VSM only.
 *
 * SecLog_SuccessfulDiagServiceExecutionEvent_TrustModelEcuTickcountSynchronization
 *   Configuration Variant(s): VSM only.
 *
 * SecLog_SuccessfulDiagServiceExecutionEvent_VehicleSharedSecretDistribution
 *   Configuration Variant(s): VSM only.
 *
 * SecLog_SuccessfulDiagServiceExecutionEvent_VsmDeriveSymmetricKeys
 *   Configuration Variant(s): VSM only.
 *
 * SecLog_SuccessfulDiagServiceExecutionEvent_VsmRenewSharedSecret
 *   Configuration Variant(s): VSM only.
 *
 * SecOC_VerificationStatusIndication
 *   Notifies via client-server port about a failed SecOC Mac verification, collects the data and creates a security log event.
 *      Connect to SecOC indication port.
 *
 *
 * Data Element Prototypes:
 * ========================
 * Ign_Stat_Pr5_ST3 of Port Interface Ssa_IgnitionStatus
 *   Ignition switch state
 *
 *
 * Operation Prototypes:
 * =====================
 * VerifyStatus of Port Interface VerificationStatusIndication
 *   This service provides the ability to inform the application about the result of the verification attempt of a received PDU by the SecOC module.
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
 * Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast
 *   Configuration Variant(s): Not in VSM.
 *
 *********************************************************************************************************************/

#include "Rte_Ssa_SecLog.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Ssa_Cfg.h"
#include "Ssa_Utils.h"

#ifdef __VCA__  /* COV_SSA_VECTOR_CODE_ANALYZER_STUB_REDIRECTION */
# include "Ssa_SecLog_Redirection.vcaspecs.h"
#endif

/* After this comment only memory mapping files may be included. Due to this turn off lint rule requesting a standard
include guard. */
/*lint -e451 */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#if defined SSA_ENABLE_CANOE_DEBUG_OUTPUT   /* COV_SSA_DEBUG XF */
# define SECLOG_CANOE_DEBUGGING_OUTPUT                                        STD_ON
# include "CANoeApi.h"
#else
# define SECLOG_CANOE_DEBUGGING_OUTPUT                                        STD_OFF
#endif /* (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON) */

#if !defined (SSA_SECLOG_LOCAL)                 /* COV_SSA_LOCAL */
# define SSA_SECLOG_LOCAL                                                     static
#endif

#if !defined (SSA_SECLOG_LOCAL_INLINE)          /* COV_SSA_LOCAL_INLINE */
# define SSA_SECLOG_LOCAL_INLINE
#endif

/* Number of UIDs in logging of successful diagnostic service execution events. */
#define SECLOG_NUMBER_OF_DIAGNOSTIC_SERVICE_UID_COUNTERS                      (10u)
/* Number of use cases in logging of signature verification events. */
#define SECLOG_NUMBER_OF_SIGNATURE_VERIFICATION_USE_CASES                     (3u)
/* Number of use cases in logging of failed SecOC MAC verification secure broadcast events. */
#define SECLOG_NUMBER_OF_SECOC_MAC_VERIFICATION_BROADCAST_USE_CASES           (4u)

/* Convert to ms */
#define SECLOG_LOGGINGACTIVE_TIMEOUT                                          (SSA_SECLOG_LOGGING_ACTIVE_TIMEOUT * 100u)
/* Size of time stamp in for logged events */
#define SECLOG_TIMESTAMP_SIZE                                                 (5u)

/* Dummy PKI role */
#define SECLOG_DUMMY_PKI_ROLE (0u)

/* NVM Write states. */
#define SECLOG_NVM_WRITE_STATE_IDLE                                           (0u)
#define SECLOG_NVM_WRITE_STATE_START_BLOCK                                    (1u)

/*! Bit flags used to store if a special local tick-count or date and time event has already been logged. */
#define SSA_SECLOG_LOCAL_TICK_COUNT_CHANGED_BY_BROADCAST                      (0x01u)
#define SSA_SECLOG_REAL_TIME_OFFSET_CHANGED_BY_REAL_TIME_OFFSET_BROADCAST     (0x02u)
#define SSA_SECLOG_LOCAL_TICK_COUNT_ATTEMPT_TO_TURN_BACK                      (0x04u)

/*! Mirror Ram block usage states. */
#define SSA_SECLOG_MIRRORRAMBLOCK_UNUSED                                      (0u)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM                                 (1u)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_DIAGSERVICE                         (2u)

/*! Time-out period for blocking the mirror RAM block by a diag. service function.
 *  Valid values are from 0 to 253. 0 means time-out is deactivated
 *  and 253 is the max time-out period at approximately 2530 ms */
#ifndef SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_DIAGSERVICE_TIMEOUT                     /* COV_SSA_OVERWRITEABLE TX */
# define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_DIAGSERVICE_TIMEOUT                ((uint8)100u)
#endif

/*! SecLog SecOc verification states */
#define SECLOG_SECOCVERIFICATIONSTATE_INITIAL                                 (0U)
#define SECLOG_SECOCVERIFICATIONSTATE_ALL_FAILED                              (1U)
#define SECLOG_SECOCVERIFICATIONSTATE_FINAL                                   (2U)

/*! Aggregated buffer lengths used for silent analysis */
#define SECLOG_AGGREGATED_CIRCULAR_BUFFER_LENGTH                              ((SSA_SECLOG_SIZE_EVNT_1 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_FAILED_CERTIFICATE_VERIFICATION_EVENT)               \
                                                                              + (SSA_SECLOG_SIZE_EVNT_2 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_CERTIFICATE_VERIFICATION_EVENT)          \
                                                                              + (SSA_SECLOG_SIZE_EVNT_3 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS_EVENT) \
                                                                              + (SSA_SECLOG_SIZE_EVNT_4 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_AUTHORIZATION_BY_SECURITY_ACCESS_EVENT)             \
                                                                              + (SSA_SECLOG_SIZE_EVNT_5 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION_EVENT)      \
                                                                              + (SSA_SECLOG_SIZE_EVNT_6 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_RIGHTSM_ANAGEMENT_EVENT)                            \
                                                                              + (SSA_SECLOG_SIZE_EVNT_7 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SIGNATURE_VERIFICATION_EVENT)                       \
                                                                              + (SSA_SECLOG_SIZE_EVNT_8 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_CHANGE_OF_TICK_COUNT_OR_DATE_AND_TIME_EVENT)        \
                                                                              + (SSA_SECLOG_SIZE_EVNT_9 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SECOC_MISCONFIGURATION_EVENT)                       \
                                                                              + (SSA_SECLOG_SIZE_EVNT_10 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_FAILED_PDU_MAC_VERIFICATION_EVENT)                 \
                                                                              + (SSA_SECLOG_SIZE_EVNT_11 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SECURE_BOOT_OR_AUTHENTICATED_BOOT_EVENT)           \
                                                                              + (SSA_SECLOG_SIZE_EVNT_12 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_CHANGE_OF_VIN_EVENT)                               \
                                                                              + (SSA_SECLOG_SIZE_EVNT_13 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_ECU_INDIVIDUAL_ACL_REPLACEMENT_EVENT))

#define SECLOG_AGGREGATED_GLOBAL_COUNTER_LENGTH                               (SSA_SECLOG_SIZE_GLOBCOUNT_1    \
                                                                               + SSA_SECLOG_SIZE_GLOBCOUNT_2  \
                                                                               + SSA_SECLOG_SIZE_GLOBCOUNT_3  \
                                                                               + SSA_SECLOG_SIZE_GLOBCOUNT_4  \
                                                                               + SSA_SECLOG_SIZE_GLOBCOUNT_5  \
                                                                               + SSA_SECLOG_SIZE_GLOBCOUNT_6  \
                                                                               + SSA_SECLOG_SIZE_GLOBCOUNT_7  \
                                                                               + SSA_SECLOG_SIZE_GLOBCOUNT_8  \
                                                                               + SSA_SECLOG_SIZE_GLOBCOUNT_9  \
                                                                               + SSA_SECLOG_SIZE_GLOBCOUNT_10 \
                                                                               + SSA_SECLOG_SIZE_GLOBCOUNT_11 \
                                                                               + SSA_SECLOG_SIZE_GLOBCOUNT_12 \
                                                                               + SSA_SECLOG_SIZE_GLOBCOUNT_13 \
                                                                               + SSA_SECLOG_SIZE_GLOBCOUNT_14 \
                                                                               + SSA_SECLOG_SIZE_GLOBCOUNT_15 \
                                                                               + SSA_SECLOG_SIZE_GLOBCOUNT_16)

#define SECLOG_MAX_SIZE_GLOBCOUNT                                             (10u)
#define SECLOG_SECLOG_INFO_AND_THRESHOLD_SIZE                                 (8u)
#define SECLOG_AGGREGATED_DID_AND_THRESHOLD_IDX_LENGTH                        (8u)

#define SECLOG_MAX_INDEX_AFTER_OVERHEAD_AND_COUNTERS                          (SECLOG_SIZE_OF_READ_DATA_LENGTH                             \
                                                                               + SECLOG_SIZEOF_TICKCOUNT                                   \
                                                                               + SECLOG_SIZEOF_REALTIME                                    \
                                                                               + (63u)                                                     \
                                                                               + SECLOG_SECLOG_INFO_AND_THRESHOLD_SIZE                     \
                                                                               + (Ssa_GetSizeOfSecLogInfo() * SECLOG_AGGREGATED_DID_AND_THRESHOLD_IDX_LENGTH))

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if !defined (Ssa_MemCpy)                   /* COV_SSA_MEMCPY */
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
# define Ssa_MemCpy(destination, source, num)                                     Ssa_Utils_MemCpy32(destination, source, num)
#endif

/* PRQA S 3453 2 */ /* MD_MSR_FctLikeMacro */
#define SecLog_EventBuffer(evId)                                                  (&(Ssa_SecLog_NvmAddress[evId].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + Ssa_SecLog_NvmCtrl[evId].globCntSize]))
#define SecLog_EventBufferMirror(evId)                                            (&(Ssa_SecLog_NvmAddress[evId].ramBlockMirror[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + Ssa_SecLog_NvmCtrl[evId].globCntSize]))

/* 4.5.3.3 Logging of failed certificate verification events (SSA-IS-1606) */
#define SecLog_Counter_FailedCertificateVerification_Pki()                        ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_FAILED_CERTIFICATE_VERIFICATION].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE]))
#define SecLog_Counter_FailedCertificateVerification_Auth_EnhanceRights()         ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_FAILED_CERTIFICATE_VERIFICATION].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE+2u]))
#define SecLog_Counter_FailedCertificateVerification_Ecu()                        ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_FAILED_CERTIFICATE_VERIFICATION].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE+4u]))
#define SecLog_Counter_FailedCertificateVerification_Coding_Data()                ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_FAILED_CERTIFICATE_VERIFICATION].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE+6u]))
/* 4.5.3.4 Logging of successful certificate verification events (SSA-IS-1622) */
#define SecLog_Counter_SuccessfulCertificateVerification_Pki()                    ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SUCCESSFUL_CERTIFICATE_VERIFICATION].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE]))
#define SecLog_Counter_SuccessfulCertificateVerification_Ecu()                    ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SUCCESSFUL_CERTIFICATE_VERIFICATION].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE+2u]))
#define SecLog_Counter_SuccessfulCertificateVerification_Coding_Data()            ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SUCCESSFUL_CERTIFICATE_VERIFICATION].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE+4u]))
/* 4.5.3.5 Logging of successful authentication and enhance rights events (SSA-IS-1638) */
#define SecLog_Counter_SuccessfulAuthentication_ExternalDiagTestTool()            ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE]))
#define SecLog_Counter_SuccessfulAuthentication_InternalDiagTestTool()            ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE+2u]))
#define SecLog_Counter_RightsEnhancements_ExternalDiagTestTool()                  ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE+4u]))
#define SecLog_Counter_RightsEnhancements_InternalDiagTestTool()                  ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE+6u]))
/* 4.5.3.6 Logging of Authorization by Security Access events (SSA-IS-1654) */
#define SecLog_Counter_SuccessfulAuthorization_SecurityAccess()                   ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_AUTHORIZATION_SECURITY_ACCESS].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE]))
#define SecLog_Counter_FailedAuthorization_SecurityAccess()                       ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_AUTHORIZATION_SECURITY_ACCESS].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE+2u]))
/* 4.5.3.7 Logging of successful diagnostic service execution events (SSA-IS-1665) */
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define SecLog_Counter_SuccessfulDiagServiceExecution(uid)                        ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE+(uid)]))
/* 4.5.3.8 Logging of rights management events (SSA-IS-1678) */
#define SecLog_Counter_RightsManagement_AuthenticatedDiagTestTool()               ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_RIGHTS_MANAGEMENT].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE]))
#define SecLog_Counter_RightsManagement_UnauthenticatedDiagTestTool()             ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_RIGHTS_MANAGEMENT].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE+4u]))
/* 4.5.3.9 Logging of signature verification events (SSA-IS-1691) */
#define SecLog_Counter_FailedSignatureVerificationSwReprogramming()               ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SIGNATURE_VERIFICATION].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE]))
#define SecLog_Counter_FailedSignatureVerificationVariantCoding()                 ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SIGNATURE_VERIFICATION].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE+2u]))
#define SecLog_Counter_FailedSignatureVerificationOtherData()                     ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SIGNATURE_VERIFICATION].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE+4u]))
/* 4.5.3.10 Logging of change of tick count or date and time events (SSA-IS-1692) */
#define SecLog_Counter_TimeSetToPast()                                            ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_CHANGE_TICK_COUNT_OR_DATE_AND_TIME].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE]))
#define SecLog_Counter_TimeSetToFuture()                                          ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_CHANGE_TICK_COUNT_OR_DATE_AND_TIME].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE+2u]))
/* 4.5.3.11 Logging of SecOC misconfiguration events (SSA-IS-1693) */
#define SecLog_Counter_SecOcMisconfiguration()                                    ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SECOC_MISCONFIGURATION].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE]))
/* 4.5.3.12 Logging of Failed SecOC MAC verification events (SSA-IS-1808) */
/* PRQA S 3453 3 */ /* MD_MSR_FctLikeMacro */
#define SecLog_Counter_FailedSecOcMacVerification_Th1(uid)                        ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_NVM_BLOCK_TABLE_TH1].ramBlock[((uid)*2u)]))
#define SecLog_Counter_FailedSecOcMacVerification_Th2(uid)                        ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_NVM_BLOCK_TABLE_TH2].ramBlock[((uid)*2u)]))
#define SecLog_Counter_FailedSecOcMacVerification_Th3(uid)                        ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_NVM_BLOCK_TABLE_TH3].ramBlock[((uid)*2u)]))
/* 4.5.3.13 Logging of secure boot or authenticated boot events (SSA-IS-1695) */
#define SecLog_Counter_SecureBootOrAuthenticatedBoot()                            ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SECURE_BOOT_OR_AUTHENTICATED_BOOT].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE]))
/* 4.5.3.14 Logging of change of VIN events (SSA-IS-1696) */
#define SecLog_Counter_ChangeOfVin()                                              ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_CHANGE_VIN].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE]))
/* 4.5.3.15 Logging of ECU-individual AccessControlList replacement events (SSA-IS-1697) */
#define SecLog_Counter_EcuIndividualAccessControlListReplacement()                ((uint8*)&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_ECU_INDIVIDUAL_ACL_REPLACEMENT].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE]))

/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define Read_SecOcVerificationState()                                             Ssa_SecLog_SecOcVerificationState
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define Write_SecOcVerificationState(data)                                        Ssa_SecLog_SecOcVerificationState = (data)

/*! Sets single or multiple bits in a bit-set */
#define SecLog_BitOpSet(bitRegisterType, bitRegister, bits)                       ((bitRegister) |= (bitRegisterType)(bits))          /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Clears single or multiple bits in a bit-set */
#define SecLog_BitOpClr(bitRegisterType, bitRegister, bits)                       ((bitRegister) &= (bitRegisterType)(~(bits)))       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Returns TRUE if at least one bit in a bit-set is set */
#define SecLog_BitOpTest(bitRegisterType, bitRegister, bits)                      (((bitRegister) & (bitRegisterType)(bits)) != 0u)   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*!
 * Format of the NVM Ram block data (Event 1 -13):
 *                        1                   2                   3
 *    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
 *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *    |            Write Idx          |        Length Content         |
 *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *    |       ThresholdWarning        |            unused             |
 *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *    |                                                               |
 *    ~                 Log Data (Global Counters)                    ~
 *    |                                                               |
 *    +               |-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *    +-+-+-+-+-+-+-+-|                                               +
 *    |                                                               |
 *    ~                 Log Data (Circular Buffer)                    ~
 *    |                                                               |
 *    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 */
#define Ssa_SecLog_NvmCtrl_SetWriteIdx(BlockIdx, Value)               SecLog_PutUint16(Ssa_SecLog_NvmAddress[BlockIdx].ramBlock, 0u, Value)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define Ssa_SecLog_NvmCtrl_SetLengthContent(BlockIdx, Value)          SecLog_PutUint16(Ssa_SecLog_NvmAddress[BlockIdx].ramBlock, 2u, Value)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define Ssa_SecLog_NvmCtrl_SetThresholdWarning(BlockIdx, Value)       SecLog_PutUint16(Ssa_SecLog_NvmAddress[BlockIdx].ramBlock, 4u, Value)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define Ssa_SecLog_NvmCtrl_SetDummy(BlockIdx, Value)                  SecLog_PutUint16(Ssa_SecLog_NvmAddress[BlockIdx].ramBlock, 6u, Value)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#define Ssa_SecLog_NvmCtrl_GetWriteIdx(BlockIdx)                      SecLog_GetUint16(Ssa_SecLog_NvmAddress[BlockIdx].ramBlock, 0u)        /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define Ssa_SecLog_NvmCtrl_GetLengthContent(BlockIdx)                 SecLog_GetUint16(Ssa_SecLog_NvmAddress[BlockIdx].ramBlock, 2u)        /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define Ssa_SecLog_NvmCtrl_GetThresholdWarning(BlockIdx)              SecLog_GetUint16(Ssa_SecLog_NvmAddress[BlockIdx].ramBlock, 4u)        /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define Ssa_SecLog_NvmCtrl_GetWriteIdxMirror(BlockIdx)                SecLog_GetUint16(Ssa_SecLog_NvmAddress[BlockIdx].ramBlockMirror, 0u)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define Ssa_SecLog_NvmCtrl_GetLengthContentMirror(BlockIdx)           SecLog_GetUint16(Ssa_SecLog_NvmAddress[BlockIdx].ramBlockMirror, 2u)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define Ssa_SecLog_NvmCtrl_GetThresholdWarningMirror(BlockIdx)        SecLog_GetUint16(Ssa_SecLog_NvmAddress[BlockIdx].ramBlockMirror, 4u)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* The following compile time assertions ensure the sizes of data types used within the SecLog submodule
 * when calling RTE APIs expecting these data types. 
 * The assertions ensure that the size of these data types is consistent with respective buffer lengths defined in the Ssa.
 * For ASIL-D, the vector code analyzer checks the same conditions within the SecLog_Init() function. */
/* PRQA S 3205, 3493 1 */ /* MD_SSA_COMPILE_TIME_ASSERTION */
Ssa_CompileTimeAssert(sizeof(Ssa_Data64ByteType) == 64u, InvalidSizeOf_Ssa_Data64ByteType); /*lint !e506 */

/*! Function pointer type definitions used for pointers to NVM service functions. */
typedef P2FUNC(Std_ReturnType, Ssa_SecLog_CODE, SecLog_NvMGetErrorStatusFctPtrType)(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorStatus);
typedef P2FUNC(Std_ReturnType, Ssa_SecLog_CODE, SecLog_NvMSetRamBlockStatusFctPtrType)(boolean RamBlockStatus);
typedef P2FUNC(Std_ReturnType, Ssa_SecLog_CODE, SecLog_NvMWriteBlockFctPtrType)(dtRef_const_VOID SrcPtr);

/*! NvRam blocks address type. */
typedef P2VAR(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) NvM_RamAddressType;
/*! SecOc Verification State type definition. */
typedef uint8 SecLog_SecOcVerificationStateType;

/*! SecLog NVM address structure type definition. */
typedef struct
{
  NvM_RamAddressType ramBlock;
  NvM_RamAddressType ramBlockMirror;
} Ssa_SecLog_NvmAddressType;

/*! SecLog NVM control structure type definition. */
typedef struct
{
  SecLog_NvMGetErrorStatusFctPtrType getErrorStatusFct;
  SecLog_NvMSetRamBlockStatusFctPtrType setRamBlockStatusFct;
  SecLog_NvMWriteBlockFctPtrType writeBlockFct;
  const uint16 ramBlockSize;        /*!< The size of the RAM block. */
  const uint16 globCntSize;         /*!< The size of the all global counters belonging to this block. */
  const uint16 entrySize;           /*!< The size of one entry. */
  const uint16 bufferSize;          /*!< The size of the circular buffer. */
  const uint16 bufferWarningLevel;  /*!< The buffer overflow threshold. To be calculated as 70 percent of the buffer size. */
} Ssa_SecLog_NvmCtrlType;

/**********************************************************************************************************************
 *  LOCAL CONST DATA
 **********************************************************************************************************************/

#define Ssa_SecLog_START_SEC_CONST_UNSPECIFIED
#include "Ssa_SecLog_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (SSA_SECLOG_USE_PIM_ACCESS_MACROS_AS_COMPILE_TIME_CONSTANTS == STD_ON)

/*! Constant data used for controlling the SecLog's NvRam blocks. */
SSA_SECLOG_LOCAL CONST(Ssa_SecLog_NvmAddressType, Ssa_SecLog_CONST) Ssa_SecLog_NvmAddress[SSA_SECLOG_NUM_NVM_BLOCKS] =
{
  /* ********** FAILED_CERTIFICATE_VERIFICATION_EVENT ********** */
  { /*lint -save -e545 */
    Rte_Pim_LogDataEvnt1_FailedCertVerif(),
    Rte_Pim_LogDataEvnt1_FailedCertVerif_Mirror(),
    /*lint -restore */
  },
  /* ********** SUCCESSFUL_CERTIFICATE_VERIFICATION_EVENT ********** */
  { /*lint -save -e545 */
    Rte_Pim_LogDataEvnt2_SucCertVerif(),
    Rte_Pim_LogDataEvnt2_SucCertVerif_Mirror(),
    /*lint -restore */
  },
  /* ********** SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS_EVENT ********** */
  { /*lint -save -e545 */
    Rte_Pim_LogDataEvnt3_SucAuthAndEnhanceRights(),
    Rte_Pim_LogDataEvnt3_SucAuthAndEnhanceRights_Mirror(),
    /*lint -restore */
  },
  /* ********** AUTHORIZATION_BY_SECURITY_ACCESS_EVENT ********** */
  { /*lint -save -e545 */
    Rte_Pim_LogDataEvnt4_AuthBySecAccess(),
    Rte_Pim_LogDataEvnt4_AuthBySecAccess_Mirror(),
    /*lint -restore */
  },
  /* ********** SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION_EVENT ********** */
  { /*lint -save -e545 */
    Rte_Pim_LogDataEvnt5_SucDiagServiceExec(),
    Rte_Pim_LogDataEvnt5_SucDiagServiceExec_Mirror(),
    /*lint -restore */
  },
  /* ********** RIGHTS_MANAGEMENT_EVENT ********** */
  { /*lint -save -e545 */
    Rte_Pim_LogDataEvnt6_RightsMgmt(),
    Rte_Pim_LogDataEvnt6_RightsMgmt_Mirror(),
    /*lint -restore */
  },
  /* ********** SIGNATURE_VERIFICATION_EVENT ********** */
  { /*lint -save -e545 */
    Rte_Pim_LogDataEvnt7_SigVerif(),
    Rte_Pim_LogDataEvnt7_SigVerif_Mirror(),
    /*lint -restore */
  },
  /* ********** CHANGE_OF_TICK_COUNT_OR_DATE_AND_TIME_EVENT ********** */
  { /*lint -save -e545 */
    Rte_Pim_LogDataEvnt8_TickCountDateAndTime(),
    Rte_Pim_LogDataEvnt8_TickCountDateAndTime_Mirror(),
    /*lint -restore */
  },
  /* ********** SECOC_MISCONFIGURATION_EVENT ********** */
  { /*lint -save -e545 */
    Rte_Pim_LogDataEvnt9_SecOcMisconfig(),
    Rte_Pim_LogDataEvnt9_SecOcMisconfig_Mirror(),
    /*lint -restore */
  },
  /* ********** FAILED_PDU_MAC_VERIFICATION_EVENT ********** */
  { /*lint -save -e545 */
    Rte_Pim_LogDataEvnt10_FailedPduMacVerif(),
    Rte_Pim_LogDataEvnt10_FailedPduMacVerif_Mirror(),
    /*lint -restore */
  },
  /* ********** SECURE_BOOT_OR_AUTHENTICATED_BOOT_EVENT ********** */
  { /*lint -save -e545 */
    Rte_Pim_LogDataEvnt11_SecOrAuthBoot(),
    Rte_Pim_LogDataEvnt11_SecOrAuthBoot_Mirror(),
    /*lint -restore */
  },
  /* ********** CHANGE_OF_VIN ********** */
  { /*lint -save -e545 */
    Rte_Pim_LogDataEvnt12_ChangeOfVin(),
    Rte_Pim_LogDataEvnt12_ChangeOfVin_Mirror(),
    /*lint -restore */
  },
  /* ********** ECU_INDIVIDUAL_ACL_REPLACEMENT_EVENT ********** */
  { /*lint -save -e545 */
    Rte_Pim_LogDataEvnt13_AclReplacement(),
    Rte_Pim_LogDataEvnt13_AclReplacement_Mirror(),
    /*lint -restore */
  },
  /* ********** MAC_VERIFICATION_COUNT_EXCEEDED_THRESHOLD_1 ********** */
  { /*lint -save -e545 */
    Rte_Pim_LogFailedMacVerifCount_ExceededTh1(),
    Rte_Pim_LogFailedMacVerifCount_ExceededTh1_Mirror(),
    /*lint -restore */
  },
  /* ********** MAC_VERIFICATION_COUNT_EXCEEDED_THRESHOLD_2 ********** */
  { /*lint -save -e545 */
    Rte_Pim_LogFailedMacVerifCount_ExceededTh2(),
    Rte_Pim_LogFailedMacVerifCount_ExceededTh2_Mirror(),
    /*lint -restore */
  },
  /* ********** MAC_VERIFICATION_COUNT_EXCEEDED_THRESHOLD_3 ********** */
  { /*lint -save -e545 */
    Rte_Pim_LogFailedMacVerifCount_ExceededTh3(),
    Rte_Pim_LogFailedMacVerifCount_ExceededTh3_Mirror(),
    /*lint -restore */
  }
};
#endif

/*! Constant data used for controlling the SecLog's NvRam blocks. */
SSA_SECLOG_LOCAL CONST(Ssa_SecLog_NvmCtrlType, Ssa_SecLog_CONST) Ssa_SecLog_NvmCtrl[SSA_SECLOG_NUM_NVM_BLOCKS] =
{
  /* ********** FAILED_CERTIFICATE_VERIFICATION_EVENT ********** */
  {
    Rte_Call_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_GetErrorStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_SetRamBlockStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_WriteBlock,
    sizeof(SecLog_LogDataEvnt1_FailedCertVerifType),
    SSA_SECLOG_SIZE_GLOBCOUNT_1,
    SSA_SECLOG_SIZE_EVNT_1,
    SSA_SECLOG_SIZE_EVNT_1 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_FAILED_CERTIFICATE_VERIFICATION_EVENT,
    SSA_SECLOG_SIZE_EVNT_1 * ((SSA_SECLOG_CIRCULAR_BUFFER_SIZE_FAILED_CERTIFICATE_VERIFICATION_EVENT * 7u) / 10u)
  },
  /* ********** SUCCESSFUL_CERTIFICATE_VERIFICATION_EVENT ********** */
  {
    Rte_Call_NvMService_SecLog_LogDataEvnt2_SucCertVerif_GetErrorStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt2_SucCertVerif_SetRamBlockStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt2_SucCertVerif_WriteBlock,
    sizeof(SecLog_LogDataEvnt2_SucCertVerifType),
    SSA_SECLOG_SIZE_GLOBCOUNT_2,
    SSA_SECLOG_SIZE_EVNT_2,
    SSA_SECLOG_SIZE_EVNT_2 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_CERTIFICATE_VERIFICATION_EVENT,
    SSA_SECLOG_SIZE_EVNT_2 * ((SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_CERTIFICATE_VERIFICATION_EVENT * 7u) / 10u)
  },
  /* ********** SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS_EVENT ********** */
  {
    Rte_Call_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_GetErrorStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_SetRamBlockStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_WriteBlock,
    sizeof(SecLog_LogDataEvnt3_SucAuthAndEnhanceRightsType),
    SSA_SECLOG_SIZE_GLOBCOUNT_3,
    SSA_SECLOG_SIZE_EVNT_3,
    SSA_SECLOG_SIZE_EVNT_3 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS_EVENT,
    SSA_SECLOG_SIZE_EVNT_3 * ((SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS_EVENT * 7u) / 10u)
  },
  /* ********** AUTHORIZATION_BY_SECURITY_ACCESS_EVENT ********** */
  {
    Rte_Call_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_GetErrorStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_SetRamBlockStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_WriteBlock,
    sizeof(SecLog_LogDataEvnt4_AuthBySecAccessType),
    SSA_SECLOG_SIZE_GLOBCOUNT_4,
    SSA_SECLOG_SIZE_EVNT_4,
    SSA_SECLOG_SIZE_EVNT_4 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_AUTHORIZATION_BY_SECURITY_ACCESS_EVENT,
    SSA_SECLOG_SIZE_EVNT_4 * ((SSA_SECLOG_CIRCULAR_BUFFER_SIZE_AUTHORIZATION_BY_SECURITY_ACCESS_EVENT * 7u) / 10u)
  },
  /* ********** SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION_EVENT ********** */
  {
    Rte_Call_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_GetErrorStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_SetRamBlockStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_WriteBlock,
    sizeof(SecLog_LogDataEvnt5_SucDiagServiceExecType),
    SSA_SECLOG_SIZE_GLOBCOUNT_5,
    SSA_SECLOG_SIZE_EVNT_5,
    SSA_SECLOG_SIZE_EVNT_5 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION_EVENT,
    SSA_SECLOG_SIZE_EVNT_5 * ((SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION_EVENT * 7u) / 10u)
  },
  /* ********** RIGHTS_MANAGEMENT_EVENT ********** */
  {
    Rte_Call_NvMService_SecLog_LogDataEvnt6_RightsMgmt_GetErrorStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt6_RightsMgmt_SetRamBlockStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt6_RightsMgmt_WriteBlock,
    sizeof(SecLog_LogDataEvnt6_RightsMgmtType),
    SSA_SECLOG_SIZE_GLOBCOUNT_6,
    SSA_SECLOG_SIZE_EVNT_6,
    SSA_SECLOG_SIZE_EVNT_6 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_RIGHTSM_ANAGEMENT_EVENT,
    SSA_SECLOG_SIZE_EVNT_6 * ((SSA_SECLOG_CIRCULAR_BUFFER_SIZE_RIGHTSM_ANAGEMENT_EVENT * 7u) / 10u)
  },
  /* ********** SIGNATURE_VERIFICATION_EVENT ********** */
  {
    Rte_Call_NvMService_SecLog_LogDataEvnt7_SigVerif_GetErrorStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt7_SigVerif_SetRamBlockStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt7_SigVerif_WriteBlock,
    sizeof(SecLog_LogDataEvnt7_SigVerifType),
    SSA_SECLOG_SIZE_GLOBCOUNT_7,
    SSA_SECLOG_SIZE_EVNT_7,
    SSA_SECLOG_SIZE_EVNT_7 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SIGNATURE_VERIFICATION_EVENT,
    SSA_SECLOG_SIZE_EVNT_7 * ((SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SIGNATURE_VERIFICATION_EVENT * 7u) / 10u)
  },
  /* ********** CHANGE_OF_TICK_COUNT_OR_DATE_AND_TIME_EVENT ********** */
  {
    Rte_Call_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_GetErrorStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_SetRamBlockStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_WriteBlock,
    sizeof(SecLog_LogDataEvnt8_TickCountDateAndTimeType),
    SSA_SECLOG_SIZE_GLOBCOUNT_8,
    SSA_SECLOG_SIZE_EVNT_8,
    SSA_SECLOG_SIZE_EVNT_8 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_CHANGE_OF_TICK_COUNT_OR_DATE_AND_TIME_EVENT,
    SSA_SECLOG_SIZE_EVNT_8 * ((SSA_SECLOG_CIRCULAR_BUFFER_SIZE_CHANGE_OF_TICK_COUNT_OR_DATE_AND_TIME_EVENT * 7u) / 10u)
  },
  /* ********** SECOC_MISCONFIGURATION_EVENT ********** */
  {
    Rte_Call_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_GetErrorStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_SetRamBlockStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_WriteBlock,
    sizeof(SecLog_LogDataEvnt9_SecOcMisconfigType),
    SSA_SECLOG_SIZE_GLOBCOUNT_9,
    SSA_SECLOG_SIZE_EVNT_9,
    SSA_SECLOG_SIZE_EVNT_9 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SECOC_MISCONFIGURATION_EVENT,
    SSA_SECLOG_SIZE_EVNT_9 * ((SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SECOC_MISCONFIGURATION_EVENT * 7u) / 10u)
  },
  /* ********** FAILED_PDU_MAC_VERIFICATION_EVENT ********** */
  {
    Rte_Call_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_GetErrorStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_SetRamBlockStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_WriteBlock,
    sizeof(SecLog_LogDataEvnt10_FailedPduMacVerifType),
    SSA_SECLOG_SIZE_GLOBCOUNT_10,
    SSA_SECLOG_SIZE_EVNT_10,
    SSA_SECLOG_SIZE_EVNT_10 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_FAILED_PDU_MAC_VERIFICATION_EVENT,
    SSA_SECLOG_SIZE_EVNT_10 * ((SSA_SECLOG_CIRCULAR_BUFFER_SIZE_FAILED_PDU_MAC_VERIFICATION_EVENT * 7u) / 10u)
  },
  /* ********** SECURE_BOOT_OR_AUTHENTICATED_BOOT_EVENT ********** */
  {
    Rte_Call_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_GetErrorStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_SetRamBlockStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_WriteBlock,
    sizeof(SecLog_LogDataEvnt11_SecOrAuthBootType),
    SSA_SECLOG_SIZE_GLOBCOUNT_11,
    SSA_SECLOG_SIZE_EVNT_11,
    SSA_SECLOG_SIZE_EVNT_11 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SECURE_BOOT_OR_AUTHENTICATED_BOOT_EVENT,
    SSA_SECLOG_SIZE_EVNT_11 * ((SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SECURE_BOOT_OR_AUTHENTICATED_BOOT_EVENT * 7u) / 10u)
  },
  /* ********** CHANGE_OF_VIN ********** */
  {
    Rte_Call_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_GetErrorStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_SetRamBlockStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_WriteBlock,
    sizeof(SecLog_LogDataEvnt12_ChangeOfVinType),
    SSA_SECLOG_SIZE_GLOBCOUNT_12,
    SSA_SECLOG_SIZE_EVNT_12,
    SSA_SECLOG_SIZE_EVNT_12 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_CHANGE_OF_VIN_EVENT,
    SSA_SECLOG_SIZE_EVNT_12 * ((SSA_SECLOG_CIRCULAR_BUFFER_SIZE_CHANGE_OF_VIN_EVENT * 7u) / 10u)
  },
  /* ********** ECU_INDIVIDUAL_ACL_REPLACEMENT_EVENT ********** */
  {
    Rte_Call_NvMService_SecLog_LogDataEvnt13_AclReplacement_GetErrorStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt13_AclReplacement_SetRamBlockStatus,
    Rte_Call_NvMService_SecLog_LogDataEvnt13_AclReplacement_WriteBlock,
    sizeof(SecLog_LogDataEvnt13_AclReplacementType),
    SSA_SECLOG_SIZE_GLOBCOUNT_13,
    SSA_SECLOG_SIZE_EVNT_13,
    SSA_SECLOG_SIZE_EVNT_13 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_ECU_INDIVIDUAL_ACL_REPLACEMENT_EVENT,
    SSA_SECLOG_SIZE_EVNT_13 * ((SSA_SECLOG_CIRCULAR_BUFFER_SIZE_ECU_INDIVIDUAL_ACL_REPLACEMENT_EVENT * 7u) / 10u)
  },
  /* ********** MAC_VERIFICATION_COUNT_EXCEEDED_THRESHOLD_1 ********** */
  {
    Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_GetErrorStatus,
    Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_SetRamBlockStatus,
    Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_WriteBlock,
    sizeof(SecLog_LogFailedMacVerifCount_ExceededThType),
    SSA_SECLOG_SIZE_GLOBCOUNT_14,
    0u,
    0u,
    0u
  },
  /* ********** MAC_VERIFICATION_COUNT_EXCEEDED_THRESHOLD_2 ********** */
  {
    Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_GetErrorStatus,
    Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_SetRamBlockStatus,
    Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_WriteBlock,
    sizeof(SecLog_LogFailedMacVerifCount_ExceededThType),
    SSA_SECLOG_SIZE_GLOBCOUNT_15,
    0u,
    0u,
    0u
  },
  /* ********** MAC_VERIFICATION_COUNT_EXCEEDED_THRESHOLD_3 ********** */
  {
    Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_GetErrorStatus,
    Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_SetRamBlockStatus,
    Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_WriteBlock,
    sizeof(SecLog_LogFailedMacVerifCount_ExceededThType),
    SSA_SECLOG_SIZE_GLOBCOUNT_16,
    0u,
    0u,
    0u
  }
};

/*! The start of logging notification message. */
SSA_SECLOG_LOCAL CONST(uint8, Ssa_SecLog_CONST) Ssa_SecLog_StartOfLoggingData[7] = { 0x01u, 0u, 0u, 0u, 0u, 0u, 0u };   /* PRQA S 3218 */ /* MD_SSA_OBJECT_AT_FILE_SCOPE */
/*! The end of logging notification message. */
SSA_SECLOG_LOCAL CONST(uint8, Ssa_SecLog_CONST) Ssa_SecLog_EndOfLoggingData[7] = { 0x02u, 0u, 0u, 0u, 0u, 0u, 0u };   /* PRQA S 3218 */ /* MD_SSA_OBJECT_AT_FILE_SCOPE */

#define Ssa_SecLog_STOP_SEC_CONST_UNSPECIFIED
#include "Ssa_SecLog_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

#define Ssa_SecLog_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Ssa_SecLog_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Storage of the output data length when reading the log data by Ssa diagnostic service. */
SSA_SECLOG_LOCAL VAR(uint16, Ssa_SecLog_VAR_NOINIT) Ssa_SecLog_ReadDataLength;
/*! Failed MAC verifications counter used for security logging and MAC attack detection. */
SSA_SECLOG_LOCAL VAR(uint16, Ssa_SecLog_VAR_NOINIT) Ssa_SecLog_FailedMacVerificationCounter[SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS];
/*! Failed MAC verifications counter used for setting DTC. */
SSA_SECLOG_LOCAL VAR(uint8, Ssa_SecLog_VAR_NOINIT) Ssa_SecLog_FailedMacVerificationCounterDtc[SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS];

/*! Storage for the previous ignition state. */
SSA_SECLOG_LOCAL VAR(Ssa_IgnitionStatusType, Ssa_SecLog_VAR_NOINIT) Ssa_SecLog_PreviousIgnitionState;
/*! The SecOC verification state used for handling the de-bouncing. */
SSA_SECLOG_LOCAL VAR(SecLog_SecOcVerificationStateType, Ssa_SecLog_VAR_NOINIT) Ssa_SecLog_SecOcVerificationState;
/*! Indicating if set NVRam block status has been requested. */
SSA_SECLOG_LOCAL VAR(boolean, Ssa_SecLog_VAR_NOINIT) Ssa_SecLog_NvMSetRamBlockStatus[SSA_SECLOG_NUM_NVM_BLOCKS];
/*! Indicating if writing the NVRam block has been requested. */
SSA_SECLOG_LOCAL VAR(boolean, Ssa_SecLog_VAR_NOINIT) Ssa_SecLog_NvMWriteRequested[SSA_SECLOG_NUM_NVM_BLOCKS];
/*! Indicating if the NVRam is being used, e.g copied for ReadDataByIdentifier service. */
SSA_SECLOG_LOCAL VAR(uint8, Ssa_SecLog_VAR_NOINIT) Ssa_SecLog_MirrorRamBlockUsed;
/*! Storing which SecLog event is being copied to its mirror RAM block.
    Access to this variable is considered to be not atomic. Thus it is only accessed in the main function. */
/*
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM_1                                   (0x00001uL)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM_2                                   (0x00002uL)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM_3                                   (0x00004uL)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM_4                                   (0x00008uL)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM_5                                   (0x00010uL)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM_6                                   (0x00020uL)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM_7                                   (0x00040uL)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM_8                                   (0x00080uL)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM_9                                   (0x00100uL)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM_10                                  (0x00200uL)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM_11                                  (0x00400uL)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM_12                                  (0x00800uL)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM_13                                  (0x01000uL)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM_14                                  (0x02000uL)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM_15                                  (0x04000uL)
#define SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM_16                                  (0x08000uL)
 */
SSA_SECLOG_LOCAL VAR(uint32, Ssa_SecLog_VAR_NOINIT) Ssa_SecLog_MirrorRamBlockUsedBits;
/*! The state of writing RAM block to NVM. */
SSA_SECLOG_LOCAL VAR(uint8, Ssa_SecLog_VAR_NOINIT) Ssa_SecLog_NvMWriteState[SSA_SECLOG_NUM_NVM_BLOCKS];

/*! Storage for the SecOcDataId requested by DEM as environmental data for DTC 0xD12083.
 *  Remains valid until it is overwritten by next SecOCDataId, i.e. it is not cleared when
 *  counter goes below threshold. */
SSA_SECLOG_LOCAL VAR(uint16, Ssa_SecLog_VAR_NOINIT) Ssa_SecLog_SecOCDataId_ThresholdReached;

/*! Bit-set indicating whether a special local tick-count or date and time event has already been logged. */
SSA_SECLOG_LOCAL VAR(uint8, Ssa_SecLog_VAR_NOINIT) Ssa_SecLog_LocalTickCountDateTimeChangeEventLogged;

/*! Storage for local tick-count and synchronization status, updated each main function cycle. */
SSA_SECLOG_LOCAL VAR(Ssa_TickCountSyncStateType, Ssa_SecLog_VAR_NOINIT) Ssa_SecLog_LocalTickCountSyncStatus;

SSA_SECLOG_LOCAL VAR(uint16, Ssa_SecLog_VAR_NOINIT) Ssa_SecLog_ElapsedTime;
SSA_SECLOG_LOCAL VAR(uint16, Ssa_SecLog_VAR_NOINIT) Ssa_SecLog_LoggingActiveTimer;

#if (SSA_SECLOG_USE_PIM_ACCESS_MACROS_AS_COMPILE_TIME_CONSTANTS == STD_OFF)
SSA_SECLOG_LOCAL VAR(Ssa_SecLog_NvmAddressType, Ssa_SecLog_VAR_NOINIT) Ssa_SecLog_NvmAddress[SSA_SECLOG_NUM_NVM_BLOCKS];
#endif

#define Ssa_SecLog_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Ssa_SecLog_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define Ssa_SecLog_START_SEC_CODE
#include "Ssa_SecLog_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * SecLog_PutUint16()
 *********************************************************************************************************************/
/*! \brief       Writes a two-byte unsigned integer into a buffer.
 *  \details     Byte-wise access for array data in network byte order.
 *  \param[out]  BufferPtr  Buffer to store the value.
 *  \param[in]   Offset     Byte offset within buffer [min: 0, max: buffer length - 2].
 *  \param[in]   Value      Value to be written.
 *  \pre         BufferPtr must be a valid pointer.
 *               The buffer referenced by BufferPtr must provide at least (Offset + 2) many bytes.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \spec        requires BufferPtr != NULL_PTR;
 *               requires $lengthOf(BufferPtr) >= (Offset + 2);                                                \endspec
 *********************************************************************************************************************/
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_PutUint16(                     /* PRQA S 3219 */ /* MD_MSR_Unreachable */
  CONSTP2VAR(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) BufferPtr,
  uint32 Offset, uint16 Value);

/**********************************************************************************************************************
 * SecLog_GetUint16()
 *********************************************************************************************************************/
/*! \brief       Reads a two-byte unsigned integer from a buffer.
 *  \details     Byte-wise access for array data in network byte order.
 *  \param[in]   BufferPtr  Buffer to read the value.
 *  \param[in]   Offset     Byte offset within buffer [min: 0, max: buffer length - 2].
 *  \return      16bit Data read from buffer
 *  \pre         BufferPtr must be a valid pointer.
 *  \context     TASK|ISR2
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *********************************************************************************************************************/
SSA_SECLOG_LOCAL_INLINE FUNC(uint16, Ssa_SecLog_CODE) SecLog_GetUint16(                     /* PRQA S 3219 */ /* MD_MSR_Unreachable */
  CONSTP2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) BufferPtr,
  uint32 Offset);

/**********************************************************************************************************************
 * SecLog_IncrementGlobalEvent1ByteCounter()
 *********************************************************************************************************************/
/*!
 * \brief         Increments a global event one byte counter.
 * \details       -
 * \param[in,out] counterAddr  Pointer to the one byte counter.
 * \pre           counterAddr must be a valid pointer.
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_IncrementGlobalEvent1ByteCounter(P2VAR(uint8, AUTOMATIC, AUTOMATIC) counterAddr);

/**********************************************************************************************************************
 * SecLog_IncrementGlobalEvent2ByteCounter()
 *********************************************************************************************************************/
/*!
 * \brief         Increments a global event two byte counter.
 * \details       -
 * \param[in,out] counterAddr  Pointer to the two byte counter.
 * \pre           counterAddr must be a valid pointer.
 *                The buffer referenced by counterAddr must provide at least 2 bytes.
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 * \spec          requires counterAddr != NULL_PTR;
 *                requires $lengthOf(counterAddr) >= 2;                                                        \endspec
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_IncrementGlobalEvent2ByteCounter(P2VAR(uint8, AUTOMATIC, AUTOMATIC) counterAddr);

/**********************************************************************************************************************
 * SecLog_IncrementGlobalEvent4ByteCounter()
 *********************************************************************************************************************/
/*!
 * \brief         Increments a global event four byte counter.
 * \details       -
 * \param[in,out] counterAddr  Pointer to the four byte counter.
 * \pre           counterAddr must be a valid pointer.
 *                The buffer referenced by counterAddr must provide at least 4 bytes.
 * \context       ANY
 * \reentrant     TRUE
 * \synchronous   TRUE
 * \spec          requires counterAddr != NULL_PTR;
 *                requires $lengthOf(counterAddr) >= 4;                                                        \endspec
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_IncrementGlobalEvent4ByteCounter(P2VAR(uint8, AUTOMATIC, AUTOMATIC) counterAddr);

/**********************************************************************************************************************
 * SecLog_GetDataIdIndex()
 *********************************************************************************************************************/
/*!
 * \brief       Gets the index of a given data id in the configured data id table.
 * \details     -
 * \param[in]   id   The data id whose index is get.
 * \param[out]  idx  Buffer where the index of the data id in the data id table shall be written to.
 * \return      TRUE  The data id has been found in the table.
 *              FALSE The data id has not been found.
 * \pre         idx must be a valid pointer.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_SECLOG_LOCAL FUNC(boolean, Ssa_SecLog_CODE) SecLog_GetDataIdIndex(uint16 id, P2VAR(uint16, AUTOMATIC, AUTOMATIC) idx);

/**********************************************************************************************************************
 * SecLog_GetTimestampAndWriteLogEntry()
 *********************************************************************************************************************/
/*!
 * \brief       Gets time-stamp and writes a log entry with this time-stamp.
 * \details     -
 * \param[in]   eventId      Identifier for the event that shall be logged.
 * \param[in]   logEntryData Pointer to the data that shall be logged, can be null.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_GetTimestampAndWriteLogEntry(uint8 eventId, P2CONST(uint8, AUTOMATIC, AUTOMATIC) logEntryData);

/**********************************************************************************************************************
 * SecLog_WriteDummyLogEntries()
 *********************************************************************************************************************/
/*!
 * \brief       Writes a dummy log entry.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_WriteDummyLogEntries(void);

/**********************************************************************************************************************
 * SecLog_WriteLogEntry()
 *********************************************************************************************************************/
/*!
 * \brief       Writes a log entry.
 * \details     -
 * \param[in]   eventIdx     Index for the event that shall be logged.
 * \param[in]   logEntryData Pointer to the data that shall be logged, can be null.
 * \param[in]   tickCount    Time-stamp that shall be written in as part of the log data.
 * \pre         tickCount must be a valid pointer
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 * \spec        requires tickCount != NULL_PTR;                                                                \endspec
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_WriteLogEntry(uint8 eventIdx, P2CONST(uint8, AUTOMATIC, AUTOMATIC) logEntryData, P2CONST(uint64, AUTOMATIC, AUTOMATIC) tickCount);

/**********************************************************************************************************************
 * SecLog_LogEvent_FailedSecOcMacVerification()
 *********************************************************************************************************************/
/*!
 * \brief       Logs an MAC verification event.
 * \details     -
 * \param[in]   verificationStatus  Pointer to the SecOC verification status.
 * \param[out]  logInfoWritten      Indicating to the caller which log information has been written.
 * \return      E_OK  Request succeeded.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_SECLOG_LOCAL FUNC(Std_ReturnType, Ssa_SecLog_CODE) SecLog_LogEvent_FailedSecOcMacVerification(
  P2CONST(SecOC_VerificationStatusType, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) verificationStatus,
  P2VAR(Ssa_ThresholdExceededType, AUTOMATIC, AUTOMATIC) logInfoWritten);

/**********************************************************************************************************************
 * SecLog_IncFailedMacCounterForDTC()
 *********************************************************************************************************************/
/*!
 * \brief       Increments the failed MAC counter and triggers the DTC.
 * \details     -
 * \param[in]   idx The table index of the considered DataId.
 * \return      The threshold exceeded by the PDU counter.
 * \pre         idx < SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \spec        requires idx < SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS;                                              \endspec
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_IncFailedMacCounterForDTC(uint16 idx);

/**********************************************************************************************************************
 * SecLog_IncFailedMacCounterForThresholds()
 *********************************************************************************************************************/
/*!
 * \brief       Increments the failed MAC counter and triggers the DTC.
 * \details     -
 * \param[in]   idx             The table index of the considered DataId.
 * \param[in]   secOCDataId     The secOCData identifier. Used if log entry is written.
 * \param[out]  logInfoWritten  Identifies which log info has been written.
 * \return      The threshold exceeded by the PDU counter.
 * \pre         logInfoWritten must be a valid pointer.
 *              idx < SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_IncFailedMacCounterForThresholds(
  uint16 idx,
  uint16 secOCDataId,
  P2VAR(Ssa_ThresholdExceededType, AUTOMATIC, AUTOMATIC) logInfoWritten);

/**********************************************************************************************************************
 * SecLog_HandleDebouncing()
 *********************************************************************************************************************/
/*!
 * \brief       Handles the de-bouncing.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_HandleDebouncing(void);

/**********************************************************************************************************************
 * SecLog_CheckNvmBlockState()
 *********************************************************************************************************************/
/*!
 * \brief       Preliminary checks of the block states before a block can be written to NvM.
 * \details     -
 * \param[in]   idxBlock  index of the block to be processed
 * \return      E_OK     NvM block state check successful
 *              E_NOT_OK NvM block state check failed
 * \pre         idxBlock < SSA_SECLOG_NUM_NVM_BLOCKS
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_SECLOG_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_SecLog_CODE) SecLog_CheckNvmBlockState(uint16 idxBlock);

/**********************************************************************************************************************
 * SecLog_CopyRamBlockToMirror()
 *********************************************************************************************************************/
/*!
 * \brief       Copies a RAM block to its mirror and triggers writing the block to the NvM.
 * \details     -
 * \param[in]   idxBlock  index of the block to be processed
 * \param[in]   bitBlock  bit mask of SecLog events to be copied to the mirror
 * \pre         idxBlock < SSA_SECLOG_NUM_NVM_BLOCKS
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_CopyRamBlockToMirror(uint16 idxBlock, uint32 bitBlock);

/**********************************************************************************************************************
 * SecLog_WriteRamBlocksToNvm()
 *********************************************************************************************************************/
/*!
 * \brief       Handles requests for writing a single RAM block to NvM.
 * \details     -
 * \param[in]   idxBlock  index of the block to be processed
 * \pre         idxBlock < SSA_SECLOG_NUM_NVM_BLOCKS
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_WriteRamBlocksToNvm(uint16 idxBlock);

/**********************************************************************************************************************
 * SecLog_HandleNvmBlock()
 *********************************************************************************************************************/
/*!
 * \brief       Handles requests for writing a single NVRam block.
 * \details     -
 * \param[in]   idxBlock  index of the block to be processed
 * \pre         idxBlock < SSA_SECLOG_NUM_NVM_BLOCKS
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_HandleNvmBlock(uint16 idxBlock);

/**********************************************************************************************************************
 * SecLog_HandleNvm()
 *********************************************************************************************************************/
/*!
 * \brief       Handles requests for writing the NVRam block.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_HandleNvm(void);

/**********************************************************************************************************************
 * SecLog_HandleTimers()
 *********************************************************************************************************************/
/*!
 * \brief       Handles the SecLog timers.
 * \details     This function handles timer for usage of mirror RAM block by diagnostic service and the LoggingActive
 *              timer and notifies end of logging if LoggingActive time-out occurs.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_HandleTimers(void);

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 * SecLog_LogEvent_SecOc_Misconfiguration()
 *********************************************************************************************************************/
/*!
 * \brief       Logs the SecOC misconfiguration event.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_LogEvent_SecOc_Misconfiguration(void);

#endif

/**********************************************************************************************************************
 * SecLog_FillInCircularBufferData()
 *********************************************************************************************************************/
/*!
 * \brief         Called from SecLog_FillInSecurityEventLog to fill in the circular buffer data to the given buffer.
 * \details       -
 * \param[out]    Data              Holds the pointer to the memory location where the read data shall be stored.
 * \param[in]     fillInAllLogData  TRUE: Fill in all log data, FALSE: Fill in only log data of global counters
 * \param[in,out] byteDestIdx     (in)  pointer to byte index at which writing to Data buffer starts
 *                                (out) pointer to byte index after data written by SecLog_FillInCircularBufferData
 * \pre           All provided pointers must be valid.
 *                The buffer referenced by Data must provide at least sizeof(Dcm_Data1024ByteType) many bytes.
 * \context       TASK
 * \reentrant     FALSE
 * \synchronous   TRUE
 * \spec          requires $lengthOf(Data) >= sizeof(Dcm_Data1024ByteType);                                    
 *                requires byteDestIdx != NULL_PTR;                                                            \endspec
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_FillInCircularBufferData(
  P2VAR(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) Data,
  const boolean fillInAllLogData,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) byteDestIdx);

/**********************************************************************************************************************
 * SecLog_FillInSecurityEventLog()
 *********************************************************************************************************************/
/*!
 * \brief       Fills in the security event log data to the given buffer.
 * \details     -
 * \param[out]  Data              Holds the pointer to the memory location where the read data shall be stored.
 * \param[in]   fillInAllLogData  TRUE: Fill in all log data, FALSE: Fill in only log data of global counters
 * \return      E_OK     Request succeeded.
 * \            E_NOT_OK Request failed.
 * \pre         Data must be a valid pointer.
 *              The buffer referenced by Data must provide at least sizeof(Dcm_Data1024ByteType) many bytes.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \spec        requires $lengthOf(Data) >= sizeof(Dcm_Data1024ByteType);                                      \endspec
 */
SSA_SECLOG_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_SecLog_CODE) SecLog_FillInSecurityEventLog(
  P2VAR(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) Data,
  boolean fillInAllLogData);

/**********************************************************************************************************************
 * SecLog_CheckContextDateTimeChangeForNvmWriteRequest()
 *********************************************************************************************************************/
/*!
 * \brief       Checks depending on the context of the date time change event if an NVM write block is requested.
 * \details     -
 * \param[in]   contextDateTimeChange The context of the date time change event
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_CheckContextDateTimeChangeForNvmWriteRequest(uint8 contextDateTimeChange);

/**********************************************************************************************************************
 * SecLog_NotifyLogging()
 *********************************************************************************************************************/
/*!
 * \brief       Notifies start of logging and re-starts the logging active timer.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_NotifyLogging(void);

/**********************************************************************************************************************
 * SecLog_InitializeNvRamBlocks()
 *********************************************************************************************************************/
/*!
 * \brief       Initializes the NvRam blocks used for logging the security events.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_InitializeNvRamBlocks(void);

/**********************************************************************************************************************
 * SecLog_DataServices_Security_Event_ReadData_DcmAndRamBlockCheck()
 *********************************************************************************************************************/
/*!
 * \brief        Preliminary checks before data is written during
 *               Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData and
 *               Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData.
 * \details      -
 * \param[in]    OpStatus Current operation status.
 * \param[out]   readLog  Flag storing whether mirror RAM block is available for reading.
 * \return       E_OK     Check of Dcm status and Ram block status successful
 *               E_NOT_OK Check of Dcm status and Ram block status failed
 * \pre          readLog must be a valid pointer.
 * \context      TASK
 * \reentrant    FALSE
 * \synchronous  TRUE
 * \spec         requires readLog != NULL_PTR;                                                                  \endspec
 */
SSA_SECLOG_LOCAL FUNC(Std_ReturnType, Ssa_SecLog_CODE) SecLog_DataServices_Security_Event_ReadData_DcmAndRamBlockCheck(
  Dcm_OpStatusType OpStatus,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) readLog);


/**********************************************************************************************************************
 * SecLog_LogEvent_FailedSecOcMacVerification_MarkRamBlocksAsChanged()
 *********************************************************************************************************************/
 /*!
 * \brief        Request marking those Ram blocks that store the number of Mac verifications as changed.
 * \details      -
 * \param[in]    logInfoWritten  Flag indicating which logInfo has to be written by NvM.
 * \pre          logInfoWritten must be either SECLOG_NVM_BLOCK_TABLE_TH1, SECLOG_NVM_BLOCK_TABLE_TH2 or
 *               SECLOG_NVM_BLOCK_TABLE_TH3.
 * \context      TASK
 * \reentrant    TRUE
 * \synchronous  TRUE
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_LogEvent_FailedSecOcMacVerification_MarkRamBlocksAsChanged(
  Ssa_ThresholdExceededType logInfoWritten);

#define Ssa_SecLog_STOP_SEC_CODE
#include "Ssa_SecLog_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
 * boolean: Boolean (standard type)
 * dtRef_const_VOID: DataReference
 * uint16: Integer in interval [0...65535] (standard type)
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
 * Dem_InitMonitorReasonType: Enumeration of integer in interval [0...255] with enumerators
 *   DEM_INIT_MONITOR_CLEAR (1U)
 *   DEM_INIT_MONITOR_RESTART (2U)
 *   DEM_INIT_MONITOR_REENABLED (3U)
 *   DEM_INIT_MONITOR_STORAGE_REENABLED (4U)
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
 * RightsM_AuthenticationModeType: Enumeration of integer in interval [0...255] with enumerators
 *   RIGHTSM_UNAUTHENTICATED (0U)
 *   RIGHTSM_AUTHENTICATED (1U)
 * SecOC_VerificationResultType: Enumeration of integer in interval [0...255] with enumerators
 *   SECOC_VERIFICATIONSUCCESS (0U)
 *   SECOC_VERIFICATIONFAILURE (1U)
 *   SECOC_FRESHNESSFAILURE (2U)
 *   SECOC_AUTHENTICATIONBUILDFAILURE (3U)
 *   SECOC_NO_VERIFICATION (4U)
 *   SECOC_VERIFICATIONFAILURE_OVERWRITTEN (5U)
 * Ssa_IgnitionStatus_Prim: Enumeration of integer in interval [0...7] with enumerators
 *   I_C03_ISW_STAT_IGN_LOCK (0U)
 *   I_C03_ISW_STAT_IGN_OFF (1U)
 *   I_C03_ISW_STAT_IGN_ACC (2U)
 *   I_C03_ISW_STAT_IGN_ON (4U)
 *   I_C03_ISW_STAT_IGN_START (5U)
 *   I_C03_ISW_STAT_SNA (7U)
 * Ssa_OnOff_StateType: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_STATE_OFF (0U)
 *   SSA_STATE_ON (1U)
 * Ssa_OperationModeType: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_ACTIVE (0U)
 *   SSA_INACTIVE (1U)
 * Ssa_ThresholdExceededType: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_THRESHOLD_EXCEEDED_NONE (0U)
 *   SSA_THRESHOLD_EXCEEDED_TH1 (1U)
 *   SSA_THRESHOLD_EXCEEDED_TH2 (2U)
 *   SSA_THRESHOLD_EXCEEDED_TH3 (3U)
 * Ssa_TickCountSyncStateType: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_TICKCOUNT_SYNC_STATE_NOT_SYNCHRONIZED (0U)
 *   SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_MASTER (1U)
 *   SSA_TICKCOUNT_SYNC_STATE_SYNCHRONIZED_TO_VSM (2U)
 *
 * Array Types:
 * ============
 * DataArrayType_uint8_2: Array with 2 element(s) of type uint8
 * Dcm_Data1024ByteType: Array with 1024 element(s) of type uint8
 * Dcm_Data4092ByteType: Array with 4092 element(s) of type uint8
 * RightsM_SerialNumberType: Array with 16 element(s) of type uint8
 * SecLog_AclVersionType: Array with 11 element(s) of type uint8
 * SecLog_AuthenticationContentType: Array with 18 element(s) of type uint8
 * SecLog_CtrlDataType: Array with 13 element(s) of type SecLog_LogEntryCtrlDataType
 * SecLog_LogDataEvnt10_FailedPduMacVerifType: Array with 128 element(s) of type uint8
 * SecLog_LogDataEvnt11_SecOrAuthBootType: Array with 59 element(s) of type uint8
 * SecLog_LogDataEvnt12_ChangeOfVinType: Array with 76 element(s) of type uint8
 * SecLog_LogDataEvnt13_AclReplacementType: Array with 95 element(s) of type uint8
 * SecLog_LogDataEvnt1_FailedCertVerifType: Array with 176 element(s) of type uint8
 * SecLog_LogDataEvnt2_SucCertVerifType: Array with 244 element(s) of type uint8
 * SecLog_LogDataEvnt3_SucAuthAndEnhanceRightsType: Array with 391 element(s) of type uint8
 * SecLog_LogDataEvnt4_AuthBySecAccessType: Array with 68 element(s) of type uint8
 * SecLog_LogDataEvnt5_SucDiagServiceExecType: Array with 138 element(s) of type uint8
 * SecLog_LogDataEvnt6_RightsMgmtType: Array with 216 element(s) of type uint8
 * SecLog_LogDataEvnt7_SigVerifType: Array with 94 element(s) of type uint8
 * SecLog_LogDataEvnt8_TickCountDateAndTimeType: Array with 232 element(s) of type uint8
 * SecLog_LogDataEvnt9_SecOcMisconfigType: Array with 62 element(s) of type uint8
 * SecLog_LogFailedMacVerifCount_ExceededThType: Array with 200 element(s) of type uint8
 * SecLog_VinType: Array with 17 element(s) of type uint8
 * Ssa_Data1024ByteType: Array with 1024 element(s) of type uint8
 * Ssa_Data4092ByteType: Array with 4092 element(s) of type uint8
 * Ssa_Data5ByteType: Array with 5 element(s) of type uint8
 * Ssa_Data64ByteType: Array with 64 element(s) of type uint8
 * Ssa_Data7ByteType: Array with 7 element(s) of type uint8
 *
 * Record Types:
 * =============
 * SecLog_LogEntryCtrlDataType: Record with elements
 *   writeIdx of type uint16
 *   lengthContent of type uint16
 *   thresholdWarning of type uint16
 * SecOC_VerificationStatusType: Record with elements
 *   freshnessValueID of type uint16
 *   verificationStatus of type SecOC_VerificationResultType
 *   secOCDataId of type uint16
 * Ssa_FailedMacVerifCounterEventType: Record with elements
 *   PduId of type uint16
 *   ThresholdExcceded of type Ssa_ThresholdExceededType
 * Ssa_IgnitionStatusType: Record with elements
 *   ISw_Stat_ST3 of type Ssa_IgnitionStatus_Prim
 * Ssa_LocalTickCountAndSyncStatusType: Record with elements
 *   LocalTickCount of type uint64
 *   SyncStatus of type Ssa_TickCountSyncStateType
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
 *   uint8 *Rte_Pim_LogDataEvnt10_FailedPduMacVerif(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt10_FailedPduMacVerifType
 *   uint8 *Rte_Pim_LogDataEvnt10_FailedPduMacVerif_Mirror(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt10_FailedPduMacVerifType
 *   uint8 *Rte_Pim_LogDataEvnt11_SecOrAuthBoot(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt11_SecOrAuthBootType
 *   uint8 *Rte_Pim_LogDataEvnt11_SecOrAuthBoot_Mirror(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt11_SecOrAuthBootType
 *   uint8 *Rte_Pim_LogDataEvnt12_ChangeOfVin(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt12_ChangeOfVinType
 *   uint8 *Rte_Pim_LogDataEvnt12_ChangeOfVin_Mirror(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt12_ChangeOfVinType
 *   uint8 *Rte_Pim_LogDataEvnt13_AclReplacement(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt13_AclReplacementType
 *   uint8 *Rte_Pim_LogDataEvnt13_AclReplacement_Mirror(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt13_AclReplacementType
 *   uint8 *Rte_Pim_LogDataEvnt1_FailedCertVerif(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt1_FailedCertVerifType
 *   uint8 *Rte_Pim_LogDataEvnt1_FailedCertVerif_Mirror(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt1_FailedCertVerifType
 *   uint8 *Rte_Pim_LogDataEvnt2_SucCertVerif(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt2_SucCertVerifType
 *   uint8 *Rte_Pim_LogDataEvnt2_SucCertVerif_Mirror(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt2_SucCertVerifType
 *   uint8 *Rte_Pim_LogDataEvnt3_SucAuthAndEnhanceRights(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt3_SucAuthAndEnhanceRightsType
 *   uint8 *Rte_Pim_LogDataEvnt3_SucAuthAndEnhanceRights_Mirror(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt3_SucAuthAndEnhanceRightsType
 *   uint8 *Rte_Pim_LogDataEvnt4_AuthBySecAccess(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt4_AuthBySecAccessType
 *   uint8 *Rte_Pim_LogDataEvnt4_AuthBySecAccess_Mirror(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt4_AuthBySecAccessType
 *   uint8 *Rte_Pim_LogDataEvnt5_SucDiagServiceExec(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt5_SucDiagServiceExecType
 *   uint8 *Rte_Pim_LogDataEvnt5_SucDiagServiceExec_Mirror(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt5_SucDiagServiceExecType
 *   uint8 *Rte_Pim_LogDataEvnt6_RightsMgmt(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt6_RightsMgmtType
 *   uint8 *Rte_Pim_LogDataEvnt6_RightsMgmt_Mirror(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt6_RightsMgmtType
 *   uint8 *Rte_Pim_LogDataEvnt7_SigVerif(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt7_SigVerifType
 *   uint8 *Rte_Pim_LogDataEvnt7_SigVerif_Mirror(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt7_SigVerifType
 *   uint8 *Rte_Pim_LogDataEvnt8_TickCountDateAndTime(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt8_TickCountDateAndTimeType
 *   uint8 *Rte_Pim_LogDataEvnt8_TickCountDateAndTime_Mirror(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt8_TickCountDateAndTimeType
 *   uint8 *Rte_Pim_LogDataEvnt9_SecOcMisconfig(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt9_SecOcMisconfigType
 *   uint8 *Rte_Pim_LogDataEvnt9_SecOcMisconfig_Mirror(void)
 *     Returnvalue: uint8* is of type SecLog_LogDataEvnt9_SecOcMisconfigType
 *   uint8 *Rte_Pim_LogFailedMacVerifCount_ExceededTh1(void)
 *     Returnvalue: uint8* is of type SecLog_LogFailedMacVerifCount_ExceededThType
 *   uint8 *Rte_Pim_LogFailedMacVerifCount_ExceededTh1_Mirror(void)
 *     Returnvalue: uint8* is of type SecLog_LogFailedMacVerifCount_ExceededThType
 *   uint8 *Rte_Pim_LogFailedMacVerifCount_ExceededTh2(void)
 *     Returnvalue: uint8* is of type SecLog_LogFailedMacVerifCount_ExceededThType
 *   uint8 *Rte_Pim_LogFailedMacVerifCount_ExceededTh2_Mirror(void)
 *     Returnvalue: uint8* is of type SecLog_LogFailedMacVerifCount_ExceededThType
 *   uint8 *Rte_Pim_LogFailedMacVerifCount_ExceededTh3(void)
 *     Returnvalue: uint8* is of type SecLog_LogFailedMacVerifCount_ExceededThType
 *   uint8 *Rte_Pim_LogFailedMacVerifCount_ExceededTh3_Mirror(void)
 *     Returnvalue: uint8* is of type SecLog_LogFailedMacVerifCount_ExceededThType
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   SecLog_LogEntryCtrlDataType *Rte_CData_NvM_SecLog_CtrlData_DefaultValue(void)
 *     Returnvalue: SecLog_LogEntryCtrlDataType* is of type SecLog_CtrlDataType
 *
 *********************************************************************************************************************/


#define Ssa_SecLog_START_SEC_CODE
#include "Ssa_SecLog_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_CSDataServices_DID_018B_SecOcDataID_ReadData
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <CSDataServices_DID_018B_SecOcDataID>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_CSDataServices_DID_018B_SecOcDataID_ReadData(uint8 *Data)
 *     Argument Data: uint8* is of type DataArrayType_uint8_2
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CSDataServices_DID_018B_SecOcDataID_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_CSDataServices_DID_018B_SecOcDataID_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
 /*!
  * \spec
  *    requires $lengthOf(Data) >= sizeof(DataArrayType_uint8_2);
  * \endspec
  */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_CSDataServices_DID_018B_SecOcDataID_ReadData(P2VAR(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_CSDataServices_DID_018B_SecOcDataID_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_CSDataServices_DID_018B_SecOcDataID_E_NOT_OK;

 /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint16 dataId = Ssa_SecLog_SecOCDataId_ThresholdReached;

    /* #10 Write SecOcDataId requested by DEM as environmental data to the output buffer with high byte first. */
    Data[0] = (uint8)(dataId >> 8u);
    Data[1] = (uint8)(dataId & 0xFFu);

    retVal = RTE_E_OK;
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING
 *   RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType retVal = RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    retVal = RTE_E_OK;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
      Rte_Enter_SecLog_ExclusiveArea();
      if (Ssa_SecLog_MirrorRamBlockUsed == SSA_SECLOG_MIRRORRAMBLOCK_UNUSED)
      {
        /* #20 If mirror RAM block is unused set mirror RAM block as used by diagnostic service and start a time-out. */
        Ssa_SecLog_MirrorRamBlockUsed = SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_DIAGSERVICE + SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_DIAGSERVICE_TIMEOUT;
      }
      else
      {
        /* #30 Else return to DCM that request is pending. */
        retVal = RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING;
      }
      Rte_Exit_SecLog_ExclusiveArea();
    }
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_KeyM_Certificate_SignData1024ByteWithEcuPrivateKey(const uint8 *data, uint16 dataLength, uint8 *signature)
 *     Argument data: uint8* is of type Ssa_Data1024ByteType
 *     Argument signature: uint8* is of type Ssa_Data64ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_KeyM_Certificate_E_NOT_OK, RTE_E_KeyM_Certificate_E_PENDING
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1024ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING
 *   RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData_doc
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
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data1024ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType retVal = RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK;
  boolean readLog = FALSE;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    Std_ReturnType localRetVal = SecLog_DataServices_Security_Event_ReadData_DcmAndRamBlockCheck(OpStatus, &readLog);
    if (localRetVal == E_OK)
    {
      retVal = RTE_E_OK;
    }

    /* #10 Fill security log data into out buffer if mirror RAM block is available for reading. */
    if (readLog == TRUE)
    {
      retVal = SecLog_FillInSecurityEventLog(Data, FALSE);
    }

    /* #20 Calculate the signature from the output log data and append the signature to the output data. */
    if (retVal == RTE_E_OK)
    {
      /*@ assert SECLOG_SIZEOF_GLOBAL_EVENT_COUNTERS_OUTPUT_OVERHEAD <= ((SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS * 2u) + 8u); */
      /*@ assert SECLOG_AGGREGATED_GLOBAL_COUNTER_LENGTH <= 63u + (3u*2u*SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS); */
      /*@ assert Ssa_SecLog_ReadDataLength <= SECLOG_SIZEOF_GLOBAL_EVENT_COUNTERS_OUTPUT_OVERHEAD + SECLOG_AGGREGATED_GLOBAL_COUNTER_LENGTH; */ /* VCA_SSA_SECLOG_READ_DATA_LENGTH_FOR_LOG_COUNTER_CURRENT_VALUES */
      uint16 logDataOutLength = SECLOG_SIZE_OF_READ_DATA_LENGTH + Ssa_SecLog_ReadDataLength;
      /*@ assert logDataOutLength <= (2u + SECLOG_SIZEOF_GLOBAL_EVENT_COUNTERS_OUTPUT_OVERHEAD + SECLOG_AGGREGATED_GLOBAL_COUNTER_LENGTH); */

      /* Sign the output log data. */
      retVal = Rte_Call_KeyM_Certificate_SignData1024ByteWithEcuPrivateKey(
        &Data[0],
        logDataOutLength,
        &Data[logDataOutLength]);

      if (retVal == RTE_E_KeyM_Certificate_E_PENDING)
      {
        retVal = RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING;
      }
      else if (retVal != RTE_E_OK)
      {
        retVal = RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK;
      }
      else
      {
        /* Success */
      }
    }

    /* #30 If service execution is completed set mirror RAM as unused. */
    if (retVal != RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING)
    {
      Ssa_SecLog_MirrorRamBlockUsed = SSA_SECLOG_MIRRORRAMBLOCK_UNUSED;
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
 * Runnable Entity Name: Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING
 *   RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK;
  uint16 idxBlock;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (DataLength == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    Rte_Enter_SecLog_ExclusiveArea();
    /* #10 Check output buffer for null pointer and check usage of the mirror RAM block by diag. service
    * did not time out. */
    if (Ssa_SecLog_MirrorRamBlockUsed >= SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_DIAGSERVICE)
    {
      /* #20 Iterate through all SecLog's NVM blocks and copy all logging data into the RAM mirror. */
      for (idxBlock = 0u; idxBlock < SSA_SECLOG_NUM_NVM_BLOCKS; ++idxBlock)
      {
        /* PRQA S 0314, 0315 4 */ /* MD_SSA_P2VOID_CAST */
        Ssa_MemCpy( /* VCA_SSA_SECLOG_NVMADDR_NVMCTRL_CORRESPONDENCE */
          Ssa_SecLog_NvmAddress[idxBlock].ramBlockMirror,
          (P2CONST(void, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA))Ssa_SecLog_NvmAddress[idxBlock].ramBlock,
          Ssa_SecLog_NvmCtrl[idxBlock].ramBlockSize); /*lint !e545 */
      }
      Rte_Exit_SecLog_ExclusiveArea();

      /* #30 Calculate the output data length of the log data and store it. */
      Ssa_SecLog_ReadDataLength = (uint16)(SECLOG_SIZEOF_GLOBAL_EVENT_COUNTERS_OUTPUT_OVERHEAD);
      /*@ assert SECLOG_SIZEOF_GLOBAL_EVENT_COUNTERS_OUTPUT_OVERHEAD <= ((SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS * 2u) + 8u); */

      for (idxBlock = 0u; idxBlock < SSA_SECLOG_NUM_NVM_BLOCKS; ++idxBlock)
      {
        Ssa_SecLog_ReadDataLength += Ssa_SecLog_NvmCtrl[idxBlock].globCntSize;
      }
      /*@ assert Ssa_SecLog_NvmCtrl[0].globCntSize == SSA_SECLOG_SIZE_GLOBCOUNT_1; */
      /*@ assert Ssa_SecLog_NvmCtrl[1].globCntSize == SSA_SECLOG_SIZE_GLOBCOUNT_2; */
      /*@ assert Ssa_SecLog_NvmCtrl[2].globCntSize == SSA_SECLOG_SIZE_GLOBCOUNT_3; */
      /*@ assert Ssa_SecLog_NvmCtrl[3].globCntSize == SSA_SECLOG_SIZE_GLOBCOUNT_4; */
      /*@ assert Ssa_SecLog_NvmCtrl[4].globCntSize == SSA_SECLOG_SIZE_GLOBCOUNT_5; */
      /*@ assert Ssa_SecLog_NvmCtrl[5].globCntSize == SSA_SECLOG_SIZE_GLOBCOUNT_6; */
      /*@ assert Ssa_SecLog_NvmCtrl[6].globCntSize == SSA_SECLOG_SIZE_GLOBCOUNT_7; */
      /*@ assert Ssa_SecLog_NvmCtrl[7].globCntSize == SSA_SECLOG_SIZE_GLOBCOUNT_8; */
      /*@ assert Ssa_SecLog_NvmCtrl[8].globCntSize == SSA_SECLOG_SIZE_GLOBCOUNT_9; */
      /*@ assert Ssa_SecLog_NvmCtrl[9].globCntSize == SSA_SECLOG_SIZE_GLOBCOUNT_10; */
      /*@ assert Ssa_SecLog_NvmCtrl[10].globCntSize == SSA_SECLOG_SIZE_GLOBCOUNT_11; */
      /*@ assert Ssa_SecLog_NvmCtrl[11].globCntSize == SSA_SECLOG_SIZE_GLOBCOUNT_12; */
      /*@ assert Ssa_SecLog_NvmCtrl[12].globCntSize == SSA_SECLOG_SIZE_GLOBCOUNT_13; */
      /*@ assert Ssa_SecLog_NvmCtrl[13].globCntSize == SSA_SECLOG_SIZE_GLOBCOUNT_14; */
      /*@ assert Ssa_SecLog_NvmCtrl[14].globCntSize == SSA_SECLOG_SIZE_GLOBCOUNT_15; */
      /*@ assert Ssa_SecLog_NvmCtrl[15].globCntSize == SSA_SECLOG_SIZE_GLOBCOUNT_16; */
      /*@ assert SECLOG_AGGREGATED_GLOBAL_COUNTER_LENGTH <= 63u + (3u*2u*SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS); */

      /*@ assert Ssa_SecLog_ReadDataLength <= (SECLOG_SIZEOF_GLOBAL_EVENT_COUNTERS_OUTPUT_OVERHEAD + SECLOG_AGGREGATED_GLOBAL_COUNTER_LENGTH);*/ /* VCA_SSA_SECLOG_READ_DATA_LENGTH_FOR_LOG_COUNTER_CURRENT_VALUES */

      /* #40 Write the total data length that is read by this service to the output buffer. */
      *DataLength = SECLOG_SIZE_OF_READ_DATA_LENGTH + Ssa_SecLog_ReadDataLength + SECLOG_SIZEOF_SIGNATURE;
      retVal = RTE_E_OK;
    }
    else
    {
      Rte_Exit_SecLog_ExclusiveArea();
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
 * Runnable Entity Name: Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Security_Event_Log_Read_Security_Event_Log_Entry>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING
 *   RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    retVal = RTE_E_OK;
    *ErrorCode = DCM_E_POSITIVERESPONSE;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
      Rte_Enter_SecLog_ExclusiveArea();
      if (Ssa_SecLog_MirrorRamBlockUsed == SSA_SECLOG_MIRRORRAMBLOCK_UNUSED)
      {
        /* #20 If mirror RAM block is unused set mirror RAM block as used by diagnostic service and start a time-out. */
        Ssa_SecLog_MirrorRamBlockUsed = SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_DIAGSERVICE + SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_DIAGSERVICE_TIMEOUT;
      }
      else
      {
        /* #30 Else return to DCM that request is pending. */
        retVal = RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING;
      }
      Rte_Exit_SecLog_ExclusiveArea();
    }
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Security_Event_Log_Read_Security_Event_Log_Entry>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_KeyM_Certificate_SignData4092ByteWithEcuPrivateKey(const uint8 *data, uint16 dataLength, uint8 *signature)
 *     Argument data: uint8* is of type Ssa_Data4092ByteType
 *     Argument signature: uint8* is of type Ssa_Data64ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_KeyM_Certificate_E_NOT_OK, RTE_E_KeyM_Certificate_E_PENDING
 *   Std_ReturnType Rte_Call_TimeM_RealTime_Get(TimeM_DateTimeType *realTime)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_RealTime_E_NOT_OK
 *   Std_ReturnType Rte_Call_TimeM_TickCount_Get(uint64 *tickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_TickCount_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4092ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING
 *   RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData_doc
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
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data4092ByteType);
 * \endspec
*/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType retVal = RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK;
  boolean readLog = FALSE;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    Std_ReturnType localRetVal = SecLog_DataServices_Security_Event_ReadData_DcmAndRamBlockCheck(OpStatus, &readLog);
    if (localRetVal == E_OK)
    {
      retVal = RTE_E_OK;
    }

    /* #10 Fill security log data into out buffer if mirror RAM block is available for reading. */
    if (readLog == TRUE)
    {
      retVal = SecLog_FillInSecurityEventLog(Data, TRUE);
    }

    /* #20 Calculate the signature from the output log data and append the signature to the output data. */
    if (retVal == RTE_E_OK)
    {
      /*@ assert  Ssa_SecLog_ReadDataLength < SECLOG_SIZEOF_GLOBAL_EVENT_COUNTERS_OUTPUT_OVERHEAD + SECLOG_AGGREGATED_CIRCULAR_BUFFER_LENGTH + SECLOG_AGGREGATED_GLOBAL_COUNTER_LENGTH + (SSA_SECLOG_NUMBER_OF_EVENTS * SECLOG_SIZEOF_CIRCULAR_BUFFER_OUTPUT_OVERHEAD); */ /* VCA_SSA_SECLOG_READ_DATA_LENGTH_FOR_LOG_ENTRY */
      uint16 logDataOutLength = SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME + SECLOG_SIZE_OF_READ_DATA_LENGTH + Ssa_SecLog_ReadDataLength;

      /* Sign the output log data. */
      retVal = Rte_Call_KeyM_Certificate_SignData4092ByteWithEcuPrivateKey(
        &Data[0],
        logDataOutLength,
        &Data[logDataOutLength]);

      if (retVal == RTE_E_KeyM_Certificate_E_PENDING)
      {
        retVal = RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING;
      }
      else if (retVal != RTE_E_OK)
      {
        retVal = RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK;
      }
      else
      {
        /* Success */
      }
    }

    if (retVal != RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING)
    {
      /* #30 Set mirror RAM as unused. */
      Ssa_SecLog_MirrorRamBlockUsed = SSA_SECLOG_MIRRORRAMBLOCK_UNUSED;
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
 * Runnable Entity Name: Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_Security_Event_Log_Read_Security_Event_Log_Entry>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING
 *   RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength(Dcm_OpStatusType OpStatus, P2VAR(uint16, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType ret = RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK;
  uint16 i;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (DataLength == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    Rte_Enter_SecLog_ExclusiveArea();
    /* #10 Check output buffer for null pointer and check usage of the mirror RAM block by diag. service
     * did not time out. */
    if (Ssa_SecLog_MirrorRamBlockUsed >= SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_DIAGSERVICE)
    {
      /* #20 Iterate through all SecLog's NVM blocks and copy all logging data into the RAM mirror. */
      for (i = 0u; i < SSA_SECLOG_NUM_NVM_BLOCKS; ++i)
      {
        /* PRQA S 0314, 0315 4 */ /* MD_SSA_P2VOID_CAST */
        Ssa_MemCpy( /* VCA_SSA_SECLOG_NVMADDR_NVMCTRL_CORRESPONDENCE */
          Ssa_SecLog_NvmAddress[i].ramBlockMirror,
          (P2CONST(void, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA))Ssa_SecLog_NvmAddress[i].ramBlock,
          Ssa_SecLog_NvmCtrl[i].ramBlockSize); /*lint !e545 */
      }
      Rte_Exit_SecLog_ExclusiveArea();

      /* #30 Calculate the output data length of the log data and store it. */
      Ssa_SecLog_ReadDataLength = (uint16)(SECLOG_SIZEOF_GLOBAL_EVENT_COUNTERS_OUTPUT_OVERHEAD);
      for (i = 0u; i < SSA_SECLOG_NUM_NVM_BLOCKS; ++i)
      {
        if (i < SSA_SECLOG_NUMBER_OF_EVENTS)
        {
          /* These values sum up to SECLOG_AGGREGATED_CIRCULAR_BUFFER_LENGTH: */
          Ssa_SecLog_ReadDataLength += Ssa_SecLog_NvmCtrl_GetLengthContent(i);
        }
        /* These values sum up to SECLOG_AGGREGATED_GLOBAL_COUNTER_LENGTH: */
        Ssa_SecLog_ReadDataLength += Ssa_SecLog_NvmCtrl[i].globCntSize;
      }
      Ssa_SecLog_ReadDataLength += SSA_SECLOG_NUMBER_OF_EVENTS * SECLOG_SIZEOF_CIRCULAR_BUFFER_OUTPUT_OVERHEAD;

      /* #40 Write the total data length that is read by this service to the output buffer. */
      *DataLength = SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME + SECLOG_SIZE_OF_READ_DATA_LENGTH
        + Ssa_SecLog_ReadDataLength + SECLOG_SIZEOF_SIGNATURE;

      ret = RTE_E_OK;
      /*@ assert  Ssa_SecLog_ReadDataLength < SECLOG_SIZEOF_GLOBAL_EVENT_COUNTERS_OUTPUT_OVERHEAD + SECLOG_AGGREGATED_CIRCULAR_BUFFER_LENGTH + SECLOG_AGGREGATED_GLOBAL_COUNTER_LENGTH + (SSA_SECLOG_NUMBER_OF_EVENTS * SECLOG_SIZEOF_CIRCULAR_BUFFER_OUTPUT_OVERHEAD); */ /* VCA_SSA_SECLOG_READ_DATA_LENGTH_FOR_LOG_ENTRY */
    }
    else
    {
      Rte_Exit_SecLog_ExclusiveArea();
    }
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return ret;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_IgnitionStatusChanged
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <Ign_Stat_Pr5_ST3> of PortPrototype <Ssa_IgnitionStatus>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3(Ssa_IgnitionStatusType *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_IgnitionStatusChanged_doc
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

FUNC(void, Ssa_SecLog_CODE) Ssa_SecLog_IgnitionStatusChanged(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_IgnitionStatusChanged
 *********************************************************************************************************************/
  Ssa_IgnitionStatusType ignitionStatus;
  /* #10 Read the current ignition status. */
  Std_ReturnType retVal = Rte_Read_Ssa_IgnitionStatus_Ign_Stat_Pr5_ST3(&ignitionStatus);
  if(retVal == E_OK)
  {
    /* #20 Check that the current ignition status is on and that the previous ignition status was not on. */
    if ((ignitionStatus.ISw_Stat_ST3 == I_C03_ISW_STAT_IGN_ON) && (Ssa_SecLog_PreviousIgnitionState.ISw_Stat_ST3 != I_C03_ISW_STAT_IGN_ON))
    {
      Ssa_SecLogInfoIterType i;

      /* #25 Set DEM event status for DTC 0xD12083 to "passed" and clear the belonging environmental data. */
      (void)Rte_Call_DTC_0xD12083_SetEventStatus(DEM_EVENT_STATUS_PASSED);

      Ssa_SecLog_SecOCDataId_ThresholdReached = 0u;

      /* #30 Clear for all DataIds the flag indicating that a failed MAC verification event has been logged and the MAC verification counter. */
      for (i = 0u; i < (Ssa_GetSizeOfSecLogInfo()); i++)
      {
        Ssa_SecLog_FailedMacVerificationCounterDtc[i] = 0x00u;
      }

      /* #35 Clear the flags indicating that local tick-count change events have been logged. */
      Ssa_SecLog_LocalTickCountDateTimeChangeEventLogged = 0x00u;

      /* #40 Reset the elapsed time counter. */
      Ssa_SecLog_ElapsedTime = 0u;
      /* #50 Reset SecOcVerificationState. */
      Write_SecOcVerificationState(SECLOG_SECOCVERIFICATIONSTATE_INITIAL);
    }

    /* 60 Finally store the current ignition status as new previous ignition status. */
    Ssa_SecLog_PreviousIgnitionState = ignitionStatus;
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt13_AclReplacement_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt2_SucCertVerif_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt6_RightsMgmt_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt7_SigVerif_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_Init_doc
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

FUNC(void, Ssa_SecLog_CODE) Ssa_SecLog_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_Init
 *********************************************************************************************************************/
  uint16 i;
  Ssa_SecLog_ReadDataLength = 0u;

#if (SSA_SECLOG_USE_PIM_ACCESS_MACROS_AS_COMPILE_TIME_CONSTANTS == STD_OFF)
  /* #5 Set the NvRam block addresses.
   *    The RTE macros for accessing the PIM addresses are not necessarily compile time constants. */
  /*lint -save -e545 */
  /* ********** FAILED_CERTIFICATE_VERIFICATION_EVENT ********** */
  Ssa_SecLog_NvmAddress[0].ramBlock = Rte_Pim_LogDataEvnt1_FailedCertVerif();
  Ssa_SecLog_NvmAddress[0].ramBlockMirror = Rte_Pim_LogDataEvnt1_FailedCertVerif_Mirror();
  /* ********** SUCCESSFUL_CERTIFICATE_VERIFICATION_EVENT ********** */
  Ssa_SecLog_NvmAddress[1].ramBlock = Rte_Pim_LogDataEvnt2_SucCertVerif();
  Ssa_SecLog_NvmAddress[1].ramBlockMirror = Rte_Pim_LogDataEvnt2_SucCertVerif_Mirror();
  /* ********** SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS_EVENT ********** */
  Ssa_SecLog_NvmAddress[2].ramBlock = Rte_Pim_LogDataEvnt3_SucAuthAndEnhanceRights();
  Ssa_SecLog_NvmAddress[2].ramBlockMirror = Rte_Pim_LogDataEvnt3_SucAuthAndEnhanceRights_Mirror();
  /* ********** AUTHORIZATION_BY_SECURITY_ACCESS_EVENT ********** */
  Ssa_SecLog_NvmAddress[3].ramBlock = Rte_Pim_LogDataEvnt4_AuthBySecAccess();
  Ssa_SecLog_NvmAddress[3].ramBlockMirror = Rte_Pim_LogDataEvnt4_AuthBySecAccess_Mirror();
  /* ********** SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION_EVENT ********** */
  Ssa_SecLog_NvmAddress[4].ramBlock = Rte_Pim_LogDataEvnt5_SucDiagServiceExec();
  Ssa_SecLog_NvmAddress[4].ramBlockMirror = Rte_Pim_LogDataEvnt5_SucDiagServiceExec_Mirror();
  /* ********** RIGHTS_MANAGEMENT_EVENT ********** */
  Ssa_SecLog_NvmAddress[5].ramBlock = Rte_Pim_LogDataEvnt6_RightsMgmt();
  Ssa_SecLog_NvmAddress[5].ramBlockMirror = Rte_Pim_LogDataEvnt6_RightsMgmt_Mirror();
  /* ********** SIGNATURE_VERIFICATION_EVENT ********** */
  Ssa_SecLog_NvmAddress[6].ramBlock = Rte_Pim_LogDataEvnt7_SigVerif();
  Ssa_SecLog_NvmAddress[6].ramBlockMirror = Rte_Pim_LogDataEvnt7_SigVerif_Mirror();
  /* ********** CHANGE_OF_TICK_COUNT_OR_DATE_AND_TIME_EVENT ********** */
  Ssa_SecLog_NvmAddress[7].ramBlock = Rte_Pim_LogDataEvnt8_TickCountDateAndTime();
  Ssa_SecLog_NvmAddress[7].ramBlockMirror = Rte_Pim_LogDataEvnt8_TickCountDateAndTime_Mirror();
  /* ********** SECOC_MISCONFIGURATION_EVENT ********** */
  Ssa_SecLog_NvmAddress[8].ramBlock = Rte_Pim_LogDataEvnt9_SecOcMisconfig();
  Ssa_SecLog_NvmAddress[8].ramBlockMirror = Rte_Pim_LogDataEvnt9_SecOcMisconfig_Mirror();
  /* ********** FAILED_PDU_MAC_VERIFICATION_EVENT ********** */
  Ssa_SecLog_NvmAddress[9].ramBlock = Rte_Pim_LogDataEvnt10_FailedPduMacVerif();
  Ssa_SecLog_NvmAddress[9].ramBlockMirror = Rte_Pim_LogDataEvnt10_FailedPduMacVerif_Mirror();
  /* ********** SECURE_BOOT_OR_AUTHENTICATED_BOOT_EVENT ********** */
  Ssa_SecLog_NvmAddress[10].ramBlock = Rte_Pim_LogDataEvnt11_SecOrAuthBoot();
  Ssa_SecLog_NvmAddress[10].ramBlockMirror = Rte_Pim_LogDataEvnt11_SecOrAuthBoot_Mirror();
  /* ********** CHANGE_OF_VIN ********** */
  Ssa_SecLog_NvmAddress[11].ramBlock = Rte_Pim_LogDataEvnt12_ChangeOfVin();
  Ssa_SecLog_NvmAddress[11].ramBlockMirror = Rte_Pim_LogDataEvnt12_ChangeOfVin_Mirror();
  /* ********** ECU_INDIVIDUAL_ACL_REPLACEMENT_EVENT ********** */
  Ssa_SecLog_NvmAddress[12].ramBlock = Rte_Pim_LogDataEvnt13_AclReplacement();
  Ssa_SecLog_NvmAddress[12].ramBlockMirror = Rte_Pim_LogDataEvnt13_AclReplacement_Mirror();
  /* ********** MAC_VERIFICATION_COUNT_EXCEEDED_THRESHOLD_1 ********** */
  Ssa_SecLog_NvmAddress[13].ramBlock = Rte_Pim_LogFailedMacVerifCount_ExceededTh1();
  Ssa_SecLog_NvmAddress[13].ramBlockMirror = Rte_Pim_LogFailedMacVerifCount_ExceededTh1_Mirror();
  /* ********** MAC_VERIFICATION_COUNT_EXCEEDED_THRESHOLD_2 ********** */
  Ssa_SecLog_NvmAddress[14].ramBlock = Rte_Pim_LogFailedMacVerifCount_ExceededTh2();
  Ssa_SecLog_NvmAddress[14].ramBlockMirror = Rte_Pim_LogFailedMacVerifCount_ExceededTh2_Mirror();
  /* ********** MAC_VERIFICATION_COUNT_EXCEEDED_THRESHOLD_3 ********** */
  Ssa_SecLog_NvmAddress[15].ramBlock = Rte_Pim_LogFailedMacVerifCount_ExceededTh3();
  Ssa_SecLog_NvmAddress[15].ramBlockMirror = Rte_Pim_LogFailedMacVerifCount_ExceededTh3_Mirror();
  /*lint -restore */
#endif

  /* #10 Initialize the NVRam blocks containing the security log data. */
  SecLog_InitializeNvRamBlocks();

  /* #20 Initialize all static variables. */
  Ssa_SecLog_PreviousIgnitionState.ISw_Stat_ST3 = I_C03_ISW_STAT_IGN_LOCK;
  for (i = 0u; i < (Ssa_GetSizeOfSecLogInfo()); i++)
  {
    Ssa_SecLog_FailedMacVerificationCounter[i] = 0x00u;
    Ssa_SecLog_FailedMacVerificationCounterDtc[i] = 0x00;
  }

  Ssa_SecLog_LocalTickCountDateTimeChangeEventLogged = 0x00;

  Write_SecOcVerificationState(SECLOG_SECOCVERIFICATIONSTATE_INITIAL);

  /* Iterate through all SecLog's NVM blocks. */
  for (i = 0u; i < SSA_SECLOG_NUM_NVM_BLOCKS; ++i)
  {
    Ssa_SecLog_NvMSetRamBlockStatus[i] = FALSE;
    Ssa_SecLog_NvMWriteRequested[i] = FALSE;
    Ssa_SecLog_NvMWriteState[i] = SECLOG_NVM_WRITE_STATE_IDLE;
  }
  Ssa_SecLog_MirrorRamBlockUsed = SSA_SECLOG_MIRRORRAMBLOCK_UNUSED;
  Ssa_SecLog_MirrorRamBlockUsedBits = 0uL;
  Ssa_SecLog_SecOCDataId_ThresholdReached = 0u;
  Ssa_SecLog_LocalTickCountSyncStatus = SSA_TICKCOUNT_SYNC_STATE_NOT_SYNCHRONIZED;

  /* Set IRVs. */
  Ssa_SecLog_ElapsedTime = 0u;
  Ssa_SecLog_LoggingActiveTimer = 0u;

  /* Assertions to make clear that Ssa_SecLog_NvmAddress[idxBlock].ramBlock != NULL_PTR: */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[0].ramBlock) >= sizeof(SecLog_LogDataEvnt1_FailedCertVerifType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[1].ramBlock) >= sizeof(SecLog_LogDataEvnt2_SucCertVerifType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[2].ramBlock) >= sizeof(SecLog_LogDataEvnt3_SucAuthAndEnhanceRightsType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[3].ramBlock) >= sizeof(SecLog_LogDataEvnt4_AuthBySecAccessType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[4].ramBlock) >= sizeof(SecLog_LogDataEvnt5_SucDiagServiceExecType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[5].ramBlock) >= sizeof(SecLog_LogDataEvnt6_RightsMgmtType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[6].ramBlock) >= sizeof(SecLog_LogDataEvnt7_SigVerifType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[7].ramBlock) >= sizeof(SecLog_LogDataEvnt8_TickCountDateAndTimeType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[8].ramBlock) >= sizeof(SecLog_LogDataEvnt9_SecOcMisconfigType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[9].ramBlock) >= sizeof(SecLog_LogDataEvnt10_FailedPduMacVerifType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[10].ramBlock) >= sizeof(SecLog_LogDataEvnt11_SecOrAuthBootType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[11].ramBlock) >= sizeof(SecLog_LogDataEvnt12_ChangeOfVinType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[12].ramBlock) >= sizeof(SecLog_LogDataEvnt13_AclReplacementType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[13].ramBlock) >= sizeof(SecLog_LogFailedMacVerifCount_ExceededThType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[14].ramBlock) >= sizeof(SecLog_LogFailedMacVerifCount_ExceededThType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[15].ramBlock) >= sizeof(SecLog_LogFailedMacVerifCount_ExceededThType); */

  /* Assertions to make clear that Ssa_SecLog_NvmAddress[idxBlock].ramBlockMirror != NULL_PTR: */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[0].ramBlockMirror) >= sizeof(SecLog_LogDataEvnt1_FailedCertVerifType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[1].ramBlockMirror) >= sizeof(SecLog_LogDataEvnt2_SucCertVerifType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[2].ramBlockMirror) >= sizeof(SecLog_LogDataEvnt3_SucAuthAndEnhanceRightsType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[3].ramBlockMirror) >= sizeof(SecLog_LogDataEvnt4_AuthBySecAccessType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[4].ramBlockMirror) >= sizeof(SecLog_LogDataEvnt5_SucDiagServiceExecType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[5].ramBlockMirror) >= sizeof(SecLog_LogDataEvnt6_RightsMgmtType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[6].ramBlockMirror) >= sizeof(SecLog_LogDataEvnt7_SigVerifType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[7].ramBlockMirror) >= sizeof(SecLog_LogDataEvnt8_TickCountDateAndTimeType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[8].ramBlockMirror) >= sizeof(SecLog_LogDataEvnt9_SecOcMisconfigType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[9].ramBlockMirror) >= sizeof(SecLog_LogDataEvnt10_FailedPduMacVerifType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[10].ramBlockMirror) >= sizeof(SecLog_LogDataEvnt11_SecOrAuthBootType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[11].ramBlockMirror) >= sizeof(SecLog_LogDataEvnt12_ChangeOfVinType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[12].ramBlockMirror) >= sizeof(SecLog_LogDataEvnt13_AclReplacementType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[13].ramBlockMirror) >= sizeof(SecLog_LogFailedMacVerifCount_ExceededThType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[14].ramBlockMirror) >= sizeof(SecLog_LogFailedMacVerifCount_ExceededThType); */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[15].ramBlockMirror) >= sizeof(SecLog_LogFailedMacVerifCount_ExceededThType); */

  /* Assertions on the relation between Ssa_SecLog_NvmAddress and Ssa_SecLog_NvmCtrl for ramBlock: */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[0].ramBlock) >= Ssa_SecLog_NvmCtrl[0].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[1].ramBlock) >= Ssa_SecLog_NvmCtrl[1].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[2].ramBlock) >= Ssa_SecLog_NvmCtrl[2].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[3].ramBlock) >= Ssa_SecLog_NvmCtrl[3].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[4].ramBlock) >= Ssa_SecLog_NvmCtrl[4].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[5].ramBlock) >= Ssa_SecLog_NvmCtrl[5].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[6].ramBlock) >= Ssa_SecLog_NvmCtrl[6].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[7].ramBlock) >= Ssa_SecLog_NvmCtrl[7].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[8].ramBlock) >= Ssa_SecLog_NvmCtrl[8].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[9].ramBlock) >= Ssa_SecLog_NvmCtrl[9].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[10].ramBlock) >= Ssa_SecLog_NvmCtrl[10].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[11].ramBlock) >= Ssa_SecLog_NvmCtrl[11].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[12].ramBlock) >= Ssa_SecLog_NvmCtrl[12].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[13].ramBlock) >= Ssa_SecLog_NvmCtrl[13].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[14].ramBlock) >= Ssa_SecLog_NvmCtrl[14].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[15].ramBlock) >= Ssa_SecLog_NvmCtrl[15].ramBlockSize; */

  /* Assertions on the relation between Ssa_SecLog_NvmAddress and Ssa_SecLog_NvmCtrl for ramBlockMirror: */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[0].ramBlockMirror) >= Ssa_SecLog_NvmCtrl[0].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[1].ramBlockMirror) >= Ssa_SecLog_NvmCtrl[1].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[2].ramBlockMirror) >= Ssa_SecLog_NvmCtrl[2].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[3].ramBlockMirror) >= Ssa_SecLog_NvmCtrl[3].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[4].ramBlockMirror) >= Ssa_SecLog_NvmCtrl[4].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[5].ramBlockMirror) >= Ssa_SecLog_NvmCtrl[5].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[6].ramBlockMirror) >= Ssa_SecLog_NvmCtrl[6].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[7].ramBlockMirror) >= Ssa_SecLog_NvmCtrl[7].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[8].ramBlockMirror) >= Ssa_SecLog_NvmCtrl[8].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[9].ramBlockMirror) >= Ssa_SecLog_NvmCtrl[9].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[10].ramBlockMirror) >= Ssa_SecLog_NvmCtrl[10].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[11].ramBlockMirror) >= Ssa_SecLog_NvmCtrl[11].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[12].ramBlockMirror) >= Ssa_SecLog_NvmCtrl[12].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[13].ramBlockMirror) >= Ssa_SecLog_NvmCtrl[13].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[14].ramBlockMirror) >= Ssa_SecLog_NvmCtrl[14].ramBlockSize; */
  /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[15].ramBlockMirror) >= Ssa_SecLog_NvmCtrl[15].ramBlockSize; */

  /* Assertions on the entry of Ssa_SecLog_NvmCtrl: */
  /*@ assert Ssa_SecLog_NvmCtrl[0].ramBlockSize == sizeof(SecLog_LogDataEvnt1_FailedCertVerifType); */
  /*@ assert Ssa_SecLog_NvmCtrl[1].ramBlockSize == sizeof(SecLog_LogDataEvnt2_SucCertVerifType); */
  /*@ assert Ssa_SecLog_NvmCtrl[2].ramBlockSize == sizeof(SecLog_LogDataEvnt3_SucAuthAndEnhanceRightsType); */
  /*@ assert Ssa_SecLog_NvmCtrl[3].ramBlockSize == sizeof(SecLog_LogDataEvnt4_AuthBySecAccessType); */
  /*@ assert Ssa_SecLog_NvmCtrl[4].ramBlockSize == sizeof(SecLog_LogDataEvnt5_SucDiagServiceExecType); */
  /*@ assert Ssa_SecLog_NvmCtrl[5].ramBlockSize == sizeof(SecLog_LogDataEvnt6_RightsMgmtType); */
  /*@ assert Ssa_SecLog_NvmCtrl[6].ramBlockSize == sizeof(SecLog_LogDataEvnt7_SigVerifType); */
  /*@ assert Ssa_SecLog_NvmCtrl[7].ramBlockSize == sizeof(SecLog_LogDataEvnt8_TickCountDateAndTimeType); */
  /*@ assert Ssa_SecLog_NvmCtrl[8].ramBlockSize == sizeof(SecLog_LogDataEvnt9_SecOcMisconfigType); */
  /*@ assert Ssa_SecLog_NvmCtrl[9].ramBlockSize == sizeof(SecLog_LogDataEvnt10_FailedPduMacVerifType); */
  /*@ assert Ssa_SecLog_NvmCtrl[10].ramBlockSize == sizeof(SecLog_LogDataEvnt11_SecOrAuthBootType); */
  /*@ assert Ssa_SecLog_NvmCtrl[11].ramBlockSize == sizeof(SecLog_LogDataEvnt12_ChangeOfVinType); */
  /*@ assert Ssa_SecLog_NvmCtrl[12].ramBlockSize == sizeof(SecLog_LogDataEvnt13_AclReplacementType); */
  /*@ assert Ssa_SecLog_NvmCtrl[13].ramBlockSize == sizeof(SecLog_LogFailedMacVerifCount_ExceededThType); */
  /*@ assert Ssa_SecLog_NvmCtrl[14].ramBlockSize == sizeof(SecLog_LogFailedMacVerifCount_ExceededThType); */
  /*@ assert Ssa_SecLog_NvmCtrl[15].ramBlockSize == sizeof(SecLog_LogFailedMacVerifCount_ExceededThType); */

  /* Ensure type sizes once for the SecLog submodule which calls RTE APIs expecting these data types:
   * Ssa_Data64ByteType must be an array with 64 element(s) of type uint8 */
  /*@ assert sizeof(Ssa_Data64ByteType) == 64; */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_InitMonitorForEvent_DTC_0xD12083
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <InitMonitorForEvent> of PortPrototype <CallbackInitMonitorForEvent_DTC_0xD12083>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_InitMonitorForEvent_DTC_0xD12083(Dem_InitMonitorReasonType InitMonitorReason)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackInitMonitorForEvent_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_InitMonitorForEvent_DTC_0xD12083_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_InitMonitorForEvent_DTC_0xD12083(Dem_InitMonitorReasonType InitMonitorReason) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_InitMonitorForEvent_DTC_0xD12083 (returns application error)
 *********************************************************************************************************************/

  /* #10 Check that "init monitor reason" is "clear". */
  if (InitMonitorReason == DEM_INIT_MONITOR_CLEAR)
  {
    Ssa_SecLogInfoIterType i;

    /* #20 Clear all counters related to this DTC. */
    for (i = 0u; i < (Ssa_GetSizeOfSecLogInfo()); i++)
    {
      Ssa_SecLog_FailedMacVerificationCounterDtc[i] = 0u;
    }
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_LogEvent_AuthorizationBySecurityAccess
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <AuthorizationBySecurityAccess> of PortPrototype <SecLog_AuthorizationBySecurityAccess>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SecLog_EventNotification_Data(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data7ByteType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RightsM_DiagnosticChannel_GetDiagChanAndAuthStatus(uint8 *diagChanAndAuthStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RightsM_DiagnosticChannel_E_NOT_OK
 *   Std_ReturnType Rte_Call_TimeM_TickCount_Get(uint64 *tickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_TickCount_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_LogEvent_AuthorizationBySecurityAccess(uint8 diagChanAuthStatus, uint8 securityLevel, uint8 securityAccessResult)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecLog_AuthorizationBySecurityAccess_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_AuthorizationBySecurityAccess_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_AuthorizationBySecurityAccess(uint8 diagChanAuthStatus, uint8 securityLevel, uint8 securityAccessResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_AuthorizationBySecurityAccess (returns application error)
 *********************************************************************************************************************/

  uint8 logEntryData[3];

  /* #10 Fill in log entry data. */
  logEntryData[0] = diagChanAuthStatus;
  logEntryData[1] = securityLevel;
  logEntryData[2] = securityAccessResult;
  /* #20 Write log entry. */
  SecLog_GetTimestampAndWriteLogEntry(SECLOG_EVENT_AUTHORIZATION_SECURITY_ACCESS, logEntryData);

#if (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON)         /* COV_SSA_DEBUG XF */
  {
    CANoeAPI_Printf("SecLog Event - Authorization by Security Access (%u): Diag.channel=%u, auth. status=%u, sec. level=%02X, access result=%02X",
      SECLOG_EVENT_AUTHORIZATION_SECURITY_ACCESS + 1u, (uint8)(diagChanAuthStatus & 0x0F), (uint8)((diagChanAuthStatus >> 7) & 0x01u), securityLevel, securityAccessResult);
  }
#endif /* (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON) */

  /* #30 Update global counters. Differentiate between successful and failed authorization. */
  /*@ assert (SECLOG_EVENT_AUTHORIZATION_SECURITY_ACCESS == 3u) && (SSA_SECLOG_SIZE_GLOBCOUNT_4 == 4u); */
  /*@ assert SSA_SECLOG_NVRAM_CTRL_DATA_SIZE == 8; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_AUTHORIZATION_SECURITY_ACCESS].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE])) >= 4; */ /* VCA_SSA_SECLOG_SIZE_OF_RAM_BLOCK_BUFFERS */
  if (securityAccessResult == 0x00u)
  {
    SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_SuccessfulAuthorization_SecurityAccess());
  }
  else
  {
    SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_FailedAuthorization_SecurityAccess());
  }

  /* #40 Request marking the RAM blocks as changed. */
  Ssa_SecLog_NvMSetRamBlockStatus[SECLOG_EVENT_AUTHORIZATION_SECURITY_ACCESS] = TRUE;

  /* #50 Notify logging. */
  SecLog_NotifyLogging();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_LogEvent_ChangeTickCountOrDateAndTime
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ChangeTickCountOrDateAndTime> of PortPrototype <SecLog_ChangeTickCountOrDateAndTimeEvent>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SecLog_EventNotification_Data(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data7ByteType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_TimeM_TickCount_Get(uint64 *tickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_TickCount_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_LogEvent_ChangeTickCountOrDateAndTime(uint8 contextDateTimeChange, const uint8 *deltaTimeChange)
 *     Argument deltaTimeChange: uint8* is of type Ssa_Data5ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecLog_ChangeTickCountOrDateAndTimeEvent_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_ChangeTickCountOrDateAndTime_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_ChangeTickCountOrDateAndTime(uint8 contextDateTimeChange, P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) deltaTimeChange) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_ChangeTickCountOrDateAndTime (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType retVal = RTE_E_SecLog_ChangeTickCountOrDateAndTimeEvent_E_NOT_OK;
  uint8 logEntryData[6] = { 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (deltaTimeChange == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Fill in log entry data. */
    logEntryData[0] = contextDateTimeChange;
    logEntryData[1] = deltaTimeChange[0];
    logEntryData[2] = deltaTimeChange[1];
    logEntryData[3] = deltaTimeChange[2];
    logEntryData[4] = deltaTimeChange[3];
    logEntryData[5] = deltaTimeChange[4];

    /* #20 Write log entry. */
    SecLog_GetTimestampAndWriteLogEntry(SECLOG_EVENT_CHANGE_TICK_COUNT_OR_DATE_AND_TIME, logEntryData);

    /* #30 Check if writing dummy log entries is required. */
    if (contextDateTimeChange == (uint8)(0x06u | 0x80u))
    {
      SecLog_WriteDummyLogEntries();
    }

#if (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON)         /* COV_SSA_DEBUG XF */
    {
      CANoeAPI_Printf("SecLog Event - Change tick count or date and time (%u): Origin/direction = 0x%02X, deltaTime=0x%02X%02X%02X%02X%02X",
        SECLOG_EVENT_CHANGE_TICK_COUNT_OR_DATE_AND_TIME,
        contextDateTimeChange, logEntryData[1], logEntryData[2], logEntryData[3], logEntryData[4], logEntryData[5]);
    }
#endif /* (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON) */

    /* #40 Update global counter. Differentiate between the case "time set to past" and "time set to future". */
    /*@ assert (SECLOG_EVENT_CHANGE_TICK_COUNT_OR_DATE_AND_TIME == 7u) && (SSA_SECLOG_SIZE_GLOBCOUNT_8 == 4u); */
    /*@ assert SSA_SECLOG_NVRAM_CTRL_DATA_SIZE == 8; */
    /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_CHANGE_TICK_COUNT_OR_DATE_AND_TIME].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE])) >= 4; */ /* VCA_SSA_SECLOG_SIZE_OF_RAM_BLOCK_BUFFERS */
    if (SecLog_BitOpTest(uint8, contextDateTimeChange, 0x80u))
    {
      SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_TimeSetToPast());
    }
    else
    {
      SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_TimeSetToFuture());
    }

    /* #50 Request writing the RAM blocks. */
    SecLog_CheckContextDateTimeChangeForNvmWriteRequest(contextDateTimeChange);

    /* #60 Notify logging. */
    SecLog_NotifyLogging();
    retVal = RTE_E_OK;
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_LogEvent_ChangeVin
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ChangeVin> of PortPrototype <SecLog_ChangeVinEvent>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SecLog_EventNotification_Data(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data7ByteType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_TimeM_TickCount_Get(uint64 *tickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_TickCount_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_LogEvent_ChangeVin(const uint8 *newVin)
 *     Argument newVin: uint8* is of type SecLog_VinType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecLog_ChangeVinEvent_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_ChangeVin_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_ChangeVin(P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) newVin) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_ChangeVin (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_SecLog_ChangeVinEvent_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (newVin == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 logEntryData[SSA_SIZEOF_VIN];
    uint8 i;

    for (i = 0u; i < SSA_SIZEOF_VIN; i++)
    {
      logEntryData[i] = newVin[i];
    }

    /* #10 Write log entry. */
    SecLog_GetTimestampAndWriteLogEntry(SECLOG_EVENT_CHANGE_VIN, logEntryData);

#if (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON)         /* COV_SSA_DEBUG XF */
    {
      CANoeAPI_Printf("SecLog Event - Change of vin (%u): New VIN=0x%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
        SECLOG_EVENT_CHANGE_VIN,
        newVin[0], newVin[1], newVin[2], newVin[3], newVin[4], newVin[5], newVin[6], newVin[7], newVin[8], newVin[9],
        newVin[10], newVin[11], newVin[12], newVin[13], newVin[14], newVin[15], newVin[16]);
    }
#endif /* (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON) */

    /* #20 Update global counter. */
    /*@ assert (SECLOG_EVENT_CHANGE_VIN == 11u) && (SSA_SECLOG_SIZE_GLOBCOUNT_12 == 2u); */
    /*@ assert SSA_SECLOG_NVRAM_CTRL_DATA_SIZE == 8; */
    /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_CHANGE_VIN].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE])) >= 2; */ /* VCA_SSA_SECLOG_SIZE_OF_RAM_BLOCK_BUFFERS */
    SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_ChangeOfVin());

    /* #30 Request marking the RAM blocks as changed. */
    Ssa_SecLog_NvMSetRamBlockStatus[SECLOG_EVENT_CHANGE_VIN] = TRUE;

    /* #40 Notify logging. */
    SecLog_NotifyLogging();
    retVal = RTE_E_OK;
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_LogEvent_EcuIndividualAclReplacement
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <EcuIndividualAclReplacement> of PortPrototype <SecLog_EcuIndividualAclReplacementEvent>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SecLog_EventNotification_Data(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data7ByteType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_TimeM_TickCount_Get(uint64 *tickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_TickCount_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_LogEvent_EcuIndividualAclReplacement(const uint8 *newAclVersion, uint8 compatibility)
 *     Argument newAclVersion: uint8* is of type SecLog_AclVersionType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecLog_EcuIndividualAclReplacementEvent_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_EcuIndividualAclReplacement_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_EcuIndividualAclReplacement(P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) newAclVersion, uint8 compatibility) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_EcuIndividualAclReplacement (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_SecLog_EcuIndividualAclReplacementEvent_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (newAclVersion == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 logEntryData[12];

    /* #10 Fill in log entry data. */
    /* PRQA S 0315 1 */ /* MD_SSA_P2VOID_CAST */
    Ssa_MemCpy(&logEntryData[0], newAclVersion, 11u);
    logEntryData[11] = compatibility;
    /* Write log entry. */
    SecLog_GetTimestampAndWriteLogEntry(SECLOG_EVENT_ECU_INDIVIDUAL_ACL_REPLACEMENT, logEntryData);

#if (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON)         /* COV_SSA_DEBUG XF */
    {
      CANoeAPI_Printf("SecLog Event - ECU-individual ACL replacement (%u): New ACL version=0x%02X%02X%02X%02X, Compatibility=0x02x",
        SECLOG_EVENT_ECU_INDIVIDUAL_ACL_REPLACEMENT, newAclVersion[0], newAclVersion[1], newAclVersion[2], compatibility);
    }
#endif /* (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON) */

    /* #20 Update global counters. */
    /*@ assert (SECLOG_EVENT_ECU_INDIVIDUAL_ACL_REPLACEMENT == 12u) && (SSA_SECLOG_SIZE_GLOBCOUNT_13 == 2u); */
    /*@ assert SSA_SECLOG_NVRAM_CTRL_DATA_SIZE == 8; */
    /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_ECU_INDIVIDUAL_ACL_REPLACEMENT].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE])) >= 2; */ /* VCA_SSA_SECLOG_SIZE_OF_RAM_BLOCK_BUFFERS */
    SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_EcuIndividualAccessControlListReplacement());

    /* #30 Request writing the RAM blocks. */
    Ssa_SecLog_NvMWriteRequested[SECLOG_EVENT_ECU_INDIVIDUAL_ACL_REPLACEMENT] = TRUE;

    /* #40 Notify logging. */
    SecLog_NotifyLogging();
    retVal = RTE_E_OK;
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_LogEvent_FailedCertificateVerification
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <FailedCertificateVerification> of PortPrototype <SecLog_FailedCertVerificationEvent>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SecLog_EventNotification_Data(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data7ByteType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RightsM_DiagnosticChannel_GetDiagChanAndAuthStatus(uint8 *diagChanAndAuthStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RightsM_DiagnosticChannel_E_NOT_OK
 *   Std_ReturnType Rte_Call_TimeM_TickCount_Get(uint64 *tickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_TickCount_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_LogEvent_FailedCertificateVerification(CertP_PkiRoleType pkiRole, CertP_VerificationResultType validationResult)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecLog_FailedCertVerificationEvent_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_FailedCertificateVerification_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_FailedCertificateVerification(CertP_PkiRoleType pkiRole, CertP_VerificationResultType validationResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_FailedCertificateVerification (returns application error)
 *********************************************************************************************************************/

  uint8 logEntryData[3];
  uint8 diagChanAuthStatus = 0xFFu;
  boolean counterWritten = FALSE, bufferSizePositive = FALSE;

  /* #10 Get the current diagnostic channel and the authentication status. */
  /* No need for the return value. */
  /*@ assert &diagChanAuthStatus != NULL_PTR; */
  (void)Rte_Call_RightsM_DiagnosticChannel_GetDiagChanAndAuthStatus(&diagChanAuthStatus);

  /* #20 Fill in log entry data. */
  logEntryData[0] = diagChanAuthStatus;
  logEntryData[1] = pkiRole;
  logEntryData[2] = validationResult;
  /* #30 Write log entry. */
  SecLog_GetTimestampAndWriteLogEntry(SECLOG_EVENT_FAILED_CERTIFICATE_VERIFICATION, logEntryData);

#if (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON)         /* COV_SSA_DEBUG XF */
  {
    CANoeAPI_Printf("SecLog Event - Failed Certificate Verification (%u): PKIRole=%02X, Diag.channel=%u, Auth.status=%u, Valid.result=%02X",
      SECLOG_EVENT_FAILED_CERTIFICATE_VERIFICATION, pkiRole, (uint8)(diagChanAuthStatus & 0x0F), (uint8)((diagChanAuthStatus >> 7) & 0x01u), validationResult);
  }
#endif /* (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON) */

  /* #40 Update global counters differentiating the PKI role. */
  /*@ assert (SECLOG_EVENT_FAILED_CERTIFICATE_VERIFICATION == 0u) && (SSA_SECLOG_SIZE_GLOBCOUNT_1 == 8u); */
  /*@ assert SSA_SECLOG_NVRAM_CTRL_DATA_SIZE == 8; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_FAILED_CERTIFICATE_VERIFICATION].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE])) >= 8; */ /* VCA_SSA_SECLOG_SIZE_OF_RAM_BLOCK_BUFFERS */
  switch (pkiRole)
  {
    /* *** Counter 1 *** */
  case CERTP_PKI_ROLE_ROOT:
    /* Fall through. */
  case CERTP_PKI_ROLE_ROOT_CA_LINK_CERT:
    /* Fall through. */
  case CERTP_PKI_ROLE_BACKEND:
    /* Fall through. */
  case CERTP_PKI_ROLE_BACKEND_CA_LINK_CERT:
    /* Fall through. */
  case CERTP_PKI_ROLE_TRUST_MODEL_ROOT_CA:
    /* Fall through: */
  case CERTP_PKI_ROLE_TRUST_MODEL_BACKEND_CA:
    /* Fall through: */
  case CERTP_PKI_ROLE_TRUST_MODEL_INTERMEDIATE_CA:
    SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_FailedCertificateVerification_Pki());
    counterWritten = TRUE;
    break;
    /* *** Counter 2 *** */
  case CERTP_PKI_ROLE_TESTER:
    /* Fall through. */
  case CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS:
    SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_FailedCertificateVerification_Auth_EnhanceRights());
    counterWritten = TRUE;
    break;
    /* *** Counter 3 *** */
  case CERTP_PKI_ROLE_ECU:
    /* Fall through. */
  case CERTP_PKI_ROLE_TRUST_MODEL_ECU:
    SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_FailedCertificateVerification_Ecu());
    counterWritten = TRUE;
    break;
    /* *** Counter 4 *** */
  case CERTP_PKI_ROLE_VARIANT_CODING:
    /* Fall through. */
  case CERTP_PKI_ROLE_USER_CERT_FOR_CODING:
    SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_FailedCertificateVerification_Coding_Data());
    counterWritten = TRUE;
    break;
  default:
    /* no action */
    break;
  }

  /* #50 Request marking the RAM blocks as changed. */
  bufferSizePositive = (SSA_SECLOG_CIRCULAR_BUFFER_SIZE_FAILED_CERTIFICATE_VERIFICATION_EVENT > 0u);
  if (counterWritten || bufferSizePositive) /* PRQA S 2991 */ /* MD_SSA_CTRLEXPR_ALWAYS_TRUE_OR_ALWAYS_FALSE */ /* COV_SSA_SECLOG_CIRCULAR_BUFFER_LENGTH_CONFIGURATION */
  {
    Ssa_SecLog_NvMSetRamBlockStatus[SECLOG_EVENT_FAILED_CERTIFICATE_VERIFICATION] = TRUE;
  }

  /* #60 Notify logging. */
  SecLog_NotifyLogging();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_LogEvent_FailedSecOcMacVerification
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <VerifyStatus> of PortPrototype <SecOC_VerificationStatusIndication>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_Ssa_FailedMacVerifCounterEvent_Event(const Ssa_FailedMacVerifCounterEventType *data)
 *   Std_ReturnType Rte_Write_SecLog_EventNotification_Data(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data7ByteType
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
 *   Std_ReturnType Rte_Call_DTC_0xD12083_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_LogEvent_FailedSecOcMacVerification(const SecOC_VerificationStatusType *verificationStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_VerificationStatusIndication_E_NOT_OK
 *   RTE_E_VerificationStatusIndication_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_FailedSecOcMacVerification_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_FailedSecOcMacVerification(P2CONST(SecOC_VerificationStatusType, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) verificationStatus) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_FailedSecOcMacVerification (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_VerificationStatusIndication_E_NOT_OK;
  Ssa_ThresholdExceededType logInfoWritten = SSA_THRESHOLD_EXCEEDED_NONE;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (verificationStatus == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #20 Write log event "failed SecOc MAC verification". */
    /* return value is always RTE_E_OK, no mapping needed */
    retVal = SecLog_LogEvent_FailedSecOcMacVerification(verificationStatus, &logInfoWritten);

    if (logInfoWritten != SSA_THRESHOLD_EXCEEDED_NONE)
    {
      /* #30 Request marking the RAM blocks as changed. */
      SecLog_LogEvent_FailedSecOcMacVerification_MarkRamBlocksAsChanged(logInfoWritten);

      /* #40 Notify logging. */
      SecLog_NotifyLogging();
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
 * Runnable Entity Name: Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <verificationStatus> of PortPrototype <BcTp_SecureBroadcastVerificationStatus>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_BcTp_SecureBroadcastVerificationStatus_verificationStatus(SecOC_VerificationStatusType *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_Ssa_FailedMacVerifCounterEvent_Event(const Ssa_FailedMacVerifCounterEventType *data)
 *   Std_ReturnType Rte_Write_SecLog_EventNotification_Data(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data7ByteType
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
 *   Std_ReturnType Rte_Call_DTC_0xD12083_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast_doc
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

FUNC(void, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_FailedSecOcMacVerificationSecureBroadcast
 *********************************************************************************************************************/
  SecOC_VerificationStatusType verifStatus;
  Ssa_ThresholdExceededType logInfoWritten = SSA_THRESHOLD_EXCEEDED_NONE;

  /* #10 Read Secure Broadcast verification status. */
  if (Rte_Read_BcTp_SecureBroadcastVerificationStatus_verificationStatus(&verifStatus) == RTE_E_OK)
  {

    /* #20 Write log event "failed SecOc MAC verification". */
    /* return value is always RTE_E_OK */
    (void)SecLog_LogEvent_FailedSecOcMacVerification(&verifStatus, &logInfoWritten);

    if (logInfoWritten != SSA_THRESHOLD_EXCEEDED_NONE)
    {
      /* #30 Request marking the RAM blocks as changed. */
      SecLog_LogEvent_FailedSecOcMacVerification_MarkRamBlocksAsChanged(logInfoWritten);

      /* #40 Notify logging. */
      SecLog_NotifyLogging();
    }
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_LogEvent_RightsManagement
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RightsManagement> of PortPrototype <SecLog_RightsManagementEvent>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SecLog_EventNotification_Data(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data7ByteType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_TimeM_TickCount_Get(uint64 *tickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_TickCount_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_LogEvent_RightsManagement(uint8 diagChanAuthStatus, uint8 serviceId, uint8 subFunction, uint16 dataIdOrRoutineId)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecLog_RightsManagementEvent_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_RightsManagement_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_RightsManagement(uint8 diagChanAuthStatus, uint8 serviceId, uint8 subFunction, uint16 dataIdOrRoutineId) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_RightsManagement (returns application error)
 *********************************************************************************************************************/

  /* #10 Check that the current diagnostic channel is in authenticated state. */
  if (SecLog_BitOpTest(uint8, diagChanAuthStatus, 0x80u))
  {
    uint8 logEntryData[5];

    /* #20 Fill in log entry data. */
    logEntryData[0] = diagChanAuthStatus;
    logEntryData[1] = serviceId;
    logEntryData[2] = subFunction;
    logEntryData[3] = (uint8)(dataIdOrRoutineId >> 8);
    logEntryData[4] = (uint8)(dataIdOrRoutineId & 0xFFu);

    /* #30 Write log entry. */
    SecLog_GetTimestampAndWriteLogEntry(SECLOG_EVENT_RIGHTS_MANAGEMENT, logEntryData);
  }

#if (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON)         /* COV_SSA_DEBUG XF */
  {
    CANoeAPI_Printf("SecLog Event - Rights Management (%u): Diag.chan.=%u, Auth.status=%u, SID=0x%02X, SF=0x%02X, DID/RID=0x%04X",
      SECLOG_EVENT_RIGHTS_MANAGEMENT, (diagChanAuthStatus & 0x0Fu), ((diagChanAuthStatus >> 7) & 0x01u), serviceId, subFunction, dataIdOrRoutineId);
  }
#endif /* (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON) */

  /* #40 Update global counters. Differentiating the authentication states "authenticated" and "not authenticated". */
  /*@ assert (SECLOG_EVENT_RIGHTS_MANAGEMENT == 5u) && (SSA_SECLOG_SIZE_GLOBCOUNT_6 == 8u); */
  /*@ assert SSA_SECLOG_NVRAM_CTRL_DATA_SIZE == 8; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_RIGHTS_MANAGEMENT].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE])) >= 8; */ /* VCA_SSA_SECLOG_SIZE_OF_RAM_BLOCK_BUFFERS */
  if (SecLog_BitOpTest(uint8, diagChanAuthStatus, 0x80u))
  {
    SecLog_IncrementGlobalEvent4ByteCounter(SecLog_Counter_RightsManagement_AuthenticatedDiagTestTool());
  }
  else
  {
    SecLog_IncrementGlobalEvent4ByteCounter(SecLog_Counter_RightsManagement_UnauthenticatedDiagTestTool());
  }

  /* #50 Request marking the RAM blocks as changed. */
  Ssa_SecLog_NvMSetRamBlockStatus[SECLOG_EVENT_RIGHTS_MANAGEMENT] = TRUE;

  /* #60 Notify logging. */
  SecLog_NotifyLogging();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_LogEvent_SecureBootOrAuthenticatedBoot
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SecureBootOrAuthenticatedBoot> of PortPrototype <SecLog_SecureBootOrAuthenticatedBootEvent>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SecLog_EventNotification_Data(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data7ByteType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_TimeM_TickCount_Get(uint64 *tickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_TickCount_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_LogEvent_SecureBootOrAuthenticatedBoot(void)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecLog_SecureBootOrAuthenticatedBootEvent_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_SecureBootOrAuthenticatedBoot_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_SecureBootOrAuthenticatedBoot(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_SecureBootOrAuthenticatedBoot (returns application error)
 *********************************************************************************************************************/

  /* #10 Write log entry. */
  SecLog_GetTimestampAndWriteLogEntry(SECLOG_EVENT_SECURE_BOOT_OR_AUTHENTICATED_BOOT, NULL_PTR);

#if (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON)         /* COV_SSA_DEBUG XF */
  {
    CANoeAPI_Printf("SecLog Event - Secure boot or authenticated boot(%u)", SECLOG_EVENT_SECURE_BOOT_OR_AUTHENTICATED_BOOT);
  }
#endif /* (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON) */

  /* #20 Update global counter. */
  SecLog_IncrementGlobalEvent1ByteCounter(SecLog_Counter_SecureBootOrAuthenticatedBoot());

  /* #30 Request writing the RAM blocks. */
  Ssa_SecLog_NvMWriteRequested[SECLOG_EVENT_SECURE_BOOT_OR_AUTHENTICATED_BOOT] = TRUE;

  /* #40 Notify logging. */
  SecLog_NotifyLogging();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_LogEvent_SignatureVerification
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SignatureVerification> of PortPrototype <SecLog_SignatureVerificationEvent_VerifySignatureSwReprogramming>
 *   - triggered by server invocation for OperationPrototype <SignatureVerification> of PortPrototype <SecLog_SignatureVerificationEvent_VerifySignatureVariantCoding>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SecLog_EventNotification_Data(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data7ByteType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RightsM_DiagnosticChannel_GetDiagChanAndAuthStatus(uint8 *diagChanAndAuthStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RightsM_DiagnosticChannel_E_NOT_OK
 *   Std_ReturnType Rte_Call_TimeM_TickCount_Get(uint64 *tickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_TickCount_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_LogEvent_SignatureVerification(uint8 verificationResult)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecLog_SignatureVerificationEvent_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_SignatureVerification_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_SignatureVerification(uint8 parg0, uint8 verificationResult) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_SignatureVerification (returns application error)
 *********************************************************************************************************************/

  uint8 logEntryData[3];
  uint8 diagChanAuthStatus = 0xFFu;

  /* #10 Get the current diagnostic channel and the authentication status. */
  /* No need for the return value. */
  (void)Rte_Call_RightsM_DiagnosticChannel_GetDiagChanAndAuthStatus(&diagChanAuthStatus);

  /* #20 Fill in log entry data. */
  logEntryData[0] = diagChanAuthStatus;
  logEntryData[1] = parg0; /* = Use case */
  logEntryData[2] = verificationResult;
  /* #30 Write log entry. */
  SecLog_GetTimestampAndWriteLogEntry(SECLOG_EVENT_SIGNATURE_VERIFICATION, logEntryData);

#if (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON)         /* COV_SSA_DEBUG XF */
  {
    CANoeAPI_Printf("SecLog Event - Successful diag. service execution (%u): Diag.channel=%u, Auth.status=%u, UseCase=%02X, verif. result=%02X",
      SECLOG_EVENT_SIGNATURE_VERIFICATION, (uint8)(diagChanAuthStatus & 0x0F), (uint8)((diagChanAuthStatus >> 7) & 0x01u), parg0, verificationResult);
  }
#endif /* (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON) */

  /* #40 Update global counter only for failed verifications. */
  /*@ assert (SECLOG_EVENT_SIGNATURE_VERIFICATION == 6u) && (SSA_SECLOG_SIZE_GLOBCOUNT_7 == 6u); */
  /*@ assert SSA_SECLOG_NVRAM_CTRL_DATA_SIZE == 8; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SIGNATURE_VERIFICATION].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE])) >= 6; */ /* VCA_SSA_SECLOG_SIZE_OF_RAM_BLOCK_BUFFERS */
  if ((parg0 < SECLOG_NUMBER_OF_SIGNATURE_VERIFICATION_USE_CASES) && (verificationResult > 0u))
  {
    switch (parg0) {
    case 0x00u:
      SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_FailedSignatureVerificationSwReprogramming());
      break;
    case 0x01u:
      SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_FailedSignatureVerificationVariantCoding());
      break;
    default:
      /* must be 0x02 */
      SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_FailedSignatureVerificationOtherData());
      break;
    }
  }

  /* #50 Request marking the RAM blocks as changed. */
  Ssa_SecLog_NvMSetRamBlockStatus[SECLOG_EVENT_SIGNATURE_VERIFICATION] = TRUE;

  /* #60 Notify logging. */
  SecLog_NotifyLogging();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_LogEvent_SuccessfulAuthAndEnhanceRights
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SuccessfulAuthAndEnhanceRights> of PortPrototype <SecLog_SuccessfulAuthAndEnhanceRights>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SecLog_EventNotification_Data(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data7ByteType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_TimeM_TickCount_Get(uint64 *tickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_TickCount_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_LogEvent_SuccessfulAuthAndEnhanceRights(uint8 diagChanAuthStatus, CertP_PkiRoleType pkiRole, const uint8 *authenticationContent)
 *     Argument authenticationContent: uint8* is of type SecLog_AuthenticationContentType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecLog_SuccessfulAuthAndEnhanceRights_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_SuccessfulAuthAndEnhanceRights_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_SuccessfulAuthAndEnhanceRights(uint8 diagChanAuthStatus, CertP_PkiRoleType pkiRole, P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) authenticationContent) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_SuccessfulAuthAndEnhanceRights (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType retVal = RTE_E_SecLog_SuccessfulAuthAndEnhanceRights_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (authenticationContent == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Filter for relevant PKI roles (dummy, tester and enhance access rights). */
    if ((pkiRole == SECLOG_DUMMY_PKI_ROLE) || (pkiRole == CERTP_PKI_ROLE_TESTER) || (pkiRole == CERTP_PKI_ROLE_ENHANCE_ACCESS_RIGHTS))
    {
      uint8 logEntryData[2u + SSA_SIZEOF_SERIALNUMBER + SSA_SIZEOF_BACKEND_SERIALNUMBER];

      /* #20 Fill in log entry data. */
      logEntryData[0] = diagChanAuthStatus;
      logEntryData[1] = pkiRole;
      logEntryData[SSA_SIZEOF_SERIALNUMBER + SSA_SIZEOF_BACKEND_SERIALNUMBER] = 0xFFu;
      logEntryData[SSA_SIZEOF_SERIALNUMBER + SSA_SIZEOF_BACKEND_SERIALNUMBER + 1u] = 0xFFu;

      if (pkiRole == SECLOG_DUMMY_PKI_ROLE)
      {
        /* PRQA S 0315 1 */ /* MD_SSA_P2VOID_CAST */
        Ssa_MemCpy(&logEntryData[2], authenticationContent, SSA_SIZEOF_SERIALNUMBER + SSA_SIZEOF_BACKEND_SERIALNUMBER);
      }
      else
      {
        /* PRQA S 0315 1 */ /* MD_SSA_P2VOID_CAST */
        Ssa_MemCpy(&logEntryData[2], authenticationContent, SSA_SIZEOF_SERIALNUMBER);
      }

      /* #30 Write log entry. */
      SecLog_GetTimestampAndWriteLogEntry(SECLOG_EVENT_SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS, logEntryData);

#if (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON)         /* COV_SSA_DEBUG XF */
      {
        CANoeAPI_Printf("SecLog Event - Successful Authentication/Enhance Rights (UID=%u): Diag.chan.=%u, Auth.status=%u, PKI Role=0x%02X, Content=0x%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
          SECLOG_EVENT_SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS, (diagChanAuthStatus & 0x0Fu), ((diagChanAuthStatus >> 7) & 0x01u), pkiRole,
          authenticationContent[0], authenticationContent[1], authenticationContent[2], authenticationContent[3], authenticationContent[4],
          authenticationContent[5], authenticationContent[6], authenticationContent[7], authenticationContent[8], authenticationContent[9],
          authenticationContent[10], authenticationContent[11], authenticationContent[12], authenticationContent[13], authenticationContent[14],
          authenticationContent[15], authenticationContent[16], authenticationContent[17], authenticationContent[18], authenticationContent[19]);
      }
#endif /* (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON) */

      /* #40 Update global counters differentiating between different PKI roles and different diagnostic users. */
      /*@ assert (SECLOG_EVENT_SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS == 2u) && (SSA_SECLOG_SIZE_GLOBCOUNT_3 == 8u); */
      /*@ assert SSA_SECLOG_NVRAM_CTRL_DATA_SIZE == 8; */
      /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE])) >= 8; */ /* VCA_SSA_SECLOG_SIZE_OF_RAM_BLOCK_BUFFERS */
      switch ((uint8)(diagChanAuthStatus & 0x0Fu))
      {
        /* Internal Diagnostic Test Tool channel (0x0D). */
      case (uint8)0x0Du:
        /* Check for local or central authentication. */
        if ((pkiRole == CERTP_PKI_ROLE_TESTER) || (pkiRole == SECLOG_DUMMY_PKI_ROLE))
        {
          /* *** Counter 2 *** */
          SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_SuccessfulAuthentication_InternalDiagTestTool());
        }
        /* Else: enhance access rights. */
        else
        {
          /* *** Counter 4 *** */
          SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_RightsEnhancements_InternalDiagTestTool());
        }
        break;

        /* Else: External Diagnostic Test Tool channels. */
      default:
        /* Check for local or central authentication. */
        if ((pkiRole == CERTP_PKI_ROLE_TESTER) || (pkiRole == SECLOG_DUMMY_PKI_ROLE))
        {
          /* *** Counter 1 *** */
          SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_SuccessfulAuthentication_ExternalDiagTestTool());
        }
        /* Else: enhance access rights. */
        else
        {
          /* *** Counter 3 *** */
          SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_RightsEnhancements_ExternalDiagTestTool());
        }
        break;
      }

      /* #50 Request marking the RAM blocks as changed. */
      Ssa_SecLog_NvMSetRamBlockStatus[SECLOG_EVENT_SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS] = TRUE;

      /* #60 Notify logging. */
      SecLog_NotifyLogging();
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
 * Runnable Entity Name: Ssa_SecLog_LogEvent_SuccessfulCertificateVerification
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SuccessfulCertificateVerification> of PortPrototype <SecLog_SuccessfulCertVerificationEvent>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SecLog_EventNotification_Data(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data7ByteType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RightsM_DiagnosticChannel_GetDiagChanAndAuthStatus(uint8 *diagChanAndAuthStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RightsM_DiagnosticChannel_E_NOT_OK
 *   Std_ReturnType Rte_Call_TimeM_TickCount_Get(uint64 *tickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_TickCount_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_LogEvent_SuccessfulCertificateVerification(const uint8 *certId, CertP_PkiRoleType pkiRole)
 *     Argument certId: uint8* is of type RightsM_SerialNumberType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecLog_SuccessfulCertVerificationEvent_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_SuccessfulCertificateVerification_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_SuccessfulCertificateVerification(P2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) certId, CertP_PkiRoleType pkiRole) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_SuccessfulCertificateVerification (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType retVal = RTE_E_SecLog_SuccessfulCertVerificationEvent_E_NOT_OK;
  uint8 logEntryData[2u + SSA_SIZEOF_SERIALNUMBER];
  uint8 diagChanAuthStatus = 0xFFu;
  boolean counterWritten = FALSE, bufferSizePositive = FALSE;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (certId == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Get the current diagnostic channel and the authentication status. */
    /* No need for the return value. */
    (void)Rte_Call_RightsM_DiagnosticChannel_GetDiagChanAndAuthStatus(&diagChanAuthStatus);

    /* #20 Fill in log entry data. */
    logEntryData[0] = diagChanAuthStatus;
    logEntryData[1] = pkiRole;

    /* PRQA S 0315 1 */ /* MD_SSA_P2VOID_CAST */
    Ssa_MemCpy(&logEntryData[2], certId, SSA_SIZEOF_SERIALNUMBER);

    /* #30 Write log entry. */
    SecLog_GetTimestampAndWriteLogEntry(SECLOG_EVENT_SUCCESSFUL_CERTIFICATE_VERIFICATION, logEntryData);

#if (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON)         /* COV_SSA_DEBUG XF */
    {
      CANoeAPI_Printf("SecLog Event - Successful Certificate Verification (UID=%u): PKIRole=%02X, Diag.channel=%u, Auth.status=%u, SubjectKeyID=%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
        SECLOG_EVENT_SUCCESSFUL_CERTIFICATE_VERIFICATION, (uint8)(diagChanAuthStatus & 0x0F), (uint8)((diagChanAuthStatus >> 7) & 0x01u), pkiRole,
        certId[0], certId[1], certId[2], certId[3], certId[4],
        certId[5], certId[6], certId[7], certId[8], certId[9],
        certId[10], certId[11], certId[12], certId[13], certId[14],
        certId[15], certId[16], certId[17], certId[18], certId[19]);
    }
#endif /* (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON) */

    /* #40 Update global counters differentiating between different PKI roles. */
    /*@ assert (SECLOG_EVENT_SUCCESSFUL_CERTIFICATE_VERIFICATION == 1u) && (SSA_SECLOG_SIZE_GLOBCOUNT_2 == 6u); */
    /*@ assert SSA_SECLOG_NVRAM_CTRL_DATA_SIZE == 8; */
    /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SUCCESSFUL_CERTIFICATE_VERIFICATION].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE])) >= 6; */ /* VCA_SSA_SECLOG_SIZE_OF_RAM_BLOCK_BUFFERS */
    switch (pkiRole)
    {
      /* *** Counter 1 *** */
    case CERTP_PKI_ROLE_ROOT:
      /* Fall through. */
    case CERTP_PKI_ROLE_ROOT_CA_LINK_CERT:
      /* Fall through. */
    case CERTP_PKI_ROLE_BACKEND:
      /* Fall through. */
    case CERTP_PKI_ROLE_BACKEND_CA_LINK_CERT:
      /* Fall through. */
    case CERTP_PKI_ROLE_TRUST_MODEL_ROOT_CA:
      /* Fall through. */
    case CERTP_PKI_ROLE_TRUST_MODEL_BACKEND_CA:
      /* Fall through. */
    case CERTP_PKI_ROLE_TRUST_MODEL_INTERMEDIATE_CA:
      SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_SuccessfulCertificateVerification_Pki());
      counterWritten = TRUE;
      break;
      /* *** Counter 2 *** */
    case CERTP_PKI_ROLE_ECU:
      /* Fall through. */
    case CERTP_PKI_ROLE_TRUST_MODEL_ECU:
      SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_SuccessfulCertificateVerification_Ecu());
      counterWritten = TRUE;
      break;
      /* *** Counter 3 *** */
    case CERTP_PKI_ROLE_VARIANT_CODING:
      /* Fall through. */
    case CERTP_PKI_ROLE_USER_CERT_FOR_CODING:
      SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_SuccessfulCertificateVerification_Coding_Data());
      counterWritten = TRUE;
      break;
    default:
      /* no action */
      break;
    }

    /* #50 Request marking the RAM blocks as changed. */
    bufferSizePositive = (SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_CERTIFICATE_VERIFICATION_EVENT > 0u);
    if (counterWritten || bufferSizePositive) /* PRQA S 2991 */ /* MD_SSA_CTRLEXPR_ALWAYS_TRUE_OR_ALWAYS_FALSE */ /* COV_SSA_SECLOG_CIRCULAR_BUFFER_LENGTH_CONFIGURATION */
    {
      Ssa_SecLog_NvMSetRamBlockStatus[SECLOG_EVENT_SUCCESSFUL_CERTIFICATE_VERIFICATION] = TRUE;
    }

    /* #60 Notify logging. */
    SecLog_NotifyLogging();
    retVal = RTE_E_OK;
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_ActivateDebugIf>
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_ClearSarMemory>
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_EcuSharedSecretDistribution>
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_EcuSharedSecretEncryption>
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_EnableSarMemOverwrite>
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_EraseMemory>
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_InjectSeed>
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_ReplaceCert>
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_ReplaceTrustModeRootCert>
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_ReplaceTrustModelCert>
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_TrustModeEcuSharedSecretDistribution>
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_TrustModelEcuSharedSecretEncryption>
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_TrustModelEcuTickcountSynchronization>
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_TrustModelGenerateKeyPair>
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_VehicleSharedSecretDistribution>
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_VsmDeriveSymmetricKeys>
 *   - triggered by server invocation for OperationPrototype <SuccessfulDiagServiceExecution> of PortPrototype <SecLog_SuccessfulDiagServiceExecutionEvent_VsmRenewSharedSecret>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SecLog_EventNotification_Data(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data7ByteType
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RightsM_DiagnosticChannel_GetDiagChanAndAuthStatus(uint8 *diagChanAndAuthStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RightsM_DiagnosticChannel_E_NOT_OK
 *   Std_ReturnType Rte_Call_TimeM_TickCount_Get(uint64 *tickCount)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_TimeM_TickCount_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution(uint8 additionalInfo)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SecLog_SuccessfulDiagServiceExecutionEvent_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution_doc
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

FUNC(Std_ReturnType, Ssa_SecLog_CODE) Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution(uint8 parg0, uint8 additionalInfo) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_LogEvent_SuccessfulDiagServiceExecution (returns application error)
 *********************************************************************************************************************/

  uint8 logEntryData[3];
  uint8 diagChanAuthStatus = 0xFFu;
  boolean counterWritten = FALSE, bufferSizePositive = FALSE;

  /* #10 Get the current diagnostic channel and the authentication status. */
  /* No need for the return value. */
  (void)Rte_Call_RightsM_DiagnosticChannel_GetDiagChanAndAuthStatus(&diagChanAuthStatus);

  /* #20 Fill in log entry data. */
  logEntryData[0] = diagChanAuthStatus;
  logEntryData[1] = parg0; /* = UID */
  logEntryData[2] = additionalInfo;
  /* #30 Write log entry. */
  SecLog_GetTimestampAndWriteLogEntry(SECLOG_EVENT_SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION, logEntryData);

#if (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON)         /* COV_SSA_DEBUG XF */
  {
    CANoeAPI_Printf("SecLog Event - Successful diag. service execution (%u): Diag.channel=%u, Auth.status=%u, UID=%02X, add.info=%02X",
      SECLOG_EVENT_SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION, (uint8)(diagChanAuthStatus & 0x0F), (uint8)((diagChanAuthStatus >> 7) & 0x01u), parg0, additionalInfo);
  }
#endif /* (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON) */

  bufferSizePositive = (SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION_EVENT > 0u);

  /* #40 Update global counter if there is one for the passed UID. */
  if (parg0 < SECLOG_NUMBER_OF_DIAGNOSTIC_SERVICE_UID_COUNTERS)
  {
    SecLog_IncrementGlobalEvent1ByteCounter(SecLog_Counter_SuccessfulDiagServiceExecution(parg0));
    counterWritten = TRUE;
  }

  /* #50 If the use case is 
   *     "Replace Certificates",
   *     "Replace Trust Model Certificates" or
   *     "Replace Trust Model Root Certificate"
   *     request writing the RAM blocks, else request marking the RAM blocks as changed. */
  if (parg0 == SSA_SECLOG_SUCDIAGEXECEVENT_UID_REPLACE_CERTIFICATES)
  {
    /* Request writing the RAM blocks.
     * Even if the circular buffer size is 0, the counter is incremented (i.e., written) for this event. */
    Ssa_SecLog_NvMWriteRequested[SECLOG_EVENT_SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION] = TRUE;
  }
  else if ((parg0 == SSA_SECLOG_SUCDIAGEXECEVENT_UID_REPLACE_TRUST_MODEL_CERTIFICATES)
        || (parg0 == SSA_SECLOG_SUCDIAGEXECEVENT_UID_REPLACE_TRUST_MODEL_ROOT_CERTIFICATE))
  {
    /* Request writing the RAM blocks.
     * For these use cases, the counter is not incremented. Writing the RAM blocks is only requested,
     * if event data was logged. */
    if (bufferSizePositive) /* PRQA S 2991, 2992 */ /* MD_SSA_CTRLEXPR_ALWAYS_TRUE_OR_ALWAYS_FALSE */ /* COV_SSA_SECLOG_CIRCULAR_BUFFER_LENGTH_CONFIGURATION */
    {
      Ssa_SecLog_NvMWriteRequested[SECLOG_EVENT_SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION] = TRUE; /* PRQA S 2880 */ /* MD_SSA_UNREACHABLE_CODE */
    }
  }
  else
  {
    /* Request marking the RAM blocks as changed. */
    if (counterWritten || bufferSizePositive)  /* PRQA S 2991 */ /* MD_SSA_CTRLEXPR_ALWAYS_TRUE_OR_ALWAYS_FALSE */ /* COV_SSA_SECLOG_CIRCULAR_BUFFER_LENGTH_CONFIGURATION */
    {
      Ssa_SecLog_NvMSetRamBlockStatus[SECLOG_EVENT_SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION] = TRUE;
    }
  }

  /* #60 Notify logging. */
  SecLog_NotifyLogging();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_SecLog_MainFunction
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
 *   Std_ReturnType Rte_Read_ReceiveLocalTickCountAndSyncStatus_Data(Ssa_LocalTickCountAndSyncStatusType *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SecLog_EventNotification_Data(const uint8 *data)
 *     Argument data: uint8* is of type Ssa_Data7ByteType
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt10_FailedPduMacVerif_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt11_SecOrAuthBoot_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt12_ChangeOfVin_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt13_AclReplacement_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt13_AclReplacement_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt13_AclReplacement_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt1_FailedCertVerif_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt2_SucCertVerif_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt2_SucCertVerif_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt2_SucCertVerif_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt3_SucAuthAndEnhanceRights_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt4_AuthBySecAccess_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt5_SucDiagServiceExec_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt6_RightsMgmt_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt6_RightsMgmt_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt6_RightsMgmt_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt7_SigVerif_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt7_SigVerif_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt7_SigVerif_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt8_TickCountDateAndTime_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogDataEvnt9_SecOcMisconfig_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh1_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh2_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvMService_SecLog_LogFailedMacVerifCount_ExceededTh3_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_SecLog_ExclusiveArea(void)
 *   void Rte_Exit_SecLog_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_MainFunction_doc
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

FUNC(void, Ssa_SecLog_CODE) Ssa_SecLog_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_SecLog_MainFunction
 *********************************************************************************************************************/
  Ssa_LocalTickCountAndSyncStatusType localTickCountAndSyncStatus;

  /* #10 Get the local tick-count and its synchronization status from FvM. */
  (void)Rte_Read_ReceiveLocalTickCountAndSyncStatus_Data(&localTickCountAndSyncStatus);
  Ssa_SecLog_LocalTickCountSyncStatus = localTickCountAndSyncStatus.SyncStatus;

  /* #20 Handle de-bouncing. */
  SecLog_HandleDebouncing();

  /* #30 Handle NVM requests. */
  SecLog_HandleNvm();

  /* #40 Handle the SecLog timers. */
  SecLog_HandleTimers();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Ssa_SecLog_STOP_SEC_CODE
#include "Ssa_SecLog_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define Ssa_SecLog_START_SEC_CODE
#include "Ssa_SecLog_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * SecLog_PutUint16()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_PutUint16(                     /* PRQA S 3219 */ /* MD_MSR_Unreachable */
  CONSTP2VAR(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) BufferPtr,
  uint32 Offset, uint16 Value)
{
  BufferPtr[Offset] = (uint8)(Value >> 8u);
  BufferPtr[Offset + 1u] = (uint8)(Value);
} /* SecLog_PutUint16() */

/**********************************************************************************************************************
 * SecLog_GetUint16()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_SECLOG_LOCAL_INLINE FUNC(uint16, Ssa_SecLog_CODE) SecLog_GetUint16(                     /* PRQA S 3219 */ /* MD_MSR_Unreachable */
  CONSTP2CONST(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) BufferPtr,
  uint32 Offset)
{
  return (uint16)(((uint16)(BufferPtr[Offset]) << 8u) | BufferPtr[Offset + 1u]);
} /* SecLog_GetUint16() */

/**********************************************************************************************************************
 * SecLog_IncrementGlobalEvent1ByteCounter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_IncrementGlobalEvent1ByteCounter(P2VAR(uint8, AUTOMATIC, AUTOMATIC) counterAddr)
{
  /* #10 Check if maximum value has already reached (to prevent roll-over). */
  if (counterAddr[0] != (uint8)0xFFu)
  {
    /* #20 Increment counter value. */
    counterAddr[0] = (uint8)(counterAddr[0] + (uint8)1u);
  }
}

/**********************************************************************************************************************
 * SecLog_IncrementGlobalEvent2ByteCounter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_IncrementGlobalEvent2ByteCounter(P2VAR(uint8, AUTOMATIC, AUTOMATIC) counterAddr)
{
  uint16 counterValue;

  Rte_Enter_SecLog_ExclusiveArea();

  /* #10 Build a temporary counter value from the input bytes (considering the high byte first principle). */
  counterValue = (uint16)((((uint16)counterAddr[0]) << 8) | ((uint16)counterAddr[1]));

  /* #20 Check if maximum value has already reached (to prevent roll-over). */
  if (counterValue != 0xFFFFu)
  {
    /* #30 Increment counter value. */
    counterValue += 1u;
    /* #40 Derive the output bytes from the counter value. */
    counterAddr[0] = (uint8)(counterValue >> 8);
    counterAddr[1] = (uint8)(counterValue & 0xFFu);
  }

  Rte_Exit_SecLog_ExclusiveArea();
}

/**********************************************************************************************************************
 * SecLog_IncrementGlobalEvent4ByteCounter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_IncrementGlobalEvent4ByteCounter(P2VAR(uint8, AUTOMATIC, AUTOMATIC) counterAddr)
{
  uint32 counterValue;

  Rte_Enter_SecLog_ExclusiveArea();

  /* #10 Build a temporary counter value from the input bytes (considering the high byte first principle). */
  counterValue = (((uint32)counterAddr[0]) << 24) | (((uint32)counterAddr[1]) << 16) | (((uint32)counterAddr[2]) << 8) | ((uint32)counterAddr[3]);

  /* #20 Check if maximum value has already reached (to prevent roll-over). */
  if (counterValue != 0xFFFFFFFFuL)
  {
    /* #30 Increment counter value. */
    counterValue += 1uL;
    /* #40 Derive the output bytes from the counter value. */
    counterAddr[0] = (uint8)(counterValue >> 24);
    counterAddr[1] = (uint8)((counterValue >> 16) & 0xFFu);
    counterAddr[2] = (uint8)((counterValue >> 8) & 0xFFu);
    counterAddr[3] = (uint8)(counterValue & 0xFFu);
  }

  Rte_Exit_SecLog_ExclusiveArea();
}

/**********************************************************************************************************************
 * SecLog_GetDataIdIndex()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_SECLOG_LOCAL FUNC(boolean, Ssa_SecLog_CODE) SecLog_GetDataIdIndex(uint16 id, P2VAR(uint16, AUTOMATIC, AUTOMATIC) idx)
{
  boolean found = FALSE;
  uint16 i;
  *idx = 0u;

  /* #10 Iterate over all DataIds. */
  for (i = 0u; i < Ssa_GetSizeOfSecLogInfo(); i++)
  {
    /* #20 Once the DataId is found return TRUE and the table index.*/
    if (Ssa_GetDataIdOfDataIdInfo(Ssa_GetDataIdInfoIdxOfSecLogInfo(i)) == id)
    {
      *idx = i;
      found = TRUE;
      break;
    }
  }

  /*@ assert *idx < Ssa_GetSizeOfSecLogInfo(); */
  /* #30 Return FALSE if the DataId is not contained by the table. */
  return found;
}

/**********************************************************************************************************************
 * SecLog_GetTimestampAndWriteLogEntry()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_GetTimestampAndWriteLogEntry(uint8 eventId, P2CONST(uint8, AUTOMATIC, AUTOMATIC) logEntryData)
{
  uint64 tickCount = 0u;

  /* #10 Get tick-count from TimeM. */
  (void)Rte_Call_TimeM_TickCount_Get(&tickCount);

  /* #20 Write log entry with this tick-count as time-stamp. */
  SecLog_WriteLogEntry(eventId, logEntryData, &tickCount);

  /* #30 If the "secure boot or authenticated boot" event has been logged notify a "critical security event". */
  if (eventId == SECLOG_EVENT_SECURE_BOOT_OR_AUTHENTICATED_BOOT)
  {
    uint8 CriticalSecurityEvent[7];
    /* Notify critical security event. */
    CriticalSecurityEvent[0] = 0x03u;
    CriticalSecurityEvent[1] = SECLOG_EVENT_SECURE_BOOT_OR_AUTHENTICATED_BOOT + 1u; /* transform to event type identifier */
    CriticalSecurityEvent[2] = (uint8)((tickCount >> 32u) & 0xFFu);
    CriticalSecurityEvent[3] = (uint8)((tickCount >> 24u) & 0xFFu);
    CriticalSecurityEvent[4] = (uint8)((tickCount >> 16u) & 0xFFu);
    CriticalSecurityEvent[5] = (uint8)((tickCount >> 8u) & 0xFFu);
    CriticalSecurityEvent[6] = (uint8)(tickCount & 0xFFu);
    (void)Rte_Write_SecLog_EventNotification_Data(CriticalSecurityEvent);
  }
}

/**********************************************************************************************************************
 * SecLog_WriteDummyLogEntries()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_WriteDummyLogEntries( void )
{
  uint8 idx;
  const uint64 tickCount = 0u;
  /* #10 Iterate over all events. */
  for (idx = 0u; idx < SSA_SECLOG_NUMBER_OF_EVENTS; idx++)
  {
    /* #20 Check that the event is not the "change tick-count or date and time" event. Omit buffers of size 0.  */
    if ((idx != (SECLOG_EVENT_CHANGE_TICK_COUNT_OR_DATE_AND_TIME)) && (Ssa_SecLog_NvmCtrl[idx].bufferSize > 0u))
    {
      uint16 lastWriteIdx;

      Rte_Enter_SecLog_ExclusiveArea();
      /* #30 Find the write index and write a dummy log entry only if the circular buffer is not still empty and if
       *     the last entry is not already a dummy log entry. */
      lastWriteIdx = (uint16)((Ssa_SecLog_NvmCtrl_GetWriteIdx(idx) + (Ssa_SecLog_NvmCtrl[idx].bufferSize - Ssa_SecLog_NvmCtrl[idx].entrySize)) % Ssa_SecLog_NvmCtrl[idx].bufferSize);

      if (Ssa_SecLog_NvmCtrl_GetLengthContent(idx) == 0u)
      {
        Rte_Exit_SecLog_ExclusiveArea();
        /* Circular buffer still empty. Do not write dummy log entry. */
      }
      else if ((SecLog_EventBuffer(idx)[lastWriteIdx] == 0x00u)
        && (SecLog_EventBuffer(idx)[lastWriteIdx + 1u] == 0x00u)
        && (SecLog_EventBuffer(idx)[lastWriteIdx + 2u] == 0x00u)
        && (SecLog_EventBuffer(idx)[lastWriteIdx + 3u] == 0x00u)
        && (SecLog_EventBuffer(idx)[lastWriteIdx + 4u] == 0x00u))
      {
        Rte_Exit_SecLog_ExclusiveArea();
        /* Last entry is a dummy log entry. Do not write dummy log entry. */
      }
      else
      {
        Rte_Exit_SecLog_ExclusiveArea();
        SecLog_WriteLogEntry(idx, NULL_PTR, &tickCount);
      }
    }
  }
}

/**********************************************************************************************************************
 * SecLog_WriteLogEntry()
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
 *
 *
 *
 *
 *
 *
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_WriteLogEntry(uint8 eventIdx, P2CONST(uint8, AUTOMATIC, AUTOMATIC) logEntryData, P2CONST(uint64, AUTOMATIC, AUTOMATIC) tickCount)
{
  /* Assert that the size of the events are known at pre-compile time. */
  /*@ assert Ssa_SecLog_NvmCtrl[0].entrySize == SSA_SECLOG_SIZE_EVNT_1; */
  /*@ assert Ssa_SecLog_NvmCtrl[1].entrySize == SSA_SECLOG_SIZE_EVNT_2; */
  /*@ assert Ssa_SecLog_NvmCtrl[2].entrySize == SSA_SECLOG_SIZE_EVNT_3; */
  /*@ assert Ssa_SecLog_NvmCtrl[3].entrySize == SSA_SECLOG_SIZE_EVNT_4; */
  /*@ assert Ssa_SecLog_NvmCtrl[4].entrySize == SSA_SECLOG_SIZE_EVNT_5; */
  /*@ assert Ssa_SecLog_NvmCtrl[5].entrySize == SSA_SECLOG_SIZE_EVNT_6; */
  /*@ assert Ssa_SecLog_NvmCtrl[6].entrySize == SSA_SECLOG_SIZE_EVNT_7; */
  /*@ assert Ssa_SecLog_NvmCtrl[7].entrySize == SSA_SECLOG_SIZE_EVNT_8; */
  /*@ assert Ssa_SecLog_NvmCtrl[8].entrySize == SSA_SECLOG_SIZE_EVNT_9; */
  /*@ assert Ssa_SecLog_NvmCtrl[9].entrySize == SSA_SECLOG_SIZE_EVNT_10; */
  /*@ assert Ssa_SecLog_NvmCtrl[10].entrySize == SSA_SECLOG_SIZE_EVNT_11; */
  /*@ assert Ssa_SecLog_NvmCtrl[11].entrySize == SSA_SECLOG_SIZE_EVNT_12; */
  /*@ assert Ssa_SecLog_NvmCtrl[12].entrySize == SSA_SECLOG_SIZE_EVNT_13; */
  /* The next three entries of Ssa_SecLog_NvmCtrl contain threshold information, no log entry will be written here. */
  /*@ assert Ssa_SecLog_NvmCtrl[13].entrySize == 0; */
  /*@ assert Ssa_SecLog_NvmCtrl[14].entrySize == 0; */
  /*@ assert Ssa_SecLog_NvmCtrl[15].entrySize == 0; */

#if (SSA_SECLOG_USE_PIM_ACCESS_MACROS_AS_COMPILE_TIME_CONSTANTS == STD_OFF)
  /* Remind the VCA of the buffers which are used as RAM blocks, if necessary: */
  /*@ assert Ssa_SecLog_NvmAddress[0].ramBlock == Rte_Pim_LogDataEvnt1_FailedCertVerif(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[1].ramBlock == Rte_Pim_LogDataEvnt2_SucCertVerif(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[2].ramBlock == Rte_Pim_LogDataEvnt3_SucAuthAndEnhanceRights(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[3].ramBlock == Rte_Pim_LogDataEvnt4_AuthBySecAccess(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[4].ramBlock == Rte_Pim_LogDataEvnt5_SucDiagServiceExec(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[5].ramBlock == Rte_Pim_LogDataEvnt6_RightsMgmt(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[6].ramBlock == Rte_Pim_LogDataEvnt7_SigVerif(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[7].ramBlock == Rte_Pim_LogDataEvnt8_TickCountDateAndTime(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[8].ramBlock == Rte_Pim_LogDataEvnt9_SecOcMisconfig(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[9].ramBlock == Rte_Pim_LogDataEvnt10_FailedPduMacVerif(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[10].ramBlock == Rte_Pim_LogDataEvnt11_SecOrAuthBoot(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[11].ramBlock == Rte_Pim_LogDataEvnt12_ChangeOfVin(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[12].ramBlock == Rte_Pim_LogDataEvnt13_AclReplacement(); */ /* VCA_SSA_SECLOG_INIT */
#endif

  /* assert that the circular buffer length for an event is a multiple of the event's length.
   * Hint: SecLog_EventBuffer(evId) = (&(Ssa_SecLog_NvmAddress[evId].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + Ssa_SecLog_NvmCtrl[evId].globCntSize])) */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[0].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + SSA_SECLOG_SIZE_GLOBCOUNT_1])) >= SSA_SECLOG_SIZE_EVNT_1 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_FAILED_CERTIFICATE_VERIFICATION_EVENT; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[1].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + SSA_SECLOG_SIZE_GLOBCOUNT_2])) >= SSA_SECLOG_SIZE_EVNT_2 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_CERTIFICATE_VERIFICATION_EVENT; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[2].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + SSA_SECLOG_SIZE_GLOBCOUNT_3])) >= SSA_SECLOG_SIZE_EVNT_3 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS_EVENT; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[3].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + SSA_SECLOG_SIZE_GLOBCOUNT_4])) >= SSA_SECLOG_SIZE_EVNT_4 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_AUTHORIZATION_BY_SECURITY_ACCESS_EVENT; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[4].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + SSA_SECLOG_SIZE_GLOBCOUNT_5])) >= SSA_SECLOG_SIZE_EVNT_5 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION_EVENT; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[5].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + SSA_SECLOG_SIZE_GLOBCOUNT_6])) >= SSA_SECLOG_SIZE_EVNT_6 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_RIGHTSM_ANAGEMENT_EVENT; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[6].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + SSA_SECLOG_SIZE_GLOBCOUNT_7])) >= SSA_SECLOG_SIZE_EVNT_7 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SIGNATURE_VERIFICATION_EVENT; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[7].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + SSA_SECLOG_SIZE_GLOBCOUNT_8])) >= SSA_SECLOG_SIZE_EVNT_8 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_CHANGE_OF_TICK_COUNT_OR_DATE_AND_TIME_EVENT; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[8].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + SSA_SECLOG_SIZE_GLOBCOUNT_9])) >= SSA_SECLOG_SIZE_EVNT_9 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SECOC_MISCONFIGURATION_EVENT; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[9].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + SSA_SECLOG_SIZE_GLOBCOUNT_10])) >= SSA_SECLOG_SIZE_EVNT_10 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_FAILED_PDU_MAC_VERIFICATION_EVENT; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[10].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + SSA_SECLOG_SIZE_GLOBCOUNT_11])) >= SSA_SECLOG_SIZE_EVNT_11 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SECURE_BOOT_OR_AUTHENTICATED_BOOT_EVENT; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[11].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + SSA_SECLOG_SIZE_GLOBCOUNT_12])) >= SSA_SECLOG_SIZE_EVNT_12 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_CHANGE_OF_VIN_EVENT; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[12].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + SSA_SECLOG_SIZE_GLOBCOUNT_13])) >= SSA_SECLOG_SIZE_EVNT_13 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_ECU_INDIVIDUAL_ACL_REPLACEMENT_EVENT; */

  /* Review hint: The right hand side of the assertions above can be accessed as Ssa_SecLog_NvmCtrl[eventIdx].bufferSize. */
  /*@ assert Ssa_SecLog_NvmCtrl[0].bufferSize == SSA_SECLOG_SIZE_EVNT_1 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_FAILED_CERTIFICATE_VERIFICATION_EVENT; */
  /*@ assert Ssa_SecLog_NvmCtrl[1].bufferSize == SSA_SECLOG_SIZE_EVNT_2 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_CERTIFICATE_VERIFICATION_EVENT; */
  /*@ assert Ssa_SecLog_NvmCtrl[2].bufferSize == SSA_SECLOG_SIZE_EVNT_3 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS_EVENT; */
  /*@ assert Ssa_SecLog_NvmCtrl[3].bufferSize == SSA_SECLOG_SIZE_EVNT_4 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_AUTHORIZATION_BY_SECURITY_ACCESS_EVENT; */
  /*@ assert Ssa_SecLog_NvmCtrl[4].bufferSize == SSA_SECLOG_SIZE_EVNT_5 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION_EVENT; */
  /*@ assert Ssa_SecLog_NvmCtrl[5].bufferSize == SSA_SECLOG_SIZE_EVNT_6 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_RIGHTSM_ANAGEMENT_EVENT; */
  /*@ assert Ssa_SecLog_NvmCtrl[6].bufferSize == SSA_SECLOG_SIZE_EVNT_7 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SIGNATURE_VERIFICATION_EVENT; */
  /*@ assert Ssa_SecLog_NvmCtrl[7].bufferSize == SSA_SECLOG_SIZE_EVNT_8 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_CHANGE_OF_TICK_COUNT_OR_DATE_AND_TIME_EVENT; */
  /*@ assert Ssa_SecLog_NvmCtrl[8].bufferSize == SSA_SECLOG_SIZE_EVNT_9 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SECOC_MISCONFIGURATION_EVENT; */
  /*@ assert Ssa_SecLog_NvmCtrl[9].bufferSize == SSA_SECLOG_SIZE_EVNT_10 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_FAILED_PDU_MAC_VERIFICATION_EVENT; */
  /*@ assert Ssa_SecLog_NvmCtrl[10].bufferSize == SSA_SECLOG_SIZE_EVNT_11 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SECURE_BOOT_OR_AUTHENTICATED_BOOT_EVENT; */
  /*@ assert Ssa_SecLog_NvmCtrl[11].bufferSize == SSA_SECLOG_SIZE_EVNT_12 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_CHANGE_OF_VIN_EVENT; */
  /*@ assert Ssa_SecLog_NvmCtrl[12].bufferSize == SSA_SECLOG_SIZE_EVNT_13 * SSA_SECLOG_CIRCULAR_BUFFER_SIZE_ECU_INDIVIDUAL_ACL_REPLACEMENT_EVENT; */

  /* #5 Do not write any log entry if there is no circular buffer at all. */

  /* Assert that (as claimed above), no log entries will be written for eventIdx = 13, 14, 15. */
  /*@ assert Ssa_SecLog_NvmCtrl[13].bufferSize == 0; */
  /*@ assert Ssa_SecLog_NvmCtrl[14].bufferSize == 0; */
  /*@ assert Ssa_SecLog_NvmCtrl[15].bufferSize == 0; */
  if (Ssa_SecLog_NvmCtrl[eventIdx].bufferSize > 0u)
  {
    uint16 bufferSize;
    uint16 entrySize;
    uint16 bufferWarningLevel;
    uint16 writeIdx;
    uint16 lengthContent;
    uint16 thresholdWarning;

    Rte_Enter_SecLog_ExclusiveArea();

    /*@ assert SSA_SECLOG_NUMBER_OF_EVENTS == 13 && eventIdx < SSA_SECLOG_NUMBER_OF_EVENTS; */

    /* The size of the circular buffer within the RAM block - configurable: */
    bufferSize = Ssa_SecLog_NvmCtrl[eventIdx].bufferSize;
    /* The size of one entry within the circular buffer - fixed: */
    entrySize = Ssa_SecLog_NvmCtrl[eventIdx].entrySize;
    bufferWarningLevel = Ssa_SecLog_NvmCtrl[eventIdx].bufferWarningLevel;

    /* Index starting from which the next log entry will be written into the circular buffer - determined at runtime: */
    writeIdx = Ssa_SecLog_NvmCtrl_GetWriteIdx(eventIdx);
    /* Length of data currently written to the circular buffer - determined at runtime: */
    lengthContent = Ssa_SecLog_NvmCtrl_GetLengthContent(eventIdx);
    thresholdWarning = Ssa_SecLog_NvmCtrl_GetThresholdWarning(eventIdx);

    /* Assert that the stored total RAM block size exceeds the length of the control data and the stored counter,
     * i.e., there is still room for the circular buffer:*/
    /*@ assert (SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + Ssa_SecLog_NvmCtrl[eventIdx].globCntSize) < Ssa_SecLog_NvmCtrl[eventIdx].ramBlockSize; */

    /* Assert that the remaining room for the circular buffer is given by bufferSize: */
    /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[eventIdx].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE + Ssa_SecLog_NvmCtrl[eventIdx].globCntSize])) >= bufferSize; */ /* VCA_SSA_SECLOG_NVMADDR_NVMCTRL_CORRESPONDENCE */

    /* Assert that starting from writeIdx, entrySize many bytes can be written: */
    /*@ assert (bufferSize - writeIdx) >= entrySize; */ /* VCA_SSA_SECLOG_EVENT_LOG_CONCEPT */

    /* #10 Write time-stamp. High byte first */
    SecLog_EventBuffer(eventIdx)[writeIdx]      = (uint8)((*tickCount >> 32u) & 0xFFu); /* VCA_SSA_SECLOG_EVENT_LOG_CONCEPT */
    SecLog_EventBuffer(eventIdx)[writeIdx + 1u] = (uint8)((*tickCount >> 24u) & 0xFFu); /* VCA_SSA_SECLOG_EVENT_LOG_CONCEPT */
    SecLog_EventBuffer(eventIdx)[writeIdx + 2u] = (uint8)((*tickCount >> 16u) & 0xFFu); /* VCA_SSA_SECLOG_EVENT_LOG_CONCEPT */
    SecLog_EventBuffer(eventIdx)[writeIdx + 3u] = (uint8)((*tickCount >> 8u) & 0xFFu);  /* VCA_SSA_SECLOG_EVENT_LOG_CONCEPT */
    SecLog_EventBuffer(eventIdx)[writeIdx + 4u] = (uint8)(*tickCount & 0xFFu);          /* VCA_SSA_SECLOG_EVENT_LOG_CONCEPT */

    /* #20 Write log entry data. */
    /*@ assert SECLOG_TIMESTAMP_SIZE == 5 && entrySize >= SECLOG_TIMESTAMP_SIZE; */
    if (logEntryData != NULL_PTR)
    {
      /* PRQA S 0315 1 */ /* MD_SSA_P2VOID_CAST */
      Ssa_MemCpy(
        &(SecLog_EventBuffer(eventIdx)[writeIdx + SECLOG_TIMESTAMP_SIZE]),
        logEntryData,
        (uint32)entrySize - SECLOG_TIMESTAMP_SIZE);
    }
    else
    {
      uint8_least i;
      /* Fill in zeroes */
      /* Substraction and cast is ok since all possible entry sizes are >=5 and <= 25 */
      for (i = 0u; i < (uint8_least)(entrySize - SECLOG_TIMESTAMP_SIZE); i++) /* FETA_SSA_SECLOG_MONOTONIC_FOR_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
      {
        SecLog_EventBuffer(eventIdx)[writeIdx + SECLOG_TIMESTAMP_SIZE + i] = 0x00u; /* VCA_SSA_SECLOG_EVENT_LOG_CONCEPT */
      }
    }
    /* #30 Calculate next log entry write index. */
    writeIdx = (writeIdx + entrySize) % bufferSize;
    /*@ assert writeIdx < bufferSize; */ /* VCA_SSA_SECLOG_MODULO */

    /*@ assert Ssa_SecLog_NvmAddress[eventIdx].ramBlock != NULL_PTR; */
    /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[eventIdx].ramBlock) >= 4; */
    Ssa_SecLog_NvmCtrl_SetWriteIdx(eventIdx, writeIdx);

    /* #40 Calculate new size of logged data. */
    if (lengthContent < bufferSize)
    {
      lengthContent += entrySize;
      Ssa_SecLog_NvmCtrl_SetLengthContent(eventIdx, lengthContent);
    }
    /*@ assert lengthContent <= bufferSize; */ /* VCA_SSA_SECLOG_EVENT_LOG_CONCEPT */

    /* #50 When the buffer overflow threshold is reached notify danger of circular buffer overflow. */
    if (writeIdx == thresholdWarning)
    {
      uint8 DangerOfCircularBufferOverflowData[7];
      DangerOfCircularBufferOverflowData[0] = 0x00u;
      DangerOfCircularBufferOverflowData[1] = eventIdx + 1u;
      DangerOfCircularBufferOverflowData[2] = 0u;
      DangerOfCircularBufferOverflowData[3] = 0u;
      DangerOfCircularBufferOverflowData[4] = 0u;
      DangerOfCircularBufferOverflowData[5] = 0u;
      DangerOfCircularBufferOverflowData[6] = 0u;
      Rte_Exit_SecLog_ExclusiveArea();
      /* Notify danger of circular buffer overflow. */
      (void)Rte_Write_SecLog_EventNotification_Data(DangerOfCircularBufferOverflowData);
      Rte_Enter_SecLog_ExclusiveArea();
      /* #55 Calculate the new buffer overflow threshold. */
      thresholdWarning = (thresholdWarning + bufferWarningLevel) % bufferSize;
      Ssa_SecLog_NvmCtrl_SetThresholdWarning(eventIdx, thresholdWarning);
    }
    Rte_Exit_SecLog_ExclusiveArea();
  }
}

/**********************************************************************************************************************
 * SecLog_LogEvent_FailedSecOcMacVerification()
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
SSA_SECLOG_LOCAL FUNC(Std_ReturnType, Ssa_SecLog_CODE) SecLog_LogEvent_FailedSecOcMacVerification(
  P2CONST(SecOC_VerificationStatusType, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA) verificationStatus,
  P2VAR(Ssa_ThresholdExceededType, AUTOMATIC, AUTOMATIC) logInfoWritten)
{
  *logInfoWritten = SSA_THRESHOLD_EXCEEDED_NONE;

  /* #10 Check that SecOC verification result indicates no success. */
  if (verificationStatus->verificationStatus != SECOC_VERIFICATIONSUCCESS)
  {
    uint16 idx = 0u;

    /* #20 Check that the DataId is valid, i.e. that it belongs to a secured PDU. */
    if (SecLog_GetDataIdIndex(verificationStatus->secOCDataId, &idx) == TRUE)
    {
      /* #30 Only if the tick-count synchronization status is synchronized increment the DTC related counter,
       *     check whether DTC threshold is exceeded and set DTC to TRUE (if required). */
      if (Ssa_SecLog_LocalTickCountSyncStatus != SSA_TICKCOUNT_SYNC_STATE_NOT_SYNCHRONIZED)
      {
        SecLog_IncFailedMacCounterForDTC(idx);
      }

      /* #40 Only if no misconfiguration event was triggered increment the thresholds related counter,
       *     check whether thresholds are exceeded and notify possible brute force attacks. */
      if (Read_SecOcVerificationState() == SECLOG_SECOCVERIFICATIONSTATE_FINAL)
      {
        /*@ assert idx < Ssa_GetSizeOfSecLogInfo(); */
        SecLog_IncFailedMacCounterForThresholds(idx, verificationStatus->secOCDataId, logInfoWritten);
      }
      /* #50 Else if it is the first propagated (negative) verification result, change state to "all failed so far". */
      else if (Read_SecOcVerificationState() == SECLOG_SECOCVERIFICATIONSTATE_INITIAL)
      {
        Write_SecOcVerificationState(SECLOG_SECOCVERIFICATIONSTATE_ALL_FAILED);
      }
      else
      {
        /* #60 Else stay in current state "all failed so far". */
      }
    }
  }
  /* #70 Else (the SecOC verification result indicates success). */
  else
  {
    /* #80 Set the SecOC verification state to "final" (due to verification success) independently of the data id. */
    if (Read_SecOcVerificationState() != SECLOG_SECOCVERIFICATIONSTATE_FINAL)
    {
      Write_SecOcVerificationState(SECLOG_SECOCVERIFICATIONSTATE_FINAL);
    }
  }

  return RTE_E_OK;
}

/**********************************************************************************************************************
 * SecLog_IncFailedMacCounterForDTC()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_IncFailedMacCounterForDTC(uint16 idx)
{
  boolean setEventStatus = FALSE;

  Rte_Enter_SecLog_ExclusiveArea();

  /* #10 Increment the counter for the given index as long as maximum value is not reached. */
  if (Ssa_SecLog_FailedMacVerificationCounterDtc[idx] < 0xFFu)
  {
    ++Ssa_SecLog_FailedMacVerificationCounterDtc[idx];

    /* #20 If the failed MAC verification counter threshold is exceeded,
     *     set DEM event status for DTC 0xD12083 to "failed". */
    if (Ssa_SecLog_FailedMacVerificationCounterDtc[idx] == (Ssa_GetThresholdOfDataIdInfo(idx) + 1u))
    {
      /* #30 Store the SecOcDataId requested by DEM as environmental data. */
      Ssa_SecLog_SecOCDataId_ThresholdReached = Ssa_GetDataIdOfDataIdInfo(Ssa_GetDataIdInfoIdxOfSecLogInfo(idx));
      /* Set DTC (later outside if the exclusive area). */
      setEventStatus = TRUE;
    }
  }

  Rte_Exit_SecLog_ExclusiveArea();

  if (setEventStatus == TRUE)
  {
    /* Set DTC to TRUE */
    (void)Rte_Call_DTC_0xD12083_SetEventStatus(DEM_EVENT_STATUS_FAILED);
  }
}

/**********************************************************************************************************************
 * SecLog_IncFailedMacCounterForThresholds()
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
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_IncFailedMacCounterForThresholds(
  uint16 idx,
  uint16 secOCDataId,
  P2VAR(Ssa_ThresholdExceededType, AUTOMATIC, AUTOMATIC) logInfoWritten)
{
  Ssa_FailedMacVerifCounterEventType failedMacVerifCounterEvent = { 0u, SSA_THRESHOLD_EXCEEDED_NONE };

  Rte_Enter_SecLog_ExclusiveArea();

  /* #10 Increment the failed MAC verification counter only if maximum value not reached yet. */
  if (Ssa_SecLog_FailedMacVerificationCounter[idx] < 0xFFFFu)
  {
    /* SSA-IS-2111 */
    ++Ssa_SecLog_FailedMacVerificationCounter[idx];

    if (Ssa_SecLog_FailedMacVerificationCounter[idx] == (SSA_SECLOG_FAILED_MAC_VERIFICATION_COUNTER_THRESHOLD1 + 1u))
    {
      failedMacVerifCounterEvent.ThresholdExcceded = SSA_THRESHOLD_EXCEEDED_TH1;
    }
    else if (Ssa_SecLog_FailedMacVerificationCounter[idx] == (SSA_SECLOG_FAILED_MAC_VERIFICATION_COUNTER_THRESHOLD2 + 1u))
    {
      failedMacVerifCounterEvent.ThresholdExcceded = SSA_THRESHOLD_EXCEEDED_TH2;
    }
    else if (Ssa_SecLog_FailedMacVerificationCounter[idx] == (SSA_SECLOG_FAILED_MAC_VERIFICATION_COUNTER_THRESHOLD3 + 1u))
    {
      failedMacVerifCounterEvent.ThresholdExcceded = SSA_THRESHOLD_EXCEEDED_TH3;
    }
    else
    {
      /* no action */
    }
  }
  Rte_Exit_SecLog_ExclusiveArea();

  /* #20 Write log entry if any threshold has been exceeded.*/
  if (failedMacVerifCounterEvent.ThresholdExcceded != SSA_THRESHOLD_EXCEEDED_NONE)
  {
    /* Fill in log entry data. */
    uint8 logEntryData[3];
    logEntryData[0] = (uint8)(secOCDataId >> 8);
    logEntryData[1] = (uint8)(secOCDataId & 0x00FFu);
    logEntryData[2] = (uint8)(failedMacVerifCounterEvent.ThresholdExcceded);
    SecLog_GetTimestampAndWriteLogEntry(SECLOG_EVENT_FAILED_SECOC_MAC_VERIFICATION, logEntryData);

#if (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON)         /* COV_SSA_DEBUG XF */
    CANoeAPI_Printf("SecLog Event - Failed SecOc MAC verification (%u): ID=0x%04X", SECLOG_EVENT_FAILED_SECOC_MAC_VERIFICATION, secOCDataId);
#endif /* (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON) */

    /* #30 Update global counters. */

    /*@ assert (SECLOG_NVM_BLOCK_TABLE_TH1 == 13u); */
    /*@ assert (SECLOG_NVM_BLOCK_TABLE_TH2 == 14u); */
    /*@ assert (SECLOG_NVM_BLOCK_TABLE_TH3 == 15u); */

    /*@ assert Ssa_SecLog_NvmAddress[13].ramBlock == Rte_Pim_LogFailedMacVerifCount_ExceededTh1(); */ /* VCA_SSA_SECLOG_INIT */
    /*@ assert Ssa_SecLog_NvmAddress[14].ramBlock == Rte_Pim_LogFailedMacVerifCount_ExceededTh2(); */ /* VCA_SSA_SECLOG_INIT */
    /*@ assert Ssa_SecLog_NvmAddress[15].ramBlock == Rte_Pim_LogFailedMacVerifCount_ExceededTh3(); */ /* VCA_SSA_SECLOG_INIT */

    /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[SECLOG_NVM_BLOCK_TABLE_TH1].ramBlock) >= (SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS * 2u); */
    /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[SECLOG_NVM_BLOCK_TABLE_TH2].ramBlock) >= (SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS * 2u); */
    /*@ assert $lengthOf(Ssa_SecLog_NvmAddress[SECLOG_NVM_BLOCK_TABLE_TH3].ramBlock) >= (SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS * 2u); */

    /*@ assert Ssa_GetSizeOfSecLogInfo() == SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS; */
    /*@ assert idx < Ssa_GetSizeOfSecLogInfo(); */

    switch (failedMacVerifCounterEvent.ThresholdExcceded) {
    case SSA_THRESHOLD_EXCEEDED_TH1:
      SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_FailedSecOcMacVerification_Th1(idx));
      break;
    case SSA_THRESHOLD_EXCEEDED_TH2:
      SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_FailedSecOcMacVerification_Th2(idx));
      break;
    default: /* must be case SSA_THRESHOLD_EXCEEDED_TH3 */
      SecLog_IncrementGlobalEvent2ByteCounter(SecLog_Counter_FailedSecOcMacVerification_Th3(idx));
      break;
    }

    /* #40 Inform the caller that a log information has been written. */
    *logInfoWritten = failedMacVerifCounterEvent.ThresholdExcceded;
    failedMacVerifCounterEvent.PduId = secOCDataId;
    /* #50 Notify possible brute force attack. */
    (void)Rte_Send_Ssa_FailedMacVerifCounterEvent_Event(&failedMacVerifCounterEvent);
  }
}

/**********************************************************************************************************************
 * SecLog_HandleDebouncing()
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
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_HandleDebouncing(void)
{
  /* #10 Check that the elapsed time counter is till below the configured elapsed time. */
  if (Ssa_SecLog_ElapsedTime <= SSA_SECLOG_DEBOUNCE_TIME)
  {
    /* #20 Increment the elapsed time counter. */
    Ssa_SecLog_ElapsedTime++;

    /* #30 Check for reaching the debounce time as long as the final SecOC verification state is not reached. */
    if (Read_SecOcVerificationState() != SECLOG_SECOCVERIFICATIONSTATE_FINAL)
    {
      if (Ssa_SecLog_ElapsedTime == (SSA_SECLOG_DEBOUNCE_TIME + 1u))
      {
#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)
        /* #50 Once the debounce time has elapsed and the all SecOC verifications have been failed so far
        * write the log event "SecOC misconfiguration and stay in state "all failed". */
        if (Read_SecOcVerificationState() == SECLOG_SECOCVERIFICATIONSTATE_ALL_FAILED)
        {

          SecLog_LogEvent_SecOc_Misconfiguration();
        }
        else
#endif
          /* #60 Set SeOC verification state to 'final'. If not VSM: Do this only if no misconfiguration event occurred. */
        {
          Write_SecOcVerificationState(SECLOG_SECOCVERIFICATIONSTATE_FINAL);
        }
      }
    }
  }
}

/**********************************************************************************************************************
 * SecLog_CheckNvmBlockState()
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
SSA_SECLOG_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_SecLog_CODE) SecLog_CheckNvmBlockState(uint16 idxBlock)
{
  Std_ReturnType ret = E_NOT_OK;
  uint32 bitBlock = 1uL << idxBlock;

  /* #10 Check if writing the NVRam blocks or setting the Ram Block status have been requested or if the mirror
         RAM block is marked as used by NVM. */
  if ((Ssa_SecLog_NvMWriteRequested[idxBlock] == TRUE)
    || (Ssa_SecLog_NvMSetRamBlockStatus[idxBlock] == TRUE)
    || SecLog_BitOpTest(uint32, Ssa_SecLog_MirrorRamBlockUsedBits, bitBlock))
  {
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;
    /* #20 Check status of the NVRam block. It must not be pending. */
    Std_ReturnType localRet = Ssa_SecLog_NvmCtrl[idxBlock].getErrorStatusFct(&errorStatus);
    if ((localRet == E_OK) && (errorStatus != NVM_REQ_PENDING))
    {
      ret = E_OK;
    }
  }
  return ret;
}

/**********************************************************************************************************************
 * SecLog_CopyRamBlockToMirror()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_CopyRamBlockToMirror(uint16 idxBlock, uint32 bitBlock)
{
  /* #10 Copy all logging data into the RAM mirror and set the mirror RAM block to used after checking that it is not used.
*        Trigger the writing of the RAM block to NVM. */
  Rte_Enter_SecLog_ExclusiveArea();
  if (Ssa_SecLog_MirrorRamBlockUsed <= SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM)
  {
    SecLog_BitOpSet(uint32, Ssa_SecLog_MirrorRamBlockUsedBits, bitBlock);
    Ssa_SecLog_MirrorRamBlockUsed = SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM;
    /* PRQA S 0314, 0315 2 */ /* MD_SSA_P2VOID_CAST */
    Ssa_MemCpy( /* VCA_SSA_SECLOG_NVMADDR_NVMCTRL_CORRESPONDENCE */
      Ssa_SecLog_NvmAddress[idxBlock].ramBlockMirror,
      (P2CONST(void, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA))Ssa_SecLog_NvmAddress[idxBlock].ramBlock,
      Ssa_SecLog_NvmCtrl[idxBlock].ramBlockSize); /*lint !e545 */
    Ssa_SecLog_NvMWriteRequested[idxBlock] = FALSE;
    SecLog_BitOpSet(uint8, Ssa_SecLog_NvMWriteState[idxBlock], SECLOG_NVM_WRITE_STATE_START_BLOCK);
  }
  Rte_Exit_SecLog_ExclusiveArea();
}

/**********************************************************************************************************************
 * SecLog_WriteRamBlocksToNvm()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_WriteRamBlocksToNvm(uint16 idxBlock)
{
  /* #10 Write NVRam block using the RAM mirror using a bit mask.
         Clear write request if writing has been successfully started. */
  if (SecLog_BitOpTest(uint8, Ssa_SecLog_NvMWriteState[idxBlock], SECLOG_NVM_WRITE_STATE_START_BLOCK))
  {
    /* PRQA S 0314 1 */ /* MD_SSA_P2VOID_CAST */
    if (Ssa_SecLog_NvmCtrl[idxBlock].writeBlockFct((dtRef_const_VOID)(Ssa_SecLog_NvmAddress[idxBlock].ramBlockMirror)) == E_OK) /*lint !e545 */
    {
      SecLog_BitOpClr(uint8, Ssa_SecLog_NvMWriteState[idxBlock], SECLOG_NVM_WRITE_STATE_START_BLOCK);
    }
  }
}

/**********************************************************************************************************************
 * SecLog_HandleNvmBlock()
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
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_HandleNvmBlock(uint16 idxBlock)
{
  uint32 bitBlock = 1uL << idxBlock;
  Std_ReturnType ret = SecLog_CheckNvmBlockState(idxBlock);

  if (ret == E_OK)
  {
    /* #10 Check if writing the NVRam blocks has been requested and if writing the RAM block to NVM is in idle state. */
    if ((Ssa_SecLog_NvMWriteRequested[idxBlock] == TRUE) && (Ssa_SecLog_NvMWriteState[idxBlock] == SECLOG_NVM_WRITE_STATE_IDLE))
    {
      SecLog_CopyRamBlockToMirror(idxBlock, bitBlock);
    }
    /* #20 Else: Check if the RAM blocks shall be written to NVM. */
    else if (Ssa_SecLog_NvMWriteState[idxBlock] != SECLOG_NVM_WRITE_STATE_IDLE)
    {
      SecLog_WriteRamBlocksToNvm(idxBlock);
    }
    /* #30 Else: Since status is not pending set the mirror RAM block to unused if marked as used by NVM. */
    else if (SecLog_BitOpTest(uint32, Ssa_SecLog_MirrorRamBlockUsedBits, bitBlock))
    {
      SecLog_BitOpClr(uint32, Ssa_SecLog_MirrorRamBlockUsedBits, bitBlock);
      /* Ssa_SecLog_MirrorRamBlockUsedBits can't be read and written in an atomic operation */
      Ssa_SecLog_MirrorRamBlockUsed = (Ssa_SecLog_MirrorRamBlockUsedBits == 0uL) ? SSA_SECLOG_MIRRORRAMBLOCK_UNUSED : SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_NVM;
    }
    /* #40 Else check if setting the Ram Block status has been requested. */
    else
    {
      /* In this branch, it must hold that (Ssa_SecLog_NvMSetRamBlockStatus[idxBlock] == TRUE),
       * because this was already checked in SecLog_CheckNvmBlockState(). */
      /* #50 Mark the RAM blocks as changed. */
      if (Ssa_SecLog_NvmCtrl[idxBlock].setRamBlockStatusFct(TRUE) == E_OK)
      {
        /* #60 Clear set status request. */
        Ssa_SecLog_NvMSetRamBlockStatus[idxBlock] = FALSE;
      }
    }
  }
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 * SecLog_HandleNvm()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_HandleNvm(void)
{
  uint16 idxBlock;

  /* #10 Iterate through all SecLog's NVM blocks. */
  for (idxBlock = 0u; idxBlock < SSA_SECLOG_NUM_NVM_BLOCKS; ++idxBlock)
  {
    /* #20 Handle blocks individually. */
    SecLog_HandleNvmBlock(idxBlock);
  }
}  /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 * SecLog_HandleLoggingActiveTimer()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_HandleTimers(void)
{
  /* #10 Handle the time-out counter for usage of mirror RAM block by diagnostic service. */
  Rte_Enter_SecLog_ExclusiveArea();
  if (Ssa_SecLog_MirrorRamBlockUsed > SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_DIAGSERVICE)
  {
    Ssa_SecLog_MirrorRamBlockUsed--;
    if (Ssa_SecLog_MirrorRamBlockUsed == SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_DIAGSERVICE)
    {
      Ssa_SecLog_MirrorRamBlockUsed = SSA_SECLOG_MIRRORRAMBLOCK_UNUSED;
    }
  }

  /* #20 Decrement the counter for the LoggingActive time-out. */
  if (Ssa_SecLog_LoggingActiveTimer > 0u)
  {
    Ssa_SecLog_LoggingActiveTimer--;

    if (Ssa_SecLog_LoggingActiveTimer == 0u)
    {
      Rte_Exit_SecLog_ExclusiveArea();

      /* #30 If LoggingActive time-out occurred notify end of logging. */
      (void)Rte_Write_SecLog_EventNotification_Data(Ssa_SecLog_EndOfLoggingData);
    }
    else
    {
      Rte_Exit_SecLog_ExclusiveArea();
    }
  }
  else
  {
    Rte_Exit_SecLog_ExclusiveArea();
  }
}

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 * SecLog_LogEvent_SecOc_Misconfiguration()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */

SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_LogEvent_SecOc_Misconfiguration(void)
{
  /* #10 Write log entry. */
  SecLog_GetTimestampAndWriteLogEntry(SECLOG_EVENT_SECOC_MISCONFIGURATION, NULL_PTR);
# if (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON)         /* COV_SSA_DEBUG XF */
  CANoeAPI_Printf("SecLog Event - Failed SecOc MAC verification (level exceeded) (%u)", SECLOG_EVENT_SECOC_MISCONFIGURATION);
# endif /* (SECLOG_CANOE_DEBUGGING_OUTPUT == STD_ON) */

  /* #20 Update global counter. */
  /*@ assert (SECLOG_EVENT_SECOC_MISCONFIGURATION == 8u) && (SSA_SECLOG_SIZE_GLOBCOUNT_9 == 4u); */
  /*@ assert SSA_SECLOG_NVRAM_CTRL_DATA_SIZE == 8; */
  /*@ assert $lengthOf(&(Ssa_SecLog_NvmAddress[SECLOG_EVENT_SECOC_MISCONFIGURATION].ramBlock[SSA_SECLOG_NVRAM_CTRL_DATA_SIZE])) >= 4; */ /* VCA_SSA_SECLOG_SIZE_OF_RAM_BLOCK_BUFFERS */
  SecLog_IncrementGlobalEvent4ByteCounter(SecLog_Counter_SecOcMisconfiguration());

  /* #30 Request marking the RAM blocks as changed. */
  Ssa_SecLog_NvMSetRamBlockStatus[SECLOG_EVENT_SECOC_MISCONFIGURATION] = TRUE;

  /* #40 Notify logging. */
  SecLog_NotifyLogging();
}

#endif

/**********************************************************************************************************************
 * SecLog_FillInCircularBufferData()
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
SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_FillInCircularBufferData(
  P2VAR(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) Data,
  const boolean fillInAllLogData,
  P2VAR(uint16, AUTOMATIC, AUTOMATIC) byteDestIdx)
{
  /*@ assert *byteDestIdx <= SECLOG_MAX_INDEX_AFTER_OVERHEAD_AND_COUNTERS; */
  Ssa_SecLogInfoIterType i = 0u;

  /* #10 If requested fill in the circular buffers' data. */
  if (fillInAllLogData)
  {
    /*@ assert $lengthOf(Data) >= sizeof(Dcm_Data4092ByteType);*/

    /* #20 Copy the log event buffers to the output buffer. Bring the content of the buffers in chronological order. */
    for (i = 0u; i < SSA_SECLOG_NUMBER_OF_EVENTS; i++)
    {
      /* Ssa_SecLog_NvmCtrl_GetWriteIdxMirror(i) is reduced modulo the bufferSize in order 
       * to facilitate the silent argumentation, since this ensures that subtracting the reduced
       * value from bufferSize does not cause an underflow.
       * Note: The write index is initialized with 0 in Ssa_SecLog_Init. It is only overwritten,
       * if bufferSize > 0 (in SecLog_WriteLogEntry). Thus, if bufferSize = 0, the write index is 0, too. 
       * In this case, nothing will be copied to Data here. */
      uint16 sizePart1 = 0u;
      uint16 writeIdxMirror = ((Ssa_SecLog_NvmCtrl[i].bufferSize > 0u) ? (Ssa_SecLog_NvmCtrl_GetWriteIdxMirror(i) % Ssa_SecLog_NvmCtrl[i].bufferSize) : Ssa_SecLog_NvmCtrl_GetWriteIdxMirror(i));

      /* Type of Event. */
      Data[*byteDestIdx] = (uint8)(i + 1u);
      /* Length of Content. */
      Data[*byteDestIdx + 1u] = (uint8)(Ssa_SecLog_NvmCtrl_GetLengthContentMirror(i) >> 8u);
      Data[*byteDestIdx + 2u] = (uint8)(Ssa_SecLog_NvmCtrl_GetLengthContentMirror(i) & 0xFFu);

      if (Ssa_SecLog_NvmCtrl_GetLengthContentMirror(i) == Ssa_SecLog_NvmCtrl[i].bufferSize)
      {
        /* #30 Copy part 1 starting at oldest log entry (which is the next to be overwritten). */
        /*@ assert Ssa_SecLog_NvmCtrl_GetWriteIdxMirror(i) <= Ssa_SecLog_NvmCtrl[i].bufferSize; */ /* VCA_SSA_SECLOG_RAM_BLOCK_MIRROR */
        sizePart1 = (uint16)(Ssa_SecLog_NvmCtrl[i].bufferSize - writeIdxMirror);
        /*@ assert sizePart1 <= Ssa_SecLog_NvmCtrl[i].bufferSize; */ /* VCA_SSA_SECLOG_SUBTRACTION_WITHOUT_UNDERFLOW */

        /* PRQA S 0314, 0315 1 */ /* MD_SSA_P2VOID_CAST */
        Ssa_MemCpy(&Data[*byteDestIdx + 3u], (P2CONST(void, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA))&(SecLog_EventBufferMirror(i)[writeIdxMirror]), sizePart1);
      }

      if (writeIdxMirror > 0u)
      {
        /* #40 Copy part 2 starting at log entry with smallest address. */
        uint16 sizePart2 = writeIdxMirror;

        /*@ assert sizePart1 <= Ssa_SecLog_NvmCtrl[i].bufferSize; */ /* VCA_SSA_SECLOG_SUBTRACTION_WITHOUT_UNDERFLOW */
        /*@ assert sizePart2 < Ssa_SecLog_NvmCtrl[i].bufferSize; */ /* VCA_SSA_SECLOG_RAM_BLOCK_MIRROR */

       /* PRQA S 0314, 0315 1 */ /* MD_SSA_P2VOID_CAST */
        Ssa_MemCpy(&Data[*byteDestIdx + 3u + sizePart1], (P2CONST(void, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA))&(SecLog_EventBufferMirror(i)[0]), sizePart2);
      }

      /* #50 Update write position in output data buffer. */
      *byteDestIdx += (3u + Ssa_SecLog_NvmCtrl_GetLengthContentMirror(i));
      /*@ assert *byteDestIdx <= (SECLOG_MAX_INDEX_AFTER_OVERHEAD_AND_COUNTERS + 3 + Ssa_SecLog_NvmCtrl[i].bufferSize); */ /* VCA_SSA_SECLOG_RAM_BLOCK_MIRROR */
    }
  }
}

/**********************************************************************************************************************
 * SecLog_FillInSecurityEventLog()
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
SSA_SECLOG_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_SecLog_CODE) SecLog_FillInSecurityEventLog(P2VAR(uint8, AUTOMATIC, RTE_SSA_SECLOG_APPL_VAR) Data, boolean fillInAllLogData)
{
  /* Assert that the maximal global counter size is 10. This is used in later justifications. */
  /*@ assert SSA_SECLOG_SIZE_GLOBCOUNT_1  <= 10; */
  /*@ assert SSA_SECLOG_SIZE_GLOBCOUNT_2  <= 10; */
  /*@ assert SSA_SECLOG_SIZE_GLOBCOUNT_3  <= 10; */
  /*@ assert SSA_SECLOG_SIZE_GLOBCOUNT_4  <= 10; */
  /*@ assert SSA_SECLOG_SIZE_GLOBCOUNT_5  <= 10; */
  /*@ assert SSA_SECLOG_SIZE_GLOBCOUNT_6  <= 10; */
  /*@ assert SSA_SECLOG_SIZE_GLOBCOUNT_7  <= 10; */
  /*@ assert SSA_SECLOG_SIZE_GLOBCOUNT_8  <= 10; */
  /*@ assert SSA_SECLOG_SIZE_GLOBCOUNT_9  <= 10; */
  /*@ assert SSA_SECLOG_SIZE_GLOBCOUNT_10 == 0; */ /* this counter is skipped in later for-loops */
  /*@ assert SSA_SECLOG_SIZE_GLOBCOUNT_11 <= 2; */
  /*@ assert SSA_SECLOG_SIZE_GLOBCOUNT_12 <= 2; */
  /*@ assert SSA_SECLOG_SIZE_GLOBCOUNT_13 <= 2; */

  Std_ReturnType retVal = RTE_E_OK;
  uint16 byteDestIdx = SECLOG_SIZE_OF_READ_DATA_LENGTH;
  uint16 idxBlock;

  /* #10 Fill in the log data depending on whether all log data or only the global counters are requested. */
  if (fillInAllLogData)
  {
    /* #20 If all log data shall be filled in set the current local tick-count, real-time offset and the data length. */
    uint64 tickCount = 0u;
    TimeM_DateTimeType currentDateTime = { 0u };

    /* #30 Get current tick-count. */
    retVal = Rte_Call_TimeM_TickCount_Get(&tickCount);
    /* #40 Get current real-time. */
    retVal |= Rte_Call_TimeM_RealTime_Get(&currentDateTime);

    if (retVal == RTE_E_OK)
    {
      uint16 rest;

      /* #50 Set tick-count as time-stamp. */
      Data[0] = (uint8)((tickCount >> 32) & 0xFFu);
      Data[1] = (uint8)((tickCount >> 24) & 0xFFu);
      Data[2] = (uint8)((tickCount >> 16) & 0xFFu);
      Data[3] = (uint8)((tickCount >> 8) & 0xFFu);
      Data[4] = (uint8)(tickCount & 0xFFu);

      /* #60 Set the current real-time. Output format according to Generalized Time. */
      rest = currentDateTime.year;
      /* Year: YYYY */
      Data[5] = (uint8)((rest / 1000u) + 0x30u);
      rest %= 1000u;
      Data[6] = (uint8)((rest / 100u) + 0x30u);
      rest %= 100u;
      Data[7] = (uint8)((rest / 10u) + 0x30u);
      rest %= 10u;
      Data[8] = (uint8)(rest + 0x30u);
      /* Month: MM */
      Data[9] = (uint8)((currentDateTime.month / 10u) + 0x30u);
      Data[10] = (uint8)((currentDateTime.month % 10u) + 0x30u);
      /* Day: DD */
      Data[11] = (uint8)((currentDateTime.day / 10u) + 0x30u);
      Data[12] = (uint8)((currentDateTime.day % 10u) + 0x30u);
      /* Hour: HH */
      Data[13] = (uint8)((currentDateTime.hour / 10u) + 0x30u);
      Data[14] = (uint8)((currentDateTime.hour % 10u) + 0x30u);
      /* Minute: MM */
      Data[15] = (uint8)((currentDateTime.minute / 10u) + 0x30u);
      Data[16] = (uint8)((currentDateTime.minute % 10u) + 0x30u);
      /* Second: SS */
      Data[17] = (uint8)((currentDateTime.second / 10u) + 0x30u);
      Data[18] = (uint8)((currentDateTime.second % 10u) + 0x30u);
      /* UTC: Z */
      Data[19] = (uint8)0x5A;

      /* #70 Set the size in Bytes of the Security Event Log. */
      Data[20] = (uint8)(Ssa_SecLog_ReadDataLength >> 8u);
      Data[21] = (uint8)(Ssa_SecLog_ReadDataLength & 0xFFu);

      /* #80 Copy global event counters data to the output buffer. */
      byteDestIdx += SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME;
    }
  }
  else
  {
    /* #90 Else: Write the data length of the global event counters to the first two bytes. */
    Data[0] = (uint8)(Ssa_SecLog_ReadDataLength >> 8u);
    Data[1] = (uint8)(Ssa_SecLog_ReadDataLength & 0xFFu);
  }

  /* Remind the VCA where the RAM block mirror pointers point to: */
  /*@ assert Ssa_SecLog_NvmAddress[0].ramBlockMirror == Rte_Pim_LogDataEvnt1_FailedCertVerif_Mirror(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[1].ramBlockMirror == Rte_Pim_LogDataEvnt2_SucCertVerif_Mirror(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[2].ramBlockMirror == Rte_Pim_LogDataEvnt3_SucAuthAndEnhanceRights_Mirror(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[3].ramBlockMirror == Rte_Pim_LogDataEvnt4_AuthBySecAccess_Mirror(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[4].ramBlockMirror == Rte_Pim_LogDataEvnt5_SucDiagServiceExec_Mirror(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[5].ramBlockMirror == Rte_Pim_LogDataEvnt6_RightsMgmt_Mirror(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[6].ramBlockMirror == Rte_Pim_LogDataEvnt7_SigVerif_Mirror(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[7].ramBlockMirror == Rte_Pim_LogDataEvnt8_TickCountDateAndTime_Mirror(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[8].ramBlockMirror == Rte_Pim_LogDataEvnt9_SecOcMisconfig_Mirror(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[9].ramBlockMirror == Rte_Pim_LogDataEvnt10_FailedPduMacVerif_Mirror(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[10].ramBlockMirror == Rte_Pim_LogDataEvnt11_SecOrAuthBoot_Mirror(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[11].ramBlockMirror == Rte_Pim_LogDataEvnt12_ChangeOfVin_Mirror(); */ /* VCA_SSA_SECLOG_INIT */
  /*@ assert Ssa_SecLog_NvmAddress[12].ramBlockMirror == Rte_Pim_LogDataEvnt13_AclReplacement_Mirror(); */ /* VCA_SSA_SECLOG_INIT */

  /* #100 Afterwards fill in the requested log data. */
  if (retVal == RTE_E_OK)
  {
    Ssa_SecLogInfoIterType i;

    /* #110 Always fill in the global counters' values. */
    /* Iterate through first part of NVM blocks. */
    /*@ assert byteDestIdx <= SECLOG_SIZE_OF_READ_DATA_LENGTH + SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME; */
    for (idxBlock = 0u; idxBlock < SECLOG_EVENT_FAILED_SECOC_MAC_VERIFICATION; ++idxBlock)
    {
      /* PRQA S 0314, 0315 1 */ /* MD_SSA_P2VOID_CAST */
      Ssa_MemCpy(&Data[byteDestIdx], (P2CONST(void, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA))&(Ssa_SecLog_NvmAddress[idxBlock].ramBlockMirror[8u]), Ssa_SecLog_NvmCtrl[idxBlock].globCntSize);
      /* Part 2 */
      byteDestIdx += Ssa_SecLog_NvmCtrl[idxBlock].globCntSize;
      /*@ assert idxBlock < SECLOG_EVENT_FAILED_SECOC_MAC_VERIFICATION; */
      /*@ assert byteDestIdx <= SECLOG_SIZE_OF_READ_DATA_LENGTH + SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME + (idxBlock * 10); */ /* VCA_SSA_SECLOG_SIZE_OF_GLOBAL_COUNTERS */
    }
    /* If the size of the first 8 counters is estimated with 10, the VCA can assert the following without justification: */
    /*@ assert byteDestIdx <= SECLOG_SIZE_OF_READ_DATA_LENGTH + SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME + ((SECLOG_EVENT_FAILED_SECOC_MAC_VERIFICATION - 1u) * 10); */
    /* This assertion is kept to simplify the review.
     * However, the exact size of the first 9 counters is known and so is their exact sum, only the VCA does not believe this without justification: */
    /*@ assert byteDestIdx <= SECLOG_SIZE_OF_READ_DATA_LENGTH + SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME + 58; */ /* VCA_SSA_SECLOG_SIZE_OF_GLOBAL_COUNTERS */

    /* Number of counter values. */
    Data[byteDestIdx] = (uint8)(Ssa_GetSizeOfSecLogInfo() >> 8u); /*lint !e572 */ /* PRQA S 0499 */ /* MD_SSA_SHIFT_OPERATION */
    Data[byteDestIdx + 1u] = (uint8)(Ssa_GetSizeOfSecLogInfo() & 0xFFu);
    byteDestIdx += 2u;
    /* Configured value for threshold th1. */
    Data[byteDestIdx] = (uint8)(SSA_SECLOG_FAILED_MAC_VERIFICATION_COUNTER_THRESHOLD1 >> 8u); /*lint !e572 */ /* PRQA S 0499 */ /* MD_SSA_SHIFT_OPERATION */
    Data[byteDestIdx + 1u] = (uint8)(SSA_SECLOG_FAILED_MAC_VERIFICATION_COUNTER_THRESHOLD1 & 0xFFu);
    byteDestIdx += 2u;
    /* Configured value for threshold th2. */
    Data[byteDestIdx] = (uint8)(SSA_SECLOG_FAILED_MAC_VERIFICATION_COUNTER_THRESHOLD2 >> 8u); /*lint !e572 */ /* PRQA S 0499 */ /* MD_SSA_SHIFT_OPERATION */
    Data[byteDestIdx + 1u] = (uint8)(SSA_SECLOG_FAILED_MAC_VERIFICATION_COUNTER_THRESHOLD2 & 0xFFu);
    byteDestIdx += 2u;
    /* Configured value for threshold th3. */
    Data[byteDestIdx] = (uint8)(SSA_SECLOG_FAILED_MAC_VERIFICATION_COUNTER_THRESHOLD3 >> 8u); /*lint !e572 */ /* PRQA S 0499 */ /* MD_SSA_SHIFT_OPERATION */
    Data[byteDestIdx + 1u] = (uint8)(SSA_SECLOG_FAILED_MAC_VERIFICATION_COUNTER_THRESHOLD3 & 0xFFu);
    byteDestIdx += 2u;

    /*@ assert byteDestIdx <= SECLOG_SIZE_OF_READ_DATA_LENGTH + SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME + 58 + 8; */
    for (i = 0u; i < Ssa_GetSizeOfSecLogInfo(); i++)
    {
      Data[byteDestIdx] = (uint8)(Ssa_GetDataIdOfDataIdInfo(Ssa_GetDataIdInfoIdxOfSecLogInfo(i)) >> 8u);
      Data[byteDestIdx + 1u] = (uint8)(Ssa_GetDataIdOfDataIdInfo(Ssa_GetDataIdInfoIdxOfSecLogInfo(i)) & 0xFFu);

      /* PRQA S 0314, 0315 3 */ /* MD_SSA_P2VOID_CAST */
      Ssa_MemCpy(&Data[byteDestIdx + 2u], (P2CONST(void, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA))&(Ssa_SecLog_NvmAddress[SECLOG_NVM_BLOCK_TABLE_TH1].ramBlockMirror[2u * i]), 2u);
      Ssa_MemCpy(&Data[byteDestIdx + 4u], (P2CONST(void, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA))&(Ssa_SecLog_NvmAddress[SECLOG_NVM_BLOCK_TABLE_TH2].ramBlockMirror[2u * i]), 2u);
      Ssa_MemCpy(&Data[byteDestIdx + 6u], (P2CONST(void, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA))&(Ssa_SecLog_NvmAddress[SECLOG_NVM_BLOCK_TABLE_TH3].ramBlockMirror[2u * i]), 2u);
      byteDestIdx += 8u;
      /*@ assert i < Ssa_GetSizeOfSecLogInfo(); */
      /*@ assert byteDestIdx <= SECLOG_SIZE_OF_READ_DATA_LENGTH + SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME + 58 + 8 + (i * 8); */ /* VCA_SSA_SECLOG_INCREASE_INDEX_IN_FOR_LOOP */
    }
    /*@ assert Ssa_GetSizeOfSecLogInfo() == SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS; */
    /*@ assert byteDestIdx <= SECLOG_SIZE_OF_READ_DATA_LENGTH + SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME + 58 + 8 + (SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS * 8); */

    /* Iterate through remaining NVM blocks. */
    for (idxBlock = SECLOG_EVENT_SECURE_BOOT_OR_AUTHENTICATED_BOOT; idxBlock < SSA_SECLOG_NUMBER_OF_EVENTS; ++idxBlock)
    {

      /* PRQA S 0314, 0315 1 */ /* MD_SSA_P2VOID_CAST */
      Ssa_MemCpy(&Data[byteDestIdx], (P2CONST(void, AUTOMATIC, RTE_SSA_SECLOG_APPL_DATA))&(Ssa_SecLog_NvmAddress[idxBlock].ramBlockMirror[8]), Ssa_SecLog_NvmCtrl[idxBlock].globCntSize);
      /* Part 2 */
      byteDestIdx += Ssa_SecLog_NvmCtrl[idxBlock].globCntSize;
      /*@ assert idxBlock < SSA_SECLOG_NUMBER_OF_EVENTS; */
      /*@ assert byteDestIdx <= SECLOG_SIZE_OF_READ_DATA_LENGTH + SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME + 58 + 8 + (SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS * 8) + ((idxBlock + 1 - SECLOG_EVENT_SECURE_BOOT_OR_AUTHENTICATED_BOOT) * 2); */ /* VCA_SSA_SECLOG_INCREASE_INDEX_IN_FOR_LOOP */
    }
    /* If the size of the used 3 counters is estimated with 2, the VCA can assert the following without justification: */
    /*@ assert byteDestIdx <= SECLOG_SIZE_OF_READ_DATA_LENGTH + SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME + 58 + 8 + (SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS * 8) + (3 * 2); */
    /* This assertion is kept to simplify the review.
     * However, the exact size of the used 3 counters is known and so is their exact sum, only the VCA does not believe this without justification: */
    /*@ assert byteDestIdx <= SECLOG_SIZE_OF_READ_DATA_LENGTH + SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME + 58 + 8 + (SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS * 8) + 5; */ /* VCA_SSA_SECLOG_SIZE_OF_GLOBAL_COUNTERS */

    /* #120 If requested fill in the circular buffers' data. */
    SecLog_FillInCircularBufferData(Data, fillInAllLogData, &byteDestIdx);
  }
  else
  {
    retVal = RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * SecLog_CheckContextDateTimeChangeForNvmWriteRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

SSA_SECLOG_LOCAL_INLINE FUNC(void, Ssa_SecLog_CODE) SecLog_CheckContextDateTimeChangeForNvmWriteRequest(uint8 contextDateTimeChange)
{
  Rte_Enter_SecLog_ExclusiveArea();

  /* #10 Depending on contextDateTimeChange an NVM write block is requested. */
  switch (contextDateTimeChange & 0x7Fu) {
  case 0x02u:
    /* Check if not yet logged. */
    if (!SecLog_BitOpTest(uint8, Ssa_SecLog_LocalTickCountDateTimeChangeEventLogged, SSA_SECLOG_LOCAL_TICK_COUNT_CHANGED_BY_BROADCAST))
    {
      Ssa_SecLog_NvMWriteRequested[SECLOG_EVENT_CHANGE_TICK_COUNT_OR_DATE_AND_TIME] = TRUE;
      SecLog_BitOpSet(uint8, Ssa_SecLog_LocalTickCountDateTimeChangeEventLogged, SSA_SECLOG_LOCAL_TICK_COUNT_CHANGED_BY_BROADCAST);
    }
    break;
  case 0x03u:
    /* Check if not yet logged. */
    if (!SecLog_BitOpTest(uint8, Ssa_SecLog_LocalTickCountDateTimeChangeEventLogged, SSA_SECLOG_REAL_TIME_OFFSET_CHANGED_BY_REAL_TIME_OFFSET_BROADCAST))
    {
      Ssa_SecLog_NvMWriteRequested[SECLOG_EVENT_CHANGE_TICK_COUNT_OR_DATE_AND_TIME] = TRUE;
      SecLog_BitOpSet(uint8, Ssa_SecLog_LocalTickCountDateTimeChangeEventLogged, SSA_SECLOG_REAL_TIME_OFFSET_CHANGED_BY_REAL_TIME_OFFSET_BROADCAST);
    }
    break;
  case 0x07u:
    /* Check if not yet logged. */
    if (!SecLog_BitOpTest(uint8, Ssa_SecLog_LocalTickCountDateTimeChangeEventLogged, SSA_SECLOG_LOCAL_TICK_COUNT_ATTEMPT_TO_TURN_BACK))
    {
      Ssa_SecLog_NvMWriteRequested[SECLOG_EVENT_CHANGE_TICK_COUNT_OR_DATE_AND_TIME] = TRUE;
      SecLog_BitOpSet(uint8, Ssa_SecLog_LocalTickCountDateTimeChangeEventLogged, SSA_SECLOG_LOCAL_TICK_COUNT_ATTEMPT_TO_TURN_BACK);
    }
    break;
  default:
    Ssa_SecLog_NvMWriteRequested[SECLOG_EVENT_CHANGE_TICK_COUNT_OR_DATE_AND_TIME] = TRUE;
    break;
  }

  Rte_Exit_SecLog_ExclusiveArea();
}

/**********************************************************************************************************************
 * SecLog_StartLogging()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_NotifyLogging(void)
{
  /* #10 Notify start of logging if the logging active timer is not yet running. */
  if (Ssa_SecLog_LoggingActiveTimer == 0u)
  {
    (void)Rte_Write_SecLog_EventNotification_Data(Ssa_SecLog_StartOfLoggingData);
  }
  /* #20 Re-start the logging active timer. */
  Ssa_SecLog_LoggingActiveTimer = SECLOG_LOGGINGACTIVE_TIMEOUT;
}

/**********************************************************************************************************************
 * SecLog_InitializeNvRamBlocks()
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
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_InitializeNvRamBlocks(void)
{
  NvM_RequestResultType nvmReqRes = NVM_REQ_NOT_OK;
  uint16 idxBlock, i;

  /* #10 Iterate through all SecLog's NVM blocks. */
  for (idxBlock = 0u; idxBlock < SSA_SECLOG_NUM_NVM_BLOCKS; ++idxBlock)
  {
    /* #20 Get the NVM (error-)status. */
    if (Ssa_SecLog_NvmCtrl[idxBlock].getErrorStatusFct(&nvmReqRes) == RTE_E_OK)
    {
      /* #30 If the error status indicates that reading the block failed reset all log data. Exclude "request pending". */
      if ((nvmReqRes != NVM_REQ_OK) && (nvmReqRes != NVM_REQ_PENDING))
      {
        /* #40 clear the complete RAM block. */
        /*@ assert SSA_SECLOG_NUM_NVM_BLOCKS == 16; */
        /*@ assert $lengthOf(Ssa_SecLog_NvmAddress) >= SSA_SECLOG_NUM_NVM_BLOCKS && idxBlock < SSA_SECLOG_NUM_NVM_BLOCKS; */
        for (i = 0u; i < Ssa_SecLog_NvmCtrl[idxBlock].ramBlockSize; ++i) /* FETA_SSA_SECLOG_MONOTONIC_FOR_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND */
        {
          /* Clear the complete RAM block. */
          Ssa_SecLog_NvmAddress[idxBlock].ramBlock[i] = (uint8)0u; /* VCA_SSA_SECLOG_NVMADDR_NVMCTRL_CORRESPONDENCE */
        }

        /* #50 Set initial threshold warning level if it is a circular buffer RAM block. */
        if (idxBlock < SSA_SECLOG_NUMBER_OF_EVENTS)
        {
          Ssa_SecLog_NvmCtrl_SetThresholdWarning(idxBlock, (Ssa_SecLog_NvmCtrl[idxBlock].bufferWarningLevel));
        }
      }
    }
  }
}

/**********************************************************************************************************************
 * SecLog_DataServices_Security_Event_ReadData_DcmAndRamBlockCheck()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_SECLOG_LOCAL FUNC(Std_ReturnType, Ssa_SecLog_CODE) SecLog_DataServices_Security_Event_ReadData_DcmAndRamBlockCheck(
  Dcm_OpStatusType OpStatus,
  P2VAR(boolean, AUTOMATIC, AUTOMATIC) readLog)
{
  Std_ReturnType retVal = E_NOT_OK;
  *readLog = FALSE;

  /* #10 Check Dcm OpStatus and check whether mirror RAM block is available for reading. */
  Rte_Enter_SecLog_ExclusiveArea();
  if (OpStatus == DCM_CANCEL)
  {
    /* Error */
  }
  else if ((OpStatus == DCM_PENDING) && (Ssa_SecLog_MirrorRamBlockUsed != SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_DIAGSERVICE))
  {
    /* Error */
  }
  else if ((OpStatus == DCM_INITIAL) && (Ssa_SecLog_MirrorRamBlockUsed < SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_DIAGSERVICE))
  {
    /* Error */
  }
  else
  {
    if (OpStatus == DCM_INITIAL)
    {
      Ssa_SecLog_MirrorRamBlockUsed = SSA_SECLOG_MIRRORRAMBLOCK_USED_BY_DIAGSERVICE;
      *readLog = TRUE;
    }
    else
    {
      /* OpStatus is pending, set return value so that signature calculation is called. */
      retVal = E_OK;
    }
  }
  Rte_Exit_SecLog_ExclusiveArea();

  return retVal;
}

/**********************************************************************************************************************
 * SecLog_LogEvent_FailedSecOcMacVerification_MarkRamBlocksAsChanged()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_SECLOG_LOCAL FUNC(void, Ssa_SecLog_CODE) SecLog_LogEvent_FailedSecOcMacVerification_MarkRamBlocksAsChanged(
  Ssa_ThresholdExceededType logInfoWritten)
{
  /* Request marking the RAM blocks as changed. */
  Ssa_SecLog_NvMSetRamBlockStatus[SECLOG_EVENT_FAILED_SECOC_MAC_VERIFICATION] = TRUE;
  switch (logInfoWritten)
  {
    case SSA_THRESHOLD_EXCEEDED_TH1:
      Ssa_SecLog_NvMSetRamBlockStatus[SECLOG_NVM_BLOCK_TABLE_TH1] = TRUE;
      break;
    case SSA_THRESHOLD_EXCEEDED_TH2:
      Ssa_SecLog_NvMSetRamBlockStatus[SECLOG_NVM_BLOCK_TABLE_TH2] = TRUE;
      break;
    default: /* must be case SSA_THRESHOLD_EXCEEDED_TH3 */
      Ssa_SecLog_NvMSetRamBlockStatus[SECLOG_NVM_BLOCK_TABLE_TH3] = TRUE;
      break;
  }
}


#define Ssa_SecLog_STOP_SEC_CODE
#include "Ssa_SecLog_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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

    \ID  VCA_SSA_SECLOG_READ_DATA_LENGTH_FOR_LOG_COUNTER_CURRENT_VALUES
      \DESCRIPTION      According to VCA, the following assertion may be violated:
                          Ssa_SecLog_ReadDataLength <= (((SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS * 2u) + 8u) + SECLOG_AGGREGATED_GLOBAL_COUNTER_LENGTH),
                        where Ssa_SecLog_ReadDataLength is computed as
                        Ssa_SecLog_ReadDataLength = SECLOG_SIZEOF_GLOBAL_EVENT_COUNTERS_OUTPUT_OVERHEAD + SSA_SECLOG_SIZE_GLOBCOUNT_1 + ...+ SSA_SECLOG_SIZE_GLOBCOUNT_16
                        in function Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength().
                        Also, the assertion
                          logDataOutLength <= (2 + SECLOG_SIZEOF_GLOBAL_EVENT_COUNTERS_OUTPUT_OVERHEAD + SECLOG_AGGREGATED_GLOBAL_COUNTER_LENGTH);
                        in the same function is violated accroding to VCA.
      \COUNTERMEASURE   \N The values of SSA_SECLOG_SIZE_GLOBCOUNT_1, ..., SSA_SECLOG_SIZE_GLOBCOUNT_13 are fixed and configuration independent, their sum is 63.
                        This is ensured by review.
                        The sum SSA_SECLOG_SIZE_GLOBCOUNT_14 + SSA_SECLOG_SIZE_GLOBCOUNT_15 + SSA_SECLOG_SIZE_GLOBCOUNT_16 is given by (3*2*SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS),
                        (this is not configuration independent). This is ensured by review.
                        Thus, the aggregated sum is given by 63 + (3*2*SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS). This is asserted.
                        This justification is used in functions
                        - Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength() and
                        - Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData(),
                        where Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength() has to be called before
                        Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData(). This is why the assertion still holds
                        in function Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData().
                        It follows from the definition of logDataOutLength, that the assertion
                          logDataOutLength <= (2 + SECLOG_SIZEOF_GLOBAL_EVENT_COUNTERS_OUTPUT_OVERHEAD + SECLOG_AGGREGATED_GLOBAL_COUNTER_LENGTH);
                        is not violated, if the first assertion on Ssa_SecLog_ReadDataLength holds.

    \ID  VCA_SSA_SECLOG_READ_DATA_LENGTH_FOR_LOG_ENTRY
      \DESCRIPTION      According to VCA, the following assertion may be violated:
                          Ssa_SecLog_ReadDataLength < SECLOG_SIZEOF_GLOBAL_EVENT_COUNTERS_OUTPUT_OVERHEAD
                                                      + SECLOG_AGGREGATED_CIRCULAR_BUFFER_LENGTH
                                                      + SECLOG_AGGREGATED_GLOBAL_COUNTER_LENGTH
                                                      + (SSA_SECLOG_NUMBER_OF_EVENTS * SECLOG_SIZEOF_CIRCULAR_BUFFER_OUTPUT_OVERHEAD),
      \COUNTERMEASURE   \N Ssa_SecLog_ReadDataLength was computed as follows:
                        for (i = 0u; i < SSA_SECLOG_NUM_NVM_BLOCKS; ++i)
                        {
                          if (i < SSA_SECLOG_NUMBER_OF_EVENTS)
                          {
                            Ssa_SecLog_ReadDataLength += Ssa_SecLog_NvmCtrl_GetLengthContent(i);
                          }
                          Ssa_SecLog_ReadDataLength += Ssa_SecLog_NvmCtrl[i].globCntSize;
                        }
                        - The sum of the global counters is fixed and known at compile time. Their sum is referred to as SECLOG_AGGREGATED_GLOBAL_COUNTER_LENGTH.
                        - Each value Ssa_SecLog_NvmCtrl_GetLengthContent(i) stores at most the length of the circular buffer for event i.
                          This value is only written in function SecLog_WriteLogEntry(), where it is asserted that the written value is
                          less than or equal to the size of the circular buffer.
                          The sum of the size of the circular buffers is rerfered to as SECLOG_AGGREGATED_CIRCULAR_BUFFER_LENGTH.
                        - The other summands can be retraced directly in function Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength().
                        This justification is used in functions
                        - Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength() and
                        - Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData(),
                        where Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength() has to be called before
                        Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData(). This is why the assertion still holds
                        in function Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData().

    \ID  VCA_SSA_SECLOG_SIZE_OF_GLOBAL_COUNTERS
      \DESCRIPTION      According to VCA, the following assertion may fail:
                          Ssa_SecLog_NvmCtrl[idxBlock].globCntSize < 10,
                        where 0 <= idxBlock < 13.
      \COUNTERMEASURE   \N Each entry of Ssa_SecLog_NvmCtrl[idxBlock] stores the size of the corresponding global counter in its
                        member globCntSize. These values are given in the symbolic constants
                        SSA_SECLOG_SIZE_GLOBCOUNT_1, ..., SSA_SECLOG_SIZE_GLOBCOUNT_13.
                        The values of SSA_SECLOG_SIZE_GLOBCOUNT_1, ..., SSA_SECLOG_SIZE_GLOBCOUNT_13 are fixed, i.e.,
                        they are configuration invariant. Their maximum value is 10, but closer bounds can be chosen for certain subsets.
                        This is asserted at the beginning of function SecLog_FillInSecurityEventLog().
                        Hence, also their sum is known and fixed:
                          - The sum of the first 9 counters is 58.
                          - The sum of counters 11, 12 and 13 is 5.

    \ID  VCA_SSA_SECLOG_NVMADDR_NVMCTRL_CORRESPONDENCE
      \DESCRIPTION      According to VCA, either the following indexed access may be out of bounds:
                          Ssa_SecLog_NvmAddress[idxBlock].ramBlock[i], 
                        where 0 <= idxBlock < 16 and 0 <= i < Ssa_SecLog_NvmCtrl[idxBlock].ramBlockSize,
                        or the following function may be called outside its specification:
                        Ssa_MemCpy(Ssa_SecLog_NvmAddress[idxBlock].ramBlockMirror,
                                   Ssa_SecLog_NvmAddress[idxBlock].ramBlock,
                                   Ssa_SecLog_NvmCtrl[idxBlock].ramBlockSize);
      \COUNTERMEASURE   \N There are two static arrays, Ssa_SecLog_NvmAddress and Ssa_SecLog_NvmCtrl. Each entry of Ssa_SecLog_NvmCtrl is in
                        correspondence with one entry of Ssa_SecLog_NvmAddr and stores length values used to navigate through the buffers
                        referenced in Ssa_SecLog_NvmAddr. In particular, Ssa_SecLog_NvmCtrl[idxBlock].ramBlockSize stores the length
                        of the buffers Ssa_SecLog_NvmAddress[idxBlock].ramBlock and Ssa_SecLog_NvmAddress[idxBlock].ramBlockMirror.
                        This is asserted within function Ssa_SecLog_Init().

    \ID  VCA_SSA_SECLOG_INIT
      \DESCRIPTION      According to VCA, the following assertion may fail:
                          Ssa_SecLog_NvmAddress[idxBlock].ramBlock == buffer,
                        where 0 <= idxBlock < 16 and 'buffer' is the buffer to which the ram block 
                        is set to point after Ssa_SecLog_Init().
      \COUNTERMEASURE   \N This assertion holds, once the init function Ssa_SecLog_Init() was executed.
                        If (SSA_SECLOG_USE_PIM_ACCESS_MACROS_AS_COMPILE_TIME_CONSTANTS == STD_ON)
                        the pointers are not assigned during Ssa_SecLog_Init(), but Ssa_SecLog_NvmAddress
                        is a const array containing the same buffers as ram blocks.
                        This is asserted within function Ssa_SecLog_Init().

    \ID  VCA_SSA_SECLOG_SIZE_OF_RAM_BLOCK_BUFFERS
      \DESCRIPTION      According to VCA, the following assertion may fail:
                          $lengthOf(&(Ssa_SecLog_NvmAddress[idxBlock].ramBlock[subindex])) >= length value, 
                        where 
                        - 0 <= idxBlock < 16, 
                        - 'subindex' is either 0 or SSA_SECLOG_NVRAM_CTRL_DATA_SIZE = 8 and
                        - 'length value' is either 2, 4, 6, 8 or 10.
      \COUNTERMEASURE   \N As stated in VCA_SSA_SECLOG_NVMADDR_NVMCTRL_CORRESPONDENCE, the length of the buffers
                        Ssa_SecLog_NvmAddress[idxBlock].ramBlock and Ssa_SecLog_NvmAddress[idxBlock].ramBlockMirror
                        is known and fixed. This is checked by assertions in function Ssa_SecLog_Init().
                        The shortest ram block buffer is of length sizeof(SecLog_LogDataEvnt11_SecOrAuthBootType) = 59.
                        Note: This justification is used to justify write accesses to the global counters part of
                        a RAM block. To facilitate the review, the size of the respective global counter part
                        is asserted, too.

    \ID  VCA_SSA_SECLOG_MODULO
      \DESCRIPTION      According to VCA, the following assertion may fail:
                          x < y,
                        where the value of x was computed as x = value mod y.
      \COUNTERMEASURE   \N After the modulo operation is executed, it holds that x < y.

    \ID  VCA_SSA_SECLOG_EVENT_LOG_CONCEPT
      \DESCRIPTION      According to VCA, several indexed accesses may fail in the context of event logging.
      \COUNTERMEASURE   \N Events are logged in a circular buffer, which is part of a RAM block.
                        The silent analysis takes into account the following points:
                        - The size of an event is known at pre-compile time, it is configuration invariant.
                          This is asserted at the beginning of function SecLog_WriteLogEntry().
                        - The length of the circular buffer to log the event is a multiple of the size of the event. This is known at pre-compile time.
                          This is asserted at the beginning of function SecLog_WriteLogEntry().
                        - The index at which a logged event is written to the RAM buffer is read from the RAM buffer control data at run time.
                        - The write index is only updated within function SecLog_WriteLogEntry().
                          This is ensured by review.
                          - The write index never exceeds the circular buffer length since it is reduced modulo the circular buffer length.
                            This is ensured by review.
                          - The write index is increased by the event length and subsequently reduced; it is not increased by other values than that.
                            This is ensured by review.
                          - Since the circular buffer length is a multiple of the event length, the minimum difference between the write index and the length
                            of the circular buffer is given by the length of the event.
                          - Thus, when SecLog_WriteLogEntry() is called, the buffer &Ssa_SecLog_NvmAddress[idxBlock].ramBlock[CONTROL_DATA + COUNTER SIZE + writeIndex]
                            provides sufficient memory to log the next event for 0 <= idxBlock < 13.
                          - In other words, the write index is only manipulated within function SecLog_WriteLogEntry().
                            There, the write index is set to a valid value, so that when the write index is evaluated
                            the next time, logging the event is a valid (silent) operation.

    \ID  VCA_SSA_SECLOG_RAM_BLOCK_MIRROR
      \DESCRIPTION      According to VCA, the following assertion may fail:
                          Ssa_SecLog_NvmCtrl_GetWriteIdxMirror(i) <= Ssa_SecLog_NvmCtrl[i].bufferSize,
                        where 0 <= i < 16.                        - 
      \COUNTERMEASURE   \N Ssa_SecLog_NvmCtrl_GetWriteIdxMirror(i) reads the first two bytes of Ssa_SecLog_NvmAddress[idxBlock].ramBlockMirror.
                        Since Ssa_SecLog_NvmAddress[idxBlock].ramBlockMirror contains the same values as Ssa_SecLog_NvmAddress[idxBlock].ramBlock,
                        the assertion holds, if the assertion holds for Ssa_SecLog_NvmAddress[idxBlock].ramBlock. The latter is shown in
                        VCA_SSA_SECLOG_EVENT_LOG_CONCEPT.
                        This justification is only used in function SecLog_FillInSecurityEventLog, which is called in
                        - Ssa_SecLog_DataServices_Security_Event_Log_Current_Counter_Values_ReadData() and
                        - Ssa_SecLog_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData().
                        Before a <Data>_ReadData function is called, the corresponding <Data>_ReadDataLength function must be called
                        (see also VCA_SSA_SECLOG_READ_DATA_LENGTH_FOR_LOG_ENTRY and VCA_SSA_SECLOG_READ_DATA_LENGTH_FOR_LOG_COUNTER_CURRENT_VALUES).
                        Ssa_SecLog_NvmAddress[idxBlock].ramBlock is copied to Ssa_SecLog_NvmAddress[idxBlock].ramBlockMirror
                        in the corresponding <Data>_ReadDataLength functions.
                        
    \ID  VCA_SSA_SECLOG_INCREASE_INDEX_IN_FOR_LOOP
      \DESCRIPTION      According to VCA, one of the following assertions may fail:
                          byteDestIdx <= SECLOG_SIZE_OF_READ_DATA_LENGTH + SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME + 58 + 8 + (i * 8),
                        or
                          byteDestIdx <= SECLOG_SIZE_OF_READ_DATA_LENGTH + SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME + 58 + 8 + (SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS * 8) + ((idxBlock + 1 - SECLOG_EVENT_SECURE_BOOT_OR_AUTHENTICATED_BOOT) * 2).
                        i and idxBlock are incremented within a for loop. idxBlock takes values in the range [10, 12] (including the boundaries).
      \COUNTERMEASURE   \N Before entering the for loop, it was asserted that
                          byteDestIdx <= SECLOG_SIZE_OF_READ_DATA_LENGTH + SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME + 58 + 8,
                        or
                          byteDestIdx <= SECLOG_SIZE_OF_READ_DATA_LENGTH + SECLOG_SIZEOF_TICKCOUNT + SECLOG_SIZEOF_REALTIME + 58 + 8 + (SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS * 8),
                        respectively.
                        Both for loops provide upper bounds for i and idxBlock.

    \ID  VCA_SSA_SECLOG_SUBTRACTION_WITHOUT_UNDERFLOW
      \DESCRIPTION      According to VCA, the following assertion may fail:
                          sizePart1 <= Ssa_SecLog_NvmCtrl[i].bufferSize,
                        where sizePart1 is either 0 or was computed as 
                          sizePart1 = (Ssa_SecLog_NvmCtrl[i].bufferSize - Ssa_SecLog_NvmCtrl_GetWriteIdxMirror(i)),
                        for 0 <= i < 13.
      \COUNTERMEASURE   \N It was asserted (or justified) before that the subraction cannot cause an underflow, since
                        Ssa_SecLog_NvmCtrl_GetWriteIdxMirror(i) <= Ssa_SecLog_NvmCtrl[i].bufferSize.
                        Also, Ssa_SecLog_NvmCtrl_GetWriteIdxMirror(i) >= 0.
                        Thus, the assertion holds.


    VCA_JUSTIFICATION_END */

/* FETA_JUSTIFICATION_BEGIN
  \ID FETA_SSA_SECLOG_MONOTONIC_FOR_LOOP_UP_WITH_UNCHANGED_UPPER_BOUND
    \DESCRIPTION  According to FETA loop may not terminate
                  in functions
                  - SecLog_WriteLogEntry() and
                  - SecLog_InitializeNvRamBlocks().
    \COUNTERMEASURE \N The here applied for loop uses a variable as upper bound that remains unchanged during loop execution.
                       The loop's type of the counter variable is appropriate for the loop's type of upper bound variable and is incremented once
                       within each single loop (strictly monotonically increasing).
FETA_JUSTIFICATION_END */

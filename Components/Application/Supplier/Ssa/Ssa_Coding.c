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
/*!        \file  Ssa_Coding.c
 *        \brief  Variant Coding of the Standard Security Architecture (Ssa).
 *
 *      \details  The Variant Coding provides interfaces to bring in and verify Variant Coding Data.
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
 * Ssa_TrustModelChainState_Type
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * Ssa_VinStoreStateType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * VIN_Status
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
 * CallbackInitMonitorForEvent_DTC_0x164456
 *   Notifies that this event is cleared, or that the operation (monitoring) cycle restarts.
 *      Connect to corresponding event of Dem.
 *
 * CallbackNotification_SigVerify_Coding
 *   Callback notification from the CSM signature verification job used for secure variant coding.
 *      Configuration Variant(s): Asynchronous job processing.
 *
 * Coding_Com_ReceiveVIN
 *   Configuration Variant(s): Not in VSM.
 *
 * Coding_Com_SendVIN
 *   Configuration Variant(s): VSM only.
 *
 * Coding_ReceiveVINTimeout
 *   Configuration Variant(s): Not in VSM.
 *
 * DTC_0x164456
 *   Set a Event Status to failed if coding data does not match the current VIN.
 *      Connect to corresponding event of Dem.
 *
 * DataServices_DID_018E_VIN_Lock_Status
 *   Retrieves the current VIN Lock Status from the ECU.
 *      Connect to corresponding Dcm port.
 *
 * DataServices_DID_018E_VIN_Status
 *   Retrieves the current VIN Status from the ECU.
 *      Connect to corresponding Dcm port.
 *
 * DataServices_DID_0197_Precompile_switch
 *   Retrieves a data field with the status of the precompiled switches from the ECU.
 *      Connect to corresponding Dcm port.
 *
 * DataServices_VINDataIdentifier
 *   Reads and Writes the VIN.
 *      Connect to corresponding Dcm port.
 *
 * Key_SignatureRamKey
 *   Sets the public key of the coding certificate to verify the signature of the coding data.
 *      Connect to a Csm Key which is able to store a public key and is used in the referenced job of the Ssa_Cdd
 *
 * NvM_CodingVIN
 *   Controlling the NvM block which stores the Coding VIN data.
 *      Connect to NvM block storing the Coding VIN.
 *
 * NvM_ControlLink
 *   Controlling the NvM block which stores coding data.
 *      Connect to NvM block storing the coding data. If more than one NvM block is responsible to store coding data use fan-out of Ssa_Cdd instead and configure corresponding NvM block in SSA configuration.
 *
 * NvM_CurrentVIN
 *   Controlling the NvM block which stores Current VIN data.
 *      Connect to NvM block storing the Current VIN.
 *
 * RoutineServices_Routine_Evaluate_Data_Verification_Certificate
 *   Transfer a Signature Verification Key to the ECU, which afterwards will be used for signature verification within software reprogramming or variant coding process. To enable the ECU to validate the Signature Verification Key, the key is transferred within an appropriate certificate.
 *
 * RoutineServices_Routine_Reset_VIN_Values
 *   Resets the currently stored VINDataIdentifier to its default value.
 *
 * RoutineServices_Routine_Verify_Signature
 *   Verifies the integrity and authenticity e.g. of variant coding data using a signature verification.
 *
 * ServiceRequestNotification
 *   Indication of a Dcm service request indication which aims for writing of coding relevant data. If request is coding relevant and coding was started, request data is uses as part of signature verification. If request is coding relevant but coding was not started, request is discarded.
 *      Connect to corresponding Dcm port.
 *
 *
 * Operation Prototypes:
 * =====================
 * KeyElementSet of Port Interface CsmKeyManagement_Ssa_SignatureRamKey
 *   Sets the given key element bytes to the key.
 *
 * KeySetValid of Port Interface CsmKeyManagement_Ssa_SignatureRamKey
 *   Sets the given key element bytes to the key.
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
 * Ssa_Coding_CsmCallbackNotification_SigVerify_Coding
 *   Configuration Variant(s): Asynchronous job processing.
 *
 * Ssa_Coding_VIN_Receive
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_Coding_VIN_Receive_Timeout
 *   Configuration Variant(s): Not in VSM.
 *
 *
 * Exclusive Areas:
 * ================
 * Coding_ExclusiveArea_VIN
 *   This Exclusive area is entered whenever the stored VIN or its attributes are accessed (read or written)
 *
 *********************************************************************************************************************/

#include "Rte_Ssa_Coding.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Includes */
#include "Ssa.h"
#include "Ssa_Cfg.h"
#include "Ssa_Utils.h"

#ifdef __VCA__  /* COV_SSA_VECTOR_CODE_ANALYZER_STUB_REDIRECTION */
# include "Ssa_Coding_Redirection.vcaspecs.h"
#endif

/* After this comment only memory mapping files may be included. Due to this turn off lint rule requesting a standard
include guard. */
/*lint -e451 */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
#if (  (SSA_SW_MAJOR_VERSION != (3u)) \
    || (SSA_SW_MINOR_VERSION != (2u)) \
    || (SSA_SW_PATCH_VERSION != (30u)))
# error "Version numbers of Ssa_Coding.c and Ssa.h are inconsistent"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SSA_CODING_LOCAL)                 /* COV_SSA_LOCAL */
# define SSA_CODING_LOCAL                                             static
#endif

#if !defined (SSA_CODING_LOCAL_INLINE)          /* COV_SSA_LOCAL_INLINE */
# define SSA_CODING_LOCAL_INLINE                                      LOCAL_INLINE
#endif

#if !defined (Ssa_MemCpy)                   /* COV_SSA_MEMCPY */
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
# define Ssa_MemCpy(destination, source, num)                         Ssa_Utils_MemCpy(destination, source, num)
#endif

/*! Calibration identification. */
#define CODING_CALID                                                  (0xF804u)

/*! The coding states. */
#define CODING_STATE_FREE                                             (0u)
#define CODING_STATE_ERROR                                            (1u)
#define CODING_STATE_WAIT_FOR_NVM                                     (2u)
#define CODING_STATE_WRITE_TO_NVM                                     (3u)
#define CODING_STATE_READ_FROM_NVM                                    (4u)
#define CODING_STATE_SUCCESSFUL                                       (5u)
#define CODING_STATE_FAILED                                           (6u)
#define CODING_TIMEOUT_OFFSET                                         (10u)
/*! Coding timeout period of 20s as a multiple of 10ms. */
#define CODING_TIMEOUT                                                (CODING_TIMEOUT_OFFSET + (SSA_CODING_TIMEOUT / 10u))
/*! VIN receive timeout period as a multiple of 10ms. */
#define CODING_VIN_RECEIVE_TIMEOUT                                    (SSA_CODING_VINRECEIVE_TIMEOUT / 10u)

/*! Origin of change request for the VIN. */
#define CODING_VIN_CHANGE_BC                                          (0u)  /**< Broadcast. */
#define CODING_VIN_CHANGE_DCM                                         (1u)  /**< Diagnostic service request. */
#define CODING_VIN_CHANGE_SET                                         (2u)  /**< By API call. */

/*! Time period for broadcasting the VIN (1000 ms / 10 ms - 1). */
#define CODING_SEND_VIN_MAINFUNCTIONS                                 (99u)

/*! VIN attributes. */
#define CODING_ATTRIBUTEMASK_LOCKED                                   (0x10u)
#define CODING_ATTRIBUTEMASK_STORED_VIN_IS_NOT_DEFAULT_VALUE          (0x40u)

/*! Coding WriteData states. */
#define CODING_WRITEDATA_STATE_IDLE                                   (0u)    /**< Idle, wait for nothing */
#define CODING_WRITEDATA_STATE_WRITEBYDID                             (1u)    /**< Wait for WriteByDID only */
#define CODING_WRITEDATA_STATE_WRITEBYDID_OR_CALID                    (2u)    /**< Wait for CALID or WriteByDID */
#define CODING_WRITEDATA_STATE_CALID_RECEIVED                         (3u)    /**< CALID has been received but verification update not yet finished. */
#define CODING_WRITEDATA_STATE_VERIF_FINISH                           (4u)    /**< Wait for verification */

/*! States for asynchronous CSM call handling. */
#define SSA_CODING_ASYNC_STATE_IDLE                                   (0x00u)
#define SSA_CODING_ASYNC_STATE_INIT                                   (0x01u)
#define SSA_CODING_ASYNC_STATE_WAIT                                   (0x02u)
#define SSA_CODING_ASYNC_STATE_READY                                  (0x03u)
#define SSA_CODING_ASYNC_STATE_FAILED                                 (0x04u)
#define SSA_CODING_ASYNC_STATE_WAIT_NVM                               (0x05u)
#define SSA_CODING_ASYNC_STATE_ROLLBACK_WAIT                          (0x06u)
#define SSA_CODING_ASYNC_STATE_CODINGVIN_NVM_WRITE                    (0x07u)
#define SSA_CODING_ASYNC_STATE_CODINGVIN_NVM_WAIT                     (0x08u)

/*! States use for asynchronous handling in routine service Evaluate_Data_Verification_Certificate_Start. */
#define CODING_VERIFY_CERT_STATE_IDLE                                 (0u)
#define CODING_VERIFY_CERT_STATE_VERIFY_CERT                          (1u)
#define CODING_VERIFY_CERT_STATE_VERIFY_DATA                          (2u)

/* Routine Controls: Values for Verification_Result parameter */
#define CODING_RC_EVALCERT_RES_CERTIFICATE_VERIFIED_SIGNATURE_VERIFICATION_KEY_ACCEPTED (0x00u)
#define CODING_RC_EVALCERT_RES_INVALID_TIME_PERIOD                    (0x10u)
#define CODING_RC_EVALCERT_RES_INVALID_SIGNATURE                      (0x11u)
#define CODING_RC_EVALCERT_RES_INVALID_CHAIN_OF_TRUST                 (0x12u)
#define CODING_RC_EVALCERT_RES_INVALID_TYPE                           (0x13u)
#define CODING_RC_EVALCERT_RES_INVALID_FORMAT                         (0x14u)
#define CODING_RC_EVALCERT_RES_INVALID_CONTENT                        (0x15u)
#define CODING_RC_EVALCERT_RES_INVALID_SCOPE                          (0x16u)

#define CODING_RC_VERIFYSIG_RES_SIGNATURE_VERIFICATION_SUCCESSFUL     (0x00u)
#define CODING_RC_VERIFYSIG_RES_INVALID_SIGNATURE                     (0x10u)
#define CODING_RC_VERIFYSIG_RES_NO_SIGNATURE_VERIFICATION_KEY_AVAILABLE (0x11u)

/*! Coding NVM Write states. */
#define CODING_NVM_WRITE_STATE_IDLE                                   (0u)
#define CODING_NVM_WRITE_STATE_START                                  (1u)
#define CODING_NVM_WRITE_STATE_PENDING                                (2u)
#define CODING_NVM_WRITE_STATE_FAILURE                                (3u)

/*! Coding VIN State Process Types */
#define SSA_VIN_STATE_SET                                             (0u)
#define SSA_VIN_STATE_UPDATE                                          (1u)

/*! Coding */
/* VIN Lock Status coded according the diagnostic template:
 *  VIN unlocked = 0x00
 *  VIN locked   = 0x01 */
#define CODING_DID_018E_VIN_LOCK_STATUS_UNLOCKED                      (0x00u)
#define CODING_DID_018E_VIN_LOCK_STATUS_LOCKED                        (0x01u)

/* VIN Status coded according the diagnostic template (which is different from the VIN Status propagated via the application interface Coding_VinStatus) :
 *  VIN correct received = 0x00
 *  New VIN received     = 0x01
 *  VIN not received     = 0x02 */
#define CODING_DID_018E_VIN_STATUS_VIN_CORRECT_RECEIVED               (0x00u)
#define CODING_DID_018E_VIN_STATUS_NEW_VIN_RECEIVED                   (0x01u)
#define CODING_DID_018E_VIN_STATUS_VIN_NOT_RECEIVED                   (0x02u)

/*! Checks if an attribute is set. */
/* PRQA S 3453 3 */ /* MD_MSR_FctLikeMacro */
#define Coding_IsAttributeSet(mask)                                   ((Rte_Pim_CurrentVIN()->attributes & (mask)) == (mask))
#define Coding_ClearAttribute(mask)                                   (Rte_Pim_CurrentVIN()->attributes = (uint8)(Rte_Pim_CurrentVIN()->attributes & (~mask)))
#define Coding_SetAttribute(mask)                                     (Rte_Pim_CurrentVIN()->attributes = (uint8)(Rte_Pim_CurrentVIN()->attributes | mask))

/*! Checks if VIN is locked. */
#define Coding_IsVinLocked()                                          Coding_IsAttributeSet(CODING_ATTRIBUTEMASK_LOCKED)
/*! Checks if the stored VIN is not the default VIN. */
#define Coding_IsVinNotDefault()                                      Coding_IsAttributeSet(CODING_ATTRIBUTEMASK_STORED_VIN_IS_NOT_DEFAULT_VALUE)


/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
#define Read_Coding_Timeout()                                         (Coding_Timeout)
#define Write_Coding_Timeout(data)                                    (Coding_Timeout = (data))
#define Decrement_Coding_Timeout()                                    (Coding_Timeout--)
/* PRQA L:L1 */

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
# define Read_Coding_VinSendTimer()                                   (Coding_VinSendTimer)
# define Write_Coding_VinSendTimer(data)                              (Coding_VinSendTimer = (data))
# define Increment_Coding_VinSendTimer()                              (Coding_VinSendTimer++)
/* PRQA L:L1 */
#else
/* PRQA S 3453 L1 */ /* MD_MSR_FctLikeMacro */
# define Get_Coding_VinReceiveTimeout_Counter()                       (Coding_VinReceiveTimeout_Counter)
# define Set_Coding_VinReceiveTimeout_Counter(data)                   (Coding_VinReceiveTimeout_Counter = (data))
# define Decrement_Coding_VinReceiveTimeout_Counter()                 (Coding_VinReceiveTimeout_Counter--)
# define Delete_Coding_Vin_ReceiveTimeout_Counter()                   (Set_Coding_VinReceiveTimeout_Counter(0u))
/* PRQA L:L1 */
#endif

/**********************************************************************************************************************
*  LOCAL FUNCTION MACROS
*********************************************************************************************************************/
/*! Sets single bit of a byte */
#define Coding_OpSetBit(byte, bit)                                    (byte |= (1u << bit))          /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Clears single bits in a byte */
#define Coding_OpClearBit(byte, bit)                                  (byte &= ~(1u << bit))         /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* The following compile time assertions ensure the sizes of data types used within the Coding submodule
 * when calling RTE APIs expecting these data types. 
 * The assertions ensure that the size of these data types is consistent with respective buffer lengths defined in the Ssa.
 * For ASIL-D, the vector code analyzer checks the same conditions within the Coding_Init() function. */
/* PRQA S 3205, 3493 2 */ /* MD_SSA_COMPILE_TIME_ASSERTION */
Ssa_CompileTimeAssert(sizeof(Coding_VINDataType) == 17u, InvalidSizeOf_Coding_VINDataType); /*lint !e506 */
Ssa_CompileTimeAssert(SSA_SIZEOF_VIN == 17u, InvalidSizeOf_VIN); /*lint !e506 */

#if (SSA_CODINGDID == STD_ON)
/*! Definition of a buffer type for the coding data. */
typedef uint8 Coding_DataBufferType[SSA_CODING_DATA_BUFFER_SIZE];
#endif

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
#define Ssa_Coding_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Ssa_Coding_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! */
SSA_CODING_LOCAL VAR(VIN_Status, Ssa_Coding_VAR_NOINIT) Coding_VIN_State;
/*! Coding state variable and counter for the coding timeout.
 *  All values greater than CODING_TIMEOUT_OFFSET mean that Coding sequence is ongoing and not yet timed out. */
SSA_CODING_LOCAL VAR(uint16, Ssa_Coding_VAR_NOINIT) Coding_Timeout;

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
SSA_CODING_LOCAL VAR(uint8, Ssa_Coding_VAR_NOINIT) Coding_VinSendTimer;
#else
SSA_CODING_LOCAL VAR(uint16, Ssa_Coding_VAR_NOINIT) Coding_VinReceiveTimeout_Counter;
#endif
/*! The write data state of variant coding. */
SSA_CODING_LOCAL VAR(uint8, Ssa_Coding_VAR_NOINIT) Coding_WriteDataState;
/*! The current diagnostic channel id. */
SSA_CODING_LOCAL VAR(uint8, Ssa_Coding_VAR_NOINIT)  Coding_CurrentDiagChanId;
/*! The last diagnostic channel id. */
SSA_CODING_LOCAL VAR(uint8, Ssa_Coding_VAR_NOINIT)  Coding_LastDiagChanId;

/*! State variable used in routine service Evaluate_Data_Verification_Certificate. */
SSA_CODING_LOCAL VAR(uint8, Ssa_Coding_VAR_NOINIT) Coding_EvalDataVerifyCertState;
/* Storages. */
SSA_CODING_LOCAL VAR(Coding_VINDataType, Ssa_Coding_VAR_NOINIT) Coding_Vin;
#if (SSA_KEEP_BUFFER_VARIABLES_STATIC == STD_ON)
SSA_CODING_LOCAL VAR(CertP_ParsedCertStructureType, Ssa_Coding_VAR_NOINIT) Coding_ParsedCertificate;  /* PRQA S 3218 */ /* MD_SSA_OBJECT_AT_FILE_SCOPE */
#endif

SSA_CODING_LOCAL VAR(CertP_PkiRoleType, Ssa_Coding_VAR_NOINIT) Coding_PkiRole;

/*! State variable used in sub function Coding_SignatureVerify_OpModeStreamStart. */
SSA_CODING_LOCAL VAR(uint8, Ssa_Coding_VAR_NOINIT) Coding_SigVerifyStartState;

/*! State variable used in routine service Verify_Signature_Start. */
SSA_CODING_LOCAL VAR(uint8, Ssa_Coding_VAR_NOINIT) Coding_SigVerifyFinishState;
/* Storages. */
SSA_CODING_LOCAL uint8 Coding_VerifySignatureVerificationResult;
SSA_CODING_LOCAL uint8 Coding_VerifySignatureErrorCode;
SSA_CODING_LOCAL uint8 Coding_EvalCertVerificationResult;
SSA_CODING_LOCAL Crypto_VerifyResultType Coding_VerifyResult;

#if (SSA_CODINGDID == STD_ON)
/*! State variable used in sub function Coding_SignatureVerifyUpdate. */
SSA_CODING_LOCAL VAR(uint8, Ssa_Coding_VAR_NOINIT) Coding_SigVerifyUpdateState;

/*! Huge storage used in Ssa_Coding_ServiceRequestNotification_Indication where the coding are copied to and then asynchronously processed. */
SSA_CODING_LOCAL Coding_DataBufferType Coding_DataBuffer;   /* PRQA S 3218 */ /* MD_SSA_OBJECT_AT_FILE_SCOPE */
#endif

/*! Indicating if writing the CurrentVIN NVRam block has been requested. */
SSA_CODING_LOCAL VAR(boolean, Ssa_Coding_VAR_NOINIT) Coding_CurrentVinNvmWriteRequested;
/*! The state of writing the CurrentVIN NVRam block. */
SSA_CODING_LOCAL VAR(uint8, Ssa_Coding_VAR_NOINIT) Coding_CurrentVinNvmWriteState;

/*! Cancel request counter used for repeated trying to cancel the signature verification of the variant coding. */
SSA_CODING_LOCAL VAR(uint8, Ssa_Coding_VAR_NOINIT) Coding_CancelSigVerify;

#define Ssa_Coding_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Ssa_Coding_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define Ssa_Coding_START_SEC_CODE
#include "Ssa_Coding_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Coding_PerformNvM()
 *********************************************************************************************************************/
/*!
 * \brief       Performs NVM services depending on the coding state.
 * \details     -
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_CODING_LOCAL FUNC(void, Ssa_Coding_CODE) Coding_PerformNvM(void);

/**********************************************************************************************************************
 * Coding_Abort()
 *********************************************************************************************************************/
/*!
 * \brief       Aborts a coding sequence.
 * \details     -
 * \param[in]   cancel    If TRUE try to cancel signature verification.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_CODING_LOCAL FUNC(void, Ssa_Coding_CODE) Coding_Abort(boolean cancel);

#if (SSA_CODINGDID == STD_ON)
/**********************************************************************************************************************
 * Coding_SignatureVerifyUpdate()
 *********************************************************************************************************************/
/*!
 * \brief       Updates the secure variant coding signature verification.
 * \details     This function checks that this WriteData service hasn't been executed before in this coding sequence
 *              and updates the secure variant coding signature verification.
 * \param[in]   didIdx       The identifier of the WriteData service.
 * \param[in]   RequestData  Memory location of the data to be verified.
 * \param[in]   DataSize     Size of the data to be verified.
 * \param[out]  ErrorCode    Negative response code to be sent by DCM if return value is E_NOT_OK.
 * \return      RTE_E_OK                                   Signature verification has been updated successfully.
 * \return      RTE_E_ServiceRequestNotification_E_NOT_OK  Error occurred.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_SignatureVerifyUpdate(uint16 didIdx, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) RequestData, uint16 DataSize, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode);

/**********************************************************************************************************************
 * Coding_MarkReceived()
 *********************************************************************************************************************/
/*!
 * \brief       Checks if a DID is marked as received and marks it as received if not.
 * \details     -
 * \param[in]   didIdx   The identifier of the WriteData service.
 * \return      TRUE   Not yet marked.
 * \return      FALSE  Already marked.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_CODING_LOCAL_INLINE FUNC(boolean, Ssa_Coding_CODE) Coding_MarkReceived(uint16 didIdx);
#endif

/**********************************************************************************************************************
 * Coding_ChangeVin()
 *********************************************************************************************************************/
/*!
 * \brief       Processes a received VIN.
 * \details     This function changes depending on origin and on the VIN state the stored VIN.
 * \param[in]   vin    Memory location where the new VIN is stored.
 * \param[in]   origin Origin of the VIN.
 * \return      E_OK                             New VIN has been processed.
 * \return      RTE_E_Coding_VINControl_E_NOT_OK VIN is locked and could not be change.
 * \pre         vin must be a valid pointer, the length of a VIN is expected to be SSA_SIZEOF_VIN bytes.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ChangeVin(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) vin, uint8 origin);

/**********************************************************************************************************************
 * Coding_CompareVIN()
 *********************************************************************************************************************/
/*!
 * \brief       Compares two VINs.
 * \details     -
 * \param[in]   vin1   Pointer to the memory location where the first VIN is stored.
 * \param[in]   vin2   Pointer to the memory location where the second VIN is stored.
 * \return      TRUE   VINs are identical.
 * \return      FALSE  VINs are not identical.
 * \pre         All provided pointers must be valid, the length of a VIN is expected to be SSA_SIZEOF_VIN bytes.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_CODING_LOCAL FUNC(boolean, Ssa_Coding_CODE) Coding_CompareVIN(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) vin1, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) vin2);

/**********************************************************************************************************************
 * Coding_ProcessVinState()
 *********************************************************************************************************************/
/*!
 * \brief       Sets and processes the new VIN state.
 * \details     -
 * \param[in]   newVinState       The new VIN state.
 * \param[in]   vinStateProcType  The VIN state process type: set or update VIN state and DTC  0x164456. An update sets
 *                                the DTC 0x164456 only if the new VIN state is different from the current state.
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_CODING_LOCAL FUNC(void, Ssa_Coding_CODE)  Coding_ProcessVinState(VIN_Status newVinState, uint8 vinStateProcType);

/**********************************************************************************************************************
 * Coding_SignatureVerify_OpModeStreamStart()
 *********************************************************************************************************************/
/*!
 * \brief       Starts the secure variant coding signature verification.
 * \details     Starts the secure variant coding signature verification after parsing and verify the passed data verification certificate.
 * \return      E_OK            Signature verification successfully started.
 * \return      E_NOT_OK        Error occurred. Signature verification not started.
 * \return      SSA_E_PENDING   Requested service is pending.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous FALSE
 */
SSA_CODING_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_SignatureVerify_OpModeStreamStart(void);

/**********************************************************************************************************************
 * Coding_HandleCodingTimeoutAndCancelation()
 *********************************************************************************************************************/
/*!
 * \brief       Handles the coding timeout and the cancellation of the signature verification.
 * \details     Handles the coding timeout. It aborts the coding sequence when the a timeout occurs. Furthermore it
 *              retries to cancel the signature verification if it previously failed.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_CODING_LOCAL_INLINE FUNC(void, Ssa_Coding_CODE) Coding_HandleCodingTimeoutAndCancelation(void);

/**********************************************************************************************************************
 * Coding_HandleNVM()
 *********************************************************************************************************************/
/*!
 * \brief       Handles NVM.
 * \details     This function handles the writing of the Coding VIN RAM block to the NVM.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_CODING_LOCAL_INLINE FUNC(void, Ssa_Coding_CODE) Coding_HandleNVM(void);

/**********************************************************************************************************************
 * Coding_CheckAndParseCodingCert()
 *********************************************************************************************************************/
/*!
 * \brief       Checks and parses the data verification certificate.
 * \details     -
 * \param[in]   Data_Verification_Certificate Input buffer containing the data verification certificate.
 * \param[out]  Verification_Result           Positive response code
 * \param[in]   DataLength                    Data length of input buffer.
 * \param[out]  parsedCertStructure           The parsed certificate data.
 * \param[out]  ErrorCode                     Negative response code.
 * \return      E_OK      Request succeeded.
 *              E_NOT_OK  Request failed.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_CODING_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_CheckAndParseCodingCert(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Data_Verification_Certificate,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Verification_Result,
  uint16 DataLength,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedCertStructure,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode);

/**********************************************************************************************************************
 * Coding_PrepareSignatureVerification()
 *********************************************************************************************************************/
/*!
 * \brief       Prepares the signature verification.
 * \details     -
 * \param[in]   verificationKey        The public key to be used for the signature verification.
 * \param[in]   verificationKeyLength  Length of the public key.
 * \return      E_OK      Request succeeded.
 *              E_NOT_OK  Request failed.
 * \pre         verificationKey must be a valid pointer.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_CODING_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_PrepareSignatureVerification(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) verificationKey,
  uint16 verificationKeyLength);

/**********************************************************************************************************************
 * Coding_VerifySignature_HandleStatesOpStatusPending()
 *********************************************************************************************************************/
/*!
 * \brief       Handles states of routine VerifySignature that are only run through for operation status DCM_PENDING.
 * \details     -
 * \param[out]  returnValue Buffer for the return value.
 * \return      TRUE  State handling is done. Do not call Coding_VerifySignature_HandleStates() afterwards.
 *              FALSE State handling is not done. Do call Coding_VerifySignature_HandleStates() afterwards.
 * \pre         returnValue must be a valid pointer.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_CODING_LOCAL FUNC(boolean, Ssa_Coding_CODE) Coding_VerifySignature_HandleStatesOpStatusPending(P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) returnValue);

/**********************************************************************************************************************
 * Coding_VerifySignature_HandleStates()
 *********************************************************************************************************************/
/*!
 * \brief       Handles states of routine VerifySignature.
 * \details     -
 * \param[in]   Signature_Value Holds a pointer to the signature to be used for verification.
 * \return      RTE_E_OK                                                      Request succeeded.
 *              RTE_E_RoutineServices_Routine_Verify_Signature_E_NOT_OK       Request failed.
 *              RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING  Request pending.
 * \pre         Signature_Value must be a valid pointer.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_VerifySignature_HandleStates(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Signature_Value);

/**********************************************************************************************************************
 * Coding_CheckCharactersOfVIN()
 *********************************************************************************************************************/
/*!
 * \brief       Checks the characters of a given VIN for printable ASCII values.
 * \details     -
 * \param[in]   vin    Pointer to the memory location where the VIN to be checked is stored.
 *                     The length of a VIN is expected to be 17 bytes.
 * \return      TRUE   VIN exclusively consists of printable ASCII values.
 * \return      FALSE  VIN does not exclusively consist of printable ASCII values.
 * \pre         vin must be a valid pointer, the length of a VIN is expected to be SSA_SIZEOF_VIN bytes.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_CODING_LOCAL FUNC(boolean, Ssa_Coding_CODE) Coding_CheckCharactersOfVIN(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) vin);

#if((SSA_ECU_TYPE == SSA_ECU_TYPE_NORMAL) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
/**********************************************************************************************************************
* Coding_Restart_VinReceiveTimeout_Counter()
*********************************************************************************************************************/
/*!
* \brief       Restarts the VinReceiveTimeout counter
* \details     -
* \pre         -
* \context     TASK
* \reentrant   TRUE
* \synchronous TRUE
*/
SSA_CODING_LOCAL FUNC(void, Ssa_Coding_CODE) Coding_Restart_VinReceiveTimeout_Counter(void);
#endif

#if (SSA_CODINGDID == STD_ON)
/**********************************************************************************************************************
 * Coding_ServiceRequestNotification_Indication_HandleDid()
 *********************************************************************************************************************/
 /*!
  * \brief       Writing of coding relevant data for Dcm service request notification.
  * \details     This function assumes that the request is coding relevant. It checks whether coding was started.
  *              If so, the request data is used as part of signature verification.
  *              If coding was not started, the request is discarded.
  * \param[in]   did                                        currently handled DID (for which secure coding is required)
  * \param[in]   idx                                        index of the currently handled did among all configured DIDs
  * \param[in]   RequestData                                Pointer to the whole data of the current request
  * \param[in]   DataSize                                   Length of RequestData in bytes.
  * \param[out]  ErrorCode                                  Negative response code to be sent by DCM if return value is
  *                                                         not E_OK.
  * \return      RTE_E_OK                                   if no coding request or coding request valid.
  *              RTE_E_ServiceRequestNotification_E_NOT_OK  otherwise.
  * \pre         All provided pointers must be valid.
  * \context     ANY
  * \reentrant   FALSE
  * \synchronous TRUE
  */
SSA_CODING_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ServiceRequestNotification_Indication_HandleDid(uint16 did, uint16 idx, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) RequestData, uint16 DataSize, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode);
#endif /* (SSA_CODINGDID == STD_ON) */

/**********************************************************************************************************************
 * Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateIdle()
 *********************************************************************************************************************/
 /*!
  * \brief       Handles IDLE state during verification phase of write request.
  * \details     This function is called from Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start
  *              to handle the IDLE state of Coding_EvalDataVerifyCertState. If finally parsing the certificate was
  *              successful, Coding_EvalDataVerifyCertState is proceeded to state VERIFY_CERT.
  * \param[in]   Data_Verification_Certificate              Holds a pointer to the certificate to be used for verification.
  * \param[in]   DataLength                                 Length of certificates stored in Data_Verification_Certificate.
  * \param[out]  parsedCertStructure                        The parsed certificate data.
  * \param[out]  ErrorCode                                  Negative response code to be sent by DCM if return value is
  *                                                         not E_OK.
  * \return      RTE_E_OK                                   if routine and called sub routines could be successfully executed.
  *              RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_PENDING if requested service is pending.
  *              RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK  if an error occurred.
  * \pre         All provided pointers must be valid.
  * \context     ANY
  * \reentrant   FALSE
  * \synchronous TRUE
  */
SSA_CODING_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateIdle(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Data_Verification_Certificate,
  uint16 DataLength,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedCertStructure,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode);

/**********************************************************************************************************************
 * Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateVerifyCert()
 *********************************************************************************************************************/
 /*!
  * \brief       Handles VERIFY_CERT state during verification phase of write request, i.e., the certificate
  *              containing the public key is verified against the backend certificate.
  * \details     This function is called from Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start
  *              to handle the VERIFY_CERT state of Coding_EvalDataVerifyCertState. If certificate verification and
  *              preparation of signature verification was successful, Coding_EvalDataVerifyCertState is proceeded
  *              to state VERIFY_DATA. If the verification of preparation step failed, the state
  *              is reset to IDLE.
  * \param[in]   Data_Verification_Certificate   Holds a pointer to the certificate to be used for verification
  *                                              Must reference a buffer of at least sizeof(Dcm_Data2002ByteType) many bytes.
  * \param[in]   prevRetVal                      Previous return value of 
  *                                              Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start,
  *                                              before Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateVerifyCert
  *                                              was called.
  * \param[out]  parsedCertStructure             The parsed certificate data.
  * \param[out]  ErrorCode                       Negative response code to be sent by DCM if return value is
  *                                              not E_OK.
  * \return      RTE_E_OK                        if routine and called sub routines could be successfully executed.
  *              RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_PENDING if requested service is pending.
  *              RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK  if an error occurred.
  * \pre         All provided pointers must be valid.
  * \context     ANY
  * \reentrant   FALSE
  * \synchronous TRUE
  * \spec        $lengthOf(Data_Verification_Certificate) >= sizeof(Dcm_Data2002ByteType);                     \endspec
  */
SSA_CODING_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateVerifyCert(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Data_Verification_Certificate,
  const Std_ReturnType prevRetVal,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedCertStructure,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode);

/**********************************************************************************************************************
 * Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateVerifyData()
 *********************************************************************************************************************/
 /*!
  * \brief       Handles VERIFY_CERT state during verification phase of write request.
  * \details     This function is called from Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start
  *              to handle the VERIFY_DATA state of Coding_EvalDataVerifyCertState, i.e., the data signature
  *              verification is started in streaming mode. Coding_EvalDataVerifyCertState is reset to IDLE,
  *              if starting the signature verification does not return PENDING.
  * \param[in]   prevRetVal                                 Previous return value of 
  *                                                         Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start, before 
  *                                                         Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateVerifyData was called.
  * \param[out]  ErrorCode                                  Negative response code to be sent by DCM if return value is
  *                                                         not E_OK.
  * \return      RTE_E_OK                                   if routine and called sub routines could be successfully executed.
  *              RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_PENDING if requested service is pending.
  *              RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK  if an error occurred.
  * \pre         ErrorCode must be a valid pointer.
  * \context     ANY
  * \reentrant   FALSE
  * \synchronous TRUE
  */
SSA_CODING_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateVerifyData(const Std_ReturnType prevRetVal, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode);

#define Ssa_Coding_STOP_SEC_CODE
#include "Ssa_Coding_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
 * Ssa_VerifyResultPtr: DataReference
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * dtRef_const_VOID: DataReference
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
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
 * Ssa_TrustModelChainState_Type: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_TRUSTMODELCHAINSTATE_INITIAL (0U)
 *   SSA_TRUSTMODELCHAINSTATE_ROOT_INJECTED (1U)
 *   SSA_TRUSTMODELCHAINSTATE_FULLY_INJECTED (2U)
 * Ssa_VinStoreStateType: Enumeration of integer in interval [0...255] with enumerators
 *   SSA_VIN_CTRLSTAT_OK (0U)
 *   SSA_VIN_CTRLSTAT_PENDING (1U)
 *   SSA_VIN_CTRLSTAT_FAILED (2U)
 * VIN_Status: Enumeration of integer in interval [0...255] with enumerators
 *   VIN_STATUS_NEW_VIN_RECEIVED (0U)
 *   VIN_STATUS_VIN_CORRECT_RECEIVED (1U)
 *   VIN_STATUS_VIN_NOT_RECEIVED (2U)
 *
 * Array Types:
 * ============
 * CertP_RawCertBufferType: Array with 910 element(s) of type uint8
 * Coding_VINDataType: Array with 17 element(s) of type uint8
 * Csm_KeyDataType_Ssa_SignatureRamKey: Array with 32 element(s) of type uint8
 * Dcm_Data17ByteType: Array with 17 element(s) of type uint8
 * Dcm_Data1ByteType: Array with 1 element(s) of type uint8
 * Dcm_Data2002ByteType: Array with 2002 element(s) of type uint8
 * Dcm_Data4ByteType: Array with 4 element(s) of type uint8
 * Dcm_Data64ByteType: Array with 64 element(s) of type uint8
 * Dcm_SsaDslBufferType: Array with 8195 element(s) of type uint8
 * SecLog_VinType: Array with 17 element(s) of type uint8
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
 * Coding_StorageType: Record with elements
 *   VIN of type Coding_VINDataType
 *   attributes of type uint8
 * RightsM_AuthNonceType: Record with elements
 *   data of type Ssa_Data32ByteType
 *   validated of type boolean
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
 *   Coding_StorageType *Rte_Pim_CodingVIN(void)
 *   Coding_StorageType *Rte_Pim_CodingVINMirror(void)
 *   Coding_StorageType *Rte_Pim_CurrentVIN(void)
 *   Coding_StorageType *Rte_Pim_CurrentVINMirror(void)
 *
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   Coding_StorageType *Rte_CData_Coding_Storage_DefaultValue(void)
 *
 *********************************************************************************************************************/


#define Ssa_Coding_START_SEC_CODE
#include "Ssa_Coding_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_CsmCallbackNotification_SigVerify_Coding
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CallbackNotification> of PortPrototype <CallbackNotification_SigVerify_Coding>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void Ssa_Coding_CsmCallbackNotification_SigVerify_Coding(Csm_ResultType result)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_CsmCallbackNotification_SigVerify_Coding_doc
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

FUNC(void, Ssa_Coding_CODE) Ssa_Coding_CsmCallbackNotification_SigVerify_Coding(Csm_ResultType result) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_CsmCallbackNotification_SigVerify_Coding
 *********************************************************************************************************************/

  /* #40 Handle the Coding_WriteDataState. */
  switch (Coding_WriteDataState) {
  case CODING_WRITEDATA_STATE_IDLE:
    /* #50 In Coding_WriteDataState "idle" handle Coding_SigVerifyStartState. */
    if (Coding_SigVerifyStartState == SSA_CODING_ASYNC_STATE_WAIT)
    {
      Coding_SigVerifyStartState = (result == E_OK) ? SSA_CODING_ASYNC_STATE_READY : SSA_CODING_ASYNC_STATE_FAILED;
    }
    break;

# if (SSA_CODINGDID == STD_ON)

  case CODING_WRITEDATA_STATE_WRITEBYDID:
  case CODING_WRITEDATA_STATE_WRITEBYDID_OR_CALID:
    /* #60 In Coding_WriteDataState "WriteByDid or WriteByDidOrCalId" handle Coding_SigVerifyUpdateState. */
    if (Coding_SigVerifyUpdateState == SSA_CODING_ASYNC_STATE_WAIT)
    {
      if (result == E_OK)
      {
        Coding_SigVerifyUpdateState = SSA_CODING_ASYNC_STATE_IDLE;
        Coding_WriteDataState = CODING_WRITEDATA_STATE_WRITEBYDID_OR_CALID;
      }
      else
      {
        /* Set the general coding state to FAILED. */
        Write_Coding_Timeout(CODING_STATE_FAILED);
      }
    }
    break;

  case CODING_WRITEDATA_STATE_CALID_RECEIVED:
    /* #70 In Coding_WriteDataState "CalId received" handle Coding_SigVerifyUpdateState. */
    if (Coding_SigVerifyUpdateState == SSA_CODING_ASYNC_STATE_WAIT)
    {
      if (result == E_OK)
      {
        Coding_SigVerifyUpdateState = SSA_CODING_ASYNC_STATE_IDLE;
        Coding_WriteDataState = CODING_WRITEDATA_STATE_VERIF_FINISH;
      }
      else
      {
        /* Set the general coding state to FAILED. */
        Write_Coding_Timeout(CODING_STATE_FAILED);
      }
    }
    break;

# endif

  case CODING_WRITEDATA_STATE_VERIF_FINISH:
    /* #80 In Coding_WriteDataState "finish" handle Coding_SigVerifyFinishState. */
    if (Coding_SigVerifyFinishState == SSA_CODING_ASYNC_STATE_WAIT)
    {
      Coding_SigVerifyFinishState = (result == E_OK) ? SSA_CODING_ASYNC_STATE_READY : SSA_CODING_ASYNC_STATE_FAILED;
    }
    break;

  default:
    /* No action. */
    break;
  }
  /* PRQA S 6030 4 */ /* MD_MSR_STCYC */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_018E_VIN_Lock_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_018E_VIN_Lock_Status_DCM_E_PENDING
 *   RTE_E_DataServices_DID_018E_VIN_Lock_Status_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_018E_VIN_Lock_Status_E_NOT_OK;

 /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    *ErrorCode = DCM_E_POSITIVERESPONSE;
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  /* #10 Return successfully, if input is not a null pointer. */
  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_018E_VIN_Lock_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_018E_VIN_Lock_Status_DCM_E_PENDING
 *   RTE_E_DataServices_DID_018E_VIN_Lock_Status_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ReadData_doc
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

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_018E_VIN_Lock_Status_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_018E_VIN_Lock_Status_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Read the VIN Lock Status and passes it to the output buffer. Code it according to the diagnostic template. */
    *Data = Coding_IsVinLocked() ? CODING_DID_018E_VIN_LOCK_STATUS_LOCKED : CODING_DID_018E_VIN_LOCK_STATUS_UNLOCKED;
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_DataServices_DID_018E_VIN_Status_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_018E_VIN_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_DataServices_DID_018E_VIN_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_018E_VIN_Status_DCM_E_PENDING
 *   RTE_E_DataServices_DID_018E_VIN_Status_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_018E_VIN_Status_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_018E_VIN_Status_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_018E_VIN_Status_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_018E_VIN_Status_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    *ErrorCode = DCM_E_POSITIVERESPONSE;
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  /* #10 Return successfully, if input is not a null pointer. */
  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_DataServices_DID_018E_VIN_Status_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_018E_VIN_Status>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_DataServices_DID_018E_VIN_Status_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_018E_VIN_Status_DCM_E_PENDING
 *   RTE_E_DataServices_DID_018E_VIN_Status_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_018E_VIN_Status_ReadData_doc
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

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_018E_VIN_Status_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_018E_VIN_Status_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_018E_VIN_Status_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Read the VIN Status and passes it to the output buffer. Code it according to the diagnostic template. */
    switch (Coding_VIN_State)
    {
    case VIN_STATUS_VIN_CORRECT_RECEIVED:
      *Data = CODING_DID_018E_VIN_STATUS_VIN_CORRECT_RECEIVED;
      break;
    case VIN_STATUS_NEW_VIN_RECEIVED:
      *Data = CODING_DID_018E_VIN_STATUS_NEW_VIN_RECEIVED;
      break;
    case VIN_STATUS_VIN_NOT_RECEIVED:
      /* Fall through */
    default:
      *Data = CODING_DID_018E_VIN_STATUS_VIN_NOT_RECEIVED;
      break;
    }
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_DataServices_DID_0197_Precompile_switch_ConditionCheckRead
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0197_Precompile_switch>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_DataServices_DID_0197_Precompile_switch_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0197_Precompile_switch_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0197_Precompile_switch_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_0197_Precompile_switch_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_0197_Precompile_switch_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_0197_Precompile_switch_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0197_Precompile_switch_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    *ErrorCode = DCM_E_POSITIVERESPONSE;
    retVal = RTE_E_OK;
  }
  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  /* #10 Return successfully, if input is not a null pointer. */
  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_DataServices_DID_0197_Precompile_switch_ReadData
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0197_Precompile_switch>
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_KeyM_Certificate_CheckTrustModelChainOfTrust(Ssa_TrustModelChainState_Type *state)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_KeyM_Certificate_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_DataServices_DID_0197_Precompile_switch_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0197_Precompile_switch_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0197_Precompile_switch_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_0197_Precompile_switch_ReadData_doc
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
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data4ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_0197_Precompile_switch_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_0197_Precompile_switch_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0197_Precompile_switch_E_NOT_OK;
  /* initialize with value different from FULLY_INJECTED */
  Ssa_TrustModelChainState_Type trustModelChainOfTrust = SSA_TRUSTMODELCHAINSTATE_ROOT_INJECTED;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  if (Rte_Call_KeyM_Certificate_CheckTrustModelChainOfTrust(&trustModelChainOfTrust) != RTE_E_OK)
  {
    /* retVal already set */
  }
  else
  {
    /* #10 Set bits of Data according to the values of the precompile switches. */
     /* Clear all bits of first two bytes */
    Data[0] = 0u;
    Data[1] = 0u;

    /* SecOc switch */
#if (SSA_SECOC_IGNORE_VERIFICATION_RESULT == STD_ON) /* COV_SSA_DEBUG XF */
    Coding_OpSetBit(Data[0], 0);
#endif

    /* #15 Set bit TrustModelChainofTrustInjected to true only if TM chain state is fully injected. */
    if (trustModelChainOfTrust == SSA_TRUSTMODELCHAINSTATE_FULLY_INJECTED)
    {
      Coding_OpSetBit(Data[0], 1u);
    }

#if (SSA_ENABLE_DEBUG_AUTHENTICATION == STD_ON) /* COV_SSA_DEBUG XF */
    Coding_OpSetBit(Data[0], 2u);
#endif

#if (SSA_ENABLE_DEBUG_RIGHTS == STD_ON) /* COV_SSA_DEBUG XF */
    Coding_OpSetBit(Data[0], 3u);
#endif

#if (SSA_ENABLE_DEBUG_NONCE == STD_ON) /* COV_SSA_DEBUG XF */
    Coding_OpSetBit(Data[0], 4u);
#endif

#if (SSA_IGNORE_SECURE_BROADCAST_VERIFICATION_RESULT == STD_ON) /* COV_SSA_DEBUG XF */
    Coding_OpSetBit(Data[0], 5u);
#endif

#if (SSA_ENABLE_DEBUG_AUTHENTICATION_STATUS == STD_ON) /* COV_SSA_DEBUG XF */
    Coding_OpSetBit(Data[0], 6u);
#endif

#if (SSA_IGNORE_CODING_VERIFICATION_RESULT == STD_ON) /* COV_SSA_DEBUG XF */
    Coding_OpSetBit(Data[1u], 0u);
#endif

#if (SSA_FVM_UNLIMITED_TURNING_BACK_OF_TICK_COUNT == STD_ON) /* COV_SSA_DEBUG XF */
    Coding_OpSetBit(Data[1], 1u);
#endif

#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
    Coding_OpSetBit(Data[1], 2u);
#endif

    /* following 3 bits are reserved */

    /* Set bits representing the ECU Type */
    Data[1] |= (uint8)(SSA_ECU_TYPE << 6); /* PRQA S 2985 */ /* MD_SSA_SHIFT_OPERATION */

    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  /* #20 Return successfully, if input is not a null pointer. */
  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_EF04_SSA_Major_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_EF04_SSA_Major_Version_DCM_E_PENDING
 *   RTE_E_DataServices_DID_EF04_SSA_Major_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_EF04_SSA_Major_Version_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    *ErrorCode = DCM_E_POSITIVERESPONSE;
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  /* #10 Return successfully, if input is not a null pointer. */
  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_EF04_SSA_Major_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_EF04_SSA_Major_Version_DCM_E_PENDING
 *   RTE_E_DataServices_DID_EF04_SSA_Major_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
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

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_EF04_SSA_Major_Version_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_EF04_SSA_Major_Version_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Write the major version to the output data buffer. */
    *Data = (uint8)SSA_SW_MAJOR_VERSION;
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  /* #20 Return successfully, if input is not a null pointer. */
  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_EF04_SSA_Minor_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_EF04_SSA_Minor_Version_DCM_E_PENDING
 *   RTE_E_DataServices_DID_EF04_SSA_Minor_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_EF04_SSA_Minor_Version_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    *ErrorCode = DCM_E_POSITIVERESPONSE;
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  /* #10 Return successfully, if input is not a null pointer. */
  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_EF04_SSA_Minor_Version>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_EF04_SSA_Minor_Version_DCM_E_PENDING
 *   RTE_E_DataServices_DID_EF04_SSA_Minor_Version_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
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

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_EF04_SSA_Minor_Version_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_EF04_SSA_Minor_Version_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Write the minor version to the output data buffer. */
    *Data = (uint8)SSA_SW_MINOR_VERSION;
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  /* #12 Return successfully, if input is not a null pointer. */
  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_EF04_SSA_Patch_Level>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_EF04_SSA_Patch_Level_DCM_E_PENDING
 *   RTE_E_DataServices_DID_EF04_SSA_Patch_Level_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ConditionCheckRead_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_EF04_SSA_Patch_Level_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    *ErrorCode = DCM_E_POSITIVERESPONSE;
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  /* #10 Return successfully, if input is not a null pointer. */
  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_EF04_SSA_Patch_Level>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_EF04_SSA_Patch_Level_DCM_E_PENDING
 *   RTE_E_DataServices_DID_EF04_SSA_Patch_Level_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
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

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_DID_EF04_SSA_Patch_Level_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_EF04_SSA_Patch_Level_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Write the patch version to the output data buffer. */
    *Data = (uint8)SSA_SW_PATCH_VERSION;
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  /* #12 Return successfully, if input is not a null pointer. */
  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_DataServices_VINDataIdentifier_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_VINDataIdentifier>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_DataServices_VINDataIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_VINDataIdentifier_DCM_E_PENDING
 *   RTE_E_DataServices_VINDataIdentifier_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_VINDataIdentifier_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_VINDataIdentifier_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_VINDataIdentifier_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType retVal = RTE_E_DataServices_VINDataIdentifier_E_NOT_OK;
  NvM_RequestResultType errorStatus = NVM_REQ_PENDING;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    *ErrorCode = DCM_E_POSITIVERESPONSE;
    retVal = RTE_E_OK;

    /* #10 Check that operation is not canceled by DCM. */
    if (OpStatus != DCM_CANCEL)
    {
      /* #20 Get status of Current VIN NVRAM block and forward it to the diagnostic user. */
      retVal = Rte_Call_NvM_CurrentVIN_GetErrorStatus(&errorStatus);
      if ((retVal != E_OK) || (errorStatus == NVM_REQ_PENDING))
      {
        retVal = RTE_E_DataServices_VINDataIdentifier_DCM_E_PENDING;
      }
    }
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_DataServices_VINDataIdentifier_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_VINDataIdentifier>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VIN(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VIN(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_DataServices_VINDataIdentifier_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data17ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_VINDataIdentifier_DCM_E_PENDING
 *   RTE_E_DataServices_VINDataIdentifier_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_VINDataIdentifier_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data17ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_VINDataIdentifier_ReadData(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_VINDataIdentifier_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_VINDataIdentifier_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Copy the CurrentVIN to the output data buffer within an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_VIN();
    Ssa_MemCpy(Data, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_CurrentVIN()->VIN, SSA_SIZEOF_VIN);
    Rte_Exit_Coding_ExclusiveArea_VIN();
    retVal = RTE_E_OK;
  }

  SSA_DUMMY_STATEMENT(OpStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  /* #12 Return successfully, if input is not a null pointer. */
  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_DataServices_VINDataIdentifier_WriteData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteData> of PortPrototype <DataServices_VINDataIdentifier>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Coding_VINStatus_status(VIN_Status data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SecLog_ChangeVinEvent_ChangeVin(const uint8 *newVin)
 *     Argument newVin: uint8* is of type SecLog_VinType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_ChangeVinEvent_E_NOT_OK
 *   Std_ReturnType Rte_Call_SsaCdd_Csm_CancelJob(uint32 jobId, Crypto_OperationModeType operationMode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DTC_0x164456_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VIN(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VIN(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_DataServices_VINDataIdentifier_WriteData(const uint8 *Data, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data: uint8* is of type Dcm_Data17ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_VINDataIdentifier_DCM_E_PENDING
 *   RTE_E_DataServices_VINDataIdentifier_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_VINDataIdentifier_WriteData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_DataServices_VINDataIdentifier_WriteData(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Data, Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_DataServices_VINDataIdentifier_WriteData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_VINDataIdentifier_DCM_E_PENDING;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((Data == NULL_PTR) || (ErrorCode == NULL_PTR))
  {
    retVal = RTE_E_DataServices_VINDataIdentifier_E_NOT_OK;
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Process the new VIN considering its origin from a diagnostic service. */
    if (OpStatus == DCM_INITIAL)
    {
      if (Coding_CheckCharactersOfVIN(Data) == FALSE)
      {
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        retVal = RTE_E_DataServices_VINDataIdentifier_E_NOT_OK;
      }
      else
      {
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
#else
        /* assumed as atomic write access */
        Coding_Restart_VinReceiveTimeout_Counter();
#endif

        if (Coding_ChangeVin(Data, CODING_VIN_CHANGE_DCM) != E_OK)
        {
          *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
          retVal = RTE_E_DataServices_VINDataIdentifier_E_NOT_OK;
        }
        else
        {
          if ((Coding_CurrentVinNvmWriteRequested == FALSE) && (Coding_CurrentVinNvmWriteState == CODING_NVM_WRITE_STATE_IDLE))
          {
            /* This path considers the case, that the task of this routine is interrupted by the mainfunction task 
               and that that mainfunction task has already finished with success. */
            *ErrorCode = DCM_E_POSITIVERESPONSE;
            retVal = RTE_E_OK;
          }
        }
      }
    }
    else if (OpStatus == DCM_PENDING)
    {
      if (Coding_CurrentVinNvmWriteRequested == FALSE)
      {
        if (Coding_CurrentVinNvmWriteState == CODING_NVM_WRITE_STATE_IDLE)
        {
          *ErrorCode = DCM_E_POSITIVERESPONSE;
          retVal = RTE_E_OK;
        }
        else if (Coding_CurrentVinNvmWriteState == CODING_NVM_WRITE_STATE_FAILURE)
        {
          *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
          retVal = RTE_E_RoutineServices_Routine_Reset_VIN_Values_E_NOT_OK;
          /* reset WriteState to idle */
          Coding_CurrentVinNvmWriteState = CODING_NVM_WRITE_STATE_IDLE;
        }
        else
        {
          /* No action */
        }
      }
    }
    else /* OpStatus == DCM_CANCEL */
    {
      /* If NvM_WriteBlock has not been called, withdraw write request. */
      Coding_CurrentVinNvmWriteRequested = FALSE;
      /* If NvM_WriteBlock has already been called, just ignore the result. Data may have been be written or not. */
      Coding_CurrentVinNvmWriteState = CODING_NVM_WRITE_STATE_IDLE;
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      retVal = RTE_E_OK;
    }
  }
  return retVal;
  /* PRQA S 6080 4 */ /* MD_MSR_STMIF */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Coding_VINStatus_status(VIN_Status data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_Init_doc
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
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_Coding_CODE) Ssa_Coding_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_Init
 *********************************************************************************************************************/

  /* #10 Mark all DIDs relevant for secure variant coding as not handled. */
#if (SSA_CODINGDID == STD_ON)
  uint8 i;
  for (i = 0u; i < Ssa_GetSizeOfDidHandled(); i++)
  {
    Ssa_SetDidHandled(i, 0u);
  }

  Coding_SigVerifyUpdateState = SSA_CODING_ASYNC_STATE_IDLE;
#endif

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
  Write_Coding_VinSendTimer(0u);
#else
  /* #20 Delete the timeout counter for the VIN received timeout, i.e. set it to zero. */
  Delete_Coding_Vin_ReceiveTimeout_Counter();
#endif
  /* #30 Reset all local variables. */
  Write_Coding_Timeout(CODING_STATE_FREE);
  Coding_WriteDataState = CODING_WRITEDATA_STATE_IDLE;
  Coding_CurrentDiagChanId = SSA_RIGHTSM_DIAG_INVALID_CHAN_ID;
  Coding_LastDiagChanId = SSA_RIGHTSM_DIAG_INVALID_CHAN_ID;
  Coding_CurrentVinNvmWriteRequested = FALSE;
  Coding_CurrentVinNvmWriteState = CODING_NVM_WRITE_STATE_IDLE;

  Coding_EvalDataVerifyCertState = CODING_VERIFY_CERT_STATE_IDLE;
  Coding_SigVerifyStartState = SSA_CODING_ASYNC_STATE_IDLE;
  Coding_SigVerifyFinishState = SSA_CODING_ASYNC_STATE_IDLE;
  Coding_CancelSigVerify = 0u;

  /* Set default values indicating a negative verification result. */
  Coding_EvalCertVerificationResult = CODING_RC_EVALCERT_RES_INVALID_FORMAT;
  Coding_VerifySignatureVerificationResult = CODING_RC_VERIFYSIG_RES_INVALID_SIGNATURE;
  Coding_VerifySignatureErrorCode = DCM_E_POSITIVERESPONSE;

  Coding_PkiRole = 0u;

  /* #40 Check if Current VIN differs from Coding VIN. */
  if (Coding_CompareVIN(
    (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))(Rte_Pim_CurrentVIN()->VIN),
    (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))(Rte_Pim_CodingVIN()->VIN)) == TRUE)
  {
    Coding_VIN_State = VIN_STATUS_VIN_CORRECT_RECEIVED;

    /* #45 If they are equal set DEM event status for DTC 0x164456 to "passed" */
    (void)Rte_Call_DTC_0x164456_SetEventStatus(DEM_EVENT_STATUS_PASSED);
  }
  else
  {
    Coding_VIN_State = VIN_STATUS_NEW_VIN_RECEIVED;

    /* Notify VIN status. */
    (void)Rte_Write_Coding_VINStatus_status(Coding_VIN_State);

    /* #50 If they are different set DEM event status for DTC 0x164456 to "failed" */
    (void)Rte_Call_DTC_0x164456_SetEventStatus(DEM_EVENT_STATUS_FAILED);
  }

  /* Ensure type sizes once for the Coding submodule which calls RTE APIs expecting these data types:
   * Coding_VINDataType must be an array with 17 element(s) of type uint8
   * SSA_SIZEOF_VIN must be configured accordingly. */
  /*@ assert sizeof(Coding_VINDataType) == 17; */
  /*@ assert SSA_SIZEOF_VIN == 17; */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_InitMonitorForEvent_DTC_0x164456
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <InitMonitorForEvent> of PortPrototype <CallbackInitMonitorForEvent_DTC_0x164456>
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DTC_0x164456_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_InitMonitorForEvent_DTC_0x164456(Dem_InitMonitorReasonType InitMonitorReason)
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
 * Symbol: Ssa_Coding_InitMonitorForEvent_DTC_0x164456_doc
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

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_InitMonitorForEvent_DTC_0x164456(Dem_InitMonitorReasonType InitMonitorReason) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_InitMonitorForEvent_DTC_0x164456 (returns application error)
 *********************************************************************************************************************/

  /* #10 Check that "init monitor reason" is "clear". */
  if (InitMonitorReason == DEM_INIT_MONITOR_CLEAR)
  {
    if (Coding_VIN_State != VIN_STATUS_VIN_CORRECT_RECEIVED)
    {
      /* #30 Set DEM event status for DTC 0x164456 to "failed" */
      (void)Rte_Call_DTC_0x164456_SetEventStatus(DEM_EVENT_STATUS_FAILED);
    }
    else
    {
      /* #50 Set DEM event status for DTC 0x164456 to "passed" */
      (void)Rte_Call_DTC_0x164456_SetEventStatus(DEM_EVENT_STATUS_PASSED);
    }
  }

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_MainFunction
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
 *   Std_ReturnType Rte_Write_Coding_Com_SendVIN_VIN(const uint8 *data)
 *     Argument data: uint8* is of type Coding_VINDataType
 *   Std_ReturnType Rte_Write_Coding_VINStatus_status(VIN_Status data)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_Coding_Mode_CodingStatus(Coding_ModeType mode)
 *   Modes of Rte_ModeType_Coding_Mode:
 *   - RTE_MODE_Coding_Mode_CODING_ACTIVE
 *   - RTE_MODE_Coding_Mode_CODING_FAILED
 *   - RTE_MODE_Coding_Mode_CODING_OK
 *   - RTE_TRANSITION_Coding_Mode
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SsaCdd_Csm_CancelJob(uint32 jobId, Crypto_OperationModeType operationMode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvM_CodingVIN_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_CodingVIN_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_ControlLink_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_ControlLink_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_CurrentVIN_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_CurrentVIN_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VIN(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VIN(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_MainFunction_doc
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

FUNC(void, Ssa_Coding_CODE) Ssa_Coding_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_MainFunction
 *********************************************************************************************************************/

  /* #10 ---------- ECU type is VSM. ---------- */
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
  /* #20 Use a counter for the periodic sending of secured VIN broadcast message. */
  if (Read_Coding_VinSendTimer() < CODING_SEND_VIN_MAINFUNCTIONS)
  {
    Increment_Coding_VinSendTimer();
  }
  /* #25 When a secured VIN broadcast message is to be sent: */
  else
  {
    Coding_VINDataType vin;
    /* #30 Copy the stored VIN into a local buffer using an exclusive area. */
    Rte_Enter_Coding_ExclusiveArea_VIN();
    Ssa_MemCpy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))vin, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_CurrentVIN()->VIN, SSA_SIZEOF_VIN);
    Rte_Exit_Coding_ExclusiveArea_VIN();
    /* #35 Send the secured VIN broadcast message. */
    (void)Rte_Write_Coding_Com_SendVIN_VIN(vin);
    Write_Coding_VinSendTimer(0u);
  }
#else
  /* #40 ---------- ECU type is either NORMAL or GATEWAY ---------- */

  Rte_Enter_Coding_ExclusiveArea_VIN();
  /* #70 In order to check for VIN receive timeout count down a counter value that is reset when any VIN is received. */
  if (Get_Coding_VinReceiveTimeout_Counter() > 0u) /*  Check if the timeout counter for the VIN received timeout is active. */
  {
    Decrement_Coding_VinReceiveTimeout_Counter();

    /* #80 If the count down reached 0 and if the stored VIN is not the default VIN notify the VIN status to
     *     "VIN not received" and set the internal VIN state "receive timeout". */
    if ((Get_Coding_VinReceiveTimeout_Counter() == 0u) && Coding_IsVinNotDefault())
    {
      Rte_Exit_Coding_ExclusiveArea_VIN();

      Coding_ProcessVinState(VIN_STATUS_VIN_NOT_RECEIVED, SSA_VIN_STATE_UPDATE);
    }
    else
    {
      Rte_Exit_Coding_ExclusiveArea_VIN();
    }
  }
  else
  {
    Rte_Exit_Coding_ExclusiveArea_VIN();
  }

#endif
  /* #220 ---------- Any ECU type ---------- */
  /* #230 Handle the coding timeout and cancellation of signature verification. */
  Coding_HandleCodingTimeoutAndCancelation();
  /* #240 Handle NVM. */
  Coding_HandleNVM();

  /* PRQA S 6030 4 */ /* MD_MSR_STCYC */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_Evaluate_Data_Verification_Certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Coding_VINStatus_status(VIN_Status data)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_Coding_Mode_CodingStatus(Coding_ModeType mode)
 *   Modes of Rte_ModeType_Coding_Mode:
 *   - RTE_MODE_Coding_Mode_CODING_ACTIVE
 *   - RTE_MODE_Coding_Mode_CODING_FAILED
 *   - RTE_MODE_Coding_Mode_CODING_OK
 *   - RTE_TRANSITION_Coding_Mode
 *   Coding_MemoryStatusType Rte_Mode_Coding_MemoryStatus_MemoryStatus(void)
 *   Modes of Rte_ModeType_Coding_MemoryStatus:
 *   - RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_FAILED
 *   - RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_OK
 *   - RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_PENDING
 *   - RTE_TRANSITION_Coding_MemoryStatus
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
 *   Std_ReturnType Rte_Call_SsaCdd_Csm_CancelJob(uint32 jobId, Crypto_OperationModeType operationMode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *   Std_ReturnType Rte_Call_SsaCdd_Csm_SignatureVerify(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_ConstDataPtr compareBuffer, uint32 compareLength, Ssa_VerifyResultPtr resultBuffer)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
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
 *   void Rte_Enter_Coding_ExclusiveArea_VIN(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VIN(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start(const uint8 *Data_Verification_Certificate, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data_Verification_Certificate: uint8* is of type Dcm_Data2002ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start_doc
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
/*!
 * \spec
 *    requires $lengthOf(Data_Verification_Certificate) >= sizeof(Dcm_Data2002ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Data_Verification_Certificate, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Verification_Result, uint16 DataLength, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_Start (returns application error)
 *********************************************************************************************************************/
  /* #10 By default this function shall return error code "pending". */
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_PENDING;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((Data_Verification_Certificate == NULL_PTR) || (routineInfo == NULL_PTR) ||
      (Verification_Result == NULL_PTR) || (ErrorCode == NULL_PTR))
  {
    retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK;
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {

#if (SSA_KEEP_BUFFER_VARIABLES_STATIC == STD_OFF)
    CertP_ParsedCertStructureType Coding_ParsedCertificate;
    /* satisfy QAC, initialize with invalid value */
    Coding_ParsedCertificate.pkiRole = 0;
    Coding_ParsedCertificate.parsedCertLength = 0;
#endif

    /* #20 Set current diagnostic channel id, if it is invalid, to the last diagnostic channel id acquired in the
     *     ServiceRequestNotification_Indication function. */
    if (Coding_CurrentDiagChanId == SSA_RIGHTSM_DIAG_INVALID_CHAN_ID)
    {
      Coding_CurrentDiagChanId = Coding_LastDiagChanId;
    }

    /* #30 Check that the current diagnostic channel id equals the last diagnostic channel id. */
    if (Coding_CurrentDiagChanId != Coding_LastDiagChanId)
    {
      *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK;
    }
    else
    {
      if ((OpStatus == DCM_PENDING) || (OpStatus == DCM_INITIAL))
      {
        /* #40 Process the states IDLE, VERIFY_CERT and VERIFY_DATA of Coding_EvalDataVerifyCertState to verify
         *     the certificate against the backend certificate, prepare the public key for usage in data
         *     signature verification and start the signature verification in streaming mode. */
        retVal = Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateIdle(Data_Verification_Certificate, DataLength, &Coding_ParsedCertificate, ErrorCode);

        /* OpStatus might be INITIAL or PENDING */
        retVal = Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateVerifyCert(Data_Verification_Certificate, retVal, &Coding_ParsedCertificate, ErrorCode);

        /* OpStatus might be INITIAL or PENDING */
        retVal = Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateVerifyData(retVal, ErrorCode);
      }
      else /*  DCM_CANCEL */
      {
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK;
      }
    }

    /* #50 Do not write the routine info as long as pending is returned because the input buffer might be overwritten. */
    if (retVal != RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_PENDING)
    {
      *routineInfo = SSA_ROUTINE_INFO_SUCCESFULLY_COMPLETED;
      *Verification_Result = Coding_EvalCertVerificationResult;
      Coding_EvalCertVerificationResult = CODING_RC_EVALCERT_RES_INVALID_FORMAT;
      if (retVal == RTE_E_OK)
      {
        *ErrorCode = DCM_E_POSITIVERESPONSE;
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
 * Runnable Entity Name: Ssa_Coding_RoutineServices_Routine_Reset_VIN_Values_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_Reset_VIN_Values>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Coding_VINStatus_status(VIN_Status data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SecLog_ChangeVinEvent_ChangeVin(const uint8 *newVin)
 *     Argument newVin: uint8* is of type SecLog_VinType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_ChangeVinEvent_E_NOT_OK
 *   Std_ReturnType Rte_Call_SsaCdd_Csm_CancelJob(uint32 jobId, Crypto_OperationModeType operationMode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DTC_0x164456_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VIN(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VIN(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_RoutineServices_Routine_Reset_VIN_Values_Start(Dcm_OpStatusType OpStatus, uint8 *routineInfo, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_Reset_VIN_Values_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_Reset_VIN_Values_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_Reset_VIN_Values_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_RoutineServices_Routine_Reset_VIN_Values_Start_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_RoutineServices_Routine_Reset_VIN_Values_Start(Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) routineInfo, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_RoutineServices_Routine_Reset_VIN_Values_Start (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Reset_VIN_Values_DCM_E_PENDING;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((routineInfo == NULL_PTR) || (ErrorCode == NULL_PTR))
  {
    retVal = RTE_E_RoutineServices_Routine_Reset_VIN_Values_E_NOT_OK;
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    if (OpStatus == DCM_INITIAL)
    {
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
#else
      /* assumed as atomic write access */
      Coding_Restart_VinReceiveTimeout_Counter();
#endif

      /* #10 Request a change of the VIN to the default VIN considering its origin from a diagnostic service. */
      if (Coding_ChangeVin((P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_CData_Coding_Storage_DefaultValue()->VIN, CODING_VIN_CHANGE_DCM) != E_OK)
      {
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        retVal = RTE_E_RoutineServices_Routine_Reset_VIN_Values_E_NOT_OK;
      }
      else
      {
        if ((Coding_CurrentVinNvmWriteRequested == FALSE)  && (Coding_CurrentVinNvmWriteState == CODING_NVM_WRITE_STATE_IDLE))
        {
          /* This path considers the case, that the task of this routine is interrupted by the mainfunction task
             and that that mainfunction task has already finished with success. */
          *ErrorCode = DCM_E_POSITIVERESPONSE;
          retVal = RTE_E_OK;
        }
      }
    }
    else if (OpStatus == DCM_PENDING)
    {
      if (Coding_CurrentVinNvmWriteRequested == FALSE)
      {
        if (Coding_CurrentVinNvmWriteState == CODING_NVM_WRITE_STATE_IDLE)
        {
          *ErrorCode = DCM_E_POSITIVERESPONSE;
          retVal = RTE_E_OK;
        }
        else if (Coding_CurrentVinNvmWriteState == CODING_NVM_WRITE_STATE_FAILURE)
        {
          *ErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
          retVal = RTE_E_RoutineServices_Routine_Reset_VIN_Values_E_NOT_OK;
          /* reset WriteState to idle */
          Coding_CurrentVinNvmWriteState = CODING_NVM_WRITE_STATE_IDLE;
        }
        else
        {
          /* No action */
        }
      }
    }
    else
    {
      *ErrorCode = DCM_E_POSITIVERESPONSE;
      retVal = RTE_E_OK;
    }

    if (retVal != RTE_E_RoutineServices_Routine_Reset_VIN_Values_DCM_E_PENDING)
    {
      *routineInfo = SSA_ROUTINE_INFO_SUCCESFULLY_COMPLETED;
    }
  }

  return retVal;
  /* PRQA S 6080 4 */ /* MD_MSR_STMIF */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_RoutineServices_Routine_Verify_Signature_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_Verify_Signature>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Coding_VINStatus_status(VIN_Status data)
 *
 * Mode Interfaces:
 * ================
 *   Std_ReturnType Rte_Switch_Coding_Mode_CodingStatus(Coding_ModeType mode)
 *   Modes of Rte_ModeType_Coding_Mode:
 *   - RTE_MODE_Coding_Mode_CODING_ACTIVE
 *   - RTE_MODE_Coding_Mode_CODING_FAILED
 *   - RTE_MODE_Coding_Mode_CODING_OK
 *   - RTE_TRANSITION_Coding_Mode
 *   Coding_MemoryStatusType Rte_Mode_Coding_MemoryStatus_MemoryStatus(void)
 *   Modes of Rte_ModeType_Coding_MemoryStatus:
 *   - RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_FAILED
 *   - RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_OK
 *   - RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_PENDING
 *   - RTE_TRANSITION_Coding_MemoryStatus
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SecLog_SignatureVerificationEvent_VerifySignatureVariantCoding_SignatureVerification(uint8 verificationResult)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_SignatureVerificationEvent_E_NOT_OK
 *   Std_ReturnType Rte_Call_SsaCdd_Csm_CancelJob(uint32 jobId, Crypto_OperationModeType operationMode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *   Std_ReturnType Rte_Call_SsaCdd_Csm_SignatureVerify(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_ConstDataPtr compareBuffer, uint32 compareLength, Ssa_VerifyResultPtr resultBuffer)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_NvM_ControlLink_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_ControlLink_ReadBlock(dtRef_VOID DstPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_ControlLink_SetRamBlockStatus(boolean RamBlockStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *   Std_ReturnType Rte_Call_NvM_ControlLink_WriteBlock(dtRef_const_VOID SrcPtr)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VIN(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VIN(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_RoutineServices_Routine_Verify_Signature_Start(uint8 Data_to_be_checked, const uint8 *Signature_Value, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Signature_Value: uint8* is of type Dcm_Data64ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_Verify_Signature_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_RoutineServices_Routine_Verify_Signature_Start_doc
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

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_RoutineServices_Routine_Verify_Signature_Start(uint8 Data_to_be_checked, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Signature_Value, Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) routineInfo, P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Verification_Result, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_RoutineServices_Routine_Verify_Signature_Start (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Verify_Signature_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((Signature_Value == NULL_PTR) || (routineInfo == NULL_PTR) ||
      (Verification_Result== NULL_PTR) || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Check that the current diagnostic channel id equals the last diagnostic channel id. */
    if (Coding_CurrentDiagChanId != Coding_LastDiagChanId)
    {
      retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK;
      Coding_VerifySignatureErrorCode = DCM_E_REQUESTSEQUENCEERROR;
    }
    else if (OpStatus == DCM_CANCEL)
    {
      retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK;
      Coding_VerifySignatureErrorCode = DCM_E_REQUESTSEQUENCEERROR;
    }
    else
    {
      boolean isStateHandled = FALSE;

      if (OpStatus == DCM_PENDING)
      {
        isStateHandled = Coding_VerifySignature_HandleStatesOpStatusPending(&retVal);
      }

      if (!isStateHandled)
      {
        retVal = Coding_VerifySignature_HandleStates(Signature_Value);
      }
    }

    /* #80 Once the operation status is not pending any more invalidate the current diagnostic channel id. */
    if (retVal != RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING)
    {
      *routineInfo = SSA_ROUTINE_INFO_SUCCESFULLY_COMPLETED;
      *Verification_Result = Coding_VerifySignatureVerificationResult;
      /* Reset static variables */
      Coding_VerifySignatureVerificationResult = CODING_RC_VERIFYSIG_RES_INVALID_SIGNATURE;
      Coding_CurrentDiagChanId = SSA_RIGHTSM_DIAG_INVALID_CHAN_ID;

      /* #90 Once the signature verification is finished (positive return value) log the verification result. */
      if (retVal == RTE_E_OK)
      {
        (void)Rte_Call_SecLog_SignatureVerificationEvent_VerifySignatureVariantCoding_SignatureVerification(*Verification_Result);
      }
      else
      {
        *ErrorCode = Coding_VerifySignatureErrorCode;
      }
    }
  }

  SSA_DUMMY_STATEMENT(Data_to_be_checked);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
  /* PRQA S 6010, 6030, 6060, 6080 4 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_SSA_STPAR, MD_MSR_STMIF */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_ServiceRequestNotification_Confirmation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Confirmation> of PortPrototype <ServiceRequestNotification>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_ServiceRequestNotification_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus)
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
 * Symbol: Ssa_Coding_ServiceRequestNotification_Confirmation_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_ServiceRequestNotification_Confirmation(uint8 SID, uint8 ReqType, uint16 SourceAddress, Dcm_ConfirmationStatusType ConfirmationStatus) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_ServiceRequestNotification_Confirmation (returns application error)
 *********************************************************************************************************************/

  /* #10 Nothing to do. Always return successfully. */
  SSA_DUMMY_STATEMENT(SID);                /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  SSA_DUMMY_STATEMENT(ReqType);            /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  SSA_DUMMY_STATEMENT(SourceAddress);      /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  SSA_DUMMY_STATEMENT(ConfirmationStatus); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_ServiceRequestNotification_Indication
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
 *   Std_ReturnType Rte_Call_SsaCdd_Csm_CancelJob(uint32 jobId, Crypto_OperationModeType operationMode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *   Std_ReturnType Rte_Call_SsaCdd_Csm_SignatureVerify(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_ConstDataPtr compareBuffer, uint32 compareLength, Ssa_VerifyResultPtr resultBuffer)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_ServiceRequestNotification_Indication(uint8 SID, const uint8 *RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, Dcm_NegativeResponseCodeType *ErrorCode)
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
 * Symbol: Ssa_Coding_ServiceRequestNotification_Indication_doc
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

/* PRQA S 3673 5 */ /* MD_SSA_PARAM_NOT_P2CONST */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_ServiceRequestNotification_Indication(uint8 SID, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) RequestData, uint16 DataSize, uint8 ReqType, uint16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_ServiceRequestNotification_Indication (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((RequestData == NULL_PTR) || (ErrorCode == NULL_PTR))
  {
    retVal = RTE_E_ServiceRequestNotification_E_NOT_OK;
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Derive the current diagnostic channel id from the source address and store it as last diagnostic channel id. */
    Coding_LastDiagChanId = Ssa_GetRightsM_TesterToChannel(SourceAddress & 0x000Fu);

#if (SSA_CODINGDID == STD_ON)
    /* #20 Filter for WriteDataByIdentifier (0x2E) service with a length of at least 2 bytes. */
    if ((SID == 0x2Eu) && (DataSize >= 2u))
    {
      uint16 idx;
      uint16 did = (uint16)((((uint16)(RequestData[0])) << 8u) | RequestData[1]);

      /* #30 Loop through all DIDs configured for secure variant coding. */
      for (idx = 0u; idx < Ssa_GetSizeOfCodingDid(); idx++)
      {
        /* #40 Filter for all DIDs where secure coding is required.  */
        if (did == Ssa_GetCodingDid(idx))
        {
          /* #50 Handle these DIDs. */
          retVal = Coding_ServiceRequestNotification_Indication_HandleDid(did, idx, RequestData, DataSize, ErrorCode);
          /* Break the loop after handling the DID. */
          break;
        }
      }
    }
#else
    SSA_DUMMY_STATEMENT(SID);          /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
    SSA_DUMMY_STATEMENT(DataSize);     /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
    SSA_DUMMY_STATEMENT(ErrorCode);     /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
#endif
  }

  SSA_DUMMY_STATEMENT(ReqType);            /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_VIN_Get
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Get> of PortPrototype <Coding_VIN>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VIN(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VIN(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_VIN_Get(uint8 *vin)
 *     Argument vin: uint8* is of type Coding_VINDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Coding_VIN_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_VIN_Get_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(vin) >= sizeof(Coding_VINDataType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_VIN_Get(P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) vin) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_VIN_Get (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_Coding_VIN_E_NOT_OK;

 /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (vin == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #10 Copy the (to be) stored CurrentVIN to the output buffer within an external area. */
    Rte_Enter_Coding_ExclusiveArea_VIN();
    Ssa_MemCpy(vin, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_CurrentVIN()->VIN, SSA_SIZEOF_VIN);
    Rte_Exit_Coding_ExclusiveArea_VIN();
    retVal = RTE_E_OK;
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_VIN_GetStoreState
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetStoreState> of PortPrototype <Coding_VINControl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_VIN_GetStoreState(Ssa_VinStoreStateType *state)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Coding_VINControl_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_VIN_GetStoreState_doc
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

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_VIN_GetStoreState(P2VAR(Ssa_VinStoreStateType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) state) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_VIN_GetStoreState (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_Coding_VINControl_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (state == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {

    if (Coding_CurrentVinNvmWriteRequested == FALSE)
    {
      if (Coding_CurrentVinNvmWriteState == CODING_NVM_WRITE_STATE_IDLE)
      {
        /* #10 Return SSA_VIN_CTRLSTAT_OK only if there is no write request for the Current VIN NV block (anymore)
        *     and if the write state is IDLE. */
        *state = SSA_VIN_CTRLSTAT_OK;
      }
      else if (Coding_CurrentVinNvmWriteState == CODING_NVM_WRITE_STATE_FAILURE)
      {
        /* #20 Return an error, if during a write request an error occurred (Coding_CurrentVinNvmWriteState == CODING_NVM_WRITE_STATE_FAILURE). */
        *state = SSA_VIN_CTRLSTAT_FAILED;
        Coding_CurrentVinNvmWriteState = CODING_NVM_WRITE_STATE_IDLE;
      }
      else
      {
        *state = SSA_VIN_CTRLSTAT_PENDING;
      }
    }
    else
    {
      *state = SSA_VIN_CTRLSTAT_PENDING;
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
 * Runnable Entity Name: Ssa_Coding_VIN_Lock
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Lock> of PortPrototype <Coding_VINControl>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VIN(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VIN(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_VIN_Lock(boolean locked)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Coding_VINControl_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_VIN_Lock_doc
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

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_VIN_Lock(boolean locked) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_VIN_Lock (returns application error)
 *********************************************************************************************************************/

  /* #10 If locking VIN is requested and the VIN is not locked, lock the VIN. Read and write the corresponding attribute bit
  *     within an exclusive area. Request for writing the NV RAM block due to changed VIN attributes. */
  Rte_Enter_Coding_ExclusiveArea_VIN();
  if (locked && (!Coding_IsVinLocked()))
  {
    Coding_SetAttribute(CODING_ATTRIBUTEMASK_LOCKED);
    Coding_CurrentVinNvmWriteRequested = TRUE;
  }
  /* #20 If unlocking VIN is requested and the VIN is locked, unlock the VIN. Read and write the corresponding attribute bit
  *     within an exclusive area. Mark the NV RAM block for the VIN attributes as changed. */
  else if ((!locked) && Coding_IsVinLocked())
  {
    Coding_ClearAttribute(CODING_ATTRIBUTEMASK_LOCKED);
    Coding_CurrentVinNvmWriteRequested = TRUE;
  }
  else
  {
    /* Lock is already in right state */
  }
  Rte_Exit_Coding_ExclusiveArea_VIN();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_VIN_Receive
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <VIN> of PortPrototype <Coding_Com_ReceiveVIN>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_Coding_Com_ReceiveVIN_VIN(uint8 *data)
 *     Argument data: uint8* is of type Coding_VINDataType
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Coding_VINStatus_status(VIN_Status data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SecLog_ChangeVinEvent_ChangeVin(const uint8 *newVin)
 *     Argument newVin: uint8* is of type SecLog_VinType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_ChangeVinEvent_E_NOT_OK
 *   Std_ReturnType Rte_Call_SsaCdd_Csm_CancelJob(uint32 jobId, Crypto_OperationModeType operationMode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DTC_0x164456_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VIN(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VIN(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_VIN_Receive_doc
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

FUNC(void, Ssa_Coding_CODE) Ssa_Coding_VIN_Receive(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_VIN_Receive
 *********************************************************************************************************************/
  Coding_VINDataType vin;
  /* #10 Read the new VIN from the receive buffer. */
  if (Rte_Read_Coding_Com_ReceiveVIN_VIN(vin) == E_OK)
  {
    /* #15 Check that the VIN exclusively consists of printable ASCII values. If not Ignore it. */
    if (Coding_CheckCharactersOfVIN(vin) == TRUE)
    {
      /* #20 Delete the VIN receive timeout counter. */
      /* Write access is not within an exclusive area since this is assumed as an atomic write access. */
      Delete_Coding_Vin_ReceiveTimeout_Counter();

      /* #30 Process the new VIN considering its origin from broadcast. */
      /* No use for return value. */
      (void)Coding_ChangeVin((P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))vin, CODING_VIN_CHANGE_BC);
    }
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_VIN_Receive_Timeout
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <state> of PortPrototype <Coding_ReceiveVINTimeout>
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_VIN_Receive_Timeout_doc
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

FUNC(void, Ssa_Coding_CODE) Ssa_Coding_VIN_Receive_Timeout(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_VIN_Receive_Timeout
 *********************************************************************************************************************/

  if (Coding_IsVinNotDefault())
  {
    Coding_ProcessVinState(VIN_STATUS_VIN_NOT_RECEIVED, SSA_VIN_STATE_UPDATE);
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Coding_VIN_Set
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set> of PortPrototype <Coding_VINControl>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Coding_VINStatus_status(VIN_Status data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_SecLog_ChangeVinEvent_ChangeVin(const uint8 *newVin)
 *     Argument newVin: uint8* is of type SecLog_VinType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecLog_ChangeVinEvent_E_NOT_OK
 *   Std_ReturnType Rte_Call_SsaCdd_Csm_CancelJob(uint32 jobId, Crypto_OperationModeType operationMode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_DTC_0x164456_SetEventStatus(Dem_EventStatusType EventStatus)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticMonitor_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Coding_ExclusiveArea_VIN(void)
 *   void Rte_Exit_Coding_ExclusiveArea_VIN(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Coding_VIN_Set(const uint8 *vin)
 *     Argument vin: uint8* is of type Coding_VINDataType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Coding_VINControl_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_VIN_Set_doc
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

FUNC(Std_ReturnType, Ssa_Coding_CODE) Ssa_Coding_VIN_Set(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) vin) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Coding_VIN_Set (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_Coding_VINControl_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (vin == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    /* #5 Check that the VIN exclusively consists of printable ASCII values. If not Ignore it. */
    if (Coding_CheckCharactersOfVIN(vin) == TRUE)
    {
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
#else
      /* assumed as atomic write access */
      Coding_Restart_VinReceiveTimeout_Counter();
#endif

      /* #10 Process the new VIN considering its origin from "set"-call. */
      retVal = Coding_ChangeVin(vin, CODING_VIN_CHANGE_SET);
    }
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Ssa_Coding_STOP_SEC_CODE
#include "Ssa_Coding_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define Ssa_Coding_START_SEC_CODE
#include "Ssa_Coding_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Coding_PerformNvM()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_CODING_LOCAL FUNC(void, Ssa_Coding_CODE) Coding_PerformNvM(void)
{
  NvM_RequestResultType nvmStatus = NVM_REQ_PENDING;

  /* #10 Prior to writing or reading NvM check the variant coding memory status */
  if ((Read_Coding_Timeout() == CODING_STATE_SUCCESSFUL)
    || (Read_Coding_Timeout() == CODING_STATE_FAILED))
  {
    switch (Rte_Mode_Coding_MemoryStatus_MemoryStatus()) {
    case RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_PENDING:
      /* return PENDING by default */
      break;
    case RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_OK:
      if (Read_Coding_Timeout() == CODING_STATE_SUCCESSFUL)
      {
        Write_Coding_Timeout(CODING_STATE_WRITE_TO_NVM);
      }
      else
      {
        Write_Coding_Timeout(CODING_STATE_READ_FROM_NVM);
      }
      break;
    default: /* RTE_MODE_Coding_MemoryStatus_CODING_MEMSTAT_FAILED */
      Write_Coding_Timeout(CODING_STATE_ERROR);
      break;
    }
  }

  /* #20 Write or read data to/from NvM. Also check status. */
  if ((Read_Coding_Timeout() == CODING_STATE_WAIT_FOR_NVM)
    || (Read_Coding_Timeout() == CODING_STATE_WRITE_TO_NVM)
    || (Read_Coding_Timeout() == CODING_STATE_READ_FROM_NVM))
  {
    if (Rte_Call_NvM_ControlLink_GetErrorStatus(&nvmStatus) == RTE_E_OK)
    {
      if (nvmStatus != NVM_REQ_PENDING)
      {
        if (Read_Coding_Timeout() == CODING_STATE_WAIT_FOR_NVM)
        {
          if (nvmStatus == NVM_REQ_OK)
          {
            Write_Coding_Timeout(CODING_STATE_FREE);
          }
          else /* nvmStatus != pending && nvMStatus != ok */
          {
            Write_Coding_Timeout(CODING_STATE_ERROR);
          }
        }
        else if (Read_Coding_Timeout() == CODING_STATE_WRITE_TO_NVM)
        {
          if (Rte_Call_NvM_ControlLink_WriteBlock(NULL_PTR) == RTE_E_OK)
          {
            /* Change to state WAIT_FOR_NVM. */
            Write_Coding_Timeout(CODING_STATE_WAIT_FOR_NVM);
          }
          else
          {
            Write_Coding_Timeout(CODING_STATE_ERROR);
          }
        }
        else /* must be CODING_STATE_READ_FROM_NVM */
        {
          if (Rte_Call_NvM_ControlLink_ReadBlock(NULL_PTR) == RTE_E_OK)
          {
            /* Change to state WAIT_FOR_NVM. */
            Write_Coding_Timeout(CODING_STATE_WAIT_FOR_NVM);
          }
          else
          {
            Write_Coding_Timeout(CODING_STATE_ERROR);
          }
        }
      }
    }
    else
    {
      Write_Coding_Timeout(CODING_STATE_ERROR);
    }
  }
} /* PRQA S 6030, 6050, 6080 4 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#if (SSA_CODINGDID == STD_ON)
/**********************************************************************************************************************
 * Coding_MarkReceived()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
SSA_CODING_LOCAL_INLINE FUNC(boolean, Ssa_Coding_CODE) Coding_MarkReceived(uint16 didIdx)
{
  uint8 i = 0u;
  uint16 id = didIdx;
  boolean retVal = FALSE;

  /* #10 Search the array index and the bit position of the DID's marker bit. */
  while (id >= 32u) /* FETA_SSA_CODING_MONOTONIC_WHILE_LOOP_DOWN */
  {
    id -= 32u;
    i++;
  }

  /* #20 If the marker bit is not set, set it and return TRUE, else return FALSE. */
  if(i < Ssa_GetSizeOfDidHandled())
  {
    if ((Ssa_GetDidHandled(i) & (((uint32)1u) << id)) == 0u)
    {
      Ssa_SetDidHandled(i, Ssa_GetDidHandled(i) | (((uint32)1u) << id));
      retVal = TRUE;
    }
  }
  return retVal;
}
#endif

/**********************************************************************************************************************
 * Coding_Abort()
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
SSA_CODING_LOCAL FUNC(void, Ssa_Coding_CODE) Coding_Abort(boolean cancel)
{
#if (SSA_CODINGDID == STD_ON)
  uint8 i;
#endif

  /* #5 Cancel the signature verification. Trigger retry if it failed. */
  if (cancel == TRUE)
  {
    if (Rte_Call_SsaCdd_Csm_CancelJob(SSA_CODING_SIGNATURE_VERIFY_JOB_ID, 0u) != E_OK)
    {
      Coding_CancelSigVerify = 10u;
    }
  }

  /* Abort former process */
  /* #10 Clear all DID handled flags. */
#if (SSA_CODINGDID == STD_ON)
  for (i = 0u; i < Ssa_GetSizeOfDidHandled(); i++)
  {
    Ssa_SetDidHandled(i, 0u);
  }
#endif
  /* #20 Reset state variables. */
  Coding_WriteDataState = CODING_WRITEDATA_STATE_IDLE;
  Coding_CurrentDiagChanId = SSA_RIGHTSM_DIAG_INVALID_CHAN_ID;
  Coding_LastDiagChanId = SSA_RIGHTSM_DIAG_INVALID_CHAN_ID;

  /* #30 Reset all signature verify states. */
  Coding_SigVerifyStartState = SSA_CODING_ASYNC_STATE_IDLE;
#if (SSA_CODINGDID == STD_ON)
  Coding_SigVerifyUpdateState = SSA_CODING_ASYNC_STATE_IDLE;
#endif
  Coding_SigVerifyFinishState = SSA_CODING_ASYNC_STATE_IDLE;

  (void)Rte_Switch_Coding_Mode_CodingStatus(RTE_MODE_Coding_Mode_CODING_FAILED);  /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */
  /* #40 Set the general coding state to FAILED. */
  Write_Coding_Timeout(CODING_STATE_FAILED);
}

#if (SSA_CODINGDID == STD_ON)
/**********************************************************************************************************************
 * Coding_SignatureVerifyUpdate()
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
SSA_CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_SignatureVerifyUpdate(uint16 didIdx, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) RequestData, uint16 DataSize, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode)
{
  Std_ReturnType retVal = RTE_E_OK;
  Crypto_VerifyResultType result;

  /* #10 Check that coding sequence is ongoing. */
  if ((DataSize < SSA_CODING_DATA_BUFFER_SIZE) && (Read_Coding_Timeout() > CODING_TIMEOUT_OFFSET)) /* second condition always true */
  {
    /* #20 CHeck that DID has not been handled yet. */
    if (Coding_MarkReceived(didIdx) == TRUE)
    {
      /* #22 Copy the coding data into a static storage for asynchronous CSM operation. */
      Ssa_MemCpy(Coding_DataBuffer, RequestData, DataSize);

      /* #24 Check that the next very update can be executed. */
      if (Coding_SigVerifyUpdateState == SSA_CODING_ASYNC_STATE_IDLE)
      {
        Coding_SigVerifyUpdateState = SSA_CODING_ASYNC_STATE_WAIT;

        /* #30 Restart the coding timeout counter. */
        Write_Coding_Timeout(CODING_TIMEOUT);

        /* #40 Update the signature verification with the requested data. */
        /* Call SignatureVerify with CRYPTO_OPERATIONMODE_UPDATE */
        if (Rte_Call_SsaCdd_Csm_SignatureVerify(SSA_CODING_SIGNATURE_VERIFY_JOB_ID, 2u, Coding_DataBuffer, DataSize, Coding_DataBuffer, 0u, &result) != E_OK)
        {
          Coding_SigVerifyUpdateState = SSA_CODING_ASYNC_STATE_IDLE;
          /* result parameter is not of interest because of CRYPTO_OPERATIONMODE_UPDATE */
          *ErrorCode = DCM_E_GENERALREJECT;
          retVal = RTE_E_ServiceRequestNotification_E_NOT_OK;
        }
# if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_OFF)
        else
        {
          Coding_SigVerifyUpdateState = SSA_CODING_ASYNC_STATE_IDLE;
        }
# endif
      }
      /* #45 Callback from last verify update not yet arrived. */
      else
      {
        /* Successive WriteByDIDs come in to fast. */
        retVal = RTE_E_ServiceRequestNotification_E_NOT_OK;
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      }
    }
    else
    {
      /* A WriteByDID must not be repeated within the same sequence (IS-1870) */
      retVal = RTE_E_ServiceRequestNotification_E_NOT_OK;
      *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
    }
  }
  else
  {
    /* Request is coding relevant but coding not active, reject it */
    retVal = RTE_E_ServiceRequestNotification_E_NOT_OK;
    *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
  }
  return retVal;
}
#endif

/**********************************************************************************************************************
 * Coding_CompareVIN()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_CODING_LOCAL FUNC(boolean, Ssa_Coding_CODE) Coding_CompareVIN(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) vin1, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) vin2)
{
  boolean isEqual = TRUE;
  uint8 i;
  /* #10 Compare two VINs byte-by-byte. */
  for (i = 0u; i < SSA_SIZEOF_VIN; i++)
  {
    if (vin1[i] != vin2[i])
    {
      isEqual = FALSE;
      break;
    }
  }
  return isEqual;
}

/**********************************************************************************************************************
 * Coding_ProcessVinState()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
SSA_CODING_LOCAL FUNC(void, Ssa_Coding_CODE)  Coding_ProcessVinState(VIN_Status newVinState, uint8 vinStateProcType)
{
  /* #10 Set the new VIN state or update it (i.e. set it only if different from the current state). */
  Rte_Enter_Coding_ExclusiveArea_VIN();
  if ((vinStateProcType == SSA_VIN_STATE_SET)
    || ((vinStateProcType == SSA_VIN_STATE_UPDATE) && (newVinState != Coding_VIN_State)))
  {
    Coding_VIN_State = newVinState;
    Rte_Exit_Coding_ExclusiveArea_VIN();

    /* #20 Notify the new VIN status. */
    (void)Rte_Write_Coding_VINStatus_status(newVinState);

    /* #30 Set DEM event status for DTC 0x164456 to "passed" if new VIN state is VIN_CORRECT_RECEIVED else to "failed". */
    if (newVinState == VIN_STATUS_VIN_CORRECT_RECEIVED)
    {
      (void)Rte_Call_DTC_0x164456_SetEventStatus(DEM_EVENT_STATUS_PASSED);
    }
    else
    {
     /* must be VIN_STATUS_NEW_VIN_RECEIVED or VIN_STATUS_VIN_NOT_RECEIVED */
      (void)Rte_Call_DTC_0x164456_SetEventStatus(DEM_EVENT_STATUS_FAILED);
    }
  }
  else
  {
    Rte_Exit_Coding_ExclusiveArea_VIN();
  }
}

/**********************************************************************************************************************
 * Coding_ChangeVin()
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
 */
SSA_CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ChangeVin(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) vin, uint8 origin)
{
  Std_ReturnType retVal = E_OK;
  boolean isEqual;
  VIN_Status newState;

  /* #10 Check if new VIN is allowed be stored as Current VIN. It must no be locked. */
  Rte_Enter_Coding_ExclusiveArea_VIN();
  if (Coding_IsVinLocked())
  {
    Rte_Exit_Coding_ExclusiveArea_VIN();
    /* VIN is locked */
    retVal = RTE_E_Coding_VINControl_E_NOT_OK;
  }
  else
  {
    /* #20 The new VIN must not be the default VIN received by broadcast. */
    boolean newIsDefault = Coding_CompareVIN((P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))(Rte_CData_Coding_Storage_DefaultValue()->VIN), vin);
    if (!((origin == CODING_VIN_CHANGE_BC) && newIsDefault))
    {
      /* #30 Proceed only if the new VIN is different from the CurrentVIN. */
      isEqual = Coding_CompareVIN(vin, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))(Rte_Pim_CurrentVIN()->VIN));
      if (!isEqual)
      {
        /* #40 Change persistent Current VIN to the retrieved one. */
        Ssa_MemCpy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))(Rte_Pim_CurrentVIN()->VIN), vin, SSA_SIZEOF_VIN);
        /* #50 Set attribute indicating if newly stored VIN is the default value or not. */
        if (newIsDefault == TRUE)
        {
          Coding_ClearAttribute(CODING_ATTRIBUTEMASK_STORED_VIN_IS_NOT_DEFAULT_VALUE);
        }
        else
        {
          Coding_SetAttribute(CODING_ATTRIBUTEMASK_STORED_VIN_IS_NOT_DEFAULT_VALUE);
        }
        Rte_Exit_Coding_ExclusiveArea_VIN();

        /* #60 Request for writing the NV RAM block due to changed VIN and VIN attributes. */
        Coding_CurrentVinNvmWriteRequested = TRUE;

        /* #70 If the coding sequence is ongoing abort and restore NvM data. */
        if (Read_Coding_Timeout() > CODING_TIMEOUT_OFFSET)
        {
          /* #75 Abort and request cancellation of the signature verification. */
          Coding_Abort(TRUE);
        }

        /* #80 Log change VIN event if the VIN that is stored has changed. */
        (void)Rte_Call_SecLog_ChangeVinEvent_ChangeVin(vin);
      }
      else
      {
        Rte_Exit_Coding_ExclusiveArea_VIN();
      }
    }
    else
    {
      Rte_Exit_Coding_ExclusiveArea_VIN();
    }
  }

  /* #90 Set state depending on whether the received VIN is different from Coding VIN or not
        (and do this also if VIN is locked) */
  Rte_Enter_Coding_ExclusiveArea_VIN();
  isEqual = Coding_CompareVIN(
    vin,
    (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))(Rte_Pim_CodingVIN()->VIN));
  Rte_Exit_Coding_ExclusiveArea_VIN();

  /* set state */
  if (isEqual)
  {
    newState = VIN_STATUS_VIN_CORRECT_RECEIVED;
  }
  else
  {
    newState = VIN_STATUS_NEW_VIN_RECEIVED;
  }
  Coding_ProcessVinState(newState, SSA_VIN_STATE_UPDATE);

  return retVal;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/**********************************************************************************************************************
 * Coding_SignatureVerify_OpModeStreamStart()
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
SSA_CODING_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_SignatureVerify_OpModeStreamStart(void)
{
  Std_ReturnType retVal = SSA_E_PENDING;

  /* #10 Check initially the state: If in state "wait" return "pending". */
  if (Coding_SigVerifyStartState == SSA_CODING_ASYNC_STATE_WAIT)
  {
    retVal = SSA_E_PENDING;
  }
  /* #20 Else (not in state idle): */
  else
  {
    /* #30 If state is "idle": */
    if (Coding_SigVerifyStartState == SSA_CODING_ASYNC_STATE_IDLE)
    {
      /* #40 Set state to "wait" as callback could occur inside of Verify() */
      Coding_SigVerifyStartState = SSA_CODING_ASYNC_STATE_WAIT;
      /* #50 Asynchronously call signature verify with streaming mode START|UPDATE. */
      retVal = Rte_Call_SsaCdd_Csm_SignatureVerify(SSA_CODING_SIGNATURE_VERIFY_JOB_ID, 3u, Coding_Vin, SSA_SIZEOF_VIN, Coding_Vin, 0u, &Coding_VerifyResult);

      /* #60 Check the return value: */
#if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)
      if ((retVal == SSA_CRYPTO_E_BUSY) || (retVal == SSA_CRYPTO_E_QUEUE_FULL))
      {
        /* #62 Fall back to state "idle" if Csm returns "busy" or "queue full" and return E_PENDING. */
        Coding_SigVerifyStartState = SSA_CODING_ASYNC_STATE_IDLE;
        retVal = SSA_E_PENDING;
      }
      else if (retVal == RTE_E_OK)
      {
        /* #66 Remain in current state if Csm returns E_OK and return E_PENDING. Now wait for callback. */
        retVal = SSA_E_PENDING;
      }
#else
      if (retVal == RTE_E_OK)
      {
        Coding_SigVerifyStartState = SSA_CODING_ASYNC_STATE_READY;
      }
#endif
      else
      {
        /* #64 Fall back to state "idle" if Csm returns "busy" or "queue full" and return E_NOT_OK. */
        Coding_SigVerifyStartState = SSA_CODING_ASYNC_STATE_IDLE;
        retVal = E_NOT_OK;
      }
    }

    /* #70 Immediately after the Csm call check the state. */
    if (Coding_SigVerifyStartState == SSA_CODING_ASYNC_STATE_READY)
    {
      /* #72 If state is "ready" fall back to "idle" and return E_OK. */
      Coding_SigVerifyStartState = SSA_CODING_ASYNC_STATE_IDLE;
      retVal = RTE_E_OK;
    }
    else if (Coding_SigVerifyStartState == SSA_CODING_ASYNC_STATE_FAILED)
    {
      /* #74 Else if state is "failed" fall back to "idle" and return E_NOT_OK. */
      Coding_SigVerifyStartState = SSA_CODING_ASYNC_STATE_IDLE;
      /* Callback returned with error */
      retVal = E_NOT_OK;
    }
    else
    {
      /* #76 Return E_PENDING. Waiting for callback notification. */
    }
  }

  return retVal;
} /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Coding_HandleCodingTimeoutAndCancelation()
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
SSA_CODING_LOCAL_INLINE FUNC(void, Ssa_Coding_CODE) Coding_HandleCodingTimeoutAndCancelation(void)
{
  /* #10 If the coding sequence is ongoing: */
  if (Read_Coding_Timeout() > CODING_TIMEOUT_OFFSET)
  {
    /* #20 Decrement the coding timeout counter. */
    Decrement_Coding_Timeout();
    if (Read_Coding_Timeout() == CODING_TIMEOUT_OFFSET)
    {
      /* #30 Abort the coding sequence when timeout reached and read the coding relevant NvM Ram blocks. */
      /* Abort and request the cancellation of the signature verification. */
      Coding_Abort(TRUE);
      (void)Coding_PerformNvM();
    }
  }
  /* #40 Else if the coding state is FAILED read the coding relevant NvM Ram blocks. */
  else if (Read_Coding_Timeout() == CODING_STATE_FAILED)
  {
    (void)Coding_PerformNvM();
  }
  else
  {
    /* No action. */
    /* The coding timeout state might remain in CODING_STATE_WAIT_FOR_NVM, but this is checked before a new coding
     * sequence with routine evaluate certificate is called. */
  }

  /* #50 Check if cancellation of the signature verification is still requested. */
  if (Coding_CancelSigVerify > 0u)
  {
    /* #60 Try to cancel the signature verify job. */
    Coding_CancelSigVerify--;
    if (Rte_Call_SsaCdd_Csm_CancelJob(SSA_CODING_SIGNATURE_VERIFY_JOB_ID, 0u) == E_OK)
    {
      /* #70 If cancellation succeeded the clear the cancel request counter. */
      Coding_CancelSigVerify = 0u;
    }
  }
}

/**********************************************************************************************************************
 * Coding_CheckAndParseCodingCert()
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
SSA_CODING_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_CheckAndParseCodingCert(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Data_Verification_Certificate,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) Verification_Result,
  uint16 DataLength,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedCertStructure,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode)
{
  Std_ReturnType retVal = E_OK;

  /* assertions for calling Rte_Call_CertP_Functions_Certificate_Parse */
  /*@ assert &Data_Verification_Certificate[2] != NULL_PTR; */
  /*@ assert parsedCertStructure != NULL_PTR; */

  /* #10 Check minimum length of data verification certificate. */
  if (DataLength < 2u)
  {
    retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK;
    *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  /* #20 Check input data length. It must not be smaller than the certificate length. */
  else if (DataLength < (2u + ((uint16)((((uint16)(Data_Verification_Certificate[0])) << 8u) | ((uint16)(Data_Verification_Certificate[1]))))))
  {
    retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK;
    *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  /* #30 Parse the data verification certificate. */
  /* Check against RTE in buffer CertP_RawCertBufferType: Data_Verification_Certificate: uint8* is of type Dcm_Data2002ByteType */
  else if (Rte_Call_CertP_Functions_Certificate_Parse(&Data_Verification_Certificate[2], (uint16)(DataLength - 2u), parsedCertStructure) != E_OK) /* VCA_SSA_CODING_NULL_PTR_REQUIREMENTS_VIOLATED */
  {
    retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK;
    *ErrorCode = DCM_E_GENERALREJECT;
  }
  /* #40 Check the verification result of parsing the certificate. */
  else if (parsedCertStructure->verificationResult != CERTP_VER_PARSE_OK)
  {
    /* Parsing failed */
    *Verification_Result = CERTP_VER_INVALID_FORMAT;
  }
  /* #50 Return a positive verification result only if all checks passed, else "invalid format" is set. */
  else
  {
    *Verification_Result =  CERTP_VER_PARSE_OK;
  }
  return retVal;
}

/**********************************************************************************************************************
 * Coding_PrepareSignatureVerification()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_CODING_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_PrepareSignatureVerification(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) verificationKey, uint16 verificationKeyLength)
{
  Std_ReturnType retVal;

  /* #10 Start the coding time monitoring. */
  Write_Coding_Timeout(CODING_TIMEOUT);
  /* #20 Switch the coding mode to CODING_ACTIVE. */
  retVal = Rte_Switch_Coding_Mode_CodingStatus(RTE_MODE_Coding_Mode_CODING_ACTIVE);
  /* #30 Set the public key from the data verification certificate as signature verification key. */
  retVal |= Rte_Call_Key_SignatureRamKey_KeyElementSet(SSA_KE_SIGNATURE_KEY, verificationKey, (uint32)verificationKeyLength);
  retVal |= Rte_Call_Key_SignatureRamKey_KeySetValid();

  /* #40 Copy the stored current VIN to a local buffer within an exclusive area. */
  Rte_Enter_Coding_ExclusiveArea_VIN();
  Ssa_MemCpy((P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Coding_Vin, (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_CurrentVIN()->VIN, SSA_SIZEOF_VIN);
  Rte_Exit_Coding_ExclusiveArea_VIN();

  return retVal;
}

/**********************************************************************************************************************
 * Coding_HandleNVM()
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
SSA_CODING_LOCAL_INLINE FUNC(void, Ssa_Coding_CODE) Coding_HandleNVM(void)
{
  Std_ReturnType ret;
  NvM_RequestResultType errorStatus = NVM_REQ_PENDING;

  /* #10 Check that writing the Coding VIN NV block has been requested and that writing to NVM is not ongoing. */
  if ((Coding_CurrentVinNvmWriteRequested == TRUE) && (Coding_CurrentVinNvmWriteState == CODING_NVM_WRITE_STATE_IDLE))
  {
    /* #20 Copy the Coding VIN RAM block data to a mirror RAM block within an exclusive area.
     *     Clear the request and start the writing to NVM. */
    Rte_Enter_Coding_ExclusiveArea_VIN();
    Rte_Pim_CurrentVINMirror()->attributes = Rte_Pim_CurrentVIN()->attributes;
    Ssa_MemCpy(
      (P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_CurrentVINMirror()->VIN,
      (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_CurrentVIN()->VIN,
      SSA_SIZEOF_VIN);
    Coding_CurrentVinNvmWriteRequested = FALSE;
    Coding_CurrentVinNvmWriteState = CODING_NVM_WRITE_STATE_START;
    Rte_Exit_Coding_ExclusiveArea_VIN();
  }

  /* #30 Check if the writing to NVM is ongoing. */
  if (Coding_CurrentVinNvmWriteState != CODING_NVM_WRITE_STATE_IDLE)
  {
    /* #40 Get status of NVRAM block. */
    ret = Rte_Call_NvM_CurrentVIN_GetErrorStatus(&errorStatus);
    if ((ret == E_OK) && (errorStatus != NVM_REQ_PENDING))
    {
      /* #50 Write NV block if it has been started and do not change back to idle state as long as NVRAM block status is pending. */
      if (Coding_CurrentVinNvmWriteState == CODING_NVM_WRITE_STATE_START)
      {
        if (Rte_Call_NvM_CurrentVIN_WriteBlock((dtRef_const_VOID)(Rte_Pim_CurrentVINMirror())) == E_OK) /* PRQA S 0314 */ /* MD_SSA_P2VOID_CAST */
        {
          /* If a writeBlock call fails repeadedly, eventually a timeout will occur. */
          Coding_CurrentVinNvmWriteState = CODING_NVM_WRITE_STATE_PENDING;
        }
      }
      /* #60 Evaluate the result of a finished write request and set the Coding_CurrentVinNvmWriteState. */
      else
      {
        /* State must be CODING_NVM_WRITE_STATE_PENDING */
        if (errorStatus == NVM_REQ_OK)
        {
          Coding_CurrentVinNvmWriteState = CODING_NVM_WRITE_STATE_IDLE;
        }
        else /* (errorStatus != NVM_REQ_OK) && (errorStatus != NVM_REQ_PENDING) */
        {
          /* Indicate failure, the state has to be set back to idle outside the mainfunction. */
          Coding_CurrentVinNvmWriteState = CODING_NVM_WRITE_STATE_FAILURE;
        }
      }
    }
  }
  else
  {
    /* no action */
  }
}

/**********************************************************************************************************************
 * Coding_VerifySignature_HandleStatesOpStatusPending()
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
 */
SSA_CODING_LOCAL FUNC(boolean, Ssa_Coding_CODE) Coding_VerifySignature_HandleStatesOpStatusPending(Std_ReturnType* returnValue)
{
  boolean isStateHandled = TRUE;

  switch (Coding_SigVerifyFinishState)
  {
  case SSA_CODING_ASYNC_STATE_WAIT:
    *returnValue = RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING;
    break;
  case SSA_CODING_ASYNC_STATE_WAIT_NVM:
    /* Fall through */
  case SSA_CODING_ASYNC_STATE_ROLLBACK_WAIT:
    /* If OpStatus is pending, verification was successful, otherwise INVALID_SIGNATURE had already be returned */
    (void) Coding_PerformNvM();

    if (Read_Coding_Timeout() == CODING_STATE_FREE)
    {
      if (Coding_SigVerifyFinishState == SSA_CODING_ASYNC_STATE_WAIT_NVM)
      {
        Rte_Enter_Coding_ExclusiveArea_VIN();

        /* adopt the CurrentVIN as CodingVIN (the attributes of the CodingVIN are unused) */
        Ssa_MemCpy(
          (P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_CodingVIN()->VIN,
          (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_CurrentVIN()->VIN,
          SSA_SIZEOF_VIN);

        /* prepare the CodingVIN mirror RAM block for writing to NVM */
        Rte_Pim_CodingVINMirror()->attributes = Rte_Pim_CodingVIN()->attributes;
        Ssa_MemCpy(
          (P2VAR(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_VAR))Rte_Pim_CodingVINMirror()->VIN,
          (P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA))Rte_Pim_CodingVIN()->VIN,
          SSA_SIZEOF_VIN);

        Rte_Exit_Coding_ExclusiveArea_VIN();

        *returnValue = RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING;
        Coding_SigVerifyFinishState = SSA_CODING_ASYNC_STATE_CODINGVIN_NVM_WRITE;
      }
      else
      {
        *returnValue =
          (Std_ReturnType)((Coding_VerifySignatureErrorCode == DCM_E_POSITIVERESPONSE) ? RTE_E_OK : RTE_E_RoutineServices_Routine_Verify_Signature_E_NOT_OK);
        Coding_SigVerifyFinishState = SSA_CODING_ASYNC_STATE_IDLE;
      }
    }
    else if (Read_Coding_Timeout() == CODING_STATE_ERROR)
    {
      /* Failed to synchronize to non-volatile memory */
      Coding_SigVerifyFinishState = SSA_CODING_ASYNC_STATE_IDLE;
      Coding_VerifySignatureVerificationResult = SSA_VER_RES_VERIFY_SIGNATURE_FAILED_TO_SYNCHRONIZE_TO_NON_VOLATILE_MEMORY;
      *returnValue = RTE_E_OK;
    }
    else
    {
      *returnValue = RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING;
      /* remain in current state */
    }
    break;

  case SSA_CODING_ASYNC_STATE_CODINGVIN_NVM_WRITE:
    /* Fall through. */
  case SSA_CODING_ASYNC_STATE_CODINGVIN_NVM_WAIT:
  {
    NvM_RequestResultType errorStatus = NVM_REQ_PENDING;

    /* get status of NVRAM block. */

    *returnValue = Rte_Call_NvM_CodingVIN_GetErrorStatus(&errorStatus);
    if ((*returnValue == E_OK) && (errorStatus != NVM_REQ_PENDING))
    {
      /* write NV block */
      if (Coding_SigVerifyFinishState == SSA_CODING_ASYNC_STATE_CODINGVIN_NVM_WRITE)
      {
        if (Rte_Call_NvM_CodingVIN_WriteBlock((dtRef_const_VOID)(Rte_Pim_CodingVINMirror())) == E_OK) /* PRQA S 0314 */ /* MD_SSA_P2VOID_CAST */
        {
          *returnValue = RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING;
          Coding_SigVerifyFinishState = SSA_CODING_ASYNC_STATE_CODINGVIN_NVM_WAIT;
        }
      }
      /* must be SSA_CODING_ASYNC_STATE_CODINGVIN_NVM_WAIT */
      else
      {
        Coding_SigVerifyFinishState = SSA_CODING_ASYNC_STATE_IDLE;
        if (errorStatus == NVM_REQ_OK)
        {
          *returnValue = RTE_E_OK;
          /* set new VIN state "VIN correct received" */
          Coding_ProcessVinState(VIN_STATUS_VIN_CORRECT_RECEIVED, SSA_VIN_STATE_SET);
        }
        else /* e.g. NVM_REQ_NOT_OK */
        {
          *returnValue = E_NOT_OK;
          Coding_VerifySignatureErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
          /* The Coding_SigVerifyFinishState does not have to be set to STATE_FAILURE, since the error is handled directly
             by the return value. */
        }
      }
    }
    else
    {
      /* stay in current state */
      *returnValue = RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING;
    }
  }
  break;

  default:
    /* no state handling so far */
    isStateHandled = FALSE;
    break;
  }

  return isStateHandled;
} /* PRQA S 6030, 6050 */ /* MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 * Coding_VerifySignature_HandleStates()
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
SSA_CODING_LOCAL FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_VerifySignature_HandleStates(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Signature_Value)
{
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Verify_Signature_E_NOT_OK;

  /*
   * - Handle only the following state of variable Coding_SigVerifyFinishState:
   *   - SSA_CODING_ASYNC_STATE_IDLE
   *   - SSA_CODING_ASYNC_STATE_INIT
   *   - SSA_CODING_ASYNC_STATE_READY
   *   - SSA_CODING_ASYNC_STATE_FAILED
   */

  if (Coding_SigVerifyFinishState == SSA_CODING_ASYNC_STATE_IDLE)
  {
    /* #20 Check that coding sequence has not run into a time-out and that coding WriteData state is "verification finish". */
    if ((Read_Coding_Timeout() > CODING_TIMEOUT_OFFSET) && (Coding_WriteDataState == CODING_WRITEDATA_STATE_VERIF_FINISH))
    {
      /* Stop timer */
      Write_Coding_Timeout(CODING_TIMEOUT_OFFSET);
      /* reset storage for negative error code */
      Coding_VerifySignatureErrorCode = DCM_E_POSITIVERESPONSE;
      Coding_SigVerifyFinishState = SSA_CODING_ASYNC_STATE_INIT;
    }
    else
    {
      /* Abort the coding and request cancellation of signature verification. */
      Coding_Abort(TRUE);
      Coding_VerifySignatureErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      retVal = RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING;
      Coding_SigVerifyFinishState = SSA_CODING_ASYNC_STATE_ROLLBACK_WAIT;
    }
  }

  /* If in state "init" change to state "wait" and asynchronously call the signature verify job with operation mode "finish". */
  if (Coding_SigVerifyFinishState == SSA_CODING_ASYNC_STATE_INIT)
  {
    Coding_SigVerifyFinishState = SSA_CODING_ASYNC_STATE_WAIT;
    Coding_VerifyResult = CRYPTO_E_VER_NOT_OK;
    retVal = Rte_Call_SsaCdd_Csm_SignatureVerify(SSA_CODING_SIGNATURE_VERIFY_JOB_ID, 4u, &Coding_VerifyResult, 0u, Signature_Value, 64u, &Coding_VerifyResult);
#if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)
    if ((retVal == SSA_CRYPTO_E_QUEUE_FULL) || (retVal == SSA_CRYPTO_E_BUSY))
    {
      Coding_SigVerifyFinishState = SSA_CODING_ASYNC_STATE_INIT;
      retVal = RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING;
    }
    else if (retVal == RTE_E_OK)
    {
      /* Remain in current state. */
      retVal = RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING;
    }
#else
    if (retVal == RTE_E_OK)
    {
      Coding_SigVerifyFinishState = SSA_CODING_ASYNC_STATE_READY;
    }
#endif
    else
    {
      /* Abort the coding without requesting cancellation of signature verification. */
      Coding_Abort(FALSE);
      Coding_VerifySignatureErrorCode = DCM_E_GENERALREJECT;
      retVal = RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING;
      Coding_SigVerifyFinishState = SSA_CODING_ASYNC_STATE_ROLLBACK_WAIT;
    }
  }

  if (Coding_SigVerifyFinishState == SSA_CODING_ASYNC_STATE_READY)
  {
    if (Coding_VerifyResult != CRYPTO_E_VER_OK)
    {
      /* Abort the coding without requesting cancellation of signature verification. */
      Coding_Abort(FALSE);
      Coding_VerifySignatureVerificationResult = CODING_RC_VERIFYSIG_RES_INVALID_SIGNATURE;
      retVal = RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING;
      Coding_SigVerifyFinishState = SSA_CODING_ASYNC_STATE_ROLLBACK_WAIT;
    }
    else
    {
      /* #60 Set all DIDs as not handled. */
#if (SSA_CODINGDID == STD_ON)
      uint8 i;
      for (i = 0u; i < Ssa_GetSizeOfDidHandled(); i++)
      {
        Ssa_SetDidHandled(i, 0u);
      }
#endif
      (void)Rte_Switch_Coding_Mode_CodingStatus(RTE_MODE_Coding_Mode_CODING_OK);  /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */
      /* #62 Set the general coding state to "successful". */
      Write_Coding_Timeout(CODING_STATE_SUCCESSFUL);
      /* #64 Set the coding WriteData state to "idle". */
      Coding_WriteDataState = CODING_WRITEDATA_STATE_IDLE;
      /* #66 Set the verification result (which is the positive response code of this service) to OK. */
      Coding_VerifySignatureVerificationResult = CODING_RC_VERIFYSIG_RES_SIGNATURE_VERIFICATION_SUCCESSFUL;
      retVal = RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING;
      Coding_SigVerifyFinishState = SSA_CODING_ASYNC_STATE_WAIT_NVM;
    }
  }
  else if (Coding_SigVerifyFinishState == SSA_CODING_ASYNC_STATE_FAILED)
  {
    /* Abort the coding without requesting cancellation of signature verification */
    Coding_Abort(FALSE);
    Coding_VerifySignatureErrorCode = DCM_E_GENERALREJECT;
    retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK;
    Coding_SigVerifyFinishState = SSA_CODING_ASYNC_STATE_IDLE;
  }
  else
  {
    /* No action. Return value is either pending or not ok. */
  }

  return retVal;
}

/**********************************************************************************************************************
 * Coding_CheckCharactersOfVIN()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_CODING_LOCAL FUNC(boolean, Ssa_Coding_CODE) Coding_CheckCharactersOfVIN(P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) vin)
{
  boolean isPrintableAsciiValue = TRUE;
  uint8 i;
  /* #10 Iterate through all characters of the VIN and check each value. */
  for (i = 0u; i < SSA_SIZEOF_VIN; i++)
  {
    if ((vin[i] < 0x21u) || (vin[i] > 0x7Eu))
    {
      isPrintableAsciiValue = FALSE;
      break;
    }
  }
  return isPrintableAsciiValue;
}

#if((SSA_ECU_TYPE == SSA_ECU_TYPE_NORMAL) || (SSA_ECU_TYPE == SSA_ECU_TYPE_GATEWAY))
/**********************************************************************************************************************
* Coding_Restart_VinReceiveTimeout_Counter()
*********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
 *
 *
*/
SSA_CODING_LOCAL FUNC(void, Ssa_Coding_CODE) Coding_Restart_VinReceiveTimeout_Counter(void)
{
  Rte_Enter_Coding_ExclusiveArea_VIN();
  if ((Coding_VIN_State == VIN_STATUS_VIN_NOT_RECEIVED) || (Get_Coding_VinReceiveTimeout_Counter() > 0u))
  {
    /* Restart VinReceiveTimeout counter */
    /* Assumed as atomic write access */
    Set_Coding_VinReceiveTimeout_Counter(CODING_VIN_RECEIVE_TIMEOUT);
  }
  Rte_Exit_Coding_ExclusiveArea_VIN();
}
#endif

/**********************************************************************************************************************
 * Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateIdle()
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
SSA_CODING_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateIdle(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Data_Verification_Certificate,
  uint16 DataLength,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedCertStructure,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode)
{
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_PENDING;

  if (Coding_EvalDataVerifyCertState == CODING_VERIFY_CERT_STATE_IDLE)
  {
    /* #10 Abort an already ongoing secure variant coding sequence. */
    /* also in error state try to read back data */
    if ((Read_Coding_Timeout() > CODING_TIMEOUT_OFFSET) || (Read_Coding_Timeout() == CODING_STATE_ERROR))
    {
      uint8 currentDiagChanId = Coding_CurrentDiagChanId;
      /* Abort the coding and request cancellation of signature verification. */
      Coding_Abort(TRUE);
      /* Coding_Abort() invalidates both Coding_LastDiagChanId and Coding_CurrentDiagChanId (which are equal here) */
      Coding_LastDiagChanId = currentDiagChanId;
      Coding_CurrentDiagChanId = currentDiagChanId;
    }

    /* #20 Check NvM State - Return value not needed - general coding state is checked instead afterwards. */
    (void)Coding_PerformNvM();

    /* #30 Check general coding state. */
    if (Read_Coding_Timeout() == CODING_STATE_FREE)
    {
      uint8 verifyResult;

      /* #40 Parse the certificate containing the signature verification key. */
      retVal = Coding_CheckAndParseCodingCert(Data_Verification_Certificate, &verifyResult, DataLength, parsedCertStructure, ErrorCode);
      if (retVal != E_OK)
      {
        retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK;
      }
      else if (verifyResult != CERTP_VER_PARSE_OK)
      {
        Coding_EvalCertVerificationResult = CODING_RC_EVALCERT_RES_INVALID_FORMAT;
        retVal = RTE_E_OK;
      }
      else
      {
        /* keep PKI role of certificate */
        Coding_PkiRole = (parsedCertStructure->pkiRole == CERTP_PKI_ROLE_USER_CERT_FOR_CODING) ? CERTP_PKI_ROLE_USER_CERT_FOR_CODING : CERTP_PKI_ROLE_VARIANT_CODING;
        /* #50 Proceed state if parsing was successful. */
        Coding_EvalDataVerifyCertState = CODING_VERIFY_CERT_STATE_VERIFY_CERT;
      }
    }
    else if (Read_Coding_Timeout() == CODING_STATE_ERROR)
    {
      Coding_EvalCertVerificationResult = SSA_VER_RES_EVAL_DATA_VERIF_CERT_FAILED_TO_SYNCHRONIZE_TO_NON_VOLATILE_MEMORY;
      retVal = RTE_E_OK;
    }
    else
    {
      /* wait */
    }
  }

  return retVal;
}

/**********************************************************************************************************************
 * Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateVerifyCert()
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
SSA_CODING_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateVerifyCert(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) Data_Verification_Certificate,
  const Std_ReturnType prevRetVal,
  P2VAR(CertP_ParsedCertStructureType, AUTOMATIC, AUTOMATIC) parsedCertStructure,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode)
{
  /* #10 In case Coding_EvalDataVerifyCertState == CODING_VERIFY_CERT_STATE_VERIFY_CERT is not fulfilled,
   *     this function leaves the previous return value unchanged. */
  Std_ReturnType retVal = prevRetVal;

  /* OpStatus might be INITIAL or PENDING */
  if (Coding_EvalDataVerifyCertState == CODING_VERIFY_CERT_STATE_VERIFY_CERT)
  {
    RightsM_AuthNonceType  noNonce = { { 0 }, FALSE };

    /* #20 Verify the data verification certificate against the backend certificate stored on the ECU. */
    /* Check against RTE in buffer CertP_RawCertBufferType: Data_Verification_Certificate: uint8* is of type Dcm_Data2002ByteType */

    /*@ assert &Data_Verification_Certificate[2] != NULL_PTR; */
    /*@ assert parsedCertStructure != NULL_PTR; */
    /*@ assert &noNonce != NULL_PTR; */
    /*@ assert $lengthOf(&Data_Verification_Certificate[2]) >= sizeof(CertP_RawCertBufferType); */ /* VCA_SSA_CODING_LENGTH_SPECIFIED_IN_FCT_CALL */
    retVal = Rte_Call_KeyM_Certificate_VerifyCertWithBackendCert( /* VCA_SSA_CODING_NULL_PTR_REQUIREMENTS_VIOLATED */
      &Data_Verification_Certificate[2],
      parsedCertStructure,
      parsedCertStructure->parsedCertLength,
      Coding_PkiRole,
      &noNonce);

    /* #30 Evaluate verification result. */
    if (retVal == RTE_E_KeyM_Certificate_E_PENDING)
    {
      /* remain in current state */
      retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_PENDING;
    }
    else if (retVal != RTE_E_OK)
    {
      *ErrorCode = DCM_E_GENERALREJECT;
      retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK;
      Coding_EvalDataVerifyCertState = CODING_VERIFY_CERT_STATE_IDLE;
    }
    else if (parsedCertStructure->verificationResult != CRYPTO_E_VER_OK)
    {
      Coding_EvalCertVerificationResult = parsedCertStructure->verificationResult;
      Coding_EvalDataVerifyCertState = CODING_VERIFY_CERT_STATE_IDLE;
    }
    else
    {
      /* #40 If certificate verification was successful, prepare the signature verification
       *     of the coding data with the certificate's key and update state. */
      retVal = Coding_PrepareSignatureVerification(&Data_Verification_Certificate[2u + parsedCertStructure->publicKey.elemDataIdx], parsedCertStructure->publicKey.elemDataLength);
      if (retVal == RTE_E_OK)
      {
        Coding_EvalDataVerifyCertState = CODING_VERIFY_CERT_STATE_VERIFY_DATA;
      }
      else
      {
        *ErrorCode = DCM_E_GENERALREJECT;
        retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK;
        Coding_EvalDataVerifyCertState = CODING_VERIFY_CERT_STATE_IDLE;
      }
    }
  }

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 * Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateVerifyData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
SSA_CODING_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_Evaluate_Data_Verification_Certificate_Start_HandleStateVerifyData(const Std_ReturnType prevRetVal, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode)
{
  /* #10 In case Coding_EvalDataVerifyCertState == CODING_VERIFY_CERT_STATE_VERIFY_CERT is not fulfilled,
   *     this function leaves the previous return value unchanged. */
  Std_ReturnType retVal = prevRetVal;

  /* OpStatus might be INITIAL or PENDING */
  if (Coding_EvalDataVerifyCertState == CODING_VERIFY_CERT_STATE_VERIFY_DATA)
  {
    /* Clear the cancel request counter. */
    Coding_CancelSigVerify = 0u;
    /* #20 If free for starting a new secure variant coding sequence start the signature verification. */
    retVal = Coding_SignatureVerify_OpModeStreamStart();

    /* #30 Evaluate result of signature verification start and reset state. */
    if (retVal == SSA_E_PENDING)
    {
      /* Remain in current state */
      retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_PENDING;
    }
    else if (retVal != RTE_E_OK)
    {
      *ErrorCode = DCM_E_GENERALREJECT;
      retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK;
      Coding_EvalDataVerifyCertState = CODING_VERIFY_CERT_STATE_IDLE;
    }
    else
    {
      /* Ok */
      Coding_EvalCertVerificationResult = CODING_RC_EVALCERT_RES_CERTIFICATE_VERIFIED_SIGNATURE_VERIFICATION_KEY_ACCEPTED;
      Coding_WriteDataState = CODING_WRITEDATA_STATE_WRITEBYDID;
      Coding_EvalDataVerifyCertState = CODING_VERIFY_CERT_STATE_IDLE;
#if (SSA_CODINGDID == STD_ON)
      /* Set signature verify update state to IDLE */
      Coding_SigVerifyUpdateState = SSA_CODING_ASYNC_STATE_IDLE;
#endif
    }
  }

  return retVal;
}


#if (SSA_CODINGDID == STD_ON)
/**********************************************************************************************************************
 * Coding_ServiceRequestNotification_Indication_HandleDid()
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
SSA_CODING_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_Coding_CODE) Coding_ServiceRequestNotification_Indication_HandleDid(uint16 did, uint16 idx, P2CONST(uint8, AUTOMATIC, RTE_SSA_CODING_APPL_DATA) RequestData, uint16 DataSize, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_CODING_APPL_VAR) ErrorCode)
{
  Std_ReturnType retVal = RTE_E_OK;

  /* #10 Check that the last diagnostic channel id equals the current diagnostic channel id and if the
   *     coding WriteDate state is not IDLE. */
  if ((Coding_LastDiagChanId != Coding_CurrentDiagChanId) || (Coding_WriteDataState == CODING_WRITEDATA_STATE_IDLE))
  {
    /* Error */
    retVal = RTE_E_ServiceRequestNotification_E_NOT_OK;
    *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
    /* No abort. */
  }
  else
  {
    /* #20 If the coding WriteDate state is WRITEBYDID: */
    if (Coding_WriteDataState == CODING_WRITEDATA_STATE_WRITEBYDID)
    {
      /* #30 If the did is  the CALID return with NRC "request sequence error. */
      if (did == CODING_CALID)
      {
        /* Error */
        retVal = RTE_E_ServiceRequestNotification_E_NOT_OK;
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
      }
      /* #32 Else (the did is not the CALID) update the signature verification with the requested data
       *     and switch to state WRITEBYDID_OR_CALID. */
      else
      {
# if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)
        /* Next state CODING_WRITEDATA_STATE_WRITEBYDID_OR_CALID is set in callback function. */
# else
        Coding_WriteDataState = CODING_WRITEDATA_STATE_WRITEBYDID_OR_CALID;
# endif
        retVal = Coding_SignatureVerifyUpdate(idx, RequestData, DataSize, ErrorCode);
      }
    }
    /* #40 If the coding WriteDate state is WRITEBYDID_OR_CALID: */
    else if (Coding_WriteDataState == CODING_WRITEDATA_STATE_WRITEBYDID_OR_CALID)
    {
      /* #50 Update the signature verification with the passed id and data. */
      if (did == CODING_CALID)
      {
# if (SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING == STD_ON)
        /* Next state CODING_WRITEDATA_STATE_VERIF_FINISH is set in callback function. */
        /* #60 If the did is the CALID switch to state CALID_RECEIVED (else remain in the current state). */
        Coding_WriteDataState = CODING_WRITEDATA_STATE_CALID_RECEIVED;
# else
        Coding_WriteDataState = CODING_WRITEDATA_STATE_VERIF_FINISH;
# endif
      }
      retVal = Coding_SignatureVerifyUpdate(idx, RequestData, DataSize, ErrorCode);
    }
    else
    {
      /* #70 In all other coding WriteDate states (CODING_WRITEDATA_STATE_VERIF_FINISH, and all undefined states)
       *      return with NRC "request sequence error. */
      retVal = RTE_E_ServiceRequestNotification_E_NOT_OK;
      *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
    }

    /* #80 If an error occurred so far abort the coding sequence. */
    if (retVal != RTE_E_OK)
    {
      /* Abort the coding and trigger cancellation of signature verification if a request sequence error occurred. */
      Coding_Abort((*ErrorCode == DCM_E_REQUESTSEQUENCEERROR) ? TRUE : FALSE);
    }
  }

  return retVal;
}
#endif /* (SSA_CODINGDID == STD_ON) */

#define Ssa_Coding_STOP_SEC_CODE
#include "Ssa_Coding_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/


/**********************************************************************************************************************
*  SAFEBSW JUSTIFICATIONS
*********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

  \ID  VCA_SSA_CODING_NULL_PTR_REQUIREMENTS_VIOLATED
    \DESCRIPTION      According to VCA, the following function might be called outside its specification:
                        1. Rte_Call_CertP_Functions_Certificate_Parse
                        2. Rte_Call_KeyM_Certificate_VerifyCertWithBackendCert
    \COUNTERMEASURE   \R Before calling the functions, all function requirements (specified in Rte.vcaspecs.c) are checked by assertions:
                        1. - rawCertData != NULL_PTR;
                           - parsedCert != NULL_PTR;
                        2. - cert != NULL_PTR
                           - parsedCertStructure != NULL_PTR
                           - expectedNonce != NULL_PTR
                        If all assertions are okay, no specifications are violated.

  \ID  VCA_SSA_CODING_LENGTH_SPECIFIED_IN_FCT_CALL
    \DESCRIPTION      According to VCA, the following assertion is possibly violated:
                        $lengthOf(&Data_Verification_Certificate[2]) >= sizeof(CertP_RawCertBufferType).
    \COUNTERMEASURE   \N A specification ensures that when the function is called,
                      $lengthOf(Data_Verification_Certificate) >= sizeof(Dcm_Data2002ByteType) holds.
                      Since sizeof(CertP_RawCertBufferType) is hard-coded to 910 there is no violation.

VCA_JUSTIFICATION_END */


/***********************************************************************************************************************
 *  FETA JUSTIFICATIONS
 **********************************************************************************************************************/
/* FETA_JUSTIFICATION_BEGIN

  \ID FETA_SSA_CODING_MONOTONIC_WHILE_LOOP_DOWN
    \DESCRIPTION  According to FETA loop may not terminate
                  in function
                  - Coding_MarkReceived()
    \COUNTERMEASURE \N The here applied while loop has the counter variable which is decremented
                       by 32 in each single loop, i.e., the counter variable is strictly monotonically decreasing.
                       The loop's lower bound is 32 and remains unchanged during loop execution.
                       Underflows are prohibited by comparing the counter to the lower bound of 32.

FETA_JUSTIFICATION_END */

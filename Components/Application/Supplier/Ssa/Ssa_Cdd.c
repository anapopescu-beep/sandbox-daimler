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
/*!        \file  Ssa_Cdd.c
 *        \brief  Complex Device Driver of the Standard Security Architecture (Ssa).
 *
 *      \details  The Complex Device Driver provides interfaces to forward not available SWC Services to the BSW.
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
 * KeyM_CertElementIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * KeyM_CertificateIdType
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * KeyM_CsrEncodingType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * KeyM_ServiceCertificateType
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
 *
 * Port Prototypes:
 * ================
 * NvMService_AC2_SRBS
 *   Iterates over all configured blocks and set up correspoding jobs. Acts as fanout from one to many NvM blocks.
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
 *********************************************************************************************************************/

#include "Rte_Ssa_Cdd.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Ssa_Cfg.h"
#include "Csm.h"
#include "NvM.h"
#include "KeyM.h"
#include "Os.h"

#include "Dcm_Types.h"

#ifdef __VCA__  /* COV_SSA_VECTOR_CODE_ANALYZER_STUB_REDIRECTION */
# include "Ssa_Cdd_Redirection.vcaspecs.h"
#endif

/* After this comment only memory mapping files may be included. Due to this turn off lint rule requesting a standard
include guard. */
/*lint -e451 */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#if !defined (SSA_CDD_LOCAL)                   /* COV_SSA_LOCAL */
# define SSA_CDD_LOCAL                                                static
#endif

 /*!  Non-RTE APIs for enable / disable OS interrupts. Use OS APIs by default. */
#if !defined (Ssa_Enter_Cdd_ExclusiveArea_External_S29_Processing) || !defined (Ssa_Exit_Cdd_ExclusiveArea_External_S29_Processing)   /* COV_SSA_CDD_EXCLUSIVE_AREA_OVERWRITABLE TX xf xf */
# define Ssa_Enter_Cdd_ExclusiveArea_External_S29_Processing() SuspendOSInterrupts()
# define Ssa_Exit_Cdd_ExclusiveArea_External_S29_Processing() ResumeOSInterrupts()
#endif

/*! States of Ssa_Cdd_S29MainProcState */
#define SSA_CDD_S29PROCSTATE_IDLE                                     (0u)  /*!< Main function processing is inactive. */
#define SSA_CDD_S29PROCSTATE_ACTIVE_INITIAL                           (1u)  /*!< Main function processing is active. */
#define SSA_CDD_S29PROCSTATE_ACTIVE_PENDING                           (2u)  /*!< Main function processing is still active. */


/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if (SSA_DECOUPLE_EXTERNAL_PROCESSING_SERVICE29 == STD_ON)

typedef struct
{
  Dcm_MsgContextType context;
  Dcm_NegativeResponseCodeType errorCode;
  Std_ReturnType retVal;
} Ssa_Cdd_S29ProcType;

#endif

/**********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/
#if (SSA_DECOUPLE_EXTERNAL_PROCESSING_SERVICE29 == STD_ON)

# define Ssa_Cdd_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "Ssa_Cdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! State variable for processing DiagnosticService_Authentication_0x29.
    This state also works as semaphore controlling access to Ssa_Cdd_S29Proc. */
SSA_CDD_LOCAL VAR(uint8, Ssa_Cdd_VAR_NOINIT) Ssa_Cdd_S29MainProcState;

/* ! Context for processing DiagnosticService_Authentication_0x29 */
SSA_CDD_LOCAL VAR(Ssa_Cdd_S29ProcType, Ssa_Cdd_VAR_NOINIT) Ssa_Cdd_S29Proc;

# define Ssa_Cdd_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "Ssa_Cdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define Ssa_Cdd_START_SEC_CODE
#include "Ssa_Cdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*!
 * \brief       Maps error codes of CSM Key Management API calls.
 * \details     -
 * \param[in]   csmError Returned error from CSM that shall be mapped.
 * \return      RTE_E_SsaCdd_Csm_KeyInterface_E_BUSY    if request was rejected because CSM is busy.
 *              RTE_E_OK                                if request was accepted.
 *              RTE_E_SsaCdd_Csm_KeyInterface_E_NOT_OK  for any others cases.
 * \pre         -
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_CDD_LOCAL FUNC(Std_ReturnType, Ssa_Cdd_CODE) Cdd_MapCsmKeyMgmtErrors(Std_ReturnType csmError);

#define Ssa_Cdd_STOP_SEC_CODE
#include "Ssa_Cdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
 * KeyM_CertElementIdType: Integer in interval [0...65535]
 * KeyM_CertificateIdType: Integer in interval [0...65535]
 * Ssa_ConstDataPtr: DataReference
 * Ssa_DataPtr: DataReference
 * Ssa_LengthPtr: DataReference
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
 * Crypto_OperationModeType: Enumeration of integer in interval [0...255] with enumerators
 *   CRYPTO_OPERATIONMODE_START (1U)
 *   CRYPTO_OPERATIONMODE_UPDATE (2U)
 *   CRYPTO_OPERATIONMODE_STREAMSTART (3U)
 *   CRYPTO_OPERATIONMODE_FINISH (4U)
 *   CRYPTO_OPERATIONMODE_SINGLECALL (7U)
 * Crypto_VerifyResultType: Enumeration of integer in interval [0...1] with enumerators
 *   CRYPTO_E_VER_OK (0U)
 *   CRYPTO_E_VER_NOT_OK (1U)
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
 * KeyM_CsrEncodingType: Enumeration of integer in interval [0...1] with enumerators
 *   KEYM_CSR_ENCODING_NONE (0U)
 *   KEYM_CSR_ENCODING_DER (1U)
 * KeyM_ServiceCertificateType: Enumeration of integer in interval [1...7] with enumerators
 *   KEYM_SERVICE_CERT_REQUEST_CSR (1U)
 *   KEYM_SERVICE_CERT_UPDATE_SIGNED_CSR (2U)
 *   KEYM_SERVICE_CERT_SET_ROOT (3U)
 *   KEYM_SERVICE_CERT_UPDATE_ROOT (4U)
 *   KEYM_SERVICE_CERT_SET_INTERMEDIATE (5U)
 *   KEYM_SERVICE_CERT_UPDATE_INTERMEDIATE (6U)
 *   KEYM_SERVICE_CERT_UPDATE_CRL (7U)
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
 *
 *********************************************************************************************************************/


#define Ssa_Cdd_START_SEC_CODE
#include "Ssa_Cdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_Csm_CancelJob
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CancelJob> of PortPrototype <SsaCdd_CryptoInterface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Cdd_Csm_CancelJob(uint32 jobId, Crypto_OperationModeType operationMode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Csm_CancelJob_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_Csm_CancelJob(uint32 jobId, Crypto_OperationModeType operationMode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Csm_CancelJob (returns application error)
 *********************************************************************************************************************/

  /* #10 Cancel the given job. */
  return Csm_CancelJob(jobId, operationMode);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_Csm_Hash
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Hash> of PortPrototype <SsaCdd_CryptoInterface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Cdd_Csm_Hash(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_DataPtr resultBuffer, Ssa_LengthPtr resultLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Csm_Hash_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_Csm_Hash(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_DataPtr resultBuffer, Ssa_LengthPtr resultLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Csm_Hash (returns application error)
 *********************************************************************************************************************/
  /* No DET Check since parameters are only forwarded to external module. */
  /* #10 Hash given data. */
  return Csm_Hash(jobId, operationMode, dataBuffer, dataLength, resultBuffer, resultLength); /* VCA_SSA_CDD_FORWARDING_PTR_TO_API */
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_Csm_KeyElementCopy
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <KeyElementCopy> of PortPrototype <SsaCdd_KeyInterface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Cdd_Csm_KeyElementCopy(uint32 keyId, uint32 keyElementId, uint32 targetKeyId, uint32 targetKeyElementId)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SsaCdd_Csm_KeyInterface_E_BUSY
 *   RTE_E_SsaCdd_Csm_KeyInterface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Csm_KeyElementCopy_doc
 *********************************************************************************************************************/
 /*!
  * Internal comment removed.
 *
 *
  */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_Csm_KeyElementCopy(uint32 keyId, uint32 keyElementId, uint32 targetKeyId, uint32 targetKeyElementId) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Csm_KeyElementCopy (returns application error)
 *********************************************************************************************************************/

   /* #10 Copy key element from keyId and keyElementId to targetKeyId and targetKeyElementId. */
  return Cdd_MapCsmKeyMgmtErrors(Csm_KeyElementCopy(keyId, keyElementId, targetKeyId, targetKeyElementId));

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_Csm_KeyElementGet
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <KeyElementGet> of PortPrototype <SsaCdd_KeyInterface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Cdd_Csm_KeyElementGet(uint32 keyId, uint32 keyElementId, Ssa_DataPtr keyPtr, Ssa_LengthPtr keyLengthPtr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SsaCdd_Csm_KeyInterface_E_BUSY
 *   RTE_E_SsaCdd_Csm_KeyInterface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Csm_KeyElementGet_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(keyPtr) >= *keyLengthPtr;
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_Csm_KeyElementGet(uint32 keyId, uint32 keyElementId, Ssa_DataPtr keyPtr, Ssa_LengthPtr keyLengthPtr) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Csm_KeyElementGet (returns application error)
 *********************************************************************************************************************/
  /* No DET Check since parameters are only forwarded to external module. */
  /* #10 Get the requested key element for the given key identifier. */
  return Cdd_MapCsmKeyMgmtErrors(Csm_KeyElementGet(keyId, keyElementId, keyPtr, keyLengthPtr)); /* VCA_SSA_CDD_FORWARDING_PTR_TO_API */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_Csm_KeyElementSet
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <KeyElementSet> of PortPrototype <SsaCdd_KeyInterface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Cdd_Csm_KeyElementSet(uint32 keyId, uint32 keyElementId, Ssa_ConstDataPtr keyPtr, uint32 keyLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SsaCdd_Csm_KeyInterface_E_BUSY
 *   RTE_E_SsaCdd_Csm_KeyInterface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Csm_KeyElementSet_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_Csm_KeyElementSet(uint32 keyId, uint32 keyElementId, Ssa_ConstDataPtr keyPtr, uint32 keyLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Csm_KeyElementSet (returns application error)
 *********************************************************************************************************************/
  /* No DET Check since parameters are only forwarded to external module. */
  /* #10 Set the given key element for the given key identifier. */
  return Cdd_MapCsmKeyMgmtErrors(Csm_KeyElementSet(keyId, keyElementId, keyPtr, keyLength));
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_Csm_KeySetValid
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <KeySetValid> of PortPrototype <SsaCdd_KeyInterface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Cdd_Csm_KeySetValid(uint32 keyId)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SsaCdd_Csm_KeyInterface_E_BUSY
 *   RTE_E_SsaCdd_Csm_KeyInterface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Csm_KeySetValid_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_Csm_KeySetValid(uint32 keyId) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Csm_KeySetValid (returns application error)
 *********************************************************************************************************************/
  /* #10 Set the key valid. */
  return Cdd_MapCsmKeyMgmtErrors(Csm_KeySetValid(keyId));
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_Csm_SignatureGenerate
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SignatureGenerate> of PortPrototype <SsaCdd_CryptoInterface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Cdd_Csm_SignatureGenerate(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_DataPtr resultBuffer, Ssa_LengthPtr resultLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Csm_SignatureGenerate_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_Csm_SignatureGenerate(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_DataPtr resultBuffer, Ssa_LengthPtr resultLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Csm_SignatureGenerate (returns application error)
 *********************************************************************************************************************/
  /* No DET Check since parameters are only forwarded to external module. */
  /* #10 Generate signature over given data. */
  return Csm_SignatureGenerate(jobId, operationMode, dataBuffer, dataLength, resultBuffer, resultLength); /* VCA_SSA_CDD_FORWARDING_PTR_TO_API */
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_Csm_SignatureVerify
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SignatureVerify> of PortPrototype <SsaCdd_CryptoInterface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Cdd_Csm_SignatureVerify(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_ConstDataPtr compareBuffer, uint32 compareLength, Ssa_VerifyResultPtr resultBuffer)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SsaCdd_CryptoInterface_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Csm_SignatureVerify_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_Csm_SignatureVerify(uint32 jobId, Crypto_OperationModeType operationMode, Ssa_ConstDataPtr dataBuffer, uint32 dataLength, Ssa_ConstDataPtr compareBuffer, uint32 compareLength, Ssa_VerifyResultPtr resultBuffer) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Csm_SignatureVerify (returns application error)
 *********************************************************************************************************************/
  /* No DET Check since parameters are only forwarded to external module. */
  /* #10 Verify the given signature. */
  return Csm_SignatureVerify(jobId, operationMode, dataBuffer, dataLength, compareBuffer, compareLength, resultBuffer);
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Init_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Ssa_Cdd_CODE) Ssa_Cdd_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_Init
 *********************************************************************************************************************/

#if (SSA_DECOUPLE_EXTERNAL_PROCESSING_SERVICE29 == STD_ON)
  Ssa_Cdd_S29MainProcState = SSA_CDD_S29PROCSTATE_IDLE;
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_KeyM_CsrElementSet
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CsrElementSet> of PortPrototype <SsaCdd_CertInterface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Cdd_KeyM_CsrElementSet(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, KeyM_CsrEncodingType EncodingType, Ssa_ConstDataPtr ElementData, uint32 ElementDataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SsaCdd_KeyM_CertInterface_E_NOT_OK
 *   RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_KEY_CERT_SIZE_MISMATCH
 *   RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_PARAMETER_MISMATCH
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_KeyM_CsrElementSet_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_KeyM_CsrElementSet(KeyM_CertificateIdType CertId, KeyM_CertElementIdType CertElementId, KeyM_CsrEncodingType EncodingType, Ssa_ConstDataPtr ElementData, uint32 ElementDataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_KeyM_CsrElementSet (returns application error)
 *********************************************************************************************************************/
  /* No DET Check since parameters are only forwarded to external module. */
  /* #10 Set CSR element. */
  return KeyM_CsrElementSet(
    CertId,
    CertElementId,
    EncodingType,
    ElementData,
    ElementDataLength);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_KeyM_GetCertificate
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetCertificate> of PortPrototype <SsaCdd_CertInterface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Cdd_KeyM_GetCertificate(KeyM_CertificateIdType CertId, Ssa_DataPtr CertData, Ssa_LengthPtr CertDataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SsaCdd_KeyM_CertInterface_E_NOT_OK
 *   RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_KEY_CERT_EMPTY
 *   RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_KEY_CERT_READ_FAIL
 *   RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_KEY_CERT_SIZE_MISMATCH
 *   RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_PARAMETER_MISMATCH
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_KeyM_GetCertificate_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_KeyM_GetCertificate(KeyM_CertificateIdType CertId, Ssa_DataPtr CertData, Ssa_LengthPtr CertDataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_KeyM_GetCertificate (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal;
  KeyM_CertDataType certificate;

  /* ----- Development Error Checks ------------------------------------- */
  /* A DET check is included, since the parameters are not directly forwarded to the KeyM module,
   * but via the local variable certificate and since the parameter CertDataLength is dereferenced
   * before being passed. */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((CertData == NULL_PTR)
    || (CertDataLength == NULL_PTR))
  {
    retVal = RTE_E_SsaCdd_KeyM_CertInterface_E_NOT_OK;
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    certificate.certData = CertData;
    certificate.certDataLength = *CertDataLength;

    /* #10 Get certificate data. */
    /*@ assert &certificate != NULL_PTR; */
    retVal = KeyM_GetCertificate(CertId, &certificate); /* VCA_SSA_CDD_FORWARDING_PTR_TO_API */

    *CertDataLength = certificate.certDataLength;
  }

  return retVal;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_KeyM_ServiceCertificate
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ServiceCertificate> of PortPrototype <SsaCdd_CertInterface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Cdd_KeyM_ServiceCertificate(KeyM_ServiceCertificateType Service, Ssa_ConstDataPtr CertNamePtr, uint32 CertNameLength, Ssa_ConstDataPtr RequestData, uint32 RequestDataLength, Ssa_DataPtr ResponseData, uint32 ResponseDataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SsaCdd_KeyM_CertInterface_E_NOT_OK
 *   RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_BUSY
 *   RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_CERT_INVALID_CHAIN_OF_TRUST
 *   RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_KEY_CERT_EMPTY
 *   RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_KEY_CERT_SIZE_MISMATCH
 *   RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_PARAMETER_MISMATCH
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_KeyM_ServiceCertificate_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_KeyM_ServiceCertificate(KeyM_ServiceCertificateType Service, Ssa_ConstDataPtr CertNamePtr, uint32 CertNameLength, Ssa_ConstDataPtr RequestData, uint32 RequestDataLength, Ssa_DataPtr ResponseData, uint32 ResponseDataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_KeyM_ServiceCertificate (returns application error)
 *********************************************************************************************************************/
  /* No DET Check since parameters are only forwarded to external module. */
  /* #10 Request for certificate service. */
  return KeyM_ServiceCertificate( /* VCA_SSA_CDD_FORWARDING_PTR_TO_API */
    Service,
    CertNamePtr,
    CertNameLength,
    RequestData,
    RequestDataLength,
    ResponseData,
    ResponseDataLength);

  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_KeyM_SetCertificate
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetCertificate> of PortPrototype <SsaCdd_CertInterface>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Cdd_KeyM_SetCertificate(KeyM_CertificateIdType CertId, Ssa_DataPtr CertData, uint32 CertDataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_SsaCdd_KeyM_CertInterface_E_NOT_OK
 *   RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_KEY_CERT_SIZE_MISMATCH
 *   RTE_E_SsaCdd_KeyM_CertInterface_KEYM_E_PARAMETER_MISMATCH
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_KeyM_SetCertificate_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_KeyM_SetCertificate(KeyM_CertificateIdType CertId, Ssa_DataPtr CertData, uint32 CertDataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_KeyM_SetCertificate (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal;
  KeyM_CertDataType certificate;

  /* ----- Development Error Checks ------------------------------------- */
  /* A DET check is included, since the parameters are not directly forwarded to the KeyM module,
   * but via the local variable certificate. */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (CertData == NULL_PTR)
  {
    retVal = RTE_E_SsaCdd_KeyM_CertInterface_E_NOT_OK;
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    certificate.certData = CertData;
    certificate.certDataLength = CertDataLength;

    /* #10 Set certificate. */
    retVal = KeyM_SetCertificate(CertId, &certificate);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_MainFunction
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_DiagnosticService_Authentication_0x29_Authenticate(Dcm_OpStatusType OpStatus, Ssa_ConstDataPtr ReqData, uint32 ReqBufSize, uint32 ReqDataLen, Ssa_DataPtr ResData, uint32 ResBufSize, uint32 *ResDataLen, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DiagnosticService_Authentication_0x29_DCM_E_FORCE_RCRRP, RTE_E_DiagnosticService_Authentication_0x29_DCM_E_PENDING, RTE_E_DiagnosticService_Authentication_0x29_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_MainFunction_doc
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

FUNC(void, Ssa_Cdd_CODE) Ssa_Cdd_MainFunction(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_MainFunction
 *********************************************************************************************************************/
#if (SSA_DECOUPLE_EXTERNAL_PROCESSING_SERVICE29 == STD_ON)
  Std_ReturnType retVal;

  /* #10 Start processing of diagnostic Authentication service once the processing state is active.
   *     Change processing state to IDLE after when processing of the diagnostic service is finished. */
  if (Ssa_Cdd_S29MainProcState != SSA_CDD_S29PROCSTATE_IDLE)
  {
    /*@ assert Ssa_Cdd_S29Proc.context.reqData != NULL_PTR; */ /* VCA_SSA_CDD_S29_DECOUPLING_CONCEPT */
    /*@ assert Ssa_Cdd_S29Proc.context.resData != NULL_PTR; */ /* VCA_SSA_CDD_S29_DECOUPLING_CONCEPT */
    /*@ assert &Ssa_Cdd_S29Proc.context.resDataLen != NULL_PTR; */
    /*@ assert &Ssa_Cdd_S29Proc.errorCode != NULL_PTR; */
    /*@ assert $lengthOf(Ssa_Cdd_S29Proc.context.resData) >= Ssa_Cdd_S29Proc.context.resBufSize; */ /* VCA_SSA_CDD_S29_DECOUPLING_CONCEPT_BUFFER_LENGTH */
    retVal = Rte_Call_DiagnosticService_Authentication_0x29_Authenticate( /* VCA_SSA_CDD_S29_DECOUPLING_CONCEPT */
      (Dcm_OpStatusType)((Ssa_Cdd_S29MainProcState == SSA_CDD_S29PROCSTATE_ACTIVE_INITIAL) ? DCM_INITIAL : DCM_PENDING),
      Ssa_Cdd_S29Proc.context.reqData,
      Ssa_Cdd_S29Proc.context.reqBufSize,
      Ssa_Cdd_S29Proc.context.reqDataLen,
      Ssa_Cdd_S29Proc.context.resData,
      Ssa_Cdd_S29Proc.context.resBufSize,
      &Ssa_Cdd_S29Proc.context.resDataLen,
      &Ssa_Cdd_S29Proc.errorCode
      );

      if (retVal != RTE_E_DiagnosticService_Authentication_0x29_DCM_E_PENDING)
      {
        /* Enter exclusive area */
        Ssa_Enter_Cdd_ExclusiveArea_External_S29_Processing();

        Ssa_Cdd_S29Proc.retVal = retVal;
        Ssa_Cdd_S29MainProcState = SSA_CDD_S29PROCSTATE_IDLE;

        /* Exit exclusive area */
        Ssa_Exit_Cdd_ExclusiveArea_External_S29_Processing();
      }
      else
      {
        Ssa_Cdd_S29MainProcState = SSA_CDD_S29PROCSTATE_ACTIVE_PENDING;
      }
  }
#endif
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_NvM_GetErrorStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetErrorStatus> of PortPrototype <NvMService_AC2_SRBS>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Cdd_NvM_GetErrorStatus(NvM_RequestResultType *ErrorStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_NvM_GetErrorStatus_doc
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

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_NvM_GetErrorStatus(P2VAR(NvM_RequestResultType, AUTOMATIC, RTE_SSA_CDD_APPL_VAR) ErrorStatus) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_NvM_GetErrorStatus (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorStatus == NULL_PTR)
  {
    retVal = RTE_E_NvMService_AC2_SRBS_E_NOT_OK;
  }
  else
#endif
  {
#if (SSA_CODINGNVMBLOCK == STD_ON)
    uint8 blockIdx;

    /* #10 Iterate through all coding NvM blocks. */
    for (blockIdx = 0u; blockIdx < Ssa_GetSizeOfCodingNvMBlock(); blockIdx++)
    {
      /* #20 Get the error status of each block. */
      retVal = NvM_GetErrorStatus((NvM_BlockIdType)Ssa_GetCodingNvMBlock(blockIdx), ErrorStatus);
      if ((retVal != E_OK) || (*ErrorStatus != NVM_REQ_OK))
      {
        break;
      }
    }
#else
    *ErrorStatus = NVM_REQ_OK;
    retVal = E_OK;
#endif
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_NvM_ReadBlock
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadBlock> of PortPrototype <NvMService_AC2_SRBS>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Cdd_NvM_ReadBlock(dtRef_VOID DstPtr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_NvM_ReadBlock_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires DstPtr == NULL_PTR;
 * \endspec
 */
/* PRQA S 3673 5 */ /* MD_SSA_PARAM_NOT_P2CONST */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_NvM_ReadBlock(dtRef_VOID DstPtr) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_NvM_ReadBlock (returns application error)
 *********************************************************************************************************************/
  /* No DET Check since parameter DstPtr is only forwarded to external module NvM. */
#if (SSA_CODINGNVMBLOCK == STD_ON)
  uint8 blockIdx;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* #10 Iterate through all coding NvM blocks. */
  for (blockIdx = 0u; blockIdx < Ssa_GetSizeOfCodingNvMBlock(); blockIdx++)
  {
    /* #20 Read each block. */
    retVal = NvM_ReadBlock((NvM_BlockIdType)Ssa_GetCodingNvMBlock(blockIdx), DstPtr); /* VCA_SSA_CDD_FORWARDING_PTR_TO_API */
    if(retVal != E_OK)
    {
      break;
    }
  }

  return retVal;
#else
  SSA_DUMMY_STATEMENT(DstPtr);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  return E_OK;
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_NvM_SetRamBlockStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SetRamBlockStatus> of PortPrototype <NvMService_AC2_SRBS>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Cdd_NvM_SetRamBlockStatus(boolean RamBlockStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_NvM_SetRamBlockStatus_doc
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

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_NvM_SetRamBlockStatus(boolean RamBlockStatus) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_NvM_SetRamBlockStatus (returns application error)
 *********************************************************************************************************************/
#if (SSA_CODINGNVMBLOCK == STD_ON)
  uint8 blockIdx;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* #10 Iterate through all coding NvM blocks. */
  for (blockIdx = 0u; blockIdx < Ssa_GetSizeOfCodingNvMBlock(); blockIdx++)
  {
    /* #20 Set the RAM block status of each block. */
    retVal = NvM_SetRamBlockStatus((NvM_BlockIdType)Ssa_GetCodingNvMBlock(blockIdx), RamBlockStatus);
    if(retVal != E_OK)
    {
      break;
    }
  }

  return retVal;
#else
  SSA_DUMMY_STATEMENT(RamBlockStatus);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  return E_OK;
#endif
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_Cdd_NvM_WriteBlock
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WriteBlock> of PortPrototype <NvMService_AC2_SRBS>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_Cdd_NvM_WriteBlock(dtRef_const_VOID SrcPtr)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NvMService_AC2_SRBS_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_NvM_WriteBlock_doc
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

FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_NvM_WriteBlock(dtRef_const_VOID SrcPtr) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_Cdd_NvM_WriteBlock (returns application error)
 *********************************************************************************************************************/
  /* No DET Check since parameter SrcPtr is only forwarded to external module NvM. */
#if (SSA_CODINGNVMBLOCK == STD_ON)
  uint8 blockIdx;
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* #10 Iterate through all coding NvM blocks. */
  for (blockIdx = 0u; blockIdx < Ssa_GetSizeOfCodingNvMBlock(); blockIdx++)
  {
    /* #20 Write each block. */
    retVal = NvM_WriteBlock((NvM_BlockIdType)Ssa_GetCodingNvMBlock(blockIdx), SrcPtr);
    if(retVal != E_OK)
    {
      break;
    }
  }

  return retVal;
#else
  SSA_DUMMY_STATEMENT_CONST(SrcPtr); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
  return E_OK;
#endif
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * Ssa_Cdd_DiagnosticService_Authentication_0x29()
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
/* PRQA S 3408 4 */ /* MD_SSA_DECLARED_IN_GENERATED_HEADER */
FUNC(Std_ReturnType, Ssa_Cdd_CODE) Ssa_Cdd_DiagnosticService_Authentication_0x29(
    Dcm_OpStatusType opStatus, Dcm_MsgContextPtrType pMsgContext, Dcm_NegativeResponseCodePtrType ErrorCode)
{
  Std_ReturnType retVal;

#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((pMsgContext == NULL_PTR)
      || (ErrorCode == NULL_PTR)
      || (pMsgContext->reqData == NULL_PTR)
      || (pMsgContext->resData == NULL_PTR))
  {
    retVal = DCM_E_NOT_OK;
  }
  else
#endif
  {
#if (SSA_DECOUPLE_EXTERNAL_PROCESSING_SERVICE29 == STD_ON)
    retVal = DCM_E_PENDING;

    /* Enter exclusive area */
    Ssa_Enter_Cdd_ExclusiveArea_External_S29_Processing();

    if (opStatus == DCM_CANCEL)
    {
      retVal = DCM_E_OK;
    }
    else if (Ssa_Cdd_S29MainProcState != SSA_CDD_S29PROCSTATE_IDLE)
    {
      /* processing is ongoing, wait */
    }
    else
    {
      /* no processing is ongoing */
      if (opStatus == DCM_INITIAL)
      {
        /* initial request, copy request data */
        Ssa_Cdd_S29Proc.context.reqDataLen = pMsgContext->reqDataLen;
        Ssa_Cdd_S29Proc.context.resDataLen = pMsgContext->resDataLen;
        Ssa_Cdd_S29Proc.context.resMaxDataLen = pMsgContext->resMaxDataLen;
        Ssa_Cdd_S29Proc.context.reqBufSize = pMsgContext->reqBufSize;
        Ssa_Cdd_S29Proc.context.resBufSize = pMsgContext->resBufSize;
        Ssa_Cdd_S29Proc.context.reqData = pMsgContext->reqData;
        Ssa_Cdd_S29Proc.context.resData = pMsgContext->resData;
        Ssa_Cdd_S29Proc.context.reqIndex = pMsgContext->reqIndex;
        Ssa_Cdd_S29Proc.context.resIndex = pMsgContext->resIndex;
        Ssa_Cdd_S29Proc.context.resProtHeadLen = pMsgContext->resProtHeadLen;
        Ssa_Cdd_S29Proc.context.msgAddInfo.reqType = pMsgContext->msgAddInfo.reqType;
        Ssa_Cdd_S29Proc.context.msgAddInfo.suppressPosResponse = pMsgContext->msgAddInfo.suppressPosResponse;
        Ssa_Cdd_S29Proc.context.rxPduId = pMsgContext->rxPduId;
        Ssa_Cdd_S29Proc.context.idContext = pMsgContext->idContext;

        /*@ assert Ssa_Cdd_S29Proc.context.reqData != NULL_PTR; */
        /*@ assert Ssa_Cdd_S29Proc.context.resData != NULL_PTR; */

        Ssa_Cdd_S29MainProcState = SSA_CDD_S29PROCSTATE_ACTIVE_INITIAL;
      }
      else
      {
        /* routine finished, copy response data */
        pMsgContext->reqDataLen = Ssa_Cdd_S29Proc.context.reqDataLen;
        pMsgContext->resDataLen = Ssa_Cdd_S29Proc.context.resDataLen;
        pMsgContext->resMaxDataLen = Ssa_Cdd_S29Proc.context.resMaxDataLen;
        pMsgContext->reqBufSize = Ssa_Cdd_S29Proc.context.reqBufSize;
        pMsgContext->resBufSize = Ssa_Cdd_S29Proc.context.resBufSize;

        *ErrorCode = Ssa_Cdd_S29Proc.errorCode;
        switch (Ssa_Cdd_S29Proc.retVal)
        {
        case RTE_E_OK:
          retVal = DCM_E_OK;
          break;
        /* In this scenario, the return value is never set to PENDING by the main function. */
        default:
          retVal = DCM_E_NOT_OK;
          break;
        }
      }
    }

    /* Exit exclusive area */
    Ssa_Exit_Cdd_ExclusiveArea_External_S29_Processing();

#else
    /* forward call */
    retVal =
        Rte_Call_DiagnosticService_Authentication_0x29_Authenticate( /* VCA_SSA_CDD_FORWARDING_PTR_TO_API */
                                                                    opStatus,
                                                                    pMsgContext->reqData,
                                                                    pMsgContext->reqBufSize,
                                                                    pMsgContext->reqDataLen,
                                                                    pMsgContext->resData,
                                                                    pMsgContext->resBufSize,
                                                                    &pMsgContext->resDataLen,
                                                                    ErrorCode);

    switch (retVal)
    {
    case RTE_E_OK:
      retVal = DCM_E_OK;
      break;
    case RTE_E_DiagnosticService_Authentication_0x29_DCM_E_PENDING:
      retVal = DCM_E_PENDING;
      break;
    default:
      retVal = DCM_E_NOT_OK;
      break;
    }
#endif
  }
  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

#define Ssa_Cdd_STOP_SEC_CODE
#include "Ssa_Cdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

#define Ssa_Cdd_START_SEC_CODE
#include "Ssa_Cdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * Cdd_MapCsmKeyMgmtErrors()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_CDD_LOCAL FUNC(Std_ReturnType, Ssa_Cdd_CODE) Cdd_MapCsmKeyMgmtErrors(Std_ReturnType csmError)
{
  Std_ReturnType retVal;

  if (csmError == E_OK)
  {
    retVal = RTE_E_OK;
  }
  else if (csmError == CRYPTO_E_BUSY)
  {
    retVal = RTE_E_SsaCdd_Csm_KeyInterface_E_BUSY;
  }
  else
  {
    retVal = RTE_E_SsaCdd_Csm_KeyInterface_E_NOT_OK;
  }
  return retVal;
}

#define Ssa_Cdd_STOP_SEC_CODE
#include "Ssa_Cdd_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

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
  \ID  VCA_SSA_CDD_FORWARDING_PTR_TO_API
    \DESCRIPTION      According to VCA, the assertion
                      - somePointer != NULL_PTR or
                      - somePointerLength <= $lengthOf(somePointer)
                      may fail, since a function is possibly called outside its specification.
    \COUNTERMEASURE   \N somePointer points to a buffer that was passed to Ssa_Cdd via an API function call.
                      The contract of the API states that the (minimum) length of that valid buffer
                      must also be passed to the API as a parameter *somePointerLength.
                      Ssa_Cdd passes on these parameters to APIs of other modules which are
                      expected to be silent.
                      This is ensured by review.
                      Exception: This justification is also applied within Ssa_Cdd_NvM_ReadBlock(),
                      where the violated assertion is somePointer == NULL_PTR. Still, the same
                      reasoning applies.

  \ID VCA_SSA_CDD_S29_DECOUPLING_CONCEPT
    \DESCRIPTION    According to VCA, the following assertions may fail:
                    - Ssa_Cdd_S29Proc.context.reqData != NULL_PTR;
                    - Ssa_Cdd_S29Proc.context.resData != NULL_PTR;
    \COUNTERMEASURE \R Ssa_Cdd_S29Proc is a static variable, which is used to decouple the processing of service 0x29
                     and the access to which is protected by the states 
                     - SSA_CDD_S29PROCSTATE_IDLE, 
                     - SSA_CDD_S29PROCSTATE_ACTIVE_INITIAL and
                     - SSA_CDD_S29PROCSTATE_ACTIVE_PENDING.
                     The state machine proceeds as follows:
                     - In Ssa_Cdd_Init(), the state Ssa_Cdd_S29MainProcState is set to SSA_CDD_S29PROCSTATE_IDLE.
                       This is ensured by review.
                     - Ssa_Cdd_DiagnosticService_Authentication_0x29() proceeds the state to
                       SSA_CDD_S29PROCSTATE_ACTIVE_INITIAL and stores the passed parameters from pMsgContext
                       in Ssa_Cdd_S29Proc.
                       In particular, the pointer members of Ssa_Cdd_S29Proc now equal the pointers in pMsgContext.
                       - A runtime check ensures that these pointers are valid.
                       - Additionally, VCA assertions ensure that after the assignment, the pointer members
                         of Ssa_Cdd_S29Proc are not null pointers.
                     - Ssa_Cdd_MainFunction only passes the members of Ssa_Cdd_S29Proc to
                       Rte_Call_DiagnosticService_Authentication_0x29_Authenticate, if the state
                       Ssa_Cdd_S29MainProcState is not SSA_CDD_S29PROCSTATE_IDLE.
                       This is ensured by a runtime check.
                       Thus, the state ensures that when Rte_Call_DiagnosticService_Authentication_0x29_Authenticate
                       is called, all pointer members of Ssa_Cdd_S29Proc are valid and the call itself is valid, too.
                     - Ssa_Cdd_MainFunction the resets the state Ssa_Cdd_S29MainProcState
                       to SSA_CDD_S29PROCSTATE_IDLE or SSA_CDD_S29PROCSTATE_ACTIVE_PENDING.

  \ID VCA_SSA_CDD_S29_DECOUPLING_CONCEPT_BUFFER_LENGTH
    \DESCRIPTION    According to VCA, the following assertion may fail:
                    $lengthOf(Ssa_Cdd_S29Proc.context.resData) >= Ssa_Cdd_S29Proc.context.resBufSize.
    \COUNTERMEASURE \N According to VCA_SSA_CDD_S29_DECOUPLING_CONCEPT, Ssa_Cdd_S29Proc.context.resData
                    is a valid buffer. Following the same principle, Ssa_Cdd_S29Proc.context.resBufSize stores the
                    value of pMsgContext->resBufSize, where pMsgContext is a parameter of function 
                    Ssa_Cdd_DiagnosticService_Authentication_0x29(). This is ensured by review.
                    The parameter is a pointer to the struct type Dcm_MsgContextType. The DCM requires
                    that resBufSize contains the correct length of the buffer referenced by resData.

VCA_JUSTIFICATION_END */

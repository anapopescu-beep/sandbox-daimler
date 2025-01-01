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
/*!        \file  Ssa_ProcCtrl.c
 *        \brief  Process Control of the Standard Security Architecture (Ssa).
 *
 *      \details  The Process Control decouples the execution of Ssa runnables from their synchronous DCM calls.
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
 *
 * Port Prototypes:
 * ================
 * DS_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs
 *   Retrieves all SecOC Data-IDs of the secured PDUs and their corresponding truncated MAC from the ECU.
 *
 * DS_DID_0199_Certificates
 *   Reads the certificates and passes it to given data parameter - Unique ECU ID chain.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): Not in VSM.
 *
 * DS_DID_0199_Data_Signature
 *   Reads a signature which was calculated over nonce and ephemeral key and passes it to given data parameter - Unique ECU ID chain.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): Not in VSM.
 *
 * DS_DID_0199_Ephemeral_ECU_Public_Key
 *   Reads the ephemeral public key and passes it to given data parameter - Unique ECU ID chain.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): Not in VSM.
 *
 * DS_DID_0199_Nonce
 *   Reads the nonce and passes it to given data parameter - Unique ECU ID chain.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): Not in VSM.
 *
 * DS_ECU_Certificate_Read_Data_Signature
 *   Reads a signature which was calculated over nonce and ephemeral key and pass it to given data parameter.
 *      Configuration Variant(s): VSM only.
 *
 * DS_ECU_Certificate_Read_ECU_Certificate
 *   Reads the Ecu certificate and pass it to given data parameter.
 *      Configuration Variant(s): VSM only.
 *
 * DS_ECU_Certificate_Read_Ephemeral_ECU_Public_Key
 *   Reads the ephemeral public key and pass it to given data parameter.
 *      Configuration Variant(s): VSM only.
 *
 * DS_ECU_Certificate_Read_Nonce
 *   Reads the nonce and pass it to given data parameter.
 *      Configuration Variant(s): VSM only.
 *
 * DS_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values
 *   Reads the current counter values of the security event log.
 *
 * DS_Security_Event_Log_Read_Security_Event_Log_Entry
 *   Reads security event log.
 *
 * DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs
 *   Retrieves all SecOC Data-IDs of the secured PDUs and their corresponding truncated MAC from the ECU.
 *      Connect to corresponding Dcm port.
 *
 * DataServices_DID_0199_Certificates
 *   Reads the certificates and passes it to given data parameter - Unique ECU ID chain.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): Not in VSM.
 *
 * DataServices_DID_0199_Data_Signature
 *   Reads a signature which was calculated over nonce and ephemeral key and passes it to given data parameter - Unique ECU ID chain.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): Not in VSM.
 *
 * DataServices_DID_0199_Ephemeral_ECU_Public_Key
 *   Reads the ephemeral public key and passes it to given data parameter - Unique ECU ID chain.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): Not in VSM.
 *
 * DataServices_DID_0199_Nonce
 *   Reads the nonce and passes it to given data parameter - Unique ECU ID chain.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): Not in VSM.
 *
 * DataServices_ECU_Certificate_Read_Data_Signature
 *   Reads a signature which was calculated over nonce and ephemeral key and pass it to given data parameter.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): VSM only.
 *
 * DataServices_ECU_Certificate_Read_ECU_Certificate
 *   Reads the Ecu certificate and pass it to given data parameter.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): VSM only.
 *
 * DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key
 *   Reads the ephemeral public key and pass it to given data parameter.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): VSM only.
 *
 * DataServices_ECU_Certificate_Read_Nonce
 *   Reads the nonce and pass it to given data parameter.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): VSM only.
 *
 * DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values
 *   Reads the current counter values of the security event log.
 *      Connect to corresponding Dcm port.
 *
 * DataServices_Security_Event_Log_Read_Security_Event_Log_Entry
 *   Reads security event log.
 *      Connect to corresponding Dcm port.
 *
 * ProcCtrl_DispatchServices_Receiver
 *   Receiver port of the ProcCtrl service dispatcher.
 *
 * ProcCtrl_DispatchServices_Sender
 *   Sender port of the ProcCtrl service dispatcher.
 *
 * RC_Authenticate_Diagnostic_User_or_Tester
 *   Authenticate a diagnostic user or tester against the ECU to obtain the appropriate access rights (authorization).
 *
 * RC_Certificate_Self_Check
 *   Verifies the chain of trust of the stored certificates and their compatibility to the private key.
 *
 * RC_Enhance_Access_Rights
 *   Request further access rights beyond the ones which are granted by the authentication of the diagnostic test tool.
 *
 * RC_Evaluate_Data_Verification_Certificate
 *   Transfer a Signature Verification Key to the ECU, which afterwards will be used for signature verification within software reprogramming or variant coding process. To enable the ECU to validate the Signature Verification Key, the key is transferred within an appropriate certificate.
 *
 * RC_Inject_Seed
 *   Injects seed data.
 *      Configuration Variant(s): Not in VSM.
 *
 * RC_Replace_Certificates
 *   Replaces the currently stored ECU Certificate, Backend CA Certificate or Root CA Certificate. The Root CA Certificate may only be replaced together with the Backend CA Certificate. The Backend CA Certificate may only be exchanged together with the ECU Certificate. Replacement of Root or Backend certificate needs a corresponding link certificate.
 *
 * RC_Reset_VIN_Values
 *   Resets the currently stored VINDataIdentifier to its default value.
 *
 * RC_SecOC_ECU_Shared_Secret_Encryption
 *   Start the generation of the shared secret and individual encryption for the passed ECU certificate. If standard shared secret is still used, a new one is generated.
 *      Configuration Variant(s): VSM only.
 *
 * RC_SecOC_ECU_TickCount_Synchronization
 *   Start the generation of the shared secret and individual encryption for the passed ECU certificate.
 *      Configuration Variant(s): VSM only.
 *
 * RC_SecOC_VSM_Derive_Symmetric_Keys
 *   Derives the symmetric key used for SecOc from the shared secret.
 *      Configuration Variant(s): VSM only.
 *
 * RC_SecOC_VSM_Renew_Shared_Secret
 *   Generates a new shared secret.
 *      Configuration Variant(s): VSM only.
 *
 * RC_SecOC_Vehicle_Shared_Secret_Distribution
 *   Triggers the transmission of a generated shared secret.
 *      Configuration Variant(s): VSM only.
 *
 * RC_Synchronize_Secured_System_Date_and_Time
 *   Initiate time synchronization by requesting a one-time challenge (nonce).
 *
 * RC_Trust_Model_SecOC_ECU_Shared_Secret_Distribution
 *   Start the distribution of the shared secret - Unique ECU ID chain.
 *      Configuration Variant(s): Not in VSM.
 *
 * RC_Trust_Model_SecOC_ECU_Shared_Secret_Encryption
 *   Start the generation of the shared secret and individual encryption for the passed ECU certificate. If standard shared secret is still used, a new one is generated - Unique ECU ID chain.
 *      Configuration Variant(s): VSM only.
 *
 * RC_Trust_Model_SecOC_ECU_TickCount_Synchronization
 *   Encrypts the car-specific secret at the garage or dealership based on the Unique ECU ID chain.
 *      Never generates a new car-specific secret. Provides time synchronization information.
 *      Configuration Variant(s): VSM only.
 *
 * RC_Verify_Signature
 *   Verifies the integrity and authenticity e.g. of variant coding data using a signature verification.
 *
 * RoutineServices_Inject_Seed
 *   Injects seed data.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): Not in VSM.
 *
 * RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester
 *   Authenticate a diagnostic user or tester against the ECU to obtain the appropriate access rights (authorization).
 *      Connect to corresponding Dcm port.
 *
 * RoutineServices_Routine_Certificate_Self_Check
 *   Verifies the chain of trust of the stored certificates and their compatibility to the private key.
 *      Connect to corresponding Dcm port.
 *
 * RoutineServices_Routine_Enhance_Access_Rights
 *   Request further access rights beyond the ones which are granted by the authentication of the diagnostic test tool.
 *      Connect to corresponding Dcm port.
 *
 * RoutineServices_Routine_Evaluate_Data_Verification_Certificate
 *   Transfer a Signature Verification Key to the ECU, which afterwards will be used for signature verification within software reprogramming or variant coding process. To enable the ECU to validate the Signature Verification Key, the key is transferred within an appropriate certificate.
 *      Connect to corresponding Dcm port.
 *
 * RoutineServices_Routine_Replace_Certificates
 *   Replaces the currently stored ECU Certificate, Backend CA Certificate or Root CA Certificate. The Root CA Certificate may only be replaced together with the Backend CA Certificate. The Backend CA Certificate may only be exchanged together with the ECU Certificate. Replacement of Root or Backend certificate needs a corresponding link certificate.
 *      Connect to corresponding Dcm port.
 *
 * RoutineServices_Routine_Reset_VIN_Values
 *   Resets the currently stored VINDataIdentifier to its default value.
 *      Connect to corresponding Dcm port.
 *
 * RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption
 *   Start the generation of the shared secret and individual encryption for the passed ECU certificate. If standard shared secret is still used, a new one is generated.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): VSM only.
 *
 * RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization
 *   Start the generation of the shared secret and individual encryption for the passed ECU certificate.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): VSM only.
 *
 * RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys
 *   Derives the symmetric key used for SecOc from the shared secret.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): VSM only.
 *
 * RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret
 *   Generates a new shared secret.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): VSM only.
 *
 * RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution
 *   Triggers the transmission of a generated shared secret.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): VSM only.
 *
 * RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time
 *   Initiate time synchronization by requesting a one-time challenge (nonce).
 *      Connect to corresponding Dcm port.
 *
 * RoutineServices_Routine_Verify_Signature
 *   Verifies the integrity and authenticity e.g. of variant coding data using a signature verification.
 *      Connect to corresponding Dcm port.
 *
 * RoutineServices_Trust_Model_Generate_Key_Pair
 *   Generates a new Ed25519 private/public key pair.
 *      Connect to corresponding Dcm port.
 *
 * RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution
 *   Start the distribution of the shared secret - Unique ECU ID chain.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): Not in VSM.
 *
 * RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption
 *   Start the generation of the shared secret and individual encryption for the passed ECU certificate. If standard shared secret is still used, a new one is generated - Unique ECU ID chain.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): VSM only.
 *
 * RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization
 *   Encrypts the car-specific secret at the garage or dealership based on the Unique ECU ID chain.
 *      Never generates a new car-specific secret. Provides time synchronization information.
 *      Connect to corresponding Dcm port.
 *      Configuration Variant(s): VSM only.
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
 * Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ConditionCheckRead
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadData
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadDataLength
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ConditionCheckRead
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ReadData
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ConditionCheckRead
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ReadData
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Data_Signature_ConditionCheckRead
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Data_Signature_ReadData
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ConditionCheckRead
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadData
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadDataLength
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ConditionCheckRead
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ReadData
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Nonce_ConditionCheckRead
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Nonce_ReadData
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_ProcCtrl_RoutineServices_Routine_Inject_Seed
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_ProcCtrl_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_ProcCtrl_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_ProcCtrl_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_ProcCtrl_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_ProcCtrl_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution
 *   Configuration Variant(s): Not in VSM.
 *
 * Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Encryption
 *   Configuration Variant(s): VSM only.
 *
 * Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_TickCount_Synchronization
 *   Configuration Variant(s): VSM only.
 *
 *********************************************************************************************************************/

#include "Rte_Ssa_ProcCtrl.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Ssa_Utils.h"
#include "Ssa_Cfg.h"

#ifdef __VCA__  /* COV_SSA_VECTOR_CODE_ANALYZER_STUB_REDIRECTION */
# include "Ssa_ProcCtrl_Redirection.vcaspecs.h"
#endif

/* After this comment only memory mapping files may be included. Due to this turn off lint rule requesting a standard
include guard. */
/*lint -e451 */

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/
#if !defined (SSA_PROCCTRL_LOCAL)               /* COV_SSA_LOCAL */
# define SSA_PROCCTRL_LOCAL                                                                     static
#endif

#if !defined (SSA_PROCCTRL_LOCAL_INLINE)        /* COV_SSA_LOCAL_INLINE */
# define SSA_PROCCTRL_LOCAL_INLINE                                                              LOCAL_INLINE
#endif

#if !defined (Ssa_MemCpy)                   /* COV_SSA_MEMCPY */
/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
# define Ssa_MemCpy(destination, source, num)                                                   Ssa_Utils_MemCpy32(destination, source, num)
#endif

/*! ProcCtrl buffer states. */
#define SSA_PROCCTRL_BUFFERSTATE_FREE                                                           (0u)
#define SSA_PROCCTRL_BUFFERSTATE_PROCESSING                                                     (1u)
#define SSA_PROCCTRL_BUFFERSTATE_PENDING                                                        (2u)
#define SSA_PROCCTRL_BUFFERSTATE_READY                                                          (3u)
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
# define SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL                                                   (4u)
# define SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL_INIT                                              (5u)
# define SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL_PENDING                                           (6u)
# define SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL_INIT_PENDING                                      (7u)
#endif

/*! ProcCtrl operations/effects triggered by the ProcCtrl state machine. */
#define SSA_PROCCTRL_OPERATION_IDLE                                                             (0u)
#define SSA_PROCCTRL_OPERATION_PENDING                                                          (1u)
#define SSA_PROCCTRL_OPERATION_INPUT                                                            (2u)
#define SSA_PROCCTRL_OPERATION_OUTPUT                                                           (3u)

/*! Local service identifiers. */
#define SSA_PROCCTRL_SERVICE_ID_AUTHENTICATE_DIAGNOSTIC_USER_OR_TESTER                          ((uint8)0u)
#define SSA_PROCCTRL_SERVICE_ID_ENHANCE_ACCESS_RIGHTS                                           ((uint8)1u)
#define SSA_PROCCTRL_SERVICE_ID_EVALUATE_DATA_VERIF_CERT                                        ((uint8)2u)
#define SSA_PROCCTRL_SERVICE_ID_REPLACE_CERTIFICATE                                             ((uint8)3u)
#define SSA_PROCCTRL_SERVICE_ID_RESET_VIN_VALUES                                                ((uint8)4u)
#define SSA_PROCCTRL_SERVICE_ID_SECOC_ECU_SHARED_SECRET_DISTRIBUTION                            ((uint8)5u)
#define SSA_PROCCTRL_SERVICE_ID_SECOC_ECU_SHARED_SECRET_ENCRYPTION                              ((uint8)6u)
#define SSA_PROCCTRL_SERVICE_ID_SECOC_ECU_TICKCOUNT_SYNC                                        ((uint8)7u)
#define SSA_PROCCTRL_SERVICE_ID_SECOC_VSM_DERIVE_SYMMETRIC_KEYS                                 ((uint8)8u)
#define SSA_PROCCTRL_SERVICE_ID_SECOC_VSM_RENEW_SHARED_SECRET                                   ((uint8)9u)
#define SSA_PROCCTRL_SERVICE_ID_SECOC_VEHICLE_SHARED_SECRET_DISTRIBUTION                        ((uint8)10u)
#define SSA_PROCCTRL_SERVICE_ID_SYNCHRONIZE_SECURED_SYSTEM_DATE_AND_TIME                        ((uint8)11u)
#define SSA_PROCCTRL_SERVICE_ID_VERIFY_SIGNATURE                                                ((uint8)12u)
#define SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_DATA_SIGNATURE_CONDITION_CHECK_READ               ((uint8)13u)
#define SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_DATA_SIGNATURE_READ_DATA                          ((uint8)14u)
#define SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_ECU_CERT_CONDITION_CHECK_READ                     ((uint8)15u)
#define SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_ECU_CERT_READ_DATA                                ((uint8)16u)
#define SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_ECU_CERT_READ_DATA_LENGTH                         ((uint8)17u)
#define SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_EPHEMERAL_ECU_PUBLIC_KEY_CONDITION_CHECK_READ     ((uint8)18u)
#define SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_EPHEMERAL_ECU_PUBLIC_KEY_READ_DATA                ((uint8)19u)
#define SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_NONCE_CONDITION_CHECK_READ                        ((uint8)20u)
#define SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_NONCE_READ_DATA                                   ((uint8)21u)
#define SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_ENTRY_CONDITION_CHECK_READ                   ((uint8)22u)
#define SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_ENTRY_READ_DATA_LENGTH                       ((uint8)23u)
#define SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_ENTRY_READ_DATA                              ((uint8)24u)
#define SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_CURRENT_COUNTER_VALUES_CONDITION_CHECK_READ  ((uint8)25u)
#define SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_CURRENT_COUNTER_VALUES_READ_DATA_LENGTH      ((uint8)26u)
#define SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_CURRENT_COUNTER_VALUES_READ_DATA             ((uint8)27u)
#define SSA_PROCCTRL_SERVICE_ID_COMPARE_KEY                                                     ((uint8)28u)
#define SSA_PROCCTRL_SERVICE_ID_GET_SEED                                                        ((uint8)29u)
#define SSA_PROCCTRL_SERVICE_ID_CERTIFICATE_SELF_CHECK                                          ((uint8)30u)
#define SSA_PROCCTRL_SERVICE_ID_SECURED_PDU_DATA_IDS_AND_KEY_CMACS_CONDITION_CHECK_READ         ((uint8)31u)
#define SSA_PROCCTRL_SERVICE_ID_SECURED_PDU_DATA_IDS_AND_KEY_CMACS_READ_DATA_LENGTH             ((uint8)32u)
#define SSA_PROCCTRL_SERVICE_ID_SECURED_PDU_DATA_IDS_AND_KEY_CMACS_READ_DATA                    ((uint8)33u)
#define SSA_PROCCTRL_SERVICE_ID_GENERATED_RANDOM_NUMBER_CONDITION_CHECK_READ                    ((uint8)34u)
#define SSA_PROCCTRL_SERVICE_ID_GENERATED_RANDOM_NUMBER_READ_DATA                               ((uint8)35u)
#define SSA_PROCCTRL_SERVICE_ID_GENERATED_RANDOM_NUMBER_RESULT_CONDITION_CHECK_READ             ((uint8)36u)
#define SSA_PROCCTRL_SERVICE_ID_GENERATED_RANDOM_NUMBER_RESULT_READ_DATA                        ((uint8)37u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_DATA_SIGNATURE_CONDITION_CHECK_READ            ((uint8)38u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_DATA_SIGNATURE_READ_DATA                       ((uint8)39u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_CERTIFICATES_CONDITION_CHECK_READ              ((uint8)40u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_CERTIFICATES_READ_DATA_LENGTH                  ((uint8)41u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_CERTIFICATES_READ_DATA                         ((uint8)42u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_EPHEMERAL_ECU_PUBLIC_KEY_CONDITION_CHECK_READ  ((uint8)43u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_EPHEMERAL_ECU_PUBLIC_KEY_READ_DATA             ((uint8)44u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_NONCE_CONDITION_CHECK_READ                     ((uint8)45u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_NONCE_READ_DATA                                ((uint8)46u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CSR_CONDITION_CHECK_READ                        ((uint8)47u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CSR_READ_DATA_LENGTH                            ((uint8)48u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CSR_READ_DATA                                   ((uint8)49u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CERTIFICATE_CONDITION_CHECK_READ                ((uint8)50u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CERTIFICATE_READ_DATA_LENGTH                    ((uint8)51u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CERTIFICATE_READ_DATA                           ((uint8)52u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_INTERMEDIATE_CA_CERTIFICATE_CONDITION_CHECK_READ    ((uint8)53u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_INTERMEDIATE_CA_CERTIFICATE_READ_DATA_LENGTH        ((uint8)54u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_INTERMEDIATE_CA_CERTIFICATE_READ_DATA               ((uint8)55u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_BACKEND_CA_CERTIFICATE_CONDITION_CHECK_READ         ((uint8)56u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_BACKEND_CA_CERTIFICATE_READ_DATA_LENGTH             ((uint8)57u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_BACKEND_CA_CERTIFICATE_READ_DATA                    ((uint8)58u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ROOT_CA_CERTIFICATE_CONDITION_CHECK_READ            ((uint8)59u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ROOT_CA_CERTIFICATE_READ_DATA_LENGTH                ((uint8)60u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ROOT_CA_CERTIFICATE_READ_DATA                       ((uint8)61u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_CERTIFICATES_CONDITION_CHECK_READ                   ((uint8)62u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_CERTIFICATES_READ_DATA_LENGTH                       ((uint8)63u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_CERTIFICATES_READ_DATA                              ((uint8)64u)
#define SSA_PROCCTRL_SERVICE_ID_REPLACE_TRUST_MODEL_CERTIFICATES                                ((uint8)65u)
#define SSA_PROCCTRL_SERVICE_ID_REPLACE_TRUST_MODEL_ROOT_CERTIFICATE                            ((uint8)66u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_SECOC_ECU_SHARED_SECRET_DISTRIBUTION                ((uint8)67u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_SECOC_ECU_SHARED_SECRET_ENCRYPTION                  ((uint8)68u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_SECOC_ECU_TICKCOUNT_SYNC                            ((uint8)69u)
#define SSA_PROCCTRL_SERVICE_ID_INJECT_SEED                                                     ((uint8)70u)
#define SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_GENERATE_KEY_PAIR                                   ((uint8)71u)
#define SSA_PROCCTRL_SERVICE_ID_AUTHENTICATE_BY_S29                                             ((uint8)72u)
#define SSA_PROCCTRL_SERVICE_ID_ENHANCE_ACCESS_RIGHTS_BY_S29                                    ((uint8)73u)
#define SSA_PROCCTRL_SERVICE_ID_AUTHENTICATION_CONFIG_BY_S29                                    ((uint8)74u)
#define SSA_PROCCTRL_SERVICE_ID_NUMBER                                                          ((uint8)75u)

/*! Sub functions of S29 */
#define SSA_S29_SF_DEAUTH                                                                       (0x00u)
#define SSA_S29_SF_VERIFY_CERT_UNIDIRECTIONAL                                                   (0x01u)
#define SSA_S29_SF_PROOF_OF_OWNERSHIP                                                           (0x03u)
#define SSA_S29_SF_TRANSMIT_CERT                                                                (0x04u)
#define SSA_S29_SF_AUTH_CONFIG                                                                  (0x08u)

/*! Define one error code for 'pending' error types. */
#define SSA_RTE_E_PENDING                                                                       (RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_PENDING)
/*! Define one error code for 'E_NOT_OK' error types. */
#define SSA_RTE_E_NOT_OK                                                                        (RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_E_NOT_OK)
/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
/* Copy the data from source buffer to destination buffer. */
# define ProcCtrl_PrepareBuffer(a, b, c)                                Ssa_MemCpy((a), (b), (c)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define ProcCtrl_CopyBufferCond(a, b, c)                               Ssa_MemCpy((a), (b), (c)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define ProcCtrl_AssignBufferCond(a, b, c)                             SSA_DUMMY_STATEMENT_CONST((a));SSA_DUMMY_STATEMENT_CONST((b));SSA_DUMMY_STATEMENT_CONST((c)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#else
/* Assign the address of the source buffer to the destination pointer. */
# define ProcCtrl_PrepareBuffer(a, b, c)                                (a) = (b) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define ProcCtrl_CopyBufferCond(a, b, c)                               SSA_DUMMY_STATEMENT_CONST((a));SSA_DUMMY_STATEMENT_CONST((b));SSA_DUMMY_STATEMENT_CONST((c)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define ProcCtrl_AssignBufferCond(a, b, c)                             (b) = (a) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#define SSA_MIN(a, b)                                                 (((a) < (b)) ? (a) : (b)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define SSA_MAX(a, b)                                                 (((a) > (b)) ? (a) : (b)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* The following compile time assertions ensure the sizes of data types used within the ProcCtrl submodule
 * when calling RTE APIs expecting these data types. 
 * The assertions ensure that the size of these data types is consistent with respective buffer lengths defined in the Ssa.
 * For ASIL-D, the vector code analyzer checks the same conditions within the ProcCtrl_Init() function. */
/* PRQA S 3205, 3493 12 */ /* MD_SSA_COMPILE_TIME_ASSERTION */
 Ssa_CompileTimeAssert(sizeof(Dcm_Data1002ByteType) == 1002u, InvalidSizeOf_Dcm_Data1002ByteType); /*lint !e506 */
 Ssa_CompileTimeAssert(sizeof(Dcm_Data1024ByteType) == 1024u, InvalidSizeOf_Dcm_Data1024ByteType); /*lint !e506 */
 Ssa_CompileTimeAssert(sizeof(Dcm_Data18ByteType) == 18u, InvalidSizeOf_Dcm_Data18ByteType); /*lint !e506 */
 Ssa_CompileTimeAssert(sizeof(Dcm_Data1ByteType) == 1u, InvalidSizeOf_Dcm_Data1ByteType); /*lint !e506 */
 Ssa_CompileTimeAssert(sizeof(Dcm_Data3006ByteType) == 3006u, InvalidSizeOf_Dcm_Data3006ByteType); /*lint !e506 */
 Ssa_CompileTimeAssert(sizeof(Dcm_Data32ByteType) == 32u, InvalidSizeOf_Dcm_Data32ByteType); /*lint !e506 */
 Ssa_CompileTimeAssert(sizeof(Dcm_Data4008ByteType) == 4008u, InvalidSizeOf_Dcm_Data4008ByteType); /*lint !e506 */
 Ssa_CompileTimeAssert(sizeof(Dcm_Data4092ByteType) == 4092u, InvalidSizeOf_Dcm_Data4092ByteType); /*lint !e506 */
 Ssa_CompileTimeAssert(sizeof(Dcm_Data5ByteType) == 5u, InvalidSizeOf_Dcm_Data5ByteType); /*lint !e506 */
 Ssa_CompileTimeAssert(sizeof(Dcm_Data64ByteType) == 64u, InvalidSizeOf_Dcm_Data64ByteType); /*lint !e506 */
 Ssa_CompileTimeAssert(sizeof(Dcm_Data7ByteType) == 7u, InvalidSizeOf_Dcm_Data7ByteType); /*lint !e506 */
 Ssa_CompileTimeAssert(sizeof(Dcm_Data80ByteType) == 80u, InvalidSizeOf_Dcm_Data80ByteType); /*lint !e506 */

/*! Dummy type definition causing compile-time assertion if RTE_E_OK is not as expected, i.e. different from 0. */
Ssa_CompileTimeAssert(RTE_E_OK == 0u, InvalidDefintionForRTE_E_OK);    /* PRQA S 3205, 3493 */ /* MD_SSA_COMPILE_TIME_ASSERTION */ /*lint !e506 */
/*! Dummy type definition causing compile-time assertion if E_OK is not as expected, i.e. different from 0. */
Ssa_CompileTimeAssert(E_OK == 0u, InvalidDefintionForE_OK);            /* PRQA S 3205, 3493 */ /* MD_SSA_COMPILE_TIME_ASSERTION */ /*lint !e506 */

/*! Dummy type definitions causing compile-time assertion if any 'pending' error code is different from SSA_RTE_E_PENDING. */
/* PRQA S 3205, 3493 L2 */ /* MD_SSA_COMPILE_TIME_ASSERTION */
Ssa_CompileTimeAssert(RTE_E_DiagnosticService_Authentication_0x29_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_DiagnosticService_Authentication_0x29_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_Enhance_Access_Rights_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Routine_Enhance_Access_Rights_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Routine_Evaluate_Data_Verification_Certificate_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_Replace_Certificates_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Routine_Replace_Certificates_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_Reset_VIN_Values_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Routine_Reset_VIN_Values_PendingErrorCode); /*lint !e506 */
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Routine_SecOC_ECU_Shared_Secret_Encryption_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Routine_SecOC_ECU_TickCount_Synchronization_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Routine_SecOC_VSM_Derive_Symmetric_Keys_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Routine_SecOC_VSM_Renew_Shared_Secret_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Routine_SecOC_Vehicle_Shared_Secret_Distribution_PendingErrorCode); /*lint !e506 */
#endif
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Routine_Synchronize_Secured_System_Date_and_Time_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Routine_Verify_Signature_PendingErrorCode); /*lint !e506 */
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
Ssa_CompileTimeAssert(RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_ECU_Certificate_Read_Data_Signature_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_ECU_Certificate_Read_ECU_Certificate_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_ECU_Certificate_Read_Nonce_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_ECU_Certificate_Read_Nonce_PendingErrorCode); /*lint !e506 */
#endif
Ssa_CompileTimeAssert(RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Security_Event_Log_Read_Security_Event_Log_Entry_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_Certificate_Self_Check_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Routine_Certificate_Self_Check_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_0191_Generated_Random_Number_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_DID_0191_Generated_Random_Number_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_DID_0191_Generated_Random_Number_Result_PendingErrorCode); /*lint !e506 */
#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_0199_Certificates_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_DID_0199_Certificates_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_0199_Data_Signature_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_DID_0199_Data_Signature_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_DID_0199_Ephemeral_ECU_Public_Key_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_0199_Nonce_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_DID_0199_Nonce_PendingErrorCode); /*lint !e506 */
#endif
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_DID_019A_Trust_model_ECU_CSR_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_DID_019B_Trust_model_ECU_Certificate_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_DID_019C_Trust_model_Intermediate_CA_Certificate_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_DID_019D_Trust_model_Backend_CA_certificate_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_DID_019E_Trust_model_Root_CA_certificate_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_019F_Trust_model_certificates_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_DID_019F_Trust_model_certificates_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Replace_Trust_model_Certificates_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Replace_Trust_model_Certificates_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Replace_Trust_model_Root_Certificate_PendingErrorCode); /*lint !e506 */
#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Inject_Seed_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Inject_Seed_PendingErrorCode); /*lint !e506 */
#else
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Trust_Model_SecOC_ECU_TickCount_Synchronization_PendingErrorCode); /*lint !e506 */
#endif
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_DCM_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_Trust_Model_Generate_Key_Pair_PendingErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING == SSA_RTE_E_PENDING, InvalidDefinitionFor_GenericSecurityAccess_PendingErrorCode); /*lint !e506 */

/*! Dummy type definitions causing compile-time assertion if any 'E_NOT_OK' error code is different from SSA_RTE_E_NOT_OK. */
Ssa_CompileTimeAssert(RTE_E_DiagnosticService_Authentication_0x29_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_DiagnosticService_Authentication_0x29_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_Enhance_Access_Rights_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Routine_Enhance_Access_Rights_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Routine_Evaluate_Data_Verification_Certificate_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_Replace_Certificates_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Routine_Replace_Certificates_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_Reset_VIN_Values_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Routine_Reset_VIN_Values_ErrorCode); /*lint !e506 */
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Routine_SecOC_ECU_Shared_Secret_Encryption_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Routine_SecOC_ECU_TickCount_Synchronization_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Routine_SecOC_VSM_Derive_Symmetric_Keys_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Routine_SecOC_VSM_Renew_Shared_Secret_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Routine_SecOC_Vehicle_Shared_Secret_Distribution_ErrorCode); /*lint !e506 */
#endif
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Routine_Synchronize_Secured_System_Date_and_Time_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_Verify_Signature_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Routine_Verify_Signature_ErrorCode); /*lint !e506 */
#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)
Ssa_CompileTimeAssert(RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_ECU_Certificate_Read_Data_Signature_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_ECU_Certificate_Read_ECU_Certificate_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_ECU_Certificate_Read_Nonce_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_ECU_Certificate_Read_Nonce_ErrorCode); /*lint !e506 */
#endif
Ssa_CompileTimeAssert(RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Security_Event_Log_Read_Security_Event_Log_Entry_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Routine_Certificate_Self_Check_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Routine_Certificate_Self_Check_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_0191_Generated_Random_Number_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_DID_0191_Generated_Random_Number_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_DID_0191_Generated_Random_Number_Result_ErrorCode); /*lint !e506 */
#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_DID_0199_Certificates_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_0199_Data_Signature_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_DID_0199_Data_Signature_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_DID_0199_Ephemeral_ECU_Public_Key_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_0199_Nonce_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_DID_0199_Nonce_ErrorCode); /*lint !e506 */
#endif
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_DID_019A_Trust_model_ECU_CSR_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_DID_019B_Trust_model_ECU_Certificate_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_DID_019C_Trust_model_Intermediate_CA_Certificate_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_DID_019D_Trust_model_Backend_CA_certificate_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_DID_019E_Trust_model_Root_CA_certificate_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_DataServices_DID_019F_Trust_model_certificates_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_DID_019F_Trust_model_certificates_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Replace_Trust_model_Certificates_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Replace_Trust_model_Certificates_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Replace_Trust_model_Root_Certificate_ErrorCode); /*lint !e506 */
#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Inject_Seed_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Inject_Seed_ErrorCode); /*lint !e506 */
#else
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Trust_Model_SecOC_ECU_TickCount_Synchronization_ErrorCode); /*lint !e506 */
#endif
Ssa_CompileTimeAssert(RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_Trust_Model_Generate_Key_Pair_ErrorCode); /*lint !e506 */
Ssa_CompileTimeAssert(RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK == SSA_RTE_E_NOT_OK, InvalidDefinitionFor_GenericSecurityAccess_ErrorCode); /*lint !e506 */

/* PRQA L:L2 */

#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
# define SSA_PROCCTRL_BUFFER_IN(Type)                                 Type    /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define SSA_PROCCTRL_BUFFER_OUT(Type)                                Type   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#else
# define SSA_PROCCTRL_BUFFER_IN(Type)                                 P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define SSA_PROCCTRL_BUFFER_OUT(Type)                                P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR)   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

/* The following structures are used as elements in the union defined below. Its resulting size
 * is dominated by large uint8 arrays. So there is no need for ordering the members of the
 * following structs according type sizes to reduce the need of padding bytes. */

/*! Data structure for routine control authenticate diagnostic user or tester. */
typedef struct
{
  uint8 Configuration;
  uint8 Task;
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data4004ByteType Challenge_Certificate_Proof_of_Ownership;
#else
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Challenge_Certificate_Proof_of_Ownership;
#endif
  uint8 routineInfo;
  uint8 Verification_Result;
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data3006ByteType Authentication_Result;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Authentication_Result;
#endif
  uint16 DataLength;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_AuthenticateDiagnosticUserOrTesterType;

typedef struct
{
  uint8 Configuration;
  uint8 Task;
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data4004ByteType Challenge_Certificate_Proof_of_Ownership;
#else
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Challenge_Certificate_Proof_of_Ownership;
#endif
  uint8 routineInfo;
  uint8 Verification_Result;
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data3006ByteType Authentication_Result;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Authentication_Result;
#endif
  uint16 DataLength;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_AuthenticateByS31Type;

/*! Data structure for routine control service enhance access rights. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data2002ByteType Enhanced_Rights_Certificate;
#else
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Enhanced_Rights_Certificate;
#endif
  uint8 routineInfo;
  uint8 Verification_Result;
  uint16 DataLength;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_EnhanceAccessRightsType;

/*! Data structure for routine control service enhance access rights. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data2002ByteType Enhanced_Rights_Certificate;
#else
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Enhanced_Rights_Certificate;
#endif
  uint8 routineInfo;
  uint8 Verification_Result;
  uint16 DataLength;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_EnhanceAccessRightsByS31Type;

/*! Data structure for routine control service evaluate data verification certificate. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data2002ByteType Data_Verification_Certificate;
#else
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Verification_Certificate;
#endif
  uint8 routineInfo;
  uint8 Verification_Result;
  uint16 DataLength;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_EvaluateDataVerificationCertificateType;

/*! Data structure for routine control service replace certificates. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data4008ByteType Certificates;
#else
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates;
#endif
  uint8 routineInfo;
  uint8 Verification_Result;
  uint16 DataLength;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_ReplaceCertificatesType;

/*! Data structure for routine control service reset VIN values. */
typedef struct
{
  uint8 routineInfo;
  uint8 Verification_Result;
  uint16 DataLength;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_ResetVinValuesType;

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

/*! Data structure for routine control service SecOC ECU shared secret distribution. */
typedef struct
{
# if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data7ByteType Date_and_Time;
  Dcm_Data5ByteType Tick_Count;
  Dcm_Data5ByteType Tick_Count_Offset;
  Dcm_Data80ByteType Encrypted_Nonce_and_Shared_Secret;
  Dcm_Data32ByteType Ephemeral_VSM_Public_Key;
  Dcm_Data64ByteType Data_Signature;
  Dcm_Data1002ByteType VSMs_ECU_Certificate;
# else
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Date_and_Time;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Tick_Count;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Tick_Count_Offset;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Encrypted_Nonce_and_Shared_Secret;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_VSM_Public_Key;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Signature;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) VSMs_ECU_Certificate;
# endif
  uint8 routineInfo;
  uint8 Verification_Result;
  uint16 DataLength;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_SecOcEcuSharedSecretDistributionType;

#else

/*! Data structure for routine control service SecOC ECU shared secret encryption. */
typedef struct
{
# if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data32ByteType Nonce;
  Dcm_Data32ByteType Ephemeral_ECU_Public_Key;
  Dcm_Data64ByteType Data_Signature_In;
  Dcm_Data1002ByteType Target_ECU_Certificate;
# else
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Nonce;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_ECU_Public_Key;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Signature_In;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Target_ECU_Certificate;
# endif
  uint8 routineInfo;
  uint8 Verification_Result;
# if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data7ByteType Date_and_Time;
  Dcm_Data5ByteType Tick_Count;
  Dcm_Data5ByteType Tick_Count_Offset;
  Dcm_Data80ByteType Encrypted_Nonce_and_Shared_Secret;
  Dcm_Data32ByteType Ephemeral_VSM_Public_Key;
  Dcm_Data64ByteType Data_Signature_Out;
  Dcm_Data1002ByteType VSM_s_ECU_Certificate;
# else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Date_and_Time;
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Tick_Count;
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Tick_Count_Offset;
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Encrypted_Nonce_and_Shared_Secret;
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Ephemeral_VSM_Public_Key;
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data_Signature_Out;
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) VSM_s_ECU_Certificate;
# endif
  uint16 DataLength;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_SecOcEcuSharedSecretEncryptionType;

/*! Data structure for routine control service SecOC ECU tick-count synchronization. */
typedef Ssa_SecOcEcuSharedSecretEncryptionType Ssa_SecOcEcuTickCountSynchronizationType;

/*! Data structure for routine control services only with output parameter routine info and error code. */
typedef struct
{
  uint8 routineInfo;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_RoutineInfoErrorCodeType;

#endif

/*! Data structure for routine control service synchronize secured system data and time. */
typedef struct
{
  uint8 routineInfo;
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data32ByteType Nonce;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Nonce;
#endif
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_SynchronizeSecuredSystemDataAndTimeType;

/*! Data structure for routine control service verify signature. */
typedef struct
{
  uint8 Data_to_be_checked;
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data64ByteType Signature_Value;
#else
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Signature_Value;
#endif
  Dcm_OpStatusType OpStatus;
  uint8 routineInfo;
  uint8 Verification_Result;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_VerifySignatureType;

/*! Data structure for data service condition check read. */
typedef struct
{
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_CondCheckReadType;

/*! Data structure for data service read data length. */
typedef struct
{
  uint16 DataLength;
} Ssa_ReadDataLengthType;

/*! Data structure for data service ECU certificate read data signature read data. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data64ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_EcuCertReadDataSignatureReadDataType;

/*! Data structure for data service ECU certificate read ECU certificate read data. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data1002ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_EcuCertReadEcuCertReadDataType;

/*! Data structure for data service ECU certificate read ephemeral ECU public key read data. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data32ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_EcuCertReadEphEcuPubKeyReadDataType;

/*! Data structure for data service ECU certificate read nonce read data. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data32ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_EcuCertReadNonceReadDataType;

/*! Data structure for data service security event log entry read data. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data4092ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_SecEventLogEntryReadDataType;

/*! Data structure for data service security event log current counter values read data. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data1024ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_SecEventLogCurrentCounterValuesReadDataType;

/*! Data structure for security access service compare key. */
typedef struct
{
  uint8 SecLevel;
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data64ByteType Key;
#else
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Key;
#endif
  Dcm_OpStatusType OpStatus;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_CompareKeyType;

/*! Data structure for security access get seed key. */
typedef struct
{
  uint8 SecLevel;
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data32ByteType Seed;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Seed;
#endif
  Dcm_OpStatusType OpStatus;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_GetSeedType;

/*! Data structure for routine control certificate self check. */
typedef struct
{
  uint8 routineInfo;
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data18ByteType Verification_Result;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result;
#endif
  uint16 DataLength;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_CertificateSelfCheckType;

/*! Data structure for data service DID 018F Secured PDU Data IDs and Key CMACs read data. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data4092ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_SecuredPduDataIdsAndKeyCmacsReadDataType;

/*! Data structure for data service DID_0191_Generated_Random_Number_ReadData. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data32ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_GeneratedRandomNumberReadDataType;

/*! Data structure for data service DID_0191_Generated_Random_Number_Result_ReadData. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data1ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_GeneratedRandomNumberResultReadDataType;

/*! Data structure for data service DID_0199_Certificates_ReadData. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data3006ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_TrustModelReadCertificatesReadDataType;

/*! Data structure for data service DID_0199_Data_Signature_ReadData. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data64ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_TrustModelReadDataSignatureReadDataType;

/*! Data structure for data service DID_0199_Ephemeral_ECU_Public_Key_ReadData. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data32ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_TrustModelReadEphemeralEcuPublicKeyReadDataType;

/*! Data structure for data service DID_0199_Nonce_ReadData. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data32ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_TrustModelReadNonceReadDataType;

/*! Data structure for data service DID_019A_Trust_model_ECU_CSR_ReadData. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data1002ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_TrustModelEcuCsrReadDataType;

/*! Data structure for data service DID_019B_Trust_model_ECU_Certificate_ReadData. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data1002ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_TrustModelEcuCertificateReadDataType;

/*! Data structure for data service DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data1002ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_TrustModelIntermediateCaCertificateReadDataType;

/*! Data structure for data service DID_019D_Trust_model_Backend_CA_certificate_ReadData. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data1002ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_TrustModelBackendCaCertificateReadDataType;

/*! Data structure for data service DID_019E_Trust_model_Root_CA_certificate_ReadData. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data1002ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_TrustModelRootCaCertificateReadDataType;

/*! Data structure for data service DID_019F_Trust_model_certificates_ReadData. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data4008ByteType Data;
#else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data;
#endif
} Ssa_TrustModelCertificatesReadDataType;

/*! Data structure for routine control service replace Trust Model Certificates. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data3006ByteType Trust_Certificates_In;
#else
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Trust_Certificates_In;
#endif
  uint8 routineInfo_Out;
  uint8 Verification_Result_Out;
  uint16 DataLength;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_ReplaceTrustModelCertificatesType;

/*! Data structure for routine control service replace Trust Model Root Certificate. */
typedef struct
{
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data64ByteType signature_new_Root_In;
  Dcm_Data64ByteType signature_In;
  Dcm_Data2004ByteType Certificates_In;
#else
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) signature_new_Root_In;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) signature_In;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates_In;
#endif
  uint8 routineInfo_Out;
  uint8 Verification_Result_Out;
  uint16 DataLength;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_ReplaceTrustModelRootCertificateType;

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

/*! Data structure for routine control service Trust Model SecOC ECU shared secret distribution. */
typedef struct
{
# if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data7ByteType Date_and_Time_In;
  Dcm_Data5ByteType Tick_Count_In;
  Dcm_Data5ByteType Tick_Count_Offset_In;
  Dcm_Data80ByteType Encrypted_Nonce_and_Shared_Secret_In;
  Dcm_Data32ByteType Ephemeral_VSM_Public_Key_In;
  Dcm_Data64ByteType Data_Signature_In;
  Dcm_Data3006ByteType Certificates_In;
# else
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Date_and_Time_In;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Tick_Count_In;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Tick_Count_Offset_In;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Encrypted_Nonce_and_Shared_Secret_In;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_VSM_Public_Key_In;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Signature_In;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates_In;
# endif
  uint8 routineInfo_Out;
  uint8 Verification_Result_Out;
  uint16 DataLength;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_TrustModelSecOcEcuSharedSecretDistributionType;

typedef struct
{
# if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data32ByteType Ephemeral_Backend_Public_Key_In;
  Dcm_Data64ByteType Data_Signature_In;
  Dcm_Data1058ByteType Encrypted_Seed_In;
# else
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_Backend_Public_Key_In;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Signature_In;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Encrypted_Seed_In;
# endif
  uint8 routineInfo_Out;
  uint8 Verification_Result_Out;
  uint16 DataLength;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_InjectSeedType;

#else

/*! Data structure for routine control service Trust Model SecOC ECU shared secret encryption. */
typedef struct
{
# if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data32ByteType Nonce_In;
  Dcm_Data32ByteType Ephemeral_ECU_Public_Key_In;
  Dcm_Data64ByteType In_Data_Signature_In;
  Dcm_Data3006ByteType In_Certificates_In;
# else
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Nonce_In;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_ECU_Public_Key_In;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) In_Data_Signature_In;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) In_Certificates_In;
# endif
  uint8 routineInfo_Out;
  uint8 Verification_Result_Out;
# if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  Dcm_Data7ByteType Date_and_Time_Out;
  Dcm_Data5ByteType Tick_Count_Out;
  Dcm_Data5ByteType Tick_Count_Offset_Out;
  Dcm_Data80ByteType Encrypted_Nonce_and_Shared_Secret_Out;
  Dcm_Data32ByteType Ephemeral_VSM_Public_Key_Out;
  Dcm_Data64ByteType Out_Data_Signature_Out;
  Dcm_Data3006ByteType Out_Certificates_Out;
# else
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Date_and_Time_Out;
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Tick_Count_Out;
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Tick_Count_Offset_Out;
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Encrypted_Nonce_and_Shared_Secret_Out;
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Ephemeral_VSM_Public_Key_Out;
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Out_Data_Signature_Out;
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Out_Certificates_Out;
# endif
  uint16 DataLength;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_TrustModelSecOcEcuSharedSecretEncryptionType;

/*! Data structure for routine control service Trust Model SecOC ECU tick-count synchronization. */
typedef Ssa_TrustModelSecOcEcuSharedSecretEncryptionType Ssa_TrustModelSecOcEcuTickCountSynchronizationType;

#endif

typedef struct
{
  SSA_PROCCTRL_BUFFER_OUT(Dcm_Data64ByteType) CSR_Signature_Out;
  SSA_PROCCTRL_BUFFER_OUT(Dcm_Data1002ByteType) Trust_Model_ECU_CSR_Out;
  uint8 routineInfo_Out;
  uint8 Verification_Result_Out;
  uint16 DataLength;
  Dcm_NegativeResponseCodeType ErrorCode;
} Ssa_TrustModelGenerateKeyPairType;

/*! Shared data structure for all services handled by the ProcCtrl. */
typedef union
{ /* PRQA S 0750 */ /* MD_MSR_Union */
  Ssa_AuthenticateDiagnosticUserOrTesterType AuthenticateDiagnosticUserOrTester;
  Ssa_EnhanceAccessRightsType EnhanceAccessRights;
  Ssa_EvaluateDataVerificationCertificateType EvaluateDataVerificationCertificate;
  Ssa_ReplaceCertificatesType ReplaceCertificates;
  Ssa_ResetVinValuesType ResetVinValues;
#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)
  Ssa_SecOcEcuSharedSecretDistributionType SecOcEcuSharedSecretDistribution;
#else
  Ssa_SecOcEcuSharedSecretEncryptionType SecOcEcuSharedSecretEncryption;
  Ssa_SecOcEcuTickCountSynchronizationType SecOcEcuTickCountSynchronization;
  Ssa_RoutineInfoErrorCodeType SecOcVsmDeriveSymmetricKeysType;
  Ssa_RoutineInfoErrorCodeType SecOcVsmRenewSharedSecretType;
  Ssa_RoutineInfoErrorCodeType SecOcVehicleSharedSecretDistribution;
#endif
  Ssa_SynchronizeSecuredSystemDataAndTimeType SynchronizeSecuredSystemDataAndTime;
  Ssa_VerifySignatureType VerifySignature;
  Ssa_CondCheckReadType EcuCertReadDataSignatureCondCheckRead;
  Ssa_EcuCertReadDataSignatureReadDataType  EcuCertReadDataSignatureReadData;
  Ssa_CondCheckReadType  EcuCertReadEcuCertCondCheckRead;
  Ssa_EcuCertReadEcuCertReadDataType  EcuCertReadEcuCertReadData;
  Ssa_ReadDataLengthType  EcuCertReadEcuCertReadDataLength;
  Ssa_CondCheckReadType EcuCertReadEphEcuPubKeyCondCheckRead;
  Ssa_EcuCertReadEphEcuPubKeyReadDataType  EcuCertReadEphEcuPubKeyReadData;
  Ssa_CondCheckReadType  EcuCertReadNonceCondCheckRead;
  Ssa_EcuCertReadNonceReadDataType EcuCertReadNonceReadData;
  Ssa_CondCheckReadType SecEventLogEntryCondCheckRead;
  Ssa_ReadDataLengthType SecEventLogEntryReadDataLength;
  Ssa_SecEventLogEntryReadDataType SecEventLogEntryReadData;
  Ssa_CondCheckReadType SecEventLogCurrentCounterValuesCondCheckRead;
  Ssa_ReadDataLengthType SecEventLogCurrentCounterValuesReadDataLength;
  Ssa_SecEventLogCurrentCounterValuesReadDataType SecEventLogCurrentCounterValuesReadData;
  Ssa_CompareKeyType CompareKey;
  Ssa_GetSeedType GetSeed;
  Ssa_CertificateSelfCheckType CertificateSelfCheck;
  Ssa_CondCheckReadType SecuredPduDataIdsAndKeyCmacsCondCheckRead;
  Ssa_ReadDataLengthType SecuredPduDataIdsAndKeyCmacsReadDataLength;
  Ssa_SecuredPduDataIdsAndKeyCmacsReadDataType SecuredPduDataIdsAndKeyCmacsReadData;
  Ssa_CondCheckReadType GeneratedRandomNumberCondCheckRead;
  Ssa_GeneratedRandomNumberReadDataType GeneratedRandomNumberReadData;
  Ssa_CondCheckReadType GeneratedRandomNumberResultCondCheckRead;
  Ssa_GeneratedRandomNumberResultReadDataType GeneratedRandomNumberResultReadData;
  Ssa_CondCheckReadType TrustModelReadCertificatesCondCheckRead;
  Ssa_ReadDataLengthType TrustModelReadCertificatesReadDataLength;
  Ssa_TrustModelReadCertificatesReadDataType TrustModelReadCertificatesReadData;
  Ssa_CondCheckReadType TrustModelReadDataSignatureCondCheckRead;
  Ssa_TrustModelReadDataSignatureReadDataType TrustModelReadDataSignatureReadData;
  Ssa_CondCheckReadType TrustModelReadEphemeralEcuPublicKeyCondCheckRead;
  Ssa_TrustModelReadEphemeralEcuPublicKeyReadDataType TrustModelReadEphemeralEcuPublicKeyReadData;
  Ssa_CondCheckReadType TrustModelReadNonceCondCheckRead;
  Ssa_TrustModelReadNonceReadDataType TrustModelReadNonceReadData;
  Ssa_CondCheckReadType TrustModelEcuCsrCondCheckRead;
  Ssa_ReadDataLengthType TrustModelEcuCsrReadDataLength;
  Ssa_TrustModelEcuCsrReadDataType TrustModelEcuCsrReadData;
  Ssa_CondCheckReadType TrustModelEcuCertificateCondCheckRead;
  Ssa_ReadDataLengthType TrustModelEcuCertificateReadDataLength;
  Ssa_TrustModelEcuCertificateReadDataType TrustModelEcuCertificateReadData;
  Ssa_CondCheckReadType TrustModelIntermediateCaCertificateCondCheckRead;
  Ssa_ReadDataLengthType TrustModelIntermediateCaCertificateReadDataLength;
  Ssa_TrustModelIntermediateCaCertificateReadDataType TrustModelIntermediateCaCertificateReadData;
  Ssa_CondCheckReadType TrustModelBackendCaCertificateCondCheckRead;
  Ssa_ReadDataLengthType TrustModelBackendCaCertificateReadDataLength;
  Ssa_TrustModelBackendCaCertificateReadDataType TrustModelBackendCaCertificateReadData;
  Ssa_CondCheckReadType TrustModelRootCaCertificateCondCheckRead;
  Ssa_ReadDataLengthType TrustModelRootCaCertificateReadDataLength;
  Ssa_TrustModelRootCaCertificateReadDataType TrustModelRootCaCertificateReadData;
  Ssa_CondCheckReadType TrustModelCertificatesCondCheckRead;
  Ssa_ReadDataLengthType TrustModelCertificatesReadDataLength;
  Ssa_TrustModelCertificatesReadDataType TrustModelCertificatesReadData;
  Ssa_ReplaceTrustModelCertificatesType ReplaceTrustModelCertificates;
  Ssa_ReplaceTrustModelRootCertificateType ReplaceTrustModelRootCertificate;
#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)
  Ssa_TrustModelSecOcEcuSharedSecretDistributionType TrustModelSecOcEcuSharedSecretDistribution;
  Ssa_InjectSeedType InjectSeed;
#else
  Ssa_TrustModelSecOcEcuSharedSecretEncryptionType TrustModelSecOcEcuSharedSecretEncryption;
  Ssa_TrustModelSecOcEcuTickCountSynchronizationType TrustModelSecOcEcuTickCountSynchronization;
#endif
  Ssa_TrustModelGenerateKeyPairType TrustModelGenerateKeyPair;
  Ssa_AuthenticateByS31Type AuthenticateByS31;
  Ssa_EnhanceAccessRightsByS31Type EnhanceAccessRightsByS31;
} Ssa_ProcCtrlSharedBufferType;

/*! Generalized uint8 pointer type for data buffers within Ssa_ProcCtrlSharedBufferType. */
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
typedef uint8 Ssa_ProcCtrlSharedBufferDataType;
# define Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(buffer)       (buffer)
#else
typedef P2VAR(uint8, AUTOMATIC, AUTOMATIC) Ssa_ProcCtrlSharedBufferDataType;
# define Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(buffer)       (&(buffer))
#endif

/*! Shared data structure for all services handled by the ProcCtrl. */
typedef struct
{
  uint8 State;
  uint8 ServiceId;
  Std_ReturnType Result;
  Dcm_OpStatusType OpStatus;
  Ssa_ProcCtrlSharedBufferType SharedData;
} Ssa_ProcCtrlBufferType;
/**********************************************************************************************************************
 *  LOCAL DATA DEFINITIONS
 *********************************************************************************************************************/
#define Ssa_ProcCtrl_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "Ssa_ProcCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Shared data buffer for all services handled by the ProcCtrl. */
SSA_PROCCTRL_LOCAL VAR(Ssa_ProcCtrlBufferType, Ssa_ProcCtrl_VAR_NOINIT) Ssa_ProcCtrlBuffer;

#define Ssa_ProcCtrl_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "Ssa_ProcCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define Ssa_ProcCtrl_START_SEC_CODE
#include "Ssa_ProcCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ProcCtrl_GenericReadData_PostStateMachineHandler()
 *********************************************************************************************************************/
/*!
 * \brief          Called in ReadData routines to apply the operation returned by the state machine.
 * \details        -
 * \param[in]      Operation           Operation to be applied, previously returned by state machine.
 * \param[in,out]  Data                (in)  If operation is INPUT, the start address of this buffer is assigned to
 *                                           ProcCtrlBuffer.
 *                                     (out) If operation is OUTPUT, data from ProcCtrlBuffer is copied to this buffer.
 * \param[in,out]  ProcCtrlBuffer      (in)  If operation is OUTPUT, this buffer is copied to Data,
 *                                           and the buffer is freed.
 *                                     (out) If operation is INPUT, ProcCtrlBuffer is assigned the start address of Data.
 * \param[in]      ProcCtrlBufferSize  Length of ProcCtrlBuffer.
 * \param[in]      ServiceId           ID to call service dispatcher with.
 * \pre         All provided pointers must be valid.
 *              If Operation == OUTPUT, the buffer referenced by Data must be at least of the size ProcCtrlBufferSize.   
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_PROCCTRL_LOCAL FUNC(void, Ssa_ProcCtrl_CODE) ProcCtrl_GenericReadData_PostStateMachineHandler(
  uint8 Operation,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data,
  P2VAR(Ssa_ProcCtrlSharedBufferDataType, AUTOMATIC, AUTOMATIC) ProcCtrlBuffer,
  const uint32 ProcCtrlBufferSize,
  const uint8 ServiceId);

/**********************************************************************************************************************
 *  ProcCtrl_GenericReadDataLength_PostStateMachineHandler()
 *********************************************************************************************************************/
/*!
 * \brief       Called in ReadDataLength routines to apply the operation returned by the state machine.
 * \details     -
 * \param[in]   Operation            Operation to be applied, previously returned by state machine.
 * \param[out]  DataLength           If operation is OUTPUT, ProcCtrlBufferLength is copied to this buffer.
 * \param[in]   ProcCtrlBufferLength If operation is OUTPUT, this value is copied to DataLength,
 *                                   and the buffer is freed.
 * \param[in]   ServiceId            ID to call service dispatcher with.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_PROCCTRL_LOCAL FUNC(void, Ssa_ProcCtrl_CODE) ProcCtrl_GenericReadDataLength_PostStateMachineHandler(
  uint8 Operation,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength,
  const uint16 ProcCtrlBufferLength,
  const uint8 ServiceId);

/**********************************************************************************************************************
 *  ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler()
 *********************************************************************************************************************/
/*!
 * \brief       Called in ConditionCheckRead routines to apply the operation returned by the state machine.
 * \details     -
 * \param[in]   Operation           Operation to be applied, previously returned by state machine.
 * \param[out]  ErrorCode           If operation is OUTPUT, ErrorCodeFromBuffer is copied to this buffer.
 * \param[in]   ErrorCodeFromBuffer If operation is OUTPUT, this value is copied to ErrorCode,
 *                                  and the buffer is freed.
 * \param[in]   ServiceId           ID to call service dispatcher with.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_PROCCTRL_LOCAL FUNC(void, Ssa_ProcCtrl_CODE) ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(
  uint8 Operation,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCodeFromBuffer,
  const uint8 ServiceId);

/**********************************************************************************************************************
 *  ProcCtrl_GenericRoutineService_PostStateMachineHandler()
 *********************************************************************************************************************/
/*!
 * \brief       Called in RoutineServices routines to apply the operation returned by the state machine.
 * \details     -
 * \param[in]   Operation             Operation to be applied, previously returned by state machine.
 * \param[out]  routineInfo           If operation is OUTPUT, ErrorCodeFromBuffer is copied to this buffer.
 * \param[out]  ErrorCode             If operation is OUTPUT, ErrorCodeFromBuffer is copied to this buffer.
 * \param[in]   routineInfoFromBuffer If operation is OUTPUT, this value is copied to routineInfo,
 *                                    and the buffer is freed.
 * \param[in]   ErrorCodeFromBuffer   If operation is OUTPUT, this value is copied to ErrorCode,
 *                                    and the buffer is freed.
 * \param[in]   ServiceId             ID to call service dispatcher with.
 * \pre         All provided pointers must be valid.
 * \note        This function is called from
 *              - Ssa_ProcCtrl_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution,
 *              - Ssa_ProcCtrl_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret,
 *              - Ssa_ProcCtrl_RoutineServices_Routine_Reset_VIN_Values and
 *              - Ssa_ProcCtrl_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_PROCCTRL_LOCAL FUNC(void, Ssa_ProcCtrl_CODE) ProcCtrl_GenericRoutineService_PostStateMachineHandler(
  uint8 Operation,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode,
  const uint8 routineInfoFromBuffer,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCodeFromBuffer,
  const uint8 ServiceId);

/**********************************************************************************************************************
 *  ProcCtrl_Statemachine_ProcessBufferStateFree()
 *********************************************************************************************************************/
/*!
 * \brief       Called from ProcCtrl_Statemachine to process state 'buffer state free'
 * \details     -
 * \param[in]   opStatus    Current operation status.
 * \param[out]  operation   The operation that shall be executed after the state handling.
 * \return      RTE_E_OK                  Request successful.
 *              SSA_RTE_E_NOT_OK          Request failed.
 *              SSA_RTE_E_PENDING         Request pending.
 * \pre         All provided pointers must be valid.
 *              To be called within exclusive area.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine_ProcessBufferStateFree(
  uint8 opStatus,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) operation);

/**********************************************************************************************************************
 *  ProcCtrl_Statemachine_ProcessBufferStateProcessing()
 *********************************************************************************************************************/
/*!
 * \brief       Called from ProcCtrl_Statemachine to process state 'buffer state processing'
 * \details     -
 * \param[in]   opStatus    Current operation status.
 * \param[out]  errorCode   Negative response code to be sent by DCM if return value is SSA_RTE_E_NOT_OK.
 * \return      RTE_E_OK                  Request successful.
 *              SSA_RTE_E_NOT_OK          Request failed.
 *              SSA_RTE_E_PENDING         Request pending.
 * \pre         All provided pointers must be valid.
 *              To be called within exclusive area.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine_ProcessBufferStateProcessing(
  uint8 opStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode);

/**********************************************************************************************************************
 *  ProcCtrl_Statemachine_ProcessBufferStatePending()
 *********************************************************************************************************************/
/*!
 * \brief       Called from ProcCtrl_Statemachine to process state 'buffer state pending'
 * \details     -
 * \param[in]   opStatus    Current operation status.
 * \param[out]  errorCode   Negative response code to be sent by DCM if return value is SSA_RTE_E_NOT_OK.
 * \param[out]  operation   The operation that shall be executed after the state handling.
 * \return      RTE_E_OK                  Request successful.
 *              SSA_RTE_E_NOT_OK          Request failed.
 *              SSA_RTE_E_PENDING         Request pending.
 * \pre         All provided pointers must be valid.
 *              To be called within exclusive area.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine_ProcessBufferStatePending(
  uint8 opStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) operation);

/**********************************************************************************************************************
 *  ProcCtrl_Statemachine_ProcessBufferStateReady()
 *********************************************************************************************************************/
/*!
 * \brief       Called from ProcCtrl_Statemachine to process state 'buffer state ready'
 * \details     -
 * \param[in]   opStatus    Current operation status.
 * \param[out]  errorCode   Negative response code to be sent by DCM if return value is SSA_RTE_E_NOT_OK.
 * \param[out]  operation   The operation that shall be executed after the state handling.
 * \return      RTE_E_OK                  Request successful.
 *              SSA_RTE_E_NOT_OK          Request failed.
 *              SSA_RTE_E_PENDING         Request pending.
 * \pre         All provided pointers must be valid.
 *              To be called within exclusive area.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine_ProcessBufferStateReady(
  uint8 opStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) operation);


#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
/**********************************************************************************************************************
 *  ProcCtrl_Statemachine_ProcessBufferStateWaitCancel()
 *********************************************************************************************************************/
/*!
 * \brief       Called from ProcCtrl_Statemachine to process state 'buffer state wait cancel'
 * \details     -
 * \param[in]   opStatus    Current operation status.
 * \param[out]  errorCode   Negative response code to be sent by DCM if return value is SSA_RTE_E_NOT_OK.
 * \return      RTE_E_OK                  Request successful.
 *              SSA_RTE_E_NOT_OK          Request failed.
 *              SSA_RTE_E_PENDING         Request pending.
 * \pre         All provided pointers must be valid.
 *              To be called within exclusive area.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine_ProcessBufferStateWaitCancel(
  uint8 opStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode);

/**********************************************************************************************************************
 *  ProcCtrl_Statemachine_ProcessBufferStateCancelInit()
 *********************************************************************************************************************/
/*!
 * \brief       Called from ProcCtrl_Statemachine to process state 'buffer state wait cancel init'
 * \details     -
 * \param[in]   opStatus    Current operation status.
 * \param[out]  errorCode   Negative response code to be sent by DCM if return value is SSA_RTE_E_NOT_OK.
 * \return      RTE_E_OK                  Request successful.
 *              SSA_RTE_E_NOT_OK          Request failed.
 *              SSA_RTE_E_PENDING         Request pending.
 * \pre         All provided pointers must be valid.
 *              To be called within exclusive area.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine_ProcessBufferStateCancelInit(
  uint8 opStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode);

/**********************************************************************************************************************
 *  ProcCtrl_Statemachine_ProcessBufferStateCancelPending()
 *********************************************************************************************************************/
/*!
 * \brief       Called from ProcCtrl_Statemachine to process state 'buffer state wait cancel pending'
 * \details     -
 * \param[in]   opStatus    Current operation status.
 * \param[out]  errorCode   Negative response code to be sent by DCM if return value is SSA_RTE_E_NOT_OK.
 * \param[out]  operation   The operation that shall be executed after the state handling.
 * \return      RTE_E_OK                  Request successful.
 *              SSA_RTE_E_NOT_OK          Request failed.
 *              SSA_RTE_E_PENDING         Request pending.
 * \pre         All provided pointers must be valid.
 *              To be called within exclusive area.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine_ProcessBufferStateCancelPending(
  uint8 opStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) operation);

/**********************************************************************************************************************
 *  ProcCtrl_Statemachine_ProcessBufferStateCancelInitPending()
 *********************************************************************************************************************/
/*!
 * \brief       Called from ProcCtrl_Statemachine to process state 'buffer state wait cancel init pending'
 * \details     -
 * \param[in]   opStatus    Current operation status.
 * \param[out]  errorCode   Negative response code to be sent by DCM if return value is SSA_RTE_E_NOT_OK.
 * \param[out]  operation   The operation that shall be executed after the state handling.
 * \return      RTE_E_OK                  Request successful.
 *              SSA_RTE_E_NOT_OK          Request failed.
 *              SSA_RTE_E_PENDING         Request pending.
 * \pre         All provided pointers must be valid.
 *              To be called within exclusive area.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine_ProcessBufferStateCancelInitPending(
  uint8 opStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) operation);
#endif /* (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) */

/**********************************************************************************************************************
 *  ProcCtrl_Statemachine()
 *********************************************************************************************************************/
/*!
 * \brief       Does the state handling of ProcCtrl.
 * \details     This function does the state handling of ProcCtrl and derives the operation to be executed.
 * \param[in]   OpStatus    Current operation status.
 * \param[out]  ErrorCode   Negative response code to be sent by DCM if return value is SSA_RTE_E_NOT_OK.
 *                          This parameter is optional, NULL_PTR can be passed.
 * \param[out]  operation   The operation that shall be executed after the state handling.
 * \return      RTE_E_OK                  Request successful.
 *              SSA_RTE_E_NOT_OK          Request failed.
 *              SSA_RTE_E_PENDING         Request pending.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_PROCCTRL_LOCAL FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine(
  uint8 OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) operation);

/**********************************************************************************************************************
 *  Ssa_ProcCtrl_MapS29In()
 *********************************************************************************************************************/
/*!
 * \brief       Maps the input parameter of S29 to the input parameter of S31 R260 resp. 261
 * \details     -
 * \param[in]   reqDataLen    Remaining request data length
 * \param[in]   reqData       Points to the request data buffer to be evaluated or passed to the application
 * \param[out]  resData       Points to the response data buffer to be written or passed to the application to provide data at
 * \param[in]   errorCodeIn   NRC passed DCM
 * \return      Negative response code to be sent by DCM if return value is E_NOT_OK.
 *              DCM_E_POSITIVERESPONSE if mapping was successful.
 * \pre         -
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Dcm_NegativeResponseCodeType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_MapS29In(
  uint32 reqDataLen,
  Ssa_ConstDataPtr reqData,
  Ssa_DataPtr resData,
  Dcm_NegativeResponseCodeType errorCodeIn);

/**********************************************************************************************************************
 *  Ssa_ProcCtrl_MapS29Out()
 *********************************************************************************************************************/
/*!
 * \brief       Maps the output parameter of S31 R260 resp. 261 to the output parameter of S29
 * \details     -
 * \param[in]   reqData           Points to the request data buffer to be evaluated or passed to the application
 * \param[in]   resDataBufferSize Size of the response data buffer resData
 * \param[out]  resDataLen        Current response data length
 * \param[out]  resData           Points to the response data buffer to be written or passed to the application to provide data at
 * \param[out]  retVal            Buffer to store updated return value in case the verification result is mapped to a NRC
 * \return      Negative response code to be sent by DCM if return value is E_NOT_OK. To be used as resulting error code.
 * \pre         All provided pointers must be valid.
 * \context     TASK
 * \reentrant   FALSE
 * \synchronous TRUE
 * \spec        requires resData != NULL_PTR;
 *              requires $lengthOf(resData) >= resDataBufferSize;     \endspec
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Dcm_NegativeResponseCodeType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_MapS29Out(
  Ssa_ConstDataPtr reqData,
  uint32 resDataBufferSize,
  P2VAR(uint32, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) resDataLen,
  Ssa_DataPtr resData,
  P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) retVal);

/**********************************************************************************************************************
 *  Ssa_ProcCtrl_MapAuthVerifResult()
 *********************************************************************************************************************/
/*!
 * \brief      Maps the verification result of S31 R260 to S29
 * \details    -
 * \param[in]  verifResultIn       Input verification result
 * \param[out]  mappedVerifResult  Mapped verification result
 * \param[out]  errorCode          Negative response code set if return value is not E_OK
 * \return     E_OK               Verification result has been mapped
 *             SSA_RTE_E_NOT_OK   Verification result has been mapped to an NRC
 * \pre        All provided pointers must be valid.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_MapAuthVerifResult(
  uint8 verifResultIn,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) mappedVerifResult,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode);

/**********************************************************************************************************************
 *  Ssa_ProcCtrl_MapEnhanceVerifResult()
 *********************************************************************************************************************/
/*!
 * \brief      Maps the verification result of S31 R261 to S29
 * \details    -
 * \param[in]   verifResultIn      Input verification result
 * \param[out]  mappedVerifResult  Mapped verification result
 * \param[out]  errorCode          Negative response code set if return value is not E_OK
 * \return     E_OK               Verification result has been mapped
 *             SSA_RTE_E_NOT_OK   Verification result has been mapped to an NRC
 * \pre        All provided pointers must be valid.
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_MapEnhanceVerifResult(
  uint8 verifResultIn,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) mappedVerifResult,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode);

/**********************************************************************************************************************
 *  Ssa_ProcCtrl_ServiceDispatcher_UpdateBufferState()
 *********************************************************************************************************************/
 /*!
  * \brief      Updates the state of Ssa_ProcCtrlBuffer.
  * \details    This function is called after the dispatching of services by Ssa_PrctCtrl_ServiceDispatcher.
  * \param[in]  retValPending Return value of the finished synchronous function call to be evaluated.
  * \pre        -
  * \context     ANY
  * \reentrant   TRUE
  * \synchronous TRUE
  */
SSA_PROCCTRL_LOCAL_INLINE FUNC(void, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_ServiceDispatcher_UpdateBufferState(Std_ReturnType retValPending);

#define Ssa_ProcCtrl_STOP_SEC_CODE
#include "Ssa_ProcCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
 * Ssa_ConstDataPtr: DataReference
 * Ssa_DataPtr: DataReference
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
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
 *
 * Array Types:
 * ============
 * Dcm_Data1002ByteType: Array with 1002 element(s) of type uint8
 * Dcm_Data1024ByteType: Array with 1024 element(s) of type uint8
 * Dcm_Data1058ByteType: Array with 1058 element(s) of type uint8
 * Dcm_Data18ByteType: Array with 18 element(s) of type uint8
 * Dcm_Data1ByteType: Array with 1 element(s) of type uint8
 * Dcm_Data2002ByteType: Array with 2002 element(s) of type uint8
 * Dcm_Data2004ByteType: Array with 2004 element(s) of type uint8
 * Dcm_Data3006ByteType: Array with 3006 element(s) of type uint8
 * Dcm_Data32ByteType: Array with 32 element(s) of type uint8
 * Dcm_Data4004ByteType: Array with 4004 element(s) of type uint8
 * Dcm_Data4008ByteType: Array with 4008 element(s) of type uint8
 * Dcm_Data4092ByteType: Array with 4092 element(s) of type uint8
 * Dcm_Data5ByteType: Array with 5 element(s) of type uint8
 * Dcm_Data64ByteType: Array with 64 element(s) of type uint8
 * Dcm_Data7ByteType: Array with 7 element(s) of type uint8
 * Dcm_Data80ByteType: Array with 80 element(s) of type uint8
 *
 *********************************************************************************************************************/


#define Ssa_ProcCtrl_START_SEC_CODE
#include "Ssa_ProcCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING
 *   RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.SecuredPduDataIdsAndKeyCmacsCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_SECURED_PDU_DATA_IDS_AND_KEY_CMACS_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4092ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING
 *   RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.SecuredPduDataIdsAndKeyCmacsReadData.Data), sizeof(Dcm_Data4092ByteType), SSA_PROCCTRL_SERVICE_ID_SECURED_PDU_DATA_IDS_AND_KEY_CMACS_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING
 *   RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (DataLength == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadDataLength_PostStateMachineHandler(operation, DataLength, Ssa_ProcCtrlBuffer.SharedData.SecuredPduDataIdsAndKeyCmacsReadDataLength.DataLength, SSA_PROCCTRL_SERVICE_ID_SECURED_PDU_DATA_IDS_AND_KEY_CMACS_READ_DATA_LENGTH);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0191_Generated_Random_Number>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0191_Generated_Random_Number_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0191_Generated_Random_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0191_Generated_Random_Number_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.GeneratedRandomNumberCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_GENERATED_RANDOM_NUMBER_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0191_Generated_Random_Number>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data32ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0191_Generated_Random_Number_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0191_Generated_Random_Number_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data32ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0191_Generated_Random_Number_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.GeneratedRandomNumberReadData.Data), sizeof(Dcm_Data32ByteType), SSA_PROCCTRL_SERVICE_ID_GENERATED_RANDOM_NUMBER_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0191_Generated_Random_Number_Result>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.GeneratedRandomNumberResultCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_GENERATED_RANDOM_NUMBER_RESULT_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0191_Generated_Random_Number_Result>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ReadData_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0191_Generated_Random_Number_Result_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.GeneratedRandomNumberResultReadData.Data), sizeof(Dcm_Data1ByteType), SSA_PROCCTRL_SERVICE_ID_GENERATED_RANDOM_NUMBER_RESULT_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0199_Certificates>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0199_Certificates_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.TrustModelReadCertificatesCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_CERTIFICATES_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0199_Certificates>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data3006ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0199_Certificates_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data3006ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelReadCertificatesReadData.Data), sizeof(Dcm_Data3006ByteType), SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_CERTIFICATES_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_DID_0199_Certificates>
 *
 **********************************************************************************************************************
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0199_Certificates_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadDataLength_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadDataLength(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Certificates_ReadDataLength (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (DataLength == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadDataLength_PostStateMachineHandler(operation, DataLength, Ssa_ProcCtrlBuffer.SharedData.TrustModelReadCertificatesReadDataLength.DataLength, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_CERTIFICATES_READ_DATA_LENGTH);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0199_Data_Signature>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0199_Data_Signature_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0199_Data_Signature_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0199_Data_Signature_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.TrustModelReadDataSignatureCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_DATA_SIGNATURE_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0199_Data_Signature>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data64ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0199_Data_Signature_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0199_Data_Signature_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Data_Signature_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0199_Data_Signature_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelReadDataSignatureReadData.Data), sizeof(Dcm_Data64ByteType), SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_DATA_SIGNATURE_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0199_Ephemeral_ECU_Public_Key>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.TrustModelReadEphemeralEcuPublicKeyCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_EPHEMERAL_ECU_PUBLIC_KEY_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0199_Ephemeral_ECU_Public_Key>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data32ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data32ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Ephemeral_ECU_Public_Key_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelReadEphemeralEcuPublicKeyReadData.Data), sizeof(Dcm_Data32ByteType), SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_EPHEMERAL_ECU_PUBLIC_KEY_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_0199_Nonce>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0199_Nonce_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0199_Nonce_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ConditionCheckRead(
  Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType,
  AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0199_Nonce_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.TrustModelReadNonceCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_NONCE_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_0199_Nonce>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data32ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_0199_Nonce_DCM_E_PENDING
 *   RTE_E_DataServices_DID_0199_Nonce_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data32ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_0199_Nonce_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_0199_Nonce_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelReadNonceReadData.Data), sizeof(Dcm_Data32ByteType), SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_NONCE_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_019A_Trust_model_ECU_CSR>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.TrustModelEcuCsrCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CSR_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_019A_Trust_model_ECU_CSR>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1002ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data1002ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelEcuCsrReadData.Data), sizeof(Dcm_Data1002ByteType), SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CSR_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_DID_019A_Trust_model_ECU_CSR>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019A_Trust_model_ECU_CSR_ReadDataLength (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (DataLength == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadDataLength_PostStateMachineHandler(operation, DataLength, Ssa_ProcCtrlBuffer.SharedData.TrustModelEcuCsrReadDataLength.DataLength, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CSR_READ_DATA_LENGTH);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_019B_Trust_model_ECU_Certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.TrustModelEcuCertificateCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CERTIFICATE_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_019B_Trust_model_ECU_Certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1002ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data1002ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelEcuCertificateReadData.Data), sizeof(Dcm_Data1002ByteType), SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CERTIFICATE_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_DID_019B_Trust_model_ECU_Certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019B_Trust_model_ECU_Certificate_ReadDataLength (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (DataLength == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadDataLength_PostStateMachineHandler(operation, DataLength, Ssa_ProcCtrlBuffer.SharedData.TrustModelEcuCertificateReadDataLength.DataLength, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CERTIFICATE_READ_DATA_LENGTH);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.TrustModelIntermediateCaCertificateCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_INTERMEDIATE_CA_CERTIFICATE_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1002ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data1002ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelIntermediateCaCertificateReadData.Data), sizeof(Dcm_Data1002ByteType), SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_INTERMEDIATE_CA_CERTIFICATE_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (DataLength == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadDataLength_PostStateMachineHandler(operation, DataLength, Ssa_ProcCtrlBuffer.SharedData.TrustModelIntermediateCaCertificateReadDataLength.DataLength, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_INTERMEDIATE_CA_CERTIFICATE_READ_DATA_LENGTH);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_019D_Trust_model_Backend_CA_certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.TrustModelBackendCaCertificateCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_BACKEND_CA_CERTIFICATE_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_019D_Trust_model_Backend_CA_certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1002ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data1002ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelBackendCaCertificateReadData.Data), sizeof(Dcm_Data1002ByteType), SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_BACKEND_CA_CERTIFICATE_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_DID_019D_Trust_model_Backend_CA_certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (DataLength == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadDataLength_PostStateMachineHandler(operation, DataLength, Ssa_ProcCtrlBuffer.SharedData.TrustModelBackendCaCertificateReadDataLength.DataLength, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_BACKEND_CA_CERTIFICATE_READ_DATA_LENGTH);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_019E_Trust_model_Root_CA_certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.TrustModelRootCaCertificateCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ROOT_CA_CERTIFICATE_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_019E_Trust_model_Root_CA_certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1002ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData_doc
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
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data1002ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelRootCaCertificateReadData.Data), sizeof(Dcm_Data1002ByteType), SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ROOT_CA_CERTIFICATE_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_DID_019E_Trust_model_Root_CA_certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (DataLength == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadDataLength_PostStateMachineHandler(operation, DataLength, Ssa_ProcCtrlBuffer.SharedData.TrustModelRootCaCertificateReadDataLength.DataLength, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ROOT_CA_CERTIFICATE_READ_DATA_LENGTH);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_DID_019F_Trust_model_certificates>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019F_Trust_model_certificates_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019F_Trust_model_certificates_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019F_Trust_model_certificates_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.TrustModelCertificatesCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_CERTIFICATES_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_DID_019F_Trust_model_certificates>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4008ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019F_Trust_model_certificates_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019F_Trust_model_certificates_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data4008ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019F_Trust_model_certificates_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelCertificatesReadData.Data), sizeof(Dcm_Data4008ByteType), SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_CERTIFICATES_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_DID_019F_Trust_model_certificates>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_DID_019F_Trust_model_certificates_DCM_E_PENDING
 *   RTE_E_DataServices_DID_019F_Trust_model_certificates_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadDataLength_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadDataLength(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_DID_019F_Trust_model_certificates_ReadDataLength (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_DID_019F_Trust_model_certificates_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (DataLength == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadDataLength_PostStateMachineHandler(operation, DataLength, Ssa_ProcCtrlBuffer.SharedData.TrustModelCertificatesReadDataLength.DataLength, SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_CERTIFICATES_READ_DATA_LENGTH);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Data_Signature_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_ECU_Certificate_Read_Data_Signature>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Data_Signature_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_DCM_E_PENDING
 *   RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Data_Signature_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Data_Signature_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Data_Signature_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.EcuCertReadDataSignatureCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_DATA_SIGNATURE_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Data_Signature_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_ECU_Certificate_Read_Data_Signature>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Data_Signature_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data64ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_DCM_E_PENDING
 *   RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Data_Signature_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Data_Signature_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Data_Signature_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.EcuCertReadDataSignatureReadData.Data), sizeof(Dcm_Data64ByteType), SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_DATA_SIGNATURE_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_ECU_Certificate_Read_ECU_Certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_DCM_E_PENDING
 *   RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.EcuCertReadEcuCertCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_ECU_CERT_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_ECU_Certificate_Read_ECU_Certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1002ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_DCM_E_PENDING
 *   RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data1002ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.EcuCertReadEcuCertReadData.Data), sizeof(Dcm_Data1002ByteType), SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_ECU_CERT_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_ECU_Certificate_Read_ECU_Certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_DCM_E_PENDING
 *   RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadDataLength_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadDataLength(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_ECU_Certificate_ReadDataLength (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (DataLength == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadDataLength_PostStateMachineHandler(operation, DataLength, Ssa_ProcCtrlBuffer.SharedData.EcuCertReadEcuCertReadDataLength.DataLength, SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_ECU_CERT_READ_DATA_LENGTH);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_DCM_E_PENDING
 *   RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.EcuCertReadEphEcuPubKeyCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_EPHEMERAL_ECU_PUBLIC_KEY_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data32ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_DCM_E_PENDING
 *   RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data32ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.EcuCertReadEphEcuPubKeyReadData.Data), sizeof(Dcm_Data32ByteType), SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_EPHEMERAL_ECU_PUBLIC_KEY_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Nonce_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_ECU_Certificate_Read_Nonce>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Nonce_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ECU_Certificate_Read_Nonce_DCM_E_PENDING
 *   RTE_E_DataServices_ECU_Certificate_Read_Nonce_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Nonce_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Nonce_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Nonce_ConditionCheckRead (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_ECU_Certificate_Read_Nonce_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (ErrorCode == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.EcuCertReadNonceCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_NONCE_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Nonce_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_ECU_Certificate_Read_Nonce>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Nonce_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data32ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DataServices_ECU_Certificate_Read_Nonce_DCM_E_PENDING
 *   RTE_E_DataServices_ECU_Certificate_Read_Nonce_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Nonce_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/*!
 * \spec
 *    requires $lengthOf(Data) >= sizeof(Dcm_Data32ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Nonce_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_ECU_Certificate_Read_Nonce_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_ECU_Certificate_Read_Nonce_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.EcuCertReadNonceReadData.Data), sizeof(Dcm_Data32ByteType), SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_NONCE_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
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
 * Symbol: Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ConditionCheckRead (returns application error)
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
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.SecEventLogCurrentCounterValuesCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_CURRENT_COUNTER_VALUES_CONDITION_CHECK_READ);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
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
 * Symbol: Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.SecEventLogCurrentCounterValuesReadData.Data), sizeof(Dcm_Data1024ByteType), SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_CURRENT_COUNTER_VALUES_READ_DATA);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
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
 * Symbol: Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_Security_Event_Log_Current_Counter_Values_ReadDataLength (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (DataLength == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadDataLength_PostStateMachineHandler(operation, DataLength, Ssa_ProcCtrlBuffer.SharedData.SecEventLogCurrentCounterValuesReadDataLength.DataLength, SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_CURRENT_COUNTER_VALUES_READ_DATA_LENGTH);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ConditionCheckRead
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ConditionCheckRead> of PortPrototype <DataServices_Security_Event_Log_Read_Security_Event_Log_Entry>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
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
 * Symbol: Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ConditionCheckRead_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ConditionCheckRead(
  Dcm_OpStatusType OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ConditionCheckRead (returns application error)
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
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(operation, ErrorCode, &Ssa_ProcCtrlBuffer.SharedData.SecEventLogEntryCondCheckRead.ErrorCode, SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_ENTRY_CONDITION_CHECK_READ);
  }
  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadData
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadData> of PortPrototype <DataServices_Security_Event_Log_Read_Security_Event_Log_Entry>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
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
 * Symbol: Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadData_doc
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadData(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadData (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (Data == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadData_PostStateMachineHandler(operation, Data, Ssa_ProcCtrl_GetStartAddressOfSharedDataBuffer(Ssa_ProcCtrlBuffer.SharedData.SecEventLogEntryReadData.Data), sizeof(Dcm_Data4092ByteType), SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_ENTRY_READ_DATA);
  }
  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadDataLength
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ReadDataLength> of PortPrototype <DataServices_Security_Event_Log_Read_Security_Event_Log_Entry>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
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
 * Symbol: Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadDataLength_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadDataLength(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DataServices_Security_Event_Log_Entry_ReadDataLength (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if (DataLength == NULL_PTR)
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, NULL_PTR, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericReadDataLength_PostStateMachineHandler(operation, DataLength, Ssa_ProcCtrlBuffer.SharedData.SecEventLogEntryReadDataLength.DataLength, SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_ENTRY_READ_DATA_LENGTH);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_DiagnosticService_Authentication_0x29_Authenticate
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Authenticate> of PortPrototype <DiagnosticService_Authentication_0x29>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_DiagnosticService_Authentication_0x29_Authenticate(Dcm_OpStatusType OpStatus, Ssa_ConstDataPtr ReqData, uint32 ReqBufSize, uint32 ReqDataLen, Ssa_DataPtr ResData, uint32 ResBufSize, uint32 *ResDataLen, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_DiagnosticService_Authentication_0x29_DCM_E_FORCE_RCRRP
 *   RTE_E_DiagnosticService_Authentication_0x29_DCM_E_PENDING
 *   RTE_E_DiagnosticService_Authentication_0x29_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DiagnosticService_Authentication_0x29_Authenticate_doc
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
/*!
 * \spec
 *    requires $lengthOf(ReqData) >= ReqBufSize;
 *    requires $lengthOf(ResData) >= ResBufSize;
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_DiagnosticService_Authentication_0x29_Authenticate(
  Dcm_OpStatusType OpStatus,
  Ssa_ConstDataPtr ReqData,
  uint32 ReqBufSize,
  uint32 ReqDataLen,
  Ssa_DataPtr ResData,
  uint32 ResBufSize,
  P2VAR(uint32, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ResDataLen,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_DiagnosticService_Authentication_0x29_Authenticate (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_DiagnosticService_Authentication_0x29_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((ReqData == NULL_PTR) || (ResData == NULL_PTR) || (ResDataLen == NULL_PTR) || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    SSA_DUMMY_STATEMENT(ReqBufSize);    /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
      case SSA_PROCCTRL_OPERATION_IDLE:
        /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
        break;
      case SSA_PROCCTRL_OPERATION_PENDING:
        /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_INPUT:
      {
        Dcm_NegativeResponseCodeType errorCode;
        /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer:
         *     Map input data of S29 to input data of appropriate routine control service.
         *     Then call the service dispatcher.*/
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_OFF) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
        /* If the ProcCtrl buffer handling is disabled,
         * Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Authentication_Result does not provide memory of
         * its own, but will point to ResData. This is why the length of ResData has to be checked here already,
         * before Ssa_ProcCtrl_MapS29In() is called.
         * In other configurations, the length of ResData is checked and used in Ssa_ProcCtrl_MapS29Out(). */
        if (ResBufSize < 2u)
        {
          errorCode = DCM_E_CONDITIONSNOTCORRECT;
        }
        else
#endif
        {
          errorCode = Ssa_ProcCtrl_MapS29In(
            ReqDataLen,
            ReqData,
            ResData,
            *ErrorCode);
        }

        if (errorCode != DCM_E_POSITIVERESPONSE)
        {
          *ErrorCode = errorCode;
          retVal = RTE_E_DiagnosticService_Authentication_0x29_E_NOT_OK;
          Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
        }
        else
        {
          /* Call service dispatcher. */
          (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        }
        break;
      }
      case SSA_PROCCTRL_OPERATION_OUTPUT:
      {
        /* #28 If operation is OUTPUT map output data of appropriate routine control service from ProcCtrl buffer
         *     to output data of S29 and free the buffer to be accessible by next service. */

        /* If operation = SSA_PROCCTRL_OPERATION_OUTPUT, the error code set by the state machine
         * is DCM_E_POSITIVERESPONSE, thus no error code will be overwritten here.
         * The retVal set by the state machine is overwritten only if the verification result is mapped to an NRC.
         * In this case the retVal is set to RTE_E_DiagnosticService_Authentication_0x29_E_NOT_OK. */

        *ErrorCode = Ssa_ProcCtrl_MapS29Out( /* VCA_SSA_PROCCTRL_RELATION_DATABUFFER_AND_SIZEOF_DATABUFFER_CHECKED_IN_SPECIFICATION */
          ReqData,
          ResBufSize,
          ResDataLen,
          ResData,
          &retVal);

        /* Set buffer state to free. */
        Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
        break;
      }
      default: /* COV_SSA_MISRA */
        /* Not reachable, QAC only. */
        break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_Init_doc
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

FUNC(void, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_Init
 *********************************************************************************************************************/

  /* #10 Initialize buffer state variable. */
  Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
  /* #20 Initialize service id to an invalid number. */
  Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_NUMBER;

  /* Ensure type sizes once for the ProcCtrl submodule which calls RTE APIs expecting these data types:
   * Dcm_Data1002ByteType must be an array with 1002 element(s) of type uint8
   * Dcm_Data1024ByteType must be an array with 1024 element(s) of type uint8
   * Dcm_Data18ByteType must be an array with 18 element(s) of type uint8
   * Dcm_Data1ByteType must be an array with 1 element(s) of type uint8
   * Dcm_Data3006ByteType must be an array with 3006 element(s) of type uint8
   * Dcm_Data32ByteType must be an array with 32 element(s) of type uin uint8
   * Dcm_Data4008ByteType must be an array with 4008 element(s) of type uint8
   * Dcm_Data4092ByteType must be an array with 4092 element(s) of type uint8
   * Dcm_Data5ByteType must be an array with 5 element(s) of type uint8
   * Dcm_Data64ByteType must be an array with 64 element(s) of type uint8
   * Dcm_Data7ByteType must be an array with 7 element(s) of type uint8
   * Dcm_Data80ByteType must be an array with 80 element(s) of type uint8 */

  /*@ assert sizeof(Dcm_Data1002ByteType) == 1002; */
  /*@ assert sizeof(Dcm_Data1024ByteType) == 1024; */
  /*@ assert sizeof(Dcm_Data18ByteType) == 18; */
  /*@ assert sizeof(Dcm_Data1ByteType) == 1; */
  /*@ assert sizeof(Dcm_Data3006ByteType) == 3006; */
  /*@ assert sizeof(Dcm_Data32ByteType) == 32; */
  /*@ assert sizeof(Dcm_Data4008ByteType) == 4008; */
  /*@ assert sizeof(Dcm_Data4092ByteType) == 4092; */
  /*@ assert sizeof(Dcm_Data5ByteType) == 5; */
  /*@ assert sizeof(Dcm_Data64ByteType) == 64; */
  /*@ assert sizeof(Dcm_Data7ByteType) == 7; */
  /*@ assert sizeof(Dcm_Data80ByteType) == 80; */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester(uint8 Configuration, uint8 Task, const uint8 *Challenge_Certificate_Proof_of_Ownership, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint8 *Authentication_Result, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
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
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_doc
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
/*!
 * \spec
 *    requires $lengthOf(Challenge_Certificate_Proof_of_Ownership) >= sizeof(Dcm_Data4004ByteType);
 *    requires $lengthOf(Authentication_Result) >= sizeof(Dcm_Data3006ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester(
  uint8 Configuration,
  uint8 Task,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Challenge_Certificate_Proof_of_Ownership,
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Authentication_Result,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((Challenge_Certificate_Proof_of_Ownership == NULL_PTR) ||
    (routineInfo == NULL_PTR) ||
    (Verification_Result == NULL_PTR) ||
    (Authentication_Result == NULL_PTR) ||
    (DataLength == NULL_PTR) ||
    (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
      case SSA_PROCCTRL_OPERATION_IDLE:
        /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
        break;
      case SSA_PROCCTRL_OPERATION_PENDING:
        /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_INPUT:
        /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.Configuration = Configuration;
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.Task = Task;
        /* DataLength is the size of passed data in buffer Challenge_Certificate_Proof_of_Ownership. */
        /*@ assert *DataLength <= sizeof(Dcm_Data4004ByteType); */  /* VCA_SSA_PROCCTRL_DATALENGTH_AND_SIZEOF_DATABUFFER_PASSED_BY_DCM */
        /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.Challenge_Certificate_Proof_of_Ownership) >= sizeof(Dcm_Data4004ByteType); */
        ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.Challenge_Certificate_Proof_of_Ownership, Challenge_Certificate_Proof_of_Ownership, *DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */

        Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.DataLength = *DataLength;
        /* Conditionally assign output buffer. */
        ProcCtrl_AssignBufferCond(Authentication_Result, Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.Authentication_Result, *DataLength); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
        /* Preset NRC buffer with value passed from DCM */
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.ErrorCode = *ErrorCode;
        /* Call service dispatcher. */
        Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_AUTHENTICATE_DIAGNOSTIC_USER_OR_TESTER;
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_OUTPUT:
        /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
        *routineInfo = Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.routineInfo;
        *Verification_Result = Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.Verification_Result;
        /* Destination buffer Authentication_Result has length sizeof(Dcm_Data3006ByteType) */
        /* DataLength is the size of passed data in buffer Authentication_Result. */

        /* This runtime check of DataLength ensures that during copying data to Authentication_Result no out of bounds writing occurs. This doublechecks that the Dcm detects incorrect data lengths when copying data. */
        *DataLength = (Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.DataLength < sizeof(Dcm_Data3006ByteType)) ? Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.DataLength : (uint16)(sizeof(Dcm_Data3006ByteType));

        ProcCtrl_CopyBufferCond(Authentication_Result, Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.Authentication_Result, *DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */

        *ErrorCode = Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.ErrorCode;
        /* Set buffer state to free. */
        Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
        break;
      default: /* COV_SSA_MISRA */
        /* Not reachable, QAC only. */
        break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_Certificate_Self_Check
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_Certificate_Self_Check>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_Certificate_Self_Check(Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Verification_Result: uint8* is of type Dcm_Data18ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_Certificate_Self_Check_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_Certificate_Self_Check_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_Certificate_Self_Check_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Certificate_Self_Check_doc
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
/*!
 * \spec
 *    requires $lengthOf(Verification_Result) >= sizeof(Dcm_Data18ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Certificate_Self_Check(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Certificate_Self_Check (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Certificate_Self_Check_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((routineInfo == NULL_PTR) ||
    (Verification_Result == NULL_PTR) ||
    (DataLength == NULL_PTR) ||
    (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
      case SSA_PROCCTRL_OPERATION_IDLE:
        /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
        break;
      case SSA_PROCCTRL_OPERATION_PENDING:
        /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_INPUT:
        /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
        /* No input data to be copied. */
        /* Conditionally assign output buffer. */
        ProcCtrl_AssignBufferCond(Verification_Result, Ssa_ProcCtrlBuffer.SharedData.CertificateSelfCheck.Verification_Result, *DataLength); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
        /* Preset NRC buffer with value passed from DCM */
        Ssa_ProcCtrlBuffer.SharedData.CertificateSelfCheck.ErrorCode = *ErrorCode;
        /* Call service dispatcher. */
        Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_CERTIFICATE_SELF_CHECK;
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_OUTPUT:
        /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
        *routineInfo = Ssa_ProcCtrlBuffer.SharedData.CertificateSelfCheck.routineInfo;
        /* DataLength is the size of passed data in buffer Verification_Result. */
        *DataLength = (Ssa_ProcCtrlBuffer.SharedData.CertificateSelfCheck.DataLength < (uint16)sizeof(Dcm_Data18ByteType)) ? Ssa_ProcCtrlBuffer.SharedData.CertificateSelfCheck.DataLength : (uint16)sizeof(Dcm_Data18ByteType);
        /*@ assert *DataLength <= sizeof(Dcm_Data18ByteType); */ /* VCA_SSA_PROCCTRL_DATALENGTH_CHECKED_BY_RUNTIME_CHECK */
        ProcCtrl_CopyBufferCond(Verification_Result, Ssa_ProcCtrlBuffer.SharedData.CertificateSelfCheck.Verification_Result, *DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */

        *ErrorCode = Ssa_ProcCtrlBuffer.SharedData.CertificateSelfCheck.ErrorCode;
        /* Set buffer state to free. */
        Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
        break;
      default: /* COV_SSA_MISRA */
        /* Not reachable, QAC only. */
        break;
    }
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_Enhance_Access_Rights
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_Enhance_Access_Rights>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_Enhance_Access_Rights(const uint8 *Enhanced_Rights_Certificate, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
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
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Enhance_Access_Rights_doc
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
/*!
 * \spec
 *    requires $lengthOf(Enhanced_Rights_Certificate) >= sizeof(Dcm_Data2002ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Enhance_Access_Rights(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Enhanced_Rights_Certificate,
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result,
  uint16 DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Enhance_Access_Rights (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Enhance_Access_Rights_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((Enhanced_Rights_Certificate == NULL_PTR) ||
    (routineInfo == NULL_PTR) ||
    (Verification_Result == NULL_PTR) ||
    (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
      case SSA_PROCCTRL_OPERATION_IDLE:
        /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
        break;
      case SSA_PROCCTRL_OPERATION_PENDING:
        /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_INPUT:
        /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
        /* DataLength is the size of passed data in buffer Enhanced_Rights_Certificate. */
        /*@ assert DataLength <= sizeof(Dcm_Data2002ByteType); */  /* VCA_SSA_PROCCTRL_DATALENGTH_AND_SIZEOF_DATABUFFER_PASSED_BY_DCM */
        /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRights.Enhanced_Rights_Certificate) >= sizeof(Dcm_Data2002ByteType); */
        ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRights.Enhanced_Rights_Certificate, Enhanced_Rights_Certificate, DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */

        Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRights.DataLength = DataLength;
        /* Preset NRC buffer with value passed from DCM */
        Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRights.ErrorCode = *ErrorCode;
        /* Call service dispatcher. */
        Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_ENHANCE_ACCESS_RIGHTS;
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_OUTPUT:
        /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
        *routineInfo = Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRights.routineInfo;
        *Verification_Result = Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRights.Verification_Result;
        *ErrorCode = Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRights.ErrorCode;
        /* Set buffer state to free. */
        Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
        break;
      default: /* COV_SSA_MISRA */
        /* Not reachable, QAC only. */
        break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_Evaluate_Data_Verification_Certificate
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
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_Evaluate_Data_Verification_Certificate(const uint8 *Data_Verification_Certificate, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
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
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_doc
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
/*!
 * \spec
 *    requires $lengthOf(Data_Verification_Certificate) >= sizeof(Dcm_Data2002ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Evaluate_Data_Verification_Certificate(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Verification_Certificate,
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result,
  uint16 DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Evaluate_Data_Verification_Certificate (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((Data_Verification_Certificate == NULL_PTR) ||
    (routineInfo == NULL_PTR) ||
    (Verification_Result == NULL_PTR) ||
    (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
      case SSA_PROCCTRL_OPERATION_IDLE:
        /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
        break;
      case SSA_PROCCTRL_OPERATION_PENDING:
        /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_INPUT:
        /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
        /* DataLength is the size of passed data in buffer Data_Verification_Certificate. */
        /*@ assert DataLength <= sizeof(Dcm_Data2002ByteType); */  /* VCA_SSA_PROCCTRL_DATALENGTH_AND_SIZEOF_DATABUFFER_PASSED_BY_DCM */
        /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.EvaluateDataVerificationCertificate.Data_Verification_Certificate) >= sizeof(Dcm_Data2002ByteType); */
        ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.EvaluateDataVerificationCertificate.Data_Verification_Certificate, Data_Verification_Certificate, DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */

        Ssa_ProcCtrlBuffer.SharedData.EvaluateDataVerificationCertificate.DataLength = DataLength;
        /* Preset NRC buffer with value passed from DCM */
        Ssa_ProcCtrlBuffer.SharedData.EvaluateDataVerificationCertificate.ErrorCode = *ErrorCode;
        /* Call service dispatcher. */
        Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_EVALUATE_DATA_VERIF_CERT;
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_OUTPUT:
        /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
        *routineInfo = Ssa_ProcCtrlBuffer.SharedData.EvaluateDataVerificationCertificate.routineInfo;
        *Verification_Result = Ssa_ProcCtrlBuffer.SharedData.EvaluateDataVerificationCertificate.Verification_Result;
        *ErrorCode = Ssa_ProcCtrlBuffer.SharedData.EvaluateDataVerificationCertificate.ErrorCode;
        /* Set buffer state to free. */
        Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
        break;
      default: /* COV_SSA_MISRA */
        /* Not reachable, QAC only. */
        break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_Inject_Seed
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Inject_Seed>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_Inject_Seed(const uint8 *Ephemeral_Backend_Public_Key_In, const uint8 *Data_Signature_In, const uint8 *Encrypted_Seed_In, Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Verification_Result_Out, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Ephemeral_Backend_Public_Key_In: uint8* is of type Dcm_Data32ByteType
 *     Argument Data_Signature_In: uint8* is of type Dcm_Data64ByteType
 *     Argument Encrypted_Seed_In: uint8* is of type Dcm_Data1058ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Inject_Seed_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Inject_Seed_DCM_E_PENDING
 *   RTE_E_RoutineServices_Inject_Seed_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Inject_Seed_doc
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
/*!
* \spec
*    requires $lengthOf(Ephemeral_Backend_Public_Key_In) >= sizeof(Dcm_Data32ByteType)
*    requires $lengthOf(Data_Signature_In) >= sizeof(Dcm_Data64ByteType)
*    requires $lengthOf(Encrypted_Seed_In) >= sizeof(Dcm_Data1058ByteType);
* \endspec
*/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Inject_Seed(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_Backend_Public_Key_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Signature_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Encrypted_Seed_In,
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out,
  uint16 DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Inject_Seed (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Inject_Seed_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((Ephemeral_Backend_Public_Key_In == NULL_PTR) ||
    (Data_Signature_In == NULL_PTR) ||
    (Encrypted_Seed_In == NULL_PTR) ||
    (routineInfo_Out == NULL_PTR) ||
    (Verification_Result_Out == NULL_PTR) ||
    (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
      case SSA_PROCCTRL_OPERATION_IDLE:
        /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
        break;
      case SSA_PROCCTRL_OPERATION_PENDING:
        /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_INPUT:
        /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */

        /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.InjectSeed.Ephemeral_Backend_Public_Key_In) >= sizeof(Dcm_Data32ByteType); */
        ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.InjectSeed.Ephemeral_Backend_Public_Key_In, Ephemeral_Backend_Public_Key_In, sizeof(Dcm_Data32ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
        /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.InjectSeed.Data_Signature_In) >= sizeof(Dcm_Data64ByteType); */
        ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.InjectSeed.Data_Signature_In, Data_Signature_In, sizeof(Dcm_Data64ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */

        /* DataLength is the size of passed data in buffer Encrypted_Seed_In. */
        /*@ assert DataLength <= sizeof(Dcm_Data1058ByteType); */  /* VCA_SSA_PROCCTRL_DATALENGTH_AND_SIZEOF_DATABUFFER_PASSED_BY_DCM */
        /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.InjectSeed.Encrypted_Seed_In) >= sizeof(Dcm_Data1058ByteType); */
        ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.InjectSeed.Encrypted_Seed_In, Encrypted_Seed_In, DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */

        Ssa_ProcCtrlBuffer.SharedData.InjectSeed.DataLength = DataLength;
        /* Preset NRC buffer with value passed from DCM */
        Ssa_ProcCtrlBuffer.SharedData.InjectSeed.ErrorCode = *ErrorCode;
        /* Call service dispatcher. */
        Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_INJECT_SEED;
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_OUTPUT:
        /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
        *routineInfo_Out = Ssa_ProcCtrlBuffer.SharedData.InjectSeed.routineInfo_Out;
        *Verification_Result_Out = Ssa_ProcCtrlBuffer.SharedData.InjectSeed.Verification_Result_Out;
        *ErrorCode = Ssa_ProcCtrlBuffer.SharedData.InjectSeed.ErrorCode;
        /* Set buffer state to free. */
        Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
        break;
      default: /* COV_SSA_MISRA */
        /* Not reachable, QAC only. */
        break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_Replace_Certificates
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_Replace_Certificates>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_Replace_Certificates(const uint8 *Certificates, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Certificates: uint8* is of type Dcm_Data4008ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_Replace_Certificates_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_Replace_Certificates_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_Replace_Certificates_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Replace_Certificates_doc
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
/*!
 * \spec
 *    requires $lengthOf(Certificates) >= sizeof(Dcm_Data4008ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Replace_Certificates(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates,
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result,
  uint16 DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Replace_Certificates (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Replace_Certificates_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((Certificates == NULL_PTR) ||
    (routineInfo == NULL_PTR) ||
    (Verification_Result == NULL_PTR) ||
    (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
      case SSA_PROCCTRL_OPERATION_IDLE:
        /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
        break;
      case SSA_PROCCTRL_OPERATION_PENDING:
        /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_INPUT:
        /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
        /* DataLength is the size of passed data in buffer Certificates. */
        /*@ assert DataLength <= sizeof(Dcm_Data4008ByteType); */  /* VCA_SSA_PROCCTRL_DATALENGTH_AND_SIZEOF_DATABUFFER_PASSED_BY_DCM */
        /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.ReplaceCertificates.Certificates) >= sizeof(Dcm_Data4008ByteType); */
        ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.ReplaceCertificates.Certificates, Certificates, DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */

        Ssa_ProcCtrlBuffer.SharedData.ReplaceCertificates.DataLength = DataLength;
        /* Preset NRC buffer with value passed from DCM */
        Ssa_ProcCtrlBuffer.SharedData.ReplaceCertificates.ErrorCode = *ErrorCode;
        /* Call service dispatcher. */
        Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_REPLACE_CERTIFICATE;
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_OUTPUT:
        /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
        *routineInfo = Ssa_ProcCtrlBuffer.SharedData.ReplaceCertificates.routineInfo;
        *Verification_Result = Ssa_ProcCtrlBuffer.SharedData.ReplaceCertificates.Verification_Result;
        *ErrorCode = Ssa_ProcCtrlBuffer.SharedData.ReplaceCertificates.ErrorCode;
        /* Set buffer state to free. */
        Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
        break;
      default: /* COV_SSA_MISRA */
        /* Not reachable, QAC only. */
        break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Certificates
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Replace_Trust_model_Certificates>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Certificates(const uint8 *Trust_Certificates_In, Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Verification_Result_Out, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Trust_Certificates_In: uint8* is of type Dcm_Data3006ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Replace_Trust_model_Certificates_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Replace_Trust_model_Certificates_DCM_E_PENDING
 *   RTE_E_RoutineServices_Replace_Trust_model_Certificates_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Certificates_doc
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
/*!
 * \spec
 *    requires $lengthOf(Trust_Certificates_In) >= sizeof(Dcm_Data3006ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Certificates(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Trust_Certificates_In,
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out,
  uint16 DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Certificates (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Replace_Trust_model_Certificates_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((Trust_Certificates_In == NULL_PTR) ||
    (routineInfo_Out == NULL_PTR) ||
    (Verification_Result_Out == NULL_PTR) ||
    (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
      case SSA_PROCCTRL_OPERATION_IDLE:
        /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
        break;
      case SSA_PROCCTRL_OPERATION_PENDING:
        /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_INPUT:
        /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
        /* DataLength is the size of passed data in buffer Trust_Certificates_In. */
        /*@ assert DataLength <= sizeof(Dcm_Data3006ByteType); */  /* VCA_SSA_PROCCTRL_DATALENGTH_AND_SIZEOF_DATABUFFER_PASSED_BY_DCM */
        /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelCertificates.Trust_Certificates_In) >= sizeof(Dcm_Data3006ByteType); */
        ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelCertificates.Trust_Certificates_In, Trust_Certificates_In, DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */

        Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelCertificates.DataLength = DataLength;
        /* Preset NRC buffer with value passed from DCM */
        Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelCertificates.ErrorCode = *ErrorCode;
        /* Call service dispatcher. */
        Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_REPLACE_TRUST_MODEL_CERTIFICATES;
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_OUTPUT:
        /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
        *routineInfo_Out = Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelCertificates.routineInfo_Out;
        *Verification_Result_Out = Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelCertificates.Verification_Result_Out;
        *ErrorCode = Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelCertificates.ErrorCode;
        /* Set buffer state to free. */
        Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
        break;
      default: /* COV_SSA_MISRA */
        /* Not reachable, QAC only. */
        break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Root_Certificate
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Replace_Trust_model_Root_Certificate>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Root_Certificate(const uint8 *signature_new_Root_In, const uint8 *signature_In, const uint8 *Certificates_In, Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Verification_Result_Out, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument signature_new_Root_In: uint8* is of type Dcm_Data64ByteType
 *     Argument signature_In: uint8* is of type Dcm_Data64ByteType
 *     Argument Certificates_In: uint8* is of type Dcm_Data2004ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_DCM_E_PENDING
 *   RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Root_Certificate_doc
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
/*!
 * \spec
 *    requires $lengthOf(signature_new_Root_In) >= sizeof(Dcm_Data64ByteType);
 *    requires $lengthOf(signature_In) >= sizeof(Dcm_Data64ByteType);
 *    requires $lengthOf(Certificates_In) >= sizeof(Dcm_Data2004ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Root_Certificate(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) signature_new_Root_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) signature_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates_In,
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out,
  uint16 DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Replace_Trust_model_Root_Certificate (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((signature_new_Root_In == NULL_PTR) ||
    (signature_In == NULL_PTR) ||
    (Certificates_In == NULL_PTR) ||
    (routineInfo_Out == NULL_PTR) ||
    (Verification_Result_Out == NULL_PTR) ||
    (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
      case SSA_PROCCTRL_OPERATION_IDLE:
        /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
        break;
      case SSA_PROCCTRL_OPERATION_PENDING:
        /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_INPUT:
        /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
        /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.signature_new_Root_In) >= sizeof(Dcm_Data64ByteType); */
        ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.signature_new_Root_In, signature_new_Root_In, sizeof(Dcm_Data64ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
        /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.signature_In) >= sizeof(Dcm_Data64ByteType); */
         ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.signature_In, signature_In, sizeof(Dcm_Data64ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
        /* DataLength is the size of passed data in buffer Certificates_In. */
        /*@ assert DataLength <= sizeof(Dcm_Data2004ByteType); */  /* VCA_SSA_PROCCTRL_DATALENGTH_AND_SIZEOF_DATABUFFER_PASSED_BY_DCM */
        /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.Certificates_In) >= sizeof(Dcm_Data2004ByteType); */
        ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.Certificates_In, Certificates_In, DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */

        Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.DataLength = DataLength;
        /* Preset NRC buffer with value passed from DCM */
        Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.ErrorCode = *ErrorCode;
        /* Call service dispatcher. */
        Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_REPLACE_TRUST_MODEL_ROOT_CERTIFICATE;
        (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
        break;
      case SSA_PROCCTRL_OPERATION_OUTPUT:
        /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
        *routineInfo_Out = Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.routineInfo_Out;
        *Verification_Result_Out = Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.Verification_Result_Out;
        *ErrorCode = Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.ErrorCode;
        /* Set buffer state to free. */
        Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
        break;
      default: /* COV_SSA_MISRA */
        /* Not reachable, QAC only. */
        break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_Reset_VIN_Values
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
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_Reset_VIN_Values(Dcm_OpStatusType OpStatus, uint8 *routineInfo, Dcm_NegativeResponseCodeType *ErrorCode)
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
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Reset_VIN_Values_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Reset_VIN_Values(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Reset_VIN_Values (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Reset_VIN_Values_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((routineInfo == NULL_PTR) || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {

    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericRoutineService_PostStateMachineHandler(operation, routineInfo, ErrorCode, Ssa_ProcCtrlBuffer.SharedData.ResetVinValues.routineInfo, &Ssa_ProcCtrlBuffer.SharedData.ResetVinValues.ErrorCode, SSA_PROCCTRL_SERVICE_ID_RESET_VIN_VALUES);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption(const uint8 *Nonce, const uint8 *Ephemeral_ECU_Public_Key, const uint8 *Data_Signature_In, const uint8 *Target_ECU_Certificate, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint8 *Date_and_Time, uint8 *Tick_Count, uint8 *Tick_Count_Offset, uint8 *Encrypted_Nonce_and_Shared_Secret, uint8 *Ephemeral_VSM_Public_Key, uint8 *Data_Signature_Out, uint8 *VSM_s_ECU_Certificate, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Nonce: uint8* is of type Dcm_Data32ByteType
 *     Argument Ephemeral_ECU_Public_Key: uint8* is of type Dcm_Data32ByteType
 *     Argument Data_Signature_In: uint8* is of type Dcm_Data64ByteType
 *     Argument Target_ECU_Certificate: uint8* is of type Dcm_Data1002ByteType
 *     Argument Date_and_Time: uint8* is of type Dcm_Data7ByteType
 *     Argument Tick_Count: uint8* is of type Dcm_Data5ByteType
 *     Argument Tick_Count_Offset: uint8* is of type Dcm_Data5ByteType
 *     Argument Encrypted_Nonce_and_Shared_Secret: uint8* is of type Dcm_Data80ByteType
 *     Argument Ephemeral_VSM_Public_Key: uint8* is of type Dcm_Data32ByteType
 *     Argument Data_Signature_Out: uint8* is of type Dcm_Data64ByteType
 *     Argument VSM_s_ECU_Certificate: uint8* is of type Dcm_Data1002ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption_doc
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
/*!
 * \spec
 *    requires $lengthOf(Nonce) >= sizeof(Dcm_Data32ByteType);
 *    requires $lengthOf(Ephemeral_ECU_Public_Key) >= sizeof(Dcm_Data32ByteType);
 *    requires $lengthOf(Data_Signature_In) >= sizeof(Dcm_Data64ByteType);
 *    requires $lengthOf(Target_ECU_Certificate) >= sizeof(Dcm_Data1002ByteType);
 *    requires $lengthOf(Date_and_Time) >= sizeof(Dcm_Data7ByteType);
 *    requires $lengthOf(Tick_Count) >= sizeof(Dcm_Data5ByteType);
 *    requires $lengthOf(Tick_Count_Offset) >= sizeof(Dcm_Data5ByteType);
 *    requires $lengthOf(Encrypted_Nonce_and_Shared_Secret) >= sizeof(Dcm_Data80ByteType);
 *    requires $lengthOf(Ephemeral_VSM_Public_Key) >= sizeof(Dcm_Data32ByteType);
 *    requires $lengthOf(Data_Signature_Out) >= sizeof(Dcm_Data64ByteType);
 *    requires $lengthOf(VSM_s_ECU_Certificate) >= sizeof(Dcm_Data1002ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Nonce,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_ECU_Public_Key,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Signature_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Target_ECU_Certificate,
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Date_and_Time,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Tick_Count,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Tick_Count_Offset,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Encrypted_Nonce_and_Shared_Secret,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Ephemeral_VSM_Public_Key,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data_Signature_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) VSM_s_ECU_Certificate,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((Nonce == NULL_PTR)
    || (Ephemeral_ECU_Public_Key == NULL_PTR)
    || (Data_Signature_In == NULL_PTR)
    || (Target_ECU_Certificate == NULL_PTR)
    || (routineInfo == NULL_PTR)
    || (Verification_Result == NULL_PTR)
    || (Date_and_Time == NULL_PTR)
    || (Tick_Count == NULL_PTR)
    || (Tick_Count_Offset == NULL_PTR)
    || (Encrypted_Nonce_and_Shared_Secret == NULL_PTR)
    || (Ephemeral_VSM_Public_Key == NULL_PTR)
    || (Data_Signature_Out == NULL_PTR)
    || (VSM_s_ECU_Certificate == NULL_PTR)
    || (DataLength == NULL_PTR)
    || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
    case SSA_PROCCTRL_OPERATION_IDLE:
      /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
      break;
    case SSA_PROCCTRL_OPERATION_PENDING:
      /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_INPUT:
      /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Nonce) >= sizeof(Dcm_Data32ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Nonce, Nonce, sizeof(Dcm_Data32ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Ephemeral_ECU_Public_Key) >= sizeof(Dcm_Data32ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Ephemeral_ECU_Public_Key, Ephemeral_ECU_Public_Key, sizeof(Dcm_Data32ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
     /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Data_Signature_In) >= sizeof(Dcm_Data64ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Data_Signature_In, Data_Signature_In, sizeof(Dcm_Data64ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /* DataLength is the size of passed data in buffer Target_ECU_Certificate. */
      /*@ assert *DataLength <= sizeof(Dcm_Data1002ByteType); */  /* VCA_SSA_PROCCTRL_DATALENGTH_AND_SIZEOF_DATABUFFER_PASSED_BY_DCM */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Target_ECU_Certificate) >= sizeof(Dcm_Data1002ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Target_ECU_Certificate, Target_ECU_Certificate, *DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */

      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.DataLength = *DataLength;
      /* Conditionally assign output buffer. */
      ProcCtrl_AssignBufferCond(Date_and_Time, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Date_and_Time, sizeof(Dcm_Data7ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Tick_Count, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Tick_Count, sizeof(Dcm_Data5ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Tick_Count_Offset, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Tick_Count_Offset, sizeof(Dcm_Data5ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Encrypted_Nonce_and_Shared_Secret, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Encrypted_Nonce_and_Shared_Secret, sizeof(Dcm_Data80ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Ephemeral_VSM_Public_Key, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Ephemeral_VSM_Public_Key, sizeof(Dcm_Data32ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Data_Signature_Out, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Data_Signature_Out, sizeof(Dcm_Data64ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(VSM_s_ECU_Certificate, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.VSM_s_ECU_Certificate, *DataLength); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      /* Preset NRC buffer with value passed from DCM */
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.ErrorCode = *ErrorCode;
      /* Call service dispatcher. */
      Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_SECOC_ECU_SHARED_SECRET_ENCRYPTION;
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_OUTPUT:
      /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
      *routineInfo = Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.routineInfo;
      *Verification_Result = Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Verification_Result;
      ProcCtrl_CopyBufferCond(Date_and_Time, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Date_and_Time, sizeof(Dcm_Data7ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Tick_Count, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Tick_Count, sizeof(Dcm_Data5ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Tick_Count_Offset, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Tick_Count_Offset, sizeof(Dcm_Data5ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Encrypted_Nonce_and_Shared_Secret, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Encrypted_Nonce_and_Shared_Secret, sizeof(Dcm_Data80ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Ephemeral_VSM_Public_Key, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Ephemeral_VSM_Public_Key, sizeof(Dcm_Data32ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Data_Signature_Out, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Data_Signature_Out, sizeof(Dcm_Data64ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /* Destination buffer VSM_s_ECU_Certificate has length sizeof(Dcm_Data1002ByteType) */
      /* DataLength is the size of passed data in buffer VSM_s_ECU_Certificate. */
      *DataLength = (Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.DataLength < (uint16)sizeof(Dcm_Data1002ByteType)) ? Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.DataLength : (uint16)sizeof(Dcm_Data1002ByteType);
      ProcCtrl_CopyBufferCond(VSM_s_ECU_Certificate, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.VSM_s_ECU_Certificate, *DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      *ErrorCode = Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.ErrorCode;
      /* Set buffer state to free. */
      Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
      break;
    default: /* COV_SSA_MISRA */
    /* Not reachable, QAC only. */
      break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization(const uint8 *Nonce, const uint8 *Ephemeral_ECU_Public_Key, const uint8 *Data_Signature_In, const uint8 *Target_ECU_Certificate, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint8 *Date_and_Time, uint8 *Tick_Count, uint8 *Tick_Count_Offset, uint8 *Encrypted_Nonce_and_Shared_Secret, uint8 *Ephemeral_VSM_Public_Key, uint8 *Data_Signature_Out, uint8 *VSM_s_ECU_Certificate, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Nonce: uint8* is of type Dcm_Data32ByteType
 *     Argument Ephemeral_ECU_Public_Key: uint8* is of type Dcm_Data32ByteType
 *     Argument Data_Signature_In: uint8* is of type Dcm_Data64ByteType
 *     Argument Target_ECU_Certificate: uint8* is of type Dcm_Data1002ByteType
 *     Argument Date_and_Time: uint8* is of type Dcm_Data7ByteType
 *     Argument Tick_Count: uint8* is of type Dcm_Data5ByteType
 *     Argument Tick_Count_Offset: uint8* is of type Dcm_Data5ByteType
 *     Argument Encrypted_Nonce_and_Shared_Secret: uint8* is of type Dcm_Data80ByteType
 *     Argument Ephemeral_VSM_Public_Key: uint8* is of type Dcm_Data32ByteType
 *     Argument Data_Signature_Out: uint8* is of type Dcm_Data64ByteType
 *     Argument VSM_s_ECU_Certificate: uint8* is of type Dcm_Data1002ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization_doc
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
/*!
 * \spec
 *    requires $lengthOf(Nonce) >= sizeof(Dcm_Data32ByteType);
 *    requires $lengthOf(Ephemeral_ECU_Public_Key) >= sizeof(Dcm_Data32ByteType);
 *    requires $lengthOf(Data_Signature_In) >= sizeof(Dcm_Data64ByteType);
 *    requires $lengthOf(Target_ECU_Certificate) >= sizeof(Dcm_Data1002ByteType);
 *    requires $lengthOf(Date_and_Time) >= sizeof(Dcm_Data7ByteType);
 *    requires $lengthOf(Tick_Count) >= sizeof(Dcm_Data5ByteType);
 *    requires $lengthOf(Tick_Count_Offset) >= sizeof(Dcm_Data5ByteType);
 *    requires $lengthOf(Encrypted_Nonce_and_Shared_Secret) >= sizeof(Dcm_Data80ByteType);
 *    requires $lengthOf(Ephemeral_VSM_Public_Key) >= sizeof(Dcm_Data32ByteType);
 *    requires $lengthOf(Data_Signature_Out) >= sizeof(Dcm_Data64ByteType);
 *    requires $lengthOf(VSM_s_ECU_Certificate) >= sizeof(Dcm_Data1002ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Nonce,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_ECU_Public_Key,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Signature_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Target_ECU_Certificate,
  Dcm_OpStatusType OpStatus, P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Date_and_Time,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Tick_Count,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Tick_Count_Offset,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Encrypted_Nonce_and_Shared_Secret,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Ephemeral_VSM_Public_Key,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data_Signature_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) VSM_s_ECU_Certificate,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((Nonce == NULL_PTR)
      || (Ephemeral_ECU_Public_Key == NULL_PTR)
      || (Data_Signature_In == NULL_PTR)
      || (Target_ECU_Certificate == NULL_PTR)
      || (routineInfo == NULL_PTR)
      || (Verification_Result == NULL_PTR)
      || (Date_and_Time == NULL_PTR)
      || (Tick_Count == NULL_PTR)
      || (Tick_Count_Offset == NULL_PTR)
      || (Encrypted_Nonce_and_Shared_Secret == NULL_PTR)
      || (Ephemeral_VSM_Public_Key == NULL_PTR)
      || (Data_Signature_Out == NULL_PTR)
      || (VSM_s_ECU_Certificate == NULL_PTR)
      || (DataLength == NULL_PTR)
      || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
    case SSA_PROCCTRL_OPERATION_IDLE:
      /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
      break;
    case SSA_PROCCTRL_OPERATION_PENDING:
      /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_INPUT:
      /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Nonce) >= sizeof(Dcm_Data32ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Nonce, Nonce, sizeof(Dcm_Data32ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Ephemeral_ECU_Public_Key) >= sizeof(Dcm_Data32ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Ephemeral_ECU_Public_Key, Ephemeral_ECU_Public_Key, sizeof(Dcm_Data32ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Data_Signature_In) >= sizeof(Dcm_Data64ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Data_Signature_In, Data_Signature_In, sizeof(Dcm_Data64ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /* DataLength is the size of passed data in buffer Target_ECU_Certificate. */
      /*@ assert *DataLength <= sizeof(Dcm_Data1002ByteType); */  /* VCA_SSA_PROCCTRL_DATALENGTH_AND_SIZEOF_DATABUFFER_PASSED_BY_DCM */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Target_ECU_Certificate) >= sizeof(Dcm_Data1002ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Target_ECU_Certificate, Target_ECU_Certificate, *DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */

      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.DataLength = *DataLength;
      /* Conditionally assign output buffer. */
      ProcCtrl_AssignBufferCond(Date_and_Time, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Date_and_Time, sizeof(Dcm_Data7ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Tick_Count, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Tick_Count, sizeof(Dcm_Data5ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Tick_Count_Offset, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Tick_Count_Offset, sizeof(Dcm_Data5ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Encrypted_Nonce_and_Shared_Secret, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Encrypted_Nonce_and_Shared_Secret, sizeof(Dcm_Data80ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Ephemeral_VSM_Public_Key, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Ephemeral_VSM_Public_Key, sizeof(Dcm_Data32ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Data_Signature_Out, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Data_Signature_Out, sizeof(Dcm_Data64ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(VSM_s_ECU_Certificate, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.VSM_s_ECU_Certificate, *DataLength); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      /* Preset NRC buffer with value passed from DCM */
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.ErrorCode = *ErrorCode;
      /* Call service dispatcher. */
      Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_SECOC_ECU_TICKCOUNT_SYNC;
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_OUTPUT:
      /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
      *routineInfo = Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.routineInfo;
      *Verification_Result = Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Verification_Result;
      ProcCtrl_CopyBufferCond(Date_and_Time, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Date_and_Time, sizeof(Dcm_Data7ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Tick_Count, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Tick_Count, sizeof(Dcm_Data5ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Tick_Count_Offset, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Tick_Count_Offset, sizeof(Dcm_Data5ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Encrypted_Nonce_and_Shared_Secret, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Encrypted_Nonce_and_Shared_Secret, sizeof(Dcm_Data80ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Ephemeral_VSM_Public_Key, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Ephemeral_VSM_Public_Key, sizeof(Dcm_Data32ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Data_Signature_Out, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Data_Signature_Out, sizeof(Dcm_Data64ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /* Destination buffer VSM_s_ECU_Certificate has length sizeof(Dcm_Data1002ByteType) */
      /* DataLength is the size of passed data in buffer VSM_s_ECU_Certificate. */
      *DataLength = (Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.DataLength < (uint16)sizeof(Dcm_Data1002ByteType)) ? Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.DataLength : (uint16)sizeof(Dcm_Data1002ByteType);
      ProcCtrl_CopyBufferCond(VSM_s_ECU_Certificate, Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.VSM_s_ECU_Certificate, *DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      *ErrorCode = Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.ErrorCode;
      /* Set buffer state to free. */
      Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
      break;
    default: /* COV_SSA_MISRA */
    /* Not reachable, QAC only. */
      break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys(Dcm_OpStatusType OpStatus, uint8 *routineInfo, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((routineInfo == NULL_PTR) || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericRoutineService_PostStateMachineHandler(operation, routineInfo, ErrorCode, Ssa_ProcCtrlBuffer.SharedData.SecOcVsmDeriveSymmetricKeysType.routineInfo, &Ssa_ProcCtrlBuffer.SharedData.SecOcVsmDeriveSymmetricKeysType.ErrorCode, SSA_PROCCTRL_SERVICE_ID_SECOC_VSM_DERIVE_SYMMETRIC_KEYS);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret(Dcm_OpStatusType OpStatus, uint8 *routineInfo, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((routineInfo == NULL_PTR) || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericRoutineService_PostStateMachineHandler(operation, routineInfo, ErrorCode, Ssa_ProcCtrlBuffer.SharedData.SecOcVsmRenewSharedSecretType.routineInfo, &Ssa_ProcCtrlBuffer.SharedData.SecOcVsmRenewSharedSecretType.ErrorCode, SSA_PROCCTRL_SERVICE_ID_SECOC_VSM_RENEW_SHARED_SECRET);
  }
  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution(Dcm_OpStatusType OpStatus, uint8 *routineInfo, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution_DCM_E_PENDING
 *   RTE_E_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution_doc
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

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((routineInfo == NULL_PTR) || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    ProcCtrl_GenericRoutineService_PostStateMachineHandler(operation, routineInfo, ErrorCode, Ssa_ProcCtrlBuffer.SharedData.SecOcVehicleSharedSecretDistribution.routineInfo, &Ssa_ProcCtrlBuffer.SharedData.SecOcVehicleSharedSecretDistribution.ErrorCode, SSA_PROCCTRL_SERVICE_ID_SECOC_VEHICLE_SHARED_SECRET_DISTRIBUTION);
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time(Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Nonce, Dcm_NegativeResponseCodeType *ErrorCode)
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
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_doc
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
/*!
 * \spec
 *    requires $lengthOf(Nonce) >= sizeof(Dcm_Data32ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Nonce,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((routineInfo == NULL_PTR) || (Nonce == NULL_PTR) || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
    case SSA_PROCCTRL_OPERATION_IDLE:
      /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
      break;
    case SSA_PROCCTRL_OPERATION_PENDING:
      /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_INPUT:
      /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
      /* No input data to be copied. */
      /* Conditionally assign output buffer. */
      ProcCtrl_AssignBufferCond(Nonce, Ssa_ProcCtrlBuffer.SharedData.SynchronizeSecuredSystemDataAndTime.Nonce, sizeof(Dcm_Data32ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      /* Preset NRC buffer with value passed from DCM */
      Ssa_ProcCtrlBuffer.SharedData.SynchronizeSecuredSystemDataAndTime.ErrorCode = *ErrorCode;
      /* Call service dispatcher. */
      Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_SYNCHRONIZE_SECURED_SYSTEM_DATE_AND_TIME;
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_OUTPUT:
      /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
      *routineInfo = Ssa_ProcCtrlBuffer.SharedData.SynchronizeSecuredSystemDataAndTime.routineInfo;
      ProcCtrl_CopyBufferCond(Nonce, Ssa_ProcCtrlBuffer.SharedData.SynchronizeSecuredSystemDataAndTime.Nonce, sizeof(Dcm_Data32ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      *ErrorCode = Ssa_ProcCtrlBuffer.SharedData.SynchronizeSecuredSystemDataAndTime.ErrorCode;
      /* Set buffer state to free. */
      Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
      break;
    default: /* COV_SSA_MISRA */
      /* Not reachable, QAC only. */
      break;
    }
  }

  return retVal;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_Generate_Key_Pair
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Trust_Model_Generate_Key_Pair>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_Generate_Key_Pair(Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Verification_Result_Out, uint8 *CSR_Signature_Out, uint8 *Trust_Model_ECU_CSR_Out, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument CSR_Signature_Out: uint8* is of type Dcm_Data64ByteType
 *     Argument Trust_Model_ECU_CSR_Out: uint8* is of type Dcm_Data1002ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_DCM_E_PENDING
 *   RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_Generate_Key_Pair_doc
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
/*!
 * \spec
 *    requires $lengthOf(CSR_Signature_Out) >= sizeof(Dcm_Data64ByteType);
 *    requires $lengthOf(Trust_Model_ECU_CSR_Out) >= sizeof(Dcm_Data1002ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_Generate_Key_Pair(
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) CSR_Signature_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Trust_Model_ECU_CSR_Out,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_Generate_Key_Pair (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((routineInfo_Out == NULL_PTR)
    || (Verification_Result_Out == NULL_PTR)
    || (CSR_Signature_Out == NULL_PTR)
    || (Trust_Model_ECU_CSR_Out == NULL_PTR)
    || (DataLength == NULL_PTR)
    || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation)
    {
    case SSA_PROCCTRL_OPERATION_IDLE:
      /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
      break;
    case SSA_PROCCTRL_OPERATION_PENDING:
      /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_INPUT:
      /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
      ProcCtrl_AssignBufferCond( /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
        CSR_Signature_Out,
        Ssa_ProcCtrlBuffer.SharedData.TrustModelGenerateKeyPair.CSR_Signature_Out,
        sizeof(Dcm_Data64ByteType));
      ProcCtrl_AssignBufferCond( /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
        Trust_Model_ECU_CSR_Out,
        Ssa_ProcCtrlBuffer.SharedData.TrustModelGenerateKeyPair.Trust_Model_ECU_CSR_Out,
        sizeof(Dcm_Data1002ByteType));
      /* Preset NRC buffer with value passed from DCM */
      Ssa_ProcCtrlBuffer.SharedData.TrustModelGenerateKeyPair.ErrorCode = *ErrorCode;
      /* Call service dispatcher. */
      Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_GENERATE_KEY_PAIR;
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_OUTPUT:
      /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free
       * the buffer to be accessible by next service. */
      *routineInfo_Out = Ssa_ProcCtrlBuffer.SharedData.TrustModelGenerateKeyPair.routineInfo_Out;
      *Verification_Result_Out = Ssa_ProcCtrlBuffer.SharedData.TrustModelGenerateKeyPair.Verification_Result_Out;
      *DataLength = (uint16)
        SSA_MIN(Ssa_ProcCtrlBuffer.SharedData.TrustModelGenerateKeyPair.DataLength, sizeof(Dcm_Data1002ByteType));
      /*@ assert *DataLength <= sizeof(Dcm_Data1002ByteType); */  /* VCA_SSA_PROCCTRL_DATALENGTH_CHECKED_BY_RUNTIME_CHECK */

      *ErrorCode = Ssa_ProcCtrlBuffer.SharedData.TrustModelGenerateKeyPair.ErrorCode;
      ProcCtrl_CopyBufferCond( /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
        CSR_Signature_Out,
        Ssa_ProcCtrlBuffer.SharedData.TrustModelGenerateKeyPair.CSR_Signature_Out,
        sizeof(Dcm_Data64ByteType));
      /* Destination buffer Trust_Model_ECU_CSR_Out has length sizeof(Dcm_Data1002ByteType) */
      /* DataLength is the length of Trust_Model_ECU_CSR_Out in bytes. */
      ProcCtrl_CopyBufferCond( /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
        Trust_Model_ECU_CSR_Out,
        Ssa_ProcCtrlBuffer.SharedData.TrustModelGenerateKeyPair.Trust_Model_ECU_CSR_Out,
        *DataLength);
      /* Set buffer state to free. */
      Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
      break;
    default: /* COV_SSA_MISRA */
      /* Not reachable, QAC only. */
      break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution(const uint8 *Date_and_Time_In, const uint8 *Tick_Count_In, const uint8 *Tick_Count_Offset_In, const uint8 *Encrypted_Nonce_and_Shared_Secret_In, const uint8 *Ephemeral_VSM_Public_Key_In, const uint8 *Data_Signature_In, const uint8 *Certificates_In, Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Verification_Result_Out, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Date_and_Time_In: uint8* is of type Dcm_Data7ByteType
 *     Argument Tick_Count_In: uint8* is of type Dcm_Data5ByteType
 *     Argument Tick_Count_Offset_In: uint8* is of type Dcm_Data5ByteType
 *     Argument Encrypted_Nonce_and_Shared_Secret_In: uint8* is of type Dcm_Data80ByteType
 *     Argument Ephemeral_VSM_Public_Key_In: uint8* is of type Dcm_Data32ByteType
 *     Argument Data_Signature_In: uint8* is of type Dcm_Data64ByteType
 *     Argument Certificates_In: uint8* is of type Dcm_Data3006ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_DCM_E_PENDING
 *   RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_doc
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
/*!
 * \spec
 *    requires $lengthOf(Date_and_Time_In) >= sizeof(Dcm_Data7ByteType);
 *    requires $lengthOf(Tick_Count_In) >= sizeof(Dcm_Data5ByteType);
 *    requires $lengthOf(Tick_Count_Offset_In) >= sizeof(Dcm_Data5ByteType);
 *    requires $lengthOf(Encrypted_Nonce_and_Shared_Secret_In) >= sizeof(Dcm_Data80ByteType);
 *    requires $lengthOf(Ephemeral_VSM_Public_Key_In) >= sizeof(Dcm_Data32ByteType);
 *    requires $lengthOf(Data_Signature_In) >= sizeof(Dcm_Data64ByteType);
 *    requires $lengthOf(Certificates_In) >= sizeof(Dcm_Data3006ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Date_and_Time_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Tick_Count_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Tick_Count_Offset_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Encrypted_Nonce_and_Shared_Secret_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_VSM_Public_Key_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Data_Signature_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Certificates_In,
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out,
  uint16 DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Distribution (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((Date_and_Time_In == NULL_PTR)
    || (Tick_Count_In == NULL_PTR)
    || (Tick_Count_Offset_In == NULL_PTR)
    || (Encrypted_Nonce_and_Shared_Secret_In == NULL_PTR)
    || (Ephemeral_VSM_Public_Key_In == NULL_PTR)
    || (Data_Signature_In == NULL_PTR)
    || (Certificates_In == NULL_PTR)
    || (routineInfo_Out == NULL_PTR)
    || (Verification_Result_Out == NULL_PTR)
    || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
    case SSA_PROCCTRL_OPERATION_IDLE:
      /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
      break;
    case SSA_PROCCTRL_OPERATION_PENDING:
      /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_INPUT:
      /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Date_and_Time_In) >= sizeof(Dcm_Data7ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Date_and_Time_In, Date_and_Time_In, sizeof(Dcm_Data7ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Tick_Count_In) >= sizeof(Dcm_Data5ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Tick_Count_In, Tick_Count_In, sizeof(Dcm_Data5ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Tick_Count_Offset_In) >= sizeof(Dcm_Data5ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Tick_Count_Offset_In, Tick_Count_Offset_In, sizeof(Dcm_Data5ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Encrypted_Nonce_and_Shared_Secret_In) >= sizeof(Dcm_Data80ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Encrypted_Nonce_and_Shared_Secret_In, Encrypted_Nonce_and_Shared_Secret_In, sizeof(Dcm_Data80ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Ephemeral_VSM_Public_Key_In) >= sizeof(Dcm_Data32ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Ephemeral_VSM_Public_Key_In, Ephemeral_VSM_Public_Key_In, sizeof(Dcm_Data32ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Data_Signature_In) >= sizeof(Dcm_Data64ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Data_Signature_In, Data_Signature_In, sizeof(Dcm_Data64ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /* Destination buffer Certificates_In has length sizeof(Dcm_Data3006ByteType) */
      /* DataLength is the size of passed data in buffer Certificates_In. */
      /*@ assert DataLength <= sizeof(Dcm_Data3006ByteType); */  /* VCA_SSA_PROCCTRL_DATALENGTH_AND_SIZEOF_DATABUFFER_PASSED_BY_DCM */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Certificates_In) >= sizeof(Dcm_Data3006ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Certificates_In, Certificates_In, DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */

      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.DataLength = DataLength;
      /* Preset NRC buffer with value passed from DCM */
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.ErrorCode = *ErrorCode;
      /* Call service dispatcher. */
      Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_SECOC_ECU_SHARED_SECRET_DISTRIBUTION;
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_OUTPUT:
      /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
      *routineInfo_Out = Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.routineInfo_Out;
      *Verification_Result_Out = Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Verification_Result_Out;
      *ErrorCode = Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.ErrorCode;
      /* Set buffer state to free. */
      Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
      break;
    default: /* COV_SSA_MISRA */
      /* Not reachable, QAC only. */
      break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

#else

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Encryption
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Encryption(const uint8 *Nonce_In, const uint8 *Ephemeral_ECU_Public_Key_In, const uint8 *In_Data_Signature_In, const uint8 *In_Certificates_In, Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Verification_Result_Out, uint8 *Date_and_Time_Out, uint8 *Tick_Count_Out, uint8 *Tick_Count_Offset_Out, uint8 *Encrypted_Nonce_and_Shared_Secret_Out, uint8 *Ephemeral_VSM_Public_Key_Out, uint8 *Out_Data_Signature_Out, uint8 *Out_Certificates_Out, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Nonce_In: uint8* is of type Dcm_Data32ByteType
 *     Argument Ephemeral_ECU_Public_Key_In: uint8* is of type Dcm_Data32ByteType
 *     Argument In_Data_Signature_In: uint8* is of type Dcm_Data64ByteType
 *     Argument In_Certificates_In: uint8* is of type Dcm_Data3006ByteType
 *     Argument Date_and_Time_Out: uint8* is of type Dcm_Data7ByteType
 *     Argument Tick_Count_Out: uint8* is of type Dcm_Data5ByteType
 *     Argument Tick_Count_Offset_Out: uint8* is of type Dcm_Data5ByteType
 *     Argument Encrypted_Nonce_and_Shared_Secret_Out: uint8* is of type Dcm_Data80ByteType
 *     Argument Ephemeral_VSM_Public_Key_Out: uint8* is of type Dcm_Data32ByteType
 *     Argument Out_Data_Signature_Out: uint8* is of type Dcm_Data64ByteType
 *     Argument Out_Certificates_Out: uint8* is of type Dcm_Data3006ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_DCM_E_PENDING
 *   RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_doc
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
/*!
 * \spec
 *    requires $lengthOf(Nonce_In) >= sizeof(Dcm_Data32ByteType);
 *    requires $lengthOf(Ephemeral_ECU_Public_Key_In) >= sizeof(Dcm_Data32ByteType);
 *    requires $lengthOf(In_Data_Signature_In) >= sizeof(Dcm_Data64ByteType);
 *    requires $lengthOf(In_Certificates_In) >= sizeof(Dcm_Data3006ByteType);
 *    requires $lengthOf(Date_and_Time_Out) >= sizeof(Dcm_Data7ByteType);
 *    requires $lengthOf(Tick_Count_Out) >= sizeof(Dcm_Data5ByteType);
 *    requires $lengthOf(Tick_Count_Offset_Out) >= sizeof(Dcm_Data5ByteType);
 *    requires $lengthOf(Encrypted_Nonce_and_Shared_Secret_Out) >= sizeof(Dcm_Data80ByteType);
 *    requires $lengthOf(Ephemeral_VSM_Public_Key_Out) >= sizeof(Dcm_Data32ByteType);
 *    requires $lengthOf(Out_Data_Signature_Out) >= sizeof(Dcm_Data64ByteType);
 *    requires $lengthOf(Out_Certificates_Out) >= sizeof(Dcm_Data3006ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Encryption(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Nonce_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_ECU_Public_Key_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) In_Data_Signature_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) In_Certificates_In,
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Date_and_Time_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Tick_Count_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Tick_Count_Offset_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Encrypted_Nonce_and_Shared_Secret_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Ephemeral_VSM_Public_Key_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Out_Data_Signature_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Out_Certificates_Out,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_Shared_Secret_Encryption (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((Nonce_In == NULL_PTR)
    || (Ephemeral_ECU_Public_Key_In == NULL_PTR)
    || (In_Data_Signature_In == NULL_PTR)
    || (In_Certificates_In == NULL_PTR)
    || (routineInfo_Out == NULL_PTR)
    || (Verification_Result_Out == NULL_PTR)
    || (Date_and_Time_Out == NULL_PTR)
    || (Tick_Count_Out == NULL_PTR)
    || (Tick_Count_Offset_Out == NULL_PTR)
    || (Encrypted_Nonce_and_Shared_Secret_Out == NULL_PTR)
    || (Ephemeral_VSM_Public_Key_Out == NULL_PTR)
    || (Out_Data_Signature_Out == NULL_PTR)
    || (Out_Certificates_Out == NULL_PTR)
    || (DataLength == NULL_PTR)
    || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
    case SSA_PROCCTRL_OPERATION_IDLE:
      /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
      break;
    case SSA_PROCCTRL_OPERATION_PENDING:
      /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_INPUT:
      /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Nonce_In) >= sizeof(Dcm_Data32ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Nonce_In, Nonce_In, sizeof(Dcm_Data32ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Ephemeral_ECU_Public_Key_In) >= sizeof(Dcm_Data32ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Ephemeral_ECU_Public_Key_In, Ephemeral_ECU_Public_Key_In, sizeof(Dcm_Data32ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.In_Data_Signature_In) >= sizeof(Dcm_Data64ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.In_Data_Signature_In, In_Data_Signature_In, sizeof(Dcm_Data64ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /* DataLength is the size of passed data in buffer In_Certificates_In. */
      /*@ assert *DataLength <= sizeof(Dcm_Data3006ByteType); */  /* VCA_SSA_PROCCTRL_DATALENGTH_AND_SIZEOF_DATABUFFER_PASSED_BY_DCM */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.In_Certificates_In) >= sizeof(Dcm_Data3006ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.In_Certificates_In, In_Certificates_In, *DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */

      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.DataLength = *DataLength;
      /* Conditionally assign output buffer. */
      ProcCtrl_AssignBufferCond(Date_and_Time_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Date_and_Time_Out, sizeof(Dcm_Data7ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Tick_Count_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Tick_Count_Out, sizeof(Dcm_Data5ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Tick_Count_Offset_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Tick_Count_Offset_Out, sizeof(Dcm_Data5ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Encrypted_Nonce_and_Shared_Secret_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Encrypted_Nonce_and_Shared_Secret_Out, sizeof(Dcm_Data80ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Ephemeral_VSM_Public_Key_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Ephemeral_VSM_Public_Key_Out, sizeof(Dcm_Data32ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Out_Data_Signature_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Out_Data_Signature_Out, sizeof(Dcm_Data64ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Out_Certificates_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Out_Certificates_Out, *DataLength); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      /* Preset NRC buffer with value passed from DCM */
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.ErrorCode = *ErrorCode;
      /* Call service dispatcher. */
      Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_SECOC_ECU_SHARED_SECRET_ENCRYPTION;
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_OUTPUT:
      /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
      *routineInfo_Out = Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.routineInfo_Out;
      *Verification_Result_Out = Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Verification_Result_Out;

      ProcCtrl_CopyBufferCond(Date_and_Time_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Date_and_Time_Out, sizeof(Dcm_Data7ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Tick_Count_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Tick_Count_Out, sizeof(Dcm_Data5ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Tick_Count_Offset_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Tick_Count_Offset_Out, sizeof(Dcm_Data5ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Encrypted_Nonce_and_Shared_Secret_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Encrypted_Nonce_and_Shared_Secret_Out, sizeof(Dcm_Data80ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Ephemeral_VSM_Public_Key_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Ephemeral_VSM_Public_Key_Out, sizeof(Dcm_Data32ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Out_Data_Signature_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Out_Data_Signature_Out, sizeof(Dcm_Data64ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /* Destination buffer Out_Certificates_Out has length sizeof(Dcm_Data3006ByteType) */
      /* DataLength is the size of passed data in buffer Out_Certificates_Out. */
      *DataLength = (Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.DataLength < (uint16)sizeof(Dcm_Data3006ByteType)) ? Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.DataLength : (uint16)sizeof(Dcm_Data3006ByteType);
      ProcCtrl_CopyBufferCond(Out_Certificates_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Out_Certificates_Out, *DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      *ErrorCode = Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.ErrorCode;
      /* Set buffer state to free. */
      Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
      break;
    default: /* COV_SSA_MISRA */
      /* Not reachable, QAC only. */
      break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_TickCount_Synchronization
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_TickCount_Synchronization(const uint8 *Nonce_In, const uint8 *Ephemeral_ECU_Public_Key_In, const uint8 *In_Data_Signature_In, const uint8 *In_Certificates_In, Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Verification_Result_Out, uint8 *Date_and_Time_Out, uint8 *Tick_Count_Out, uint8 *Tick_Count_Offset_Out, uint8 *Encrypted_Nonce_and_Shared_Secret_Out, uint8 *Ephemeral_VSM_Public_Key_Out, uint8 *Out_Data_Signature_Out, uint8 *Out_Certificates_Out, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Nonce_In: uint8* is of type Dcm_Data32ByteType
 *     Argument Ephemeral_ECU_Public_Key_In: uint8* is of type Dcm_Data32ByteType
 *     Argument In_Data_Signature_In: uint8* is of type Dcm_Data64ByteType
 *     Argument In_Certificates_In: uint8* is of type Dcm_Data3006ByteType
 *     Argument Date_and_Time_Out: uint8* is of type Dcm_Data7ByteType
 *     Argument Tick_Count_Out: uint8* is of type Dcm_Data5ByteType
 *     Argument Tick_Count_Offset_Out: uint8* is of type Dcm_Data5ByteType
 *     Argument Encrypted_Nonce_and_Shared_Secret_Out: uint8* is of type Dcm_Data80ByteType
 *     Argument Ephemeral_VSM_Public_Key_Out: uint8* is of type Dcm_Data32ByteType
 *     Argument Out_Data_Signature_Out: uint8* is of type Dcm_Data64ByteType
 *     Argument Out_Certificates_Out: uint8* is of type Dcm_Data3006ByteType
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization_DCM_E_FORCE_RCRRP
 *   RTE_E_RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization_DCM_E_PENDING
 *   RTE_E_RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_TickCount_Synchronization_doc
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
/*!
 * \spec
 *    requires $lengthOf(Nonce_In) >= sizeof(Dcm_Data32ByteType);
 *    requires $lengthOf(Ephemeral_ECU_Public_Key_In) >= sizeof(Dcm_Data32ByteType);
 *    requires $lengthOf(In_Data_Signature_In) >= sizeof(Dcm_Data64ByteType);
 *    requires $lengthOf(In_Certificates_In) >= sizeof(Dcm_Data3006ByteType);
 *    requires $lengthOf(Date_and_Time_Out) >= sizeof(Dcm_Data7ByteType);
 *    requires $lengthOf(Tick_Count_Out) >= sizeof(Dcm_Data5ByteType);
 *    requires $lengthOf(Tick_Count_Offset_Out) >= sizeof(Dcm_Data5ByteType);
 *    requires $lengthOf(Encrypted_Nonce_and_Shared_Secret_Out) >= sizeof(Dcm_Data80ByteType);
 *    requires $lengthOf(Ephemeral_VSM_Public_Key_Out) >= sizeof(Dcm_Data32ByteType);
 *    requires $lengthOf(Out_Data_Signature_Out) >= sizeof(Dcm_Data64ByteType);
 *    requires $lengthOf(Out_Certificates_Out) >= sizeof(Dcm_Data3006ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_TickCount_Synchronization(
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Nonce_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Ephemeral_ECU_Public_Key_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) In_Data_Signature_In,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) In_Certificates_In,
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Date_and_Time_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Tick_Count_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Tick_Count_Offset_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Encrypted_Nonce_and_Shared_Secret_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Ephemeral_VSM_Public_Key_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Out_Data_Signature_Out,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Out_Certificates_Out,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Trust_Model_SecOC_ECU_TickCount_Synchronization (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
# if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((Nonce_In == NULL_PTR)
    || (Ephemeral_ECU_Public_Key_In == NULL_PTR)
    || (In_Data_Signature_In == NULL_PTR)
    || (In_Certificates_In == NULL_PTR)
    || (routineInfo_Out == NULL_PTR)
    || (Verification_Result_Out == NULL_PTR)
    || (Date_and_Time_Out == NULL_PTR)
    || (Tick_Count_Out == NULL_PTR)
    || (Tick_Count_Offset_Out == NULL_PTR)
    || (Encrypted_Nonce_and_Shared_Secret_Out == NULL_PTR)
    || (Ephemeral_VSM_Public_Key_Out == NULL_PTR)
    || (Out_Data_Signature_Out == NULL_PTR)
    || (Out_Certificates_Out == NULL_PTR)
    || (DataLength == NULL_PTR)
    || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
# endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
    case SSA_PROCCTRL_OPERATION_IDLE:
      /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
      break;
    case SSA_PROCCTRL_OPERATION_PENDING:
      /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_INPUT:
      /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Nonce_In) >= sizeof(Dcm_Data32ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Nonce_In, Nonce_In, sizeof(Dcm_Data32ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Ephemeral_ECU_Public_Key_In) >= sizeof(Dcm_Data32ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Ephemeral_ECU_Public_Key_In, Ephemeral_ECU_Public_Key_In, sizeof(Dcm_Data32ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.In_Data_Signature_In) >= sizeof(Dcm_Data64ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.In_Data_Signature_In, In_Data_Signature_In, sizeof(Dcm_Data64ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /* DataLength is the size of passed data in buffer In_Certificates_In. */
      /*@ assert *DataLength <= sizeof(Dcm_Data3006ByteType); */  /* VCA_SSA_PROCCTRL_DATALENGTH_AND_SIZEOF_DATABUFFER_PASSED_BY_DCM */
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.In_Certificates_In) >= sizeof(Dcm_Data3006ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.In_Certificates_In, In_Certificates_In, *DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */

      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.DataLength = *DataLength;
      /* Conditionally assign output buffer. */
      ProcCtrl_AssignBufferCond(Date_and_Time_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Date_and_Time_Out, sizeof(Dcm_Data7ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Tick_Count_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Tick_Count_Out, sizeof(Dcm_Data5ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Tick_Count_Offset_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Tick_Count_Offset_Out, sizeof(Dcm_Data5ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Encrypted_Nonce_and_Shared_Secret_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Encrypted_Nonce_and_Shared_Secret_Out, sizeof(Dcm_Data80ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Ephemeral_VSM_Public_Key_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Ephemeral_VSM_Public_Key_Out, sizeof(Dcm_Data32ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Out_Data_Signature_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Out_Data_Signature_Out, sizeof(Dcm_Data64ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      ProcCtrl_AssignBufferCond(Out_Certificates_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Out_Certificates_Out, *DataLength); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      /* Preset NRC buffer with value passed from DCM */
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.ErrorCode = *ErrorCode;
      /* Call service dispatcher. */
      Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_SECOC_ECU_TICKCOUNT_SYNC;
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_OUTPUT:

      /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
      *routineInfo_Out = Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.routineInfo_Out;
      *Verification_Result_Out = Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Verification_Result_Out;
      ProcCtrl_CopyBufferCond(Date_and_Time_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Date_and_Time_Out, sizeof(Dcm_Data7ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Tick_Count_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Tick_Count_Out, sizeof(Dcm_Data5ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Tick_Count_Offset_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Tick_Count_Offset_Out, sizeof(Dcm_Data5ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Encrypted_Nonce_and_Shared_Secret_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Encrypted_Nonce_and_Shared_Secret_Out, sizeof(Dcm_Data80ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Ephemeral_VSM_Public_Key_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Ephemeral_VSM_Public_Key_Out, sizeof(Dcm_Data32ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      ProcCtrl_CopyBufferCond(Out_Data_Signature_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Out_Data_Signature_Out, sizeof(Dcm_Data64ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /* Destination buffer Out_Certificates_Out has length sizeof(Dcm_Data3006ByteType) */
      /* DataLength is the size of passed data in buffer Out_Certificates_Out. */
      *DataLength = (Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.DataLength < (uint16)sizeof(Dcm_Data3006ByteType)) ? Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.DataLength : (uint16)sizeof(Dcm_Data3006ByteType);
      ProcCtrl_CopyBufferCond(Out_Certificates_Out, Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Out_Certificates_Out, *DataLength); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      *ErrorCode = Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.ErrorCode;
      /* Set buffer state to free. */
      Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
      break;
    default: /* COV_SSA_MISRA */
      /* Not reachable, QAC only. */
      break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
#endif

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_RoutineServices_Routine_Verify_Signature
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
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_RoutineServices_Routine_Verify_Signature(uint8 Data_to_be_checked, const uint8 *Signature_Value, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, Dcm_NegativeResponseCodeType *ErrorCode)
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
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Verify_Signature_doc
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
 /*!
 * \spec
 *    requires $lengthOf(Signature_Value) >= sizeof(Dcm_Data64ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_RoutineServices_Routine_Verify_Signature(
  uint8 Data_to_be_checked,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) Signature_Value,
  Dcm_OpStatusType OpStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Verification_Result,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_RoutineServices_Routine_Verify_Signature (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_RoutineServices_Routine_Verify_Signature_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((Signature_Value == NULL_PTR)
    || (routineInfo == NULL_PTR)
    || (Verification_Result == NULL_PTR)
    || (ErrorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(OpStatus, ErrorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
    case SSA_PROCCTRL_OPERATION_IDLE:
      /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
      break;
    case SSA_PROCCTRL_OPERATION_PENDING:
      /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_INPUT:
      /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
      Ssa_ProcCtrlBuffer.SharedData.VerifySignature.Data_to_be_checked = Data_to_be_checked;
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.VerifySignature.Signature_Value) >= sizeof(Dcm_Data64ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.VerifySignature.Signature_Value, Signature_Value, sizeof(Dcm_Data64ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /* Preset NRC buffer with value passed from DCM */
      Ssa_ProcCtrlBuffer.SharedData.VerifySignature.ErrorCode = *ErrorCode;
      /* Call service dispatcher. */
      Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_VERIFY_SIGNATURE;
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_OUTPUT:
      /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
      *routineInfo = Ssa_ProcCtrlBuffer.SharedData.VerifySignature.routineInfo;
      *Verification_Result = Ssa_ProcCtrlBuffer.SharedData.VerifySignature.Verification_Result;
      *ErrorCode = Ssa_ProcCtrlBuffer.SharedData.VerifySignature.ErrorCode;
      /* Set buffer state to free. */
      Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
      break;
    default: /* COV_SSA_MISRA */
      /* Not reachable, QAC only. */
      break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_SecurityAccess_CompareKey
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <CompareKey> of PortPrototype <SecurityAccess_Server>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_SecurityAccess_CompareKey(uint8 secLevel, const uint8 *key, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode)
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
 * Symbol: Ssa_ProcCtrl_SecurityAccess_CompareKey_doc
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
 /*!
 * \spec
 *    requires $lengthOf(key) >= sizeof(Dcm_Data64ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_SecurityAccess_CompareKey(
  uint8 secLevel,
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_DATA) key,
  Dcm_OpStatusType opStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_SecurityAccess_CompareKey (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((key == NULL_PTR) || (errorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(opStatus, errorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
    case SSA_PROCCTRL_OPERATION_IDLE:
      /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
      break;
    case SSA_PROCCTRL_OPERATION_PENDING:
      /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_INPUT:
      /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
      Ssa_ProcCtrlBuffer.SharedData.CompareKey.SecLevel = secLevel;
      /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.CompareKey.Key) >= sizeof(Dcm_Data64ByteType); */
      ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.CompareKey.Key, key, sizeof(Dcm_Data64ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      /* Preset NRC buffer with value passed from DCM */
      Ssa_ProcCtrlBuffer.SharedData.CompareKey.ErrorCode = *errorCode;
      /* Call service dispatcher. */
      Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_COMPARE_KEY;
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_OUTPUT:
      /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
      *errorCode = Ssa_ProcCtrlBuffer.SharedData.CompareKey.ErrorCode;
      /* Set buffer state to free. */
      Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
      break;
    default: /* COV_SSA_MISRA */
      /* Not reachable, QAC only. */
      break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_SecurityAccess_GetSeed
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetSeed> of PortPrototype <SecurityAccess_Server>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(uint8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType Ssa_ProcCtrl_SecurityAccess_GetSeed(uint8 secLevel, Dcm_OpStatusType opStatus, uint8 *seed, Dcm_NegativeResponseCodeType *errorCode)
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
 * Symbol: Ssa_ProcCtrl_SecurityAccess_GetSeed_doc
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
/*!
 * \spec
 *    requires $lengthOf(seed) >= sizeof(Dcm_Data32ByteType);
 * \endspec
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_SecurityAccess_GetSeed(
  uint8 secLevel,
  Dcm_OpStatusType opStatus,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) seed,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_SecurityAccess_GetSeed (returns application error)
 *********************************************************************************************************************/
  Std_ReturnType retVal = RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#if (SSA_DEV_ERROR_DETECT == STD_ON)
  if ((seed == NULL_PTR) || (errorCode == NULL_PTR))
  {
    /* retVal already set */
  }
  else
#endif /* SSA_DEV_ERROR_DETECT == STD_ON */
  {
    uint8 operation = SSA_PROCCTRL_OPERATION_IDLE;

    /* #10 Call ProcCtrl state machine with operation status as input. */
    retVal = ProcCtrl_Statemachine(opStatus, errorCode, &operation);

    /* #20 Apply operation returned by state machine. */
    switch (operation) {
    case SSA_PROCCTRL_OPERATION_IDLE:
      /* #22 If operation is IDLE wait for called service to finish, i.e. no action. */
      break;
    case SSA_PROCCTRL_OPERATION_PENDING:
      /* #24 If operation is PENDING call again the ProcCtrl service dispatcher. */
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_INPUT:
      /* #26 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
      Ssa_ProcCtrlBuffer.SharedData.GetSeed.SecLevel = secLevel;
      /* Conditionally assign output buffer. */
      ProcCtrl_AssignBufferCond(seed, Ssa_ProcCtrlBuffer.SharedData.GetSeed.Seed, sizeof(Dcm_Data32ByteType)); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
      /* Preset NRC buffer with value passed from DCM */
      Ssa_ProcCtrlBuffer.SharedData.GetSeed.ErrorCode = *errorCode;
      /* Call service dispatcher. */
      Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_GET_SEED;
      (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
      break;
    case SSA_PROCCTRL_OPERATION_OUTPUT:
      /* #28 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
      /* Conditionally copy output buffer data. */
      ProcCtrl_CopyBufferCond(seed, Ssa_ProcCtrlBuffer.SharedData.GetSeed.Seed, sizeof(Dcm_Data32ByteType)); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
      *errorCode = Ssa_ProcCtrlBuffer.SharedData.GetSeed.ErrorCode;
      /* Set buffer state to free. */
      Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
      break;
    default: /* COV_SSA_MISRA */
      /* Not reachable, QAC only. */
      break;
    }
  }

  return retVal;
  /* PRQA S 6060 4 */ /* MD_SSA_STPAR */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Ssa_ProcCtrl_ServiceDispatcher
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <ServiceId> of PortPrototype <ProcCtrl_DispatchServices_Receiver>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_ProcCtrl_DispatchServices_Receiver_ServiceId(uint8 *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_DS_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING, RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4092ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING, RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING, RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_0191_Generated_Random_Number_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_0191_Generated_Random_Number_DCM_E_PENDING, RTE_E_DataServices_DID_0191_Generated_Random_Number_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_0191_Generated_Random_Number_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data32ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_0191_Generated_Random_Number_DCM_E_PENDING, RTE_E_DataServices_DID_0191_Generated_Random_Number_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_0191_Generated_Random_Number_Result_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_DCM_E_PENDING, RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_0191_Generated_Random_Number_Result_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_DCM_E_PENDING, RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_0199_Certificates_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_0199_Certificates_DCM_E_PENDING, RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_0199_Certificates_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data3006ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_0199_Certificates_DCM_E_PENDING, RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_0199_Certificates_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_0199_Certificates_DCM_E_PENDING, RTE_E_DataServices_DID_0199_Certificates_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_0199_Data_Signature_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_0199_Data_Signature_DCM_E_PENDING, RTE_E_DataServices_DID_0199_Data_Signature_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_0199_Data_Signature_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data64ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_0199_Data_Signature_DCM_E_PENDING, RTE_E_DataServices_DID_0199_Data_Signature_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_DCM_E_PENDING, RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_0199_Ephemeral_ECU_Public_Key_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data32ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_DCM_E_PENDING, RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_0199_Nonce_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_0199_Nonce_DCM_E_PENDING, RTE_E_DataServices_DID_0199_Nonce_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_0199_Nonce_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data32ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_0199_Nonce_DCM_E_PENDING, RTE_E_DataServices_DID_0199_Nonce_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_DCM_E_PENDING, RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019A_Trust_model_ECU_CSR_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1002ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_DCM_E_PENDING, RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019A_Trust_model_ECU_CSR_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_DCM_E_PENDING, RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_DCM_E_PENDING, RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019B_Trust_model_ECU_Certificate_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1002ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_DCM_E_PENDING, RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019B_Trust_model_ECU_Certificate_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_DCM_E_PENDING, RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_DCM_E_PENDING, RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1002ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_DCM_E_PENDING, RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_DCM_E_PENDING, RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_DCM_E_PENDING, RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019D_Trust_model_Backend_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1002ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_DCM_E_PENDING, RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_DCM_E_PENDING, RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_DCM_E_PENDING, RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019E_Trust_model_Root_CA_certificate_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1002ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_DCM_E_PENDING, RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_DCM_E_PENDING, RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019F_Trust_model_certificates_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019F_Trust_model_certificates_DCM_E_PENDING, RTE_E_DataServices_DID_019F_Trust_model_certificates_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019F_Trust_model_certificates_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4008ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019F_Trust_model_certificates_DCM_E_PENDING, RTE_E_DataServices_DID_019F_Trust_model_certificates_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_DID_019F_Trust_model_certificates_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_DID_019F_Trust_model_certificates_DCM_E_PENDING, RTE_E_DataServices_DID_019F_Trust_model_certificates_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_ECU_Certificate_Read_Data_Signature_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_DCM_E_PENDING, RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_ECU_Certificate_Read_Data_Signature_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data64ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_DCM_E_PENDING, RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_ECU_Certificate_Read_ECU_Certificate_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_DCM_E_PENDING, RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_ECU_Certificate_Read_ECU_Certificate_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1002ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_DCM_E_PENDING, RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_ECU_Certificate_Read_ECU_Certificate_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_DCM_E_PENDING, RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_DCM_E_PENDING, RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data32ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_DCM_E_PENDING, RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_ECU_Certificate_Read_Nonce_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_ECU_Certificate_Read_Nonce_DCM_E_PENDING, RTE_E_DataServices_ECU_Certificate_Read_Nonce_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_ECU_Certificate_Read_Nonce_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data32ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_ECU_Certificate_Read_Nonce_DCM_E_PENDING, RTE_E_DataServices_ECU_Certificate_Read_Nonce_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING, RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data1024ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING, RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING, RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_Security_Event_Log_Read_Security_Event_Log_Entry_ConditionCheckRead(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING, RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData(Dcm_OpStatusType OpStatus, uint8 *Data)
 *     Argument Data: uint8* is of type Dcm_Data4092ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING, RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK
 *   Std_ReturnType Rte_Call_DS_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength(Dcm_OpStatusType OpStatus, uint16 *DataLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING, RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_Authenticate_Diagnostic_User_or_Tester_Start(uint8 Configuration, uint8 Task, const uint8 *Challenge_Certificate_Proof_of_Ownership, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint8 *Authentication_Result, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Challenge_Certificate_Proof_of_Ownership: uint8* is of type Dcm_Data4004ByteType
 *     Argument Authentication_Result: uint8* is of type Dcm_Data3006ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_PENDING, RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_Certificate_Self_Check_Start(Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Verification_Result: uint8* is of type Dcm_Data18ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Routine_Certificate_Self_Check_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Routine_Certificate_Self_Check_DCM_E_PENDING, RTE_E_RoutineServices_Routine_Certificate_Self_Check_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_Enhance_Access_Rights_Start(const uint8 *Enhanced_Rights_Certificate, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Enhanced_Rights_Certificate: uint8* is of type Dcm_Data2002ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Routine_Enhance_Access_Rights_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Routine_Enhance_Access_Rights_DCM_E_PENDING, RTE_E_RoutineServices_Routine_Enhance_Access_Rights_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_Evaluate_Data_Verification_Certificate_Start(const uint8 *Data_Verification_Certificate, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Data_Verification_Certificate: uint8* is of type Dcm_Data2002ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_PENDING, RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_Inject_Seed_Start(const uint8 *Ephemeral_Backend_Public_Key_In, const uint8 *Data_Signature_In, const uint8 *Encrypted_Seed_In, Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Verification_Result_Out, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Ephemeral_Backend_Public_Key_In: uint8* is of type Dcm_Data32ByteType
 *     Argument Data_Signature_In: uint8* is of type Dcm_Data64ByteType
 *     Argument Encrypted_Seed_In: uint8* is of type Dcm_Data1058ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Inject_Seed_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Inject_Seed_DCM_E_PENDING, RTE_E_RoutineServices_Inject_Seed_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_Replace_Certificates_Start(const uint8 *Certificates, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Certificates: uint8* is of type Dcm_Data4008ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Routine_Replace_Certificates_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Routine_Replace_Certificates_DCM_E_PENDING, RTE_E_RoutineServices_Routine_Replace_Certificates_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_Replace_Trust_model_Certificates_Start(const uint8 *Trust_Certificates_In, Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Verification_Result_Out, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Trust_Certificates_In: uint8* is of type Dcm_Data3006ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Replace_Trust_model_Certificates_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Replace_Trust_model_Certificates_DCM_E_PENDING, RTE_E_RoutineServices_Replace_Trust_model_Certificates_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_Replace_Trust_model_Root_Certificate_Start(const uint8 *signature_new_Root_In, const uint8 *signature_In, const uint8 *Certificates_In, Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Verification_Result_Out, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument signature_new_Root_In: uint8* is of type Dcm_Data64ByteType
 *     Argument signature_In: uint8* is of type Dcm_Data64ByteType
 *     Argument Certificates_In: uint8* is of type Dcm_Data2004ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_DCM_E_PENDING, RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_Reset_VIN_Values_Start(Dcm_OpStatusType OpStatus, uint8 *routineInfo, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Routine_Reset_VIN_Values_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Routine_Reset_VIN_Values_DCM_E_PENDING, RTE_E_RoutineServices_Routine_Reset_VIN_Values_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_SecOC_ECU_Shared_Secret_Encryption_Start(const uint8 *Nonce, const uint8 *Ephemeral_ECU_Public_Key, const uint8 *Data_Signature_In, const uint8 *Target_ECU_Certificate, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint8 *Date_and_Time, uint8 *Tick_Count, uint8 *Tick_Count_Offset, uint8 *Encrypted_Nonce_and_Shared_Secret, uint8 *Ephemeral_VSM_Public_Key, uint8 *Data_Signature_Out, uint8 *VSM_s_ECU_Certificate, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Nonce: uint8* is of type Dcm_Data32ByteType
 *     Argument Ephemeral_ECU_Public_Key: uint8* is of type Dcm_Data32ByteType
 *     Argument Data_Signature_In: uint8* is of type Dcm_Data64ByteType
 *     Argument Target_ECU_Certificate: uint8* is of type Dcm_Data1002ByteType
 *     Argument Date_and_Time: uint8* is of type Dcm_Data7ByteType
 *     Argument Tick_Count: uint8* is of type Dcm_Data5ByteType
 *     Argument Tick_Count_Offset: uint8* is of type Dcm_Data5ByteType
 *     Argument Encrypted_Nonce_and_Shared_Secret: uint8* is of type Dcm_Data80ByteType
 *     Argument Ephemeral_VSM_Public_Key: uint8* is of type Dcm_Data32ByteType
 *     Argument Data_Signature_Out: uint8* is of type Dcm_Data64ByteType
 *     Argument VSM_s_ECU_Certificate: uint8* is of type Dcm_Data1002ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption_DCM_E_PENDING, RTE_E_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_SecOC_ECU_TickCount_Synchronization_Start(const uint8 *Nonce, const uint8 *Ephemeral_ECU_Public_Key, const uint8 *Data_Signature_In, const uint8 *Target_ECU_Certificate, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, uint8 *Date_and_Time, uint8 *Tick_Count, uint8 *Tick_Count_Offset, uint8 *Encrypted_Nonce_and_Shared_Secret, uint8 *Ephemeral_VSM_Public_Key, uint8 *Data_Signature_Out, uint8 *VSM_s_ECU_Certificate, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Nonce: uint8* is of type Dcm_Data32ByteType
 *     Argument Ephemeral_ECU_Public_Key: uint8* is of type Dcm_Data32ByteType
 *     Argument Data_Signature_In: uint8* is of type Dcm_Data64ByteType
 *     Argument Target_ECU_Certificate: uint8* is of type Dcm_Data1002ByteType
 *     Argument Date_and_Time: uint8* is of type Dcm_Data7ByteType
 *     Argument Tick_Count: uint8* is of type Dcm_Data5ByteType
 *     Argument Tick_Count_Offset: uint8* is of type Dcm_Data5ByteType
 *     Argument Encrypted_Nonce_and_Shared_Secret: uint8* is of type Dcm_Data80ByteType
 *     Argument Ephemeral_VSM_Public_Key: uint8* is of type Dcm_Data32ByteType
 *     Argument Data_Signature_Out: uint8* is of type Dcm_Data64ByteType
 *     Argument VSM_s_ECU_Certificate: uint8* is of type Dcm_Data1002ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization_DCM_E_PENDING, RTE_E_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_SecOC_VSM_Derive_Symmetric_Keys_Start(Dcm_OpStatusType OpStatus, uint8 *routineInfo, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys_DCM_E_PENDING, RTE_E_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_SecOC_VSM_Renew_Shared_Secret_Start(Dcm_OpStatusType OpStatus, uint8 *routineInfo, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret_DCM_E_PENDING, RTE_E_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_SecOC_Vehicle_Shared_Secret_Distribution_Start(Dcm_OpStatusType OpStatus, uint8 *routineInfo, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution_DCM_E_PENDING, RTE_E_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_Synchronize_Secured_System_Date_and_Time_Start(Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Nonce, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Nonce: uint8* is of type Dcm_Data32ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_DCM_E_PENDING, RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_Trust_Model_Generate_Key_Pair_Start(Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Verification_Result_Out, uint8 *CSR_Signature_Out, uint8 *Trust_Model_ECU_CSR_Out, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument CSR_Signature_Out: uint8* is of type Dcm_Data64ByteType
 *     Argument Trust_Model_ECU_CSR_Out: uint8* is of type Dcm_Data1002ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_DCM_E_PENDING, RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start(const uint8 *Date_and_Time_In, const uint8 *Tick_Count_In, const uint8 *Tick_Count_Offset_In, const uint8 *Encrypted_Nonce_and_Shared_Secret_In, const uint8 *Ephemeral_VSM_Public_Key_In, const uint8 *Data_Signature_In, const uint8 *Certificates_In, Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Verification_Result_Out, uint16 DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Date_and_Time_In: uint8* is of type Dcm_Data7ByteType
 *     Argument Tick_Count_In: uint8* is of type Dcm_Data5ByteType
 *     Argument Tick_Count_Offset_In: uint8* is of type Dcm_Data5ByteType
 *     Argument Encrypted_Nonce_and_Shared_Secret_In: uint8* is of type Dcm_Data80ByteType
 *     Argument Ephemeral_VSM_Public_Key_In: uint8* is of type Dcm_Data32ByteType
 *     Argument Data_Signature_In: uint8* is of type Dcm_Data64ByteType
 *     Argument Certificates_In: uint8* is of type Dcm_Data3006ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_DCM_E_PENDING, RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_Start(const uint8 *Nonce_In, const uint8 *Ephemeral_ECU_Public_Key_In, const uint8 *In_Data_Signature_In, const uint8 *In_Certificates_In, Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Verification_Result_Out, uint8 *Date_and_Time_Out, uint8 *Tick_Count_Out, uint8 *Tick_Count_Offset_Out, uint8 *Encrypted_Nonce_and_Shared_Secret_Out, uint8 *Ephemeral_VSM_Public_Key_Out, uint8 *Out_Data_Signature_Out, uint8 *Out_Certificates_Out, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Nonce_In: uint8* is of type Dcm_Data32ByteType
 *     Argument Ephemeral_ECU_Public_Key_In: uint8* is of type Dcm_Data32ByteType
 *     Argument In_Data_Signature_In: uint8* is of type Dcm_Data64ByteType
 *     Argument In_Certificates_In: uint8* is of type Dcm_Data3006ByteType
 *     Argument Date_and_Time_Out: uint8* is of type Dcm_Data7ByteType
 *     Argument Tick_Count_Out: uint8* is of type Dcm_Data5ByteType
 *     Argument Tick_Count_Offset_Out: uint8* is of type Dcm_Data5ByteType
 *     Argument Encrypted_Nonce_and_Shared_Secret_Out: uint8* is of type Dcm_Data80ByteType
 *     Argument Ephemeral_VSM_Public_Key_Out: uint8* is of type Dcm_Data32ByteType
 *     Argument Out_Data_Signature_Out: uint8* is of type Dcm_Data64ByteType
 *     Argument Out_Certificates_Out: uint8* is of type Dcm_Data3006ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_DCM_E_PENDING, RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_Trust_Model_SecOC_ECU_TickCount_Synchronization_Start(const uint8 *Nonce_In, const uint8 *Ephemeral_ECU_Public_Key_In, const uint8 *In_Data_Signature_In, const uint8 *In_Certificates_In, Dcm_OpStatusType OpStatus, uint8 *routineInfo_Out, uint8 *Verification_Result_Out, uint8 *Date_and_Time_Out, uint8 *Tick_Count_Out, uint8 *Tick_Count_Offset_Out, uint8 *Encrypted_Nonce_and_Shared_Secret_Out, uint8 *Ephemeral_VSM_Public_Key_Out, uint8 *Out_Data_Signature_Out, uint8 *Out_Certificates_Out, uint16 *DataLength, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Nonce_In: uint8* is of type Dcm_Data32ByteType
 *     Argument Ephemeral_ECU_Public_Key_In: uint8* is of type Dcm_Data32ByteType
 *     Argument In_Data_Signature_In: uint8* is of type Dcm_Data64ByteType
 *     Argument In_Certificates_In: uint8* is of type Dcm_Data3006ByteType
 *     Argument Date_and_Time_Out: uint8* is of type Dcm_Data7ByteType
 *     Argument Tick_Count_Out: uint8* is of type Dcm_Data5ByteType
 *     Argument Tick_Count_Offset_Out: uint8* is of type Dcm_Data5ByteType
 *     Argument Encrypted_Nonce_and_Shared_Secret_Out: uint8* is of type Dcm_Data80ByteType
 *     Argument Ephemeral_VSM_Public_Key_Out: uint8* is of type Dcm_Data32ByteType
 *     Argument Out_Data_Signature_Out: uint8* is of type Dcm_Data64ByteType
 *     Argument Out_Certificates_Out: uint8* is of type Dcm_Data3006ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization_DCM_E_PENDING, RTE_E_RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization_E_NOT_OK
 *   Std_ReturnType Rte_Call_RC_Verify_Signature_Start(uint8 Data_to_be_checked, const uint8 *Signature_Value, Dcm_OpStatusType OpStatus, uint8 *routineInfo, uint8 *Verification_Result, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument Signature_Value: uint8* is of type Dcm_Data64ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_FORCE_RCRRP, RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING, RTE_E_RoutineServices_Routine_Verify_Signature_E_NOT_OK
 *   Std_ReturnType Rte_Call_SecurityAccess_Client_CompareKey(uint8 secLevel, const uint8 *key, Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode)
 *     Argument key: uint8* is of type Dcm_Data64ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK, RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING
 *   Std_ReturnType Rte_Call_SecurityAccess_Client_GetSeed(uint8 secLevel, Dcm_OpStatusType opStatus, uint8 *seed, Dcm_NegativeResponseCodeType *errorCode)
 *     Argument seed: uint8* is of type Dcm_Data32ByteType
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_SecurityAccessServices_GenericSecurityAccess_E_NOT_OK, RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_Ssa_ProcCtrl_ExclusiveArea(void)
 *   void Rte_Exit_Ssa_ProcCtrl_ExclusiveArea(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_ServiceDispatcher_doc
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

FUNC(void, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_ServiceDispatcher(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Ssa_ProcCtrl_ServiceDispatcher
 *********************************************************************************************************************/
  uint8 serviceId = SSA_PROCCTRL_SERVICE_ID_NUMBER; /* PRQA S 2981 */ /* MD_SSA_REDUNDANT_INITIALIZATION */
  Std_ReturnType retValPending;

  /* #10 Read the service id. */
  (void)Rte_Read_ProcCtrl_DispatchServices_Receiver_ServiceId(&serviceId); /* PRQA S 3417, 3426 */ /* MD_SSA_MICROSAR_OS */

    /* #20 Dispatch services, i.e. synchronously call the requested service. */
  switch (serviceId) {
  case SSA_PROCCTRL_SERVICE_ID_AUTHENTICATE_DIAGNOSTIC_USER_OR_TESTER:
    retValPending = RTE_E_RoutineServices_Routine_Authenticate_Diagnostic_User_or_Tester_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Authenticate_Diagnostic_User_or_Tester_Start(
      Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.Configuration,
      Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.Task,
      Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.Challenge_Certificate_Proof_of_Ownership,
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.routineInfo,
      &Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.Verification_Result,
      Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.Authentication_Result,
      &Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.DataLength,
      &Ssa_ProcCtrlBuffer.SharedData.AuthenticateDiagnosticUserOrTester.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_ENHANCE_ACCESS_RIGHTS:
    retValPending = RTE_E_RoutineServices_Routine_Enhance_Access_Rights_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Enhance_Access_Rights_Start(
      Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRights.Enhanced_Rights_Certificate,
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRights.routineInfo,
      &Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRights.Verification_Result,
      Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRights.DataLength,
      &Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRights.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_EVALUATE_DATA_VERIF_CERT:
    retValPending = RTE_E_RoutineServices_Routine_Evaluate_Data_Verification_Certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Evaluate_Data_Verification_Certificate_Start(
      Ssa_ProcCtrlBuffer.SharedData.EvaluateDataVerificationCertificate.Data_Verification_Certificate,
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.EvaluateDataVerificationCertificate.routineInfo,
      &Ssa_ProcCtrlBuffer.SharedData.EvaluateDataVerificationCertificate.Verification_Result,
      Ssa_ProcCtrlBuffer.SharedData.EvaluateDataVerificationCertificate.DataLength,
      &Ssa_ProcCtrlBuffer.SharedData.EvaluateDataVerificationCertificate.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_REPLACE_CERTIFICATE:
    retValPending = RTE_E_RoutineServices_Routine_Replace_Certificates_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Replace_Certificates_Start(
      Ssa_ProcCtrlBuffer.SharedData.ReplaceCertificates.Certificates,
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.ReplaceCertificates.routineInfo,
      &Ssa_ProcCtrlBuffer.SharedData.ReplaceCertificates.Verification_Result,
      Ssa_ProcCtrlBuffer.SharedData.ReplaceCertificates.DataLength,
      &Ssa_ProcCtrlBuffer.SharedData.ReplaceCertificates.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_RESET_VIN_VALUES:
    retValPending = RTE_E_RoutineServices_Routine_Reset_VIN_Values_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Reset_VIN_Values_Start(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.ResetVinValues.routineInfo,
      &Ssa_ProcCtrlBuffer.SharedData.ResetVinValues.ErrorCode);
    break;

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)

  case SSA_PROCCTRL_SERVICE_ID_SECOC_ECU_SHARED_SECRET_ENCRYPTION:
    retValPending = RTE_E_RoutineServices_Routine_SecOC_ECU_Shared_Secret_Encryption_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_SecOC_ECU_Shared_Secret_Encryption_Start(
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Nonce,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Ephemeral_ECU_Public_Key,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Data_Signature_In,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Target_ECU_Certificate,
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.routineInfo,
      &Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Verification_Result,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Date_and_Time,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Tick_Count,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Tick_Count_Offset,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Encrypted_Nonce_and_Shared_Secret,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Ephemeral_VSM_Public_Key,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.Data_Signature_Out,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.VSM_s_ECU_Certificate,
      &Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.DataLength,
      &Ssa_ProcCtrlBuffer.SharedData.SecOcEcuSharedSecretEncryption.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_SECOC_ECU_TICKCOUNT_SYNC:
    retValPending = RTE_E_RoutineServices_Routine_SecOC_ECU_TickCount_Synchronization_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_SecOC_ECU_TickCount_Synchronization_Start(
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Nonce,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Ephemeral_ECU_Public_Key,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Data_Signature_In,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Target_ECU_Certificate,
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.routineInfo,
      &Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Verification_Result,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Date_and_Time,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Tick_Count,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Tick_Count_Offset,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Encrypted_Nonce_and_Shared_Secret,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Ephemeral_VSM_Public_Key,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.Data_Signature_Out,
      Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.VSM_s_ECU_Certificate,
      &Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.DataLength,
      &Ssa_ProcCtrlBuffer.SharedData.SecOcEcuTickCountSynchronization.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_SECOC_VEHICLE_SHARED_SECRET_DISTRIBUTION:
    retValPending = RTE_E_RoutineServices_Routine_SecOC_Vehicle_Shared_Secret_Distribution_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_SecOC_Vehicle_Shared_Secret_Distribution_Start(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.SecOcVehicleSharedSecretDistribution.routineInfo,
      &Ssa_ProcCtrlBuffer.SharedData.SecOcVehicleSharedSecretDistribution.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_SECOC_VSM_DERIVE_SYMMETRIC_KEYS:
    retValPending = RTE_E_RoutineServices_Routine_SecOC_VSM_Derive_Symmetric_Keys_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_SecOC_VSM_Derive_Symmetric_Keys_Start(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.SecOcVehicleSharedSecretDistribution.routineInfo,
      &Ssa_ProcCtrlBuffer.SharedData.SecOcVehicleSharedSecretDistribution.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_SECOC_VSM_RENEW_SHARED_SECRET:
    retValPending = RTE_E_RoutineServices_Routine_SecOC_VSM_Renew_Shared_Secret_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_SecOC_VSM_Renew_Shared_Secret_Start(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.SecOcVehicleSharedSecretDistribution.routineInfo,
      &Ssa_ProcCtrlBuffer.SharedData.SecOcVehicleSharedSecretDistribution.ErrorCode);
    break;

#endif /* (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM) */

  case SSA_PROCCTRL_SERVICE_ID_SYNCHRONIZE_SECURED_SYSTEM_DATE_AND_TIME:
    retValPending = RTE_E_RoutineServices_Routine_Synchronize_Secured_System_Date_and_Time_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Synchronize_Secured_System_Date_and_Time_Start(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.SynchronizeSecuredSystemDataAndTime.routineInfo,
      Ssa_ProcCtrlBuffer.SharedData.SynchronizeSecuredSystemDataAndTime.Nonce,
      &Ssa_ProcCtrlBuffer.SharedData.SynchronizeSecuredSystemDataAndTime.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_VERIFY_SIGNATURE:
    retValPending = RTE_E_RoutineServices_Routine_Verify_Signature_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Verify_Signature_Start(
      Ssa_ProcCtrlBuffer.SharedData.VerifySignature.Data_to_be_checked,
      Ssa_ProcCtrlBuffer.SharedData.VerifySignature.Signature_Value,
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.VerifySignature.routineInfo,
      &Ssa_ProcCtrlBuffer.SharedData.VerifySignature.Verification_Result,
      &Ssa_ProcCtrlBuffer.SharedData.VerifySignature.ErrorCode);
    break;

#if (SSA_ECU_TYPE == SSA_ECU_TYPE_VSM)

  case SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_DATA_SIGNATURE_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_ECU_Certificate_Read_Data_Signature_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.EcuCertReadDataSignatureCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_DATA_SIGNATURE_READ_DATA:
    retValPending = RTE_E_DataServices_ECU_Certificate_Read_Data_Signature_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_ECU_Certificate_Read_Data_Signature_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.EcuCertReadDataSignatureReadData.Data);
    break;

  case SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_ECU_CERT_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_ECU_Certificate_Read_ECU_Certificate_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.EcuCertReadEcuCertCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_ECU_CERT_READ_DATA:
    retValPending = RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_ECU_Certificate_Read_ECU_Certificate_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.EcuCertReadEcuCertReadData.Data);
    break;

  case SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_ECU_CERT_READ_DATA_LENGTH:
    retValPending = RTE_E_DataServices_ECU_Certificate_Read_ECU_Certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_ECU_Certificate_Read_ECU_Certificate_ReadDataLength(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.EcuCertReadEcuCertReadDataLength.DataLength);
    break;

  case SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_EPHEMERAL_ECU_PUBLIC_KEY_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.EcuCertReadEphEcuPubKeyCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_EPHEMERAL_ECU_PUBLIC_KEY_READ_DATA:
    retValPending = RTE_E_DataServices_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_ECU_Certificate_Read_Ephemeral_ECU_Public_Key_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.EcuCertReadEphEcuPubKeyReadData.Data);
    break;

  case SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_NONCE_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_ECU_Certificate_Read_Nonce_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_ECU_Certificate_Read_Nonce_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.EcuCertReadNonceCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_ECU_CERT_READ_NONCE_READ_DATA:
    retValPending = RTE_E_DataServices_ECU_Certificate_Read_Nonce_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_ECU_Certificate_Read_Nonce_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.EcuCertReadNonceReadData.Data);
    break;

#endif

  case SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_ENTRY_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_Security_Event_Log_Read_Security_Event_Log_Entry_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.SecEventLogEntryCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_ENTRY_READ_DATA_LENGTH:
    retValPending = RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_Security_Event_Log_Read_Security_Event_Log_Entry_ReadDataLength(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.SecEventLogEntryReadDataLength.DataLength);
    break;

  case SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_ENTRY_READ_DATA:
    retValPending = RTE_E_DataServices_Security_Event_Log_Read_Security_Event_Log_Entry_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_Security_Event_Log_Read_Security_Event_Log_Entry_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.SecEventLogEntryReadData.Data);
    break;

  case SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_CURRENT_COUNTER_VALUES_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.SecEventLogCurrentCounterValuesCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_CURRENT_COUNTER_VALUES_READ_DATA_LENGTH:
    retValPending = RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_ReadDataLength(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.SecEventLogCurrentCounterValuesReadDataLength.DataLength);
    break;

  case SSA_PROCCTRL_SERVICE_ID_SECURITY_EVENT_LOG_CURRENT_COUNTER_VALUES_READ_DATA:
    retValPending = RTE_E_DataServices_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_Security_Event_Log_Current_Counter_Values_Read_Security_Event_Log_Current_Counter_Values_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.SecEventLogCurrentCounterValuesReadData.Data);
    break;

  case SSA_PROCCTRL_SERVICE_ID_COMPARE_KEY:
    retValPending = RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_SecurityAccess_Client_CompareKey(
      Ssa_ProcCtrlBuffer.SharedData.CompareKey.SecLevel,
      Ssa_ProcCtrlBuffer.SharedData.CompareKey.Key,
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.CompareKey.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_GET_SEED:
    retValPending = RTE_E_SecurityAccessServices_GenericSecurityAccess_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_SecurityAccess_Client_GetSeed(
      Ssa_ProcCtrlBuffer.SharedData.GetSeed.SecLevel,
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.GetSeed.Seed,
      &Ssa_ProcCtrlBuffer.SharedData.GetSeed.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_CERTIFICATE_SELF_CHECK:
    retValPending = RTE_E_RoutineServices_Routine_Certificate_Self_Check_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Certificate_Self_Check_Start(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.CertificateSelfCheck.routineInfo,
      Ssa_ProcCtrlBuffer.SharedData.CertificateSelfCheck.Verification_Result,
      &Ssa_ProcCtrlBuffer.SharedData.CertificateSelfCheck.DataLength,
      &Ssa_ProcCtrlBuffer.SharedData.CertificateSelfCheck.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_SECURED_PDU_DATA_IDS_AND_KEY_CMACS_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.SecuredPduDataIdsAndKeyCmacsCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_SECURED_PDU_DATA_IDS_AND_KEY_CMACS_READ_DATA_LENGTH:
    retValPending = RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadDataLength(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.SecuredPduDataIdsAndKeyCmacsReadDataLength.DataLength);
    break;

  case SSA_PROCCTRL_SERVICE_ID_SECURED_PDU_DATA_IDS_AND_KEY_CMACS_READ_DATA:
    retValPending = RTE_E_DataServices_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_018F_Secured_PDU_Data_IDs_and_Key_CMACs_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.SecuredPduDataIdsAndKeyCmacsReadData.Data);
    break;

  case SSA_PROCCTRL_SERVICE_ID_GENERATED_RANDOM_NUMBER_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_DID_0191_Generated_Random_Number_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_0191_Generated_Random_Number_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.GeneratedRandomNumberCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_GENERATED_RANDOM_NUMBER_READ_DATA:
    retValPending = RTE_E_DataServices_DID_0191_Generated_Random_Number_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_0191_Generated_Random_Number_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.GeneratedRandomNumberReadData.Data);
    break;

  case SSA_PROCCTRL_SERVICE_ID_GENERATED_RANDOM_NUMBER_RESULT_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_0191_Generated_Random_Number_Result_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.GeneratedRandomNumberResultCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_GENERATED_RANDOM_NUMBER_RESULT_READ_DATA:
    retValPending = RTE_E_DataServices_DID_0191_Generated_Random_Number_Result_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_0191_Generated_Random_Number_Result_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.GeneratedRandomNumberResultReadData.Data);
    break;

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_DATA_SIGNATURE_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_DID_0199_Data_Signature_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_0199_Data_Signature_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelReadDataSignatureCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_DATA_SIGNATURE_READ_DATA:
    retValPending = RTE_E_DataServices_DID_0199_Data_Signature_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_0199_Data_Signature_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelReadDataSignatureReadData.Data);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_CERTIFICATES_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_DID_0199_Certificates_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_0199_Certificates_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelReadCertificatesCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_CERTIFICATES_READ_DATA_LENGTH:
    retValPending = RTE_E_DataServices_DID_0199_Certificates_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_0199_Certificates_ReadDataLength(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelReadCertificatesReadDataLength.DataLength);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_CERTIFICATES_READ_DATA:
    retValPending = RTE_E_DataServices_DID_0199_Certificates_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_0199_Certificates_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelReadCertificatesReadData.Data);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_EPHEMERAL_ECU_PUBLIC_KEY_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_0199_Ephemeral_ECU_Public_Key_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelReadEphemeralEcuPublicKeyCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_EPHEMERAL_ECU_PUBLIC_KEY_READ_DATA:
    retValPending = RTE_E_DataServices_DID_0199_Ephemeral_ECU_Public_Key_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_0199_Ephemeral_ECU_Public_Key_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelReadEphemeralEcuPublicKeyReadData.Data);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_NONCE_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_DID_0199_Nonce_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_0199_Nonce_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelReadNonceCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_READ_NONCE_READ_DATA:
    retValPending = RTE_E_DataServices_DID_0199_Nonce_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_0199_Nonce_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelReadNonceReadData.Data);
    break;

#endif

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CSR_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019A_Trust_model_ECU_CSR_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelEcuCsrCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CSR_READ_DATA_LENGTH:
    retValPending = RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019A_Trust_model_ECU_CSR_ReadDataLength(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelEcuCsrReadDataLength.DataLength);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CSR_READ_DATA:
    retValPending = RTE_E_DataServices_DID_019A_Trust_model_ECU_CSR_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019A_Trust_model_ECU_CSR_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelEcuCsrReadData.Data);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CERTIFICATE_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019B_Trust_model_ECU_Certificate_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelEcuCertificateCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CERTIFICATE_READ_DATA_LENGTH:
    retValPending = RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019B_Trust_model_ECU_Certificate_ReadDataLength(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelEcuCertificateReadDataLength.DataLength);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ECU_CERTIFICATE_READ_DATA:
    retValPending = RTE_E_DataServices_DID_019B_Trust_model_ECU_Certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019B_Trust_model_ECU_Certificate_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelEcuCertificateReadData.Data);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_INTERMEDIATE_CA_CERTIFICATE_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019C_Trust_model_Intermediate_CA_Certificate_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelIntermediateCaCertificateCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_INTERMEDIATE_CA_CERTIFICATE_READ_DATA_LENGTH:
    retValPending = RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadDataLength(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelIntermediateCaCertificateReadDataLength.DataLength);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_INTERMEDIATE_CA_CERTIFICATE_READ_DATA:
    retValPending = RTE_E_DataServices_DID_019C_Trust_model_Intermediate_CA_Certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019C_Trust_model_Intermediate_CA_Certificate_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelIntermediateCaCertificateReadData.Data);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_BACKEND_CA_CERTIFICATE_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019D_Trust_model_Backend_CA_certificate_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelBackendCaCertificateCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_BACKEND_CA_CERTIFICATE_READ_DATA_LENGTH:
    retValPending = RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019D_Trust_model_Backend_CA_certificate_ReadDataLength(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelBackendCaCertificateReadDataLength.DataLength);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_BACKEND_CA_CERTIFICATE_READ_DATA:
    retValPending = RTE_E_DataServices_DID_019D_Trust_model_Backend_CA_certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019D_Trust_model_Backend_CA_certificate_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelBackendCaCertificateReadData.Data);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ROOT_CA_CERTIFICATE_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019E_Trust_model_Root_CA_certificate_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelRootCaCertificateCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ROOT_CA_CERTIFICATE_READ_DATA_LENGTH:
    retValPending = RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019E_Trust_model_Root_CA_certificate_ReadDataLength(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelRootCaCertificateReadDataLength.DataLength);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_ROOT_CA_CERTIFICATE_READ_DATA:
    retValPending = RTE_E_DataServices_DID_019E_Trust_model_Root_CA_certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019E_Trust_model_Root_CA_certificate_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelRootCaCertificateReadData.Data);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_CERTIFICATES_CONDITION_CHECK_READ:
    retValPending = RTE_E_DataServices_DID_019F_Trust_model_certificates_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019F_Trust_model_certificates_ConditionCheckRead(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelCertificatesCondCheckRead.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_CERTIFICATES_READ_DATA_LENGTH:
    retValPending = RTE_E_DataServices_DID_019F_Trust_model_certificates_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019F_Trust_model_certificates_ReadDataLength(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelCertificatesReadDataLength.DataLength);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_CERTIFICATES_READ_DATA:
    retValPending = RTE_E_DataServices_DID_019F_Trust_model_certificates_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_DS_DID_019F_Trust_model_certificates_ReadData(
      Ssa_ProcCtrlBuffer.OpStatus,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelCertificatesReadData.Data);
    break;

  case SSA_PROCCTRL_SERVICE_ID_REPLACE_TRUST_MODEL_CERTIFICATES:
    retValPending = RTE_E_RoutineServices_Replace_Trust_model_Certificates_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Replace_Trust_model_Certificates_Start(
      Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelCertificates.Trust_Certificates_In,
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelCertificates.routineInfo_Out,
      &Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelCertificates.Verification_Result_Out,
      Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelCertificates.DataLength,
      &Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelCertificates.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_REPLACE_TRUST_MODEL_ROOT_CERTIFICATE:
    retValPending = RTE_E_RoutineServices_Replace_Trust_model_Root_Certificate_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Replace_Trust_model_Root_Certificate_Start(
      Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.signature_new_Root_In,
      Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.signature_In,
      Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.Certificates_In,
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.routineInfo_Out,
      &Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.Verification_Result_Out,
      Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.DataLength,
      &Ssa_ProcCtrlBuffer.SharedData.ReplaceTrustModelRootCertificate.ErrorCode);
    break;

#if (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM)

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_SECOC_ECU_SHARED_SECRET_DISTRIBUTION:
    retValPending = RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Trust_Model_SecOC_ECU_Shared_Secret_Distribution_Start(
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Date_and_Time_In,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Tick_Count_In,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Tick_Count_Offset_In,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Encrypted_Nonce_and_Shared_Secret_In,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Ephemeral_VSM_Public_Key_In,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Data_Signature_In,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Certificates_In,
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.routineInfo_Out,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.Verification_Result_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.DataLength,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretDistribution.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_INJECT_SEED:
    retValPending = RTE_E_RoutineServices_Inject_Seed_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Inject_Seed_Start(
      Ssa_ProcCtrlBuffer.SharedData.InjectSeed.Ephemeral_Backend_Public_Key_In,
      Ssa_ProcCtrlBuffer.SharedData.InjectSeed.Data_Signature_In,
      Ssa_ProcCtrlBuffer.SharedData.InjectSeed.Encrypted_Seed_In,
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.InjectSeed.routineInfo_Out,
      &Ssa_ProcCtrlBuffer.SharedData.InjectSeed.Verification_Result_Out,
      Ssa_ProcCtrlBuffer.SharedData.InjectSeed.DataLength,
      &Ssa_ProcCtrlBuffer.SharedData.InjectSeed.ErrorCode);
    break;

#else /* (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM) */

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_SECOC_ECU_SHARED_SECRET_ENCRYPTION:
    retValPending = RTE_E_RoutineServices_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Trust_Model_SecOC_ECU_Shared_Secret_Encryption_Start(
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Nonce_In,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Ephemeral_ECU_Public_Key_In,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.In_Data_Signature_In,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.In_Certificates_In,
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.routineInfo_Out,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Verification_Result_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Date_and_Time_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Tick_Count_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Tick_Count_Offset_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Encrypted_Nonce_and_Shared_Secret_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Ephemeral_VSM_Public_Key_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Out_Data_Signature_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.Out_Certificates_Out,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.DataLength,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuSharedSecretEncryption.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_SECOC_ECU_TICKCOUNT_SYNC:
    retValPending = RTE_E_RoutineServices_Trust_Model_SecOC_ECU_TickCount_Synchronization_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Trust_Model_SecOC_ECU_TickCount_Synchronization_Start(
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Nonce_In,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Ephemeral_ECU_Public_Key_In,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.In_Data_Signature_In,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.In_Certificates_In,
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.routineInfo_Out,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Verification_Result_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Date_and_Time_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Tick_Count_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Tick_Count_Offset_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Encrypted_Nonce_and_Shared_Secret_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Ephemeral_VSM_Public_Key_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Out_Data_Signature_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.Out_Certificates_Out,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.DataLength,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelSecOcEcuTickCountSynchronization.ErrorCode);
    break;

#endif /* (SSA_ECU_TYPE != SSA_ECU_TYPE_VSM) */

  case SSA_PROCCTRL_SERVICE_ID_TRUST_MODEL_GENERATE_KEY_PAIR:
    retValPending = RTE_E_RoutineServices_Trust_Model_Generate_Key_Pair_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Trust_Model_Generate_Key_Pair_Start(
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelGenerateKeyPair.routineInfo_Out,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelGenerateKeyPair.Verification_Result_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelGenerateKeyPair.CSR_Signature_Out,
      Ssa_ProcCtrlBuffer.SharedData.TrustModelGenerateKeyPair.Trust_Model_ECU_CSR_Out,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelGenerateKeyPair.DataLength,
      &Ssa_ProcCtrlBuffer.SharedData.TrustModelGenerateKeyPair.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_AUTHENTICATE_BY_S29:
    retValPending = RTE_E_DiagnosticService_Authentication_0x29_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Authenticate_Diagnostic_User_or_Tester_Start(
      Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Configuration,
      Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Task,
      Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Challenge_Certificate_Proof_of_Ownership,
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.routineInfo,
      &Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Verification_Result,
      Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Authentication_Result,
      &Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.DataLength,
      &Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.ErrorCode);
    break;

  case SSA_PROCCTRL_SERVICE_ID_AUTHENTICATION_CONFIG_BY_S29:
    retValPending = RTE_E_DiagnosticService_Authentication_0x29_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = RTE_E_OK;
    Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Verification_Result = SSA_VER_RES_AUTH_S29_AUTHENTICATION_CONFIGURATION_APCE;
    break;

  case SSA_PROCCTRL_SERVICE_ID_ENHANCE_ACCESS_RIGHTS_BY_S29:
    retValPending = RTE_E_DiagnosticService_Authentication_0x29_DCM_E_PENDING;
    Ssa_ProcCtrlBuffer.Result = Rte_Call_RC_Enhance_Access_Rights_Start(
      Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRightsByS31.Enhanced_Rights_Certificate,
      Ssa_ProcCtrlBuffer.OpStatus,
      &Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRightsByS31.routineInfo,
      &Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRightsByS31.Verification_Result,
      Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRightsByS31.DataLength,
      &Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRightsByS31.ErrorCode);
    break;

  default:
    /* #30 Trigger no service if read service id is unknown. */
    Ssa_ProcCtrlBuffer.Result = E_NOT_OK;
    retValPending = E_NOT_OK;
    break;
  }

  /* #40 Handle state depending on the return value from the finished, synchronous function call. */
  Ssa_ProcCtrl_ServiceDispatcher_UpdateBufferState(retValPending);

  /* PRQA S 6010, 6030, 6050 4 */ /* MD_SSA_METRIC_SERVICE_DISPATCHER, MD_SSA_METRIC_SERVICE_DISPATCHER, MD_MSR_STCAL */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define Ssa_ProcCtrl_STOP_SEC_CODE
#include "Ssa_ProcCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define Ssa_ProcCtrl_START_SEC_CODE
#include "Ssa_ProcCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * ProcCtrl_GenericReadData_PostStateMachineHandler()
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
SSA_PROCCTRL_LOCAL FUNC(void, Ssa_ProcCtrl_CODE) ProcCtrl_GenericReadData_PostStateMachineHandler(
  uint8 Operation,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) Data, /* PRQA S 3673 */ /* MD_SSA_LOCAL_FUNCTION_PARAM_NOT_P2CONST */
  P2VAR(Ssa_ProcCtrlSharedBufferDataType, AUTOMATIC, AUTOMATIC) ProcCtrlBuffer, /* PRQA S 3673 */ /* MD_SSA_LOCAL_FUNCTION_PARAM_NOT_P2CONST */
  const uint32 ProcCtrlBufferSize,
  const uint8 ServiceId)
{
  /* #10 Apply operation returned by state machine. */
  switch (Operation) {
  case SSA_PROCCTRL_OPERATION_IDLE:
    /* #12 If operation is IDLE wait for called service to finish, i.e. no action. */
    break;
  case SSA_PROCCTRL_OPERATION_PENDING:
    /* #14 If operation is PENDING call again the ProcCtrl service dispatcher. */
    (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
    break;
  case SSA_PROCCTRL_OPERATION_INPUT:
    /* #16 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
    /* No input data to be copied. */
    /* Conditionally assign output buffer. */
    ProcCtrl_AssignBufferCond(Data, *ProcCtrlBuffer, ProcCtrlBufferSize);
    /* Call service dispatcher. */
    Ssa_ProcCtrlBuffer.ServiceId = ServiceId;
    (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
    break;
  case SSA_PROCCTRL_OPERATION_OUTPUT:
    /* #18 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer and free the buffer to be accessible by next service. */
    ProcCtrl_CopyBufferCond(Data, ProcCtrlBuffer, ProcCtrlBufferSize); /* PRQA S 0315, 1338, 2983, 3112  */ /* MD_SSA_P2VOID_CAST, MD_MSR_DummyStmt  */ /*lint -e{438} */
    /* Set buffer state to free. */
    Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
    break;
  default: /* COV_SSA_MISRA */
    /* Not reachable, QAC only. */
    break;
  }
}

/**********************************************************************************************************************
 * ProcCtrl_GenericReadDataLength_PostStateMachineHandler()
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
SSA_PROCCTRL_LOCAL FUNC(void, Ssa_ProcCtrl_CODE) ProcCtrl_GenericReadDataLength_PostStateMachineHandler(
  uint8 Operation,
  P2VAR(uint16, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) DataLength,
  const uint16 ProcCtrlBufferLength,
  const uint8 ServiceId)
{
  /* #10 Apply operation returned by state machine. */
  switch (Operation) {
  case SSA_PROCCTRL_OPERATION_IDLE:
    /* #12 If operation is IDLE wait for called service to finish, i.e. no action. */
    break;
  case SSA_PROCCTRL_OPERATION_PENDING:
    /* #14 If operation is PENDING call again the ProcCtrl service dispatcher. */
    (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
    break;
  case SSA_PROCCTRL_OPERATION_INPUT:
    /* #16 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
    /* No input data to be copied. */
    /* Call service dispatcher. */
    Ssa_ProcCtrlBuffer.ServiceId = ServiceId;
    (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
    break;
  case SSA_PROCCTRL_OPERATION_OUTPUT:
    /* #18 If operation is OUTPUT and buffer handling is enabled copy the output data length from the ProcCtrl buffer
     * and free the buffer to be accessible by next service. */
    *DataLength = ProcCtrlBufferLength;
    /* Set buffer state to free. */
    Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
    break;
  default: /* COV_SSA_MISRA */
    /* Not reachable, QAC only. */
    break;
  }
}

/**********************************************************************************************************************
 * ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler()
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
SSA_PROCCTRL_LOCAL FUNC(void, Ssa_ProcCtrl_CODE) ProcCtrl_GenericConditionCheckRead_PostStateMachineHandler(
  uint8 Operation,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCodeFromBuffer,
  const uint8 ServiceId)
{
  /* #10 Apply operation returned by state machine. */
  switch (Operation) {
  case SSA_PROCCTRL_OPERATION_IDLE:
    /* #12 If operation is IDLE wait for called service to finish, i.e. no action. */
    break;
  case SSA_PROCCTRL_OPERATION_PENDING:
    /* #14 If operation is PENDING call again the ProcCtrl service dispatcher. */
    (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
    break;
  case SSA_PROCCTRL_OPERATION_INPUT:
    /* #16 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
    /* No input data to be copied. */
    /* Preset NRC buffer with value passed from DCM */
    *ErrorCodeFromBuffer = *ErrorCode;
    /* Call service dispatcher. */
    Ssa_ProcCtrlBuffer.ServiceId = ServiceId;
    (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
    break;
  case SSA_PROCCTRL_OPERATION_OUTPUT:
    /* #18 If operation is OUTPUT and buffer handling is enabled copy the output data from the ProcCtrl buffer (ErrorCodeFromBuffer)
     * and free the buffer to be accessible by next service. */
    *ErrorCode = *ErrorCodeFromBuffer;
    /* Set buffer state to free. */
    Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
    break;
  default: /* COV_SSA_MISRA */
    /* Not reachable, QAC only. */
    break;
  }
}

/**********************************************************************************************************************
 * ProcCtrl_GenericRoutineService_PostStateMachineHandler()
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
SSA_PROCCTRL_LOCAL FUNC(void, Ssa_ProcCtrl_CODE) ProcCtrl_GenericRoutineService_PostStateMachineHandler(
  uint8 Operation,
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) routineInfo,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode,
  const uint8 routineInfoFromBuffer,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCodeFromBuffer,
  const uint8 ServiceId)
{
  /* #10 Apply operation returned by state machine. */
  switch (Operation) {
  case SSA_PROCCTRL_OPERATION_IDLE:
    /* #12 If operation is IDLE wait for called service to finish, i.e. no action. */
    break;
  case SSA_PROCCTRL_OPERATION_PENDING:
    /* #14 If operation is PENDING call again the ProcCtrl service dispatcher. */
    (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
    break;
  case SSA_PROCCTRL_OPERATION_INPUT:
    /* #16 If operation is INPUT prepare the input data of the ProcCtrl buffer and call the service dispatcher. */
    /* No input data to be copied. */
    /* Preset NRC buffer with value passed from DCM */
    *ErrorCodeFromBuffer = *ErrorCode;
    /* Call service dispatcher. */
    Ssa_ProcCtrlBuffer.ServiceId = ServiceId;
    (void)Rte_Write_ProcCtrl_DispatchServices_Sender_ServiceId(Ssa_ProcCtrlBuffer.ServiceId);
    break;
  case SSA_PROCCTRL_OPERATION_OUTPUT:
    /* #18 If operation is OUTPUT and buffer handling is enabled copy the output data routineInfo and errorCode
     *     from the ProcCtrl buffer and free the buffer to be accessible by next service. */
    *routineInfo = routineInfoFromBuffer;
    *ErrorCode = *ErrorCodeFromBuffer;
    /* Set buffer state to free. */
    Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
    break;
  default: /* COV_SSA_MISRA */
    /* Not reachable, QAC only. */
    break;
  }
} /* PRQA S 6060 */ /* MD_SSA_STPAR */

/**********************************************************************************************************************
 * ProcCtrl_Statemachine_ProcessBufferStateFree()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine_ProcessBufferStateFree(
  uint8 opStatus,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) operation)
{
  Std_ReturnType retVal;

  /* #10 Handle operation status in buffer state FREE. */
  if ((opStatus == DCM_INITIAL) || (opStatus == DCM_PENDING))
  {
    Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_PROCESSING;
    *operation = SSA_PROCCTRL_OPERATION_INPUT;
    /* Input data are copied, change to OpStatus DCM_INITIAL. */
    Ssa_ProcCtrlBuffer.OpStatus = DCM_INITIAL;
    retVal = SSA_RTE_E_PENDING;
  }
  else
  {
    retVal = RTE_E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * ProcCtrl_Statemachine_ProcessBufferStateProcessing()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine_ProcessBufferStateProcessing(
  uint8 opStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode)
{
  Std_ReturnType retVal;

  /* #10 Handle operation status in buffer state PROCESSING. */
  if (opStatus == DCM_PENDING)
  {
    retVal = SSA_RTE_E_PENDING;
  }
  else if (opStatus == DCM_CANCEL)
  {
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
    Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL;
    retVal = RTE_E_OK;
#else
    *errorCode = DCM_E_GENERALREJECT;
    retVal = SSA_RTE_E_NOT_OK;
#endif
  }
  else
  {
    *errorCode = DCM_E_CONDITIONSNOTCORRECT;
    retVal = SSA_RTE_E_NOT_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * ProcCtrl_Statemachine_ProcessBufferStatePending()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine_ProcessBufferStatePending(
  uint8 opStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) operation)
{
  Std_ReturnType retVal;

  /* #10 Handle operation status in buffer state PENDING. */
  if (opStatus == DCM_PENDING)
  {
    *operation = SSA_PROCCTRL_OPERATION_PENDING;
    Ssa_ProcCtrlBuffer.OpStatus = DCM_PENDING;
    Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_PROCESSING;
    retVal = SSA_RTE_E_PENDING;
  }
  else if (opStatus == DCM_CANCEL)
  {
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
    *operation = SSA_PROCCTRL_OPERATION_PENDING;
    Ssa_ProcCtrlBuffer.OpStatus = DCM_PENDING;
    Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL;
    retVal = RTE_E_OK;
#else
    *errorCode = DCM_E_GENERALREJECT;
    retVal = SSA_RTE_E_NOT_OK;
#endif
  }
  else
  {
    *errorCode = DCM_E_CONDITIONSNOTCORRECT;
    retVal = SSA_RTE_E_NOT_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * ProcCtrl_Statemachine_ProcessBufferStateReady()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine_ProcessBufferStateReady(
  uint8 opStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) operation)
{
  Std_ReturnType retVal;

  /* #10 Handle operation status in buffer state READY. */
  if (opStatus == DCM_INITIAL)
  {
    *errorCode = DCM_E_CONDITIONSNOTCORRECT;
    retVal = SSA_RTE_E_NOT_OK;
  }
  else if (opStatus == DCM_PENDING)
  {
    *operation = SSA_PROCCTRL_OPERATION_OUTPUT;
    retVal = Ssa_ProcCtrlBuffer.Result;
    /* Set a default negative response code to prevent SSA from returning E_NOT_OK and DCM_E_POSITIVE_RESPONSE.
       This value is supposed to be overwritten. */
    if (retVal == SSA_RTE_E_NOT_OK)
    {
      *errorCode = DCM_E_CONDITIONSNOTCORRECT;
    }
    /* Set buffer state to free in every caller. */
  }
  else
  {
    Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
    retVal = RTE_E_OK;
  }

  return retVal;
}

#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
/**********************************************************************************************************************
 * ProcCtrl_Statemachine_ProcessBufferStateWaitCancel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine_ProcessBufferStateWaitCancel(
  uint8 opStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode)
{
  Std_ReturnType retVal;

  /* #10 Handle operation status in buffer state WAIT_CANCEL. */
  if (opStatus == DCM_INITIAL)
  {
    Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL_INIT;
    retVal = SSA_RTE_E_PENDING;
  }
  else if (opStatus == DCM_PENDING)
  {
    *errorCode = DCM_E_CONDITIONSNOTCORRECT;
    retVal = SSA_RTE_E_NOT_OK;
  }
  else
  {
    retVal = RTE_E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * ProcCtrl_Statemachine_ProcessBufferStateCancelInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine_ProcessBufferStateCancelInit(
  uint8 opStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode)
{
  Std_ReturnType retVal;

  /* #10 Handle operation status in buffer state WAIT_CANCEL_INIT. */
  if (opStatus == DCM_PENDING)
  {
    retVal = SSA_RTE_E_PENDING;
  }
  else if (opStatus == DCM_INITIAL)
  {
    *errorCode = DCM_E_CONDITIONSNOTCORRECT;
    retVal = SSA_RTE_E_NOT_OK;
  }
  else
  {
    retVal = RTE_E_OK;
  }

  return retVal;
}

/**********************************************************************************************************************
 * ProcCtrl_Statemachine()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine_ProcessBufferStateCancelPending(
  uint8 opStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) operation)
{
  Std_ReturnType retVal;

  /* #10 Handle operation status in buffer state WAIT_CANCEL_PENDING. */
  if (opStatus == DCM_INITIAL)
  {
    Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL_INIT;
    retVal = SSA_RTE_E_PENDING;
  }
  else if (opStatus == DCM_PENDING)
  {
    Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL;
    *errorCode = DCM_E_CONDITIONSNOTCORRECT;
    retVal = SSA_RTE_E_NOT_OK;
  }
  else
  {
    Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL;
    retVal = RTE_E_OK;
  }
  Ssa_ProcCtrlBuffer.OpStatus = DCM_PENDING;
  *operation = SSA_PROCCTRL_OPERATION_PENDING;

  return retVal;
}

/**********************************************************************************************************************
 * ProcCtrl_Statemachine_ProcessBufferStateCancelInitPending()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine_ProcessBufferStateCancelInitPending(
  uint8 opStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) operation)
{
  Std_ReturnType retVal;

  /* #10 Handle operation status in buffer state WAIT_CANCEL_INIT_PENDING. */
  if (opStatus == DCM_PENDING)
  {
    retVal = SSA_RTE_E_PENDING;
  }
  else if (opStatus == DCM_INITIAL)
  {
    *errorCode = DCM_E_CONDITIONSNOTCORRECT;
    retVal = SSA_RTE_E_NOT_OK;
  }
  else
  {
    retVal = RTE_E_OK;
  }
  Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL_INIT;
  Ssa_ProcCtrlBuffer.OpStatus = DCM_PENDING;
  *operation = SSA_PROCCTRL_OPERATION_PENDING;

  return retVal;
}
#endif /* (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) */

/**********************************************************************************************************************
 * ProcCtrl_Statemachine()
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
SSA_PROCCTRL_LOCAL FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) ProcCtrl_Statemachine(
  uint8 OpStatus,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) ErrorCode,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) operation)
{
  Std_ReturnType retVal;
  Dcm_NegativeResponseCodeType localErrorCode = DCM_E_POSITIVERESPONSE;
  /* Initialize error code to prevent SSA from returning E_NOT_OK and DCM_E_POSITIVERESPONSE */
  if (ErrorCode != NULL_PTR)
  {
    localErrorCode = *ErrorCode;
  }

  /* Set default operation. */
  *operation = SSA_PROCCTRL_OPERATION_IDLE;

  Rte_Enter_Ssa_ProcCtrl_ExclusiveArea();

  /* #10 Depending on buffer state and DCM operation status, the operation (IDLE, PENDING, INPUT, OUTPUT) and the return value are derived. */
  /* #20 Do the state machine handling for the ProcCtrl buffer state variable. */
  switch (Ssa_ProcCtrlBuffer.State) {
  case  SSA_PROCCTRL_BUFFERSTATE_FREE:
    /* #30 Handle operation status in buffer state FREE. */
    retVal = ProcCtrl_Statemachine_ProcessBufferStateFree(OpStatus, operation);
    break;

  case  SSA_PROCCTRL_BUFFERSTATE_PROCESSING:
    /* #40 Handle operation status in buffer state PROCESSING. */
    retVal = ProcCtrl_Statemachine_ProcessBufferStateProcessing(OpStatus, &localErrorCode);
    break;

  case SSA_PROCCTRL_BUFFERSTATE_PENDING:
    /* #50 Handle operation status in buffer state PENDING. */
    retVal = ProcCtrl_Statemachine_ProcessBufferStatePending(OpStatus, &localErrorCode, operation);
    break;

  case SSA_PROCCTRL_BUFFERSTATE_READY:
    /* #60 Handle operation status in buffer state READY. */
    retVal = ProcCtrl_Statemachine_ProcessBufferStateReady(OpStatus, &localErrorCode, operation);
    break;

#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  case SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL:
    /* #70 Handle operation status in buffer state WAIT_CANCEL. */
    retVal = ProcCtrl_Statemachine_ProcessBufferStateWaitCancel(OpStatus, &localErrorCode);
    break;

  case SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL_INIT:
    /* #80 Handle operation status in buffer state WAIT_CANCEL_INIT. */
    retVal = ProcCtrl_Statemachine_ProcessBufferStateCancelInit(OpStatus, &localErrorCode);
    break;

  case SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL_PENDING:
    /* #90 Handle operation status in buffer state WAIT_CANCEL_PENDING. */
    retVal = ProcCtrl_Statemachine_ProcessBufferStateCancelPending(OpStatus, &localErrorCode, operation);
    break;

  case SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL_INIT_PENDING:
    /* #100 Handle operation status in buffer state WAIT_CANCEL_INIT_PENDING. */
    retVal = ProcCtrl_Statemachine_ProcessBufferStateCancelInitPending(OpStatus, &localErrorCode, operation);
    break;
#endif

  default:  /* COV_SSA_MISRA */
    retVal = SSA_RTE_E_NOT_OK;
    localErrorCode = DCM_E_GENERALREJECT;
    break;
  }
  Rte_Exit_Ssa_ProcCtrl_ExclusiveArea();

  if (ErrorCode != NULL_PTR)
  {
    *ErrorCode = localErrorCode;
  }

  return retVal;
} /* PRQA S 6030, 6050 */ /* MD_MSR_STCYC, MD_MSR_STCAL */

/**********************************************************************************************************************
 *  Ssa_ProcCtrl_MapS29In()
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
/* PRQA S 3673 4 */ /* MD_SSA_PARAM_NOT_P2CONST */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Dcm_NegativeResponseCodeType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_MapS29In(
  uint32 reqDataLen,
  Ssa_ConstDataPtr reqData,
  Ssa_DataPtr resData,
  Dcm_NegativeResponseCodeType errorCodeIn
)
{
  Dcm_NegativeResponseCodeType errorCode = DCM_E_POSITIVERESPONSE;
  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) dataIn = (P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR))reqData;
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) dataOut = (P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR))resData; /* PRQA S 3678 */ /* MD_SSA_PARAM_NOT_P2CONST */

  if (reqDataLen < 1u)
  {
    errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
  }
  else
  {
    /* #10 Get sub function with blinding out the suppressPositiveResponse bit. */
    uint8 subFunc = (dataIn[0] & ((uint8)0x7Fu));

    /* #20 Map the parameters of S29 onto the parameter of S31, R260 resp. R261, dependent on the sub-function. */
    switch (subFunc)
    {
    case SSA_S29_SF_DEAUTH:
      /* #30 Sub-function DeAuthenticate: Set Task 0x02 */
      if (reqDataLen > 1u)
      {
        errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      }
      else
      {
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Configuration = SSA_AUTHENTICATE_UNIDIRECTIONAL_AUTHETICATION_CONFIGURATION;
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Task = SSA_AUTHENTICATE_DEAUTH_TASK;
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.DataLength = 0u;
        /* Conditionally assign output buffer. */
        ProcCtrl_AssignBufferCond(&dataOut[2], Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Authentication_Result, 0); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
        /* Preset NRC buffer with value passed from DCM */
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.ErrorCode = errorCodeIn;
        /* Set dispatcher service id. */
        Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_AUTHENTICATE_BY_S29;
      }
      break;
    case SSA_S29_SF_VERIFY_CERT_UNIDIRECTIONAL:
      /* #40 Sub-function VerifyCertificateUnidirectional: Set Task 0x00 */
      if (reqDataLen < 6u)
      {
        errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      }
      else
      {
        uint16 len;
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Task = SSA_AUTHENTICATE_INITIATE_AUTH_TASK;
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Configuration = SSA_AUTHENTICATE_UNIDIRECTIONAL_AUTHETICATION_CONFIGURATION;
        /* No challenge sent from diagnostic user */
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Challenge_Certificate_Proof_of_Ownership[0] = 0x00u;
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Challenge_Certificate_Proof_of_Ownership[1] = 0x00u;
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.DataLength = 2u;
#else
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Configuration = SSA_AUTHENTICATE_UNIDIRECTIONAL_AUTHETICATION_CONFIGURATION | SSA_AUTHENTICATE_S29_SUB_PROCESSING_ACTIVE_CONFIGURATION;
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.DataLength = 0u;
#endif

        /* Destination buffer Challenge_Certificate_Proof_of_Ownership has length sizeof(Dcm_Data4004ByteType) */
        /* DataLength is the size of passed data in buffer Challenge_Certificate_Proof_of_Ownership. */
        /* #45 Get and check length of certificate, then map it
         *     Use SSA_S29_SUB_PROCESSING_ACTIVE if SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING is not STD_ON */

        len = Ssa_GetUint16(dataIn[2], dataIn[3]);
        /* communication configuration must be 0 */
        if (dataIn[1] != 0x00u)
        {
          errorCode = DCM_E_REQUESTOUTOFRANGE;
        }
        if ((reqDataLen < (6u + (uint32)len)) || ((4u + len) >(uint16)sizeof(Dcm_Data4004ByteType)))
        {
          errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        }
        else
        {
          /* add length of size information */
          len += 2u;

#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
          Ssa_MemCpy(&Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Challenge_Certificate_Proof_of_Ownership[2], &dataIn[2], len); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
#else
          Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Challenge_Certificate_Proof_of_Ownership = &dataIn[2];
#endif
          Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.DataLength += len;  /* PRQA S 2986 */ /* MD_SSA_REDUNDANT_OP */
          /* Conditionally assign output buffer. */
          ProcCtrl_AssignBufferCond(&dataOut[2], Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Authentication_Result, len); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
          /* don't care about challenge client */
          /* Preset NRC buffer with value passed from DCM */
          Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.ErrorCode = errorCodeIn;
          /* Call service dispatcher. */
          Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_AUTHENTICATE_BY_S29;
        }
      }
      break;
    case SSA_S29_SF_PROOF_OF_OWNERSHIP:
      /* #50 Sub-function ProofOfOwnership: Set Task 0x01 */
      if (reqDataLen < 5u)
      {
        errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      }
      else
      {
        uint16 len;
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Task = SSA_AUTHENTICATE_PROOF_OF_OWNERSHIP_TASK;
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Configuration = SSA_AUTHENTICATE_UNIDIRECTIONAL_AUTHETICATION_CONFIGURATION;
        /* No challenge sent from diagnostic user */
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Challenge_Certificate_Proof_of_Ownership[0] = 0x00u;
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Challenge_Certificate_Proof_of_Ownership[1] = 0x00u;
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.DataLength = 2u;
#else
        /* Set highest bit of Configuration to indicate */
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Configuration = SSA_AUTHENTICATE_UNIDIRECTIONAL_AUTHETICATION_CONFIGURATION | SSA_AUTHENTICATE_S29_SUB_PROCESSING_ACTIVE_CONFIGURATION;
        Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.DataLength = 0u;
#endif
        /* Destination buffer Challenge_Certificate_Proof_of_Ownership has length sizeof(Dcm_Data4004ByteType) */
        /* DataLength is the size of passed data in buffer Challenge_Certificate_Proof_of_Ownership. */
        /* #55 Get and check length of proof, then map it
         *     Use SSA_S29_SUB_PROCESSING_ACTIVE if SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING is not STD_ON */
        len = Ssa_GetUint16(dataIn[1], dataIn[2]);
        if ((reqDataLen < (5u + (uint32)len)) || ((4u + (uint32)len) > (uint32)sizeof(Dcm_Data4004ByteType)))
        {
          errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        }
        else
        {
          /* add length of size information */
          len += 2u;
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
          Ssa_MemCpy(&Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Challenge_Certificate_Proof_of_Ownership[2], &dataIn[1], len); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
#else
          Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Challenge_Certificate_Proof_of_Ownership = &dataIn[1];
#endif
          Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.DataLength += len; /* PRQA S 2986 */ /* MD_SSA_REDUNDANT_OP */
          /* don't care about EphemeralPublicKeyClient */
          /* Conditionally assign output buffer. */
          ProcCtrl_AssignBufferCond(&dataOut[2], Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Authentication_Result, len); /* PRQA S 1338, 2983, 3112  */ /* MD_MSR_DummyStmt */ /*lint -e{438} */
          /* Preset NRC buffer with value passed from DCM */
          Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.ErrorCode = errorCodeIn;
          /* Set dispatcher service id. */
          Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_AUTHENTICATE_BY_S29;
        }
      }
      break;
    case SSA_S29_SF_TRANSMIT_CERT:
      /* #60 Sub-function TransmitCertificate */
      if (reqDataLen < 5u)
      {
        errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      }
      else
      {
        uint16 len;
        /* Destination buffer Enhanced_Rights_Certificate has length sizeof(Dcm_Data2002ByteType) */
        /* DataLength is the size of passed data in buffer Enhanced_Rights_Certificate. */
        /* ignore check 2 bytes CertificateEvaluationId */
        /* #65 Get and check length of certificate, then map it */
        len = Ssa_GetUint16(dataIn[3], dataIn[4]);
        if ((reqDataLen < (4u + (uint32)len)) || ((2u + (uint32)len) > (uint32)sizeof(Dcm_Data2002ByteType)))
        {
          errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        }
        else
        {
          /* add length of size information */
          len += 2u;
          /*@assert len <= sizeof(Dcm_Data2002ByteType) */
          /*@ assert $lengthOf(Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRightsByS31.Enhanced_Rights_Certificate) >= sizeof(Dcm_Data2002ByteType); */
          ProcCtrl_PrepareBuffer(Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRightsByS31.Enhanced_Rights_Certificate, &dataIn[3], len); /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */
          Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRightsByS31.DataLength = len;
          /* Call service dispatcher. */
          Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_ENHANCE_ACCESS_RIGHTS_BY_S29;
        }
      }
      break;
    case SSA_S29_SF_AUTH_CONFIG:
      /* #70 Sub-function AuthenticationConfiguration. Simulate a service call. */
      if (reqDataLen > 1u)
      {
        errorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
      }
      else
      {
        Ssa_ProcCtrlBuffer.ServiceId = SSA_PROCCTRL_SERVICE_ID_AUTHENTICATION_CONFIG_BY_S29;
      }
      break;
    default:
      errorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
      break;
    }
  }
  return errorCode;
} /* PRQA S 6030 */ /* MD_MSR_STCYC */

/**********************************************************************************************************************
 *  Ssa_ProcCtrl_MapS29Out()
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
SSA_PROCCTRL_LOCAL_INLINE FUNC(Dcm_NegativeResponseCodeType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_MapS29Out(
  Ssa_ConstDataPtr reqData,
  uint32 resDataBufferSize,
  P2VAR(uint32, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) resDataLen,
  Ssa_DataPtr resData,
  P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) retVal)
{
  uint8 mappedVerifResult;
  Dcm_NegativeResponseCodeType errorCode = DCM_E_POSITIVERESPONSE;

  P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) dataIn = (P2CONST(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR))reqData;
  P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) dataOut = (P2VAR(uint8, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR))resData;

  /* #10 Get sub-function with blinding out the suppressPositiveResponse bit. */
  /*     The buffer dataIn was checked to have a length >=1 in the function Ssa_ProcCtrl_MapS29In, that has been called beforehand. */
  uint8 subFunc = (dataIn[0] & ((uint8)0x7Fu));

  /* #20 Do the mapping dependent on the sub-function for verification results that shall be mapped to dataOut. */
  if (resDataBufferSize < 2u)
  {
    /* This runtimecheck is required, since in each case of the switch it is written to dataOut[0] and dataOut[1], i.e. resData[0] and resData[1]. */
    errorCode = DCM_E_CONDITIONSNOTCORRECT;
  }
  else
  {
    /*@ assert $lengthOf(resData) >= resDataBufferSize; */ /* VCA_SSA_PROCCTRL_RELATION_DATABUFFER_AND_SIZEOF_DATABUFFER_CHECKED_IN_SPECIFICATION */
    /*@ assert resDataBufferSize >= 2u; */
    switch (subFunc)
    {
      /* #30 Sub-function DeAuthenticate */
      case SSA_S29_SF_DEAUTH:
      {
        if (*retVal == E_OK)
        {
          /* Map the verification result. */
          *retVal = Ssa_ProcCtrl_MapAuthVerifResult(Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Verification_Result, &mappedVerifResult, &errorCode);
          if (*retVal == E_OK)
          {
            dataOut[0] = dataIn[0];
            dataOut[1] = mappedVerifResult;
            *resDataLen = 2u;
          }
        }
        else
        {
          errorCode = Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.ErrorCode;
          /* Do not overwrite retVal in this case, the retVal is already E_NOT_OK. */
        }
        break;
      }
      /* #40 Sub-function VerifyCertificateUnidirectional */
      case SSA_S29_SF_VERIFY_CERT_UNIDIRECTIONAL:
      {
        if (*retVal == E_OK)
        {
          uint16 len;
          uint16 resDataBufferSize_uint16;

          /* Map the verification result. */
          *retVal = Ssa_ProcCtrl_MapAuthVerifResult(Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Verification_Result, &mappedVerifResult, &errorCode);

          if (*retVal == E_OK)
          {
            dataOut[0] = dataIn[0];
            dataOut[1] = mappedVerifResult;
            *resDataLen = 2u;

            /* The authentication result consists of 3 iterations (see Candela file), here only the first iteration is required. */

            /* len cannot be larger than the size of Authentication_Result, which ist 3006 byte */
            len = Ssa_GetUint16(Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Authentication_Result[0], Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Authentication_Result[1]);

            /* The uint32 resDataBuffer should not be larger than an uint16, since it represents the length of the returned challenge (i.e. 32 byte)
               The type uint32 is defined by the Dcm and cannot be changed, but here it is calculated only with uint16. */
            resDataBufferSize_uint16 = (uint16)(SSA_MIN(resDataBufferSize, 0xFFFFu));

            /* Length check for writing to dataOut and for reading from Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Authentication_Result.*/
            /* For reading, len has to be <= sizeof(Dcm_Data3006ByteType), which is the length of Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Authentication_Result. */
            if (((((uint32)len + 6u) < (uint32)resDataBufferSize_uint16) && (((uint32)len + 2u) <=  (uint32)sizeof(Dcm_Data3006ByteType))))
            {
              len += 2u; /* Also copy the length of Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Authentication_Result, which is stored in the first two bytes. */
              /* Destination buffer dataOut has length resDataBufferSize. */
              ProcCtrl_CopyBufferCond( /* PRQA S 0315 */ /* MD_SSA_P2VOID_CAST */  /* VCA_SSA_PROCCTRL_DATALENGTH_CHECKED_BY_RUNTIME_CHECK */
                &dataOut[2],
                Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Authentication_Result,
                len);

              *resDataLen += len;
              /* NoEphemeralPublicKeyServer */
              dataOut[2u + len] = 0u; /* VCA_SSA_PROCCTRL_MAP_S29_OUT_WRITE_ACCESS_DATAOUT */
              dataOut[2u + len + 1u] = 0u; /* VCA_SSA_PROCCTRL_MAP_S29_OUT_WRITE_ACCESS_DATAOUT */
              *resDataLen += 2u;
            }
            else
            {
              errorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
          }
        }
        else
        {
          errorCode = Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.ErrorCode;
          /* Do not overwrite retVal in this case, the retVal is already E_NOT_OK. */
        }
        break;
      }
      /* #50 Sub-function ProofOfOwnership */
      case SSA_S29_SF_PROOF_OF_OWNERSHIP:
      {
        if (*retVal == E_OK)
        {
          /* Map the verification result. */
          *retVal = Ssa_ProcCtrl_MapAuthVerifResult(Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.Verification_Result, &mappedVerifResult, &errorCode);
          if (*retVal == E_OK)
          {
            if (resDataBufferSize < 4u) /* resDataBufferSize is the size of dataOut, i.e. resData. */
            {
              errorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
            else
            {
              /*@ assert $lengthOf(resData) >= resDataBufferSize; */ /* VCA_SSA_PROCCTRL_RELATION_DATABUFFER_AND_SIZEOF_DATABUFFER_CHECKED_IN_SPECIFICATION */
              /*@ assert resDataBufferSize >= 4u; */
              dataOut[0] = dataIn[0];
              dataOut[1] = mappedVerifResult;
              *resDataLen = 2u;
              /* NoSessionKeyInfo */
              dataOut[2] = 0u;
              dataOut[3] = 0u;
              *resDataLen += 2u;
            }
          }
        }
        else
        {
          errorCode = Ssa_ProcCtrlBuffer.SharedData.AuthenticateByS31.ErrorCode;
          /* Do not overwrite retVal in this case, the retVal is already E_NOT_OK. */
        }
        break;
      }
      /* #60 Sub-function TransmitCertificate */
      case SSA_S29_SF_TRANSMIT_CERT:
      {
        if (*retVal == E_OK)
        {
          /* Map the verification result. */
          *retVal = Ssa_ProcCtrl_MapEnhanceVerifResult(Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRightsByS31.Verification_Result, &mappedVerifResult, &errorCode);
          if (*retVal == E_OK)
          {
            /*@ assert resDataBufferSize >= 2u; */
            dataOut[0] = dataIn[0];
            dataOut[1] = mappedVerifResult;
            *resDataLen = 2u;
          }
        }
        else
        {
          errorCode = Ssa_ProcCtrlBuffer.SharedData.EnhanceAccessRightsByS31.ErrorCode;
          /* Do not overwrite retVal in this case, the retVal is already E_NOT_OK. */
        }
        break;
      }
      case SSA_S29_SF_AUTH_CONFIG:
        /* #70 Sub-function AuthenticationConfiguration. Set verification result directly. */
        /*@ assert resDataBufferSize >= 2u; */
        dataOut[0] = dataIn[0];
        dataOut[1] = SSA_VER_RES_AUTH_S29_AUTHENTICATION_CONFIGURATION_APCE;
        *resDataLen = 2u;
        errorCode = DCM_E_POSITIVERESPONSE;
        break;
      default:
        errorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        break;
    }
  }
  return errorCode;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  Ssa_ProcCtrl_MapAuthVerifResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_MapAuthVerifResult(
  uint8 verifResultIn,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) mappedVerifResult,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode)
{
  Std_ReturnType retVal = E_OK;

  switch (verifResultIn)
  {
  /* Map verification results to verification results. */
  case SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFIED_OWNERSHIP_VERIFICATION_NECESSARY:
    *mappedVerifResult = SSA_VER_RES_AUTH_S29_CERTIFICATE_VERIFIED_OWNERSHIP_VERIFICATION_NECESSARY;
    break;
  case SSA_VER_RES_AUTHENTICATE_OWNERSHIP_VERIFIED_AUTHENTICATION_COMPLETE:
  case SSA_VER_RES_AUTHENTICATE_OWNERSHIP_VERIFIED_AUTHENTICATION_COMPLETE_CENTRAL_AUTHENTICATION_BROADCAST_TRIGGERED:
    *mappedVerifResult = SSA_VER_RES_AUTH_S29_OWNERSHIP_VERIFIED_AUTHENTICATION_COMPLETE;
    break;
  case SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFIED_TIME_SET:
    *mappedVerifResult = SSA_VER_RES_AUTH_S29_CERTIFICATE_VERIFIED;
    break;
  case SSA_VER_RES_AUTHENTICATE_DEAUTHENTICATION_SUCCESSFUL:
    *mappedVerifResult = SSA_VER_RES_AUTH_S29_DEAUTHENTICATION_SUCCESSFUL;
    break;
  /* Map verification results to NRCs. */
  case SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD:
    *errorCode = SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD;
    retVal = SSA_RTE_E_NOT_OK;
    break;
  case SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE:
    *errorCode = SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE;
    retVal = SSA_RTE_E_NOT_OK;
    break;
  case SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST:
    *errorCode = SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST;
    retVal = SSA_RTE_E_NOT_OK;
    break;
  case SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE:
    *errorCode = SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE;
    retVal = SSA_RTE_E_NOT_OK;
    break;
  case SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT:
    *errorCode = SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT;
    retVal = SSA_RTE_E_NOT_OK;
    break;
  case SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT:
  case SSA_VER_RES_AUTHENTICATE_SYNCHRONIZE_TIME_FAILED_NONCE_NOT_ACCEPTED:
    *errorCode = SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT;
    retVal = SSA_RTE_E_NOT_OK;
    break;
  case SSA_VER_RES_AUTHENTICATE_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE:
    *errorCode = SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE;
    retVal = SSA_RTE_E_NOT_OK;
    break;
  case SSA_VER_RES_AUTHENTICATE_OWNERSHIP_VERIFICATION_FAILED:
    *errorCode = SSA_DCM_E_NRC_AUTH_S29_OWNERSHIP_VERIFICATION_FAILED;
    retVal = SSA_RTE_E_NOT_OK;
    break;
  case SSA_VER_RES_AUTHENTICATE_DEAUTHENTICATION_FAILED:
    *errorCode = SSA_DCM_E_NRC_AUTH_S29_DEAUTHENTICATION_FAILED;
    retVal = SSA_RTE_E_NOT_OK;
    break;
  default:
    *mappedVerifResult = SSA_VER_RES_AUTH_S29_GENERAL_REJECT;
    break;
  }

  return retVal;
} /* PRQA S 6030 */ /* MD_SSA_MIF_CHECK_CONDITIONS */

/**********************************************************************************************************************
 *  Ssa_ProcCtrl_MapEnhanceVerifResult()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
SSA_PROCCTRL_LOCAL_INLINE FUNC(Std_ReturnType, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_MapEnhanceVerifResult(
  uint8 verifResultIn,
  P2VAR(uint8, AUTOMATIC, AUTOMATIC) mappedVerifResult,
  P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_SSA_PROCCTRL_APPL_VAR) errorCode)
{
  Std_ReturnType retVal = E_OK;

  switch (verifResultIn)
  {
  case SSA_VER_RES_ENHANCE_ACCESS_RIGHTS_CERTIFICATE_VERIFIFED_ACCESS_RIGHTS_ENHANCED:
    *mappedVerifResult = SSA_VER_RES_AUTH_S29_CERTIFICATE_VERIFIED;
    break;
  case SSA_VER_RES_ENHANCE_ACCESS_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD:
    *errorCode = SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_TIME_PERIOD;
    retVal = SSA_RTE_E_NOT_OK;
    break;
  case SSA_VER_RES_ENHANCE_ACCESS_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE:
    *errorCode = SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_SIGNATURE;
    retVal = SSA_RTE_E_NOT_OK;
    break;
  case SSA_VER_RES_ENHANCE_ACCESS_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST:
    *errorCode = SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_CHAIN_OF_TRUST;
    retVal = SSA_RTE_E_NOT_OK;
    break;
  case SSA_VER_RES_ENHANCE_ACCESS_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE:
    *errorCode = SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_TYPE;
    retVal = SSA_RTE_E_NOT_OK;
    break;
  case SSA_VER_RES_ENHANCE_ACCESS_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT:
    *errorCode = SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_FORMAT;
    retVal = SSA_RTE_E_NOT_OK;
    break;
  case SSA_VER_RES_ENHANCE_ACCESS_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT:
    *errorCode = SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_CONTENT;
    retVal = SSA_RTE_E_NOT_OK;
    break;
  case SSA_VER_RES_ENHANCE_ACCESS_RIGHTS_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE:
    *errorCode = SSA_DCM_E_NRC_AUTH_S29_CERTIFICATE_VERIFICATION_FAILED_INVALID_SCOPE;
    retVal = SSA_RTE_E_NOT_OK;
    break;
  default:
    *mappedVerifResult = SSA_VER_RES_AUTH_S29_SETTING_ACCESS_RIGHTS_FAILED;
    break;
  }
  return retVal;
}

/**********************************************************************************************************************
 *  Ssa_ProcCtrl_ServiceDispatcher_UpdateBufferState()
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
SSA_PROCCTRL_LOCAL_INLINE FUNC(void, Ssa_ProcCtrl_CODE) Ssa_ProcCtrl_ServiceDispatcher_UpdateBufferState(Std_ReturnType retValPending)
{
  Rte_Enter_Ssa_ProcCtrl_ExclusiveArea();
#if (SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING == STD_ON) /* COV_SSA_PROC_CTRL_BUFFER_HANDLING */
  if ((Ssa_ProcCtrlBuffer.State == SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL) || (Ssa_ProcCtrlBuffer.State == SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL_INIT))
  {
    /* #10 If in buffer state WAIT_CANCEL or WAIT_CANCEL_INIT change to WAIT_CANCEL_PENDING if pending is returned from
     * synchronous call, else change to buffer state FREE. */
    if (Ssa_ProcCtrlBuffer.Result == retValPending)
    {
      Ssa_ProcCtrlBuffer.State = (Ssa_ProcCtrlBuffer.State == SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL) ? SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL_PENDING : SSA_PROCCTRL_BUFFERSTATE_WAIT_CANCEL_INIT_PENDING;
    }
    else
    {
      Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_FREE;
    }
  }
  else
#endif
  {
    /* #20 If not in buffer state WAIT_CANCEL change to PENDING if pending is returned from
     * synchronous call, else change to buffer state READY. */
    if (Ssa_ProcCtrlBuffer.Result == retValPending)
    {
      Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_PENDING;
    }
    else
    {
      Ssa_ProcCtrlBuffer.State = SSA_PROCCTRL_BUFFERSTATE_READY;
    }
  }
  Rte_Exit_Ssa_ProcCtrl_ExclusiveArea();
}

#define Ssa_ProcCtrl_STOP_SEC_CODE
#include "Ssa_ProcCtrl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

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
 *  MISRA JUSTIFICATIONS
 *********************************************************************************************************************/
/* Justification for module-specific MISRA deviations:

  MD_SSA_STPAR:
    Reason:     Parameters are required by code design and to hold other code metrics.
    Risk:       Code is difficult to maintain. Poor readability of the code due to too many input parameters.
    Prevention: Design and code review. Clearly structured and commented code.

  MD_SSA_UTILS_11.3:
    Description: Rule 11.3
                 A cast should not be performed between a pointer type and an integral type.
    Reason:      An optimized copy algorithm can be used for aligned data. To check if pointers are aligned, pointers need to be casted to an integer type.
    Risk:        No functional risk. Only the lower 8 bits of the address are checked, therefore all integer types are sufficient.
    Prevention:  Not required.

  MD_SSA_MICROSAR_OS:
    Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS.
                Those deviations are no issues in the Ssa code.
    Risk:       No functional risk.
    Prevention: Not required.

  MD_SSA_OBJECT_AT_FILE_SCOPE:
    Description: Rule 8.9
                 Objects shall be defined at block scope if they are only accessed from within a single function.
    Reason:      Vector style guide prevents usage of static variables/constant objects in function scope.
    Risk:        None.
    Prevention:  Covered by code review.

  MD_SSA_OBJECT_REFERENCED_ONCE:
    Description: Rule 8.9
                 An object should be defined at block scope if its identifier only appears in a single function.
    Reason:      Vector style guide prevents usage of static variables/constant objects in function scope.
                 And, this object is separated by an extra file from implementation so that can exchanged more easily.
    Risk:        None.
    Prevention:  None.

  MD_SSA_DECLARED_IN_GENERATED_HEADER:
    Description: MISRA C 2012 Rule 8.4
                 This function has external linkage, but no previous declaration (e.g. in a header file) was found.
    Reason:      False positive. The previous declaration exists in a generated header file which is not taken into
                 account by the analysis tool.
    Risk:        None.
    Prevention:  None.

  MD_SSA_COMPILE_TIME_ASSERTION:
    Description: Rule 2.3
                 Rule 14.3
    Reason:      Dummy type definition causing compile-time assertion if a defined value is not as expected.
    Risk:        None.
    Prevention:  None.

  MD_SSA_REDUNDANT_INITIALIZATION:
    Description: MISRA Rule 2.2
                 This initialization is redundant. The value of this object is never used before being modified.
    Reason:      This initialization is done for avoiding compiler warnings.
    Risk:        None.
    Prevention:  None.

  MD_SSA_P2VOID_CAST:
    Description: MISRA Dir 1.1
    Reason:      The implicit conversion from a pointer to object type to a pointer to void is used calling functions
                 that allow pointers to different object types as parameter.
    Risk:        There is an invalid conversion within the function from a pointer to void to a pointer to object type
                 and thus invalid data are read.
    Prevention:  Code inspection.

  MD_SSA_SHIFT_OPERATION:
    Description: MISRA2012-Rule12.2
    Reason:      The right hand operand of a shift operator shall lie in the range zero to one less than the width
                 in bits of the essential type of the left hand operand.
    Risk:        Useless operation, value can be zero. This is required due to configurable parameter.
    Prevention:  Code inspection.

  MD_SSA_CPYFCT_PTRCAST:
    Reason:     Pointer is casted as different memory access sizes are utilized due to performance reasons.
    Risk:       Wrong pointer access is performed.
    Prevention: Code inspection.

  MD_SSA_BOOLEXPR_ALWAYS_TRUE_OR_ALWAYS_FALSE:
    Description: Rule 13.7
                 Boolean operations whose results are invariant shall not be permitted.
    Reason:      Due to an unconnected port this boolean operation results always in true resp. false.
    Risk:        This code part is not tested.
    Prevention:  Run a test with a configuration with this port being connected.

  MD_SSA_CTRLEXPR_ALWAYS_TRUE_OR_ALWAYS_FALSE:
    Description: Rule 14.3
                 Controlling expressions shall not be invariant.
    Reason:      Due to an unconnected port or depending on a precompile configuration this controlling expression
                 is a constant expression and either always true or always false.
    Risk:        This code part is not tested.
    Prevention:  Run a test with a configuration with this port being connected or where the affected precompile configuration are disabled/enabled.

  MD_SSA_UNREACHABLE_CODE:
    Description: Rule 2.1
                 A project shall not contain unreachable code.
    Reason:      Due to an unconnected port or depending on a precompile configuration a part of the code is not reachable.
    Risk:        This code part is not tested.
                 Compile error/warnings.
    Prevention:  Run a test with a configuration with this port being connected.
                 All code paths are compiled using different test configurations.

  MD_SSA_REDUNDANT_OP:
    Description: MISRA Rule 2.2
                 This operation is redundant. The value of the result is always that of the right/left-hand operand.
    Reason:      This operation is done to simplify code for different variants.
    Risk:        Compile error/warnings.
    Prevention:  Code inspection.

  MD_SSA_REDUNDANT_OP_IN_MACRO:
    Description: MISRA Rule 2.2
                 This operation is redundant. The value of the result is always that of the right/left-hand operand.
    Reason:      The operation is performed inside of a macro. Although it is redundant within the "macro caller"
                 context, removing it might be necessary in other contexts where the macro is used.
    Risk:        None.
    Prevention:  None

  MD_SSA_CFG_8.12_3684:
    Reason:     The unspecific declaration has been used to allow a user defined configuration of the array without having to
                adapt the number of entries afterwards (the actual value will be calculated automatically).
    Risk:       Out-of-bounds access.
    Prevention: Actual number of entries is provided as automatically calculated constant value.

  MD_SSA_SWITCH_FALLTHROUGH:
    Description: Rule 15.2
                 The preceding non-empty 'case' or 'default' clause does not end with an explicit 'break' or 'return' statement.
    Reason:      To use optimal design small switch-case dispatchers use fall-through cases.
    Risk:        None, since documented as an explicit fall-through case.
    Prevention:  None.

  MD_SSA_ADDITIONAL_BREAK:
    Description: Rule 14.6
                 More than one break statement is being used to terminate an iteration statement.
    Reason:      The loop needs multiple exit points since error conditions cannot be verified prior to the loop.
    Risk:        None.
    Prevention:  None.

  MD_SSA_PARAM_NOT_P2CONST:
    Description: Rule 16.7
                 A pointer parameter in a function prototype should be declared as pointer to const if the pointer is not used to
                 modify the addressed object.
    Reason:      The data behind the pointer is modified, or modified in some configurations.
                 The interface cannot be changed because it is defined by AUTOSAR.
    Risk:        None.
    Prevention:  None.

  MD_SSA_LOCAL_FUNCTION_PARAM_NOT_P2CONST:
    Description: Rule 8.13
                 A pointer parameter in a function prototype should be declared as pointer to const if the pointer is not used to
                 modify the addressed object.
    Reason:      The data behind the pointer is modified, or modified in some configurations. The modification is wrapped in
                 a function-like macro.
    Risk:        None.
    Prevention:  None.

  MD_Rte_0624:  MISRA rule: Rule8.3
    Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                The typedefs are never used in the same context.
    Risk:       No functional risk. Only a cast to uint8* is performed.
    Prevention: Not required.

  MD_Rte_3206:  MISRA rule: Rule2.7
    Reason:     The parameter are not used by the code in all possible code variants.
    Risk:       No functional risk.
    Prevention: Not required.

  MD_SSA_MIF_CHECK_CONDITIONS:
    Description: HIS metric
    Reason:      A high number of simple, coherent conditions is checked, which leads to a violation of MIF metric. The control structures
                 within this function are not deeply nested, but the complexity of the function is driven by the number of checks.
                 Subdividing the checks into several functions would result in smaller functions which are incomplete contentwisely.
    Risk:        Code is difficult to maintain.
    Prevention:  Design and code review. Clearly structured and commented code.

  MD_SSA_PTH_CHECK_CONDITIONS:
    Description: PATH metric
    Reason:      A high number of simple, coherent conditions is checked, which leads to a violation of PTH metric. The control structures
                 within this function are not deeply nested, but the complexity of the function is driven by the number of checks.
                 Subdividing the checks into several functions would result in smaller functions which are incomplete contentwisely.
    Risk:        Code is difficult to maintain.
    Prevention:  Design and code review. Clearly structured and commented code.

  MD_SSA_METRIC_SERVICE_DISPATCHER:
    Description: PTH metric
    Reason:      The function Ssa_PrcCtrl_ServiceDispatcher processes a high number of services in a switch-case structure, which
                 therefore covers many cases. Each case consists of the same simple steps, namely updating a return value and calling
                 the respective service function via the RTE. The control structures within this function are not deeply nested,
                 but the complexity of the function is driven by the number of different services covered.
    Risk:        Understandability and testability might become too complex.
    Prevention:  Design and code review. Clearly structured and commented code.

  MD_SSA_CYC_VERIFICATION_RESULT_MAPPING:
    Description: CYC metric
    Reason:      The functions KeyM_ReplaceCertificate_MapCertificateStatusToVerificationResult and  
                 KeyM_SharedSecretDistribution_MapCertificateStatusToVerificationResult map all possible certificate
                 status to the respective verification result. The mapping differs for different certificates and for 
                 different certificate entries. The high metric results from the high number of certificate entries that
                 are handled.
                 Further subdivision of the functions would decrease the metric, but not the complexity of the mapping.
    Risk:        Code is difficult to maintain.
    Prevention:  Design and code review. Clearly structured and commented code.
 */

/***********************************************************************************************************************
 *  SILENTBSW JUSTIFICATIONS
 **********************************************************************************************************************/
/* VCA_JUSTIFICATION_BEGIN

    \ID  VCA_SSA_PROCCTRL_DATALENGTH_AND_SIZEOF_DATABUFFER_PASSED_BY_DCM
      \DESCRIPTION      According to VCA, the following assertion may be violated:
                        DataLength <= sizeof('DcmDataType')
                        where DataLength is the length of bytes to be copied, passed by Dcm
                        and 'Dcm_DataType' is the size of the according buffer to which data is copied, passed by Dcm
      \COUNTERMEASURE   \N As described in the doxygen of the calling function, DataLength is the length in bytes of 
                           the buffer from which data is copied.
                           The size of the input buffer is assured to be sizeof('DcmDataType') by a function specification.

    \ID  VCA_SSA_PROCCTRL_DATALENGTH_CHECKED_BY_RUNTIME_CHECK
      \DESCRIPTION      According to VCA the copy-function is called outside its specification, i.e. the length value
                        is not ensured to be smaller than the size of the destination buffer.
      \COUNTERMEASURE   \R A runtime check ensures that the length of the copied data is not larger
                          than the destination buffer size.

    \ID  VCA_SSA_PROCCTRL_RELATION_DATABUFFER_AND_SIZEOF_DATABUFFER_CHECKED_IN_SPECIFICATION
      \DESCRIPTION      According to VCA, the following assertion may be violated:
                        $lengthOf(ResData) >= ResBufSize;
                        where ResBufSize is the buffer size of the buffer ResData.
      \COUNTERMEASURE   \N This assertion holds, since it is checked in the specification of the function, 
                           and ResBufSize is not modified.
                           The Vca checks this specification at function entry, but is not able to propagate the 
                           requirement into the function.

    \ID  VCA_SSA_PROCCTRL_MAP_S29_OUT_WRITE_ACCESS_DATAOUT
      \DESCRIPTION      According to VCA, the following accesses are possibly out of bounds:
                          - dataOut[2u + len],
                          - dataOut[2u + len + 1u],
                        where len is a local variable in function Ssa_ProcCtrl_MapS29Out().
      \COUNTERMEASURE   \R dataOut is a local pointer variable, referencing the output buffer resData,
                        which is passed to Ssa_ProcCtrl_DiagnosticService_Authentication_0x29_Authenticate.
                        The API contract of this API states that the buffer provided by resData must provide
                        at least ResBufSize many bytes, where ResBufSize is another parameter of the same API.
                        ResBufSize is passed on to Ssa_ProcCtrl_MapS29Out(), where it is called ResDataBufferSize.
                        Before the write access to dataOut, a runtime check ensures that
                          ((len + 6u) < ResDataBufferSize).
                        Thus, the access is valid.

 VCA_JUSTIFICATION_END */

/***********************************************************************************************************************
 *  COVERAGE JUSTIFICATIONS
 **********************************************************************************************************************/
/* COV_JUSTIFICATION_BEGIN

  \ID COV_SSA_DEBUG
    \REASON Debug switches must not be enabled in productive code.
    \PREVENTION Issue report declaring the debug switches as feature with BETA state exists.

  \ID COV_SSA_LOCAL
    \ACCEPT TX
    \REASON Only ensures that LOCAL is always set.
    \PREVENTION Covered by code review

  \ID COV_SSA_LOCAL_INLINE
    \ACCEPT TX
    \REASON Only ensures that LOCAL_INLINE is always set.
    \PREVENTION Covered by code review

  \ID COV_SSA_MEMCPY
    \ACCEPT TX
    \REASON Only ensures that MEMCPY is always set.
    \PREVENTION Covered by code review

  \ID COV_SSA_MISRA
    \ACCEPT XX
    \REASON [MSR_COV_MISRA]

  \ID COV_SSA_OVERWRITEABLE
    \REASON This parameter is normally defined by SSA. For some Reasons, it can be necessary to configure this parameter to a different value.

  \ID COV_SSA_CDD_EXCLUSIVE_AREA_OVERWRITABLE
    \REASON These exclusive area enter/exit calls are normally defined by SSA. For some reasons, it can be necessary
            to configure them to a user-defined resource locking method.
    \PREVENTION Covered by code review

  \ID COV_SSA_VECTOR_CODE_ANALYZER_STUB_REDIRECTION
    \ACCEPT TX
    \REASON     VCA uses stubs to approximate other modules' parameter requirements and side effects.
                This is done to contain VCA execution times to a reasonable range.
                This ifdef encapsulates an #include directive for a header file that redefines all interfaces to other modules and components
                to their respective VCA stub implementations.
                The inclusion of the header files is irrelevant for preprocessor coverage analysis (performed by VCA).
    \PREVENTION The correctness of the stubs' assumed requirements and side effects is covered by code review (stubs are subject to review).

  \ID COV_SSA_VECTOR_CODE_ANALYZER_ASSIGNMENT_OF_STRUCT_VARIABLE
    \ACCEPT TX
    \REASON     In the used version, VCA cannot evaluate variables that are multiply nested.
                By assinging such variables nested in a struct to a new variable, vca can evaluate it.
                This additional assignment is irrelevant for preprocessor coverage analysis (performed by VCA).
    \PREVENTION The correctness of the assignment is covered by code review.

  \ID COV_SSA_PROC_CTRL_BUFFER_HANDLING
    \ACCEPT TX
    \ACCEPT XF
    \REASON      SafeBSW requires SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING to be always STD_ON.
    \PREVENTION  The module's MSSV plugin enforces this configuration.

  \ID COV_SSA_SECLOG_CIRCULAR_BUFFER_LENGTH_CONFIGURATION
    \ACCEPT TX
    \ACCEPT XF
    \ACCEPT TX tf tx
    \ACCEPT TF tf xf
    \REASON      The result of the check depends on the configured length of the circular buffer, which stores the logging data for an event.
                 If the buffer length is positive, the result is always TX (tx), if the buffer length is zero, the result is always XF (xf).
                 It is necessary to distinguish these cases in order to avoid unnecessary NvM write requests.

  \ID COV_SSA_KEYM_UNIQUE_ECU_ID_LENGTH_CHECK
    \ACCEPT TX
    \ACCEPT XF
    \REASON      The check under consideration compares the read length of a configured unique ECU ID with the upper bound of
                 SSA_MAX_SIZEOF_UNIQUEECUID (30) bytes. A generator validation ensures that no unique ECU ID of more than 30
                 bytes is configured.
                 Consequently, all checks following the successful length check, are successful, too:
                   - KeyM_GetNumBytesNeededForEncodingUniqueEcuIds() never sets retVal = E_NOT_OK,
                   - KeyM_GetNumBytesNeededForEncodingUniqueEcuIds() always returns E_OK and
                   - KeyM_EncodeUniqueEcuIds() always returns E_OK.
                 The check is required for the Silent Analysis, which must not depend on configured values. Thus, a runtime
                 check was introduced.

  \ID COV_TIMEM_OPMODE_INACTIVE
    \ACCEPT TX
    \REASON      Condition can never be false for GW configurations because Rte_Mode_Ssa_TimeM_OperationMode_Mode
                 is always active. Code generator defines Rte_Mode_Ssa_TimeM_OperationMode_Mode as
                 RTE_MODE_Ssa_OperationMode_SSA_ACTIVE in GW configurations, which makes the expression equal
                 to "if (0==0)".

COV_JUSTIFICATION_END */


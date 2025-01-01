/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Ssa
 *           Program: MSR_Daimler_SLP11
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: TC3xx
 *    License Scope : The usage is restricted to CBD2200333_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Ssa_Cfg.h
 *   Generation Time: 2023-09-25 13:39:35
 *           Project: StartApplication - Version 1.0
 *          Delivery: CBD2200333_D05
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (SSA_CFG_H)
#define SSA_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Ssa_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef SSA_USE_DUMMY_STATEMENT
#define SSA_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SSA_DUMMY_STATEMENT
#define SSA_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SSA_DUMMY_STATEMENT_CONST
#define SSA_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef SSA_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define SSA_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef SSA_ATOMIC_VARIABLE_ACCESS
#define SSA_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef SSA_PROCESSOR_TC322L
#define SSA_PROCESSOR_TC322L
#endif
#ifndef SSA_COMP_TASKING
#define SSA_COMP_TASKING
#endif
#ifndef SSA_GEN_GENERATOR_MSR
#define SSA_GEN_GENERATOR_MSR
#endif
#ifndef SSA_CPUTYPE_BITORDER_LSB2MSB
#define SSA_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef SSA_CONFIGURATION_VARIANT_PRECOMPILE
#define SSA_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef SSA_CONFIGURATION_VARIANT_LINKTIME
#define SSA_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef SSA_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define SSA_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef SSA_CONFIGURATION_VARIANT
#define SSA_CONFIGURATION_VARIANT SSA_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef SSA_POSTBUILD_VARIANT_SUPPORT
#define SSA_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define SSA_TRUST_MODEL_ECU_CERT_ID                                                                 2u
#define SSA_TRUST_MODEL_INTERMEDIATE_CERT_ID                                                        5u
#define SSA_TRUST_MODEL_BACKEND_CERT_ID                                                             0u
#define SSA_TRUST_MODEL_ROOT_CERT_ID                                                                7u
#define SSA_TRUST_MODEL_ECU_PEER_CERT_ID                                                            4u
#define SSA_TRUST_MODEL_INTERMEDIATE_PEER_CERT_ID                                                   6u
#define SSA_TRUST_MODEL_BACKEND_PEER_CERT_ID                                                        1u
#define SSA_TRUST_MODEL_ECU_CSR_CERT_ID                                                             3u
/* Microsar Define Block for Boolean and Integers */
#define SSA_ENABLE_DEBUG_AUTHENTICATION                                                             STD_OFF 
#define SSA_ENABLE_DEBUG_RIGHTS                                                                     STD_OFF 
#define SSA_ENABLE_DEBUG_NONCE                                                                      STD_OFF 
#define SSA_IGNORE_SECURE_BROADCAST_VERIFICATION_RESULT                                             STD_OFF 
#define SSA_ENABLE_DEBUG_AUTHENTICATION_STATUS                                                      STD_OFF 
#define SSA_IGNORE_CODING_VERIFICATION_RESULT                                                       STD_OFF 
#define SSA_ENABLE_ASYNC_CSM_JOB_PROCESSING                                                         STD_OFF 
#define SSA_ENABLE_ASYNC_CSM_KEYM_ANAGEMENT_PRIMITIVES                                              STD_OFF 
#define SSA_KEEP_BUFFER_VARIABLES_STATIC                                                            STD_OFF 
#define SSA_DIAG_SERVICE_INJECT_SEED                                                                STD_OFF 
#define SSA_DIAG_SERVICE_TRUST_MODEL_GENERATE_KEY_PAIR                                              STD_ON 
#define SSA_DECOUPLE_EXTERNAL_PROCESSING_SERVICE29                                                  STD_ON 
#define SSA_GENERATE_KEY_PAIR_CUSTOM_CALLOUT                                                        STD_OFF 
#define SSA_DEV_ERROR_DETECT                                                                        STD_OFF 
#define SSA_CODING_TIMEOUT                                                                          20000u 
#define SSA_CODING_VINRECEIVE_TIMEOUT                                                               5000u 
#define SSA_CODING_DATA_BUFFER_SIZE                                                                 1081u 
#define SSA_FVM_UNLIMITED_TURNING_BACK_OF_TICK_COUNT                                                STD_OFF 
#define SSA_FVM_PERCENTAGE_TURNING_BACK_LOCAL_TICK_COUNT                                            40u 
#define SSA_FVM_PERCENTAGE_LOCAL_TICK_COUNT_SLOWDOWN                                                2u 
#define SSA_FVM_RTC_CORRECTION_TOLERANCE                                                            0u 
#define SSA_FVM_RTC_RESOLUTION                                                                      1000u 
#define SSA_FVM_SECURED_TICK_COUNT_CYCLE_TIME                                                       100u 
#define SSA_FVM_SECURED_TICK_COUNT_STARTUP_CYCLE_TIME                                               100u 
#define SSA_FVM_SECURED_TICK_COUNT_STARTUP_CYCLE_DURATION                                           1000u 
#define SSA_FVM_DEBOUNCE_TIME_DETECTION_UNAUTHETICATED_TICK_COUNT_MESSAGES                          3000u 
#define SSA_FVM_DEBOUNCE_TIME_DETECTION_MISSING_TICK_COUNT_MESSAGES                                 3000u 
#define SSA_FVM_DEBOUNCE_TIME_DETECTION_REJECTED_TICK_COUNT_MESSAGES                                3000u 
#define SSA_FVM_LOCAL_TICK_COUNT_SYNCHRONIZATION_TIMEOUT                                            3000u 
#define SSA_SECLOG_CIRCULAR_BUFFER_SIZE_FAILED_CERTIFICATE_VERIFICATION_EVENT                       20u 
#define SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_CERTIFICATE_VERIFICATION_EVENT                   10u 
#define SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS_EVENT          15u 
#define SSA_SECLOG_CIRCULAR_BUFFER_SIZE_AUTHORIZATION_BY_SECURITY_ACCESS_EVENT                      7u 
#define SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION_EVENT               15u 
#define SSA_SECLOG_CIRCULAR_BUFFER_SIZE_RIGHTSM_ANAGEMENT_EVENT                                     20u 
#define SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SIGNATURE_VERIFICATION_EVENT                                10u 
#define SSA_SECLOG_CIRCULAR_BUFFER_SIZE_CHANGE_OF_TICK_COUNT_OR_DATE_AND_TIME_EVENT                 20u 
#define SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SECOC_MISCONFIGURATION_EVENT                                10u 
#define SSA_SECLOG_CIRCULAR_BUFFER_SIZE_FAILED_PDU_MAC_VERIFICATION_EVENT                           15u 
#define SSA_SECLOG_CIRCULAR_BUFFER_SIZE_SECURE_BOOT_OR_AUTHENTICATED_BOOT_EVENT                     10u 
#define SSA_SECLOG_CIRCULAR_BUFFER_SIZE_CHANGE_OF_VIN_EVENT                                         3u 
#define SSA_SECLOG_CIRCULAR_BUFFER_SIZE_ECU_INDIVIDUAL_ACL_REPLACEMENT_EVENT                        5u 
#define SSA_SECLOG_FAILED_MAC_VERIFICATION_COUNTER_THRESHOLD_DTC                                    100u 
#define SSA_SECLOG_LOGGING_ACTIVE_TIMEOUT                                                           180u 
#define SSA_SECLOG_FAILED_MAC_VERIFICATION_COUNTER_THRESHOLD1                                       250u 
#define SSA_SECLOG_FAILED_MAC_VERIFICATION_COUNTER_THRESHOLD2                                       1000u 
#define SSA_SECLOG_FAILED_MAC_VERIFICATION_COUNTER_THRESHOLD3                                       50000u 
#define SSA_SECLOG_USE_PIM_ACCESS_MACROS_AS_COMPILE_TIME_CONSTANTS                                  STD_ON 
#define SSA_RIGHTSM_ENHANCED_ACCESS_RIGHTS_TABLE_SIZE                                               300u 
#define SSA_RIGHTSM_POST_PRODUCTION_STATUS_ACTIVATION_MILEAGE_THRESHOLD                             100000u 
#define SSA_RIGHTSM_MAX_DID_LIST_LENGTH                                                             30u 
#define SSA_KEYM_NUMBER_KEYS_GENERATED_IN_MAIN                                                      65535u 
#define SSA_KEYM_NUMBER_RETRIES_KEY_GENERATION                                                      0u 
#define SSA_KEYM_NUMBER_WAIT_CYCLES_BEFORE_KEY_GENERATION                                           0u 
#define SSA_PROC_CTRL_ENABLE_BUFFER_HANDLING                                                        STD_ON 

#define SSA_ECU_TYPE_GATEWAY                                                                        0x00u 
#define SSA_ECU_TYPE_NORMAL                                                                         0x01u 
#define SSA_ECU_TYPE_VSM                                                                            0x02u 


#define SSA_ECU_TYPE                                                                                SSA_ECU_TYPE_NORMAL
#define SSA_TOTAL_NUMBER_OF_DATA_IDS                                                                7u
#define SSA_KEYM_CSM_KEY_EXCHANGE_KEY                                                               46u
#define SSA_KEYM_CSM_PDU_KEYS_MAC_KEY                                                               40u
#define SSA_KEYM_CSM_KEY_TRUST_MODEL_ECU_LIVE_PRIVATE_KEY                                           13u
#define SSA_KEYM_CSM_KEY_TRUST_MODEL_ECU_STAGING_PRIVATE_KEY                                        11u
#define SSA_KEYM_CSM_KEY_TRUST_MODEL_ECU_STAGING_PUBLIC_KEY                                         8u
#define SSA_KEYM_CSM_KEY_TRUST_MODEL_ECU_CSR_PRIVATE_KEY                                            15u
#define SSA_KEYM_CSM_KEY_TRUST_MODEL_ECU_CSR_PUBLIC_KEY                                             16u
#define SSA_KEYM_CSM_KEY_DIAG_CHAIN_BACKEND_CERT                                                    39u
#define SSA_KEYM_CSM_KEY_DIAG_CHAIN_ROOT_CERT                                                       43u
#define SSA_TRUST_MODEL_ECU_CSR_CERTIFICATE_ELEMENT_COMMON_NAME                                     6u
#define SSA_TRUST_MODEL_ECU_CSR_CERTIFICATE_ELEMENT_UNIQUE_ECU_ID                                   17u
#define SSA_TRUST_MODEL_ECU_CSR_CERTIFICATE_ELEMENT_SPECIAL_ECU                                     18u
#define SSA_SECLOG_DEBOUNCE_TIME                                                                    300u
#define SSA_SECLOG_NVRAM_CTRL_DATA_SIZE                                                             8u
#define SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS                                                           7u
#define SSA_SECLOG_NUMBER_OF_EVENTS                                                                 13u
#define SSA_SECLOG_NUM_NVM_BLOCKS                                                                   16u
#define SSA_SECLOG_NUMBER_OF_UNIQUE_ECU_IDS                                                         2u
#define SSA_SECLOG_LENGTH_OF_ALL_UNIQUE_ECU_IDS                                                     18u

/* SecLog Size Global Counters.*/
#define SSA_SECLOG_SIZE_GLOBCOUNT_1                                                                 8u
#define SSA_SECLOG_SIZE_GLOBCOUNT_2                                                                 6u
#define SSA_SECLOG_SIZE_GLOBCOUNT_3                                                                 8u
#define SSA_SECLOG_SIZE_GLOBCOUNT_4                                                                 4u
#define SSA_SECLOG_SIZE_GLOBCOUNT_5                                                                 10u
#define SSA_SECLOG_SIZE_GLOBCOUNT_6                                                                 8u
#define SSA_SECLOG_SIZE_GLOBCOUNT_7                                                                 6u
#define SSA_SECLOG_SIZE_GLOBCOUNT_8                                                                 4u
#define SSA_SECLOG_SIZE_GLOBCOUNT_9                                                                 4u
#define SSA_SECLOG_SIZE_GLOBCOUNT_10                                                                0u
#define SSA_SECLOG_SIZE_GLOBCOUNT_11                                                                1u
#define SSA_SECLOG_SIZE_GLOBCOUNT_12                                                                2u
#define SSA_SECLOG_SIZE_GLOBCOUNT_13                                                                2u
#define SSA_SECLOG_SIZE_GLOBCOUNT_14                                                                14u
#define SSA_SECLOG_SIZE_GLOBCOUNT_15                                                                14u
#define SSA_SECLOG_SIZE_GLOBCOUNT_16                                                                14u

/* SecLog Size Event 0-12 (must be >= 5).*/
#define SSA_SECLOG_SIZE_EVNT_1                                                                      8u
#define SSA_SECLOG_SIZE_EVNT_2                                                                      23u
#define SSA_SECLOG_SIZE_EVNT_3                                                                      25u
#define SSA_SECLOG_SIZE_EVNT_4                                                                      8u
#define SSA_SECLOG_SIZE_EVNT_5                                                                      8u
#define SSA_SECLOG_SIZE_EVNT_6                                                                      10u
#define SSA_SECLOG_SIZE_EVNT_7                                                                      8u
#define SSA_SECLOG_SIZE_EVNT_8                                                                      11u
#define SSA_SECLOG_SIZE_EVNT_9                                                                      5u
#define SSA_SECLOG_SIZE_EVNT_10                                                                     8u
#define SSA_SECLOG_SIZE_EVNT_11                                                                     5u
#define SSA_SECLOG_SIZE_EVNT_12                                                                     22u
#define SSA_SECLOG_SIZE_EVNT_13                                                                     17u

#define SSA_CODING_SIGNATURE_VERIFY_JOB_ID                                                          37u
#define SSA_RIGHTSM_HASH_JOB_ID                                                                     26u
#define SSA_RIGHTSM_SIGNATURE_VERIFY_JOB_ID                                                         39u
#define SSA_KEYM_TRUST_MODEL_ECU_CSR_SIGNATURE_GENERATE_JOB_ID                                      1u
#define SSA_KEYM_TRUST_MODEL_ECU_LIVE_SIGNATURE_GENERATE_JOB_ID                                     34u
#define SSA_KEYM_SIGNATURE_VERIFY_JOB_ID                                                            39u
#define SSA_KEYM_SIGNATURE_VERIFY_REPLACMENT_AUTHORITY_JOB_ID                                       41u
#define SSA_KEYM_TRUST_MODEL_BACKEND_SIGNATURE_VERIFY_JOB_ID                                        2u
#define SSA_KEYM_TRUST_MODEL_TEMP_SIGNATURE_VERIFY_JOB_ID                                           24u
#define SSA_KEYM_HASH_JOB_ID                                                                        26u
#define SSA_CERTP_SIGNATURE_VERIFY_JOB_ID                                                           39u
#define SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS                                                      4u
#define SSA_RIGHTSM_NUMBER_SECURITY_ACCESS_LEVELS                                                   4u
#define SSA_RightsM_EcuIndividualAccessControlList()                                                Ssa_RightsM_EcuIndividualAcl

#define SSA_SECOC_IGNORE_VERIFICATION_RESULT                                                        STD_OFF


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  SsaPCDataSwitches  Ssa Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define SSA_CIRCULARBUFFERSIZEAUTHORIZATIONBYSECURITYACCESSEVENTOFSECLOG                            STD_ON
#define SSA_CIRCULARBUFFERSIZECHANGEOFTICKCOUNTORDATEANDTIMEEVENTOFSECLOG                           STD_ON
#define SSA_CIRCULARBUFFERSIZECHANGEOFVINEVENTOFSECLOG                                              STD_ON
#define SSA_CIRCULARBUFFERSIZEECUINDIVIDUALACLREPLACEMENTEVENTOFSECLOG                              STD_ON
#define SSA_CIRCULARBUFFERSIZEFAILEDCERTIFICATEVERIFICATIONEVENTOFSECLOG                            STD_ON
#define SSA_CIRCULARBUFFERSIZEFAILEDPDUMACVERIFICATIONEVENTOFSECLOG                                 STD_ON
#define SSA_CIRCULARBUFFERSIZERIGHTSMANAGEMENTEVENTOFSECLOG                                         STD_ON
#define SSA_CIRCULARBUFFERSIZESECOCMISCONFIGURATIONEVENTOFSECLOG                                    STD_ON
#define SSA_CIRCULARBUFFERSIZESECUREBOOTORAUTHENTICATEDBOOTEVENTOFSECLOG                            STD_ON
#define SSA_CIRCULARBUFFERSIZESIGNATUREVERIFICATIONEVENTOFSECLOG                                    STD_ON
#define SSA_CIRCULARBUFFERSIZESUCCESSFULAUTHENTICATIONANDENHANCERIGHTSEVENTOFSECLOG                 STD_ON
#define SSA_CIRCULARBUFFERSIZESUCCESSFULCERTIFICATEVERIFICATIONEVENTOFSECLOG                        STD_ON
#define SSA_CIRCULARBUFFERSIZESUCCESSFULDIAGNOSTICSERVICEEXECUTIONEVENTOFSECLOG                     STD_ON
#define SSA_CODINGDID                                                                               STD_ON
#define SSA_CODINGNVMBLOCK                                                                          STD_ON
#define SSA_DEV_ERROR_DETECTOFGENERAL                                                               STD_ON
#define SSA_DATABUFFERSIZEOFCODING                                                                  STD_ON
#define SSA_DATAIDINFO                                                                              STD_ON
#define SSA_DATAIDOFDATAIDINFO                                                                      STD_ON
#define SSA_KEYIDOFDATAIDINFO                                                                       STD_ON
#define SSA_THRESHOLDOFDATAIDINFO                                                                   STD_ON
#define SSA_DEBOUNCETIMEDETECTIONMISSINGTICKCOUNTMESSAGESOFFVM                                      STD_ON
#define SSA_DEBOUNCETIMEDETECTIONREJECTEDTICKCOUNTMESSAGESOFFVM                                     STD_ON
#define SSA_DEBOUNCETIMEDETECTIONUNAUTHETICATEDTICKCOUNTMESSAGESOFFVM                               STD_ON
#define SSA_DECOUPLEEXTERNALPROCESSINGSERVICE29OFGENERAL                                            STD_ON
#define SSA_DIAGSERVICEINJECTSEEDOFGENERAL                                                          STD_ON
#define SSA_DIAGSERVICETRUSTMODELGENERATEKEYPAIROFGENERAL                                           STD_ON
#define SSA_DIDHANDLED                                                                              STD_ON
#define SSA_ECUINDIVIDUALACLPTRNAMEOFRIGHTSM                                                        STD_ON
#define SSA_ECUTYPEOFGENERAL                                                                        STD_ON
#define SSA_ENABLEASYNCCSMJOBPROCESSINGOFGENERAL                                                    STD_ON
#define SSA_ENABLEASYNCCSMKEYMANAGEMENTPRIMITIVESOFGENERAL                                          STD_ON
#define SSA_ENABLEBUFFERHANDLINGOFPROCCTRL                                                          STD_ON
#define SSA_ENABLEDEBUGAUTHENTICATIONOFGENERAL                                                      STD_ON
#define SSA_ENABLEDEBUGAUTHENTICATIONSTATUSOFGENERAL                                                STD_ON
#define SSA_ENABLEDEBUGNONCEOFGENERAL                                                               STD_ON
#define SSA_ENABLEDEBUGRIGHTSOFGENERAL                                                              STD_ON
#define SSA_ENHANCEDACCESSRIGHTSTABLESIZEOFRIGHTSM                                                  STD_ON
#define SSA_EXPECTEDCOMPATIBILITYVERSION                                                            STD_OFF  /**< Deactivateable: 'Ssa_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define SSA_FAILEDMACVERIFICATIONCOUNTERTHRESHOLD1OFSECLOG                                          STD_ON
#define SSA_FAILEDMACVERIFICATIONCOUNTERTHRESHOLD2OFSECLOG                                          STD_ON
#define SSA_FAILEDMACVERIFICATIONCOUNTERTHRESHOLD3OFSECLOG                                          STD_ON
#define SSA_FAILEDMACVERIFICATIONCOUNTERTHRESHOLDDTCOFSECLOG                                        STD_ON
#define SSA_FINALMAGICNUMBER                                                                        STD_OFF  /**< Deactivateable: 'Ssa_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define SSA_GENERATEKEYPAIRCUSTOMCALLOUTOFGENERAL                                                   STD_ON
#define SSA_GENERATORCOMPATIBILITYVERSION                                                           STD_OFF  /**< Deactivateable: 'Ssa_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define SSA_IGNORECODINGVERIFICATIONRESULTOFGENERAL                                                 STD_ON
#define SSA_IGNORESECUREBROADCASTVERIFICATIONRESULTOFGENERAL                                        STD_ON
#define SSA_INITDATAHASHCODE                                                                        STD_OFF  /**< Deactivateable: 'Ssa_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define SSA_KEEPBUFFERVARIABLESSTATICOFGENERAL                                                      STD_ON
#define SSA_LOCALTICKCOUNTSYNCHRONIZATIONTIMEOUTOFFVM                                               STD_ON
#define SSA_LOGGINGACTIVETIMEOUTOFSECLOG                                                            STD_ON
#define SSA_MAXDIDLISTLENGTHOFRIGHTSM                                                               STD_ON
#define SSA_NUMBERKEYSGENERATEDINMAINOFKEYM                                                         STD_ON
#define SSA_NUMBERRETRIESKEYGENERATIONOFKEYM                                                        STD_ON
#define SSA_NUMBERWAITCYCLESBEFOREKEYGENERATIONOFKEYM                                               STD_ON
#define SSA_PERCENTAGELOCALTICKCOUNTSLOWDOWNOFFVM                                                   STD_ON
#define SSA_PERCENTAGETURNINGBACKLOCALTICKCOUNTOFFVM                                                STD_ON
#define SSA_POSTPRODUCTIONSTATUSACTIVATIONMILEAGETHRESHOLDOFRIGHTSM                                 STD_ON
#define SSA_RIGHTSM_TESTERTOCHANNEL                                                                 STD_ON
#define SSA_RTCCORRECTIONTOLERANCEOFFVM                                                             STD_ON
#define SSA_RTCRESOLUTIONOFFVM                                                                      STD_ON
#define SSA_SECLOGINFO                                                                              STD_ON
#define SSA_DATAIDINFOIDXOFSECLOGINFO                                                               STD_ON
#define SSA_SECUREDTICKCOUNTCYCLETIMEOFFVM                                                          STD_ON
#define SSA_SECUREDTICKCOUNTSTARTUPCYCLEDURATIONOFFVM                                               STD_ON
#define SSA_SECUREDTICKCOUNTSTARTUPCYCLETIMEOFFVM                                                   STD_ON
#define SSA_SECURITYACCESSLEVEL                                                                     STD_ON
#define SSA_JOBIDOFSECURITYACCESSLEVEL                                                              STD_ON
#define SSA_LEVELOFSECURITYACCESSLEVEL                                                              STD_ON
#define SSA_SIZEOFCODINGDID                                                                         STD_ON
#define SSA_SIZEOFCODINGNVMBLOCK                                                                    STD_ON
#define SSA_SIZEOFDATAIDINFO                                                                        STD_ON
#define SSA_SIZEOFDIDHANDLED                                                                        STD_ON
#define SSA_SIZEOFRIGHTSM_TESTERTOCHANNEL                                                           STD_ON
#define SSA_SIZEOFSECLOGINFO                                                                        STD_ON
#define SSA_SIZEOFSECURITYACCESSLEVEL                                                               STD_ON
#define SSA_SIZEOFTRUSTMODELBACKENDCERTNAME                                                         STD_ON
#define SSA_SIZEOFTRUSTMODELBACKENDPEERCERTNAME                                                     STD_ON
#define SSA_SIZEOFTRUSTMODELECUCERTNAME                                                             STD_ON
#define SSA_SIZEOFTRUSTMODELECUCSRCERTNAME                                                          STD_ON
#define SSA_SIZEOFTRUSTMODELECUPEERCERTNAME                                                         STD_ON
#define SSA_SIZEOFTRUSTMODELINTERMEDIATECERTNAME                                                    STD_ON
#define SSA_SIZEOFTRUSTMODELINTERMEDIATEPEERCERTNAME                                                STD_ON
#define SSA_SIZEOFTRUSTMODELROOTCERTNAME                                                            STD_ON
#define SSA_SIZEOFUNIQUEECUID                                                                       STD_ON
#define SSA_SIZEOFUNIQUEECUIDS                                                                      STD_ON
#define SSA_TIMEOUTOFCODING                                                                         STD_ON
#define SSA_TRUSTMODELBACKENDCERTNAME                                                               STD_ON
#define SSA_TRUSTMODELBACKENDPEERCERTNAME                                                           STD_ON
#define SSA_TRUSTMODELECUCERTNAME                                                                   STD_ON
#define SSA_TRUSTMODELECUCSRCERTNAME                                                                STD_ON
#define SSA_TRUSTMODELECUCSRREFOFKEYM                                                               STD_ON
#define SSA_TRUSTMODELECUPEERCERTNAME                                                               STD_ON
#define SSA_TRUSTMODELINTERMEDIATECERTNAME                                                          STD_ON
#define SSA_TRUSTMODELINTERMEDIATEPEERCERTNAME                                                      STD_ON
#define SSA_TRUSTMODELROOTCERTNAME                                                                  STD_ON
#define SSA_UNIQUEECUID                                                                             STD_ON
#define SSA_UNIQUEECUIDSUNIQUEECUIDSENDIDXOFUNIQUEECUID                                             STD_ON
#define SSA_UNIQUEECUIDSUNIQUEECUIDSSTARTIDXOFUNIQUEECUID                                           STD_ON
#define SSA_UNIQUEECUIDS                                                                            STD_ON
#define SSA_UNLIMITEDTURNINGBACKOFTICKCOUNTOFFVM                                                    STD_ON
#define SSA_USEPIMACCESSMACROSASCOMPILETIMECONSTANTSOFSECLOG                                        STD_ON
#define SSA_VINRECEIVETIMEOUTOFCODING                                                               STD_ON
#define SSA_PCCONFIG                                                                                STD_ON
#define SSA_CIRCULARBUFFERSIZEAUTHORIZATIONBYSECURITYACCESSEVENTOFSECLOGOFPCCONFIG                  STD_ON
#define SSA_CIRCULARBUFFERSIZECHANGEOFTICKCOUNTORDATEANDTIMEEVENTOFSECLOGOFPCCONFIG                 STD_ON
#define SSA_CIRCULARBUFFERSIZECHANGEOFVINEVENTOFSECLOGOFPCCONFIG                                    STD_ON
#define SSA_CIRCULARBUFFERSIZEECUINDIVIDUALACLREPLACEMENTEVENTOFSECLOGOFPCCONFIG                    STD_ON
#define SSA_CIRCULARBUFFERSIZEFAILEDCERTIFICATEVERIFICATIONEVENTOFSECLOGOFPCCONFIG                  STD_ON
#define SSA_CIRCULARBUFFERSIZEFAILEDPDUMACVERIFICATIONEVENTOFSECLOGOFPCCONFIG                       STD_ON
#define SSA_CIRCULARBUFFERSIZERIGHTSMANAGEMENTEVENTOFSECLOGOFPCCONFIG                               STD_ON
#define SSA_CIRCULARBUFFERSIZESECOCMISCONFIGURATIONEVENTOFSECLOGOFPCCONFIG                          STD_ON
#define SSA_CIRCULARBUFFERSIZESECUREBOOTORAUTHENTICATEDBOOTEVENTOFSECLOGOFPCCONFIG                  STD_ON
#define SSA_CIRCULARBUFFERSIZESIGNATUREVERIFICATIONEVENTOFSECLOGOFPCCONFIG                          STD_ON
#define SSA_CIRCULARBUFFERSIZESUCCESSFULAUTHENTICATIONANDENHANCERIGHTSEVENTOFSECLOGOFPCCONFIG       STD_ON
#define SSA_CIRCULARBUFFERSIZESUCCESSFULCERTIFICATEVERIFICATIONEVENTOFSECLOGOFPCCONFIG              STD_ON
#define SSA_CIRCULARBUFFERSIZESUCCESSFULDIAGNOSTICSERVICEEXECUTIONEVENTOFSECLOGOFPCCONFIG           STD_ON
#define SSA_CODINGDIDOFPCCONFIG                                                                     STD_ON
#define SSA_CODINGNVMBLOCKOFPCCONFIG                                                                STD_ON
#define SSA_DEV_ERROR_DETECTOFGENERALOFPCCONFIG                                                     STD_ON
#define SSA_DATABUFFERSIZEOFCODINGOFPCCONFIG                                                        STD_ON
#define SSA_DATAIDINFOOFPCCONFIG                                                                    STD_ON
#define SSA_DEBOUNCETIMEDETECTIONMISSINGTICKCOUNTMESSAGESOFFVMOFPCCONFIG                            STD_ON
#define SSA_DEBOUNCETIMEDETECTIONREJECTEDTICKCOUNTMESSAGESOFFVMOFPCCONFIG                           STD_ON
#define SSA_DEBOUNCETIMEDETECTIONUNAUTHETICATEDTICKCOUNTMESSAGESOFFVMOFPCCONFIG                     STD_ON
#define SSA_DECOUPLEEXTERNALPROCESSINGSERVICE29OFGENERALOFPCCONFIG                                  STD_ON
#define SSA_DIAGSERVICEINJECTSEEDOFGENERALOFPCCONFIG                                                STD_ON
#define SSA_DIAGSERVICETRUSTMODELGENERATEKEYPAIROFGENERALOFPCCONFIG                                 STD_ON
#define SSA_DIDHANDLEDOFPCCONFIG                                                                    STD_ON
#define SSA_ECUINDIVIDUALACLPTRNAMEOFRIGHTSMOFPCCONFIG                                              STD_ON
#define SSA_ECUTYPEOFGENERALOFPCCONFIG                                                              STD_ON
#define SSA_ENABLEASYNCCSMJOBPROCESSINGOFGENERALOFPCCONFIG                                          STD_ON
#define SSA_ENABLEASYNCCSMKEYMANAGEMENTPRIMITIVESOFGENERALOFPCCONFIG                                STD_ON
#define SSA_ENABLEBUFFERHANDLINGOFPROCCTRLOFPCCONFIG                                                STD_ON
#define SSA_ENABLEDEBUGAUTHENTICATIONOFGENERALOFPCCONFIG                                            STD_ON
#define SSA_ENABLEDEBUGAUTHENTICATIONSTATUSOFGENERALOFPCCONFIG                                      STD_ON
#define SSA_ENABLEDEBUGNONCEOFGENERALOFPCCONFIG                                                     STD_ON
#define SSA_ENABLEDEBUGRIGHTSOFGENERALOFPCCONFIG                                                    STD_ON
#define SSA_ENHANCEDACCESSRIGHTSTABLESIZEOFRIGHTSMOFPCCONFIG                                        STD_ON
#define SSA_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                                  STD_OFF  /**< Deactivateable: 'Ssa_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define SSA_FAILEDMACVERIFICATIONCOUNTERTHRESHOLD1OFSECLOGOFPCCONFIG                                STD_ON
#define SSA_FAILEDMACVERIFICATIONCOUNTERTHRESHOLD2OFSECLOGOFPCCONFIG                                STD_ON
#define SSA_FAILEDMACVERIFICATIONCOUNTERTHRESHOLD3OFSECLOGOFPCCONFIG                                STD_ON
#define SSA_FAILEDMACVERIFICATIONCOUNTERTHRESHOLDDTCOFSECLOGOFPCCONFIG                              STD_ON
#define SSA_FINALMAGICNUMBEROFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Ssa_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define SSA_GENERATEKEYPAIRCUSTOMCALLOUTOFGENERALOFPCCONFIG                                         STD_ON
#define SSA_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'Ssa_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define SSA_IGNORECODINGVERIFICATIONRESULTOFGENERALOFPCCONFIG                                       STD_ON
#define SSA_IGNORESECUREBROADCASTVERIFICATIONRESULTOFGENERALOFPCCONFIG                              STD_ON
#define SSA_INITDATAHASHCODEOFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Ssa_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define SSA_KEEPBUFFERVARIABLESSTATICOFGENERALOFPCCONFIG                                            STD_ON
#define SSA_LOCALTICKCOUNTSYNCHRONIZATIONTIMEOUTOFFVMOFPCCONFIG                                     STD_ON
#define SSA_LOGGINGACTIVETIMEOUTOFSECLOGOFPCCONFIG                                                  STD_ON
#define SSA_MAXDIDLISTLENGTHOFRIGHTSMOFPCCONFIG                                                     STD_ON
#define SSA_NUMBERKEYSGENERATEDINMAINOFKEYMOFPCCONFIG                                               STD_ON
#define SSA_NUMBERRETRIESKEYGENERATIONOFKEYMOFPCCONFIG                                              STD_ON
#define SSA_NUMBERWAITCYCLESBEFOREKEYGENERATIONOFKEYMOFPCCONFIG                                     STD_ON
#define SSA_PERCENTAGELOCALTICKCOUNTSLOWDOWNOFFVMOFPCCONFIG                                         STD_ON
#define SSA_PERCENTAGETURNINGBACKLOCALTICKCOUNTOFFVMOFPCCONFIG                                      STD_ON
#define SSA_POSTPRODUCTIONSTATUSACTIVATIONMILEAGETHRESHOLDOFRIGHTSMOFPCCONFIG                       STD_ON
#define SSA_RIGHTSM_TESTERTOCHANNELOFPCCONFIG                                                       STD_ON
#define SSA_RTCCORRECTIONTOLERANCEOFFVMOFPCCONFIG                                                   STD_ON
#define SSA_RTCRESOLUTIONOFFVMOFPCCONFIG                                                            STD_ON
#define SSA_SECLOGINFOOFPCCONFIG                                                                    STD_ON
#define SSA_SECUREDTICKCOUNTCYCLETIMEOFFVMOFPCCONFIG                                                STD_ON
#define SSA_SECUREDTICKCOUNTSTARTUPCYCLEDURATIONOFFVMOFPCCONFIG                                     STD_ON
#define SSA_SECUREDTICKCOUNTSTARTUPCYCLETIMEOFFVMOFPCCONFIG                                         STD_ON
#define SSA_SECURITYACCESSLEVELOFPCCONFIG                                                           STD_ON
#define SSA_SIZEOFCODINGDIDOFPCCONFIG                                                               STD_ON
#define SSA_SIZEOFCODINGNVMBLOCKOFPCCONFIG                                                          STD_ON
#define SSA_SIZEOFDATAIDINFOOFPCCONFIG                                                              STD_ON
#define SSA_SIZEOFDIDHANDLEDOFPCCONFIG                                                              STD_ON
#define SSA_SIZEOFRIGHTSM_TESTERTOCHANNELOFPCCONFIG                                                 STD_ON
#define SSA_SIZEOFSECLOGINFOOFPCCONFIG                                                              STD_ON
#define SSA_SIZEOFSECURITYACCESSLEVELOFPCCONFIG                                                     STD_ON
#define SSA_SIZEOFTRUSTMODELBACKENDCERTNAMEOFPCCONFIG                                               STD_ON
#define SSA_SIZEOFTRUSTMODELBACKENDPEERCERTNAMEOFPCCONFIG                                           STD_ON
#define SSA_SIZEOFTRUSTMODELECUCERTNAMEOFPCCONFIG                                                   STD_ON
#define SSA_SIZEOFTRUSTMODELECUCSRCERTNAMEOFPCCONFIG                                                STD_ON
#define SSA_SIZEOFTRUSTMODELECUPEERCERTNAMEOFPCCONFIG                                               STD_ON
#define SSA_SIZEOFTRUSTMODELINTERMEDIATECERTNAMEOFPCCONFIG                                          STD_ON
#define SSA_SIZEOFTRUSTMODELINTERMEDIATEPEERCERTNAMEOFPCCONFIG                                      STD_ON
#define SSA_SIZEOFTRUSTMODELROOTCERTNAMEOFPCCONFIG                                                  STD_ON
#define SSA_SIZEOFUNIQUEECUIDOFPCCONFIG                                                             STD_ON
#define SSA_SIZEOFUNIQUEECUIDSOFPCCONFIG                                                            STD_ON
#define SSA_TIMEOUTOFCODINGOFPCCONFIG                                                               STD_ON
#define SSA_TRUSTMODELBACKENDCERTNAMEOFPCCONFIG                                                     STD_ON
#define SSA_TRUSTMODELBACKENDPEERCERTNAMEOFPCCONFIG                                                 STD_ON
#define SSA_TRUSTMODELECUCERTNAMEOFPCCONFIG                                                         STD_ON
#define SSA_TRUSTMODELECUCSRCERTNAMEOFPCCONFIG                                                      STD_ON
#define SSA_TRUSTMODELECUCSRREFOFKEYMOFPCCONFIG                                                     STD_ON
#define SSA_TRUSTMODELECUPEERCERTNAMEOFPCCONFIG                                                     STD_ON
#define SSA_TRUSTMODELINTERMEDIATECERTNAMEOFPCCONFIG                                                STD_ON
#define SSA_TRUSTMODELINTERMEDIATEPEERCERTNAMEOFPCCONFIG                                            STD_ON
#define SSA_TRUSTMODELROOTCERTNAMEOFPCCONFIG                                                        STD_ON
#define SSA_UNIQUEECUIDOFPCCONFIG                                                                   STD_ON
#define SSA_UNIQUEECUIDSOFPCCONFIG                                                                  STD_ON
#define SSA_UNLIMITEDTURNINGBACKOFTICKCOUNTOFFVMOFPCCONFIG                                          STD_ON
#define SSA_USEPIMACCESSMACROSASCOMPILETIMECONSTANTSOFSECLOGOFPCCONFIG                              STD_ON
#define SSA_VINRECEIVETIMEOUTOFCODINGOFPCCONFIG                                                     STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCMinNumericValueDefines  Ssa Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define SSA_MIN_DIDHANDLED                                                                          0u
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCMaxNumericValueDefines  Ssa Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define SSA_MAX_DIDHANDLED                                                                          4294967295u
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCNoReferenceDefines  Ssa No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define SSA_NO_EXPECTEDCOMPATIBILITYVERSION                                                         65535u
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCIsReducedToDefineDefines  Ssa Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define SSA_ISDEF_CODINGDID                                                                         STD_OFF
#define SSA_ISDEF_CODINGNVMBLOCK                                                                    STD_OFF
#define SSA_ISDEF_DATAIDOFDATAIDINFO                                                                STD_OFF
#define SSA_ISDEF_KEYIDOFDATAIDINFO                                                                 STD_OFF
#define SSA_ISDEF_THRESHOLDOFDATAIDINFO                                                             STD_OFF
#define SSA_ISDEF_RIGHTSM_TESTERTOCHANNEL                                                           STD_OFF
#define SSA_ISDEF_DATAIDINFOIDXOFSECLOGINFO                                                         STD_OFF
#define SSA_ISDEF_JOBIDOFSECURITYACCESSLEVEL                                                        STD_OFF
#define SSA_ISDEF_LEVELOFSECURITYACCESSLEVEL                                                        STD_OFF
#define SSA_ISDEF_TRUSTMODELBACKENDCERTNAME                                                         STD_OFF
#define SSA_ISDEF_TRUSTMODELBACKENDPEERCERTNAME                                                     STD_OFF
#define SSA_ISDEF_TRUSTMODELECUCERTNAME                                                             STD_OFF
#define SSA_ISDEF_TRUSTMODELECUCSRCERTNAME                                                          STD_OFF
#define SSA_ISDEF_TRUSTMODELECUPEERCERTNAME                                                         STD_OFF
#define SSA_ISDEF_TRUSTMODELINTERMEDIATECERTNAME                                                    STD_OFF
#define SSA_ISDEF_TRUSTMODELINTERMEDIATEPEERCERTNAME                                                STD_OFF
#define SSA_ISDEF_TRUSTMODELROOTCERTNAME                                                            STD_OFF
#define SSA_ISDEF_UNIQUEECUIDSUNIQUEECUIDSENDIDXOFUNIQUEECUID                                       STD_OFF
#define SSA_ISDEF_UNIQUEECUIDSUNIQUEECUIDSSTARTIDXOFUNIQUEECUID                                     STD_OFF
#define SSA_ISDEF_UNIQUEECUIDS                                                                      STD_OFF
#define SSA_ISDEF_CODINGDIDOFPCCONFIG                                                               STD_ON
#define SSA_ISDEF_CODINGNVMBLOCKOFPCCONFIG                                                          STD_ON
#define SSA_ISDEF_DATAIDINFOOFPCCONFIG                                                              STD_ON
#define SSA_ISDEF_DIDHANDLEDOFPCCONFIG                                                              STD_ON
#define SSA_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                            STD_OFF
#define SSA_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                        STD_OFF
#define SSA_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                           STD_OFF
#define SSA_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                        STD_OFF
#define SSA_ISDEF_RIGHTSM_TESTERTOCHANNELOFPCCONFIG                                                 STD_ON
#define SSA_ISDEF_SECLOGINFOOFPCCONFIG                                                              STD_ON
#define SSA_ISDEF_SECURITYACCESSLEVELOFPCCONFIG                                                     STD_ON
#define SSA_ISDEF_TRUSTMODELBACKENDCERTNAMEOFPCCONFIG                                               STD_ON
#define SSA_ISDEF_TRUSTMODELBACKENDPEERCERTNAMEOFPCCONFIG                                           STD_ON
#define SSA_ISDEF_TRUSTMODELECUCERTNAMEOFPCCONFIG                                                   STD_ON
#define SSA_ISDEF_TRUSTMODELECUCSRCERTNAMEOFPCCONFIG                                                STD_ON
#define SSA_ISDEF_TRUSTMODELECUPEERCERTNAMEOFPCCONFIG                                               STD_ON
#define SSA_ISDEF_TRUSTMODELINTERMEDIATECERTNAMEOFPCCONFIG                                          STD_ON
#define SSA_ISDEF_TRUSTMODELINTERMEDIATEPEERCERTNAMEOFPCCONFIG                                      STD_ON
#define SSA_ISDEF_TRUSTMODELROOTCERTNAMEOFPCCONFIG                                                  STD_ON
#define SSA_ISDEF_UNIQUEECUIDOFPCCONFIG                                                             STD_ON
#define SSA_ISDEF_UNIQUEECUIDSOFPCCONFIG                                                            STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCEqualsAlwaysToDefines  Ssa Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define SSA_EQ2_CODINGDID                                                                           
#define SSA_EQ2_CODINGNVMBLOCK                                                                      
#define SSA_EQ2_DATAIDOFDATAIDINFO                                                                  
#define SSA_EQ2_KEYIDOFDATAIDINFO                                                                   
#define SSA_EQ2_THRESHOLDOFDATAIDINFO                                                               
#define SSA_EQ2_RIGHTSM_TESTERTOCHANNEL                                                             
#define SSA_EQ2_DATAIDINFOIDXOFSECLOGINFO                                                           
#define SSA_EQ2_JOBIDOFSECURITYACCESSLEVEL                                                          
#define SSA_EQ2_LEVELOFSECURITYACCESSLEVEL                                                          
#define SSA_EQ2_TRUSTMODELBACKENDCERTNAME                                                           
#define SSA_EQ2_TRUSTMODELBACKENDPEERCERTNAME                                                       
#define SSA_EQ2_TRUSTMODELECUCERTNAME                                                               
#define SSA_EQ2_TRUSTMODELECUCSRCERTNAME                                                            
#define SSA_EQ2_TRUSTMODELECUPEERCERTNAME                                                           
#define SSA_EQ2_TRUSTMODELINTERMEDIATECERTNAME                                                      
#define SSA_EQ2_TRUSTMODELINTERMEDIATEPEERCERTNAME                                                  
#define SSA_EQ2_TRUSTMODELROOTCERTNAME                                                              
#define SSA_EQ2_UNIQUEECUIDSUNIQUEECUIDSENDIDXOFUNIQUEECUID                                         
#define SSA_EQ2_UNIQUEECUIDSUNIQUEECUIDSSTARTIDXOFUNIQUEECUID                                       
#define SSA_EQ2_UNIQUEECUIDS                                                                        
#define SSA_EQ2_CODINGDIDOFPCCONFIG                                                                 Ssa_CodingDid
#define SSA_EQ2_CODINGNVMBLOCKOFPCCONFIG                                                            Ssa_CodingNvMBlock
#define SSA_EQ2_DATAIDINFOOFPCCONFIG                                                                Ssa_DataIdInfo
#define SSA_EQ2_DIDHANDLEDOFPCCONFIG                                                                Ssa_DidHandled
#define SSA_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                              
#define SSA_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                          
#define SSA_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                             
#define SSA_EQ2_INITDATAHASHCODEOFPCCONFIG                                                          
#define SSA_EQ2_RIGHTSM_TESTERTOCHANNELOFPCCONFIG                                                   Ssa_RightsM_TesterToChannel
#define SSA_EQ2_SECLOGINFOOFPCCONFIG                                                                Ssa_SecLogInfo
#define SSA_EQ2_SECURITYACCESSLEVELOFPCCONFIG                                                       Ssa_SecurityAccessLevel
#define SSA_EQ2_TRUSTMODELBACKENDCERTNAMEOFPCCONFIG                                                 Ssa_TrustModelBackendCertName
#define SSA_EQ2_TRUSTMODELBACKENDPEERCERTNAMEOFPCCONFIG                                             Ssa_TrustModelBackendPeerCertName
#define SSA_EQ2_TRUSTMODELECUCERTNAMEOFPCCONFIG                                                     Ssa_TrustModelEcuCertName
#define SSA_EQ2_TRUSTMODELECUCSRCERTNAMEOFPCCONFIG                                                  Ssa_TrustModelEcuCsrCertName
#define SSA_EQ2_TRUSTMODELECUPEERCERTNAMEOFPCCONFIG                                                 Ssa_TrustModelEcuPeerCertName
#define SSA_EQ2_TRUSTMODELINTERMEDIATECERTNAMEOFPCCONFIG                                            Ssa_TrustModelIntermediateCertName
#define SSA_EQ2_TRUSTMODELINTERMEDIATEPEERCERTNAMEOFPCCONFIG                                        Ssa_TrustModelIntermediatePeerCertName
#define SSA_EQ2_TRUSTMODELROOTCERTNAMEOFPCCONFIG                                                    Ssa_TrustModelRootCertName
#define SSA_EQ2_UNIQUEECUIDOFPCCONFIG                                                               Ssa_UniqueEcuId
#define SSA_EQ2_UNIQUEECUIDSOFPCCONFIG                                                              Ssa_UniqueEcuIds
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCSymbolicInitializationPointers  Ssa Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Ssa_Config_Ptr                                                                              NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Ssa' */
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCInitializationSymbols  Ssa Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Ssa_Config                                                                                  NULL_PTR  /**< symbolic identifier which could be used to initialize 'Ssa */
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCGeneral  Ssa General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define SSA_CHECK_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define SSA_FINAL_MAGIC_NUMBER                                                                      0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Ssa */
#define SSA_INDIVIDUAL_POSTBUILD                                                                    STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Ssa' is not configured to be postbuild capable. */
#define SSA_INIT_DATA                                                                               SSA_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define SSA_INIT_DATA_HASH_CODE                                                                     605893504  /**< the precompile constant to validate the initialization structure at initialization time of Ssa with a hashcode. The seed value is '0xFF1Eu' */
#define SSA_USE_ECUM_BSW_ERROR_HOOK                                                                 STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define SSA_USE_INIT_POINTER                                                                        STD_OFF  /**< STD_ON if the init pointer Ssa shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  SsaPBDataSwitches  Ssa Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define SSA_PBCONFIG                                                                                STD_OFF  /**< Deactivateable: 'Ssa_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define SSA_LTCONFIGIDXOFPBCONFIG                                                                   STD_OFF  /**< Deactivateable: 'Ssa_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define SSA_PCCONFIGIDXOFPBCONFIG                                                                   STD_OFF  /**< Deactivateable: 'Ssa_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  SsaPBIsReducedToDefineDefines  Ssa Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define SSA_ISDEF_LTCONFIGIDXOFPBCONFIG                                                             STD_OFF
#define SSA_ISDEF_PCCONFIGIDXOFPBCONFIG                                                             STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  SsaPBEqualsAlwaysToDefines  Ssa Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define SSA_EQ2_LTCONFIGIDXOFPBCONFIG                                                               
#define SSA_EQ2_PCCONFIGIDXOFPBCONFIG                                                               
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  SsaPCGetRootDataMacros  Ssa Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Ssa_GetExpectedCompatibilityVersionOfPCConfig()                                               /**< Deactivateable: 'Ssa_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Ssa_GetFinalMagicNumberOfPCConfig()                                                           /**< Deactivateable: 'Ssa_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Ssa_GetGeneratorCompatibilityVersionOfPCConfig()                                              /**< Deactivateable: 'Ssa_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Ssa_GetInitDataHashCodeOfPCConfig()                                                           /**< Deactivateable: 'Ssa_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCGetConstantDuplicatedRootDataMacros  Ssa Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Ssa_GetCircularBufferSizeAuthorizationBySecurityAccessEventOfSecLogOfPCConfig()             7u
#define Ssa_GetCircularBufferSizeChangeOfTickCountOrDateAndTimeEventOfSecLogOfPCConfig()            20u
#define Ssa_GetCircularBufferSizeChangeOfVinEventOfSecLogOfPCConfig()                               3u
#define Ssa_GetCircularBufferSizeEcuIndividualAclReplacementEventOfSecLogOfPCConfig()               5u
#define Ssa_GetCircularBufferSizeFailedCertificateVerificationEventOfSecLogOfPCConfig()             20u
#define Ssa_GetCircularBufferSizeFailedPduMacVerificationEventOfSecLogOfPCConfig()                  15u
#define Ssa_GetCircularBufferSizeRightsManagementEventOfSecLogOfPCConfig()                          20u
#define Ssa_GetCircularBufferSizeSecocMisconfigurationEventOfSecLogOfPCConfig()                     10u
#define Ssa_GetCircularBufferSizeSecureBootOrAuthenticatedBootEventOfSecLogOfPCConfig()             10u
#define Ssa_GetCircularBufferSizeSignatureVerificationEventOfSecLogOfPCConfig()                     10u
#define Ssa_GetCircularBufferSizeSuccessfulAuthenticationAndEnhanceRightsEventOfSecLogOfPCConfig()  15u
#define Ssa_GetCircularBufferSizeSuccessfulCertificateVerificationEventOfSecLogOfPCConfig()         10u
#define Ssa_GetCircularBufferSizeSuccessfulDiagnosticServiceExecutionEventOfSecLogOfPCConfig()      15u
#define Ssa_GetCodingDidOfPCConfig()                                                                Ssa_CodingDid  /**< the pointer to Ssa_CodingDid */
#define Ssa_GetCodingNvMBlockOfPCConfig()                                                           Ssa_CodingNvMBlock  /**< the pointer to Ssa_CodingNvMBlock */
#define Ssa_IsDEV_ERROR_DETECTOfGeneralOfPCConfig()                                                 (((FALSE)) != FALSE)
#define Ssa_GetDataBufferSizeOfCodingOfPCConfig()                                                   1081u
#define Ssa_GetDataIdInfoOfPCConfig()                                                               Ssa_DataIdInfo  /**< the pointer to Ssa_DataIdInfo */
#define Ssa_GetDebounceTimeDetectionMissingTickCountMessagesOfFvMOfPCConfig()                       3000u
#define Ssa_GetDebounceTimeDetectionRejectedTickCountMessagesOfFvMOfPCConfig()                      3000u
#define Ssa_GetDebounceTimeDetectionUnautheticatedTickCountMessagesOfFvMOfPCConfig()                3000u
#define Ssa_IsDecoupleExternalProcessingService29OfGeneralOfPCConfig()                              (((TRUE)) != FALSE)
#define Ssa_IsDiagServiceInjectSeedOfGeneralOfPCConfig()                                            (((FALSE)) != FALSE)
#define Ssa_IsDiagServiceTrustModelGenerateKeyPairOfGeneralOfPCConfig()                             (((TRUE)) != FALSE)
#define Ssa_GetDidHandledOfPCConfig()                                                               Ssa_DidHandled  /**< the pointer to Ssa_DidHandled */
#define Ssa_GetEcuIndividualAclPtrNameOfRightsMOfPCConfig()                                         Ssa_RightsM_EcuIndividualAcl
#define Ssa_GetEcuTypeOfGeneralOfPCConfig()                                                         SSA_ECU_TYPE_NORMAL
#define Ssa_IsEnableAsyncCsmJobProcessingOfGeneralOfPCConfig()                                      (((FALSE)) != FALSE)
#define Ssa_IsEnableAsyncCsmKeyManagementPrimitivesOfGeneralOfPCConfig()                            (((FALSE)) != FALSE)
#define Ssa_IsEnableBufferHandlingOfProcCtrlOfPCConfig()                                            (((TRUE)) != FALSE)
#define Ssa_IsEnableDebugAuthenticationOfGeneralOfPCConfig()                                        (((FALSE)) != FALSE)
#define Ssa_IsEnableDebugAuthenticationStatusOfGeneralOfPCConfig()                                  (((FALSE)) != FALSE)
#define Ssa_IsEnableDebugNonceOfGeneralOfPCConfig()                                                 (((FALSE)) != FALSE)
#define Ssa_IsEnableDebugRightsOfGeneralOfPCConfig()                                                (((FALSE)) != FALSE)
#define Ssa_GetEnhancedAccessRightsTableSizeOfRightsMOfPCConfig()                                   300u
#define Ssa_GetFailedMacVerificationCounterThreshold1OfSecLogOfPCConfig()                           250u
#define Ssa_GetFailedMacVerificationCounterThreshold2OfSecLogOfPCConfig()                           1000u
#define Ssa_GetFailedMacVerificationCounterThreshold3OfSecLogOfPCConfig()                           50000u
#define Ssa_GetFailedMacVerificationCounterThresholdDtcOfSecLogOfPCConfig()                         100u
#define Ssa_IsGenerateKeyPairCustomCalloutOfGeneralOfPCConfig()                                     (((FALSE)) != FALSE)
#define Ssa_IsIgnoreCodingVerificationResultOfGeneralOfPCConfig()                                   (((FALSE)) != FALSE)
#define Ssa_IsIgnoreSecureBroadcastVerificationResultOfGeneralOfPCConfig()                          (((FALSE)) != FALSE)
#define Ssa_IsKeepBufferVariablesStaticOfGeneralOfPCConfig()                                        (((FALSE)) != FALSE)
#define Ssa_GetLocalTickCountSynchronizationTimeoutOfFvMOfPCConfig()                                3000u
#define Ssa_GetLoggingActiveTimeoutOfSecLogOfPCConfig()                                             180u
#define Ssa_GetMaxDidListLengthOfRightsMOfPCConfig()                                                30u
#define Ssa_GetNumberKeysGeneratedInMainOfKeyMOfPCConfig()                                          65535u
#define Ssa_GetNumberRetriesKeyGenerationOfKeyMOfPCConfig()                                         0u
#define Ssa_GetNumberWaitCyclesBeforeKeyGenerationOfKeyMOfPCConfig()                                0u
#define Ssa_GetPercentageLocalTickCountSlowdownOfFvMOfPCConfig()                                    2u
#define Ssa_GetPercentageTurningBackLocalTickCountOfFvMOfPCConfig()                                 40u
#define Ssa_GetPostProductionStatusActivationMileageThresholdOfRightsMOfPCConfig()                  100000u
#define Ssa_GetRightsM_TesterToChannelOfPCConfig()                                                  Ssa_RightsM_TesterToChannel  /**< the pointer to Ssa_RightsM_TesterToChannel */
#define Ssa_GetRtcCorrectionToleranceOfFvMOfPCConfig()                                              0u
#define Ssa_GetRtcResolutionOfFvMOfPCConfig()                                                       1000u
#define Ssa_GetSecLogInfoOfPCConfig()                                                               Ssa_SecLogInfo  /**< the pointer to Ssa_SecLogInfo */
#define Ssa_GetSecuredTickCountCycleTimeOfFvMOfPCConfig()                                           100u
#define Ssa_GetSecuredTickCountStartupCycleDurationOfFvMOfPCConfig()                                1000u
#define Ssa_GetSecuredTickCountStartupCycleTimeOfFvMOfPCConfig()                                    100u
#define Ssa_GetSecurityAccessLevelOfPCConfig()                                                      Ssa_SecurityAccessLevel  /**< the pointer to Ssa_SecurityAccessLevel */
#define Ssa_GetSizeOfCodingDidOfPCConfig()                                                          9u  /**< the number of accomplishable value elements in Ssa_CodingDid */
#define Ssa_GetSizeOfCodingNvMBlockOfPCConfig()                                                     7u  /**< the number of accomplishable value elements in Ssa_CodingNvMBlock */
#define Ssa_GetSizeOfDataIdInfoOfPCConfig()                                                         7u  /**< the number of accomplishable value elements in Ssa_DataIdInfo */
#define Ssa_GetSizeOfDidHandledOfPCConfig()                                                         1u  /**< the number of accomplishable value elements in Ssa_DidHandled */
#define Ssa_GetSizeOfRightsM_TesterToChannelOfPCConfig()                                            16u  /**< the number of accomplishable value elements in Ssa_RightsM_TesterToChannel */
#define Ssa_GetSizeOfSecLogInfoOfPCConfig()                                                         7u  /**< the number of accomplishable value elements in Ssa_SecLogInfo */
#define Ssa_GetSizeOfSecurityAccessLevelOfPCConfig()                                                4u  /**< the number of accomplishable value elements in Ssa_SecurityAccessLevel */
#define Ssa_GetSizeOfTrustModelBackendCertNameOfPCConfig()                                          21u  /**< the number of accomplishable value elements in Ssa_TrustModelBackendCertName */
#define Ssa_GetSizeOfTrustModelBackendPeerCertNameOfPCConfig()                                      25u  /**< the number of accomplishable value elements in Ssa_TrustModelBackendPeerCertName */
#define Ssa_GetSizeOfTrustModelEcuCertNameOfPCConfig()                                              17u  /**< the number of accomplishable value elements in Ssa_TrustModelEcuCertName */
#define Ssa_GetSizeOfTrustModelEcuCsrCertNameOfPCConfig()                                           16u  /**< the number of accomplishable value elements in Ssa_TrustModelEcuCsrCertName */
#define Ssa_GetSizeOfTrustModelEcuPeerCertNameOfPCConfig()                                          21u  /**< the number of accomplishable value elements in Ssa_TrustModelEcuPeerCertName */
#define Ssa_GetSizeOfTrustModelIntermediateCertNameOfPCConfig()                                     26u  /**< the number of accomplishable value elements in Ssa_TrustModelIntermediateCertName */
#define Ssa_GetSizeOfTrustModelIntermediatePeerCertNameOfPCConfig()                                 30u  /**< the number of accomplishable value elements in Ssa_TrustModelIntermediatePeerCertName */
#define Ssa_GetSizeOfTrustModelRootCertNameOfPCConfig()                                             18u  /**< the number of accomplishable value elements in Ssa_TrustModelRootCertName */
#define Ssa_GetSizeOfUniqueEcuIdOfPCConfig()                                                        2u  /**< the number of accomplishable value elements in Ssa_UniqueEcuId */
#define Ssa_GetSizeOfUniqueEcuIdsOfPCConfig()                                                       18u  /**< the number of accomplishable value elements in Ssa_UniqueEcuIds */
#define Ssa_GetTimeoutOfCodingOfPCConfig()                                                          20000u
#define Ssa_GetTrustModelBackendCertNameOfPCConfig()                                                Ssa_TrustModelBackendCertName  /**< the pointer to Ssa_TrustModelBackendCertName */
#define Ssa_GetTrustModelBackendPeerCertNameOfPCConfig()                                            Ssa_TrustModelBackendPeerCertName  /**< the pointer to Ssa_TrustModelBackendPeerCertName */
#define Ssa_GetTrustModelEcuCertNameOfPCConfig()                                                    Ssa_TrustModelEcuCertName  /**< the pointer to Ssa_TrustModelEcuCertName */
#define Ssa_GetTrustModelEcuCsrCertNameOfPCConfig()                                                 Ssa_TrustModelEcuCsrCertName  /**< the pointer to Ssa_TrustModelEcuCsrCertName */
#define Ssa_GetTrustModelEcuCsrRefOfKeyMOfPCConfig()                                                KeyMConf_KeyMCertificate_Ssa_TrustModelEcuCsr
#define Ssa_GetTrustModelEcuPeerCertNameOfPCConfig()                                                Ssa_TrustModelEcuPeerCertName  /**< the pointer to Ssa_TrustModelEcuPeerCertName */
#define Ssa_GetTrustModelIntermediateCertNameOfPCConfig()                                           Ssa_TrustModelIntermediateCertName  /**< the pointer to Ssa_TrustModelIntermediateCertName */
#define Ssa_GetTrustModelIntermediatePeerCertNameOfPCConfig()                                       Ssa_TrustModelIntermediatePeerCertName  /**< the pointer to Ssa_TrustModelIntermediatePeerCertName */
#define Ssa_GetTrustModelRootCertNameOfPCConfig()                                                   Ssa_TrustModelRootCertName  /**< the pointer to Ssa_TrustModelRootCertName */
#define Ssa_GetUniqueEcuIdOfPCConfig()                                                              Ssa_UniqueEcuId  /**< the pointer to Ssa_UniqueEcuId */
#define Ssa_GetUniqueEcuIdsOfPCConfig()                                                             Ssa_UniqueEcuIds  /**< the pointer to Ssa_UniqueEcuIds */
#define Ssa_IsUnlimitedTurningBackOfTickCountOfFvMOfPCConfig()                                      (((FALSE)) != FALSE)
#define Ssa_IsUsePimAccessMacrosAsCompileTimeConstantsOfSecLogOfPCConfig()                          (((TRUE)) != FALSE)
#define Ssa_GetVINReceiveTimeoutOfCodingOfPCConfig()                                                5000u
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCGetDataMacros  Ssa Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Ssa_GetCodingDid(Index)                                                                     (Ssa_GetCodingDidOfPCConfig()[(Index)])
#define Ssa_GetCodingNvMBlock(Index)                                                                (Ssa_GetCodingNvMBlockOfPCConfig()[(Index)])
#define Ssa_GetDataIdOfDataIdInfo(Index)                                                            (Ssa_GetDataIdInfoOfPCConfig()[(Index)].DataIdOfDataIdInfo)
#define Ssa_GetKeyIdOfDataIdInfo(Index)                                                             (Ssa_GetDataIdInfoOfPCConfig()[(Index)].KeyIdOfDataIdInfo)
#define Ssa_GetThresholdOfDataIdInfo(Index)                                                         (Ssa_GetDataIdInfoOfPCConfig()[(Index)].ThresholdOfDataIdInfo)
#define Ssa_GetDidHandled(Index)                                                                    (Ssa_GetDidHandledOfPCConfig()[(Index)])
#define Ssa_GetRightsM_TesterToChannel(Index)                                                       (Ssa_GetRightsM_TesterToChannelOfPCConfig()[(Index)])
#define Ssa_GetJobIdOfSecurityAccessLevel(Index)                                                    (Ssa_GetSecurityAccessLevelOfPCConfig()[(Index)].JobIdOfSecurityAccessLevel)
#define Ssa_GetLevelOfSecurityAccessLevel(Index)                                                    (Ssa_GetSecurityAccessLevelOfPCConfig()[(Index)].LevelOfSecurityAccessLevel)
#define Ssa_GetTrustModelBackendCertName(Index)                                                     (Ssa_GetTrustModelBackendCertNameOfPCConfig()[(Index)])
#define Ssa_GetTrustModelBackendPeerCertName(Index)                                                 (Ssa_GetTrustModelBackendPeerCertNameOfPCConfig()[(Index)])
#define Ssa_GetTrustModelEcuCertName(Index)                                                         (Ssa_GetTrustModelEcuCertNameOfPCConfig()[(Index)])
#define Ssa_GetTrustModelEcuCsrCertName(Index)                                                      (Ssa_GetTrustModelEcuCsrCertNameOfPCConfig()[(Index)])
#define Ssa_GetTrustModelEcuPeerCertName(Index)                                                     (Ssa_GetTrustModelEcuPeerCertNameOfPCConfig()[(Index)])
#define Ssa_GetTrustModelIntermediateCertName(Index)                                                (Ssa_GetTrustModelIntermediateCertNameOfPCConfig()[(Index)])
#define Ssa_GetTrustModelIntermediatePeerCertName(Index)                                            (Ssa_GetTrustModelIntermediatePeerCertNameOfPCConfig()[(Index)])
#define Ssa_GetTrustModelRootCertName(Index)                                                        (Ssa_GetTrustModelRootCertNameOfPCConfig()[(Index)])
#define Ssa_GetUniqueEcuIdsUniqueEcuIdsEndIdxOfUniqueEcuId(Index)                                   (Ssa_GetUniqueEcuIdOfPCConfig()[(Index)].UniqueEcuIdsUniqueEcuIdsEndIdxOfUniqueEcuId)
#define Ssa_GetUniqueEcuIdsUniqueEcuIdsStartIdxOfUniqueEcuId(Index)                                 (Ssa_GetUniqueEcuIdOfPCConfig()[(Index)].UniqueEcuIdsUniqueEcuIdsStartIdxOfUniqueEcuId)
#define Ssa_GetUniqueEcuIds(Index)                                                                  (Ssa_GetUniqueEcuIdsOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCGetDeduplicatedDataMacros  Ssa Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Ssa_GetCircularBufferSizeAuthorizationBySecurityAccessEventOfSecLog()                       Ssa_GetCircularBufferSizeAuthorizationBySecurityAccessEventOfSecLogOfPCConfig()
#define Ssa_GetCircularBufferSizeChangeOfTickCountOrDateAndTimeEventOfSecLog()                      Ssa_GetCircularBufferSizeChangeOfTickCountOrDateAndTimeEventOfSecLogOfPCConfig()
#define Ssa_GetCircularBufferSizeChangeOfVinEventOfSecLog()                                         Ssa_GetCircularBufferSizeChangeOfVinEventOfSecLogOfPCConfig()
#define Ssa_GetCircularBufferSizeEcuIndividualAclReplacementEventOfSecLog()                         Ssa_GetCircularBufferSizeEcuIndividualAclReplacementEventOfSecLogOfPCConfig()
#define Ssa_GetCircularBufferSizeFailedCertificateVerificationEventOfSecLog()                       Ssa_GetCircularBufferSizeFailedCertificateVerificationEventOfSecLogOfPCConfig()
#define Ssa_GetCircularBufferSizeFailedPduMacVerificationEventOfSecLog()                            Ssa_GetCircularBufferSizeFailedPduMacVerificationEventOfSecLogOfPCConfig()
#define Ssa_GetCircularBufferSizeRightsManagementEventOfSecLog()                                    Ssa_GetCircularBufferSizeRightsManagementEventOfSecLogOfPCConfig()
#define Ssa_GetCircularBufferSizeSecocMisconfigurationEventOfSecLog()                               Ssa_GetCircularBufferSizeSecocMisconfigurationEventOfSecLogOfPCConfig()
#define Ssa_GetCircularBufferSizeSecureBootOrAuthenticatedBootEventOfSecLog()                       Ssa_GetCircularBufferSizeSecureBootOrAuthenticatedBootEventOfSecLogOfPCConfig()
#define Ssa_GetCircularBufferSizeSignatureVerificationEventOfSecLog()                               Ssa_GetCircularBufferSizeSignatureVerificationEventOfSecLogOfPCConfig()
#define Ssa_GetCircularBufferSizeSuccessfulAuthenticationAndEnhanceRightsEventOfSecLog()            Ssa_GetCircularBufferSizeSuccessfulAuthenticationAndEnhanceRightsEventOfSecLogOfPCConfig()
#define Ssa_GetCircularBufferSizeSuccessfulCertificateVerificationEventOfSecLog()                   Ssa_GetCircularBufferSizeSuccessfulCertificateVerificationEventOfSecLogOfPCConfig()
#define Ssa_GetCircularBufferSizeSuccessfulDiagnosticServiceExecutionEventOfSecLog()                Ssa_GetCircularBufferSizeSuccessfulDiagnosticServiceExecutionEventOfSecLogOfPCConfig()
#define Ssa_IsDEV_ERROR_DETECTOfGeneral()                                                           Ssa_IsDEV_ERROR_DETECTOfGeneralOfPCConfig()
#define Ssa_GetDataBufferSizeOfCoding()                                                             Ssa_GetDataBufferSizeOfCodingOfPCConfig()
#define Ssa_GetDebounceTimeDetectionMissingTickCountMessagesOfFvM()                                 Ssa_GetDebounceTimeDetectionMissingTickCountMessagesOfFvMOfPCConfig()
#define Ssa_GetDebounceTimeDetectionRejectedTickCountMessagesOfFvM()                                Ssa_GetDebounceTimeDetectionRejectedTickCountMessagesOfFvMOfPCConfig()
#define Ssa_GetDebounceTimeDetectionUnautheticatedTickCountMessagesOfFvM()                          Ssa_GetDebounceTimeDetectionUnautheticatedTickCountMessagesOfFvMOfPCConfig()
#define Ssa_IsDecoupleExternalProcessingService29OfGeneral()                                        Ssa_IsDecoupleExternalProcessingService29OfGeneralOfPCConfig()
#define Ssa_IsDiagServiceInjectSeedOfGeneral()                                                      Ssa_IsDiagServiceInjectSeedOfGeneralOfPCConfig()
#define Ssa_IsDiagServiceTrustModelGenerateKeyPairOfGeneral()                                       Ssa_IsDiagServiceTrustModelGenerateKeyPairOfGeneralOfPCConfig()
#define Ssa_GetEcuIndividualAclPtrNameOfRightsM()                                                   Ssa_GetEcuIndividualAclPtrNameOfRightsMOfPCConfig()
#define Ssa_GetEcuTypeOfGeneral()                                                                   Ssa_GetEcuTypeOfGeneralOfPCConfig()
#define Ssa_IsEnableAsyncCsmJobProcessingOfGeneral()                                                Ssa_IsEnableAsyncCsmJobProcessingOfGeneralOfPCConfig()
#define Ssa_IsEnableAsyncCsmKeyManagementPrimitivesOfGeneral()                                      Ssa_IsEnableAsyncCsmKeyManagementPrimitivesOfGeneralOfPCConfig()
#define Ssa_IsEnableBufferHandlingOfProcCtrl()                                                      Ssa_IsEnableBufferHandlingOfProcCtrlOfPCConfig()
#define Ssa_IsEnableDebugAuthenticationOfGeneral()                                                  Ssa_IsEnableDebugAuthenticationOfGeneralOfPCConfig()
#define Ssa_IsEnableDebugAuthenticationStatusOfGeneral()                                            Ssa_IsEnableDebugAuthenticationStatusOfGeneralOfPCConfig()
#define Ssa_IsEnableDebugNonceOfGeneral()                                                           Ssa_IsEnableDebugNonceOfGeneralOfPCConfig()
#define Ssa_IsEnableDebugRightsOfGeneral()                                                          Ssa_IsEnableDebugRightsOfGeneralOfPCConfig()
#define Ssa_GetEnhancedAccessRightsTableSizeOfRightsM()                                             Ssa_GetEnhancedAccessRightsTableSizeOfRightsMOfPCConfig()
#define Ssa_GetExpectedCompatibilityVersion()                                                         /**< Deactivateable: 'Ssa_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Ssa_GetFailedMacVerificationCounterThreshold1OfSecLog()                                     Ssa_GetFailedMacVerificationCounterThreshold1OfSecLogOfPCConfig()
#define Ssa_GetFailedMacVerificationCounterThreshold2OfSecLog()                                     Ssa_GetFailedMacVerificationCounterThreshold2OfSecLogOfPCConfig()
#define Ssa_GetFailedMacVerificationCounterThreshold3OfSecLog()                                     Ssa_GetFailedMacVerificationCounterThreshold3OfSecLogOfPCConfig()
#define Ssa_GetFailedMacVerificationCounterThresholdDtcOfSecLog()                                   Ssa_GetFailedMacVerificationCounterThresholdDtcOfSecLogOfPCConfig()
#define Ssa_GetFinalMagicNumber()                                                                     /**< Deactivateable: 'Ssa_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Ssa_IsGenerateKeyPairCustomCalloutOfGeneral()                                               Ssa_IsGenerateKeyPairCustomCalloutOfGeneralOfPCConfig()
#define Ssa_GetGeneratorCompatibilityVersion()                                                        /**< Deactivateable: 'Ssa_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Ssa_IsIgnoreCodingVerificationResultOfGeneral()                                             Ssa_IsIgnoreCodingVerificationResultOfGeneralOfPCConfig()
#define Ssa_IsIgnoreSecureBroadcastVerificationResultOfGeneral()                                    Ssa_IsIgnoreSecureBroadcastVerificationResultOfGeneralOfPCConfig()
#define Ssa_GetInitDataHashCode()                                                                     /**< Deactivateable: 'Ssa_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Ssa_IsKeepBufferVariablesStaticOfGeneral()                                                  Ssa_IsKeepBufferVariablesStaticOfGeneralOfPCConfig()
#define Ssa_GetLocalTickCountSynchronizationTimeoutOfFvM()                                          Ssa_GetLocalTickCountSynchronizationTimeoutOfFvMOfPCConfig()
#define Ssa_GetLoggingActiveTimeoutOfSecLog()                                                       Ssa_GetLoggingActiveTimeoutOfSecLogOfPCConfig()
#define Ssa_GetMaxDidListLengthOfRightsM()                                                          Ssa_GetMaxDidListLengthOfRightsMOfPCConfig()
#define Ssa_GetNumberKeysGeneratedInMainOfKeyM()                                                    Ssa_GetNumberKeysGeneratedInMainOfKeyMOfPCConfig()
#define Ssa_GetNumberRetriesKeyGenerationOfKeyM()                                                   Ssa_GetNumberRetriesKeyGenerationOfKeyMOfPCConfig()
#define Ssa_GetNumberWaitCyclesBeforeKeyGenerationOfKeyM()                                          Ssa_GetNumberWaitCyclesBeforeKeyGenerationOfKeyMOfPCConfig()
#define Ssa_GetPercentageLocalTickCountSlowdownOfFvM()                                              Ssa_GetPercentageLocalTickCountSlowdownOfFvMOfPCConfig()
#define Ssa_GetPercentageTurningBackLocalTickCountOfFvM()                                           Ssa_GetPercentageTurningBackLocalTickCountOfFvMOfPCConfig()
#define Ssa_GetPostProductionStatusActivationMileageThresholdOfRightsM()                            Ssa_GetPostProductionStatusActivationMileageThresholdOfRightsMOfPCConfig()
#define Ssa_GetRtcCorrectionToleranceOfFvM()                                                        Ssa_GetRtcCorrectionToleranceOfFvMOfPCConfig()
#define Ssa_GetRtcResolutionOfFvM()                                                                 Ssa_GetRtcResolutionOfFvMOfPCConfig()
#define Ssa_GetDataIdInfoIdxOfSecLogInfo(Index)                                                     ((Ssa_DataIdInfoIdxOfSecLogInfoType)((Index)))  /**< the index of the 1:1 relation pointing to Ssa_DataIdInfo */
#define Ssa_GetSecuredTickCountCycleTimeOfFvM()                                                     Ssa_GetSecuredTickCountCycleTimeOfFvMOfPCConfig()
#define Ssa_GetSecuredTickCountStartupCycleDurationOfFvM()                                          Ssa_GetSecuredTickCountStartupCycleDurationOfFvMOfPCConfig()
#define Ssa_GetSecuredTickCountStartupCycleTimeOfFvM()                                              Ssa_GetSecuredTickCountStartupCycleTimeOfFvMOfPCConfig()
#define Ssa_GetSizeOfCodingDid()                                                                    Ssa_GetSizeOfCodingDidOfPCConfig()
#define Ssa_GetSizeOfCodingNvMBlock()                                                               Ssa_GetSizeOfCodingNvMBlockOfPCConfig()
#define Ssa_GetSizeOfDataIdInfo()                                                                   Ssa_GetSizeOfDataIdInfoOfPCConfig()
#define Ssa_GetSizeOfDidHandled()                                                                   Ssa_GetSizeOfDidHandledOfPCConfig()
#define Ssa_GetSizeOfRightsM_TesterToChannel()                                                      Ssa_GetSizeOfRightsM_TesterToChannelOfPCConfig()
#define Ssa_GetSizeOfSecLogInfo()                                                                   Ssa_GetSizeOfSecLogInfoOfPCConfig()
#define Ssa_GetSizeOfSecurityAccessLevel()                                                          Ssa_GetSizeOfSecurityAccessLevelOfPCConfig()
#define Ssa_GetSizeOfTrustModelBackendCertName()                                                    Ssa_GetSizeOfTrustModelBackendCertNameOfPCConfig()
#define Ssa_GetSizeOfTrustModelBackendPeerCertName()                                                Ssa_GetSizeOfTrustModelBackendPeerCertNameOfPCConfig()
#define Ssa_GetSizeOfTrustModelEcuCertName()                                                        Ssa_GetSizeOfTrustModelEcuCertNameOfPCConfig()
#define Ssa_GetSizeOfTrustModelEcuCsrCertName()                                                     Ssa_GetSizeOfTrustModelEcuCsrCertNameOfPCConfig()
#define Ssa_GetSizeOfTrustModelEcuPeerCertName()                                                    Ssa_GetSizeOfTrustModelEcuPeerCertNameOfPCConfig()
#define Ssa_GetSizeOfTrustModelIntermediateCertName()                                               Ssa_GetSizeOfTrustModelIntermediateCertNameOfPCConfig()
#define Ssa_GetSizeOfTrustModelIntermediatePeerCertName()                                           Ssa_GetSizeOfTrustModelIntermediatePeerCertNameOfPCConfig()
#define Ssa_GetSizeOfTrustModelRootCertName()                                                       Ssa_GetSizeOfTrustModelRootCertNameOfPCConfig()
#define Ssa_GetSizeOfUniqueEcuId()                                                                  Ssa_GetSizeOfUniqueEcuIdOfPCConfig()
#define Ssa_GetSizeOfUniqueEcuIds()                                                                 Ssa_GetSizeOfUniqueEcuIdsOfPCConfig()
#define Ssa_GetTimeoutOfCoding()                                                                    Ssa_GetTimeoutOfCodingOfPCConfig()
#define Ssa_GetTrustModelEcuCsrRefOfKeyM()                                                          Ssa_GetTrustModelEcuCsrRefOfKeyMOfPCConfig()
#define Ssa_IsUnlimitedTurningBackOfTickCountOfFvM()                                                Ssa_IsUnlimitedTurningBackOfTickCountOfFvMOfPCConfig()
#define Ssa_IsUsePimAccessMacrosAsCompileTimeConstantsOfSecLog()                                    Ssa_IsUsePimAccessMacrosAsCompileTimeConstantsOfSecLogOfPCConfig()
#define Ssa_GetVINReceiveTimeoutOfCoding()                                                          Ssa_GetVINReceiveTimeoutOfCodingOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCSetDataMacros  Ssa Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Ssa_SetDidHandled(Index, Value)                                                             Ssa_GetDidHandledOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCGetAddressOfDataMacros  Ssa Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Ssa_GetAddrTrustModelBackendCertName(Index)                                                 (&Ssa_GetTrustModelBackendCertName(Index))
#define Ssa_GetAddrTrustModelBackendPeerCertName(Index)                                             (&Ssa_GetTrustModelBackendPeerCertName(Index))
#define Ssa_GetAddrTrustModelEcuCertName(Index)                                                     (&Ssa_GetTrustModelEcuCertName(Index))
#define Ssa_GetAddrTrustModelEcuCsrCertName(Index)                                                  (&Ssa_GetTrustModelEcuCsrCertName(Index))
#define Ssa_GetAddrTrustModelEcuPeerCertName(Index)                                                 (&Ssa_GetTrustModelEcuPeerCertName(Index))
#define Ssa_GetAddrTrustModelIntermediateCertName(Index)                                            (&Ssa_GetTrustModelIntermediateCertName(Index))
#define Ssa_GetAddrTrustModelIntermediatePeerCertName(Index)                                        (&Ssa_GetTrustModelIntermediatePeerCertName(Index))
#define Ssa_GetAddrTrustModelRootCertName(Index)                                                    (&Ssa_GetTrustModelRootCertName(Index))
#define Ssa_GetAddrUniqueEcuIds(Index)                                                              (&Ssa_GetUniqueEcuIds(Index))
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCHasMacros  Ssa Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Ssa_HasCircularBufferSizeAuthorizationBySecurityAccessEventOfSecLog()                       (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeChangeOfTickCountOrDateAndTimeEventOfSecLog()                      (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeChangeOfVinEventOfSecLog()                                         (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeEcuIndividualAclReplacementEventOfSecLog()                         (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeFailedCertificateVerificationEventOfSecLog()                       (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeFailedPduMacVerificationEventOfSecLog()                            (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeRightsManagementEventOfSecLog()                                    (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeSecocMisconfigurationEventOfSecLog()                               (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeSecureBootOrAuthenticatedBootEventOfSecLog()                       (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeSignatureVerificationEventOfSecLog()                               (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeSuccessfulAuthenticationAndEnhanceRightsEventOfSecLog()            (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeSuccessfulCertificateVerificationEventOfSecLog()                   (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeSuccessfulDiagnosticServiceExecutionEventOfSecLog()                (TRUE != FALSE)
#define Ssa_HasCodingDid()                                                                          (TRUE != FALSE)
#define Ssa_HasCodingNvMBlock()                                                                     (TRUE != FALSE)
#define Ssa_HasDEV_ERROR_DETECTOfGeneral()                                                          (TRUE != FALSE)
#define Ssa_HasDataBufferSizeOfCoding()                                                             (TRUE != FALSE)
#define Ssa_HasDataIdInfo()                                                                         (TRUE != FALSE)
#define Ssa_HasDataIdOfDataIdInfo()                                                                 (TRUE != FALSE)
#define Ssa_HasKeyIdOfDataIdInfo()                                                                  (TRUE != FALSE)
#define Ssa_HasThresholdOfDataIdInfo()                                                              (TRUE != FALSE)
#define Ssa_HasDebounceTimeDetectionMissingTickCountMessagesOfFvM()                                 (TRUE != FALSE)
#define Ssa_HasDebounceTimeDetectionRejectedTickCountMessagesOfFvM()                                (TRUE != FALSE)
#define Ssa_HasDebounceTimeDetectionUnautheticatedTickCountMessagesOfFvM()                          (TRUE != FALSE)
#define Ssa_HasDecoupleExternalProcessingService29OfGeneral()                                       (TRUE != FALSE)
#define Ssa_HasDiagServiceInjectSeedOfGeneral()                                                     (TRUE != FALSE)
#define Ssa_HasDiagServiceTrustModelGenerateKeyPairOfGeneral()                                      (TRUE != FALSE)
#define Ssa_HasDidHandled()                                                                         (TRUE != FALSE)
#define Ssa_HasEcuIndividualAclPtrNameOfRightsM()                                                   (TRUE != FALSE)
#define Ssa_HasEcuTypeOfGeneral()                                                                   (TRUE != FALSE)
#define Ssa_HasEnableAsyncCsmJobProcessingOfGeneral()                                               (TRUE != FALSE)
#define Ssa_HasEnableAsyncCsmKeyManagementPrimitivesOfGeneral()                                     (TRUE != FALSE)
#define Ssa_HasEnableBufferHandlingOfProcCtrl()                                                     (TRUE != FALSE)
#define Ssa_HasEnableDebugAuthenticationOfGeneral()                                                 (TRUE != FALSE)
#define Ssa_HasEnableDebugAuthenticationStatusOfGeneral()                                           (TRUE != FALSE)
#define Ssa_HasEnableDebugNonceOfGeneral()                                                          (TRUE != FALSE)
#define Ssa_HasEnableDebugRightsOfGeneral()                                                         (TRUE != FALSE)
#define Ssa_HasEnhancedAccessRightsTableSizeOfRightsM()                                             (TRUE != FALSE)
#define Ssa_HasExpectedCompatibilityVersion()                                                         /**< Deactivateable: 'Ssa_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Ssa_HasFailedMacVerificationCounterThreshold1OfSecLog()                                     (TRUE != FALSE)
#define Ssa_HasFailedMacVerificationCounterThreshold2OfSecLog()                                     (TRUE != FALSE)
#define Ssa_HasFailedMacVerificationCounterThreshold3OfSecLog()                                     (TRUE != FALSE)
#define Ssa_HasFailedMacVerificationCounterThresholdDtcOfSecLog()                                   (TRUE != FALSE)
#define Ssa_HasFinalMagicNumber()                                                                     /**< Deactivateable: 'Ssa_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Ssa_HasGenerateKeyPairCustomCalloutOfGeneral()                                              (TRUE != FALSE)
#define Ssa_HasGeneratorCompatibilityVersion()                                                        /**< Deactivateable: 'Ssa_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Ssa_HasIgnoreCodingVerificationResultOfGeneral()                                            (TRUE != FALSE)
#define Ssa_HasIgnoreSecureBroadcastVerificationResultOfGeneral()                                   (TRUE != FALSE)
#define Ssa_HasInitDataHashCode()                                                                     /**< Deactivateable: 'Ssa_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Ssa_HasKeepBufferVariablesStaticOfGeneral()                                                 (TRUE != FALSE)
#define Ssa_HasLocalTickCountSynchronizationTimeoutOfFvM()                                          (TRUE != FALSE)
#define Ssa_HasLoggingActiveTimeoutOfSecLog()                                                       (TRUE != FALSE)
#define Ssa_HasMaxDidListLengthOfRightsM()                                                          (TRUE != FALSE)
#define Ssa_HasNumberKeysGeneratedInMainOfKeyM()                                                    (TRUE != FALSE)
#define Ssa_HasNumberRetriesKeyGenerationOfKeyM()                                                   (TRUE != FALSE)
#define Ssa_HasNumberWaitCyclesBeforeKeyGenerationOfKeyM()                                          (TRUE != FALSE)
#define Ssa_HasPercentageLocalTickCountSlowdownOfFvM()                                              (TRUE != FALSE)
#define Ssa_HasPercentageTurningBackLocalTickCountOfFvM()                                           (TRUE != FALSE)
#define Ssa_HasPostProductionStatusActivationMileageThresholdOfRightsM()                            (TRUE != FALSE)
#define Ssa_HasRightsM_TesterToChannel()                                                            (TRUE != FALSE)
#define Ssa_HasRtcCorrectionToleranceOfFvM()                                                        (TRUE != FALSE)
#define Ssa_HasRtcResolutionOfFvM()                                                                 (TRUE != FALSE)
#define Ssa_HasSecLogInfo()                                                                         (TRUE != FALSE)
#define Ssa_HasDataIdInfoIdxOfSecLogInfo()                                                          (TRUE != FALSE)
#define Ssa_HasSecuredTickCountCycleTimeOfFvM()                                                     (TRUE != FALSE)
#define Ssa_HasSecuredTickCountStartupCycleDurationOfFvM()                                          (TRUE != FALSE)
#define Ssa_HasSecuredTickCountStartupCycleTimeOfFvM()                                              (TRUE != FALSE)
#define Ssa_HasSecurityAccessLevel()                                                                (TRUE != FALSE)
#define Ssa_HasJobIdOfSecurityAccessLevel()                                                         (TRUE != FALSE)
#define Ssa_HasLevelOfSecurityAccessLevel()                                                         (TRUE != FALSE)
#define Ssa_HasSizeOfCodingDid()                                                                    (TRUE != FALSE)
#define Ssa_HasSizeOfCodingNvMBlock()                                                               (TRUE != FALSE)
#define Ssa_HasSizeOfDataIdInfo()                                                                   (TRUE != FALSE)
#define Ssa_HasSizeOfDidHandled()                                                                   (TRUE != FALSE)
#define Ssa_HasSizeOfRightsM_TesterToChannel()                                                      (TRUE != FALSE)
#define Ssa_HasSizeOfSecLogInfo()                                                                   (TRUE != FALSE)
#define Ssa_HasSizeOfSecurityAccessLevel()                                                          (TRUE != FALSE)
#define Ssa_HasSizeOfTrustModelBackendCertName()                                                    (TRUE != FALSE)
#define Ssa_HasSizeOfTrustModelBackendPeerCertName()                                                (TRUE != FALSE)
#define Ssa_HasSizeOfTrustModelEcuCertName()                                                        (TRUE != FALSE)
#define Ssa_HasSizeOfTrustModelEcuCsrCertName()                                                     (TRUE != FALSE)
#define Ssa_HasSizeOfTrustModelEcuPeerCertName()                                                    (TRUE != FALSE)
#define Ssa_HasSizeOfTrustModelIntermediateCertName()                                               (TRUE != FALSE)
#define Ssa_HasSizeOfTrustModelIntermediatePeerCertName()                                           (TRUE != FALSE)
#define Ssa_HasSizeOfTrustModelRootCertName()                                                       (TRUE != FALSE)
#define Ssa_HasSizeOfUniqueEcuId()                                                                  (TRUE != FALSE)
#define Ssa_HasSizeOfUniqueEcuIds()                                                                 (TRUE != FALSE)
#define Ssa_HasTimeoutOfCoding()                                                                    (TRUE != FALSE)
#define Ssa_HasTrustModelBackendCertName()                                                          (TRUE != FALSE)
#define Ssa_HasTrustModelBackendPeerCertName()                                                      (TRUE != FALSE)
#define Ssa_HasTrustModelEcuCertName()                                                              (TRUE != FALSE)
#define Ssa_HasTrustModelEcuCsrCertName()                                                           (TRUE != FALSE)
#define Ssa_HasTrustModelEcuCsrRefOfKeyM()                                                          (TRUE != FALSE)
#define Ssa_HasTrustModelEcuPeerCertName()                                                          (TRUE != FALSE)
#define Ssa_HasTrustModelIntermediateCertName()                                                     (TRUE != FALSE)
#define Ssa_HasTrustModelIntermediatePeerCertName()                                                 (TRUE != FALSE)
#define Ssa_HasTrustModelRootCertName()                                                             (TRUE != FALSE)
#define Ssa_HasUniqueEcuId()                                                                        (TRUE != FALSE)
#define Ssa_HasUniqueEcuIdsUniqueEcuIdsEndIdxOfUniqueEcuId()                                        (TRUE != FALSE)
#define Ssa_HasUniqueEcuIdsUniqueEcuIdsStartIdxOfUniqueEcuId()                                      (TRUE != FALSE)
#define Ssa_HasUniqueEcuIds()                                                                       (TRUE != FALSE)
#define Ssa_HasUnlimitedTurningBackOfTickCountOfFvM()                                               (TRUE != FALSE)
#define Ssa_HasUsePimAccessMacrosAsCompileTimeConstantsOfSecLog()                                   (TRUE != FALSE)
#define Ssa_HasVINReceiveTimeoutOfCoding()                                                          (TRUE != FALSE)
#define Ssa_HasPCConfig()                                                                           (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeAuthorizationBySecurityAccessEventOfSecLogOfPCConfig()             (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeChangeOfTickCountOrDateAndTimeEventOfSecLogOfPCConfig()            (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeChangeOfVinEventOfSecLogOfPCConfig()                               (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeEcuIndividualAclReplacementEventOfSecLogOfPCConfig()               (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeFailedCertificateVerificationEventOfSecLogOfPCConfig()             (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeFailedPduMacVerificationEventOfSecLogOfPCConfig()                  (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeRightsManagementEventOfSecLogOfPCConfig()                          (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeSecocMisconfigurationEventOfSecLogOfPCConfig()                     (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeSecureBootOrAuthenticatedBootEventOfSecLogOfPCConfig()             (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeSignatureVerificationEventOfSecLogOfPCConfig()                     (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeSuccessfulAuthenticationAndEnhanceRightsEventOfSecLogOfPCConfig()  (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeSuccessfulCertificateVerificationEventOfSecLogOfPCConfig()         (TRUE != FALSE)
#define Ssa_HasCircularBufferSizeSuccessfulDiagnosticServiceExecutionEventOfSecLogOfPCConfig()      (TRUE != FALSE)
#define Ssa_HasCodingDidOfPCConfig()                                                                (TRUE != FALSE)
#define Ssa_HasCodingNvMBlockOfPCConfig()                                                           (TRUE != FALSE)
#define Ssa_HasDEV_ERROR_DETECTOfGeneralOfPCConfig()                                                (TRUE != FALSE)
#define Ssa_HasDataBufferSizeOfCodingOfPCConfig()                                                   (TRUE != FALSE)
#define Ssa_HasDataIdInfoOfPCConfig()                                                               (TRUE != FALSE)
#define Ssa_HasDebounceTimeDetectionMissingTickCountMessagesOfFvMOfPCConfig()                       (TRUE != FALSE)
#define Ssa_HasDebounceTimeDetectionRejectedTickCountMessagesOfFvMOfPCConfig()                      (TRUE != FALSE)
#define Ssa_HasDebounceTimeDetectionUnautheticatedTickCountMessagesOfFvMOfPCConfig()                (TRUE != FALSE)
#define Ssa_HasDecoupleExternalProcessingService29OfGeneralOfPCConfig()                             (TRUE != FALSE)
#define Ssa_HasDiagServiceInjectSeedOfGeneralOfPCConfig()                                           (TRUE != FALSE)
#define Ssa_HasDiagServiceTrustModelGenerateKeyPairOfGeneralOfPCConfig()                            (TRUE != FALSE)
#define Ssa_HasDidHandledOfPCConfig()                                                               (TRUE != FALSE)
#define Ssa_HasEcuIndividualAclPtrNameOfRightsMOfPCConfig()                                         (TRUE != FALSE)
#define Ssa_HasEcuTypeOfGeneralOfPCConfig()                                                         (TRUE != FALSE)
#define Ssa_HasEnableAsyncCsmJobProcessingOfGeneralOfPCConfig()                                     (TRUE != FALSE)
#define Ssa_HasEnableAsyncCsmKeyManagementPrimitivesOfGeneralOfPCConfig()                           (TRUE != FALSE)
#define Ssa_HasEnableBufferHandlingOfProcCtrlOfPCConfig()                                           (TRUE != FALSE)
#define Ssa_HasEnableDebugAuthenticationOfGeneralOfPCConfig()                                       (TRUE != FALSE)
#define Ssa_HasEnableDebugAuthenticationStatusOfGeneralOfPCConfig()                                 (TRUE != FALSE)
#define Ssa_HasEnableDebugNonceOfGeneralOfPCConfig()                                                (TRUE != FALSE)
#define Ssa_HasEnableDebugRightsOfGeneralOfPCConfig()                                               (TRUE != FALSE)
#define Ssa_HasEnhancedAccessRightsTableSizeOfRightsMOfPCConfig()                                   (TRUE != FALSE)
#define Ssa_HasExpectedCompatibilityVersionOfPCConfig()                                               /**< Deactivateable: 'Ssa_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Ssa_HasFailedMacVerificationCounterThreshold1OfSecLogOfPCConfig()                           (TRUE != FALSE)
#define Ssa_HasFailedMacVerificationCounterThreshold2OfSecLogOfPCConfig()                           (TRUE != FALSE)
#define Ssa_HasFailedMacVerificationCounterThreshold3OfSecLogOfPCConfig()                           (TRUE != FALSE)
#define Ssa_HasFailedMacVerificationCounterThresholdDtcOfSecLogOfPCConfig()                         (TRUE != FALSE)
#define Ssa_HasFinalMagicNumberOfPCConfig()                                                           /**< Deactivateable: 'Ssa_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Ssa_HasGenerateKeyPairCustomCalloutOfGeneralOfPCConfig()                                    (TRUE != FALSE)
#define Ssa_HasGeneratorCompatibilityVersionOfPCConfig()                                              /**< Deactivateable: 'Ssa_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Ssa_HasIgnoreCodingVerificationResultOfGeneralOfPCConfig()                                  (TRUE != FALSE)
#define Ssa_HasIgnoreSecureBroadcastVerificationResultOfGeneralOfPCConfig()                         (TRUE != FALSE)
#define Ssa_HasInitDataHashCodeOfPCConfig()                                                           /**< Deactivateable: 'Ssa_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Ssa_HasKeepBufferVariablesStaticOfGeneralOfPCConfig()                                       (TRUE != FALSE)
#define Ssa_HasLocalTickCountSynchronizationTimeoutOfFvMOfPCConfig()                                (TRUE != FALSE)
#define Ssa_HasLoggingActiveTimeoutOfSecLogOfPCConfig()                                             (TRUE != FALSE)
#define Ssa_HasMaxDidListLengthOfRightsMOfPCConfig()                                                (TRUE != FALSE)
#define Ssa_HasNumberKeysGeneratedInMainOfKeyMOfPCConfig()                                          (TRUE != FALSE)
#define Ssa_HasNumberRetriesKeyGenerationOfKeyMOfPCConfig()                                         (TRUE != FALSE)
#define Ssa_HasNumberWaitCyclesBeforeKeyGenerationOfKeyMOfPCConfig()                                (TRUE != FALSE)
#define Ssa_HasPercentageLocalTickCountSlowdownOfFvMOfPCConfig()                                    (TRUE != FALSE)
#define Ssa_HasPercentageTurningBackLocalTickCountOfFvMOfPCConfig()                                 (TRUE != FALSE)
#define Ssa_HasPostProductionStatusActivationMileageThresholdOfRightsMOfPCConfig()                  (TRUE != FALSE)
#define Ssa_HasRightsM_TesterToChannelOfPCConfig()                                                  (TRUE != FALSE)
#define Ssa_HasRtcCorrectionToleranceOfFvMOfPCConfig()                                              (TRUE != FALSE)
#define Ssa_HasRtcResolutionOfFvMOfPCConfig()                                                       (TRUE != FALSE)
#define Ssa_HasSecLogInfoOfPCConfig()                                                               (TRUE != FALSE)
#define Ssa_HasSecuredTickCountCycleTimeOfFvMOfPCConfig()                                           (TRUE != FALSE)
#define Ssa_HasSecuredTickCountStartupCycleDurationOfFvMOfPCConfig()                                (TRUE != FALSE)
#define Ssa_HasSecuredTickCountStartupCycleTimeOfFvMOfPCConfig()                                    (TRUE != FALSE)
#define Ssa_HasSecurityAccessLevelOfPCConfig()                                                      (TRUE != FALSE)
#define Ssa_HasSizeOfCodingDidOfPCConfig()                                                          (TRUE != FALSE)
#define Ssa_HasSizeOfCodingNvMBlockOfPCConfig()                                                     (TRUE != FALSE)
#define Ssa_HasSizeOfDataIdInfoOfPCConfig()                                                         (TRUE != FALSE)
#define Ssa_HasSizeOfDidHandledOfPCConfig()                                                         (TRUE != FALSE)
#define Ssa_HasSizeOfRightsM_TesterToChannelOfPCConfig()                                            (TRUE != FALSE)
#define Ssa_HasSizeOfSecLogInfoOfPCConfig()                                                         (TRUE != FALSE)
#define Ssa_HasSizeOfSecurityAccessLevelOfPCConfig()                                                (TRUE != FALSE)
#define Ssa_HasSizeOfTrustModelBackendCertNameOfPCConfig()                                          (TRUE != FALSE)
#define Ssa_HasSizeOfTrustModelBackendPeerCertNameOfPCConfig()                                      (TRUE != FALSE)
#define Ssa_HasSizeOfTrustModelEcuCertNameOfPCConfig()                                              (TRUE != FALSE)
#define Ssa_HasSizeOfTrustModelEcuCsrCertNameOfPCConfig()                                           (TRUE != FALSE)
#define Ssa_HasSizeOfTrustModelEcuPeerCertNameOfPCConfig()                                          (TRUE != FALSE)
#define Ssa_HasSizeOfTrustModelIntermediateCertNameOfPCConfig()                                     (TRUE != FALSE)
#define Ssa_HasSizeOfTrustModelIntermediatePeerCertNameOfPCConfig()                                 (TRUE != FALSE)
#define Ssa_HasSizeOfTrustModelRootCertNameOfPCConfig()                                             (TRUE != FALSE)
#define Ssa_HasSizeOfUniqueEcuIdOfPCConfig()                                                        (TRUE != FALSE)
#define Ssa_HasSizeOfUniqueEcuIdsOfPCConfig()                                                       (TRUE != FALSE)
#define Ssa_HasTimeoutOfCodingOfPCConfig()                                                          (TRUE != FALSE)
#define Ssa_HasTrustModelBackendCertNameOfPCConfig()                                                (TRUE != FALSE)
#define Ssa_HasTrustModelBackendPeerCertNameOfPCConfig()                                            (TRUE != FALSE)
#define Ssa_HasTrustModelEcuCertNameOfPCConfig()                                                    (TRUE != FALSE)
#define Ssa_HasTrustModelEcuCsrCertNameOfPCConfig()                                                 (TRUE != FALSE)
#define Ssa_HasTrustModelEcuCsrRefOfKeyMOfPCConfig()                                                (TRUE != FALSE)
#define Ssa_HasTrustModelEcuPeerCertNameOfPCConfig()                                                (TRUE != FALSE)
#define Ssa_HasTrustModelIntermediateCertNameOfPCConfig()                                           (TRUE != FALSE)
#define Ssa_HasTrustModelIntermediatePeerCertNameOfPCConfig()                                       (TRUE != FALSE)
#define Ssa_HasTrustModelRootCertNameOfPCConfig()                                                   (TRUE != FALSE)
#define Ssa_HasUniqueEcuIdOfPCConfig()                                                              (TRUE != FALSE)
#define Ssa_HasUniqueEcuIdsOfPCConfig()                                                             (TRUE != FALSE)
#define Ssa_HasUnlimitedTurningBackOfTickCountOfFvMOfPCConfig()                                     (TRUE != FALSE)
#define Ssa_HasUsePimAccessMacrosAsCompileTimeConstantsOfSecLogOfPCConfig()                         (TRUE != FALSE)
#define Ssa_HasVINReceiveTimeoutOfCodingOfPCConfig()                                                (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCIncrementDataMacros  Ssa Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Ssa_IncDidHandled(Index)                                                                    Ssa_GetDidHandled(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCDecrementDataMacros  Ssa Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Ssa_DecDidHandled(Index)                                                                    Ssa_GetDidHandled(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCAddDataMacros  Ssa Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define Ssa_AddDidHandled(Index, Value)                                                             Ssa_SetDidHandled(Index, (Ssa_GetDidHandled(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCSubstractDataMacros  Ssa Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define Ssa_SubDidHandled(Index, Value)                                                             Ssa_SetDidHandled(Index, (Ssa_GetDidHandled(Index) - Value))
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  SsaPBGetRootDataMacros  Ssa Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Ssa_GetLTConfigIdxOfPBConfig()                                                                /**< Deactivateable: 'Ssa_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Ssa_GetPCConfigIdxOfPBConfig()                                                                /**< Deactivateable: 'Ssa_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  SsaPBHasMacros  Ssa Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Ssa_HasPBConfig()                                                                             /**< Deactivateable: 'Ssa_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Ssa_HasLTConfigIdxOfPBConfig()                                                                /**< Deactivateable: 'Ssa_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Ssa_HasPCConfigIdxOfPBConfig()                                                                /**< Deactivateable: 'Ssa_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/






/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#define SSA_DATAID_TICKCOUNT                                                                        0xFFFFu
#define SSA_DATAID_DIAGNOSTICAUTHENTICATION                                                         0xFFFCu
#define SSA_DATAID_REALTIME                                                                         0xFFFEu
#define SSA_DATAID_VIN                                                                              0xFFFDu
                                                                                                    
#define SSA_ROUTINE_INFO_SUCCESFULLY_COMPLETED                                                      0x00u
#define SSA_ROUTINE_INFO_IN_PROGRESS                                                                0x01u
#define SSA_ROUTINE_INFO_STOPPED_WITHOUT_RESULTS                                                    0x02u
                                                                                                    
#define SSA_SIZEOF_SIGNATURE                                                                        64u
#define SSA_SIZEOF_PRIVATE_KEY                                                                      32u
#define SSA_SIZEOF_PUBLICKEY                                                                        32u
#define SSA_SIZEOF_SERIALNUMBER                                                                     16u
#define SSA_SIZEOF_BACKEND_SERIALNUMBER                                                             2u
                                                                                                    
#define SSA_SIZEOF_SECRET                                                                           32u
#define SSA_SIZEOF_SECRETHASH                                                                       4u
#define SSA_SIZEOF_KEY_EXCHANGE_SECRET                                                              32u
#define SSA_SIZEOF_NONCE                                                                            32u
#define SSA_SIZEOF_HASHVALUE                                                                        64u
#define SSA_SIZEOF_SYMKEY                                                                           16u
#define SSA_SIZEOF_KEY_CHECKSUM                                                                     4u
#define SSA_SIZEOF_CERT_MAX                                                                         910u
#define SSA_SIZEOF_CERT_SUBJECT_KEY_ID                                                              20u
#define SSA_SIZEOF_ISSUER                                                                           15u
#define SSA_SIZEOF_VIN                                                                              17u 
                                                                                                    
#define SSA_SIZEOF_ENCRYPTED_NONCE_AND_SECRET                                                       (SSA_SIZEOF_NONCE + SSA_SIZEOF_SECRET + 16u)
                                                                                                    
/* 2 year + month + day + hour + minute + second */
#define SSA_SIZEOF_REALTIME                                                                         (7u)
/* 40 Bit */                                                                                        
#define SSA_SIZEOF_TICKCOUNT                                                                        (5u)
                                                                                                    
                                                                                                    
#define SSA_RIGHTSM_SIZEOF_CHALLENGE_ECU                                                            32u
#define SSA_RIGHTSM_SIZEOF_SYNC_TIME_NONCE                                                          32u
#define SSA_RIGHTSM_SIZEOF_CHALLENGE_TESTER                                                         32u
                                                                                                    
#define SSA_RIGHTSM_SIZEOF_AUTHENTICATION_BROADCAST                                                 20u
                                                                                                    
#define SSA_RIGHTSM_DIAG_SERVICE_SESSION_CONTROL                                                    0x10u
#define SSA_RIGHTSM_DIAG_SESSION_ID_DEFAULT                                                         0x01u
                                                                                                    
#define SSA_RIGHTSM_DIAG_INVALID_CHAN_ID                                                            SSA_RIGHTSM_NUMBER_DIAGNOSTIC_CHANNELS
#define SSA_RIGHTSM_DIAG_INVALID_CHANNEL                                                            (0xFFu)
                                                                                                    
#define SSA_RIGHTSM_AUTHENTICATION_BROADCAST_CYCLE_TIME                                             100u /* 1 second */
#define SSA_RIGHTSM_AUTHENTICATION_TIMEOUT                                                          2000u /* 20 seconds */
                                                                                                    
                                                                                                    
#define SECLOG_SIZEOF_SIGNATURE                                                                     (64u)
#define SECLOG_SIZEOF_TICKCOUNT                                                                     (5u)
#define SECLOG_SIZEOF_REALTIME                                                                      (15u)
#define SECLOG_SIZE_OF_READ_DATA_LENGTH                                                             (2u)
#define SECLOG_SIZEOF_CIRCULAR_BUFFER_OUTPUT_OVERHEAD                                               (3u)
#define SECLOG_SIZEOF_GLOBAL_EVENT_COUNTERS_OUTPUT_OVERHEAD                                         ((SSA_SECLOG_MAX_NUMBER_OF_DATA_IDS * 2u) + 8u)
                                                                                                    
/* Types of events */                                                                               
#define SECLOG_EVENT_FAILED_CERTIFICATE_VERIFICATION                                                (0u)   /**< Failed certificate verification events */
#define SECLOG_EVENT_SUCCESSFUL_CERTIFICATE_VERIFICATION                                            (1u)   /**< Successful certificate verification events */
#define SECLOG_EVENT_SUCCESSFUL_AUTHENTICATION_AND_ENHANCE_RIGHTS                                   (2u)   /**< Successful authentication and enhance rights events */
#define SECLOG_EVENT_AUTHORIZATION_SECURITY_ACCESS                                                  (3u)   /**< Authorization by Security Access events */
#define SECLOG_EVENT_SUCCESSFUL_DIAGNOSTIC_SERVICE_EXECUTION                                        (4u)   /**< Successful diagnostic service execution events */
#define SECLOG_EVENT_RIGHTS_MANAGEMENT                                                              (5u)   /**< Rights management events */
#define SECLOG_EVENT_SIGNATURE_VERIFICATION                                                         (6u)   /**< Signature verification events */
#define SECLOG_EVENT_CHANGE_TICK_COUNT_OR_DATE_AND_TIME                                             (7u)   /**< Change of tick count or date and time events */
#define SECLOG_EVENT_SECOC_MISCONFIGURATION                                                         (8u)   /**< SecOC misconfiguration events */
#define SECLOG_EVENT_FAILED_SECOC_MAC_VERIFICATION                                                  (9u)   /**< Failed SecOC MAC verification events */
#define SECLOG_EVENT_SECURE_BOOT_OR_AUTHENTICATED_BOOT                                              (10u)  /**< Secure boot or authenticated boot events */
#define SECLOG_EVENT_CHANGE_VIN                                                                     (11u)  /**< Change of VIN events */
#define SECLOG_EVENT_ECU_INDIVIDUAL_ACL_REPLACEMENT                                                 (12u)  /**< ECU-individual AccessControlList replacement events */
#define SECLOG_NVM_BLOCK_TABLE_TH1                                                                  (13u)  /**< Global counters for exceeding threshold 1 */
#define SECLOG_NVM_BLOCK_TABLE_TH2                                                                  (14u)  /**< Global counters for exceeding threshold 2 */
#define SECLOG_NVM_BLOCK_TABLE_TH3                                                                  (15u)  /**< Global counters for exceeding threshold 3 */





/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  SsaPCIterableTypes  Ssa Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Ssa_CodingDid */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfCodingDid() } \endspec */ 
typedef uint8_least Ssa_CodingDidIterType;

/**   \brief  type used to iterate Ssa_CodingNvMBlock */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfCodingNvMBlock() } \endspec */ 
typedef uint8_least Ssa_CodingNvMBlockIterType;

/**   \brief  type used to iterate Ssa_DataIdInfo */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfDataIdInfo() } \endspec */ 
typedef uint8_least Ssa_DataIdInfoIterType;

/**   \brief  type used to iterate Ssa_DidHandled */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfDidHandled() } \endspec */ 
typedef uint8_least Ssa_DidHandledIterType;

/**   \brief  type used to iterate Ssa_RightsM_TesterToChannel */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfRightsM_TesterToChannel() } \endspec */ 
typedef uint8_least Ssa_RightsM_TesterToChannelIterType;

/**   \brief  type used to iterate Ssa_SecLogInfo */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfSecLogInfo() } \endspec */ 
typedef uint8_least Ssa_SecLogInfoIterType;

/**   \brief  type used to iterate Ssa_SecurityAccessLevel */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfSecurityAccessLevel() } \endspec */ 
typedef uint8_least Ssa_SecurityAccessLevelIterType;

/**   \brief  type used to iterate Ssa_TrustModelBackendCertName */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfTrustModelBackendCertName() } \endspec */ 
typedef uint8_least Ssa_TrustModelBackendCertNameIterType;

/**   \brief  type used to iterate Ssa_TrustModelBackendPeerCertName */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfTrustModelBackendPeerCertName() } \endspec */ 
typedef uint8_least Ssa_TrustModelBackendPeerCertNameIterType;

/**   \brief  type used to iterate Ssa_TrustModelEcuCertName */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfTrustModelEcuCertName() } \endspec */ 
typedef uint8_least Ssa_TrustModelEcuCertNameIterType;

/**   \brief  type used to iterate Ssa_TrustModelEcuCsrCertName */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfTrustModelEcuCsrCertName() } \endspec */ 
typedef uint8_least Ssa_TrustModelEcuCsrCertNameIterType;

/**   \brief  type used to iterate Ssa_TrustModelEcuPeerCertName */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfTrustModelEcuPeerCertName() } \endspec */ 
typedef uint8_least Ssa_TrustModelEcuPeerCertNameIterType;

/**   \brief  type used to iterate Ssa_TrustModelIntermediateCertName */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfTrustModelIntermediateCertName() } \endspec */ 
typedef uint8_least Ssa_TrustModelIntermediateCertNameIterType;

/**   \brief  type used to iterate Ssa_TrustModelIntermediatePeerCertName */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfTrustModelIntermediatePeerCertName() } \endspec */ 
typedef uint8_least Ssa_TrustModelIntermediatePeerCertNameIterType;

/**   \brief  type used to iterate Ssa_TrustModelRootCertName */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfTrustModelRootCertName() } \endspec */ 
typedef uint8_least Ssa_TrustModelRootCertNameIterType;

/**   \brief  type used to iterate Ssa_UniqueEcuId */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfUniqueEcuId() } \endspec */ 
typedef uint8_least Ssa_UniqueEcuIdIterType;

/**   \brief  type used to iterate Ssa_UniqueEcuIds */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfUniqueEcuIds() } \endspec */ 
typedef uint8_least Ssa_UniqueEcuIdsIterType;

/** 
  \}
*/ 

/** 
  \defgroup  SsaPCValueTypes  Ssa Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Ssa_CircularBufferSizeAuthorizationBySecurityAccessEventOfSecLog */
typedef uint8 Ssa_CircularBufferSizeAuthorizationBySecurityAccessEventOfSecLogType;

/**   \brief  value based type definition for Ssa_CircularBufferSizeChangeOfTickCountOrDateAndTimeEventOfSecLog */
typedef uint8 Ssa_CircularBufferSizeChangeOfTickCountOrDateAndTimeEventOfSecLogType;

/**   \brief  value based type definition for Ssa_CircularBufferSizeChangeOfVinEventOfSecLog */
typedef uint8 Ssa_CircularBufferSizeChangeOfVinEventOfSecLogType;

/**   \brief  value based type definition for Ssa_CircularBufferSizeEcuIndividualAclReplacementEventOfSecLog */
typedef uint8 Ssa_CircularBufferSizeEcuIndividualAclReplacementEventOfSecLogType;

/**   \brief  value based type definition for Ssa_CircularBufferSizeFailedCertificateVerificationEventOfSecLog */
typedef uint8 Ssa_CircularBufferSizeFailedCertificateVerificationEventOfSecLogType;

/**   \brief  value based type definition for Ssa_CircularBufferSizeFailedPduMacVerificationEventOfSecLog */
typedef uint8 Ssa_CircularBufferSizeFailedPduMacVerificationEventOfSecLogType;

/**   \brief  value based type definition for Ssa_CircularBufferSizeRightsManagementEventOfSecLog */
typedef uint8 Ssa_CircularBufferSizeRightsManagementEventOfSecLogType;

/**   \brief  value based type definition for Ssa_CircularBufferSizeSecocMisconfigurationEventOfSecLog */
typedef uint8 Ssa_CircularBufferSizeSecocMisconfigurationEventOfSecLogType;

/**   \brief  value based type definition for Ssa_CircularBufferSizeSecureBootOrAuthenticatedBootEventOfSecLog */
typedef uint8 Ssa_CircularBufferSizeSecureBootOrAuthenticatedBootEventOfSecLogType;

/**   \brief  value based type definition for Ssa_CircularBufferSizeSignatureVerificationEventOfSecLog */
typedef uint8 Ssa_CircularBufferSizeSignatureVerificationEventOfSecLogType;

/**   \brief  value based type definition for Ssa_CircularBufferSizeSuccessfulAuthenticationAndEnhanceRightsEventOfSecLog */
typedef uint8 Ssa_CircularBufferSizeSuccessfulAuthenticationAndEnhanceRightsEventOfSecLogType;

/**   \brief  value based type definition for Ssa_CircularBufferSizeSuccessfulCertificateVerificationEventOfSecLog */
typedef uint8 Ssa_CircularBufferSizeSuccessfulCertificateVerificationEventOfSecLogType;

/**   \brief  value based type definition for Ssa_CircularBufferSizeSuccessfulDiagnosticServiceExecutionEventOfSecLog */
typedef uint8 Ssa_CircularBufferSizeSuccessfulDiagnosticServiceExecutionEventOfSecLogType;

/**   \brief  value based type definition for Ssa_CodingDid */
typedef uint16 Ssa_CodingDidType;

/**   \brief  value based type definition for Ssa_CodingNvMBlock */
typedef uint16 Ssa_CodingNvMBlockType;

/**   \brief  value based type definition for Ssa_DEV_ERROR_DETECTOfGeneral */
typedef boolean Ssa_DEV_ERROR_DETECTOfGeneralType;

/**   \brief  value based type definition for Ssa_DataBufferSizeOfCoding */
typedef uint16 Ssa_DataBufferSizeOfCodingType;

/**   \brief  value based type definition for Ssa_DataIdOfDataIdInfo */
typedef uint16 Ssa_DataIdOfDataIdInfoType;

/**   \brief  value based type definition for Ssa_KeyIdOfDataIdInfo */
typedef uint32 Ssa_KeyIdOfDataIdInfoType;

/**   \brief  value based type definition for Ssa_ThresholdOfDataIdInfo */
typedef uint8 Ssa_ThresholdOfDataIdInfoType;

/**   \brief  value based type definition for Ssa_DebounceTimeDetectionMissingTickCountMessagesOfFvM */
typedef uint16 Ssa_DebounceTimeDetectionMissingTickCountMessagesOfFvMType;

/**   \brief  value based type definition for Ssa_DebounceTimeDetectionRejectedTickCountMessagesOfFvM */
typedef uint16 Ssa_DebounceTimeDetectionRejectedTickCountMessagesOfFvMType;

/**   \brief  value based type definition for Ssa_DebounceTimeDetectionUnautheticatedTickCountMessagesOfFvM */
typedef uint16 Ssa_DebounceTimeDetectionUnautheticatedTickCountMessagesOfFvMType;

/**   \brief  value based type definition for Ssa_DecoupleExternalProcessingService29OfGeneral */
typedef boolean Ssa_DecoupleExternalProcessingService29OfGeneralType;

/**   \brief  value based type definition for Ssa_DiagServiceInjectSeedOfGeneral */
typedef boolean Ssa_DiagServiceInjectSeedOfGeneralType;

/**   \brief  value based type definition for Ssa_DiagServiceTrustModelGenerateKeyPairOfGeneral */
typedef boolean Ssa_DiagServiceTrustModelGenerateKeyPairOfGeneralType;

/**   \brief  value based type definition for Ssa_DidHandled */
typedef uint32 Ssa_DidHandledType;

/**   \brief  value based type definition for Ssa_EcuIndividualAclPtrNameOfRightsM */
typedef uint32 Ssa_EcuIndividualAclPtrNameOfRightsMType;

/**   \brief  value based type definition for Ssa_EcuTypeOfGeneral */
typedef uint8 Ssa_EcuTypeOfGeneralType;

/**   \brief  value based type definition for Ssa_EnableAsyncCsmJobProcessingOfGeneral */
typedef boolean Ssa_EnableAsyncCsmJobProcessingOfGeneralType;

/**   \brief  value based type definition for Ssa_EnableAsyncCsmKeyManagementPrimitivesOfGeneral */
typedef boolean Ssa_EnableAsyncCsmKeyManagementPrimitivesOfGeneralType;

/**   \brief  value based type definition for Ssa_EnableBufferHandlingOfProcCtrl */
typedef boolean Ssa_EnableBufferHandlingOfProcCtrlType;

/**   \brief  value based type definition for Ssa_EnableDebugAuthenticationOfGeneral */
typedef boolean Ssa_EnableDebugAuthenticationOfGeneralType;

/**   \brief  value based type definition for Ssa_EnableDebugAuthenticationStatusOfGeneral */
typedef boolean Ssa_EnableDebugAuthenticationStatusOfGeneralType;

/**   \brief  value based type definition for Ssa_EnableDebugNonceOfGeneral */
typedef boolean Ssa_EnableDebugNonceOfGeneralType;

/**   \brief  value based type definition for Ssa_EnableDebugRightsOfGeneral */
typedef boolean Ssa_EnableDebugRightsOfGeneralType;

/**   \brief  value based type definition for Ssa_EnhancedAccessRightsTableSizeOfRightsM */
typedef uint16 Ssa_EnhancedAccessRightsTableSizeOfRightsMType;

/**   \brief  value based type definition for Ssa_FailedMacVerificationCounterThreshold1OfSecLog */
typedef uint8 Ssa_FailedMacVerificationCounterThreshold1OfSecLogType;

/**   \brief  value based type definition for Ssa_FailedMacVerificationCounterThreshold2OfSecLog */
typedef uint16 Ssa_FailedMacVerificationCounterThreshold2OfSecLogType;

/**   \brief  value based type definition for Ssa_FailedMacVerificationCounterThreshold3OfSecLog */
typedef uint16 Ssa_FailedMacVerificationCounterThreshold3OfSecLogType;

/**   \brief  value based type definition for Ssa_FailedMacVerificationCounterThresholdDtcOfSecLog */
typedef uint8 Ssa_FailedMacVerificationCounterThresholdDtcOfSecLogType;

/**   \brief  value based type definition for Ssa_GenerateKeyPairCustomCalloutOfGeneral */
typedef boolean Ssa_GenerateKeyPairCustomCalloutOfGeneralType;

/**   \brief  value based type definition for Ssa_IgnoreCodingVerificationResultOfGeneral */
typedef boolean Ssa_IgnoreCodingVerificationResultOfGeneralType;

/**   \brief  value based type definition for Ssa_IgnoreSecureBroadcastVerificationResultOfGeneral */
typedef boolean Ssa_IgnoreSecureBroadcastVerificationResultOfGeneralType;

/**   \brief  value based type definition for Ssa_KeepBufferVariablesStaticOfGeneral */
typedef boolean Ssa_KeepBufferVariablesStaticOfGeneralType;

/**   \brief  value based type definition for Ssa_LocalTickCountSynchronizationTimeoutOfFvM */
typedef uint16 Ssa_LocalTickCountSynchronizationTimeoutOfFvMType;

/**   \brief  value based type definition for Ssa_LoggingActiveTimeoutOfSecLog */
typedef uint8 Ssa_LoggingActiveTimeoutOfSecLogType;

/**   \brief  value based type definition for Ssa_MaxDidListLengthOfRightsM */
typedef uint8 Ssa_MaxDidListLengthOfRightsMType;

/**   \brief  value based type definition for Ssa_NumberKeysGeneratedInMainOfKeyM */
typedef uint16 Ssa_NumberKeysGeneratedInMainOfKeyMType;

/**   \brief  value based type definition for Ssa_NumberRetriesKeyGenerationOfKeyM */
typedef uint8 Ssa_NumberRetriesKeyGenerationOfKeyMType;

/**   \brief  value based type definition for Ssa_NumberWaitCyclesBeforeKeyGenerationOfKeyM */
typedef uint8 Ssa_NumberWaitCyclesBeforeKeyGenerationOfKeyMType;

/**   \brief  value based type definition for Ssa_PercentageLocalTickCountSlowdownOfFvM */
typedef uint8 Ssa_PercentageLocalTickCountSlowdownOfFvMType;

/**   \brief  value based type definition for Ssa_PercentageTurningBackLocalTickCountOfFvM */
typedef uint8 Ssa_PercentageTurningBackLocalTickCountOfFvMType;

/**   \brief  value based type definition for Ssa_PostProductionStatusActivationMileageThresholdOfRightsM */
typedef uint32 Ssa_PostProductionStatusActivationMileageThresholdOfRightsMType;

/**   \brief  value based type definition for Ssa_RightsM_TesterToChannel */
typedef uint8 Ssa_RightsM_TesterToChannelType;

/**   \brief  value based type definition for Ssa_RtcCorrectionToleranceOfFvM */
typedef uint8 Ssa_RtcCorrectionToleranceOfFvMType;

/**   \brief  value based type definition for Ssa_RtcResolutionOfFvM */
typedef uint16 Ssa_RtcResolutionOfFvMType;

/**   \brief  value based type definition for Ssa_DataIdInfoIdxOfSecLogInfo */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfDataIdInfo() } \endspec */ 
typedef uint8 Ssa_DataIdInfoIdxOfSecLogInfoType;

/**   \brief  value based type definition for Ssa_SecuredTickCountCycleTimeOfFvM */
typedef uint8 Ssa_SecuredTickCountCycleTimeOfFvMType;

/**   \brief  value based type definition for Ssa_SecuredTickCountStartupCycleDurationOfFvM */
typedef uint16 Ssa_SecuredTickCountStartupCycleDurationOfFvMType;

/**   \brief  value based type definition for Ssa_SecuredTickCountStartupCycleTimeOfFvM */
typedef uint8 Ssa_SecuredTickCountStartupCycleTimeOfFvMType;

/**   \brief  value based type definition for Ssa_JobIdOfSecurityAccessLevel */
typedef uint8 Ssa_JobIdOfSecurityAccessLevelType;

/**   \brief  value based type definition for Ssa_LevelOfSecurityAccessLevel */
typedef uint8 Ssa_LevelOfSecurityAccessLevelType;

/**   \brief  value based type definition for Ssa_SizeOfCodingDid */
typedef uint8 Ssa_SizeOfCodingDidType;

/**   \brief  value based type definition for Ssa_SizeOfCodingNvMBlock */
typedef uint8 Ssa_SizeOfCodingNvMBlockType;

/**   \brief  value based type definition for Ssa_SizeOfDataIdInfo */
typedef uint8 Ssa_SizeOfDataIdInfoType;

/**   \brief  value based type definition for Ssa_SizeOfDidHandled */
typedef uint8 Ssa_SizeOfDidHandledType;

/**   \brief  value based type definition for Ssa_SizeOfRightsM_TesterToChannel */
typedef uint8 Ssa_SizeOfRightsM_TesterToChannelType;

/**   \brief  value based type definition for Ssa_SizeOfSecLogInfo */
typedef uint8 Ssa_SizeOfSecLogInfoType;

/**   \brief  value based type definition for Ssa_SizeOfSecurityAccessLevel */
typedef uint8 Ssa_SizeOfSecurityAccessLevelType;

/**   \brief  value based type definition for Ssa_SizeOfTrustModelBackendCertName */
typedef uint8 Ssa_SizeOfTrustModelBackendCertNameType;

/**   \brief  value based type definition for Ssa_SizeOfTrustModelBackendPeerCertName */
typedef uint8 Ssa_SizeOfTrustModelBackendPeerCertNameType;

/**   \brief  value based type definition for Ssa_SizeOfTrustModelEcuCertName */
typedef uint8 Ssa_SizeOfTrustModelEcuCertNameType;

/**   \brief  value based type definition for Ssa_SizeOfTrustModelEcuCsrCertName */
typedef uint8 Ssa_SizeOfTrustModelEcuCsrCertNameType;

/**   \brief  value based type definition for Ssa_SizeOfTrustModelEcuPeerCertName */
typedef uint8 Ssa_SizeOfTrustModelEcuPeerCertNameType;

/**   \brief  value based type definition for Ssa_SizeOfTrustModelIntermediateCertName */
typedef uint8 Ssa_SizeOfTrustModelIntermediateCertNameType;

/**   \brief  value based type definition for Ssa_SizeOfTrustModelIntermediatePeerCertName */
typedef uint8 Ssa_SizeOfTrustModelIntermediatePeerCertNameType;

/**   \brief  value based type definition for Ssa_SizeOfTrustModelRootCertName */
typedef uint8 Ssa_SizeOfTrustModelRootCertNameType;

/**   \brief  value based type definition for Ssa_SizeOfUniqueEcuId */
typedef uint8 Ssa_SizeOfUniqueEcuIdType;

/**   \brief  value based type definition for Ssa_SizeOfUniqueEcuIds */
typedef uint8 Ssa_SizeOfUniqueEcuIdsType;

/**   \brief  value based type definition for Ssa_TimeoutOfCoding */
typedef uint16 Ssa_TimeoutOfCodingType;

/**   \brief  value based type definition for Ssa_TrustModelBackendCertName */
typedef uint8 Ssa_TrustModelBackendCertNameType;

/**   \brief  value based type definition for Ssa_TrustModelBackendPeerCertName */
typedef uint8 Ssa_TrustModelBackendPeerCertNameType;

/**   \brief  value based type definition for Ssa_TrustModelEcuCertName */
typedef uint8 Ssa_TrustModelEcuCertNameType;

/**   \brief  value based type definition for Ssa_TrustModelEcuCsrCertName */
typedef uint8 Ssa_TrustModelEcuCsrCertNameType;

/**   \brief  value based type definition for Ssa_TrustModelEcuCsrRefOfKeyM */
typedef uint16 Ssa_TrustModelEcuCsrRefOfKeyMType;

/**   \brief  value based type definition for Ssa_TrustModelEcuPeerCertName */
typedef uint8 Ssa_TrustModelEcuPeerCertNameType;

/**   \brief  value based type definition for Ssa_TrustModelIntermediateCertName */
typedef uint8 Ssa_TrustModelIntermediateCertNameType;

/**   \brief  value based type definition for Ssa_TrustModelIntermediatePeerCertName */
typedef uint8 Ssa_TrustModelIntermediatePeerCertNameType;

/**   \brief  value based type definition for Ssa_TrustModelRootCertName */
typedef uint8 Ssa_TrustModelRootCertNameType;

/**   \brief  value based type definition for Ssa_UniqueEcuIdsUniqueEcuIdsEndIdxOfUniqueEcuId */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfUniqueEcuIds() } \endspec */ 
typedef uint8 Ssa_UniqueEcuIdsUniqueEcuIdsEndIdxOfUniqueEcuIdType;

/**   \brief  value based type definition for Ssa_UniqueEcuIdsUniqueEcuIdsStartIdxOfUniqueEcuId */
/*! \spec strong type invariant () { self < Ssa_GetSizeOfUniqueEcuIds() } \endspec */ 
typedef uint8 Ssa_UniqueEcuIdsUniqueEcuIdsStartIdxOfUniqueEcuIdType;

/**   \brief  value based type definition for Ssa_UniqueEcuIds */
typedef uint8 Ssa_UniqueEcuIdsType;

/**   \brief  value based type definition for Ssa_UnlimitedTurningBackOfTickCountOfFvM */
typedef boolean Ssa_UnlimitedTurningBackOfTickCountOfFvMType;

/**   \brief  value based type definition for Ssa_UsePimAccessMacrosAsCompileTimeConstantsOfSecLog */
typedef boolean Ssa_UsePimAccessMacrosAsCompileTimeConstantsOfSecLogType;

/**   \brief  value based type definition for Ssa_VINReceiveTimeoutOfCoding */
typedef uint16 Ssa_VINReceiveTimeoutOfCodingType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  SsaPCStructTypes  Ssa Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Ssa_DataIdInfo */
typedef struct sSsa_DataIdInfoType
{
  Ssa_KeyIdOfDataIdInfoType KeyIdOfDataIdInfo;
  Ssa_DataIdOfDataIdInfoType DataIdOfDataIdInfo;
  Ssa_ThresholdOfDataIdInfoType ThresholdOfDataIdInfo;
} Ssa_DataIdInfoType;

/**   \brief  type used in Ssa_SecLogInfo */
typedef struct sSsa_SecLogInfoType
{
  uint8 Ssa_SecLogInfoNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Ssa_SecLogInfoType;

/**   \brief  type used in Ssa_SecurityAccessLevel */
typedef struct sSsa_SecurityAccessLevelType
{
  Ssa_JobIdOfSecurityAccessLevelType JobIdOfSecurityAccessLevel;
  Ssa_LevelOfSecurityAccessLevelType LevelOfSecurityAccessLevel;
} Ssa_SecurityAccessLevelType;

/**   \brief  type used in Ssa_UniqueEcuId */
/*! 
 * \spec strong type invariant () { 
 *   (self.UniqueEcuIdsUniqueEcuIdsEndIdxOfUniqueEcuId < Ssa_GetSizeOfUniqueEcuIds()) &&
 *   (self.UniqueEcuIdsUniqueEcuIdsStartIdxOfUniqueEcuId < Ssa_GetSizeOfUniqueEcuIds())
 * }
 * \endspec 
 */ 
typedef struct sSsa_UniqueEcuIdType
{
  Ssa_UniqueEcuIdsUniqueEcuIdsEndIdxOfUniqueEcuIdType UniqueEcuIdsUniqueEcuIdsEndIdxOfUniqueEcuId;  /**< the end index of the 1:n relation pointing to Ssa_UniqueEcuIds */
  Ssa_UniqueEcuIdsUniqueEcuIdsStartIdxOfUniqueEcuIdType UniqueEcuIdsUniqueEcuIdsStartIdxOfUniqueEcuId;  /**< the start index of the 1:n relation pointing to Ssa_UniqueEcuIds */
} Ssa_UniqueEcuIdType;

/** 
  \}
*/ 

/** 
  \defgroup  SsaPCSymbolicStructTypes  Ssa Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCUnionIndexAndSymbolTypes  Ssa Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  SsaPCRootPointerTypes  Ssa Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Ssa_CodingDid */
typedef P2CONST(Ssa_CodingDidType, TYPEDEF, SSA_CONST) Ssa_CodingDidPtrType;

/**   \brief  type used to point to Ssa_CodingNvMBlock */
typedef P2CONST(Ssa_CodingNvMBlockType, TYPEDEF, SSA_CONST) Ssa_CodingNvMBlockPtrType;

/**   \brief  type used to point to Ssa_DataIdInfo */
typedef P2CONST(Ssa_DataIdInfoType, TYPEDEF, SSA_CONST) Ssa_DataIdInfoPtrType;

/**   \brief  type used to point to Ssa_DidHandled */
typedef P2VAR(Ssa_DidHandledType, TYPEDEF, SSA_VAR_NOINIT) Ssa_DidHandledPtrType;

/**   \brief  type used to point to Ssa_RightsM_TesterToChannel */
typedef P2CONST(Ssa_RightsM_TesterToChannelType, TYPEDEF, SSA_CONST) Ssa_RightsM_TesterToChannelPtrType;

/**   \brief  type used to point to Ssa_SecLogInfo */
typedef P2CONST(Ssa_SecLogInfoType, TYPEDEF, SSA_CONST) Ssa_SecLogInfoPtrType;

/**   \brief  type used to point to Ssa_SecurityAccessLevel */
typedef P2CONST(Ssa_SecurityAccessLevelType, TYPEDEF, SSA_CONST) Ssa_SecurityAccessLevelPtrType;

/**   \brief  type used to point to Ssa_TrustModelBackendCertName */
typedef P2CONST(Ssa_TrustModelBackendCertNameType, TYPEDEF, SSA_CONST) Ssa_TrustModelBackendCertNamePtrType;

/**   \brief  type used to point to Ssa_TrustModelBackendPeerCertName */
typedef P2CONST(Ssa_TrustModelBackendPeerCertNameType, TYPEDEF, SSA_CONST) Ssa_TrustModelBackendPeerCertNamePtrType;

/**   \brief  type used to point to Ssa_TrustModelEcuCertName */
typedef P2CONST(Ssa_TrustModelEcuCertNameType, TYPEDEF, SSA_CONST) Ssa_TrustModelEcuCertNamePtrType;

/**   \brief  type used to point to Ssa_TrustModelEcuCsrCertName */
typedef P2CONST(Ssa_TrustModelEcuCsrCertNameType, TYPEDEF, SSA_CONST) Ssa_TrustModelEcuCsrCertNamePtrType;

/**   \brief  type used to point to Ssa_TrustModelEcuPeerCertName */
typedef P2CONST(Ssa_TrustModelEcuPeerCertNameType, TYPEDEF, SSA_CONST) Ssa_TrustModelEcuPeerCertNamePtrType;

/**   \brief  type used to point to Ssa_TrustModelIntermediateCertName */
typedef P2CONST(Ssa_TrustModelIntermediateCertNameType, TYPEDEF, SSA_CONST) Ssa_TrustModelIntermediateCertNamePtrType;

/**   \brief  type used to point to Ssa_TrustModelIntermediatePeerCertName */
typedef P2CONST(Ssa_TrustModelIntermediatePeerCertNameType, TYPEDEF, SSA_CONST) Ssa_TrustModelIntermediatePeerCertNamePtrType;

/**   \brief  type used to point to Ssa_TrustModelRootCertName */
typedef P2CONST(Ssa_TrustModelRootCertNameType, TYPEDEF, SSA_CONST) Ssa_TrustModelRootCertNamePtrType;

/**   \brief  type used to point to Ssa_UniqueEcuId */
typedef P2CONST(Ssa_UniqueEcuIdType, TYPEDEF, SSA_CONST) Ssa_UniqueEcuIdPtrType;

/**   \brief  type used to point to Ssa_UniqueEcuIds */
typedef P2CONST(Ssa_UniqueEcuIdsType, TYPEDEF, SSA_CONST) Ssa_UniqueEcuIdsPtrType;

/**   \brief  type used to point to Ssa_EcuIndividualAclPtrNameOfRightsMOfPCConfig */
typedef P2CONST(Ssa_EcuIndividualAclPtrNameOfRightsMType, TYPEDEF, SSA_CONST) Ssa_EcuIndividualAclPtrNameOfRightsMOfPCConfigPtrType;

/**   \brief  type used to point to Ssa_EcuTypeOfGeneralOfPCConfig */
typedef P2CONST(Ssa_EcuTypeOfGeneralType, TYPEDEF, SSA_CONST) Ssa_EcuTypeOfGeneralOfPCConfigPtrType;

/**   \brief  type used to point to Ssa_TrustModelEcuCsrRefOfKeyMOfPCConfig */
typedef P2CONST(Ssa_TrustModelEcuCsrRefOfKeyMType, TYPEDEF, SSA_CONST) Ssa_TrustModelEcuCsrRefOfKeyMOfPCConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  SsaPCRootValueTypes  Ssa Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Ssa_PCConfig */
typedef struct sSsa_PCConfigType
{
  uint8 Ssa_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Ssa_PCConfigType;

typedef Ssa_PCConfigType Ssa_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  SsaPBValueTypes  Ssa Value Types (POST_BUILD)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  SsaPBRootValueTypes  Ssa Root Value Types (POST_BUILD)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Ssa_CodingDid
**********************************************************************************************************************/
#define SSA_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Ssa_CodingDidType, SSA_CONST) Ssa_CodingDid[9];
#define SSA_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_CodingNvMBlock
**********************************************************************************************************************/
/** 
  \var    Ssa_CodingNvMBlock
  \brief  Contains values of DefinitionRef: /MICROSAR/Ssa/SsaCoding/SsaCodingNvMBlock.
*/ 
#define SSA_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Ssa_CodingNvMBlockType, SSA_CONST) Ssa_CodingNvMBlock[7];
#define SSA_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_DataIdInfo
**********************************************************************************************************************/
/** 
  \var    Ssa_DataIdInfo
  \details
  Element      Description
  KeyId    
  DataId   
  Threshold
*/ 
#define SSA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Ssa_DataIdInfoType, SSA_CONST) Ssa_DataIdInfo[7];
#define SSA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_RightsM_TesterToChannel
**********************************************************************************************************************/
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Ssa_RightsM_TesterToChannelType, SSA_CONST) Ssa_RightsM_TesterToChannel[16];
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_SecurityAccessLevel
**********************************************************************************************************************/
/** 
  \var    Ssa_SecurityAccessLevel
  \brief  Contains parameters of /MICROSAR/Ssa/SsaRightsM/SsaSecurityAccessLevel.
  \details
  Element    Description
  JobId  
  Level  
*/ 
#define SSA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Ssa_SecurityAccessLevelType, SSA_CONST) Ssa_SecurityAccessLevel[4];
#define SSA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_TrustModelBackendCertName
**********************************************************************************************************************/
/** 
  \var    Ssa_TrustModelBackendCertName
  \brief  Holds ASCII representation of certificate name used in AsrPath: /ActiveEcuC/KeyM/Ssa_TrustModelBackendCert (Value: TrustModelBackendCert).
*/ 
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Ssa_TrustModelBackendCertNameType, SSA_CONST) Ssa_TrustModelBackendCertName[21];
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_TrustModelBackendPeerCertName
**********************************************************************************************************************/
/** 
  \var    Ssa_TrustModelBackendPeerCertName
  \brief  Holds ASCII representation of certificate name used in AsrPath: /ActiveEcuC/KeyM/Ssa_TrustModelBackendPeerCert (Value: TrustModelBackendPeerCert).
*/ 
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Ssa_TrustModelBackendPeerCertNameType, SSA_CONST) Ssa_TrustModelBackendPeerCertName[25];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_TrustModelEcuCertName
**********************************************************************************************************************/
/** 
  \var    Ssa_TrustModelEcuCertName
  \brief  Holds ASCII representation of certificate name used in AsrPath: /ActiveEcuC/KeyM/Ssa_TrustModelEcuCert (Value: TrustModelEcuCert).
*/ 
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Ssa_TrustModelEcuCertNameType, SSA_CONST) Ssa_TrustModelEcuCertName[17];
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_TrustModelEcuCsrCertName
**********************************************************************************************************************/
/** 
  \var    Ssa_TrustModelEcuCsrCertName
  \brief  Holds ASCII representation of certificate name used in AsrPath: /ActiveEcuC/KeyM/Ssa_TrustModelEcuCsr (Value: TrustModelEcuCsr).
*/ 
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Ssa_TrustModelEcuCsrCertNameType, SSA_CONST) Ssa_TrustModelEcuCsrCertName[16];
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_TrustModelEcuPeerCertName
**********************************************************************************************************************/
/** 
  \var    Ssa_TrustModelEcuPeerCertName
  \brief  Holds ASCII representation of certificate name used in AsrPath: /ActiveEcuC/KeyM/Ssa_TrustModelEcuPeerCert (Value: TrustModelEcuPeerCert).
*/ 
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Ssa_TrustModelEcuPeerCertNameType, SSA_CONST) Ssa_TrustModelEcuPeerCertName[21];
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_TrustModelIntermediateCertName
**********************************************************************************************************************/
/** 
  \var    Ssa_TrustModelIntermediateCertName
  \brief  Holds ASCII representation of certificate name used in AsrPath: /ActiveEcuC/KeyM/Ssa_TrustModelIntermediateCert (Value: TrustModelIntermediateCert).
*/ 
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Ssa_TrustModelIntermediateCertNameType, SSA_CONST) Ssa_TrustModelIntermediateCertName[26];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_TrustModelIntermediatePeerCertName
**********************************************************************************************************************/
/** 
  \var    Ssa_TrustModelIntermediatePeerCertName
  \brief  Holds ASCII representation of certificate name used in AsrPath: /ActiveEcuC/KeyM/Ssa_TrustModelIntermediatePeerCert (Value: TrustModelIntermediatePeerCert).
*/ 
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Ssa_TrustModelIntermediatePeerCertNameType, SSA_CONST) Ssa_TrustModelIntermediatePeerCertName[30];  /* PRQA S 0777 */  /* MD_MSR_Rule5.1 */
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_TrustModelRootCertName
**********************************************************************************************************************/
/** 
  \var    Ssa_TrustModelRootCertName
  \brief  Holds ASCII representation of certificate name used in AsrPath: /ActiveEcuC/KeyM/Ssa_TrustModelRootCert (Value: TrustModelRootCert).
*/ 
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Ssa_TrustModelRootCertNameType, SSA_CONST) Ssa_TrustModelRootCertName[18];
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_UniqueEcuId
**********************************************************************************************************************/
/** 
  \var    Ssa_UniqueEcuId
  \details
  Element                             Description
  UniqueEcuIdsUniqueEcuIdsEndIdx      the end index of the 1:n relation pointing to Ssa_UniqueEcuIds
  UniqueEcuIdsUniqueEcuIdsStartIdx    the start index of the 1:n relation pointing to Ssa_UniqueEcuIds
*/ 
#define SSA_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Ssa_UniqueEcuIdType, SSA_CONST) Ssa_UniqueEcuId[2];
#define SSA_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_UniqueEcuIds
**********************************************************************************************************************/
#define SSA_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Ssa_UniqueEcuIdsType, SSA_CONST) Ssa_UniqueEcuIds[18];
#define SSA_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Ssa_DidHandled
**********************************************************************************************************************/
#define SSA_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Ssa_DidHandledType, SSA_VAR_NOINIT) Ssa_DidHandled[1];
#define SSA_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/* PRQA S 3684 1 */ /* MD_SSA_CFG_8.12_3684 */
extern CONST(uint8, RTE_SSA_RIGHTSM_APPL_CONST) Ssa_RightsM_EcuIndividualAcl[];


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTION PROTOTYPES
**********************************************************************************************************************/

 
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/






#if !defined (SSA_NOUNIT_CSLUNIT)
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/

#endif



#endif /* SSA_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Ssa_Cfg.h
 *********************************************************************************************************************/


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
 *            Module: vHsm
 *           Program: HSM_Vector_SLP1
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200336_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: vHsm_Cfg.h
 *   Generation Time: 2023-08-16 13:28:24
 *           Project: vHsmConfig - Version 1.0
 *          Delivery: CBD2200336_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.31 SP1
 *
 *
 *********************************************************************************************************************/


#if !defined (VHSM_CFG_H)
#define VHSM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Csm_Types.h"
#include "vHsm_Types.h"
#include "Os.h"
/* PRQA S 3471 EOF */ /* MD_MSR_FctLikeMacro */
#include "NvM.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef VHSM_USE_DUMMY_STATEMENT
#define VHSM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VHSM_DUMMY_STATEMENT
#define VHSM_DUMMY_STATEMENT(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VHSM_DUMMY_STATEMENT_CONST
#define VHSM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef VHSM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define VHSM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef VHSM_ATOMIC_VARIABLE_ACCESS
#define VHSM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef VHSM_PROCESSOR_TC322L
#define VHSM_PROCESSOR_TC322L
#endif
#ifndef VHSM_COMP_TASKING
#define VHSM_COMP_TASKING
#endif
#ifndef VHSM_GEN_GENERATOR_MSR
#define VHSM_GEN_GENERATOR_MSR
#endif
#ifndef VHSM_CPUTYPE_BITORDER_LSB2MSB
#define VHSM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef VHSM_CONFIGURATION_VARIANT_PRECOMPILE
#define VHSM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef VHSM_CONFIGURATION_VARIANT_LINKTIME
#define VHSM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef VHSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define VHSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef VHSM_CONFIGURATION_VARIANT
#define VHSM_CONFIGURATION_VARIANT VHSM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef VHSM_POSTBUILD_VARIANT_SUPPORT
#define VHSM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define VHSM_CYCLIC_VERIFICATION_AVAILABLE                                                          STD_OFF
#define VHSM_FIRMWARE_UPDATE_MAC_KEY                                                                CryIfConf_CryIfKey_vHsm_FirmwareUpdate_Mac
#define VHSM_FIRMWARE_UPDATE_ENCRYPT_KEY                                                            CryIfConf_CryIfKey_vHsm_FirmwareUpdate_Encrypt
#define CryptoConf_CryptoKey_vHsmInfo (30000u)
#define CryptoConf_CryptoKey_vHsmSecureBootGroupInfo (30001u)
#define CryptoConf_CryptoKey_vHsmLog (30002u)
#define VHSM_CORE_AGGREGATED_KEY_AVAILABLE                                                          STD_ON
/* Microsar Define Block for Boolean and Integers */
#define VHSM_SOFT_RESET_LIMIT                                                                       8u 
#define VHSM_REDIRECTION                                                                            STD_OFF 
#define VHSM_ENABLE_RAM_LOOP_CALLOUT                                                                STD_ON 
#define VHSM_GENERATE_RANDOM_IPC_VALUES                                                             STD_OFF 
#define VHSM_GENERATE_RANDOM_STACK_PROTECTION_CANARY                                                STD_OFF 
#define VHSM_FORCE_INTERRUPT_TRIGGERING                                                             STD_OFF 
#define VHSM_SUPPORT_SAVE_RESTORE_CONTEXT                                                           STD_OFF 
#define VHSM_OPTION_BYTE_MODIFICATION                                                               STD_OFF 
#define VHSM_TRACE_INFO                                                                             STD_OFF 
#define VHSM_TRACE_WARNING                                                                          STD_OFF 
#define VHSM_TRACE_DEBUG                                                                            STD_OFF 
#define VHSM_TRACE_ERROR                                                                            STD_OFF 
#define VHSM_TRACE_KEY_STORAGE                                                                      STD_OFF 
#define VHSM_UPGRADE_PROTECTION_MODIFICATION                                                        STD_OFF 
#define VHSM_ENABLE_SECURE_BOOT_AUTOSTART                                                           STD_ON 
#define VHSM_DEVELOPMENT                                                                            STD_OFF 
#define VHSM_IPC_CHANNELS                                                                           2u 
#define VHSM_IPC_PROTOCOL_VERSION                                                                   3u 
#define VHSM_JUMP_TO_UPDATER_RESTRICTION                                                            STD_OFF 
#define VHSM_FIRMWARE_UPDATE                                                                        STD_ON 
#define VHSM_SECURE_BOOT_SPLIT_SIZE                                                                 256u 
#define VHSM_SECURE_BOOT_QUEUE_SIZE                                                                 10u 
#define VHSM_SECURE_BOOT_CYCLIC_VERIFICATION_SPLIT_SIZE                                             256u 
#define VHSM_SECURE_BOOT_SEGMENT_SUCCESS_CALLOUT                                                    STD_OFF 
#define VHSM_SECURE_BOOT_FORCED_SEQUENTIAL_PROCESSING_ON_FIRST_VERIFICATION                         STD_OFF 
#define VHSM_ATOMIC_BUFFER_SIZE                                                                     128u 
#define VHSM_SECURE_BOOT_UPDATE                                                                     STD_OFF 
#define VHSM_ALLOW_ADDRESS_CHANGE                                                                   STD_OFF 
#define VHSM_SECURE_SOFTWARE_DOWNLOAD                                                               STD_OFF 
#define VHSM_SECURE_BOOT                                                                            STD_OFF 
#define VHSM_LOG                                                                                    STD_OFF 
#define VHSM_OS_SUPPORT                                                                             STD_ON 
#define VHSM_INTERRUPT_MODE                                                                         STD_ON 
#define VHSM_PARTITION_LAYOUT                                                                       STD_OFF 

/* Symbolic Name Define Block */
#define vHsmConf_vHsmMemoryArea_TC3xx_CPU0_CPU1_CPU2                                                0u 
#define vHsmConf_vHsmMemoryArea_TC3xx_CPU3_CPU4                                                     1u 
#define vHsmConf_vHsmMemoryArea_TC3xx_CPU5                                                          2u 
#define vHsmConf_vHsmMemoryArea_TC3xx_HostAccessWindow                                              3u 
#define vHsmConf_vHsmMemoryArea_TC3xx_LMURAM_cached_HOST                                            4u 
#define vHsmConf_vHsmMemoryArea_TC3xx_LMURAM_cached_HSM                                             5u 
#define vHsmConf_vHsmMemoryArea_TC3xx_LMURAM_noncached                                              6u 
#define vHsmConf_vHsmMemoryArea_TC3xx_PFLASH_cached                                                 7u 
#define vHsmConf_vHsmMemoryArea_TC3xx_PFLASH_noncached                                              8u 
#define vHsmConf_vHsmIpcInstance_vHsmIpcInstance                                                    0u 
#define vHsmConf_vHsmSchedulableEntities_vHsmSchedulableEntities_HighPrio                           0u 
#define vHsmConf_vHsmSchedulableEntities_vHsmSchedulableEntities_Unmapped                           1u 

#define VHSM_IGNORE_INVALID_BLOCKS                                                                  0x00000000u 
#define VHSM_PERSIST_INVALID_BLOCKS                                                                 0x00000001u 
#define VHSM_PERSIST_NVMCONFIGBLOCK                                                                 0x00000002u 
#define VHSM_STORAGE_IN_CSM                                                                         0x00000000u 
#define VHSM_STORAGE_IN_NVM                                                                         0x00000001u 
#define VHSM_STORAGE_NONE                                                                           0x00000002u 
#define VHSM_GROUP_TAG                                                                              0x00000000u 
#define VHSM_PROCESSING_TAG                                                                         0x00000001u 
#define VHSM_SEGMENT_TAG                                                                            0x00000002u 
#define VHSM_NV_PROCESSING_DEFERRED                                                                 0x00000000u 
#define VHSM_NV_PROCESSING_IMMEDIATE                                                                0x00000001u 
#define VHSM_NV_PROCESSING_NONE                                                                     0x00000002u 
#define VHSM_EXPORT_ALL_FIFO                                                                        0x00000000u 
#define VHSM_EXPORT_ALL_FILO                                                                        0x00000001u 
#define VHSM_EXPORT_LATEST                                                                          0x00000002u 
#define VHSM_EXPORT_NONE                                                                            0x00000003u 
#define VHSM_EXPORT_OCCURRENCES                                                                     0x00000004u 
#define VHSM_EXPORT_OLDEST                                                                          0x00000005u 

#ifndef VHSM_DEV_ERROR_DETECT
#define VHSM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef VHSM_DEV_ERROR_REPORT
#define VHSM_DEV_ERROR_REPORT STD_ON
#endif
#define VHSM_INVALID_NV_MBLOCK_BEHAVIOUR                                                            VHSM_IGNORE_INVALID_BLOCKS
/* The following defines represent the configuration of vHsmAdditionalSettings. */
#define VHSM_SETTING_ENABLE_API_CODE_FLASH_ACCESS                                                   STD_OFF
#define VHSM_SETTING_ENABLE_API_RESET_VECTOR                                                        STD_OFF
#define VHSM_SETTING_ENABLE_API_GET_IPC_ADDRESS                                                     STD_ON
#define VHSM_SETTING_ENABLE_API_PREPARE_JOB_DATA                                                    STD_ON
#define VHSM_SETTING_ENABLE_API_GET_CODE_FLASH_ADDRESS                                              STD_OFF
#define VHSM_SETTING_ENABLE_API_HALT                                                                STD_OFF
#define VHSM_SETTING_ENABLE_UNALIGNED_ACCESS                                                        STD_ON
#define VHSM_SETTING_ENABLE_IPC_INIT_VIA_INTERRUPT                                                  STD_OFF

#define VHSM_NVM_SUPPORT                                                                            STD_ON
#define VHSM_CRYPTO_NV_SUPPORT                                                                      STD_ON
#define VHSM_TOTAL_NV_BLOCKS                                                                        9u
#define VHSM_MEMORY_AREA_READ                                                                       0x00u
#define VHSM_MEMORY_AREA_READWRITE                                                                  0x01u
#define VHSM_FIRMWARE_UPDATE_RECRYPTION                                                             STD_ON
#define VHSM_INTERNALONLYKEYS                                                                       VHSM_INTERNALONLYOFKEYINFO
#define VHSM_HARDWAREOFKEYINFO                                                                      STD_OFF
#define VHSM_MAX_SEGMENTS_PER_GROUP                                                                 1u
#define VHSM_VERMETHOD_EXTERNAL_SL_AVAILABLE                                                        STD_OFF
#define VHSM_VERMETHOD_COMPARE_INTERNAL_TAG_AVAILABLE                                               STD_OFF
#define VHSM_MAX_TAG_SIZE                                                                           0u
#define VHSM_MAX_TAG_SIZE_OR_SHA256                                                                 32u
#define VHSM_MAX_TAG_SIZE_OR_SHA512                                                                 32u
#define VHSM_LOG_THRESHOLD_CALLOUT_ENABLED                                                          STD_OFF
#define VHSM_LOG_EVENT_CALLOUT_ENABLED                                                              STD_OFF
#define VHSM_LOG_TIMESTAMP_CALLOUT_ENABLED                                                          STD_OFF
#define VHSM_ISR_PROCESSED_CHANNELS                                                                 STD_OFF
#define VHSM_CALL_CONTEXT_TASK                                                                      0u
#define VHSM_CALL_CONTEXT_ISR1                                                                      1u
#define VHSM_CALL_CONTEXT_ISR2                                                                      2u
#define VHSM_CATEGORY_1                                                                             VHSM_CALL_CONTEXT_ISR1
#define VHSM_CATEGORY_2                                                                             VHSM_CALL_CONTEXT_ISR2


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vHsmPCDataSwitches  vHsm Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VHSM_ALLOWADDRESSCHANGEOFSECURESOFTWAREDOWNLOAD                                             STD_OFF  /**< Deactivateable: 'vHsm_AllowAddressChangeOfSecureSoftwareDownload' Reason: 'Parameter is not configured!' */
#define VHSM_ATOMICBUFFERSIZEOFSECUREBOOT                                                           STD_OFF  /**< Deactivateable: 'vHsm_AtomicBufferSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define VHSM_CHANNELINFO                                                                            STD_ON
#define VHSM_CRYPTOFUNCTIONSIDXOFCHANNELINFO                                                        STD_ON
#define VHSM_DRIVEROBJECTREFOFCHANNELINFO                                                           STD_ON
#define VHSM_CHANNELSOFIPC                                                                          STD_ON
#define VHSM_COREKEY                                                                                STD_ON
#define VHSM_AGGREGATEDCRYPTOKEYIDOFCOREKEY                                                         STD_ON
#define VHSM_KEYIDOFCOREKEY                                                                         STD_ON
#define VHSM_CRYPTOFUNCTIONS                                                                        STD_ON
#define VHSM_CANCELJOBOFCRYPTOFUNCTIONS                                                             STD_ON
#define VHSM_CERTIFICATEPARSEOFCRYPTOFUNCTIONS                                                      STD_ON
#define VHSM_CERTIFICATEVERIFYOFCRYPTOFUNCTIONS                                                     STD_ON
#define VHSM_KEYCOPYOFCRYPTOFUNCTIONS                                                               STD_ON
#define VHSM_KEYDERIVEOFCRYPTOFUNCTIONS                                                             STD_ON
#define VHSM_KEYELEMENTCOPYOFCRYPTOFUNCTIONS                                                        STD_ON
#define VHSM_KEYELEMENTCOPYPARTIALOFCRYPTOFUNCTIONS                                                 STD_ON
#define VHSM_KEYELEMENTGETOFCRYPTOFUNCTIONS                                                         STD_ON
#define VHSM_KEYELEMENTIDSGETOFCRYPTOFUNCTIONS                                                      STD_ON
#define VHSM_KEYELEMENTSETOFCRYPTOFUNCTIONS                                                         STD_ON
#define VHSM_KEYEXCHANGECALCPUBVALOFCRYPTOFUNCTIONS                                                 STD_ON
#define VHSM_KEYEXCHANGECALCSECRETOFCRYPTOFUNCTIONS                                                 STD_ON
#define VHSM_KEYGENERATEOFCRYPTOFUNCTIONS                                                           STD_ON
#define VHSM_KEYVALIDSETOFCRYPTOFUNCTIONS                                                           STD_ON
#define VHSM_PROCESSJOBOFCRYPTOFUNCTIONS                                                            STD_ON
#define VHSM_RANDOMSEEDOFCRYPTOFUNCTIONS                                                            STD_ON
#define VHSM_CSMHASHJOBREFERENCEOFSECUREBOOTUPDATE                                                  STD_OFF  /**< Deactivateable: 'vHsm_CsmHashJobReferenceOfSecureBootUpdate' Reason: 'Reference is not configured!' */
#define VHSM_CSMJOBDECRYPTREFOFFIRMWAREUPDATE                                                       STD_ON
#define VHSM_CSMJOBENCRYPTREFOFFIRMWAREUPDATE                                                       STD_ON
#define VHSM_CSMJOBMACGENERATEREFOFFIRMWAREUPDATE                                                   STD_ON
#define VHSM_CSMJOBSIGNATUREVERIFYREFOFFIRMWAREUPDATE                                               STD_ON
#define VHSM_CSMSIGNATUREJOBREFERENCEOFSECUREBOOTUPDATE                                             STD_OFF  /**< Deactivateable: 'vHsm_CsmSignatureJobReferenceOfSecureBootUpdate' Reason: 'Reference is not configured!' */
#define VHSM_CSMSIGNATUREJOBREFERENCEOFSECURESOFTWAREDOWNLOAD                                       STD_OFF  /**< Deactivateable: 'vHsm_CsmSignatureJobReferenceOfSecureSoftwareDownload' Reason: 'Reference is not configured!' */
#define VHSM_CUSTOMCALLOUT                                                                          STD_OFF  /**< Deactivateable: 'vHsm_CustomCallout' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define VHSM_DUMMYOFCUSTOMCALLOUT                                                                   STD_OFF  /**< Deactivateable: 'vHsm_CustomCallout.Dummy' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_CUSTOMCALLOUTCYCLIC                                                                    STD_OFF  /**< Deactivateable: 'vHsm_CustomCalloutCyclic' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define VHSM_DUMMYOFCUSTOMCALLOUTCYCLIC                                                             STD_OFF  /**< Deactivateable: 'vHsm_CustomCalloutCyclic.Dummy' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_CYCLICVERIFICATIONSPLITSIZEOFSECUREBOOT                                                STD_OFF  /**< Deactivateable: 'vHsm_CyclicVerificationSplitSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define VHSM_DRIVEROBJECTMAPPING                                                                    STD_ON
#define VHSM_DRIVEROBJECTMAPPINGIND                                                                 STD_ON
#define VHSM_ENABLERAMLOOPCALLOUTOFGENERAL                                                          STD_ON
#define VHSM_ENABLESECUREBOOTAUTOSTARTOFDEVELOPMENT                                                 STD_OFF  /**< Deactivateable: 'vHsm_EnableSecureBootAutostartOfDevelopment' Reason: 'Parameter is not configured!' */
#define VHSM_ERRORLOGEVENTLOGREFOFGENERAL                                                           STD_OFF  /**< Deactivateable: 'vHsm_ErrorLogEventLogRefOfGeneral' Reason: 'Reference is not configured!' */
#define VHSM_EXPECTEDCOMPATIBILITYVERSION                                                           STD_OFF  /**< Deactivateable: 'vHsm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VHSM_FINALMAGICNUMBER                                                                       STD_OFF  /**< Deactivateable: 'vHsm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VHSM_FORCEINTERRUPTTRIGGERINGOFGENERAL                                                      STD_ON
#define VHSM_FORCEDSEQUENTIALPROCESSINGONFIRSTVERIFICATIONOFSECUREBOOT                              STD_OFF  /**< Deactivateable: 'vHsm_ForcedSequentialProcessingOnFirstVerificationOfSecureBoot' Reason: 'Parameter is not configured!' */
#define VHSM_GENERATERANDOMIPCVALUESOFGENERAL                                                       STD_ON
#define VHSM_GENERATERANDOMSTACKPROTECTIONCANARYOFGENERAL                                           STD_ON
#define VHSM_GENERATORCOMPATIBILITYVERSION                                                          STD_OFF  /**< Deactivateable: 'vHsm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VHSM_INITDATAHASHCODE                                                                       STD_OFF  /**< Deactivateable: 'vHsm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VHSM_INTERRUPTMODEOFSCHEDULING                                                              STD_ON
#define VHSM_INVALIDNVMBLOCKBEHAVIOUROFGENERAL                                                      STD_ON
#define VHSM_IPCINSTANCE                                                                            STD_ON
#define VHSM_DRIVEROBJECTMAPPINGINDENDIDXOFIPCINSTANCE                                              STD_ON
#define VHSM_DRIVEROBJECTMAPPINGINDSTARTIDXOFIPCINSTANCE                                            STD_ON
#define VHSM_DRIVEROBJECTMAPPINGINDUSEDOFIPCINSTANCE                                                STD_ON
#define VHSM_HARDWAREUNITOFIPCINSTANCE                                                              STD_ON
#define VHSM_IDOFIPCINSTANCE                                                                        STD_ON
#define VHSM_MEMORYOFIPCINSTANCE                                                                    STD_ON
#define VHSM_RESPONSEINTERRUPTFLAGSETADDRESSOFIPCINSTANCE                                           STD_ON
#define VHSM_RESPONSEINTERRUPTFLAGSETMASKOFIPCINSTANCE                                              STD_ON
#define VHSM_ISRFORPROCESSINGOFSCHEDULING                                                           STD_ON
#define VHSM_JOBOBJECTINFO                                                                          STD_ON
#define VHSM_EVENTTRIGGEREDOFJOBOBJECTINFO                                                          STD_ON
#define VHSM_ISRPROCESSINGOFJOBOBJECTINFO                                                           STD_ON
#define VHSM_MASKEDBITSOFJOBOBJECTINFO                                                              STD_ON
#define VHSM_SCHEDEVENTREFOFJOBOBJECTINFO                                                           STD_ON
#define VHSM_SCHEDTASKREFOFJOBOBJECTINFO                                                            STD_ON
#define VHSM_JOBOBJECTS                                                                             STD_ON
#define VHSM_CANCELFLAGOFJOBOBJECTS                                                                 STD_ON
#define VHSM_IPCCHANNELOFJOBOBJECTS                                                                 STD_ON
#define VHSM_IPCINSTANCEOFJOBOBJECTS                                                                STD_ON
#define VHSM_IPCMAPPINGOFJOBOBJECTS                                                                 STD_ON
#define VHSM_JOBDATAOFJOBOBJECTS                                                                    STD_ON
#define VHSM_JOBREQUESTIDOFJOBOBJECTS                                                               STD_ON
#define VHSM_JOBREQUESTKINDOFJOBOBJECTS                                                             STD_ON
#define VHSM_JOBRETVALOFJOBOBJECTS                                                                  STD_ON
#define VHSM_LOCALOUTPUTOFJOBOBJECTS                                                                STD_ON
#define VHSM_PROCESSKINDOFJOBOBJECTS                                                                STD_ON
#define VHSM_PROCESSINGTYPEOFJOBOBJECTS                                                             STD_ON
#define VHSM_REDIRECTIONFLAGSOFJOBOBJECTS                                                           STD_ON
#define VHSM_STATEOFJOBOBJECTS                                                                      STD_ON
#define VHSM_USAGERESTRICTIONOFJOBOBJECTS                                                           STD_ON
#define VHSM_VALIDREQUESTFLAGOFJOBOBJECTS                                                           STD_ON
#define VHSM_JUMPTOUPDATERRESTRICTIONOFFIRMWAREUPDATE                                               STD_ON
#define VHSM_KEYINFO                                                                                STD_ON
#define VHSM_CRYPTOFUNCTIONSIDXOFKEYINFO                                                            STD_ON
#define VHSM_CRYPTOKEYIDOFKEYINFO                                                                   STD_ON
#define VHSM_INTERNALONLYOFKEYINFO                                                                  STD_ON
#define VHSM_MASKEDBITSOFKEYINFO                                                                    STD_ON
#define VHSM_ROUTEDOFKEYINFO                                                                        STD_ON
#define VHSM_SECUREBOOTGROUPOFKEYINFO                                                               STD_OFF  /**< Deactivateable: 'vHsm_KeyInfo.SecureBootGroup' Reason: 'No Secure Boot Group Key configured' */
#define VHSM_SECUREBOOTPROTECTEDOFKEYINFO                                                           STD_OFF  /**< Deactivateable: 'vHsm_KeyInfo.SecureBootProtected' Reason: 'No Secure Boot Protected Key configured!' */
#define VHSM_SECUREBOOTSEGMENTOFKEYINFO                                                             STD_OFF  /**< Deactivateable: 'vHsm_KeyInfo.SecureBootSegment' Reason: 'No Secure Boot Segment Key configured' */
#define VHSM_KEYMANAGEMENTCHANNELOFCHANNELMAPPING                                                   STD_ON
#define VHSM_LOGEVENT                                                                               STD_OFF  /**< Deactivateable: 'vHsm_LogEvent' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define VHSM_COUNTERSIZEOFLOGEVENT                                                                  STD_OFF  /**< Deactivateable: 'vHsm_LogEvent.CounterSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_DATASIZEOFLOGEVENT                                                                     STD_OFF  /**< Deactivateable: 'vHsm_LogEvent.DataSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_DISCARDWHENFULLOFLOGEVENT                                                              STD_OFF  /**< Deactivateable: 'vHsm_LogEvent.DiscardWhenFull' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_EVENTCALLOUTOFLOGEVENT                                                                 STD_OFF  /**< Deactivateable: 'vHsm_LogEvent.EventCallout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_EXPORTSTRATEGYOFLOGEVENT                                                               STD_OFF  /**< Deactivateable: 'vHsm_LogEvent.ExportStrategy' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_FILLLEVELTHRESHOLDOFLOGEVENT                                                           STD_OFF  /**< Deactivateable: 'vHsm_LogEvent.FillLevelThreshold' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_IDOFLOGEVENT                                                                           STD_OFF  /**< Deactivateable: 'vHsm_LogEvent.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_LOGEVENTMEMORYENDIDXOFLOGEVENT                                                         STD_OFF  /**< Deactivateable: 'vHsm_LogEvent.LogEventMemoryEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_LOGEVENTMEMORYSTARTIDXOFLOGEVENT                                                       STD_OFF  /**< Deactivateable: 'vHsm_LogEvent.LogEventMemoryStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_MAXENTRIESOFLOGEVENT                                                                   STD_OFF  /**< Deactivateable: 'vHsm_LogEvent.MaxEntries' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_NVBLOCKDESCRIPTOROFLOGEVENT                                                            STD_OFF  /**< Deactivateable: 'vHsm_LogEvent.NvBlockDescriptor' Reason: 'DefinitionRef: /MICROSAR/vHsm/vHsmLog/vHsmLogEvent/vHsmNvBlockDescriptor not configured.' */
#define VHSM_NVBLOCKDESCRIPTORVALIDOFLOGEVENT                                                       STD_OFF  /**< Deactivateable: 'vHsm_LogEvent.NvBlockDescriptorValid' Reason: 'DefinitionRef: /MICROSAR/vHsm/vHsmLog/vHsmLogEvent/vHsmNvBlockDescriptor not configured.' */
#define VHSM_NVPROCESSINGOFLOGEVENT                                                                 STD_OFF  /**< Deactivateable: 'vHsm_LogEvent.NvProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_TIMESTAMPSIZEOFLOGEVENT                                                                STD_OFF  /**< Deactivateable: 'vHsm_LogEvent.TimestampSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_LOGEVENTMEMORY                                                                         STD_OFF  /**< Deactivateable: 'vHsm_LogEventMemory' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_MAINFUNCTIONPERIODOFGENERAL                                                            STD_OFF  /**< Deactivateable: 'vHsm_MainFunctionPeriodOfGeneral' Reason: 'Parameter is not configured!' */
#define VHSM_MEMORYAREA                                                                             STD_ON
#define VHSM_STARTOFMEMORYAREA                                                                      STD_ON
#define VHSM_STOPOFMEMORYAREA                                                                       STD_ON
#define VHSM_TYPEOFMEMORYAREA                                                                       STD_ON
#define VHSM_OPTIONBYTEMODIFICATIONOFDEVELOPMENT                                                    STD_OFF  /**< Deactivateable: 'vHsm_OptionByteModificationOfDevelopment' Reason: 'Parameter is not configured!' */
#define VHSM_OSSUPPORTOFSCHEDULING                                                                  STD_ON
#define VHSM_PARTITION                                                                              STD_OFF  /**< Deactivateable: 'vHsm_Partition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define VHSM_IDOFPARTITION                                                                          STD_OFF  /**< Deactivateable: 'vHsm_Partition.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_LENGTHOFPARTITION                                                                      STD_OFF  /**< Deactivateable: 'vHsm_Partition.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_STARTADDRESSOFPARTITION                                                                STD_OFF  /**< Deactivateable: 'vHsm_Partition.StartAddress' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_PARTITIONGROUP                                                                         STD_OFF  /**< Deactivateable: 'vHsm_PartitionGroup' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define VHSM_PARTITIONREFINDENDIDXOFPARTITIONGROUP                                                  STD_OFF  /**< Deactivateable: 'vHsm_PartitionGroup.PartitionRefIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_PARTITIONREFINDSTARTIDXOFPARTITIONGROUP                                                STD_OFF  /**< Deactivateable: 'vHsm_PartitionGroup.PartitionRefIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_PARTITIONREFINDUSEDOFPARTITIONGROUP                                                    STD_OFF  /**< Deactivateable: 'vHsm_PartitionGroup.PartitionRefIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_PARTITIONREF                                                                           STD_OFF  /**< Deactivateable: 'vHsm_PartitionRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_PARTITIONREFIND                                                                        STD_OFF  /**< Deactivateable: 'vHsm_PartitionRefInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_PROTOCOLVERSIONOFIPC                                                                   STD_ON
#define VHSM_QUEUESIZEOFSECUREBOOT                                                                  STD_OFF  /**< Deactivateable: 'vHsm_QueueSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define VHSM_RANDOMCSMJOBREFOFGENERAL                                                               STD_ON
#define VHSM_RANDOMINIT                                                                             STD_ON
#define VHSM_KEYELEMENTOFRANDOMINIT                                                                 STD_ON
#define VHSM_KEYOFRANDOMINIT                                                                        STD_ON
#define VHSM_REDIRECTIONOFGENERAL                                                                   STD_ON
#define VHSM_RESTRICTEDCHANNELS                                                                     STD_ON
#define VHSM_SCHEDULABLEENTITIES                                                                    STD_ON
#define VHSM_SCHEDULEDCHANNELSENDIDXOFSCHEDULABLEENTITIES                                           STD_ON
#define VHSM_SCHEDULEDCHANNELSSTARTIDXOFSCHEDULABLEENTITIES                                         STD_ON
#define VHSM_SCHEDULEDCHANNELS                                                                      STD_ON
#define VHSM_SECUREBOOTGROUP                                                                        STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define VHSM_AUTOSTARTOFSECUREBOOTGROUP                                                             STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.Autostart' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_CRYPTOKEYIDOFSECUREBOOTGROUP                                                           STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.CryptoKeyId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_CUSTOMCALLOUTCYCLICIDXOFSECUREBOOTGROUP                                                STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.CustomCalloutCyclicIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_CUSTOMCALLOUTCYCLICUSEDOFSECUREBOOTGROUP                                               STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.CustomCalloutCyclicUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_CUSTOMCALLOUTIDXOFSECUREBOOTGROUP                                                      STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.CustomCalloutIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_CUSTOMCALLOUTUSEDOFSECUREBOOTGROUP                                                     STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.CustomCalloutUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_CYCLICVERIFICATIONOFSECUREBOOTGROUP                                                    STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.CyclicVerification' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_IDOFSECUREBOOTGROUP                                                                    STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_NVBLOCKDESCRIPTOROFSECUREBOOTGROUP                                                     STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.NvBlockDescriptor' Reason: 'DefinitionRef: /MICROSAR/vHsm/vHsmSecureBoot/vHsmSecureBootGroup/vHsmNvBlockDescriptor not configured.' */
#define VHSM_NVBLOCKDESCRIPTORVALIDOFSECUREBOOTGROUP                                                STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.NvBlockDescriptorValid' Reason: 'DefinitionRef: /MICROSAR/vHsm/vHsmSecureBoot/vHsmSecureBootGroup/vHsmNvBlockDescriptor not configured.' */
#define VHSM_SANCTIONOFSECUREBOOTGROUP                                                              STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.Sanction' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_SECUREBOOTSEGMENTENDIDXOFSECUREBOOTGROUP                                               STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.SecureBootSegmentEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_SECUREBOOTSEGMENTSTARTIDXOFSECUREBOOTGROUP                                             STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.SecureBootSegmentStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_SECUREBOOTSEGMENTUSEDOFSECUREBOOTGROUP                                                 STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.SecureBootSegmentUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_SERVICEOFSECUREBOOTGROUP                                                               STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.Service' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_SIGJOBEXTERNALSLOFSECUREBOOTGROUP                                                      STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.SigJobExternalSl' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_SLLOCATIONOFSECUREBOOTGROUP                                                            STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.SlLocation' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_TAGHANDLINGOFSECUREBOOTGROUP                                                           STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.TagHandling' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_TAGLENGTHOFSECUREBOOTGROUP                                                             STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.TagLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_VERJOBCOMPINTERNALOFSECUREBOOTGROUP                                                    STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.VerJobCompInternal' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_VERJOBEXTERNALSLOFSECUREBOOTGROUP                                                      STD_OFF  /**< Deactivateable: 'vHsm_SecureBootGroup.VerJobExternalSl' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_SECUREBOOTPROTECTEDCHANNELS                                                            STD_OFF  /**< Deactivateable: 'vHsm_SecureBootProtectedChannels' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_SECUREBOOTPROTECTEDKEYS                                                                STD_OFF  /**< Deactivateable: 'vHsm_SecureBootProtectedKeys' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_SECUREBOOTSEGMENT                                                                      STD_OFF  /**< Deactivateable: 'vHsm_SecureBootSegment' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define VHSM_CRYPTOKEYIDOFSECUREBOOTSEGMENT                                                         STD_OFF  /**< Deactivateable: 'vHsm_SecureBootSegment.CryptoKeyId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_GROUPIDXOFSECUREBOOTSEGMENT                                                            STD_OFF  /**< Deactivateable: 'vHsm_SecureBootSegment.GroupIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_SECUREBOOTSEGMENTINITVALUESIDXOFSECUREBOOTSEGMENT                                      STD_OFF  /**< Deactivateable: 'vHsm_SecureBootSegment.SecureBootSegmentInitValuesIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_SECUREBOOTSEGMENTINITVALUESUSEDOFSECUREBOOTSEGMENT                                     STD_OFF  /**< Deactivateable: 'vHsm_SecureBootSegment.SecureBootSegmentInitValuesUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_SECUREBOOTSEGMENTINITVALUES                                                            STD_OFF  /**< Deactivateable: 'vHsm_SecureBootSegmentInitValues' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define VHSM_ADDRESSOFSECUREBOOTSEGMENTINITVALUES                                                   STD_OFF  /**< Deactivateable: 'vHsm_SecureBootSegmentInitValues.Address' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_LENGTHOFSECUREBOOTSEGMENTINITVALUES                                                    STD_OFF  /**< Deactivateable: 'vHsm_SecureBootSegmentInitValues.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_MODEOFSECUREBOOTSEGMENTINITVALUES                                                      STD_OFF  /**< Deactivateable: 'vHsm_SecureBootSegmentInitValues.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_SANCTIONOFSECUREBOOTSEGMENTINITVALUES                                                  STD_OFF  /**< Deactivateable: 'vHsm_SecureBootSegmentInitValues.Sanction' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_SECUREBOOTVERIFICATIONJOB                                                              STD_OFF  /**< Deactivateable: 'vHsm_SecureBootVerificationJob' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define VHSM_CSMJOBPARALLELREFOFSECUREBOOTVERIFICATIONJOB                                           STD_OFF  /**< Deactivateable: 'vHsm_SecureBootVerificationJob.CsmJobParallelRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_CSMJOBSEQUENTIALREFOFSECUREBOOTVERIFICATIONJOB                                         STD_OFF  /**< Deactivateable: 'vHsm_SecureBootVerificationJob.CsmJobSequentialRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_IDOFSECUREBOOTVERIFICATIONJOB                                                          STD_OFF  /**< Deactivateable: 'vHsm_SecureBootVerificationJob.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_PARALLELCHANNELREFOFSECUREBOOTVERIFICATIONJOB                                          STD_OFF  /**< Deactivateable: 'vHsm_SecureBootVerificationJob.ParallelChannelRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define VHSM_SEGMENTSUCCESSCALLOUTOFSECUREBOOT                                                      STD_OFF  /**< Deactivateable: 'vHsm_SegmentSuccessCalloutOfSecureBoot' Reason: 'Parameter is not configured!' */
#define VHSM_SIZEOFCHANNELINFO                                                                      STD_ON
#define VHSM_SIZEOFCOREKEY                                                                          STD_ON
#define VHSM_SIZEOFCRYPTOFUNCTIONS                                                                  STD_ON
#define VHSM_SIZEOFDRIVEROBJECTMAPPING                                                              STD_ON
#define VHSM_SIZEOFDRIVEROBJECTMAPPINGIND                                                           STD_ON
#define VHSM_SIZEOFIPCINSTANCE                                                                      STD_ON
#define VHSM_SIZEOFJOBOBJECTINFO                                                                    STD_ON
#define VHSM_SIZEOFJOBOBJECTS                                                                       STD_ON
#define VHSM_SIZEOFKEYINFO                                                                          STD_ON
#define VHSM_SIZEOFMEMORYAREA                                                                       STD_ON
#define VHSM_SIZEOFRANDOMINIT                                                                       STD_ON
#define VHSM_SIZEOFRESTRICTEDCHANNELS                                                               STD_ON
#define VHSM_SIZEOFSCHEDULABLEENTITIES                                                              STD_ON
#define VHSM_SIZEOFSCHEDULEDCHANNELS                                                                STD_ON
#define VHSM_SOFTRESETLIMITOFGENERAL                                                                STD_ON
#define VHSM_SPLITSIZEOFSECUREBOOT                                                                  STD_OFF  /**< Deactivateable: 'vHsm_SplitSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define VHSM_STORAGEMETHODOFSECUREBOOT                                                              STD_OFF  /**< Deactivateable: 'vHsm_StorageMethodOfSecureBoot' Reason: 'Parameter is not configured!' */
#define VHSM_SUPPORTSAVERESTORECONTEXTOFGENERAL                                                     STD_ON
#define VHSM_TRACEDEBUGOFDEVELOPMENT                                                                STD_OFF  /**< Deactivateable: 'vHsm_TraceDebugOfDevelopment' Reason: 'Parameter is not configured!' */
#define VHSM_TRACEERROROFDEVELOPMENT                                                                STD_OFF  /**< Deactivateable: 'vHsm_TraceErrorOfDevelopment' Reason: 'Parameter is not configured!' */
#define VHSM_TRACEINFOOFDEVELOPMENT                                                                 STD_OFF  /**< Deactivateable: 'vHsm_TraceInfoOfDevelopment' Reason: 'Parameter is not configured!' */
#define VHSM_TRACEKEYSTORAGEOFDEVELOPMENT                                                           STD_OFF  /**< Deactivateable: 'vHsm_TraceKeyStorageOfDevelopment' Reason: 'Parameter is not configured!' */
#define VHSM_TRACEWARNINGOFDEVELOPMENT                                                              STD_OFF  /**< Deactivateable: 'vHsm_TraceWarningOfDevelopment' Reason: 'Parameter is not configured!' */
#define VHSM_UPDATERADDRESSOFFIRMWAREUPDATE                                                         STD_ON
#define VHSM_UPGRADEPROTECTIONMODIFICATIONOFDEVELOPMENT                                             STD_OFF  /**< Deactivateable: 'vHsm_UpgradeProtectionModificationOfDevelopment' Reason: 'Parameter is not configured!' */
#define VHSM_USERREVISIONOFGENERAL                                                                  STD_OFF  /**< Deactivateable: 'vHsm_UserRevisionOfGeneral' Reason: 'Parameter is not configured!' */
#define VHSM_PCCONFIG                                                                               STD_ON
#define VHSM_ALLOWADDRESSCHANGEOFSECURESOFTWAREDOWNLOADOFPCCONFIG                                   STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.AllowAddressChangeOfSecureSoftwareDownload' Reason: 'Parameter is not configured!' */
#define VHSM_ATOMICBUFFERSIZEOFSECUREBOOTOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.AtomicBufferSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define VHSM_CHANNELINFOOFPCCONFIG                                                                  STD_ON
#define VHSM_CHANNELSOFIPCOFPCCONFIG                                                                STD_ON
#define VHSM_COREKEYOFPCCONFIG                                                                      STD_ON
#define VHSM_CRYPTOFUNCTIONSOFPCCONFIG                                                              STD_ON
#define VHSM_CSMHASHJOBREFERENCEOFSECUREBOOTUPDATEOFPCCONFIG                                        STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.CsmHashJobReferenceOfSecureBootUpdate' Reason: 'Reference is not configured!' */
#define VHSM_CSMJOBDECRYPTREFOFFIRMWAREUPDATEOFPCCONFIG                                             STD_ON
#define VHSM_CSMJOBENCRYPTREFOFFIRMWAREUPDATEOFPCCONFIG                                             STD_ON
#define VHSM_CSMJOBMACGENERATEREFOFFIRMWAREUPDATEOFPCCONFIG                                         STD_ON
#define VHSM_CSMJOBSIGNATUREVERIFYREFOFFIRMWAREUPDATEOFPCCONFIG                                     STD_ON
#define VHSM_CSMSIGNATUREJOBREFERENCEOFSECUREBOOTUPDATEOFPCCONFIG                                   STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.CsmSignatureJobReferenceOfSecureBootUpdate' Reason: 'Reference is not configured!' */
#define VHSM_CSMSIGNATUREJOBREFERENCEOFSECURESOFTWAREDOWNLOADOFPCCONFIG                             STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.CsmSignatureJobReferenceOfSecureSoftwareDownload' Reason: 'Reference is not configured!' */
#define VHSM_CYCLICVERIFICATIONSPLITSIZEOFSECUREBOOTOFPCCONFIG                                      STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.CyclicVerificationSplitSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define VHSM_DRIVEROBJECTMAPPINGINDOFPCCONFIG                                                       STD_ON
#define VHSM_DRIVEROBJECTMAPPINGOFPCCONFIG                                                          STD_ON
#define VHSM_ENABLERAMLOOPCALLOUTOFGENERALOFPCCONFIG                                                STD_ON
#define VHSM_ENABLESECUREBOOTAUTOSTARTOFDEVELOPMENTOFPCCONFIG                                       STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.EnableSecureBootAutostartOfDevelopment' Reason: 'Parameter is not configured!' */
#define VHSM_ERRORLOGEVENTLOGREFOFGENERALOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.ErrorLogEventLogRefOfGeneral' Reason: 'Reference is not configured!' */
#define VHSM_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VHSM_FINALMAGICNUMBEROFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define VHSM_FORCEINTERRUPTTRIGGERINGOFGENERALOFPCCONFIG                                            STD_ON
#define VHSM_FORCEDSEQUENTIALPROCESSINGONFIRSTVERIFICATIONOFSECUREBOOTOFPCCONFIG                    STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.ForcedSequentialProcessingOnFirstVerificationOfSecureBoot' Reason: 'Parameter is not configured!' */
#define VHSM_GENERATERANDOMIPCVALUESOFGENERALOFPCCONFIG                                             STD_ON
#define VHSM_GENERATERANDOMSTACKPROTECTIONCANARYOFGENERALOFPCCONFIG                                 STD_ON
#define VHSM_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                                STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define VHSM_INITDATAHASHCODEOFPCCONFIG                                                             STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define VHSM_INTERRUPTMODEOFSCHEDULINGOFPCCONFIG                                                    STD_ON
#define VHSM_INVALIDNVMBLOCKBEHAVIOUROFGENERALOFPCCONFIG                                            STD_ON
#define VHSM_IPCINSTANCEOFPCCONFIG                                                                  STD_ON
#define VHSM_ISRFORPROCESSINGOFSCHEDULINGOFPCCONFIG                                                 STD_ON
#define VHSM_JOBOBJECTINFOOFPCCONFIG                                                                STD_ON
#define VHSM_JOBOBJECTSOFPCCONFIG                                                                   STD_ON
#define VHSM_JUMPTOUPDATERRESTRICTIONOFFIRMWAREUPDATEOFPCCONFIG                                     STD_ON
#define VHSM_KEYINFOOFPCCONFIG                                                                      STD_ON
#define VHSM_KEYMANAGEMENTCHANNELOFCHANNELMAPPINGOFPCCONFIG                                         STD_ON
#define VHSM_MAINFUNCTIONPERIODOFGENERALOFPCCONFIG                                                  STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.MainFunctionPeriodOfGeneral' Reason: 'Parameter is not configured!' */
#define VHSM_MEMORYAREAOFPCCONFIG                                                                   STD_ON
#define VHSM_OPTIONBYTEMODIFICATIONOFDEVELOPMENTOFPCCONFIG                                          STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.OptionByteModificationOfDevelopment' Reason: 'Parameter is not configured!' */
#define VHSM_OSSUPPORTOFSCHEDULINGOFPCCONFIG                                                        STD_ON
#define VHSM_PROTOCOLVERSIONOFIPCOFPCCONFIG                                                         STD_ON
#define VHSM_QUEUESIZEOFSECUREBOOTOFPCCONFIG                                                        STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.QueueSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define VHSM_RANDOMCSMJOBREFOFGENERALOFPCCONFIG                                                     STD_ON
#define VHSM_RANDOMINITOFPCCONFIG                                                                   STD_ON
#define VHSM_REDIRECTIONOFGENERALOFPCCONFIG                                                         STD_ON
#define VHSM_RESTRICTEDCHANNELSOFPCCONFIG                                                           STD_ON
#define VHSM_SCHEDULABLEENTITIESOFPCCONFIG                                                          STD_ON
#define VHSM_SCHEDULEDCHANNELSOFPCCONFIG                                                            STD_ON
#define VHSM_SEGMENTSUCCESSCALLOUTOFSECUREBOOTOFPCCONFIG                                            STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.SegmentSuccessCalloutOfSecureBoot' Reason: 'Parameter is not configured!' */
#define VHSM_SIZEOFCHANNELINFOOFPCCONFIG                                                            STD_ON
#define VHSM_SIZEOFCOREKEYOFPCCONFIG                                                                STD_ON
#define VHSM_SIZEOFCRYPTOFUNCTIONSOFPCCONFIG                                                        STD_ON
#define VHSM_SIZEOFDRIVEROBJECTMAPPINGINDOFPCCONFIG                                                 STD_ON
#define VHSM_SIZEOFDRIVEROBJECTMAPPINGOFPCCONFIG                                                    STD_ON
#define VHSM_SIZEOFIPCINSTANCEOFPCCONFIG                                                            STD_ON
#define VHSM_SIZEOFJOBOBJECTINFOOFPCCONFIG                                                          STD_ON
#define VHSM_SIZEOFJOBOBJECTSOFPCCONFIG                                                             STD_ON
#define VHSM_SIZEOFKEYINFOOFPCCONFIG                                                                STD_ON
#define VHSM_SIZEOFMEMORYAREAOFPCCONFIG                                                             STD_ON
#define VHSM_SIZEOFRANDOMINITOFPCCONFIG                                                             STD_ON
#define VHSM_SIZEOFRESTRICTEDCHANNELSOFPCCONFIG                                                     STD_ON
#define VHSM_SIZEOFSCHEDULABLEENTITIESOFPCCONFIG                                                    STD_ON
#define VHSM_SIZEOFSCHEDULEDCHANNELSOFPCCONFIG                                                      STD_ON
#define VHSM_SOFTRESETLIMITOFGENERALOFPCCONFIG                                                      STD_ON
#define VHSM_SPLITSIZEOFSECUREBOOTOFPCCONFIG                                                        STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.SplitSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define VHSM_STORAGEMETHODOFSECUREBOOTOFPCCONFIG                                                    STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.StorageMethodOfSecureBoot' Reason: 'Parameter is not configured!' */
#define VHSM_SUPPORTSAVERESTORECONTEXTOFGENERALOFPCCONFIG                                           STD_ON
#define VHSM_TRACEDEBUGOFDEVELOPMENTOFPCCONFIG                                                      STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.TraceDebugOfDevelopment' Reason: 'Parameter is not configured!' */
#define VHSM_TRACEERROROFDEVELOPMENTOFPCCONFIG                                                      STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.TraceErrorOfDevelopment' Reason: 'Parameter is not configured!' */
#define VHSM_TRACEINFOOFDEVELOPMENTOFPCCONFIG                                                       STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.TraceInfoOfDevelopment' Reason: 'Parameter is not configured!' */
#define VHSM_TRACEKEYSTORAGEOFDEVELOPMENTOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.TraceKeyStorageOfDevelopment' Reason: 'Parameter is not configured!' */
#define VHSM_TRACEWARNINGOFDEVELOPMENTOFPCCONFIG                                                    STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.TraceWarningOfDevelopment' Reason: 'Parameter is not configured!' */
#define VHSM_UPDATERADDRESSOFFIRMWAREUPDATEOFPCCONFIG                                               STD_ON
#define VHSM_UPGRADEPROTECTIONMODIFICATIONOFDEVELOPMENTOFPCCONFIG                                   STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.UpgradeProtectionModificationOfDevelopment' Reason: 'Parameter is not configured!' */
#define VHSM_USERREVISIONOFGENERALOFPCCONFIG                                                        STD_OFF  /**< Deactivateable: 'vHsm_PCConfig.UserRevisionOfGeneral' Reason: 'Parameter is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCMinNumericValueDefines  vHsm Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define VHSM_MIN_IPCCHANNELOFJOBOBJECTS                                                             0u
#define VHSM_MIN_IPCINSTANCEOFJOBOBJECTS                                                            0u
#define VHSM_MIN_IPCMAPPINGOFJOBOBJECTS                                                             0u
#define VHSM_MIN_JOBRETVALOFJOBOBJECTS                                                              0u
#define VHSM_MIN_PROCESSKINDOFJOBOBJECTS                                                            0u
#define VHSM_MIN_REDIRECTIONFLAGSOFJOBOBJECTS                                                       0u
#define VHSM_MIN_USAGERESTRICTIONOFJOBOBJECTS                                                       0u
#define VHSM_MIN_LOGEVENTMEMORY                                                                     0u
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCMaxNumericValueDefines  vHsm Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define VHSM_MAX_IPCCHANNELOFJOBOBJECTS                                                             4294967295u
#define VHSM_MAX_IPCINSTANCEOFJOBOBJECTS                                                            255u
#define VHSM_MAX_IPCMAPPINGOFJOBOBJECTS                                                             255u
#define VHSM_MAX_JOBRETVALOFJOBOBJECTS                                                              4294967295u
#define VHSM_MAX_PROCESSKINDOFJOBOBJECTS                                                            255u
#define VHSM_MAX_REDIRECTIONFLAGSOFJOBOBJECTS                                                       255u
#define VHSM_MAX_USAGERESTRICTIONOFJOBOBJECTS                                                       255u
#define VHSM_MAX_LOGEVENTMEMORY                                                                     4294967295u
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCNoReferenceDefines  vHsm No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define VHSM_NO_DRIVEROBJECTMAPPINGINDENDIDXOFIPCINSTANCE                                           255u
#define VHSM_NO_DRIVEROBJECTMAPPINGINDSTARTIDXOFIPCINSTANCE                                         255u
#define VHSM_NO_PARTITIONREFINDENDIDXOFPARTITIONGROUP                                               255u
#define VHSM_NO_PARTITIONREFINDSTARTIDXOFPARTITIONGROUP                                             255u
#define VHSM_NO_CUSTOMCALLOUTCYCLICIDXOFSECUREBOOTGROUP                                             255u
#define VHSM_NO_CUSTOMCALLOUTIDXOFSECUREBOOTGROUP                                                   255u
#define VHSM_NO_SECUREBOOTSEGMENTENDIDXOFSECUREBOOTGROUP                                            255u
#define VHSM_NO_SECUREBOOTSEGMENTSTARTIDXOFSECUREBOOTGROUP                                          255u
#define VHSM_NO_SECUREBOOTSEGMENTINITVALUESIDXOFSECUREBOOTSEGMENT                                   255u
#define VHSM_NO_EXPECTEDCOMPATIBILITYVERSION                                                        65535u
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCMaskedBitDefines  vHsm Masked Bit Defines (PRE_COMPILE)
  \brief  These defines are masks to extract packed boolean data.
  \{
*/ 
#define VHSM_EVENTTRIGGEREDOFJOBOBJECTINFO_MASK                                                     0x02u
#define VHSM_ISRPROCESSINGOFJOBOBJECTINFO_MASK                                                      0x01u
#define VHSM_INTERNALONLYOFKEYINFO_MASK                                                             0x02u
#define VHSM_ROUTEDOFKEYINFO_MASK                                                                   0x01u
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCIsReducedToDefineDefines  vHsm Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VHSM_ISDEF_CRYPTOFUNCTIONSIDXOFCHANNELINFO                                                  STD_OFF
#define VHSM_ISDEF_DRIVEROBJECTREFOFCHANNELINFO                                                     STD_OFF
#define VHSM_ISDEF_AGGREGATEDCRYPTOKEYIDOFCOREKEY                                                   STD_OFF
#define VHSM_ISDEF_KEYIDOFCOREKEY                                                                   STD_OFF
#define VHSM_ISDEF_CANCELJOBOFCRYPTOFUNCTIONS                                                       STD_OFF
#define VHSM_ISDEF_CERTIFICATEPARSEOFCRYPTOFUNCTIONS                                                STD_OFF
#define VHSM_ISDEF_CERTIFICATEVERIFYOFCRYPTOFUNCTIONS                                               STD_OFF
#define VHSM_ISDEF_KEYCOPYOFCRYPTOFUNCTIONS                                                         STD_OFF
#define VHSM_ISDEF_KEYDERIVEOFCRYPTOFUNCTIONS                                                       STD_OFF
#define VHSM_ISDEF_KEYELEMENTCOPYOFCRYPTOFUNCTIONS                                                  STD_OFF
#define VHSM_ISDEF_KEYELEMENTCOPYPARTIALOFCRYPTOFUNCTIONS                                           STD_OFF
#define VHSM_ISDEF_KEYELEMENTGETOFCRYPTOFUNCTIONS                                                   STD_OFF
#define VHSM_ISDEF_KEYELEMENTIDSGETOFCRYPTOFUNCTIONS                                                STD_OFF
#define VHSM_ISDEF_KEYELEMENTSETOFCRYPTOFUNCTIONS                                                   STD_OFF
#define VHSM_ISDEF_KEYEXCHANGECALCPUBVALOFCRYPTOFUNCTIONS                                           STD_OFF
#define VHSM_ISDEF_KEYEXCHANGECALCSECRETOFCRYPTOFUNCTIONS                                           STD_OFF
#define VHSM_ISDEF_KEYGENERATEOFCRYPTOFUNCTIONS                                                     STD_OFF
#define VHSM_ISDEF_KEYVALIDSETOFCRYPTOFUNCTIONS                                                     STD_OFF
#define VHSM_ISDEF_PROCESSJOBOFCRYPTOFUNCTIONS                                                      STD_OFF
#define VHSM_ISDEF_RANDOMSEEDOFCRYPTOFUNCTIONS                                                      STD_OFF
#define VHSM_ISDEF_DUMMYOFCUSTOMCALLOUT                                                             STD_OFF
#define VHSM_ISDEF_DUMMYOFCUSTOMCALLOUTCYCLIC                                                       STD_OFF
#define VHSM_ISDEF_DRIVEROBJECTMAPPING                                                              STD_OFF
#define VHSM_ISDEF_DRIVEROBJECTMAPPINGIND                                                           STD_OFF
#define VHSM_ISDEF_DRIVEROBJECTMAPPINGINDENDIDXOFIPCINSTANCE                                        STD_OFF
#define VHSM_ISDEF_DRIVEROBJECTMAPPINGINDSTARTIDXOFIPCINSTANCE                                      STD_OFF
#define VHSM_ISDEF_DRIVEROBJECTMAPPINGINDUSEDOFIPCINSTANCE                                          STD_OFF
#define VHSM_ISDEF_HARDWAREUNITOFIPCINSTANCE                                                        STD_OFF
#define VHSM_ISDEF_IDOFIPCINSTANCE                                                                  STD_OFF
#define VHSM_ISDEF_MEMORYOFIPCINSTANCE                                                              STD_OFF
#define VHSM_ISDEF_RESPONSEINTERRUPTFLAGSETADDRESSOFIPCINSTANCE                                     STD_OFF
#define VHSM_ISDEF_RESPONSEINTERRUPTFLAGSETMASKOFIPCINSTANCE                                        STD_OFF
#define VHSM_ISDEF_EVENTTRIGGEREDOFJOBOBJECTINFO                                                    STD_OFF
#define VHSM_ISDEF_ISRPROCESSINGOFJOBOBJECTINFO                                                     STD_OFF
#define VHSM_ISDEF_MASKEDBITSOFJOBOBJECTINFO                                                        STD_OFF
#define VHSM_ISDEF_SCHEDEVENTREFOFJOBOBJECTINFO                                                     STD_OFF
#define VHSM_ISDEF_SCHEDTASKREFOFJOBOBJECTINFO                                                      STD_OFF
#define VHSM_ISDEF_CRYPTOFUNCTIONSIDXOFKEYINFO                                                      STD_OFF
#define VHSM_ISDEF_CRYPTOKEYIDOFKEYINFO                                                             STD_OFF
#define VHSM_ISDEF_INTERNALONLYOFKEYINFO                                                            STD_OFF
#define VHSM_ISDEF_MASKEDBITSOFKEYINFO                                                              STD_OFF
#define VHSM_ISDEF_ROUTEDOFKEYINFO                                                                  STD_OFF
#define VHSM_ISDEF_SECUREBOOTGROUPOFKEYINFO                                                         STD_OFF
#define VHSM_ISDEF_SECUREBOOTPROTECTEDOFKEYINFO                                                     STD_OFF
#define VHSM_ISDEF_SECUREBOOTSEGMENTOFKEYINFO                                                       STD_OFF
#define VHSM_ISDEF_COUNTERSIZEOFLOGEVENT                                                            STD_OFF
#define VHSM_ISDEF_DATASIZEOFLOGEVENT                                                               STD_OFF
#define VHSM_ISDEF_DISCARDWHENFULLOFLOGEVENT                                                        STD_OFF
#define VHSM_ISDEF_EVENTCALLOUTOFLOGEVENT                                                           STD_OFF
#define VHSM_ISDEF_EXPORTSTRATEGYOFLOGEVENT                                                         STD_OFF
#define VHSM_ISDEF_FILLLEVELTHRESHOLDOFLOGEVENT                                                     STD_OFF
#define VHSM_ISDEF_IDOFLOGEVENT                                                                     STD_OFF
#define VHSM_ISDEF_LOGEVENTMEMORYENDIDXOFLOGEVENT                                                   STD_OFF
#define VHSM_ISDEF_LOGEVENTMEMORYSTARTIDXOFLOGEVENT                                                 STD_OFF
#define VHSM_ISDEF_MAXENTRIESOFLOGEVENT                                                             STD_OFF
#define VHSM_ISDEF_NVBLOCKDESCRIPTOROFLOGEVENT                                                      STD_OFF
#define VHSM_ISDEF_NVBLOCKDESCRIPTORVALIDOFLOGEVENT                                                 STD_OFF
#define VHSM_ISDEF_NVPROCESSINGOFLOGEVENT                                                           STD_OFF
#define VHSM_ISDEF_TIMESTAMPSIZEOFLOGEVENT                                                          STD_OFF
#define VHSM_ISDEF_STARTOFMEMORYAREA                                                                STD_OFF
#define VHSM_ISDEF_STOPOFMEMORYAREA                                                                 STD_OFF
#define VHSM_ISDEF_TYPEOFMEMORYAREA                                                                 STD_OFF
#define VHSM_ISDEF_IDOFPARTITION                                                                    STD_OFF
#define VHSM_ISDEF_LENGTHOFPARTITION                                                                STD_OFF
#define VHSM_ISDEF_STARTADDRESSOFPARTITION                                                          STD_OFF
#define VHSM_ISDEF_PARTITIONREFINDENDIDXOFPARTITIONGROUP                                            STD_OFF
#define VHSM_ISDEF_PARTITIONREFINDSTARTIDXOFPARTITIONGROUP                                          STD_OFF
#define VHSM_ISDEF_PARTITIONREFINDUSEDOFPARTITIONGROUP                                              STD_OFF
#define VHSM_ISDEF_PARTITIONREF                                                                     STD_OFF
#define VHSM_ISDEF_PARTITIONREFIND                                                                  STD_OFF
#define VHSM_ISDEF_KEYELEMENTOFRANDOMINIT                                                           STD_OFF
#define VHSM_ISDEF_KEYOFRANDOMINIT                                                                  STD_OFF
#define VHSM_ISDEF_SCHEDULEDCHANNELSENDIDXOFSCHEDULABLEENTITIES                                     STD_OFF
#define VHSM_ISDEF_SCHEDULEDCHANNELSSTARTIDXOFSCHEDULABLEENTITIES                                   STD_OFF
#define VHSM_ISDEF_SCHEDULEDCHANNELS                                                                STD_OFF
#define VHSM_ISDEF_AUTOSTARTOFSECUREBOOTGROUP                                                       STD_OFF
#define VHSM_ISDEF_CRYPTOKEYIDOFSECUREBOOTGROUP                                                     STD_OFF
#define VHSM_ISDEF_CUSTOMCALLOUTCYCLICIDXOFSECUREBOOTGROUP                                          STD_OFF
#define VHSM_ISDEF_CUSTOMCALLOUTCYCLICUSEDOFSECUREBOOTGROUP                                         STD_OFF
#define VHSM_ISDEF_CUSTOMCALLOUTIDXOFSECUREBOOTGROUP                                                STD_OFF
#define VHSM_ISDEF_CUSTOMCALLOUTUSEDOFSECUREBOOTGROUP                                               STD_OFF
#define VHSM_ISDEF_CYCLICVERIFICATIONOFSECUREBOOTGROUP                                              STD_OFF
#define VHSM_ISDEF_IDOFSECUREBOOTGROUP                                                              STD_OFF
#define VHSM_ISDEF_NVBLOCKDESCRIPTOROFSECUREBOOTGROUP                                               STD_OFF
#define VHSM_ISDEF_NVBLOCKDESCRIPTORVALIDOFSECUREBOOTGROUP                                          STD_OFF
#define VHSM_ISDEF_SANCTIONOFSECUREBOOTGROUP                                                        STD_OFF
#define VHSM_ISDEF_SECUREBOOTSEGMENTENDIDXOFSECUREBOOTGROUP                                         STD_OFF
#define VHSM_ISDEF_SECUREBOOTSEGMENTSTARTIDXOFSECUREBOOTGROUP                                       STD_OFF
#define VHSM_ISDEF_SECUREBOOTSEGMENTUSEDOFSECUREBOOTGROUP                                           STD_OFF
#define VHSM_ISDEF_SERVICEOFSECUREBOOTGROUP                                                         STD_OFF
#define VHSM_ISDEF_SIGJOBEXTERNALSLOFSECUREBOOTGROUP                                                STD_OFF
#define VHSM_ISDEF_SLLOCATIONOFSECUREBOOTGROUP                                                      STD_OFF
#define VHSM_ISDEF_TAGHANDLINGOFSECUREBOOTGROUP                                                     STD_OFF
#define VHSM_ISDEF_TAGLENGTHOFSECUREBOOTGROUP                                                       STD_OFF
#define VHSM_ISDEF_VERJOBCOMPINTERNALOFSECUREBOOTGROUP                                              STD_OFF
#define VHSM_ISDEF_VERJOBEXTERNALSLOFSECUREBOOTGROUP                                                STD_OFF
#define VHSM_ISDEF_SECUREBOOTPROTECTEDCHANNELS                                                      STD_OFF
#define VHSM_ISDEF_SECUREBOOTPROTECTEDKEYS                                                          STD_OFF
#define VHSM_ISDEF_CRYPTOKEYIDOFSECUREBOOTSEGMENT                                                   STD_OFF
#define VHSM_ISDEF_GROUPIDXOFSECUREBOOTSEGMENT                                                      STD_OFF
#define VHSM_ISDEF_SECUREBOOTSEGMENTINITVALUESIDXOFSECUREBOOTSEGMENT                                STD_OFF
#define VHSM_ISDEF_SECUREBOOTSEGMENTINITVALUESUSEDOFSECUREBOOTSEGMENT                               STD_OFF
#define VHSM_ISDEF_ADDRESSOFSECUREBOOTSEGMENTINITVALUES                                             STD_OFF
#define VHSM_ISDEF_LENGTHOFSECUREBOOTSEGMENTINITVALUES                                              STD_OFF
#define VHSM_ISDEF_MODEOFSECUREBOOTSEGMENTINITVALUES                                                STD_OFF
#define VHSM_ISDEF_SANCTIONOFSECUREBOOTSEGMENTINITVALUES                                            STD_OFF
#define VHSM_ISDEF_CSMJOBPARALLELREFOFSECUREBOOTVERIFICATIONJOB                                     STD_OFF
#define VHSM_ISDEF_CSMJOBSEQUENTIALREFOFSECUREBOOTVERIFICATIONJOB                                   STD_OFF
#define VHSM_ISDEF_IDOFSECUREBOOTVERIFICATIONJOB                                                    STD_OFF
#define VHSM_ISDEF_PARALLELCHANNELREFOFSECUREBOOTVERIFICATIONJOB                                    STD_OFF
#define VHSM_ISDEF_ALLOWADDRESSCHANGEOFSECURESOFTWAREDOWNLOADOFPCCONFIG                             STD_OFF
#define VHSM_ISDEF_ATOMICBUFFERSIZEOFSECUREBOOTOFPCCONFIG                                           STD_OFF
#define VHSM_ISDEF_CHANNELINFOOFPCCONFIG                                                            STD_ON
#define VHSM_ISDEF_COREKEYOFPCCONFIG                                                                STD_ON
#define VHSM_ISDEF_CRYPTOFUNCTIONSOFPCCONFIG                                                        STD_ON
#define VHSM_ISDEF_CSMHASHJOBREFERENCEOFSECUREBOOTUPDATEOFPCCONFIG                                  STD_OFF
#define VHSM_ISDEF_CSMSIGNATUREJOBREFERENCEOFSECUREBOOTUPDATEOFPCCONFIG                             STD_OFF
#define VHSM_ISDEF_CSMSIGNATUREJOBREFERENCEOFSECURESOFTWAREDOWNLOADOFPCCONFIG                       STD_OFF
#define VHSM_ISDEF_CYCLICVERIFICATIONSPLITSIZEOFSECUREBOOTOFPCCONFIG                                STD_OFF
#define VHSM_ISDEF_DRIVEROBJECTMAPPINGINDOFPCCONFIG                                                 STD_ON
#define VHSM_ISDEF_DRIVEROBJECTMAPPINGOFPCCONFIG                                                    STD_ON
#define VHSM_ISDEF_ENABLESECUREBOOTAUTOSTARTOFDEVELOPMENTOFPCCONFIG                                 STD_OFF
#define VHSM_ISDEF_ERRORLOGEVENTLOGREFOFGENERALOFPCCONFIG                                           STD_OFF
#define VHSM_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                           STD_OFF
#define VHSM_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                       STD_OFF
#define VHSM_ISDEF_FORCEDSEQUENTIALPROCESSINGONFIRSTVERIFICATIONOFSECUREBOOTOFPCCONFIG              STD_OFF
#define VHSM_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                          STD_OFF
#define VHSM_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                       STD_OFF
#define VHSM_ISDEF_IPCINSTANCEOFPCCONFIG                                                            STD_ON
#define VHSM_ISDEF_JOBOBJECTINFOOFPCCONFIG                                                          STD_ON
#define VHSM_ISDEF_JOBOBJECTSOFPCCONFIG                                                             STD_ON
#define VHSM_ISDEF_KEYINFOOFPCCONFIG                                                                STD_ON
#define VHSM_ISDEF_MAINFUNCTIONPERIODOFGENERALOFPCCONFIG                                            STD_OFF
#define VHSM_ISDEF_MEMORYAREAOFPCCONFIG                                                             STD_ON
#define VHSM_ISDEF_OPTIONBYTEMODIFICATIONOFDEVELOPMENTOFPCCONFIG                                    STD_OFF
#define VHSM_ISDEF_QUEUESIZEOFSECUREBOOTOFPCCONFIG                                                  STD_OFF
#define VHSM_ISDEF_RANDOMINITOFPCCONFIG                                                             STD_ON
#define VHSM_ISDEF_RESTRICTEDCHANNELSOFPCCONFIG                                                     STD_ON
#define VHSM_ISDEF_SCHEDULABLEENTITIESOFPCCONFIG                                                    STD_ON
#define VHSM_ISDEF_SCHEDULEDCHANNELSOFPCCONFIG                                                      STD_ON
#define VHSM_ISDEF_SEGMENTSUCCESSCALLOUTOFSECUREBOOTOFPCCONFIG                                      STD_OFF
#define VHSM_ISDEF_SPLITSIZEOFSECUREBOOTOFPCCONFIG                                                  STD_OFF
#define VHSM_ISDEF_STORAGEMETHODOFSECUREBOOTOFPCCONFIG                                              STD_OFF
#define VHSM_ISDEF_TRACEDEBUGOFDEVELOPMENTOFPCCONFIG                                                STD_OFF
#define VHSM_ISDEF_TRACEERROROFDEVELOPMENTOFPCCONFIG                                                STD_OFF
#define VHSM_ISDEF_TRACEINFOOFDEVELOPMENTOFPCCONFIG                                                 STD_OFF
#define VHSM_ISDEF_TRACEKEYSTORAGEOFDEVELOPMENTOFPCCONFIG                                           STD_OFF
#define VHSM_ISDEF_TRACEWARNINGOFDEVELOPMENTOFPCCONFIG                                              STD_OFF
#define VHSM_ISDEF_UPGRADEPROTECTIONMODIFICATIONOFDEVELOPMENTOFPCCONFIG                             STD_OFF
#define VHSM_ISDEF_USERREVISIONOFGENERALOFPCCONFIG                                                  STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCEqualsAlwaysToDefines  vHsm Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VHSM_EQ2_CRYPTOFUNCTIONSIDXOFCHANNELINFO                                                    
#define VHSM_EQ2_DRIVEROBJECTREFOFCHANNELINFO                                                       
#define VHSM_EQ2_AGGREGATEDCRYPTOKEYIDOFCOREKEY                                                     
#define VHSM_EQ2_KEYIDOFCOREKEY                                                                     
#define VHSM_EQ2_CANCELJOBOFCRYPTOFUNCTIONS                                                         
#define VHSM_EQ2_CERTIFICATEPARSEOFCRYPTOFUNCTIONS                                                  
#define VHSM_EQ2_CERTIFICATEVERIFYOFCRYPTOFUNCTIONS                                                 
#define VHSM_EQ2_KEYCOPYOFCRYPTOFUNCTIONS                                                           
#define VHSM_EQ2_KEYDERIVEOFCRYPTOFUNCTIONS                                                         
#define VHSM_EQ2_KEYELEMENTCOPYOFCRYPTOFUNCTIONS                                                    
#define VHSM_EQ2_KEYELEMENTCOPYPARTIALOFCRYPTOFUNCTIONS                                             
#define VHSM_EQ2_KEYELEMENTGETOFCRYPTOFUNCTIONS                                                     
#define VHSM_EQ2_KEYELEMENTIDSGETOFCRYPTOFUNCTIONS                                                  
#define VHSM_EQ2_KEYELEMENTSETOFCRYPTOFUNCTIONS                                                     
#define VHSM_EQ2_KEYEXCHANGECALCPUBVALOFCRYPTOFUNCTIONS                                             
#define VHSM_EQ2_KEYEXCHANGECALCSECRETOFCRYPTOFUNCTIONS                                             
#define VHSM_EQ2_KEYGENERATEOFCRYPTOFUNCTIONS                                                       
#define VHSM_EQ2_KEYVALIDSETOFCRYPTOFUNCTIONS                                                       
#define VHSM_EQ2_PROCESSJOBOFCRYPTOFUNCTIONS                                                        
#define VHSM_EQ2_RANDOMSEEDOFCRYPTOFUNCTIONS                                                        
#define VHSM_EQ2_DUMMYOFCUSTOMCALLOUT                                                               
#define VHSM_EQ2_DUMMYOFCUSTOMCALLOUTCYCLIC                                                         
#define VHSM_EQ2_DRIVEROBJECTMAPPING                                                                
#define VHSM_EQ2_DRIVEROBJECTMAPPINGIND                                                             
#define VHSM_EQ2_DRIVEROBJECTMAPPINGINDENDIDXOFIPCINSTANCE                                          
#define VHSM_EQ2_DRIVEROBJECTMAPPINGINDSTARTIDXOFIPCINSTANCE                                        
#define VHSM_EQ2_DRIVEROBJECTMAPPINGINDUSEDOFIPCINSTANCE                                            
#define VHSM_EQ2_HARDWAREUNITOFIPCINSTANCE                                                          
#define VHSM_EQ2_IDOFIPCINSTANCE                                                                    
#define VHSM_EQ2_MEMORYOFIPCINSTANCE                                                                
#define VHSM_EQ2_RESPONSEINTERRUPTFLAGSETADDRESSOFIPCINSTANCE                                       
#define VHSM_EQ2_RESPONSEINTERRUPTFLAGSETMASKOFIPCINSTANCE                                          
#define VHSM_EQ2_EVENTTRIGGEREDOFJOBOBJECTINFO                                                      
#define VHSM_EQ2_ISRPROCESSINGOFJOBOBJECTINFO                                                       
#define VHSM_EQ2_MASKEDBITSOFJOBOBJECTINFO                                                          
#define VHSM_EQ2_SCHEDEVENTREFOFJOBOBJECTINFO                                                       
#define VHSM_EQ2_SCHEDTASKREFOFJOBOBJECTINFO                                                        
#define VHSM_EQ2_CRYPTOFUNCTIONSIDXOFKEYINFO                                                        
#define VHSM_EQ2_CRYPTOKEYIDOFKEYINFO                                                               
#define VHSM_EQ2_INTERNALONLYOFKEYINFO                                                              
#define VHSM_EQ2_MASKEDBITSOFKEYINFO                                                                
#define VHSM_EQ2_ROUTEDOFKEYINFO                                                                    
#define VHSM_EQ2_SECUREBOOTGROUPOFKEYINFO                                                           
#define VHSM_EQ2_SECUREBOOTPROTECTEDOFKEYINFO                                                       
#define VHSM_EQ2_SECUREBOOTSEGMENTOFKEYINFO                                                         
#define VHSM_EQ2_COUNTERSIZEOFLOGEVENT                                                              
#define VHSM_EQ2_DATASIZEOFLOGEVENT                                                                 
#define VHSM_EQ2_DISCARDWHENFULLOFLOGEVENT                                                          
#define VHSM_EQ2_EVENTCALLOUTOFLOGEVENT                                                             
#define VHSM_EQ2_EXPORTSTRATEGYOFLOGEVENT                                                           
#define VHSM_EQ2_FILLLEVELTHRESHOLDOFLOGEVENT                                                       
#define VHSM_EQ2_IDOFLOGEVENT                                                                       
#define VHSM_EQ2_LOGEVENTMEMORYENDIDXOFLOGEVENT                                                     
#define VHSM_EQ2_LOGEVENTMEMORYSTARTIDXOFLOGEVENT                                                   
#define VHSM_EQ2_MAXENTRIESOFLOGEVENT                                                               
#define VHSM_EQ2_NVBLOCKDESCRIPTOROFLOGEVENT                                                        
#define VHSM_EQ2_NVBLOCKDESCRIPTORVALIDOFLOGEVENT                                                   
#define VHSM_EQ2_NVPROCESSINGOFLOGEVENT                                                             
#define VHSM_EQ2_TIMESTAMPSIZEOFLOGEVENT                                                            
#define VHSM_EQ2_STARTOFMEMORYAREA                                                                  
#define VHSM_EQ2_STOPOFMEMORYAREA                                                                   
#define VHSM_EQ2_TYPEOFMEMORYAREA                                                                   
#define VHSM_EQ2_IDOFPARTITION                                                                      
#define VHSM_EQ2_LENGTHOFPARTITION                                                                  
#define VHSM_EQ2_STARTADDRESSOFPARTITION                                                            
#define VHSM_EQ2_PARTITIONREFINDENDIDXOFPARTITIONGROUP                                              
#define VHSM_EQ2_PARTITIONREFINDSTARTIDXOFPARTITIONGROUP                                            
#define VHSM_EQ2_PARTITIONREFINDUSEDOFPARTITIONGROUP                                                
#define VHSM_EQ2_PARTITIONREF                                                                       
#define VHSM_EQ2_PARTITIONREFIND                                                                    
#define VHSM_EQ2_KEYELEMENTOFRANDOMINIT                                                             
#define VHSM_EQ2_KEYOFRANDOMINIT                                                                    
#define VHSM_EQ2_SCHEDULEDCHANNELSENDIDXOFSCHEDULABLEENTITIES                                       
#define VHSM_EQ2_SCHEDULEDCHANNELSSTARTIDXOFSCHEDULABLEENTITIES                                     
#define VHSM_EQ2_SCHEDULEDCHANNELS                                                                  
#define VHSM_EQ2_AUTOSTARTOFSECUREBOOTGROUP                                                         
#define VHSM_EQ2_CRYPTOKEYIDOFSECUREBOOTGROUP                                                       
#define VHSM_EQ2_CUSTOMCALLOUTCYCLICIDXOFSECUREBOOTGROUP                                            
#define VHSM_EQ2_CUSTOMCALLOUTCYCLICUSEDOFSECUREBOOTGROUP                                           
#define VHSM_EQ2_CUSTOMCALLOUTIDXOFSECUREBOOTGROUP                                                  
#define VHSM_EQ2_CUSTOMCALLOUTUSEDOFSECUREBOOTGROUP                                                 
#define VHSM_EQ2_CYCLICVERIFICATIONOFSECUREBOOTGROUP                                                
#define VHSM_EQ2_IDOFSECUREBOOTGROUP                                                                
#define VHSM_EQ2_NVBLOCKDESCRIPTOROFSECUREBOOTGROUP                                                 
#define VHSM_EQ2_NVBLOCKDESCRIPTORVALIDOFSECUREBOOTGROUP                                            
#define VHSM_EQ2_SANCTIONOFSECUREBOOTGROUP                                                          
#define VHSM_EQ2_SECUREBOOTSEGMENTENDIDXOFSECUREBOOTGROUP                                           
#define VHSM_EQ2_SECUREBOOTSEGMENTSTARTIDXOFSECUREBOOTGROUP                                         
#define VHSM_EQ2_SECUREBOOTSEGMENTUSEDOFSECUREBOOTGROUP                                             
#define VHSM_EQ2_SERVICEOFSECUREBOOTGROUP                                                           
#define VHSM_EQ2_SIGJOBEXTERNALSLOFSECUREBOOTGROUP                                                  
#define VHSM_EQ2_SLLOCATIONOFSECUREBOOTGROUP                                                        
#define VHSM_EQ2_TAGHANDLINGOFSECUREBOOTGROUP                                                       
#define VHSM_EQ2_TAGLENGTHOFSECUREBOOTGROUP                                                         
#define VHSM_EQ2_VERJOBCOMPINTERNALOFSECUREBOOTGROUP                                                
#define VHSM_EQ2_VERJOBEXTERNALSLOFSECUREBOOTGROUP                                                  
#define VHSM_EQ2_SECUREBOOTPROTECTEDCHANNELS                                                        
#define VHSM_EQ2_SECUREBOOTPROTECTEDKEYS                                                            
#define VHSM_EQ2_CRYPTOKEYIDOFSECUREBOOTSEGMENT                                                     
#define VHSM_EQ2_GROUPIDXOFSECUREBOOTSEGMENT                                                        
#define VHSM_EQ2_SECUREBOOTSEGMENTINITVALUESIDXOFSECUREBOOTSEGMENT                                  
#define VHSM_EQ2_SECUREBOOTSEGMENTINITVALUESUSEDOFSECUREBOOTSEGMENT                                 
#define VHSM_EQ2_ADDRESSOFSECUREBOOTSEGMENTINITVALUES                                               
#define VHSM_EQ2_LENGTHOFSECUREBOOTSEGMENTINITVALUES                                                
#define VHSM_EQ2_MODEOFSECUREBOOTSEGMENTINITVALUES                                                  
#define VHSM_EQ2_SANCTIONOFSECUREBOOTSEGMENTINITVALUES                                              
#define VHSM_EQ2_CSMJOBPARALLELREFOFSECUREBOOTVERIFICATIONJOB                                       
#define VHSM_EQ2_CSMJOBSEQUENTIALREFOFSECUREBOOTVERIFICATIONJOB                                     
#define VHSM_EQ2_IDOFSECUREBOOTVERIFICATIONJOB                                                      
#define VHSM_EQ2_PARALLELCHANNELREFOFSECUREBOOTVERIFICATIONJOB                                      
#define VHSM_EQ2_ALLOWADDRESSCHANGEOFSECURESOFTWAREDOWNLOADOFPCCONFIG                               
#define VHSM_EQ2_ATOMICBUFFERSIZEOFSECUREBOOTOFPCCONFIG                                             
#define VHSM_EQ2_CHANNELINFOOFPCCONFIG                                                              vHsm_ChannelInfo
#define VHSM_EQ2_COREKEYOFPCCONFIG                                                                  vHsm_CoreKey
#define VHSM_EQ2_CRYPTOFUNCTIONSOFPCCONFIG                                                          vHsm_CryptoFunctions
#define VHSM_EQ2_CSMHASHJOBREFERENCEOFSECUREBOOTUPDATEOFPCCONFIG                                    
#define VHSM_EQ2_CSMSIGNATUREJOBREFERENCEOFSECUREBOOTUPDATEOFPCCONFIG                               
#define VHSM_EQ2_CSMSIGNATUREJOBREFERENCEOFSECURESOFTWAREDOWNLOADOFPCCONFIG                         
#define VHSM_EQ2_CYCLICVERIFICATIONSPLITSIZEOFSECUREBOOTOFPCCONFIG                                  
#define VHSM_EQ2_DRIVEROBJECTMAPPINGINDOFPCCONFIG                                                   vHsm_DriverObjectMappingInd
#define VHSM_EQ2_DRIVEROBJECTMAPPINGOFPCCONFIG                                                      vHsm_DriverObjectMapping
#define VHSM_EQ2_ENABLESECUREBOOTAUTOSTARTOFDEVELOPMENTOFPCCONFIG                                   
#define VHSM_EQ2_ERRORLOGEVENTLOGREFOFGENERALOFPCCONFIG                                             
#define VHSM_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                             
#define VHSM_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                         
#define VHSM_EQ2_FORCEDSEQUENTIALPROCESSINGONFIRSTVERIFICATIONOFSECUREBOOTOFPCCONFIG                
#define VHSM_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                            
#define VHSM_EQ2_INITDATAHASHCODEOFPCCONFIG                                                         
#define VHSM_EQ2_IPCINSTANCEOFPCCONFIG                                                              vHsm_IpcInstance
#define VHSM_EQ2_JOBOBJECTINFOOFPCCONFIG                                                            vHsm_JobObjectInfo
#define VHSM_EQ2_JOBOBJECTSOFPCCONFIG                                                               vHsm_JobObjects
#define VHSM_EQ2_KEYINFOOFPCCONFIG                                                                  vHsm_KeyInfo
#define VHSM_EQ2_MAINFUNCTIONPERIODOFGENERALOFPCCONFIG                                              
#define VHSM_EQ2_MEMORYAREAOFPCCONFIG                                                               vHsm_MemoryArea
#define VHSM_EQ2_OPTIONBYTEMODIFICATIONOFDEVELOPMENTOFPCCONFIG                                      
#define VHSM_EQ2_QUEUESIZEOFSECUREBOOTOFPCCONFIG                                                    
#define VHSM_EQ2_RANDOMINITOFPCCONFIG                                                               vHsm_RandomInit
#define VHSM_EQ2_RESTRICTEDCHANNELSOFPCCONFIG                                                       vHsm_RestrictedChannels
#define VHSM_EQ2_SCHEDULABLEENTITIESOFPCCONFIG                                                      vHsm_SchedulableEntities
#define VHSM_EQ2_SCHEDULEDCHANNELSOFPCCONFIG                                                        vHsm_ScheduledChannels
#define VHSM_EQ2_SEGMENTSUCCESSCALLOUTOFSECUREBOOTOFPCCONFIG                                        
#define VHSM_EQ2_SPLITSIZEOFSECUREBOOTOFPCCONFIG                                                    
#define VHSM_EQ2_STORAGEMETHODOFSECUREBOOTOFPCCONFIG                                                
#define VHSM_EQ2_TRACEDEBUGOFDEVELOPMENTOFPCCONFIG                                                  
#define VHSM_EQ2_TRACEERROROFDEVELOPMENTOFPCCONFIG                                                  
#define VHSM_EQ2_TRACEINFOOFDEVELOPMENTOFPCCONFIG                                                   
#define VHSM_EQ2_TRACEKEYSTORAGEOFDEVELOPMENTOFPCCONFIG                                             
#define VHSM_EQ2_TRACEWARNINGOFDEVELOPMENTOFPCCONFIG                                                
#define VHSM_EQ2_UPGRADEPROTECTIONMODIFICATIONOFDEVELOPMENTOFPCCONFIG                               
#define VHSM_EQ2_USERREVISIONOFGENERALOFPCCONFIG                                                    
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCSymbolicInitializationPointers  vHsm Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define vHsm_Config_Ptr                                                                             NULL_PTR  /**< symbolic identifier which shall be used to initialize 'vHsm' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCInitializationSymbols  vHsm Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define vHsm_Config                                                                                 NULL_PTR  /**< symbolic identifier which could be used to initialize 'vHsm */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCGeneral  vHsm General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define VHSM_CHECK_INIT_POINTER                                                                     STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define VHSM_FINAL_MAGIC_NUMBER                                                                     0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of vHsm */
#define VHSM_INDIVIDUAL_POSTBUILD                                                                   STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'vHsm' is not configured to be postbuild capable. */
#define VHSM_INIT_DATA                                                                              VHSM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define VHSM_INIT_DATA_HASH_CODE                                                                    -361787251  /**< the precompile constant to validate the initialization structure at initialization time of vHsm with a hashcode. The seed value is '0xFF1Eu' */
#define VHSM_USE_ECUM_BSW_ERROR_HOOK                                                                STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define VHSM_USE_INIT_POINTER                                                                       STD_OFF  /**< STD_ON if the init pointer vHsm shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  vHsmPBDataSwitches  vHsm Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define VHSM_PBCONFIG                                                                               STD_OFF  /**< Deactivateable: 'vHsm_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define VHSM_LTCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'vHsm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define VHSM_PCCONFIGIDXOFPBCONFIG                                                                  STD_OFF  /**< Deactivateable: 'vHsm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPBIsReducedToDefineDefines  vHsm Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define VHSM_ISDEF_LTCONFIGIDXOFPBCONFIG                                                            STD_OFF
#define VHSM_ISDEF_PCCONFIGIDXOFPBCONFIG                                                            STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPBEqualsAlwaysToDefines  vHsm Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define VHSM_EQ2_LTCONFIGIDXOFPBCONFIG                                                              
#define VHSM_EQ2_PCCONFIGIDXOFPBCONFIG                                                              
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
  \defgroup  vHsmPCGetRootDataMacros  vHsm Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define vHsm_IsAllowAddressChangeOfSecureSoftwareDownloadOfPCConfig()                                 /**< Deactivateable: 'vHsm_PCConfig.AllowAddressChangeOfSecureSoftwareDownload' Reason: 'Parameter is not configured!' */
#define vHsm_GetAtomicBufferSizeOfSecureBootOfPCConfig()                                              /**< Deactivateable: 'vHsm_PCConfig.AtomicBufferSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_GetCsmHashJobReferenceOfSecureBootUpdateOfPCConfig()                                     /**< Deactivateable: 'vHsm_PCConfig.CsmHashJobReferenceOfSecureBootUpdate' Reason: 'Reference is not configured!' */
#define vHsm_GetCsmSignatureJobReferenceOfSecureBootUpdateOfPCConfig()                                /**< Deactivateable: 'vHsm_PCConfig.CsmSignatureJobReferenceOfSecureBootUpdate' Reason: 'Reference is not configured!' */
#define vHsm_GetCsmSignatureJobReferenceOfSecureSoftwareDownloadOfPCConfig()                          /**< Deactivateable: 'vHsm_PCConfig.CsmSignatureJobReferenceOfSecureSoftwareDownload' Reason: 'Reference is not configured!' */
#define vHsm_GetCyclicVerificationSplitSizeOfSecureBootOfPCConfig()                                   /**< Deactivateable: 'vHsm_PCConfig.CyclicVerificationSplitSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_IsEnableSecureBootAutostartOfDevelopmentOfPCConfig()                                     /**< Deactivateable: 'vHsm_PCConfig.EnableSecureBootAutostartOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_GetErrorLogEventLogRefOfGeneralOfPCConfig()                                              /**< Deactivateable: 'vHsm_PCConfig.ErrorLogEventLogRefOfGeneral' Reason: 'Reference is not configured!' */
#define vHsm_GetExpectedCompatibilityVersionOfPCConfig()                                              /**< Deactivateable: 'vHsm_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsm_GetFinalMagicNumberOfPCConfig()                                                          /**< Deactivateable: 'vHsm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vHsm_IsForcedSequentialProcessingOnFirstVerificationOfSecureBootOfPCConfig()                  /**< Deactivateable: 'vHsm_PCConfig.ForcedSequentialProcessingOnFirstVerificationOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_GetGeneratorCompatibilityVersionOfPCConfig()                                             /**< Deactivateable: 'vHsm_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsm_GetInitDataHashCodeOfPCConfig()                                                          /**< Deactivateable: 'vHsm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vHsm_GetMainFunctionPeriodOfGeneralOfPCConfig()                                               /**< Deactivateable: 'vHsm_PCConfig.MainFunctionPeriodOfGeneral' Reason: 'Parameter is not configured!' */
#define vHsm_IsOptionByteModificationOfDevelopmentOfPCConfig()                                        /**< Deactivateable: 'vHsm_PCConfig.OptionByteModificationOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_GetQueueSizeOfSecureBootOfPCConfig()                                                     /**< Deactivateable: 'vHsm_PCConfig.QueueSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_IsSegmentSuccessCalloutOfSecureBootOfPCConfig()                                          /**< Deactivateable: 'vHsm_PCConfig.SegmentSuccessCalloutOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_GetSplitSizeOfSecureBootOfPCConfig()                                                     /**< Deactivateable: 'vHsm_PCConfig.SplitSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_GetStorageMethodOfSecureBootOfPCConfig()                                                 /**< Deactivateable: 'vHsm_PCConfig.StorageMethodOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_IsTraceDebugOfDevelopmentOfPCConfig()                                                    /**< Deactivateable: 'vHsm_PCConfig.TraceDebugOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_IsTraceErrorOfDevelopmentOfPCConfig()                                                    /**< Deactivateable: 'vHsm_PCConfig.TraceErrorOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_IsTraceInfoOfDevelopmentOfPCConfig()                                                     /**< Deactivateable: 'vHsm_PCConfig.TraceInfoOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_IsTraceKeyStorageOfDevelopmentOfPCConfig()                                               /**< Deactivateable: 'vHsm_PCConfig.TraceKeyStorageOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_IsTraceWarningOfDevelopmentOfPCConfig()                                                  /**< Deactivateable: 'vHsm_PCConfig.TraceWarningOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_IsUpgradeProtectionModificationOfDevelopmentOfPCConfig()                                 /**< Deactivateable: 'vHsm_PCConfig.UpgradeProtectionModificationOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_GetUserRevisionOfGeneralOfPCConfig()                                                     /**< Deactivateable: 'vHsm_PCConfig.UserRevisionOfGeneral' Reason: 'Parameter is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCGetConstantDuplicatedRootDataMacros  vHsm Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define vHsm_GetChannelInfoOfPCConfig()                                                             vHsm_ChannelInfo  /**< the pointer to vHsm_ChannelInfo */
#define vHsm_GetChannelsOfIpcOfPCConfig()                                                           2u
#define vHsm_GetCoreKeyOfPCConfig()                                                                 vHsm_CoreKey  /**< the pointer to vHsm_CoreKey */
#define vHsm_GetCryptoFunctionsOfPCConfig()                                                         vHsm_CryptoFunctions  /**< the pointer to vHsm_CryptoFunctions */
#define vHsm_GetCsmJobDecryptRefOfFirmwareUpdateOfPCConfig()                                        CsmConf_CsmJob_CsmJob_FirmwareUpdate_Decrypt
#define vHsm_GetCsmJobEncryptRefOfFirmwareUpdateOfPCConfig()                                        CsmConf_CsmJob_CsmJob_FirmwareUpdate_Encrypt
#define vHsm_GetCsmJobMacGenerateRefOfFirmwareUpdateOfPCConfig()                                    CsmConf_CsmJob_CsmJob_FirmwareUpdate_MacGenerate
#define vHsm_GetCsmJobSignatureVerifyRefOfFirmwareUpdateOfPCConfig()                                CsmConf_CsmJob_CsmJob_FirmwareUpdate_SignatureVerify
#define vHsm_GetDriverObjectMappingIndOfPCConfig()                                                  vHsm_DriverObjectMappingInd  /**< the pointer to vHsm_DriverObjectMappingInd */
#define vHsm_GetDriverObjectMappingOfPCConfig()                                                     vHsm_DriverObjectMapping  /**< the pointer to vHsm_DriverObjectMapping */
#define vHsm_IsEnableRamLoopCalloutOfGeneralOfPCConfig()                                            (((TRUE)) != FALSE)
#define vHsm_IsForceInterruptTriggeringOfGeneralOfPCConfig()                                        (((FALSE)) != FALSE)
#define vHsm_IsGenerateRandomIpcValuesOfGeneralOfPCConfig()                                         (((FALSE)) != FALSE)
#define vHsm_IsGenerateRandomStackProtectionCanaryOfGeneralOfPCConfig()                             (((FALSE)) != FALSE)
#define vHsm_IsInterruptModeOfSchedulingOfPCConfig()                                                (((TRUE)) != FALSE)
#define vHsm_GetInvalidNvMBlockBehaviourOfGeneralOfPCConfig()                                       VHSM_IGNORE_INVALID_BLOCKS
#define vHsm_GetIpcInstanceOfPCConfig()                                                             vHsm_IpcInstance  /**< the pointer to vHsm_IpcInstance */
#define vHsm_GetIsrForProcessingOfSchedulingOfPCConfig()                                            VHSM_CATEGORY_1
#define vHsm_GetJobObjectInfoOfPCConfig()                                                           vHsm_JobObjectInfo  /**< the pointer to vHsm_JobObjectInfo */
#define vHsm_GetJobObjectsOfPCConfig()                                                              vHsm_JobObjects  /**< the pointer to vHsm_JobObjects */
#define vHsm_IsJumpToUpdaterRestrictionOfFirmwareUpdateOfPCConfig()                                 (((FALSE)) != FALSE)
#define vHsm_GetKeyInfoOfPCConfig()                                                                 vHsm_KeyInfo  /**< the pointer to vHsm_KeyInfo */
#define vHsm_GetKeyManagementChannelOfChannelMappingOfPCConfig()                                    CryIfConf_CryIfChannel_Crypto_30_vHsm_KeyManagement
#define vHsm_GetMemoryAreaOfPCConfig()                                                              vHsm_MemoryArea  /**< the pointer to vHsm_MemoryArea */
#define vHsm_IsOsSupportOfSchedulingOfPCConfig()                                                    (((TRUE)) != FALSE)
#define vHsm_GetProtocolVersionOfIpcOfPCConfig()                                                    3u
#define vHsm_GetRandomCsmJobRefOfGeneralOfPCConfig()                                                CsmConf_CsmJob_CsmJob_Random
#define vHsm_GetRandomInitOfPCConfig()                                                              vHsm_RandomInit  /**< the pointer to vHsm_RandomInit */
#define vHsm_IsRedirectionOfGeneralOfPCConfig()                                                     (((FALSE)) != FALSE)
#define vHsm_GetRestrictedChannelsOfPCConfig()                                                      vHsm_RestrictedChannels  /**< the pointer to vHsm_RestrictedChannels */
#define vHsm_GetSchedulableEntitiesOfPCConfig()                                                     vHsm_SchedulableEntities  /**< the pointer to vHsm_SchedulableEntities */
#define vHsm_GetScheduledChannelsOfPCConfig()                                                       vHsm_ScheduledChannels  /**< the pointer to vHsm_ScheduledChannels */
#define vHsm_GetSizeOfChannelInfoOfPCConfig()                                                       12u  /**< the number of accomplishable value elements in vHsm_ChannelInfo */
#define vHsm_GetSizeOfCoreKeyOfPCConfig()                                                           3u  /**< the number of accomplishable value elements in vHsm_CoreKey */
#define vHsm_GetSizeOfCryptoFunctionsOfPCConfig()                                                   5u  /**< the number of accomplishable value elements in vHsm_CryptoFunctions */
#define vHsm_GetSizeOfDriverObjectMappingIndOfPCConfig()                                            7u  /**< the number of accomplishable value elements in vHsm_DriverObjectMappingInd */
#define vHsm_GetSizeOfDriverObjectMappingOfPCConfig()                                               7u  /**< the number of accomplishable value elements in vHsm_DriverObjectMapping */
#define vHsm_GetSizeOfIpcInstanceOfPCConfig()                                                       1u  /**< the number of accomplishable value elements in vHsm_IpcInstance */
#define vHsm_GetSizeOfJobObjectInfoOfPCConfig()                                                     12u  /**< the number of accomplishable value elements in vHsm_JobObjectInfo */
#define vHsm_GetSizeOfJobObjectsOfPCConfig()                                                        12u  /**< the number of accomplishable value elements in vHsm_JobObjects */
#define vHsm_GetSizeOfKeyInfoOfPCConfig()                                                           62u  /**< the number of accomplishable value elements in vHsm_KeyInfo */
#define vHsm_GetSizeOfMemoryAreaOfPCConfig()                                                        8u  /**< the number of accomplishable value elements in vHsm_MemoryArea */
#define vHsm_GetSizeOfRandomInitOfPCConfig()                                                        1u  /**< the number of accomplishable value elements in vHsm_RandomInit */
#define vHsm_GetSizeOfRestrictedChannelsOfPCConfig()                                                12u  /**< the number of accomplishable value elements in vHsm_RestrictedChannels */
#define vHsm_GetSizeOfSchedulableEntitiesOfPCConfig()                                               2u  /**< the number of accomplishable value elements in vHsm_SchedulableEntities */
#define vHsm_GetSizeOfScheduledChannelsOfPCConfig()                                                 12u  /**< the number of accomplishable value elements in vHsm_ScheduledChannels */
#define vHsm_GetSoftResetLimitOfGeneralOfPCConfig()                                                 8u
#define vHsm_IsSupportSaveRestoreContextOfGeneralOfPCConfig()                                       (((FALSE)) != FALSE)
#define vHsm_GetUpdaterAddressOfFirmwareUpdateOfPCConfig()                                          VHSM_FIRMWARE_UPDATER
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCGetDataMacros  vHsm Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define vHsm_GetCryptoFunctionsIdxOfChannelInfo(Index)                                              (vHsm_GetChannelInfoOfPCConfig()[(Index)].CryptoFunctionsIdxOfChannelInfo)
#define vHsm_GetDriverObjectRefOfChannelInfo(Index)                                                 (vHsm_GetChannelInfoOfPCConfig()[(Index)].DriverObjectRefOfChannelInfo)
#define vHsm_GetAggregatedCryptoKeyIdOfCoreKey(Index)                                               (vHsm_GetCoreKeyOfPCConfig()[(Index)].AggregatedCryptoKeyIdOfCoreKey)
#define vHsm_GetCancelJobOfCryptoFunctions(Index)                                                   (vHsm_GetCryptoFunctionsOfPCConfig()[(Index)].CancelJobOfCryptoFunctions)
#define vHsm_GetCertificateParseOfCryptoFunctions(Index)                                            (vHsm_GetCryptoFunctionsOfPCConfig()[(Index)].CertificateParseOfCryptoFunctions)
#define vHsm_GetCertificateVerifyOfCryptoFunctions(Index)                                           (vHsm_GetCryptoFunctionsOfPCConfig()[(Index)].CertificateVerifyOfCryptoFunctions)
#define vHsm_GetKeyCopyOfCryptoFunctions(Index)                                                     (vHsm_GetCryptoFunctionsOfPCConfig()[(Index)].KeyCopyOfCryptoFunctions)
#define vHsm_GetKeyDeriveOfCryptoFunctions(Index)                                                   (vHsm_GetCryptoFunctionsOfPCConfig()[(Index)].KeyDeriveOfCryptoFunctions)
#define vHsm_GetKeyElementCopyOfCryptoFunctions(Index)                                              (vHsm_GetCryptoFunctionsOfPCConfig()[(Index)].KeyElementCopyOfCryptoFunctions)
#define vHsm_GetKeyElementCopyPartialOfCryptoFunctions(Index)                                       (vHsm_GetCryptoFunctionsOfPCConfig()[(Index)].KeyElementCopyPartialOfCryptoFunctions)
#define vHsm_GetKeyElementGetOfCryptoFunctions(Index)                                               (vHsm_GetCryptoFunctionsOfPCConfig()[(Index)].KeyElementGetOfCryptoFunctions)
#define vHsm_GetKeyElementIdsGetOfCryptoFunctions(Index)                                            (vHsm_GetCryptoFunctionsOfPCConfig()[(Index)].KeyElementIdsGetOfCryptoFunctions)
#define vHsm_GetKeyElementSetOfCryptoFunctions(Index)                                               (vHsm_GetCryptoFunctionsOfPCConfig()[(Index)].KeyElementSetOfCryptoFunctions)
#define vHsm_GetKeyExchangeCalcPubValOfCryptoFunctions(Index)                                       (vHsm_GetCryptoFunctionsOfPCConfig()[(Index)].KeyExchangeCalcPubValOfCryptoFunctions)
#define vHsm_GetKeyExchangeCalcSecretOfCryptoFunctions(Index)                                       (vHsm_GetCryptoFunctionsOfPCConfig()[(Index)].KeyExchangeCalcSecretOfCryptoFunctions)
#define vHsm_GetKeyGenerateOfCryptoFunctions(Index)                                                 (vHsm_GetCryptoFunctionsOfPCConfig()[(Index)].KeyGenerateOfCryptoFunctions)
#define vHsm_GetKeyValidSetOfCryptoFunctions(Index)                                                 (vHsm_GetCryptoFunctionsOfPCConfig()[(Index)].KeyValidSetOfCryptoFunctions)
#define vHsm_GetProcessJobOfCryptoFunctions(Index)                                                  (vHsm_GetCryptoFunctionsOfPCConfig()[(Index)].ProcessJobOfCryptoFunctions)
#define vHsm_GetRandomSeedOfCryptoFunctions(Index)                                                  (vHsm_GetCryptoFunctionsOfPCConfig()[(Index)].RandomSeedOfCryptoFunctions)
#define vHsm_IsDummyOfCustomCallout(Index)                                                            /**< Deactivateable: 'vHsm_CustomCallout.Dummy' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_IsDummyOfCustomCalloutCyclic(Index)                                                      /**< Deactivateable: 'vHsm_CustomCalloutCyclic.Dummy' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetDriverObjectMapping(Index)                                                          (vHsm_GetDriverObjectMappingOfPCConfig()[(Index)])
#define vHsm_GetMemoryOfIpcInstance(Index)                                                          (vHsm_GetIpcInstanceOfPCConfig()[(Index)].MemoryOfIpcInstance)
#define vHsm_GetMaskedBitsOfJobObjectInfo(Index)                                                    (vHsm_GetJobObjectInfoOfPCConfig()[(Index)].MaskedBitsOfJobObjectInfo)
#define vHsm_GetSchedEventRefOfJobObjectInfo(Index)                                                 (vHsm_GetJobObjectInfoOfPCConfig()[(Index)].SchedEventRefOfJobObjectInfo)
#define vHsm_GetSchedTaskRefOfJobObjectInfo(Index)                                                  (vHsm_GetJobObjectInfoOfPCConfig()[(Index)].SchedTaskRefOfJobObjectInfo)
#define vHsm_IsCancelFlagOfJobObjects(Index)                                                        ((vHsm_GetJobObjectsOfPCConfig()[(Index)].CancelFlagOfJobObjects) != FALSE)
#define vHsm_GetIpcChannelOfJobObjects(Index)                                                       (vHsm_GetJobObjectsOfPCConfig()[(Index)].IpcChannelOfJobObjects)
#define vHsm_GetIpcInstanceOfJobObjects(Index)                                                      (vHsm_GetJobObjectsOfPCConfig()[(Index)].IpcInstanceOfJobObjects)
#define vHsm_GetIpcMappingOfJobObjects(Index)                                                       (vHsm_GetJobObjectsOfPCConfig()[(Index)].IpcMappingOfJobObjects)
#define vHsm_GetJobDataOfJobObjects(Index)                                                          (vHsm_GetJobObjectsOfPCConfig()[(Index)].JobDataOfJobObjects)
#define vHsm_GetJobRequestIdOfJobObjects(Index)                                                     (vHsm_GetJobObjectsOfPCConfig()[(Index)].JobRequestIdOfJobObjects)
#define vHsm_GetJobRequestKindOfJobObjects(Index)                                                   (vHsm_GetJobObjectsOfPCConfig()[(Index)].JobRequestKindOfJobObjects)
#define vHsm_GetJobRetValOfJobObjects(Index)                                                        (vHsm_GetJobObjectsOfPCConfig()[(Index)].JobRetValOfJobObjects)
#define vHsm_GetLocalOutputOfJobObjects(Index)                                                      (vHsm_GetJobObjectsOfPCConfig()[(Index)].LocalOutputOfJobObjects)
#define vHsm_GetProcessKindOfJobObjects(Index)                                                      (vHsm_GetJobObjectsOfPCConfig()[(Index)].ProcessKindOfJobObjects)
#define vHsm_GetProcessingTypeOfJobObjects(Index)                                                   (vHsm_GetJobObjectsOfPCConfig()[(Index)].ProcessingTypeOfJobObjects)
#define vHsm_GetRedirectionFlagsOfJobObjects(Index)                                                 (vHsm_GetJobObjectsOfPCConfig()[(Index)].RedirectionFlagsOfJobObjects)
#define vHsm_GetStateOfJobObjects(Index)                                                            (vHsm_GetJobObjectsOfPCConfig()[(Index)].StateOfJobObjects)
#define vHsm_GetUsageRestrictionOfJobObjects(Index)                                                 (vHsm_GetJobObjectsOfPCConfig()[(Index)].UsageRestrictionOfJobObjects)
#define vHsm_IsValidRequestFlagOfJobObjects(Index)                                                  ((vHsm_GetJobObjectsOfPCConfig()[(Index)].ValidRequestFlagOfJobObjects) != FALSE)
#define vHsm_GetCryptoFunctionsIdxOfKeyInfo(Index)                                                  (vHsm_GetKeyInfoOfPCConfig()[(Index)].CryptoFunctionsIdxOfKeyInfo)
#define vHsm_GetCryptoKeyIdOfKeyInfo(Index)                                                         (vHsm_GetKeyInfoOfPCConfig()[(Index)].CryptoKeyIdOfKeyInfo)
#define vHsm_GetMaskedBitsOfKeyInfo(Index)                                                          (vHsm_GetKeyInfoOfPCConfig()[(Index)].MaskedBitsOfKeyInfo)
#define vHsm_IsSecureBootGroupOfKeyInfo(Index)                                                        /**< Deactivateable: 'vHsm_KeyInfo.SecureBootGroup' Reason: 'No Secure Boot Group Key configured' */
#define vHsm_IsSecureBootProtectedOfKeyInfo(Index)                                                    /**< Deactivateable: 'vHsm_KeyInfo.SecureBootProtected' Reason: 'No Secure Boot Protected Key configured!' */
#define vHsm_IsSecureBootSegmentOfKeyInfo(Index)                                                      /**< Deactivateable: 'vHsm_KeyInfo.SecureBootSegment' Reason: 'No Secure Boot Segment Key configured' */
#define vHsm_GetCounterSizeOfLogEvent(Index)                                                          /**< Deactivateable: 'vHsm_LogEvent.CounterSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetDataSizeOfLogEvent(Index)                                                             /**< Deactivateable: 'vHsm_LogEvent.DataSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_IsDiscardWhenFullOfLogEvent(Index)                                                       /**< Deactivateable: 'vHsm_LogEvent.DiscardWhenFull' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_IsEventCalloutOfLogEvent(Index)                                                          /**< Deactivateable: 'vHsm_LogEvent.EventCallout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetExportStrategyOfLogEvent(Index)                                                       /**< Deactivateable: 'vHsm_LogEvent.ExportStrategy' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetFillLevelThresholdOfLogEvent(Index)                                                   /**< Deactivateable: 'vHsm_LogEvent.FillLevelThreshold' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetIdOfLogEvent(Index)                                                                   /**< Deactivateable: 'vHsm_LogEvent.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetLogEventMemoryEndIdxOfLogEvent(Index)                                                 /**< Deactivateable: 'vHsm_LogEvent.LogEventMemoryEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetLogEventMemoryStartIdxOfLogEvent(Index)                                               /**< Deactivateable: 'vHsm_LogEvent.LogEventMemoryStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetMaxEntriesOfLogEvent(Index)                                                           /**< Deactivateable: 'vHsm_LogEvent.MaxEntries' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetNvBlockDescriptorOfLogEvent(Index)                                                    /**< Deactivateable: 'vHsm_LogEvent.NvBlockDescriptor' Reason: 'DefinitionRef: /MICROSAR/vHsm/vHsmLog/vHsmLogEvent/vHsmNvBlockDescriptor not configured.' */
#define vHsm_IsNvBlockDescriptorValidOfLogEvent(Index)                                                /**< Deactivateable: 'vHsm_LogEvent.NvBlockDescriptorValid' Reason: 'DefinitionRef: /MICROSAR/vHsm/vHsmLog/vHsmLogEvent/vHsmNvBlockDescriptor not configured.' */
#define vHsm_GetNvProcessingOfLogEvent(Index)                                                         /**< Deactivateable: 'vHsm_LogEvent.NvProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetTimestampSizeOfLogEvent(Index)                                                        /**< Deactivateable: 'vHsm_LogEvent.TimestampSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetLogEventMemory(Index)                                                                 /**< Deactivateable: 'vHsm_LogEventMemory' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetStartOfMemoryArea(Index)                                                            (vHsm_GetMemoryAreaOfPCConfig()[(Index)].StartOfMemoryArea)
#define vHsm_GetStopOfMemoryArea(Index)                                                             (vHsm_GetMemoryAreaOfPCConfig()[(Index)].StopOfMemoryArea)
#define vHsm_GetTypeOfMemoryArea(Index)                                                             (vHsm_GetMemoryAreaOfPCConfig()[(Index)].TypeOfMemoryArea)
#define vHsm_GetIdOfPartition(Index)                                                                  /**< Deactivateable: 'vHsm_Partition.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetLengthOfPartition(Index)                                                              /**< Deactivateable: 'vHsm_Partition.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetStartAddressOfPartition(Index)                                                        /**< Deactivateable: 'vHsm_Partition.StartAddress' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetPartitionRefIndEndIdxOfPartitionGroup(Index)                                          /**< Deactivateable: 'vHsm_PartitionGroup.PartitionRefIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetPartitionRefIndStartIdxOfPartitionGroup(Index)                                        /**< Deactivateable: 'vHsm_PartitionGroup.PartitionRefIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_IsPartitionRefIndUsedOfPartitionGroup(Index)                                             /**< Deactivateable: 'vHsm_PartitionGroup.PartitionRefIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetPartitionRef(Index)                                                                   /**< Deactivateable: 'vHsm_PartitionRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetPartitionRefInd(Index)                                                                /**< Deactivateable: 'vHsm_PartitionRefInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetKeyElementOfRandomInit(Index)                                                       (vHsm_GetRandomInitOfPCConfig()[(Index)].KeyElementOfRandomInit)
#define vHsm_GetKeyOfRandomInit(Index)                                                              (vHsm_GetRandomInitOfPCConfig()[(Index)].KeyOfRandomInit)
#define vHsm_IsRestrictedChannels(Index)                                                            ((vHsm_GetRestrictedChannelsOfPCConfig()[(Index)]) != FALSE)
#define vHsm_GetScheduledChannelsEndIdxOfSchedulableEntities(Index)                                 (vHsm_GetSchedulableEntitiesOfPCConfig()[(Index)].ScheduledChannelsEndIdxOfSchedulableEntities)
#define vHsm_GetScheduledChannelsStartIdxOfSchedulableEntities(Index)                               (vHsm_GetSchedulableEntitiesOfPCConfig()[(Index)].ScheduledChannelsStartIdxOfSchedulableEntities)
#define vHsm_GetScheduledChannels(Index)                                                            (vHsm_GetScheduledChannelsOfPCConfig()[(Index)])
#define vHsm_IsAutostartOfSecureBootGroup(Index)                                                      /**< Deactivateable: 'vHsm_SecureBootGroup.Autostart' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetCryptoKeyIdOfSecureBootGroup(Index)                                                   /**< Deactivateable: 'vHsm_SecureBootGroup.CryptoKeyId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetCustomCalloutCyclicIdxOfSecureBootGroup(Index)                                        /**< Deactivateable: 'vHsm_SecureBootGroup.CustomCalloutCyclicIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_IsCustomCalloutCyclicUsedOfSecureBootGroup(Index)                                        /**< Deactivateable: 'vHsm_SecureBootGroup.CustomCalloutCyclicUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetCustomCalloutIdxOfSecureBootGroup(Index)                                              /**< Deactivateable: 'vHsm_SecureBootGroup.CustomCalloutIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_IsCustomCalloutUsedOfSecureBootGroup(Index)                                              /**< Deactivateable: 'vHsm_SecureBootGroup.CustomCalloutUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_IsCyclicVerificationOfSecureBootGroup(Index)                                             /**< Deactivateable: 'vHsm_SecureBootGroup.CyclicVerification' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetIdOfSecureBootGroup(Index)                                                            /**< Deactivateable: 'vHsm_SecureBootGroup.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetNvBlockDescriptorOfSecureBootGroup(Index)                                             /**< Deactivateable: 'vHsm_SecureBootGroup.NvBlockDescriptor' Reason: 'DefinitionRef: /MICROSAR/vHsm/vHsmSecureBoot/vHsmSecureBootGroup/vHsmNvBlockDescriptor not configured.' */
#define vHsm_IsNvBlockDescriptorValidOfSecureBootGroup(Index)                                         /**< Deactivateable: 'vHsm_SecureBootGroup.NvBlockDescriptorValid' Reason: 'DefinitionRef: /MICROSAR/vHsm/vHsmSecureBoot/vHsmSecureBootGroup/vHsmNvBlockDescriptor not configured.' */
#define vHsm_GetSanctionOfSecureBootGroup(Index)                                                      /**< Deactivateable: 'vHsm_SecureBootGroup.Sanction' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetSecureBootSegmentEndIdxOfSecureBootGroup(Index)                                       /**< Deactivateable: 'vHsm_SecureBootGroup.SecureBootSegmentEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetSecureBootSegmentStartIdxOfSecureBootGroup(Index)                                     /**< Deactivateable: 'vHsm_SecureBootGroup.SecureBootSegmentStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_IsSecureBootSegmentUsedOfSecureBootGroup(Index)                                          /**< Deactivateable: 'vHsm_SecureBootGroup.SecureBootSegmentUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetServiceOfSecureBootGroup(Index)                                                       /**< Deactivateable: 'vHsm_SecureBootGroup.Service' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetSigJobExternalSlOfSecureBootGroup(Index)                                              /**< Deactivateable: 'vHsm_SecureBootGroup.SigJobExternalSl' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetSlLocationOfSecureBootGroup(Index)                                                    /**< Deactivateable: 'vHsm_SecureBootGroup.SlLocation' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetTagHandlingOfSecureBootGroup(Index)                                                   /**< Deactivateable: 'vHsm_SecureBootGroup.TagHandling' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetTagLengthOfSecureBootGroup(Index)                                                     /**< Deactivateable: 'vHsm_SecureBootGroup.TagLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetVerJobCompInternalOfSecureBootGroup(Index)                                            /**< Deactivateable: 'vHsm_SecureBootGroup.VerJobCompInternal' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetVerJobExternalSlOfSecureBootGroup(Index)                                              /**< Deactivateable: 'vHsm_SecureBootGroup.VerJobExternalSl' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetSecureBootProtectedChannels(Index)                                                    /**< Deactivateable: 'vHsm_SecureBootProtectedChannels' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetSecureBootProtectedKeys(Index)                                                        /**< Deactivateable: 'vHsm_SecureBootProtectedKeys' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetCryptoKeyIdOfSecureBootSegment(Index)                                                 /**< Deactivateable: 'vHsm_SecureBootSegment.CryptoKeyId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetGroupIdxOfSecureBootSegment(Index)                                                    /**< Deactivateable: 'vHsm_SecureBootSegment.GroupIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetSecureBootSegmentInitValuesIdxOfSecureBootSegment(Index)                              /**< Deactivateable: 'vHsm_SecureBootSegment.SecureBootSegmentInitValuesIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_IsSecureBootSegmentInitValuesUsedOfSecureBootSegment(Index)                              /**< Deactivateable: 'vHsm_SecureBootSegment.SecureBootSegmentInitValuesUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetAddressOfSecureBootSegmentInitValues(Index)                                           /**< Deactivateable: 'vHsm_SecureBootSegmentInitValues.Address' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetLengthOfSecureBootSegmentInitValues(Index)                                            /**< Deactivateable: 'vHsm_SecureBootSegmentInitValues.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetModeOfSecureBootSegmentInitValues(Index)                                              /**< Deactivateable: 'vHsm_SecureBootSegmentInitValues.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetSanctionOfSecureBootSegmentInitValues(Index)                                          /**< Deactivateable: 'vHsm_SecureBootSegmentInitValues.Sanction' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetCsmJobParallelRefOfSecureBootVerificationJob(Index)                                   /**< Deactivateable: 'vHsm_SecureBootVerificationJob.CsmJobParallelRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetCsmJobSequentialRefOfSecureBootVerificationJob(Index)                                 /**< Deactivateable: 'vHsm_SecureBootVerificationJob.CsmJobSequentialRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetIdOfSecureBootVerificationJob(Index)                                                  /**< Deactivateable: 'vHsm_SecureBootVerificationJob.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_GetParallelChannelRefOfSecureBootVerificationJob(Index)                                  /**< Deactivateable: 'vHsm_SecureBootVerificationJob.ParallelChannelRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCGetBitDataMacros  vHsm Get Bit Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read bitcoded data elements.
  \{
*/ 
#define vHsm_IsIsrProcessingOfJobObjectInfo(Index)                                                  (VHSM_ISRPROCESSINGOFJOBOBJECTINFO_MASK == (vHsm_GetMaskedBitsOfJobObjectInfo(Index) & VHSM_ISRPROCESSINGOFJOBOBJECTINFO_MASK))  /**< If true, channel is directly processed in ISR. */
#define vHsm_IsInternalOnlyOfKeyInfo(Index)                                                         (VHSM_INTERNALONLYOFKEYINFO_MASK == (vHsm_GetMaskedBitsOfKeyInfo(Index) & VHSM_INTERNALONLYOFKEYINFO_MASK))
#define vHsm_IsRoutedOfKeyInfo(Index)                                                               (VHSM_ROUTEDOFKEYINFO_MASK == (vHsm_GetMaskedBitsOfKeyInfo(Index) & VHSM_ROUTEDOFKEYINFO_MASK))
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCGetDeduplicatedDataMacros  vHsm Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define vHsm_IsAllowAddressChangeOfSecureSoftwareDownload()                                           /**< Deactivateable: 'vHsm_AllowAddressChangeOfSecureSoftwareDownload' Reason: 'Parameter is not configured!' */
#define vHsm_GetAtomicBufferSizeOfSecureBoot()                                                        /**< Deactivateable: 'vHsm_AtomicBufferSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_GetChannelsOfIpc()                                                                     vHsm_GetChannelsOfIpcOfPCConfig()
#define vHsm_GetKeyIdOfCoreKey(Index)                                                               ((vHsm_KeyIdOfCoreKeyType)((((vHsm_KeyIdOfCoreKeyType)(Index)) + 30000u)))
#define vHsm_GetCsmHashJobReferenceOfSecureBootUpdate()                                               /**< Deactivateable: 'vHsm_CsmHashJobReferenceOfSecureBootUpdate' Reason: 'Reference is not configured!' */
#define vHsm_GetCsmJobDecryptRefOfFirmwareUpdate()                                                  vHsm_GetCsmJobDecryptRefOfFirmwareUpdateOfPCConfig()
#define vHsm_GetCsmJobEncryptRefOfFirmwareUpdate()                                                  vHsm_GetCsmJobEncryptRefOfFirmwareUpdateOfPCConfig()
#define vHsm_GetCsmJobMacGenerateRefOfFirmwareUpdate()                                              vHsm_GetCsmJobMacGenerateRefOfFirmwareUpdateOfPCConfig()
#define vHsm_GetCsmJobSignatureVerifyRefOfFirmwareUpdate()                                          vHsm_GetCsmJobSignatureVerifyRefOfFirmwareUpdateOfPCConfig()
#define vHsm_GetCsmSignatureJobReferenceOfSecureBootUpdate()                                          /**< Deactivateable: 'vHsm_CsmSignatureJobReferenceOfSecureBootUpdate' Reason: 'Reference is not configured!' */
#define vHsm_GetCsmSignatureJobReferenceOfSecureSoftwareDownload()                                    /**< Deactivateable: 'vHsm_CsmSignatureJobReferenceOfSecureSoftwareDownload' Reason: 'Reference is not configured!' */
#define vHsm_GetCyclicVerificationSplitSizeOfSecureBoot()                                             /**< Deactivateable: 'vHsm_CyclicVerificationSplitSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_GetDriverObjectMappingInd(Index)                                                       ((vHsm_DriverObjectMappingIndType)((Index)))  /**< the indexes of the 1:1 sorted relation pointing to vHsm_DriverObjectMapping */
#define vHsm_IsEnableRamLoopCalloutOfGeneral()                                                      vHsm_IsEnableRamLoopCalloutOfGeneralOfPCConfig()
#define vHsm_IsEnableSecureBootAutostartOfDevelopment()                                               /**< Deactivateable: 'vHsm_EnableSecureBootAutostartOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_GetErrorLogEventLogRefOfGeneral()                                                        /**< Deactivateable: 'vHsm_ErrorLogEventLogRefOfGeneral' Reason: 'Reference is not configured!' */
#define vHsm_GetExpectedCompatibilityVersion()                                                        /**< Deactivateable: 'vHsm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsm_GetFinalMagicNumber()                                                                    /**< Deactivateable: 'vHsm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vHsm_IsForceInterruptTriggeringOfGeneral()                                                  vHsm_IsForceInterruptTriggeringOfGeneralOfPCConfig()
#define vHsm_IsForcedSequentialProcessingOnFirstVerificationOfSecureBoot()                            /**< Deactivateable: 'vHsm_ForcedSequentialProcessingOnFirstVerificationOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_IsGenerateRandomIpcValuesOfGeneral()                                                   vHsm_IsGenerateRandomIpcValuesOfGeneralOfPCConfig()
#define vHsm_IsGenerateRandomStackProtectionCanaryOfGeneral()                                       vHsm_IsGenerateRandomStackProtectionCanaryOfGeneralOfPCConfig()
#define vHsm_GetGeneratorCompatibilityVersion()                                                       /**< Deactivateable: 'vHsm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsm_GetInitDataHashCode()                                                                    /**< Deactivateable: 'vHsm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vHsm_IsInterruptModeOfScheduling()                                                          vHsm_IsInterruptModeOfSchedulingOfPCConfig()
#define vHsm_GetInvalidNvMBlockBehaviourOfGeneral()                                                 vHsm_GetInvalidNvMBlockBehaviourOfGeneralOfPCConfig()
#define vHsm_GetDriverObjectMappingIndEndIdxOfIpcInstance(Index)                                    ((vHsm_DriverObjectMappingIndEndIdxOfIpcInstanceType)((((vHsm_DriverObjectMappingIndEndIdxOfIpcInstanceType)(Index)) + 7u)))  /**< the end index of the 0:n relation pointing to vHsm_DriverObjectMappingInd */
#define vHsm_GetDriverObjectMappingIndStartIdxOfIpcInstance(Index)                                  ((vHsm_DriverObjectMappingIndStartIdxOfIpcInstanceType)((Index)))  /**< the start index of the 0:n relation pointing to vHsm_DriverObjectMappingInd */
#define vHsm_IsDriverObjectMappingIndUsedOfIpcInstance(Index)                                       (((boolean)(vHsm_GetDriverObjectMappingIndStartIdxOfIpcInstance(Index) != VHSM_NO_DRIVEROBJECTMAPPINGINDSTARTIDXOFIPCINSTANCE)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to vHsm_DriverObjectMappingInd */
#define vHsm_GetHardwareUnitOfIpcInstance(Index)                                                    ((vHsm_HardwareUnitOfIpcInstanceType)((Index)))  /**< Contains values of DefinitionRef: /MICROSAR/vHsm/vHsmIpc/vHsmIpcInstance/vHsmIpcHardwareUnit. */
#define vHsm_GetIdOfIpcInstance(Index)                                                              ((vHsm_IdOfIpcInstanceType)((Index)))  /**< Contains values of DefinitionRef: /MICROSAR/vHsm/vHsmIpc/vHsmIpcInstance/vHsmIpcInstanceId. */
#define vHsm_GetResponseInterruptFlagSetAddressOfIpcInstance(Index)                                 ((vHsm_ResponseInterruptFlagSetAddressOfIpcInstanceType)((((vHsm_ResponseInterruptFlagSetAddressOfIpcInstanceType)(Index)) + 0xF0040028u)))  /**< Contains values of DefinitionRef: /MICROSAR/vHsm/vHsmIpc/vHsmIpcInstance/vHsmResponseInterruptFlagSetAddress. */
#define vHsm_GetResponseInterruptFlagSetMaskOfIpcInstance(Index)                                    ((vHsm_ResponseInterruptFlagSetMaskOfIpcInstanceType)((((vHsm_ResponseInterruptFlagSetMaskOfIpcInstanceType)(Index)) + 0x01u)))  /**< Contains values of DefinitionRef: /MICROSAR/vHsm/vHsmIpc/vHsmIpcInstance/vHsmResponseInterruptFlagSetMask. */
#define vHsm_GetIsrForProcessingOfScheduling()                                                      vHsm_GetIsrForProcessingOfSchedulingOfPCConfig()
#define vHsm_IsEventTriggeredOfJobObjectInfo(Index)                                                 vHsm_IsIsrProcessingOfJobObjectInfo(Index)  /**< If true, Task is triggered by event. */
#define vHsm_IsJumpToUpdaterRestrictionOfFirmwareUpdate()                                           vHsm_IsJumpToUpdaterRestrictionOfFirmwareUpdateOfPCConfig()
#define vHsm_GetKeyManagementChannelOfChannelMapping()                                              vHsm_GetKeyManagementChannelOfChannelMappingOfPCConfig()
#define vHsm_GetMainFunctionPeriodOfGeneral()                                                         /**< Deactivateable: 'vHsm_MainFunctionPeriodOfGeneral' Reason: 'Parameter is not configured!' */
#define vHsm_IsOptionByteModificationOfDevelopment()                                                  /**< Deactivateable: 'vHsm_OptionByteModificationOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_IsOsSupportOfScheduling()                                                              vHsm_IsOsSupportOfSchedulingOfPCConfig()
#define vHsm_GetProtocolVersionOfIpc()                                                              vHsm_GetProtocolVersionOfIpcOfPCConfig()
#define vHsm_GetQueueSizeOfSecureBoot()                                                               /**< Deactivateable: 'vHsm_QueueSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_GetRandomCsmJobRefOfGeneral()                                                          vHsm_GetRandomCsmJobRefOfGeneralOfPCConfig()
#define vHsm_IsRedirectionOfGeneral()                                                               vHsm_IsRedirectionOfGeneralOfPCConfig()
#define vHsm_IsSegmentSuccessCalloutOfSecureBoot()                                                    /**< Deactivateable: 'vHsm_SegmentSuccessCalloutOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_GetSizeOfChannelInfo()                                                                 vHsm_GetSizeOfChannelInfoOfPCConfig()
#define vHsm_GetSizeOfCoreKey()                                                                     vHsm_GetSizeOfCoreKeyOfPCConfig()
#define vHsm_GetSizeOfCryptoFunctions()                                                             vHsm_GetSizeOfCryptoFunctionsOfPCConfig()
#define vHsm_GetSizeOfDriverObjectMapping()                                                         vHsm_GetSizeOfDriverObjectMappingOfPCConfig()
#define vHsm_GetSizeOfDriverObjectMappingInd()                                                      vHsm_GetSizeOfDriverObjectMappingIndOfPCConfig()
#define vHsm_GetSizeOfIpcInstance()                                                                 vHsm_GetSizeOfIpcInstanceOfPCConfig()
#define vHsm_GetSizeOfJobObjectInfo()                                                               vHsm_GetSizeOfJobObjectInfoOfPCConfig()
#define vHsm_GetSizeOfJobObjects()                                                                  vHsm_GetSizeOfJobObjectsOfPCConfig()
#define vHsm_GetSizeOfKeyInfo()                                                                     vHsm_GetSizeOfKeyInfoOfPCConfig()
#define vHsm_GetSizeOfMemoryArea()                                                                  vHsm_GetSizeOfMemoryAreaOfPCConfig()
#define vHsm_GetSizeOfRandomInit()                                                                  vHsm_GetSizeOfRandomInitOfPCConfig()
#define vHsm_GetSizeOfRestrictedChannels()                                                          vHsm_GetSizeOfRestrictedChannelsOfPCConfig()
#define vHsm_GetSizeOfSchedulableEntities()                                                         vHsm_GetSizeOfSchedulableEntitiesOfPCConfig()
#define vHsm_GetSizeOfScheduledChannels()                                                           vHsm_GetSizeOfScheduledChannelsOfPCConfig()
#define vHsm_GetSoftResetLimitOfGeneral()                                                           vHsm_GetSoftResetLimitOfGeneralOfPCConfig()
#define vHsm_GetSplitSizeOfSecureBoot()                                                               /**< Deactivateable: 'vHsm_SplitSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_GetStorageMethodOfSecureBoot()                                                           /**< Deactivateable: 'vHsm_StorageMethodOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_IsSupportSaveRestoreContextOfGeneral()                                                 vHsm_IsSupportSaveRestoreContextOfGeneralOfPCConfig()
#define vHsm_IsTraceDebugOfDevelopment()                                                              /**< Deactivateable: 'vHsm_TraceDebugOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_IsTraceErrorOfDevelopment()                                                              /**< Deactivateable: 'vHsm_TraceErrorOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_IsTraceInfoOfDevelopment()                                                               /**< Deactivateable: 'vHsm_TraceInfoOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_IsTraceKeyStorageOfDevelopment()                                                         /**< Deactivateable: 'vHsm_TraceKeyStorageOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_IsTraceWarningOfDevelopment()                                                            /**< Deactivateable: 'vHsm_TraceWarningOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_GetUpdaterAddressOfFirmwareUpdate()                                                    vHsm_GetUpdaterAddressOfFirmwareUpdateOfPCConfig()
#define vHsm_IsUpgradeProtectionModificationOfDevelopment()                                           /**< Deactivateable: 'vHsm_UpgradeProtectionModificationOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_GetUserRevisionOfGeneral()                                                               /**< Deactivateable: 'vHsm_UserRevisionOfGeneral' Reason: 'Parameter is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCSetDataMacros  vHsm Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define vHsm_SetCancelFlagOfJobObjects(Index, Value)                                                vHsm_GetJobObjectsOfPCConfig()[(Index)].CancelFlagOfJobObjects = (Value)
#define vHsm_SetIpcChannelOfJobObjects(Index, Value)                                                vHsm_GetJobObjectsOfPCConfig()[(Index)].IpcChannelOfJobObjects = (Value)
#define vHsm_SetIpcInstanceOfJobObjects(Index, Value)                                               vHsm_GetJobObjectsOfPCConfig()[(Index)].IpcInstanceOfJobObjects = (Value)
#define vHsm_SetIpcMappingOfJobObjects(Index, Value)                                                vHsm_GetJobObjectsOfPCConfig()[(Index)].IpcMappingOfJobObjects = (Value)
#define vHsm_SetJobDataOfJobObjects(Index, Value)                                                   vHsm_GetJobObjectsOfPCConfig()[(Index)].JobDataOfJobObjects = (Value)
#define vHsm_SetJobRequestIdOfJobObjects(Index, Value)                                              vHsm_GetJobObjectsOfPCConfig()[(Index)].JobRequestIdOfJobObjects = (Value)
#define vHsm_SetJobRequestKindOfJobObjects(Index, Value)                                            vHsm_GetJobObjectsOfPCConfig()[(Index)].JobRequestKindOfJobObjects = (Value)
#define vHsm_SetJobRetValOfJobObjects(Index, Value)                                                 vHsm_GetJobObjectsOfPCConfig()[(Index)].JobRetValOfJobObjects = (Value)
#define vHsm_SetLocalOutputOfJobObjects(Index, Value)                                               vHsm_GetJobObjectsOfPCConfig()[(Index)].LocalOutputOfJobObjects = (Value)
#define vHsm_SetProcessKindOfJobObjects(Index, Value)                                               vHsm_GetJobObjectsOfPCConfig()[(Index)].ProcessKindOfJobObjects = (Value)
#define vHsm_SetProcessingTypeOfJobObjects(Index, Value)                                            vHsm_GetJobObjectsOfPCConfig()[(Index)].ProcessingTypeOfJobObjects = (Value)
#define vHsm_SetRedirectionFlagsOfJobObjects(Index, Value)                                          vHsm_GetJobObjectsOfPCConfig()[(Index)].RedirectionFlagsOfJobObjects = (Value)
#define vHsm_SetStateOfJobObjects(Index, Value)                                                     vHsm_GetJobObjectsOfPCConfig()[(Index)].StateOfJobObjects = (Value)
#define vHsm_SetUsageRestrictionOfJobObjects(Index, Value)                                          vHsm_GetJobObjectsOfPCConfig()[(Index)].UsageRestrictionOfJobObjects = (Value)
#define vHsm_SetValidRequestFlagOfJobObjects(Index, Value)                                          vHsm_GetJobObjectsOfPCConfig()[(Index)].ValidRequestFlagOfJobObjects = (Value)
#define vHsm_SetLogEventMemory(Index, Value)                                                          /**< Deactivateable: 'vHsm_LogEventMemory' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_SetRestrictedChannels(Index, Value)                                                    vHsm_GetRestrictedChannelsOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCGetAddressOfDataMacros  vHsm Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define vHsm_GetAddrLogEventMemory(Index)                                                             /**< Deactivateable: 'vHsm_LogEventMemory' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCHasMacros  vHsm Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vHsm_HasAllowAddressChangeOfSecureSoftwareDownload()                                          /**< Deactivateable: 'vHsm_AllowAddressChangeOfSecureSoftwareDownload' Reason: 'Parameter is not configured!' */
#define vHsm_HasAtomicBufferSizeOfSecureBoot()                                                        /**< Deactivateable: 'vHsm_AtomicBufferSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_HasChannelInfo()                                                                       (TRUE != FALSE)
#define vHsm_HasCryptoFunctionsIdxOfChannelInfo()                                                   (TRUE != FALSE)
#define vHsm_HasDriverObjectRefOfChannelInfo()                                                      (TRUE != FALSE)
#define vHsm_HasChannelsOfIpc()                                                                     (TRUE != FALSE)
#define vHsm_HasCoreKey()                                                                           (TRUE != FALSE)
#define vHsm_HasAggregatedCryptoKeyIdOfCoreKey()                                                    (TRUE != FALSE)
#define vHsm_HasKeyIdOfCoreKey()                                                                    (TRUE != FALSE)
#define vHsm_HasCryptoFunctions()                                                                   (TRUE != FALSE)
#define vHsm_HasCancelJobOfCryptoFunctions()                                                        (TRUE != FALSE)
#define vHsm_HasCertificateParseOfCryptoFunctions()                                                 (TRUE != FALSE)
#define vHsm_HasCertificateVerifyOfCryptoFunctions()                                                (TRUE != FALSE)
#define vHsm_HasKeyCopyOfCryptoFunctions()                                                          (TRUE != FALSE)
#define vHsm_HasKeyDeriveOfCryptoFunctions()                                                        (TRUE != FALSE)
#define vHsm_HasKeyElementCopyOfCryptoFunctions()                                                   (TRUE != FALSE)
#define vHsm_HasKeyElementCopyPartialOfCryptoFunctions()                                            (TRUE != FALSE)
#define vHsm_HasKeyElementGetOfCryptoFunctions()                                                    (TRUE != FALSE)
#define vHsm_HasKeyElementIdsGetOfCryptoFunctions()                                                 (TRUE != FALSE)
#define vHsm_HasKeyElementSetOfCryptoFunctions()                                                    (TRUE != FALSE)
#define vHsm_HasKeyExchangeCalcPubValOfCryptoFunctions()                                            (TRUE != FALSE)
#define vHsm_HasKeyExchangeCalcSecretOfCryptoFunctions()                                            (TRUE != FALSE)
#define vHsm_HasKeyGenerateOfCryptoFunctions()                                                      (TRUE != FALSE)
#define vHsm_HasKeyValidSetOfCryptoFunctions()                                                      (TRUE != FALSE)
#define vHsm_HasProcessJobOfCryptoFunctions()                                                       (TRUE != FALSE)
#define vHsm_HasRandomSeedOfCryptoFunctions()                                                       (TRUE != FALSE)
#define vHsm_HasCsmHashJobReferenceOfSecureBootUpdate()                                               /**< Deactivateable: 'vHsm_CsmHashJobReferenceOfSecureBootUpdate' Reason: 'Reference is not configured!' */
#define vHsm_HasCsmJobDecryptRefOfFirmwareUpdate()                                                  (TRUE != FALSE)
#define vHsm_HasCsmJobEncryptRefOfFirmwareUpdate()                                                  (TRUE != FALSE)
#define vHsm_HasCsmJobMacGenerateRefOfFirmwareUpdate()                                              (TRUE != FALSE)
#define vHsm_HasCsmJobSignatureVerifyRefOfFirmwareUpdate()                                          (TRUE != FALSE)
#define vHsm_HasCsmSignatureJobReferenceOfSecureBootUpdate()                                          /**< Deactivateable: 'vHsm_CsmSignatureJobReferenceOfSecureBootUpdate' Reason: 'Reference is not configured!' */
#define vHsm_HasCsmSignatureJobReferenceOfSecureSoftwareDownload()                                    /**< Deactivateable: 'vHsm_CsmSignatureJobReferenceOfSecureSoftwareDownload' Reason: 'Reference is not configured!' */
#define vHsm_HasCustomCallout()                                                                       /**< Deactivateable: 'vHsm_CustomCallout' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define vHsm_HasDummyOfCustomCallout()                                                                /**< Deactivateable: 'vHsm_CustomCallout.Dummy' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasCustomCalloutCyclic()                                                                 /**< Deactivateable: 'vHsm_CustomCalloutCyclic' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define vHsm_HasDummyOfCustomCalloutCyclic()                                                          /**< Deactivateable: 'vHsm_CustomCalloutCyclic.Dummy' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasCyclicVerificationSplitSizeOfSecureBoot()                                             /**< Deactivateable: 'vHsm_CyclicVerificationSplitSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_HasDriverObjectMapping()                                                               (TRUE != FALSE)
#define vHsm_HasDriverObjectMappingInd()                                                            (TRUE != FALSE)
#define vHsm_HasEnableRamLoopCalloutOfGeneral()                                                     (TRUE != FALSE)
#define vHsm_HasEnableSecureBootAutostartOfDevelopment()                                              /**< Deactivateable: 'vHsm_EnableSecureBootAutostartOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_HasErrorLogEventLogRefOfGeneral()                                                        /**< Deactivateable: 'vHsm_ErrorLogEventLogRefOfGeneral' Reason: 'Reference is not configured!' */
#define vHsm_HasExpectedCompatibilityVersion()                                                        /**< Deactivateable: 'vHsm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsm_HasFinalMagicNumber()                                                                    /**< Deactivateable: 'vHsm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vHsm_HasForceInterruptTriggeringOfGeneral()                                                 (TRUE != FALSE)
#define vHsm_HasForcedSequentialProcessingOnFirstVerificationOfSecureBoot()                           /**< Deactivateable: 'vHsm_ForcedSequentialProcessingOnFirstVerificationOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_HasGenerateRandomIpcValuesOfGeneral()                                                  (TRUE != FALSE)
#define vHsm_HasGenerateRandomStackProtectionCanaryOfGeneral()                                      (TRUE != FALSE)
#define vHsm_HasGeneratorCompatibilityVersion()                                                       /**< Deactivateable: 'vHsm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsm_HasInitDataHashCode()                                                                    /**< Deactivateable: 'vHsm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vHsm_HasInterruptModeOfScheduling()                                                         (TRUE != FALSE)
#define vHsm_HasInvalidNvMBlockBehaviourOfGeneral()                                                 (TRUE != FALSE)
#define vHsm_HasIpcInstance()                                                                       (TRUE != FALSE)
#define vHsm_HasDriverObjectMappingIndEndIdxOfIpcInstance()                                         (TRUE != FALSE)
#define vHsm_HasDriverObjectMappingIndStartIdxOfIpcInstance()                                       (TRUE != FALSE)
#define vHsm_HasDriverObjectMappingIndUsedOfIpcInstance()                                           (TRUE != FALSE)
#define vHsm_HasHardwareUnitOfIpcInstance()                                                         (TRUE != FALSE)
#define vHsm_HasIdOfIpcInstance()                                                                   (TRUE != FALSE)
#define vHsm_HasMemoryOfIpcInstance()                                                               (TRUE != FALSE)
#define vHsm_HasResponseInterruptFlagSetAddressOfIpcInstance()                                      (TRUE != FALSE)
#define vHsm_HasResponseInterruptFlagSetMaskOfIpcInstance()                                         (TRUE != FALSE)
#define vHsm_HasIsrForProcessingOfScheduling()                                                      (TRUE != FALSE)
#define vHsm_HasJobObjectInfo()                                                                     (TRUE != FALSE)
#define vHsm_HasEventTriggeredOfJobObjectInfo()                                                     (TRUE != FALSE)
#define vHsm_HasIsrProcessingOfJobObjectInfo()                                                      (TRUE != FALSE)
#define vHsm_HasMaskedBitsOfJobObjectInfo()                                                         (TRUE != FALSE)
#define vHsm_HasSchedEventRefOfJobObjectInfo()                                                      (TRUE != FALSE)
#define vHsm_HasSchedTaskRefOfJobObjectInfo()                                                       (TRUE != FALSE)
#define vHsm_HasJobObjects()                                                                        (TRUE != FALSE)
#define vHsm_HasCancelFlagOfJobObjects()                                                            (TRUE != FALSE)
#define vHsm_HasIpcChannelOfJobObjects()                                                            (TRUE != FALSE)
#define vHsm_HasIpcInstanceOfJobObjects()                                                           (TRUE != FALSE)
#define vHsm_HasIpcMappingOfJobObjects()                                                            (TRUE != FALSE)
#define vHsm_HasJobDataOfJobObjects()                                                               (TRUE != FALSE)
#define vHsm_HasJobRequestIdOfJobObjects()                                                          (TRUE != FALSE)
#define vHsm_HasJobRequestKindOfJobObjects()                                                        (TRUE != FALSE)
#define vHsm_HasJobRetValOfJobObjects()                                                             (TRUE != FALSE)
#define vHsm_HasLocalOutputOfJobObjects()                                                           (TRUE != FALSE)
#define vHsm_HasProcessKindOfJobObjects()                                                           (TRUE != FALSE)
#define vHsm_HasProcessingTypeOfJobObjects()                                                        (TRUE != FALSE)
#define vHsm_HasRedirectionFlagsOfJobObjects()                                                      (TRUE != FALSE)
#define vHsm_HasStateOfJobObjects()                                                                 (TRUE != FALSE)
#define vHsm_HasUsageRestrictionOfJobObjects()                                                      (TRUE != FALSE)
#define vHsm_HasValidRequestFlagOfJobObjects()                                                      (TRUE != FALSE)
#define vHsm_HasJumpToUpdaterRestrictionOfFirmwareUpdate()                                          (TRUE != FALSE)
#define vHsm_HasKeyInfo()                                                                           (TRUE != FALSE)
#define vHsm_HasCryptoFunctionsIdxOfKeyInfo()                                                       (TRUE != FALSE)
#define vHsm_HasCryptoKeyIdOfKeyInfo()                                                              (TRUE != FALSE)
#define vHsm_HasInternalOnlyOfKeyInfo()                                                             (TRUE != FALSE)
#define vHsm_HasMaskedBitsOfKeyInfo()                                                               (TRUE != FALSE)
#define vHsm_HasRoutedOfKeyInfo()                                                                   (TRUE != FALSE)
#define vHsm_HasSecureBootGroupOfKeyInfo()                                                            /**< Deactivateable: 'vHsm_KeyInfo.SecureBootGroup' Reason: 'No Secure Boot Group Key configured' */
#define vHsm_HasSecureBootProtectedOfKeyInfo()                                                        /**< Deactivateable: 'vHsm_KeyInfo.SecureBootProtected' Reason: 'No Secure Boot Protected Key configured!' */
#define vHsm_HasSecureBootSegmentOfKeyInfo()                                                          /**< Deactivateable: 'vHsm_KeyInfo.SecureBootSegment' Reason: 'No Secure Boot Segment Key configured' */
#define vHsm_HasKeyManagementChannelOfChannelMapping()                                              (TRUE != FALSE)
#define vHsm_HasLogEvent()                                                                            /**< Deactivateable: 'vHsm_LogEvent' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define vHsm_HasCounterSizeOfLogEvent()                                                               /**< Deactivateable: 'vHsm_LogEvent.CounterSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasDataSizeOfLogEvent()                                                                  /**< Deactivateable: 'vHsm_LogEvent.DataSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasDiscardWhenFullOfLogEvent()                                                           /**< Deactivateable: 'vHsm_LogEvent.DiscardWhenFull' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasEventCalloutOfLogEvent()                                                              /**< Deactivateable: 'vHsm_LogEvent.EventCallout' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasExportStrategyOfLogEvent()                                                            /**< Deactivateable: 'vHsm_LogEvent.ExportStrategy' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasFillLevelThresholdOfLogEvent()                                                        /**< Deactivateable: 'vHsm_LogEvent.FillLevelThreshold' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasIdOfLogEvent()                                                                        /**< Deactivateable: 'vHsm_LogEvent.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasLogEventMemoryEndIdxOfLogEvent()                                                      /**< Deactivateable: 'vHsm_LogEvent.LogEventMemoryEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasLogEventMemoryStartIdxOfLogEvent()                                                    /**< Deactivateable: 'vHsm_LogEvent.LogEventMemoryStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasMaxEntriesOfLogEvent()                                                                /**< Deactivateable: 'vHsm_LogEvent.MaxEntries' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasNvBlockDescriptorOfLogEvent()                                                         /**< Deactivateable: 'vHsm_LogEvent.NvBlockDescriptor' Reason: 'DefinitionRef: /MICROSAR/vHsm/vHsmLog/vHsmLogEvent/vHsmNvBlockDescriptor not configured.' */
#define vHsm_HasNvBlockDescriptorValidOfLogEvent()                                                    /**< Deactivateable: 'vHsm_LogEvent.NvBlockDescriptorValid' Reason: 'DefinitionRef: /MICROSAR/vHsm/vHsmLog/vHsmLogEvent/vHsmNvBlockDescriptor not configured.' */
#define vHsm_HasNvProcessingOfLogEvent()                                                              /**< Deactivateable: 'vHsm_LogEvent.NvProcessing' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasTimestampSizeOfLogEvent()                                                             /**< Deactivateable: 'vHsm_LogEvent.TimestampSize' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasLogEventMemory()                                                                      /**< Deactivateable: 'vHsm_LogEventMemory' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasMainFunctionPeriodOfGeneral()                                                         /**< Deactivateable: 'vHsm_MainFunctionPeriodOfGeneral' Reason: 'Parameter is not configured!' */
#define vHsm_HasMemoryArea()                                                                        (TRUE != FALSE)
#define vHsm_HasStartOfMemoryArea()                                                                 (TRUE != FALSE)
#define vHsm_HasStopOfMemoryArea()                                                                  (TRUE != FALSE)
#define vHsm_HasTypeOfMemoryArea()                                                                  (TRUE != FALSE)
#define vHsm_HasOptionByteModificationOfDevelopment()                                                 /**< Deactivateable: 'vHsm_OptionByteModificationOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_HasOsSupportOfScheduling()                                                             (TRUE != FALSE)
#define vHsm_HasPartition()                                                                           /**< Deactivateable: 'vHsm_Partition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define vHsm_HasIdOfPartition()                                                                       /**< Deactivateable: 'vHsm_Partition.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasLengthOfPartition()                                                                   /**< Deactivateable: 'vHsm_Partition.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasStartAddressOfPartition()                                                             /**< Deactivateable: 'vHsm_Partition.StartAddress' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasPartitionGroup()                                                                      /**< Deactivateable: 'vHsm_PartitionGroup' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define vHsm_HasPartitionRefIndEndIdxOfPartitionGroup()                                               /**< Deactivateable: 'vHsm_PartitionGroup.PartitionRefIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasPartitionRefIndStartIdxOfPartitionGroup()                                             /**< Deactivateable: 'vHsm_PartitionGroup.PartitionRefIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasPartitionRefIndUsedOfPartitionGroup()                                                 /**< Deactivateable: 'vHsm_PartitionGroup.PartitionRefIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasPartitionRef()                                                                        /**< Deactivateable: 'vHsm_PartitionRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasPartitionRefInd()                                                                     /**< Deactivateable: 'vHsm_PartitionRefInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasProtocolVersionOfIpc()                                                              (TRUE != FALSE)
#define vHsm_HasQueueSizeOfSecureBoot()                                                               /**< Deactivateable: 'vHsm_QueueSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_HasRandomCsmJobRefOfGeneral()                                                          (TRUE != FALSE)
#define vHsm_HasRandomInit()                                                                        (TRUE != FALSE)
#define vHsm_HasKeyElementOfRandomInit()                                                            (TRUE != FALSE)
#define vHsm_HasKeyOfRandomInit()                                                                   (TRUE != FALSE)
#define vHsm_HasRedirectionOfGeneral()                                                              (TRUE != FALSE)
#define vHsm_HasRestrictedChannels()                                                                (TRUE != FALSE)
#define vHsm_HasSchedulableEntities()                                                               (TRUE != FALSE)
#define vHsm_HasScheduledChannelsEndIdxOfSchedulableEntities()                                      (TRUE != FALSE)
#define vHsm_HasScheduledChannelsStartIdxOfSchedulableEntities()                                    (TRUE != FALSE)
#define vHsm_HasScheduledChannels()                                                                 (TRUE != FALSE)
#define vHsm_HasSecureBootGroup()                                                                     /**< Deactivateable: 'vHsm_SecureBootGroup' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define vHsm_HasAutostartOfSecureBootGroup()                                                          /**< Deactivateable: 'vHsm_SecureBootGroup.Autostart' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasCryptoKeyIdOfSecureBootGroup()                                                        /**< Deactivateable: 'vHsm_SecureBootGroup.CryptoKeyId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasCustomCalloutCyclicIdxOfSecureBootGroup()                                             /**< Deactivateable: 'vHsm_SecureBootGroup.CustomCalloutCyclicIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasCustomCalloutCyclicUsedOfSecureBootGroup()                                            /**< Deactivateable: 'vHsm_SecureBootGroup.CustomCalloutCyclicUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasCustomCalloutIdxOfSecureBootGroup()                                                   /**< Deactivateable: 'vHsm_SecureBootGroup.CustomCalloutIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasCustomCalloutUsedOfSecureBootGroup()                                                  /**< Deactivateable: 'vHsm_SecureBootGroup.CustomCalloutUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasCyclicVerificationOfSecureBootGroup()                                                 /**< Deactivateable: 'vHsm_SecureBootGroup.CyclicVerification' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasIdOfSecureBootGroup()                                                                 /**< Deactivateable: 'vHsm_SecureBootGroup.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasNvBlockDescriptorOfSecureBootGroup()                                                  /**< Deactivateable: 'vHsm_SecureBootGroup.NvBlockDescriptor' Reason: 'DefinitionRef: /MICROSAR/vHsm/vHsmSecureBoot/vHsmSecureBootGroup/vHsmNvBlockDescriptor not configured.' */
#define vHsm_HasNvBlockDescriptorValidOfSecureBootGroup()                                             /**< Deactivateable: 'vHsm_SecureBootGroup.NvBlockDescriptorValid' Reason: 'DefinitionRef: /MICROSAR/vHsm/vHsmSecureBoot/vHsmSecureBootGroup/vHsmNvBlockDescriptor not configured.' */
#define vHsm_HasSanctionOfSecureBootGroup()                                                           /**< Deactivateable: 'vHsm_SecureBootGroup.Sanction' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasSecureBootSegmentEndIdxOfSecureBootGroup()                                            /**< Deactivateable: 'vHsm_SecureBootGroup.SecureBootSegmentEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasSecureBootSegmentStartIdxOfSecureBootGroup()                                          /**< Deactivateable: 'vHsm_SecureBootGroup.SecureBootSegmentStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasSecureBootSegmentUsedOfSecureBootGroup()                                              /**< Deactivateable: 'vHsm_SecureBootGroup.SecureBootSegmentUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasServiceOfSecureBootGroup()                                                            /**< Deactivateable: 'vHsm_SecureBootGroup.Service' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasSigJobExternalSlOfSecureBootGroup()                                                   /**< Deactivateable: 'vHsm_SecureBootGroup.SigJobExternalSl' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasSlLocationOfSecureBootGroup()                                                         /**< Deactivateable: 'vHsm_SecureBootGroup.SlLocation' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasTagHandlingOfSecureBootGroup()                                                        /**< Deactivateable: 'vHsm_SecureBootGroup.TagHandling' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasTagLengthOfSecureBootGroup()                                                          /**< Deactivateable: 'vHsm_SecureBootGroup.TagLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasVerJobCompInternalOfSecureBootGroup()                                                 /**< Deactivateable: 'vHsm_SecureBootGroup.VerJobCompInternal' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasVerJobExternalSlOfSecureBootGroup()                                                   /**< Deactivateable: 'vHsm_SecureBootGroup.VerJobExternalSl' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasSecureBootProtectedChannels()                                                         /**< Deactivateable: 'vHsm_SecureBootProtectedChannels' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasSecureBootProtectedKeys()                                                             /**< Deactivateable: 'vHsm_SecureBootProtectedKeys' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasSecureBootSegment()                                                                   /**< Deactivateable: 'vHsm_SecureBootSegment' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define vHsm_HasCryptoKeyIdOfSecureBootSegment()                                                      /**< Deactivateable: 'vHsm_SecureBootSegment.CryptoKeyId' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasGroupIdxOfSecureBootSegment()                                                         /**< Deactivateable: 'vHsm_SecureBootSegment.GroupIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasSecureBootSegmentInitValuesIdxOfSecureBootSegment()                                   /**< Deactivateable: 'vHsm_SecureBootSegment.SecureBootSegmentInitValuesIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasSecureBootSegmentInitValuesUsedOfSecureBootSegment()                                  /**< Deactivateable: 'vHsm_SecureBootSegment.SecureBootSegmentInitValuesUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasSecureBootSegmentInitValues()                                                         /**< Deactivateable: 'vHsm_SecureBootSegmentInitValues' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define vHsm_HasAddressOfSecureBootSegmentInitValues()                                                /**< Deactivateable: 'vHsm_SecureBootSegmentInitValues.Address' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasLengthOfSecureBootSegmentInitValues()                                                 /**< Deactivateable: 'vHsm_SecureBootSegmentInitValues.Length' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasModeOfSecureBootSegmentInitValues()                                                   /**< Deactivateable: 'vHsm_SecureBootSegmentInitValues.Mode' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasSanctionOfSecureBootSegmentInitValues()                                               /**< Deactivateable: 'vHsm_SecureBootSegmentInitValues.Sanction' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasSecureBootVerificationJob()                                                           /**< Deactivateable: 'vHsm_SecureBootVerificationJob' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define vHsm_HasCsmJobParallelRefOfSecureBootVerificationJob()                                        /**< Deactivateable: 'vHsm_SecureBootVerificationJob.CsmJobParallelRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasCsmJobSequentialRefOfSecureBootVerificationJob()                                      /**< Deactivateable: 'vHsm_SecureBootVerificationJob.CsmJobSequentialRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasIdOfSecureBootVerificationJob()                                                       /**< Deactivateable: 'vHsm_SecureBootVerificationJob.Id' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasParallelChannelRefOfSecureBootVerificationJob()                                       /**< Deactivateable: 'vHsm_SecureBootVerificationJob.ParallelChannelRef' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define vHsm_HasSegmentSuccessCalloutOfSecureBoot()                                                   /**< Deactivateable: 'vHsm_SegmentSuccessCalloutOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_HasSizeOfChannelInfo()                                                                 (TRUE != FALSE)
#define vHsm_HasSizeOfCoreKey()                                                                     (TRUE != FALSE)
#define vHsm_HasSizeOfCryptoFunctions()                                                             (TRUE != FALSE)
#define vHsm_HasSizeOfDriverObjectMapping()                                                         (TRUE != FALSE)
#define vHsm_HasSizeOfDriverObjectMappingInd()                                                      (TRUE != FALSE)
#define vHsm_HasSizeOfIpcInstance()                                                                 (TRUE != FALSE)
#define vHsm_HasSizeOfJobObjectInfo()                                                               (TRUE != FALSE)
#define vHsm_HasSizeOfJobObjects()                                                                  (TRUE != FALSE)
#define vHsm_HasSizeOfKeyInfo()                                                                     (TRUE != FALSE)
#define vHsm_HasSizeOfMemoryArea()                                                                  (TRUE != FALSE)
#define vHsm_HasSizeOfRandomInit()                                                                  (TRUE != FALSE)
#define vHsm_HasSizeOfRestrictedChannels()                                                          (TRUE != FALSE)
#define vHsm_HasSizeOfSchedulableEntities()                                                         (TRUE != FALSE)
#define vHsm_HasSizeOfScheduledChannels()                                                           (TRUE != FALSE)
#define vHsm_HasSoftResetLimitOfGeneral()                                                           (TRUE != FALSE)
#define vHsm_HasSplitSizeOfSecureBoot()                                                               /**< Deactivateable: 'vHsm_SplitSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_HasStorageMethodOfSecureBoot()                                                           /**< Deactivateable: 'vHsm_StorageMethodOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_HasSupportSaveRestoreContextOfGeneral()                                                (TRUE != FALSE)
#define vHsm_HasTraceDebugOfDevelopment()                                                             /**< Deactivateable: 'vHsm_TraceDebugOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_HasTraceErrorOfDevelopment()                                                             /**< Deactivateable: 'vHsm_TraceErrorOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_HasTraceInfoOfDevelopment()                                                              /**< Deactivateable: 'vHsm_TraceInfoOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_HasTraceKeyStorageOfDevelopment()                                                        /**< Deactivateable: 'vHsm_TraceKeyStorageOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_HasTraceWarningOfDevelopment()                                                           /**< Deactivateable: 'vHsm_TraceWarningOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_HasUpdaterAddressOfFirmwareUpdate()                                                    (TRUE != FALSE)
#define vHsm_HasUpgradeProtectionModificationOfDevelopment()                                          /**< Deactivateable: 'vHsm_UpgradeProtectionModificationOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_HasUserRevisionOfGeneral()                                                               /**< Deactivateable: 'vHsm_UserRevisionOfGeneral' Reason: 'Parameter is not configured!' */
#define vHsm_HasPCConfig()                                                                          (TRUE != FALSE)
#define vHsm_HasAllowAddressChangeOfSecureSoftwareDownloadOfPCConfig()                                /**< Deactivateable: 'vHsm_PCConfig.AllowAddressChangeOfSecureSoftwareDownload' Reason: 'Parameter is not configured!' */
#define vHsm_HasAtomicBufferSizeOfSecureBootOfPCConfig()                                              /**< Deactivateable: 'vHsm_PCConfig.AtomicBufferSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_HasChannelInfoOfPCConfig()                                                             (TRUE != FALSE)
#define vHsm_HasChannelsOfIpcOfPCConfig()                                                           (TRUE != FALSE)
#define vHsm_HasCoreKeyOfPCConfig()                                                                 (TRUE != FALSE)
#define vHsm_HasCryptoFunctionsOfPCConfig()                                                         (TRUE != FALSE)
#define vHsm_HasCsmHashJobReferenceOfSecureBootUpdateOfPCConfig()                                     /**< Deactivateable: 'vHsm_PCConfig.CsmHashJobReferenceOfSecureBootUpdate' Reason: 'Reference is not configured!' */
#define vHsm_HasCsmJobDecryptRefOfFirmwareUpdateOfPCConfig()                                        (TRUE != FALSE)
#define vHsm_HasCsmJobEncryptRefOfFirmwareUpdateOfPCConfig()                                        (TRUE != FALSE)
#define vHsm_HasCsmJobMacGenerateRefOfFirmwareUpdateOfPCConfig()                                    (TRUE != FALSE)
#define vHsm_HasCsmJobSignatureVerifyRefOfFirmwareUpdateOfPCConfig()                                (TRUE != FALSE)
#define vHsm_HasCsmSignatureJobReferenceOfSecureBootUpdateOfPCConfig()                                /**< Deactivateable: 'vHsm_PCConfig.CsmSignatureJobReferenceOfSecureBootUpdate' Reason: 'Reference is not configured!' */
#define vHsm_HasCsmSignatureJobReferenceOfSecureSoftwareDownloadOfPCConfig()                          /**< Deactivateable: 'vHsm_PCConfig.CsmSignatureJobReferenceOfSecureSoftwareDownload' Reason: 'Reference is not configured!' */
#define vHsm_HasCyclicVerificationSplitSizeOfSecureBootOfPCConfig()                                   /**< Deactivateable: 'vHsm_PCConfig.CyclicVerificationSplitSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_HasDriverObjectMappingIndOfPCConfig()                                                  (TRUE != FALSE)
#define vHsm_HasDriverObjectMappingOfPCConfig()                                                     (TRUE != FALSE)
#define vHsm_HasEnableRamLoopCalloutOfGeneralOfPCConfig()                                           (TRUE != FALSE)
#define vHsm_HasEnableSecureBootAutostartOfDevelopmentOfPCConfig()                                    /**< Deactivateable: 'vHsm_PCConfig.EnableSecureBootAutostartOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_HasErrorLogEventLogRefOfGeneralOfPCConfig()                                              /**< Deactivateable: 'vHsm_PCConfig.ErrorLogEventLogRefOfGeneral' Reason: 'Reference is not configured!' */
#define vHsm_HasExpectedCompatibilityVersionOfPCConfig()                                              /**< Deactivateable: 'vHsm_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsm_HasFinalMagicNumberOfPCConfig()                                                          /**< Deactivateable: 'vHsm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define vHsm_HasForceInterruptTriggeringOfGeneralOfPCConfig()                                       (TRUE != FALSE)
#define vHsm_HasForcedSequentialProcessingOnFirstVerificationOfSecureBootOfPCConfig()                 /**< Deactivateable: 'vHsm_PCConfig.ForcedSequentialProcessingOnFirstVerificationOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_HasGenerateRandomIpcValuesOfGeneralOfPCConfig()                                        (TRUE != FALSE)
#define vHsm_HasGenerateRandomStackProtectionCanaryOfGeneralOfPCConfig()                            (TRUE != FALSE)
#define vHsm_HasGeneratorCompatibilityVersionOfPCConfig()                                             /**< Deactivateable: 'vHsm_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define vHsm_HasInitDataHashCodeOfPCConfig()                                                          /**< Deactivateable: 'vHsm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define vHsm_HasInterruptModeOfSchedulingOfPCConfig()                                               (TRUE != FALSE)
#define vHsm_HasInvalidNvMBlockBehaviourOfGeneralOfPCConfig()                                       (TRUE != FALSE)
#define vHsm_HasIpcInstanceOfPCConfig()                                                             (TRUE != FALSE)
#define vHsm_HasIsrForProcessingOfSchedulingOfPCConfig()                                            (TRUE != FALSE)
#define vHsm_HasJobObjectInfoOfPCConfig()                                                           (TRUE != FALSE)
#define vHsm_HasJobObjectsOfPCConfig()                                                              (TRUE != FALSE)
#define vHsm_HasJumpToUpdaterRestrictionOfFirmwareUpdateOfPCConfig()                                (TRUE != FALSE)
#define vHsm_HasKeyInfoOfPCConfig()                                                                 (TRUE != FALSE)
#define vHsm_HasKeyManagementChannelOfChannelMappingOfPCConfig()                                    (TRUE != FALSE)
#define vHsm_HasMainFunctionPeriodOfGeneralOfPCConfig()                                               /**< Deactivateable: 'vHsm_PCConfig.MainFunctionPeriodOfGeneral' Reason: 'Parameter is not configured!' */
#define vHsm_HasMemoryAreaOfPCConfig()                                                              (TRUE != FALSE)
#define vHsm_HasOptionByteModificationOfDevelopmentOfPCConfig()                                       /**< Deactivateable: 'vHsm_PCConfig.OptionByteModificationOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_HasOsSupportOfSchedulingOfPCConfig()                                                   (TRUE != FALSE)
#define vHsm_HasProtocolVersionOfIpcOfPCConfig()                                                    (TRUE != FALSE)
#define vHsm_HasQueueSizeOfSecureBootOfPCConfig()                                                     /**< Deactivateable: 'vHsm_PCConfig.QueueSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_HasRandomCsmJobRefOfGeneralOfPCConfig()                                                (TRUE != FALSE)
#define vHsm_HasRandomInitOfPCConfig()                                                              (TRUE != FALSE)
#define vHsm_HasRedirectionOfGeneralOfPCConfig()                                                    (TRUE != FALSE)
#define vHsm_HasRestrictedChannelsOfPCConfig()                                                      (TRUE != FALSE)
#define vHsm_HasSchedulableEntitiesOfPCConfig()                                                     (TRUE != FALSE)
#define vHsm_HasScheduledChannelsOfPCConfig()                                                       (TRUE != FALSE)
#define vHsm_HasSegmentSuccessCalloutOfSecureBootOfPCConfig()                                         /**< Deactivateable: 'vHsm_PCConfig.SegmentSuccessCalloutOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_HasSizeOfChannelInfoOfPCConfig()                                                       (TRUE != FALSE)
#define vHsm_HasSizeOfCoreKeyOfPCConfig()                                                           (TRUE != FALSE)
#define vHsm_HasSizeOfCryptoFunctionsOfPCConfig()                                                   (TRUE != FALSE)
#define vHsm_HasSizeOfDriverObjectMappingIndOfPCConfig()                                            (TRUE != FALSE)
#define vHsm_HasSizeOfDriverObjectMappingOfPCConfig()                                               (TRUE != FALSE)
#define vHsm_HasSizeOfIpcInstanceOfPCConfig()                                                       (TRUE != FALSE)
#define vHsm_HasSizeOfJobObjectInfoOfPCConfig()                                                     (TRUE != FALSE)
#define vHsm_HasSizeOfJobObjectsOfPCConfig()                                                        (TRUE != FALSE)
#define vHsm_HasSizeOfKeyInfoOfPCConfig()                                                           (TRUE != FALSE)
#define vHsm_HasSizeOfMemoryAreaOfPCConfig()                                                        (TRUE != FALSE)
#define vHsm_HasSizeOfRandomInitOfPCConfig()                                                        (TRUE != FALSE)
#define vHsm_HasSizeOfRestrictedChannelsOfPCConfig()                                                (TRUE != FALSE)
#define vHsm_HasSizeOfSchedulableEntitiesOfPCConfig()                                               (TRUE != FALSE)
#define vHsm_HasSizeOfScheduledChannelsOfPCConfig()                                                 (TRUE != FALSE)
#define vHsm_HasSoftResetLimitOfGeneralOfPCConfig()                                                 (TRUE != FALSE)
#define vHsm_HasSplitSizeOfSecureBootOfPCConfig()                                                     /**< Deactivateable: 'vHsm_PCConfig.SplitSizeOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_HasStorageMethodOfSecureBootOfPCConfig()                                                 /**< Deactivateable: 'vHsm_PCConfig.StorageMethodOfSecureBoot' Reason: 'Parameter is not configured!' */
#define vHsm_HasSupportSaveRestoreContextOfGeneralOfPCConfig()                                      (TRUE != FALSE)
#define vHsm_HasTraceDebugOfDevelopmentOfPCConfig()                                                   /**< Deactivateable: 'vHsm_PCConfig.TraceDebugOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_HasTraceErrorOfDevelopmentOfPCConfig()                                                   /**< Deactivateable: 'vHsm_PCConfig.TraceErrorOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_HasTraceInfoOfDevelopmentOfPCConfig()                                                    /**< Deactivateable: 'vHsm_PCConfig.TraceInfoOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_HasTraceKeyStorageOfDevelopmentOfPCConfig()                                              /**< Deactivateable: 'vHsm_PCConfig.TraceKeyStorageOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_HasTraceWarningOfDevelopmentOfPCConfig()                                                 /**< Deactivateable: 'vHsm_PCConfig.TraceWarningOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_HasUpdaterAddressOfFirmwareUpdateOfPCConfig()                                          (TRUE != FALSE)
#define vHsm_HasUpgradeProtectionModificationOfDevelopmentOfPCConfig()                                /**< Deactivateable: 'vHsm_PCConfig.UpgradeProtectionModificationOfDevelopment' Reason: 'Parameter is not configured!' */
#define vHsm_HasUserRevisionOfGeneralOfPCConfig()                                                     /**< Deactivateable: 'vHsm_PCConfig.UserRevisionOfGeneral' Reason: 'Parameter is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCIncrementDataMacros  vHsm Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define vHsm_IncIpcChannelOfJobObjects(Index)                                                       vHsm_GetIpcChannelOfJobObjects(Index)++
#define vHsm_IncIpcInstanceOfJobObjects(Index)                                                      vHsm_GetIpcInstanceOfJobObjects(Index)++
#define vHsm_IncIpcMappingOfJobObjects(Index)                                                       vHsm_GetIpcMappingOfJobObjects(Index)++
#define vHsm_IncJobDataOfJobObjects(Index)                                                          vHsm_GetJobDataOfJobObjects(Index)++
#define vHsm_IncJobRequestIdOfJobObjects(Index)                                                     vHsm_GetJobRequestIdOfJobObjects(Index)++
#define vHsm_IncJobRequestKindOfJobObjects(Index)                                                   vHsm_GetJobRequestKindOfJobObjects(Index)++
#define vHsm_IncJobRetValOfJobObjects(Index)                                                        vHsm_GetJobRetValOfJobObjects(Index)++
#define vHsm_IncLocalOutputOfJobObjects(Index)                                                      vHsm_GetLocalOutputOfJobObjects(Index)++
#define vHsm_IncProcessKindOfJobObjects(Index)                                                      vHsm_GetProcessKindOfJobObjects(Index)++
#define vHsm_IncProcessingTypeOfJobObjects(Index)                                                   vHsm_GetProcessingTypeOfJobObjects(Index)++
#define vHsm_IncRedirectionFlagsOfJobObjects(Index)                                                 vHsm_GetRedirectionFlagsOfJobObjects(Index)++
#define vHsm_IncStateOfJobObjects(Index)                                                            vHsm_GetStateOfJobObjects(Index)++
#define vHsm_IncUsageRestrictionOfJobObjects(Index)                                                 vHsm_GetUsageRestrictionOfJobObjects(Index)++
#define vHsm_IncLogEventMemory(Index)                                                                 /**< Deactivateable: 'vHsm_LogEventMemory' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCDecrementDataMacros  vHsm Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define vHsm_DecIpcChannelOfJobObjects(Index)                                                       vHsm_GetIpcChannelOfJobObjects(Index)--
#define vHsm_DecIpcInstanceOfJobObjects(Index)                                                      vHsm_GetIpcInstanceOfJobObjects(Index)--
#define vHsm_DecIpcMappingOfJobObjects(Index)                                                       vHsm_GetIpcMappingOfJobObjects(Index)--
#define vHsm_DecJobDataOfJobObjects(Index)                                                          vHsm_GetJobDataOfJobObjects(Index)--
#define vHsm_DecJobRequestIdOfJobObjects(Index)                                                     vHsm_GetJobRequestIdOfJobObjects(Index)--
#define vHsm_DecJobRequestKindOfJobObjects(Index)                                                   vHsm_GetJobRequestKindOfJobObjects(Index)--
#define vHsm_DecJobRetValOfJobObjects(Index)                                                        vHsm_GetJobRetValOfJobObjects(Index)--
#define vHsm_DecLocalOutputOfJobObjects(Index)                                                      vHsm_GetLocalOutputOfJobObjects(Index)--
#define vHsm_DecProcessKindOfJobObjects(Index)                                                      vHsm_GetProcessKindOfJobObjects(Index)--
#define vHsm_DecProcessingTypeOfJobObjects(Index)                                                   vHsm_GetProcessingTypeOfJobObjects(Index)--
#define vHsm_DecRedirectionFlagsOfJobObjects(Index)                                                 vHsm_GetRedirectionFlagsOfJobObjects(Index)--
#define vHsm_DecStateOfJobObjects(Index)                                                            vHsm_GetStateOfJobObjects(Index)--
#define vHsm_DecUsageRestrictionOfJobObjects(Index)                                                 vHsm_GetUsageRestrictionOfJobObjects(Index)--
#define vHsm_DecLogEventMemory(Index)                                                                 /**< Deactivateable: 'vHsm_LogEventMemory' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCAddDataMacros  vHsm Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define vHsm_AddIpcChannelOfJobObjects(Index, Value)                                                vHsm_SetIpcChannelOfJobObjects(Index, (vHsm_GetIpcChannelOfJobObjects(Index) + Value))
#define vHsm_AddIpcInstanceOfJobObjects(Index, Value)                                               vHsm_SetIpcInstanceOfJobObjects(Index, (vHsm_GetIpcInstanceOfJobObjects(Index) + Value))
#define vHsm_AddIpcMappingOfJobObjects(Index, Value)                                                vHsm_SetIpcMappingOfJobObjects(Index, (vHsm_GetIpcMappingOfJobObjects(Index) + Value))
#define vHsm_AddJobDataOfJobObjects(Index, Value)                                                   vHsm_SetJobDataOfJobObjects(Index, (vHsm_GetJobDataOfJobObjects(Index) + Value))
#define vHsm_AddJobRequestIdOfJobObjects(Index, Value)                                              vHsm_SetJobRequestIdOfJobObjects(Index, (vHsm_GetJobRequestIdOfJobObjects(Index) + Value))
#define vHsm_AddJobRequestKindOfJobObjects(Index, Value)                                            vHsm_SetJobRequestKindOfJobObjects(Index, (vHsm_GetJobRequestKindOfJobObjects(Index) + Value))
#define vHsm_AddJobRetValOfJobObjects(Index, Value)                                                 vHsm_SetJobRetValOfJobObjects(Index, (vHsm_GetJobRetValOfJobObjects(Index) + Value))
#define vHsm_AddLocalOutputOfJobObjects(Index, Value)                                               vHsm_SetLocalOutputOfJobObjects(Index, (vHsm_GetLocalOutputOfJobObjects(Index) + Value))
#define vHsm_AddProcessKindOfJobObjects(Index, Value)                                               vHsm_SetProcessKindOfJobObjects(Index, (vHsm_GetProcessKindOfJobObjects(Index) + Value))
#define vHsm_AddProcessingTypeOfJobObjects(Index, Value)                                            vHsm_SetProcessingTypeOfJobObjects(Index, (vHsm_GetProcessingTypeOfJobObjects(Index) + Value))
#define vHsm_AddRedirectionFlagsOfJobObjects(Index, Value)                                          vHsm_SetRedirectionFlagsOfJobObjects(Index, (vHsm_GetRedirectionFlagsOfJobObjects(Index) + Value))
#define vHsm_AddStateOfJobObjects(Index, Value)                                                     vHsm_SetStateOfJobObjects(Index, (vHsm_GetStateOfJobObjects(Index) + Value))
#define vHsm_AddUsageRestrictionOfJobObjects(Index, Value)                                          vHsm_SetUsageRestrictionOfJobObjects(Index, (vHsm_GetUsageRestrictionOfJobObjects(Index) + Value))
#define vHsm_AddLogEventMemory(Index, Value)                                                          /**< Deactivateable: 'vHsm_LogEventMemory' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCSubstractDataMacros  vHsm Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define vHsm_SubIpcChannelOfJobObjects(Index, Value)                                                vHsm_SetIpcChannelOfJobObjects(Index, (vHsm_GetIpcChannelOfJobObjects(Index) - Value))
#define vHsm_SubIpcInstanceOfJobObjects(Index, Value)                                               vHsm_SetIpcInstanceOfJobObjects(Index, (vHsm_GetIpcInstanceOfJobObjects(Index) - Value))
#define vHsm_SubIpcMappingOfJobObjects(Index, Value)                                                vHsm_SetIpcMappingOfJobObjects(Index, (vHsm_GetIpcMappingOfJobObjects(Index) - Value))
#define vHsm_SubJobDataOfJobObjects(Index, Value)                                                   vHsm_SetJobDataOfJobObjects(Index, (vHsm_GetJobDataOfJobObjects(Index) - Value))
#define vHsm_SubJobRequestIdOfJobObjects(Index, Value)                                              vHsm_SetJobRequestIdOfJobObjects(Index, (vHsm_GetJobRequestIdOfJobObjects(Index) - Value))
#define vHsm_SubJobRequestKindOfJobObjects(Index, Value)                                            vHsm_SetJobRequestKindOfJobObjects(Index, (vHsm_GetJobRequestKindOfJobObjects(Index) - Value))
#define vHsm_SubJobRetValOfJobObjects(Index, Value)                                                 vHsm_SetJobRetValOfJobObjects(Index, (vHsm_GetJobRetValOfJobObjects(Index) - Value))
#define vHsm_SubLocalOutputOfJobObjects(Index, Value)                                               vHsm_SetLocalOutputOfJobObjects(Index, (vHsm_GetLocalOutputOfJobObjects(Index) - Value))
#define vHsm_SubProcessKindOfJobObjects(Index, Value)                                               vHsm_SetProcessKindOfJobObjects(Index, (vHsm_GetProcessKindOfJobObjects(Index) - Value))
#define vHsm_SubProcessingTypeOfJobObjects(Index, Value)                                            vHsm_SetProcessingTypeOfJobObjects(Index, (vHsm_GetProcessingTypeOfJobObjects(Index) - Value))
#define vHsm_SubRedirectionFlagsOfJobObjects(Index, Value)                                          vHsm_SetRedirectionFlagsOfJobObjects(Index, (vHsm_GetRedirectionFlagsOfJobObjects(Index) - Value))
#define vHsm_SubStateOfJobObjects(Index, Value)                                                     vHsm_SetStateOfJobObjects(Index, (vHsm_GetStateOfJobObjects(Index) - Value))
#define vHsm_SubUsageRestrictionOfJobObjects(Index, Value)                                          vHsm_SetUsageRestrictionOfJobObjects(Index, (vHsm_GetUsageRestrictionOfJobObjects(Index) - Value))
#define vHsm_SubLogEventMemory(Index, Value)                                                          /**< Deactivateable: 'vHsm_LogEventMemory' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
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
  \defgroup  vHsmPBGetRootDataMacros  vHsm Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define vHsm_GetLTConfigIdxOfPBConfig()                                                               /**< Deactivateable: 'vHsm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vHsm_GetPCConfigIdxOfPBConfig()                                                               /**< Deactivateable: 'vHsm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPBHasMacros  vHsm Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define vHsm_HasPBConfig()                                                                            /**< Deactivateable: 'vHsm_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vHsm_HasLTConfigIdxOfPBConfig()                                                               /**< Deactivateable: 'vHsm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define vHsm_HasPCConfigIdxOfPBConfig()                                                               /**< Deactivateable: 'vHsm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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




/* PRQA S 3453 1 */ /* MD_MSR_FctLikeMacro */
#define vHsm_TriggerResponseInterrupt(ipcChannel) *(P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR))((uint32)vHsm_GetResponseInterruptFlagSetAddressOfIpcInstance((ipcChannel))) = vHsm_GetResponseInterruptFlagSetMaskOfIpcInstance((ipcChannel))


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef P2VAR(uint32, VHSM_CONST, VHSM_VAR_NOINIT) vHsm_Ipc_MemoryPtrType;
/*! Temporary local length pointers used to replace the one provided by the application */
# if (VHSM_IPC_PROTOCOL_VERSION == 2u)
typedef struct
{
  P2VAR(uint32, AUTOMATIC, VHSM_APPL_VAR) lengthPtr;
  uint32 length;
} vHsm_LocalOutputInfoType;
# endif

/*! Temporary local length pointers used to replace the one provided by the application */
typedef struct
{
# if (VHSM_IPC_PROTOCOL_VERSION == 3u)
  uint32 outputLength;
  uint32 secondaryOutputLength;
  Crypto_VerifyResultType verifyResult;
# else
  vHsm_LocalOutputInfoType output;
  vHsm_LocalOutputInfoType secondaryOutput;
# endif
} vHsm_LocalOutputType;
typedef P2FUNC (Std_ReturnType, VHSM_APPL_CODE, vHsm_KeyElementSetFuncType)(uint32 cryptoKeyId, uint32 keyElementId, const uint8* keyPtr, uint32 keyLength);
typedef P2FUNC (Std_ReturnType, VHSM_CODE, vHsm_KeyValidSetFuncType)(uint32 cryptoKeyId);
typedef P2FUNC (Std_ReturnType, VHSM_APPL_CODE, vHsm_KeyElementGetFuncType)(uint32 cryptoKeyId, uint32 keyElementId, uint8* resultPtr, uint32* resultLengthPtr);
typedef P2FUNC (Std_ReturnType, VHSM_APPL_CODE, vHsm_KeyElementCopyFuncType)(uint32 cryptoKeyId, uint32 keyElementId, uint32 targetCryptoKeyId, uint32 targetKeyElementId);
typedef P2FUNC (Std_ReturnType, VHSM_APPL_CODE, vHsm_KeyElementCopyPartialFuncType)(uint32 cryptoKeyId, uint32 keyElementId, uint32 keyElementSourceOffset, uint32 keyElementTargetOffset, uint32 keyElementCopyLength, uint32 targetCryptoKeyId, uint32 targetKeyElementId);
typedef P2FUNC (Std_ReturnType, VHSM_APPL_CODE, vHsm_KeyElementIdsGetFuncType)(uint32 cryptoKeyId, uint32* keyElementIdsPtr, uint32* keyElementIdsLengthPtr);
typedef P2FUNC (Std_ReturnType, VHSM_APPL_CODE, vHsm_KeyCopyFuncType)(uint32 cryptoKeyId, uint32 targetCryptoKeyId);
typedef P2FUNC (Std_ReturnType, VHSM_APPL_CODE, vHsm_RandomSeedFuncType)(uint32 cryptoKeyId, const uint8* entropyPtr, uint32 entropyLength);
typedef P2FUNC (Std_ReturnType, VHSM_CODE, vHsm_KeyGenerateFuncType)(uint32 cryptoKeyId);
typedef P2FUNC (Std_ReturnType, VHSM_APPL_CODE, vHsm_KeyDeriveFuncType)(uint32 cryptoKeyId, uint32 targetCryptoKeyId);
typedef P2FUNC (Std_ReturnType, VHSM_APPL_CODE, vHsm_KeyExchangeCalcPubValFuncType)(uint32 cryptoKeyId, uint8* publicValuePtr, uint32* publicValueLengthPtr);
typedef P2FUNC (Std_ReturnType, VHSM_APPL_CODE, vHsm_KeyExchangeCalcSecretFuncType)(uint32 cryptoKeyId, const uint8* partnerPublicValuePtr, uint32 partnerPublicValueLength);
typedef P2FUNC (Std_ReturnType, VHSM_CODE, vHsm_CertificateParseFuncType)(uint32 cryptoKeyId);
typedef P2FUNC (Std_ReturnType, VHSM_APPL_CODE, vHsm_CertificateVerifyFuncType)(uint32 cryptoKeyId, uint32 verifyCryptoKeyId, Crypto_VerifyResultType* verifyPtr);
typedef P2FUNC (Std_ReturnType, VHSM_APPL_CODE, vHsm_CancelJobFuncType)(uint32 objectId, Crypto_JobType* job);
typedef P2FUNC (Std_ReturnType, VHSM_APPL_CODE, vHsm_ProcessJobFuncType)(uint32 objectId, Crypto_JobType* job);
typedef uint8 vHsm_CallContextType;


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vHsmPCIterableTypes  vHsm Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate vHsm_ChannelInfo */
typedef uint8_least vHsm_ChannelInfoIterType;

/**   \brief  type used to iterate vHsm_CoreKey */
typedef uint8_least vHsm_CoreKeyIterType;

/**   \brief  type used to iterate vHsm_CryptoFunctions */
typedef uint8_least vHsm_CryptoFunctionsIterType;

/**   \brief  type used to iterate vHsm_DriverObjectMapping */
typedef uint8_least vHsm_DriverObjectMappingIterType;

/**   \brief  type used to iterate vHsm_DriverObjectMappingInd */
typedef uint8_least vHsm_DriverObjectMappingIndIterType;

/**   \brief  type used to iterate vHsm_IpcInstance */
typedef uint8_least vHsm_IpcInstanceIterType;

/**   \brief  type used to iterate vHsm_JobObjectInfo */
typedef uint8_least vHsm_JobObjectInfoIterType;

/**   \brief  type used to iterate vHsm_JobObjects */
typedef uint8_least vHsm_JobObjectsIterType;

/**   \brief  type used to iterate vHsm_KeyInfo */
typedef uint8_least vHsm_KeyInfoIterType;

/**   \brief  type used to iterate vHsm_MemoryArea */
typedef uint8_least vHsm_MemoryAreaIterType;

/**   \brief  type used to iterate vHsm_RandomInit */
typedef uint8_least vHsm_RandomInitIterType;

/**   \brief  type used to iterate vHsm_RestrictedChannels */
typedef uint8_least vHsm_RestrictedChannelsIterType;

/**   \brief  type used to iterate vHsm_SchedulableEntities */
typedef uint8_least vHsm_SchedulableEntitiesIterType;

/**   \brief  type used to iterate vHsm_ScheduledChannels */
typedef uint8_least vHsm_ScheduledChannelsIterType;

/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCValueTypes  vHsm Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for vHsm_CryptoFunctionsIdxOfChannelInfo */
typedef uint8 vHsm_CryptoFunctionsIdxOfChannelInfoType;

/**   \brief  value based type definition for vHsm_DriverObjectRefOfChannelInfo */
typedef uint32 vHsm_DriverObjectRefOfChannelInfoType;

/**   \brief  value based type definition for vHsm_ChannelsOfIpc */
typedef uint8 vHsm_ChannelsOfIpcType;

/**   \brief  value based type definition for vHsm_AggregatedCryptoKeyIdOfCoreKey */
typedef uint32 vHsm_AggregatedCryptoKeyIdOfCoreKeyType;

/**   \brief  value based type definition for vHsm_KeyIdOfCoreKey */
typedef uint16 vHsm_KeyIdOfCoreKeyType;

/**   \brief  value based type definition for vHsm_CsmJobDecryptRefOfFirmwareUpdate */
typedef uint32 vHsm_CsmJobDecryptRefOfFirmwareUpdateType;

/**   \brief  value based type definition for vHsm_CsmJobEncryptRefOfFirmwareUpdate */
typedef uint32 vHsm_CsmJobEncryptRefOfFirmwareUpdateType;

/**   \brief  value based type definition for vHsm_CsmJobMacGenerateRefOfFirmwareUpdate */
typedef uint32 vHsm_CsmJobMacGenerateRefOfFirmwareUpdateType;

/**   \brief  value based type definition for vHsm_CsmJobSignatureVerifyRefOfFirmwareUpdate */
typedef uint32 vHsm_CsmJobSignatureVerifyRefOfFirmwareUpdateType;

/**   \brief  value based type definition for vHsm_DriverObjectMapping */
typedef uint32 vHsm_DriverObjectMappingType;

/**   \brief  value based type definition for vHsm_DriverObjectMappingInd */
typedef uint8 vHsm_DriverObjectMappingIndType;

/**   \brief  value based type definition for vHsm_EnableRamLoopCalloutOfGeneral */
typedef boolean vHsm_EnableRamLoopCalloutOfGeneralType;

/**   \brief  value based type definition for vHsm_ForceInterruptTriggeringOfGeneral */
typedef boolean vHsm_ForceInterruptTriggeringOfGeneralType;

/**   \brief  value based type definition for vHsm_GenerateRandomIpcValuesOfGeneral */
typedef boolean vHsm_GenerateRandomIpcValuesOfGeneralType;

/**   \brief  value based type definition for vHsm_GenerateRandomStackProtectionCanaryOfGeneral */
typedef boolean vHsm_GenerateRandomStackProtectionCanaryOfGeneralType;

/**   \brief  value based type definition for vHsm_InterruptModeOfScheduling */
typedef boolean vHsm_InterruptModeOfSchedulingType;

/**   \brief  value based type definition for vHsm_InvalidNvMBlockBehaviourOfGeneral */
typedef uint32 vHsm_InvalidNvMBlockBehaviourOfGeneralType;

/**   \brief  value based type definition for vHsm_DriverObjectMappingIndEndIdxOfIpcInstance */
typedef uint8 vHsm_DriverObjectMappingIndEndIdxOfIpcInstanceType;

/**   \brief  value based type definition for vHsm_DriverObjectMappingIndStartIdxOfIpcInstance */
typedef uint8 vHsm_DriverObjectMappingIndStartIdxOfIpcInstanceType;

/**   \brief  value based type definition for vHsm_DriverObjectMappingIndUsedOfIpcInstance */
typedef boolean vHsm_DriverObjectMappingIndUsedOfIpcInstanceType;

/**   \brief  value based type definition for vHsm_HardwareUnitOfIpcInstance */
typedef uint8 vHsm_HardwareUnitOfIpcInstanceType;

/**   \brief  value based type definition for vHsm_IdOfIpcInstance */
typedef uint8 vHsm_IdOfIpcInstanceType;

/**   \brief  value based type definition for vHsm_ResponseInterruptFlagSetAddressOfIpcInstance */
typedef uint32 vHsm_ResponseInterruptFlagSetAddressOfIpcInstanceType;

/**   \brief  value based type definition for vHsm_ResponseInterruptFlagSetMaskOfIpcInstance */
typedef uint8 vHsm_ResponseInterruptFlagSetMaskOfIpcInstanceType;

/**   \brief  value based type definition for vHsm_IsrForProcessingOfScheduling */
typedef uint32 vHsm_IsrForProcessingOfSchedulingType;

/**   \brief  value based type definition for vHsm_EventTriggeredOfJobObjectInfo */
typedef boolean vHsm_EventTriggeredOfJobObjectInfoType;

/**   \brief  value based type definition for vHsm_IsrProcessingOfJobObjectInfo */
typedef boolean vHsm_IsrProcessingOfJobObjectInfoType;

/**   \brief  value based type definition for vHsm_MaskedBitsOfJobObjectInfo */
typedef uint8 vHsm_MaskedBitsOfJobObjectInfoType;

/**   \brief  value based type definition for vHsm_CancelFlagOfJobObjects */
typedef boolean vHsm_CancelFlagOfJobObjectsType;

/**   \brief  value based type definition for vHsm_IpcChannelOfJobObjects */
typedef uint32 vHsm_IpcChannelOfJobObjectsType;

/**   \brief  value based type definition for vHsm_IpcInstanceOfJobObjects */
typedef uint8 vHsm_IpcInstanceOfJobObjectsType;

/**   \brief  value based type definition for vHsm_IpcMappingOfJobObjects */
typedef uint8 vHsm_IpcMappingOfJobObjectsType;

/**   \brief  value based type definition for vHsm_JobRetValOfJobObjects */
typedef uint32 vHsm_JobRetValOfJobObjectsType;

/**   \brief  value based type definition for vHsm_ProcessKindOfJobObjects */
typedef uint8 vHsm_ProcessKindOfJobObjectsType;

/**   \brief  value based type definition for vHsm_RedirectionFlagsOfJobObjects */
typedef uint8 vHsm_RedirectionFlagsOfJobObjectsType;

/**   \brief  value based type definition for vHsm_UsageRestrictionOfJobObjects */
typedef uint8 vHsm_UsageRestrictionOfJobObjectsType;

/**   \brief  value based type definition for vHsm_ValidRequestFlagOfJobObjects */
typedef boolean vHsm_ValidRequestFlagOfJobObjectsType;

/**   \brief  value based type definition for vHsm_JumpToUpdaterRestrictionOfFirmwareUpdate */
typedef boolean vHsm_JumpToUpdaterRestrictionOfFirmwareUpdateType;

/**   \brief  value based type definition for vHsm_CryptoFunctionsIdxOfKeyInfo */
typedef uint8 vHsm_CryptoFunctionsIdxOfKeyInfoType;

/**   \brief  value based type definition for vHsm_CryptoKeyIdOfKeyInfo */
typedef uint32 vHsm_CryptoKeyIdOfKeyInfoType;

/**   \brief  value based type definition for vHsm_InternalOnlyOfKeyInfo */
typedef boolean vHsm_InternalOnlyOfKeyInfoType;

/**   \brief  value based type definition for vHsm_MaskedBitsOfKeyInfo */
typedef uint8 vHsm_MaskedBitsOfKeyInfoType;

/**   \brief  value based type definition for vHsm_RoutedOfKeyInfo */
typedef boolean vHsm_RoutedOfKeyInfoType;

/**   \brief  value based type definition for vHsm_KeyManagementChannelOfChannelMapping */
typedef uint32 vHsm_KeyManagementChannelOfChannelMappingType;

/**   \brief  value based type definition for vHsm_StartOfMemoryArea */
typedef uint32 vHsm_StartOfMemoryAreaType;

/**   \brief  value based type definition for vHsm_StopOfMemoryArea */
typedef uint32 vHsm_StopOfMemoryAreaType;

/**   \brief  value based type definition for vHsm_TypeOfMemoryArea */
typedef uint8 vHsm_TypeOfMemoryAreaType;

/**   \brief  value based type definition for vHsm_OsSupportOfScheduling */
typedef boolean vHsm_OsSupportOfSchedulingType;

/**   \brief  value based type definition for vHsm_ProtocolVersionOfIpc */
typedef uint8 vHsm_ProtocolVersionOfIpcType;

/**   \brief  value based type definition for vHsm_RandomCsmJobRefOfGeneral */
typedef uint32 vHsm_RandomCsmJobRefOfGeneralType;

/**   \brief  value based type definition for vHsm_KeyElementOfRandomInit */
typedef uint32 vHsm_KeyElementOfRandomInitType;

/**   \brief  value based type definition for vHsm_KeyOfRandomInit */
typedef uint32 vHsm_KeyOfRandomInitType;

/**   \brief  value based type definition for vHsm_RedirectionOfGeneral */
typedef boolean vHsm_RedirectionOfGeneralType;

/**   \brief  value based type definition for vHsm_RestrictedChannels */
typedef boolean vHsm_RestrictedChannelsType;

/**   \brief  value based type definition for vHsm_ScheduledChannelsEndIdxOfSchedulableEntities */
typedef uint8 vHsm_ScheduledChannelsEndIdxOfSchedulableEntitiesType;

/**   \brief  value based type definition for vHsm_ScheduledChannelsStartIdxOfSchedulableEntities */
typedef uint8 vHsm_ScheduledChannelsStartIdxOfSchedulableEntitiesType;

/**   \brief  value based type definition for vHsm_ScheduledChannels */
typedef uint32 vHsm_ScheduledChannelsType;

/**   \brief  value based type definition for vHsm_SizeOfChannelInfo */
typedef uint8 vHsm_SizeOfChannelInfoType;

/**   \brief  value based type definition for vHsm_SizeOfCoreKey */
typedef uint8 vHsm_SizeOfCoreKeyType;

/**   \brief  value based type definition for vHsm_SizeOfCryptoFunctions */
typedef uint8 vHsm_SizeOfCryptoFunctionsType;

/**   \brief  value based type definition for vHsm_SizeOfDriverObjectMapping */
typedef uint8 vHsm_SizeOfDriverObjectMappingType;

/**   \brief  value based type definition for vHsm_SizeOfDriverObjectMappingInd */
typedef uint8 vHsm_SizeOfDriverObjectMappingIndType;

/**   \brief  value based type definition for vHsm_SizeOfIpcInstance */
typedef uint8 vHsm_SizeOfIpcInstanceType;

/**   \brief  value based type definition for vHsm_SizeOfJobObjectInfo */
typedef uint8 vHsm_SizeOfJobObjectInfoType;

/**   \brief  value based type definition for vHsm_SizeOfJobObjects */
typedef uint8 vHsm_SizeOfJobObjectsType;

/**   \brief  value based type definition for vHsm_SizeOfKeyInfo */
typedef uint8 vHsm_SizeOfKeyInfoType;

/**   \brief  value based type definition for vHsm_SizeOfMemoryArea */
typedef uint8 vHsm_SizeOfMemoryAreaType;

/**   \brief  value based type definition for vHsm_SizeOfRandomInit */
typedef uint8 vHsm_SizeOfRandomInitType;

/**   \brief  value based type definition for vHsm_SizeOfRestrictedChannels */
typedef uint8 vHsm_SizeOfRestrictedChannelsType;

/**   \brief  value based type definition for vHsm_SizeOfSchedulableEntities */
typedef uint8 vHsm_SizeOfSchedulableEntitiesType;

/**   \brief  value based type definition for vHsm_SizeOfScheduledChannels */
typedef uint8 vHsm_SizeOfScheduledChannelsType;

/**   \brief  value based type definition for vHsm_SoftResetLimitOfGeneral */
typedef uint8 vHsm_SoftResetLimitOfGeneralType;

/**   \brief  value based type definition for vHsm_SupportSaveRestoreContextOfGeneral */
typedef boolean vHsm_SupportSaveRestoreContextOfGeneralType;

/**   \brief  value based type definition for vHsm_UpdaterAddressOfFirmwareUpdate */
typedef uint32 vHsm_UpdaterAddressOfFirmwareUpdateType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vHsmPCStructTypes  vHsm Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in vHsm_ChannelInfo */
/*! \spec weak type invariant () { 
 * (self.CryptoFunctionsIdxOfChannelInfo < vHsm_GetSizeOfCryptoFunctions())
 * } */
typedef struct svHsm_ChannelInfoType
{
  vHsm_DriverObjectRefOfChannelInfoType DriverObjectRefOfChannelInfo;
  vHsm_CryptoFunctionsIdxOfChannelInfoType CryptoFunctionsIdxOfChannelInfo;  /**< the index of the 1:1 relation pointing to vHsm_CryptoFunctions */
} vHsm_ChannelInfoType;

/**   \brief  type used in vHsm_CoreKey */
typedef struct svHsm_CoreKeyType
{
  vHsm_AggregatedCryptoKeyIdOfCoreKeyType AggregatedCryptoKeyIdOfCoreKey;
} vHsm_CoreKeyType;

/**   \brief  type used in vHsm_CryptoFunctions */
typedef struct svHsm_CryptoFunctionsType
{
  vHsm_CancelJobFuncType CancelJobOfCryptoFunctions;
  vHsm_CertificateParseFuncType CertificateParseOfCryptoFunctions;
  vHsm_CertificateVerifyFuncType CertificateVerifyOfCryptoFunctions;
  vHsm_KeyCopyFuncType KeyCopyOfCryptoFunctions;
  vHsm_KeyDeriveFuncType KeyDeriveOfCryptoFunctions;
  vHsm_KeyElementCopyFuncType KeyElementCopyOfCryptoFunctions;
  vHsm_KeyElementCopyPartialFuncType KeyElementCopyPartialOfCryptoFunctions;
  vHsm_KeyElementGetFuncType KeyElementGetOfCryptoFunctions;
  vHsm_KeyElementIdsGetFuncType KeyElementIdsGetOfCryptoFunctions;
  vHsm_KeyElementSetFuncType KeyElementSetOfCryptoFunctions;
  vHsm_KeyExchangeCalcPubValFuncType KeyExchangeCalcPubValOfCryptoFunctions;
  vHsm_KeyExchangeCalcSecretFuncType KeyExchangeCalcSecretOfCryptoFunctions;
  vHsm_KeyGenerateFuncType KeyGenerateOfCryptoFunctions;
  vHsm_KeyValidSetFuncType KeyValidSetOfCryptoFunctions;
  vHsm_ProcessJobFuncType ProcessJobOfCryptoFunctions;
  vHsm_RandomSeedFuncType RandomSeedOfCryptoFunctions;
} vHsm_CryptoFunctionsType;

/**   \brief  type used in vHsm_IpcInstance */
typedef struct svHsm_IpcInstanceType
{
  vHsm_Ipc_MemoryPtrType MemoryOfIpcInstance;
} vHsm_IpcInstanceType;

/**   \brief  type used in vHsm_JobObjectInfo */
typedef struct svHsm_JobObjectInfoType
{
  vHsm_MaskedBitsOfJobObjectInfoType MaskedBitsOfJobObjectInfo;  /**< contains bitcoded the boolean data of vHsm_EventTriggeredOfJobObjectInfo, vHsm_IsrProcessingOfJobObjectInfo */
  EventMaskType SchedEventRefOfJobObjectInfo;  /**< Event that needs to be triggered to activate Task. */
  TaskType SchedTaskRefOfJobObjectInfo;  /**< Task in which channel shall be processed. */
} vHsm_JobObjectInfoType;

/**   \brief  type used in vHsm_JobObjects */
typedef struct svHsm_JobObjectsType
{
  vHsm_IpcChannelOfJobObjectsType IpcChannelOfJobObjects;
  vHsm_JobRetValOfJobObjectsType JobRetValOfJobObjects;
  vHsm_CancelFlagOfJobObjectsType CancelFlagOfJobObjects;
  vHsm_IpcInstanceOfJobObjectsType IpcInstanceOfJobObjects;
  vHsm_IpcMappingOfJobObjectsType IpcMappingOfJobObjects;
  vHsm_ProcessKindOfJobObjectsType ProcessKindOfJobObjects;
  vHsm_RedirectionFlagsOfJobObjectsType RedirectionFlagsOfJobObjects;
  vHsm_UsageRestrictionOfJobObjectsType UsageRestrictionOfJobObjects;
  vHsm_ValidRequestFlagOfJobObjectsType ValidRequestFlagOfJobObjects;
  vHsm_JobDataUnionType JobDataOfJobObjects;
  vHsm_JobRequestIdType JobRequestIdOfJobObjects;
  vHsm_JobRequestKindType JobRequestKindOfJobObjects;
  vHsm_LocalOutputType LocalOutputOfJobObjects;
  Crypto_ProcessingType ProcessingTypeOfJobObjects;
  volatile vHsm_JobObjectstateType StateOfJobObjects;
} vHsm_JobObjectsType;

/**   \brief  type used in vHsm_KeyInfo */
/*! \spec weak type invariant () { 
 * (self.CryptoFunctionsIdxOfKeyInfo < vHsm_GetSizeOfCryptoFunctions())
 * } */
typedef struct svHsm_KeyInfoType
{
  vHsm_CryptoKeyIdOfKeyInfoType CryptoKeyIdOfKeyInfo;
  vHsm_CryptoFunctionsIdxOfKeyInfoType CryptoFunctionsIdxOfKeyInfo;  /**< the index of the 1:1 relation pointing to vHsm_CryptoFunctions */
  vHsm_MaskedBitsOfKeyInfoType MaskedBitsOfKeyInfo;  /**< contains bitcoded the boolean data of vHsm_InternalOnlyOfKeyInfo, vHsm_RoutedOfKeyInfo */
} vHsm_KeyInfoType;

/**   \brief  type used in vHsm_MemoryArea */
typedef struct svHsm_MemoryAreaType
{
  vHsm_StartOfMemoryAreaType StartOfMemoryArea;  /**< Start address of area */
  vHsm_StopOfMemoryAreaType StopOfMemoryArea;  /**< Stop address of area */
  vHsm_TypeOfMemoryAreaType TypeOfMemoryArea;  /**< Access type of area */
} vHsm_MemoryAreaType;

/**   \brief  type used in vHsm_RandomInit */
typedef struct svHsm_RandomInitType
{
  vHsm_KeyOfRandomInitType KeyOfRandomInit;  /**< Contains values of DefinitionRef: /MICROSAR/vHsm/vHsmKeyMapping/vHsmRandomInit/vHsmRandomInitKey. */
  vHsm_KeyElementOfRandomInitType KeyElementOfRandomInit;  /**< Contains values of DefinitionRef: /MICROSAR/vHsm/vHsmKeyMapping/vHsmRandomInit/vHsmRandomInitKeyElement. */
} vHsm_RandomInitType;

/**   \brief  type used in vHsm_SchedulableEntities */
/*! \spec weak type invariant () { 
 * (self.ScheduledChannelsStartIdxOfSchedulableEntities < vHsm_GetSizeOfScheduledChannels()) &&
 * (self.ScheduledChannelsEndIdxOfSchedulableEntities < vHsm_GetSizeOfScheduledChannels())
 * } */
typedef struct svHsm_SchedulableEntitiesType
{
  vHsm_ScheduledChannelsEndIdxOfSchedulableEntitiesType ScheduledChannelsEndIdxOfSchedulableEntities;  /**< the end index of the 1:n relation pointing to vHsm_ScheduledChannels */
  vHsm_ScheduledChannelsStartIdxOfSchedulableEntitiesType ScheduledChannelsStartIdxOfSchedulableEntities;  /**< the start index of the 1:n relation pointing to vHsm_ScheduledChannels */
} vHsm_SchedulableEntitiesType;

/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCSymbolicStructTypes  vHsm Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCUnionIndexAndSymbolTypes  vHsm Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCRootPointerTypes  vHsm Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to vHsm_ChannelInfo */
typedef P2CONST(vHsm_ChannelInfoType, TYPEDEF, VHSM_CONST) vHsm_ChannelInfoPtrType;

/**   \brief  type used to point to vHsm_CoreKey */
typedef P2CONST(vHsm_CoreKeyType, TYPEDEF, VHSM_CONST) vHsm_CoreKeyPtrType;

/**   \brief  type used to point to vHsm_CryptoFunctions */
typedef P2CONST(vHsm_CryptoFunctionsType, TYPEDEF, VHSM_CONST) vHsm_CryptoFunctionsPtrType;

/**   \brief  type used to point to vHsm_DriverObjectMapping */
typedef P2CONST(vHsm_DriverObjectMappingType, TYPEDEF, VHSM_CONST) vHsm_DriverObjectMappingPtrType;

/**   \brief  type used to point to vHsm_DriverObjectMappingInd */
typedef P2CONST(vHsm_DriverObjectMappingIndType, TYPEDEF, VHSM_CONST) vHsm_DriverObjectMappingIndPtrType;

/**   \brief  type used to point to vHsm_IpcInstance */
typedef P2CONST(vHsm_IpcInstanceType, TYPEDEF, VHSM_CONST) vHsm_IpcInstancePtrType;

/**   \brief  type used to point to vHsm_JobObjectInfo */
typedef P2CONST(vHsm_JobObjectInfoType, TYPEDEF, VHSM_CONST) vHsm_JobObjectInfoPtrType;

/**   \brief  type used to point to vHsm_JobObjects */
typedef P2VAR(vHsm_JobObjectsType, TYPEDEF, VHSM_VAR_NOINIT) vHsm_JobObjectsPtrType;

/**   \brief  type used to point to vHsm_KeyInfo */
typedef P2CONST(vHsm_KeyInfoType, TYPEDEF, VHSM_CONST) vHsm_KeyInfoPtrType;

/**   \brief  type used to point to vHsm_MemoryArea */
typedef P2CONST(vHsm_MemoryAreaType, TYPEDEF, VHSM_CONST) vHsm_MemoryAreaPtrType;

/**   \brief  type used to point to vHsm_RandomInit */
typedef P2CONST(vHsm_RandomInitType, TYPEDEF, VHSM_CONST) vHsm_RandomInitPtrType;

/**   \brief  type used to point to vHsm_RestrictedChannels */
typedef P2VAR(vHsm_RestrictedChannelsType, TYPEDEF, VHSM_VAR_NOINIT) vHsm_RestrictedChannelsPtrType;

/**   \brief  type used to point to vHsm_SchedulableEntities */
typedef P2CONST(vHsm_SchedulableEntitiesType, TYPEDEF, VHSM_CONST) vHsm_SchedulableEntitiesPtrType;

/**   \brief  type used to point to vHsm_ScheduledChannels */
typedef P2CONST(vHsm_ScheduledChannelsType, TYPEDEF, VHSM_CONST) vHsm_ScheduledChannelsPtrType;

/**   \brief  type used to point to vHsm_CsmJobDecryptRefOfFirmwareUpdateOfPCConfig */
typedef P2CONST(vHsm_CsmJobDecryptRefOfFirmwareUpdateType, TYPEDEF, VHSM_CONST) vHsm_CsmJobDecryptRefOfFirmwareUpdateOfPCConfigPtrType;

/**   \brief  type used to point to vHsm_CsmJobEncryptRefOfFirmwareUpdateOfPCConfig */
typedef P2CONST(vHsm_CsmJobEncryptRefOfFirmwareUpdateType, TYPEDEF, VHSM_CONST) vHsm_CsmJobEncryptRefOfFirmwareUpdateOfPCConfigPtrType;

/**   \brief  type used to point to vHsm_CsmJobMacGenerateRefOfFirmwareUpdateOfPCConfig */
typedef P2CONST(vHsm_CsmJobMacGenerateRefOfFirmwareUpdateType, TYPEDEF, VHSM_CONST) vHsm_CsmJobMacGenerateRefOfFirmwareUpdateOfPCConfigPtrType;

/**   \brief  type used to point to vHsm_CsmJobSignatureVerifyRefOfFirmwareUpdateOfPCConfig */
typedef P2CONST(vHsm_CsmJobSignatureVerifyRefOfFirmwareUpdateType, TYPEDEF, VHSM_CONST) vHsm_CsmJobSignatureVerifyRefOfFirmwareUpdateOfPCConfigPtrType;

/**   \brief  type used to point to vHsm_InvalidNvMBlockBehaviourOfGeneralOfPCConfig */
typedef P2CONST(vHsm_InvalidNvMBlockBehaviourOfGeneralType, TYPEDEF, VHSM_CONST) vHsm_InvalidNvMBlockBehaviourOfGeneralOfPCConfigPtrType;

/**   \brief  type used to point to vHsm_IsrForProcessingOfSchedulingOfPCConfig */
typedef P2CONST(vHsm_IsrForProcessingOfSchedulingType, TYPEDEF, VHSM_CONST) vHsm_IsrForProcessingOfSchedulingOfPCConfigPtrType;

/**   \brief  type used to point to vHsm_KeyManagementChannelOfChannelMappingOfPCConfig */
typedef P2CONST(vHsm_KeyManagementChannelOfChannelMappingType, TYPEDEF, VHSM_CONST) vHsm_KeyManagementChannelOfChannelMappingOfPCConfigPtrType;

/**   \brief  type used to point to vHsm_RandomCsmJobRefOfGeneralOfPCConfig */
typedef P2CONST(vHsm_RandomCsmJobRefOfGeneralType, TYPEDEF, VHSM_CONST) vHsm_RandomCsmJobRefOfGeneralOfPCConfigPtrType;

/**   \brief  type used to point to vHsm_UpdaterAddressOfFirmwareUpdateOfPCConfig */
typedef P2CONST(vHsm_UpdaterAddressOfFirmwareUpdateType, TYPEDEF, VHSM_CONST) vHsm_UpdaterAddressOfFirmwareUpdateOfPCConfigPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  vHsmPCRootValueTypes  vHsm Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in vHsm_PCConfig */
typedef struct svHsm_PCConfigType
{
  uint8 vHsm_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} vHsm_PCConfigType;

typedef vHsm_PCConfigType vHsm_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  vHsmPBValueTypes  vHsm Value Types (POST_BUILD)
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
  \defgroup  vHsmPBRootValueTypes  vHsm Root Value Types (POST_BUILD)
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
  vHsm_ChannelInfo
**********************************************************************************************************************/
/** 
  \var    vHsm_ChannelInfo
  \brief  Contains attributes per Channel, accessible by external CryIfChannelId
  \details
  Element               Description
  DriverObjectRef   
  CryptoFunctionsIdx    the index of the 1:1 relation pointing to vHsm_CryptoFunctions
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsm_ChannelInfoType, VHSM_CONST) vHsm_ChannelInfo[12];
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_CoreKey
**********************************************************************************************************************/
/** 
  \var    vHsm_CoreKey
  \brief  Contains keys of vHsm_Core, accessible by external KeyId reduced by offset of 30000.
  \details
  Element                  Description
  AggregatedCryptoKeyId
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsm_CoreKeyType, VHSM_CONST) vHsm_CoreKey[3];
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_CryptoFunctions
**********************************************************************************************************************/
/** 
  \var    vHsm_CryptoFunctions
  \details
  Element                  Description
  CancelJob            
  CertificateParse     
  CertificateVerify    
  KeyCopy              
  KeyDerive            
  KeyElementCopy       
  KeyElementCopyPartial
  KeyElementGet        
  KeyElementIdsGet     
  KeyElementSet        
  KeyExchangeCalcPubVal
  KeyExchangeCalcSecret
  KeyGenerate          
  KeyValidSet          
  ProcessJob           
  RandomSeed           
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsm_CryptoFunctionsType, VHSM_CONST) vHsm_CryptoFunctions[5];
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_DriverObjectMapping
**********************************************************************************************************************/
/** 
  \var    vHsm_DriverObjectMapping
  \brief  Contains values of DefinitionRef: /MICROSAR/vHsm/vHsmIpc/vHsmIpcInstance/vHsmDriverObjectMapping.
*/ 
#define VHSM_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsm_DriverObjectMappingType, VHSM_CONST) vHsm_DriverObjectMapping[7];
#define VHSM_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_IpcInstance
**********************************************************************************************************************/
/** 
  \var    vHsm_IpcInstance
  \brief  Contains parameters of /MICROSAR/vHsm/vHsmIpc/vHsmIpcInstance.
  \details
  Element    Description
  Memory 
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsm_IpcInstanceType, VHSM_CONST) vHsm_IpcInstance[1];
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_JobObjectInfo
**********************************************************************************************************************/
/** 
  \var    vHsm_JobObjectInfo
  \brief  Contains attributes per Key, accessible by external KeyId
  \details
  Element          Description
  MaskedBits       contains bitcoded the boolean data of vHsm_EventTriggeredOfJobObjectInfo, vHsm_IsrProcessingOfJobObjectInfo
  SchedEventRef    Event that needs to be triggered to activate Task.
  SchedTaskRef     Task in which channel shall be processed.
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsm_JobObjectInfoType, VHSM_CONST) vHsm_JobObjectInfo[12];
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_KeyInfo
**********************************************************************************************************************/
/** 
  \var    vHsm_KeyInfo
  \brief  Contains attributes per Key, accessible by external KeyId
  \details
  Element               Description
  CryptoKeyId       
  CryptoFunctionsIdx    the index of the 1:1 relation pointing to vHsm_CryptoFunctions
  MaskedBits            contains bitcoded the boolean data of vHsm_InternalOnlyOfKeyInfo, vHsm_RoutedOfKeyInfo
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsm_KeyInfoType, VHSM_CONST) vHsm_KeyInfo[62];
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_MemoryArea
**********************************************************************************************************************/
/** 
  \var    vHsm_MemoryArea
  \brief  Memory to which vHsm allows access.
  \details
  Element    Description
  Start      Start address of area
  Stop       Stop address of area
  Type       Access type of area
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsm_MemoryAreaType, VHSM_CONST) vHsm_MemoryArea[8];
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_RandomInit
**********************************************************************************************************************/
/** 
  \var    vHsm_RandomInit
  \brief  Contains parameters of /MICROSAR/vHsm/vHsmKeyMapping/vHsmRandomInit.
  \details
  Element       Description
  Key           Contains values of DefinitionRef: /MICROSAR/vHsm/vHsmKeyMapping/vHsmRandomInit/vHsmRandomInitKey.
  KeyElement    Contains values of DefinitionRef: /MICROSAR/vHsm/vHsmKeyMapping/vHsmRandomInit/vHsmRandomInitKeyElement.
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsm_RandomInitType, VHSM_CONST) vHsm_RandomInit[1];
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_SchedulableEntities
**********************************************************************************************************************/
/** 
  \var    vHsm_SchedulableEntities
  \details
  Element                      Description
  ScheduledChannelsEndIdx      the end index of the 1:n relation pointing to vHsm_ScheduledChannels
  ScheduledChannelsStartIdx    the start index of the 1:n relation pointing to vHsm_ScheduledChannels
*/ 
#define VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsm_SchedulableEntitiesType, VHSM_CONST) vHsm_SchedulableEntities[2];
#define VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_ScheduledChannels
**********************************************************************************************************************/
#define VHSM_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(vHsm_ScheduledChannelsType, VHSM_CONST) vHsm_ScheduledChannels[12];
#define VHSM_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_JobObjects
**********************************************************************************************************************/
/** 
  \var    vHsm_JobObjects
  \details
  Element             Description
  IpcChannel      
  JobRetVal       
  CancelFlag      
  IpcInstance     
  IpcMapping      
  ProcessKind     
  RedirectionFlags
  UsageRestriction
  ValidRequestFlag
  JobData         
  JobRequestId    
  JobRequestKind  
  LocalOutput     
  ProcessingType  
  State           
*/ 
#define VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(vHsm_JobObjectsType, VHSM_VAR_NOINIT) vHsm_JobObjects[12];
#define VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  vHsm_RestrictedChannels
**********************************************************************************************************************/
/** 
  \var    vHsm_RestrictedChannels
  \brief  Array with size of Channels to allow restrict channel usage from outside due to internal needs.
*/ 
#define VHSM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(vHsm_RestrictedChannelsType, VHSM_VAR_NOINIT) vHsm_RestrictedChannels[12];
#define VHSM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/



#define VHSM_IPC_PROTOCOL_INFO_MEMORY_SIZE                 (12u)

#if (VHSM_IPC_PROTOCOL_VERSION == 2u)
#define VHSM_IPC_RX_CHANNEL_ENTRY_MEMORY_SIZE              (96u)
#define VHSM_IPC_TX_CHANNEL_ENTRY_MEMORY_SIZE              (24u)
#else
#define VHSM_IPC_RX_CHANNEL_ENTRY_MEMORY_SIZE              (116u)
#define VHSM_IPC_TX_CHANNEL_ENTRY_MEMORY_SIZE              (56u)
#endif
#define VHSM_JOBREQUEST_HEADER_SIZE                        (12u)
#define VHSM_JOBRESPONSE_HEADER_SIZE                       (8u)
#define VHSM_IPC_GLOBALINFO_MEMORY_SIZE                    (44u)
#define VHSM_IPC_CHANNEL_HEADER_MEMORY_SIZE                (8u)

#define VHSM_IPC_MEMORY_SIZE                               \
    ((vHsm_GetChannelsOfIpc() * (VHSM_IPC_CHANNEL_HEADER_MEMORY_SIZE + VHSM_IPC_RX_CHANNEL_ENTRY_MEMORY_SIZE)) + \
     (vHsm_GetChannelsOfIpc() * (VHSM_IPC_CHANNEL_HEADER_MEMORY_SIZE + VHSM_IPC_TX_CHANNEL_ENTRY_MEMORY_SIZE)) + \
     VHSM_IPC_GLOBALINFO_MEMORY_SIZE +\
     VHSM_IPC_PROTOCOL_INFO_MEMORY_SIZE)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#define VHSM_START_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
 *  TaskMainFunction
 **********************************************************************************************************************/
/*!
 * \fn          vHsm_MainFunction_vHsmSchedulableEntities_HighPrio
 * \fn          vHsm_MainFunction_vHsmSchedulableEntities_Unmapped
 * \brief       Task main function for driver object processing. 
 * \pre         -
 * \reentrant   FALSE
 * \synchronous TRUE
 */
#define VHSM_STOP_SEC_CODE
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"    /* PRQA S 5087 */      /* MD_MSR_MemMap */
/*lint -restore */


/* User Config File Start */
#if (VHSM_DEV_ERROR_DETECT == STD_OFF)
# if (VHSM_DEV_ERROR_REPORT == STD_ON)
#  undef VHSM_DEV_ERROR_REPORT
#  define VHSM_DEV_ERROR_REPORT   STD_OFF
# endif
#endif
/* User Config File End */




#endif /* VHSM_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: vHsm_Cfg.h
 *********************************************************************************************************************/


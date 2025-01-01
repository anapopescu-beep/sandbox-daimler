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
 *            Module: Csm
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Csm_Cfg.h
 *   Generation Time: 2023-08-16 14:35:31
 *           Project: CBD2000614_Bm - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (CSM_CFG_H)
#define CSM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Csm_Types.h"
#include "Crypto_30_LibCv_Custom.h"
#include "Crypto_30_vHsm_Custom.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef CSM_USE_DUMMY_STATEMENT
#define CSM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CSM_DUMMY_STATEMENT
#define CSM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CSM_DUMMY_STATEMENT_CONST
#define CSM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CSM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CSM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CSM_ATOMIC_VARIABLE_ACCESS
#define CSM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CSM_PROCESSOR_TC322L
#define CSM_PROCESSOR_TC322L
#endif
#ifndef CSM_COMP_TASKING
#define CSM_COMP_TASKING
#endif
#ifndef CSM_GEN_GENERATOR_MSR
#define CSM_GEN_GENERATOR_MSR
#endif
#ifndef CSM_CPUTYPE_BITORDER_LSB2MSB
#define CSM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CSM_CONFIGURATION_VARIANT_PRECOMPILE
#define CSM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CSM_CONFIGURATION_VARIANT_LINKTIME
#define CSM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CSM_CONFIGURATION_VARIANT
#define CSM_CONFIGURATION_VARIANT CSM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CSM_POSTBUILD_VARIANT_SUPPORT
#define CSM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define CSM_ASYNC_PROCESSING                                                                        STD_OFF
/* Microsar Define Block for Boolean and Integers */
#define CSM_CALLBACKS                                                                               STD_OFF 
#define CSM_ASYM_PRIVATE_KEY_MAX_LENGTH                                                             32u 
#define CSM_ASYM_PUBLIC_KEY_MAX_LENGTH                                                              1024u 
#define CSM_SYM_KEY_MAX_LENGTH                                                                      16u 
#define CSM_USE_DEPRECATED                                                                          STD_OFF 
#define CSM_VERSION_INFO_API                                                                        STD_OFF 
#define CSM_CALLBACK_START_NOTIFICATION                                                             STD_OFF 
#define CSM_CANCELATION_DURING_PROCESSING                                                           STD_OFF 
#define CSM_JOBS                                                                                    STD_ON 
#define CSM_KEYS                                                                                    STD_ON 
#define CSM_QUEUES                                                                                  STD_ON 
#define CSM_CALLOUTS                                                                                STD_OFF 
#define CSM_IN_OUT_REDIRECTIONS                                                                     STD_OFF 

/* Symbolic Name Define Block */
#define CsmConf_CsmJob_CsmJob_DecryptionAes128NoneCbc                                               0u 
#define CsmConf_CsmJob_CsmJob_DecryptionAes128PkcsCbc                                               1u 
#define CsmConf_CsmJob_CsmJob_RandomGenerate                                                        2u 
#define CsmConf_CsmJob_CsmJob_Sha512                                                                3u 
#define CsmConf_CsmJob_CsmJob_SigAsymVer_Ed25519Sha512                                              4u 
#define CsmConf_CsmKey_CsmKey_Fbl_Decrypt_Aes128                                                    0u 
#define CsmConf_CsmKey_CsmKey_Fbl_Decrypt_Aes128_01                                                 1u 
#define CsmConf_CsmKey_CsmKey_Fbl_HashDummy                                                         2u 
#define CsmConf_CsmKey_CsmKey_Fbl_HashDummy_01                                                      3u 
#define CsmConf_CsmKey_CsmKey_Fbl_Rng_Fips186                                                       4u 
#define CsmConf_CsmKey_CsmKey_Fbl_Rng_Fips186_01                                                    5u 
#define CsmConf_CsmKey_CsmKey_Fbl_SecurityAccess_Ed25519                                            6u 
#define CsmConf_CsmKey_CsmKey_Fbl_Signature_Ed25519                                                 7u 
#define CsmConf_CsmKey_CsmKey_Fbl_Signature_Ed25519_01                                              8u 
#define CsmConf_CsmKey_CsmKey_KeyMCertificate_OSSL_X509_ECDSA_P384_CA_01                            9u 
#define CsmConf_CsmKey_CsmKey_KeyMCertificate_OSSL_X509_ECDSA_P384_IA_01                            10u 
#define CsmConf_CsmKey_CsmKey_KeyM_Cert_Intermediate                                                11u 
#define CsmConf_CsmKey_CsmKey_KeyM_Cert_Root                                                        12u 
#define CsmConf_CsmKey_CsmKey_KeyM_ECC_Intermediate                                                 13u 
#define CsmConf_CsmKey_CsmKey_KeyM_ECC_Root                                                         14u 
#define CsmConf_CsmKey_CsmKey_KeyM_SigVerifyKey_TrustModelBackend                                   15u 
#define CsmConf_CsmKey_CsmKey_KeyM_SigVerifyKey_TrustModelBackendPeer                               16u 
#define CsmConf_CsmKey_CsmKey_KeyM_SigVerifyKey_TrustModelEcuPeer                                   17u 
#define CsmConf_CsmKey_CsmKey_KeyM_SigVerifyKey_TrustModelIntermediate                              18u 
#define CsmConf_CsmKey_CsmKey_KeyM_SigVerifyKey_TrustModelIntermediatePeer                          19u 
#define CsmConf_CsmKey_CsmKey_KeyM_SigVerifyKey_TrustModelRoot                                      20u 
#define CsmConf_CsmKey_CsmKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx                21u 
#define CsmConf_CsmKey_CsmKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx                22u 
#define CsmConf_CsmKey_CsmKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx                23u 
#define CsmConf_CsmKey_CsmKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx             24u 
#define CsmConf_CsmKey_CsmKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx             25u 
#define CsmConf_CsmKey_CsmKey_SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer                             26u 
#define CsmConf_CsmKey_CsmKey_SSA_SecOC_Int_MacVerify_Ign_Stat                                      27u 
#define CsmConf_CsmKey_CsmKey_SSA_SecOC_Int_MacVerify_PN14_Master_Stat1                             28u 
#define CsmConf_CsmKey_CsmKey_SSA_SecOC_Int_MacVerify_PT4_PTCoor4                                   29u 
#define CsmConf_CsmKey_CsmKey_SSA_SecOC_Int_MacVerify_VehSpd_8                                      30u 
#define CsmConf_CsmKey_CsmKey_Ssa_AesRamKey                                                         31u 
#define CsmConf_CsmKey_CsmKey_Ssa_Authentication                                                    32u 
#define CsmConf_CsmKey_CsmKey_Ssa_BackendCert                                                       33u 
#define CsmConf_CsmKey_CsmKey_Ssa_PduKeysMac                                                        34u 
#define CsmConf_CsmKey_CsmKey_Ssa_RandomSeed                                                        35u 
#define CsmConf_CsmKey_CsmKey_Ssa_RealTime                                                          36u 
#define CsmConf_CsmKey_CsmKey_Ssa_RootCert                                                          37u 
#define CsmConf_CsmKey_CsmKey_Ssa_SecurityAccessPublicKey                                           38u 
#define CsmConf_CsmKey_CsmKey_Ssa_SharedSecretExchangeKey                                           39u 
#define CsmConf_CsmKey_CsmKey_Ssa_SharedSecretHash                                                  40u 
#define CsmConf_CsmKey_CsmKey_Ssa_SignatureRamKey                                                   41u 
#define CsmConf_CsmKey_CsmKey_Ssa_SignatureRamKey_replacementAuthority                              42u 
#define CsmConf_CsmKey_CsmKey_Ssa_TickCount                                                         43u 
#define CsmConf_CsmKey_CsmKey_Ssa_TrustModelBackendCert_inHSM                                       44u 
#define CsmConf_CsmKey_CsmKey_Ssa_TrustModelEcuCert_inHSM                                           45u 
#define CsmConf_CsmKey_CsmKey_Ssa_TrustModelEcuPublicCsr_StagingKey                                 46u 
#define CsmConf_CsmKey_CsmKey_Ssa_TrustModelEcuPublic_LiveKey                                       47u 
#define CsmConf_CsmKey_CsmKey_Ssa_TrustModelIntermediateCert_inHSM                                  48u 
#define CsmConf_CsmKey_CsmKey_Ssa_TrustModelPrivateEcuUnique_StagingKey                             49u 
#define CsmConf_CsmKey_CsmKey_Ssa_TrustModelPrivateEcu_LiveKey                                      50u 
#define CsmConf_CsmKey_CsmKey_Ssa_TrustModelRootCert_inHSM                                          51u 
#define CsmConf_CsmKey_CsmKey_Ssa_TrustModel_Ecu_CsrPrivateKey                                      52u 
#define CsmConf_CsmKey_CsmKey_Ssa_TrustModel_Ecu_CsrPublicKey                                       53u 
#define CsmConf_CsmKey_CsmKey_Ssa_VIN                                                               54u 
#define CsmConf_CsmKey_CsmKey_vHSM_Custom_HSM_Version                                               55u 
#define CsmConf_CsmKey_CsmKey_vHsm_Custom                                                           56u 
#define CsmConf_CsmKey_CsmKey_vHsm_FirmwareUpdate_Signature                                         57u 
#define CsmConf_CsmKey_CsmKey_vHsm_Hardware                                                         58u 
#define CsmConf_CsmKey_CsmKey_vHsm_Info                                                             59u 
#define CsmConf_CsmKey_CsmKey_vHsm_Info_01                                                          60u 
#define CsmConf_CsmKey_CsmKey_vHsm_Log                                                              61u 
#define CsmConf_CsmKey_CsmKey_vHsm_RomKey0                                                          62u 
#define CsmConf_CsmKey_CsmKey_vHsm_TRNG                                                             63u 

#ifndef CSM_DEV_ERROR_DETECT
#define CSM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef CSM_DEV_ERROR_REPORT
#define CSM_DEV_ERROR_REPORT STD_ON
#endif
#define CSM_EXIST_AEADDECRYPT                                                                       STD_OFF
#define CSM_EXIST_AEADENCRYPT                                                                       STD_OFF
#define CSM_EXIST_DECRYPT                                                                           STD_ON
#define CSM_EXIST_ENCRYPT                                                                           STD_OFF
#define CSM_EXIST_HASH                                                                              STD_ON
#define CSM_EXIST_MACGENERATE                                                                       STD_OFF
#define CSM_EXIST_MACVERIFY                                                                         STD_OFF
#define CSM_EXIST_RANDOMGENERATE                                                                    STD_ON
#define CSM_EXIST_SECURECOUNTER                                                                     STD_OFF
#define CSM_EXIST_SIGNATUREGENERATE                                                                 STD_OFF
#define CSM_EXIST_SIGNATUREVERIFY                                                                   STD_ON
#define CSM_EXIST_JOBKEYSETVALID                                                                    STD_OFF
#define CSM_EXIST_JOBKEYEXCHANGECALCPUBVAL                                                          STD_OFF
#define CSM_EXIST_JOBKEYEXCHANGECALCSECRET                                                          STD_OFF
#define CSM_EXIST_JOBKEYDERIVE                                                                      STD_OFF
#define CSM_EXIST_JOBRANDOMSEED                                                                     STD_OFF
#define CSM_EXIST_JOBKEYGENERATE                                                                    STD_OFF
#define CSM_EXIST_JOBCERTIFICATEPARSE                                                               STD_OFF
#define CSM_EXIST_JOBCERTIFICATEVERIFY                                                              STD_OFF
#define CSM_RTE_PORTS                                                                               STD_OFF
#define CSM_INVALID_KEYID                                                                           0xFFFFFFFFUL


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CsmPCDataSwitches  Csm Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CSM_ASYMPRIVATEKEYMAXLENGTHOFGENERAL                                                        STD_ON
#define CSM_ASYMPUBLICKEYMAXLENGTHOFGENERAL                                                         STD_ON
#define CSM_BSWCALLBACKS                                                                            STD_OFF  /**< Deactivateable: 'Csm_BswCallbacks' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CSM_CALLBACKFUNC43OFBSWCALLBACKS                                                            STD_OFF  /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc43' Reason: 'No Callback according to ASR 4.3 is configured' */
#define CSM_CALLBACKFUNC44OFBSWCALLBACKS                                                            STD_OFF  /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc44' Reason: 'No Callback according to ASR 4.4 is configured' */
#define CSM_CALLBACKFUNC45OFBSWCALLBACKS                                                            STD_OFF  /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc45' Reason: 'No Callback according to ASR 4.5 is configured' */
#define CSM_CALLBACKSTARTNOTIFICATIONOFGENERAL                                                      STD_ON
#define CSM_CALLOUT                                                                                 STD_OFF  /**< Deactivateable: 'Csm_Callout' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CSM_POSTJOBCALLOUTFUNCOFCALLOUT                                                             STD_OFF  /**< Deactivateable: 'Csm_Callout.PostJobCalloutFunc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CSM_PREJOBCALLOUTFUNCOFCALLOUT                                                              STD_OFF  /**< Deactivateable: 'Csm_Callout.PreJobCalloutFunc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CSM_CALLOUTINFO                                                                             STD_OFF  /**< Deactivateable: 'Csm_CalloutInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CSM_CALLOUTIDXOFCALLOUTINFO                                                                 STD_OFF  /**< Deactivateable: 'Csm_CalloutInfo.CalloutIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CSM_JOBTABLEIDXOFCALLOUTINFO                                                                STD_OFF  /**< Deactivateable: 'Csm_CalloutInfo.JobTableIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CSM_CALLOUTSTATE                                                                            STD_OFF  /**< Deactivateable: 'Csm_CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define CSM_CALLOUTSTATEOFCALLOUTSTATE                                                              STD_OFF  /**< Deactivateable: 'Csm_CalloutState.CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define CSM_CANCELATIONDURINGPROCESSINGOFGENERAL                                                    STD_ON
#define CSM_EXPECTEDCOMPATIBILITYVERSION                                                            STD_OFF  /**< Deactivateable: 'Csm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CSM_FINALMAGICNUMBER                                                                        STD_OFF  /**< Deactivateable: 'Csm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CSM_GENERATORCOMPATIBILITYVERSION                                                           STD_OFF  /**< Deactivateable: 'Csm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CSM_INOUTJOBREDIRECTIONTABLE                                                                STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable' Reason: 'Not enabled for any job' */
#define CSM_INPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                             STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyElementId' Reason: 'Not enabled for any job' */
#define CSM_INPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                                    STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyId' Reason: 'Not enabled for any job' */
#define CSM_OUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                            STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyElementId' Reason: 'Not enabled for any job' */
#define CSM_OUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                                   STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyId' Reason: 'Not enabled for any job' */
#define CSM_REDIRECTIONCONFIGVALUEOFINOUTJOBREDIRECTIONTABLE                                        STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.RedirectionConfigValue' Reason: 'Not enabled for any job' */
#define CSM_SECONDARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                    STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define CSM_SECONDARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                           STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyId' Reason: 'Not enabled for any job' */
#define CSM_SECONDARYOUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                   STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyElementId' Reason: 'Not enabled for any job' */
#define CSM_SECONDARYOUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                          STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyId' Reason: 'Not enabled for any job' */
#define CSM_TERTIARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                     STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define CSM_TERTIARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                            STD_OFF  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyId' Reason: 'Not enabled for any job' */
#define CSM_INOUTREDIRECTION                                                                        STD_OFF  /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CSM_INOUTREDIRECTIONMAP                                                                     STD_OFF  /**< Deactivateable: 'Csm_InOutRedirectionMap' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define CSM_INOUTJOBREDIRECTIONTABLEIDXOFINOUTREDIRECTIONMAP                                        STD_OFF  /**< Deactivateable: 'Csm_InOutRedirectionMap.InOutJobRedirectionTableIdx' Reason: 'Not enabled for any job' */
#define CSM_INVALIDHNDOFINOUTREDIRECTIONMAP                                                         STD_OFF  /**< Deactivateable: 'Csm_InOutRedirectionMap.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define CSM_INITDATAHASHCODE                                                                        STD_OFF  /**< Deactivateable: 'Csm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CSM_JOB                                                                                     STD_ON
#define CSM_JOBINFO                                                                                 STD_ON
#define CSM_JOBPRIMITIVEINFO                                                                        STD_ON
#define CSM_JOBSTATE                                                                                STD_ON
#define CSM_JOBTABLE                                                                                STD_ON
#define CSM_ASYNCHRONOUSOFJOBTABLE                                                                  STD_ON
#define CSM_BSWCALLBACKSIDXOFJOBTABLE                                                               STD_OFF  /**< Deactivateable: 'Csm_JobTable.BswCallbacksIdx' Reason: 'the optional indirection is deactivated because BswCallbacksUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CSM_BSWCALLBACKSUSEDOFJOBTABLE                                                              STD_OFF  /**< Deactivateable: 'Csm_JobTable.BswCallbacksUsed' Reason: 'the optional indirection is deactivated because BswCallbacksUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CSM_CALLOUTINFOIDXOFJOBTABLE                                                                STD_OFF  /**< Deactivateable: 'Csm_JobTable.CalloutInfoIdx' Reason: 'the optional indirection is deactivated because CalloutInfoUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CSM_CALLOUTINFOUSEDOFJOBTABLE                                                               STD_OFF  /**< Deactivateable: 'Csm_JobTable.CalloutInfoUsed' Reason: 'the optional indirection is deactivated because CalloutInfoUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CSM_CSMKEYIDIDXOFJOBTABLE                                                                   STD_ON
#define CSM_INOUTREDIRECTIONMAPIDXOFJOBTABLE                                                        STD_OFF  /**< Deactivateable: 'Csm_JobTable.InOutRedirectionMapIdx' Reason: 'the optional indirection is deactivated because InOutRedirectionMapUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CSM_INOUTREDIRECTIONMAPUSEDOFJOBTABLE                                                       STD_OFF  /**< Deactivateable: 'Csm_JobTable.InOutRedirectionMapUsed' Reason: 'the optional indirection is deactivated because InOutRedirectionMapUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CSM_JOBIDXOFJOBTABLE                                                                        STD_OFF  /**< Deactivateable: 'Csm_JobTable.JobIdx' Reason: 'the optional indirection is deactivated because JobUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CSM_JOBINFOIDXOFJOBTABLE                                                                    STD_ON
#define CSM_JOBPRIMITIVEINFOIDXOFJOBTABLE                                                           STD_ON
#define CSM_JOBUSEDOFJOBTABLE                                                                       STD_OFF  /**< Deactivateable: 'Csm_JobTable.JobUsed' Reason: 'the optional indirection is deactivated because JobUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define CSM_MASKEDBITSOFJOBTABLE                                                                    STD_ON
#define CSM_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE                                           STD_ON
#define CSM_PRIORITYOFJOBTABLE                                                                      STD_ON
#define CSM_QUEUEREFIDXOFJOBTABLE                                                                   STD_ON
#define CSM_RTECALLBACKIDXOFJOBTABLE                                                                STD_OFF  /**< Deactivateable: 'Csm_JobTable.RteCallbackIdx' Reason: 'No RTE Callback is configured' */
#define CSM_RTECALLBACKUSEDOFJOBTABLE                                                               STD_OFF  /**< Deactivateable: 'Csm_JobTable.RteCallbackUsed' Reason: 'No RTE Callback is configured' */
#define CSM_JOBTOOBJMAP                                                                             STD_ON
#define CSM_KEY                                                                                     STD_ON
#define CSM_CRYIFKEYIDOFKEY                                                                         STD_ON
#define CSM_MAINFUNCTIONPERIODOFGENERAL                                                             STD_ON
#define CSM_PRIMITIVEINFO                                                                           STD_ON
#define CSM_QUEUE                                                                                   STD_ON
#define CSM_QUEUEINFO                                                                               STD_ON
#define CSM_CHANNELIDOFQUEUEINFO                                                                    STD_ON
#define CSM_JOBOBJSYNCHRONOUSIDXOFQUEUEINFO                                                         STD_ON
#define CSM_JOBOBJSYNCHRONOUSUSEDOFQUEUEINFO                                                        STD_ON
#define CSM_JOBPOOLENDIDXOFQUEUEINFO                                                                STD_ON
#define CSM_JOBPOOLSTARTIDXOFQUEUEINFO                                                              STD_ON
#define CSM_JOBPOOLUSEDOFQUEUEINFO                                                                  STD_ON
#define CSM_JOBSHARINGOFQUEUEINFO                                                                   STD_ON
#define CSM_MASKEDBITSOFQUEUEINFO                                                                   STD_ON
#define CSM_QUEUEENDIDXOFQUEUEINFO                                                                  STD_ON
#define CSM_QUEUESTARTIDXOFQUEUEINFO                                                                STD_ON
#define CSM_TRIGGERASYNCHJOBSINCALLBACKOFQUEUEINFO                                                  STD_OFF  /**< Deactivateable: 'Csm_QueueInfo.TriggerAsynchJobsInCallback' Reason: 'Not enabled for any of the queues.' */
#define CSM_QUEUESTATE                                                                              STD_ON
#define CSM_LOCKOFQUEUESTATE                                                                        STD_ON
#define CSM_QUEUEIDXOFQUEUESTATE                                                                    STD_ON
#define CSM_RETRIGGERINGOFQUEUESTATE                                                                STD_OFF  /**< Deactivateable: 'Csm_QueueState.Retriggering' Reason: 'Not enabled for any of the queues.' */
#define CSM_RTECALLBACK                                                                             STD_OFF  /**< Deactivateable: 'Csm_RteCallback' Reason: 'No RTE Callback is configured' */
#define CSM_RTECALLBACKOCCURRED                                                                     STD_OFF  /**< Deactivateable: 'Csm_RteCallbackOccurred' Reason: 'No RTE Callback is configured' */
#define CSM_RTERESULT                                                                               STD_OFF  /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
#define CSM_SIZEOFJOB                                                                               STD_ON
#define CSM_SIZEOFJOBINFO                                                                           STD_ON
#define CSM_SIZEOFJOBPRIMITIVEINFO                                                                  STD_ON
#define CSM_SIZEOFJOBSTATE                                                                          STD_ON
#define CSM_SIZEOFJOBTABLE                                                                          STD_ON
#define CSM_SIZEOFJOBTOOBJMAP                                                                       STD_ON
#define CSM_SIZEOFKEY                                                                               STD_ON
#define CSM_SIZEOFPRIMITIVEINFO                                                                     STD_ON
#define CSM_SIZEOFQUEUE                                                                             STD_ON
#define CSM_SIZEOFQUEUEINFO                                                                         STD_ON
#define CSM_SIZEOFQUEUESTATE                                                                        STD_ON
#define CSM_SYMKEYMAXLENGTHOFGENERAL                                                                STD_ON
#define CSM_USEDEPRECATEDOFGENERAL                                                                  STD_ON
#define CSM_VERSIONINFOAPIOFGENERAL                                                                 STD_ON
#define CSM_PCCONFIG                                                                                STD_ON
#define CSM_ASYMPRIVATEKEYMAXLENGTHOFGENERALOFPCCONFIG                                              STD_ON
#define CSM_ASYMPUBLICKEYMAXLENGTHOFGENERALOFPCCONFIG                                               STD_ON
#define CSM_CALLBACKSTARTNOTIFICATIONOFGENERALOFPCCONFIG                                            STD_ON
#define CSM_CANCELATIONDURINGPROCESSINGOFGENERALOFPCCONFIG                                          STD_ON
#define CSM_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                                  STD_OFF  /**< Deactivateable: 'Csm_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CSM_FINALMAGICNUMBEROFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Csm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CSM_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                                 STD_OFF  /**< Deactivateable: 'Csm_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CSM_INITDATAHASHCODEOFPCCONFIG                                                              STD_OFF  /**< Deactivateable: 'Csm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CSM_JOBINFOOFPCCONFIG                                                                       STD_ON
#define CSM_JOBOFPCCONFIG                                                                           STD_ON
#define CSM_JOBPRIMITIVEINFOOFPCCONFIG                                                              STD_ON
#define CSM_JOBSTATEOFPCCONFIG                                                                      STD_ON
#define CSM_JOBTABLEOFPCCONFIG                                                                      STD_ON
#define CSM_JOBTOOBJMAPOFPCCONFIG                                                                   STD_ON
#define CSM_KEYOFPCCONFIG                                                                           STD_ON
#define CSM_MAINFUNCTIONPERIODOFGENERALOFPCCONFIG                                                   STD_ON
#define CSM_PRIMITIVEINFOOFPCCONFIG                                                                 STD_ON
#define CSM_QUEUEINFOOFPCCONFIG                                                                     STD_ON
#define CSM_QUEUEOFPCCONFIG                                                                         STD_ON
#define CSM_QUEUESTATEOFPCCONFIG                                                                    STD_ON
#define CSM_SIZEOFJOBINFOOFPCCONFIG                                                                 STD_ON
#define CSM_SIZEOFJOBOFPCCONFIG                                                                     STD_ON
#define CSM_SIZEOFJOBPRIMITIVEINFOOFPCCONFIG                                                        STD_ON
#define CSM_SIZEOFJOBSTATEOFPCCONFIG                                                                STD_ON
#define CSM_SIZEOFJOBTABLEOFPCCONFIG                                                                STD_ON
#define CSM_SIZEOFJOBTOOBJMAPOFPCCONFIG                                                             STD_ON
#define CSM_SIZEOFKEYOFPCCONFIG                                                                     STD_ON
#define CSM_SIZEOFPRIMITIVEINFOOFPCCONFIG                                                           STD_ON
#define CSM_SIZEOFQUEUEINFOOFPCCONFIG                                                               STD_ON
#define CSM_SIZEOFQUEUEOFPCCONFIG                                                                   STD_ON
#define CSM_SIZEOFQUEUESTATEOFPCCONFIG                                                              STD_ON
#define CSM_SYMKEYMAXLENGTHOFGENERALOFPCCONFIG                                                      STD_ON
#define CSM_USEDEPRECATEDOFGENERALOFPCCONFIG                                                        STD_ON
#define CSM_VERSIONINFOAPIOFGENERALOFPCCONFIG                                                       STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCMinNumericValueDefines  Csm Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CSM_MIN_CALLOUTSTATEOFCALLOUTSTATE                                                          0u
#define CSM_MIN_JOBSTATE                                                                            0u
#define CSM_MIN_LOCKOFQUEUESTATE                                                                    0u
#define CSM_MIN_QUEUEIDXOFQUEUESTATE                                                                0u
#define CSM_MIN_RETRIGGERINGOFQUEUESTATE                                                            0u
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCMaxNumericValueDefines  Csm Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CSM_MAX_CALLOUTSTATEOFCALLOUTSTATE                                                          255u
#define CSM_MAX_JOBSTATE                                                                            255u
#define CSM_MAX_LOCKOFQUEUESTATE                                                                    65535u
#define CSM_MAX_QUEUEIDXOFQUEUESTATE                                                                255u
#define CSM_MAX_RETRIGGERINGOFQUEUESTATE                                                            255u
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCNoReferenceDefines  Csm No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CSM_NO_BSWCALLBACKSIDXOFJOBTABLE                                                            255u
#define CSM_NO_CALLOUTINFOIDXOFJOBTABLE                                                             255u
#define CSM_NO_INOUTREDIRECTIONMAPIDXOFJOBTABLE                                                     255u
#define CSM_NO_JOBIDXOFJOBTABLE                                                                     255u
#define CSM_NO_RTECALLBACKIDXOFJOBTABLE                                                             255u
#define CSM_NO_JOBOBJSYNCHRONOUSIDXOFQUEUEINFO                                                      255u
#define CSM_NO_JOBPOOLENDIDXOFQUEUEINFO                                                             255u
#define CSM_NO_JOBPOOLSTARTIDXOFQUEUEINFO                                                           255u
#define CSM_NO_EXPECTEDCOMPATIBILITYVERSION                                                         65535u
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCMaskedBitDefines  Csm Masked Bit Defines (PRE_COMPILE)
  \brief  These defines are masks to extract packed boolean data.
  \{
*/ 
#define CSM_ASYNCHRONOUSOFJOBTABLE_MASK                                                             0x02u
#define CSM_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE_MASK                                      0x01u
#define CSM_JOBOBJSYNCHRONOUSUSEDOFQUEUEINFO_MASK                                                   0x04u
#define CSM_JOBPOOLUSEDOFQUEUEINFO_MASK                                                             0x02u
#define CSM_JOBSHARINGOFQUEUEINFO_MASK                                                              0x01u
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCIsReducedToDefineDefines  Csm Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CSM_ISDEF_CALLBACKFUNC43OFBSWCALLBACKS                                                      STD_OFF
#define CSM_ISDEF_CALLBACKFUNC44OFBSWCALLBACKS                                                      STD_OFF
#define CSM_ISDEF_CALLBACKFUNC45OFBSWCALLBACKS                                                      STD_OFF
#define CSM_ISDEF_POSTJOBCALLOUTFUNCOFCALLOUT                                                       STD_OFF
#define CSM_ISDEF_PREJOBCALLOUTFUNCOFCALLOUT                                                        STD_OFF
#define CSM_ISDEF_CALLOUTIDXOFCALLOUTINFO                                                           STD_OFF
#define CSM_ISDEF_JOBTABLEIDXOFCALLOUTINFO                                                          STD_OFF
#define CSM_ISDEF_INPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                       STD_OFF
#define CSM_ISDEF_INPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                              STD_OFF
#define CSM_ISDEF_OUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                      STD_OFF
#define CSM_ISDEF_OUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                             STD_OFF
#define CSM_ISDEF_REDIRECTIONCONFIGVALUEOFINOUTJOBREDIRECTIONTABLE                                  STD_OFF
#define CSM_ISDEF_SECONDARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                              STD_OFF
#define CSM_ISDEF_SECONDARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                     STD_OFF
#define CSM_ISDEF_SECONDARYOUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                             STD_OFF
#define CSM_ISDEF_SECONDARYOUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                    STD_OFF
#define CSM_ISDEF_TERTIARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                               STD_OFF
#define CSM_ISDEF_TERTIARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                      STD_OFF
#define CSM_ISDEF_INOUTJOBREDIRECTIONTABLEIDXOFINOUTREDIRECTIONMAP                                  STD_OFF
#define CSM_ISDEF_INVALIDHNDOFINOUTREDIRECTIONMAP                                                   STD_OFF
#define CSM_ISDEF_JOBINFO                                                                           STD_OFF
#define CSM_ISDEF_JOBPRIMITIVEINFO                                                                  STD_OFF
#define CSM_ISDEF_ASYNCHRONOUSOFJOBTABLE                                                            STD_OFF
#define CSM_ISDEF_BSWCALLBACKSIDXOFJOBTABLE                                                         STD_OFF
#define CSM_ISDEF_BSWCALLBACKSUSEDOFJOBTABLE                                                        STD_OFF
#define CSM_ISDEF_CALLOUTINFOIDXOFJOBTABLE                                                          STD_OFF
#define CSM_ISDEF_CALLOUTINFOUSEDOFJOBTABLE                                                         STD_OFF
#define CSM_ISDEF_CSMKEYIDIDXOFJOBTABLE                                                             STD_OFF
#define CSM_ISDEF_INOUTREDIRECTIONMAPIDXOFJOBTABLE                                                  STD_OFF
#define CSM_ISDEF_INOUTREDIRECTIONMAPUSEDOFJOBTABLE                                                 STD_OFF
#define CSM_ISDEF_JOBIDXOFJOBTABLE                                                                  STD_OFF
#define CSM_ISDEF_JOBINFOIDXOFJOBTABLE                                                              STD_OFF
#define CSM_ISDEF_JOBPRIMITIVEINFOIDXOFJOBTABLE                                                     STD_OFF
#define CSM_ISDEF_JOBUSEDOFJOBTABLE                                                                 STD_OFF
#define CSM_ISDEF_MASKEDBITSOFJOBTABLE                                                              STD_OFF
#define CSM_ISDEF_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE                                     STD_OFF
#define CSM_ISDEF_PRIORITYOFJOBTABLE                                                                STD_OFF
#define CSM_ISDEF_QUEUEREFIDXOFJOBTABLE                                                             STD_OFF
#define CSM_ISDEF_RTECALLBACKIDXOFJOBTABLE                                                          STD_OFF
#define CSM_ISDEF_RTECALLBACKUSEDOFJOBTABLE                                                         STD_OFF
#define CSM_ISDEF_CRYIFKEYIDOFKEY                                                                   STD_OFF
#define CSM_ISDEF_PRIMITIVEINFO                                                                     STD_OFF
#define CSM_ISDEF_CHANNELIDOFQUEUEINFO                                                              STD_OFF
#define CSM_ISDEF_JOBOBJSYNCHRONOUSIDXOFQUEUEINFO                                                   STD_OFF
#define CSM_ISDEF_JOBOBJSYNCHRONOUSUSEDOFQUEUEINFO                                                  STD_OFF
#define CSM_ISDEF_JOBPOOLENDIDXOFQUEUEINFO                                                          STD_OFF
#define CSM_ISDEF_JOBPOOLSTARTIDXOFQUEUEINFO                                                        STD_OFF
#define CSM_ISDEF_JOBPOOLUSEDOFQUEUEINFO                                                            STD_OFF
#define CSM_ISDEF_JOBSHARINGOFQUEUEINFO                                                             STD_OFF
#define CSM_ISDEF_MASKEDBITSOFQUEUEINFO                                                             STD_OFF
#define CSM_ISDEF_QUEUEENDIDXOFQUEUEINFO                                                            STD_OFF
#define CSM_ISDEF_QUEUESTARTIDXOFQUEUEINFO                                                          STD_OFF
#define CSM_ISDEF_TRIGGERASYNCHJOBSINCALLBACKOFQUEUEINFO                                            STD_OFF
#define CSM_ISDEF_RTECALLBACK                                                                       STD_OFF
#define CSM_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                            STD_OFF
#define CSM_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                                        STD_OFF
#define CSM_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                           STD_OFF
#define CSM_ISDEF_INITDATAHASHCODEOFPCCONFIG                                                        STD_OFF
#define CSM_ISDEF_JOBINFOOFPCCONFIG                                                                 STD_ON
#define CSM_ISDEF_JOBOFPCCONFIG                                                                     STD_ON
#define CSM_ISDEF_JOBPRIMITIVEINFOOFPCCONFIG                                                        STD_ON
#define CSM_ISDEF_JOBSTATEOFPCCONFIG                                                                STD_ON
#define CSM_ISDEF_JOBTABLEOFPCCONFIG                                                                STD_ON
#define CSM_ISDEF_JOBTOOBJMAPOFPCCONFIG                                                             STD_ON
#define CSM_ISDEF_KEYOFPCCONFIG                                                                     STD_ON
#define CSM_ISDEF_PRIMITIVEINFOOFPCCONFIG                                                           STD_ON
#define CSM_ISDEF_QUEUEINFOOFPCCONFIG                                                               STD_ON
#define CSM_ISDEF_QUEUEOFPCCONFIG                                                                   STD_ON
#define CSM_ISDEF_QUEUESTATEOFPCCONFIG                                                              STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCEqualsAlwaysToDefines  Csm Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CSM_EQ2_CALLBACKFUNC43OFBSWCALLBACKS                                                        
#define CSM_EQ2_CALLBACKFUNC44OFBSWCALLBACKS                                                        
#define CSM_EQ2_CALLBACKFUNC45OFBSWCALLBACKS                                                        
#define CSM_EQ2_POSTJOBCALLOUTFUNCOFCALLOUT                                                         
#define CSM_EQ2_PREJOBCALLOUTFUNCOFCALLOUT                                                          
#define CSM_EQ2_CALLOUTIDXOFCALLOUTINFO                                                             
#define CSM_EQ2_JOBTABLEIDXOFCALLOUTINFO                                                            
#define CSM_EQ2_INPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                         
#define CSM_EQ2_INPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                                
#define CSM_EQ2_OUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                        
#define CSM_EQ2_OUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                               
#define CSM_EQ2_REDIRECTIONCONFIGVALUEOFINOUTJOBREDIRECTIONTABLE                                    
#define CSM_EQ2_SECONDARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                
#define CSM_EQ2_SECONDARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                       
#define CSM_EQ2_SECONDARYOUTPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                               
#define CSM_EQ2_SECONDARYOUTPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                      
#define CSM_EQ2_TERTIARYINPUTKEYELEMENTIDOFINOUTJOBREDIRECTIONTABLE                                 
#define CSM_EQ2_TERTIARYINPUTKEYIDOFINOUTJOBREDIRECTIONTABLE                                        
#define CSM_EQ2_INOUTJOBREDIRECTIONTABLEIDXOFINOUTREDIRECTIONMAP                                    
#define CSM_EQ2_INVALIDHNDOFINOUTREDIRECTIONMAP                                                     
#define CSM_EQ2_JOBINFO                                                                             
#define CSM_EQ2_JOBPRIMITIVEINFO                                                                    
#define CSM_EQ2_ASYNCHRONOUSOFJOBTABLE                                                              
#define CSM_EQ2_BSWCALLBACKSIDXOFJOBTABLE                                                           
#define CSM_EQ2_BSWCALLBACKSUSEDOFJOBTABLE                                                          
#define CSM_EQ2_CALLOUTINFOIDXOFJOBTABLE                                                            
#define CSM_EQ2_CALLOUTINFOUSEDOFJOBTABLE                                                           
#define CSM_EQ2_CSMKEYIDIDXOFJOBTABLE                                                               
#define CSM_EQ2_INOUTREDIRECTIONMAPIDXOFJOBTABLE                                                    
#define CSM_EQ2_INOUTREDIRECTIONMAPUSEDOFJOBTABLE                                                   
#define CSM_EQ2_JOBIDXOFJOBTABLE                                                                    
#define CSM_EQ2_JOBINFOIDXOFJOBTABLE                                                                
#define CSM_EQ2_JOBPRIMITIVEINFOIDXOFJOBTABLE                                                       
#define CSM_EQ2_JOBUSEDOFJOBTABLE                                                                   
#define CSM_EQ2_MASKEDBITSOFJOBTABLE                                                                
#define CSM_EQ2_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE                                       
#define CSM_EQ2_PRIORITYOFJOBTABLE                                                                  
#define CSM_EQ2_QUEUEREFIDXOFJOBTABLE                                                               
#define CSM_EQ2_RTECALLBACKIDXOFJOBTABLE                                                            
#define CSM_EQ2_RTECALLBACKUSEDOFJOBTABLE                                                           
#define CSM_EQ2_CRYIFKEYIDOFKEY                                                                     
#define CSM_EQ2_PRIMITIVEINFO                                                                       
#define CSM_EQ2_CHANNELIDOFQUEUEINFO                                                                
#define CSM_EQ2_JOBOBJSYNCHRONOUSIDXOFQUEUEINFO                                                     
#define CSM_EQ2_JOBOBJSYNCHRONOUSUSEDOFQUEUEINFO                                                    
#define CSM_EQ2_JOBPOOLENDIDXOFQUEUEINFO                                                            
#define CSM_EQ2_JOBPOOLSTARTIDXOFQUEUEINFO                                                          
#define CSM_EQ2_JOBPOOLUSEDOFQUEUEINFO                                                              
#define CSM_EQ2_JOBSHARINGOFQUEUEINFO                                                               
#define CSM_EQ2_MASKEDBITSOFQUEUEINFO                                                               
#define CSM_EQ2_QUEUEENDIDXOFQUEUEINFO                                                              
#define CSM_EQ2_QUEUESTARTIDXOFQUEUEINFO                                                            
#define CSM_EQ2_TRIGGERASYNCHJOBSINCALLBACKOFQUEUEINFO                                              
#define CSM_EQ2_RTECALLBACK                                                                         
#define CSM_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                              
#define CSM_EQ2_FINALMAGICNUMBEROFPCCONFIG                                                          
#define CSM_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                             
#define CSM_EQ2_INITDATAHASHCODEOFPCCONFIG                                                          
#define CSM_EQ2_JOBINFOOFPCCONFIG                                                                   Csm_JobInfo
#define CSM_EQ2_JOBOFPCCONFIG                                                                       Csm_Job
#define CSM_EQ2_JOBPRIMITIVEINFOOFPCCONFIG                                                          Csm_JobPrimitiveInfo
#define CSM_EQ2_JOBSTATEOFPCCONFIG                                                                  Csm_JobState
#define CSM_EQ2_JOBTABLEOFPCCONFIG                                                                  Csm_JobTable
#define CSM_EQ2_JOBTOOBJMAPOFPCCONFIG                                                               Csm_JobToObjMap
#define CSM_EQ2_KEYOFPCCONFIG                                                                       Csm_Key
#define CSM_EQ2_PRIMITIVEINFOOFPCCONFIG                                                             Csm_PrimitiveInfo
#define CSM_EQ2_QUEUEINFOOFPCCONFIG                                                                 Csm_QueueInfo
#define CSM_EQ2_QUEUEOFPCCONFIG                                                                     Csm_Queue.raw
#define CSM_EQ2_QUEUESTATEOFPCCONFIG                                                                Csm_QueueState
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCSymbolicInitializationPointers  Csm Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Csm_Config_Ptr                                                                              NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Csm' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCInitializationSymbols  Csm Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Csm_Config                                                                                  NULL_PTR  /**< symbolic identifier which could be used to initialize 'Csm */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGeneral  Csm General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CSM_CHECK_INIT_POINTER                                                                      STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CSM_FINAL_MAGIC_NUMBER                                                                      0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Csm */
#define CSM_INDIVIDUAL_POSTBUILD                                                                    STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Csm' is not configured to be postbuild capable. */
#define CSM_INIT_DATA                                                                               CSM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CSM_INIT_DATA_HASH_CODE                                                                     842809845  /**< the precompile constant to validate the initialization structure at initialization time of Csm with a hashcode. The seed value is '0xFF1Eu' */
#define CSM_USE_ECUM_BSW_ERROR_HOOK                                                                 STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CSM_USE_INIT_POINTER                                                                        STD_OFF  /**< STD_ON if the init pointer Csm shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CsmPBDataSwitches  Csm Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CSM_PBCONFIG                                                                                STD_OFF  /**< Deactivateable: 'Csm_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CSM_LTCONFIGIDXOFPBCONFIG                                                                   STD_OFF  /**< Deactivateable: 'Csm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CSM_PCCONFIGIDXOFPBCONFIG                                                                   STD_OFF  /**< Deactivateable: 'Csm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPBIsReducedToDefineDefines  Csm Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CSM_ISDEF_LTCONFIGIDXOFPBCONFIG                                                             STD_OFF
#define CSM_ISDEF_PCCONFIGIDXOFPBCONFIG                                                             STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  CsmPBEqualsAlwaysToDefines  Csm Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CSM_EQ2_LTCONFIGIDXOFPBCONFIG                                                               
#define CSM_EQ2_PCCONFIGIDXOFPBCONFIG                                                               
/** 
  \}
*/ 



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
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
  \defgroup  CsmPCGetRootDataMacros  Csm Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Csm_GetExpectedCompatibilityVersionOfPCConfig()                                               /**< Deactivateable: 'Csm_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_GetFinalMagicNumberOfPCConfig()                                                           /**< Deactivateable: 'Csm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_GetGeneratorCompatibilityVersionOfPCConfig()                                              /**< Deactivateable: 'Csm_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_GetInitDataHashCodeOfPCConfig()                                                           /**< Deactivateable: 'Csm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetConstantDuplicatedRootDataMacros  Csm Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Csm_GetAsymPrivateKeyMaxLengthOfGeneralOfPCConfig()                                         32u
#define Csm_GetAsymPublicKeyMaxLengthOfGeneralOfPCConfig()                                          1024u
#define Csm_IsCallbackStartNotificationOfGeneralOfPCConfig()                                        (((FALSE)) != FALSE)
#define Csm_IsCancelationDuringProcessingOfGeneralOfPCConfig()                                      (((FALSE)) != FALSE)
#define Csm_GetJobInfoOfPCConfig()                                                                  Csm_JobInfo  /**< the pointer to Csm_JobInfo */
#define Csm_GetJobOfPCConfig()                                                                      Csm_Job  /**< the pointer to Csm_Job */
#define Csm_GetJobPrimitiveInfoOfPCConfig()                                                         Csm_JobPrimitiveInfo  /**< the pointer to Csm_JobPrimitiveInfo */
#define Csm_GetJobStateOfPCConfig()                                                                 Csm_JobState  /**< the pointer to Csm_JobState */
#define Csm_GetJobTableOfPCConfig()                                                                 Csm_JobTable  /**< the pointer to Csm_JobTable */
#define Csm_GetJobToObjMapOfPCConfig()                                                              Csm_JobToObjMap  /**< the pointer to Csm_JobToObjMap */
#define Csm_GetKeyOfPCConfig()                                                                      Csm_Key  /**< the pointer to Csm_Key */
#define Csm_GetMainFunctionPeriodOfGeneralOfPCConfig()                                              1u
#define Csm_GetPrimitiveInfoOfPCConfig()                                                            Csm_PrimitiveInfo  /**< the pointer to Csm_PrimitiveInfo */
#define Csm_GetQueueInfoOfPCConfig()                                                                Csm_QueueInfo  /**< the pointer to Csm_QueueInfo */
#define Csm_GetQueueOfPCConfig()                                                                    Csm_Queue.raw  /**< the pointer to Csm_Queue */
#define Csm_GetQueueStateOfPCConfig()                                                               Csm_QueueState  /**< the pointer to Csm_QueueState */
#define Csm_GetSizeOfJobInfoOfPCConfig()                                                            5u  /**< the number of accomplishable value elements in Csm_JobInfo */
#define Csm_GetSizeOfJobOfPCConfig()                                                                4u  /**< the number of accomplishable value elements in Csm_Job */
#define Csm_GetSizeOfJobPrimitiveInfoOfPCConfig()                                                   5u  /**< the number of accomplishable value elements in Csm_JobPrimitiveInfo */
#define Csm_GetSizeOfJobTableOfPCConfig()                                                           5u  /**< the number of accomplishable value elements in Csm_JobTable */
#define Csm_GetSizeOfKeyOfPCConfig()                                                                64u  /**< the number of accomplishable value elements in Csm_Key */
#define Csm_GetSizeOfPrimitiveInfoOfPCConfig()                                                      5u  /**< the number of accomplishable value elements in Csm_PrimitiveInfo */
#define Csm_GetSizeOfQueueInfoOfPCConfig()                                                          4u  /**< the number of accomplishable value elements in Csm_QueueInfo */
#define Csm_GetSizeOfQueueOfPCConfig()                                                              4u  /**< the number of accomplishable value elements in Csm_Queue */
#define Csm_GetSymKeyMaxLengthOfGeneralOfPCConfig()                                                 16u
#define Csm_IsUseDeprecatedOfGeneralOfPCConfig()                                                    (((FALSE)) != FALSE)
#define Csm_IsVersionInfoApiOfGeneralOfPCConfig()                                                   (((FALSE)) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetDuplicatedRootDataMacros  Csm Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Csm_GetSizeOfJobStateOfPCConfig()                                                           Csm_GetSizeOfJobTableOfPCConfig()  /**< the number of accomplishable value elements in Csm_JobState */
#define Csm_GetSizeOfJobToObjMapOfPCConfig()                                                        Csm_GetSizeOfJobTableOfPCConfig()  /**< the number of accomplishable value elements in Csm_JobToObjMap */
#define Csm_GetSizeOfQueueStateOfPCConfig()                                                         Csm_GetSizeOfQueueInfoOfPCConfig()  /**< the number of accomplishable value elements in Csm_QueueState */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetDataMacros  Csm Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Csm_GetCallbackFunc43OfBswCallbacks(Index)                                                    /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc43' Reason: 'No Callback according to ASR 4.3 is configured' */
#define Csm_GetCallbackFunc44OfBswCallbacks(Index)                                                    /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc44' Reason: 'No Callback according to ASR 4.4 is configured' */
#define Csm_GetCallbackFunc45OfBswCallbacks(Index)                                                    /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc45' Reason: 'No Callback according to ASR 4.5 is configured' */
#define Csm_GetPostJobCalloutFuncOfCallout(Index)                                                     /**< Deactivateable: 'Csm_Callout.PostJobCalloutFunc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_GetPreJobCalloutFuncOfCallout(Index)                                                      /**< Deactivateable: 'Csm_Callout.PreJobCalloutFunc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_GetCalloutIdxOfCalloutInfo(Index)                                                         /**< Deactivateable: 'Csm_CalloutInfo.CalloutIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_GetJobTableIdxOfCalloutInfo(Index)                                                        /**< Deactivateable: 'Csm_CalloutInfo.JobTableIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_GetCalloutStateOfCalloutState(Index)                                                      /**< Deactivateable: 'Csm_CalloutState.CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Csm_GetInputKeyElementIdOfInOutJobRedirectionTable(Index)                                     /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_GetInputKeyIdOfInOutJobRedirectionTable(Index)                                            /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyId' Reason: 'Not enabled for any job' */
#define Csm_GetOutputKeyElementIdOfInOutJobRedirectionTable(Index)                                    /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_GetOutputKeyIdOfInOutJobRedirectionTable(Index)                                           /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyId' Reason: 'Not enabled for any job' */
#define Csm_GetRedirectionConfigValueOfInOutJobRedirectionTable(Index)                                /**< Deactivateable: 'Csm_InOutJobRedirectionTable.RedirectionConfigValue' Reason: 'Not enabled for any job' */
#define Csm_GetSecondaryInputKeyElementIdOfInOutJobRedirectionTable(Index)                            /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_GetSecondaryInputKeyIdOfInOutJobRedirectionTable(Index)                                   /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyId' Reason: 'Not enabled for any job' */
#define Csm_GetSecondaryOutputKeyElementIdOfInOutJobRedirectionTable(Index)                           /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_GetSecondaryOutputKeyIdOfInOutJobRedirectionTable(Index)                                  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyId' Reason: 'Not enabled for any job' */
#define Csm_GetTertiaryInputKeyElementIdOfInOutJobRedirectionTable(Index)                             /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_GetTertiaryInputKeyIdOfInOutJobRedirectionTable(Index)                                    /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyId' Reason: 'Not enabled for any job' */
#define Csm_GetInOutRedirection(Index)                                                                /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_GetInOutJobRedirectionTableIdxOfInOutRedirectionMap(Index)                                /**< Deactivateable: 'Csm_InOutRedirectionMap.InOutJobRedirectionTableIdx' Reason: 'Not enabled for any job' */
#define Csm_IsInvalidHndOfInOutRedirectionMap(Index)                                                  /**< Deactivateable: 'Csm_InOutRedirectionMap.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_GetJob(Index)                                                                           (Csm_GetJobOfPCConfig()[(Index)])
#define Csm_GetJobInfo(Index)                                                                       (Csm_GetJobInfoOfPCConfig()[(Index)])
#define Csm_GetJobPrimitiveInfo(Index)                                                              (Csm_GetJobPrimitiveInfoOfPCConfig()[(Index)])
#define Csm_GetJobState(Index)                                                                      (Csm_GetJobStateOfPCConfig()[(Index)])
#define Csm_GetBswCallbacksIdxOfJobTable(Index)                                                       /**< Deactivateable: 'Csm_JobTable.BswCallbacksIdx' Reason: 'the optional indirection is deactivated because BswCallbacksUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_IsBswCallbacksUsedOfJobTable(Index)                                                       /**< Deactivateable: 'Csm_JobTable.BswCallbacksUsed' Reason: 'the optional indirection is deactivated because BswCallbacksUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_GetCalloutInfoIdxOfJobTable(Index)                                                        /**< Deactivateable: 'Csm_JobTable.CalloutInfoIdx' Reason: 'the optional indirection is deactivated because CalloutInfoUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_IsCalloutInfoUsedOfJobTable(Index)                                                        /**< Deactivateable: 'Csm_JobTable.CalloutInfoUsed' Reason: 'the optional indirection is deactivated because CalloutInfoUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_GetCsmKeyIdIdxOfJobTable(Index)                                                         (Csm_GetJobTableOfPCConfig()[(Index)].CsmKeyIdIdxOfJobTable)
#define Csm_GetInOutRedirectionMapIdxOfJobTable(Index)                                                /**< Deactivateable: 'Csm_JobTable.InOutRedirectionMapIdx' Reason: 'the optional indirection is deactivated because InOutRedirectionMapUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_IsInOutRedirectionMapUsedOfJobTable(Index)                                                /**< Deactivateable: 'Csm_JobTable.InOutRedirectionMapUsed' Reason: 'the optional indirection is deactivated because InOutRedirectionMapUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_GetJobIdxOfJobTable(Index)                                                                /**< Deactivateable: 'Csm_JobTable.JobIdx' Reason: 'the optional indirection is deactivated because JobUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_IsJobUsedOfJobTable(Index)                                                                /**< Deactivateable: 'Csm_JobTable.JobUsed' Reason: 'the optional indirection is deactivated because JobUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_GetPriorityOfJobTable(Index)                                                            (Csm_GetJobTableOfPCConfig()[(Index)].PriorityOfJobTable)
#define Csm_GetQueueRefIdxOfJobTable(Index)                                                         (Csm_GetJobTableOfPCConfig()[(Index)].QueueRefIdxOfJobTable)
#define Csm_GetRteCallbackIdxOfJobTable(Index)                                                        /**< Deactivateable: 'Csm_JobTable.RteCallbackIdx' Reason: 'No RTE Callback is configured' */
#define Csm_IsRteCallbackUsedOfJobTable(Index)                                                        /**< Deactivateable: 'Csm_JobTable.RteCallbackUsed' Reason: 'No RTE Callback is configured' */
#define Csm_GetJobToObjMap(Index)                                                                   (Csm_GetJobToObjMapOfPCConfig()[(Index)])
#define Csm_GetCryIfKeyIdOfKey(Index)                                                               (Csm_GetKeyOfPCConfig()[(Index)].CryIfKeyIdOfKey)
#define Csm_GetPrimitiveInfo(Index)                                                                 (Csm_GetPrimitiveInfoOfPCConfig()[(Index)])
#define Csm_GetQueue(Index)                                                                         (Csm_GetQueueOfPCConfig()[(Index)])
#define Csm_GetChannelIdOfQueueInfo(Index)                                                          (Csm_GetQueueInfoOfPCConfig()[(Index)].ChannelIdOfQueueInfo)
#define Csm_GetJobPoolStartIdxOfQueueInfo(Index)                                                    (Csm_GetQueueInfoOfPCConfig()[(Index)].JobPoolStartIdxOfQueueInfo)
#define Csm_GetMaskedBitsOfQueueInfo(Index)                                                         (Csm_GetQueueInfoOfPCConfig()[(Index)].MaskedBitsOfQueueInfo)
#define Csm_GetQueueEndIdxOfQueueInfo(Index)                                                        (Csm_GetQueueInfoOfPCConfig()[(Index)].QueueEndIdxOfQueueInfo)
#define Csm_IsTriggerAsynchJobsInCallbackOfQueueInfo(Index)                                           /**< Deactivateable: 'Csm_QueueInfo.TriggerAsynchJobsInCallback' Reason: 'Not enabled for any of the queues.' */
#define Csm_GetLockOfQueueState(Index)                                                              (Csm_GetQueueStateOfPCConfig()[(Index)].LockOfQueueState)
#define Csm_GetQueueIdxOfQueueState(Index)                                                          (Csm_GetQueueStateOfPCConfig()[(Index)].QueueIdxOfQueueState)
#define Csm_GetRetriggeringOfQueueState(Index)                                                        /**< Deactivateable: 'Csm_QueueState.Retriggering' Reason: 'Not enabled for any of the queues.' */
#define Csm_GetRteCallback(Index)                                                                     /**< Deactivateable: 'Csm_RteCallback' Reason: 'No RTE Callback is configured' */
#define Csm_IsRteCallbackOccurred()                                                                   /**< Deactivateable: 'Csm_RteCallbackOccurred' Reason: 'No RTE Callback is configured' */
#define Csm_GetRteResult(Index)                                                                       /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetBitDataMacros  Csm Get Bit Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read bitcoded data elements.
  \{
*/ 
#define Csm_IsPrimitiveCallbackUpdateNotificationOfJobTable(Index)                                  (CSM_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE_MASK == (Csm_GetMaskedBitsOfJobTable(Index) & CSM_PRIMITIVECALLBACKUPDATENOTIFICATIONOFJOBTABLE_MASK))  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmJobs/CsmJob/CsmJobPrimitiveCallbackUpdateNotification. */
#define Csm_IsJobPoolUsedOfQueueInfo(Index)                                                         (CSM_JOBPOOLUSEDOFQUEUEINFO_MASK == (Csm_GetMaskedBitsOfQueueInfo(Index) & CSM_JOBPOOLUSEDOFQUEUEINFO_MASK))  /**< TRUE, if the 0:n relation has 1 relation pointing to Csm_Job */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetDeduplicatedDataMacros  Csm Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Csm_GetAsymPrivateKeyMaxLengthOfGeneral()                                                   Csm_GetAsymPrivateKeyMaxLengthOfGeneralOfPCConfig()
#define Csm_GetAsymPublicKeyMaxLengthOfGeneral()                                                    Csm_GetAsymPublicKeyMaxLengthOfGeneralOfPCConfig()
#define Csm_IsCallbackStartNotificationOfGeneral()                                                  Csm_IsCallbackStartNotificationOfGeneralOfPCConfig()
#define Csm_IsCancelationDuringProcessingOfGeneral()                                                Csm_IsCancelationDuringProcessingOfGeneralOfPCConfig()
#define Csm_GetExpectedCompatibilityVersion()                                                         /**< Deactivateable: 'Csm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_GetFinalMagicNumber()                                                                     /**< Deactivateable: 'Csm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_GetGeneratorCompatibilityVersion()                                                        /**< Deactivateable: 'Csm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_GetInitDataHashCode()                                                                     /**< Deactivateable: 'Csm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_IsAsynchronousOfJobTable(Index)                                                         Csm_IsPrimitiveCallbackUpdateNotificationOfJobTable(Index)
#define Csm_GetJobInfoIdxOfJobTable(Index)                                                          ((Csm_JobInfoIdxOfJobTableType)((Index)))  /**< the index of the 1:1 relation pointing to Csm_JobInfo */
#define Csm_GetJobPrimitiveInfoIdxOfJobTable(Index)                                                 ((Csm_JobPrimitiveInfoIdxOfJobTableType)((Index)))  /**< the index of the 1:1 relation pointing to Csm_JobPrimitiveInfo */
#define Csm_GetMaskedBitsOfJobTable(Index)                                                          Csm_GetPriorityOfJobTable(Index)  /**< contains bitcoded the boolean data of Csm_AsynchronousOfJobTable, Csm_PrimitiveCallbackUpdateNotificationOfJobTable */
#define Csm_GetMainFunctionPeriodOfGeneral()                                                        Csm_GetMainFunctionPeriodOfGeneralOfPCConfig()
#define Csm_GetJobObjSynchronousIdxOfQueueInfo(Index)                                               Csm_GetJobPoolStartIdxOfQueueInfo(Index)  /**< the index of the 0:1 relation pointing to Csm_Job */
#define Csm_IsJobObjSynchronousUsedOfQueueInfo(Index)                                               Csm_IsJobPoolUsedOfQueueInfo(Index)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Csm_Job */
#define Csm_GetJobPoolEndIdxOfQueueInfo(Index)                                                      Csm_GetQueueEndIdxOfQueueInfo(Index)  /**< the end index of the 0:n relation pointing to Csm_Job */
#define Csm_IsJobSharingOfQueueInfo(Index)                                                          Csm_IsJobPoolUsedOfQueueInfo(Index)  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmJobSharing. */
#define Csm_GetQueueStartIdxOfQueueInfo(Index)                                                      Csm_GetJobPoolStartIdxOfQueueInfo(Index)  /**< the start index of the 1:n relation pointing to Csm_Queue */
#define Csm_GetSizeOfJob()                                                                          Csm_GetSizeOfJobOfPCConfig()
#define Csm_GetSizeOfJobInfo()                                                                      Csm_GetSizeOfJobInfoOfPCConfig()
#define Csm_GetSizeOfJobPrimitiveInfo()                                                             Csm_GetSizeOfJobPrimitiveInfoOfPCConfig()
#define Csm_GetSizeOfJobState()                                                                     Csm_GetSizeOfJobStateOfPCConfig()
#define Csm_GetSizeOfJobTable()                                                                     Csm_GetSizeOfJobTableOfPCConfig()
#define Csm_GetSizeOfJobToObjMap()                                                                  Csm_GetSizeOfJobToObjMapOfPCConfig()
#define Csm_GetSizeOfKey()                                                                          Csm_GetSizeOfKeyOfPCConfig()
#define Csm_GetSizeOfPrimitiveInfo()                                                                Csm_GetSizeOfPrimitiveInfoOfPCConfig()
#define Csm_GetSizeOfQueue()                                                                        Csm_GetSizeOfQueueOfPCConfig()
#define Csm_GetSizeOfQueueInfo()                                                                    Csm_GetSizeOfQueueInfoOfPCConfig()
#define Csm_GetSizeOfQueueState()                                                                   Csm_GetSizeOfQueueStateOfPCConfig()
#define Csm_GetSymKeyMaxLengthOfGeneral()                                                           Csm_GetSymKeyMaxLengthOfGeneralOfPCConfig()
#define Csm_IsUseDeprecatedOfGeneral()                                                              Csm_IsUseDeprecatedOfGeneralOfPCConfig()
#define Csm_IsVersionInfoApiOfGeneral()                                                             Csm_IsVersionInfoApiOfGeneralOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCSetDataMacros  Csm Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Csm_SetCalloutStateOfCalloutState(Index, Value)                                               /**< Deactivateable: 'Csm_CalloutState.CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Csm_SetInOutRedirection(Index, Value)                                                         /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_SetJob(Index, Value)                                                                    Csm_GetJobOfPCConfig()[(Index)] = (Value)
#define Csm_SetJobState(Index, Value)                                                               Csm_GetJobStateOfPCConfig()[(Index)] = (Value)
#define Csm_SetJobToObjMap(Index, Value)                                                            Csm_GetJobToObjMapOfPCConfig()[(Index)] = (Value)
#define Csm_SetQueue(Index, Value)                                                                  Csm_GetQueueOfPCConfig()[(Index)] = (Value)
#define Csm_SetLockOfQueueState(Index, Value)                                                       Csm_GetQueueStateOfPCConfig()[(Index)].LockOfQueueState = (Value)
#define Csm_SetQueueIdxOfQueueState(Index, Value)                                                   Csm_GetQueueStateOfPCConfig()[(Index)].QueueIdxOfQueueState = (Value)
#define Csm_SetRetriggeringOfQueueState(Index, Value)                                                 /**< Deactivateable: 'Csm_QueueState.Retriggering' Reason: 'Not enabled for any of the queues.' */
#define Csm_SetRteCallbackOccurred(Value)                                                             /**< Deactivateable: 'Csm_RteCallbackOccurred' Reason: 'No RTE Callback is configured' */
#define Csm_SetRteResult(Index, Value)                                                                /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCGetAddressOfDataMacros  Csm Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Csm_GetAddrInOutRedirection(Index)                                                            /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_GetAddrJob(Index)                                                                       (&Csm_GetJob(Index))
#define Csm_GetAddrJobInfo(Index)                                                                   (&Csm_GetJobInfo(Index))
#define Csm_GetAddrJobPrimitiveInfo(Index)                                                          (&Csm_GetJobPrimitiveInfo(Index))
#define Csm_GetAddrPrimitiveInfo(Index)                                                             (&Csm_GetPrimitiveInfo(Index))
#define Csm_GetAddrQueue(Index)                                                                     (&Csm_GetQueue(Index))
#define Csm_GetAddrRteResult(Index)                                                                   /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCHasMacros  Csm Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Csm_HasAsymPrivateKeyMaxLengthOfGeneral()                                                   (TRUE != FALSE)
#define Csm_HasAsymPublicKeyMaxLengthOfGeneral()                                                    (TRUE != FALSE)
#define Csm_HasBswCallbacks()                                                                         /**< Deactivateable: 'Csm_BswCallbacks' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Csm_HasCallbackFunc43OfBswCallbacks()                                                         /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc43' Reason: 'No Callback according to ASR 4.3 is configured' */
#define Csm_HasCallbackFunc44OfBswCallbacks()                                                         /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc44' Reason: 'No Callback according to ASR 4.4 is configured' */
#define Csm_HasCallbackFunc45OfBswCallbacks()                                                         /**< Deactivateable: 'Csm_BswCallbacks.CallbackFunc45' Reason: 'No Callback according to ASR 4.5 is configured' */
#define Csm_HasCallbackStartNotificationOfGeneral()                                                 (TRUE != FALSE)
#define Csm_HasCallout()                                                                              /**< Deactivateable: 'Csm_Callout' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Csm_HasPostJobCalloutFuncOfCallout()                                                          /**< Deactivateable: 'Csm_Callout.PostJobCalloutFunc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_HasPreJobCalloutFuncOfCallout()                                                           /**< Deactivateable: 'Csm_Callout.PreJobCalloutFunc' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_HasCalloutInfo()                                                                          /**< Deactivateable: 'Csm_CalloutInfo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Csm_HasCalloutIdxOfCalloutInfo()                                                              /**< Deactivateable: 'Csm_CalloutInfo.CalloutIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_HasJobTableIdxOfCalloutInfo()                                                             /**< Deactivateable: 'Csm_CalloutInfo.JobTableIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_HasCalloutState()                                                                         /**< Deactivateable: 'Csm_CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Csm_HasCalloutStateOfCalloutState()                                                           /**< Deactivateable: 'Csm_CalloutState.CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Csm_HasCancelationDuringProcessingOfGeneral()                                               (TRUE != FALSE)
#define Csm_HasExpectedCompatibilityVersion()                                                         /**< Deactivateable: 'Csm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_HasFinalMagicNumber()                                                                     /**< Deactivateable: 'Csm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_HasGeneratorCompatibilityVersion()                                                        /**< Deactivateable: 'Csm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_HasInOutJobRedirectionTable()                                                             /**< Deactivateable: 'Csm_InOutJobRedirectionTable' Reason: 'Not enabled for any job' */
#define Csm_HasInputKeyElementIdOfInOutJobRedirectionTable()                                          /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_HasInputKeyIdOfInOutJobRedirectionTable()                                                 /**< Deactivateable: 'Csm_InOutJobRedirectionTable.InputKeyId' Reason: 'Not enabled for any job' */
#define Csm_HasOutputKeyElementIdOfInOutJobRedirectionTable()                                         /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_HasOutputKeyIdOfInOutJobRedirectionTable()                                                /**< Deactivateable: 'Csm_InOutJobRedirectionTable.OutputKeyId' Reason: 'Not enabled for any job' */
#define Csm_HasRedirectionConfigValueOfInOutJobRedirectionTable()                                     /**< Deactivateable: 'Csm_InOutJobRedirectionTable.RedirectionConfigValue' Reason: 'Not enabled for any job' */
#define Csm_HasSecondaryInputKeyElementIdOfInOutJobRedirectionTable()                                 /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_HasSecondaryInputKeyIdOfInOutJobRedirectionTable()                                        /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryInputKeyId' Reason: 'Not enabled for any job' */
#define Csm_HasSecondaryOutputKeyElementIdOfInOutJobRedirectionTable()                                /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_HasSecondaryOutputKeyIdOfInOutJobRedirectionTable()                                       /**< Deactivateable: 'Csm_InOutJobRedirectionTable.SecondaryOutputKeyId' Reason: 'Not enabled for any job' */
#define Csm_HasTertiaryInputKeyElementIdOfInOutJobRedirectionTable()                                  /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyElementId' Reason: 'Not enabled for any job' */
#define Csm_HasTertiaryInputKeyIdOfInOutJobRedirectionTable()                                         /**< Deactivateable: 'Csm_InOutJobRedirectionTable.TertiaryInputKeyId' Reason: 'Not enabled for any job' */
#define Csm_HasInOutRedirection()                                                                     /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_HasInOutRedirectionMap()                                                                  /**< Deactivateable: 'Csm_InOutRedirectionMap' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define Csm_HasInOutJobRedirectionTableIdxOfInOutRedirectionMap()                                     /**< Deactivateable: 'Csm_InOutRedirectionMap.InOutJobRedirectionTableIdx' Reason: 'Not enabled for any job' */
#define Csm_HasInvalidHndOfInOutRedirectionMap()                                                      /**< Deactivateable: 'Csm_InOutRedirectionMap.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_HasInitDataHashCode()                                                                     /**< Deactivateable: 'Csm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_HasJob()                                                                                (TRUE != FALSE)
#define Csm_HasJobInfo()                                                                            (TRUE != FALSE)
#define Csm_HasJobPrimitiveInfo()                                                                   (TRUE != FALSE)
#define Csm_HasJobState()                                                                           (TRUE != FALSE)
#define Csm_HasJobTable()                                                                           (TRUE != FALSE)
#define Csm_HasAsynchronousOfJobTable()                                                             (TRUE != FALSE)
#define Csm_HasBswCallbacksIdxOfJobTable()                                                            /**< Deactivateable: 'Csm_JobTable.BswCallbacksIdx' Reason: 'the optional indirection is deactivated because BswCallbacksUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_HasBswCallbacksUsedOfJobTable()                                                           /**< Deactivateable: 'Csm_JobTable.BswCallbacksUsed' Reason: 'the optional indirection is deactivated because BswCallbacksUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_HasCalloutInfoIdxOfJobTable()                                                             /**< Deactivateable: 'Csm_JobTable.CalloutInfoIdx' Reason: 'the optional indirection is deactivated because CalloutInfoUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_HasCalloutInfoUsedOfJobTable()                                                            /**< Deactivateable: 'Csm_JobTable.CalloutInfoUsed' Reason: 'the optional indirection is deactivated because CalloutInfoUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_HasCsmKeyIdIdxOfJobTable()                                                              (TRUE != FALSE)
#define Csm_HasInOutRedirectionMapIdxOfJobTable()                                                     /**< Deactivateable: 'Csm_JobTable.InOutRedirectionMapIdx' Reason: 'the optional indirection is deactivated because InOutRedirectionMapUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_HasInOutRedirectionMapUsedOfJobTable()                                                    /**< Deactivateable: 'Csm_JobTable.InOutRedirectionMapUsed' Reason: 'the optional indirection is deactivated because InOutRedirectionMapUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_HasJobIdxOfJobTable()                                                                     /**< Deactivateable: 'Csm_JobTable.JobIdx' Reason: 'the optional indirection is deactivated because JobUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_HasJobInfoIdxOfJobTable()                                                               (TRUE != FALSE)
#define Csm_HasJobPrimitiveInfoIdxOfJobTable()                                                      (TRUE != FALSE)
#define Csm_HasJobUsedOfJobTable()                                                                    /**< Deactivateable: 'Csm_JobTable.JobUsed' Reason: 'the optional indirection is deactivated because JobUsedOfJobTable is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define Csm_HasMaskedBitsOfJobTable()                                                               (TRUE != FALSE)
#define Csm_HasPrimitiveCallbackUpdateNotificationOfJobTable()                                      (TRUE != FALSE)
#define Csm_HasPriorityOfJobTable()                                                                 (TRUE != FALSE)
#define Csm_HasQueueRefIdxOfJobTable()                                                              (TRUE != FALSE)
#define Csm_HasRteCallbackIdxOfJobTable()                                                             /**< Deactivateable: 'Csm_JobTable.RteCallbackIdx' Reason: 'No RTE Callback is configured' */
#define Csm_HasRteCallbackUsedOfJobTable()                                                            /**< Deactivateable: 'Csm_JobTable.RteCallbackUsed' Reason: 'No RTE Callback is configured' */
#define Csm_HasJobToObjMap()                                                                        (TRUE != FALSE)
#define Csm_HasKey()                                                                                (TRUE != FALSE)
#define Csm_HasCryIfKeyIdOfKey()                                                                    (TRUE != FALSE)
#define Csm_HasMainFunctionPeriodOfGeneral()                                                        (TRUE != FALSE)
#define Csm_HasPrimitiveInfo()                                                                      (TRUE != FALSE)
#define Csm_HasQueue()                                                                              (TRUE != FALSE)
#define Csm_HasQueueInfo()                                                                          (TRUE != FALSE)
#define Csm_HasChannelIdOfQueueInfo()                                                               (TRUE != FALSE)
#define Csm_HasJobObjSynchronousIdxOfQueueInfo()                                                    (TRUE != FALSE)
#define Csm_HasJobObjSynchronousUsedOfQueueInfo()                                                   (TRUE != FALSE)
#define Csm_HasJobPoolEndIdxOfQueueInfo()                                                           (TRUE != FALSE)
#define Csm_HasJobPoolStartIdxOfQueueInfo()                                                         (TRUE != FALSE)
#define Csm_HasJobPoolUsedOfQueueInfo()                                                             (TRUE != FALSE)
#define Csm_HasJobSharingOfQueueInfo()                                                              (TRUE != FALSE)
#define Csm_HasMaskedBitsOfQueueInfo()                                                              (TRUE != FALSE)
#define Csm_HasQueueEndIdxOfQueueInfo()                                                             (TRUE != FALSE)
#define Csm_HasQueueStartIdxOfQueueInfo()                                                           (TRUE != FALSE)
#define Csm_HasTriggerAsynchJobsInCallbackOfQueueInfo()                                               /**< Deactivateable: 'Csm_QueueInfo.TriggerAsynchJobsInCallback' Reason: 'Not enabled for any of the queues.' */
#define Csm_HasQueueState()                                                                         (TRUE != FALSE)
#define Csm_HasLockOfQueueState()                                                                   (TRUE != FALSE)
#define Csm_HasQueueIdxOfQueueState()                                                               (TRUE != FALSE)
#define Csm_HasRetriggeringOfQueueState()                                                             /**< Deactivateable: 'Csm_QueueState.Retriggering' Reason: 'Not enabled for any of the queues.' */
#define Csm_HasRteCallback()                                                                          /**< Deactivateable: 'Csm_RteCallback' Reason: 'No RTE Callback is configured' */
#define Csm_HasRteCallbackOccurred()                                                                  /**< Deactivateable: 'Csm_RteCallbackOccurred' Reason: 'No RTE Callback is configured' */
#define Csm_HasRteResult()                                                                            /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
#define Csm_HasSizeOfJob()                                                                          (TRUE != FALSE)
#define Csm_HasSizeOfJobInfo()                                                                      (TRUE != FALSE)
#define Csm_HasSizeOfJobPrimitiveInfo()                                                             (TRUE != FALSE)
#define Csm_HasSizeOfJobState()                                                                     (TRUE != FALSE)
#define Csm_HasSizeOfJobTable()                                                                     (TRUE != FALSE)
#define Csm_HasSizeOfJobToObjMap()                                                                  (TRUE != FALSE)
#define Csm_HasSizeOfKey()                                                                          (TRUE != FALSE)
#define Csm_HasSizeOfPrimitiveInfo()                                                                (TRUE != FALSE)
#define Csm_HasSizeOfQueue()                                                                        (TRUE != FALSE)
#define Csm_HasSizeOfQueueInfo()                                                                    (TRUE != FALSE)
#define Csm_HasSizeOfQueueState()                                                                   (TRUE != FALSE)
#define Csm_HasSymKeyMaxLengthOfGeneral()                                                           (TRUE != FALSE)
#define Csm_HasUseDeprecatedOfGeneral()                                                             (TRUE != FALSE)
#define Csm_HasVersionInfoApiOfGeneral()                                                            (TRUE != FALSE)
#define Csm_HasPCConfig()                                                                           (TRUE != FALSE)
#define Csm_HasAsymPrivateKeyMaxLengthOfGeneralOfPCConfig()                                         (TRUE != FALSE)
#define Csm_HasAsymPublicKeyMaxLengthOfGeneralOfPCConfig()                                          (TRUE != FALSE)
#define Csm_HasCallbackStartNotificationOfGeneralOfPCConfig()                                       (TRUE != FALSE)
#define Csm_HasCancelationDuringProcessingOfGeneralOfPCConfig()                                     (TRUE != FALSE)
#define Csm_HasExpectedCompatibilityVersionOfPCConfig()                                               /**< Deactivateable: 'Csm_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_HasFinalMagicNumberOfPCConfig()                                                           /**< Deactivateable: 'Csm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_HasGeneratorCompatibilityVersionOfPCConfig()                                              /**< Deactivateable: 'Csm_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Csm_HasInitDataHashCodeOfPCConfig()                                                           /**< Deactivateable: 'Csm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Csm_HasJobInfoOfPCConfig()                                                                  (TRUE != FALSE)
#define Csm_HasJobOfPCConfig()                                                                      (TRUE != FALSE)
#define Csm_HasJobPrimitiveInfoOfPCConfig()                                                         (TRUE != FALSE)
#define Csm_HasJobStateOfPCConfig()                                                                 (TRUE != FALSE)
#define Csm_HasJobTableOfPCConfig()                                                                 (TRUE != FALSE)
#define Csm_HasJobToObjMapOfPCConfig()                                                              (TRUE != FALSE)
#define Csm_HasKeyOfPCConfig()                                                                      (TRUE != FALSE)
#define Csm_HasMainFunctionPeriodOfGeneralOfPCConfig()                                              (TRUE != FALSE)
#define Csm_HasPrimitiveInfoOfPCConfig()                                                            (TRUE != FALSE)
#define Csm_HasQueueInfoOfPCConfig()                                                                (TRUE != FALSE)
#define Csm_HasQueueOfPCConfig()                                                                    (TRUE != FALSE)
#define Csm_HasQueueStateOfPCConfig()                                                               (TRUE != FALSE)
#define Csm_HasSizeOfJobInfoOfPCConfig()                                                            (TRUE != FALSE)
#define Csm_HasSizeOfJobOfPCConfig()                                                                (TRUE != FALSE)
#define Csm_HasSizeOfJobPrimitiveInfoOfPCConfig()                                                   (TRUE != FALSE)
#define Csm_HasSizeOfJobStateOfPCConfig()                                                           (TRUE != FALSE)
#define Csm_HasSizeOfJobTableOfPCConfig()                                                           (TRUE != FALSE)
#define Csm_HasSizeOfJobToObjMapOfPCConfig()                                                        (TRUE != FALSE)
#define Csm_HasSizeOfKeyOfPCConfig()                                                                (TRUE != FALSE)
#define Csm_HasSizeOfPrimitiveInfoOfPCConfig()                                                      (TRUE != FALSE)
#define Csm_HasSizeOfQueueInfoOfPCConfig()                                                          (TRUE != FALSE)
#define Csm_HasSizeOfQueueOfPCConfig()                                                              (TRUE != FALSE)
#define Csm_HasSizeOfQueueStateOfPCConfig()                                                         (TRUE != FALSE)
#define Csm_HasSymKeyMaxLengthOfGeneralOfPCConfig()                                                 (TRUE != FALSE)
#define Csm_HasUseDeprecatedOfGeneralOfPCConfig()                                                   (TRUE != FALSE)
#define Csm_HasVersionInfoApiOfGeneralOfPCConfig()                                                  (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCIncrementDataMacros  Csm Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Csm_IncCalloutStateOfCalloutState(Index)                                                      /**< Deactivateable: 'Csm_CalloutState.CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Csm_IncInOutRedirection(Index)                                                                /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_IncJob(Index)                                                                           Csm_GetJob(Index)++
#define Csm_IncJobState(Index)                                                                      Csm_GetJobState(Index)++
#define Csm_IncQueue(Index)                                                                         Csm_GetQueue(Index)++
#define Csm_IncLockOfQueueState(Index)                                                              Csm_GetLockOfQueueState(Index)++
#define Csm_IncQueueIdxOfQueueState(Index)                                                          Csm_GetQueueIdxOfQueueState(Index)++
#define Csm_IncRetriggeringOfQueueState(Index)                                                        /**< Deactivateable: 'Csm_QueueState.Retriggering' Reason: 'Not enabled for any of the queues.' */
#define Csm_IncRteResult(Index)                                                                       /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCDecrementDataMacros  Csm Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Csm_DecCalloutStateOfCalloutState(Index)                                                      /**< Deactivateable: 'Csm_CalloutState.CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Csm_DecInOutRedirection(Index)                                                                /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_DecJob(Index)                                                                           Csm_GetJob(Index)--
#define Csm_DecJobState(Index)                                                                      Csm_GetJobState(Index)--
#define Csm_DecQueue(Index)                                                                         Csm_GetQueue(Index)--
#define Csm_DecLockOfQueueState(Index)                                                              Csm_GetLockOfQueueState(Index)--
#define Csm_DecQueueIdxOfQueueState(Index)                                                          Csm_GetQueueIdxOfQueueState(Index)--
#define Csm_DecRetriggeringOfQueueState(Index)                                                        /**< Deactivateable: 'Csm_QueueState.Retriggering' Reason: 'Not enabled for any of the queues.' */
#define Csm_DecRteResult(Index)                                                                       /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCAddDataMacros  Csm Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define Csm_AddCalloutStateOfCalloutState(Index, Value)                                               /**< Deactivateable: 'Csm_CalloutState.CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Csm_AddInOutRedirection(Index, Value)                                                         /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_AddJob(Index, Value)                                                                    Csm_SetJob(Index, (Csm_GetJob(Index) + Value))
#define Csm_AddJobState(Index, Value)                                                               Csm_SetJobState(Index, (Csm_GetJobState(Index) + Value))
#define Csm_AddQueue(Index, Value)                                                                  Csm_SetQueue(Index, (Csm_GetQueue(Index) + Value))
#define Csm_AddLockOfQueueState(Index, Value)                                                       Csm_SetLockOfQueueState(Index, (Csm_GetLockOfQueueState(Index) + Value))
#define Csm_AddQueueIdxOfQueueState(Index, Value)                                                   Csm_SetQueueIdxOfQueueState(Index, (Csm_GetQueueIdxOfQueueState(Index) + Value))
#define Csm_AddRetriggeringOfQueueState(Index, Value)                                                 /**< Deactivateable: 'Csm_QueueState.Retriggering' Reason: 'Not enabled for any of the queues.' */
#define Csm_AddRteResult(Index, Value)                                                                /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPCSubstractDataMacros  Csm Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define Csm_SubCalloutStateOfCalloutState(Index, Value)                                               /**< Deactivateable: 'Csm_CalloutState.CalloutState' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define Csm_SubInOutRedirection(Index, Value)                                                         /**< Deactivateable: 'Csm_InOutRedirection' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define Csm_SubJob(Index, Value)                                                                    Csm_SetJob(Index, (Csm_GetJob(Index) - Value))
#define Csm_SubJobState(Index, Value)                                                               Csm_SetJobState(Index, (Csm_GetJobState(Index) - Value))
#define Csm_SubQueue(Index, Value)                                                                  Csm_SetQueue(Index, (Csm_GetQueue(Index) - Value))
#define Csm_SubLockOfQueueState(Index, Value)                                                       Csm_SetLockOfQueueState(Index, (Csm_GetLockOfQueueState(Index) - Value))
#define Csm_SubQueueIdxOfQueueState(Index, Value)                                                   Csm_SetQueueIdxOfQueueState(Index, (Csm_GetQueueIdxOfQueueState(Index) - Value))
#define Csm_SubRetriggeringOfQueueState(Index, Value)                                                 /**< Deactivateable: 'Csm_QueueState.Retriggering' Reason: 'Not enabled for any of the queues.' */
#define Csm_SubRteResult(Index, Value)                                                                /**< Deactivateable: 'Csm_RteResult' Reason: 'No RTE Callback is configured' */
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
  \defgroup  CsmPBGetRootDataMacros  Csm Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Csm_GetLTConfigIdxOfPBConfig()                                                                /**< Deactivateable: 'Csm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Csm_GetPCConfigIdxOfPBConfig()                                                                /**< Deactivateable: 'Csm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  CsmPBHasMacros  Csm Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Csm_HasPBConfig()                                                                             /**< Deactivateable: 'Csm_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Csm_HasLTConfigIdxOfPBConfig()                                                                /**< Deactivateable: 'Csm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Csm_HasPCConfigIdxOfPBConfig()                                                                /**< Deactivateable: 'Csm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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
**********************************************************************************************************************/
typedef P2VAR(Crypto_JobType, AUTOMATIC, CSM_VAR_NOINIT) Csm_QueueElementType;
typedef uint8 Csm_JobCalloutStateType;
typedef P2FUNC (void, CSM_CODE, Csm_CallbackFunc43Type)(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Std_ReturnType result);
typedef P2FUNC (void, CSM_CODE, Csm_CallbackFunc44Type)(const uint32 jobID, Csm_ResultType result);
typedef P2FUNC (void, CSM_CODE, Csm_CallbackFunc45Type)(P2CONST(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Crypto_ResultType result);
typedef P2FUNC (Std_ReturnType, CSM_CODE, Csm_PreJobCalloutFunc)(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state);
typedef P2FUNC (Std_ReturnType, CSM_CODE, Csm_PostJobCalloutFunc)(P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_VAR) job, Csm_JobCalloutStateType state, P2VAR(Std_ReturnType, AUTOMATIC, CSM_APPL_VAR) jobReturnValue);


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CsmPCIterableTypes  Csm Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Csm_Job */
typedef uint8_least Csm_JobIterType;

/**   \brief  type used to iterate Csm_JobInfo */
typedef uint8_least Csm_JobInfoIterType;

/**   \brief  type used to iterate Csm_JobPrimitiveInfo */
typedef uint8_least Csm_JobPrimitiveInfoIterType;

/**   \brief  type used to iterate Csm_JobTable */
typedef uint8_least Csm_JobTableIterType;

/**   \brief  type used to iterate Csm_Key */
typedef uint8_least Csm_KeyIterType;

/**   \brief  type used to iterate Csm_PrimitiveInfo */
typedef uint8_least Csm_PrimitiveInfoIterType;

/**   \brief  type used to iterate Csm_Queue */
typedef uint8_least Csm_QueueIterType;

/**   \brief  type used to iterate Csm_QueueInfo */
typedef uint8_least Csm_QueueInfoIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCIterableTypesWithSizeRelations  Csm Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Csm_JobState */
typedef Csm_JobTableIterType Csm_JobStateIterType;

/**   \brief  type used to iterate Csm_JobToObjMap */
typedef Csm_JobTableIterType Csm_JobToObjMapIterType;

/**   \brief  type used to iterate Csm_QueueState */
typedef Csm_QueueInfoIterType Csm_QueueStateIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCValueTypes  Csm Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Csm_AsymPrivateKeyMaxLengthOfGeneral */
typedef uint8 Csm_AsymPrivateKeyMaxLengthOfGeneralType;

/**   \brief  value based type definition for Csm_AsymPublicKeyMaxLengthOfGeneral */
typedef uint16 Csm_AsymPublicKeyMaxLengthOfGeneralType;

/**   \brief  value based type definition for Csm_CallbackStartNotificationOfGeneral */
typedef boolean Csm_CallbackStartNotificationOfGeneralType;

/**   \brief  value based type definition for Csm_CancelationDuringProcessingOfGeneral */
typedef boolean Csm_CancelationDuringProcessingOfGeneralType;

/**   \brief  value based type definition for Csm_JobState */
typedef uint8 Csm_JobStateType;

/**   \brief  value based type definition for Csm_AsynchronousOfJobTable */
typedef boolean Csm_AsynchronousOfJobTableType;

/**   \brief  value based type definition for Csm_CsmKeyIdIdxOfJobTable */
typedef uint8 Csm_CsmKeyIdIdxOfJobTableType;

/**   \brief  value based type definition for Csm_JobInfoIdxOfJobTable */
typedef uint8 Csm_JobInfoIdxOfJobTableType;

/**   \brief  value based type definition for Csm_JobPrimitiveInfoIdxOfJobTable */
typedef uint8 Csm_JobPrimitiveInfoIdxOfJobTableType;

/**   \brief  value based type definition for Csm_MaskedBitsOfJobTable */
typedef uint8 Csm_MaskedBitsOfJobTableType;

/**   \brief  value based type definition for Csm_PrimitiveCallbackUpdateNotificationOfJobTable */
typedef boolean Csm_PrimitiveCallbackUpdateNotificationOfJobTableType;

/**   \brief  value based type definition for Csm_PriorityOfJobTable */
typedef uint8 Csm_PriorityOfJobTableType;

/**   \brief  value based type definition for Csm_QueueRefIdxOfJobTable */
typedef uint8 Csm_QueueRefIdxOfJobTableType;

/**   \brief  value based type definition for Csm_CryIfKeyIdOfKey */
typedef uint32 Csm_CryIfKeyIdOfKeyType;

/**   \brief  value based type definition for Csm_MainFunctionPeriodOfGeneral */
typedef uint8 Csm_MainFunctionPeriodOfGeneralType;

/**   \brief  value based type definition for Csm_ChannelIdOfQueueInfo */
typedef uint32 Csm_ChannelIdOfQueueInfoType;

/**   \brief  value based type definition for Csm_JobObjSynchronousIdxOfQueueInfo */
typedef uint8 Csm_JobObjSynchronousIdxOfQueueInfoType;

/**   \brief  value based type definition for Csm_JobObjSynchronousUsedOfQueueInfo */
typedef boolean Csm_JobObjSynchronousUsedOfQueueInfoType;

/**   \brief  value based type definition for Csm_JobPoolEndIdxOfQueueInfo */
typedef uint8 Csm_JobPoolEndIdxOfQueueInfoType;

/**   \brief  value based type definition for Csm_JobPoolStartIdxOfQueueInfo */
typedef uint8 Csm_JobPoolStartIdxOfQueueInfoType;

/**   \brief  value based type definition for Csm_JobPoolUsedOfQueueInfo */
typedef boolean Csm_JobPoolUsedOfQueueInfoType;

/**   \brief  value based type definition for Csm_JobSharingOfQueueInfo */
typedef boolean Csm_JobSharingOfQueueInfoType;

/**   \brief  value based type definition for Csm_MaskedBitsOfQueueInfo */
typedef uint8 Csm_MaskedBitsOfQueueInfoType;

/**   \brief  value based type definition for Csm_QueueEndIdxOfQueueInfo */
typedef uint8 Csm_QueueEndIdxOfQueueInfoType;

/**   \brief  value based type definition for Csm_QueueStartIdxOfQueueInfo */
typedef uint8 Csm_QueueStartIdxOfQueueInfoType;

/**   \brief  value based type definition for Csm_LockOfQueueState */
typedef uint16 Csm_LockOfQueueStateType;

/**   \brief  value based type definition for Csm_QueueIdxOfQueueState */
typedef uint8 Csm_QueueIdxOfQueueStateType;

/**   \brief  value based type definition for Csm_SizeOfJob */
typedef uint8 Csm_SizeOfJobType;

/**   \brief  value based type definition for Csm_SizeOfJobInfo */
typedef uint8 Csm_SizeOfJobInfoType;

/**   \brief  value based type definition for Csm_SizeOfJobPrimitiveInfo */
typedef uint8 Csm_SizeOfJobPrimitiveInfoType;

/**   \brief  value based type definition for Csm_SizeOfJobState */
typedef uint8 Csm_SizeOfJobStateType;

/**   \brief  value based type definition for Csm_SizeOfJobTable */
typedef uint8 Csm_SizeOfJobTableType;

/**   \brief  value based type definition for Csm_SizeOfJobToObjMap */
typedef uint8 Csm_SizeOfJobToObjMapType;

/**   \brief  value based type definition for Csm_SizeOfKey */
typedef uint8 Csm_SizeOfKeyType;

/**   \brief  value based type definition for Csm_SizeOfPrimitiveInfo */
typedef uint8 Csm_SizeOfPrimitiveInfoType;

/**   \brief  value based type definition for Csm_SizeOfQueue */
typedef uint8 Csm_SizeOfQueueType;

/**   \brief  value based type definition for Csm_SizeOfQueueInfo */
typedef uint8 Csm_SizeOfQueueInfoType;

/**   \brief  value based type definition for Csm_SizeOfQueueState */
typedef uint8 Csm_SizeOfQueueStateType;

/**   \brief  value based type definition for Csm_SymKeyMaxLengthOfGeneral */
typedef uint8 Csm_SymKeyMaxLengthOfGeneralType;

/**   \brief  value based type definition for Csm_UseDeprecatedOfGeneral */
typedef boolean Csm_UseDeprecatedOfGeneralType;

/**   \brief  value based type definition for Csm_VersionInfoApiOfGeneral */
typedef boolean Csm_VersionInfoApiOfGeneralType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CsmPCStructTypes  Csm Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Csm_JobTable */
typedef struct sCsm_JobTableType
{
  Csm_CsmKeyIdIdxOfJobTableType CsmKeyIdIdxOfJobTable;  /**< the index of the 1:1 relation pointing to one of Csm_Key */
  Csm_PriorityOfJobTableType PriorityOfJobTable;  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmJobs/CsmJob/CsmJobPriority. */
  Csm_QueueRefIdxOfJobTableType QueueRefIdxOfJobTable;  /**< the index of the 1:1 relation pointing to one of Csm_QueueInfo */
} Csm_JobTableType;

/**   \brief  type used in Csm_Key */
typedef struct sCsm_KeyType
{
  Csm_CryIfKeyIdOfKeyType CryIfKeyIdOfKey;  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmKeys/CsmKey/CsmKeyRef. */
} Csm_KeyType;

/**   \brief  type used in Csm_QueueInfo */
/*! \spec weak type invariant () { 
 * (self.QueueEndIdxOfQueueInfo < Csm_GetSizeOfQueue())
 * } */
typedef struct sCsm_QueueInfoType
{
  Csm_ChannelIdOfQueueInfoType ChannelIdOfQueueInfo;  /**< Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmChannelRef. */
  Csm_JobPoolStartIdxOfQueueInfoType JobPoolStartIdxOfQueueInfo;  /**< the start index of the 0:n relation pointing to Csm_Job */
  Csm_MaskedBitsOfQueueInfoType MaskedBitsOfQueueInfo;  /**< contains bitcoded the boolean data of Csm_JobObjSynchronousUsedOfQueueInfo, Csm_JobPoolUsedOfQueueInfo, Csm_JobSharingOfQueueInfo */
  Csm_QueueEndIdxOfQueueInfoType QueueEndIdxOfQueueInfo;  /**< the end index of the 1:n relation pointing to Csm_Queue */
} Csm_QueueInfoType;

/**   \brief  type used in Csm_QueueState */
typedef struct sCsm_QueueStateType
{
  Csm_LockOfQueueStateType LockOfQueueState;
  Csm_QueueIdxOfQueueStateType QueueIdxOfQueueState;  /**< the index of the 1:1 relation pointing to Csm_Queue */
} Csm_QueueStateType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCSymbolicStructTypes  Csm Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to Csm_Queue */
typedef struct Csm_QueueStructSTag
{
  Csm_QueueElementType CsmQueue_Standard;
  Csm_QueueElementType CsmQueue_Aes;
  Csm_QueueElementType CsmQueue_Rng;
  Csm_QueueElementType CsmQueue_vHsm_Core;
} Csm_QueueStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCUnionIndexAndSymbolTypes  Csm Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access Csm_Queue in an index and symbol based style. */
typedef union Csm_QueueUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Csm_QueueElementType raw[4];
  Csm_QueueStructSType str;
} Csm_QueueUType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCRootPointerTypes  Csm Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Csm_Job */
typedef P2VAR(Crypto_JobType, TYPEDEF, CSM_VAR_NOINIT) Csm_JobPtrType;

/**   \brief  type used to point to Csm_JobInfo */
typedef P2CONST(Crypto_JobInfoType, TYPEDEF, CSM_CONST) Csm_JobInfoPtrType;

/**   \brief  type used to point to Csm_JobPrimitiveInfo */
typedef P2CONST(Crypto_JobPrimitiveInfoType, TYPEDEF, CSM_CONST) Csm_JobPrimitiveInfoPtrType;

/**   \brief  type used to point to Csm_JobState */
typedef P2VAR(Csm_JobStateType, TYPEDEF, CSM_VAR_NOINIT) Csm_JobStatePtrType;

/**   \brief  type used to point to Csm_JobTable */
typedef P2CONST(Csm_JobTableType, TYPEDEF, CSM_CONST) Csm_JobTablePtrType;

/**   \brief  type used to point to Csm_JobToObjMap */
typedef P2VAR(Csm_SizeOfJobType, TYPEDEF, CSM_VAR_NOINIT) Csm_JobToObjMapPtrType;

/**   \brief  type used to point to Csm_Key */
typedef P2CONST(Csm_KeyType, TYPEDEF, CSM_CONST) Csm_KeyPtrType;

/**   \brief  type used to point to Csm_PrimitiveInfo */
typedef P2CONST(Crypto_PrimitiveInfoType, TYPEDEF, CSM_CONST) Csm_PrimitiveInfoPtrType;

/**   \brief  type used to point to Csm_Queue */
typedef P2VAR(Csm_QueueElementType, TYPEDEF, CSM_VAR_NOINIT) Csm_QueuePtrType;

/**   \brief  type used to point to Csm_QueueInfo */
typedef P2CONST(Csm_QueueInfoType, TYPEDEF, CSM_CONST) Csm_QueueInfoPtrType;

/**   \brief  type used to point to Csm_QueueState */
typedef P2VAR(Csm_QueueStateType, TYPEDEF, CSM_VAR_NOINIT) Csm_QueueStatePtrType;

/** 
  \}
*/ 

/** 
  \defgroup  CsmPCRootValueTypes  Csm Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Csm_PCConfig */
typedef struct sCsm_PCConfigType
{
  uint8 Csm_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Csm_PCConfigType;

typedef Csm_PCConfigType Csm_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CsmPBValueTypes  Csm Value Types (POST_BUILD)
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
  \defgroup  CsmPBRootValueTypes  Csm Root Value Types (POST_BUILD)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Csm_JobInfo
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_JobInfoType, CSM_CONST) Csm_JobInfo[5];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobPrimitiveInfo
**********************************************************************************************************************/
/** 
  \var    Csm_JobPrimitiveInfo
  \brief  const uint32 callbackId; const Crypto_PrimitiveInfoType* primitiveInfo; const uint32 secureCounterId; const uint32 cryIfKeyId; const Crypto_ProcessingType processingType; const bool callbackUpdateNotification
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_JobPrimitiveInfoType, CSM_CONST) Csm_JobPrimitiveInfo[5];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobTable
**********************************************************************************************************************/
/** 
  \var    Csm_JobTable
  \brief  Contains parameters of /MICROSAR/Csm/CsmJobs/CsmJob.
  \details
  Element        Description
  CsmKeyIdIdx    the index of the 1:1 relation pointing to one of Csm_Key
  Priority       Contains values of DefinitionRef: /MICROSAR/Csm/CsmJobs/CsmJob/CsmJobPriority.
  QueueRefIdx    the index of the 1:1 relation pointing to one of Csm_QueueInfo
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Csm_JobTableType, CSM_CONST) Csm_JobTable[5];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Key
**********************************************************************************************************************/
/** 
  \var    Csm_Key
  \brief  Contains parameters of /AUTOSAR/EcucDefs/Csm/CsmKeys/CsmKey.
  \details
  Element       Description
  CryIfKeyId    Contains values of DefinitionRef: /MICROSAR/Csm/CsmKeys/CsmKey/CsmKeyRef.
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Csm_KeyType, CSM_CONST) Csm_Key[64];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_PrimitiveInfo
**********************************************************************************************************************/
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_PrimitiveInfoType, CSM_CONST) Csm_PrimitiveInfo[5];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_QueueInfo
**********************************************************************************************************************/
/** 
  \var    Csm_QueueInfo
  \brief  Contains parameters of /AUTOSAR/EcucDefs/Csm/CsmQueues/CsmQueue.
  \details
  Element            Description
  ChannelId          Contains values of DefinitionRef: /MICROSAR/Csm/CsmQueues/CsmQueue/CsmChannelRef.
  JobPoolStartIdx    the start index of the 0:n relation pointing to Csm_Job
  MaskedBits         contains bitcoded the boolean data of Csm_JobObjSynchronousUsedOfQueueInfo, Csm_JobPoolUsedOfQueueInfo, Csm_JobSharingOfQueueInfo
  QueueEndIdx        the end index of the 1:n relation pointing to Csm_Queue
*/ 
#define CSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Csm_QueueInfoType, CSM_CONST) Csm_QueueInfo[4];
#define CSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Job
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_JobType, CSM_VAR_NOINIT) Csm_Job[4];
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobState
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Csm_JobStateType, CSM_VAR_NOINIT) Csm_JobState[5];
#define CSM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_JobToObjMap
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Csm_SizeOfJobType, CSM_VAR_NOINIT) Csm_JobToObjMap[5];
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_Queue
**********************************************************************************************************************/
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Csm_QueueUType, CSM_VAR_NOINIT) Csm_Queue;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Csm_QueueState
**********************************************************************************************************************/
/** 
  \var    Csm_QueueState
  \brief  Stores state of the asynchronous job queue.
  \details
  Element     Description
  Lock    
  QueueIdx    the index of the 1:1 relation pointing to Csm_Queue
*/ 
#define CSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Csm_QueueStateType, CSM_VAR_NOINIT) Csm_QueueState[4];
#define CSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/




/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/








#endif /* CSM_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Csm_Cfg.h
 *********************************************************************************************************************/


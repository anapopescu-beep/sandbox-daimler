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
 *            Module: Crypto_30_vHsm
 *           Program: FBL Daimler SLP11 (FBL_Daimler_SLP11)
 *          Customer: Mercedes-Benz AG
 *       Expiry Date: Not restricted
 *  Ordered Derivat.:  TC399
 *    License Scope : The usage is restricted to CBD2200332_D02
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Crypto_30_vHsm_Cfg.h
 *   Generation Time: 2023-08-16 14:36:31
 *           Project: CBD2000614_fblbm_Upd - Version 1.0
 *          Delivery: CBD2200332_D02
 *      Tool Version: DaVinci Configurator Classic 5.25.50 SP5
 *
 *
 *********************************************************************************************************************/


#if !defined (CRYPTO_30_VHSM_CFG_H)
#define CRYPTO_30_VHSM_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Crypto_30_vHsm_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef CRYPTO_30_VHSM_USE_DUMMY_STATEMENT
#define CRYPTO_30_VHSM_USE_DUMMY_STATEMENT STD_OFF /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_VHSM_DUMMY_STATEMENT
#define CRYPTO_30_VHSM_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_VHSM_DUMMY_STATEMENT_CONST
#define CRYPTO_30_VHSM_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CRYPTO_30_VHSM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CRYPTO_30_VHSM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CRYPTO_30_VHSM_ATOMIC_VARIABLE_ACCESS
#define CRYPTO_30_VHSM_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CRYPTO_30_VHSM_PROCESSOR_TC322L
#define CRYPTO_30_VHSM_PROCESSOR_TC322L
#endif
#ifndef CRYPTO_30_VHSM_COMP_TASKING
#define CRYPTO_30_VHSM_COMP_TASKING
#endif
#ifndef CRYPTO_30_VHSM_GEN_GENERATOR_MSR
#define CRYPTO_30_VHSM_GEN_GENERATOR_MSR
#endif
#ifndef CRYPTO_30_VHSM_CPUTYPE_BITORDER_LSB2MSB
#define CRYPTO_30_VHSM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CRYPTO_30_VHSM_CONFIGURATION_VARIANT_PRECOMPILE
#define CRYPTO_30_VHSM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CRYPTO_30_VHSM_CONFIGURATION_VARIANT_LINKTIME
#define CRYPTO_30_VHSM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CRYPTO_30_VHSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CRYPTO_30_VHSM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CRYPTO_30_VHSM_CONFIGURATION_VARIANT
#define CRYPTO_30_VHSM_CONFIGURATION_VARIANT CRYPTO_30_VHSM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CRYPTO_30_VHSM_POSTBUILD_VARIANT_SUPPORT
#define CRYPTO_30_VHSM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#ifdef _MICROSOFT_C_VTT_
#define CRYPTO_30_VHSM_USE_VTT STD_ON
#else
#define CRYPTO_30_VHSM_USE_VTT STD_OFF
#endif
#define CRYPTO_30_VHSM_NOBUFFERING_ENABLED                                                          STD_OFF
/* Microsar Define Block for Boolean and Integers */
#define CRYPTO_30_VHSM_VERSION_INFO_API                                                             STD_OFF 
#define CRYPTO_30_VHSM_KEY_ELEMENT_DELETE_SUPPORT                                                   STD_ON 
#define CRYPTO_30_VHSM_INTERRUPT_MODE                                                               STD_OFF 
#define CRYPTO_30_VHSM_IPC_CHANNELS                                                                 2u 
#define CRYPTO_30_VHSM_IPC_PROTOCOL_VERSION                                                         3u 
#define CRYPTO_30_VHSM_REDIRECTION                                                                  STD_OFF 
#define CRYPTO_30_VHSM_IPC_MAC_JOB_OPTIMIZATION                                                     STD_OFF 
#define CRYPTO_30_VHSM_DET_INSTANCE_MASK                                                            0x00u 
#define CRYPTO_30_VHSM_KEY_DERIVE_JOB_SUPPORT                                                       STD_ON 
#define CRYPTO_30_VHSM_HOST2_HSM_ADDRESS                                                            0xF0040038u 
#define CRYPTO_30_VHSM_HSM2_HOST_ADDRESS                                                            0xF0040034u 
#define CRYPTO_30_VHSM_IPC_INSTANCE_ID                                                              0u 
#define CRYPTO_30_VHSM_IPC_INITIALIZATION                                                           STD_ON 
#define CRYPTO_30_VHSM_JOB_RESPONSE_INTERRUPT_FLAG_CLEAR_ADDRESS                                    0xF0040028u 
#define CRYPTO_30_VHSM_JOB_RESPONSE_INTERRUPT_FLAG_CLEAR_MASK                                       0x00000001u 
#define CRYPTO_30_VHSM_JOB_RESPONSE_INTERRUPT_FLAG_CLEAR_VALUE                                      0x01u 
#define CRYPTO_30_VHSM_JOB_RESPONSE_INTERRUPT_FLAG_CLEARING                                         STD_ON 
#define CRYPTO_30_VHSM_JOB_REQUEST_INTERRUPT_FLAG_SET_ADDRESS                                       0xF0040020u 
#define CRYPTO_30_VHSM_JOB_REQUEST_INTERRUPT_FLAG_SET_MASK                                          0x00000001u 
#define CRYPTO_30_VHSM_JOB_REQUEST_INTERRUPT_FLAG_SETTING                                           STD_ON 

/* Symbolic Name Define Block */
#define CryptoConf_CryptoDriverObject_Crypto_30_vHsm_Core                                           0u 
#define CryptoConf_CryptoDriverObject_Crypto_30_vHsm_Hwa                                            1u 
#define CryptoConf_CryptoDriverObject_Crypto_30_vHsm_Hwa_HighPrio                                   2u 
#define CryptoConf_CryptoDriverObject_Crypto_30_vHsm_KeyM_LibCv                                     4u 
#define CryptoConf_CryptoDriverObject_Crypto_30_vHsm_KeyManagement                                  5u 
#define CryptoConf_CryptoDriverObject_Crypto_30_vHsm_LibCv                                          6u 
#define CryptoConf_CryptoDriverObject_Crypto_30_vHsm_LibCv_HighPrio                                 7u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_CryptoKeyElement_Cert_wPersist             0u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_KeyM_CertificateData                       0u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Ssa_BackendCert                            0u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Ssa_RootCert                               0u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_vHsm_Core_vHsmLog_EventId                        0u 
#define CryptoConf_CryptoKeyElement_vHsmDummyKeyElement                                             0u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Cipher_Key                                 1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Fbl_Decrypt_Aes128_Key                     1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Fbl_SecurityAccess_Ed25519_Key             1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Fbl_Signature_Ed25519_Key                  1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_KeyExchange_SharedValue                    1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_KeyGenerate_Key                            1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Signature_Key                              1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Signature_Key_replacementAuthority         1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Ssa_Cipher_Key                             1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Ssa_MacKey_nonPersisting                   1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Ssa_Mac_Key                                1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Ssa_SecurityAccesPublicKey                 1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Ssa_TrustModelEcuPublicCsr_StagingKey      1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Ssa_TrustModelEcuPublic_LiveKey            1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Ssa_TrustModelPrivateEcu_LiveKey           1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Ssa_TrustModel_Csr_Key_NonPersisting_Element 1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_vHsm_Version                               1u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Ssa_MacKey_Hash_nonPersisting              2u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Ssa_Mac_Proof                              2u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Ssa_SharedSecretHash                       2u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Random_Seed                                3u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Random_Seed_Nist_800_90A_DRBG_AES128       3u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_Hwa_Hash_Result                                  4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128  4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Random_Algorithm_Nist_800_90A_DRBG_AES128_DF 4u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_Hwa_Random_Algorithm_Fips186_Sha1                5u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Cipher_IV                                  5u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Fbl_Decrypt_Aes128_Iv                      5u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Ssa_Cipher_IV                              5u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_Hwa_Random_Seed                                  6u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Cipher_Proof                               6u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_Hwa_RomKey                                       7u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_KeyExchange_Base                           8u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_KeyExchange_PrivKey                        9u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_KeyExchange_OwnPubKey                      10u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_KeyExchange_Algorithm_X25519               12u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_KeyGenerate_Algorithm_Ed25519              17u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_CryptoKeyElement_DummyWorkaround_RandomSeedSize 999u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Random_PrivateString                       3015u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Random_AdditionalInput                     3016u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Ssa_Random_Nonce                           3017u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_Random_Reseed_Counter                      3018u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_vHsm_Core_vHsmInfo_Version                       3020u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_vHsm_Info_Uid                              3021u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_vHsm_Core_vHsmInfo_PerformPersist                3022u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_LibCv_vHsm_Info_ErrorLog                         3023u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_vHsm_Core_vHsmInfo_SecureBootEnd                 3028u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_Hwa_vHsm_Hal_FlashOperation                      3032u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_vHsm_Core_vHsmInfo_PerformRepersist              3036u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_vHsm_Core_vHsmInfo_SecureBootResult              3037u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_vHsm_Core_vHsmInfo_StartFirmwareUpdater          3038u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_KeyM_KeyM_Certificate                            3080u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_KeyM_KeyM_GetStatus                              3081u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_KeyM_KeyM_VerifyCertificate                      3082u 
#define CryptoConf_CryptoKeyElement_Crypto_30_vHsm_KeyM_KeyM_VerifyCertificates                     3083u 
#define CryptoConf_CryptoKey_CryIfKey_Fbl_Decrypt_Aes128                                            0u 
#define CryptoConf_CryptoKey_CryIfKey_Fbl_HashDummy                                                 1u 
#define CryptoConf_CryptoKey_CryIfKey_Fbl_Rng_Fips186                                               2u 
#define CryptoConf_CryptoKey_CryIfKey_Fbl_SecurityAccess_Ed25519                                    3u 
#define CryptoConf_CryptoKey_CryIfKey_Fbl_Signature_Ed25519                                         4u 
#define CryptoConf_CryptoKey_CryIfKey_KeyMCertificate_OSSL_X509_ECDSA_P384_CA                       5u 
#define CryptoConf_CryptoKey_CryIfKey_KeyMCertificate_OSSL_X509_ECDSA_P384_IA                       6u 
#define CryptoConf_CryptoKey_CryIfKey_Ssa_SignatureRamKey_replacementAuthority                      7u 
#define CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModelBackendCert_inHSM                               8u 
#define CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModelEcuCert_inHSM                                   9u 
#define CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModelIntermediateCert_inHSM                          10u 
#define CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModelPrivateEcuUnique_StagingKey                     11u 
#define CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModelRootCert_inHSM                                  12u 
#define CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPrivateKey                              13u 
#define CryptoConf_CryptoKey_CryIfKey_Ssa_TrustModel_Ecu_CsrPublicKey                               14u 
#define CryptoConf_CryptoKey_CryIfKey_vHsm_Info                                                     15u 
#define CryptoConf_CryptoKey_KeyM_Cert_Root                                                         16u 
#define CryptoConf_CryptoKey_KeyM_ECC_Intermediate                                                  17u 
#define CryptoConf_CryptoKey_KeyM_ECC_Root                                                          18u 
#define CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelBackend                                    19u 
#define CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelBackendPeer                                20u 
#define CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelEcuPeer                                    21u 
#define CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelIntermediate                               22u 
#define CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelIntermediatePeer                           23u 
#define CryptoConf_CryptoKey_KeyM_SigVerifyKey_TrustModelRoot                                       24u 
#define CryptoConf_CryptoKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu03_secured_044596e0_Tx                 25u 
#define CryptoConf_CryptoKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu20_secured_393d7a18_Tx                 26u 
#define CryptoConf_CryptoKey_SSA_SecOC_Int_MacGen_COM_C04_Pdu21_secured_2e466e5b_Tx                 27u 
#define CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu20_secured_3ef6961f_Rx              28u 
#define CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_COM_C0X_Pdu21_secured_298d825c_Rx              29u 
#define CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_DI_OdoSpeedometer                              30u 
#define CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_Ign_Stat                                       31u 
#define CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_PN14_Master_Stat1                              32u 
#define CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_PT4_PTCoor4                                    33u 
#define CryptoConf_CryptoKey_SSA_SecOC_Int_MacVerify_VehSpd_8                                       34u 
#define CryptoConf_CryptoKey_Ssa_AesRamKey                                                          35u 
#define CryptoConf_CryptoKey_Ssa_Authentication                                                     36u 
#define CryptoConf_CryptoKey_Ssa_BackendCert                                                        37u 
#define CryptoConf_CryptoKey_Ssa_PduKeysMac                                                         38u 
#define CryptoConf_CryptoKey_Ssa_RandomSeed                                                         39u 
#define CryptoConf_CryptoKey_Ssa_RealTime                                                           40u 
#define CryptoConf_CryptoKey_Ssa_RootCert                                                           41u 
#define CryptoConf_CryptoKey_Ssa_SecurityAccessPublicKey                                            42u 
#define CryptoConf_CryptoKey_Ssa_SharedSecretExchangeKey                                            43u 
#define CryptoConf_CryptoKey_Ssa_SharedSecretHash                                                   44u 
#define CryptoConf_CryptoKey_Ssa_SignatureRamKey                                                    45u 
#define CryptoConf_CryptoKey_Ssa_TickCount                                                          46u 
#define CryptoConf_CryptoKey_Ssa_TrustModelEcuPublicCsr_StagingKey                                  47u 
#define CryptoConf_CryptoKey_vHsm_Custom                                                            48u 
#define CryptoConf_CryptoKey_Ssa_TrustModelEcuPublic_LiveKey                                        49u 
#define CryptoConf_CryptoKey_Ssa_TrustModelPrivateEcu_LiveKey                                       50u 
#define CryptoConf_CryptoKey_Ssa_VIN                                                                51u 
#define CryptoConf_CryptoKey_vHSM_Custom_HSM_Version                                                52u 
#define CryptoConf_CryptoKey_vHsm_Hardware                                                          53u 
#define CryptoConf_CryptoKey_vHsm_Info                                                              54u 
#define CryptoConf_CryptoKey_vHsm_Log                                                               56u 
#define CryptoConf_CryptoKey_vHsm_RomKey0                                                           57u 
#define CryptoConf_CryptoKey_vHsm_TRNG                                                              60u 
#define CryptoConf_CryptoKey_vHsm_FirmwareUpdate_Signature                                          61u 

#ifndef CRYPTO_30_VHSM_DEV_ERROR_DETECT
#define CRYPTO_30_VHSM_DEV_ERROR_DETECT STD_ON
#endif
#ifndef CRYPTO_30_VHSM_DEV_ERROR_REPORT
#define CRYPTO_30_VHSM_DEV_ERROR_REPORT STD_ON
#endif
#define CRYPTO_30_VHSM_SERVICE_MAC_VERIFY                                                           STD_ON
#define CRYPTO_30_VHSM_SERVICE_MAC_GENERATE                                                         STD_ON
#define CRYPTO_30_VHSM_SERVICE_SIGNATURE_VERIFY                                                     STD_ON
#define CRYPTO_30_VHSM_SERVICE_SIGNATURE_GENERATE                                                   STD_ON
#define CRYPTO_30_VHSM_SERVICE_ENCRYPT                                                              STD_ON
#define CRYPTO_30_VHSM_SERVICE_DECRYPT                                                              STD_ON
#define CRYPTO_30_VHSM_SERVICE_AEADENCRYPT                                                          STD_ON
#define CRYPTO_30_VHSM_SERVICE_AEADDECRYPT                                                          STD_ON
#define CRYPTO_30_VHSM_SERVICE_HASH                                                                 STD_ON
#define CRYPTO_30_VHSM_SERVICE_RANDOM                                                               STD_ON
#define CRYPTO_30_VHSM_SERVICE_KEY_SET_VALID                                                        STD_OFF
#define CRYPTO_30_VHSM_SERVICE_RANDOM_SEED                                                          STD_OFF
#define CRYPTO_30_VHSM_SERVICE_KEY_GENERATE                                                         STD_ON
#define CRYPTO_30_VHSM_SERVICE_KEY_DERIVE                                                           STD_OFF
#define CRYPTO_30_VHSM_SERVICE_KEY_EXCHANGE_CALC_PUBVAL                                             STD_OFF
#define CRYPTO_30_VHSM_SERVICE_KEY_EXCHANGE_CALC_SECRET                                             STD_OFF
#define CRYPTO_30_VHSM_SERVICE_CERIFICATE_PARSE                                                     STD_OFF
#define CRYPTO_30_VHSM_SERVICE_CERTIFICATE_VERIFY                                                   STD_OFF
#define CRYPTO_30_VHSM_IPC_PROTOCOL_INFO_SIZE                                                       12u
#define CRYPTO_30_VHSM_AREA_HSM_READ_ACCESS                                                         0x00u
#define CRYPTO_30_VHSM_AREA_HSM_READWRITE_ACCESS                                                    0x01u
#define CRYPTO_30_VHSM_READWRITE_AVAILABLE                                                          STD_ON
#define CRYPTO_30_VHSM_SUPPORT_SAVE_RESTORE_CONTEXT                                                 STD_OFF


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_vHsmPCDataSwitches  Crypto_30_vHsm Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CRYPTO_30_VHSM_CHANNELSTATE                                                                 STD_ON
#define CRYPTO_30_VHSM_DETINSTANCEMASKOFVHSM                                                        STD_ON
#define CRYPTO_30_VHSM_DRIVEROBJECTLOCK                                                             STD_ON
#define CRYPTO_30_VHSM_EXPECTEDCOMPATIBILITYVERSION                                                 STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_VHSM_FINALMAGICNUMBER                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_VHSM_FLAGCLEARADDRESSOFJOBRESPONSEINTERRUPT                                       STD_ON
#define CRYPTO_30_VHSM_FLAGCLEARMASKOFJOBRESPONSEINTERRUPT                                          STD_ON
#define CRYPTO_30_VHSM_FLAGCLEARVALUEOFJOBRESPONSEINTERRUPT                                         STD_ON
#define CRYPTO_30_VHSM_FLAGCLEARINGOFJOBRESPONSEINTERRUPT                                           STD_ON
#define CRYPTO_30_VHSM_FLAGSETADDRESSOFJOBREQUESTINTERRUPT                                          STD_ON
#define CRYPTO_30_VHSM_FLAGSETMASKOFJOBREQUESTINTERRUPT                                             STD_ON
#define CRYPTO_30_VHSM_FLAGSETTINGOFJOBREQUESTINTERRUPT                                             STD_ON
#define CRYPTO_30_VHSM_GENERATORCOMPATIBILITYVERSION                                                STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_VHSM_HOST2HSMADDRESSOFVHSM                                                        STD_ON
#define CRYPTO_30_VHSM_HSM2HOSTADDRESSOFVHSM                                                        STD_ON
#define CRYPTO_30_VHSM_INITDATAHASHCODE                                                             STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_VHSM_INTERRUPTMODEOFVHSM                                                          STD_ON
#define CRYPTO_30_VHSM_IPCCHANNELSOFVHSM                                                            STD_ON
#define CRYPTO_30_VHSM_IPCINITIALIZATIONOFVHSM                                                      STD_ON
#define CRYPTO_30_VHSM_IPCINSTANCEIDOFVHSM                                                          STD_ON
#define CRYPTO_30_VHSM_IPCMACJOBOPTIMIZATIONOFVHSM                                                  STD_ON
#define CRYPTO_30_VHSM_IPCPROTOCOLVERSIONOFVHSM                                                     STD_ON
#define CRYPTO_30_VHSM_JOBREQUEST                                                                   STD_ON
#define CRYPTO_30_VHSM_CANCELOFJOBREQUEST                                                           STD_ON
#define CRYPTO_30_VHSM_COUNTEROFJOBREQUEST                                                          STD_ON
#define CRYPTO_30_VHSM_CRYPTOJOBOFJOBREQUEST                                                        STD_ON
#define CRYPTO_30_VHSM_JOBSTATEOFJOBREQUEST                                                         STD_ON
#define CRYPTO_30_VHSM_KEYMJOBOFJOBREQUEST                                                          STD_ON
#define CRYPTO_30_VHSM_KINDOFJOBREQUEST                                                             STD_ON
#define CRYPTO_30_VHSM_LOCKOFJOBREQUEST                                                             STD_ON
#define CRYPTO_30_VHSM_OUTPUTOFFSETOFJOBREQUEST                                                     STD_ON
#define CRYPTO_30_VHSM_PROCESSINGTYPEOFJOBREQUEST                                                   STD_ON
#define CRYPTO_30_VHSM_RESULTOFJOBREQUEST                                                           STD_ON
#define CRYPTO_30_VHSM_SECONDARYOUTPUTOFFSETOFJOBREQUEST                                            STD_ON
#define CRYPTO_30_VHSM_STATEOFJOBREQUEST                                                            STD_ON
#define CRYPTO_30_VHSM_TRIMMEDOUTPUTBUFFEROFJOBREQUEST                                              STD_ON
#define CRYPTO_30_VHSM_USEDBUFFEROFJOBREQUEST                                                       STD_ON
#define CRYPTO_30_VHSM_KEYDERIVEJOBSUPPORTOFVHSM                                                    STD_ON
#define CRYPTO_30_VHSM_KEYELEMENTDELETESUPPORTOFVHSM                                                STD_ON
#define CRYPTO_30_VHSM_KEYMGMOBJ                                                                    STD_ON
#define CRYPTO_30_VHSM_OBJECTINFOIDXOFKEYMGMOBJ                                                     STD_ON
#define CRYPTO_30_VHSM_MAINFUNCTIONPERIODOFGENERAL                                                  STD_ON
#define CRYPTO_30_VHSM_MEMORYAREA                                                                   STD_ON
#define CRYPTO_30_VHSM_AREASTARTOFMEMORYAREA                                                        STD_ON
#define CRYPTO_30_VHSM_AREASTOPOFMEMORYAREA                                                         STD_ON
#define CRYPTO_30_VHSM_AREATYPEOFMEMORYAREA                                                         STD_ON
#define CRYPTO_30_VHSM_OBJMAP                                                                       STD_ON
#define CRYPTO_30_VHSM_OBJECTINFOIDXOFOBJMAP                                                        STD_ON
#define CRYPTO_30_VHSM_OBJECTINFOUSEDOFOBJMAP                                                       STD_ON
#define CRYPTO_30_VHSM_OBJECTINFO                                                                   STD_ON
#define CRYPTO_30_VHSM_BUFFERUSEDOFOBJECTINFO                                                       STD_ON
#define CRYPTO_30_VHSM_HSMOBJIDOFOBJECTINFO                                                         STD_ON
#define CRYPTO_30_VHSM_SHAREDDATABUFFERENDIDXOFOBJECTINFO                                           STD_ON
#define CRYPTO_30_VHSM_SHAREDDATABUFFERSTARTIDXOFOBJECTINFO                                         STD_ON
#define CRYPTO_30_VHSM_SHAREDDATABUFFERUSEDOFOBJECTINFO                                             STD_ON
#define CRYPTO_30_VHSM_OUTPUTLENGTHPTRDATABUFFER                                                    STD_ON
#define CRYPTO_30_VHSM_REDIRECTIONOFVHSM                                                            STD_ON
#define CRYPTO_30_VHSM_SECONDARYOUTPUTLENGTHPTRDATABUFFER                                           STD_ON
#define CRYPTO_30_VHSM_SHAREDDATABUFFER                                                             STD_ON
#define CRYPTO_30_VHSM_SIZEOFCHANNELSTATE                                                           STD_ON
#define CRYPTO_30_VHSM_SIZEOFDRIVEROBJECTLOCK                                                       STD_ON
#define CRYPTO_30_VHSM_SIZEOFJOBREQUEST                                                             STD_ON
#define CRYPTO_30_VHSM_SIZEOFKEYMGMOBJ                                                              STD_ON
#define CRYPTO_30_VHSM_SIZEOFMEMORYAREA                                                             STD_ON
#define CRYPTO_30_VHSM_SIZEOFOBJMAP                                                                 STD_ON
#define CRYPTO_30_VHSM_SIZEOFOBJECTINFO                                                             STD_ON
#define CRYPTO_30_VHSM_SIZEOFOUTPUTLENGTHPTRDATABUFFER                                              STD_ON
#define CRYPTO_30_VHSM_SIZEOFSECONDARYOUTPUTLENGTHPTRDATABUFFER                                     STD_ON
#define CRYPTO_30_VHSM_SIZEOFSHAREDDATABUFFER                                                       STD_ON
#define CRYPTO_30_VHSM_SIZEOFVERIFYPTRDATABUFFER                                                    STD_ON
#define CRYPTO_30_VHSM_VERIFYPTRDATABUFFER                                                          STD_ON
#define CRYPTO_30_VHSM_VERSIONINFOAPIOFGENERAL                                                      STD_ON
#define CRYPTO_30_VHSM_WAITLOOPCALLOUTOFVHSM                                                        STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_WaitLoopCalloutOfvHsm' Reason: 'Parameter is not configured!' */
#define CRYPTO_30_VHSM_PCCONFIG                                                                     STD_ON
#define CRYPTO_30_VHSM_CHANNELSTATEOFPCCONFIG                                                       STD_ON
#define CRYPTO_30_VHSM_DETINSTANCEMASKOFVHSMOFPCCONFIG                                              STD_ON
#define CRYPTO_30_VHSM_DRIVEROBJECTLOCKOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_VHSM_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                       STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_VHSM_FINALMAGICNUMBEROFPCCONFIG                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_VHSM_FLAGCLEARADDRESSOFJOBRESPONSEINTERRUPTOFPCCONFIG                             STD_ON
#define CRYPTO_30_VHSM_FLAGCLEARMASKOFJOBRESPONSEINTERRUPTOFPCCONFIG                                STD_ON
#define CRYPTO_30_VHSM_FLAGCLEARVALUEOFJOBRESPONSEINTERRUPTOFPCCONFIG                               STD_ON
#define CRYPTO_30_VHSM_FLAGCLEARINGOFJOBRESPONSEINTERRUPTOFPCCONFIG                                 STD_ON
#define CRYPTO_30_VHSM_FLAGSETADDRESSOFJOBREQUESTINTERRUPTOFPCCONFIG                                STD_ON
#define CRYPTO_30_VHSM_FLAGSETMASKOFJOBREQUESTINTERRUPTOFPCCONFIG                                   STD_ON
#define CRYPTO_30_VHSM_FLAGSETTINGOFJOBREQUESTINTERRUPTOFPCCONFIG                                   STD_ON
#define CRYPTO_30_VHSM_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                      STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define CRYPTO_30_VHSM_HOST2HSMADDRESSOFVHSMOFPCCONFIG                                              STD_ON
#define CRYPTO_30_VHSM_HSM2HOSTADDRESSOFVHSMOFPCCONFIG                                              STD_ON
#define CRYPTO_30_VHSM_INITDATAHASHCODEOFPCCONFIG                                                   STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CRYPTO_30_VHSM_INTERRUPTMODEOFVHSMOFPCCONFIG                                                STD_ON
#define CRYPTO_30_VHSM_IPCCHANNELSOFVHSMOFPCCONFIG                                                  STD_ON
#define CRYPTO_30_VHSM_IPCINITIALIZATIONOFVHSMOFPCCONFIG                                            STD_ON
#define CRYPTO_30_VHSM_IPCINSTANCEIDOFVHSMOFPCCONFIG                                                STD_ON
#define CRYPTO_30_VHSM_IPCMACJOBOPTIMIZATIONOFVHSMOFPCCONFIG                                        STD_ON
#define CRYPTO_30_VHSM_IPCPROTOCOLVERSIONOFVHSMOFPCCONFIG                                           STD_ON
#define CRYPTO_30_VHSM_JOBREQUESTOFPCCONFIG                                                         STD_ON
#define CRYPTO_30_VHSM_KEYDERIVEJOBSUPPORTOFVHSMOFPCCONFIG                                          STD_ON
#define CRYPTO_30_VHSM_KEYELEMENTDELETESUPPORTOFVHSMOFPCCONFIG                                      STD_ON
#define CRYPTO_30_VHSM_KEYMGMOBJOFPCCONFIG                                                          STD_ON
#define CRYPTO_30_VHSM_MAINFUNCTIONPERIODOFGENERALOFPCCONFIG                                        STD_ON
#define CRYPTO_30_VHSM_MEMORYAREAOFPCCONFIG                                                         STD_ON
#define CRYPTO_30_VHSM_OBJMAPOFPCCONFIG                                                             STD_ON
#define CRYPTO_30_VHSM_OBJECTINFOOFPCCONFIG                                                         STD_ON
#define CRYPTO_30_VHSM_OUTPUTLENGTHPTRDATABUFFEROFPCCONFIG                                          STD_ON
#define CRYPTO_30_VHSM_REDIRECTIONOFVHSMOFPCCONFIG                                                  STD_ON
#define CRYPTO_30_VHSM_SECONDARYOUTPUTLENGTHPTRDATABUFFEROFPCCONFIG                                 STD_ON
#define CRYPTO_30_VHSM_SHAREDDATABUFFEROFPCCONFIG                                                   STD_ON
#define CRYPTO_30_VHSM_SIZEOFCHANNELSTATEOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_VHSM_SIZEOFDRIVEROBJECTLOCKOFPCCONFIG                                             STD_ON
#define CRYPTO_30_VHSM_SIZEOFJOBREQUESTOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_VHSM_SIZEOFKEYMGMOBJOFPCCONFIG                                                    STD_ON
#define CRYPTO_30_VHSM_SIZEOFMEMORYAREAOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_VHSM_SIZEOFOBJMAPOFPCCONFIG                                                       STD_ON
#define CRYPTO_30_VHSM_SIZEOFOBJECTINFOOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_VHSM_SIZEOFOUTPUTLENGTHPTRDATABUFFEROFPCCONFIG                                    STD_ON
#define CRYPTO_30_VHSM_SIZEOFSECONDARYOUTPUTLENGTHPTRDATABUFFEROFPCCONFIG                           STD_ON
#define CRYPTO_30_VHSM_SIZEOFSHAREDDATABUFFEROFPCCONFIG                                             STD_ON
#define CRYPTO_30_VHSM_SIZEOFVERIFYPTRDATABUFFEROFPCCONFIG                                          STD_ON
#define CRYPTO_30_VHSM_VERIFYPTRDATABUFFEROFPCCONFIG                                                STD_ON
#define CRYPTO_30_VHSM_VERSIONINFOAPIOFGENERALOFPCCONFIG                                            STD_ON
#define CRYPTO_30_VHSM_WAITLOOPCALLOUTOFVHSMOFPCCONFIG                                              STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.WaitLoopCalloutOfvHsm' Reason: 'Parameter is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCMinNumericValueDefines  Crypto_30_vHsm Min Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the minimum value in numerical based data.
  \{
*/ 
#define CRYPTO_30_VHSM_MIN_CHANNELSTATE                                                             0u
#define CRYPTO_30_VHSM_MIN_DRIVEROBJECTLOCK                                                         0u
#define CRYPTO_30_VHSM_MIN_COUNTEROFJOBREQUEST                                                      0u
#define CRYPTO_30_VHSM_MIN_KINDOFJOBREQUEST                                                         0u
#define CRYPTO_30_VHSM_MIN_OUTPUTOFFSETOFJOBREQUEST                                                 0u
#define CRYPTO_30_VHSM_MIN_PROCESSINGTYPEOFJOBREQUEST                                               0u
#define CRYPTO_30_VHSM_MIN_RESULTOFJOBREQUEST                                                       0u
#define CRYPTO_30_VHSM_MIN_SECONDARYOUTPUTOFFSETOFJOBREQUEST                                        0u
#define CRYPTO_30_VHSM_MIN_STATEOFJOBREQUEST                                                        0u
#define CRYPTO_30_VHSM_MIN_USEDBUFFEROFJOBREQUEST                                                   0u
#define CRYPTO_30_VHSM_MIN_OUTPUTLENGTHPTRDATABUFFER                                                0u
#define CRYPTO_30_VHSM_MIN_SECONDARYOUTPUTLENGTHPTRDATABUFFER                                       0u
#define CRYPTO_30_VHSM_MIN_SHAREDDATABUFFER                                                         0u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCMaxNumericValueDefines  Crypto_30_vHsm Max Numeric Value Defines (PRE_COMPILE)
  \brief  These defines are used to implement against the maximum value in numerical based data.
  \{
*/ 
#define CRYPTO_30_VHSM_MAX_CHANNELSTATE                                                             255u
#define CRYPTO_30_VHSM_MAX_DRIVEROBJECTLOCK                                                         4294967295u
#define CRYPTO_30_VHSM_MAX_COUNTEROFJOBREQUEST                                                      255u
#define CRYPTO_30_VHSM_MAX_KINDOFJOBREQUEST                                                         255u
#define CRYPTO_30_VHSM_MAX_OUTPUTOFFSETOFJOBREQUEST                                                 4294967295u
#define CRYPTO_30_VHSM_MAX_PROCESSINGTYPEOFJOBREQUEST                                               255u
#define CRYPTO_30_VHSM_MAX_RESULTOFJOBREQUEST                                                       255u
#define CRYPTO_30_VHSM_MAX_SECONDARYOUTPUTOFFSETOFJOBREQUEST                                        4294967295u
#define CRYPTO_30_VHSM_MAX_STATEOFJOBREQUEST                                                        255u
#define CRYPTO_30_VHSM_MAX_USEDBUFFEROFJOBREQUEST                                                   4294967295u
#define CRYPTO_30_VHSM_MAX_OUTPUTLENGTHPTRDATABUFFER                                                4294967295u
#define CRYPTO_30_VHSM_MAX_SECONDARYOUTPUTLENGTHPTRDATABUFFER                                       4294967295u
#define CRYPTO_30_VHSM_MAX_SHAREDDATABUFFER                                                         4294967295u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCNoReferenceDefines  Crypto_30_vHsm No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CRYPTO_30_VHSM_NO_OBJECTINFOIDXOFOBJMAP                                                     255u
#define CRYPTO_30_VHSM_NO_SHAREDDATABUFFERENDIDXOFOBJECTINFO                                        65535u
#define CRYPTO_30_VHSM_NO_SHAREDDATABUFFERSTARTIDXOFOBJECTINFO                                      65535u
#define CRYPTO_30_VHSM_NO_EXPECTEDCOMPATIBILITYVERSION                                              65535u
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCIsReducedToDefineDefines  Crypto_30_vHsm Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CRYPTO_30_VHSM_ISDEF_OBJECTINFOIDXOFKEYMGMOBJ                                               STD_OFF
#define CRYPTO_30_VHSM_ISDEF_AREASTARTOFMEMORYAREA                                                  STD_OFF
#define CRYPTO_30_VHSM_ISDEF_AREASTOPOFMEMORYAREA                                                   STD_OFF
#define CRYPTO_30_VHSM_ISDEF_AREATYPEOFMEMORYAREA                                                   STD_OFF
#define CRYPTO_30_VHSM_ISDEF_OBJECTINFOIDXOFOBJMAP                                                  STD_OFF
#define CRYPTO_30_VHSM_ISDEF_OBJECTINFOUSEDOFOBJMAP                                                 STD_OFF
#define CRYPTO_30_VHSM_ISDEF_BUFFERUSEDOFOBJECTINFO                                                 STD_OFF
#define CRYPTO_30_VHSM_ISDEF_HSMOBJIDOFOBJECTINFO                                                   STD_OFF
#define CRYPTO_30_VHSM_ISDEF_SHAREDDATABUFFERENDIDXOFOBJECTINFO                                     STD_OFF
#define CRYPTO_30_VHSM_ISDEF_SHAREDDATABUFFERSTARTIDXOFOBJECTINFO                                   STD_OFF
#define CRYPTO_30_VHSM_ISDEF_SHAREDDATABUFFERUSEDOFOBJECTINFO                                       STD_OFF
#define CRYPTO_30_VHSM_ISDEF_CHANNELSTATEOFPCCONFIG                                                 STD_ON
#define CRYPTO_30_VHSM_ISDEF_DRIVEROBJECTLOCKOFPCCONFIG                                             STD_ON
#define CRYPTO_30_VHSM_ISDEF_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                 STD_OFF
#define CRYPTO_30_VHSM_ISDEF_FINALMAGICNUMBEROFPCCONFIG                                             STD_OFF
#define CRYPTO_30_VHSM_ISDEF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                STD_OFF
#define CRYPTO_30_VHSM_ISDEF_INITDATAHASHCODEOFPCCONFIG                                             STD_OFF
#define CRYPTO_30_VHSM_ISDEF_JOBREQUESTOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_VHSM_ISDEF_KEYMGMOBJOFPCCONFIG                                                    STD_ON
#define CRYPTO_30_VHSM_ISDEF_MEMORYAREAOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_VHSM_ISDEF_OBJMAPOFPCCONFIG                                                       STD_ON
#define CRYPTO_30_VHSM_ISDEF_OBJECTINFOOFPCCONFIG                                                   STD_ON
#define CRYPTO_30_VHSM_ISDEF_OUTPUTLENGTHPTRDATABUFFEROFPCCONFIG                                    STD_ON
#define CRYPTO_30_VHSM_ISDEF_SECONDARYOUTPUTLENGTHPTRDATABUFFEROFPCCONFIG                           STD_ON
#define CRYPTO_30_VHSM_ISDEF_SHAREDDATABUFFEROFPCCONFIG                                             STD_ON
#define CRYPTO_30_VHSM_ISDEF_VERIFYPTRDATABUFFEROFPCCONFIG                                          STD_ON
#define CRYPTO_30_VHSM_ISDEF_WAITLOOPCALLOUTOFVHSMOFPCCONFIG                                        STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCEqualsAlwaysToDefines  Crypto_30_vHsm Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CRYPTO_30_VHSM_EQ2_OBJECTINFOIDXOFKEYMGMOBJ                                                 
#define CRYPTO_30_VHSM_EQ2_AREASTARTOFMEMORYAREA                                                    
#define CRYPTO_30_VHSM_EQ2_AREASTOPOFMEMORYAREA                                                     
#define CRYPTO_30_VHSM_EQ2_AREATYPEOFMEMORYAREA                                                     
#define CRYPTO_30_VHSM_EQ2_OBJECTINFOIDXOFOBJMAP                                                    
#define CRYPTO_30_VHSM_EQ2_OBJECTINFOUSEDOFOBJMAP                                                   
#define CRYPTO_30_VHSM_EQ2_BUFFERUSEDOFOBJECTINFO                                                   
#define CRYPTO_30_VHSM_EQ2_HSMOBJIDOFOBJECTINFO                                                     
#define CRYPTO_30_VHSM_EQ2_SHAREDDATABUFFERENDIDXOFOBJECTINFO                                       
#define CRYPTO_30_VHSM_EQ2_SHAREDDATABUFFERSTARTIDXOFOBJECTINFO                                     
#define CRYPTO_30_VHSM_EQ2_SHAREDDATABUFFERUSEDOFOBJECTINFO                                         
#define CRYPTO_30_VHSM_EQ2_CHANNELSTATEOFPCCONFIG                                                   Crypto_30_vHsm_ChannelState
#define CRYPTO_30_VHSM_EQ2_DRIVEROBJECTLOCKOFPCCONFIG                                               Crypto_30_vHsm_DriverObjectLock.raw
#define CRYPTO_30_VHSM_EQ2_EXPECTEDCOMPATIBILITYVERSIONOFPCCONFIG                                   
#define CRYPTO_30_VHSM_EQ2_FINALMAGICNUMBEROFPCCONFIG                                               
#define CRYPTO_30_VHSM_EQ2_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                                  
#define CRYPTO_30_VHSM_EQ2_INITDATAHASHCODEOFPCCONFIG                                               
#define CRYPTO_30_VHSM_EQ2_JOBREQUESTOFPCCONFIG                                                     Crypto_30_vHsm_JobRequest.raw
#define CRYPTO_30_VHSM_EQ2_KEYMGMOBJOFPCCONFIG                                                      Crypto_30_vHsm_KeyMgmObj
#define CRYPTO_30_VHSM_EQ2_MEMORYAREAOFPCCONFIG                                                     Crypto_30_vHsm_MemoryArea
#define CRYPTO_30_VHSM_EQ2_OBJMAPOFPCCONFIG                                                         Crypto_30_vHsm_ObjMap
#define CRYPTO_30_VHSM_EQ2_OBJECTINFOOFPCCONFIG                                                     Crypto_30_vHsm_ObjectInfo
#define CRYPTO_30_VHSM_EQ2_OUTPUTLENGTHPTRDATABUFFEROFPCCONFIG                                      Crypto_30_vHsm_OutputLengthPtrDataBuffer.raw
#define CRYPTO_30_VHSM_EQ2_SECONDARYOUTPUTLENGTHPTRDATABUFFEROFPCCONFIG                             Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer.raw
#define CRYPTO_30_VHSM_EQ2_SHAREDDATABUFFEROFPCCONFIG                                               Crypto_30_vHsm_SharedDataBuffer.raw
#define CRYPTO_30_VHSM_EQ2_VERIFYPTRDATABUFFEROFPCCONFIG                                            Crypto_30_vHsm_VerifyPtrDataBuffer.raw
#define CRYPTO_30_VHSM_EQ2_WAITLOOPCALLOUTOFVHSMOFPCCONFIG                                          
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCSymbolicInitializationPointers  Crypto_30_vHsm Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Crypto_30_vHsm_Config_Ptr                                                                   NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Crypto_30_vHsm' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCInitializationSymbols  Crypto_30_vHsm Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Crypto_30_vHsm_Config                                                                       NULL_PTR  /**< symbolic identifier which could be used to initialize 'Crypto_30_vHsm */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCGeneral  Crypto_30_vHsm General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CRYPTO_30_VHSM_CHECK_INIT_POINTER                                                           STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CRYPTO_30_VHSM_FINAL_MAGIC_NUMBER                                                           0xFF1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of Crypto_30_vHsm */
#define CRYPTO_30_VHSM_INDIVIDUAL_POSTBUILD                                                         STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Crypto_30_vHsm' is not configured to be postbuild capable. */
#define CRYPTO_30_VHSM_INIT_DATA                                                                    CRYPTO_30_VHSM_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CRYPTO_30_VHSM_INIT_DATA_HASH_CODE                                                          366851565  /**< the precompile constant to validate the initialization structure at initialization time of Crypto_30_vHsm with a hashcode. The seed value is '0xFF1Eu' */
#define CRYPTO_30_VHSM_USE_ECUM_BSW_ERROR_HOOK                                                      STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CRYPTO_30_VHSM_USE_INIT_POINTER                                                             STD_OFF  /**< STD_ON if the init pointer Crypto_30_vHsm shall be used. */
/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_vHsmPBDataSwitches  Crypto_30_vHsm Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CRYPTO_30_VHSM_PBCONFIG                                                                     STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRYPTO_30_VHSM_LTCONFIGIDXOFPBCONFIG                                                        STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CRYPTO_30_VHSM_PCCONFIGIDXOFPBCONFIG                                                        STD_OFF  /**< Deactivateable: 'Crypto_30_vHsm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPBIsReducedToDefineDefines  Crypto_30_vHsm Is Reduced To Define Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CRYPTO_30_VHSM_ISDEF_LTCONFIGIDXOFPBCONFIG                                                  STD_OFF
#define CRYPTO_30_VHSM_ISDEF_PCCONFIGIDXOFPBCONFIG                                                  STD_OFF
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPBEqualsAlwaysToDefines  Crypto_30_vHsm Equals Always To Defines (POST_BUILD)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CRYPTO_30_VHSM_EQ2_LTCONFIGIDXOFPBCONFIG                                                    
#define CRYPTO_30_VHSM_EQ2_PCCONFIGIDXOFPBCONFIG                                                    
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
  \defgroup  Crypto_30_vHsmPCGetRootDataMacros  Crypto_30_vHsm Get Root Data Macros (PRE_COMPILE)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Crypto_30_vHsm_GetExpectedCompatibilityVersionOfPCConfig()                                    /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_vHsm_GetFinalMagicNumberOfPCConfig()                                                /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_vHsm_GetGeneratorCompatibilityVersionOfPCConfig()                                   /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_vHsm_GetInitDataHashCodeOfPCConfig()                                                /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_vHsm_GetWaitLoopCalloutOfvHsmOfPCConfig()                                           /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.WaitLoopCalloutOfvHsm' Reason: 'Parameter is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCGetConstantDuplicatedRootDataMacros  Crypto_30_vHsm Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Crypto_30_vHsm_GetChannelStateOfPCConfig()                                                  Crypto_30_vHsm_ChannelState  /**< the pointer to Crypto_30_vHsm_ChannelState */
#define Crypto_30_vHsm_GetDetInstanceMaskOfvHsmOfPCConfig()                                         0x00u
#define Crypto_30_vHsm_GetDriverObjectLockOfPCConfig()                                              Crypto_30_vHsm_DriverObjectLock.raw  /**< the pointer to Crypto_30_vHsm_DriverObjectLock */
#define Crypto_30_vHsm_GetFlagClearAddressOfJobResponseInterruptOfPCConfig()                        0xF0040028u
#define Crypto_30_vHsm_GetFlagClearMaskOfJobResponseInterruptOfPCConfig()                           0x01u
#define Crypto_30_vHsm_GetFlagClearValueOfJobResponseInterruptOfPCConfig()                          0x01u
#define Crypto_30_vHsm_IsFlagClearingOfJobResponseInterruptOfPCConfig()                             (((TRUE)) != FALSE)
#define Crypto_30_vHsm_GetFlagSetAddressOfJobRequestInterruptOfPCConfig()                           0xF0040020u
#define Crypto_30_vHsm_GetFlagSetMaskOfJobRequestInterruptOfPCConfig()                              0x01u
#define Crypto_30_vHsm_IsFlagSettingOfJobRequestInterruptOfPCConfig()                               (((TRUE)) != FALSE)
#define Crypto_30_vHsm_GetHost2HsmAddressOfvHsmOfPCConfig()                                         0xF0040038u
#define Crypto_30_vHsm_GetHsm2HostAddressOfvHsmOfPCConfig()                                         0xF0040034u
#define Crypto_30_vHsm_IsInterruptModeOfvHsmOfPCConfig()                                            (((FALSE)) != FALSE)
#define Crypto_30_vHsm_GetIpcChannelsOfvHsmOfPCConfig()                                             2u
#define Crypto_30_vHsm_IsIpcInitializationOfvHsmOfPCConfig()                                        (((TRUE)) != FALSE)
#define Crypto_30_vHsm_GetIpcInstanceIdOfvHsmOfPCConfig()                                           0u
#define Crypto_30_vHsm_IsIpcMacJobOptimizationOfvHsmOfPCConfig()                                    (((FALSE)) != FALSE)
#define Crypto_30_vHsm_GetIpcProtocolVersionOfvHsmOfPCConfig()                                      3u
#define Crypto_30_vHsm_GetJobRequestOfPCConfig()                                                    Crypto_30_vHsm_JobRequest.raw  /**< the pointer to Crypto_30_vHsm_JobRequest */
#define Crypto_30_vHsm_IsKeyDeriveJobSupportOfvHsmOfPCConfig()                                      (((TRUE)) != FALSE)
#define Crypto_30_vHsm_IsKeyElementDeleteSupportOfvHsmOfPCConfig()                                  (((TRUE)) != FALSE)
#define Crypto_30_vHsm_GetKeyMgmObjOfPCConfig()                                                     Crypto_30_vHsm_KeyMgmObj  /**< the pointer to Crypto_30_vHsm_KeyMgmObj */
#define Crypto_30_vHsm_GetMainFunctionPeriodOfGeneralOfPCConfig()                                   1u
#define Crypto_30_vHsm_GetMemoryAreaOfPCConfig()                                                    Crypto_30_vHsm_MemoryArea  /**< the pointer to Crypto_30_vHsm_MemoryArea */
#define Crypto_30_vHsm_GetObjMapOfPCConfig()                                                        Crypto_30_vHsm_ObjMap  /**< the pointer to Crypto_30_vHsm_ObjMap */
#define Crypto_30_vHsm_GetObjectInfoOfPCConfig()                                                    Crypto_30_vHsm_ObjectInfo  /**< the pointer to Crypto_30_vHsm_ObjectInfo */
#define Crypto_30_vHsm_GetOutputLengthPtrDataBufferOfPCConfig()                                     Crypto_30_vHsm_OutputLengthPtrDataBuffer.raw  /**< the pointer to Crypto_30_vHsm_OutputLengthPtrDataBuffer */
#define Crypto_30_vHsm_IsRedirectionOfvHsmOfPCConfig()                                              (((FALSE)) != FALSE)
#define Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBufferOfPCConfig()                            Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer.raw  /**< the pointer to Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer */
#define Crypto_30_vHsm_GetSharedDataBufferOfPCConfig()                                              Crypto_30_vHsm_SharedDataBuffer.raw  /**< the pointer to Crypto_30_vHsm_SharedDataBuffer */
#define Crypto_30_vHsm_GetSizeOfChannelStateOfPCConfig()                                            2u  /**< the number of accomplishable value elements in Crypto_30_vHsm_ChannelState */
#define Crypto_30_vHsm_GetSizeOfKeyMgmObjOfPCConfig()                                               1u  /**< the number of accomplishable value elements in Crypto_30_vHsm_KeyMgmObj */
#define Crypto_30_vHsm_GetSizeOfMemoryAreaOfPCConfig()                                              7u  /**< the number of accomplishable value elements in Crypto_30_vHsm_MemoryArea */
#define Crypto_30_vHsm_GetSizeOfObjMapOfPCConfig()                                                  8u  /**< the number of accomplishable value elements in Crypto_30_vHsm_ObjMap */
#define Crypto_30_vHsm_GetSizeOfObjectInfoOfPCConfig()                                              7u  /**< the number of accomplishable value elements in Crypto_30_vHsm_ObjectInfo */
#define Crypto_30_vHsm_GetSizeOfSharedDataBufferOfPCConfig()                                        469u  /**< the number of accomplishable value elements in Crypto_30_vHsm_SharedDataBuffer */
#define Crypto_30_vHsm_GetVerifyPtrDataBufferOfPCConfig()                                           Crypto_30_vHsm_VerifyPtrDataBuffer.raw  /**< the pointer to Crypto_30_vHsm_VerifyPtrDataBuffer */
#define Crypto_30_vHsm_IsVersionInfoApiOfGeneralOfPCConfig()                                        (((FALSE)) != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCGetDuplicatedRootDataMacros  Crypto_30_vHsm Get Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated root data elements.
  \{
*/ 
#define Crypto_30_vHsm_GetSizeOfDriverObjectLockOfPCConfig()                                        Crypto_30_vHsm_GetSizeOfObjectInfoOfPCConfig()  /**< the number of accomplishable value elements in Crypto_30_vHsm_DriverObjectLock */
#define Crypto_30_vHsm_GetSizeOfJobRequestOfPCConfig()                                              Crypto_30_vHsm_GetSizeOfObjectInfoOfPCConfig()  /**< the number of accomplishable value elements in Crypto_30_vHsm_JobRequest */
#define Crypto_30_vHsm_GetSizeOfOutputLengthPtrDataBufferOfPCConfig()                               Crypto_30_vHsm_GetSizeOfObjectInfoOfPCConfig()  /**< the number of accomplishable value elements in Crypto_30_vHsm_OutputLengthPtrDataBuffer */
#define Crypto_30_vHsm_GetSizeOfSecondaryOutputLengthPtrDataBufferOfPCConfig()                      Crypto_30_vHsm_GetSizeOfObjectInfoOfPCConfig()  /**< the number of accomplishable value elements in Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer */
#define Crypto_30_vHsm_GetSizeOfVerifyPtrDataBufferOfPCConfig()                                     Crypto_30_vHsm_GetSizeOfObjectInfoOfPCConfig()  /**< the number of accomplishable value elements in Crypto_30_vHsm_VerifyPtrDataBuffer */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCGetDataMacros  Crypto_30_vHsm Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Crypto_30_vHsm_GetChannelState(Index)                                                       (Crypto_30_vHsm_GetChannelStateOfPCConfig()[(Index)])
#define Crypto_30_vHsm_GetDriverObjectLock(Index)                                                   (Crypto_30_vHsm_GetDriverObjectLockOfPCConfig()[(Index)])
#define Crypto_30_vHsm_IsCancelOfJobRequest(Index)                                                  ((Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].CancelOfJobRequest) != FALSE)
#define Crypto_30_vHsm_GetCounterOfJobRequest(Index)                                                (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].CounterOfJobRequest)
#define Crypto_30_vHsm_GetCryptoJobOfJobRequest(Index)                                              (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].CryptoJobOfJobRequest)
#define Crypto_30_vHsm_GetJobStateOfJobRequest(Index)                                               (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].JobStateOfJobRequest)
#define Crypto_30_vHsm_GetKeyMJobOfJobRequest(Index)                                                (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].KeyMJobOfJobRequest)
#define Crypto_30_vHsm_GetKindOfJobRequest(Index)                                                   (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].KindOfJobRequest)
#define Crypto_30_vHsm_IsLockOfJobRequest(Index)                                                    ((Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].LockOfJobRequest) != FALSE)
#define Crypto_30_vHsm_GetOutputOffsetOfJobRequest(Index)                                           (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].OutputOffsetOfJobRequest)
#define Crypto_30_vHsm_GetProcessingTypeOfJobRequest(Index)                                         (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].ProcessingTypeOfJobRequest)
#define Crypto_30_vHsm_GetResultOfJobRequest(Index)                                                 (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].ResultOfJobRequest)
#define Crypto_30_vHsm_GetSecondaryOutputOffsetOfJobRequest(Index)                                  (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].SecondaryOutputOffsetOfJobRequest)
#define Crypto_30_vHsm_GetStateOfJobRequest(Index)                                                  (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].StateOfJobRequest)
#define Crypto_30_vHsm_IsTrimmedOutputBufferOfJobRequest(Index)                                     ((Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].TrimmedOutputBufferOfJobRequest) != FALSE)
#define Crypto_30_vHsm_GetUsedBufferOfJobRequest(Index)                                             (Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].UsedBufferOfJobRequest)
#define Crypto_30_vHsm_GetObjectInfoIdxOfKeyMgmObj(Index)                                           (Crypto_30_vHsm_GetKeyMgmObjOfPCConfig()[(Index)].ObjectInfoIdxOfKeyMgmObj)
#define Crypto_30_vHsm_GetAreaStartOfMemoryArea(Index)                                              (Crypto_30_vHsm_GetMemoryAreaOfPCConfig()[(Index)].AreaStartOfMemoryArea)
#define Crypto_30_vHsm_GetAreaStopOfMemoryArea(Index)                                               (Crypto_30_vHsm_GetMemoryAreaOfPCConfig()[(Index)].AreaStopOfMemoryArea)
#define Crypto_30_vHsm_GetAreaTypeOfMemoryArea(Index)                                               (Crypto_30_vHsm_GetMemoryAreaOfPCConfig()[(Index)].AreaTypeOfMemoryArea)
#define Crypto_30_vHsm_GetObjectInfoIdxOfObjMap(Index)                                              (Crypto_30_vHsm_GetObjMapOfPCConfig()[(Index)].ObjectInfoIdxOfObjMap)
#define Crypto_30_vHsm_IsBufferUsedOfObjectInfo(Index)                                              ((Crypto_30_vHsm_GetObjectInfoOfPCConfig()[(Index)].BufferUsedOfObjectInfo) != FALSE)
#define Crypto_30_vHsm_GetHsmObjIdOfObjectInfo(Index)                                               (Crypto_30_vHsm_GetObjectInfoOfPCConfig()[(Index)].HsmObjIdOfObjectInfo)
#define Crypto_30_vHsm_GetSharedDataBufferEndIdxOfObjectInfo(Index)                                 (Crypto_30_vHsm_GetObjectInfoOfPCConfig()[(Index)].SharedDataBufferEndIdxOfObjectInfo)
#define Crypto_30_vHsm_GetSharedDataBufferStartIdxOfObjectInfo(Index)                               (Crypto_30_vHsm_GetObjectInfoOfPCConfig()[(Index)].SharedDataBufferStartIdxOfObjectInfo)
#define Crypto_30_vHsm_GetOutputLengthPtrDataBuffer(Index)                                          (Crypto_30_vHsm_GetOutputLengthPtrDataBufferOfPCConfig()[(Index)])
#define Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBuffer(Index)                                 (Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBufferOfPCConfig()[(Index)])
#define Crypto_30_vHsm_GetSharedDataBuffer(Index)                                                   (Crypto_30_vHsm_GetSharedDataBufferOfPCConfig()[(Index)])
#define Crypto_30_vHsm_GetVerifyPtrDataBuffer(Index)                                                (Crypto_30_vHsm_GetVerifyPtrDataBufferOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCGetDeduplicatedDataMacros  Crypto_30_vHsm Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Crypto_30_vHsm_GetDetInstanceMaskOfvHsm()                                                   Crypto_30_vHsm_GetDetInstanceMaskOfvHsmOfPCConfig()
#define Crypto_30_vHsm_GetExpectedCompatibilityVersion()                                              /**< Deactivateable: 'Crypto_30_vHsm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_vHsm_GetFinalMagicNumber()                                                          /**< Deactivateable: 'Crypto_30_vHsm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_vHsm_GetFlagClearAddressOfJobResponseInterrupt()                                  Crypto_30_vHsm_GetFlagClearAddressOfJobResponseInterruptOfPCConfig()
#define Crypto_30_vHsm_GetFlagClearMaskOfJobResponseInterrupt()                                     Crypto_30_vHsm_GetFlagClearMaskOfJobResponseInterruptOfPCConfig()
#define Crypto_30_vHsm_GetFlagClearValueOfJobResponseInterrupt()                                    Crypto_30_vHsm_GetFlagClearValueOfJobResponseInterruptOfPCConfig()
#define Crypto_30_vHsm_IsFlagClearingOfJobResponseInterrupt()                                       Crypto_30_vHsm_IsFlagClearingOfJobResponseInterruptOfPCConfig()
#define Crypto_30_vHsm_GetFlagSetAddressOfJobRequestInterrupt()                                     Crypto_30_vHsm_GetFlagSetAddressOfJobRequestInterruptOfPCConfig()
#define Crypto_30_vHsm_GetFlagSetMaskOfJobRequestInterrupt()                                        Crypto_30_vHsm_GetFlagSetMaskOfJobRequestInterruptOfPCConfig()
#define Crypto_30_vHsm_IsFlagSettingOfJobRequestInterrupt()                                         Crypto_30_vHsm_IsFlagSettingOfJobRequestInterruptOfPCConfig()
#define Crypto_30_vHsm_GetGeneratorCompatibilityVersion()                                             /**< Deactivateable: 'Crypto_30_vHsm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_vHsm_GetHost2HsmAddressOfvHsm()                                                   Crypto_30_vHsm_GetHost2HsmAddressOfvHsmOfPCConfig()
#define Crypto_30_vHsm_GetHsm2HostAddressOfvHsm()                                                   Crypto_30_vHsm_GetHsm2HostAddressOfvHsmOfPCConfig()
#define Crypto_30_vHsm_GetInitDataHashCode()                                                          /**< Deactivateable: 'Crypto_30_vHsm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_vHsm_IsInterruptModeOfvHsm()                                                      Crypto_30_vHsm_IsInterruptModeOfvHsmOfPCConfig()
#define Crypto_30_vHsm_GetIpcChannelsOfvHsm()                                                       Crypto_30_vHsm_GetIpcChannelsOfvHsmOfPCConfig()
#define Crypto_30_vHsm_IsIpcInitializationOfvHsm()                                                  Crypto_30_vHsm_IsIpcInitializationOfvHsmOfPCConfig()
#define Crypto_30_vHsm_GetIpcInstanceIdOfvHsm()                                                     Crypto_30_vHsm_GetIpcInstanceIdOfvHsmOfPCConfig()
#define Crypto_30_vHsm_IsIpcMacJobOptimizationOfvHsm()                                              Crypto_30_vHsm_IsIpcMacJobOptimizationOfvHsmOfPCConfig()
#define Crypto_30_vHsm_GetIpcProtocolVersionOfvHsm()                                                Crypto_30_vHsm_GetIpcProtocolVersionOfvHsmOfPCConfig()
#define Crypto_30_vHsm_IsKeyDeriveJobSupportOfvHsm()                                                Crypto_30_vHsm_IsKeyDeriveJobSupportOfvHsmOfPCConfig()
#define Crypto_30_vHsm_IsKeyElementDeleteSupportOfvHsm()                                            Crypto_30_vHsm_IsKeyElementDeleteSupportOfvHsmOfPCConfig()
#define Crypto_30_vHsm_GetMainFunctionPeriodOfGeneral()                                             Crypto_30_vHsm_GetMainFunctionPeriodOfGeneralOfPCConfig()
#define Crypto_30_vHsm_IsObjectInfoUsedOfObjMap(Index)                                              (((boolean)(Crypto_30_vHsm_GetObjectInfoIdxOfObjMap(Index) != CRYPTO_30_VHSM_NO_OBJECTINFOIDXOFOBJMAP)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to Crypto_30_vHsm_ObjectInfo */
#define Crypto_30_vHsm_IsSharedDataBufferUsedOfObjectInfo(Index)                                    (((boolean)(Crypto_30_vHsm_GetSharedDataBufferStartIdxOfObjectInfo(Index) != CRYPTO_30_VHSM_NO_SHAREDDATABUFFERSTARTIDXOFOBJECTINFO)) != FALSE)  /**< TRUE, if the 0:n relation has 1 relation pointing to Crypto_30_vHsm_SharedDataBuffer */
#define Crypto_30_vHsm_IsRedirectionOfvHsm()                                                        Crypto_30_vHsm_IsRedirectionOfvHsmOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfChannelState()                                                      Crypto_30_vHsm_GetSizeOfChannelStateOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfDriverObjectLock()                                                  Crypto_30_vHsm_GetSizeOfDriverObjectLockOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfJobRequest()                                                        Crypto_30_vHsm_GetSizeOfJobRequestOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfKeyMgmObj()                                                         Crypto_30_vHsm_GetSizeOfKeyMgmObjOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfMemoryArea()                                                        Crypto_30_vHsm_GetSizeOfMemoryAreaOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfObjMap()                                                            Crypto_30_vHsm_GetSizeOfObjMapOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfObjectInfo()                                                        Crypto_30_vHsm_GetSizeOfObjectInfoOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfOutputLengthPtrDataBuffer()                                         Crypto_30_vHsm_GetSizeOfOutputLengthPtrDataBufferOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfSecondaryOutputLengthPtrDataBuffer()                                Crypto_30_vHsm_GetSizeOfSecondaryOutputLengthPtrDataBufferOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfSharedDataBuffer()                                                  Crypto_30_vHsm_GetSizeOfSharedDataBufferOfPCConfig()
#define Crypto_30_vHsm_GetSizeOfVerifyPtrDataBuffer()                                               Crypto_30_vHsm_GetSizeOfVerifyPtrDataBufferOfPCConfig()
#define Crypto_30_vHsm_IsVersionInfoApiOfGeneral()                                                  Crypto_30_vHsm_IsVersionInfoApiOfGeneralOfPCConfig()
#define Crypto_30_vHsm_GetWaitLoopCalloutOfvHsm()                                                     /**< Deactivateable: 'Crypto_30_vHsm_WaitLoopCalloutOfvHsm' Reason: 'Parameter is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCSetDataMacros  Crypto_30_vHsm Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define Crypto_30_vHsm_SetChannelState(Index, Value)                                                Crypto_30_vHsm_GetChannelStateOfPCConfig()[(Index)] = (Value)
#define Crypto_30_vHsm_SetDriverObjectLock(Index, Value)                                            Crypto_30_vHsm_GetDriverObjectLockOfPCConfig()[(Index)] = (Value)
#define Crypto_30_vHsm_SetCancelOfJobRequest(Index, Value)                                          Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].CancelOfJobRequest = (Value)
#define Crypto_30_vHsm_SetCounterOfJobRequest(Index, Value)                                         Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].CounterOfJobRequest = (Value)
#define Crypto_30_vHsm_SetCryptoJobOfJobRequest(Index, Value)                                       Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].CryptoJobOfJobRequest = (Value)
#define Crypto_30_vHsm_SetJobStateOfJobRequest(Index, Value)                                        Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].JobStateOfJobRequest = (Value)
#define Crypto_30_vHsm_SetKeyMJobOfJobRequest(Index, Value)                                         Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].KeyMJobOfJobRequest = (Value)
#define Crypto_30_vHsm_SetKindOfJobRequest(Index, Value)                                            Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].KindOfJobRequest = (Value)
#define Crypto_30_vHsm_SetLockOfJobRequest(Index, Value)                                            Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].LockOfJobRequest = (Value)
#define Crypto_30_vHsm_SetOutputOffsetOfJobRequest(Index, Value)                                    Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].OutputOffsetOfJobRequest = (Value)
#define Crypto_30_vHsm_SetProcessingTypeOfJobRequest(Index, Value)                                  Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].ProcessingTypeOfJobRequest = (Value)
#define Crypto_30_vHsm_SetResultOfJobRequest(Index, Value)                                          Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].ResultOfJobRequest = (Value)
#define Crypto_30_vHsm_SetSecondaryOutputOffsetOfJobRequest(Index, Value)                           Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].SecondaryOutputOffsetOfJobRequest = (Value)
#define Crypto_30_vHsm_SetStateOfJobRequest(Index, Value)                                           Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].StateOfJobRequest = (Value)
#define Crypto_30_vHsm_SetTrimmedOutputBufferOfJobRequest(Index, Value)                             Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].TrimmedOutputBufferOfJobRequest = (Value)
#define Crypto_30_vHsm_SetUsedBufferOfJobRequest(Index, Value)                                      Crypto_30_vHsm_GetJobRequestOfPCConfig()[(Index)].UsedBufferOfJobRequest = (Value)
#define Crypto_30_vHsm_SetOutputLengthPtrDataBuffer(Index, Value)                                   Crypto_30_vHsm_GetOutputLengthPtrDataBufferOfPCConfig()[(Index)] = (Value)
#define Crypto_30_vHsm_SetSecondaryOutputLengthPtrDataBuffer(Index, Value)                          Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBufferOfPCConfig()[(Index)] = (Value)
#define Crypto_30_vHsm_SetSharedDataBuffer(Index, Value)                                            Crypto_30_vHsm_GetSharedDataBufferOfPCConfig()[(Index)] = (Value)
#define Crypto_30_vHsm_SetVerifyPtrDataBuffer(Index, Value)                                         Crypto_30_vHsm_GetVerifyPtrDataBufferOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCGetAddressOfDataMacros  Crypto_30_vHsm Get Address Of Data Macros (PRE_COMPILE)
  \brief  These macros can be used to get the data by the address operator.
  \{
*/ 
#define Crypto_30_vHsm_GetAddrOutputLengthPtrDataBuffer(Index)                                      (&Crypto_30_vHsm_GetOutputLengthPtrDataBuffer(Index))
#define Crypto_30_vHsm_GetAddrSecondaryOutputLengthPtrDataBuffer(Index)                             (&Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBuffer(Index))
#define Crypto_30_vHsm_GetAddrSharedDataBuffer(Index)                                               (&Crypto_30_vHsm_GetSharedDataBuffer(Index))
#define Crypto_30_vHsm_GetAddrVerifyPtrDataBuffer(Index)                                            (&Crypto_30_vHsm_GetVerifyPtrDataBuffer(Index))
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCHasMacros  Crypto_30_vHsm Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Crypto_30_vHsm_HasChannelState()                                                            (TRUE != FALSE)
#define Crypto_30_vHsm_HasDetInstanceMaskOfvHsm()                                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasDriverObjectLock()                                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasExpectedCompatibilityVersion()                                              /**< Deactivateable: 'Crypto_30_vHsm_ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_vHsm_HasFinalMagicNumber()                                                          /**< Deactivateable: 'Crypto_30_vHsm_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_vHsm_HasFlagClearAddressOfJobResponseInterrupt()                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagClearMaskOfJobResponseInterrupt()                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagClearValueOfJobResponseInterrupt()                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagClearingOfJobResponseInterrupt()                                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagSetAddressOfJobRequestInterrupt()                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagSetMaskOfJobRequestInterrupt()                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagSettingOfJobRequestInterrupt()                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasGeneratorCompatibilityVersion()                                             /**< Deactivateable: 'Crypto_30_vHsm_GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_vHsm_HasHost2HsmAddressOfvHsm()                                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasHsm2HostAddressOfvHsm()                                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasInitDataHashCode()                                                          /**< Deactivateable: 'Crypto_30_vHsm_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_vHsm_HasInterruptModeOfvHsm()                                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcChannelsOfvHsm()                                                       (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcInitializationOfvHsm()                                                 (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcInstanceIdOfvHsm()                                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcMacJobOptimizationOfvHsm()                                             (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcProtocolVersionOfvHsm()                                                (TRUE != FALSE)
#define Crypto_30_vHsm_HasJobRequest()                                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasCancelOfJobRequest()                                                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasCounterOfJobRequest()                                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasCryptoJobOfJobRequest()                                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasJobStateOfJobRequest()                                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasKeyMJobOfJobRequest()                                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasKindOfJobRequest()                                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasLockOfJobRequest()                                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasOutputOffsetOfJobRequest()                                                (TRUE != FALSE)
#define Crypto_30_vHsm_HasProcessingTypeOfJobRequest()                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasResultOfJobRequest()                                                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasSecondaryOutputOffsetOfJobRequest()                                       (TRUE != FALSE)
#define Crypto_30_vHsm_HasStateOfJobRequest()                                                       (TRUE != FALSE)
#define Crypto_30_vHsm_HasTrimmedOutputBufferOfJobRequest()                                         (TRUE != FALSE)
#define Crypto_30_vHsm_HasUsedBufferOfJobRequest()                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasKeyDeriveJobSupportOfvHsm()                                               (TRUE != FALSE)
#define Crypto_30_vHsm_HasKeyElementDeleteSupportOfvHsm()                                           (TRUE != FALSE)
#define Crypto_30_vHsm_HasKeyMgmObj()                                                               (TRUE != FALSE)
#define Crypto_30_vHsm_HasObjectInfoIdxOfKeyMgmObj()                                                (TRUE != FALSE)
#define Crypto_30_vHsm_HasMainFunctionPeriodOfGeneral()                                             (TRUE != FALSE)
#define Crypto_30_vHsm_HasMemoryArea()                                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasAreaStartOfMemoryArea()                                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasAreaStopOfMemoryArea()                                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasAreaTypeOfMemoryArea()                                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasObjMap()                                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasObjectInfoIdxOfObjMap()                                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasObjectInfoUsedOfObjMap()                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasObjectInfo()                                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasBufferUsedOfObjectInfo()                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasHsmObjIdOfObjectInfo()                                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasSharedDataBufferEndIdxOfObjectInfo()                                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasSharedDataBufferStartIdxOfObjectInfo()                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasSharedDataBufferUsedOfObjectInfo()                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasOutputLengthPtrDataBuffer()                                               (TRUE != FALSE)
#define Crypto_30_vHsm_HasRedirectionOfvHsm()                                                       (TRUE != FALSE)
#define Crypto_30_vHsm_HasSecondaryOutputLengthPtrDataBuffer()                                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasSharedDataBuffer()                                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfChannelState()                                                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfDriverObjectLock()                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfJobRequest()                                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfKeyMgmObj()                                                         (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfMemoryArea()                                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfObjMap()                                                            (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfObjectInfo()                                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfOutputLengthPtrDataBuffer()                                         (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfSecondaryOutputLengthPtrDataBuffer()                                (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfSharedDataBuffer()                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfVerifyPtrDataBuffer()                                               (TRUE != FALSE)
#define Crypto_30_vHsm_HasVerifyPtrDataBuffer()                                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasVersionInfoApiOfGeneral()                                                 (TRUE != FALSE)
#define Crypto_30_vHsm_HasWaitLoopCalloutOfvHsm()                                                     /**< Deactivateable: 'Crypto_30_vHsm_WaitLoopCalloutOfvHsm' Reason: 'Parameter is not configured!' */
#define Crypto_30_vHsm_HasPCConfig()                                                                (TRUE != FALSE)
#define Crypto_30_vHsm_HasChannelStateOfPCConfig()                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasDetInstanceMaskOfvHsmOfPCConfig()                                         (TRUE != FALSE)
#define Crypto_30_vHsm_HasDriverObjectLockOfPCConfig()                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasExpectedCompatibilityVersionOfPCConfig()                                    /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.ExpectedCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_vHsm_HasFinalMagicNumberOfPCConfig()                                                /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_vHsm_HasFlagClearAddressOfJobResponseInterruptOfPCConfig()                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagClearMaskOfJobResponseInterruptOfPCConfig()                           (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagClearValueOfJobResponseInterruptOfPCConfig()                          (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagClearingOfJobResponseInterruptOfPCConfig()                            (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagSetAddressOfJobRequestInterruptOfPCConfig()                           (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagSetMaskOfJobRequestInterruptOfPCConfig()                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasFlagSettingOfJobRequestInterruptOfPCConfig()                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasGeneratorCompatibilityVersionOfPCConfig()                                   /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.GeneratorCompatibilityVersion' Reason: 'Variant is not VARIANT-POST-BUILD-LOADABLE' */
#define Crypto_30_vHsm_HasHost2HsmAddressOfvHsmOfPCConfig()                                         (TRUE != FALSE)
#define Crypto_30_vHsm_HasHsm2HostAddressOfvHsmOfPCConfig()                                         (TRUE != FALSE)
#define Crypto_30_vHsm_HasInitDataHashCodeOfPCConfig()                                                /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define Crypto_30_vHsm_HasInterruptModeOfvHsmOfPCConfig()                                           (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcChannelsOfvHsmOfPCConfig()                                             (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcInitializationOfvHsmOfPCConfig()                                       (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcInstanceIdOfvHsmOfPCConfig()                                           (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcMacJobOptimizationOfvHsmOfPCConfig()                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasIpcProtocolVersionOfvHsmOfPCConfig()                                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasJobRequestOfPCConfig()                                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasKeyDeriveJobSupportOfvHsmOfPCConfig()                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasKeyElementDeleteSupportOfvHsmOfPCConfig()                                 (TRUE != FALSE)
#define Crypto_30_vHsm_HasKeyMgmObjOfPCConfig()                                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasMainFunctionPeriodOfGeneralOfPCConfig()                                   (TRUE != FALSE)
#define Crypto_30_vHsm_HasMemoryAreaOfPCConfig()                                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasObjMapOfPCConfig()                                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasObjectInfoOfPCConfig()                                                    (TRUE != FALSE)
#define Crypto_30_vHsm_HasOutputLengthPtrDataBufferOfPCConfig()                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasRedirectionOfvHsmOfPCConfig()                                             (TRUE != FALSE)
#define Crypto_30_vHsm_HasSecondaryOutputLengthPtrDataBufferOfPCConfig()                            (TRUE != FALSE)
#define Crypto_30_vHsm_HasSharedDataBufferOfPCConfig()                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfChannelStateOfPCConfig()                                            (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfDriverObjectLockOfPCConfig()                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfJobRequestOfPCConfig()                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfKeyMgmObjOfPCConfig()                                               (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfMemoryAreaOfPCConfig()                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfObjMapOfPCConfig()                                                  (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfObjectInfoOfPCConfig()                                              (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfOutputLengthPtrDataBufferOfPCConfig()                               (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfSecondaryOutputLengthPtrDataBufferOfPCConfig()                      (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfSharedDataBufferOfPCConfig()                                        (TRUE != FALSE)
#define Crypto_30_vHsm_HasSizeOfVerifyPtrDataBufferOfPCConfig()                                     (TRUE != FALSE)
#define Crypto_30_vHsm_HasVerifyPtrDataBufferOfPCConfig()                                           (TRUE != FALSE)
#define Crypto_30_vHsm_HasVersionInfoApiOfGeneralOfPCConfig()                                       (TRUE != FALSE)
#define Crypto_30_vHsm_HasWaitLoopCalloutOfvHsmOfPCConfig()                                           /**< Deactivateable: 'Crypto_30_vHsm_PCConfig.WaitLoopCalloutOfvHsm' Reason: 'Parameter is not configured!' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCIncrementDataMacros  Crypto_30_vHsm Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_vHsm_IncChannelState(Index)                                                       Crypto_30_vHsm_GetChannelState(Index)++
#define Crypto_30_vHsm_IncDriverObjectLock(Index)                                                   Crypto_30_vHsm_GetDriverObjectLock(Index)++
#define Crypto_30_vHsm_IncCounterOfJobRequest(Index)                                                Crypto_30_vHsm_GetCounterOfJobRequest(Index)++
#define Crypto_30_vHsm_IncCryptoJobOfJobRequest(Index)                                              Crypto_30_vHsm_GetCryptoJobOfJobRequest(Index)++
#define Crypto_30_vHsm_IncJobStateOfJobRequest(Index)                                               Crypto_30_vHsm_GetJobStateOfJobRequest(Index)++
#define Crypto_30_vHsm_IncKeyMJobOfJobRequest(Index)                                                Crypto_30_vHsm_GetKeyMJobOfJobRequest(Index)++
#define Crypto_30_vHsm_IncKindOfJobRequest(Index)                                                   Crypto_30_vHsm_GetKindOfJobRequest(Index)++
#define Crypto_30_vHsm_IncOutputOffsetOfJobRequest(Index)                                           Crypto_30_vHsm_GetOutputOffsetOfJobRequest(Index)++
#define Crypto_30_vHsm_IncProcessingTypeOfJobRequest(Index)                                         Crypto_30_vHsm_GetProcessingTypeOfJobRequest(Index)++
#define Crypto_30_vHsm_IncResultOfJobRequest(Index)                                                 Crypto_30_vHsm_GetResultOfJobRequest(Index)++
#define Crypto_30_vHsm_IncSecondaryOutputOffsetOfJobRequest(Index)                                  Crypto_30_vHsm_GetSecondaryOutputOffsetOfJobRequest(Index)++
#define Crypto_30_vHsm_IncStateOfJobRequest(Index)                                                  Crypto_30_vHsm_GetStateOfJobRequest(Index)++
#define Crypto_30_vHsm_IncUsedBufferOfJobRequest(Index)                                             Crypto_30_vHsm_GetUsedBufferOfJobRequest(Index)++
#define Crypto_30_vHsm_IncOutputLengthPtrDataBuffer(Index)                                          Crypto_30_vHsm_GetOutputLengthPtrDataBuffer(Index)++
#define Crypto_30_vHsm_IncSecondaryOutputLengthPtrDataBuffer(Index)                                 Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBuffer(Index)++
#define Crypto_30_vHsm_IncSharedDataBuffer(Index)                                                   Crypto_30_vHsm_GetSharedDataBuffer(Index)++
#define Crypto_30_vHsm_IncVerifyPtrDataBuffer(Index)                                                Crypto_30_vHsm_GetVerifyPtrDataBuffer(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCDecrementDataMacros  Crypto_30_vHsm Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_vHsm_DecChannelState(Index)                                                       Crypto_30_vHsm_GetChannelState(Index)--
#define Crypto_30_vHsm_DecDriverObjectLock(Index)                                                   Crypto_30_vHsm_GetDriverObjectLock(Index)--
#define Crypto_30_vHsm_DecCounterOfJobRequest(Index)                                                Crypto_30_vHsm_GetCounterOfJobRequest(Index)--
#define Crypto_30_vHsm_DecCryptoJobOfJobRequest(Index)                                              Crypto_30_vHsm_GetCryptoJobOfJobRequest(Index)--
#define Crypto_30_vHsm_DecJobStateOfJobRequest(Index)                                               Crypto_30_vHsm_GetJobStateOfJobRequest(Index)--
#define Crypto_30_vHsm_DecKeyMJobOfJobRequest(Index)                                                Crypto_30_vHsm_GetKeyMJobOfJobRequest(Index)--
#define Crypto_30_vHsm_DecKindOfJobRequest(Index)                                                   Crypto_30_vHsm_GetKindOfJobRequest(Index)--
#define Crypto_30_vHsm_DecOutputOffsetOfJobRequest(Index)                                           Crypto_30_vHsm_GetOutputOffsetOfJobRequest(Index)--
#define Crypto_30_vHsm_DecProcessingTypeOfJobRequest(Index)                                         Crypto_30_vHsm_GetProcessingTypeOfJobRequest(Index)--
#define Crypto_30_vHsm_DecResultOfJobRequest(Index)                                                 Crypto_30_vHsm_GetResultOfJobRequest(Index)--
#define Crypto_30_vHsm_DecSecondaryOutputOffsetOfJobRequest(Index)                                  Crypto_30_vHsm_GetSecondaryOutputOffsetOfJobRequest(Index)--
#define Crypto_30_vHsm_DecStateOfJobRequest(Index)                                                  Crypto_30_vHsm_GetStateOfJobRequest(Index)--
#define Crypto_30_vHsm_DecUsedBufferOfJobRequest(Index)                                             Crypto_30_vHsm_GetUsedBufferOfJobRequest(Index)--
#define Crypto_30_vHsm_DecOutputLengthPtrDataBuffer(Index)                                          Crypto_30_vHsm_GetOutputLengthPtrDataBuffer(Index)--
#define Crypto_30_vHsm_DecSecondaryOutputLengthPtrDataBuffer(Index)                                 Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBuffer(Index)--
#define Crypto_30_vHsm_DecSharedDataBuffer(Index)                                                   Crypto_30_vHsm_GetSharedDataBuffer(Index)--
#define Crypto_30_vHsm_DecVerifyPtrDataBuffer(Index)                                                Crypto_30_vHsm_GetVerifyPtrDataBuffer(Index)--
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCAddDataMacros  Crypto_30_vHsm Add Data Macros (PRE_COMPILE)
  \brief  These macros can be used to add VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_vHsm_AddChannelState(Index, Value)                                                Crypto_30_vHsm_SetChannelState(Index, (Crypto_30_vHsm_GetChannelState(Index) + Value))
#define Crypto_30_vHsm_AddDriverObjectLock(Index, Value)                                            Crypto_30_vHsm_SetDriverObjectLock(Index, (Crypto_30_vHsm_GetDriverObjectLock(Index) + Value))
#define Crypto_30_vHsm_AddCounterOfJobRequest(Index, Value)                                         Crypto_30_vHsm_SetCounterOfJobRequest(Index, (Crypto_30_vHsm_GetCounterOfJobRequest(Index) + Value))
#define Crypto_30_vHsm_AddCryptoJobOfJobRequest(Index, Value)                                       Crypto_30_vHsm_SetCryptoJobOfJobRequest(Index, (Crypto_30_vHsm_GetCryptoJobOfJobRequest(Index) + Value))
#define Crypto_30_vHsm_AddJobStateOfJobRequest(Index, Value)                                        Crypto_30_vHsm_SetJobStateOfJobRequest(Index, (Crypto_30_vHsm_GetJobStateOfJobRequest(Index) + Value))
#define Crypto_30_vHsm_AddKeyMJobOfJobRequest(Index, Value)                                         Crypto_30_vHsm_SetKeyMJobOfJobRequest(Index, (Crypto_30_vHsm_GetKeyMJobOfJobRequest(Index) + Value))
#define Crypto_30_vHsm_AddKindOfJobRequest(Index, Value)                                            Crypto_30_vHsm_SetKindOfJobRequest(Index, (Crypto_30_vHsm_GetKindOfJobRequest(Index) + Value))
#define Crypto_30_vHsm_AddOutputOffsetOfJobRequest(Index, Value)                                    Crypto_30_vHsm_SetOutputOffsetOfJobRequest(Index, (Crypto_30_vHsm_GetOutputOffsetOfJobRequest(Index) + Value))
#define Crypto_30_vHsm_AddProcessingTypeOfJobRequest(Index, Value)                                  Crypto_30_vHsm_SetProcessingTypeOfJobRequest(Index, (Crypto_30_vHsm_GetProcessingTypeOfJobRequest(Index) + Value))
#define Crypto_30_vHsm_AddResultOfJobRequest(Index, Value)                                          Crypto_30_vHsm_SetResultOfJobRequest(Index, (Crypto_30_vHsm_GetResultOfJobRequest(Index) + Value))
#define Crypto_30_vHsm_AddSecondaryOutputOffsetOfJobRequest(Index, Value)                           Crypto_30_vHsm_SetSecondaryOutputOffsetOfJobRequest(Index, (Crypto_30_vHsm_GetSecondaryOutputOffsetOfJobRequest(Index) + Value))
#define Crypto_30_vHsm_AddStateOfJobRequest(Index, Value)                                           Crypto_30_vHsm_SetStateOfJobRequest(Index, (Crypto_30_vHsm_GetStateOfJobRequest(Index) + Value))
#define Crypto_30_vHsm_AddUsedBufferOfJobRequest(Index, Value)                                      Crypto_30_vHsm_SetUsedBufferOfJobRequest(Index, (Crypto_30_vHsm_GetUsedBufferOfJobRequest(Index) + Value))
#define Crypto_30_vHsm_AddOutputLengthPtrDataBuffer(Index, Value)                                   Crypto_30_vHsm_SetOutputLengthPtrDataBuffer(Index, (Crypto_30_vHsm_GetOutputLengthPtrDataBuffer(Index) + Value))
#define Crypto_30_vHsm_AddSecondaryOutputLengthPtrDataBuffer(Index, Value)                          Crypto_30_vHsm_SetSecondaryOutputLengthPtrDataBuffer(Index, (Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBuffer(Index) + Value))
#define Crypto_30_vHsm_AddSharedDataBuffer(Index, Value)                                            Crypto_30_vHsm_SetSharedDataBuffer(Index, (Crypto_30_vHsm_GetSharedDataBuffer(Index) + Value))
#define Crypto_30_vHsm_AddVerifyPtrDataBuffer(Index, Value)                                         Crypto_30_vHsm_SetVerifyPtrDataBuffer(Index, (Crypto_30_vHsm_GetVerifyPtrDataBuffer(Index) + Value))
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCSubstractDataMacros  Crypto_30_vHsm Substract Data Macros (PRE_COMPILE)
  \brief  These macros can be used to substract VAR data with numerical nature.
  \{
*/ 
#define Crypto_30_vHsm_SubChannelState(Index, Value)                                                Crypto_30_vHsm_SetChannelState(Index, (Crypto_30_vHsm_GetChannelState(Index) - Value))
#define Crypto_30_vHsm_SubDriverObjectLock(Index, Value)                                            Crypto_30_vHsm_SetDriverObjectLock(Index, (Crypto_30_vHsm_GetDriverObjectLock(Index) - Value))
#define Crypto_30_vHsm_SubCounterOfJobRequest(Index, Value)                                         Crypto_30_vHsm_SetCounterOfJobRequest(Index, (Crypto_30_vHsm_GetCounterOfJobRequest(Index) - Value))
#define Crypto_30_vHsm_SubCryptoJobOfJobRequest(Index, Value)                                       Crypto_30_vHsm_SetCryptoJobOfJobRequest(Index, (Crypto_30_vHsm_GetCryptoJobOfJobRequest(Index) - Value))
#define Crypto_30_vHsm_SubJobStateOfJobRequest(Index, Value)                                        Crypto_30_vHsm_SetJobStateOfJobRequest(Index, (Crypto_30_vHsm_GetJobStateOfJobRequest(Index) - Value))
#define Crypto_30_vHsm_SubKeyMJobOfJobRequest(Index, Value)                                         Crypto_30_vHsm_SetKeyMJobOfJobRequest(Index, (Crypto_30_vHsm_GetKeyMJobOfJobRequest(Index) - Value))
#define Crypto_30_vHsm_SubKindOfJobRequest(Index, Value)                                            Crypto_30_vHsm_SetKindOfJobRequest(Index, (Crypto_30_vHsm_GetKindOfJobRequest(Index) - Value))
#define Crypto_30_vHsm_SubOutputOffsetOfJobRequest(Index, Value)                                    Crypto_30_vHsm_SetOutputOffsetOfJobRequest(Index, (Crypto_30_vHsm_GetOutputOffsetOfJobRequest(Index) - Value))
#define Crypto_30_vHsm_SubProcessingTypeOfJobRequest(Index, Value)                                  Crypto_30_vHsm_SetProcessingTypeOfJobRequest(Index, (Crypto_30_vHsm_GetProcessingTypeOfJobRequest(Index) - Value))
#define Crypto_30_vHsm_SubResultOfJobRequest(Index, Value)                                          Crypto_30_vHsm_SetResultOfJobRequest(Index, (Crypto_30_vHsm_GetResultOfJobRequest(Index) - Value))
#define Crypto_30_vHsm_SubSecondaryOutputOffsetOfJobRequest(Index, Value)                           Crypto_30_vHsm_SetSecondaryOutputOffsetOfJobRequest(Index, (Crypto_30_vHsm_GetSecondaryOutputOffsetOfJobRequest(Index) - Value))
#define Crypto_30_vHsm_SubStateOfJobRequest(Index, Value)                                           Crypto_30_vHsm_SetStateOfJobRequest(Index, (Crypto_30_vHsm_GetStateOfJobRequest(Index) - Value))
#define Crypto_30_vHsm_SubUsedBufferOfJobRequest(Index, Value)                                      Crypto_30_vHsm_SetUsedBufferOfJobRequest(Index, (Crypto_30_vHsm_GetUsedBufferOfJobRequest(Index) - Value))
#define Crypto_30_vHsm_SubOutputLengthPtrDataBuffer(Index, Value)                                   Crypto_30_vHsm_SetOutputLengthPtrDataBuffer(Index, (Crypto_30_vHsm_GetOutputLengthPtrDataBuffer(Index) - Value))
#define Crypto_30_vHsm_SubSecondaryOutputLengthPtrDataBuffer(Index, Value)                          Crypto_30_vHsm_SetSecondaryOutputLengthPtrDataBuffer(Index, (Crypto_30_vHsm_GetSecondaryOutputLengthPtrDataBuffer(Index) - Value))
#define Crypto_30_vHsm_SubSharedDataBuffer(Index, Value)                                            Crypto_30_vHsm_SetSharedDataBuffer(Index, (Crypto_30_vHsm_GetSharedDataBuffer(Index) - Value))
#define Crypto_30_vHsm_SubVerifyPtrDataBuffer(Index, Value)                                         Crypto_30_vHsm_SetVerifyPtrDataBuffer(Index, (Crypto_30_vHsm_GetVerifyPtrDataBuffer(Index) - Value))
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
  \defgroup  Crypto_30_vHsmPBGetRootDataMacros  Crypto_30_vHsm Get Root Data Macros (POST_BUILD)
  \brief  These macros are used to get data pointers of root data.
  \{
*/ 
#define Crypto_30_vHsm_GetLTConfigIdxOfPBConfig()                                                     /**< Deactivateable: 'Crypto_30_vHsm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_vHsm_GetPCConfigIdxOfPBConfig()                                                     /**< Deactivateable: 'Crypto_30_vHsm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPBHasMacros  Crypto_30_vHsm Has Macros (POST_BUILD)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Crypto_30_vHsm_HasPBConfig()                                                                  /**< Deactivateable: 'Crypto_30_vHsm_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_vHsm_HasLTConfigIdxOfPBConfig()                                                     /**< Deactivateable: 'Crypto_30_vHsm_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define Crypto_30_vHsm_HasPCConfigIdxOfPBConfig()                                                     /**< Deactivateable: 'Crypto_30_vHsm_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
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




/* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
#define Crypto_30_vHsm_TriggerInterrupt()                                                           (*(volatile uint32 *)CRYPTO_30_VHSM_JOB_REQUEST_INTERRUPT_FLAG_SET_ADDRESS) |= (0x00000001u)
#define Crypto_30_vHsm_ClearInterrupt()                                                             (*(volatile uint32 *)CRYPTO_30_VHSM_JOB_RESPONSE_INTERRUPT_FLAG_CLEAR_ADDRESS) |= (0x00000001u)
#define Crypto_30_vHsm_IndicateInitializedIpc()                                                     (*(volatile uint32*)CRYPTO_30_VHSM_HOST2_HSM_ADDRESS |= (1u << CRYPTO_30_VHSM_IPC_INSTANCE_ID))
#define Crypto_30_vHsm_IndicateUninitializedIpc()                                                   (*(volatile uint32*)CRYPTO_30_VHSM_HOST2_HSM_ADDRESS &= ~(1u << CRYPTO_30_VHSM_IPC_INSTANCE_ID))
#define Crypto_30_vHsm_IsIpcNotInitialized()                                                        ((*(volatile uint32*)CRYPTO_30_VHSM_HOST2_HSM_ADDRESS & (1u << CRYPTO_30_VHSM_IPC_INSTANCE_ID) ) != (1u << CRYPTO_30_VHSM_IPC_INSTANCE_ID))
#define Crypto_30_vHsm_CheckForHsmReady()                                                           ((*(volatile uint32*)CRYPTO_30_VHSM_HSM2_HOST_ADDRESS & ((1u << CRYPTO_30_VHSM_HSM2HOST_READY) | (1u << CRYPTO_30_VHSM_HSM2HOST_ACTIVE))) != ((1u << CRYPTO_30_VHSM_HSM2HOST_READY) | (1u << CRYPTO_30_VHSM_HSM2HOST_ACTIVE)))
/* PRQA L:Macros_3453 */


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) Crypto_30_vHsm_CryptoJobPtr;
typedef P2VAR(Crypto_30_vHsm_KeyM_JobType, AUTOMATIC, CRYPTO_30_VHSM_APPL_VAR) Crypto_30_vHsm_KeyMJobPtr;
typedef Crypto_JobType* Crypto_30_vHsm_QueueElementType;


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_vHsmPCIterableTypes  Crypto_30_vHsm Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Crypto_30_vHsm_ChannelState */
/*! \spec strong type invariant () { self < Crypto_30_vHsm_GetSizeOfChannelState() } \endspec */ 
typedef uint8_least Crypto_30_vHsm_ChannelStateIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_KeyMgmObj */
/*! \spec strong type invariant () { self < Crypto_30_vHsm_GetSizeOfKeyMgmObj() } \endspec */ 
typedef uint8_least Crypto_30_vHsm_KeyMgmObjIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_MemoryArea */
/*! \spec strong type invariant () { self < Crypto_30_vHsm_GetSizeOfMemoryArea() } \endspec */ 
typedef uint8_least Crypto_30_vHsm_MemoryAreaIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_ObjMap */
/*! \spec strong type invariant () { self < Crypto_30_vHsm_GetSizeOfObjMap() } \endspec */ 
typedef uint8_least Crypto_30_vHsm_ObjMapIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_ObjectInfo */
/*! \spec strong type invariant () { self < Crypto_30_vHsm_GetSizeOfObjectInfo() } \endspec */ 
typedef uint8_least Crypto_30_vHsm_ObjectInfoIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_SharedDataBuffer */
/*! \spec strong type invariant () { self < Crypto_30_vHsm_GetSizeOfSharedDataBuffer() } \endspec */ 
typedef uint16_least Crypto_30_vHsm_SharedDataBufferIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCIterableTypesWithSizeRelations  Crypto_30_vHsm Iterable Types With Size Relations (PRE_COMPILE)
  \brief  These type definitions are used to iterate over a VAR based array with the same iterator as the related CONST array.
  \{
*/ 
/**   \brief  type used to iterate Crypto_30_vHsm_DriverObjectLock */
/*! \spec strong type invariant () { self < Crypto_30_vHsm_GetSizeOfDriverObjectLock() } \endspec */ 
typedef Crypto_30_vHsm_ObjectInfoIterType Crypto_30_vHsm_DriverObjectLockIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_JobRequest */
/*! \spec strong type invariant () { self < Crypto_30_vHsm_GetSizeOfJobRequest() } \endspec */ 
typedef Crypto_30_vHsm_ObjectInfoIterType Crypto_30_vHsm_JobRequestIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_OutputLengthPtrDataBuffer */
/*! \spec strong type invariant () { self < Crypto_30_vHsm_GetSizeOfOutputLengthPtrDataBuffer() } \endspec */ 
typedef Crypto_30_vHsm_ObjectInfoIterType Crypto_30_vHsm_OutputLengthPtrDataBufferIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer */
/*! \spec strong type invariant () { self < Crypto_30_vHsm_GetSizeOfSecondaryOutputLengthPtrDataBuffer() } \endspec */ 
typedef Crypto_30_vHsm_ObjectInfoIterType Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferIterType;

/**   \brief  type used to iterate Crypto_30_vHsm_VerifyPtrDataBuffer */
/*! \spec strong type invariant () { self < Crypto_30_vHsm_GetSizeOfVerifyPtrDataBuffer() } \endspec */ 
typedef Crypto_30_vHsm_ObjectInfoIterType Crypto_30_vHsm_VerifyPtrDataBufferIterType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCValueTypes  Crypto_30_vHsm Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Crypto_30_vHsm_ChannelState */
typedef uint8 Crypto_30_vHsm_ChannelStateType;

/**   \brief  value based type definition for Crypto_30_vHsm_DetInstanceMaskOfvHsm */
typedef uint8 Crypto_30_vHsm_DetInstanceMaskOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_DriverObjectLock */
typedef uint32 Crypto_30_vHsm_DriverObjectLockType;

/**   \brief  value based type definition for Crypto_30_vHsm_FlagClearAddressOfJobResponseInterrupt */
typedef uint32 Crypto_30_vHsm_FlagClearAddressOfJobResponseInterruptType;

/**   \brief  value based type definition for Crypto_30_vHsm_FlagClearMaskOfJobResponseInterrupt */
typedef uint8 Crypto_30_vHsm_FlagClearMaskOfJobResponseInterruptType;

/**   \brief  value based type definition for Crypto_30_vHsm_FlagClearValueOfJobResponseInterrupt */
typedef uint8 Crypto_30_vHsm_FlagClearValueOfJobResponseInterruptType;

/**   \brief  value based type definition for Crypto_30_vHsm_FlagClearingOfJobResponseInterrupt */
typedef boolean Crypto_30_vHsm_FlagClearingOfJobResponseInterruptType;

/**   \brief  value based type definition for Crypto_30_vHsm_FlagSetAddressOfJobRequestInterrupt */
typedef uint32 Crypto_30_vHsm_FlagSetAddressOfJobRequestInterruptType;

/**   \brief  value based type definition for Crypto_30_vHsm_FlagSetMaskOfJobRequestInterrupt */
typedef uint8 Crypto_30_vHsm_FlagSetMaskOfJobRequestInterruptType;

/**   \brief  value based type definition for Crypto_30_vHsm_FlagSettingOfJobRequestInterrupt */
typedef boolean Crypto_30_vHsm_FlagSettingOfJobRequestInterruptType;

/**   \brief  value based type definition for Crypto_30_vHsm_Host2HsmAddressOfvHsm */
typedef uint32 Crypto_30_vHsm_Host2HsmAddressOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_Hsm2HostAddressOfvHsm */
typedef uint32 Crypto_30_vHsm_Hsm2HostAddressOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_InterruptModeOfvHsm */
typedef boolean Crypto_30_vHsm_InterruptModeOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_IpcChannelsOfvHsm */
typedef uint8 Crypto_30_vHsm_IpcChannelsOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_IpcInitializationOfvHsm */
typedef boolean Crypto_30_vHsm_IpcInitializationOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_IpcInstanceIdOfvHsm */
typedef uint8 Crypto_30_vHsm_IpcInstanceIdOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_IpcMacJobOptimizationOfvHsm */
typedef boolean Crypto_30_vHsm_IpcMacJobOptimizationOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_IpcProtocolVersionOfvHsm */
typedef uint8 Crypto_30_vHsm_IpcProtocolVersionOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_CancelOfJobRequest */
typedef boolean Crypto_30_vHsm_CancelOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_CounterOfJobRequest */
typedef uint8 Crypto_30_vHsm_CounterOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_KindOfJobRequest */
typedef uint8 Crypto_30_vHsm_KindOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_LockOfJobRequest */
typedef boolean Crypto_30_vHsm_LockOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_OutputOffsetOfJobRequest */
typedef uint32 Crypto_30_vHsm_OutputOffsetOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_ProcessingTypeOfJobRequest */
typedef uint8 Crypto_30_vHsm_ProcessingTypeOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_ResultOfJobRequest */
typedef uint8 Crypto_30_vHsm_ResultOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_SecondaryOutputOffsetOfJobRequest */
typedef uint32 Crypto_30_vHsm_SecondaryOutputOffsetOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_StateOfJobRequest */
typedef uint8 Crypto_30_vHsm_StateOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_TrimmedOutputBufferOfJobRequest */
typedef boolean Crypto_30_vHsm_TrimmedOutputBufferOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_UsedBufferOfJobRequest */
typedef uint32 Crypto_30_vHsm_UsedBufferOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_KeyDeriveJobSupportOfvHsm */
typedef boolean Crypto_30_vHsm_KeyDeriveJobSupportOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_KeyElementDeleteSupportOfvHsm */
typedef boolean Crypto_30_vHsm_KeyElementDeleteSupportOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_ObjectInfoIdxOfKeyMgmObj */
/*! \spec strong type invariant () { self < Crypto_30_vHsm_GetSizeOfObjectInfo() } \endspec */ 
typedef uint8 Crypto_30_vHsm_ObjectInfoIdxOfKeyMgmObjType;

/**   \brief  value based type definition for Crypto_30_vHsm_MainFunctionPeriodOfGeneral */
typedef uint8 Crypto_30_vHsm_MainFunctionPeriodOfGeneralType;

/**   \brief  value based type definition for Crypto_30_vHsm_AreaStartOfMemoryArea */
typedef uint32 Crypto_30_vHsm_AreaStartOfMemoryAreaType;

/**   \brief  value based type definition for Crypto_30_vHsm_AreaStopOfMemoryArea */
typedef uint32 Crypto_30_vHsm_AreaStopOfMemoryAreaType;

/**   \brief  value based type definition for Crypto_30_vHsm_AreaTypeOfMemoryArea */
typedef uint8 Crypto_30_vHsm_AreaTypeOfMemoryAreaType;

/**   \brief  value based type definition for Crypto_30_vHsm_ObjectInfoIdxOfObjMap */
/*! \spec strong type invariant () { self < Crypto_30_vHsm_GetSizeOfObjectInfo() } \endspec */ 
typedef uint8 Crypto_30_vHsm_ObjectInfoIdxOfObjMapType;

/**   \brief  value based type definition for Crypto_30_vHsm_ObjectInfoUsedOfObjMap */
typedef boolean Crypto_30_vHsm_ObjectInfoUsedOfObjMapType;

/**   \brief  value based type definition for Crypto_30_vHsm_BufferUsedOfObjectInfo */
typedef boolean Crypto_30_vHsm_BufferUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_vHsm_HsmObjIdOfObjectInfo */
typedef uint8 Crypto_30_vHsm_HsmObjIdOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_vHsm_SharedDataBufferEndIdxOfObjectInfo */
/*! \spec strong type invariant () { self < Crypto_30_vHsm_GetSizeOfSharedDataBuffer() } \endspec */ 
typedef uint16 Crypto_30_vHsm_SharedDataBufferEndIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_vHsm_SharedDataBufferStartIdxOfObjectInfo */
/*! \spec strong type invariant () { self < Crypto_30_vHsm_GetSizeOfSharedDataBuffer() } \endspec */ 
typedef uint16 Crypto_30_vHsm_SharedDataBufferStartIdxOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_vHsm_SharedDataBufferUsedOfObjectInfo */
typedef boolean Crypto_30_vHsm_SharedDataBufferUsedOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_vHsm_OutputLengthPtrDataBuffer */
typedef uint32 Crypto_30_vHsm_OutputLengthPtrDataBufferType;

/**   \brief  value based type definition for Crypto_30_vHsm_RedirectionOfvHsm */
typedef boolean Crypto_30_vHsm_RedirectionOfvHsmType;

/**   \brief  value based type definition for Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer */
typedef uint32 Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType;

/**   \brief  value based type definition for Crypto_30_vHsm_SharedDataBuffer */
typedef uint32 Crypto_30_vHsm_SharedDataBufferType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfChannelState */
typedef uint8 Crypto_30_vHsm_SizeOfChannelStateType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfDriverObjectLock */
typedef uint8 Crypto_30_vHsm_SizeOfDriverObjectLockType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfJobRequest */
typedef uint8 Crypto_30_vHsm_SizeOfJobRequestType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfKeyMgmObj */
typedef uint8 Crypto_30_vHsm_SizeOfKeyMgmObjType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfMemoryArea */
typedef uint8 Crypto_30_vHsm_SizeOfMemoryAreaType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfObjMap */
typedef uint8 Crypto_30_vHsm_SizeOfObjMapType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfObjectInfo */
typedef uint8 Crypto_30_vHsm_SizeOfObjectInfoType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfOutputLengthPtrDataBuffer */
typedef uint8 Crypto_30_vHsm_SizeOfOutputLengthPtrDataBufferType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfSecondaryOutputLengthPtrDataBuffer */
typedef uint8 Crypto_30_vHsm_SizeOfSecondaryOutputLengthPtrDataBufferType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfSharedDataBuffer */
typedef uint16 Crypto_30_vHsm_SizeOfSharedDataBufferType;

/**   \brief  value based type definition for Crypto_30_vHsm_SizeOfVerifyPtrDataBuffer */
typedef uint8 Crypto_30_vHsm_SizeOfVerifyPtrDataBufferType;

/**   \brief  value based type definition for Crypto_30_vHsm_VersionInfoApiOfGeneral */
typedef boolean Crypto_30_vHsm_VersionInfoApiOfGeneralType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_vHsmPCStructTypes  Crypto_30_vHsm Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in Crypto_30_vHsm_JobRequest */
typedef struct sCrypto_30_vHsm_JobRequestType
{
  Crypto_30_vHsm_OutputOffsetOfJobRequestType OutputOffsetOfJobRequest;
  Crypto_30_vHsm_SecondaryOutputOffsetOfJobRequestType SecondaryOutputOffsetOfJobRequest;
  Crypto_30_vHsm_UsedBufferOfJobRequestType UsedBufferOfJobRequest;
  Crypto_30_vHsm_CancelOfJobRequestType CancelOfJobRequest;
  Crypto_30_vHsm_CounterOfJobRequestType CounterOfJobRequest;
  Crypto_30_vHsm_KindOfJobRequestType KindOfJobRequest;
  Crypto_30_vHsm_LockOfJobRequestType LockOfJobRequest;
  Crypto_30_vHsm_ProcessingTypeOfJobRequestType ProcessingTypeOfJobRequest;
  Crypto_30_vHsm_ResultOfJobRequestType ResultOfJobRequest;
  Crypto_30_vHsm_StateOfJobRequestType StateOfJobRequest;
  Crypto_30_vHsm_TrimmedOutputBufferOfJobRequestType TrimmedOutputBufferOfJobRequest;
  Crypto_30_vHsm_CryptoJobPtr CryptoJobOfJobRequest;
  Crypto_JobStateType JobStateOfJobRequest;
  Crypto_30_vHsm_KeyMJobPtr KeyMJobOfJobRequest;
} Crypto_30_vHsm_JobRequestType;

/**   \brief  type used in Crypto_30_vHsm_KeyMgmObj */
/*! 
 * \spec strong type invariant () { 
 *   (self.ObjectInfoIdxOfKeyMgmObj < Crypto_30_vHsm_GetSizeOfObjectInfo())
 * }
 * \endspec 
 */ 
typedef struct sCrypto_30_vHsm_KeyMgmObjType
{
  Crypto_30_vHsm_ObjectInfoIdxOfKeyMgmObjType ObjectInfoIdxOfKeyMgmObj;  /**< the index of the 1:1 relation pointing to Crypto_30_vHsm_ObjectInfo */
} Crypto_30_vHsm_KeyMgmObjType;

/**   \brief  type used in Crypto_30_vHsm_MemoryArea */
typedef struct sCrypto_30_vHsm_MemoryAreaType
{
  Crypto_30_vHsm_AreaStartOfMemoryAreaType AreaStartOfMemoryArea;  /**< Start address of area */
  Crypto_30_vHsm_AreaStopOfMemoryAreaType AreaStopOfMemoryArea;  /**< Stop address of area */
  Crypto_30_vHsm_AreaTypeOfMemoryAreaType AreaTypeOfMemoryArea;  /**< Access type of area */
} Crypto_30_vHsm_MemoryAreaType;

/**   \brief  type used in Crypto_30_vHsm_ObjMap */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.ObjectInfoIdxOfObjMap != CRYPTO_30_VHSM_NO_OBJECTINFOIDXOFOBJMAP) || (self.ObjectInfoIdxOfObjMap < Crypto_30_vHsm_GetSizeOfObjectInfo()))
 * }
 * \endspec 
 */ 
typedef struct sCrypto_30_vHsm_ObjMapType
{
  Crypto_30_vHsm_ObjectInfoIdxOfObjMapType ObjectInfoIdxOfObjMap;  /**< the index of the 0:1 relation pointing to Crypto_30_vHsm_ObjectInfo */
} Crypto_30_vHsm_ObjMapType;

/**   \brief  type used in Crypto_30_vHsm_ObjectInfo */
/*! 
 * \spec strong type invariant () { 
 *   (!(self.SharedDataBufferStartIdxOfObjectInfo != CRYPTO_30_VHSM_NO_SHAREDDATABUFFERSTARTIDXOFOBJECTINFO) || (self.SharedDataBufferEndIdxOfObjectInfo < Crypto_30_vHsm_GetSizeOfSharedDataBuffer())) &&
 *   (!(self.SharedDataBufferStartIdxOfObjectInfo != CRYPTO_30_VHSM_NO_SHAREDDATABUFFERSTARTIDXOFOBJECTINFO) || (self.SharedDataBufferStartIdxOfObjectInfo < Crypto_30_vHsm_GetSizeOfSharedDataBuffer()))
 * }
 * \endspec 
 */ 
typedef struct sCrypto_30_vHsm_ObjectInfoType
{
  Crypto_30_vHsm_SharedDataBufferEndIdxOfObjectInfoType SharedDataBufferEndIdxOfObjectInfo;  /**< the end index of the 0:n relation pointing to Crypto_30_vHsm_SharedDataBuffer */
  Crypto_30_vHsm_SharedDataBufferStartIdxOfObjectInfoType SharedDataBufferStartIdxOfObjectInfo;  /**< the start index of the 0:n relation pointing to Crypto_30_vHsm_SharedDataBuffer */
  Crypto_30_vHsm_BufferUsedOfObjectInfoType BufferUsedOfObjectInfo;
  Crypto_30_vHsm_HsmObjIdOfObjectInfoType HsmObjIdOfObjectInfo;
} Crypto_30_vHsm_ObjectInfoType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCSymbolicStructTypes  Crypto_30_vHsm Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to Crypto_30_vHsm_DriverObjectLock */
typedef struct Crypto_30_vHsm_DriverObjectLockStructSTag
{
  Crypto_30_vHsm_DriverObjectLockType Crypto_30_vHsm_Core;
  Crypto_30_vHsm_DriverObjectLockType Crypto_30_vHsm_Hwa;
  Crypto_30_vHsm_DriverObjectLockType Crypto_30_vHsm_Hwa_HighPrio;
  Crypto_30_vHsm_DriverObjectLockType Crypto_30_vHsm_KeyM_LibCv;
  Crypto_30_vHsm_DriverObjectLockType Crypto_30_vHsm_KeyManagement;
  Crypto_30_vHsm_DriverObjectLockType Crypto_30_vHsm_LibCv;
  Crypto_30_vHsm_DriverObjectLockType Crypto_30_vHsm_LibCv_HighPrio;
} Crypto_30_vHsm_DriverObjectLockStructSType;

/**   \brief  type to be used as symbolic data element access to Crypto_30_vHsm_JobRequest */
typedef struct Crypto_30_vHsm_JobRequestStructSTag
{
  Crypto_30_vHsm_JobRequestType Crypto_30_vHsm_Core;
  Crypto_30_vHsm_JobRequestType Crypto_30_vHsm_Hwa;
  Crypto_30_vHsm_JobRequestType Crypto_30_vHsm_Hwa_HighPrio;
  Crypto_30_vHsm_JobRequestType Crypto_30_vHsm_KeyM_LibCv;
  Crypto_30_vHsm_JobRequestType Crypto_30_vHsm_KeyManagement;
  Crypto_30_vHsm_JobRequestType Crypto_30_vHsm_LibCv;
  Crypto_30_vHsm_JobRequestType Crypto_30_vHsm_LibCv_HighPrio;
} Crypto_30_vHsm_JobRequestStructSType;

/**   \brief  type to be used as symbolic data element access to Crypto_30_vHsm_OutputLengthPtrDataBuffer */
typedef struct Crypto_30_vHsm_OutputLengthPtrDataBufferStructSTag
{
  Crypto_30_vHsm_OutputLengthPtrDataBufferType Crypto_30_vHsm_Core;
  Crypto_30_vHsm_OutputLengthPtrDataBufferType Crypto_30_vHsm_Hwa;
  Crypto_30_vHsm_OutputLengthPtrDataBufferType Crypto_30_vHsm_Hwa_HighPrio;
  Crypto_30_vHsm_OutputLengthPtrDataBufferType Crypto_30_vHsm_KeyM_LibCv;
  Crypto_30_vHsm_OutputLengthPtrDataBufferType Crypto_30_vHsm_KeyManagement;
  Crypto_30_vHsm_OutputLengthPtrDataBufferType Crypto_30_vHsm_LibCv;
  Crypto_30_vHsm_OutputLengthPtrDataBufferType Crypto_30_vHsm_LibCv_HighPrio;
} Crypto_30_vHsm_OutputLengthPtrDataBufferStructSType;

/**   \brief  type to be used as symbolic data element access to Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer */
typedef struct Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferStructSTag
{
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType Crypto_30_vHsm_Core;
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType Crypto_30_vHsm_Hwa;
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType Crypto_30_vHsm_Hwa_HighPrio;
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType Crypto_30_vHsm_KeyM_LibCv;
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType Crypto_30_vHsm_KeyManagement;
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType Crypto_30_vHsm_LibCv;
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType Crypto_30_vHsm_LibCv_HighPrio;
} Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferStructSType;

/**   \brief  type to be used as symbolic data element access to Crypto_30_vHsm_SharedDataBuffer */
typedef struct Crypto_30_vHsm_SharedDataBufferStructSTag
{
  Crypto_30_vHsm_SharedDataBufferType Crypto_30_vHsm_Core[67];
  Crypto_30_vHsm_SharedDataBufferType Crypto_30_vHsm_Hwa[67];
  Crypto_30_vHsm_SharedDataBufferType Crypto_30_vHsm_Hwa_HighPrio[67];
  Crypto_30_vHsm_SharedDataBufferType Crypto_30_vHsm_KeyM_LibCv[67];
  Crypto_30_vHsm_SharedDataBufferType Crypto_30_vHsm_KeyManagement[67];
  Crypto_30_vHsm_SharedDataBufferType Crypto_30_vHsm_LibCv[67];
  Crypto_30_vHsm_SharedDataBufferType Crypto_30_vHsm_LibCv_HighPrio[67];
} Crypto_30_vHsm_SharedDataBufferStructSType;

/**   \brief  type to be used as symbolic data element access to Crypto_30_vHsm_VerifyPtrDataBuffer */
typedef struct Crypto_30_vHsm_VerifyPtrDataBufferStructSTag
{
  Crypto_VerifyResultType Crypto_30_vHsm_Core;
  Crypto_VerifyResultType Crypto_30_vHsm_Hwa;
  Crypto_VerifyResultType Crypto_30_vHsm_Hwa_HighPrio;
  Crypto_VerifyResultType Crypto_30_vHsm_KeyM_LibCv;
  Crypto_VerifyResultType Crypto_30_vHsm_KeyManagement;
  Crypto_VerifyResultType Crypto_30_vHsm_LibCv;
  Crypto_VerifyResultType Crypto_30_vHsm_LibCv_HighPrio;
} Crypto_30_vHsm_VerifyPtrDataBufferStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCUnionIndexAndSymbolTypes  Crypto_30_vHsm Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access Crypto_30_vHsm_DriverObjectLock in an index and symbol based style. */
typedef union Crypto_30_vHsm_DriverObjectLockUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_vHsm_DriverObjectLockType raw[7];
  Crypto_30_vHsm_DriverObjectLockStructSType str;
} Crypto_30_vHsm_DriverObjectLockUType;

/**   \brief  type to access Crypto_30_vHsm_JobRequest in an index and symbol based style. */
typedef union Crypto_30_vHsm_JobRequestUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_vHsm_JobRequestType raw[7];
  Crypto_30_vHsm_JobRequestStructSType str;
} Crypto_30_vHsm_JobRequestUType;

/**   \brief  type to access Crypto_30_vHsm_OutputLengthPtrDataBuffer in an index and symbol based style. */
typedef union Crypto_30_vHsm_OutputLengthPtrDataBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_vHsm_OutputLengthPtrDataBufferType raw[7];
  Crypto_30_vHsm_OutputLengthPtrDataBufferStructSType str;
} Crypto_30_vHsm_OutputLengthPtrDataBufferUType;

/**   \brief  type to access Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer in an index and symbol based style. */
typedef union Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType raw[7];
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferStructSType str;
} Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferUType;

/**   \brief  type to access Crypto_30_vHsm_SharedDataBuffer in an index and symbol based style. */
typedef union Crypto_30_vHsm_SharedDataBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_30_vHsm_SharedDataBufferType raw[469];
  Crypto_30_vHsm_SharedDataBufferStructSType str;
} Crypto_30_vHsm_SharedDataBufferUType;

/**   \brief  type to access Crypto_30_vHsm_VerifyPtrDataBuffer in an index and symbol based style. */
typedef union Crypto_30_vHsm_VerifyPtrDataBufferUTag
{  /* PRQA S 0750 */  /* MD_CSL_Union */
  Crypto_VerifyResultType raw[7];
  Crypto_30_vHsm_VerifyPtrDataBufferStructSType str;
} Crypto_30_vHsm_VerifyPtrDataBufferUType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCRootPointerTypes  Crypto_30_vHsm Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to Crypto_30_vHsm_ChannelState */
typedef P2VAR(volatile Crypto_30_vHsm_ChannelStateType, TYPEDEF, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_ChannelStatePtrType;

/**   \brief  type used to point to Crypto_30_vHsm_DriverObjectLock */
typedef P2VAR(volatile Crypto_30_vHsm_DriverObjectLockType, TYPEDEF, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_DriverObjectLockPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_JobRequest */
typedef P2VAR(volatile Crypto_30_vHsm_JobRequestType, TYPEDEF, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_JobRequestPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_KeyMgmObj */
typedef P2CONST(Crypto_30_vHsm_KeyMgmObjType, TYPEDEF, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_KeyMgmObjPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_MemoryArea */
typedef P2CONST(Crypto_30_vHsm_MemoryAreaType, TYPEDEF, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_MemoryAreaPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_ObjMap */
typedef P2CONST(Crypto_30_vHsm_ObjMapType, TYPEDEF, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_ObjMapPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_ObjectInfo */
typedef P2CONST(Crypto_30_vHsm_ObjectInfoType, TYPEDEF, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_ObjectInfoPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_OutputLengthPtrDataBuffer */
typedef P2VAR(Crypto_30_vHsm_OutputLengthPtrDataBufferType, TYPEDEF, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_OutputLengthPtrDataBufferPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer */
typedef P2VAR(Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferType, TYPEDEF, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_SharedDataBuffer */
typedef P2VAR(Crypto_30_vHsm_SharedDataBufferType, TYPEDEF, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_SharedDataBufferPtrType;

/**   \brief  type used to point to Crypto_30_vHsm_VerifyPtrDataBuffer */
typedef P2VAR(Crypto_VerifyResultType, TYPEDEF, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_VerifyPtrDataBufferPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  Crypto_30_vHsmPCRootValueTypes  Crypto_30_vHsm Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Crypto_30_vHsm_PCConfig */
typedef struct sCrypto_30_vHsm_PCConfigType
{
  uint8 Crypto_30_vHsm_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Crypto_30_vHsm_PCConfigType;

typedef Crypto_30_vHsm_PCConfigType Crypto_30_vHsm_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  Crypto_30_vHsmPBValueTypes  Crypto_30_vHsm Value Types (POST_BUILD)
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
  \defgroup  Crypto_30_vHsmPBRootValueTypes  Crypto_30_vHsm Root Value Types (POST_BUILD)
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
  Crypto_30_vHsm_KeyMgmObj
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_KeyMgmObj
  \details
  Element          Description
  ObjectInfoIdx    the index of the 1:1 relation pointing to Crypto_30_vHsm_ObjectInfo
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_vHsm_KeyMgmObjType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_KeyMgmObj[1];
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_MemoryArea
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_MemoryArea
  \brief  Memory to which vHsm has direct access without the need of a copy.
  \details
  Element      Description
  AreaStart    Start address of area
  AreaStop     Stop address of area
  AreaType     Access type of area
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_vHsm_MemoryAreaType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_MemoryArea[7];
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_ObjMap
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_ObjMap
  \details
  Element          Description
  ObjectInfoIdx    the index of the 0:1 relation pointing to Crypto_30_vHsm_ObjectInfo
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_vHsm_ObjMapType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_ObjMap[8];
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_ObjectInfo
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_ObjectInfo
  \details
  Element                     Description
  SharedDataBufferEndIdx      the end index of the 0:n relation pointing to Crypto_30_vHsm_SharedDataBuffer
  SharedDataBufferStartIdx    the start index of the 0:n relation pointing to Crypto_30_vHsm_SharedDataBuffer
  BufferUsed              
  HsmObjId                
*/ 
#define CRYPTO_30_VHSM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(Crypto_30_vHsm_ObjectInfoType, CRYPTO_30_VHSM_CONST) Crypto_30_vHsm_ObjectInfo[7];
#define CRYPTO_30_VHSM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_ChannelState
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_ChannelState
  \brief  Tracks which IPC channel is currently used.
*/ 
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(Crypto_30_vHsm_ChannelStateType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_ChannelState[2];
#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_DriverObjectLock
**********************************************************************************************************************/
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(Crypto_30_vHsm_DriverObjectLockUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_DriverObjectLock;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_JobRequest
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_JobRequest
  \brief  Stores data for a job request sent to vHSM.
  \details
  Element                  Description
  OutputOffset         
  SecondaryOutputOffset
  UsedBuffer           
  Cancel               
  Counter              
  Kind                 
  Lock                 
  ProcessingType       
  Result               
  State                
  TrimmedOutputBuffer  
  CryptoJob            
  JobState             
  KeyMJob              
*/ 
#define CRYPTO_30_VHSM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern volatile VAR(Crypto_30_vHsm_JobRequestUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_JobRequest;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CRYPTO_30_VHSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_OutputLengthPtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_OutputLengthPtrDataBuffer
  \brief  Buffer for the outputLengthPtr data on the shared RAM.
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_vHsm_OutputLengthPtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_OutputLengthPtrDataBuffer;  /* PRQA S 0777, 0759 */  /* MD_MSR_Rule5.1, MD_CSL_Union */
#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer
  \brief  Buffer for the secondaryOutputLengthPtr data on the shared RAM.
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_vHsm_SecondaryOutputLengthPtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_SecondaryOutputLengthPtrDataBuffer;  /* PRQA S 0777, 0759 */  /* MD_MSR_Rule5.1, MD_CSL_Union */
#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_SharedDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_SharedDataBuffer
  \brief  Buffer for input and output data on the shared RAM
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_vHsm_SharedDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_SharedDataBuffer;  /* PRQA S 0759 */  /* MD_CSL_Union */
#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Crypto_30_vHsm_VerifyPtrDataBuffer
**********************************************************************************************************************/
/** 
  \var    Crypto_30_vHsm_VerifyPtrDataBuffer
  \brief  Buffer for the verifyPtr data on the shared RAM.
*/ 
#define CRYPTO_30_VHSM_START_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(Crypto_30_vHsm_VerifyPtrDataBufferUType, CRYPTO_30_VHSM_VAR_NOINIT) Crypto_30_vHsm_VerifyPtrDataBuffer;  /* PRQA S 0777, 0759 */  /* MD_MSR_Rule5.1, MD_CSL_Union */
#define CRYPTO_30_VHSM_STOP_SEC_GLOBAL_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/




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





#define CRYPTO_30_VHSM_START_SEC_APPL_CODE
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


#define CRYPTO_30_VHSM_STOP_SEC_APPL_CODE
/*lint -save -esym(961, 19.1) */
#include "Crypto_30_vHsm_MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


#if !defined (CRYPTO_30_VHSM_NOUNIT_CSLUNIT)
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL INLINE FUNCTIONS
**********************************************************************************************************************/

#endif



#endif /* CRYPTO_30_VHSM_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Crypto_30_vHsm_Cfg.h
 *********************************************************************************************************************/

